/****************************************************************************************************//**
 * @file     $(targetDevice).h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKM14Z5.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2016/02
 *
 *******************************************************************************************************/

#ifndef MCU_MKM14Z5
#define MCU_MKM14Z5

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
/* ----------------------   MKM14Z5 VectorTable                      ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 DMA Controller                                                                   */
  DMA1_IRQn                     =   1,   /**<  17 DMA Controller                                                                   */
  DMA2_IRQn                     =   2,   /**<  18 DMA Controller                                                                   */
  DMA3_IRQn                     =   3,   /**<  19 DMA Controller                                                                   */
  SPI0_IRQn                     =   4,   /**<  20 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =   5,   /**<  21 Serial Peripheral Interface                                                      */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  TMR0_IRQn                     =   7,   /**<  23 Quad Timer                                                                       */
  TMR1_IRQn                     =   8,   /**<  24 Quad Timer                                                                       */
  TMR2_IRQn                     =   9,   /**<  25 Quad Timer                                                                       */
  TMR3_IRQn                     =  10,   /**<  26 Quad Timer                                                                       */
  PIT0_PIT1_IRQn                =  11,   /**<  27 Periodic Interrupt Timer                                                         */
  LLWU_IRQn                     =  12,   /**<  28 Low Leakage Wakeup                                                               */
  FTF_Command_IRQn              =  13,   /**<  29 Flash Memory Interface                                                           */
  CMP0_CMP1_IRQn                =  14,   /**<  30 High-Speed Comparator                                                            */
  ADC_IRQn                      =  16,   /**<  32 Analogue to Digital Converter                                                    */
  PTx_IRQn                      =  17,   /**<  33 General Purpose Input/Output                                                     */
  UART0_UART1_IRQn              =  19,   /**<  35 Serial Communication Interface                                                   */
  UART2_UART3_IRQn              =  20,   /**<  36 Serial Communication Interface                                                   */
  AFE_CH0_IRQn                  =  21,   /**<  37 This section describes the ADC registers                                         */
  AFE_CH1_IRQn                  =  22,   /**<  38 This section describes the ADC registers                                         */
  AFE_CH2_IRQn                  =  23,   /**<  39 This section describes the ADC registers                                         */
  AFE_CH3_IRQn                  =  24,   /**<  40 This section describes the ADC registers                                         */
  RTC_Alarm_IRQn                =  25,   /**<  41 Real Time Clock                                                                  */
  I2C0_I2C1_IRQn                =  26,   /**<  42 Inter-Integrated Circuit                                                         */
  EWM_IRQn                      =  27,   /**<  43 External Watchdog Monitor                                                        */
  MCG_IRQn                      =  28,   /**<  44 Multipurpose Clock Generator                                                     */
  WDOG_IRQn                     =  29,   /**<  45 External Watchdog Monitor                                                        */
  LPTMR_IRQn                    =  30,   /**<  46 Low Power Timer                                                                  */
  XBAR_IRQn                     =  31,   /**<  47 Crossbar Switch                                                                  */
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
extern void DMA0_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA1_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA2_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA3_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void TMR0_IRQHandler(void);             /**< Quad Timer                                                                       */
extern void TMR1_IRQHandler(void);             /**< Quad Timer                                                                       */
extern void TMR2_IRQHandler(void);             /**< Quad Timer                                                                       */
extern void TMR3_IRQHandler(void);             /**< Quad Timer                                                                       */
extern void PIT0_PIT1_IRQHandler(void);        /**< Periodic Interrupt Timer                                                         */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void FTF_Command_IRQHandler(void);      /**< Flash Memory Interface                                                           */
extern void CMP0_CMP1_IRQHandler(void);        /**< High-Speed Comparator                                                            */
extern void ADC_IRQHandler(void);              /**< Analogue to Digital Converter                                                    */
extern void PTx_IRQHandler(void);              /**< General Purpose Input/Output                                                     */
extern void UART0_UART1_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART2_UART3_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void AFE_CH0_IRQHandler(void);          /**< This section describes the ADC registers                                         */
extern void AFE_CH1_IRQHandler(void);          /**< This section describes the ADC registers                                         */
extern void AFE_CH2_IRQHandler(void);          /**< This section describes the ADC registers                                         */
extern void AFE_CH3_IRQHandler(void);          /**< This section describes the ADC registers                                         */
extern void RTC_Alarm_IRQHandler(void);        /**< Real Time Clock                                                                  */
extern void I2C0_I2C1_IRQHandler(void);        /**< Inter-Integrated Circuit                                                         */
extern void EWM_IRQHandler(void);              /**< External Watchdog Monitor                                                        */
extern void MCG_IRQHandler(void);              /**< Multipurpose Clock Generator                                                     */
extern void WDOG_IRQHandler(void);             /**< External Watchdog Monitor                                                        */
extern void LPTMR_IRQHandler(void);            /**< Low Power Timer                                                                  */
extern void XBAR_IRQHandler(void);             /**< Crossbar Switch                                                                  */

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
/* ================           ADC0 (file:ADC0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC0 Structure                                               */
   __IO uint32_t  SC1[4];                       /**< 0000: Status and Control Registers 1                               */
   __IO uint32_t  CFG1;                         /**< 0010: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 0014: Configuration Register 2                                     */
   __I  uint32_t  R[4];                         /**< 0018: Data Result Register                                         */
   __IO uint32_t  CV1;                          /**< 0028: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 002C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0030: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0034: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0038: Offset Correction Register                                   */
   __IO uint32_t  PG;                           /**< 003C: Plus-Side Gain Register                                      */
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  CLPD;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 004C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0050: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0054: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0058: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 005C: Plus-Side General Calibration Value                          */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- SC1 Bit Fields                           ------ */
#define ADC_SC1_ADCH_MASK                        (0x1FUL << ADC_SC1_ADCH_SHIFT)                      /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       0                                                   /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x01UL << ADC_SC1_AIEN_SHIFT)                      /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       6                                                   /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_COCO_MASK                        (0x01UL << ADC_SC1_COCO_SHIFT)                      /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       7                                                   /*!< ADC0_SC1: COCO Position                 */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x03UL << ADC_CFG1_ADICLK_SHIFT)                   /*!< ADC0_CFG1: ADICLK Mask                  */
#define ADC_CFG1_ADICLK_SHIFT                    0                                                   /*!< ADC0_CFG1: ADICLK Position              */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_MODE_MASK                       (0x03UL << ADC_CFG1_MODE_SHIFT)                     /*!< ADC0_CFG1: MODE Mask                    */
#define ADC_CFG1_MODE_SHIFT                      2                                                   /*!< ADC0_CFG1: MODE Position                */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLSMP_MASK                     (0x01UL << ADC_CFG1_ADLSMP_SHIFT)                   /*!< ADC0_CFG1: ADLSMP Mask                  */
#define ADC_CFG1_ADLSMP_SHIFT                    4                                                   /*!< ADC0_CFG1: ADLSMP Position              */
#define ADC_CFG1_ADIV_MASK                       (0x03UL << ADC_CFG1_ADIV_SHIFT)                     /*!< ADC0_CFG1: ADIV Mask                    */
#define ADC_CFG1_ADIV_SHIFT                      5                                                   /*!< ADC0_CFG1: ADIV Position                */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLPC_MASK                      (0x01UL << ADC_CFG1_ADLPC_SHIFT)                    /*!< ADC0_CFG1: ADLPC Mask                   */
#define ADC_CFG1_ADLPC_SHIFT                     7                                                   /*!< ADC0_CFG1: ADLPC Position               */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x03UL << ADC_CFG2_ADLSTS_SHIFT)                   /*!< ADC0_CFG2: ADLSTS Mask                  */
#define ADC_CFG2_ADLSTS_SHIFT                    0                                                   /*!< ADC0_CFG2: ADLSTS Position              */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADHSC_MASK                      (0x01UL << ADC_CFG2_ADHSC_SHIFT)                    /*!< ADC0_CFG2: ADHSC Mask                   */
#define ADC_CFG2_ADHSC_SHIFT                     2                                                   /*!< ADC0_CFG2: ADHSC Position               */
#define ADC_CFG2_ADACKEN_MASK                    (0x01UL << ADC_CFG2_ADACKEN_SHIFT)                  /*!< ADC0_CFG2: ADACKEN Mask                 */
#define ADC_CFG2_ADACKEN_SHIFT                   3                                                   /*!< ADC0_CFG2: ADACKEN Position             */
#define ADC_CFG2_MUXSEL_MASK                     (0x01UL << ADC_CFG2_MUXSEL_SHIFT)                   /*!< ADC0_CFG2: MUXSEL Mask                  */
#define ADC_CFG2_MUXSEL_SHIFT                    4                                                   /*!< ADC0_CFG2: MUXSEL Position              */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFUL << ADC_R_D_SHIFT)                         /*!< ADC0_R: D Mask                          */
#define ADC_R_D_SHIFT                            0                                                   /*!< ADC0_R: D Position                      */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFUL << ADC_CV_CV_SHIFT)                       /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          0                                                   /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x03UL << ADC_SC2_REFSEL_SHIFT)                    /*!< ADC0_SC2: REFSEL Mask                   */
#define ADC_SC2_REFSEL_SHIFT                     0                                                   /*!< ADC0_SC2: REFSEL Position               */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_DMAEN_MASK                       (0x01UL << ADC_SC2_DMAEN_SHIFT)                     /*!< ADC0_SC2: DMAEN Mask                    */
#define ADC_SC2_DMAEN_SHIFT                      2                                                   /*!< ADC0_SC2: DMAEN Position                */
#define ADC_SC2_ACREN_MASK                       (0x01UL << ADC_SC2_ACREN_SHIFT)                     /*!< ADC0_SC2: ACREN Mask                    */
#define ADC_SC2_ACREN_SHIFT                      3                                                   /*!< ADC0_SC2: ACREN Position                */
#define ADC_SC2_ACFGT_MASK                       (0x01UL << ADC_SC2_ACFGT_SHIFT)                     /*!< ADC0_SC2: ACFGT Mask                    */
#define ADC_SC2_ACFGT_SHIFT                      4                                                   /*!< ADC0_SC2: ACFGT Position                */
#define ADC_SC2_ACFE_MASK                        (0x01UL << ADC_SC2_ACFE_SHIFT)                      /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       5                                                   /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ADTRG_MASK                       (0x01UL << ADC_SC2_ADTRG_SHIFT)                     /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      6                                                   /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADACT_MASK                       (0x01UL << ADC_SC2_ADACT_SHIFT)                     /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      7                                                   /*!< ADC0_SC2: ADACT Position                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x03UL << ADC_SC3_AVGS_SHIFT)                      /*!< ADC0_SC3: AVGS Mask                     */
#define ADC_SC3_AVGS_SHIFT                       0                                                   /*!< ADC0_SC3: AVGS Position                 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_AVGE_MASK                        (0x01UL << ADC_SC3_AVGE_SHIFT)                      /*!< ADC0_SC3: AVGE Mask                     */
#define ADC_SC3_AVGE_SHIFT                       2                                                   /*!< ADC0_SC3: AVGE Position                 */
#define ADC_SC3_ADCO_MASK                        (0x01UL << ADC_SC3_ADCO_SHIFT)                      /*!< ADC0_SC3: ADCO Mask                     */
#define ADC_SC3_ADCO_SHIFT                       3                                                   /*!< ADC0_SC3: ADCO Position                 */
#define ADC_SC3_CALF_MASK                        (0x01UL << ADC_SC3_CALF_SHIFT)                      /*!< ADC0_SC3: CALF Mask                     */
#define ADC_SC3_CALF_SHIFT                       6                                                   /*!< ADC0_SC3: CALF Position                 */
#define ADC_SC3_CAL_MASK                         (0x01UL << ADC_SC3_CAL_SHIFT)                       /*!< ADC0_SC3: CAL Mask                      */
#define ADC_SC3_CAL_SHIFT                        7                                                   /*!< ADC0_SC3: CAL Position                  */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFUL << ADC_OFS_OFS_SHIFT)                     /*!< ADC0_OFS: OFS Mask                      */
#define ADC_OFS_OFS_SHIFT                        0                                                   /*!< ADC0_OFS: OFS Position                  */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /*!< ADC0_OFS                                */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFUL << ADC_PG_PG_SHIFT)                       /*!< ADC0_PG: PG Mask                        */
#define ADC_PG_PG_SHIFT                          0                                                   /*!< ADC0_PG: PG Position                    */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /*!< ADC0_PG                                 */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FUL << ADC_CLPD_CLPD_SHIFT)                     /*!< ADC0_CLPD: CLPD Mask                    */
#define ADC_CLPD_CLPD_SHIFT                      0                                                   /*!< ADC0_CLPD: CLPD Position                */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /*!< ADC0_CLPD                               */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FUL << ADC_CLPS_CLPS_SHIFT)                     /*!< ADC0_CLPS: CLPS Mask                    */
#define ADC_CLPS_CLPS_SHIFT                      0                                                   /*!< ADC0_CLPS: CLPS Position                */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /*!< ADC0_CLPS                               */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFUL << ADC_CLP4_CLP4_SHIFT)                    /*!< ADC0_CLP4: CLP4 Mask                    */
#define ADC_CLP4_CLP4_SHIFT                      0                                                   /*!< ADC0_CLP4: CLP4 Position                */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /*!< ADC0_CLP4                               */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFUL << ADC_CLP3_CLP3_SHIFT)                    /*!< ADC0_CLP3: CLP3 Mask                    */
#define ADC_CLP3_CLP3_SHIFT                      0                                                   /*!< ADC0_CLP3: CLP3 Position                */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /*!< ADC0_CLP3                               */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFUL << ADC_CLP2_CLP2_SHIFT)                     /*!< ADC0_CLP2: CLP2 Mask                    */
#define ADC_CLP2_CLP2_SHIFT                      0                                                   /*!< ADC0_CLP2: CLP2 Position                */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /*!< ADC0_CLP2                               */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FUL << ADC_CLP1_CLP1_SHIFT)                     /*!< ADC0_CLP1: CLP1 Mask                    */
#define ADC_CLP1_CLP1_SHIFT                      0                                                   /*!< ADC0_CLP1: CLP1 Position                */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /*!< ADC0_CLP1                               */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FUL << ADC_CLP0_CLP0_SHIFT)                     /*!< ADC0_CLP0: CLP0 Mask                    */
#define ADC_CLP0_CLP0_SHIFT                      0                                                   /*!< ADC0_CLP0: CLP0 Position                */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /*!< ADC0_CLP0                               */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4002B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup AFE_Peripheral_access_layer_GROUP AFE Peripheral Access Layer
* @brief C Struct for AFE
* @{
*/

/* ================================================================================ */
/* ================           AFE (file:AFE_0)                     ================ */
/* ================================================================================ */

/**
 * @brief This section describes the ADC
 */
/**
* @addtogroup AFE_structs_GROUP AFE struct
* @brief Struct for AFE
* @{
*/
typedef struct {                                /*       AFE Structure                                                */
   __IO uint32_t  CH0_CFR;                      /**< 0000: Channel0 Configuration Register                              */
   __IO uint32_t  CH1_CFR;                      /**< 0004: Channel1 Configuration Register                              */
   __IO uint32_t  CH2_CFR;                      /**< 0008: Channel2 Configuration Register                              */
   __IO uint32_t  CH3_CFR;                      /**< 000C: Channel3 Configuration Register                              */
   __I  uint32_t  RESERVED0[2];                
   __IO uint32_t  CR;                           /**< 0018: Control Register                                             */
   __IO uint32_t  CKR;                          /**< 001C: Clock Configuration Register                                 */
   __IO uint32_t  DI;                           /**< 0020: DMA and Interrupt Register                                   */
   __I  uint32_t  RESERVED1[2];                
   __IO uint32_t  CH0_DR;                       /**< 002C: Channel0 Delay Register                                      */
   __IO uint32_t  CH1_DR;                       /**< 0030: Channel1 Delay Register                                      */
   __IO uint32_t  CH2_DR;                       /**< 0034: Channel2 Delay Register                                      */
   __IO uint32_t  CH3_DR;                       /**< 0038: Channel3 Delay Register                                      */
   __I  uint32_t  RESERVED2[2];                
   __I  uint32_t  CH0_RR;                       /**< 0044: Channel0 Result Register                                     */
   __I  uint32_t  CH1_RR;                       /**< 0048: Channel1 Result Register                                     */
   __I  uint32_t  CH2_RR;                       /**< 004C: Channel2 Result Register                                     */
   __I  uint32_t  CH3_RR;                       /**< 0050: Channel3 Result Register                                     */
   __I  uint32_t  RESERVED3[2];                
   __I  uint32_t  SR;                           /**< 005C: Status Register                                              */
} AFE_Type;

/**
 * @} */ /* End group AFE_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'AFE' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup AFE_Register_Masks_GROUP AFE Register Masks
* @brief Register Masks for AFE
* @{
*/
/* ------- CH0_CFR Bit Fields                       ------ */
#define AFE_CH0_CFR_HW_TRG_MASK                  (0x01UL << AFE_CH0_CFR_HW_TRG_SHIFT)                /*!< AFE_CH0_CFR: HW_TRG Mask                */
#define AFE_CH0_CFR_HW_TRG_SHIFT                 9                                                   /*!< AFE_CH0_CFR: HW_TRG Position            */
#define AFE_CH0_CFR_DEC_CLK_INP_SEL_MASK         (0x01UL << AFE_CH0_CFR_DEC_CLK_INP_SEL_SHIFT)       /*!< AFE_CH0_CFR: DEC_CLK_INP_SEL Mask       */
#define AFE_CH0_CFR_DEC_CLK_INP_SEL_SHIFT        10                                                  /*!< AFE_CH0_CFR: DEC_CLK_INP_SEL Position   */
#define AFE_CH0_CFR_DEC_CLK_EDGE_SEL_MASK        (0x01UL << AFE_CH0_CFR_DEC_CLK_EDGE_SEL_SHIFT)      /*!< AFE_CH0_CFR: DEC_CLK_EDGE_SEL Mask      */
#define AFE_CH0_CFR_DEC_CLK_EDGE_SEL_SHIFT       11                                                  /*!< AFE_CH0_CFR: DEC_CLK_EDGE_SEL Position  */
#define AFE_CH0_CFR_CC_MASK                      (0x01UL << AFE_CH0_CFR_CC_SHIFT)                    /*!< AFE_CH0_CFR: CC Mask                    */
#define AFE_CH0_CFR_CC_SHIFT                     12                                                  /*!< AFE_CH0_CFR: CC Position                */
#define AFE_CH0_CFR_DEC_EN_MASK                  (0x01UL << AFE_CH0_CFR_DEC_EN_SHIFT)                /*!< AFE_CH0_CFR: DEC_EN Mask                */
#define AFE_CH0_CFR_DEC_EN_SHIFT                 13                                                  /*!< AFE_CH0_CFR: DEC_EN Position            */
#define AFE_CH0_CFR_SD_MOD_EN_MASK               (0x01UL << AFE_CH0_CFR_SD_MOD_EN_SHIFT)             /*!< AFE_CH0_CFR: SD_MOD_EN Mask             */
#define AFE_CH0_CFR_SD_MOD_EN_SHIFT              14                                                  /*!< AFE_CH0_CFR: SD_MOD_EN Position         */
#define AFE_CH0_CFR_BYP_MODE_MASK                (0x01UL << AFE_CH0_CFR_BYP_MODE_SHIFT)              /*!< AFE_CH0_CFR: BYP_MODE Mask              */
#define AFE_CH0_CFR_BYP_MODE_SHIFT               17                                                  /*!< AFE_CH0_CFR: BYP_MODE Position          */
#define AFE_CH0_CFR_PGA_GAIN_SEL_MASK            (0x07UL << AFE_CH0_CFR_PGA_GAIN_SEL_SHIFT)          /*!< AFE_CH0_CFR: PGA_GAIN_SEL Mask          */
#define AFE_CH0_CFR_PGA_GAIN_SEL_SHIFT           19                                                  /*!< AFE_CH0_CFR: PGA_GAIN_SEL Position      */
#define AFE_CH0_CFR_PGA_GAIN_SEL(x)              (((uint32_t)(((uint32_t)(x))<<AFE_CH0_CFR_PGA_GAIN_SEL_SHIFT))&AFE_CH0_CFR_PGA_GAIN_SEL_MASK) /*!< AFE_CH0_CFR                             */
#define AFE_CH0_CFR_PGA_EN_MASK                  (0x01UL << AFE_CH0_CFR_PGA_EN_SHIFT)                /*!< AFE_CH0_CFR: PGA_EN Mask                */
#define AFE_CH0_CFR_PGA_EN_SHIFT                 24                                                  /*!< AFE_CH0_CFR: PGA_EN Position            */
#define AFE_CH0_CFR_DEC_OSR_MASK                 (0x07UL << AFE_CH0_CFR_DEC_OSR_SHIFT)               /*!< AFE_CH0_CFR: DEC_OSR Mask               */
#define AFE_CH0_CFR_DEC_OSR_SHIFT                29                                                  /*!< AFE_CH0_CFR: DEC_OSR Position           */
#define AFE_CH0_CFR_DEC_OSR(x)                   (((uint32_t)(((uint32_t)(x))<<AFE_CH0_CFR_DEC_OSR_SHIFT))&AFE_CH0_CFR_DEC_OSR_MASK) /*!< AFE_CH0_CFR                             */
/* ------- CH1_CFR Bit Fields                       ------ */
#define AFE_CH1_CFR_HW_TRG_MASK                  (0x01UL << AFE_CH1_CFR_HW_TRG_SHIFT)                /*!< AFE_CH1_CFR: HW_TRG Mask                */
#define AFE_CH1_CFR_HW_TRG_SHIFT                 9                                                   /*!< AFE_CH1_CFR: HW_TRG Position            */
#define AFE_CH1_CFR_DEC_CLK_INP_SEL_MASK         (0x01UL << AFE_CH1_CFR_DEC_CLK_INP_SEL_SHIFT)       /*!< AFE_CH1_CFR: DEC_CLK_INP_SEL Mask       */
#define AFE_CH1_CFR_DEC_CLK_INP_SEL_SHIFT        10                                                  /*!< AFE_CH1_CFR: DEC_CLK_INP_SEL Position   */
#define AFE_CH1_CFR_DEC_CLK_EDGE_SEL_MASK        (0x01UL << AFE_CH1_CFR_DEC_CLK_EDGE_SEL_SHIFT)      /*!< AFE_CH1_CFR: DEC_CLK_EDGE_SEL Mask      */
#define AFE_CH1_CFR_DEC_CLK_EDGE_SEL_SHIFT       11                                                  /*!< AFE_CH1_CFR: DEC_CLK_EDGE_SEL Position  */
#define AFE_CH1_CFR_CC_MASK                      (0x01UL << AFE_CH1_CFR_CC_SHIFT)                    /*!< AFE_CH1_CFR: CC Mask                    */
#define AFE_CH1_CFR_CC_SHIFT                     12                                                  /*!< AFE_CH1_CFR: CC Position                */
#define AFE_CH1_CFR_DEC_EN_MASK                  (0x01UL << AFE_CH1_CFR_DEC_EN_SHIFT)                /*!< AFE_CH1_CFR: DEC_EN Mask                */
#define AFE_CH1_CFR_DEC_EN_SHIFT                 13                                                  /*!< AFE_CH1_CFR: DEC_EN Position            */
#define AFE_CH1_CFR_SD_MOD_EN_MASK               (0x01UL << AFE_CH1_CFR_SD_MOD_EN_SHIFT)             /*!< AFE_CH1_CFR: SD_MOD_EN Mask             */
#define AFE_CH1_CFR_SD_MOD_EN_SHIFT              14                                                  /*!< AFE_CH1_CFR: SD_MOD_EN Position         */
#define AFE_CH1_CFR_BYP_MODE_MASK                (0x01UL << AFE_CH1_CFR_BYP_MODE_SHIFT)              /*!< AFE_CH1_CFR: BYP_MODE Mask              */
#define AFE_CH1_CFR_BYP_MODE_SHIFT               17                                                  /*!< AFE_CH1_CFR: BYP_MODE Position          */
#define AFE_CH1_CFR_PGA_GAIN_SEL_MASK            (0x07UL << AFE_CH1_CFR_PGA_GAIN_SEL_SHIFT)          /*!< AFE_CH1_CFR: PGA_GAIN_SEL Mask          */
#define AFE_CH1_CFR_PGA_GAIN_SEL_SHIFT           19                                                  /*!< AFE_CH1_CFR: PGA_GAIN_SEL Position      */
#define AFE_CH1_CFR_PGA_GAIN_SEL(x)              (((uint32_t)(((uint32_t)(x))<<AFE_CH1_CFR_PGA_GAIN_SEL_SHIFT))&AFE_CH1_CFR_PGA_GAIN_SEL_MASK) /*!< AFE_CH1_CFR                             */
#define AFE_CH1_CFR_PGA_EN_MASK                  (0x01UL << AFE_CH1_CFR_PGA_EN_SHIFT)                /*!< AFE_CH1_CFR: PGA_EN Mask                */
#define AFE_CH1_CFR_PGA_EN_SHIFT                 24                                                  /*!< AFE_CH1_CFR: PGA_EN Position            */
#define AFE_CH1_CFR_DEC_OSR_MASK                 (0x07UL << AFE_CH1_CFR_DEC_OSR_SHIFT)               /*!< AFE_CH1_CFR: DEC_OSR Mask               */
#define AFE_CH1_CFR_DEC_OSR_SHIFT                29                                                  /*!< AFE_CH1_CFR: DEC_OSR Position           */
#define AFE_CH1_CFR_DEC_OSR(x)                   (((uint32_t)(((uint32_t)(x))<<AFE_CH1_CFR_DEC_OSR_SHIFT))&AFE_CH1_CFR_DEC_OSR_MASK) /*!< AFE_CH1_CFR                             */
/* ------- CH2_CFR Bit Fields                       ------ */
#define AFE_CH2_CFR_HW_TRG_MASK                  (0x01UL << AFE_CH2_CFR_HW_TRG_SHIFT)                /*!< AFE_CH2_CFR: HW_TRG Mask                */
#define AFE_CH2_CFR_HW_TRG_SHIFT                 9                                                   /*!< AFE_CH2_CFR: HW_TRG Position            */
#define AFE_CH2_CFR_DEC_CLK_INP_SEL_MASK         (0x01UL << AFE_CH2_CFR_DEC_CLK_INP_SEL_SHIFT)       /*!< AFE_CH2_CFR: DEC_CLK_INP_SEL Mask       */
#define AFE_CH2_CFR_DEC_CLK_INP_SEL_SHIFT        10                                                  /*!< AFE_CH2_CFR: DEC_CLK_INP_SEL Position   */
#define AFE_CH2_CFR_DEC_CLK_EDGE_SEL_MASK        (0x01UL << AFE_CH2_CFR_DEC_CLK_EDGE_SEL_SHIFT)      /*!< AFE_CH2_CFR: DEC_CLK_EDGE_SEL Mask      */
#define AFE_CH2_CFR_DEC_CLK_EDGE_SEL_SHIFT       11                                                  /*!< AFE_CH2_CFR: DEC_CLK_EDGE_SEL Position  */
#define AFE_CH2_CFR_CC_MASK                      (0x01UL << AFE_CH2_CFR_CC_SHIFT)                    /*!< AFE_CH2_CFR: CC Mask                    */
#define AFE_CH2_CFR_CC_SHIFT                     12                                                  /*!< AFE_CH2_CFR: CC Position                */
#define AFE_CH2_CFR_DEC_EN_MASK                  (0x01UL << AFE_CH2_CFR_DEC_EN_SHIFT)                /*!< AFE_CH2_CFR: DEC_EN Mask                */
#define AFE_CH2_CFR_DEC_EN_SHIFT                 13                                                  /*!< AFE_CH2_CFR: DEC_EN Position            */
#define AFE_CH2_CFR_SD_MOD_EN_MASK               (0x01UL << AFE_CH2_CFR_SD_MOD_EN_SHIFT)             /*!< AFE_CH2_CFR: SD_MOD_EN Mask             */
#define AFE_CH2_CFR_SD_MOD_EN_SHIFT              14                                                  /*!< AFE_CH2_CFR: SD_MOD_EN Position         */
#define AFE_CH2_CFR_BYP_MODE_MASK                (0x01UL << AFE_CH2_CFR_BYP_MODE_SHIFT)              /*!< AFE_CH2_CFR: BYP_MODE Mask              */
#define AFE_CH2_CFR_BYP_MODE_SHIFT               17                                                  /*!< AFE_CH2_CFR: BYP_MODE Position          */
#define AFE_CH2_CFR_DEC_OSR_MASK                 (0x07UL << AFE_CH2_CFR_DEC_OSR_SHIFT)               /*!< AFE_CH2_CFR: DEC_OSR Mask               */
#define AFE_CH2_CFR_DEC_OSR_SHIFT                29                                                  /*!< AFE_CH2_CFR: DEC_OSR Position           */
#define AFE_CH2_CFR_DEC_OSR(x)                   (((uint32_t)(((uint32_t)(x))<<AFE_CH2_CFR_DEC_OSR_SHIFT))&AFE_CH2_CFR_DEC_OSR_MASK) /*!< AFE_CH2_CFR                             */
/* ------- CH3_CFR Bit Fields                       ------ */
#define AFE_CH3_CFR_HW_TRG_MASK                  (0x01UL << AFE_CH3_CFR_HW_TRG_SHIFT)                /*!< AFE_CH3_CFR: HW_TRG Mask                */
#define AFE_CH3_CFR_HW_TRG_SHIFT                 9                                                   /*!< AFE_CH3_CFR: HW_TRG Position            */
#define AFE_CH3_CFR_DEC_CLK_INP_SEL_MASK         (0x01UL << AFE_CH3_CFR_DEC_CLK_INP_SEL_SHIFT)       /*!< AFE_CH3_CFR: DEC_CLK_INP_SEL Mask       */
#define AFE_CH3_CFR_DEC_CLK_INP_SEL_SHIFT        10                                                  /*!< AFE_CH3_CFR: DEC_CLK_INP_SEL Position   */
#define AFE_CH3_CFR_DEC_CLK_EDGE_SEL_MASK        (0x01UL << AFE_CH3_CFR_DEC_CLK_EDGE_SEL_SHIFT)      /*!< AFE_CH3_CFR: DEC_CLK_EDGE_SEL Mask      */
#define AFE_CH3_CFR_DEC_CLK_EDGE_SEL_SHIFT       11                                                  /*!< AFE_CH3_CFR: DEC_CLK_EDGE_SEL Position  */
#define AFE_CH3_CFR_CC_MASK                      (0x01UL << AFE_CH3_CFR_CC_SHIFT)                    /*!< AFE_CH3_CFR: CC Mask                    */
#define AFE_CH3_CFR_CC_SHIFT                     12                                                  /*!< AFE_CH3_CFR: CC Position                */
#define AFE_CH3_CFR_DEC_EN_MASK                  (0x01UL << AFE_CH3_CFR_DEC_EN_SHIFT)                /*!< AFE_CH3_CFR: DEC_EN Mask                */
#define AFE_CH3_CFR_DEC_EN_SHIFT                 13                                                  /*!< AFE_CH3_CFR: DEC_EN Position            */
#define AFE_CH3_CFR_SD_MOD_EN_MASK               (0x01UL << AFE_CH3_CFR_SD_MOD_EN_SHIFT)             /*!< AFE_CH3_CFR: SD_MOD_EN Mask             */
#define AFE_CH3_CFR_SD_MOD_EN_SHIFT              14                                                  /*!< AFE_CH3_CFR: SD_MOD_EN Position         */
#define AFE_CH3_CFR_BYP_MODE_MASK                (0x01UL << AFE_CH3_CFR_BYP_MODE_SHIFT)              /*!< AFE_CH3_CFR: BYP_MODE Mask              */
#define AFE_CH3_CFR_BYP_MODE_SHIFT               17                                                  /*!< AFE_CH3_CFR: BYP_MODE Position          */
#define AFE_CH3_CFR_DEC_OSR_MASK                 (0x07UL << AFE_CH3_CFR_DEC_OSR_SHIFT)               /*!< AFE_CH3_CFR: DEC_OSR Mask               */
#define AFE_CH3_CFR_DEC_OSR_SHIFT                29                                                  /*!< AFE_CH3_CFR: DEC_OSR Position           */
#define AFE_CH3_CFR_DEC_OSR(x)                   (((uint32_t)(((uint32_t)(x))<<AFE_CH3_CFR_DEC_OSR_SHIFT))&AFE_CH3_CFR_DEC_OSR_MASK) /*!< AFE_CH3_CFR                             */
/* ------- CR Bit Fields                            ------ */
#define AFE_CR_STRTUP_CNT_MASK                   (0x7FUL << AFE_CR_STRTUP_CNT_SHIFT)                 /*!< AFE_CR: STRTUP_CNT Mask                 */
#define AFE_CR_STRTUP_CNT_SHIFT                  9                                                   /*!< AFE_CR: STRTUP_CNT Position             */
#define AFE_CR_STRTUP_CNT(x)                     (((uint32_t)(((uint32_t)(x))<<AFE_CR_STRTUP_CNT_SHIFT))&AFE_CR_STRTUP_CNT_MASK) /*!< AFE_CR                                  */
#define AFE_CR_RESULT_FORMAT_MASK                (0x01UL << AFE_CR_RESULT_FORMAT_SHIFT)              /*!< AFE_CR: RESULT_FORMAT Mask              */
#define AFE_CR_RESULT_FORMAT_SHIFT               18                                                  /*!< AFE_CR: RESULT_FORMAT Position          */
#define AFE_CR_DLY_OK_MASK                       (0x01UL << AFE_CR_DLY_OK_SHIFT)                     /*!< AFE_CR: DLY_OK Mask                     */
#define AFE_CR_DLY_OK_SHIFT                      21                                                  /*!< AFE_CR: DLY_OK Position                 */
#define AFE_CR_RST_B_MASK                        (0x01UL << AFE_CR_RST_B_SHIFT)                      /*!< AFE_CR: RST_B Mask                      */
#define AFE_CR_RST_B_SHIFT                       22                                                  /*!< AFE_CR: RST_B Position                  */
#define AFE_CR_LPM_EN_MASK                       (0x01UL << AFE_CR_LPM_EN_SHIFT)                     /*!< AFE_CR: LPM_EN Mask                     */
#define AFE_CR_LPM_EN_SHIFT                      25                                                  /*!< AFE_CR: LPM_EN Position                 */
#define AFE_CR_SOFT_TRG3_MASK                    (0x01UL << AFE_CR_SOFT_TRG3_SHIFT)                  /*!< AFE_CR: SOFT_TRG3 Mask                  */
#define AFE_CR_SOFT_TRG3_SHIFT                   27                                                  /*!< AFE_CR: SOFT_TRG3 Position              */
#define AFE_CR_SOFT_TRG2_MASK                    (0x01UL << AFE_CR_SOFT_TRG2_SHIFT)                  /*!< AFE_CR: SOFT_TRG2 Mask                  */
#define AFE_CR_SOFT_TRG2_SHIFT                   28                                                  /*!< AFE_CR: SOFT_TRG2 Position              */
#define AFE_CR_SOFT_TRG1_MASK                    (0x01UL << AFE_CR_SOFT_TRG1_SHIFT)                  /*!< AFE_CR: SOFT_TRG1 Mask                  */
#define AFE_CR_SOFT_TRG1_SHIFT                   29                                                  /*!< AFE_CR: SOFT_TRG1 Position              */
#define AFE_CR_SOFT_TRG0_MASK                    (0x01UL << AFE_CR_SOFT_TRG0_SHIFT)                  /*!< AFE_CR: SOFT_TRG0 Mask                  */
#define AFE_CR_SOFT_TRG0_SHIFT                   30                                                  /*!< AFE_CR: SOFT_TRG0 Position              */
#define AFE_CR_MSTR_EN_MASK                      (0x01UL << AFE_CR_MSTR_EN_SHIFT)                    /*!< AFE_CR: MSTR_EN Mask                    */
#define AFE_CR_MSTR_EN_SHIFT                     31                                                  /*!< AFE_CR: MSTR_EN Position                */
/* ------- CKR Bit Fields                           ------ */
#define AFE_CKR_CLS_MASK                         (0x03UL << AFE_CKR_CLS_SHIFT)                       /*!< AFE_CKR: CLS Mask                       */
#define AFE_CKR_CLS_SHIFT                        21                                                  /*!< AFE_CKR: CLS Position                   */
#define AFE_CKR_CLS(x)                           (((uint32_t)(((uint32_t)(x))<<AFE_CKR_CLS_SHIFT))&AFE_CKR_CLS_MASK) /*!< AFE_CKR                                 */
#define AFE_CKR_DIV_MASK                         (0x0FUL << AFE_CKR_DIV_SHIFT)                       /*!< AFE_CKR: DIV Mask                       */
#define AFE_CKR_DIV_SHIFT                        28                                                  /*!< AFE_CKR: DIV Position                   */
#define AFE_CKR_DIV(x)                           (((uint32_t)(((uint32_t)(x))<<AFE_CKR_DIV_SHIFT))&AFE_CKR_DIV_MASK) /*!< AFE_CKR                                 */
/* ------- DI Bit Fields                            ------ */
#define AFE_DI_INTEN3_MASK                       (0x01UL << AFE_DI_INTEN3_SHIFT)                     /*!< AFE_DI: INTEN3 Mask                     */
#define AFE_DI_INTEN3_SHIFT                      23                                                  /*!< AFE_DI: INTEN3 Position                 */
#define AFE_DI_INTEN2_MASK                       (0x01UL << AFE_DI_INTEN2_SHIFT)                     /*!< AFE_DI: INTEN2 Mask                     */
#define AFE_DI_INTEN2_SHIFT                      24                                                  /*!< AFE_DI: INTEN2 Position                 */
#define AFE_DI_INTEN1_MASK                       (0x01UL << AFE_DI_INTEN1_SHIFT)                     /*!< AFE_DI: INTEN1 Mask                     */
#define AFE_DI_INTEN1_SHIFT                      25                                                  /*!< AFE_DI: INTEN1 Position                 */
#define AFE_DI_INTEN0_MASK                       (0x01UL << AFE_DI_INTEN0_SHIFT)                     /*!< AFE_DI: INTEN0 Mask                     */
#define AFE_DI_INTEN0_SHIFT                      26                                                  /*!< AFE_DI: INTEN0 Position                 */
#define AFE_DI_DMAEN3_MASK                       (0x01UL << AFE_DI_DMAEN3_SHIFT)                     /*!< AFE_DI: DMAEN3 Mask                     */
#define AFE_DI_DMAEN3_SHIFT                      28                                                  /*!< AFE_DI: DMAEN3 Position                 */
#define AFE_DI_DMAEN2_MASK                       (0x01UL << AFE_DI_DMAEN2_SHIFT)                     /*!< AFE_DI: DMAEN2 Mask                     */
#define AFE_DI_DMAEN2_SHIFT                      29                                                  /*!< AFE_DI: DMAEN2 Position                 */
#define AFE_DI_DMAEN1_MASK                       (0x01UL << AFE_DI_DMAEN1_SHIFT)                     /*!< AFE_DI: DMAEN1 Mask                     */
#define AFE_DI_DMAEN1_SHIFT                      30                                                  /*!< AFE_DI: DMAEN1 Position                 */
#define AFE_DI_DMAEN0_MASK                       (0x01UL << AFE_DI_DMAEN0_SHIFT)                     /*!< AFE_DI: DMAEN0 Mask                     */
#define AFE_DI_DMAEN0_SHIFT                      31                                                  /*!< AFE_DI: DMAEN0 Position                 */
/* ------- CH0_DR Bit Fields                        ------ */
#define AFE_CH0_DR_DLY_MASK                      (0x7FFUL << AFE_CH0_DR_DLY_SHIFT)                   /*!< AFE_CH0_DR: DLY Mask                    */
#define AFE_CH0_DR_DLY_SHIFT                     0                                                   /*!< AFE_CH0_DR: DLY Position                */
#define AFE_CH0_DR_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH0_DR_DLY_SHIFT))&AFE_CH0_DR_DLY_MASK) /*!< AFE_CH0_DR                              */
/* ------- CH1_DR Bit Fields                        ------ */
#define AFE_CH1_DR_DLY_MASK                      (0x7FFUL << AFE_CH1_DR_DLY_SHIFT)                   /*!< AFE_CH1_DR: DLY Mask                    */
#define AFE_CH1_DR_DLY_SHIFT                     0                                                   /*!< AFE_CH1_DR: DLY Position                */
#define AFE_CH1_DR_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH1_DR_DLY_SHIFT))&AFE_CH1_DR_DLY_MASK) /*!< AFE_CH1_DR                              */
/* ------- CH2_DR Bit Fields                        ------ */
#define AFE_CH2_DR_DLY_MASK                      (0x7FFUL << AFE_CH2_DR_DLY_SHIFT)                   /*!< AFE_CH2_DR: DLY Mask                    */
#define AFE_CH2_DR_DLY_SHIFT                     0                                                   /*!< AFE_CH2_DR: DLY Position                */
#define AFE_CH2_DR_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH2_DR_DLY_SHIFT))&AFE_CH2_DR_DLY_MASK) /*!< AFE_CH2_DR                              */
/* ------- CH3_DR Bit Fields                        ------ */
#define AFE_CH3_DR_DLY_MASK                      (0x7FFUL << AFE_CH3_DR_DLY_SHIFT)                   /*!< AFE_CH3_DR: DLY Mask                    */
#define AFE_CH3_DR_DLY_SHIFT                     0                                                   /*!< AFE_CH3_DR: DLY Position                */
#define AFE_CH3_DR_DLY(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH3_DR_DLY_SHIFT))&AFE_CH3_DR_DLY_MASK) /*!< AFE_CH3_DR                              */
/* ------- CH0_RR Bit Fields                        ------ */
#define AFE_CH0_RR_SDR_MASK                      (0x7FFFFFUL << AFE_CH0_RR_SDR_SHIFT)                /*!< AFE_CH0_RR: SDR Mask                    */
#define AFE_CH0_RR_SDR_SHIFT                     0                                                   /*!< AFE_CH0_RR: SDR Position                */
#define AFE_CH0_RR_SDR(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH0_RR_SDR_SHIFT))&AFE_CH0_RR_SDR_MASK) /*!< AFE_CH0_RR                              */
#define AFE_CH0_RR_SIGN_BITS_MASK                (0x1FFUL << AFE_CH0_RR_SIGN_BITS_SHIFT)             /*!< AFE_CH0_RR: SIGN_BITS Mask              */
#define AFE_CH0_RR_SIGN_BITS_SHIFT               23                                                  /*!< AFE_CH0_RR: SIGN_BITS Position          */
#define AFE_CH0_RR_SIGN_BITS(x)                  (((uint32_t)(((uint32_t)(x))<<AFE_CH0_RR_SIGN_BITS_SHIFT))&AFE_CH0_RR_SIGN_BITS_MASK) /*!< AFE_CH0_RR                              */
/* ------- CH1_RR Bit Fields                        ------ */
#define AFE_CH1_RR_SDR_MASK                      (0x7FFFFFUL << AFE_CH1_RR_SDR_SHIFT)                /*!< AFE_CH1_RR: SDR Mask                    */
#define AFE_CH1_RR_SDR_SHIFT                     0                                                   /*!< AFE_CH1_RR: SDR Position                */
#define AFE_CH1_RR_SDR(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH1_RR_SDR_SHIFT))&AFE_CH1_RR_SDR_MASK) /*!< AFE_CH1_RR                              */
#define AFE_CH1_RR_SIGN_BITS_MASK                (0x1FFUL << AFE_CH1_RR_SIGN_BITS_SHIFT)             /*!< AFE_CH1_RR: SIGN_BITS Mask              */
#define AFE_CH1_RR_SIGN_BITS_SHIFT               23                                                  /*!< AFE_CH1_RR: SIGN_BITS Position          */
#define AFE_CH1_RR_SIGN_BITS(x)                  (((uint32_t)(((uint32_t)(x))<<AFE_CH1_RR_SIGN_BITS_SHIFT))&AFE_CH1_RR_SIGN_BITS_MASK) /*!< AFE_CH1_RR                              */
/* ------- CH2_RR Bit Fields                        ------ */
#define AFE_CH2_RR_SDR_MASK                      (0x7FFFFFUL << AFE_CH2_RR_SDR_SHIFT)                /*!< AFE_CH2_RR: SDR Mask                    */
#define AFE_CH2_RR_SDR_SHIFT                     0                                                   /*!< AFE_CH2_RR: SDR Position                */
#define AFE_CH2_RR_SDR(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH2_RR_SDR_SHIFT))&AFE_CH2_RR_SDR_MASK) /*!< AFE_CH2_RR                              */
#define AFE_CH2_RR_SIGN_BITS_MASK                (0x1FFUL << AFE_CH2_RR_SIGN_BITS_SHIFT)             /*!< AFE_CH2_RR: SIGN_BITS Mask              */
#define AFE_CH2_RR_SIGN_BITS_SHIFT               23                                                  /*!< AFE_CH2_RR: SIGN_BITS Position          */
#define AFE_CH2_RR_SIGN_BITS(x)                  (((uint32_t)(((uint32_t)(x))<<AFE_CH2_RR_SIGN_BITS_SHIFT))&AFE_CH2_RR_SIGN_BITS_MASK) /*!< AFE_CH2_RR                              */
/* ------- CH3_RR Bit Fields                        ------ */
#define AFE_CH3_RR_SDR_MASK                      (0x7FFFFFUL << AFE_CH3_RR_SDR_SHIFT)                /*!< AFE_CH3_RR: SDR Mask                    */
#define AFE_CH3_RR_SDR_SHIFT                     0                                                   /*!< AFE_CH3_RR: SDR Position                */
#define AFE_CH3_RR_SDR(x)                        (((uint32_t)(((uint32_t)(x))<<AFE_CH3_RR_SDR_SHIFT))&AFE_CH3_RR_SDR_MASK) /*!< AFE_CH3_RR                              */
#define AFE_CH3_RR_SIGN_BITS_MASK                (0x1FFUL << AFE_CH3_RR_SIGN_BITS_SHIFT)             /*!< AFE_CH3_RR: SIGN_BITS Mask              */
#define AFE_CH3_RR_SIGN_BITS_SHIFT               23                                                  /*!< AFE_CH3_RR: SIGN_BITS Position          */
#define AFE_CH3_RR_SIGN_BITS(x)                  (((uint32_t)(((uint32_t)(x))<<AFE_CH3_RR_SIGN_BITS_SHIFT))&AFE_CH3_RR_SIGN_BITS_MASK) /*!< AFE_CH3_RR                              */
/* ------- SR Bit Fields                            ------ */
#define AFE_SR_RDY3_MASK                         (0x01UL << AFE_SR_RDY3_SHIFT)                       /*!< AFE_SR: RDY3 Mask                       */
#define AFE_SR_RDY3_SHIFT                        16                                                  /*!< AFE_SR: RDY3 Position                   */
#define AFE_SR_RDY2_MASK                         (0x01UL << AFE_SR_RDY2_SHIFT)                       /*!< AFE_SR: RDY2 Mask                       */
#define AFE_SR_RDY2_SHIFT                        17                                                  /*!< AFE_SR: RDY2 Position                   */
#define AFE_SR_RDY1_MASK                         (0x01UL << AFE_SR_RDY1_SHIFT)                       /*!< AFE_SR: RDY1 Mask                       */
#define AFE_SR_RDY1_SHIFT                        18                                                  /*!< AFE_SR: RDY1 Position                   */
#define AFE_SR_RDY0_MASK                         (0x01UL << AFE_SR_RDY0_SHIFT)                       /*!< AFE_SR: RDY0 Mask                       */
#define AFE_SR_RDY0_SHIFT                        19                                                  /*!< AFE_SR: RDY0 Position                   */
#define AFE_SR_OVR3_MASK                         (0x01UL << AFE_SR_OVR3_SHIFT)                       /*!< AFE_SR: OVR3 Mask                       */
#define AFE_SR_OVR3_SHIFT                        21                                                  /*!< AFE_SR: OVR3 Position                   */
#define AFE_SR_OVR2_MASK                         (0x01UL << AFE_SR_OVR2_SHIFT)                       /*!< AFE_SR: OVR2 Mask                       */
#define AFE_SR_OVR2_SHIFT                        22                                                  /*!< AFE_SR: OVR2 Position                   */
#define AFE_SR_OVR1_MASK                         (0x01UL << AFE_SR_OVR1_SHIFT)                       /*!< AFE_SR: OVR1 Mask                       */
#define AFE_SR_OVR1_SHIFT                        23                                                  /*!< AFE_SR: OVR1 Position                   */
#define AFE_SR_OVR0_MASK                         (0x01UL << AFE_SR_OVR0_SHIFT)                       /*!< AFE_SR: OVR0 Mask                       */
#define AFE_SR_OVR0_SHIFT                        24                                                  /*!< AFE_SR: OVR0 Position                   */
#define AFE_SR_COC3_MASK                         (0x01UL << AFE_SR_COC3_SHIFT)                       /*!< AFE_SR: COC3 Mask                       */
#define AFE_SR_COC3_SHIFT                        28                                                  /*!< AFE_SR: COC3 Position                   */
#define AFE_SR_COC2_MASK                         (0x01UL << AFE_SR_COC2_SHIFT)                       /*!< AFE_SR: COC2 Mask                       */
#define AFE_SR_COC2_SHIFT                        29                                                  /*!< AFE_SR: COC2 Position                   */
#define AFE_SR_COC1_MASK                         (0x01UL << AFE_SR_COC1_SHIFT)                       /*!< AFE_SR: COC1 Mask                       */
#define AFE_SR_COC1_SHIFT                        30                                                  /*!< AFE_SR: COC1 Position                   */
#define AFE_SR_COC0_MASK                         (0x01UL << AFE_SR_COC0_SHIFT)                       /*!< AFE_SR: COC0 Mask                       */
#define AFE_SR_COC0_SHIFT                        31                                                  /*!< AFE_SR: COC0 Position                   */
/**
 * @} */ /* End group AFE_Register_Masks_GROUP 
 */

/* AFE - Peripheral instance base addresses */
#define AFE_BasePtr                    0x40030000UL //!< Peripheral base address
#define AFE                            ((AFE_Type *) AFE_BasePtr) //!< Freescale base pointer
#define AFE_BASE_PTR                   (AFE) //!< Freescale style base pointer
/**
 * @} */ /* End group AFE_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_0x40072000)          ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       CMP0 Structure                                               */
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define CMP_CR0_HYSTCTR_MASK                     (0x03UL << CMP_CR0_HYSTCTR_SHIFT)                   /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    0                                                   /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x07UL << CMP_CR0_FILTER_CNT_SHIFT)                /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 4                                                   /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x01UL << CMP_CR1_EN_SHIFT)                        /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         0                                                   /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_OPE_MASK                         (0x01UL << CMP_CR1_OPE_SHIFT)                       /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        1                                                   /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_COS_MASK                         (0x01UL << CMP_CR1_COS_SHIFT)                       /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        2                                                   /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_INV_MASK                         (0x01UL << CMP_CR1_INV_SHIFT)                       /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        3                                                   /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_PMODE_MASK                       (0x01UL << CMP_CR1_PMODE_SHIFT)                     /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      4                                                   /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_TRIGM_MASK                       (0x01UL << CMP_CR1_TRIGM_SHIFT)                     /*!< CMP0_CR1: TRIGM Mask                    */
#define CMP_CR1_TRIGM_SHIFT                      5                                                   /*!< CMP0_CR1: TRIGM Position                */
#define CMP_CR1_WE_MASK                          (0x01UL << CMP_CR1_WE_SHIFT)                        /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         6                                                   /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_SE_MASK                          (0x01UL << CMP_CR1_SE_SHIFT)                        /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         7                                                   /*!< CMP0_CR1: SE Position                   */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFUL << CMP_FPR_FILT_PER_SHIFT)                  /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   0                                                   /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x01UL << CMP_SCR_COUT_SHIFT)                      /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       0                                                   /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_CFF_MASK                         (0x01UL << CMP_SCR_CFF_SHIFT)                       /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        1                                                   /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFR_MASK                         (0x01UL << CMP_SCR_CFR_SHIFT)                       /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        2                                                   /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_IEF_MASK                         (0x01UL << CMP_SCR_IEF_SHIFT)                       /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        3                                                   /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IER_MASK                         (0x01UL << CMP_SCR_IER_SHIFT)                       /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        4                                                   /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_DMAEN_MASK                       (0x01UL << CMP_SCR_DMAEN_SHIFT)                     /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      6                                                   /*!< CMP0_SCR: DMAEN Position                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FUL << CMP_DACCR_VOSEL_SHIFT)                   /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    0                                                   /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x01UL << CMP_DACCR_VRSEL_SHIFT)                   /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    6                                                   /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_DACEN_MASK                     (0x01UL << CMP_DACCR_DACEN_SHIFT)                   /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    7                                                   /*!< CMP0_DACCR: DACEN Position              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x07UL << CMP_MUXCR_MSEL_SHIFT)                    /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     0                                                   /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x07UL << CMP_MUXCR_PSEL_SHIFT)                    /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     3                                                   /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40072000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP1 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP1 - Peripheral instance base addresses */
#define CMP1_BasePtr                   0x40072008UL //!< Peripheral base address
#define CMP1                           ((CMP_Type *) CMP1_BasePtr) //!< Freescale base pointer
#define CMP1_BASE_PTR                  (CMP1) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC (file:CRC_0x40034000)            ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC Structure                                                */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /**< 0000: CRC Data register                                            */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: CRC_DATAL register                                           */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: CRC_DATALL register                                          */
               __IO uint8_t   DATALU;           /**< 0001: CRC_DATALU register                                          */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: CRC_DATAH register                                           */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: CRC_DATAHL register                                          */
               __IO uint8_t   DATAHU;           /**< 0003: CRC_DATAHU register                                          */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: CRC Polynomial register                                      */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0004: CRC_GPOLYL register                                          */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /**< 0004: CRC_GPOLYLL register                                         */
               __IO uint8_t   GPOLYLU;          /**< 0005: CRC_GPOLYLU register                                         */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0006: CRC_GPOLYH register                                          */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /**< 0006: CRC_GPOLYHL register                                         */
               __IO uint8_t   GPOLYHU;          /**< 0007: CRC_GPOLYHU register                                         */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: CRC Control register                                         */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __I  uint8_t   RESERVED0[3];          
         __IO uint8_t   CTRLHU;                 /**< 000B: CRC_CTRLHU register                                          */
      };
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define CRC_DATA_LL_MASK                         (0xFFUL << CRC_DATA_LL_SHIFT)                       /*!< CRC_DATA: LL Mask                       */
#define CRC_DATA_LL_SHIFT                        0                                                   /*!< CRC_DATA: LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_LU_MASK                         (0xFFUL << CRC_DATA_LU_SHIFT)                       /*!< CRC_DATA: LU Mask                       */
#define CRC_DATA_LU_SHIFT                        8                                                   /*!< CRC_DATA: LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HL_MASK                         (0xFFUL << CRC_DATA_HL_SHIFT)                       /*!< CRC_DATA: HL Mask                       */
#define CRC_DATA_HL_SHIFT                        16                                                  /*!< CRC_DATA: HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HU_MASK                         (0xFFUL << CRC_DATA_HU_SHIFT)                       /*!< CRC_DATA: HU Mask                       */
#define CRC_DATA_HU_SHIFT                        24                                                  /*!< CRC_DATA: HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK) /*!< CRC_DATA                                */
/* ------- DATAL Bit Fields                         ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFUL << CRC_DATAL_DATAL_SHIFT)                 /*!< CRC_DATAL: DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    0                                                   /*!< CRC_DATAL: DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK) /*!< CRC_DATAL                               */
/* ------- DATALL Bit Fields                        ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFUL << CRC_DATALL_DATALL_SHIFT)                 /*!< CRC_DATALL: DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  0                                                   /*!< CRC_DATALL: DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK) /*!< CRC_DATALL                              */
/* ------- DATALU Bit Fields                        ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFUL << CRC_DATALU_DATALU_SHIFT)                 /*!< CRC_DATALU: DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  0                                                   /*!< CRC_DATALU: DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK) /*!< CRC_DATALU                              */
/* ------- DATAH Bit Fields                         ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFUL << CRC_DATAH_DATAH_SHIFT)                 /*!< CRC_DATAH: DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    0                                                   /*!< CRC_DATAH: DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK) /*!< CRC_DATAH                               */
/* ------- DATAHL Bit Fields                        ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFUL << CRC_DATAHL_DATAHL_SHIFT)                 /*!< CRC_DATAHL: DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  0                                                   /*!< CRC_DATAHL: DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK) /*!< CRC_DATAHL                              */
/* ------- DATAHU Bit Fields                        ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFUL << CRC_DATAHU_DATAHU_SHIFT)                 /*!< CRC_DATAHU: DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  0                                                   /*!< CRC_DATAHU: DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK) /*!< CRC_DATAHU                              */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL << CRC_GPOLY_LOW_SHIFT)                   /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      0                                                   /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFFUL << CRC_GPOLY_HIGH_SHIFT)                  /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     16                                                  /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /*!< CRC_GPOLY                               */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFUL << CRC_GPOLYL_GPOLYL_SHIFT)               /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  0                                                   /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFUL << CRC_GPOLYLL_GPOLYLL_SHIFT)               /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0                                                   /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFUL << CRC_GPOLYLU_GPOLYLU_SHIFT)               /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0                                                   /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFUL << CRC_GPOLYH_GPOLYH_SHIFT)               /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  0                                                   /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFUL << CRC_GPOLYHL_GPOLYHL_SHIFT)               /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0                                                   /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFUL << CRC_GPOLYHU_GPOLYHU_SHIFT)               /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0                                                   /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x01UL << CRC_CTRL_TCRC_SHIFT)                     /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      24                                                  /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_WAS_MASK                        (0x01UL << CRC_CTRL_WAS_SHIFT)                      /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       25                                                  /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_FXOR_MASK                       (0x01UL << CRC_CTRL_FXOR_SHIFT)                     /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      26                                                  /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_TOTR_MASK                       (0x03UL << CRC_CTRL_TOTR_SHIFT)                     /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      28                                                  /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0x03UL << CRC_CTRL_TOT_SHIFT)                      /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       30                                                  /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /*!< CRC_CTRL                                */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x01UL << CRC_CTRLHU_TCRC_SHIFT)                   /*!< CRC_CTRLHU: TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    0                                                   /*!< CRC_CTRLHU: TCRC Position               */
#define CRC_CTRLHU_WAS_MASK                      (0x01UL << CRC_CTRLHU_WAS_SHIFT)                    /*!< CRC_CTRLHU: WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     1                                                   /*!< CRC_CTRLHU: WAS Position                */
#define CRC_CTRLHU_FXOR_MASK                     (0x01UL << CRC_CTRLHU_FXOR_SHIFT)                   /*!< CRC_CTRLHU: FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    2                                                   /*!< CRC_CTRLHU: FXOR Position               */
#define CRC_CTRLHU_TOTR_MASK                     (0x03UL << CRC_CTRLHU_TOTR_SHIFT)                   /*!< CRC_CTRLHU: TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    4                                                   /*!< CRC_CTRLHU: TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOT_MASK                      (0x03UL << CRC_CTRLHU_TOT_SHIFT)                    /*!< CRC_CTRLHU: TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     6                                                   /*!< CRC_CTRLHU: TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK) /*!< CRC_CTRLHU                              */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0x40034000UL //!< Peripheral base address
#define CRC                            ((CRC_Type *) CRC_BasePtr) //!< Freescale base pointer
#define CRC_BASE_PTR                   (CRC) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer
* @brief C Struct for DMA0
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA0_structs_GROUP DMA0 struct
* @brief Struct for DMA0
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
   __I  uint32_t  RESERVED0[64];               
   struct {
      __IO uint32_t  SAR;                       /**< 0100: Source Address Register                                      */
      __IO uint32_t  DAR;                       /**< 0104: Destination Address Register                                 */
      union {                                   /**< 0100: (size=0004)                                                  */
         __IO uint32_t  DSR_BCR;                /**< 0108: DMA Status / Byte Count Register                             */
         struct {                               /**< 0100: (size=0004)                                                  */
            __I  uint8_t   RESERVED0[3];       
            __IO uint8_t   DSR;                 /**< 010B: DMA Status Register                                          */
         };
      };
      __IO uint32_t  DCR;                       /**< 010C: DMA Control Register                                         */
   } DMA[4];                                    /**< 0100: (cluster: size=0x0040, 64)                                   */
} DMA_Type;

/**
 * @} */ /* End group DMA0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks
* @brief Register Masks for DMA0
* @{
*/
/* ------- SAR Bit Fields                           ------ */
/* ------- DAR Bit Fields                           ------ */
/* ------- DSR_BCR Bit Fields                       ------ */
#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFUL << DMA_DSR_BCR_BCR_SHIFT)               /*!< DMA0_DSR_BCR: BCR Mask                  */
#define DMA_DSR_BCR_BCR_SHIFT                    0                                                   /*!< DMA0_DSR_BCR: BCR Position              */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_DONE_MASK                    (0x01UL << DMA_DSR_BCR_DONE_SHIFT)                  /*!< DMA0_DSR_BCR: DONE Mask                 */
#define DMA_DSR_BCR_DONE_SHIFT                   24                                                  /*!< DMA0_DSR_BCR: DONE Position             */
#define DMA_DSR_BCR_BSY_MASK                     (0x01UL << DMA_DSR_BCR_BSY_SHIFT)                   /*!< DMA0_DSR_BCR: BSY Mask                  */
#define DMA_DSR_BCR_BSY_SHIFT                    25                                                  /*!< DMA0_DSR_BCR: BSY Position              */
#define DMA_DSR_BCR_REQ_MASK                     (0x01UL << DMA_DSR_BCR_REQ_SHIFT)                   /*!< DMA0_DSR_BCR: REQ Mask                  */
#define DMA_DSR_BCR_REQ_SHIFT                    26                                                  /*!< DMA0_DSR_BCR: REQ Position              */
#define DMA_DSR_BCR_BED_MASK                     (0x01UL << DMA_DSR_BCR_BED_SHIFT)                   /*!< DMA0_DSR_BCR: BED Mask                  */
#define DMA_DSR_BCR_BED_SHIFT                    28                                                  /*!< DMA0_DSR_BCR: BED Position              */
#define DMA_DSR_BCR_BES_MASK                     (0x01UL << DMA_DSR_BCR_BES_SHIFT)                   /*!< DMA0_DSR_BCR: BES Mask                  */
#define DMA_DSR_BCR_BES_SHIFT                    29                                                  /*!< DMA0_DSR_BCR: BES Position              */
#define DMA_DSR_BCR_CE_MASK                      (0x01UL << DMA_DSR_BCR_CE_SHIFT)                    /*!< DMA0_DSR_BCR: CE Mask                   */
#define DMA_DSR_BCR_CE_SHIFT                     30                                                  /*!< DMA0_DSR_BCR: CE Position               */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x01UL << DMA_DSR_DONE_SHIFT)                      /*!< DMA0_DSR: DONE Mask                     */
#define DMA_DSR_DONE_SHIFT                       0                                                   /*!< DMA0_DSR: DONE Position                 */
#define DMA_DSR_BSY_MASK                         (0x01UL << DMA_DSR_BSY_SHIFT)                       /*!< DMA0_DSR: BSY Mask                      */
#define DMA_DSR_BSY_SHIFT                        1                                                   /*!< DMA0_DSR: BSY Position                  */
#define DMA_DSR_REQ_MASK                         (0x01UL << DMA_DSR_REQ_SHIFT)                       /*!< DMA0_DSR: REQ Mask                      */
#define DMA_DSR_REQ_SHIFT                        2                                                   /*!< DMA0_DSR: REQ Position                  */
#define DMA_DSR_BED_MASK                         (0x01UL << DMA_DSR_BED_SHIFT)                       /*!< DMA0_DSR: BED Mask                      */
#define DMA_DSR_BED_SHIFT                        4                                                   /*!< DMA0_DSR: BED Position                  */
#define DMA_DSR_BES_MASK                         (0x01UL << DMA_DSR_BES_SHIFT)                       /*!< DMA0_DSR: BES Mask                      */
#define DMA_DSR_BES_SHIFT                        5                                                   /*!< DMA0_DSR: BES Position                  */
#define DMA_DSR_CE_MASK                          (0x01UL << DMA_DSR_CE_SHIFT)                        /*!< DMA0_DSR: CE Mask                       */
#define DMA_DSR_CE_SHIFT                         6                                                   /*!< DMA0_DSR: CE Position                   */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x03UL << DMA_DCR_LCH2_SHIFT)                      /*!< DMA0_DCR: LCH2 Mask                     */
#define DMA_DCR_LCH2_SHIFT                       0                                                   /*!< DMA0_DCR: LCH2 Position                 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LCH1_MASK                        (0x03UL << DMA_DCR_LCH1_SHIFT)                      /*!< DMA0_DCR: LCH1 Mask                     */
#define DMA_DCR_LCH1_SHIFT                       2                                                   /*!< DMA0_DCR: LCH1 Position                 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LINKCC_MASK                      (0x03UL << DMA_DCR_LINKCC_SHIFT)                    /*!< DMA0_DCR: LINKCC Mask                   */
#define DMA_DCR_LINKCC_SHIFT                     4                                                   /*!< DMA0_DCR: LINKCC Position               */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_D_REQ_MASK                       (0x01UL << DMA_DCR_D_REQ_SHIFT)                     /*!< DMA0_DCR: D_REQ Mask                    */
#define DMA_DCR_D_REQ_SHIFT                      7                                                   /*!< DMA0_DCR: D_REQ Position                */
#define DMA_DCR_DMOD_MASK                        (0x0FUL << DMA_DCR_DMOD_SHIFT)                      /*!< DMA0_DCR: DMOD Mask                     */
#define DMA_DCR_DMOD_SHIFT                       8                                                   /*!< DMA0_DCR: DMOD Position                 */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SMOD_MASK                        (0x0FUL << DMA_DCR_SMOD_SHIFT)                      /*!< DMA0_DCR: SMOD Mask                     */
#define DMA_DCR_SMOD_SHIFT                       12                                                  /*!< DMA0_DCR: SMOD Position                 */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_START_MASK                       (0x01UL << DMA_DCR_START_SHIFT)                     /*!< DMA0_DCR: START Mask                    */
#define DMA_DCR_START_SHIFT                      16                                                  /*!< DMA0_DCR: START Position                */
#define DMA_DCR_DSIZE_MASK                       (0x03UL << DMA_DCR_DSIZE_SHIFT)                     /*!< DMA0_DCR: DSIZE Mask                    */
#define DMA_DCR_DSIZE_SHIFT                      17                                                  /*!< DMA0_DCR: DSIZE Position                */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_DINC_MASK                        (0x01UL << DMA_DCR_DINC_SHIFT)                      /*!< DMA0_DCR: DINC Mask                     */
#define DMA_DCR_DINC_SHIFT                       19                                                  /*!< DMA0_DCR: DINC Position                 */
#define DMA_DCR_SSIZE_MASK                       (0x03UL << DMA_DCR_SSIZE_SHIFT)                     /*!< DMA0_DCR: SSIZE Mask                    */
#define DMA_DCR_SSIZE_SHIFT                      20                                                  /*!< DMA0_DCR: SSIZE Position                */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SINC_MASK                        (0x01UL << DMA_DCR_SINC_SHIFT)                      /*!< DMA0_DCR: SINC Mask                     */
#define DMA_DCR_SINC_SHIFT                       22                                                  /*!< DMA0_DCR: SINC Position                 */
#define DMA_DCR_EADREQ_MASK                      (0x01UL << DMA_DCR_EADREQ_SHIFT)                    /*!< DMA0_DCR: EADREQ Mask                   */
#define DMA_DCR_EADREQ_SHIFT                     23                                                  /*!< DMA0_DCR: EADREQ Position               */
#define DMA_DCR_UMNSM_MASK                       (0x03UL << DMA_DCR_UMNSM_SHIFT)                     /*!< DMA0_DCR: UMNSM Mask                    */
#define DMA_DCR_UMNSM_SHIFT                      24                                                  /*!< DMA0_DCR: UMNSM Position                */
#define DMA_DCR_UMNSM(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_UMNSM_SHIFT))&DMA_DCR_UMNSM_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_CHACR_MASK                       (0x03UL << DMA_DCR_CHACR_SHIFT)                     /*!< DMA0_DCR: CHACR Mask                    */
#define DMA_DCR_CHACR_SHIFT                      26                                                  /*!< DMA0_DCR: CHACR Position                */
#define DMA_DCR_CHACR(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_CHACR_SHIFT))&DMA_DCR_CHACR_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_AA_MASK                          (0x01UL << DMA_DCR_AA_SHIFT)                        /*!< DMA0_DCR: AA Mask                       */
#define DMA_DCR_AA_SHIFT                         28                                                  /*!< DMA0_DCR: AA Position                   */
#define DMA_DCR_CS_MASK                          (0x01UL << DMA_DCR_CS_SHIFT)                        /*!< DMA0_DCR: CS Mask                       */
#define DMA_DCR_CS_SHIFT                         29                                                  /*!< DMA0_DCR: CS Position                   */
#define DMA_DCR_ERQ_MASK                         (0x01UL << DMA_DCR_ERQ_SHIFT)                       /*!< DMA0_DCR: ERQ Mask                      */
#define DMA_DCR_ERQ_SHIFT                        30                                                  /*!< DMA0_DCR: ERQ Position                  */
#define DMA_DCR_EINT_MASK                        (0x01UL << DMA_DCR_EINT_SHIFT)                      /*!< DMA0_DCR: EINT Mask                     */
#define DMA_DCR_EINT_SHIFT                       31                                                  /*!< DMA0_DCR: EINT Position                 */
/**
 * @} */ /* End group DMA0_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_1CH_TRIG)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX0 Structure                                            */
   __IO uint8_t   CHCFG;                        /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FUL << DMAMUX_CHCFG_SOURCE_SHIFT)               /*!< DMAMUX0_CHCFG: SOURCE Mask              */
#define DMAMUX_CHCFG_SOURCE_SHIFT                0                                                   /*!< DMAMUX0_CHCFG: SOURCE Position          */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x01UL << DMAMUX_CHCFG_TRIG_SHIFT)                 /*!< DMAMUX0_CHCFG: TRIG Mask                */
#define DMAMUX_CHCFG_TRIG_SHIFT                  6                                                   /*!< DMAMUX0_CHCFG: TRIG Position            */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x01UL << DMAMUX_CHCFG_ENBL_SHIFT)                 /*!< DMAMUX0_CHCFG: ENBL Mask                */
#define DMAMUX_CHCFG_ENBL_SHIFT                  7                                                   /*!< DMAMUX0_CHCFG: ENBL Position            */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX1 (derived from DMAMUX0)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */

/* DMAMUX1 - Peripheral instance base addresses */
#define DMAMUX1_BasePtr                0x40022000UL //!< Peripheral base address
#define DMAMUX1                        ((DMAMUX_Type *) DMAMUX1_BasePtr) //!< Freescale base pointer
#define DMAMUX1_BASE_PTR               (DMAMUX1) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX2 (derived from DMAMUX0)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */

/* DMAMUX2 - Peripheral instance base addresses */
#define DMAMUX2_BasePtr                0x40023000UL //!< Peripheral base address
#define DMAMUX2                        ((DMAMUX_Type *) DMAMUX2_BasePtr) //!< Freescale base pointer
#define DMAMUX2_BASE_PTR               (DMAMUX2) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX3 (derived from DMAMUX0)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */

/* DMAMUX3 - Peripheral instance base addresses */
#define DMAMUX3_BasePtr                0x40024000UL //!< Peripheral base address
#define DMAMUX3                        ((DMAMUX_Type *) DMAMUX3_BasePtr) //!< Freescale base pointer
#define DMAMUX3_BASE_PTR               (DMAMUX3) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_2)                     ================ */
/* ================================================================================ */

/**
 * @brief External Watchdog Monitor
 */
/**
* @addtogroup EWM_structs_GROUP EWM struct
* @brief Struct for EWM
* @{
*/
typedef struct {                                /*       EWM Structure                                                */
   __IO uint8_t   CTRL;                         /**< 0000: Control Register                                             */
   __O  uint8_t   SERV;                         /**< 0001: Service Register                                             */
   __IO uint8_t   CMPL;                         /**< 0002: Compare Low Register                                         */
   __IO uint8_t   CMPH;                         /**< 0003: Compare High Register                                        */
} EWM_Type;

/**
 * @} */ /* End group EWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EWM_Register_Masks_GROUP EWM Register Masks
* @brief Register Masks for EWM
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define EWM_CTRL_EWMEN_MASK                      (0x01UL << EWM_CTRL_EWMEN_SHIFT)                    /*!< EWM_CTRL: EWMEN Mask                    */
#define EWM_CTRL_EWMEN_SHIFT                     0                                                   /*!< EWM_CTRL: EWMEN Position                */
#define EWM_CTRL_ASSIN_MASK                      (0x01UL << EWM_CTRL_ASSIN_SHIFT)                    /*!< EWM_CTRL: ASSIN Mask                    */
#define EWM_CTRL_ASSIN_SHIFT                     1                                                   /*!< EWM_CTRL: ASSIN Position                */
#define EWM_CTRL_INEN_MASK                       (0x01UL << EWM_CTRL_INEN_SHIFT)                     /*!< EWM_CTRL: INEN Mask                     */
#define EWM_CTRL_INEN_SHIFT                      2                                                   /*!< EWM_CTRL: INEN Position                 */
#define EWM_CTRL_INTEN_MASK                      (0x01UL << EWM_CTRL_INTEN_SHIFT)                    /*!< EWM_CTRL: INTEN Mask                    */
#define EWM_CTRL_INTEN_SHIFT                     3                                                   /*!< EWM_CTRL: INTEN Position                */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFUL << EWM_SERV_SERVICE_SHIFT)                  /*!< EWM_SERV: SERVICE Mask                  */
#define EWM_SERV_SERVICE_SHIFT                   0                                                   /*!< EWM_SERV: SERVICE Position              */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK) /*!< EWM_SERV                                */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFUL << EWM_CMPL_COMPAREL_SHIFT)                 /*!< EWM_CMPL: COMPAREL Mask                 */
#define EWM_CMPL_COMPAREL_SHIFT                  0                                                   /*!< EWM_CMPL: COMPAREL Position             */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK) /*!< EWM_CMPL                                */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFUL << EWM_CMPH_COMPAREH_SHIFT)                 /*!< EWM_CMPH: COMPAREH Mask                 */
#define EWM_CMPH_COMPAREH_SHIFT                  0                                                   /*!< EWM_CMPH: COMPAREH Position             */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK) /*!< EWM_CMPH                                */
/**
 * @} */ /* End group EWM_Register_Masks_GROUP 
 */

/* EWM - Peripheral instance base addresses */
#define EWM_BasePtr                    0x40061000UL //!< Peripheral base address
#define EWM                            ((EWM_Type *) EWM_BasePtr) //!< Freescale base pointer
#define EWM_BASE_PTR                   (EWM) //!< Freescale style base pointer
/**
 * @} */ /* End group EWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFA_Peripheral_access_layer_GROUP FTFA Peripheral Access Layer
* @brief C Struct for FTFA
* @{
*/

/* ================================================================================ */
/* ================           FTFA (file:FTFA)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFA_structs_GROUP FTFA struct
* @brief Struct for FTFA
* @{
*/
typedef struct {                                /*       FTFA Structure                                               */
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

/**
 * @} */ /* End group FTFA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFA_Register_Masks_GROUP FTFA Register Masks
* @brief Register Masks for FTFA
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x01UL << FTFA_FSTAT_MGSTAT0_SHIFT)                /*!< FTFA_FSTAT: MGSTAT0 Mask                */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 0                                                   /*!< FTFA_FSTAT: MGSTAT0 Position            */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x01UL << FTFA_FSTAT_FPVIOL_SHIFT)                 /*!< FTFA_FSTAT: FPVIOL Mask                 */
#define FTFA_FSTAT_FPVIOL_SHIFT                  4                                                   /*!< FTFA_FSTAT: FPVIOL Position             */
#define FTFA_FSTAT_ACCERR_MASK                   (0x01UL << FTFA_FSTAT_ACCERR_SHIFT)                 /*!< FTFA_FSTAT: ACCERR Mask                 */
#define FTFA_FSTAT_ACCERR_SHIFT                  5                                                   /*!< FTFA_FSTAT: ACCERR Position             */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x01UL << FTFA_FSTAT_RDCOLERR_SHIFT)               /*!< FTFA_FSTAT: RDCOLERR Mask               */
#define FTFA_FSTAT_RDCOLERR_SHIFT                6                                                   /*!< FTFA_FSTAT: RDCOLERR Position           */
#define FTFA_FSTAT_CCIF_MASK                     (0x01UL << FTFA_FSTAT_CCIF_SHIFT)                   /*!< FTFA_FSTAT: CCIF Mask                   */
#define FTFA_FSTAT_CCIF_SHIFT                    7                                                   /*!< FTFA_FSTAT: CCIF Position               */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x01UL << FTFA_FCNFG_ERSSUSP_SHIFT)                /*!< FTFA_FCNFG: ERSSUSP Mask                */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 4                                                   /*!< FTFA_FCNFG: ERSSUSP Position            */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x01UL << FTFA_FCNFG_ERSAREQ_SHIFT)                /*!< FTFA_FCNFG: ERSAREQ Mask                */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 5                                                   /*!< FTFA_FCNFG: ERSAREQ Position            */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x01UL << FTFA_FCNFG_RDCOLLIE_SHIFT)               /*!< FTFA_FCNFG: RDCOLLIE Mask               */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                6                                                   /*!< FTFA_FCNFG: RDCOLLIE Position           */
#define FTFA_FCNFG_CCIE_MASK                     (0x01UL << FTFA_FCNFG_CCIE_SHIFT)                   /*!< FTFA_FCNFG: CCIE Mask                   */
#define FTFA_FCNFG_CCIE_SHIFT                    7                                                   /*!< FTFA_FCNFG: CCIE Position               */
/* ------- FSEC Bit Fields                          ------ */
#define FTFA_FSEC_SEC_MASK                       (0x03UL << FTFA_FSEC_SEC_SHIFT)                     /*!< FTFA_FSEC: SEC Mask                     */
#define FTFA_FSEC_SEC_SHIFT                      0                                                   /*!< FTFA_FSEC: SEC Position                 */
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_FSLACC_MASK                    (0x03UL << FTFA_FSEC_FSLACC_SHIFT)                  /*!< FTFA_FSEC: FSLACC Mask                  */
#define FTFA_FSEC_FSLACC_SHIFT                   2                                                   /*!< FTFA_FSEC: FSLACC Position              */
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_MEEN_MASK                      (0x03UL << FTFA_FSEC_MEEN_SHIFT)                    /*!< FTFA_FSEC: MEEN Mask                    */
#define FTFA_FSEC_MEEN_SHIFT                     4                                                   /*!< FTFA_FSEC: MEEN Position                */
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_KEYEN_MASK                     (0x03UL << FTFA_FSEC_KEYEN_SHIFT)                   /*!< FTFA_FSEC: KEYEN Mask                   */
#define FTFA_FSEC_KEYEN_SHIFT                    6                                                   /*!< FTFA_FSEC: KEYEN Position               */
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK) /*!< FTFA_FSEC                               */
/* ------- FOPT Bit Fields                          ------ */
#define FTFA_FOPT_OPT_MASK                       (0xFFUL << FTFA_FOPT_OPT_SHIFT)                     /*!< FTFA_FOPT: OPT Mask                     */
#define FTFA_FOPT_OPT_SHIFT                      0                                                   /*!< FTFA_FOPT: OPT Position                 */
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK) /*!< FTFA_FOPT                               */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFUL << FTFA_FCCOB_CCOBn_SHIFT)                  /*!< FTFA_FCCOB: CCOBn Mask                  */
#define FTFA_FCCOB_CCOBn_SHIFT                   0                                                   /*!< FTFA_FCCOB: CCOBn Position              */
#define FTFA_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB_CCOBn_SHIFT))&FTFA_FCCOB_CCOBn_MASK) /*!< FTFA_FCCOB                              */
/* ------- FPROT Bit Fields                         ------ */
#define FTFA_FPROT_PROT_MASK                     (0xFFUL << FTFA_FPROT_PROT_SHIFT)                   /*!< FTFA_FPROT: PROT Mask                   */
#define FTFA_FPROT_PROT_SHIFT                    0                                                   /*!< FTFA_FPROT: PROT Position               */
#define FTFA_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT_PROT_SHIFT))&FTFA_FPROT_PROT_MASK) /*!< FTFA_FPROT                              */
/**
 * @} */ /* End group FTFA_Register_Masks_GROUP 
 */

/* FTFA - Peripheral instance base addresses */
#define FTFA_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFA                           ((FTFA_Type *) FTFA_BasePtr) //!< Freescale base pointer
#define FTFA_BASE_PTR                  (FTFA) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_MKM)               ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup GPIOA_structs_GROUP GPIOA struct
* @brief Struct for GPIOA
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint8_t   PDOR;                         /**< 0000: Port Data Output Register                                    */
   __I  uint8_t   RESERVED0[15];               
   __I  uint8_t   PDIR;                         /**< 0010: Port Data Input Register                                     */
   __I  uint8_t   RESERVED1[3];                
   __IO uint8_t   PDDR;                         /**< 0014: Port Data Direction Register                                 */
   __I  uint8_t   RESERVED2[7];                
   __IO uint8_t   GACR;                         /**< 001C: GPIO Attribute Checker Register                              */
} GPIO_Type;

/**
 * @} */ /* End group GPIOA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIOA_Register_Masks_GROUP GPIOA Register Masks
* @brief Register Masks for GPIOA
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/* ------- GACR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIOA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF001UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF002UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF003UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOF (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOF - Peripheral instance base addresses */
#define GPIOF_BasePtr                  0x400FF041UL //!< Peripheral base address
#define GPIOF                          ((GPIO_Type *) GPIOF_BasePtr) //!< Freescale base pointer
#define GPIOF_BASE_PTR                 (GPIOF) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOG (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOG - Peripheral instance base addresses */
#define GPIOG_BasePtr                  0x400FF042UL //!< Peripheral base address
#define GPIOG                          ((GPIO_Type *) GPIOG_BasePtr) //!< Freescale base pointer
#define GPIOG_BASE_PTR                 (GPIOG) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOH (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOH - Peripheral instance base addresses */
#define GPIOH_BasePtr                  0x400FF043UL //!< Peripheral base address
#define GPIOH                          ((GPIO_Type *) GPIOH_BasePtr) //!< Freescale base pointer
#define GPIOH_BASE_PTR                 (GPIOH) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOI (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOI - Peripheral instance base addresses */
#define GPIOI_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOI                          ((GPIO_Type *) GPIOI_BasePtr) //!< Freescale base pointer
#define GPIOI_BASE_PTR                 (GPIOI) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C0 Structure                                               */
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

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- A1 Bit Fields                            ------ */
#define I2C_A1_AD_MASK                           (0x7FUL << I2C_A1_AD_SHIFT)                         /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          1                                                   /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FUL << I2C_F_ICR_SHIFT)                         /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          0                                                   /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0x03UL << I2C_F_MULT_SHIFT)                        /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         6                                                   /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x01UL << I2C_C1_DMAEN_SHIFT)                      /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       0                                                   /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_WUEN_MASK                         (0x01UL << I2C_C1_WUEN_SHIFT)                       /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        1                                                   /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_RSTA_MASK                         (0x01UL << I2C_C1_RSTA_SHIFT)                       /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        2                                                   /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_TXAK_MASK                         (0x01UL << I2C_C1_TXAK_SHIFT)                       /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        3                                                   /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TX_MASK                           (0x01UL << I2C_C1_TX_SHIFT)                         /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          4                                                   /*!< I2C0_C1: TX Position                    */
#define I2C_C1_MST_MASK                          (0x01UL << I2C_C1_MST_SHIFT)                        /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         5                                                   /*!< I2C0_C1: MST Position                   */
#define I2C_C1_IICIE_MASK                        (0x01UL << I2C_C1_IICIE_SHIFT)                      /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       6                                                   /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICEN_MASK                        (0x01UL << I2C_C1_IICEN_SHIFT)                      /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       7                                                   /*!< I2C0_C1: IICEN Position                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x01UL << I2C_S_RXAK_SHIFT)                        /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         0                                                   /*!< I2C0_S: RXAK Position                   */
#define I2C_S_IICIF_MASK                         (0x01UL << I2C_S_IICIF_SHIFT)                       /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        1                                                   /*!< I2C0_S: IICIF Position                  */
#define I2C_S_SRW_MASK                           (0x01UL << I2C_S_SRW_SHIFT)                         /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          2                                                   /*!< I2C0_S: SRW Position                    */
#define I2C_S_RAM_MASK                           (0x01UL << I2C_S_RAM_SHIFT)                         /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          3                                                   /*!< I2C0_S: RAM Position                    */
#define I2C_S_ARBL_MASK                          (0x01UL << I2C_S_ARBL_SHIFT)                        /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         4                                                   /*!< I2C0_S: ARBL Position                   */
#define I2C_S_BUSY_MASK                          (0x01UL << I2C_S_BUSY_SHIFT)                        /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         5                                                   /*!< I2C0_S: BUSY Position                   */
#define I2C_S_IAAS_MASK                          (0x01UL << I2C_S_IAAS_SHIFT)                        /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         6                                                   /*!< I2C0_S: IAAS Position                   */
#define I2C_S_TCF_MASK                           (0x01UL << I2C_S_TCF_SHIFT)                         /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          7                                                   /*!< I2C0_S: TCF Position                    */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFUL << I2C_D_DATA_SHIFT)                        /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         0                                                   /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x07UL << I2C_C2_AD_SHIFT)                         /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          0                                                   /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x01UL << I2C_C2_RMEN_SHIFT)                       /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        3                                                   /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_SBRC_MASK                         (0x01UL << I2C_C2_SBRC_SHIFT)                       /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        4                                                   /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_HDRS_MASK                         (0x01UL << I2C_C2_HDRS_SHIFT)                       /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        5                                                   /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_ADEXT_MASK                        (0x01UL << I2C_C2_ADEXT_SHIFT)                      /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       6                                                   /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_GCAEN_MASK                        (0x01UL << I2C_C2_GCAEN_SHIFT)                      /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       7                                                   /*!< I2C0_C2: GCAEN Position                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0x0FUL << I2C_FLT_FLT_SHIFT)                       /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        0                                                   /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_STARTF_MASK                      (0x01UL << I2C_FLT_STARTF_SHIFT)                    /*!< I2C0_FLT: STARTF Mask                   */
#define I2C_FLT_STARTF_SHIFT                     4                                                   /*!< I2C0_FLT: STARTF Position               */
#define I2C_FLT_SSIE_MASK                        (0x01UL << I2C_FLT_SSIE_SHIFT)                      /*!< I2C0_FLT: SSIE Mask                     */
#define I2C_FLT_SSIE_SHIFT                       5                                                   /*!< I2C0_FLT: SSIE Position                 */
#define I2C_FLT_STOPF_MASK                       (0x01UL << I2C_FLT_STOPF_SHIFT)                     /*!< I2C0_FLT: STOPF Mask                    */
#define I2C_FLT_STOPF_SHIFT                      6                                                   /*!< I2C0_FLT: STOPF Position                */
#define I2C_FLT_SHEN_MASK                        (0x01UL << I2C_FLT_SHEN_SHIFT)                      /*!< I2C0_FLT: SHEN Mask                     */
#define I2C_FLT_SHEN_SHIFT                       7                                                   /*!< I2C0_FLT: SHEN Position                 */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0x7FUL << I2C_RA_RAD_SHIFT)                        /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         1                                                   /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x01UL << I2C_SMB_SHTF2IE_SHIFT)                   /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    0                                                   /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2_MASK                       (0x01UL << I2C_SMB_SHTF2_SHIFT)                     /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      1                                                   /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF1_MASK                       (0x01UL << I2C_SMB_SHTF1_SHIFT)                     /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      2                                                   /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SLTF_MASK                        (0x01UL << I2C_SMB_SLTF_SHIFT)                      /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       3                                                   /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_TCKSEL_MASK                      (0x01UL << I2C_SMB_TCKSEL_SHIFT)                    /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     4                                                   /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_SIICAEN_MASK                     (0x01UL << I2C_SMB_SIICAEN_SHIFT)                   /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    5                                                   /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_ALERTEN_MASK                     (0x01UL << I2C_SMB_ALERTEN_SHIFT)                   /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    6                                                   /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_FACK_MASK                        (0x01UL << I2C_SMB_FACK_SHIFT)                      /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       7                                                   /*!< I2C0_SMB: FACK Position                 */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0x7FUL << I2C_A2_SAD_SHIFT)                        /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         1                                                   /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFUL << I2C_SLTH_SSLT_SHIFT)                     /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFUL << I2C_SLTL_SSLT_SHIFT)                     /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40067000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C1 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C1 - Peripheral instance base addresses */
#define I2C1_BasePtr                   0x40068000UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_PE3_FILT2)           ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
* @addtogroup LLWU_structs_GROUP LLWU struct
* @brief Struct for LLWU
* @{
*/
typedef struct {                                /*       LLWU Structure                                               */
   __IO uint8_t   PE1;                          /**< 0000: Pin Enable 1 Register                                        */
   __IO uint8_t   PE2;                          /**< 0001: Pin Enable 2 Register                                        */
   __IO uint8_t   PE3;                          /**< 0002: Pin Enable 3 Register                                        */
   __IO uint8_t   PE4;                          /**< 0003: Pin Enable 4 Register                                        */
   __IO uint8_t   ME;                           /**< 0004: Module Enable Register                                       */
   __IO uint8_t   F1;                           /**< 0005: Flag 1 Register                                              */
   __IO uint8_t   F2;                           /**< 0006: Flag 2 Register                                              */
   union {                                      /**< 0000: (size=0001)                                                  */
      __I  uint8_t   F3;                        /**< 0007: Flag 3 Register                                              */
      __I  uint8_t   MF0;                       /**< 0007: Module Flag 0 Register                                       */
   };
   __IO uint8_t   FILT1;                        /**< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /**< 0009: Pin Filter 2 register                                        */
} LLWU_Type;

/**
 * @} */ /* End group LLWU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks
* @brief Register Masks for LLWU
* @{
*/
/* ------- PE1 Bit Fields                           ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x03UL << LLWU_PE1_WUPE0_SHIFT)                    /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     0                                                   /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0x03UL << LLWU_PE1_WUPE1_SHIFT)                    /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     2                                                   /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x03UL << LLWU_PE1_WUPE2_SHIFT)                    /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     4                                                   /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0x03UL << LLWU_PE1_WUPE3_SHIFT)                    /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     6                                                   /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /*!< LLWU_PE1                                */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x03UL << LLWU_PE2_WUPE4_SHIFT)                    /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     0                                                   /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0x03UL << LLWU_PE2_WUPE5_SHIFT)                    /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     2                                                   /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x03UL << LLWU_PE2_WUPE6_SHIFT)                    /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     4                                                   /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0x03UL << LLWU_PE2_WUPE7_SHIFT)                    /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     6                                                   /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /*!< LLWU_PE2                                */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x03UL << LLWU_PE3_WUPE8_SHIFT)                    /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     0                                                   /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0x03UL << LLWU_PE3_WUPE9_SHIFT)                    /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     2                                                   /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x03UL << LLWU_PE3_WUPE10_SHIFT)                   /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    4                                                   /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0x03UL << LLWU_PE3_WUPE11_SHIFT)                   /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    6                                                   /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x03UL << LLWU_PE4_WUPE12_SHIFT)                   /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    0                                                   /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0x03UL << LLWU_PE4_WUPE13_SHIFT)                   /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    2                                                   /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x03UL << LLWU_PE4_WUPE14_SHIFT)                   /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    4                                                   /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0x03UL << LLWU_PE4_WUPE15_SHIFT)                   /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    6                                                   /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x01UL << LLWU_ME_WUME0_SHIFT)                     /*!< LLWU_ME: WUME0 Mask                     */
#define LLWU_ME_WUME0_SHIFT                      0                                                   /*!< LLWU_ME: WUME0 Position                 */
#define LLWU_ME_WUME1_MASK                       (0x01UL << LLWU_ME_WUME1_SHIFT)                     /*!< LLWU_ME: WUME1 Mask                     */
#define LLWU_ME_WUME1_SHIFT                      1                                                   /*!< LLWU_ME: WUME1 Position                 */
#define LLWU_ME_WUME2_MASK                       (0x01UL << LLWU_ME_WUME2_SHIFT)                     /*!< LLWU_ME: WUME2 Mask                     */
#define LLWU_ME_WUME2_SHIFT                      2                                                   /*!< LLWU_ME: WUME2 Position                 */
#define LLWU_ME_WUME3_MASK                       (0x01UL << LLWU_ME_WUME3_SHIFT)                     /*!< LLWU_ME: WUME3 Mask                     */
#define LLWU_ME_WUME3_SHIFT                      3                                                   /*!< LLWU_ME: WUME3 Position                 */
#define LLWU_ME_WUME4_MASK                       (0x01UL << LLWU_ME_WUME4_SHIFT)                     /*!< LLWU_ME: WUME4 Mask                     */
#define LLWU_ME_WUME4_SHIFT                      4                                                   /*!< LLWU_ME: WUME4 Position                 */
#define LLWU_ME_WUME5_MASK                       (0x01UL << LLWU_ME_WUME5_SHIFT)                     /*!< LLWU_ME: WUME5 Mask                     */
#define LLWU_ME_WUME5_SHIFT                      5                                                   /*!< LLWU_ME: WUME5 Position                 */
#define LLWU_ME_WUME6_MASK                       (0x01UL << LLWU_ME_WUME6_SHIFT)                     /*!< LLWU_ME: WUME6 Mask                     */
#define LLWU_ME_WUME6_SHIFT                      6                                                   /*!< LLWU_ME: WUME6 Position                 */
#define LLWU_ME_WUME7_MASK                       (0x01UL << LLWU_ME_WUME7_SHIFT)                     /*!< LLWU_ME: WUME7 Mask                     */
#define LLWU_ME_WUME7_SHIFT                      7                                                   /*!< LLWU_ME: WUME7 Position                 */
/* ------- F1 Bit Fields                            ------ */
#define LLWU_F1_WUF0_MASK                        (0x01UL << LLWU_F1_WUF0_SHIFT)                      /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       0                                                   /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF1_MASK                        (0x01UL << LLWU_F1_WUF1_SHIFT)                      /*!< LLWU_F1: WUF1 Mask                      */
#define LLWU_F1_WUF1_SHIFT                       1                                                   /*!< LLWU_F1: WUF1 Position                  */
#define LLWU_F1_WUF2_MASK                        (0x01UL << LLWU_F1_WUF2_SHIFT)                      /*!< LLWU_F1: WUF2 Mask                      */
#define LLWU_F1_WUF2_SHIFT                       2                                                   /*!< LLWU_F1: WUF2 Position                  */
#define LLWU_F1_WUF3_MASK                        (0x01UL << LLWU_F1_WUF3_SHIFT)                      /*!< LLWU_F1: WUF3 Mask                      */
#define LLWU_F1_WUF3_SHIFT                       3                                                   /*!< LLWU_F1: WUF3 Position                  */
#define LLWU_F1_WUF4_MASK                        (0x01UL << LLWU_F1_WUF4_SHIFT)                      /*!< LLWU_F1: WUF4 Mask                      */
#define LLWU_F1_WUF4_SHIFT                       4                                                   /*!< LLWU_F1: WUF4 Position                  */
#define LLWU_F1_WUF5_MASK                        (0x01UL << LLWU_F1_WUF5_SHIFT)                      /*!< LLWU_F1: WUF5 Mask                      */
#define LLWU_F1_WUF5_SHIFT                       5                                                   /*!< LLWU_F1: WUF5 Position                  */
#define LLWU_F1_WUF6_MASK                        (0x01UL << LLWU_F1_WUF6_SHIFT)                      /*!< LLWU_F1: WUF6 Mask                      */
#define LLWU_F1_WUF6_SHIFT                       6                                                   /*!< LLWU_F1: WUF6 Position                  */
#define LLWU_F1_WUF7_MASK                        (0x01UL << LLWU_F1_WUF7_SHIFT)                      /*!< LLWU_F1: WUF7 Mask                      */
#define LLWU_F1_WUF7_SHIFT                       7                                                   /*!< LLWU_F1: WUF7 Position                  */
/* ------- F2 Bit Fields                            ------ */
#define LLWU_F2_WUF8_MASK                        (0x01UL << LLWU_F2_WUF8_SHIFT)                      /*!< LLWU_F2: WUF8 Mask                      */
#define LLWU_F2_WUF8_SHIFT                       0                                                   /*!< LLWU_F2: WUF8 Position                  */
#define LLWU_F2_WUF9_MASK                        (0x01UL << LLWU_F2_WUF9_SHIFT)                      /*!< LLWU_F2: WUF9 Mask                      */
#define LLWU_F2_WUF9_SHIFT                       1                                                   /*!< LLWU_F2: WUF9 Position                  */
#define LLWU_F2_WUF10_MASK                       (0x01UL << LLWU_F2_WUF10_SHIFT)                     /*!< LLWU_F2: WUF10 Mask                     */
#define LLWU_F2_WUF10_SHIFT                      2                                                   /*!< LLWU_F2: WUF10 Position                 */
#define LLWU_F2_WUF11_MASK                       (0x01UL << LLWU_F2_WUF11_SHIFT)                     /*!< LLWU_F2: WUF11 Mask                     */
#define LLWU_F2_WUF11_SHIFT                      3                                                   /*!< LLWU_F2: WUF11 Position                 */
#define LLWU_F2_WUF12_MASK                       (0x01UL << LLWU_F2_WUF12_SHIFT)                     /*!< LLWU_F2: WUF12 Mask                     */
#define LLWU_F2_WUF12_SHIFT                      4                                                   /*!< LLWU_F2: WUF12 Position                 */
#define LLWU_F2_WUF13_MASK                       (0x01UL << LLWU_F2_WUF13_SHIFT)                     /*!< LLWU_F2: WUF13 Mask                     */
#define LLWU_F2_WUF13_SHIFT                      5                                                   /*!< LLWU_F2: WUF13 Position                 */
#define LLWU_F2_WUF14_MASK                       (0x01UL << LLWU_F2_WUF14_SHIFT)                     /*!< LLWU_F2: WUF14 Mask                     */
#define LLWU_F2_WUF14_SHIFT                      6                                                   /*!< LLWU_F2: WUF14 Position                 */
#define LLWU_F2_WUF15_MASK                       (0x01UL << LLWU_F2_WUF15_SHIFT)                     /*!< LLWU_F2: WUF15 Mask                     */
#define LLWU_F2_WUF15_SHIFT                      7                                                   /*!< LLWU_F2: WUF15 Position                 */
/* ------- F3 Bit Fields                            ------ */
#define LLWU_F3_MWUF0_MASK                       (0x01UL << LLWU_F3_MWUF0_SHIFT)                     /*!< LLWU_F3: MWUF0 Mask                     */
#define LLWU_F3_MWUF0_SHIFT                      0                                                   /*!< LLWU_F3: MWUF0 Position                 */
#define LLWU_F3_MWUF1_MASK                       (0x01UL << LLWU_F3_MWUF1_SHIFT)                     /*!< LLWU_F3: MWUF1 Mask                     */
#define LLWU_F3_MWUF1_SHIFT                      1                                                   /*!< LLWU_F3: MWUF1 Position                 */
#define LLWU_F3_MWUF2_MASK                       (0x01UL << LLWU_F3_MWUF2_SHIFT)                     /*!< LLWU_F3: MWUF2 Mask                     */
#define LLWU_F3_MWUF2_SHIFT                      2                                                   /*!< LLWU_F3: MWUF2 Position                 */
#define LLWU_F3_MWUF3_MASK                       (0x01UL << LLWU_F3_MWUF3_SHIFT)                     /*!< LLWU_F3: MWUF3 Mask                     */
#define LLWU_F3_MWUF3_SHIFT                      3                                                   /*!< LLWU_F3: MWUF3 Position                 */
#define LLWU_F3_MWUF4_MASK                       (0x01UL << LLWU_F3_MWUF4_SHIFT)                     /*!< LLWU_F3: MWUF4 Mask                     */
#define LLWU_F3_MWUF4_SHIFT                      4                                                   /*!< LLWU_F3: MWUF4 Position                 */
#define LLWU_F3_MWUF5_MASK                       (0x01UL << LLWU_F3_MWUF5_SHIFT)                     /*!< LLWU_F3: MWUF5 Mask                     */
#define LLWU_F3_MWUF5_SHIFT                      5                                                   /*!< LLWU_F3: MWUF5 Position                 */
#define LLWU_F3_MWUF6_MASK                       (0x01UL << LLWU_F3_MWUF6_SHIFT)                     /*!< LLWU_F3: MWUF6 Mask                     */
#define LLWU_F3_MWUF6_SHIFT                      6                                                   /*!< LLWU_F3: MWUF6 Position                 */
#define LLWU_F3_MWUF7_MASK                       (0x01UL << LLWU_F3_MWUF7_SHIFT)                     /*!< LLWU_F3: MWUF7 Mask                     */
#define LLWU_F3_MWUF7_SHIFT                      7                                                   /*!< LLWU_F3: MWUF7 Position                 */
/* ------- MF0 Bit Fields                           ------ */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x0FUL << LLWU_FILT_FILTSEL_SHIFT)                 /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  0                                                   /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x03UL << LLWU_FILT_FILTE_SHIFT)                   /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    5                                                   /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x01UL << LLWU_FILT_FILTF_SHIFT)                   /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    7                                                   /*!< LLWU_FILT: FILTF Position               */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
/**
 * @} */ /* End group LLWU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_0x4003C000)       ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
* @addtogroup LPTMR_structs_GROUP LPTMR struct
* @brief Struct for LPTMR
* @{
*/
typedef struct {                                /*       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __I  uint32_t  CNR;                          /**< 000C: Counter Register                                             */
} LPTMR_Type;

/**
 * @} */ /* End group LPTMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks
* @brief Register Masks for LPTMR
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define LPTMR_CSR_TEN_MASK                       (0x01UL << LPTMR_CSR_TEN_SHIFT)                     /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      0                                                   /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TMS_MASK                       (0x01UL << LPTMR_CSR_TMS_SHIFT)                     /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      1                                                   /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TFC_MASK                       (0x01UL << LPTMR_CSR_TFC_SHIFT)                     /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      2                                                   /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TPP_MASK                       (0x01UL << LPTMR_CSR_TPP_SHIFT)                     /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      3                                                   /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPS_MASK                       (0x03UL << LPTMR_CSR_TPS_SHIFT)                     /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      4                                                   /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x01UL << LPTMR_CSR_TIE_SHIFT)                     /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      6                                                   /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TCF_MASK                       (0x01UL << LPTMR_CSR_TCF_SHIFT)                     /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      7                                                   /*!< LPTMR0_CSR: TCF Position                */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x03UL << LPTMR_PSR_PCS_SHIFT)                     /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      0                                                   /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x01UL << LPTMR_PSR_PBYP_SHIFT)                    /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     2                                                   /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PRESCALE_MASK                  (0x0FUL << LPTMR_PSR_PRESCALE_SHIFT)                /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 3                                                   /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFUL << LPTMR_CMR_COMPARE_SHIFT)               /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  0                                                   /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFUL << LPTMR_CNR_COUNTER_SHIFT)               /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  0                                                   /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x4003C000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MKM335)                ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
   __I  uint8_t   RESERVED0;                   
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
   __IO uint8_t   C7;                           /**< 000C: Control 7 Register                                           */
   __IO uint8_t   C8;                           /**< 000D: Control 8 Register                                           */
   __IO uint8_t   C9;                           /**< 000E: Control 9 Register                                           */
} MCG_Type;

/**
 * @} */ /* End group MCG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCG_Register_Masks_GROUP MCG Register Masks
* @brief Register Masks for MCG
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x01UL << MCG_C1_IREFSTEN_SHIFT)                   /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    0                                                   /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IRCLKEN_MASK                      (0x01UL << MCG_C1_IRCLKEN_SHIFT)                    /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     1                                                   /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IREFS_MASK                        (0x01UL << MCG_C1_IREFS_SHIFT)                      /*!< MCG_C1: IREFS Mask                      */
#define MCG_C1_IREFS_SHIFT                       2                                                   /*!< MCG_C1: IREFS Position                  */
#define MCG_C1_FRDIV_MASK                        (0x07UL << MCG_C1_FRDIV_SHIFT)                      /*!< MCG_C1: FRDIV Mask                      */
#define MCG_C1_FRDIV_SHIFT                       3                                                   /*!< MCG_C1: FRDIV Position                  */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK) /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0x03UL << MCG_C1_CLKS_SHIFT)                       /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        6                                                   /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /*!< MCG_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x01UL << MCG_C2_IRCS_SHIFT)                       /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        0                                                   /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_LP_MASK                           (0x01UL << MCG_C2_LP_SHIFT)                         /*!< MCG_C2: LP Mask                         */
#define MCG_C2_LP_SHIFT                          1                                                   /*!< MCG_C2: LP Position                     */
#define MCG_C2_EREFS0_MASK                       (0x01UL << MCG_C2_EREFS0_SHIFT)                     /*!< MCG_C2: EREFS0 Mask                     */
#define MCG_C2_EREFS0_SHIFT                      2                                                   /*!< MCG_C2: EREFS0 Position                 */
#define MCG_C2_HGO0_MASK                         (0x01UL << MCG_C2_HGO0_SHIFT)                       /*!< MCG_C2: HGO0 Mask                       */
#define MCG_C2_HGO0_SHIFT                        3                                                   /*!< MCG_C2: HGO0 Position                   */
#define MCG_C2_RANGE0_MASK                       (0x03UL << MCG_C2_RANGE0_SHIFT)                     /*!< MCG_C2: RANGE0 Mask                     */
#define MCG_C2_RANGE0_SHIFT                      4                                                   /*!< MCG_C2: RANGE0 Position                 */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_LOCRE0_MASK                       (0x01UL << MCG_C2_LOCRE0_SHIFT)                     /*!< MCG_C2: LOCRE0 Mask                     */
#define MCG_C2_LOCRE0_SHIFT                      7                                                   /*!< MCG_C2: LOCRE0 Position                 */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFUL << MCG_C3_SCTRIM_SHIFT)                     /*!< MCG_C3: SCTRIM Mask                     */
#define MCG_C3_SCTRIM_SHIFT                      0                                                   /*!< MCG_C3: SCTRIM Position                 */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK) /*!< MCG_C3                                  */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x01UL << MCG_C4_SCFTRIM_SHIFT)                    /*!< MCG_C4: SCFTRIM Mask                    */
#define MCG_C4_SCFTRIM_SHIFT                     0                                                   /*!< MCG_C4: SCFTRIM Position                */
#define MCG_C4_FCTRIM_MASK                       (0x0FUL << MCG_C4_FCTRIM_SHIFT)                     /*!< MCG_C4: FCTRIM Mask                     */
#define MCG_C4_FCTRIM_SHIFT                      1                                                   /*!< MCG_C4: FCTRIM Position                 */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DRST_DRS_MASK                     (0x03UL << MCG_C4_DRST_DRS_SHIFT)                   /*!< MCG_C4: DRST_DRS Mask                   */
#define MCG_C4_DRST_DRS_SHIFT                    5                                                   /*!< MCG_C4: DRST_DRS Position               */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DMX32_MASK                        (0x01UL << MCG_C4_DMX32_SHIFT)                      /*!< MCG_C4: DMX32 Mask                      */
#define MCG_C4_DMX32_SHIFT                       7                                                   /*!< MCG_C4: DMX32 Position                  */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PLLSTEN0_MASK                     (0x01UL << MCG_C5_PLLSTEN0_SHIFT)                   /*!< MCG_C5: PLLSTEN0 Mask                   */
#define MCG_C5_PLLSTEN0_SHIFT                    5                                                   /*!< MCG_C5: PLLSTEN0 Position               */
#define MCG_C5_PLLCLKEN0_MASK                    (0x01UL << MCG_C5_PLLCLKEN0_SHIFT)                  /*!< MCG_C5: PLLCLKEN0 Mask                  */
#define MCG_C5_PLLCLKEN0_SHIFT                   6                                                   /*!< MCG_C5: PLLCLKEN0 Position              */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_CHGPMP_BIAS_MASK                  (0x1FUL << MCG_C6_CHGPMP_BIAS_SHIFT)                /*!< MCG_C6: CHGPMP_BIAS Mask                */
#define MCG_C6_CHGPMP_BIAS_SHIFT                 0                                                   /*!< MCG_C6: CHGPMP_BIAS Position            */
#define MCG_C6_CHGPMP_BIAS(x)                    (((uint8_t)(((uint8_t)(x))<<MCG_C6_CHGPMP_BIAS_SHIFT))&MCG_C6_CHGPMP_BIAS_MASK) /*!< MCG_C6                                  */
#define MCG_C6_CME0_MASK                         (0x01UL << MCG_C6_CME0_SHIFT)                       /*!< MCG_C6: CME0 Mask                       */
#define MCG_C6_CME0_SHIFT                        5                                                   /*!< MCG_C6: CME0 Position                   */
#define MCG_C6_PLLS_MASK                         (0x01UL << MCG_C6_PLLS_SHIFT)                       /*!< MCG_C6: PLLS Mask                       */
#define MCG_C6_PLLS_SHIFT                        6                                                   /*!< MCG_C6: PLLS Position                   */
#define MCG_C6_LOLIE0_MASK                       (0x01UL << MCG_C6_LOLIE0_SHIFT)                     /*!< MCG_C6: LOLIE0 Mask                     */
#define MCG_C6_LOLIE0_SHIFT                      7                                                   /*!< MCG_C6: LOLIE0 Position                 */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x01UL << MCG_S_IRCST_SHIFT)                       /*!< MCG_S: IRCST Mask                       */
#define MCG_S_IRCST_SHIFT                        0                                                   /*!< MCG_S: IRCST Position                   */
#define MCG_S_OSCINIT0_MASK                      (0x01UL << MCG_S_OSCINIT0_SHIFT)                    /*!< MCG_S: OSCINIT0 Mask                    */
#define MCG_S_OSCINIT0_SHIFT                     1                                                   /*!< MCG_S: OSCINIT0 Position                */
#define MCG_S_CLKST_MASK                         (0x03UL << MCG_S_CLKST_SHIFT)                       /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        2                                                   /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /*!< MCG_S                                   */
#define MCG_S_IREFST_MASK                        (0x01UL << MCG_S_IREFST_SHIFT)                      /*!< MCG_S: IREFST Mask                      */
#define MCG_S_IREFST_SHIFT                       4                                                   /*!< MCG_S: IREFST Position                  */
#define MCG_S_PLLST_MASK                         (0x01UL << MCG_S_PLLST_SHIFT)                       /*!< MCG_S: PLLST Mask                       */
#define MCG_S_PLLST_SHIFT                        5                                                   /*!< MCG_S: PLLST Position                   */
#define MCG_S_LOCK0_MASK                         (0x01UL << MCG_S_LOCK0_SHIFT)                       /*!< MCG_S: LOCK0 Mask                       */
#define MCG_S_LOCK0_SHIFT                        6                                                   /*!< MCG_S: LOCK0 Position                   */
#define MCG_S_LOLS0_MASK                         (0x01UL << MCG_S_LOLS0_SHIFT)                       /*!< MCG_S: LOLS0 Mask                       */
#define MCG_S_LOLS0_SHIFT                        7                                                   /*!< MCG_S: LOLS0 Position                   */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x01UL << MCG_SC_LOCS0_SHIFT)                      /*!< MCG_SC: LOCS0 Mask                      */
#define MCG_SC_LOCS0_SHIFT                       0                                                   /*!< MCG_SC: LOCS0 Position                  */
#define MCG_SC_FCRDIV_MASK                       (0x07UL << MCG_SC_FCRDIV_SHIFT)                     /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      1                                                   /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FLTPRSRV_MASK                     (0x01UL << MCG_SC_FLTPRSRV_SHIFT)                   /*!< MCG_SC: FLTPRSRV Mask                   */
#define MCG_SC_FLTPRSRV_SHIFT                    4                                                   /*!< MCG_SC: FLTPRSRV Position               */
#define MCG_SC_ATMF_MASK                         (0x01UL << MCG_SC_ATMF_SHIFT)                       /*!< MCG_SC: ATMF Mask                       */
#define MCG_SC_ATMF_SHIFT                        5                                                   /*!< MCG_SC: ATMF Position                   */
#define MCG_SC_ATMS_MASK                         (0x01UL << MCG_SC_ATMS_SHIFT)                       /*!< MCG_SC: ATMS Mask                       */
#define MCG_SC_ATMS_SHIFT                        6                                                   /*!< MCG_SC: ATMS Position                   */
#define MCG_SC_ATME_MASK                         (0x01UL << MCG_SC_ATME_SHIFT)                       /*!< MCG_SC: ATME Mask                       */
#define MCG_SC_ATME_SHIFT                        7                                                   /*!< MCG_SC: ATME Position                   */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFUL << MCG_ATCVH_ATCVH_SHIFT)                   /*!< MCG_ATCVH: ATCVH Mask                   */
#define MCG_ATCVH_ATCVH_SHIFT                    0                                                   /*!< MCG_ATCVH: ATCVH Position               */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK) /*!< MCG_ATCVH                               */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFUL << MCG_ATCVL_ATCVL_SHIFT)                   /*!< MCG_ATCVL: ATCVL Mask                   */
#define MCG_ATCVL_ATCVL_SHIFT                    0                                                   /*!< MCG_ATCVL: ATCVL Position               */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK) /*!< MCG_ATCVL                               */
/* ------- C7 Bit Fields                            ------ */
#define MCG_C7_OSCSEL_MASK                       (0x01UL << MCG_C7_OSCSEL_SHIFT)                     /*!< MCG_C7: OSCSEL Mask                     */
#define MCG_C7_OSCSEL_SHIFT                      0                                                   /*!< MCG_C7: OSCSEL Position                 */
#define MCG_C7_PLL32KREFSEL_MASK                 (0x03UL << MCG_C7_PLL32KREFSEL_SHIFT)               /*!< MCG_C7: PLL32KREFSEL Mask               */
#define MCG_C7_PLL32KREFSEL_SHIFT                6                                                   /*!< MCG_C7: PLL32KREFSEL Position           */
#define MCG_C7_PLL32KREFSEL(x)                   (((uint8_t)(((uint8_t)(x))<<MCG_C7_PLL32KREFSEL_SHIFT))&MCG_C7_PLL32KREFSEL_MASK) /*!< MCG_C7                                  */
/* ------- C8 Bit Fields                            ------ */
#define MCG_C8_LOCS1_MASK                        (0x01UL << MCG_C8_LOCS1_SHIFT)                      /*!< MCG_C8: LOCS1 Mask                      */
#define MCG_C8_LOCS1_SHIFT                       0                                                   /*!< MCG_C8: LOCS1 Position                  */
#define MCG_C8_COARSE_LOLIE_MASK                 (0x01UL << MCG_C8_COARSE_LOLIE_SHIFT)               /*!< MCG_C8: COARSE_LOLIE Mask               */
#define MCG_C8_COARSE_LOLIE_SHIFT                4                                                   /*!< MCG_C8: COARSE_LOLIE Position           */
#define MCG_C8_CME1_MASK                         (0x01UL << MCG_C8_CME1_SHIFT)                       /*!< MCG_C8: CME1 Mask                       */
#define MCG_C8_CME1_SHIFT                        5                                                   /*!< MCG_C8: CME1 Position                   */
#define MCG_C8_LOLRE_MASK                        (0x01UL << MCG_C8_LOLRE_SHIFT)                      /*!< MCG_C8: LOLRE Mask                      */
#define MCG_C8_LOLRE_SHIFT                       6                                                   /*!< MCG_C8: LOLRE Position                  */
#define MCG_C8_LOCRE1_MASK                       (0x01UL << MCG_C8_LOCRE1_SHIFT)                     /*!< MCG_C8: LOCRE1 Mask                     */
#define MCG_C8_LOCRE1_SHIFT                      7                                                   /*!< MCG_C8: LOCRE1 Position                 */
/* ------- C9 Bit Fields                            ------ */
#define MCG_C9_COARSE_LOCK_MASK                  (0x01UL << MCG_C9_COARSE_LOCK_SHIFT)                /*!< MCG_C9: COARSE_LOCK Mask                */
#define MCG_C9_COARSE_LOCK_SHIFT                 6                                                   /*!< MCG_C9: COARSE_LOCK Position            */
#define MCG_C9_COARSE_LOLS_MASK                  (0x01UL << MCG_C9_COARSE_LOLS_SHIFT)                /*!< MCG_C9: COARSE_LOLS Mask                */
#define MCG_C9_COARSE_LOLS_SHIFT                 7                                                   /*!< MCG_C9: COARSE_LOLS Position            */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MKM14ZA5)              ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
* @addtogroup MCM_structs_GROUP MCM struct
* @brief Struct for MCM
* @{
*/
typedef struct {                                /*       MCM Structure                                                */
   __I  uint32_t  RESERVED0[2];                
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /**< 000C: Platform Control Register                                    */
   __I  uint32_t  RESERVED1[8];                
   __IO uint32_t  PID;                          /**< 0030: Process ID register                                          */
   __I  uint32_t  RESERVED2[3];                
   __IO uint32_t  CPO;                          /**< 0040: Compute Operation Control Register                           */
   __I  uint32_t  RESERVED3[15];               
   __IO uint32_t  MATCR;                        /**< 0080: Master Attribute Configuration Register                      */
} MCM_Type;

/**
 * @} */ /* End group MCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCM_Register_Masks_GROUP MCM Register Masks
* @brief Register Masks for MCM
* @{
*/
/* ------- PLASC Bit Fields                         ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFUL << MCM_PLASC_ASC_SHIFT)                     /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      0                                                   /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /*!< MCM_PLASC                               */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFUL << MCM_PLAMC_AMC_SHIFT)                     /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      0                                                   /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /*!< MCM_PLAMC                               */
/* ------- PLACR Bit Fields                         ------ */
#define MCM_PLACR_ARB_MASK                       (0x01UL << MCM_PLACR_ARB_SHIFT)                     /*!< MCM_PLACR: ARB Mask                     */
#define MCM_PLACR_ARB_SHIFT                      9                                                   /*!< MCM_PLACR: ARB Position                 */
#define MCM_PLACR_CFCC_MASK                      (0x01UL << MCM_PLACR_CFCC_SHIFT)                    /*!< MCM_PLACR: CFCC Mask                    */
#define MCM_PLACR_CFCC_SHIFT                     10                                                  /*!< MCM_PLACR: CFCC Position                */
#define MCM_PLACR_DFCDA_MASK                     (0x01UL << MCM_PLACR_DFCDA_SHIFT)                   /*!< MCM_PLACR: DFCDA Mask                   */
#define MCM_PLACR_DFCDA_SHIFT                    11                                                  /*!< MCM_PLACR: DFCDA Position               */
#define MCM_PLACR_DFCIC_MASK                     (0x01UL << MCM_PLACR_DFCIC_SHIFT)                   /*!< MCM_PLACR: DFCIC Mask                   */
#define MCM_PLACR_DFCIC_SHIFT                    12                                                  /*!< MCM_PLACR: DFCIC Position               */
#define MCM_PLACR_DFCC_MASK                      (0x01UL << MCM_PLACR_DFCC_SHIFT)                    /*!< MCM_PLACR: DFCC Mask                    */
#define MCM_PLACR_DFCC_SHIFT                     13                                                  /*!< MCM_PLACR: DFCC Position                */
#define MCM_PLACR_EFDS_MASK                      (0x01UL << MCM_PLACR_EFDS_SHIFT)                    /*!< MCM_PLACR: EFDS Mask                    */
#define MCM_PLACR_EFDS_SHIFT                     14                                                  /*!< MCM_PLACR: EFDS Position                */
#define MCM_PLACR_DFCS_MASK                      (0x01UL << MCM_PLACR_DFCS_SHIFT)                    /*!< MCM_PLACR: DFCS Mask                    */
#define MCM_PLACR_DFCS_SHIFT                     15                                                  /*!< MCM_PLACR: DFCS Position                */
#define MCM_PLACR_ESFC_MASK                      (0x01UL << MCM_PLACR_ESFC_SHIFT)                    /*!< MCM_PLACR: ESFC Mask                    */
#define MCM_PLACR_ESFC_SHIFT                     16                                                  /*!< MCM_PLACR: ESFC Position                */
/* ------- PID Bit Fields                           ------ */
#define MCM_PID_PID_MASK                         (0xFFUL << MCM_PID_PID_SHIFT)                       /*!< MCM_PID: PID Mask                       */
#define MCM_PID_PID_SHIFT                        0                                                   /*!< MCM_PID: PID Position                   */
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x))<<MCM_PID_PID_SHIFT))&MCM_PID_PID_MASK) /*!< MCM_PID                                 */
/* ------- CPO Bit Fields                           ------ */
#define MCM_CPO_CPOREQ_MASK                      (0x01UL << MCM_CPO_CPOREQ_SHIFT)                    /*!< MCM_CPO: CPOREQ Mask                    */
#define MCM_CPO_CPOREQ_SHIFT                     0                                                   /*!< MCM_CPO: CPOREQ Position                */
#define MCM_CPO_CPOACK_MASK                      (0x01UL << MCM_CPO_CPOACK_SHIFT)                    /*!< MCM_CPO: CPOACK Mask                    */
#define MCM_CPO_CPOACK_SHIFT                     1                                                   /*!< MCM_CPO: CPOACK Position                */
#define MCM_CPO_CPOWOI_MASK                      (0x01UL << MCM_CPO_CPOWOI_SHIFT)                    /*!< MCM_CPO: CPOWOI Mask                    */
#define MCM_CPO_CPOWOI_SHIFT                     2                                                   /*!< MCM_CPO: CPOWOI Position                */
/* ------- MATCR Bit Fields                         ------ */
#define MCM_MATCR_ATC0_MASK                      (0x07UL << MCM_MATCR_ATC0_SHIFT)                    /*!< MCM_MATCR: ATC0 Mask                    */
#define MCM_MATCR_ATC0_SHIFT                     0                                                   /*!< MCM_MATCR: ATC0 Position                */
#define MCM_MATCR_ATC0(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_MATCR_ATC0_SHIFT))&MCM_MATCR_ATC0_MASK) /*!< MCM_MATCR                               */
#define MCM_MATCR_RO0_MASK                       (0x01UL << MCM_MATCR_RO0_SHIFT)                     /*!< MCM_MATCR: RO0 Mask                     */
#define MCM_MATCR_RO0_SHIFT                      7                                                   /*!< MCM_MATCR: RO0 Position                 */
#define MCM_MATCR_ATC2_MASK                      (0x07UL << MCM_MATCR_ATC2_SHIFT)                    /*!< MCM_MATCR: ATC2 Mask                    */
#define MCM_MATCR_ATC2_SHIFT                     16                                                  /*!< MCM_MATCR: ATC2 Position                */
#define MCM_MATCR_ATC2(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_MATCR_ATC2_SHIFT))&MCM_MATCR_ATC2_MASK) /*!< MCM_MATCR                               */
#define MCM_MATCR_RO2_MASK                       (0x01UL << MCM_MATCR_RO2_SHIFT)                     /*!< MCM_MATCR: RO2 Mask                     */
#define MCM_MATCR_RO2_SHIFT                      23                                                  /*!< MCM_MATCR: RO2 Position                 */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xF0003000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MPU_Peripheral_access_layer_GROUP MPU Peripheral Access Layer
* @brief C Struct for MPU
* @{
*/

/* ================================================================================ */
/* ================           MPU (file:MPU_MKM14ZA5_R8)           ================ */
/* ================================================================================ */

/**
 * @brief Memory protection unit
 */
/**
* @addtogroup MPU_structs_GROUP MPU struct
* @brief Struct for MPU
* @{
*/
typedef struct {                                /*       MPU Structure                                                */
   __IO uint32_t  CESR;                         /**< 0000: Control/Error Status Register                                */
   __I  uint32_t  RESERVED0[3];                
   struct {
      __I  uint32_t  EAR;                       /**< 0010: Error Address Register, Slave Port n                         */
      __I  uint32_t  EDR;                       /**< 0014: Error Detail Register, Slave Port n                          */
   } SP[2];                                     /**< 0010: (cluster: size=0x0010, 16)                                   */
   __I  uint32_t  RESERVED1[248];              
   struct {
      __IO uint32_t  WORD0;                     /**< 0400: Region Descriptor n, Word 0                                  */
      __IO uint32_t  WORD1;                     /**< 0404: Region Descriptor n, Word 1                                  */
      __IO uint32_t  WORD2;                     /**< 0408: Region Descriptor n, Word 2                                  */
      __IO uint32_t  WORD3;                     /**< 040C: Region Descriptor n, Word 3                                  */
   } RGD[8];                                    /**< 0400: (cluster: size=0x0080, 128)                                  */
   __I  uint32_t  RESERVED2[224];              
   __IO uint32_t  RGDAAC[8];                    /**< 0800: Region Descriptor Alternate Access Control n                 */
} MPU_Type;

/**
 * @} */ /* End group MPU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MPU' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MPU_Register_Masks_GROUP MPU Register Masks
* @brief Register Masks for MPU
* @{
*/
/* ------- CESR Bit Fields                          ------ */
#define MPU_CESR_VLD_MASK                        (0x01UL << MPU_CESR_VLD_SHIFT)                      /*!< MPU_CESR: VLD Mask                      */
#define MPU_CESR_VLD_SHIFT                       0                                                   /*!< MPU_CESR: VLD Position                  */
#define MPU_CESR_NRGD_MASK                       (0x0FUL << MPU_CESR_NRGD_SHIFT)                     /*!< MPU_CESR: NRGD Mask                     */
#define MPU_CESR_NRGD_SHIFT                      8                                                   /*!< MPU_CESR: NRGD Position                 */
#define MPU_CESR_NRGD(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NRGD_SHIFT))&MPU_CESR_NRGD_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_NSP_MASK                        (0x0FUL << MPU_CESR_NSP_SHIFT)                      /*!< MPU_CESR: NSP Mask                      */
#define MPU_CESR_NSP_SHIFT                       12                                                  /*!< MPU_CESR: NSP Position                  */
#define MPU_CESR_NSP(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_HRL_MASK                        (0x0FUL << MPU_CESR_HRL_SHIFT)                      /*!< MPU_CESR: HRL Mask                      */
#define MPU_CESR_HRL_SHIFT                       16                                                  /*!< MPU_CESR: HRL Position                  */
#define MPU_CESR_HRL(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_HRL_SHIFT))&MPU_CESR_HRL_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_SPERR_MASK                      (0x03UL << MPU_CESR_SPERR_SHIFT)                    /*!< MPU_CESR: SPERR Mask                    */
#define MPU_CESR_SPERR_SHIFT                     30                                                  /*!< MPU_CESR: SPERR Position                */
#define MPU_CESR_SPERR(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_CESR_SPERR_SHIFT))&MPU_CESR_SPERR_MASK) /*!< MPU_CESR                                */
/* ------- EAR Bit Fields                           ------ */
#define MPU_EAR_EADDR_MASK                       (0xFFFFFFFFUL << MPU_EAR_EADDR_SHIFT)               /*!< MPU_EAR: EADDR Mask                     */
#define MPU_EAR_EADDR_SHIFT                      0                                                   /*!< MPU_EAR: EADDR Position                 */
#define MPU_EAR_EADDR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EAR_EADDR_SHIFT))&MPU_EAR_EADDR_MASK) /*!< MPU_EAR                                 */
/* ------- EDR Bit Fields                           ------ */
#define MPU_EDR_ERW_MASK                         (0x01UL << MPU_EDR_ERW_SHIFT)                       /*!< MPU_EDR: ERW Mask                       */
#define MPU_EDR_ERW_SHIFT                        0                                                   /*!< MPU_EDR: ERW Position                   */
#define MPU_EDR_EATTR_MASK                       (0x07UL << MPU_EDR_EATTR_SHIFT)                     /*!< MPU_EDR: EATTR Mask                     */
#define MPU_EDR_EATTR_SHIFT                      1                                                   /*!< MPU_EDR: EATTR Position                 */
#define MPU_EDR_EATTR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EATTR_SHIFT))&MPU_EDR_EATTR_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EMN_MASK                         (0x0FUL << MPU_EDR_EMN_SHIFT)                       /*!< MPU_EDR: EMN Mask                       */
#define MPU_EDR_EMN_SHIFT                        4                                                   /*!< MPU_EDR: EMN Position                   */
#define MPU_EDR_EMN(x)                           (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EMN_SHIFT))&MPU_EDR_EMN_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EPID_MASK                        (0xFFUL << MPU_EDR_EPID_SHIFT)                      /*!< MPU_EDR: EPID Mask                      */
#define MPU_EDR_EPID_SHIFT                       8                                                   /*!< MPU_EDR: EPID Position                  */
#define MPU_EDR_EPID(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EPID_SHIFT))&MPU_EDR_EPID_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EACD_MASK                        (0xFFFFUL << MPU_EDR_EACD_SHIFT)                    /*!< MPU_EDR: EACD Mask                      */
#define MPU_EDR_EACD_SHIFT                       16                                                  /*!< MPU_EDR: EACD Position                  */
#define MPU_EDR_EACD(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EACD_SHIFT))&MPU_EDR_EACD_MASK) /*!< MPU_EDR                                 */
/* ------- WORD0 Bit Fields                         ------ */
#define MPU_WORD0_SRTADDR_MASK                   (0x7FFFFFFUL << MPU_WORD0_SRTADDR_SHIFT)            /*!< MPU_WORD0: SRTADDR Mask                 */
#define MPU_WORD0_SRTADDR_SHIFT                  5                                                   /*!< MPU_WORD0: SRTADDR Position             */
#define MPU_WORD0_SRTADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MPU_WORD0_SRTADDR_SHIFT))&MPU_WORD0_SRTADDR_MASK) /*!< MPU_WORD0                               */
/* ------- WORD1 Bit Fields                         ------ */
#define MPU_WORD1_ENDADDR_MASK                   (0x7FFFFFFUL << MPU_WORD1_ENDADDR_SHIFT)            /*!< MPU_WORD1: ENDADDR Mask                 */
#define MPU_WORD1_ENDADDR_SHIFT                  5                                                   /*!< MPU_WORD1: ENDADDR Position             */
#define MPU_WORD1_ENDADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MPU_WORD1_ENDADDR_SHIFT))&MPU_WORD1_ENDADDR_MASK) /*!< MPU_WORD1                               */
/* ------- WORD2 Bit Fields                         ------ */
#define MPU_WORD2_M0UM_MASK                      (0x07UL << MPU_WORD2_M0UM_SHIFT)                    /*!< MPU_WORD2: M0UM Mask                    */
#define MPU_WORD2_M0UM_SHIFT                     0                                                   /*!< MPU_WORD2: M0UM Position                */
#define MPU_WORD2_M0UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M0UM_SHIFT))&MPU_WORD2_M0UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M0SM_MASK                      (0x03UL << MPU_WORD2_M0SM_SHIFT)                    /*!< MPU_WORD2: M0SM Mask                    */
#define MPU_WORD2_M0SM_SHIFT                     3                                                   /*!< MPU_WORD2: M0SM Position                */
#define MPU_WORD2_M0SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M0SM_SHIFT))&MPU_WORD2_M0SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M0PE_MASK                      (0x01UL << MPU_WORD2_M0PE_SHIFT)                    /*!< MPU_WORD2: M0PE Mask                    */
#define MPU_WORD2_M0PE_SHIFT                     5                                                   /*!< MPU_WORD2: M0PE Position                */
#define MPU_WORD2_M1UM_MASK                      (0x07UL << MPU_WORD2_M1UM_SHIFT)                    /*!< MPU_WORD2: M1UM Mask                    */
#define MPU_WORD2_M1UM_SHIFT                     6                                                   /*!< MPU_WORD2: M1UM Position                */
#define MPU_WORD2_M1UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M1UM_SHIFT))&MPU_WORD2_M1UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M1SM_MASK                      (0x03UL << MPU_WORD2_M1SM_SHIFT)                    /*!< MPU_WORD2: M1SM Mask                    */
#define MPU_WORD2_M1SM_SHIFT                     9                                                   /*!< MPU_WORD2: M1SM Position                */
#define MPU_WORD2_M1SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M1SM_SHIFT))&MPU_WORD2_M1SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M1PE_MASK                      (0x01UL << MPU_WORD2_M1PE_SHIFT)                    /*!< MPU_WORD2: M1PE Mask                    */
#define MPU_WORD2_M1PE_SHIFT                     11                                                  /*!< MPU_WORD2: M1PE Position                */
#define MPU_WORD2_M2UM_MASK                      (0x07UL << MPU_WORD2_M2UM_SHIFT)                    /*!< MPU_WORD2: M2UM Mask                    */
#define MPU_WORD2_M2UM_SHIFT                     12                                                  /*!< MPU_WORD2: M2UM Position                */
#define MPU_WORD2_M2UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M2UM_SHIFT))&MPU_WORD2_M2UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M2SM_MASK                      (0x03UL << MPU_WORD2_M2SM_SHIFT)                    /*!< MPU_WORD2: M2SM Mask                    */
#define MPU_WORD2_M2SM_SHIFT                     15                                                  /*!< MPU_WORD2: M2SM Position                */
#define MPU_WORD2_M2SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M2SM_SHIFT))&MPU_WORD2_M2SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M2PE_MASK                      (0x01UL << MPU_WORD2_M2PE_SHIFT)                    /*!< MPU_WORD2: M2PE Mask                    */
#define MPU_WORD2_M2PE_SHIFT                     17                                                  /*!< MPU_WORD2: M2PE Position                */
#define MPU_WORD2_M3UM_MASK                      (0x07UL << MPU_WORD2_M3UM_SHIFT)                    /*!< MPU_WORD2: M3UM Mask                    */
#define MPU_WORD2_M3UM_SHIFT                     18                                                  /*!< MPU_WORD2: M3UM Position                */
#define MPU_WORD2_M3UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M3UM_SHIFT))&MPU_WORD2_M3UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M3SM_MASK                      (0x03UL << MPU_WORD2_M3SM_SHIFT)                    /*!< MPU_WORD2: M3SM Mask                    */
#define MPU_WORD2_M3SM_SHIFT                     21                                                  /*!< MPU_WORD2: M3SM Position                */
#define MPU_WORD2_M3SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M3SM_SHIFT))&MPU_WORD2_M3SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M3PE_MASK                      (0x01UL << MPU_WORD2_M3PE_SHIFT)                    /*!< MPU_WORD2: M3PE Mask                    */
#define MPU_WORD2_M3PE_SHIFT                     23                                                  /*!< MPU_WORD2: M3PE Position                */
#define MPU_WORD2_M4WE_MASK                      (0x01UL << MPU_WORD2_M4WE_SHIFT)                    /*!< MPU_WORD2: M4WE Mask                    */
#define MPU_WORD2_M4WE_SHIFT                     24                                                  /*!< MPU_WORD2: M4WE Position                */
#define MPU_WORD2_M4RE_MASK                      (0x01UL << MPU_WORD2_M4RE_SHIFT)                    /*!< MPU_WORD2: M4RE Mask                    */
#define MPU_WORD2_M4RE_SHIFT                     25                                                  /*!< MPU_WORD2: M4RE Position                */
#define MPU_WORD2_M5WE_MASK                      (0x01UL << MPU_WORD2_M5WE_SHIFT)                    /*!< MPU_WORD2: M5WE Mask                    */
#define MPU_WORD2_M5WE_SHIFT                     26                                                  /*!< MPU_WORD2: M5WE Position                */
#define MPU_WORD2_M5RE_MASK                      (0x01UL << MPU_WORD2_M5RE_SHIFT)                    /*!< MPU_WORD2: M5RE Mask                    */
#define MPU_WORD2_M5RE_SHIFT                     27                                                  /*!< MPU_WORD2: M5RE Position                */
#define MPU_WORD2_M6WE_MASK                      (0x01UL << MPU_WORD2_M6WE_SHIFT)                    /*!< MPU_WORD2: M6WE Mask                    */
#define MPU_WORD2_M6WE_SHIFT                     28                                                  /*!< MPU_WORD2: M6WE Position                */
#define MPU_WORD2_M6RE_MASK                      (0x01UL << MPU_WORD2_M6RE_SHIFT)                    /*!< MPU_WORD2: M6RE Mask                    */
#define MPU_WORD2_M6RE_SHIFT                     29                                                  /*!< MPU_WORD2: M6RE Position                */
#define MPU_WORD2_M7WE_MASK                      (0x01UL << MPU_WORD2_M7WE_SHIFT)                    /*!< MPU_WORD2: M7WE Mask                    */
#define MPU_WORD2_M7WE_SHIFT                     30                                                  /*!< MPU_WORD2: M7WE Position                */
#define MPU_WORD2_M7RE_MASK                      (0x01UL << MPU_WORD2_M7RE_SHIFT)                    /*!< MPU_WORD2: M7RE Mask                    */
#define MPU_WORD2_M7RE_SHIFT                     31                                                  /*!< MPU_WORD2: M7RE Position                */
/* ------- WORD3 Bit Fields                         ------ */
#define MPU_WORD3_VLD_MASK                       (0x01UL << MPU_WORD3_VLD_SHIFT)                     /*!< MPU_WORD3: VLD Mask                     */
#define MPU_WORD3_VLD_SHIFT                      0                                                   /*!< MPU_WORD3: VLD Position                 */
#define MPU_WORD3_PIDMASK_MASK                   (0xFFUL << MPU_WORD3_PIDMASK_SHIFT)                 /*!< MPU_WORD3: PIDMASK Mask                 */
#define MPU_WORD3_PIDMASK_SHIFT                  16                                                  /*!< MPU_WORD3: PIDMASK Position             */
#define MPU_WORD3_PIDMASK(x)                     (((uint32_t)(((uint32_t)(x))<<MPU_WORD3_PIDMASK_SHIFT))&MPU_WORD3_PIDMASK_MASK) /*!< MPU_WORD3                               */
#define MPU_WORD3_PID_MASK                       (0xFFUL << MPU_WORD3_PID_SHIFT)                     /*!< MPU_WORD3: PID Mask                     */
#define MPU_WORD3_PID_SHIFT                      24                                                  /*!< MPU_WORD3: PID Position                 */
#define MPU_WORD3_PID(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD3_PID_SHIFT))&MPU_WORD3_PID_MASK) /*!< MPU_WORD3                               */
/* ------- RGDAAC Bit Fields                        ------ */
#define MPU_RGDAAC_M0UM_MASK                     (0x07UL << MPU_RGDAAC_M0UM_SHIFT)                   /*!< MPU_RGDAAC: M0UM Mask                   */
#define MPU_RGDAAC_M0UM_SHIFT                    0                                                   /*!< MPU_RGDAAC: M0UM Position               */
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0UM_SHIFT))&MPU_RGDAAC_M0UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M0SM_MASK                     (0x03UL << MPU_RGDAAC_M0SM_SHIFT)                   /*!< MPU_RGDAAC: M0SM Mask                   */
#define MPU_RGDAAC_M0SM_SHIFT                    3                                                   /*!< MPU_RGDAAC: M0SM Position               */
#define MPU_RGDAAC_M0SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0SM_SHIFT))&MPU_RGDAAC_M0SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M0PE_MASK                     (0x01UL << MPU_RGDAAC_M0PE_SHIFT)                   /*!< MPU_RGDAAC: M0PE Mask                   */
#define MPU_RGDAAC_M0PE_SHIFT                    5                                                   /*!< MPU_RGDAAC: M0PE Position               */
#define MPU_RGDAAC_M1UM_MASK                     (0x07UL << MPU_RGDAAC_M1UM_SHIFT)                   /*!< MPU_RGDAAC: M1UM Mask                   */
#define MPU_RGDAAC_M1UM_SHIFT                    6                                                   /*!< MPU_RGDAAC: M1UM Position               */
#define MPU_RGDAAC_M1UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1UM_SHIFT))&MPU_RGDAAC_M1UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M1SM_MASK                     (0x03UL << MPU_RGDAAC_M1SM_SHIFT)                   /*!< MPU_RGDAAC: M1SM Mask                   */
#define MPU_RGDAAC_M1SM_SHIFT                    9                                                   /*!< MPU_RGDAAC: M1SM Position               */
#define MPU_RGDAAC_M1SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1SM_SHIFT))&MPU_RGDAAC_M1SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M1PE_MASK                     (0x01UL << MPU_RGDAAC_M1PE_SHIFT)                   /*!< MPU_RGDAAC: M1PE Mask                   */
#define MPU_RGDAAC_M1PE_SHIFT                    11                                                  /*!< MPU_RGDAAC: M1PE Position               */
#define MPU_RGDAAC_M2UM_MASK                     (0x07UL << MPU_RGDAAC_M2UM_SHIFT)                   /*!< MPU_RGDAAC: M2UM Mask                   */
#define MPU_RGDAAC_M2UM_SHIFT                    12                                                  /*!< MPU_RGDAAC: M2UM Position               */
#define MPU_RGDAAC_M2UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2UM_SHIFT))&MPU_RGDAAC_M2UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M2SM_MASK                     (0x03UL << MPU_RGDAAC_M2SM_SHIFT)                   /*!< MPU_RGDAAC: M2SM Mask                   */
#define MPU_RGDAAC_M2SM_SHIFT                    15                                                  /*!< MPU_RGDAAC: M2SM Position               */
#define MPU_RGDAAC_M2SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2SM_SHIFT))&MPU_RGDAAC_M2SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M2PE_MASK                     (0x01UL << MPU_RGDAAC_M2PE_SHIFT)                   /*!< MPU_RGDAAC: M2PE Mask                   */
#define MPU_RGDAAC_M2PE_SHIFT                    17                                                  /*!< MPU_RGDAAC: M2PE Position               */
#define MPU_RGDAAC_M3UM_MASK                     (0x07UL << MPU_RGDAAC_M3UM_SHIFT)                   /*!< MPU_RGDAAC: M3UM Mask                   */
#define MPU_RGDAAC_M3UM_SHIFT                    18                                                  /*!< MPU_RGDAAC: M3UM Position               */
#define MPU_RGDAAC_M3UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3UM_SHIFT))&MPU_RGDAAC_M3UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M3SM_MASK                     (0x03UL << MPU_RGDAAC_M3SM_SHIFT)                   /*!< MPU_RGDAAC: M3SM Mask                   */
#define MPU_RGDAAC_M3SM_SHIFT                    21                                                  /*!< MPU_RGDAAC: M3SM Position               */
#define MPU_RGDAAC_M3SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3SM_SHIFT))&MPU_RGDAAC_M3SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M3PE_MASK                     (0x01UL << MPU_RGDAAC_M3PE_SHIFT)                   /*!< MPU_RGDAAC: M3PE Mask                   */
#define MPU_RGDAAC_M3PE_SHIFT                    23                                                  /*!< MPU_RGDAAC: M3PE Position               */
#define MPU_RGDAAC_M4WE_MASK                     (0x01UL << MPU_RGDAAC_M4WE_SHIFT)                   /*!< MPU_RGDAAC: M4WE Mask                   */
#define MPU_RGDAAC_M4WE_SHIFT                    24                                                  /*!< MPU_RGDAAC: M4WE Position               */
#define MPU_RGDAAC_M4RE_MASK                     (0x01UL << MPU_RGDAAC_M4RE_SHIFT)                   /*!< MPU_RGDAAC: M4RE Mask                   */
#define MPU_RGDAAC_M4RE_SHIFT                    25                                                  /*!< MPU_RGDAAC: M4RE Position               */
#define MPU_RGDAAC_M5WE_MASK                     (0x01UL << MPU_RGDAAC_M5WE_SHIFT)                   /*!< MPU_RGDAAC: M5WE Mask                   */
#define MPU_RGDAAC_M5WE_SHIFT                    26                                                  /*!< MPU_RGDAAC: M5WE Position               */
#define MPU_RGDAAC_M5RE_MASK                     (0x01UL << MPU_RGDAAC_M5RE_SHIFT)                   /*!< MPU_RGDAAC: M5RE Mask                   */
#define MPU_RGDAAC_M5RE_SHIFT                    27                                                  /*!< MPU_RGDAAC: M5RE Position               */
#define MPU_RGDAAC_M6WE_MASK                     (0x01UL << MPU_RGDAAC_M6WE_SHIFT)                   /*!< MPU_RGDAAC: M6WE Mask                   */
#define MPU_RGDAAC_M6WE_SHIFT                    28                                                  /*!< MPU_RGDAAC: M6WE Position               */
#define MPU_RGDAAC_M6RE_MASK                     (0x01UL << MPU_RGDAAC_M6RE_SHIFT)                   /*!< MPU_RGDAAC: M6RE Mask                   */
#define MPU_RGDAAC_M6RE_SHIFT                    29                                                  /*!< MPU_RGDAAC: M6RE Position               */
#define MPU_RGDAAC_M7WE_MASK                     (0x01UL << MPU_RGDAAC_M7WE_SHIFT)                   /*!< MPU_RGDAAC: M7WE Mask                   */
#define MPU_RGDAAC_M7WE_SHIFT                    30                                                  /*!< MPU_RGDAAC: M7WE Position               */
#define MPU_RGDAAC_M7RE_MASK                     (0x01UL << MPU_RGDAAC_M7RE_SHIFT)                   /*!< MPU_RGDAAC: M7RE Mask                   */
#define MPU_RGDAAC_M7RE_SHIFT                    31                                                  /*!< MPU_RGDAAC: M7RE Position               */
/**
 * @} */ /* End group MPU_Register_Masks_GROUP 
 */

/* MPU - Peripheral instance base addresses */
#define MPU_BasePtr                    0x4000A000UL //!< Peripheral base address
#define MPU                            ((MPU_Type *) MPU_BasePtr) //!< Freescale base pointer
#define MPU_BASE_PTR                   (MPU) //!< Freescale style base pointer
/**
 * @} */ /* End group MPU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTB_Peripheral_access_layer_GROUP MTB Peripheral Access Layer
* @brief C Struct for MTB
* @{
*/

/* ================================================================================ */
/* ================           MTB (file:MTB)                       ================ */
/* ================================================================================ */

/**
 * @brief Micro Trace Buffer
 */
/**
* @addtogroup MTB_structs_GROUP MTB struct
* @brief Struct for MTB
* @{
*/
typedef struct {                                /*       MTB Structure                                                */
   __IO uint32_t  POSITION;                     /**< 0000: MTB Position Register                                        */
   __IO uint32_t  MASTER;                       /**< 0004: MTB Master Register                                          */
   __IO uint32_t  FLOW;                         /**< 0008: MTB Flow Register                                            */
   __I  uint32_t  BASE;                         /**< 000C: MTB Base Register                                            */
   __I  uint32_t  RESERVED0[956];              
   __I  uint32_t  MODECTRL;                     /**< 0F00: Integration Mode Control Register                            */
   __I  uint32_t  RESERVED1[39];               
   __I  uint32_t  TAGSET;                       /**< 0FA0: Claim TAG Set Register                                       */
   __I  uint32_t  TAGCLEAR;                     /**< 0FA4: Claim TAG Clear Register                                     */
   __I  uint32_t  RESERVED2[2];                
   __I  uint32_t  LOCKACCESS;                   /**< 0FB0: Lock Access Register                                         */
   __I  uint32_t  LOCKSTAT;                     /**< 0FB4: Lock Status Register                                         */
   __I  uint32_t  AUTHSTAT;                     /**< 0FB8: Authentication Status Register                               */
   __I  uint32_t  DEVICEARCH;                   /**< 0FBC: Device Architecture Register                                 */
   __I  uint32_t  RESERVED3[2];                
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

/**
 * @} */ /* End group MTB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTB_Register_Masks_GROUP MTB Register Masks
* @brief Register Masks for MTB
* @{
*/
/* ------- POSITION Bit Fields                      ------ */
#define MTB_POSITION_WRAP_MASK                   (0x01UL << MTB_POSITION_WRAP_SHIFT)                 /*!< MTB_POSITION: WRAP Mask                 */
#define MTB_POSITION_WRAP_SHIFT                  2                                                   /*!< MTB_POSITION: WRAP Position             */
#define MTB_POSITION_POINTER_MASK                (0x1FFFFFFFUL << MTB_POSITION_POINTER_SHIFT)        /*!< MTB_POSITION: POINTER Mask              */
#define MTB_POSITION_POINTER_SHIFT               3                                                   /*!< MTB_POSITION: POINTER Position          */
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_POINTER_SHIFT))&MTB_POSITION_POINTER_MASK) /*!< MTB_POSITION                            */
/* ------- MASTER Bit Fields                        ------ */
#define MTB_MASTER_MASK_MASK                     (0x1FUL << MTB_MASTER_MASK_SHIFT)                   /*!< MTB_MASTER: MASK Mask                   */
#define MTB_MASTER_MASK_SHIFT                    0                                                   /*!< MTB_MASTER: MASK Position               */
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_MASK_SHIFT))&MTB_MASTER_MASK_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_TSTARTEN_MASK                 (0x01UL << MTB_MASTER_TSTARTEN_SHIFT)               /*!< MTB_MASTER: TSTARTEN Mask               */
#define MTB_MASTER_TSTARTEN_SHIFT                5                                                   /*!< MTB_MASTER: TSTARTEN Position           */
#define MTB_MASTER_TSTOPEN_MASK                  (0x01UL << MTB_MASTER_TSTOPEN_SHIFT)                /*!< MTB_MASTER: TSTOPEN Mask                */
#define MTB_MASTER_TSTOPEN_SHIFT                 6                                                   /*!< MTB_MASTER: TSTOPEN Position            */
#define MTB_MASTER_SFRWPRIV_MASK                 (0x01UL << MTB_MASTER_SFRWPRIV_SHIFT)               /*!< MTB_MASTER: SFRWPRIV Mask               */
#define MTB_MASTER_SFRWPRIV_SHIFT                7                                                   /*!< MTB_MASTER: SFRWPRIV Position           */
#define MTB_MASTER_RAMPRIV_MASK                  (0x01UL << MTB_MASTER_RAMPRIV_SHIFT)                /*!< MTB_MASTER: RAMPRIV Mask                */
#define MTB_MASTER_RAMPRIV_SHIFT                 8                                                   /*!< MTB_MASTER: RAMPRIV Position            */
#define MTB_MASTER_HALTREQ_MASK                  (0x01UL << MTB_MASTER_HALTREQ_SHIFT)                /*!< MTB_MASTER: HALTREQ Mask                */
#define MTB_MASTER_HALTREQ_SHIFT                 9                                                   /*!< MTB_MASTER: HALTREQ Position            */
#define MTB_MASTER_EN_MASK                       (0x01UL << MTB_MASTER_EN_SHIFT)                     /*!< MTB_MASTER: EN Mask                     */
#define MTB_MASTER_EN_SHIFT                      31                                                  /*!< MTB_MASTER: EN Position                 */
/* ------- FLOW Bit Fields                          ------ */
#define MTB_FLOW_AUTOSTOP_MASK                   (0x01UL << MTB_FLOW_AUTOSTOP_SHIFT)                 /*!< MTB_FLOW: AUTOSTOP Mask                 */
#define MTB_FLOW_AUTOSTOP_SHIFT                  0                                                   /*!< MTB_FLOW: AUTOSTOP Position             */
#define MTB_FLOW_AUTOHALT_MASK                   (0x01UL << MTB_FLOW_AUTOHALT_SHIFT)                 /*!< MTB_FLOW: AUTOHALT Mask                 */
#define MTB_FLOW_AUTOHALT_SHIFT                  1                                                   /*!< MTB_FLOW: AUTOHALT Position             */
#define MTB_FLOW_WATERMARK_MASK                  (0x1FFFFFFFUL << MTB_FLOW_WATERMARK_SHIFT)          /*!< MTB_FLOW: WATERMARK Mask                */
#define MTB_FLOW_WATERMARK_SHIFT                 3                                                   /*!< MTB_FLOW: WATERMARK Position            */
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_WATERMARK_SHIFT))&MTB_FLOW_WATERMARK_MASK) /*!< MTB_FLOW                                */
/* ------- BASE Bit Fields                          ------ */
#define MTB_BASE_BASEADDR_MASK                   (0xFFFFFFFFUL << MTB_BASE_BASEADDR_SHIFT)           /*!< MTB_BASE: BASEADDR Mask                 */
#define MTB_BASE_BASEADDR_SHIFT                  0                                                   /*!< MTB_BASE: BASEADDR Position             */
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_BASE_BASEADDR_SHIFT))&MTB_BASE_BASEADDR_MASK) /*!< MTB_BASE                                */
/* ------- MODECTRL Bit Fields                      ------ */
#define MTB_MODECTRL_MODECTRL_MASK               (0xFFFFFFFFUL << MTB_MODECTRL_MODECTRL_SHIFT)       /*!< MTB_MODECTRL: MODECTRL Mask             */
#define MTB_MODECTRL_MODECTRL_SHIFT              0                                                   /*!< MTB_MODECTRL: MODECTRL Position         */
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_MODECTRL_MODECTRL_SHIFT))&MTB_MODECTRL_MODECTRL_MASK) /*!< MTB_MODECTRL                            */
/* ------- TAGSET Bit Fields                        ------ */
#define MTB_TAGSET_TAGSET_MASK                   (0xFFFFFFFFUL << MTB_TAGSET_TAGSET_SHIFT)           /*!< MTB_TAGSET: TAGSET Mask                 */
#define MTB_TAGSET_TAGSET_SHIFT                  0                                                   /*!< MTB_TAGSET: TAGSET Position             */
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_TAGSET_TAGSET_SHIFT))&MTB_TAGSET_TAGSET_MASK) /*!< MTB_TAGSET                              */
/* ------- TAGCLEAR Bit Fields                      ------ */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               (0xFFFFFFFFUL << MTB_TAGCLEAR_TAGCLEAR_SHIFT)       /*!< MTB_TAGCLEAR: TAGCLEAR Mask             */
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              0                                                   /*!< MTB_TAGCLEAR: TAGCLEAR Position         */
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_TAGCLEAR_TAGCLEAR_SHIFT))&MTB_TAGCLEAR_TAGCLEAR_MASK) /*!< MTB_TAGCLEAR                            */
/* ------- LOCKACCESS Bit Fields                    ------ */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           (0xFFFFFFFFUL << MTB_LOCKACCESS_LOCKACCESS_SHIFT)   /*!< MTB_LOCKACCESS: LOCKACCESS Mask         */
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          0                                                   /*!< MTB_LOCKACCESS: LOCKACCESS Position     */
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<MTB_LOCKACCESS_LOCKACCESS_SHIFT))&MTB_LOCKACCESS_LOCKACCESS_MASK) /*!< MTB_LOCKACCESS                          */
/* ------- LOCKSTAT Bit Fields                      ------ */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               (0xFFFFFFFFUL << MTB_LOCKSTAT_LOCKSTAT_SHIFT)       /*!< MTB_LOCKSTAT: LOCKSTAT Mask             */
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              0                                                   /*!< MTB_LOCKSTAT: LOCKSTAT Position         */
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_LOCKSTAT_LOCKSTAT_SHIFT))&MTB_LOCKSTAT_LOCKSTAT_MASK) /*!< MTB_LOCKSTAT                            */
/* ------- AUTHSTAT Bit Fields                      ------ */
#define MTB_AUTHSTAT_BIT0_MASK                   (0x01UL << MTB_AUTHSTAT_BIT0_SHIFT)                 /*!< MTB_AUTHSTAT: BIT0 Mask                 */
#define MTB_AUTHSTAT_BIT0_SHIFT                  0                                                   /*!< MTB_AUTHSTAT: BIT0 Position             */
#define MTB_AUTHSTAT_BIT1_MASK                   (0x01UL << MTB_AUTHSTAT_BIT1_SHIFT)                 /*!< MTB_AUTHSTAT: BIT1 Mask                 */
#define MTB_AUTHSTAT_BIT1_SHIFT                  1                                                   /*!< MTB_AUTHSTAT: BIT1 Position             */
#define MTB_AUTHSTAT_BIT2_MASK                   (0x01UL << MTB_AUTHSTAT_BIT2_SHIFT)                 /*!< MTB_AUTHSTAT: BIT2 Mask                 */
#define MTB_AUTHSTAT_BIT2_SHIFT                  2                                                   /*!< MTB_AUTHSTAT: BIT2 Position             */
#define MTB_AUTHSTAT_BIT3_MASK                   (0x01UL << MTB_AUTHSTAT_BIT3_SHIFT)                 /*!< MTB_AUTHSTAT: BIT3 Mask                 */
#define MTB_AUTHSTAT_BIT3_SHIFT                  3                                                   /*!< MTB_AUTHSTAT: BIT3 Position             */
/* ------- DEVICEARCH Bit Fields                    ------ */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           (0xFFFFFFFFUL << MTB_DEVICEARCH_DEVICEARCH_SHIFT)   /*!< MTB_DEVICEARCH: DEVICEARCH Mask         */
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          0                                                   /*!< MTB_DEVICEARCH: DEVICEARCH Position     */
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<MTB_DEVICEARCH_DEVICEARCH_SHIFT))&MTB_DEVICEARCH_DEVICEARCH_MASK) /*!< MTB_DEVICEARCH                          */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTB_DEVICECFG_DEVICECFG_MASK             (0xFFFFFFFFUL << MTB_DEVICECFG_DEVICECFG_SHIFT)     /*!< MTB_DEVICECFG: DEVICECFG Mask           */
#define MTB_DEVICECFG_DEVICECFG_SHIFT            0                                                   /*!< MTB_DEVICECFG: DEVICECFG Position       */
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<MTB_DEVICECFG_DEVICECFG_SHIFT))&MTB_DEVICECFG_DEVICECFG_MASK) /*!< MTB_DEVICECFG                           */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         (0xFFFFFFFFUL << MTB_DEVICETYPID_DEVICETYPID_SHIFT) /*!< MTB_DEVICETYPID: DEVICETYPID Mask       */
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        0                                                   /*!< MTB_DEVICETYPID: DEVICETYPID Position   */
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<MTB_DEVICETYPID_DEVICETYPID_SHIFT))&MTB_DEVICETYPID_DEVICETYPID_MASK) /*!< MTB_DEVICETYPID                         */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTB_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFUL << MTB_PERIPHID_PERIPHID_SHIFT)       /*!< MTB_PERIPHID: PERIPHID Mask             */
#define MTB_PERIPHID_PERIPHID_SHIFT              0                                                   /*!< MTB_PERIPHID: PERIPHID Position         */
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_PERIPHID_PERIPHID_SHIFT))&MTB_PERIPHID_PERIPHID_MASK) /*!< MTB_PERIPHID                            */
/* ------- COMPID Bit Fields                        ------ */
#define MTB_COMPID_COMPID_MASK                   (0xFFFFFFFFUL << MTB_COMPID_COMPID_SHIFT)           /*!< MTB_COMPID: COMPID Mask                 */
#define MTB_COMPID_COMPID_SHIFT                  0                                                   /*!< MTB_COMPID: COMPID Position             */
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_COMPID_COMPID_SHIFT))&MTB_COMPID_COMPID_MASK) /*!< MTB_COMPID                              */
/**
 * @} */ /* End group MTB_Register_Masks_GROUP 
 */

/* MTB - Peripheral instance base addresses */
#define MTB_BasePtr                    0xF0000000UL //!< Peripheral base address
#define MTB                            ((MTB_Type *) MTB_BasePtr) //!< Freescale base pointer
#define MTB_BASE_PTR                   (MTB) //!< Freescale style base pointer
/**
 * @} */ /* End group MTB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTBDWT_Peripheral_access_layer_GROUP MTBDWT Peripheral Access Layer
* @brief C Struct for MTBDWT
* @{
*/

/* ================================================================================ */
/* ================           MTBDWT (file:MTBDWT_MKL)             ================ */
/* ================================================================================ */

/**
 * @brief MTB data watchpoint and trace
 */
/**
* @addtogroup MTBDWT_structs_GROUP MTBDWT struct
* @brief Struct for MTBDWT
* @{
*/
typedef struct {                                /*       MTBDWT Structure                                             */
   __I  uint32_t  CTRL;                         /**< 0000: MTB DWT Control Register                                     */
   __I  uint32_t  RESERVED0[7];                
   struct {
      __IO uint32_t  COMP;                      /**< 0020: MTB_DWT Comparator Register                                  */
      __IO uint32_t  MASK;                      /**< 0024: MTB_DWT Comparator Mask Register                             */
      __IO uint32_t  FCT;                       /**< 0028: MTB_DWT Comparator Function Register 0                       */
      __I  uint32_t  RESERVED0;                
   } COMPARATOR[2];                             /**< 0020: (cluster: size=0x0020, 32)                                   */
   __I  uint32_t  RESERVED1[112];              
   __IO uint32_t  TBCTRL;                       /**< 0200: MTB_DWT Trace Buffer Control Register                        */
   __I  uint32_t  RESERVED2[881];              
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

/**
 * @} */ /* End group MTBDWT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTBDWT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTBDWT_Register_Masks_GROUP MTBDWT Register Masks
* @brief Register Masks for MTBDWT
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define MTBDWT_CTRL_DWTCFGCTRL_MASK              (0xFFFFFFFUL << MTBDWT_CTRL_DWTCFGCTRL_SHIFT)       /*!< MTBDWT_CTRL: DWTCFGCTRL Mask            */
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             0                                                   /*!< MTBDWT_CTRL: DWTCFGCTRL Position        */
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_DWTCFGCTRL_SHIFT))&MTBDWT_CTRL_DWTCFGCTRL_MASK) /*!< MTBDWT_CTRL                             */
#define MTBDWT_CTRL_NUMCMP_MASK                  (0x0FUL << MTBDWT_CTRL_NUMCMP_SHIFT)                /*!< MTBDWT_CTRL: NUMCMP Mask                */
#define MTBDWT_CTRL_NUMCMP_SHIFT                 28                                                  /*!< MTBDWT_CTRL: NUMCMP Position            */
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_NUMCMP_SHIFT))&MTBDWT_CTRL_NUMCMP_MASK) /*!< MTBDWT_CTRL                             */
/* ------- COMP Bit Fields                          ------ */
#define MTBDWT_COMP_COMP_MASK                    (0xFFFFFFFFUL << MTBDWT_COMP_COMP_SHIFT)            /*!< MTBDWT_COMP: COMP Mask                  */
#define MTBDWT_COMP_COMP_SHIFT                   0                                                   /*!< MTBDWT_COMP: COMP Position              */
#define MTBDWT_COMP_COMP(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMP_COMP_SHIFT))&MTBDWT_COMP_COMP_MASK) /*!< MTBDWT_COMP                             */
/* ------- MASK Bit Fields                          ------ */
#define MTBDWT_MASK_MASK_MASK                    (0x1FUL << MTBDWT_MASK_MASK_SHIFT)                  /*!< MTBDWT_MASK: MASK Mask                  */
#define MTBDWT_MASK_MASK_SHIFT                   0                                                   /*!< MTBDWT_MASK: MASK Position              */
#define MTBDWT_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_MASK_MASK_SHIFT))&MTBDWT_MASK_MASK_MASK) /*!< MTBDWT_MASK                             */
/* ------- FCT Bit Fields                           ------ */
#define MTBDWT_FCT_FUNCTION_MASK                 (0x0FUL << MTBDWT_FCT_FUNCTION_SHIFT)               /*!< MTBDWT_FCT: FUNCTION Mask               */
#define MTBDWT_FCT_FUNCTION_SHIFT                0                                                   /*!< MTBDWT_FCT: FUNCTION Position           */
#define MTBDWT_FCT_FUNCTION(x)                   (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_FUNCTION_SHIFT))&MTBDWT_FCT_FUNCTION_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_DATAVMATCH_MASK               (0x01UL << MTBDWT_FCT_DATAVMATCH_SHIFT)             /*!< MTBDWT_FCT: DATAVMATCH Mask             */
#define MTBDWT_FCT_DATAVMATCH_SHIFT              8                                                   /*!< MTBDWT_FCT: DATAVMATCH Position         */
#define MTBDWT_FCT_DATAVSIZE_MASK                (0x03UL << MTBDWT_FCT_DATAVSIZE_SHIFT)              /*!< MTBDWT_FCT: DATAVSIZE Mask              */
#define MTBDWT_FCT_DATAVSIZE_SHIFT               10                                                  /*!< MTBDWT_FCT: DATAVSIZE Position          */
#define MTBDWT_FCT_DATAVSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVSIZE_SHIFT))&MTBDWT_FCT_DATAVSIZE_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_DATAVADDR0_MASK               (0x0FUL << MTBDWT_FCT_DATAVADDR0_SHIFT)             /*!< MTBDWT_FCT: DATAVADDR0 Mask             */
#define MTBDWT_FCT_DATAVADDR0_SHIFT              12                                                  /*!< MTBDWT_FCT: DATAVADDR0 Position         */
#define MTBDWT_FCT_DATAVADDR0(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVADDR0_SHIFT))&MTBDWT_FCT_DATAVADDR0_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_MATCHED_MASK                  (0x01UL << MTBDWT_FCT_MATCHED_SHIFT)                /*!< MTBDWT_FCT: MATCHED Mask                */
#define MTBDWT_FCT_MATCHED_SHIFT                 24                                                  /*!< MTBDWT_FCT: MATCHED Position            */
/* ------- TBCTRL Bit Fields                        ------ */
#define MTBDWT_TBCTRL_ACOMP0_MASK                (0x01UL << MTBDWT_TBCTRL_ACOMP0_SHIFT)              /*!< MTBDWT_TBCTRL: ACOMP0 Mask              */
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               0                                                   /*!< MTBDWT_TBCTRL: ACOMP0 Position          */
#define MTBDWT_TBCTRL_ACOMP1_MASK                (0x01UL << MTBDWT_TBCTRL_ACOMP1_SHIFT)              /*!< MTBDWT_TBCTRL: ACOMP1 Mask              */
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               1                                                   /*!< MTBDWT_TBCTRL: ACOMP1 Position          */
#define MTBDWT_TBCTRL_NUMCOMP_MASK               (0x0FUL << MTBDWT_TBCTRL_NUMCOMP_SHIFT)             /*!< MTBDWT_TBCTRL: NUMCOMP Mask             */
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              28                                                  /*!< MTBDWT_TBCTRL: NUMCOMP Position         */
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_NUMCOMP_SHIFT))&MTBDWT_TBCTRL_NUMCOMP_MASK) /*!< MTBDWT_TBCTRL                           */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTBDWT_DEVICECFG_DEVICECFG_MASK          (0xFFFFFFFFUL << MTBDWT_DEVICECFG_DEVICECFG_SHIFT)  /*!< MTBDWT_DEVICECFG: DEVICECFG Mask        */
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         0                                                   /*!< MTBDWT_DEVICECFG: DEVICECFG Position    */
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICECFG_DEVICECFG_SHIFT))&MTBDWT_DEVICECFG_DEVICECFG_MASK) /*!< MTBDWT_DEVICECFG                        */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      (0xFFFFFFFFUL << MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT) /*!< MTBDWT_DEVICETYPID: DEVICETYPID Mask    */
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     0                                                   /*!< MTBDWT_DEVICETYPID: DEVICETYPID Position*/
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT))&MTBDWT_DEVICETYPID_DEVICETYPID_MASK) /*!< MTBDWT_DEVICETYPID                      */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTBDWT_PERIPHID_PERIPHID_MASK            (0xFFFFFFFFUL << MTBDWT_PERIPHID_PERIPHID_SHIFT)    /*!< MTBDWT_PERIPHID: PERIPHID Mask          */
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           0                                                   /*!< MTBDWT_PERIPHID: PERIPHID Position      */
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x))<<MTBDWT_PERIPHID_PERIPHID_SHIFT))&MTBDWT_PERIPHID_PERIPHID_MASK) /*!< MTBDWT_PERIPHID                         */
/* ------- COMPID Bit Fields                        ------ */
#define MTBDWT_COMPID_COMPID_MASK                (0xFFFFFFFFUL << MTBDWT_COMPID_COMPID_SHIFT)        /*!< MTBDWT_COMPID: COMPID Mask              */
#define MTBDWT_COMPID_COMPID_SHIFT               0                                                   /*!< MTBDWT_COMPID: COMPID Position          */
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMPID_COMPID_SHIFT))&MTBDWT_COMPID_COMPID_MASK) /*!< MTBDWT_COMPID                           */
/**
 * @} */ /* End group MTBDWT_Register_Masks_GROUP 
 */

/* MTBDWT - Peripheral instance base addresses */
#define MTBDWT_BasePtr                 0xF0001000UL //!< Peripheral base address
#define MTBDWT                         ((MTBDWT_Type *) MTBDWT_BasePtr) //!< Freescale base pointer
#define MTBDWT_BASE_PTR                (MTBDWT) //!< Freescale style base pointer
/**
 * @} */ /* End group MTBDWT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_MKM)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
* @addtogroup NV_structs_GROUP NV struct
* @brief Struct for NV
* @{
*/
typedef struct {                                /*       NV Structure                                                 */
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

/**
 * @} */ /* End group NV_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup NV_Register_Masks_GROUP NV Register Masks
* @brief Register Masks for NV
* @{
*/
/* ------- BACKKEY Bit Fields                       ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFUL << NV_BACKKEY_KEY_SHIFT)                    /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     0                                                   /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /*!< NV_BACKKEY                              */
/* ------- FPROT3 Bit Fields                        ------ */
#define NV_FPROT3_PROT_MASK                      (0xFFUL << NV_FPROT3_PROT_SHIFT)                    /*!< NV_FPROT3: PROT Mask                    */
#define NV_FPROT3_PROT_SHIFT                     0                                                   /*!< NV_FPROT3: PROT Position                */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK) /*!< NV_FPROT3                               */
/* ------- FPROT2 Bit Fields                        ------ */
#define NV_FPROT2_PROT_MASK                      (0xFFUL << NV_FPROT2_PROT_SHIFT)                    /*!< NV_FPROT2: PROT Mask                    */
#define NV_FPROT2_PROT_SHIFT                     0                                                   /*!< NV_FPROT2: PROT Position                */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK) /*!< NV_FPROT2                               */
/* ------- FPROT1 Bit Fields                        ------ */
#define NV_FPROT1_PROT_MASK                      (0xFFUL << NV_FPROT1_PROT_SHIFT)                    /*!< NV_FPROT1: PROT Mask                    */
#define NV_FPROT1_PROT_SHIFT                     0                                                   /*!< NV_FPROT1: PROT Position                */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK) /*!< NV_FPROT1                               */
/* ------- FPROT0 Bit Fields                        ------ */
#define NV_FPROT0_PROT_MASK                      (0xFFUL << NV_FPROT0_PROT_SHIFT)                    /*!< NV_FPROT0: PROT Mask                    */
#define NV_FPROT0_PROT_SHIFT                     0                                                   /*!< NV_FPROT0: PROT Position                */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK) /*!< NV_FPROT0                               */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x03UL << NV_FSEC_SEC_SHIFT)                       /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        0                                                   /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_FSLACC_MASK                      (0x03UL << NV_FSEC_FSLACC_SHIFT)                    /*!< NV_FSEC: FSLACC Mask                    */
#define NV_FSEC_FSLACC_SHIFT                     2                                                   /*!< NV_FSEC: FSLACC Position                */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_MEEN_MASK                        (0x03UL << NV_FSEC_MEEN_SHIFT)                      /*!< NV_FSEC: MEEN Mask                      */
#define NV_FSEC_MEEN_SHIFT                       4                                                   /*!< NV_FSEC: MEEN Position                  */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0x03UL << NV_FSEC_KEYEN_SHIFT)                     /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      6                                                   /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /*!< NV_FSEC                                 */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x01UL << NV_FOPT_LPBOOT_SHIFT)                    /*!< NV_FOPT: LPBOOT Mask                    */
#define NV_FOPT_LPBOOT_SHIFT                     0                                                   /*!< NV_FOPT: LPBOOT Position                */
#define NV_FOPT_NMI_EN_MASK                      (0x01UL << NV_FOPT_NMI_EN_SHIFT)                    /*!< NV_FOPT: NMI_EN Mask                    */
#define NV_FOPT_NMI_EN_SHIFT                     2                                                   /*!< NV_FOPT: NMI_EN Position                */
#define NV_FOPT_EXE_MODE_MASK                    (0x01UL << NV_FOPT_EXE_MODE_SHIFT)                  /*!< NV_FOPT: EXE_MODE Mask                  */
#define NV_FOPT_EXE_MODE_SHIFT                   3                                                   /*!< NV_FOPT: EXE_MODE Position              */
#define NV_FOPT_CLK_SRC_MASK                     (0x01UL << NV_FOPT_CLK_SRC_SHIFT)                   /*!< NV_FOPT: CLK_SRC Mask                   */
#define NV_FOPT_CLK_SRC_SHIFT                    5                                                   /*!< NV_FOPT: CLK_SRC Position               */
/**
 * @} */ /* End group NV_Register_Masks_GROUP 
 */

/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer
/**
 * @} */ /* End group NV_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC0 (file:OSC_MKM)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SC16P_MASK                        (0x01UL << OSC_CR_SC16P_SHIFT)                      /*!< OSC0_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       0                                                   /*!< OSC0_CR: SC16P Position                 */
#define OSC_CR_SC8P_MASK                         (0x01UL << OSC_CR_SC8P_SHIFT)                       /*!< OSC0_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        1                                                   /*!< OSC0_CR: SC8P Position                  */
#define OSC_CR_SC4P_MASK                         (0x01UL << OSC_CR_SC4P_SHIFT)                       /*!< OSC0_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        2                                                   /*!< OSC0_CR: SC4P Position                  */
#define OSC_CR_SC2P_MASK                         (0x01UL << OSC_CR_SC2P_SHIFT)                       /*!< OSC0_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        3                                                   /*!< OSC0_CR: SC2P Position                  */
#define OSC_CR_EREFSTEN_MASK                     (0x01UL << OSC_CR_EREFSTEN_SHIFT)                   /*!< OSC0_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    5                                                   /*!< OSC0_CR: EREFSTEN Position              */
#define OSC_CR_ERCLKEN_MASK                      (0x01UL << OSC_CR_ERCLKEN_SHIFT)                    /*!< OSC0_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     7                                                   /*!< OSC0_CR: ERCLKEN Position               */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40066000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT0 (file:PIT0_2CH_CHAIN_MKM)       ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (2 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
   __I  uint32_t  RESERVED0[63];               
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[2];                                /**< 0100: (cluster: size=0x0020, 32)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x01UL << PIT_MCR_FRZ_SHIFT)                       /*!< PIT0_MCR: FRZ Mask                      */
#define PIT_MCR_FRZ_SHIFT                        0                                                   /*!< PIT0_MCR: FRZ Position                  */
#define PIT_MCR_MDIS_MASK                        (0x01UL << PIT_MCR_MDIS_SHIFT)                      /*!< PIT0_MCR: MDIS Mask                     */
#define PIT_MCR_MDIS_SHIFT                       1                                                   /*!< PIT0_MCR: MDIS Position                 */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFUL << PIT_LDVAL_TSV_SHIFT)               /*!< PIT0_LDVAL: TSV Mask                    */
#define PIT_LDVAL_TSV_SHIFT                      0                                                   /*!< PIT0_LDVAL: TSV Position                */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /*!< PIT0_LDVAL                              */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFUL << PIT_CVAL_TVL_SHIFT)                /*!< PIT0_CVAL: TVL Mask                     */
#define PIT_CVAL_TVL_SHIFT                       0                                                   /*!< PIT0_CVAL: TVL Position                 */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /*!< PIT0_CVAL                               */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x01UL << PIT_TCTRL_TEN_SHIFT)                     /*!< PIT0_TCTRL: TEN Mask                    */
#define PIT_TCTRL_TEN_SHIFT                      0                                                   /*!< PIT0_TCTRL: TEN Position                */
#define PIT_TCTRL_TIE_MASK                       (0x01UL << PIT_TCTRL_TIE_SHIFT)                     /*!< PIT0_TCTRL: TIE Mask                    */
#define PIT_TCTRL_TIE_SHIFT                      1                                                   /*!< PIT0_TCTRL: TIE Position                */
#define PIT_TCTRL_CHN_MASK                       (0x01UL << PIT_TCTRL_CHN_SHIFT)                     /*!< PIT0_TCTRL: CHN Mask                    */
#define PIT_TCTRL_CHN_SHIFT                      2                                                   /*!< PIT0_TCTRL: CHN Position                */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x01UL << PIT_TFLG_TIF_SHIFT)                      /*!< PIT0_TFLG: TIF Mask                     */
#define PIT_TFLG_TIF_SHIFT                       0                                                   /*!< PIT0_TFLG: TIF Position                 */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT0 - Peripheral instance base addresses */
#define PIT0_BasePtr                   0x4002D000UL //!< Peripheral base address
#define PIT0                           ((PIT_Type *) PIT0_BasePtr) //!< Freescale base pointer
#define PIT0_BASE_PTR                  (PIT0) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT1 (derived from PIT0)             ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (2 channels)
 */

/* PIT1 - Peripheral instance base addresses */
#define PIT1_BasePtr                   0x4002E000UL //!< Peripheral base address
#define PIT1                           ((PIT_Type *) PIT1_BasePtr) //!< Freescale base pointer
#define PIT1_BASE_PTR                  (PIT1) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
* @addtogroup PMC_structs_GROUP PMC struct
* @brief Struct for PMC
* @{
*/
typedef struct {                                /*       PMC Structure                                                */
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Detect Status and Control 1 Register             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Detect Status and Control 2 Register             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control Register                        */
} PMC_Type;

/**
 * @} */ /* End group PMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMC_Register_Masks_GROUP PMC Register Masks
* @brief Register Masks for PMC
* @{
*/
/* ------- LVDSC1 Bit Fields                        ------ */
#define PMC_LVDSC1_LVDV_MASK                     (0x03UL << PMC_LVDSC1_LVDV_SHIFT)                   /*!< PMC_LVDSC1: LVDV Mask                   */
#define PMC_LVDSC1_LVDV_SHIFT                    0                                                   /*!< PMC_LVDSC1: LVDV Position               */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDRE_MASK                    (0x01UL << PMC_LVDSC1_LVDRE_SHIFT)                  /*!< PMC_LVDSC1: LVDRE Mask                  */
#define PMC_LVDSC1_LVDRE_SHIFT                   4                                                   /*!< PMC_LVDSC1: LVDRE Position              */
#define PMC_LVDSC1_LVDIE_MASK                    (0x01UL << PMC_LVDSC1_LVDIE_SHIFT)                  /*!< PMC_LVDSC1: LVDIE Mask                  */
#define PMC_LVDSC1_LVDIE_SHIFT                   5                                                   /*!< PMC_LVDSC1: LVDIE Position              */
#define PMC_LVDSC1_LVDACK_MASK                   (0x01UL << PMC_LVDSC1_LVDACK_SHIFT)                 /*!< PMC_LVDSC1: LVDACK Mask                 */
#define PMC_LVDSC1_LVDACK_SHIFT                  6                                                   /*!< PMC_LVDSC1: LVDACK Position             */
#define PMC_LVDSC1_LVDF_MASK                     (0x01UL << PMC_LVDSC1_LVDF_SHIFT)                   /*!< PMC_LVDSC1: LVDF Mask                   */
#define PMC_LVDSC1_LVDF_SHIFT                    7                                                   /*!< PMC_LVDSC1: LVDF Position               */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x03UL << PMC_LVDSC2_LVWV_SHIFT)                   /*!< PMC_LVDSC2: LVWV Mask                   */
#define PMC_LVDSC2_LVWV_SHIFT                    0                                                   /*!< PMC_LVDSC2: LVWV Position               */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWIE_MASK                    (0x01UL << PMC_LVDSC2_LVWIE_SHIFT)                  /*!< PMC_LVDSC2: LVWIE Mask                  */
#define PMC_LVDSC2_LVWIE_SHIFT                   5                                                   /*!< PMC_LVDSC2: LVWIE Position              */
#define PMC_LVDSC2_LVWACK_MASK                   (0x01UL << PMC_LVDSC2_LVWACK_SHIFT)                 /*!< PMC_LVDSC2: LVWACK Mask                 */
#define PMC_LVDSC2_LVWACK_SHIFT                  6                                                   /*!< PMC_LVDSC2: LVWACK Position             */
#define PMC_LVDSC2_LVWF_MASK                     (0x01UL << PMC_LVDSC2_LVWF_SHIFT)                   /*!< PMC_LVDSC2: LVWF Mask                   */
#define PMC_LVDSC2_LVWF_SHIFT                    7                                                   /*!< PMC_LVDSC2: LVWF Position               */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x01UL << PMC_REGSC_BGBE_SHIFT)                    /*!< PMC_REGSC: BGBE Mask                    */
#define PMC_REGSC_BGBE_SHIFT                     0                                                   /*!< PMC_REGSC: BGBE Position                */
#define PMC_REGSC_BGBDS_MASK                     (0x01UL << PMC_REGSC_BGBDS_SHIFT)                   /*!< PMC_REGSC: BGBDS Mask                   */
#define PMC_REGSC_BGBDS_SHIFT                    1                                                   /*!< PMC_REGSC: BGBDS Position               */
#define PMC_REGSC_REGONS_MASK                    (0x01UL << PMC_REGSC_REGONS_SHIFT)                  /*!< PMC_REGSC: REGONS Mask                  */
#define PMC_REGSC_REGONS_SHIFT                   2                                                   /*!< PMC_REGSC: REGONS Position              */
#define PMC_REGSC_ACKISO_MASK                    (0x01UL << PMC_REGSC_ACKISO_SHIFT)                  /*!< PMC_REGSC: ACKISO Mask                  */
#define PMC_REGSC_ACKISO_SHIFT                   3                                                   /*!< PMC_REGSC: ACKISO Position              */
#define PMC_REGSC_BGEN_MASK                      (0x01UL << PMC_REGSC_BGEN_SHIFT)                    /*!< PMC_REGSC: BGEN Mask                    */
#define PMC_REGSC_BGEN_SHIFT                     4                                                   /*!< PMC_REGSC: BGEN Position                */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTA (file:PORTA_MKM)               ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTA Structure                                              */
   __IO uint32_t  PCR[8];                       /**< 0000: Pin Control Register                                         */
   __I  uint32_t  RESERVED0[24];               
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
   __I  uint32_t  RESERVED1[6];                
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
} PORT_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
#define PORT_PCR_PS_MASK                         (0x01UL << PORT_PCR_PS_SHIFT)                       /*!< PORTA_PCR: PS Mask                      */
#define PORT_PCR_PS_SHIFT                        0                                                   /*!< PORTA_PCR: PS Position                  */
#define PORT_PCR_PE_MASK                         (0x01UL << PORT_PCR_PE_SHIFT)                       /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        1                                                   /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_SRE_MASK                        (0x01UL << PORT_PCR_SRE_SHIFT)                      /*!< PORTA_PCR: SRE Mask                     */
#define PORT_PCR_SRE_SHIFT                       2                                                   /*!< PORTA_PCR: SRE Position                 */
#define PORT_PCR_MUX_MASK                        (0x07UL << PORT_PCR_MUX_SHIFT)                      /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       8                                                   /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_LK_MASK                         (0x01UL << PORT_PCR_LK_SHIFT)                       /*!< PORTA_PCR: LK Mask                      */
#define PORT_PCR_LK_SHIFT                        15                                                  /*!< PORTA_PCR: LK Position                  */
#define PORT_PCR_IRQC_MASK                       (0x0FUL << PORT_PCR_IRQC_SHIFT)                     /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      16                                                  /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x01UL << PORT_PCR_ISF_SHIFT)                      /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       24                                                  /*!< PORTA_PCR: ISF Position                 */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFUL << PORT_GPCLR_GPWD_SHIFT)                 /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFFUL << PORT_GPCLR_GPWE_SHIFT)                 /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFUL << PORT_GPCHR_GPWD_SHIFT)                 /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFFUL << PORT_GPCHR_GPWE_SHIFT)                 /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */
/* ------- ISFR Bit Fields                          ------ */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40046000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTB - Peripheral instance base addresses */
#define PORTB_BasePtr                  0x40047000UL //!< Peripheral base address
#define PORTB                          ((PORT_Type *) PORTB_BasePtr) //!< Freescale base pointer
#define PORTB_BASE_PTR                 (PORTB) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTC (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x40048000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTD (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTD                          ((PORT_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTE (file:PORTE_MKM_FILT)          ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTE Structure                                              */
   __IO uint32_t  PCR[8];                       /**< 0000: Pin Control Register                                         */
   __I  uint32_t  RESERVED0[24];               
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
   __I  uint32_t  RESERVED1[6];                
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
   __I  uint32_t  RESERVED2[7];                
   __IO uint32_t  DFER;                         /**< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /**< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /**< 00C8: Digital Filter Width Register                                */
} PORTE_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTE' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
/* ------- GPCLR Bit Fields                         ------ */
/* ------- GPCHR Bit Fields                         ------ */
/* ------- ISFR Bit Fields                          ------ */
/* ------- DFER Bit Fields                          ------ */
/* ------- DFCR Bit Fields                          ------ */
#define PORT_DFCR_CS_MASK                        (0x01UL << PORT_DFCR_CS_SHIFT)                      /*!< PORTE_DFCR: CS Mask                     */
#define PORT_DFCR_CS_SHIFT                       0                                                   /*!< PORTE_DFCR: CS Position                 */
/* ------- DFWR Bit Fields                          ------ */
#define PORT_DFWR_FILT_MASK                      (0x1FUL << PORT_DFWR_FILT_SHIFT)                    /*!< PORTE_DFWR: FILT Mask                   */
#define PORT_DFWR_FILT_SHIFT                     0                                                   /*!< PORTE_DFWR: FILT Position               */
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK) /*!< PORTE_DFWR                              */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004A000UL //!< Peripheral base address
#define PORTE                          ((PORTE_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTF (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTF - Peripheral instance base addresses */
#define PORTF_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTF                          ((PORT_Type *) PORTF_BasePtr) //!< Freescale base pointer
#define PORTF_BASE_PTR                 (PORTF) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTG (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTG - Peripheral instance base addresses */
#define PORTG_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTG                          ((PORT_Type *) PORTG_BasePtr) //!< Freescale base pointer
#define PORTG_BASE_PTR                 (PORTG) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTH (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTH - Peripheral instance base addresses */
#define PORTH_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTH                          ((PORT_Type *) PORTH_BasePtr) //!< Freescale base pointer
#define PORTH_BASE_PTR                 (PORTH) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTI (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTI - Peripheral instance base addresses */
#define PORTI_BasePtr                  0x4004E000UL //!< Peripheral base address
#define PORTI                          ((PORT_Type *) PORTI_BasePtr) //!< Freescale base pointer
#define PORTI_BASE_PTR                 (PORTI) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MKM14ZA5)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
} RCM_Type;

/**
 * @} */ /* End group RCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RCM_Register_Masks_GROUP RCM Register Masks
* @brief Register Masks for RCM
* @{
*/
/* ------- SRS0 Bit Fields                          ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x01UL << RCM_SRS0_WAKEUP_SHIFT)                   /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    0                                                   /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_LVD_MASK                        (0x01UL << RCM_SRS0_LVD_SHIFT)                      /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       1                                                   /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LOC_MASK                        (0x01UL << RCM_SRS0_LOC_SHIFT)                      /*!< RCM_SRS0: LOC Mask                      */
#define RCM_SRS0_LOC_SHIFT                       2                                                   /*!< RCM_SRS0: LOC Position                  */
#define RCM_SRS0_LOL_MASK                        (0x01UL << RCM_SRS0_LOL_SHIFT)                      /*!< RCM_SRS0: LOL Mask                      */
#define RCM_SRS0_LOL_SHIFT                       3                                                   /*!< RCM_SRS0: LOL Position                  */
#define RCM_SRS0_WDOG_MASK                       (0x01UL << RCM_SRS0_WDOG_SHIFT)                     /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      5                                                   /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_PIN_MASK                        (0x01UL << RCM_SRS0_PIN_SHIFT)                      /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       6                                                   /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_POR_MASK                        (0x01UL << RCM_SRS0_POR_SHIFT)                      /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       7                                                   /*!< RCM_SRS0: POR Position                  */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_LOCKUP_MASK                     (0x01UL << RCM_SRS1_LOCKUP_SHIFT)                   /*!< RCM_SRS1: LOCKUP Mask                   */
#define RCM_SRS1_LOCKUP_SHIFT                    1                                                   /*!< RCM_SRS1: LOCKUP Position               */
#define RCM_SRS1_SW_MASK                         (0x01UL << RCM_SRS1_SW_SHIFT)                       /*!< RCM_SRS1: SW Mask                       */
#define RCM_SRS1_SW_SHIFT                        2                                                   /*!< RCM_SRS1: SW Position                   */
#define RCM_SRS1_MDM_AP_MASK                     (0x01UL << RCM_SRS1_MDM_AP_SHIFT)                   /*!< RCM_SRS1: MDM_AP Mask                   */
#define RCM_SRS1_MDM_AP_SHIFT                    3                                                   /*!< RCM_SRS1: MDM_AP Position               */
#define RCM_SRS1_SACKERR_MASK                    (0x01UL << RCM_SRS1_SACKERR_SHIFT)                  /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   5                                                   /*!< RCM_SRS1: SACKERR Position              */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x03UL << RCM_RPFC_RSTFLTSRW_SHIFT)                /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0                                                   /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x01UL << RCM_RPFC_RSTFLTSS_SHIFT)                 /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  2                                                   /*!< RCM_RPFC: RSTFLTSS Position             */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FUL << RCM_RPFW_RSTFLTSEL_SHIFT)                /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0                                                   /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007B000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RNG_Peripheral_access_layer_GROUP RNG Peripheral Access Layer
* @brief C Struct for RNG
* @{
*/

/* ================================================================================ */
/* ================           RNG (file:RNG_1)                     ================ */
/* ================================================================================ */

/**
 * @brief Random Number Generator Accelerator
 */
/**
* @addtogroup RNG_structs_GROUP RNG struct
* @brief Struct for RNG
* @{
*/
typedef struct {                                /*       RNG Structure                                                */
   __IO uint32_t  CR;                           /**< 0000: RNGA Control Register                                        */
   __I  uint32_t  SR;                           /**< 0004: RNGA Status Register                                         */
   __O  uint32_t  ER;                           /**< 0008: RNGA Entropy Register                                        */
   __I  uint32_t  OR;                           /**< 000C: RNGA Output Register                                         */
} RNG_Type;

/**
 * @} */ /* End group RNG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RNG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RNG_Register_Masks_GROUP RNG Register Masks
* @brief Register Masks for RNG
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define RNG_CR_GO_MASK                           (0x01UL << RNG_CR_GO_SHIFT)                         /*!< RNG_CR: GO Mask                         */
#define RNG_CR_GO_SHIFT                          0                                                   /*!< RNG_CR: GO Position                     */
#define RNG_CR_HA_MASK                           (0x01UL << RNG_CR_HA_SHIFT)                         /*!< RNG_CR: HA Mask                         */
#define RNG_CR_HA_SHIFT                          1                                                   /*!< RNG_CR: HA Position                     */
#define RNG_CR_INTM_MASK                         (0x01UL << RNG_CR_INTM_SHIFT)                       /*!< RNG_CR: INTM Mask                       */
#define RNG_CR_INTM_SHIFT                        2                                                   /*!< RNG_CR: INTM Position                   */
#define RNG_CR_CLRI_MASK                         (0x01UL << RNG_CR_CLRI_SHIFT)                       /*!< RNG_CR: CLRI Mask                       */
#define RNG_CR_CLRI_SHIFT                        3                                                   /*!< RNG_CR: CLRI Position                   */
#define RNG_CR_SLP_MASK                          (0x01UL << RNG_CR_SLP_SHIFT)                        /*!< RNG_CR: SLP Mask                        */
#define RNG_CR_SLP_SHIFT                         4                                                   /*!< RNG_CR: SLP Position                    */
/* ------- SR Bit Fields                            ------ */
#define RNG_SR_SECV_MASK                         (0x01UL << RNG_SR_SECV_SHIFT)                       /*!< RNG_SR: SECV Mask                       */
#define RNG_SR_SECV_SHIFT                        0                                                   /*!< RNG_SR: SECV Position                   */
#define RNG_SR_LRS_MASK                          (0x01UL << RNG_SR_LRS_SHIFT)                        /*!< RNG_SR: LRS Mask                        */
#define RNG_SR_LRS_SHIFT                         1                                                   /*!< RNG_SR: LRS Position                    */
#define RNG_SR_ORU_MASK                          (0x01UL << RNG_SR_ORU_SHIFT)                        /*!< RNG_SR: ORU Mask                        */
#define RNG_SR_ORU_SHIFT                         2                                                   /*!< RNG_SR: ORU Position                    */
#define RNG_SR_ERRI_MASK                         (0x01UL << RNG_SR_ERRI_SHIFT)                       /*!< RNG_SR: ERRI Mask                       */
#define RNG_SR_ERRI_SHIFT                        3                                                   /*!< RNG_SR: ERRI Position                   */
#define RNG_SR_SLP_MASK                          (0x01UL << RNG_SR_SLP_SHIFT)                        /*!< RNG_SR: SLP Mask                        */
#define RNG_SR_SLP_SHIFT                         4                                                   /*!< RNG_SR: SLP Position                    */
#define RNG_SR_OREG_LVL_MASK                     (0xFFUL << RNG_SR_OREG_LVL_SHIFT)                   /*!< RNG_SR: OREG_LVL Mask                   */
#define RNG_SR_OREG_LVL_SHIFT                    8                                                   /*!< RNG_SR: OREG_LVL Position               */
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_LVL_SHIFT))&RNG_SR_OREG_LVL_MASK) /*!< RNG_SR                                  */
#define RNG_SR_OREG_SIZE_MASK                    (0xFFUL << RNG_SR_OREG_SIZE_SHIFT)                  /*!< RNG_SR: OREG_SIZE Mask                  */
#define RNG_SR_OREG_SIZE_SHIFT                   16                                                  /*!< RNG_SR: OREG_SIZE Position              */
#define RNG_SR_OREG_SIZE(x)                      (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_SIZE_SHIFT))&RNG_SR_OREG_SIZE_MASK) /*!< RNG_SR                                  */
/* ------- ER Bit Fields                            ------ */
#define RNG_ER_EXT_ENT_MASK                      (0xFFFFFFFFUL << RNG_ER_EXT_ENT_SHIFT)              /*!< RNG_ER: EXT_ENT Mask                    */
#define RNG_ER_EXT_ENT_SHIFT                     0                                                   /*!< RNG_ER: EXT_ENT Position                */
#define RNG_ER_EXT_ENT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_ER_EXT_ENT_SHIFT))&RNG_ER_EXT_ENT_MASK) /*!< RNG_ER                                  */
/* ------- OR Bit Fields                            ------ */
#define RNG_OR_RANDOUT_MASK                      (0xFFFFFFFFUL << RNG_OR_RANDOUT_SHIFT)              /*!< RNG_OR: RANDOUT Mask                    */
#define RNG_OR_RANDOUT_SHIFT                     0                                                   /*!< RNG_OR: RANDOUT Position                */
#define RNG_OR_RANDOUT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_OR_RANDOUT_SHIFT))&RNG_OR_RANDOUT_MASK) /*!< RNG_OR                                  */
/**
 * @} */ /* End group RNG_Register_Masks_GROUP 
 */

/* RNG - Peripheral instance base addresses */
#define RNG_BasePtr                    0x40029000UL //!< Peripheral base address
#define RNG                            ((RNG_Type *) RNG_BasePtr) //!< Freescale base pointer
#define RNG_BASE_PTR                   (RNG) //!< Freescale style base pointer
/**
 * @} */ /* End group RNG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ROM_Peripheral_access_layer_GROUP ROM Peripheral Access Layer
* @brief C Struct for ROM
* @{
*/

/* ================================================================================ */
/* ================           ROM (file:ROM_MKL)                   ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
/**
* @addtogroup ROM_structs_GROUP ROM struct
* @brief Struct for ROM
* @{
*/
typedef struct {                                /*       ROM Structure                                                */
   __I  uint32_t  ENTRY[3];                     /**< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /**< 000C: End of Table Marker Register                                 */
   __I  uint32_t  RESERVED0[1007];             
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

/**
 * @} */ /* End group ROM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ROM_Register_Masks_GROUP ROM Register Masks
* @brief Register Masks for ROM
* @{
*/
/* ------- ENTRY Bit Fields                         ------ */
#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFUL << ROM_ENTRY_ENTRY_SHIFT)             /*!< ROM_ENTRY: ENTRY Mask                   */
#define ROM_ENTRY_ENTRY_SHIFT                    0                                                   /*!< ROM_ENTRY: ENTRY Position               */
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<ROM_ENTRY_ENTRY_SHIFT))&ROM_ENTRY_ENTRY_MASK) /*!< ROM_ENTRY                               */
/* ------- TABLEMARK Bit Fields                     ------ */
#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFUL << ROM_TABLEMARK_MARK_SHIFT)          /*!< ROM_TABLEMARK: MARK Mask                */
#define ROM_TABLEMARK_MARK_SHIFT                 0                                                   /*!< ROM_TABLEMARK: MARK Position            */
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<ROM_TABLEMARK_MARK_SHIFT))&ROM_TABLEMARK_MARK_MASK) /*!< ROM_TABLEMARK                           */
/* ------- SYSACCESS Bit Fields                     ------ */
#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFUL << ROM_SYSACCESS_SYSACCESS_SHIFT)     /*!< ROM_SYSACCESS: SYSACCESS Mask           */
#define ROM_SYSACCESS_SYSACCESS_SHIFT            0                                                   /*!< ROM_SYSACCESS: SYSACCESS Position       */
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<ROM_SYSACCESS_SYSACCESS_SHIFT))&ROM_SYSACCESS_SYSACCESS_MASK) /*!< ROM_SYSACCESS                           */
/* ------- PERIPHID Bit Fields                      ------ */
#define ROM_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFUL << ROM_PERIPHID_PERIPHID_SHIFT)       /*!< ROM_PERIPHID: PERIPHID Mask             */
#define ROM_PERIPHID_PERIPHID_SHIFT              0                                                   /*!< ROM_PERIPHID: PERIPHID Position         */
#define ROM_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID_PERIPHID_SHIFT))&ROM_PERIPHID_PERIPHID_MASK) /*!< ROM_PERIPHID                            */
/* ------- COMPID Bit Fields                        ------ */
#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFUL << ROM_COMPID_COMPID_SHIFT)           /*!< ROM_COMPID: COMPID Mask                 */
#define ROM_COMPID_COMPID_SHIFT                  0                                                   /*!< ROM_COMPID: COMPID Position             */
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<ROM_COMPID_COMPID_SHIFT))&ROM_COMPID_COMPID_MASK) /*!< ROM_COMPID                              */
/**
 * @} */ /* End group ROM_Register_Masks_GROUP 
 */

/* ROM - Peripheral instance base addresses */
#define ROM_BasePtr                    0xF0002000UL //!< Peripheral base address
#define ROM                            ((ROM_Type *) ROM_BasePtr) //!< Freescale base pointer
#define ROM_BASE_PTR                   (ROM) //!< Freescale style base pointer
/**
 * @} */ /* End group ROM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_MKM14ZA5)              ================ */
/* ================================================================================ */

/**
 * @brief Real Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint16_t  YEARMON;                      /**< 0000: Year and Month Counters Register                             */
   __IO uint16_t  DAYS;                         /**< 0002: Days and Day-of-Week Counters Register                       */
   __IO uint16_t  HOURMIN;                      /**< 0004: Hours and Minutes Counters Register                          */
   __IO uint16_t  SECONDS;                      /**< 0006: Seconds Counters Register                                    */
   __IO uint16_t  ALM_YEARMON;                  /**< 0008: Year and Months Alarm Register                               */
   __IO uint16_t  ALM_DAYS;                     /**< 000A: Days Alarm Register                                          */
   __IO uint16_t  ALM_HOURMIN;                  /**< 000C: Hours and Minutes Alarm Register                             */
   __IO uint16_t  ALM_SECONDS;                  /**< 000E: Seconds Alarm Register                                       */
   __IO uint16_t  CTRL;                         /**< 0010: Control Register                                             */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  STATUS;                    /**< 0012: Status Register                                              */
      __IO uint8_t   STATUS_B;                  /**< 0012: Status Register LSB                                          */
   };
   __I  uint16_t  ISR;                          /**< 0014: Interrupt Status Register                                    */
   __IO uint16_t  IER;                          /**< 0016: Interrupt Enable Register                                    */
   __I  uint32_t  RESERVED0[2];                
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  GP_DATA_REG;               /**< 0020: General Purpose Data Register                                */
      __IO uint16_t  OSC;                       /**< 0020: RTC Control Register                                         */
   };
   __IO uint16_t  DST_HOUR;                     /**< 0022: Daylight Saving Hour Register                                */
   __IO uint16_t  DST_MONTH;                    /**< 0024: Daylight Saving Month Register                               */
   __IO uint16_t  DST_DAY;                      /**< 0026: Daylight Saving Day Register                                 */
   __IO uint16_t  COMPEN;                       /**< 0028: Compensation Register                                        */
   __I  uint16_t  RESERVED1;                   
   __IO uint16_t  TAMPER_DIRECTION;             /**< 002C: Tamper Direction Register                                    */
   __IO uint16_t  TAMPER_QSCR;                  /**< 002E: Tamper Queue Status and Control Register                     */
   __I  uint16_t  RESERVED2;                   
   __IO uint16_t  TAMPER_SCR;                   /**< 0032: Tamper Status and Control Register                           */
   __IO uint16_t  FILTER01_CFG;                 /**< 0034: Tamper 01 Filter Configuration Register                      */
   __IO uint16_t  FILTER2_CFG;                  /**< 0036: Tamper 2 Filter Configuration Register                       */
   __I  uint32_t  RESERVED3[2];                
   __I  uint16_t  TAMPER_QUEUE;                 /**< 0040: Tamper Queue Register                                        */
   __IO uint16_t  CTRL2;                        /**< 0042: Control 2 Register                                           */
} RTC_Type;

/**
 * @} */ /* End group RTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RTC_Register_Masks_GROUP RTC Register Masks
* @brief Register Masks for RTC
* @{
*/
/* ------- YEARMON Bit Fields                       ------ */
#define RTC_YEARMON_MON_CNT_MASK                 (0x0FUL << RTC_YEARMON_MON_CNT_SHIFT)               /*!< RTC_YEARMON: MON_CNT Mask               */
#define RTC_YEARMON_MON_CNT_SHIFT                0                                                   /*!< RTC_YEARMON: MON_CNT Position           */
#define RTC_YEARMON_MON_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_YEARMON_MON_CNT_SHIFT))&RTC_YEARMON_MON_CNT_MASK) /*!< RTC_YEARMON                             */
#define RTC_YEARMON_YROFST_MASK                  (0xFFUL << RTC_YEARMON_YROFST_SHIFT)                /*!< RTC_YEARMON: YROFST Mask                */
#define RTC_YEARMON_YROFST_SHIFT                 8                                                   /*!< RTC_YEARMON: YROFST Position            */
#define RTC_YEARMON_YROFST(x)                    (((uint16_t)(((uint16_t)(x))<<RTC_YEARMON_YROFST_SHIFT))&RTC_YEARMON_YROFST_MASK) /*!< RTC_YEARMON                             */
/* ------- DAYS Bit Fields                          ------ */
#define RTC_DAYS_DAY_CNT_MASK                    (0x1FUL << RTC_DAYS_DAY_CNT_SHIFT)                  /*!< RTC_DAYS: DAY_CNT Mask                  */
#define RTC_DAYS_DAY_CNT_SHIFT                   0                                                   /*!< RTC_DAYS: DAY_CNT Position              */
#define RTC_DAYS_DAY_CNT(x)                      (((uint16_t)(((uint16_t)(x))<<RTC_DAYS_DAY_CNT_SHIFT))&RTC_DAYS_DAY_CNT_MASK) /*!< RTC_DAYS                                */
#define RTC_DAYS_DOW_MASK                        (0x07UL << RTC_DAYS_DOW_SHIFT)                      /*!< RTC_DAYS: DOW Mask                      */
#define RTC_DAYS_DOW_SHIFT                       8                                                   /*!< RTC_DAYS: DOW Position                  */
#define RTC_DAYS_DOW(x)                          (((uint16_t)(((uint16_t)(x))<<RTC_DAYS_DOW_SHIFT))&RTC_DAYS_DOW_MASK) /*!< RTC_DAYS                                */
/* ------- HOURMIN Bit Fields                       ------ */
#define RTC_HOURMIN_MIN_CNT_MASK                 (0x3FUL << RTC_HOURMIN_MIN_CNT_SHIFT)               /*!< RTC_HOURMIN: MIN_CNT Mask               */
#define RTC_HOURMIN_MIN_CNT_SHIFT                0                                                   /*!< RTC_HOURMIN: MIN_CNT Position           */
#define RTC_HOURMIN_MIN_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_HOURMIN_MIN_CNT_SHIFT))&RTC_HOURMIN_MIN_CNT_MASK) /*!< RTC_HOURMIN                             */
#define RTC_HOURMIN_HOUR_CNT_MASK                (0x1FUL << RTC_HOURMIN_HOUR_CNT_SHIFT)              /*!< RTC_HOURMIN: HOUR_CNT Mask              */
#define RTC_HOURMIN_HOUR_CNT_SHIFT               8                                                   /*!< RTC_HOURMIN: HOUR_CNT Position          */
#define RTC_HOURMIN_HOUR_CNT(x)                  (((uint16_t)(((uint16_t)(x))<<RTC_HOURMIN_HOUR_CNT_SHIFT))&RTC_HOURMIN_HOUR_CNT_MASK) /*!< RTC_HOURMIN                             */
/* ------- SECONDS Bit Fields                       ------ */
#define RTC_SECONDS_SEC_CNT_MASK                 (0x3FUL << RTC_SECONDS_SEC_CNT_SHIFT)               /*!< RTC_SECONDS: SEC_CNT Mask               */
#define RTC_SECONDS_SEC_CNT_SHIFT                0                                                   /*!< RTC_SECONDS: SEC_CNT Position           */
#define RTC_SECONDS_SEC_CNT(x)                   (((uint16_t)(((uint16_t)(x))<<RTC_SECONDS_SEC_CNT_SHIFT))&RTC_SECONDS_SEC_CNT_MASK) /*!< RTC_SECONDS                             */
/* ------- ALM_YEARMON Bit Fields                   ------ */
#define RTC_ALM_YEARMON_ALM_MON_MASK             (0x0FUL << RTC_ALM_YEARMON_ALM_MON_SHIFT)           /*!< RTC_ALM_YEARMON: ALM_MON Mask           */
#define RTC_ALM_YEARMON_ALM_MON_SHIFT            0                                                   /*!< RTC_ALM_YEARMON: ALM_MON Position       */
#define RTC_ALM_YEARMON_ALM_MON(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_YEARMON_ALM_MON_SHIFT))&RTC_ALM_YEARMON_ALM_MON_MASK) /*!< RTC_ALM_YEARMON                         */
#define RTC_ALM_YEARMON_ALM_YEAR_MASK            (0xFFUL << RTC_ALM_YEARMON_ALM_YEAR_SHIFT)          /*!< RTC_ALM_YEARMON: ALM_YEAR Mask          */
#define RTC_ALM_YEARMON_ALM_YEAR_SHIFT           8                                                   /*!< RTC_ALM_YEARMON: ALM_YEAR Position      */
#define RTC_ALM_YEARMON_ALM_YEAR(x)              (((uint16_t)(((uint16_t)(x))<<RTC_ALM_YEARMON_ALM_YEAR_SHIFT))&RTC_ALM_YEARMON_ALM_YEAR_MASK) /*!< RTC_ALM_YEARMON                         */
/* ------- ALM_DAYS Bit Fields                      ------ */
#define RTC_ALM_DAYS_ALM_DAY_MASK                (0x1FUL << RTC_ALM_DAYS_ALM_DAY_SHIFT)              /*!< RTC_ALM_DAYS: ALM_DAY Mask              */
#define RTC_ALM_DAYS_ALM_DAY_SHIFT               0                                                   /*!< RTC_ALM_DAYS: ALM_DAY Position          */
#define RTC_ALM_DAYS_ALM_DAY(x)                  (((uint16_t)(((uint16_t)(x))<<RTC_ALM_DAYS_ALM_DAY_SHIFT))&RTC_ALM_DAYS_ALM_DAY_MASK) /*!< RTC_ALM_DAYS                            */
/* ------- ALM_HOURMIN Bit Fields                   ------ */
#define RTC_ALM_HOURMIN_ALM_MIN_MASK             (0x3FUL << RTC_ALM_HOURMIN_ALM_MIN_SHIFT)           /*!< RTC_ALM_HOURMIN: ALM_MIN Mask           */
#define RTC_ALM_HOURMIN_ALM_MIN_SHIFT            0                                                   /*!< RTC_ALM_HOURMIN: ALM_MIN Position       */
#define RTC_ALM_HOURMIN_ALM_MIN(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_HOURMIN_ALM_MIN_SHIFT))&RTC_ALM_HOURMIN_ALM_MIN_MASK) /*!< RTC_ALM_HOURMIN                         */
#define RTC_ALM_HOURMIN_ALM_HOUR_MASK            (0x1FUL << RTC_ALM_HOURMIN_ALM_HOUR_SHIFT)          /*!< RTC_ALM_HOURMIN: ALM_HOUR Mask          */
#define RTC_ALM_HOURMIN_ALM_HOUR_SHIFT           8                                                   /*!< RTC_ALM_HOURMIN: ALM_HOUR Position      */
#define RTC_ALM_HOURMIN_ALM_HOUR(x)              (((uint16_t)(((uint16_t)(x))<<RTC_ALM_HOURMIN_ALM_HOUR_SHIFT))&RTC_ALM_HOURMIN_ALM_HOUR_MASK) /*!< RTC_ALM_HOURMIN                         */
/* ------- ALM_SECONDS Bit Fields                   ------ */
#define RTC_ALM_SECONDS_ALM_SEC_MASK             (0x3FUL << RTC_ALM_SECONDS_ALM_SEC_SHIFT)           /*!< RTC_ALM_SECONDS: ALM_SEC Mask           */
#define RTC_ALM_SECONDS_ALM_SEC_SHIFT            0                                                   /*!< RTC_ALM_SECONDS: ALM_SEC Position       */
#define RTC_ALM_SECONDS_ALM_SEC(x)               (((uint16_t)(((uint16_t)(x))<<RTC_ALM_SECONDS_ALM_SEC_SHIFT))&RTC_ALM_SECONDS_ALM_SEC_MASK) /*!< RTC_ALM_SECONDS                         */
/* ------- CTRL Bit Fields                          ------ */
#define RTC_CTRL_FINEEN_MASK                     (0x01UL << RTC_CTRL_FINEEN_SHIFT)                   /*!< RTC_CTRL: FINEEN Mask                   */
#define RTC_CTRL_FINEEN_SHIFT                    0                                                   /*!< RTC_CTRL: FINEEN Position               */
#define RTC_CTRL_COMP_EN_MASK                    (0x01UL << RTC_CTRL_COMP_EN_SHIFT)                  /*!< RTC_CTRL: COMP_EN Mask                  */
#define RTC_CTRL_COMP_EN_SHIFT                   1                                                   /*!< RTC_CTRL: COMP_EN Position              */
#define RTC_CTRL_ALM_MATCH_MASK                  (0x03UL << RTC_CTRL_ALM_MATCH_SHIFT)                /*!< RTC_CTRL: ALM_MATCH Mask                */
#define RTC_CTRL_ALM_MATCH_SHIFT                 2                                                   /*!< RTC_CTRL: ALM_MATCH Position            */
#define RTC_CTRL_ALM_MATCH(x)                    (((uint16_t)(((uint16_t)(x))<<RTC_CTRL_ALM_MATCH_SHIFT))&RTC_CTRL_ALM_MATCH_MASK) /*!< RTC_CTRL                                */
#define RTC_CTRL_TIMER_STB_MASK_MASK             (0x01UL << RTC_CTRL_TIMER_STB_MASK_SHIFT)           /*!< RTC_CTRL: TIMER_STB_MASK Mask           */
#define RTC_CTRL_TIMER_STB_MASK_SHIFT            4                                                   /*!< RTC_CTRL: TIMER_STB_MASK Position       */
#define RTC_CTRL_DST_EN_MASK                     (0x01UL << RTC_CTRL_DST_EN_SHIFT)                   /*!< RTC_CTRL: DST_EN Mask                   */
#define RTC_CTRL_DST_EN_SHIFT                    6                                                   /*!< RTC_CTRL: DST_EN Position               */
#define RTC_CTRL_SWR_MASK                        (0x01UL << RTC_CTRL_SWR_SHIFT)                      /*!< RTC_CTRL: SWR Mask                      */
#define RTC_CTRL_SWR_SHIFT                       8                                                   /*!< RTC_CTRL: SWR Position                  */
#define RTC_CTRL_CLKOUT_MASK                     (0x03UL << RTC_CTRL_CLKOUT_SHIFT)                   /*!< RTC_CTRL: CLKOUT Mask                   */
#define RTC_CTRL_CLKOUT_SHIFT                    13                                                  /*!< RTC_CTRL: CLKOUT Position               */
#define RTC_CTRL_CLKOUT(x)                       (((uint16_t)(((uint16_t)(x))<<RTC_CTRL_CLKOUT_SHIFT))&RTC_CTRL_CLKOUT_MASK) /*!< RTC_CTRL                                */
/* ------- STATUS Bit Fields                        ------ */
#define RTC_STATUS_INVAL_BIT_MASK                (0x01UL << RTC_STATUS_INVAL_BIT_SHIFT)              /*!< RTC_STATUS: INVAL_BIT Mask              */
#define RTC_STATUS_INVAL_BIT_SHIFT               0                                                   /*!< RTC_STATUS: INVAL_BIT Position          */
#define RTC_STATUS_WRITE_PROT_EN_MASK            (0x01UL << RTC_STATUS_WRITE_PROT_EN_SHIFT)          /*!< RTC_STATUS: WRITE_PROT_EN Mask          */
#define RTC_STATUS_WRITE_PROT_EN_SHIFT           1                                                   /*!< RTC_STATUS: WRITE_PROT_EN Position      */
#define RTC_STATUS_CPU_LOW_VOLT_MASK             (0x01UL << RTC_STATUS_CPU_LOW_VOLT_SHIFT)           /*!< RTC_STATUS: CPU_LOW_VOLT Mask           */
#define RTC_STATUS_CPU_LOW_VOLT_SHIFT            2                                                   /*!< RTC_STATUS: CPU_LOW_VOLT Position       */
#define RTC_STATUS_RST_SRC_MASK                  (0x01UL << RTC_STATUS_RST_SRC_SHIFT)                /*!< RTC_STATUS: RST_SRC Mask                */
#define RTC_STATUS_RST_SRC_SHIFT                 3                                                   /*!< RTC_STATUS: RST_SRC Position            */
#define RTC_STATUS_CMP_INT_MASK                  (0x01UL << RTC_STATUS_CMP_INT_SHIFT)                /*!< RTC_STATUS: CMP_INT Mask                */
#define RTC_STATUS_CMP_INT_SHIFT                 5                                                   /*!< RTC_STATUS: CMP_INT Position            */
#define RTC_STATUS_WE_MASK                       (0x03UL << RTC_STATUS_WE_SHIFT)                     /*!< RTC_STATUS: WE Mask                     */
#define RTC_STATUS_WE_SHIFT                      6                                                   /*!< RTC_STATUS: WE Position                 */
#define RTC_STATUS_WE(x)                         (((uint16_t)(((uint16_t)(x))<<RTC_STATUS_WE_SHIFT))&RTC_STATUS_WE_MASK) /*!< RTC_STATUS                              */
#define RTC_STATUS_BUS_ERR_MASK                  (0x01UL << RTC_STATUS_BUS_ERR_SHIFT)                /*!< RTC_STATUS: BUS_ERR Mask                */
#define RTC_STATUS_BUS_ERR_SHIFT                 8                                                   /*!< RTC_STATUS: BUS_ERR Position            */
#define RTC_STATUS_CMP_DONE_MASK                 (0x01UL << RTC_STATUS_CMP_DONE_SHIFT)               /*!< RTC_STATUS: CMP_DONE Mask               */
#define RTC_STATUS_CMP_DONE_SHIFT                11                                                  /*!< RTC_STATUS: CMP_DONE Position           */
/* ------- STATUS_B Bit Fields                      ------ */
/* ------- ISR Bit Fields                           ------ */
#define RTC_ISR_TAMPER_IS_MASK                   (0x01UL << RTC_ISR_TAMPER_IS_SHIFT)                 /*!< RTC_ISR: TAMPER_IS Mask                 */
#define RTC_ISR_TAMPER_IS_SHIFT                  0                                                   /*!< RTC_ISR: TAMPER_IS Position             */
#define RTC_ISR_ALM_IS_MASK                      (0x01UL << RTC_ISR_ALM_IS_SHIFT)                    /*!< RTC_ISR: ALM_IS Mask                    */
#define RTC_ISR_ALM_IS_SHIFT                     2                                                   /*!< RTC_ISR: ALM_IS Position                */
#define RTC_ISR_DAY_IS_MASK                      (0x01UL << RTC_ISR_DAY_IS_SHIFT)                    /*!< RTC_ISR: DAY_IS Mask                    */
#define RTC_ISR_DAY_IS_SHIFT                     3                                                   /*!< RTC_ISR: DAY_IS Position                */
#define RTC_ISR_HOUR_IS_MASK                     (0x01UL << RTC_ISR_HOUR_IS_SHIFT)                   /*!< RTC_ISR: HOUR_IS Mask                   */
#define RTC_ISR_HOUR_IS_SHIFT                    4                                                   /*!< RTC_ISR: HOUR_IS Position               */
#define RTC_ISR_MIN_IS_MASK                      (0x01UL << RTC_ISR_MIN_IS_SHIFT)                    /*!< RTC_ISR: MIN_IS Mask                    */
#define RTC_ISR_MIN_IS_SHIFT                     5                                                   /*!< RTC_ISR: MIN_IS Position                */
#define RTC_ISR_IS_1HZ_MASK                      (0x01UL << RTC_ISR_IS_1HZ_SHIFT)                    /*!< RTC_ISR: IS_1HZ Mask                    */
#define RTC_ISR_IS_1HZ_SHIFT                     6                                                   /*!< RTC_ISR: IS_1HZ Position                */
#define RTC_ISR_IS_2HZ_MASK                      (0x01UL << RTC_ISR_IS_2HZ_SHIFT)                    /*!< RTC_ISR: IS_2HZ Mask                    */
#define RTC_ISR_IS_2HZ_SHIFT                     7                                                   /*!< RTC_ISR: IS_2HZ Position                */
#define RTC_ISR_IS_4HZ_MASK                      (0x01UL << RTC_ISR_IS_4HZ_SHIFT)                    /*!< RTC_ISR: IS_4HZ Mask                    */
#define RTC_ISR_IS_4HZ_SHIFT                     8                                                   /*!< RTC_ISR: IS_4HZ Position                */
#define RTC_ISR_IS_8HZ_MASK                      (0x01UL << RTC_ISR_IS_8HZ_SHIFT)                    /*!< RTC_ISR: IS_8HZ Mask                    */
#define RTC_ISR_IS_8HZ_SHIFT                     9                                                   /*!< RTC_ISR: IS_8HZ Position                */
#define RTC_ISR_IS_16HZ_MASK                     (0x01UL << RTC_ISR_IS_16HZ_SHIFT)                   /*!< RTC_ISR: IS_16HZ Mask                   */
#define RTC_ISR_IS_16HZ_SHIFT                    10                                                  /*!< RTC_ISR: IS_16HZ Position               */
#define RTC_ISR_IS_32HZ_MASK                     (0x01UL << RTC_ISR_IS_32HZ_SHIFT)                   /*!< RTC_ISR: IS_32HZ Mask                   */
#define RTC_ISR_IS_32HZ_SHIFT                    11                                                  /*!< RTC_ISR: IS_32HZ Position               */
#define RTC_ISR_IS_64HZ_MASK                     (0x01UL << RTC_ISR_IS_64HZ_SHIFT)                   /*!< RTC_ISR: IS_64HZ Mask                   */
#define RTC_ISR_IS_64HZ_SHIFT                    12                                                  /*!< RTC_ISR: IS_64HZ Position               */
#define RTC_ISR_IS_128HZ_MASK                    (0x01UL << RTC_ISR_IS_128HZ_SHIFT)                  /*!< RTC_ISR: IS_128HZ Mask                  */
#define RTC_ISR_IS_128HZ_SHIFT                   13                                                  /*!< RTC_ISR: IS_128HZ Position              */
#define RTC_ISR_IS_256HZ_MASK                    (0x01UL << RTC_ISR_IS_256HZ_SHIFT)                  /*!< RTC_ISR: IS_256HZ Mask                  */
#define RTC_ISR_IS_256HZ_SHIFT                   14                                                  /*!< RTC_ISR: IS_256HZ Position              */
#define RTC_ISR_IS_512HZ_MASK                    (0x01UL << RTC_ISR_IS_512HZ_SHIFT)                  /*!< RTC_ISR: IS_512HZ Mask                  */
#define RTC_ISR_IS_512HZ_SHIFT                   15                                                  /*!< RTC_ISR: IS_512HZ Position              */
/* ------- IER Bit Fields                           ------ */
#define RTC_IER_TAMPER_IE_MASK                   (0x01UL << RTC_IER_TAMPER_IE_SHIFT)                 /*!< RTC_IER: TAMPER_IE Mask                 */
#define RTC_IER_TAMPER_IE_SHIFT                  0                                                   /*!< RTC_IER: TAMPER_IE Position             */
#define RTC_IER_ALM_IE_MASK                      (0x01UL << RTC_IER_ALM_IE_SHIFT)                    /*!< RTC_IER: ALM_IE Mask                    */
#define RTC_IER_ALM_IE_SHIFT                     2                                                   /*!< RTC_IER: ALM_IE Position                */
#define RTC_IER_DAY_IE_MASK                      (0x01UL << RTC_IER_DAY_IE_SHIFT)                    /*!< RTC_IER: DAY_IE Mask                    */
#define RTC_IER_DAY_IE_SHIFT                     3                                                   /*!< RTC_IER: DAY_IE Position                */
#define RTC_IER_HOUR_IE_MASK                     (0x01UL << RTC_IER_HOUR_IE_SHIFT)                   /*!< RTC_IER: HOUR_IE Mask                   */
#define RTC_IER_HOUR_IE_SHIFT                    4                                                   /*!< RTC_IER: HOUR_IE Position               */
#define RTC_IER_MIN_IE_MASK                      (0x01UL << RTC_IER_MIN_IE_SHIFT)                    /*!< RTC_IER: MIN_IE Mask                    */
#define RTC_IER_MIN_IE_SHIFT                     5                                                   /*!< RTC_IER: MIN_IE Position                */
#define RTC_IER_IE_1HZ_MASK                      (0x01UL << RTC_IER_IE_1HZ_SHIFT)                    /*!< RTC_IER: IE_1HZ Mask                    */
#define RTC_IER_IE_1HZ_SHIFT                     6                                                   /*!< RTC_IER: IE_1HZ Position                */
#define RTC_IER_IE_2HZ_MASK                      (0x01UL << RTC_IER_IE_2HZ_SHIFT)                    /*!< RTC_IER: IE_2HZ Mask                    */
#define RTC_IER_IE_2HZ_SHIFT                     7                                                   /*!< RTC_IER: IE_2HZ Position                */
#define RTC_IER_IE_4HZ_MASK                      (0x01UL << RTC_IER_IE_4HZ_SHIFT)                    /*!< RTC_IER: IE_4HZ Mask                    */
#define RTC_IER_IE_4HZ_SHIFT                     8                                                   /*!< RTC_IER: IE_4HZ Position                */
#define RTC_IER_IE_8HZ_MASK                      (0x01UL << RTC_IER_IE_8HZ_SHIFT)                    /*!< RTC_IER: IE_8HZ Mask                    */
#define RTC_IER_IE_8HZ_SHIFT                     9                                                   /*!< RTC_IER: IE_8HZ Position                */
#define RTC_IER_IE_16HZ_MASK                     (0x01UL << RTC_IER_IE_16HZ_SHIFT)                   /*!< RTC_IER: IE_16HZ Mask                   */
#define RTC_IER_IE_16HZ_SHIFT                    10                                                  /*!< RTC_IER: IE_16HZ Position               */
#define RTC_IER_IE_32HZ_MASK                     (0x01UL << RTC_IER_IE_32HZ_SHIFT)                   /*!< RTC_IER: IE_32HZ Mask                   */
#define RTC_IER_IE_32HZ_SHIFT                    11                                                  /*!< RTC_IER: IE_32HZ Position               */
#define RTC_IER_IE_64HZ_MASK                     (0x01UL << RTC_IER_IE_64HZ_SHIFT)                   /*!< RTC_IER: IE_64HZ Mask                   */
#define RTC_IER_IE_64HZ_SHIFT                    12                                                  /*!< RTC_IER: IE_64HZ Position               */
#define RTC_IER_IE_128HZ_MASK                    (0x01UL << RTC_IER_IE_128HZ_SHIFT)                  /*!< RTC_IER: IE_128HZ Mask                  */
#define RTC_IER_IE_128HZ_SHIFT                   13                                                  /*!< RTC_IER: IE_128HZ Position              */
#define RTC_IER_IE_256HZ_MASK                    (0x01UL << RTC_IER_IE_256HZ_SHIFT)                  /*!< RTC_IER: IE_256HZ Mask                  */
#define RTC_IER_IE_256HZ_SHIFT                   14                                                  /*!< RTC_IER: IE_256HZ Position              */
#define RTC_IER_IE_512HZ_MASK                    (0x01UL << RTC_IER_IE_512HZ_SHIFT)                  /*!< RTC_IER: IE_512HZ Mask                  */
#define RTC_IER_IE_512HZ_SHIFT                   15                                                  /*!< RTC_IER: IE_512HZ Position              */
/* ------- GP_DATA_REG Bit Fields                   ------ */
/* ------- OSC Bit Fields                           ------ */
#define RTC_OSC_OSC_DISABLE_MASK                 (0x01UL << RTC_OSC_OSC_DISABLE_SHIFT)               /*!< RTC_OSC: OSC_DISABLE Mask               */
#define RTC_OSC_OSC_DISABLE_SHIFT                0                                                   /*!< RTC_OSC: OSC_DISABLE Position           */
#define RTC_OSC_SC2P_MASK                        (0x01UL << RTC_OSC_SC2P_SHIFT)                      /*!< RTC_OSC: SC2P Mask                      */
#define RTC_OSC_SC2P_SHIFT                       1                                                   /*!< RTC_OSC: SC2P Position                  */
#define RTC_OSC_SC4P_MASK                        (0x01UL << RTC_OSC_SC4P_SHIFT)                      /*!< RTC_OSC: SC4P Mask                      */
#define RTC_OSC_SC4P_SHIFT                       2                                                   /*!< RTC_OSC: SC4P Position                  */
#define RTC_OSC_SC8P_MASK                        (0x01UL << RTC_OSC_SC8P_SHIFT)                      /*!< RTC_OSC: SC8P Mask                      */
#define RTC_OSC_SC8P_SHIFT                       3                                                   /*!< RTC_OSC: SC8P Position                  */
#define RTC_OSC_SC16P_MASK                       (0x01UL << RTC_OSC_SC16P_SHIFT)                     /*!< RTC_OSC: SC16P Mask                     */
#define RTC_OSC_SC16P_SHIFT                      4                                                   /*!< RTC_OSC: SC16P Position                 */
#define RTC_OSC_BOOT_MODE_MASK                   (0x01UL << RTC_OSC_BOOT_MODE_SHIFT)                 /*!< RTC_OSC: BOOT_MODE Mask                 */
#define RTC_OSC_BOOT_MODE_SHIFT                  7                                                   /*!< RTC_OSC: BOOT_MODE Position             */
/* ------- DST_HOUR Bit Fields                      ------ */
#define RTC_DST_HOUR_DST_END_HOUR_MASK           (0x1FUL << RTC_DST_HOUR_DST_END_HOUR_SHIFT)         /*!< RTC_DST_HOUR: DST_END_HOUR Mask         */
#define RTC_DST_HOUR_DST_END_HOUR_SHIFT          0                                                   /*!< RTC_DST_HOUR: DST_END_HOUR Position     */
#define RTC_DST_HOUR_DST_END_HOUR(x)             (((uint16_t)(((uint16_t)(x))<<RTC_DST_HOUR_DST_END_HOUR_SHIFT))&RTC_DST_HOUR_DST_END_HOUR_MASK) /*!< RTC_DST_HOUR                            */
#define RTC_DST_HOUR_DST_START_HOUR_MASK         (0x1FUL << RTC_DST_HOUR_DST_START_HOUR_SHIFT)       /*!< RTC_DST_HOUR: DST_START_HOUR Mask       */
#define RTC_DST_HOUR_DST_START_HOUR_SHIFT        8                                                   /*!< RTC_DST_HOUR: DST_START_HOUR Position   */
#define RTC_DST_HOUR_DST_START_HOUR(x)           (((uint16_t)(((uint16_t)(x))<<RTC_DST_HOUR_DST_START_HOUR_SHIFT))&RTC_DST_HOUR_DST_START_HOUR_MASK) /*!< RTC_DST_HOUR                            */
/* ------- DST_MONTH Bit Fields                     ------ */
#define RTC_DST_MONTH_DST_END_MONTH_MASK         (0x0FUL << RTC_DST_MONTH_DST_END_MONTH_SHIFT)       /*!< RTC_DST_MONTH: DST_END_MONTH Mask       */
#define RTC_DST_MONTH_DST_END_MONTH_SHIFT        0                                                   /*!< RTC_DST_MONTH: DST_END_MONTH Position   */
#define RTC_DST_MONTH_DST_END_MONTH(x)           (((uint16_t)(((uint16_t)(x))<<RTC_DST_MONTH_DST_END_MONTH_SHIFT))&RTC_DST_MONTH_DST_END_MONTH_MASK) /*!< RTC_DST_MONTH                           */
#define RTC_DST_MONTH_DST_START_MONTH_MASK       (0x0FUL << RTC_DST_MONTH_DST_START_MONTH_SHIFT)     /*!< RTC_DST_MONTH: DST_START_MONTH Mask     */
#define RTC_DST_MONTH_DST_START_MONTH_SHIFT      8                                                   /*!< RTC_DST_MONTH: DST_START_MONTH Position */
#define RTC_DST_MONTH_DST_START_MONTH(x)         (((uint16_t)(((uint16_t)(x))<<RTC_DST_MONTH_DST_START_MONTH_SHIFT))&RTC_DST_MONTH_DST_START_MONTH_MASK) /*!< RTC_DST_MONTH                           */
/* ------- DST_DAY Bit Fields                       ------ */
#define RTC_DST_DAY_DST_END_DAY_MASK             (0x1FUL << RTC_DST_DAY_DST_END_DAY_SHIFT)           /*!< RTC_DST_DAY: DST_END_DAY Mask           */
#define RTC_DST_DAY_DST_END_DAY_SHIFT            0                                                   /*!< RTC_DST_DAY: DST_END_DAY Position       */
#define RTC_DST_DAY_DST_END_DAY(x)               (((uint16_t)(((uint16_t)(x))<<RTC_DST_DAY_DST_END_DAY_SHIFT))&RTC_DST_DAY_DST_END_DAY_MASK) /*!< RTC_DST_DAY                             */
#define RTC_DST_DAY_DST_START_DAY_MASK           (0x1FUL << RTC_DST_DAY_DST_START_DAY_SHIFT)         /*!< RTC_DST_DAY: DST_START_DAY Mask         */
#define RTC_DST_DAY_DST_START_DAY_SHIFT          8                                                   /*!< RTC_DST_DAY: DST_START_DAY Position     */
#define RTC_DST_DAY_DST_START_DAY(x)             (((uint16_t)(((uint16_t)(x))<<RTC_DST_DAY_DST_START_DAY_SHIFT))&RTC_DST_DAY_DST_START_DAY_MASK) /*!< RTC_DST_DAY                             */
/* ------- COMPEN Bit Fields                        ------ */
/* ------- TAMPER_DIRECTION Bit Fields              ------ */
#define RTC_TAMPER_DIRECTION_A_P_TAMP_MASK       (0x0FUL << RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT)     /*!< RTC_TAMPER_DIRECTION: A_P_TAMP Mask     */
#define RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT      0                                                   /*!< RTC_TAMPER_DIRECTION: A_P_TAMP Position */
#define RTC_TAMPER_DIRECTION_A_P_TAMP(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_DIRECTION_A_P_TAMP_SHIFT))&RTC_TAMPER_DIRECTION_A_P_TAMP_MASK) /*!< RTC_TAMPER_DIRECTION                    */
#define RTC_TAMPER_DIRECTION_I_O_TAMP_MASK       (0x0FUL << RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT)     /*!< RTC_TAMPER_DIRECTION: I_O_TAMP Mask     */
#define RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT      8                                                   /*!< RTC_TAMPER_DIRECTION: I_O_TAMP Position */
#define RTC_TAMPER_DIRECTION_I_O_TAMP(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_DIRECTION_I_O_TAMP_SHIFT))&RTC_TAMPER_DIRECTION_I_O_TAMP_MASK) /*!< RTC_TAMPER_DIRECTION                    */
/* ------- TAMPER_QSCR Bit Fields                   ------ */
#define RTC_TAMPER_QSCR_Q_FULL_MASK              (0x01UL << RTC_TAMPER_QSCR_Q_FULL_SHIFT)            /*!< RTC_TAMPER_QSCR: Q_FULL Mask            */
#define RTC_TAMPER_QSCR_Q_FULL_SHIFT             0                                                   /*!< RTC_TAMPER_QSCR: Q_FULL Position        */
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_MASK       (0x01UL << RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT)     /*!< RTC_TAMPER_QSCR: Q_FULL_INT_EN Mask     */
#define RTC_TAMPER_QSCR_Q_FULL_INT_EN_SHIFT      1                                                   /*!< RTC_TAMPER_QSCR: Q_FULL_INT_EN Position */
#define RTC_TAMPER_QSCR_Q_CLEAR_MASK             (0x01UL << RTC_TAMPER_QSCR_Q_CLEAR_SHIFT)           /*!< RTC_TAMPER_QSCR: Q_CLEAR Mask           */
#define RTC_TAMPER_QSCR_Q_CLEAR_SHIFT            2                                                   /*!< RTC_TAMPER_QSCR: Q_CLEAR Position       */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK        (0x07UL << RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT)      /*!< RTC_TAMPER_QSCR: LFSR_CLK_SEL Mask      */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT       8                                                   /*!< RTC_TAMPER_QSCR: LFSR_CLK_SEL Position  */
#define RTC_TAMPER_QSCR_LFSR_CLK_SEL(x)          (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QSCR_LFSR_CLK_SEL_SHIFT))&RTC_TAMPER_QSCR_LFSR_CLK_SEL_MASK) /*!< RTC_TAMPER_QSCR                         */
#define RTC_TAMPER_QSCR_LFSR_DURATION_MASK       (0x0FUL << RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT)     /*!< RTC_TAMPER_QSCR: LFSR_DURATION Mask     */
#define RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT      12                                                  /*!< RTC_TAMPER_QSCR: LFSR_DURATION Position */
#define RTC_TAMPER_QSCR_LFSR_DURATION(x)         (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QSCR_LFSR_DURATION_SHIFT))&RTC_TAMPER_QSCR_LFSR_DURATION_MASK) /*!< RTC_TAMPER_QSCR                         */
/* ------- TAMPER_SCR Bit Fields                    ------ */
#define RTC_TAMPER_SCR_TMPR_EN_MASK              (0x0FUL << RTC_TAMPER_SCR_TMPR_EN_SHIFT)            /*!< RTC_TAMPER_SCR: TMPR_EN Mask            */
#define RTC_TAMPER_SCR_TMPR_EN_SHIFT             0                                                   /*!< RTC_TAMPER_SCR: TMPR_EN Position        */
#define RTC_TAMPER_SCR_TMPR_EN(x)                (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_SCR_TMPR_EN_SHIFT))&RTC_TAMPER_SCR_TMPR_EN_MASK) /*!< RTC_TAMPER_SCR                          */
#define RTC_TAMPER_SCR_TMPR_STS_MASK             (0x0FUL << RTC_TAMPER_SCR_TMPR_STS_SHIFT)           /*!< RTC_TAMPER_SCR: TMPR_STS Mask           */
#define RTC_TAMPER_SCR_TMPR_STS_SHIFT            8                                                   /*!< RTC_TAMPER_SCR: TMPR_STS Position       */
#define RTC_TAMPER_SCR_TMPR_STS(x)               (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_SCR_TMPR_STS_SHIFT))&RTC_TAMPER_SCR_TMPR_STS_MASK) /*!< RTC_TAMPER_SCR                          */
/* ------- FILTER01_CFG Bit Fields                  ------ */
#define RTC_FILTER01_CFG_FIL_DUR1_MASK           (0x0FUL << RTC_FILTER01_CFG_FIL_DUR1_SHIFT)         /*!< RTC_FILTER01_CFG: FIL_DUR1 Mask         */
#define RTC_FILTER01_CFG_FIL_DUR1_SHIFT          0                                                   /*!< RTC_FILTER01_CFG: FIL_DUR1 Position     */
#define RTC_FILTER01_CFG_FIL_DUR1(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_FIL_DUR1_SHIFT))&RTC_FILTER01_CFG_FIL_DUR1_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_CLK_SEL1_MASK           (0x07UL << RTC_FILTER01_CFG_CLK_SEL1_SHIFT)         /*!< RTC_FILTER01_CFG: CLK_SEL1 Mask         */
#define RTC_FILTER01_CFG_CLK_SEL1_SHIFT          4                                                   /*!< RTC_FILTER01_CFG: CLK_SEL1 Position     */
#define RTC_FILTER01_CFG_CLK_SEL1(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_CLK_SEL1_SHIFT))&RTC_FILTER01_CFG_CLK_SEL1_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_POL1_MASK               (0x01UL << RTC_FILTER01_CFG_POL1_SHIFT)             /*!< RTC_FILTER01_CFG: POL1 Mask             */
#define RTC_FILTER01_CFG_POL1_SHIFT              7                                                   /*!< RTC_FILTER01_CFG: POL1 Position         */
#define RTC_FILTER01_CFG_FIL_DUR0_MASK           (0x0FUL << RTC_FILTER01_CFG_FIL_DUR0_SHIFT)         /*!< RTC_FILTER01_CFG: FIL_DUR0 Mask         */
#define RTC_FILTER01_CFG_FIL_DUR0_SHIFT          8                                                   /*!< RTC_FILTER01_CFG: FIL_DUR0 Position     */
#define RTC_FILTER01_CFG_FIL_DUR0(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_FIL_DUR0_SHIFT))&RTC_FILTER01_CFG_FIL_DUR0_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_CLK_SEL0_MASK           (0x07UL << RTC_FILTER01_CFG_CLK_SEL0_SHIFT)         /*!< RTC_FILTER01_CFG: CLK_SEL0 Mask         */
#define RTC_FILTER01_CFG_CLK_SEL0_SHIFT          12                                                  /*!< RTC_FILTER01_CFG: CLK_SEL0 Position     */
#define RTC_FILTER01_CFG_CLK_SEL0(x)             (((uint16_t)(((uint16_t)(x))<<RTC_FILTER01_CFG_CLK_SEL0_SHIFT))&RTC_FILTER01_CFG_CLK_SEL0_MASK) /*!< RTC_FILTER01_CFG                        */
#define RTC_FILTER01_CFG_POL0_MASK               (0x01UL << RTC_FILTER01_CFG_POL0_SHIFT)             /*!< RTC_FILTER01_CFG: POL0 Mask             */
#define RTC_FILTER01_CFG_POL0_SHIFT              15                                                  /*!< RTC_FILTER01_CFG: POL0 Position         */
/* ------- FILTER2_CFG Bit Fields                   ------ */
#define RTC_FILTER2_CFG_FIL_DUR2_MASK            (0x0FUL << RTC_FILTER2_CFG_FIL_DUR2_SHIFT)          /*!< RTC_FILTER2_CFG: FIL_DUR2 Mask          */
#define RTC_FILTER2_CFG_FIL_DUR2_SHIFT           8                                                   /*!< RTC_FILTER2_CFG: FIL_DUR2 Position      */
#define RTC_FILTER2_CFG_FIL_DUR2(x)              (((uint16_t)(((uint16_t)(x))<<RTC_FILTER2_CFG_FIL_DUR2_SHIFT))&RTC_FILTER2_CFG_FIL_DUR2_MASK) /*!< RTC_FILTER2_CFG                         */
#define RTC_FILTER2_CFG_CLK_SEL2_MASK            (0x07UL << RTC_FILTER2_CFG_CLK_SEL2_SHIFT)          /*!< RTC_FILTER2_CFG: CLK_SEL2 Mask          */
#define RTC_FILTER2_CFG_CLK_SEL2_SHIFT           12                                                  /*!< RTC_FILTER2_CFG: CLK_SEL2 Position      */
#define RTC_FILTER2_CFG_CLK_SEL2(x)              (((uint16_t)(((uint16_t)(x))<<RTC_FILTER2_CFG_CLK_SEL2_SHIFT))&RTC_FILTER2_CFG_CLK_SEL2_MASK) /*!< RTC_FILTER2_CFG                         */
#define RTC_FILTER2_CFG_POL2_MASK                (0x01UL << RTC_FILTER2_CFG_POL2_SHIFT)              /*!< RTC_FILTER2_CFG: POL2 Mask              */
#define RTC_FILTER2_CFG_POL2_SHIFT               15                                                  /*!< RTC_FILTER2_CFG: POL2 Position          */
/* ------- TAMPER_QUEUE Bit Fields                  ------ */
#define RTC_TAMPER_QUEUE_TAMPER_DATA_MASK        (0xFFFFUL << RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT)    /*!< RTC_TAMPER_QUEUE: TAMPER_DATA Mask      */
#define RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT       0                                                   /*!< RTC_TAMPER_QUEUE: TAMPER_DATA Position  */
#define RTC_TAMPER_QUEUE_TAMPER_DATA(x)          (((uint16_t)(((uint16_t)(x))<<RTC_TAMPER_QUEUE_TAMPER_DATA_SHIFT))&RTC_TAMPER_QUEUE_TAMPER_DATA_MASK) /*!< RTC_TAMPER_QUEUE                        */
/* ------- CTRL2 Bit Fields                         ------ */
#define RTC_CTRL2_TAMP_CFG_OVER_MASK             (0x01UL << RTC_CTRL2_TAMP_CFG_OVER_SHIFT)           /*!< RTC_CTRL2: TAMP_CFG_OVER Mask           */
#define RTC_CTRL2_TAMP_CFG_OVER_SHIFT            0                                                   /*!< RTC_CTRL2: TAMP_CFG_OVER Position       */
#define RTC_CTRL2_WAKEUP_STATUS_MASK             (0x03UL << RTC_CTRL2_WAKEUP_STATUS_SHIFT)           /*!< RTC_CTRL2: WAKEUP_STATUS Mask           */
#define RTC_CTRL2_WAKEUP_STATUS_SHIFT            5                                                   /*!< RTC_CTRL2: WAKEUP_STATUS Position       */
#define RTC_CTRL2_WAKEUP_STATUS(x)               (((uint16_t)(((uint16_t)(x))<<RTC_CTRL2_WAKEUP_STATUS_SHIFT))&RTC_CTRL2_WAKEUP_STATUS_MASK) /*!< RTC_CTRL2                               */
#define RTC_CTRL2_WAKEUP_MODE_MASK               (0x01UL << RTC_CTRL2_WAKEUP_MODE_SHIFT)             /*!< RTC_CTRL2: WAKEUP_MODE Mask             */
#define RTC_CTRL2_WAKEUP_MODE_SHIFT              7                                                   /*!< RTC_CTRL2: WAKEUP_MODE Position         */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x40050000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
/**
 * @} */ /* End group RTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MKM33ZA5)              ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
* @addtogroup SIM_structs_GROUP SIM struct
* @brief Struct for SIM
* @{
*/
typedef struct {                                /*       SIM Structure                                                */
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
   __IO uint32_t  SOPT1_CFG;                    /**< 0004: SOPT1 Configuration Register                                 */
   __I  uint32_t  RESERVED0[1023];             
   __IO uint32_t  CTRL_REG;                     /**< 1004: System Control Register                                      */
   __I  uint32_t  RESERVED1[7];                
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
   __I  uint32_t  RESERVED2[3];                
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
   __I  uint32_t  RESERVED3;                   
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UID[4];                       /**< 1054: Unique Identification Register                               */
   __I  uint32_t  RESERVED4[2];                
   __IO uint32_t  MISC_CTL;                     /**< 106C: Miscellaneous Control Register                               */
} SIM_Type;

/**
 * @} */ /* End group SIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SIM_Register_Masks_GROUP SIM Register Masks
* @brief Register Masks for SIM
* @{
*/
/* ------- SOPT1 Bit Fields                         ------ */
#define SIM_SOPT1_SRAMSIZE_MASK                  (0x0FUL << SIM_SOPT1_SRAMSIZE_SHIFT)                /*!< SIM_SOPT1: SRAMSIZE Mask                */
#define SIM_SOPT1_SRAMSIZE_SHIFT                 12                                                  /*!< SIM_SOPT1: SRAMSIZE Position            */
#define SIM_SOPT1_SRAMSIZE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_SRAMSIZE_SHIFT))&SIM_SOPT1_SRAMSIZE_MASK) /*!< SIM_SOPT1                               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0x03UL << SIM_SOPT1_OSC32KSEL_SHIFT)               /*!< SIM_SOPT1: OSC32KSEL Mask               */
#define SIM_SOPT1_OSC32KSEL_SHIFT                18                                                  /*!< SIM_SOPT1: OSC32KSEL Position           */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /*!< SIM_SOPT1                               */
/* ------- SOPT1_CFG Bit Fields                     ------ */
#define SIM_SOPT1_CFG_LPTMR1SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR1SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR1SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR1SEL_SHIFT            0                                                   /*!< SIM_SOPT1_CFG: LPTMR1SEL Position       */
#define SIM_SOPT1_CFG_LPTMR1SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR1SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR1SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_LPTMR2SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR2SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR2SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR2SEL_SHIFT            2                                                   /*!< SIM_SOPT1_CFG: LPTMR2SEL Position       */
#define SIM_SOPT1_CFG_LPTMR2SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR2SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR2SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_LPTMR3SEL_MASK             (0x03UL << SIM_SOPT1_CFG_LPTMR3SEL_SHIFT)           /*!< SIM_SOPT1_CFG: LPTMR3SEL Mask           */
#define SIM_SOPT1_CFG_LPTMR3SEL_SHIFT            4                                                   /*!< SIM_SOPT1_CFG: LPTMR3SEL Position       */
#define SIM_SOPT1_CFG_LPTMR3SEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_CFG_LPTMR3SEL_SHIFT))&SIM_SOPT1_CFG_LPTMR3SEL_MASK) /*!< SIM_SOPT1_CFG                           */
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK         (0x01UL << SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT)       /*!< SIM_SOPT1_CFG: CMPOLPTMR0SEL Mask       */
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT        6                                                   /*!< SIM_SOPT1_CFG: CMPOLPTMR0SEL Position   */
#define SIM_SOPT1_CFG_RAMSBDIS_MASK              (0x01UL << SIM_SOPT1_CFG_RAMSBDIS_SHIFT)            /*!< SIM_SOPT1_CFG: RAMSBDIS Mask            */
#define SIM_SOPT1_CFG_RAMSBDIS_SHIFT             8                                                   /*!< SIM_SOPT1_CFG: RAMSBDIS Position        */
#define SIM_SOPT1_CFG_RAMBPEN_MASK               (0x01UL << SIM_SOPT1_CFG_RAMBPEN_SHIFT)             /*!< SIM_SOPT1_CFG: RAMBPEN Mask             */
#define SIM_SOPT1_CFG_RAMBPEN_SHIFT              9                                                   /*!< SIM_SOPT1_CFG: RAMBPEN Position         */
/* ------- CTRL_REG Bit Fields                      ------ */
#define SIM_CTRL_REG_NMIDIS_MASK                 (0x01UL << SIM_CTRL_REG_NMIDIS_SHIFT)               /*!< SIM_CTRL_REG: NMIDIS Mask               */
#define SIM_CTRL_REG_NMIDIS_SHIFT                0                                                   /*!< SIM_CTRL_REG: NMIDIS Position           */
#define SIM_CTRL_REG_PLL_VLP_EN_MASK             (0x01UL << SIM_CTRL_REG_PLL_VLP_EN_SHIFT)           /*!< SIM_CTRL_REG: PLL_VLP_EN Mask           */
#define SIM_CTRL_REG_PLL_VLP_EN_SHIFT            1                                                   /*!< SIM_CTRL_REG: PLL_VLP_EN Position       */
#define SIM_CTRL_REG_PTC2_HD_EN_MASK             (0x01UL << SIM_CTRL_REG_PTC2_HD_EN_SHIFT)           /*!< SIM_CTRL_REG: PTC2_HD_EN Mask           */
#define SIM_CTRL_REG_PTC2_HD_EN_SHIFT            2                                                   /*!< SIM_CTRL_REG: PTC2_HD_EN Position       */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK        (0x03UL << SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT)      /*!< SIM_CTRL_REG: SAR_TRG_CLK_SEL Mask      */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT       3                                                   /*!< SIM_CTRL_REG: SAR_TRG_CLK_SEL Position  */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT))&SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK) /*!< SIM_CTRL_REG                            */
#define SIM_CTRL_REG_CLKOUTSEL_MASK              (0x07UL << SIM_CTRL_REG_CLKOUTSEL_SHIFT)            /*!< SIM_CTRL_REG: CLKOUTSEL Mask            */
#define SIM_CTRL_REG_CLKOUTSEL_SHIFT             5                                                   /*!< SIM_CTRL_REG: CLKOUTSEL Position        */
#define SIM_CTRL_REG_CLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_CTRL_REG_CLKOUTSEL_SHIFT))&SIM_CTRL_REG_CLKOUTSEL_MASK) /*!< SIM_CTRL_REG                            */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0x0FUL << SIM_SDID_PINID_SHIFT)                    /*!< SIM_SDID: PINID Mask                    */
#define SIM_SDID_PINID_SHIFT                     0                                                   /*!< SIM_SDID: PINID Position                */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_DIEID_MASK                      (0x0FUL << SIM_SDID_DIEID_SHIFT)                    /*!< SIM_SDID: DIEID Mask                    */
#define SIM_SDID_DIEID_SHIFT                     4                                                   /*!< SIM_SDID: DIEID Position                */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0x0FUL << SIM_SDID_REVID_SHIFT)                    /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     8                                                   /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SRAMSIZE_MASK                   (0x0FUL << SIM_SDID_SRAMSIZE_SHIFT)                 /*!< SIM_SDID: SRAMSIZE Mask                 */
#define SIM_SDID_SRAMSIZE_SHIFT                  12                                                  /*!< SIM_SDID: SRAMSIZE Position             */
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_ATTR_MASK                       (0x0FUL << SIM_SDID_ATTR_SHIFT)                     /*!< SIM_SDID: ATTR Mask                     */
#define SIM_SDID_ATTR_SHIFT                      16                                                  /*!< SIM_SDID: ATTR Position                 */
#define SIM_SDID_ATTR(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SDID_ATTR_SHIFT))&SIM_SDID_ATTR_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SERIESID_MASK                   (0x0FUL << SIM_SDID_SERIESID_SHIFT)                 /*!< SIM_SDID: SERIESID Mask                 */
#define SIM_SDID_SERIESID_SHIFT                  20                                                  /*!< SIM_SDID: SERIESID Position             */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SUBFAMID_MASK                   (0x0FUL << SIM_SDID_SUBFAMID_SHIFT)                 /*!< SIM_SDID: SUBFAMID Mask                 */
#define SIM_SDID_SUBFAMID_SHIFT                  24                                                  /*!< SIM_SDID: SUBFAMID Position             */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_FAMID_MASK                      (0x0FUL << SIM_SDID_FAMID_SHIFT)                    /*!< SIM_SDID: FAMID Mask                    */
#define SIM_SDID_FAMID_SHIFT                     28                                                  /*!< SIM_SDID: FAMID Position                */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK) /*!< SIM_SDID                                */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_EWM_MASK                       (0x01UL << SIM_SCGC4_EWM_SHIFT)                     /*!< SIM_SCGC4: EWM Mask                     */
#define SIM_SCGC4_EWM_SHIFT                      1                                                   /*!< SIM_SCGC4: EWM Position                 */
#define SIM_SCGC4_MCG_MASK                       (0x01UL << SIM_SCGC4_MCG_SHIFT)                     /*!< SIM_SCGC4: MCG Mask                     */
#define SIM_SCGC4_MCG_SHIFT                      4                                                   /*!< SIM_SCGC4: MCG Position                 */
#define SIM_SCGC4_OSC_MASK                       (0x01UL << SIM_SCGC4_OSC_SHIFT)                     /*!< SIM_SCGC4: OSC Mask                     */
#define SIM_SCGC4_OSC_SHIFT                      6                                                   /*!< SIM_SCGC4: OSC Position                 */
#define SIM_SCGC4_I2C0_MASK                      (0x01UL << SIM_SCGC4_I2C0_SHIFT)                    /*!< SIM_SCGC4: I2C0 Mask                    */
#define SIM_SCGC4_I2C0_SHIFT                     7                                                   /*!< SIM_SCGC4: I2C0 Position                */
#define SIM_SCGC4_I2C1_MASK                      (0x01UL << SIM_SCGC4_I2C1_SHIFT)                    /*!< SIM_SCGC4: I2C1 Mask                    */
#define SIM_SCGC4_I2C1_SHIFT                     8                                                   /*!< SIM_SCGC4: I2C1 Position                */
#define SIM_SCGC4_UART0_MASK                     (0x01UL << SIM_SCGC4_UART0_SHIFT)                   /*!< SIM_SCGC4: UART0 Mask                   */
#define SIM_SCGC4_UART0_SHIFT                    10                                                  /*!< SIM_SCGC4: UART0 Position               */
#define SIM_SCGC4_UART1_MASK                     (0x01UL << SIM_SCGC4_UART1_SHIFT)                   /*!< SIM_SCGC4: UART1 Mask                   */
#define SIM_SCGC4_UART1_SHIFT                    11                                                  /*!< SIM_SCGC4: UART1 Position               */
#define SIM_SCGC4_UART2_MASK                     (0x01UL << SIM_SCGC4_UART2_SHIFT)                   /*!< SIM_SCGC4: UART2 Mask                   */
#define SIM_SCGC4_UART2_SHIFT                    12                                                  /*!< SIM_SCGC4: UART2 Position               */
#define SIM_SCGC4_UART3_MASK                     (0x01UL << SIM_SCGC4_UART3_SHIFT)                   /*!< SIM_SCGC4: UART3 Mask                   */
#define SIM_SCGC4_UART3_SHIFT                    13                                                  /*!< SIM_SCGC4: UART3 Position               */
#define SIM_SCGC4_VREF_MASK                      (0x01UL << SIM_SCGC4_VREF_SHIFT)                    /*!< SIM_SCGC4: VREF Mask                    */
#define SIM_SCGC4_VREF_SHIFT                     15                                                  /*!< SIM_SCGC4: VREF Position                */
#define SIM_SCGC4_CMP0_MASK                      (0x01UL << SIM_SCGC4_CMP0_SHIFT)                    /*!< SIM_SCGC4: CMP0 Mask                    */
#define SIM_SCGC4_CMP0_SHIFT                     18                                                  /*!< SIM_SCGC4: CMP0 Position                */
#define SIM_SCGC4_CMP1_MASK                      (0x01UL << SIM_SCGC4_CMP1_SHIFT)                    /*!< SIM_SCGC4: CMP1 Mask                    */
#define SIM_SCGC4_CMP1_SHIFT                     19                                                  /*!< SIM_SCGC4: CMP1 Position                */
#define SIM_SCGC4_SPI0_MASK                      (0x01UL << SIM_SCGC4_SPI0_SHIFT)                    /*!< SIM_SCGC4: SPI0 Mask                    */
#define SIM_SCGC4_SPI0_SHIFT                     21                                                  /*!< SIM_SCGC4: SPI0 Position                */
#define SIM_SCGC4_SPI1_MASK                      (0x01UL << SIM_SCGC4_SPI1_SHIFT)                    /*!< SIM_SCGC4: SPI1 Mask                    */
#define SIM_SCGC4_SPI1_SHIFT                     22                                                  /*!< SIM_SCGC4: SPI1 Position                */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_SLCD_MASK                      (0x01UL << SIM_SCGC5_SLCD_SHIFT)                    /*!< SIM_SCGC5: SLCD Mask                    */
#define SIM_SCGC5_SLCD_SHIFT                     3                                                   /*!< SIM_SCGC5: SLCD Position                */
#define SIM_SCGC5_PORTA_MASK                     (0x01UL << SIM_SCGC5_PORTA_SHIFT)                   /*!< SIM_SCGC5: PORTA Mask                   */
#define SIM_SCGC5_PORTA_SHIFT                    6                                                   /*!< SIM_SCGC5: PORTA Position               */
#define SIM_SCGC5_PORTB_MASK                     (0x01UL << SIM_SCGC5_PORTB_SHIFT)                   /*!< SIM_SCGC5: PORTB Mask                   */
#define SIM_SCGC5_PORTB_SHIFT                    7                                                   /*!< SIM_SCGC5: PORTB Position               */
#define SIM_SCGC5_PORTC_MASK                     (0x01UL << SIM_SCGC5_PORTC_SHIFT)                   /*!< SIM_SCGC5: PORTC Mask                   */
#define SIM_SCGC5_PORTC_SHIFT                    8                                                   /*!< SIM_SCGC5: PORTC Position               */
#define SIM_SCGC5_PORTD_MASK                     (0x01UL << SIM_SCGC5_PORTD_SHIFT)                   /*!< SIM_SCGC5: PORTD Mask                   */
#define SIM_SCGC5_PORTD_SHIFT                    9                                                   /*!< SIM_SCGC5: PORTD Position               */
#define SIM_SCGC5_PORTE_MASK                     (0x01UL << SIM_SCGC5_PORTE_SHIFT)                   /*!< SIM_SCGC5: PORTE Mask                   */
#define SIM_SCGC5_PORTE_SHIFT                    10                                                  /*!< SIM_SCGC5: PORTE Position               */
#define SIM_SCGC5_PORTF_MASK                     (0x01UL << SIM_SCGC5_PORTF_SHIFT)                   /*!< SIM_SCGC5: PORTF Mask                   */
#define SIM_SCGC5_PORTF_SHIFT                    11                                                  /*!< SIM_SCGC5: PORTF Position               */
#define SIM_SCGC5_PORTG_MASK                     (0x01UL << SIM_SCGC5_PORTG_SHIFT)                   /*!< SIM_SCGC5: PORTG Mask                   */
#define SIM_SCGC5_PORTG_SHIFT                    12                                                  /*!< SIM_SCGC5: PORTG Position               */
#define SIM_SCGC5_PORTH_MASK                     (0x01UL << SIM_SCGC5_PORTH_SHIFT)                   /*!< SIM_SCGC5: PORTH Mask                   */
#define SIM_SCGC5_PORTH_SHIFT                    13                                                  /*!< SIM_SCGC5: PORTH Position               */
#define SIM_SCGC5_PORTI_MASK                     (0x01UL << SIM_SCGC5_PORTI_SHIFT)                   /*!< SIM_SCGC5: PORTI Mask                   */
#define SIM_SCGC5_PORTI_SHIFT                    14                                                  /*!< SIM_SCGC5: PORTI Position               */
#define SIM_SCGC5_IRTC_MASK                      (0x01UL << SIM_SCGC5_IRTC_SHIFT)                    /*!< SIM_SCGC5: IRTC Mask                    */
#define SIM_SCGC5_IRTC_SHIFT                     16                                                  /*!< SIM_SCGC5: IRTC Position                */
#define SIM_SCGC5_IRTCREGFILE_MASK               (0x01UL << SIM_SCGC5_IRTCREGFILE_SHIFT)             /*!< SIM_SCGC5: IRTCREGFILE Mask             */
#define SIM_SCGC5_IRTCREGFILE_SHIFT              17                                                  /*!< SIM_SCGC5: IRTCREGFILE Position         */
#define SIM_SCGC5_WDOG_MASK                      (0x01UL << SIM_SCGC5_WDOG_SHIFT)                    /*!< SIM_SCGC5: WDOG Mask                    */
#define SIM_SCGC5_WDOG_SHIFT                     19                                                  /*!< SIM_SCGC5: WDOG Position                */
#define SIM_SCGC5_XBAR_MASK                      (0x01UL << SIM_SCGC5_XBAR_SHIFT)                    /*!< SIM_SCGC5: XBAR Mask                    */
#define SIM_SCGC5_XBAR_SHIFT                     21                                                  /*!< SIM_SCGC5: XBAR Position                */
#define SIM_SCGC5_TMR0_MASK                      (0x01UL << SIM_SCGC5_TMR0_SHIFT)                    /*!< SIM_SCGC5: TMR0 Mask                    */
#define SIM_SCGC5_TMR0_SHIFT                     23                                                  /*!< SIM_SCGC5: TMR0 Position                */
#define SIM_SCGC5_TMR1_MASK                      (0x01UL << SIM_SCGC5_TMR1_SHIFT)                    /*!< SIM_SCGC5: TMR1 Mask                    */
#define SIM_SCGC5_TMR1_SHIFT                     24                                                  /*!< SIM_SCGC5: TMR1 Position                */
#define SIM_SCGC5_TMR2_MASK                      (0x01UL << SIM_SCGC5_TMR2_SHIFT)                    /*!< SIM_SCGC5: TMR2 Mask                    */
#define SIM_SCGC5_TMR2_SHIFT                     25                                                  /*!< SIM_SCGC5: TMR2 Position                */
#define SIM_SCGC5_TMR3_MASK                      (0x01UL << SIM_SCGC5_TMR3_SHIFT)                    /*!< SIM_SCGC5: TMR3 Mask                    */
#define SIM_SCGC5_TMR3_SHIFT                     26                                                  /*!< SIM_SCGC5: TMR3 Position                */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_FTFA_MASK                      (0x01UL << SIM_SCGC6_FTFA_SHIFT)                    /*!< SIM_SCGC6: FTFA Mask                    */
#define SIM_SCGC6_FTFA_SHIFT                     0                                                   /*!< SIM_SCGC6: FTFA Position                */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x01UL << SIM_SCGC6_DMAMUX0_SHIFT)                 /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  1                                                   /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX1_MASK                   (0x01UL << SIM_SCGC6_DMAMUX1_SHIFT)                 /*!< SIM_SCGC6: DMAMUX1 Mask                 */
#define SIM_SCGC6_DMAMUX1_SHIFT                  2                                                   /*!< SIM_SCGC6: DMAMUX1 Position             */
#define SIM_SCGC6_DMAMUX2_MASK                   (0x01UL << SIM_SCGC6_DMAMUX2_SHIFT)                 /*!< SIM_SCGC6: DMAMUX2 Mask                 */
#define SIM_SCGC6_DMAMUX2_SHIFT                  3                                                   /*!< SIM_SCGC6: DMAMUX2 Position             */
#define SIM_SCGC6_DMAMUX3_MASK                   (0x01UL << SIM_SCGC6_DMAMUX3_SHIFT)                 /*!< SIM_SCGC6: DMAMUX3 Mask                 */
#define SIM_SCGC6_DMAMUX3_SHIFT                  4                                                   /*!< SIM_SCGC6: DMAMUX3 Position             */
#define SIM_SCGC6_RNGA_MASK                      (0x01UL << SIM_SCGC6_RNGA_SHIFT)                    /*!< SIM_SCGC6: RNGA Mask                    */
#define SIM_SCGC6_RNGA_SHIFT                     9                                                   /*!< SIM_SCGC6: RNGA Position                */
#define SIM_SCGC6_ADC_MASK                       (0x01UL << SIM_SCGC6_ADC_SHIFT)                     /*!< SIM_SCGC6: ADC Mask                     */
#define SIM_SCGC6_ADC_SHIFT                      11                                                  /*!< SIM_SCGC6: ADC Position                 */
#define SIM_SCGC6_PIT0_MASK                      (0x01UL << SIM_SCGC6_PIT0_SHIFT)                    /*!< SIM_SCGC6: PIT0 Mask                    */
#define SIM_SCGC6_PIT0_SHIFT                     13                                                  /*!< SIM_SCGC6: PIT0 Position                */
#define SIM_SCGC6_PIT1_MASK                      (0x01UL << SIM_SCGC6_PIT1_SHIFT)                    /*!< SIM_SCGC6: PIT1 Mask                    */
#define SIM_SCGC6_PIT1_SHIFT                     14                                                  /*!< SIM_SCGC6: PIT1 Position                */
#define SIM_SCGC6_AFE_MASK                       (0x01UL << SIM_SCGC6_AFE_SHIFT)                     /*!< SIM_SCGC6: AFE Mask                     */
#define SIM_SCGC6_AFE_SHIFT                      16                                                  /*!< SIM_SCGC6: AFE Position                 */
#define SIM_SCGC6_CRC_MASK                       (0x01UL << SIM_SCGC6_CRC_SHIFT)                     /*!< SIM_SCGC6: CRC Mask                     */
#define SIM_SCGC6_CRC_SHIFT                      20                                                  /*!< SIM_SCGC6: CRC Position                 */
#define SIM_SCGC6_LPTMR_MASK                     (0x01UL << SIM_SCGC6_LPTMR_SHIFT)                   /*!< SIM_SCGC6: LPTMR Mask                   */
#define SIM_SCGC6_LPTMR_SHIFT                    28                                                  /*!< SIM_SCGC6: LPTMR Position               */
#define SIM_SCGC6_SIM_LP_MASK                    (0x01UL << SIM_SCGC6_SIM_LP_SHIFT)                  /*!< SIM_SCGC6: SIM_LP Mask                  */
#define SIM_SCGC6_SIM_LP_SHIFT                   30                                                  /*!< SIM_SCGC6: SIM_LP Position              */
#define SIM_SCGC6_SIM_HP_MASK                    (0x01UL << SIM_SCGC6_SIM_HP_SHIFT)                  /*!< SIM_SCGC6: SIM_HP Mask                  */
#define SIM_SCGC6_SIM_HP_SHIFT                   31                                                  /*!< SIM_SCGC6: SIM_HP Position              */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_MPU_MASK                       (0x01UL << SIM_SCGC7_MPU_SHIFT)                     /*!< SIM_SCGC7: MPU Mask                     */
#define SIM_SCGC7_MPU_SHIFT                      0                                                   /*!< SIM_SCGC7: MPU Position                 */
#define SIM_SCGC7_DMA_MASK                       (0x01UL << SIM_SCGC7_DMA_SHIFT)                     /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      1                                                   /*!< SIM_SCGC7: DMA Position                 */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_SYSCLKMODE_MASK              (0x01UL << SIM_CLKDIV1_SYSCLKMODE_SHIFT)            /*!< SIM_CLKDIV1: SYSCLKMODE Mask            */
#define SIM_CLKDIV1_SYSCLKMODE_SHIFT             27                                                  /*!< SIM_CLKDIV1: SYSCLKMODE Position        */
#define SIM_CLKDIV1_SYSDIV_MASK                  (0x0FUL << SIM_CLKDIV1_SYSDIV_SHIFT)                /*!< SIM_CLKDIV1: SYSDIV Mask                */
#define SIM_CLKDIV1_SYSDIV_SHIFT                 28                                                  /*!< SIM_CLKDIV1: SYSDIV Position            */
#define SIM_CLKDIV1_SYSDIV(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_SYSDIV_SHIFT))&SIM_CLKDIV1_SYSDIV_MASK) /*!< SIM_CLKDIV1                             */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x01UL << SIM_FCFG1_FLASHDIS_SHIFT)                /*!< SIM_FCFG1: FLASHDIS Mask                */
#define SIM_FCFG1_FLASHDIS_SHIFT                 0                                                   /*!< SIM_FCFG1: FLASHDIS Position            */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x01UL << SIM_FCFG1_FLASHDOZE_SHIFT)               /*!< SIM_FCFG1: FLASHDOZE Mask               */
#define SIM_FCFG1_FLASHDOZE_SHIFT                1                                                   /*!< SIM_FCFG1: FLASHDOZE Position           */
#define SIM_FCFG1_PFSIZE_MASK                    (0x0FUL << SIM_FCFG1_PFSIZE_SHIFT)                  /*!< SIM_FCFG1: PFSIZE Mask                  */
#define SIM_FCFG1_PFSIZE_SHIFT                   24                                                  /*!< SIM_FCFG1: PFSIZE Position              */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK) /*!< SIM_FCFG1                               */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR_MASK                   (0x7FUL << SIM_FCFG2_MAXADDR_SHIFT)                 /*!< SIM_FCFG2: MAXADDR Mask                 */
#define SIM_FCFG2_MAXADDR_SHIFT                  24                                                  /*!< SIM_FCFG2: MAXADDR Position             */
#define SIM_FCFG2_MAXADDR(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR_SHIFT))&SIM_FCFG2_MAXADDR_MASK) /*!< SIM_FCFG2                               */
/* ------- UID Bit Fields                           ------ */
#define SIM_UID_UID_MASK                         (0xFFFFFFFFUL << SIM_UID_UID_SHIFT)                 /*!< SIM_UID: UID Mask                       */
#define SIM_UID_UID_SHIFT                        0                                                   /*!< SIM_UID: UID Position                   */
#define SIM_UID_UID(x)                           (((uint32_t)(((uint32_t)(x))<<SIM_UID_UID_SHIFT))&SIM_UID_UID_MASK) /*!< SIM_UID                                 */
/* ------- MISC_CTL Bit Fields                      ------ */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK       (0x03UL << SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT)     /*!< SIM_MISC_CTL: XBARAFEMODOUTSEL Mask     */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT      0                                                   /*!< SIM_MISC_CTL: XBARAFEMODOUTSEL Position */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL(x)         (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT))&SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_DMADONESEL_MASK             (0x03UL << SIM_MISC_CTL_DMADONESEL_SHIFT)           /*!< SIM_MISC_CTL: DMADONESEL Mask           */
#define SIM_MISC_CTL_DMADONESEL_SHIFT            2                                                   /*!< SIM_MISC_CTL: DMADONESEL Position       */
#define SIM_MISC_CTL_DMADONESEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_DMADONESEL_SHIFT))&SIM_MISC_CTL_DMADONESEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_AFECLKSEL_MASK              (0x03UL << SIM_MISC_CTL_AFECLKSEL_SHIFT)            /*!< SIM_MISC_CTL: AFECLKSEL Mask            */
#define SIM_MISC_CTL_AFECLKSEL_SHIFT             4                                                   /*!< SIM_MISC_CTL: AFECLKSEL Position        */
#define SIM_MISC_CTL_AFECLKSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_AFECLKSEL_SHIFT))&SIM_MISC_CTL_AFECLKSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_AFECLKPADDIR_MASK           (0x01UL << SIM_MISC_CTL_AFECLKPADDIR_SHIFT)         /*!< SIM_MISC_CTL: AFECLKPADDIR Mask         */
#define SIM_MISC_CTL_AFECLKPADDIR_SHIFT          6                                                   /*!< SIM_MISC_CTL: AFECLKPADDIR Position     */
#define SIM_MISC_CTL_UARTMODTYPE_MASK            (0x01UL << SIM_MISC_CTL_UARTMODTYPE_SHIFT)          /*!< SIM_MISC_CTL: UARTMODTYPE Mask          */
#define SIM_MISC_CTL_UARTMODTYPE_SHIFT           7                                                   /*!< SIM_MISC_CTL: UARTMODTYPE Position      */
#define SIM_MISC_CTL_UART0IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART0IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART0IRSEL Mask           */
#define SIM_MISC_CTL_UART0IRSEL_SHIFT            8                                                   /*!< SIM_MISC_CTL: UART0IRSEL Position       */
#define SIM_MISC_CTL_UART1IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART1IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART1IRSEL Mask           */
#define SIM_MISC_CTL_UART1IRSEL_SHIFT            9                                                   /*!< SIM_MISC_CTL: UART1IRSEL Position       */
#define SIM_MISC_CTL_UART2IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART2IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART2IRSEL Mask           */
#define SIM_MISC_CTL_UART2IRSEL_SHIFT            10                                                  /*!< SIM_MISC_CTL: UART2IRSEL Position       */
#define SIM_MISC_CTL_UART3IRSEL_MASK             (0x01UL << SIM_MISC_CTL_UART3IRSEL_SHIFT)           /*!< SIM_MISC_CTL: UART3IRSEL Mask           */
#define SIM_MISC_CTL_UART3IRSEL_SHIFT            11                                                  /*!< SIM_MISC_CTL: UART3IRSEL Position       */
#define SIM_MISC_CTL_XBARPITOUTSEL_MASK          (0x03UL << SIM_MISC_CTL_XBARPITOUTSEL_SHIFT)        /*!< SIM_MISC_CTL: XBARPITOUTSEL Mask        */
#define SIM_MISC_CTL_XBARPITOUTSEL_SHIFT         12                                                  /*!< SIM_MISC_CTL: XBARPITOUTSEL Position    */
#define SIM_MISC_CTL_XBARPITOUTSEL(x)            (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_XBARPITOUTSEL_SHIFT))&SIM_MISC_CTL_XBARPITOUTSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_EWMINSEL_MASK               (0x01UL << SIM_MISC_CTL_EWMINSEL_SHIFT)             /*!< SIM_MISC_CTL: EWMINSEL Mask             */
#define SIM_MISC_CTL_EWMINSEL_SHIFT              14                                                  /*!< SIM_MISC_CTL: EWMINSEL Position         */
#define SIM_MISC_CTL_TMR0PLLCLKSEL_MASK          (0x01UL << SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT)        /*!< SIM_MISC_CTL: TMR0PLLCLKSEL Mask        */
#define SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT         15                                                  /*!< SIM_MISC_CTL: TMR0PLLCLKSEL Position    */
#define SIM_MISC_CTL_TMR0SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR0SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR0SCSSEL Mask           */
#define SIM_MISC_CTL_TMR0SCSSEL_SHIFT            16                                                  /*!< SIM_MISC_CTL: TMR0SCSSEL Position       */
#define SIM_MISC_CTL_TMR1SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR1SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR1SCSSEL Mask           */
#define SIM_MISC_CTL_TMR1SCSSEL_SHIFT            17                                                  /*!< SIM_MISC_CTL: TMR1SCSSEL Position       */
#define SIM_MISC_CTL_TMR2SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR2SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR2SCSSEL Mask           */
#define SIM_MISC_CTL_TMR2SCSSEL_SHIFT            18                                                  /*!< SIM_MISC_CTL: TMR2SCSSEL Position       */
#define SIM_MISC_CTL_TMR3SCSSEL_MASK             (0x01UL << SIM_MISC_CTL_TMR3SCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR3SCSSEL Mask           */
#define SIM_MISC_CTL_TMR3SCSSEL_SHIFT            19                                                  /*!< SIM_MISC_CTL: TMR3SCSSEL Position       */
#define SIM_MISC_CTL_TMR0PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR0PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR0PCSSEL Mask           */
#define SIM_MISC_CTL_TMR0PCSSEL_SHIFT            20                                                  /*!< SIM_MISC_CTL: TMR0PCSSEL Position       */
#define SIM_MISC_CTL_TMR0PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR0PCSSEL_SHIFT))&SIM_MISC_CTL_TMR0PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR1PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR1PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR1PCSSEL Mask           */
#define SIM_MISC_CTL_TMR1PCSSEL_SHIFT            22                                                  /*!< SIM_MISC_CTL: TMR1PCSSEL Position       */
#define SIM_MISC_CTL_TMR1PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR1PCSSEL_SHIFT))&SIM_MISC_CTL_TMR1PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR2PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR2PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR2PCSSEL Mask           */
#define SIM_MISC_CTL_TMR2PCSSEL_SHIFT            24                                                  /*!< SIM_MISC_CTL: TMR2PCSSEL Position       */
#define SIM_MISC_CTL_TMR2PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR2PCSSEL_SHIFT))&SIM_MISC_CTL_TMR2PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_TMR3PCSSEL_MASK             (0x03UL << SIM_MISC_CTL_TMR3PCSSEL_SHIFT)           /*!< SIM_MISC_CTL: TMR3PCSSEL Mask           */
#define SIM_MISC_CTL_TMR3PCSSEL_SHIFT            26                                                  /*!< SIM_MISC_CTL: TMR3PCSSEL Position       */
#define SIM_MISC_CTL_TMR3PCSSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_MISC_CTL_TMR3PCSSEL_SHIFT))&SIM_MISC_CTL_TMR3PCSSEL_MASK) /*!< SIM_MISC_CTL                            */
#define SIM_MISC_CTL_RTCCLKSEL_MASK              (0x01UL << SIM_MISC_CTL_RTCCLKSEL_SHIFT)            /*!< SIM_MISC_CTL: RTCCLKSEL Mask            */
#define SIM_MISC_CTL_RTCCLKSEL_SHIFT             28                                                  /*!< SIM_MISC_CTL: RTCCLKSEL Position        */
#define SIM_MISC_CTL_VREFBUFOUTEN_MASK           (0x01UL << SIM_MISC_CTL_VREFBUFOUTEN_SHIFT)         /*!< SIM_MISC_CTL: VREFBUFOUTEN Mask         */
#define SIM_MISC_CTL_VREFBUFOUTEN_SHIFT          29                                                  /*!< SIM_MISC_CTL: VREFBUFOUTEN Position     */
#define SIM_MISC_CTL_VREFBUFINSEL_MASK           (0x01UL << SIM_MISC_CTL_VREFBUFINSEL_SHIFT)         /*!< SIM_MISC_CTL: VREFBUFINSEL Mask         */
#define SIM_MISC_CTL_VREFBUFINSEL_SHIFT          30                                                  /*!< SIM_MISC_CTL: VREFBUFINSEL Position     */
#define SIM_MISC_CTL_VREFBUFPD_MASK              (0x01UL << SIM_MISC_CTL_VREFBUFPD_SHIFT)            /*!< SIM_MISC_CTL: VREFBUFPD Mask            */
#define SIM_MISC_CTL_VREFBUFPD_SHIFT             31                                                  /*!< SIM_MISC_CTL: VREFBUFPD Position        */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x4003E000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer
/**
 * @} */ /* End group SIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer
* @brief C Struct for SMC
* @{
*/

/* ================================================================================ */
/* ================           SMC (file:SMC_MKM14ZA5)              ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control Register                                  */
   __IO uint8_t   STOPCTRL;                     /**< 0002: Stop Control Register                                        */
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status Register                                   */
} SMC_Type;

/**
 * @} */ /* End group SMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SMC_Register_Masks_GROUP SMC Register Masks
* @brief Register Masks for SMC
* @{
*/
/* ------- PMPROT Bit Fields                        ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x01UL << SMC_PMPROT_AVLLS_SHIFT)                  /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   1                                                   /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_AVLP_MASK                     (0x01UL << SMC_PMPROT_AVLP_SHIFT)                   /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    5                                                   /*!< SMC_PMPROT: AVLP Position               */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x07UL << SMC_PMCTRL_STOPM_SHIFT)                  /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   0                                                   /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x01UL << SMC_PMCTRL_STOPA_SHIFT)                  /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   3                                                   /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_RUNM_MASK                     (0x03UL << SMC_PMCTRL_RUNM_SHIFT)                   /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    5                                                   /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */
/* ------- STOPCTRL Bit Fields                      ------ */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x07UL << SMC_STOPCTRL_VLLSM_SHIFT)                /*!< SMC_STOPCTRL: VLLSM Mask                */
#define SMC_STOPCTRL_VLLSM_SHIFT                 0                                                   /*!< SMC_STOPCTRL: VLLSM Position            */
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_PORPO_MASK                  (0x01UL << SMC_STOPCTRL_PORPO_SHIFT)                /*!< SMC_STOPCTRL: PORPO Mask                */
#define SMC_STOPCTRL_PORPO_SHIFT                 5                                                   /*!< SMC_STOPCTRL: PORPO Position            */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0x03UL << SMC_STOPCTRL_PSTOPO_SHIFT)               /*!< SMC_STOPCTRL: PSTOPO Mask               */
#define SMC_STOPCTRL_PSTOPO_SHIFT                6                                                   /*!< SMC_STOPCTRL: PSTOPO Position           */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK) /*!< SMC_STOPCTRL                            */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0x7FUL << SMC_PMSTAT_PMSTAT_SHIFT)                 /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  0                                                   /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer
/**
 * @} */ /* End group SMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MKM33ZA5)            ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __I  uint8_t   S;                            /**< 0000: Status register                                              */
   __IO uint8_t   BR;                           /**< 0001: Baud rate register                                           */
   __IO uint8_t   C2;                           /**< 0002: Control register 2                                           */
   __IO uint8_t   C1;                           /**< 0003: Control register 1                                           */
   __IO uint8_t   ML;                           /**< 0004: Match register low                                           */
   __IO uint8_t   MH;                           /**< 0005: Match register high                                          */
   __IO uint8_t   DL;                           /**< 0006: Data register low                                            */
   __IO uint8_t   DH;                           /**< 0007: Data register high                                           */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   CI;                           /**< 000A: Clear interrupt register                                     */
   __IO uint8_t   C3;                           /**< 000B: Control register 3                                           */
} SPI_Type;

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
/* ------- S Bit Fields                             ------ */
#define SPI_S_RFIFOEF_MASK                       (0x01UL << SPI_S_RFIFOEF_SHIFT)                     /*!< SPI0_S: RFIFOEF Mask                    */
#define SPI_S_RFIFOEF_SHIFT                      0                                                   /*!< SPI0_S: RFIFOEF Position                */
#define SPI_S_TXFULLF_MASK                       (0x01UL << SPI_S_TXFULLF_SHIFT)                     /*!< SPI0_S: TXFULLF Mask                    */
#define SPI_S_TXFULLF_SHIFT                      1                                                   /*!< SPI0_S: TXFULLF Position                */
#define SPI_S_TNEAREF_MASK                       (0x01UL << SPI_S_TNEAREF_SHIFT)                     /*!< SPI0_S: TNEAREF Mask                    */
#define SPI_S_TNEAREF_SHIFT                      2                                                   /*!< SPI0_S: TNEAREF Position                */
#define SPI_S_RNFULLF_MASK                       (0x01UL << SPI_S_RNFULLF_SHIFT)                     /*!< SPI0_S: RNFULLF Mask                    */
#define SPI_S_RNFULLF_SHIFT                      3                                                   /*!< SPI0_S: RNFULLF Position                */
#define SPI_S_MODF_MASK                          (0x01UL << SPI_S_MODF_SHIFT)                        /*!< SPI0_S: MODF Mask                       */
#define SPI_S_MODF_SHIFT                         4                                                   /*!< SPI0_S: MODF Position                   */
#define SPI_S_SPTEF_MASK                         (0x01UL << SPI_S_SPTEF_SHIFT)                       /*!< SPI0_S: SPTEF Mask                      */
#define SPI_S_SPTEF_SHIFT                        5                                                   /*!< SPI0_S: SPTEF Position                  */
#define SPI_S_SPMF_MASK                          (0x01UL << SPI_S_SPMF_SHIFT)                        /*!< SPI0_S: SPMF Mask                       */
#define SPI_S_SPMF_SHIFT                         6                                                   /*!< SPI0_S: SPMF Position                   */
#define SPI_S_SPRF_MASK                          (0x01UL << SPI_S_SPRF_SHIFT)                        /*!< SPI0_S: SPRF Mask                       */
#define SPI_S_SPRF_SHIFT                         7                                                   /*!< SPI0_S: SPRF Position                   */
/* ------- BR Bit Fields                            ------ */
#define SPI_BR_SPR_MASK                          (0x0FUL << SPI_BR_SPR_SHIFT)                        /*!< SPI0_BR: SPR Mask                       */
#define SPI_BR_SPR_SHIFT                         0                                                   /*!< SPI0_BR: SPR Position                   */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /*!< SPI0_BR                                 */
#define SPI_BR_SPPR_MASK                         (0x07UL << SPI_BR_SPPR_SHIFT)                       /*!< SPI0_BR: SPPR Mask                      */
#define SPI_BR_SPPR_SHIFT                        4                                                   /*!< SPI0_BR: SPPR Position                  */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /*!< SPI0_BR                                 */
/* ------- C2 Bit Fields                            ------ */
#define SPI_C2_SPC0_MASK                         (0x01UL << SPI_C2_SPC0_SHIFT)                       /*!< SPI0_C2: SPC0 Mask                      */
#define SPI_C2_SPC0_SHIFT                        0                                                   /*!< SPI0_C2: SPC0 Position                  */
#define SPI_C2_SPISWAI_MASK                      (0x01UL << SPI_C2_SPISWAI_SHIFT)                    /*!< SPI0_C2: SPISWAI Mask                   */
#define SPI_C2_SPISWAI_SHIFT                     1                                                   /*!< SPI0_C2: SPISWAI Position               */
#define SPI_C2_RXDMAE_MASK                       (0x01UL << SPI_C2_RXDMAE_SHIFT)                     /*!< SPI0_C2: RXDMAE Mask                    */
#define SPI_C2_RXDMAE_SHIFT                      2                                                   /*!< SPI0_C2: RXDMAE Position                */
#define SPI_C2_BIDIROE_MASK                      (0x01UL << SPI_C2_BIDIROE_SHIFT)                    /*!< SPI0_C2: BIDIROE Mask                   */
#define SPI_C2_BIDIROE_SHIFT                     3                                                   /*!< SPI0_C2: BIDIROE Position               */
#define SPI_C2_MODFEN_MASK                       (0x01UL << SPI_C2_MODFEN_SHIFT)                     /*!< SPI0_C2: MODFEN Mask                    */
#define SPI_C2_MODFEN_SHIFT                      4                                                   /*!< SPI0_C2: MODFEN Position                */
#define SPI_C2_TXDMAE_MASK                       (0x01UL << SPI_C2_TXDMAE_SHIFT)                     /*!< SPI0_C2: TXDMAE Mask                    */
#define SPI_C2_TXDMAE_SHIFT                      5                                                   /*!< SPI0_C2: TXDMAE Position                */
#define SPI_C2_SPIMODE_MASK                      (0x01UL << SPI_C2_SPIMODE_SHIFT)                    /*!< SPI0_C2: SPIMODE Mask                   */
#define SPI_C2_SPIMODE_SHIFT                     6                                                   /*!< SPI0_C2: SPIMODE Position               */
#define SPI_C2_SPMIE_MASK                        (0x01UL << SPI_C2_SPMIE_SHIFT)                      /*!< SPI0_C2: SPMIE Mask                     */
#define SPI_C2_SPMIE_SHIFT                       7                                                   /*!< SPI0_C2: SPMIE Position                 */
/* ------- C1 Bit Fields                            ------ */
#define SPI_C1_LSBFE_MASK                        (0x01UL << SPI_C1_LSBFE_SHIFT)                      /*!< SPI0_C1: LSBFE Mask                     */
#define SPI_C1_LSBFE_SHIFT                       0                                                   /*!< SPI0_C1: LSBFE Position                 */
#define SPI_C1_SSOE_MASK                         (0x01UL << SPI_C1_SSOE_SHIFT)                       /*!< SPI0_C1: SSOE Mask                      */
#define SPI_C1_SSOE_SHIFT                        1                                                   /*!< SPI0_C1: SSOE Position                  */
#define SPI_C1_CPHA_MASK                         (0x01UL << SPI_C1_CPHA_SHIFT)                       /*!< SPI0_C1: CPHA Mask                      */
#define SPI_C1_CPHA_SHIFT                        2                                                   /*!< SPI0_C1: CPHA Position                  */
#define SPI_C1_CPOL_MASK                         (0x01UL << SPI_C1_CPOL_SHIFT)                       /*!< SPI0_C1: CPOL Mask                      */
#define SPI_C1_CPOL_SHIFT                        3                                                   /*!< SPI0_C1: CPOL Position                  */
#define SPI_C1_MSTR_MASK                         (0x01UL << SPI_C1_MSTR_SHIFT)                       /*!< SPI0_C1: MSTR Mask                      */
#define SPI_C1_MSTR_SHIFT                        4                                                   /*!< SPI0_C1: MSTR Position                  */
#define SPI_C1_SPTIE_MASK                        (0x01UL << SPI_C1_SPTIE_SHIFT)                      /*!< SPI0_C1: SPTIE Mask                     */
#define SPI_C1_SPTIE_SHIFT                       5                                                   /*!< SPI0_C1: SPTIE Position                 */
#define SPI_C1_SPE_MASK                          (0x01UL << SPI_C1_SPE_SHIFT)                        /*!< SPI0_C1: SPE Mask                       */
#define SPI_C1_SPE_SHIFT                         6                                                   /*!< SPI0_C1: SPE Position                   */
#define SPI_C1_SPIE_MASK                         (0x01UL << SPI_C1_SPIE_SHIFT)                       /*!< SPI0_C1: SPIE Mask                      */
#define SPI_C1_SPIE_SHIFT                        7                                                   /*!< SPI0_C1: SPIE Position                  */
/* ------- ML Bit Fields                            ------ */
#define SPI_ML_Bits_MASK                         (0xFFUL << SPI_ML_Bits_SHIFT)                       /*!< SPI0_ML: Bits Mask                      */
#define SPI_ML_Bits_SHIFT                        0                                                   /*!< SPI0_ML: Bits Position                  */
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK) /*!< SPI0_ML                                 */
/* ------- MH Bit Fields                            ------ */
#define SPI_MH_Bits_MASK                         (0xFFUL << SPI_MH_Bits_SHIFT)                       /*!< SPI0_MH: Bits Mask                      */
#define SPI_MH_Bits_SHIFT                        0                                                   /*!< SPI0_MH: Bits Position                  */
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK) /*!< SPI0_MH                                 */
/* ------- DL Bit Fields                            ------ */
#define SPI_DL_Bits_MASK                         (0xFFUL << SPI_DL_Bits_SHIFT)                       /*!< SPI0_DL: Bits Mask                      */
#define SPI_DL_Bits_SHIFT                        0                                                   /*!< SPI0_DL: Bits Position                  */
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK) /*!< SPI0_DL                                 */
/* ------- DH Bit Fields                            ------ */
#define SPI_DH_Bits_MASK                         (0xFFUL << SPI_DH_Bits_SHIFT)                       /*!< SPI0_DH: Bits Mask                      */
#define SPI_DH_Bits_SHIFT                        0                                                   /*!< SPI0_DH: Bits Position                  */
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK) /*!< SPI0_DH                                 */
/* ------- CI Bit Fields                            ------ */
#define SPI_CI_SPRFCI_MASK                       (0x01UL << SPI_CI_SPRFCI_SHIFT)                     /*!< SPI0_CI: SPRFCI Mask                    */
#define SPI_CI_SPRFCI_SHIFT                      0                                                   /*!< SPI0_CI: SPRFCI Position                */
#define SPI_CI_SPTEFCI_MASK                      (0x01UL << SPI_CI_SPTEFCI_SHIFT)                    /*!< SPI0_CI: SPTEFCI Mask                   */
#define SPI_CI_SPTEFCI_SHIFT                     1                                                   /*!< SPI0_CI: SPTEFCI Position               */
#define SPI_CI_RNFULLFCI_MASK                    (0x01UL << SPI_CI_RNFULLFCI_SHIFT)                  /*!< SPI0_CI: RNFULLFCI Mask                 */
#define SPI_CI_RNFULLFCI_SHIFT                   2                                                   /*!< SPI0_CI: RNFULLFCI Position             */
#define SPI_CI_TNEAREFCI_MASK                    (0x01UL << SPI_CI_TNEAREFCI_SHIFT)                  /*!< SPI0_CI: TNEAREFCI Mask                 */
#define SPI_CI_TNEAREFCI_SHIFT                   3                                                   /*!< SPI0_CI: TNEAREFCI Position             */
#define SPI_CI_RXFOF_MASK                        (0x01UL << SPI_CI_RXFOF_SHIFT)                      /*!< SPI0_CI: RXFOF Mask                     */
#define SPI_CI_RXFOF_SHIFT                       4                                                   /*!< SPI0_CI: RXFOF Position                 */
#define SPI_CI_TXFOF_MASK                        (0x01UL << SPI_CI_TXFOF_SHIFT)                      /*!< SPI0_CI: TXFOF Mask                     */
#define SPI_CI_TXFOF_SHIFT                       5                                                   /*!< SPI0_CI: TXFOF Position                 */
#define SPI_CI_RXFERR_MASK                       (0x01UL << SPI_CI_RXFERR_SHIFT)                     /*!< SPI0_CI: RXFERR Mask                    */
#define SPI_CI_RXFERR_SHIFT                      6                                                   /*!< SPI0_CI: RXFERR Position                */
#define SPI_CI_TXFERR_MASK                       (0x01UL << SPI_CI_TXFERR_SHIFT)                     /*!< SPI0_CI: TXFERR Mask                    */
#define SPI_CI_TXFERR_SHIFT                      7                                                   /*!< SPI0_CI: TXFERR Position                */
/* ------- C3 Bit Fields                            ------ */
#define SPI_C3_FIFOMODE_MASK                     (0x01UL << SPI_C3_FIFOMODE_SHIFT)                   /*!< SPI0_C3: FIFOMODE Mask                  */
#define SPI_C3_FIFOMODE_SHIFT                    0                                                   /*!< SPI0_C3: FIFOMODE Position              */
#define SPI_C3_RNFULLIEN_MASK                    (0x01UL << SPI_C3_RNFULLIEN_SHIFT)                  /*!< SPI0_C3: RNFULLIEN Mask                 */
#define SPI_C3_RNFULLIEN_SHIFT                   1                                                   /*!< SPI0_C3: RNFULLIEN Position             */
#define SPI_C3_TNEARIEN_MASK                     (0x01UL << SPI_C3_TNEARIEN_SHIFT)                   /*!< SPI0_C3: TNEARIEN Mask                  */
#define SPI_C3_TNEARIEN_SHIFT                    2                                                   /*!< SPI0_C3: TNEARIEN Position              */
#define SPI_C3_INTCLR_MASK                       (0x01UL << SPI_C3_INTCLR_SHIFT)                     /*!< SPI0_C3: INTCLR Mask                    */
#define SPI_C3_INTCLR_SHIFT                      3                                                   /*!< SPI0_C3: INTCLR Position                */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x01UL << SPI_C3_RNFULLF_MARK_SHIFT)               /*!< SPI0_C3: RNFULLF_MARK Mask              */
#define SPI_C3_RNFULLF_MARK_SHIFT                4                                                   /*!< SPI0_C3: RNFULLF_MARK Position          */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x01UL << SPI_C3_TNEAREF_MARK_SHIFT)               /*!< SPI0_C3: TNEAREF_MARK Mask              */
#define SPI_C3_TNEAREF_MARK_SHIFT                5                                                   /*!< SPI0_C3: TNEAREF_MARK Position          */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x40075000UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
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
 * @brief Serial Peripheral Interface
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x40076000UL //!< Peripheral base address
#define SPI1                           ((SPI_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TMR_Peripheral_access_layer_GROUP TMR Peripheral Access Layer
* @brief C Struct for TMR
* @{
*/

/* ================================================================================ */
/* ================           TMR0 (file:TMR0_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Quad Timer
 */
/**
* @addtogroup TMR_structs_GROUP TMR struct
* @brief Struct for TMR
* @{
*/
typedef struct {                                /*       TMR0 Structure                                               */
   __IO uint16_t  COMP1;                        /**< 0000: Timer Channel Compare Register 1                             */
   __IO uint16_t  COMP2;                        /**< 0002: Timer Channel Compare Register 2                             */
   __IO uint16_t  CAPT;                         /**< 0004: Timer Channel Capture Register                               */
   __IO uint16_t  LOAD;                         /**< 0006: Timer Channel Load Register                                  */
   __IO uint16_t  HOLD;                         /**< 0008: Timer Channel Hold Register                                  */
   __IO uint16_t  CNTR;                         /**< 000A: Timer Channel Counter Register                               */
   __IO uint16_t  CTRL;                         /**< 000C: Timer Channel Control Register                               */
   __IO uint16_t  SCTRL;                        /**< 000E: Timer Channel Status and Control Register                    */
   __IO uint16_t  CMPLD1;                       /**< 0010: Timer Channel Comparator Load Register 1                     */
   __IO uint16_t  CMPLD2;                       /**< 0012: Timer Channel Comparator Load Register 2                     */
   __IO uint16_t  CSCTRL;                       /**< 0014: Timer Channel Comparator Status and Control Register         */
   __IO uint16_t  FILT;                         /**< 0016: Timer Channel Input Filter Register                          */
   __I  uint16_t  RESERVED0[3];                
   __IO uint16_t  ENBL;                         /**< 001E: Timer Channel Enable Register                                */
} TMR_Type;

/**
 * @} */ /* End group TMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TMR0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TMR_Register_Masks_GROUP TMR Register Masks
* @brief Register Masks for TMR
* @{
*/
/* ------- COMP Bit Fields                          ------ */
#define TMR0_COMP_COMPARISON_1_MASK              (0xFFFFUL << TMR0_COMP_COMPARISON_1_SHIFT)          /*!< TMR0_COMP: COMPARISON_1 Mask            */
#define TMR0_COMP_COMPARISON_1_SHIFT             0                                                   /*!< TMR0_COMP: COMPARISON_1 Position        */
#define TMR0_COMP_COMPARISON_1(x)                (((uint16_t)(((uint16_t)(x))<<TMR0_COMP_COMPARISON_1_SHIFT))&TMR0_COMP_COMPARISON_1_MASK) /*!< TMR0_COMP                               */
/* ------- CAPT Bit Fields                          ------ */
#define TMR0_CAPT_CAPTURE_MASK                   (0xFFFFUL << TMR0_CAPT_CAPTURE_SHIFT)               /*!< TMR0_CAPT: CAPTURE Mask                 */
#define TMR0_CAPT_CAPTURE_SHIFT                  0                                                   /*!< TMR0_CAPT: CAPTURE Position             */
#define TMR0_CAPT_CAPTURE(x)                     (((uint16_t)(((uint16_t)(x))<<TMR0_CAPT_CAPTURE_SHIFT))&TMR0_CAPT_CAPTURE_MASK) /*!< TMR0_CAPT                               */
/* ------- LOAD Bit Fields                          ------ */
#define TMR0_LOAD_LOAD_MASK                      (0xFFFFUL << TMR0_LOAD_LOAD_SHIFT)                  /*!< TMR0_LOAD: LOAD Mask                    */
#define TMR0_LOAD_LOAD_SHIFT                     0                                                   /*!< TMR0_LOAD: LOAD Position                */
#define TMR0_LOAD_LOAD(x)                        (((uint16_t)(((uint16_t)(x))<<TMR0_LOAD_LOAD_SHIFT))&TMR0_LOAD_LOAD_MASK) /*!< TMR0_LOAD                               */
/* ------- HOLD Bit Fields                          ------ */
#define TMR0_HOLD_HOLD_MASK                      (0xFFFFUL << TMR0_HOLD_HOLD_SHIFT)                  /*!< TMR0_HOLD: HOLD Mask                    */
#define TMR0_HOLD_HOLD_SHIFT                     0                                                   /*!< TMR0_HOLD: HOLD Position                */
#define TMR0_HOLD_HOLD(x)                        (((uint16_t)(((uint16_t)(x))<<TMR0_HOLD_HOLD_SHIFT))&TMR0_HOLD_HOLD_MASK) /*!< TMR0_HOLD                               */
/* ------- CNTR Bit Fields                          ------ */
#define TMR0_CNTR_COUNTER_MASK                   (0xFFFFUL << TMR0_CNTR_COUNTER_SHIFT)               /*!< TMR0_CNTR: COUNTER Mask                 */
#define TMR0_CNTR_COUNTER_SHIFT                  0                                                   /*!< TMR0_CNTR: COUNTER Position             */
#define TMR0_CNTR_COUNTER(x)                     (((uint16_t)(((uint16_t)(x))<<TMR0_CNTR_COUNTER_SHIFT))&TMR0_CNTR_COUNTER_MASK) /*!< TMR0_CNTR                               */
/* ------- CTRL Bit Fields                          ------ */
#define TMR0_CTRL_OUTMODE_MASK                   (0x07UL << TMR0_CTRL_OUTMODE_SHIFT)                 /*!< TMR0_CTRL: OUTMODE Mask                 */
#define TMR0_CTRL_OUTMODE_SHIFT                  0                                                   /*!< TMR0_CTRL: OUTMODE Position             */
#define TMR0_CTRL_OUTMODE(x)                     (((uint16_t)(((uint16_t)(x))<<TMR0_CTRL_OUTMODE_SHIFT))&TMR0_CTRL_OUTMODE_MASK) /*!< TMR0_CTRL                               */
#define TMR0_CTRL_COINIT_MASK                    (0x01UL << TMR0_CTRL_COINIT_SHIFT)                  /*!< TMR0_CTRL: COINIT Mask                  */
#define TMR0_CTRL_COINIT_SHIFT                   3                                                   /*!< TMR0_CTRL: COINIT Position              */
#define TMR0_CTRL_DIR_MASK                       (0x01UL << TMR0_CTRL_DIR_SHIFT)                     /*!< TMR0_CTRL: DIR Mask                     */
#define TMR0_CTRL_DIR_SHIFT                      4                                                   /*!< TMR0_CTRL: DIR Position                 */
#define TMR0_CTRL_LENGTH_MASK                    (0x01UL << TMR0_CTRL_LENGTH_SHIFT)                  /*!< TMR0_CTRL: LENGTH Mask                  */
#define TMR0_CTRL_LENGTH_SHIFT                   5                                                   /*!< TMR0_CTRL: LENGTH Position              */
#define TMR0_CTRL_ONCE_MASK                      (0x01UL << TMR0_CTRL_ONCE_SHIFT)                    /*!< TMR0_CTRL: ONCE Mask                    */
#define TMR0_CTRL_ONCE_SHIFT                     6                                                   /*!< TMR0_CTRL: ONCE Position                */
#define TMR0_CTRL_SCS_MASK                       (0x03UL << TMR0_CTRL_SCS_SHIFT)                     /*!< TMR0_CTRL: SCS Mask                     */
#define TMR0_CTRL_SCS_SHIFT                      7                                                   /*!< TMR0_CTRL: SCS Position                 */
#define TMR0_CTRL_SCS(x)                         (((uint16_t)(((uint16_t)(x))<<TMR0_CTRL_SCS_SHIFT))&TMR0_CTRL_SCS_MASK) /*!< TMR0_CTRL                               */
#define TMR0_CTRL_PCS_MASK                       (0x0FUL << TMR0_CTRL_PCS_SHIFT)                     /*!< TMR0_CTRL: PCS Mask                     */
#define TMR0_CTRL_PCS_SHIFT                      9                                                   /*!< TMR0_CTRL: PCS Position                 */
#define TMR0_CTRL_PCS(x)                         (((uint16_t)(((uint16_t)(x))<<TMR0_CTRL_PCS_SHIFT))&TMR0_CTRL_PCS_MASK) /*!< TMR0_CTRL                               */
#define TMR0_CTRL_CM_MASK                        (0x07UL << TMR0_CTRL_CM_SHIFT)                      /*!< TMR0_CTRL: CM Mask                      */
#define TMR0_CTRL_CM_SHIFT                       13                                                  /*!< TMR0_CTRL: CM Position                  */
#define TMR0_CTRL_CM(x)                          (((uint16_t)(((uint16_t)(x))<<TMR0_CTRL_CM_SHIFT))&TMR0_CTRL_CM_MASK) /*!< TMR0_CTRL                               */
/* ------- SCTRL Bit Fields                         ------ */
#define TMR0_SCTRL_OEN_MASK                      (0x01UL << TMR0_SCTRL_OEN_SHIFT)                    /*!< TMR0_SCTRL: OEN Mask                    */
#define TMR0_SCTRL_OEN_SHIFT                     0                                                   /*!< TMR0_SCTRL: OEN Position                */
#define TMR0_SCTRL_OPS_MASK                      (0x01UL << TMR0_SCTRL_OPS_SHIFT)                    /*!< TMR0_SCTRL: OPS Mask                    */
#define TMR0_SCTRL_OPS_SHIFT                     1                                                   /*!< TMR0_SCTRL: OPS Position                */
#define TMR0_SCTRL_FORCE_MASK                    (0x01UL << TMR0_SCTRL_FORCE_SHIFT)                  /*!< TMR0_SCTRL: FORCE Mask                  */
#define TMR0_SCTRL_FORCE_SHIFT                   2                                                   /*!< TMR0_SCTRL: FORCE Position              */
#define TMR0_SCTRL_VAL_MASK                      (0x01UL << TMR0_SCTRL_VAL_SHIFT)                    /*!< TMR0_SCTRL: VAL Mask                    */
#define TMR0_SCTRL_VAL_SHIFT                     3                                                   /*!< TMR0_SCTRL: VAL Position                */
#define TMR0_SCTRL_EEOF_MASK                     (0x01UL << TMR0_SCTRL_EEOF_SHIFT)                   /*!< TMR0_SCTRL: EEOF Mask                   */
#define TMR0_SCTRL_EEOF_SHIFT                    4                                                   /*!< TMR0_SCTRL: EEOF Position               */
#define TMR0_SCTRL_MSTR_MASK                     (0x01UL << TMR0_SCTRL_MSTR_SHIFT)                   /*!< TMR0_SCTRL: MSTR Mask                   */
#define TMR0_SCTRL_MSTR_SHIFT                    5                                                   /*!< TMR0_SCTRL: MSTR Position               */
#define TMR0_SCTRL_CAPTURE_MODE_MASK             (0x03UL << TMR0_SCTRL_CAPTURE_MODE_SHIFT)           /*!< TMR0_SCTRL: CAPTURE_MODE Mask           */
#define TMR0_SCTRL_CAPTURE_MODE_SHIFT            6                                                   /*!< TMR0_SCTRL: CAPTURE_MODE Position       */
#define TMR0_SCTRL_CAPTURE_MODE(x)               (((uint16_t)(((uint16_t)(x))<<TMR0_SCTRL_CAPTURE_MODE_SHIFT))&TMR0_SCTRL_CAPTURE_MODE_MASK) /*!< TMR0_SCTRL                              */
#define TMR0_SCTRL_INPUT_MASK                    (0x01UL << TMR0_SCTRL_INPUT_SHIFT)                  /*!< TMR0_SCTRL: INPUT Mask                  */
#define TMR0_SCTRL_INPUT_SHIFT                   8                                                   /*!< TMR0_SCTRL: INPUT Position              */
#define TMR0_SCTRL_IPS_MASK                      (0x01UL << TMR0_SCTRL_IPS_SHIFT)                    /*!< TMR0_SCTRL: IPS Mask                    */
#define TMR0_SCTRL_IPS_SHIFT                     9                                                   /*!< TMR0_SCTRL: IPS Position                */
#define TMR0_SCTRL_IEFIE_MASK                    (0x01UL << TMR0_SCTRL_IEFIE_SHIFT)                  /*!< TMR0_SCTRL: IEFIE Mask                  */
#define TMR0_SCTRL_IEFIE_SHIFT                   10                                                  /*!< TMR0_SCTRL: IEFIE Position              */
#define TMR0_SCTRL_IEF_MASK                      (0x01UL << TMR0_SCTRL_IEF_SHIFT)                    /*!< TMR0_SCTRL: IEF Mask                    */
#define TMR0_SCTRL_IEF_SHIFT                     11                                                  /*!< TMR0_SCTRL: IEF Position                */
#define TMR0_SCTRL_TOFIE_MASK                    (0x01UL << TMR0_SCTRL_TOFIE_SHIFT)                  /*!< TMR0_SCTRL: TOFIE Mask                  */
#define TMR0_SCTRL_TOFIE_SHIFT                   12                                                  /*!< TMR0_SCTRL: TOFIE Position              */
#define TMR0_SCTRL_TOF_MASK                      (0x01UL << TMR0_SCTRL_TOF_SHIFT)                    /*!< TMR0_SCTRL: TOF Mask                    */
#define TMR0_SCTRL_TOF_SHIFT                     13                                                  /*!< TMR0_SCTRL: TOF Position                */
#define TMR0_SCTRL_TCFIE_MASK                    (0x01UL << TMR0_SCTRL_TCFIE_SHIFT)                  /*!< TMR0_SCTRL: TCFIE Mask                  */
#define TMR0_SCTRL_TCFIE_SHIFT                   14                                                  /*!< TMR0_SCTRL: TCFIE Position              */
#define TMR0_SCTRL_TCF_MASK                      (0x01UL << TMR0_SCTRL_TCF_SHIFT)                    /*!< TMR0_SCTRL: TCF Mask                    */
#define TMR0_SCTRL_TCF_SHIFT                     15                                                  /*!< TMR0_SCTRL: TCF Position                */
/* ------- CMPLD Bit Fields                         ------ */
#define TMR0_CMPLD_COMPARATOR_LOAD_1_MASK        (0xFFFFUL << TMR0_CMPLD_COMPARATOR_LOAD_1_SHIFT)    /*!< TMR0_CMPLD: COMPARATOR_LOAD_1 Mask      */
#define TMR0_CMPLD_COMPARATOR_LOAD_1_SHIFT       0                                                   /*!< TMR0_CMPLD: COMPARATOR_LOAD_1 Position  */
#define TMR0_CMPLD_COMPARATOR_LOAD_1(x)          (((uint16_t)(((uint16_t)(x))<<TMR0_CMPLD_COMPARATOR_LOAD_1_SHIFT))&TMR0_CMPLD_COMPARATOR_LOAD_1_MASK) /*!< TMR0_CMPLD                              */
/* ------- CSCTRL Bit Fields                        ------ */
#define TMR0_CSCTRL_CL1_MASK                     (0x03UL << TMR0_CSCTRL_CL1_SHIFT)                   /*!< TMR0_CSCTRL: CL1 Mask                   */
#define TMR0_CSCTRL_CL1_SHIFT                    0                                                   /*!< TMR0_CSCTRL: CL1 Position               */
#define TMR0_CSCTRL_CL1(x)                       (((uint16_t)(((uint16_t)(x))<<TMR0_CSCTRL_CL1_SHIFT))&TMR0_CSCTRL_CL1_MASK) /*!< TMR0_CSCTRL                             */
#define TMR0_CSCTRL_CL2_MASK                     (0x03UL << TMR0_CSCTRL_CL2_SHIFT)                   /*!< TMR0_CSCTRL: CL2 Mask                   */
#define TMR0_CSCTRL_CL2_SHIFT                    2                                                   /*!< TMR0_CSCTRL: CL2 Position               */
#define TMR0_CSCTRL_CL2(x)                       (((uint16_t)(((uint16_t)(x))<<TMR0_CSCTRL_CL2_SHIFT))&TMR0_CSCTRL_CL2_MASK) /*!< TMR0_CSCTRL                             */
#define TMR0_CSCTRL_TCF1_MASK                    (0x01UL << TMR0_CSCTRL_TCF1_SHIFT)                  /*!< TMR0_CSCTRL: TCF1 Mask                  */
#define TMR0_CSCTRL_TCF1_SHIFT                   4                                                   /*!< TMR0_CSCTRL: TCF1 Position              */
#define TMR0_CSCTRL_TCF2_MASK                    (0x01UL << TMR0_CSCTRL_TCF2_SHIFT)                  /*!< TMR0_CSCTRL: TCF2 Mask                  */
#define TMR0_CSCTRL_TCF2_SHIFT                   5                                                   /*!< TMR0_CSCTRL: TCF2 Position              */
#define TMR0_CSCTRL_TCF1EN_MASK                  (0x01UL << TMR0_CSCTRL_TCF1EN_SHIFT)                /*!< TMR0_CSCTRL: TCF1EN Mask                */
#define TMR0_CSCTRL_TCF1EN_SHIFT                 6                                                   /*!< TMR0_CSCTRL: TCF1EN Position            */
#define TMR0_CSCTRL_TCF2EN_MASK                  (0x01UL << TMR0_CSCTRL_TCF2EN_SHIFT)                /*!< TMR0_CSCTRL: TCF2EN Mask                */
#define TMR0_CSCTRL_TCF2EN_SHIFT                 7                                                   /*!< TMR0_CSCTRL: TCF2EN Position            */
#define TMR0_CSCTRL_OFLAG_MASK                   (0x01UL << TMR0_CSCTRL_OFLAG_SHIFT)                 /*!< TMR0_CSCTRL: OFLAG Mask                 */
#define TMR0_CSCTRL_OFLAG_SHIFT                  8                                                   /*!< TMR0_CSCTRL: OFLAG Position             */
#define TMR0_CSCTRL_UP_MASK                      (0x01UL << TMR0_CSCTRL_UP_SHIFT)                    /*!< TMR0_CSCTRL: UP Mask                    */
#define TMR0_CSCTRL_UP_SHIFT                     9                                                   /*!< TMR0_CSCTRL: UP Position                */
#define TMR0_CSCTRL_TCI_MASK                     (0x01UL << TMR0_CSCTRL_TCI_SHIFT)                   /*!< TMR0_CSCTRL: TCI Mask                   */
#define TMR0_CSCTRL_TCI_SHIFT                    10                                                  /*!< TMR0_CSCTRL: TCI Position               */
#define TMR0_CSCTRL_ROC_MASK                     (0x01UL << TMR0_CSCTRL_ROC_SHIFT)                   /*!< TMR0_CSCTRL: ROC Mask                   */
#define TMR0_CSCTRL_ROC_SHIFT                    11                                                  /*!< TMR0_CSCTRL: ROC Position               */
#define TMR0_CSCTRL_ALT_LOAD_MASK                (0x01UL << TMR0_CSCTRL_ALT_LOAD_SHIFT)              /*!< TMR0_CSCTRL: ALT_LOAD Mask              */
#define TMR0_CSCTRL_ALT_LOAD_SHIFT               12                                                  /*!< TMR0_CSCTRL: ALT_LOAD Position          */
#define TMR0_CSCTRL_FAULT_MASK                   (0x01UL << TMR0_CSCTRL_FAULT_SHIFT)                 /*!< TMR0_CSCTRL: FAULT Mask                 */
#define TMR0_CSCTRL_FAULT_SHIFT                  13                                                  /*!< TMR0_CSCTRL: FAULT Position             */
#define TMR0_CSCTRL_DBG_EN_MASK                  (0x03UL << TMR0_CSCTRL_DBG_EN_SHIFT)                /*!< TMR0_CSCTRL: DBG_EN Mask                */
#define TMR0_CSCTRL_DBG_EN_SHIFT                 14                                                  /*!< TMR0_CSCTRL: DBG_EN Position            */
#define TMR0_CSCTRL_DBG_EN(x)                    (((uint16_t)(((uint16_t)(x))<<TMR0_CSCTRL_DBG_EN_SHIFT))&TMR0_CSCTRL_DBG_EN_MASK) /*!< TMR0_CSCTRL                             */
/* ------- FILT Bit Fields                          ------ */
#define TMR0_FILT_FILT_PER_MASK                  (0xFFUL << TMR0_FILT_FILT_PER_SHIFT)                /*!< TMR0_FILT: FILT_PER Mask                */
#define TMR0_FILT_FILT_PER_SHIFT                 0                                                   /*!< TMR0_FILT: FILT_PER Position            */
#define TMR0_FILT_FILT_PER(x)                    (((uint16_t)(((uint16_t)(x))<<TMR0_FILT_FILT_PER_SHIFT))&TMR0_FILT_FILT_PER_MASK) /*!< TMR0_FILT                               */
#define TMR0_FILT_FILT_CNT_MASK                  (0x07UL << TMR0_FILT_FILT_CNT_SHIFT)                /*!< TMR0_FILT: FILT_CNT Mask                */
#define TMR0_FILT_FILT_CNT_SHIFT                 8                                                   /*!< TMR0_FILT: FILT_CNT Position            */
#define TMR0_FILT_FILT_CNT(x)                    (((uint16_t)(((uint16_t)(x))<<TMR0_FILT_FILT_CNT_SHIFT))&TMR0_FILT_FILT_CNT_MASK) /*!< TMR0_FILT                               */
/* ------- ENBL Bit Fields                          ------ */
#define TMR0_ENBL_ENBL_MASK                      (0x0FUL << TMR0_ENBL_ENBL_SHIFT)                    /*!< TMR0_ENBL: ENBL Mask                    */
#define TMR0_ENBL_ENBL_SHIFT                     0                                                   /*!< TMR0_ENBL: ENBL Position                */
#define TMR0_ENBL_ENBL(x)                        (((uint16_t)(((uint16_t)(x))<<TMR0_ENBL_ENBL_SHIFT))&TMR0_ENBL_ENBL_MASK) /*!< TMR0_ENBL                               */
/**
 * @} */ /* End group TMR_Register_Masks_GROUP 
 */

/* TMR0 - Peripheral instance base addresses */
#define TMR0_BasePtr                   0x40057000UL //!< Peripheral base address
#define TMR0                           ((TMR_Type *) TMR0_BasePtr) //!< Freescale base pointer
#define TMR0_BASE_PTR                  (TMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group TMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TMR_Peripheral_access_layer_GROUP TMR Peripheral Access Layer
* @brief C Struct for TMR
* @{
*/

/* ================================================================================ */
/* ================           TMR1 (file:TMR1_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Quad Timer
 */
/**
* @addtogroup TMR_structs_GROUP TMR struct
* @brief Struct for TMR
* @{
*/
typedef struct {                                /*       TMR1 Structure                                               */
   __IO uint16_t  COMP1;                        /**< 0000: Timer Channel Compare Register 1                             */
   __IO uint16_t  COMP2;                        /**< 0002: Timer Channel Compare Register 2                             */
   __IO uint16_t  CAPT;                         /**< 0004: Timer Channel Capture Register                               */
   __IO uint16_t  LOAD;                         /**< 0006: Timer Channel Load Register                                  */
   __IO uint16_t  HOLD;                         /**< 0008: Timer Channel Hold Register                                  */
   __IO uint16_t  CNTR;                         /**< 000A: Timer Channel Counter Register                               */
   __IO uint16_t  CTRL;                         /**< 000C: Timer Channel Control Register                               */
   __IO uint16_t  SCTRL;                        /**< 000E: Timer Channel Status and Control Register                    */
   __IO uint16_t  CMPLD1;                       /**< 0010: Timer Channel Comparator Load Register 1                     */
   __IO uint16_t  CMPLD2;                       /**< 0012: Timer Channel Comparator Load Register 2                     */
   __IO uint16_t  CSCTRL;                       /**< 0014: Timer Channel Comparator Status and Control Register         */
   __IO uint16_t  FILT;                         /**< 0016: Timer Channel Input Filter Register                          */
} TMR1_Type;

/**
 * @} */ /* End group TMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TMR1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TMR_Register_Masks_GROUP TMR Register Masks
* @brief Register Masks for TMR
* @{
*/
/* ------- COMP Bit Fields                          ------ */
#define TMR1_COMP_COMPARISON_1_MASK              (0xFFFFUL << TMR1_COMP_COMPARISON_1_SHIFT)          /*!< TMR1_COMP: COMPARISON_1 Mask            */
#define TMR1_COMP_COMPARISON_1_SHIFT             0                                                   /*!< TMR1_COMP: COMPARISON_1 Position        */
#define TMR1_COMP_COMPARISON_1(x)                (((uint16_t)(((uint16_t)(x))<<TMR1_COMP_COMPARISON_1_SHIFT))&TMR1_COMP_COMPARISON_1_MASK) /*!< TMR1_COMP                               */
/* ------- CAPT Bit Fields                          ------ */
#define TMR1_CAPT_CAPTURE_MASK                   (0xFFFFUL << TMR1_CAPT_CAPTURE_SHIFT)               /*!< TMR1_CAPT: CAPTURE Mask                 */
#define TMR1_CAPT_CAPTURE_SHIFT                  0                                                   /*!< TMR1_CAPT: CAPTURE Position             */
#define TMR1_CAPT_CAPTURE(x)                     (((uint16_t)(((uint16_t)(x))<<TMR1_CAPT_CAPTURE_SHIFT))&TMR1_CAPT_CAPTURE_MASK) /*!< TMR1_CAPT                               */
/* ------- LOAD Bit Fields                          ------ */
#define TMR1_LOAD_LOAD_MASK                      (0xFFFFUL << TMR1_LOAD_LOAD_SHIFT)                  /*!< TMR1_LOAD: LOAD Mask                    */
#define TMR1_LOAD_LOAD_SHIFT                     0                                                   /*!< TMR1_LOAD: LOAD Position                */
#define TMR1_LOAD_LOAD(x)                        (((uint16_t)(((uint16_t)(x))<<TMR1_LOAD_LOAD_SHIFT))&TMR1_LOAD_LOAD_MASK) /*!< TMR1_LOAD                               */
/* ------- HOLD Bit Fields                          ------ */
#define TMR1_HOLD_HOLD_MASK                      (0xFFFFUL << TMR1_HOLD_HOLD_SHIFT)                  /*!< TMR1_HOLD: HOLD Mask                    */
#define TMR1_HOLD_HOLD_SHIFT                     0                                                   /*!< TMR1_HOLD: HOLD Position                */
#define TMR1_HOLD_HOLD(x)                        (((uint16_t)(((uint16_t)(x))<<TMR1_HOLD_HOLD_SHIFT))&TMR1_HOLD_HOLD_MASK) /*!< TMR1_HOLD                               */
/* ------- CNTR Bit Fields                          ------ */
#define TMR1_CNTR_COUNTER_MASK                   (0xFFFFUL << TMR1_CNTR_COUNTER_SHIFT)               /*!< TMR1_CNTR: COUNTER Mask                 */
#define TMR1_CNTR_COUNTER_SHIFT                  0                                                   /*!< TMR1_CNTR: COUNTER Position             */
#define TMR1_CNTR_COUNTER(x)                     (((uint16_t)(((uint16_t)(x))<<TMR1_CNTR_COUNTER_SHIFT))&TMR1_CNTR_COUNTER_MASK) /*!< TMR1_CNTR                               */
/* ------- CTRL Bit Fields                          ------ */
#define TMR1_CTRL_OUTMODE_MASK                   (0x07UL << TMR1_CTRL_OUTMODE_SHIFT)                 /*!< TMR1_CTRL: OUTMODE Mask                 */
#define TMR1_CTRL_OUTMODE_SHIFT                  0                                                   /*!< TMR1_CTRL: OUTMODE Position             */
#define TMR1_CTRL_OUTMODE(x)                     (((uint16_t)(((uint16_t)(x))<<TMR1_CTRL_OUTMODE_SHIFT))&TMR1_CTRL_OUTMODE_MASK) /*!< TMR1_CTRL                               */
#define TMR1_CTRL_COINIT_MASK                    (0x01UL << TMR1_CTRL_COINIT_SHIFT)                  /*!< TMR1_CTRL: COINIT Mask                  */
#define TMR1_CTRL_COINIT_SHIFT                   3                                                   /*!< TMR1_CTRL: COINIT Position              */
#define TMR1_CTRL_DIR_MASK                       (0x01UL << TMR1_CTRL_DIR_SHIFT)                     /*!< TMR1_CTRL: DIR Mask                     */
#define TMR1_CTRL_DIR_SHIFT                      4                                                   /*!< TMR1_CTRL: DIR Position                 */
#define TMR1_CTRL_LENGTH_MASK                    (0x01UL << TMR1_CTRL_LENGTH_SHIFT)                  /*!< TMR1_CTRL: LENGTH Mask                  */
#define TMR1_CTRL_LENGTH_SHIFT                   5                                                   /*!< TMR1_CTRL: LENGTH Position              */
#define TMR1_CTRL_ONCE_MASK                      (0x01UL << TMR1_CTRL_ONCE_SHIFT)                    /*!< TMR1_CTRL: ONCE Mask                    */
#define TMR1_CTRL_ONCE_SHIFT                     6                                                   /*!< TMR1_CTRL: ONCE Position                */
#define TMR1_CTRL_SCS_MASK                       (0x03UL << TMR1_CTRL_SCS_SHIFT)                     /*!< TMR1_CTRL: SCS Mask                     */
#define TMR1_CTRL_SCS_SHIFT                      7                                                   /*!< TMR1_CTRL: SCS Position                 */
#define TMR1_CTRL_SCS(x)                         (((uint16_t)(((uint16_t)(x))<<TMR1_CTRL_SCS_SHIFT))&TMR1_CTRL_SCS_MASK) /*!< TMR1_CTRL                               */
#define TMR1_CTRL_PCS_MASK                       (0x0FUL << TMR1_CTRL_PCS_SHIFT)                     /*!< TMR1_CTRL: PCS Mask                     */
#define TMR1_CTRL_PCS_SHIFT                      9                                                   /*!< TMR1_CTRL: PCS Position                 */
#define TMR1_CTRL_PCS(x)                         (((uint16_t)(((uint16_t)(x))<<TMR1_CTRL_PCS_SHIFT))&TMR1_CTRL_PCS_MASK) /*!< TMR1_CTRL                               */
#define TMR1_CTRL_CM_MASK                        (0x07UL << TMR1_CTRL_CM_SHIFT)                      /*!< TMR1_CTRL: CM Mask                      */
#define TMR1_CTRL_CM_SHIFT                       13                                                  /*!< TMR1_CTRL: CM Position                  */
#define TMR1_CTRL_CM(x)                          (((uint16_t)(((uint16_t)(x))<<TMR1_CTRL_CM_SHIFT))&TMR1_CTRL_CM_MASK) /*!< TMR1_CTRL                               */
/* ------- SCTRL Bit Fields                         ------ */
#define TMR1_SCTRL_OEN_MASK                      (0x01UL << TMR1_SCTRL_OEN_SHIFT)                    /*!< TMR1_SCTRL: OEN Mask                    */
#define TMR1_SCTRL_OEN_SHIFT                     0                                                   /*!< TMR1_SCTRL: OEN Position                */
#define TMR1_SCTRL_OPS_MASK                      (0x01UL << TMR1_SCTRL_OPS_SHIFT)                    /*!< TMR1_SCTRL: OPS Mask                    */
#define TMR1_SCTRL_OPS_SHIFT                     1                                                   /*!< TMR1_SCTRL: OPS Position                */
#define TMR1_SCTRL_FORCE_MASK                    (0x01UL << TMR1_SCTRL_FORCE_SHIFT)                  /*!< TMR1_SCTRL: FORCE Mask                  */
#define TMR1_SCTRL_FORCE_SHIFT                   2                                                   /*!< TMR1_SCTRL: FORCE Position              */
#define TMR1_SCTRL_VAL_MASK                      (0x01UL << TMR1_SCTRL_VAL_SHIFT)                    /*!< TMR1_SCTRL: VAL Mask                    */
#define TMR1_SCTRL_VAL_SHIFT                     3                                                   /*!< TMR1_SCTRL: VAL Position                */
#define TMR1_SCTRL_EEOF_MASK                     (0x01UL << TMR1_SCTRL_EEOF_SHIFT)                   /*!< TMR1_SCTRL: EEOF Mask                   */
#define TMR1_SCTRL_EEOF_SHIFT                    4                                                   /*!< TMR1_SCTRL: EEOF Position               */
#define TMR1_SCTRL_MSTR_MASK                     (0x01UL << TMR1_SCTRL_MSTR_SHIFT)                   /*!< TMR1_SCTRL: MSTR Mask                   */
#define TMR1_SCTRL_MSTR_SHIFT                    5                                                   /*!< TMR1_SCTRL: MSTR Position               */
#define TMR1_SCTRL_CAPTURE_MODE_MASK             (0x03UL << TMR1_SCTRL_CAPTURE_MODE_SHIFT)           /*!< TMR1_SCTRL: CAPTURE_MODE Mask           */
#define TMR1_SCTRL_CAPTURE_MODE_SHIFT            6                                                   /*!< TMR1_SCTRL: CAPTURE_MODE Position       */
#define TMR1_SCTRL_CAPTURE_MODE(x)               (((uint16_t)(((uint16_t)(x))<<TMR1_SCTRL_CAPTURE_MODE_SHIFT))&TMR1_SCTRL_CAPTURE_MODE_MASK) /*!< TMR1_SCTRL                              */
#define TMR1_SCTRL_INPUT_MASK                    (0x01UL << TMR1_SCTRL_INPUT_SHIFT)                  /*!< TMR1_SCTRL: INPUT Mask                  */
#define TMR1_SCTRL_INPUT_SHIFT                   8                                                   /*!< TMR1_SCTRL: INPUT Position              */
#define TMR1_SCTRL_IPS_MASK                      (0x01UL << TMR1_SCTRL_IPS_SHIFT)                    /*!< TMR1_SCTRL: IPS Mask                    */
#define TMR1_SCTRL_IPS_SHIFT                     9                                                   /*!< TMR1_SCTRL: IPS Position                */
#define TMR1_SCTRL_IEFIE_MASK                    (0x01UL << TMR1_SCTRL_IEFIE_SHIFT)                  /*!< TMR1_SCTRL: IEFIE Mask                  */
#define TMR1_SCTRL_IEFIE_SHIFT                   10                                                  /*!< TMR1_SCTRL: IEFIE Position              */
#define TMR1_SCTRL_IEF_MASK                      (0x01UL << TMR1_SCTRL_IEF_SHIFT)                    /*!< TMR1_SCTRL: IEF Mask                    */
#define TMR1_SCTRL_IEF_SHIFT                     11                                                  /*!< TMR1_SCTRL: IEF Position                */
#define TMR1_SCTRL_TOFIE_MASK                    (0x01UL << TMR1_SCTRL_TOFIE_SHIFT)                  /*!< TMR1_SCTRL: TOFIE Mask                  */
#define TMR1_SCTRL_TOFIE_SHIFT                   12                                                  /*!< TMR1_SCTRL: TOFIE Position              */
#define TMR1_SCTRL_TOF_MASK                      (0x01UL << TMR1_SCTRL_TOF_SHIFT)                    /*!< TMR1_SCTRL: TOF Mask                    */
#define TMR1_SCTRL_TOF_SHIFT                     13                                                  /*!< TMR1_SCTRL: TOF Position                */
#define TMR1_SCTRL_TCFIE_MASK                    (0x01UL << TMR1_SCTRL_TCFIE_SHIFT)                  /*!< TMR1_SCTRL: TCFIE Mask                  */
#define TMR1_SCTRL_TCFIE_SHIFT                   14                                                  /*!< TMR1_SCTRL: TCFIE Position              */
#define TMR1_SCTRL_TCF_MASK                      (0x01UL << TMR1_SCTRL_TCF_SHIFT)                    /*!< TMR1_SCTRL: TCF Mask                    */
#define TMR1_SCTRL_TCF_SHIFT                     15                                                  /*!< TMR1_SCTRL: TCF Position                */
/* ------- CMPLD Bit Fields                         ------ */
#define TMR1_CMPLD_COMPARATOR_LOAD_1_MASK        (0xFFFFUL << TMR1_CMPLD_COMPARATOR_LOAD_1_SHIFT)    /*!< TMR1_CMPLD: COMPARATOR_LOAD_1 Mask      */
#define TMR1_CMPLD_COMPARATOR_LOAD_1_SHIFT       0                                                   /*!< TMR1_CMPLD: COMPARATOR_LOAD_1 Position  */
#define TMR1_CMPLD_COMPARATOR_LOAD_1(x)          (((uint16_t)(((uint16_t)(x))<<TMR1_CMPLD_COMPARATOR_LOAD_1_SHIFT))&TMR1_CMPLD_COMPARATOR_LOAD_1_MASK) /*!< TMR1_CMPLD                              */
/* ------- CSCTRL Bit Fields                        ------ */
#define TMR1_CSCTRL_CL1_MASK                     (0x03UL << TMR1_CSCTRL_CL1_SHIFT)                   /*!< TMR1_CSCTRL: CL1 Mask                   */
#define TMR1_CSCTRL_CL1_SHIFT                    0                                                   /*!< TMR1_CSCTRL: CL1 Position               */
#define TMR1_CSCTRL_CL1(x)                       (((uint16_t)(((uint16_t)(x))<<TMR1_CSCTRL_CL1_SHIFT))&TMR1_CSCTRL_CL1_MASK) /*!< TMR1_CSCTRL                             */
#define TMR1_CSCTRL_CL2_MASK                     (0x03UL << TMR1_CSCTRL_CL2_SHIFT)                   /*!< TMR1_CSCTRL: CL2 Mask                   */
#define TMR1_CSCTRL_CL2_SHIFT                    2                                                   /*!< TMR1_CSCTRL: CL2 Position               */
#define TMR1_CSCTRL_CL2(x)                       (((uint16_t)(((uint16_t)(x))<<TMR1_CSCTRL_CL2_SHIFT))&TMR1_CSCTRL_CL2_MASK) /*!< TMR1_CSCTRL                             */
#define TMR1_CSCTRL_TCF1_MASK                    (0x01UL << TMR1_CSCTRL_TCF1_SHIFT)                  /*!< TMR1_CSCTRL: TCF1 Mask                  */
#define TMR1_CSCTRL_TCF1_SHIFT                   4                                                   /*!< TMR1_CSCTRL: TCF1 Position              */
#define TMR1_CSCTRL_TCF2_MASK                    (0x01UL << TMR1_CSCTRL_TCF2_SHIFT)                  /*!< TMR1_CSCTRL: TCF2 Mask                  */
#define TMR1_CSCTRL_TCF2_SHIFT                   5                                                   /*!< TMR1_CSCTRL: TCF2 Position              */
#define TMR1_CSCTRL_TCF1EN_MASK                  (0x01UL << TMR1_CSCTRL_TCF1EN_SHIFT)                /*!< TMR1_CSCTRL: TCF1EN Mask                */
#define TMR1_CSCTRL_TCF1EN_SHIFT                 6                                                   /*!< TMR1_CSCTRL: TCF1EN Position            */
#define TMR1_CSCTRL_TCF2EN_MASK                  (0x01UL << TMR1_CSCTRL_TCF2EN_SHIFT)                /*!< TMR1_CSCTRL: TCF2EN Mask                */
#define TMR1_CSCTRL_TCF2EN_SHIFT                 7                                                   /*!< TMR1_CSCTRL: TCF2EN Position            */
#define TMR1_CSCTRL_OFLAG_MASK                   (0x01UL << TMR1_CSCTRL_OFLAG_SHIFT)                 /*!< TMR1_CSCTRL: OFLAG Mask                 */
#define TMR1_CSCTRL_OFLAG_SHIFT                  8                                                   /*!< TMR1_CSCTRL: OFLAG Position             */
#define TMR1_CSCTRL_UP_MASK                      (0x01UL << TMR1_CSCTRL_UP_SHIFT)                    /*!< TMR1_CSCTRL: UP Mask                    */
#define TMR1_CSCTRL_UP_SHIFT                     9                                                   /*!< TMR1_CSCTRL: UP Position                */
#define TMR1_CSCTRL_TCI_MASK                     (0x01UL << TMR1_CSCTRL_TCI_SHIFT)                   /*!< TMR1_CSCTRL: TCI Mask                   */
#define TMR1_CSCTRL_TCI_SHIFT                    10                                                  /*!< TMR1_CSCTRL: TCI Position               */
#define TMR1_CSCTRL_ROC_MASK                     (0x01UL << TMR1_CSCTRL_ROC_SHIFT)                   /*!< TMR1_CSCTRL: ROC Mask                   */
#define TMR1_CSCTRL_ROC_SHIFT                    11                                                  /*!< TMR1_CSCTRL: ROC Position               */
#define TMR1_CSCTRL_ALT_LOAD_MASK                (0x01UL << TMR1_CSCTRL_ALT_LOAD_SHIFT)              /*!< TMR1_CSCTRL: ALT_LOAD Mask              */
#define TMR1_CSCTRL_ALT_LOAD_SHIFT               12                                                  /*!< TMR1_CSCTRL: ALT_LOAD Position          */
#define TMR1_CSCTRL_FAULT_MASK                   (0x01UL << TMR1_CSCTRL_FAULT_SHIFT)                 /*!< TMR1_CSCTRL: FAULT Mask                 */
#define TMR1_CSCTRL_FAULT_SHIFT                  13                                                  /*!< TMR1_CSCTRL: FAULT Position             */
#define TMR1_CSCTRL_DBG_EN_MASK                  (0x03UL << TMR1_CSCTRL_DBG_EN_SHIFT)                /*!< TMR1_CSCTRL: DBG_EN Mask                */
#define TMR1_CSCTRL_DBG_EN_SHIFT                 14                                                  /*!< TMR1_CSCTRL: DBG_EN Position            */
#define TMR1_CSCTRL_DBG_EN(x)                    (((uint16_t)(((uint16_t)(x))<<TMR1_CSCTRL_DBG_EN_SHIFT))&TMR1_CSCTRL_DBG_EN_MASK) /*!< TMR1_CSCTRL                             */
/* ------- FILT Bit Fields                          ------ */
#define TMR1_FILT_FILT_PER_MASK                  (0xFFUL << TMR1_FILT_FILT_PER_SHIFT)                /*!< TMR1_FILT: FILT_PER Mask                */
#define TMR1_FILT_FILT_PER_SHIFT                 0                                                   /*!< TMR1_FILT: FILT_PER Position            */
#define TMR1_FILT_FILT_PER(x)                    (((uint16_t)(((uint16_t)(x))<<TMR1_FILT_FILT_PER_SHIFT))&TMR1_FILT_FILT_PER_MASK) /*!< TMR1_FILT                               */
#define TMR1_FILT_FILT_CNT_MASK                  (0x07UL << TMR1_FILT_FILT_CNT_SHIFT)                /*!< TMR1_FILT: FILT_CNT Mask                */
#define TMR1_FILT_FILT_CNT_SHIFT                 8                                                   /*!< TMR1_FILT: FILT_CNT Position            */
#define TMR1_FILT_FILT_CNT(x)                    (((uint16_t)(((uint16_t)(x))<<TMR1_FILT_FILT_CNT_SHIFT))&TMR1_FILT_FILT_CNT_MASK) /*!< TMR1_FILT                               */
/**
 * @} */ /* End group TMR_Register_Masks_GROUP 
 */

/* TMR1 - Peripheral instance base addresses */
#define TMR1_BasePtr                   0x40058000UL //!< Peripheral base address
#define TMR1                           ((TMR1_Type *) TMR1_BasePtr) //!< Freescale base pointer
#define TMR1_BASE_PTR                  (TMR1) //!< Freescale style base pointer
/**
 * @} */ /* End group TMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TMR_Peripheral_access_layer_GROUP TMR Peripheral Access Layer
* @brief C Struct for TMR
* @{
*/

/* ================================================================================ */
/* ================           TMR2 (derived from TMR1)             ================ */
/* ================================================================================ */

/**
 * @brief Quad Timer
 */

/* TMR2 - Peripheral instance base addresses */
#define TMR2_BasePtr                   0x40059000UL //!< Peripheral base address
#define TMR2                           ((TMR1_Type *) TMR2_BasePtr) //!< Freescale base pointer
#define TMR2_BASE_PTR                  (TMR2) //!< Freescale style base pointer
/**
 * @} */ /* End group TMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TMR_Peripheral_access_layer_GROUP TMR Peripheral Access Layer
* @brief C Struct for TMR
* @{
*/

/* ================================================================================ */
/* ================           TMR3 (derived from TMR1)             ================ */
/* ================================================================================ */

/**
 * @brief Quad Timer
 */

/* TMR3 - Peripheral instance base addresses */
#define TMR3_BasePtr                   0x4005A000UL //!< Peripheral base address
#define TMR3                           ((TMR1_Type *) TMR3_BasePtr) //!< Freescale base pointer
#define TMR3_BASE_PTR                  (TMR3) //!< Freescale style base pointer
/**
 * @} */ /* End group TMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKM14ZA5)          ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
} UART1_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FUL << UART_BDH_SBR_SHIFT)                      /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       0                                                   /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x01UL << UART_BDH_RXEDGIE_SHIFT)                  /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   6                                                   /*!< UART0_BDH: RXEDGIE Position             */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFUL << UART_BDL_SBR_SHIFT)                      /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       0                                                   /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART0_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x01UL << UART_C1_PT_SHIFT)                        /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         0                                                   /*!< UART0_C1: PT Position                   */
#define UART_C1_PE_MASK                          (0x01UL << UART_C1_PE_SHIFT)                        /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         1                                                   /*!< UART0_C1: PE Position                   */
#define UART_C1_ILT_MASK                         (0x01UL << UART_C1_ILT_SHIFT)                       /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        2                                                   /*!< UART0_C1: ILT Position                  */
#define UART_C1_WAKE_MASK                        (0x01UL << UART_C1_WAKE_SHIFT)                      /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       3                                                   /*!< UART0_C1: WAKE Position                 */
#define UART_C1_M_MASK                           (0x01UL << UART_C1_M_SHIFT)                         /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          4                                                   /*!< UART0_C1: M Position                    */
#define UART_C1_RSRC_MASK                        (0x01UL << UART_C1_RSRC_SHIFT)                      /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       5                                                   /*!< UART0_C1: RSRC Position                 */
#define UART_C1_LOOPS_MASK                       (0x01UL << UART_C1_LOOPS_SHIFT)                     /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      7                                                   /*!< UART0_C1: LOOPS Position                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x01UL << UART_C2_SBK_SHIFT)                       /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        0                                                   /*!< UART0_C2: SBK Position                  */
#define UART_C2_RWU_MASK                         (0x01UL << UART_C2_RWU_SHIFT)                       /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        1                                                   /*!< UART0_C2: RWU Position                  */
#define UART_C2_RE_MASK                          (0x01UL << UART_C2_RE_SHIFT)                        /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         2                                                   /*!< UART0_C2: RE Position                   */
#define UART_C2_TE_MASK                          (0x01UL << UART_C2_TE_SHIFT)                        /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         3                                                   /*!< UART0_C2: TE Position                   */
#define UART_C2_ILIE_MASK                        (0x01UL << UART_C2_ILIE_SHIFT)                      /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       4                                                   /*!< UART0_C2: ILIE Position                 */
#define UART_C2_RIE_MASK                         (0x01UL << UART_C2_RIE_SHIFT)                       /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        5                                                   /*!< UART0_C2: RIE Position                  */
#define UART_C2_TCIE_MASK                        (0x01UL << UART_C2_TCIE_SHIFT)                      /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       6                                                   /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TIE_MASK                         (0x01UL << UART_C2_TIE_SHIFT)                       /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        7                                                   /*!< UART0_C2: TIE Position                  */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x01UL << UART_S1_PF_SHIFT)                        /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         0                                                   /*!< UART0_S1: PF Position                   */
#define UART_S1_FE_MASK                          (0x01UL << UART_S1_FE_SHIFT)                        /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         1                                                   /*!< UART0_S1: FE Position                   */
#define UART_S1_NF_MASK                          (0x01UL << UART_S1_NF_SHIFT)                        /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         2                                                   /*!< UART0_S1: NF Position                   */
#define UART_S1_OR_MASK                          (0x01UL << UART_S1_OR_SHIFT)                        /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         3                                                   /*!< UART0_S1: OR Position                   */
#define UART_S1_IDLE_MASK                        (0x01UL << UART_S1_IDLE_SHIFT)                      /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       4                                                   /*!< UART0_S1: IDLE Position                 */
#define UART_S1_RDRF_MASK                        (0x01UL << UART_S1_RDRF_SHIFT)                      /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       5                                                   /*!< UART0_S1: RDRF Position                 */
#define UART_S1_TC_MASK                          (0x01UL << UART_S1_TC_SHIFT)                        /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         6                                                   /*!< UART0_S1: TC Position                   */
#define UART_S1_TDRE_MASK                        (0x01UL << UART_S1_TDRE_SHIFT)                      /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       7                                                   /*!< UART0_S1: TDRE Position                 */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x01UL << UART_S2_RAF_SHIFT)                       /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        0                                                   /*!< UART0_S2: RAF Position                  */
#define UART_S2_BRK13_MASK                       (0x01UL << UART_S2_BRK13_SHIFT)                     /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      2                                                   /*!< UART0_S2: BRK13 Position                */
#define UART_S2_RWUID_MASK                       (0x01UL << UART_S2_RWUID_SHIFT)                     /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      3                                                   /*!< UART0_S2: RWUID Position                */
#define UART_S2_RXINV_MASK                       (0x01UL << UART_S2_RXINV_SHIFT)                     /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      4                                                   /*!< UART0_S2: RXINV Position                */
#define UART_S2_MSBF_MASK                        (0x01UL << UART_S2_MSBF_SHIFT)                      /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       5                                                   /*!< UART0_S2: MSBF Position                 */
#define UART_S2_RXEDGIF_MASK                     (0x01UL << UART_S2_RXEDGIF_SHIFT)                   /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    6                                                   /*!< UART0_S2: RXEDGIF Position              */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x01UL << UART_C3_PEIE_SHIFT)                      /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       0                                                   /*!< UART0_C3: PEIE Position                 */
#define UART_C3_FEIE_MASK                        (0x01UL << UART_C3_FEIE_SHIFT)                      /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       1                                                   /*!< UART0_C3: FEIE Position                 */
#define UART_C3_NEIE_MASK                        (0x01UL << UART_C3_NEIE_SHIFT)                      /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       2                                                   /*!< UART0_C3: NEIE Position                 */
#define UART_C3_ORIE_MASK                        (0x01UL << UART_C3_ORIE_SHIFT)                      /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       3                                                   /*!< UART0_C3: ORIE Position                 */
#define UART_C3_TXINV_MASK                       (0x01UL << UART_C3_TXINV_SHIFT)                     /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      4                                                   /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXDIR_MASK                       (0x01UL << UART_C3_TXDIR_SHIFT)                     /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      5                                                   /*!< UART0_C3: TXDIR Position                */
#define UART_C3_T8_MASK                          (0x01UL << UART_C3_T8_SHIFT)                        /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         6                                                   /*!< UART0_C3: T8 Position                   */
#define UART_C3_R8_MASK                          (0x01UL << UART_C3_R8_SHIFT)                        /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         7                                                   /*!< UART0_C3: R8 Position                   */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFUL << UART_D_RT_SHIFT)                         /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          0                                                   /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART0_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFUL << UART_MA_MA_SHIFT)                        /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         0                                                   /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART0_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FUL << UART_C4_BRFA_SHIFT)                      /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       0                                                   /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x01UL << UART_C4_M10_SHIFT)                       /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        5                                                   /*!< UART0_C4: M10 Position                  */
#define UART_C4_MAEN2_MASK                       (0x01UL << UART_C4_MAEN2_SHIFT)                     /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      6                                                   /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN1_MASK                       (0x01UL << UART_C4_MAEN1_SHIFT)                     /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      7                                                   /*!< UART0_C4: MAEN1 Position                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_RDMAS_MASK                       (0x01UL << UART_C5_RDMAS_SHIFT)                     /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      5                                                   /*!< UART0_C5: RDMAS Position                */
#define UART_C5_TDMAS_MASK                       (0x01UL << UART_C5_TDMAS_SHIFT)                     /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      7                                                   /*!< UART0_C5: TDMAS Position                */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x01UL << UART_ED_PARITYE_SHIFT)                   /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    6                                                   /*!< UART0_ED: PARITYE Position              */
#define UART_ED_NOISY_MASK                       (0x01UL << UART_ED_NOISY_SHIFT)                     /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      7                                                   /*!< UART0_ED: NOISY Position                */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x01UL << UART_MODEM_TXCTSE_SHIFT)                 /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  0                                                   /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXRTSE_MASK                   (0x01UL << UART_MODEM_TXRTSE_SHIFT)                 /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  1                                                   /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSPOL_MASK                 (0x01UL << UART_MODEM_TXRTSPOL_SHIFT)               /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                2                                                   /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_RXRTSE_MASK                   (0x01UL << UART_MODEM_RXRTSE_SHIFT)                 /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  3                                                   /*!< UART0_MODEM: RXRTSE Position            */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_RXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0                                                   /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x01UL << UART_PFIFO_RXFE_SHIFT)                   /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    3                                                   /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_TXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4                                                   /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x01UL << UART_PFIFO_TXFE_SHIFT)                   /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    7                                                   /*!< UART0_PFIFO: TXFE Position              */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x01UL << UART_CFIFO_RXUFE_SHIFT)                  /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   0                                                   /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_TXOFE_MASK                    (0x01UL << UART_CFIFO_TXOFE_SHIFT)                  /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   1                                                   /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_RXOFE_MASK                    (0x01UL << UART_CFIFO_RXOFE_SHIFT)                  /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   2                                                   /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x01UL << UART_CFIFO_RXFLUSH_SHIFT)                /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 6                                                   /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_TXFLUSH_MASK                  (0x01UL << UART_CFIFO_TXFLUSH_SHIFT)                /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 7                                                   /*!< UART0_CFIFO: TXFLUSH Position           */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x01UL << UART_SFIFO_RXUF_SHIFT)                   /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    0                                                   /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_TXOF_MASK                     (0x01UL << UART_SFIFO_TXOF_SHIFT)                   /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    1                                                   /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_RXOF_MASK                     (0x01UL << UART_SFIFO_RXOF_SHIFT)                   /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    2                                                   /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXEMPT_MASK                   (0x01UL << UART_SFIFO_RXEMPT_SHIFT)                 /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  6                                                   /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_TXEMPT_MASK                   (0x01UL << UART_SFIFO_TXEMPT_SHIFT)                 /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  7                                                   /*!< UART0_SFIFO: TXEMPT Position            */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFUL << UART_TWFIFO_TXWATER_SHIFT)               /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                0                                                   /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFUL << UART_TCFIFO_TXCOUNT_SHIFT)               /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                0                                                   /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFUL << UART_RWFIFO_RXWATER_SHIFT)               /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                0                                                   /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFUL << UART_RCFIFO_RXCOUNT_SHIFT)               /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                0                                                   /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART1_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART1 (file:UART1_MKM14ZA5_C7816)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART1 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816T0;                  /**< 001B: 7816 Wait Parameter Register                                 */
      __IO uint8_t   WP7816T1;                  /**< 001B: 7816 Wait Parameter Register                                 */
   };
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART1' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
/* ------- BDL Bit Fields                           ------ */
/* ------- C1 Bit Fields                            ------ */
/* ------- C2 Bit Fields                            ------ */
/* ------- S1 Bit Fields                            ------ */
/* ------- S2 Bit Fields                            ------ */
/* ------- C3 Bit Fields                            ------ */
/* ------- D Bit Fields                             ------ */
/* ------- MA Bit Fields                            ------ */
/* ------- C4 Bit Fields                            ------ */
/* ------- C5 Bit Fields                            ------ */
/* ------- ED Bit Fields                            ------ */
/* ------- MODEM Bit Fields                         ------ */
/* ------- PFIFO Bit Fields                         ------ */
/* ------- CFIFO Bit Fields                         ------ */
/* ------- SFIFO Bit Fields                         ------ */
/* ------- TWFIFO Bit Fields                        ------ */
/* ------- TCFIFO Bit Fields                        ------ */
/* ------- RWFIFO Bit Fields                        ------ */
/* ------- RCFIFO Bit Fields                        ------ */
/* ------- C7816 Bit Fields                         ------ */
#define UART_C7816_ISO_7816E_MASK                (0x01UL << UART_C7816_ISO_7816E_SHIFT)              /*!< UART1_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               0                                                   /*!< UART1_C7816: ISO_7816E Position         */
#define UART_C7816_TTYPE_MASK                    (0x01UL << UART_C7816_TTYPE_SHIFT)                  /*!< UART1_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   1                                                   /*!< UART1_C7816: TTYPE Position             */
#define UART_C7816_INIT_MASK                     (0x01UL << UART_C7816_INIT_SHIFT)                   /*!< UART1_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    2                                                   /*!< UART1_C7816: INIT Position              */
#define UART_C7816_ANACK_MASK                    (0x01UL << UART_C7816_ANACK_SHIFT)                  /*!< UART1_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   3                                                   /*!< UART1_C7816: ANACK Position             */
#define UART_C7816_ONACK_MASK                    (0x01UL << UART_C7816_ONACK_SHIFT)                  /*!< UART1_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   4                                                   /*!< UART1_C7816: ONACK Position             */
/* ------- IE7816 Bit Fields                        ------ */
#define UART_IE7816_RXTE_MASK                    (0x01UL << UART_IE7816_RXTE_SHIFT)                  /*!< UART1_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   0                                                   /*!< UART1_IE7816: RXTE Position             */
#define UART_IE7816_TXTE_MASK                    (0x01UL << UART_IE7816_TXTE_SHIFT)                  /*!< UART1_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   1                                                   /*!< UART1_IE7816: TXTE Position             */
#define UART_IE7816_GTVE_MASK                    (0x01UL << UART_IE7816_GTVE_SHIFT)                  /*!< UART1_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   2                                                   /*!< UART1_IE7816: GTVE Position             */
#define UART_IE7816_INITDE_MASK                  (0x01UL << UART_IE7816_INITDE_SHIFT)                /*!< UART1_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 4                                                   /*!< UART1_IE7816: INITDE Position           */
#define UART_IE7816_BWTE_MASK                    (0x01UL << UART_IE7816_BWTE_SHIFT)                  /*!< UART1_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   5                                                   /*!< UART1_IE7816: BWTE Position             */
#define UART_IE7816_CWTE_MASK                    (0x01UL << UART_IE7816_CWTE_SHIFT)                  /*!< UART1_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   6                                                   /*!< UART1_IE7816: CWTE Position             */
#define UART_IE7816_WTE_MASK                     (0x01UL << UART_IE7816_WTE_SHIFT)                   /*!< UART1_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    7                                                   /*!< UART1_IE7816: WTE Position              */
/* ------- IS7816 Bit Fields                        ------ */
#define UART_IS7816_RXT_MASK                     (0x01UL << UART_IS7816_RXT_SHIFT)                   /*!< UART1_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    0                                                   /*!< UART1_IS7816: RXT Position              */
#define UART_IS7816_TXT_MASK                     (0x01UL << UART_IS7816_TXT_SHIFT)                   /*!< UART1_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    1                                                   /*!< UART1_IS7816: TXT Position              */
#define UART_IS7816_GTV_MASK                     (0x01UL << UART_IS7816_GTV_SHIFT)                   /*!< UART1_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    2                                                   /*!< UART1_IS7816: GTV Position              */
#define UART_IS7816_INITD_MASK                   (0x01UL << UART_IS7816_INITD_SHIFT)                 /*!< UART1_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  4                                                   /*!< UART1_IS7816: INITD Position            */
#define UART_IS7816_BWT_MASK                     (0x01UL << UART_IS7816_BWT_SHIFT)                   /*!< UART1_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    5                                                   /*!< UART1_IS7816: BWT Position              */
#define UART_IS7816_CWT_MASK                     (0x01UL << UART_IS7816_CWT_SHIFT)                   /*!< UART1_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    6                                                   /*!< UART1_IS7816: CWT Position              */
#define UART_IS7816_WT_MASK                      (0x01UL << UART_IS7816_WT_SHIFT)                    /*!< UART1_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     7                                                   /*!< UART1_IS7816: WT Position               */
/* ------- WP7816T0 Bit Fields                      ------ */
#define UART_WP7816T0_WI_MASK                    (0xFFUL << UART_WP7816T0_WI_SHIFT)                  /*!< UART1_WP7816T0: WI Mask                 */
#define UART_WP7816T0_WI_SHIFT                   0                                                   /*!< UART1_WP7816T0: WI Position             */
#define UART_WP7816T0_WI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WP7816T0_WI_SHIFT))&UART_WP7816T0_WI_MASK) /*!< UART1_WP7816T0                          */
/* ------- WP7816T1 Bit Fields                      ------ */
#define UART_WP7816T1_BWI_MASK                   (0x0FUL << UART_WP7816T1_BWI_SHIFT)                 /*!< UART1_WP7816T1: BWI Mask                */
#define UART_WP7816T1_BWI_SHIFT                  0                                                   /*!< UART1_WP7816T1: BWI Position            */
#define UART_WP7816T1_BWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_BWI_SHIFT))&UART_WP7816T1_BWI_MASK) /*!< UART1_WP7816T1                          */
#define UART_WP7816T1_CWI_MASK                   (0x0FUL << UART_WP7816T1_CWI_SHIFT)                 /*!< UART1_WP7816T1: CWI Mask                */
#define UART_WP7816T1_CWI_SHIFT                  4                                                   /*!< UART1_WP7816T1: CWI Position            */
#define UART_WP7816T1_CWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_CWI_SHIFT))&UART_WP7816T1_CWI_MASK) /*!< UART1_WP7816T1                          */
/* ------- WN7816 Bit Fields                        ------ */
#define UART_WN7816_GTN_MASK                     (0xFFUL << UART_WN7816_GTN_SHIFT)                   /*!< UART1_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    0                                                   /*!< UART1_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /*!< UART1_WN7816                            */
/* ------- WF7816 Bit Fields                        ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFUL << UART_WF7816_GTFD_SHIFT)                  /*!< UART1_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   0                                                   /*!< UART1_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /*!< UART1_WF7816                            */
/* ------- ET7816 Bit Fields                        ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_RXTHRESHOLD_SHIFT)           /*!< UART1_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            0                                                   /*!< UART1_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART1_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_TXTHRESHOLD_SHIFT)           /*!< UART1_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            4                                                   /*!< UART1_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART1_ET7816                            */
/* ------- TL7816 Bit Fields                        ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFUL << UART_TL7816_TLEN_SHIFT)                  /*!< UART1_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   0                                                   /*!< UART1_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /*!< UART1_TL7816                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART2 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART1_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART3 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART3 - Peripheral instance base addresses */
#define UART3_BasePtr                  0x4006D000UL //!< Peripheral base address
#define UART3                          ((UART_Type *) UART3_BasePtr) //!< Freescale base pointer
#define UART3_BASE_PTR                 (UART3) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
/**
* @addtogroup VREF_structs_GROUP VREF struct
* @brief Struct for VREF
* @{
*/
typedef struct {                                /*       VREF Structure                                               */
   __IO uint8_t   VREFH_TRM;                    /**< 0000: VREFH Trim Register                                          */
   __IO uint8_t   VREFH_SC;                     /**< 0001: Status and Control Register                                  */
   __I  uint8_t   RESERVED0[3];                
   __IO uint8_t   VREFL_TRM;                    /**< 0005: VREFL TRIM Register                                          */
} VREF_Type;

/**
 * @} */ /* End group VREF_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup VREF_Register_Masks_GROUP VREF Register Masks
* @brief Register Masks for VREF
* @{
*/
/* ------- VREFH_TRM Bit Fields                     ------ */
#define VREF_VREFH_TRM_TRIM_MASK                 (0x3FUL << VREF_VREFH_TRM_TRIM_SHIFT)               /*!< VREF_VREFH_TRM: TRIM Mask               */
#define VREF_VREFH_TRM_TRIM_SHIFT                0                                                   /*!< VREF_VREFH_TRM: TRIM Position           */
#define VREF_VREFH_TRM_TRIM(x)                   (((uint8_t)(((uint8_t)(x))<<VREF_VREFH_TRM_TRIM_SHIFT))&VREF_VREFH_TRM_TRIM_MASK) /*!< VREF_VREFH_TRM                          */
#define VREF_VREFH_TRM_CHOPEN_MASK               (0x01UL << VREF_VREFH_TRM_CHOPEN_SHIFT)             /*!< VREF_VREFH_TRM: CHOPEN Mask             */
#define VREF_VREFH_TRM_CHOPEN_SHIFT              6                                                   /*!< VREF_VREFH_TRM: CHOPEN Position         */
/* ------- VREFH_SC Bit Fields                      ------ */
#define VREF_VREFH_SC_MODE_LV_MASK               (0x03UL << VREF_VREFH_SC_MODE_LV_SHIFT)             /*!< VREF_VREFH_SC: MODE_LV Mask             */
#define VREF_VREFH_SC_MODE_LV_SHIFT              0                                                   /*!< VREF_VREFH_SC: MODE_LV Position         */
#define VREF_VREFH_SC_MODE_LV(x)                 (((uint8_t)(((uint8_t)(x))<<VREF_VREFH_SC_MODE_LV_SHIFT))&VREF_VREFH_SC_MODE_LV_MASK) /*!< VREF_VREFH_SC                           */
#define VREF_VREFH_SC_VREFST_MASK                (0x01UL << VREF_VREFH_SC_VREFST_SHIFT)              /*!< VREF_VREFH_SC: VREFST Mask              */
#define VREF_VREFH_SC_VREFST_SHIFT               2                                                   /*!< VREF_VREFH_SC: VREFST Position          */
#define VREF_VREFH_SC_REGEN_MASK                 (0x01UL << VREF_VREFH_SC_REGEN_SHIFT)               /*!< VREF_VREFH_SC: REGEN Mask               */
#define VREF_VREFH_SC_REGEN_SHIFT                6                                                   /*!< VREF_VREFH_SC: REGEN Position           */
#define VREF_VREFH_SC_VREFEN_MASK                (0x01UL << VREF_VREFH_SC_VREFEN_SHIFT)              /*!< VREF_VREFH_SC: VREFEN Mask              */
#define VREF_VREFH_SC_VREFEN_SHIFT               7                                                   /*!< VREF_VREFH_SC: VREFEN Position          */
/* ------- VREFL_TRM Bit Fields                     ------ */
#define VREF_VREFL_TRM_VREFL_TRIM_MASK           (0x07UL << VREF_VREFL_TRM_VREFL_TRIM_SHIFT)         /*!< VREF_VREFL_TRM: VREFL_TRIM Mask         */
#define VREF_VREFL_TRM_VREFL_TRIM_SHIFT          0                                                   /*!< VREF_VREFL_TRM: VREFL_TRIM Position     */
#define VREF_VREFL_TRM_VREFL_TRIM(x)             (((uint8_t)(((uint8_t)(x))<<VREF_VREFL_TRM_VREFL_TRIM_SHIFT))&VREF_VREFL_TRM_VREFL_TRIM_MASK) /*!< VREF_VREFL_TRM                          */
#define VREF_VREFL_TRM_VREFL_EN_MASK             (0x01UL << VREF_VREFL_TRM_VREFL_EN_SHIFT)           /*!< VREF_VREFL_TRM: VREFL_EN Mask           */
#define VREF_VREFL_TRM_VREFL_EN_SHIFT            3                                                   /*!< VREF_VREFL_TRM: VREFL_EN Position       */
#define VREF_VREFL_TRM_VREFL_SEL_MASK            (0x01UL << VREF_VREFL_TRM_VREFL_SEL_SHIFT)          /*!< VREF_VREFL_TRM: VREFL_SEL Mask          */
#define VREF_VREFL_TRM_VREFL_SEL_SHIFT           4                                                   /*!< VREF_VREFL_TRM: VREFL_SEL Position      */
/**
 * @} */ /* End group VREF_Register_Masks_GROUP 
 */

/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0x4006F000UL //!< Peripheral base address
#define VREF                           ((VREF_Type *) VREF_BasePtr) //!< Freescale base pointer
#define VREF_BASE_PTR                  (VREF) //!< Freescale style base pointer
/**
 * @} */ /* End group VREF_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer
* @brief C Struct for WDOG
* @{
*/

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer
 */
/**
* @addtogroup WDOG_structs_GROUP WDOG struct
* @brief Struct for WDOG
* @{
*/
typedef struct {                                /*       WDOG Structure                                               */
   __IO uint16_t  STCTRLH;                      /**< 0000: Status and Control Register High                             */
   __IO uint16_t  STCTRLL;                      /**< 0002: Status and Control Register Low                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TOVAL;                     /**< 0004: Time-out Value Register High TOVALL:TOVALH                   */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TOVALH;                 /**< 0004: Time-out Value Register High                                 */
         __IO uint16_t  TOVALL;                 /**< 0006: Time-out Value Register Low                                  */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  WIN;                       /**< 0008: Window Register (WINL:WINH)                                  */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  WINH;                   /**< 0008: Window Register High                                         */
         __IO uint16_t  WINL;                   /**< 000A: Window Register Low                                          */
      };
   };
   __IO uint16_t  REFRESH;                      /**< 000C: Refresh Register                                             */
   __IO uint16_t  UNLOCK;                       /**< 000E: Unlock Register                                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TMROUT;                    /**< 0010: Timer Output Register (TMROUTL:TMROUTH)                      */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TMROUTH;                /**< 0010: Timer Output Register High                                   */
         __IO uint16_t  TMROUTL;                /**< 0012: Timer Output Register Low                                    */
      };
   };
   __IO uint16_t  RSTCNT;                       /**< 0014: Reset Count Register                                         */
   __IO uint16_t  PRESC;                        /**< 0016: Prescaler Register                                           */
} WDOG_Type;

/**
 * @} */ /* End group WDOG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WDOG_Register_Masks_GROUP WDOG Register Masks
* @brief Register Masks for WDOG
* @{
*/
/* ------- STCTRLH Bit Fields                       ------ */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x01UL << WDOG_STCTRLH_WDOGEN_SHIFT)               /*!< WDOG_STCTRLH: WDOGEN Mask               */
#define WDOG_STCTRLH_WDOGEN_SHIFT                0                                                   /*!< WDOG_STCTRLH: WDOGEN Position           */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x01UL << WDOG_STCTRLH_CLKSRC_SHIFT)               /*!< WDOG_STCTRLH: CLKSRC Mask               */
#define WDOG_STCTRLH_CLKSRC_SHIFT                1                                                   /*!< WDOG_STCTRLH: CLKSRC Position           */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x01UL << WDOG_STCTRLH_IRQRSTEN_SHIFT)             /*!< WDOG_STCTRLH: IRQRSTEN Mask             */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2                                                   /*!< WDOG_STCTRLH: IRQRSTEN Position         */
#define WDOG_STCTRLH_WINEN_MASK                  (0x01UL << WDOG_STCTRLH_WINEN_SHIFT)                /*!< WDOG_STCTRLH: WINEN Mask                */
#define WDOG_STCTRLH_WINEN_SHIFT                 3                                                   /*!< WDOG_STCTRLH: WINEN Position            */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x01UL << WDOG_STCTRLH_ALLOWUPDATE_SHIFT)          /*!< WDOG_STCTRLH: ALLOWUPDATE Mask          */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4                                                   /*!< WDOG_STCTRLH: ALLOWUPDATE Position      */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x01UL << WDOG_STCTRLH_DBGEN_SHIFT)                /*!< WDOG_STCTRLH: DBGEN Mask                */
#define WDOG_STCTRLH_DBGEN_SHIFT                 5                                                   /*!< WDOG_STCTRLH: DBGEN Position            */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x01UL << WDOG_STCTRLH_STOPEN_SHIFT)               /*!< WDOG_STCTRLH: STOPEN Mask               */
#define WDOG_STCTRLH_STOPEN_SHIFT                6                                                   /*!< WDOG_STCTRLH: STOPEN Position           */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x01UL << WDOG_STCTRLH_TESTWDOG_SHIFT)             /*!< WDOG_STCTRLH: TESTWDOG Mask             */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10                                                  /*!< WDOG_STCTRLH: TESTWDOG Position         */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x01UL << WDOG_STCTRLH_TESTSEL_SHIFT)              /*!< WDOG_STCTRLH: TESTSEL Mask              */
#define WDOG_STCTRLH_TESTSEL_SHIFT               11                                                  /*!< WDOG_STCTRLH: TESTSEL Position          */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x03UL << WDOG_STCTRLH_BYTESEL_SHIFT)              /*!< WDOG_STCTRLH: BYTESEL Mask              */
#define WDOG_STCTRLH_BYTESEL_SHIFT               12                                                  /*!< WDOG_STCTRLH: BYTESEL Position          */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x01UL << WDOG_STCTRLH_DISTESTWDOG_SHIFT)          /*!< WDOG_STCTRLH: DISTESTWDOG Mask          */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14                                                  /*!< WDOG_STCTRLH: DISTESTWDOG Position      */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x01UL << WDOG_STCTRLL_INTFLG_SHIFT)               /*!< WDOG_STCTRLL: INTFLG Mask               */
#define WDOG_STCTRLL_INTFLG_SHIFT                15                                                  /*!< WDOG_STCTRLL: INTFLG Position           */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFUL << WDOG_TOVAL_TOVAL_SHIFT)            /*!< WDOG_TOVAL: TOVAL Mask                  */
#define WDOG_TOVAL_TOVAL_SHIFT                   0                                                   /*!< WDOG_TOVAL: TOVAL Position              */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK) /*!< WDOG_TOVAL                              */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFUL << WDOG_TOVALH_TOVALHIGH_SHIFT)           /*!< WDOG_TOVALH: TOVALHIGH Mask             */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0                                                   /*!< WDOG_TOVALH: TOVALHIGH Position         */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK) /*!< WDOG_TOVALH                             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFUL << WDOG_TOVALL_TOVALLOW_SHIFT)            /*!< WDOG_TOVALL: TOVALLOW Mask              */
#define WDOG_TOVALL_TOVALLOW_SHIFT               0                                                   /*!< WDOG_TOVALL: TOVALLOW Position          */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK) /*!< WDOG_TOVALL                             */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFUL << WDOG_WIN_WIN_SHIFT)                /*!< WDOG_WIN: WIN Mask                      */
#define WDOG_WIN_WIN_SHIFT                       0                                                   /*!< WDOG_WIN: WIN Position                  */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK) /*!< WDOG_WIN                                */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFUL << WDOG_WINH_WINHIGH_SHIFT)               /*!< WDOG_WINH: WINHIGH Mask                 */
#define WDOG_WINH_WINHIGH_SHIFT                  0                                                   /*!< WDOG_WINH: WINHIGH Position             */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK) /*!< WDOG_WINH                               */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFUL << WDOG_WINL_WINLOW_SHIFT)                /*!< WDOG_WINL: WINLOW Mask                  */
#define WDOG_WINL_WINLOW_SHIFT                   0                                                   /*!< WDOG_WINL: WINLOW Position              */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK) /*!< WDOG_WINL                               */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFUL << WDOG_REFRESH_WDOGREFRESH_SHIFT)        /*!< WDOG_REFRESH: WDOGREFRESH Mask          */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0                                                   /*!< WDOG_REFRESH: WDOGREFRESH Position      */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK) /*!< WDOG_REFRESH                            */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFUL << WDOG_UNLOCK_WDOGUNLOCK_SHIFT)          /*!< WDOG_UNLOCK: WDOGUNLOCK Mask            */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0                                                   /*!< WDOG_UNLOCK: WDOGUNLOCK Position        */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK) /*!< WDOG_UNLOCK                             */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFUL << WDOG_TMROUT_TIMEROUTHIGH_SHIFT)    /*!< WDOG_TMROUT: TIMEROUTHIGH Mask          */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           0                                                   /*!< WDOG_TMROUT: TIMEROUTHIGH Position      */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<WDOG_TMROUT_TIMEROUTHIGH_SHIFT))&WDOG_TMROUT_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUT                             */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFUL << WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)       /*!< WDOG_TMROUTH: TIMEROUTHIGH Mask         */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0                                                   /*!< WDOG_TMROUTH: TIMEROUTHIGH Position     */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUTH                            */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFUL << WDOG_TMROUTL_TIMEROUTLOW_SHIFT)        /*!< WDOG_TMROUTL: TIMEROUTLOW Mask          */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0                                                   /*!< WDOG_TMROUTL: TIMEROUTLOW Position      */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK) /*!< WDOG_TMROUTL                            */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFUL << WDOG_RSTCNT_RSTCNT_SHIFT)              /*!< WDOG_RSTCNT: RSTCNT Mask                */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0                                                   /*!< WDOG_RSTCNT: RSTCNT Position            */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK) /*!< WDOG_RSTCNT                             */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x07UL << WDOG_PRESC_PRESCVAL_SHIFT)               /*!< WDOG_PRESC: PRESCVAL Mask               */
#define WDOG_PRESC_PRESCVAL_SHIFT                8                                                   /*!< WDOG_PRESC: PRESCVAL Position           */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK) /*!< WDOG_PRESC                              */
/**
 * @} */ /* End group WDOG_Register_Masks_GROUP 
 */

/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x40053000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
/**
 * @} */ /* End group WDOG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup XBAR_Peripheral_access_layer_GROUP XBAR Peripheral Access Layer
* @brief C Struct for XBAR
* @{
*/

/* ================================================================================ */
/* ================           XBAR (file:XBAR_MKM)                 ================ */
/* ================================================================================ */

/**
 * @brief Crossbar Switch
 */
/**
* @addtogroup XBAR_structs_GROUP XBAR struct
* @brief Struct for XBAR
* @{
*/
typedef struct {                                /*       XBAR Structure                                               */
   __IO uint16_t  SEL0;                         /**< 0000: Crossbar Select Register 0                                   */
   __IO uint16_t  SEL1;                         /**< 0002: Crossbar Select Register 1                                   */
   __IO uint16_t  SEL2;                         /**< 0004: Crossbar Select Register 2                                   */
   __IO uint16_t  SEL3;                         /**< 0006: Crossbar Select Register 3                                   */
   __IO uint16_t  SEL4;                         /**< 0008: Crossbar Select Register 4                                   */
   __IO uint16_t  SEL5;                         /**< 000A: Crossbar Select Register 5                                   */
   __IO uint16_t  SEL6;                         /**< 000C: Crossbar Select Register 6                                   */
   __IO uint16_t  SEL7;                         /**< 000E: Crossbar Select Register 7                                   */
   __IO uint16_t  SEL8;                         /**< 0010: Crossbar Select Register 8                                   */
   __IO uint16_t  SEL9;                         /**< 0012: Crossbar Select Register 9                                   */
   __IO uint16_t  SEL10;                        /**< 0014: Crossbar Select Register 10                                  */
   __IO uint16_t  SEL11;                        /**< 0016: Crossbar Select Register 11                                  */
   __IO uint16_t  SEL12;                        /**< 0018: Crossbar Select Register 12                                  */
   __IO uint16_t  SEL13;                        /**< 001A: Crossbar Select Register 13                                  */
   __IO uint16_t  SEL14;                        /**< 001C: Crossbar Select Register 14                                  */
   __IO uint16_t  SEL15;                        /**< 001E: Crossbar Select Register 15                                  */
   __IO uint16_t  SEL16;                        /**< 0020: Crossbar Select Register 16                                  */
   __IO uint16_t  CTRL0;                        /**< 0022: Crossbar Control Register 0                                  */
} XBAR_Type;

/**
 * @} */ /* End group XBAR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'XBAR' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup XBAR_Register_Masks_GROUP XBAR Register Masks
* @brief Register Masks for XBAR
* @{
*/
/* ------- SEL0 Bit Fields                          ------ */
#define XBAR_SEL0_SEL0_MASK                      (0x3FUL << XBAR_SEL0_SEL0_SHIFT)                    /*!< XBAR_SEL0: SEL0 Mask                    */
#define XBAR_SEL0_SEL0_SHIFT                     0                                                   /*!< XBAR_SEL0: SEL0 Position                */
#define XBAR_SEL0_SEL0(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL0_SEL0_SHIFT))&XBAR_SEL0_SEL0_MASK) /*!< XBAR_SEL0                               */
#define XBAR_SEL0_SEL1_MASK                      (0x3FUL << XBAR_SEL0_SEL1_SHIFT)                    /*!< XBAR_SEL0: SEL1 Mask                    */
#define XBAR_SEL0_SEL1_SHIFT                     8                                                   /*!< XBAR_SEL0: SEL1 Position                */
#define XBAR_SEL0_SEL1(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL0_SEL1_SHIFT))&XBAR_SEL0_SEL1_MASK) /*!< XBAR_SEL0                               */
/* ------- SEL1 Bit Fields                          ------ */
#define XBAR_SEL1_SEL2_MASK                      (0x3FUL << XBAR_SEL1_SEL2_SHIFT)                    /*!< XBAR_SEL1: SEL2 Mask                    */
#define XBAR_SEL1_SEL2_SHIFT                     0                                                   /*!< XBAR_SEL1: SEL2 Position                */
#define XBAR_SEL1_SEL2(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL1_SEL2_SHIFT))&XBAR_SEL1_SEL2_MASK) /*!< XBAR_SEL1                               */
#define XBAR_SEL1_SEL3_MASK                      (0x3FUL << XBAR_SEL1_SEL3_SHIFT)                    /*!< XBAR_SEL1: SEL3 Mask                    */
#define XBAR_SEL1_SEL3_SHIFT                     8                                                   /*!< XBAR_SEL1: SEL3 Position                */
#define XBAR_SEL1_SEL3(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL1_SEL3_SHIFT))&XBAR_SEL1_SEL3_MASK) /*!< XBAR_SEL1                               */
/* ------- SEL2 Bit Fields                          ------ */
#define XBAR_SEL2_SEL4_MASK                      (0x3FUL << XBAR_SEL2_SEL4_SHIFT)                    /*!< XBAR_SEL2: SEL4 Mask                    */
#define XBAR_SEL2_SEL4_SHIFT                     0                                                   /*!< XBAR_SEL2: SEL4 Position                */
#define XBAR_SEL2_SEL4(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL2_SEL4_SHIFT))&XBAR_SEL2_SEL4_MASK) /*!< XBAR_SEL2                               */
#define XBAR_SEL2_SEL5_MASK                      (0x3FUL << XBAR_SEL2_SEL5_SHIFT)                    /*!< XBAR_SEL2: SEL5 Mask                    */
#define XBAR_SEL2_SEL5_SHIFT                     8                                                   /*!< XBAR_SEL2: SEL5 Position                */
#define XBAR_SEL2_SEL5(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL2_SEL5_SHIFT))&XBAR_SEL2_SEL5_MASK) /*!< XBAR_SEL2                               */
/* ------- SEL3 Bit Fields                          ------ */
#define XBAR_SEL3_SEL6_MASK                      (0x3FUL << XBAR_SEL3_SEL6_SHIFT)                    /*!< XBAR_SEL3: SEL6 Mask                    */
#define XBAR_SEL3_SEL6_SHIFT                     0                                                   /*!< XBAR_SEL3: SEL6 Position                */
#define XBAR_SEL3_SEL6(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL3_SEL6_SHIFT))&XBAR_SEL3_SEL6_MASK) /*!< XBAR_SEL3                               */
#define XBAR_SEL3_SEL7_MASK                      (0x3FUL << XBAR_SEL3_SEL7_SHIFT)                    /*!< XBAR_SEL3: SEL7 Mask                    */
#define XBAR_SEL3_SEL7_SHIFT                     8                                                   /*!< XBAR_SEL3: SEL7 Position                */
#define XBAR_SEL3_SEL7(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL3_SEL7_SHIFT))&XBAR_SEL3_SEL7_MASK) /*!< XBAR_SEL3                               */
/* ------- SEL4 Bit Fields                          ------ */
#define XBAR_SEL4_SEL8_MASK                      (0x3FUL << XBAR_SEL4_SEL8_SHIFT)                    /*!< XBAR_SEL4: SEL8 Mask                    */
#define XBAR_SEL4_SEL8_SHIFT                     0                                                   /*!< XBAR_SEL4: SEL8 Position                */
#define XBAR_SEL4_SEL8(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL4_SEL8_SHIFT))&XBAR_SEL4_SEL8_MASK) /*!< XBAR_SEL4                               */
#define XBAR_SEL4_SEL9_MASK                      (0x3FUL << XBAR_SEL4_SEL9_SHIFT)                    /*!< XBAR_SEL4: SEL9 Mask                    */
#define XBAR_SEL4_SEL9_SHIFT                     8                                                   /*!< XBAR_SEL4: SEL9 Position                */
#define XBAR_SEL4_SEL9(x)                        (((uint16_t)(((uint16_t)(x))<<XBAR_SEL4_SEL9_SHIFT))&XBAR_SEL4_SEL9_MASK) /*!< XBAR_SEL4                               */
/* ------- SEL5 Bit Fields                          ------ */
#define XBAR_SEL5_SEL10_MASK                     (0x3FUL << XBAR_SEL5_SEL10_SHIFT)                   /*!< XBAR_SEL5: SEL10 Mask                   */
#define XBAR_SEL5_SEL10_SHIFT                    0                                                   /*!< XBAR_SEL5: SEL10 Position               */
#define XBAR_SEL5_SEL10(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL5_SEL10_SHIFT))&XBAR_SEL5_SEL10_MASK) /*!< XBAR_SEL5                               */
#define XBAR_SEL5_SEL11_MASK                     (0x3FUL << XBAR_SEL5_SEL11_SHIFT)                   /*!< XBAR_SEL5: SEL11 Mask                   */
#define XBAR_SEL5_SEL11_SHIFT                    8                                                   /*!< XBAR_SEL5: SEL11 Position               */
#define XBAR_SEL5_SEL11(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL5_SEL11_SHIFT))&XBAR_SEL5_SEL11_MASK) /*!< XBAR_SEL5                               */
/* ------- SEL6 Bit Fields                          ------ */
#define XBAR_SEL6_SEL12_MASK                     (0x3FUL << XBAR_SEL6_SEL12_SHIFT)                   /*!< XBAR_SEL6: SEL12 Mask                   */
#define XBAR_SEL6_SEL12_SHIFT                    0                                                   /*!< XBAR_SEL6: SEL12 Position               */
#define XBAR_SEL6_SEL12(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL6_SEL12_SHIFT))&XBAR_SEL6_SEL12_MASK) /*!< XBAR_SEL6                               */
#define XBAR_SEL6_SEL13_MASK                     (0x3FUL << XBAR_SEL6_SEL13_SHIFT)                   /*!< XBAR_SEL6: SEL13 Mask                   */
#define XBAR_SEL6_SEL13_SHIFT                    8                                                   /*!< XBAR_SEL6: SEL13 Position               */
#define XBAR_SEL6_SEL13(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL6_SEL13_SHIFT))&XBAR_SEL6_SEL13_MASK) /*!< XBAR_SEL6                               */
/* ------- SEL7 Bit Fields                          ------ */
#define XBAR_SEL7_SEL14_MASK                     (0x3FUL << XBAR_SEL7_SEL14_SHIFT)                   /*!< XBAR_SEL7: SEL14 Mask                   */
#define XBAR_SEL7_SEL14_SHIFT                    0                                                   /*!< XBAR_SEL7: SEL14 Position               */
#define XBAR_SEL7_SEL14(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL7_SEL14_SHIFT))&XBAR_SEL7_SEL14_MASK) /*!< XBAR_SEL7                               */
#define XBAR_SEL7_SEL15_MASK                     (0x3FUL << XBAR_SEL7_SEL15_SHIFT)                   /*!< XBAR_SEL7: SEL15 Mask                   */
#define XBAR_SEL7_SEL15_SHIFT                    8                                                   /*!< XBAR_SEL7: SEL15 Position               */
#define XBAR_SEL7_SEL15(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL7_SEL15_SHIFT))&XBAR_SEL7_SEL15_MASK) /*!< XBAR_SEL7                               */
/* ------- SEL8 Bit Fields                          ------ */
#define XBAR_SEL8_SEL16_MASK                     (0x3FUL << XBAR_SEL8_SEL16_SHIFT)                   /*!< XBAR_SEL8: SEL16 Mask                   */
#define XBAR_SEL8_SEL16_SHIFT                    0                                                   /*!< XBAR_SEL8: SEL16 Position               */
#define XBAR_SEL8_SEL16(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL8_SEL16_SHIFT))&XBAR_SEL8_SEL16_MASK) /*!< XBAR_SEL8                               */
#define XBAR_SEL8_SEL17_MASK                     (0x3FUL << XBAR_SEL8_SEL17_SHIFT)                   /*!< XBAR_SEL8: SEL17 Mask                   */
#define XBAR_SEL8_SEL17_SHIFT                    8                                                   /*!< XBAR_SEL8: SEL17 Position               */
#define XBAR_SEL8_SEL17(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL8_SEL17_SHIFT))&XBAR_SEL8_SEL17_MASK) /*!< XBAR_SEL8                               */
/* ------- SEL9 Bit Fields                          ------ */
#define XBAR_SEL9_SEL18_MASK                     (0x3FUL << XBAR_SEL9_SEL18_SHIFT)                   /*!< XBAR_SEL9: SEL18 Mask                   */
#define XBAR_SEL9_SEL18_SHIFT                    0                                                   /*!< XBAR_SEL9: SEL18 Position               */
#define XBAR_SEL9_SEL18(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL9_SEL18_SHIFT))&XBAR_SEL9_SEL18_MASK) /*!< XBAR_SEL9                               */
#define XBAR_SEL9_SEL19_MASK                     (0x3FUL << XBAR_SEL9_SEL19_SHIFT)                   /*!< XBAR_SEL9: SEL19 Mask                   */
#define XBAR_SEL9_SEL19_SHIFT                    8                                                   /*!< XBAR_SEL9: SEL19 Position               */
#define XBAR_SEL9_SEL19(x)                       (((uint16_t)(((uint16_t)(x))<<XBAR_SEL9_SEL19_SHIFT))&XBAR_SEL9_SEL19_MASK) /*!< XBAR_SEL9                               */
/* ------- SEL10 Bit Fields                         ------ */
#define XBAR_SEL10_SEL20_MASK                    (0x1FUL << XBAR_SEL10_SEL20_SHIFT)                  /*!< XBAR_SEL10: SEL20 Mask                  */
#define XBAR_SEL10_SEL20_SHIFT                   0                                                   /*!< XBAR_SEL10: SEL20 Position              */
#define XBAR_SEL10_SEL20(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL10_SEL20_SHIFT))&XBAR_SEL10_SEL20_MASK) /*!< XBAR_SEL10                              */
#define XBAR_SEL10_SEL21_MASK                    (0x1FUL << XBAR_SEL10_SEL21_SHIFT)                  /*!< XBAR_SEL10: SEL21 Mask                  */
#define XBAR_SEL10_SEL21_SHIFT                   8                                                   /*!< XBAR_SEL10: SEL21 Position              */
#define XBAR_SEL10_SEL21(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL10_SEL21_SHIFT))&XBAR_SEL10_SEL21_MASK) /*!< XBAR_SEL10                              */
/* ------- SEL11 Bit Fields                         ------ */
#define XBAR_SEL11_SEL22_MASK                    (0x3FUL << XBAR_SEL11_SEL22_SHIFT)                  /*!< XBAR_SEL11: SEL22 Mask                  */
#define XBAR_SEL11_SEL22_SHIFT                   0                                                   /*!< XBAR_SEL11: SEL22 Position              */
#define XBAR_SEL11_SEL22(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL11_SEL22_SHIFT))&XBAR_SEL11_SEL22_MASK) /*!< XBAR_SEL11                              */
#define XBAR_SEL11_SEL23_MASK                    (0x3FUL << XBAR_SEL11_SEL23_SHIFT)                  /*!< XBAR_SEL11: SEL23 Mask                  */
#define XBAR_SEL11_SEL23_SHIFT                   8                                                   /*!< XBAR_SEL11: SEL23 Position              */
#define XBAR_SEL11_SEL23(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL11_SEL23_SHIFT))&XBAR_SEL11_SEL23_MASK) /*!< XBAR_SEL11                              */
/* ------- SEL12 Bit Fields                         ------ */
#define XBAR_SEL12_SEL24_MASK                    (0x1FUL << XBAR_SEL12_SEL24_SHIFT)                  /*!< XBAR_SEL12: SEL24 Mask                  */
#define XBAR_SEL12_SEL24_SHIFT                   0                                                   /*!< XBAR_SEL12: SEL24 Position              */
#define XBAR_SEL12_SEL24(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL12_SEL24_SHIFT))&XBAR_SEL12_SEL24_MASK) /*!< XBAR_SEL12                              */
#define XBAR_SEL12_SEL25_MASK                    (0x1FUL << XBAR_SEL12_SEL25_SHIFT)                  /*!< XBAR_SEL12: SEL25 Mask                  */
#define XBAR_SEL12_SEL25_SHIFT                   8                                                   /*!< XBAR_SEL12: SEL25 Position              */
#define XBAR_SEL12_SEL25(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL12_SEL25_SHIFT))&XBAR_SEL12_SEL25_MASK) /*!< XBAR_SEL12                              */
/* ------- SEL13 Bit Fields                         ------ */
#define XBAR_SEL13_SEL26_MASK                    (0x3FUL << XBAR_SEL13_SEL26_SHIFT)                  /*!< XBAR_SEL13: SEL26 Mask                  */
#define XBAR_SEL13_SEL26_SHIFT                   0                                                   /*!< XBAR_SEL13: SEL26 Position              */
#define XBAR_SEL13_SEL26(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL13_SEL26_SHIFT))&XBAR_SEL13_SEL26_MASK) /*!< XBAR_SEL13                              */
#define XBAR_SEL13_SEL27_MASK                    (0x3FUL << XBAR_SEL13_SEL27_SHIFT)                  /*!< XBAR_SEL13: SEL27 Mask                  */
#define XBAR_SEL13_SEL27_SHIFT                   8                                                   /*!< XBAR_SEL13: SEL27 Position              */
#define XBAR_SEL13_SEL27(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL13_SEL27_SHIFT))&XBAR_SEL13_SEL27_MASK) /*!< XBAR_SEL13                              */
/* ------- SEL14 Bit Fields                         ------ */
#define XBAR_SEL14_SEL28_MASK                    (0x3FUL << XBAR_SEL14_SEL28_SHIFT)                  /*!< XBAR_SEL14: SEL28 Mask                  */
#define XBAR_SEL14_SEL28_SHIFT                   0                                                   /*!< XBAR_SEL14: SEL28 Position              */
#define XBAR_SEL14_SEL28(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL14_SEL28_SHIFT))&XBAR_SEL14_SEL28_MASK) /*!< XBAR_SEL14                              */
#define XBAR_SEL14_SEL29_MASK                    (0x3FUL << XBAR_SEL14_SEL29_SHIFT)                  /*!< XBAR_SEL14: SEL29 Mask                  */
#define XBAR_SEL14_SEL29_SHIFT                   8                                                   /*!< XBAR_SEL14: SEL29 Position              */
#define XBAR_SEL14_SEL29(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL14_SEL29_SHIFT))&XBAR_SEL14_SEL29_MASK) /*!< XBAR_SEL14                              */
/* ------- SEL15 Bit Fields                         ------ */
#define XBAR_SEL15_SEL30_MASK                    (0x1FUL << XBAR_SEL15_SEL30_SHIFT)                  /*!< XBAR_SEL15: SEL30 Mask                  */
#define XBAR_SEL15_SEL30_SHIFT                   0                                                   /*!< XBAR_SEL15: SEL30 Position              */
#define XBAR_SEL15_SEL30(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL15_SEL30_SHIFT))&XBAR_SEL15_SEL30_MASK) /*!< XBAR_SEL15                              */
#define XBAR_SEL15_SEL31_MASK                    (0x1FUL << XBAR_SEL15_SEL31_SHIFT)                  /*!< XBAR_SEL15: SEL31 Mask                  */
#define XBAR_SEL15_SEL31_SHIFT                   8                                                   /*!< XBAR_SEL15: SEL31 Position              */
#define XBAR_SEL15_SEL31(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL15_SEL31_SHIFT))&XBAR_SEL15_SEL31_MASK) /*!< XBAR_SEL15                              */
/* ------- SEL16 Bit Fields                         ------ */
#define XBAR_SEL16_SEL32_MASK                    (0x3FUL << XBAR_SEL16_SEL32_SHIFT)                  /*!< XBAR_SEL16: SEL32 Mask                  */
#define XBAR_SEL16_SEL32_SHIFT                   0                                                   /*!< XBAR_SEL16: SEL32 Position              */
#define XBAR_SEL16_SEL32(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_SEL16_SEL32_SHIFT))&XBAR_SEL16_SEL32_MASK) /*!< XBAR_SEL16                              */
/* ------- CTRL0 Bit Fields                         ------ */
#define XBAR_CTRL0_DEN0_MASK                     (0x01UL << XBAR_CTRL0_DEN0_SHIFT)                   /*!< XBAR_CTRL0: DEN0 Mask                   */
#define XBAR_CTRL0_DEN0_SHIFT                    0                                                   /*!< XBAR_CTRL0: DEN0 Position               */
#define XBAR_CTRL0_IEN0_MASK                     (0x01UL << XBAR_CTRL0_IEN0_SHIFT)                   /*!< XBAR_CTRL0: IEN0 Mask                   */
#define XBAR_CTRL0_IEN0_SHIFT                    1                                                   /*!< XBAR_CTRL0: IEN0 Position               */
#define XBAR_CTRL0_EDGE0_MASK                    (0x03UL << XBAR_CTRL0_EDGE0_SHIFT)                  /*!< XBAR_CTRL0: EDGE0 Mask                  */
#define XBAR_CTRL0_EDGE0_SHIFT                   2                                                   /*!< XBAR_CTRL0: EDGE0 Position              */
#define XBAR_CTRL0_EDGE0(x)                      (((uint16_t)(((uint16_t)(x))<<XBAR_CTRL0_EDGE0_SHIFT))&XBAR_CTRL0_EDGE0_MASK) /*!< XBAR_CTRL0                              */
#define XBAR_CTRL0_STS0_MASK                     (0x01UL << XBAR_CTRL0_STS0_SHIFT)                   /*!< XBAR_CTRL0: STS0 Mask                   */
#define XBAR_CTRL0_STS0_SHIFT                    4                                                   /*!< XBAR_CTRL0: STS0 Position               */
/**
 * @} */ /* End group XBAR_Register_Masks_GROUP 
 */

/* XBAR - Peripheral instance base addresses */
#define XBAR_BasePtr                   0x40055000UL //!< Peripheral base address
#define XBAR                           ((XBAR_Type *) XBAR_BasePtr) //!< Freescale base pointer
#define XBAR_BASE_PTR                  (XBAR) //!< Freescale style base pointer
/**
 * @} */ /* End group XBAR_Peripheral_access_layer_GROUP 
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


#endif  /* MCU_MKM14Z5 */

