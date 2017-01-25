/****************************************************************************************************//**
 * @file     MKE14D7.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKE14D7.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2016/12
 *
 *******************************************************************************************************/

#ifndef MCU_MKE14D7
#define MCU_MKE14D7

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
/* ----------------------   MKE14D7 VectorTable                      ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 Direct memory access controller                                                  */
  DMA1_IRQn                     =   1,   /**<  17 Direct memory access controller                                                  */
  DMA2_IRQn                     =   2,   /**<  18 Direct memory access controller                                                  */
  DMA3_IRQn                     =   3,   /**<  19 Direct memory access controller                                                  */
  DMA4_IRQn                     =   4,   /**<  20 Direct memory access controller                                                  */
  DMA5_IRQn                     =   5,   /**<  21 Direct memory access controller                                                  */
  DMA6_IRQn                     =   6,   /**<  22 Direct memory access controller                                                  */
  DMA7_IRQn                     =   7,   /**<  23 Direct memory access controller                                                  */
  DMA8_IRQn                     =   8,   /**<  24 Direct memory access controller                                                  */
  DMA9_IRQn                     =   9,   /**<  25 Direct memory access controller                                                  */
  DMA10_IRQn                    =  10,   /**<  26 Direct memory access controller                                                  */
  DMA11_IRQn                    =  11,   /**<  27 Direct memory access controller                                                  */
  DMA12_IRQn                    =  12,   /**<  28 Direct memory access controller                                                  */
  DMA13_IRQn                    =  13,   /**<  29 Direct memory access controller                                                  */
  DMA_Error_IRQn                =  16,   /**<  32 Direct memory access controller                                                  */
  FTMRA_IRQn                    =  18,   /**<  34 FTMRA Family Flash Module                                                        */
  PMC_IRQn                      =  20,   /**<  36 Power Management Controller                                                      */
  WDOG_IRQn                     =  22,   /**<  38 External Watchdog Monitor                                                        */
  ADC2_IRQn                     =  24,   /**<  40 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  25,   /**<  41 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  26,   /**<  42 Serial Peripheral Interface                                                      */
  PDB0_IRQn                     =  49,   /**<  65 Serial Communication Interface                                                   */
  PIT0_IRQn                     =  53,   /**<  69 Periodic Interrupt Timer                                                         */
  PIT1_IRQn                     =  54,   /**<  70 Periodic Interrupt Timer                                                         */
  PORTA_IRQn                    =  59,   /**<  75 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  60,   /**<  76 General Purpose Input/Output                                                     */
  PORTC_IRQn                    =  61,   /**<  77 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  62,   /**<  78 General Purpose Input/Output                                                     */
  PORTE_IRQn                    =  63,   /**<  79 General Purpose Input/Output                                                     */
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
extern void DMA0_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA1_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA2_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA3_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA4_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA5_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA6_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA7_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA8_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA9_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA10_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA11_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA12_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA13_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA_Error_IRQHandler(void);        /**< Direct memory access controller                                                  */
extern void FTMRA_IRQHandler(void);            /**< FTMRA Family Flash Module                                                        */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void WDOG_IRQHandler(void);             /**< External Watchdog Monitor                                                        */
extern void ADC2_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void PDB0_IRQHandler(void);             /**< Serial Communication Interface                                                   */
extern void PIT0_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT1_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTC_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTE_IRQHandler(void);            /**< General Purpose Input/Output                                                     */

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
#define __NVIC_PRIO_BITS          0          /**< Number of implemented bits in NVIC PRIO register    */
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
/* ================           ADC0 (file:ADC0_MKE10)               ================ */
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
   __IO uint16_t  SC1;                          /**< 0000: Status and Control Register 1                                */
   __IO uint16_t  SC2;                          /**< 0002: Status and Control Register 2                                */
   __IO uint16_t  SC3;                          /**< 0004: Status and Control Register 3                                */
   __IO uint16_t  SC4;                          /**< 0006: Status and Control Register 4                                */
   __I  uint16_t  R;                            /**< 0008: Conversion Result Register                                   */
   __IO uint16_t  CVA;                          /**< 000A: Compare Value Register A                                     */
   __IO uint16_t  CVB;                          /**< 000C: Compare Value Register B                                     */
   __IO uint16_t  APCTL;                        /**< 000E: Pin Control Register                                         */
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
#define ADC_SC1_ADCH_MASK                        (0x1FU)                                             /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       (0U)                                                /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_ADCO_MASK                        (0x20U)                                             /*!< ADC0_SC1: ADCO Mask                     */
#define ADC_SC1_ADCO_SHIFT                       (5U)                                                /*!< ADC0_SC1: ADCO Position                 */
#define ADC_SC1_ADCO(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC1_ADCO_SHIFT))&ADC_SC1_ADCO_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_AIEN(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /*!< ADC0_SC1: COCO Position                 */
#define ADC_SC1_COCO(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /*!< ADC0_SC1                                */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_FFULL_MASK                       (0x4U)                                              /*!< ADC0_SC2: FFULL Mask                    */
#define ADC_SC2_FFULL_SHIFT                      (2U)                                                /*!< ADC0_SC2: FFULL Position                */
#define ADC_SC2_FFULL(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC2_FFULL_SHIFT))&ADC_SC2_FFULL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_FEMPTY_MASK                      (0x8U)                                              /*!< ADC0_SC2: FEMPTY Mask                   */
#define ADC_SC2_FEMPTY_SHIFT                     (3U)                                                /*!< ADC0_SC2: FEMPTY Position               */
#define ADC_SC2_FEMPTY(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC2_FEMPTY_SHIFT))&ADC_SC2_FEMPTY_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACDSEL_MASK                      (0x10U)                                             /*!< ADC0_SC2: ACDSEL Mask                   */
#define ADC_SC2_ACDSEL_SHIFT                     (4U)                                                /*!< ADC0_SC2: ACDSEL Position               */
#define ADC_SC2_ACDSEL(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC2_ACDSEL_SHIFT))&ADC_SC2_ACDSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFE_MASK                        (0x20U)                                             /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       (5U)                                                /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ACFE(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADTRG_MASK                       (0x40U)                                             /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      (6U)                                                /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADTRG(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADACT_MASK                       (0x80U)                                             /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      (7U)                                                /*!< ADC0_SC2: ADACT Position                */
#define ADC_SC2_ADACT(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK) /*!< ADC0_SC2                                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_ADICLK_MASK                      (0x3U)                                              /*!< ADC0_SC3: ADICLK Mask                   */
#define ADC_SC3_ADICLK_SHIFT                     (0U)                                                /*!< ADC0_SC3: ADICLK Position               */
#define ADC_SC3_ADICLK(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC3_ADICLK_SHIFT))&ADC_SC3_ADICLK_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_MODE_MASK                        (0xCU)                                              /*!< ADC0_SC3: MODE Mask                     */
#define ADC_SC3_MODE_SHIFT                       (2U)                                                /*!< ADC0_SC3: MODE Position                 */
#define ADC_SC3_MODE(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC3_MODE_SHIFT))&ADC_SC3_MODE_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADLSMP_MASK                      (0x10U)                                             /*!< ADC0_SC3: ADLSMP Mask                   */
#define ADC_SC3_ADLSMP_SHIFT                     (4U)                                                /*!< ADC0_SC3: ADLSMP Position               */
#define ADC_SC3_ADLSMP(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC3_ADLSMP_SHIFT))&ADC_SC3_ADLSMP_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADIV_MASK                        (0x60U)                                             /*!< ADC0_SC3: ADIV Mask                     */
#define ADC_SC3_ADIV_SHIFT                       (5U)                                                /*!< ADC0_SC3: ADIV Position                 */
#define ADC_SC3_ADIV(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SC3_ADIV_SHIFT))&ADC_SC3_ADIV_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADLPC_MASK                       (0x80U)                                             /*!< ADC0_SC3: ADLPC Mask                    */
#define ADC_SC3_ADLPC_SHIFT                      (7U)                                                /*!< ADC0_SC3: ADLPC Position                */
#define ADC_SC3_ADLPC(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC3_ADLPC_SHIFT))&ADC_SC3_ADLPC_MASK) /*!< ADC0_SC3                                */
/* ------- SC4 Bit Fields                           ------ */
#define ADC_SC4_AFDEP_MASK                       (0x7U)                                              /*!< ADC0_SC4: AFDEP Mask                    */
#define ADC_SC4_AFDEP_SHIFT                      (0U)                                                /*!< ADC0_SC4: AFDEP Position                */
#define ADC_SC4_AFDEP(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC4_AFDEP_SHIFT))&ADC_SC4_AFDEP_MASK) /*!< ADC0_SC4                                */
#define ADC_SC4_ACFSEL_MASK                      (0x20U)                                             /*!< ADC0_SC4: ACFSEL Mask                   */
#define ADC_SC4_ACFSEL_SHIFT                     (5U)                                                /*!< ADC0_SC4: ACFSEL Position               */
#define ADC_SC4_ACFSEL(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC4_ACFSEL_SHIFT))&ADC_SC4_ACFSEL_MASK) /*!< ADC0_SC4                                */
#define ADC_SC4_ASCANE_MASK                      (0x40U)                                             /*!< ADC0_SC4: ASCANE Mask                   */
#define ADC_SC4_ASCANE_SHIFT                     (6U)                                                /*!< ADC0_SC4: ASCANE Position               */
#define ADC_SC4_ASCANE(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_SC4_ASCANE_SHIFT))&ADC_SC4_ASCANE_MASK) /*!< ADC0_SC4                                */
#define ADC_SC4_DMAEN_MASK                       (0x80U)                                             /*!< ADC0_SC4: DMAEN Mask                    */
#define ADC_SC4_DMAEN_SHIFT                      (7U)                                                /*!< ADC0_SC4: DMAEN Position                */
#define ADC_SC4_DMAEN(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_SC4_DMAEN_SHIFT))&ADC_SC4_DMAEN_MASK) /*!< ADC0_SC4                                */
/* ------- R Bit Fields                             ------ */
#define ADC_R_ADR_MASK                           (0xFFFU)                                            /*!< ADC0_R: ADR Mask                        */
#define ADC_R_ADR_SHIFT                          (0U)                                                /*!< ADC0_R: ADR Position                    */
#define ADC_R_ADR(x)                             (((uint16_t)(((uint16_t)(x))<<ADC_R_ADR_SHIFT))&ADC_R_ADR_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFU)                                            /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          (0U)                                                /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint16_t)(((uint16_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- APCTL Bit Fields                         ------ */
#define ADC_APCTL_ADPC_MASK                      (0xFFFFU)                                           /*!< ADC0_APCTL: ADPC Mask                   */
#define ADC_APCTL_ADPC_SHIFT                     (0U)                                                /*!< ADC0_APCTL: ADPC Position               */
#define ADC_APCTL_ADPC(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_APCTL_ADPC_SHIFT))&ADC_APCTL_ADPC_MASK) /*!< ADC0_APCTL                              */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4003B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC1 (derived from ADC0)             ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */

/* ADC1 - Peripheral instance base addresses */
#define ADC1_BasePtr                   0x4003C000UL //!< Peripheral base address
#define ADC1                           ((ADC_Type *) ADC1_BasePtr) //!< Freescale base pointer
#define ADC1_BASE_PTR                  (ADC1) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC2 (derived from ADC0)             ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */

/* ADC2 - Peripheral instance base addresses */
#define ADC2_BasePtr                   0x4003D000UL //!< Peripheral base address
#define ADC2                           ((ADC_Type *) ADC2_BasePtr) //!< Freescale base pointer
#define ADC2_BASE_PTR                  (ADC2) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC3 (derived from ADC0)             ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */

/* ADC3 - Peripheral instance base addresses */
#define ADC3_BasePtr                   0x4003E000UL //!< Peripheral base address
#define ADC3                           ((ADC_Type *) ADC3_BasePtr) //!< Freescale base pointer
#define ADC3_BASE_PTR                  (ADC3) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_MKE10)               ================ */
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
   __IO uint8_t   MUXPE;                        /**< 0006: MUX Pin Enable Register                                      */
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
#define CMP_CR0_HYSTCTR_MASK                     (0x1U)                                              /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /*!< CMP0_CR1: SE Position                   */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK) /*!< CMP0_CR1                                */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /*!< CMP0_SCR: DMAEN Position                */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK) /*!< CMP0_SCR                                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /*!< CMP0_DACCR: DACEN Position              */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK) /*!< CMP0_DACCR                              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x3U)                                              /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x30U)                                             /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     (4U)                                                /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
/* ------- MUXPE Bit Fields                         ------ */
#define CMP_MUXPE_INPE_MASK                      (0x7U)                                              /*!< CMP0_MUXPE: INPE Mask                   */
#define CMP_MUXPE_INPE_SHIFT                     (0U)                                                /*!< CMP0_MUXPE: INPE Position               */
#define CMP_MUXPE_INPE(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXPE_INPE_SHIFT))&CMP_MUXPE_INPE_MASK) /*!< CMP0_MUXPE                              */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40050000UL //!< Peripheral base address
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
#define CMP1_BasePtr                   0x40051000UL //!< Peripheral base address
#define CMP1                           ((CMP_Type *) CMP1_BasePtr) //!< Freescale base pointer
#define CMP1_BASE_PTR                  (CMP1) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP2 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP2 - Peripheral instance base addresses */
#define CMP2_BasePtr                   0x40052000UL //!< Peripheral base address
#define CMP2                           ((CMP_Type *) CMP2_BasePtr) //!< Freescale base pointer
#define CMP2_BASE_PTR                  (CMP2) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP3 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP3 - Peripheral instance base addresses */
#define CMP3_BasePtr                   0x40053000UL //!< Peripheral base address
#define CMP3                           ((CMP_Type *) CMP3_BasePtr) //!< Freescale base pointer
#define CMP3_BASE_PTR                  (CMP3) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMT_Peripheral_access_layer_GROUP CMT Peripheral Access Layer
* @brief C Struct for CMT
* @{
*/

/* ================================================================================ */
/* ================           CMT (file:CMT_MKE10)                 ================ */
/* ================================================================================ */

/**
 * @brief Carrier Modulator Transmitter
 */
/**
* @addtogroup CMT_structs_GROUP CMT struct
* @brief Struct for CMT
* @{
*/
typedef struct {                                /*       CMT Structure                                                */
   __IO uint8_t   CGH1;                         /**< 0000: Carrier Generator High Data Register 1                       */
   __IO uint8_t   CGL1;                         /**< 0001: Carrier Generator Low Data Register 1                        */
   __IO uint8_t   CGH2;                         /**< 0002: Carrier Generator High Data Register 2                       */
   __IO uint8_t   CGL2;                         /**< 0003: Carrier Generator Low Data Register 2                        */
   __IO uint8_t   OC;                           /**< 0004: Output Control Register                                      */
   __IO uint8_t   MSC;                          /**< 0005: Modulator Status and Control Register                        */
   __IO uint8_t   CMD1;                         /**< 0006: Modulator Data Register Mark High                            */
   __IO uint8_t   CMD2;                         /**< 0007: Modulator Data Register Mark Low                             */
   __IO uint8_t   CMD3;                         /**< 0008: Modulator Data Register Space High                           */
   __IO uint8_t   CMD4;                         /**< 0009: Modulator Data Register Space Low                            */
   __IO uint8_t   PPS;                          /**< 000A: Primary Prescaler Register                                   */
   __IO uint8_t   DMA;                          /**< 000B: Direct Memory Access                                         */
} CMT_Type;

/**
 * @} */ /* End group CMT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMT_Register_Masks_GROUP CMT Register Masks
* @brief Register Masks for CMT
* @{
*/
/* ------- CGH1 Bit Fields                          ------ */
#define CMT_CGH1_PH_MASK                         (0xFFU)                                             /*!< CMT_CGH1: PH Mask                       */
#define CMT_CGH1_PH_SHIFT                        (0U)                                                /*!< CMT_CGH1: PH Position                   */
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK) /*!< CMT_CGH1                                */
/* ------- CGL1 Bit Fields                          ------ */
#define CMT_CGL1_PL_MASK                         (0xFFU)                                             /*!< CMT_CGL1: PL Mask                       */
#define CMT_CGL1_PL_SHIFT                        (0U)                                                /*!< CMT_CGL1: PL Position                   */
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK) /*!< CMT_CGL1                                */
/* ------- CGH2 Bit Fields                          ------ */
#define CMT_CGH2_SH_MASK                         (0xFFU)                                             /*!< CMT_CGH2: SH Mask                       */
#define CMT_CGH2_SH_SHIFT                        (0U)                                                /*!< CMT_CGH2: SH Position                   */
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK) /*!< CMT_CGH2                                */
/* ------- CGL2 Bit Fields                          ------ */
#define CMT_CGL2_SL_MASK                         (0xFFU)                                             /*!< CMT_CGL2: SL Mask                       */
#define CMT_CGL2_SL_SHIFT                        (0U)                                                /*!< CMT_CGL2: SL Position                   */
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK) /*!< CMT_CGL2                                */
/* ------- OC Bit Fields                            ------ */
#define CMT_OC_IROPEN_MASK                       (0x20U)                                             /*!< CMT_OC: IROPEN Mask                     */
#define CMT_OC_IROPEN_SHIFT                      (5U)                                                /*!< CMT_OC: IROPEN Position                 */
#define CMT_OC_IROPEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROPEN_SHIFT))&CMT_OC_IROPEN_MASK) /*!< CMT_OC                                  */
#define CMT_OC_CMTPOL_MASK                       (0x40U)                                             /*!< CMT_OC: CMTPOL Mask                     */
#define CMT_OC_CMTPOL_SHIFT                      (6U)                                                /*!< CMT_OC: CMTPOL Position                 */
#define CMT_OC_CMTPOL(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_CMTPOL_SHIFT))&CMT_OC_CMTPOL_MASK) /*!< CMT_OC                                  */
#define CMT_OC_IROL_MASK                         (0x80U)                                             /*!< CMT_OC: IROL Mask                       */
#define CMT_OC_IROL_SHIFT                        (7U)                                                /*!< CMT_OC: IROL Position                   */
#define CMT_OC_IROL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROL_SHIFT))&CMT_OC_IROL_MASK) /*!< CMT_OC                                  */
/* ------- MSC Bit Fields                           ------ */
#define CMT_MSC_MCGEN_MASK                       (0x1U)                                              /*!< CMT_MSC: MCGEN Mask                     */
#define CMT_MSC_MCGEN_SHIFT                      (0U)                                                /*!< CMT_MSC: MCGEN Position                 */
#define CMT_MSC_MCGEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_MCGEN_SHIFT))&CMT_MSC_MCGEN_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCIE_MASK                       (0x2U)                                              /*!< CMT_MSC: EOCIE Mask                     */
#define CMT_MSC_EOCIE_SHIFT                      (1U)                                                /*!< CMT_MSC: EOCIE Position                 */
#define CMT_MSC_EOCIE(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCIE_SHIFT))&CMT_MSC_EOCIE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_FSK_MASK                         (0x4U)                                              /*!< CMT_MSC: FSK Mask                       */
#define CMT_MSC_FSK_SHIFT                        (2U)                                                /*!< CMT_MSC: FSK Position                   */
#define CMT_MSC_FSK(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_MSC_FSK_SHIFT))&CMT_MSC_FSK_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_BASE_MASK                        (0x8U)                                              /*!< CMT_MSC: BASE Mask                      */
#define CMT_MSC_BASE_SHIFT                       (3U)                                                /*!< CMT_MSC: BASE Position                  */
#define CMT_MSC_BASE(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_BASE_SHIFT))&CMT_MSC_BASE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EXSPC_MASK                       (0x10U)                                             /*!< CMT_MSC: EXSPC Mask                     */
#define CMT_MSC_EXSPC_SHIFT                      (4U)                                                /*!< CMT_MSC: EXSPC Position                 */
#define CMT_MSC_EXSPC(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EXSPC_SHIFT))&CMT_MSC_EXSPC_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_CMTDIV_MASK                      (0x60U)                                             /*!< CMT_MSC: CMTDIV Mask                    */
#define CMT_MSC_CMTDIV_SHIFT                     (5U)                                                /*!< CMT_MSC: CMTDIV Position                */
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCF_MASK                        (0x80U)                                             /*!< CMT_MSC: EOCF Mask                      */
#define CMT_MSC_EOCF_SHIFT                       (7U)                                                /*!< CMT_MSC: EOCF Position                  */
#define CMT_MSC_EOCF(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCF_SHIFT))&CMT_MSC_EOCF_MASK) /*!< CMT_MSC                                 */
/* ------- CMD1 Bit Fields                          ------ */
#define CMT_CMD1_MB_MASK                         (0xFFU)                                             /*!< CMT_CMD1: MB Mask                       */
#define CMT_CMD1_MB_SHIFT                        (0U)                                                /*!< CMT_CMD1: MB Position                   */
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK) /*!< CMT_CMD1                                */
/* ------- CMD2 Bit Fields                          ------ */
#define CMT_CMD2_MB_MASK                         (0xFFU)                                             /*!< CMT_CMD2: MB Mask                       */
#define CMT_CMD2_MB_SHIFT                        (0U)                                                /*!< CMT_CMD2: MB Position                   */
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK) /*!< CMT_CMD2                                */
/* ------- CMD3 Bit Fields                          ------ */
#define CMT_CMD3_SB_MASK                         (0xFFU)                                             /*!< CMT_CMD3: SB Mask                       */
#define CMT_CMD3_SB_SHIFT                        (0U)                                                /*!< CMT_CMD3: SB Position                   */
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK) /*!< CMT_CMD3                                */
/* ------- CMD4 Bit Fields                          ------ */
#define CMT_CMD4_SB_MASK                         (0xFFU)                                             /*!< CMT_CMD4: SB Mask                       */
#define CMT_CMD4_SB_SHIFT                        (0U)                                                /*!< CMT_CMD4: SB Position                   */
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK) /*!< CMT_CMD4                                */
/* ------- PPS Bit Fields                           ------ */
#define CMT_PPS_PPSDIV_MASK                      (0xFU)                                              /*!< CMT_PPS: PPSDIV Mask                    */
#define CMT_PPS_PPSDIV_SHIFT                     (0U)                                                /*!< CMT_PPS: PPSDIV Position                */
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK) /*!< CMT_PPS                                 */
/* ------- DMA Bit Fields                           ------ */
#define CMT_DMA_DMA_MASK                         (0x1U)                                              /*!< CMT_DMA: DMA Mask                       */
#define CMT_DMA_DMA_SHIFT                        (0U)                                                /*!< CMT_DMA: DMA Position                   */
#define CMT_DMA_DMA(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_DMA_DMA_SHIFT))&CMT_DMA_DMA_MASK) /*!< CMT_DMA                                 */
/**
 * @} */ /* End group CMT_Register_Masks_GROUP 
 */

/* CMT - Peripheral instance base addresses */
#define CMT_BasePtr                    0x40042000UL //!< Peripheral base address
#define CMT                            ((CMT_Type *) CMT_BasePtr) //!< Freescale base pointer
#define CMT_BASE_PTR                   (CMT) //!< Freescale style base pointer
/**
 * @} */ /* End group CMT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC (file:CRC_0x40024000)            ================ */
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
      __IO uint32_t  DATA;                      /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: DATAL register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /**< 0001: DATALU register                                              */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: DATAH register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /**< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0004: GPOLYL register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /**< 0004: GPOLYLL register                                             */
               __IO uint8_t   GPOLYLU;          /**< 0005: GPOLYLU register                                             */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0006: GPOLYH register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /**< 0006: GPOLYHL register                                             */
               __IO uint8_t   GPOLYHU;          /**< 0007: GPOLYHU register                                             */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: Control register                                             */
      struct {                                  /**< 0000: (size=0004)                                                  */
              uint8_t   RESERVED_6[3];         
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
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
#define CRC_DATA_LL_MASK                         (0xFFU)                                             /*!< CRC_DATA: LL Mask                       */
#define CRC_DATA_LL_SHIFT                        (0U)                                                /*!< CRC_DATA: LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_LU_MASK                         (0xFF00U)                                           /*!< CRC_DATA: LU Mask                       */
#define CRC_DATA_LU_SHIFT                        (8U)                                                /*!< CRC_DATA: LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HL_MASK                         (0xFF0000U)                                         /*!< CRC_DATA: HL Mask                       */
#define CRC_DATA_HL_SHIFT                        (16U)                                               /*!< CRC_DATA: HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HU_MASK                         (0xFF000000U)                                       /*!< CRC_DATA: HU Mask                       */
#define CRC_DATA_HU_SHIFT                        (24U)                                               /*!< CRC_DATA: HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK) /*!< CRC_DATA                                */
/* ------- DATAL Bit Fields                         ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)                                           /*!< CRC_DATAL: DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    (0U)                                                /*!< CRC_DATAL: DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK) /*!< CRC_DATAL                               */
/* ------- DATALL Bit Fields                        ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)                                             /*!< CRC_DATALL: DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  (0U)                                                /*!< CRC_DATALL: DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK) /*!< CRC_DATALL                              */
/* ------- DATALU Bit Fields                        ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)                                             /*!< CRC_DATALU: DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  (0U)                                                /*!< CRC_DATALU: DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK) /*!< CRC_DATALU                              */
/* ------- DATAH Bit Fields                         ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)                                           /*!< CRC_DATAH: DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    (0U)                                                /*!< CRC_DATAH: DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK) /*!< CRC_DATAH                               */
/* ------- DATAHL Bit Fields                        ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)                                             /*!< CRC_DATAHL: DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)                                                /*!< CRC_DATAHL: DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK) /*!< CRC_DATAHL                              */
/* ------- DATAHU Bit Fields                        ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)                                             /*!< CRC_DATAHU: DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)                                                /*!< CRC_DATAHU: DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK) /*!< CRC_DATAHU                              */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)                                           /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      (0U)                                                /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)                                       /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     (16U)                                               /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /*!< CRC_GPOLY                               */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)                                           /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)                                                /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)                                             /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)                                                /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)                                             /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)                                                /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)                                           /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)                                                /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)                                             /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)                                                /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)                                             /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)                                                /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)                                        /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      (24U)                                               /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TCRC_SHIFT))&CRC_CTRL_TCRC_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_WAS_MASK                        (0x2000000U)                                        /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       (25U)                                               /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_WAS_SHIFT))&CRC_CTRL_WAS_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)                                        /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      (26U)                                               /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_FXOR_SHIFT))&CRC_CTRL_FXOR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)                                       /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      (28U)                                               /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)                                       /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       (30U)                                               /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /*!< CRC_CTRL                                */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)                                              /*!< CRC_CTRLHU: TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)                                                /*!< CRC_CTRLHU: TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TCRC_SHIFT))&CRC_CTRLHU_TCRC_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_WAS_MASK                      (0x2U)                                              /*!< CRC_CTRLHU: WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     (1U)                                                /*!< CRC_CTRLHU: WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_WAS_SHIFT))&CRC_CTRLHU_WAS_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)                                              /*!< CRC_CTRLHU: FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)                                                /*!< CRC_CTRLHU: FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_FXOR_SHIFT))&CRC_CTRLHU_FXOR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)                                             /*!< CRC_CTRLHU: TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)                                                /*!< CRC_CTRLHU: TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)                                             /*!< CRC_CTRLHU: TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     (6U)                                                /*!< CRC_CTRLHU: TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK) /*!< CRC_CTRLHU                              */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0x40024000UL //!< Peripheral base address
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
/* ================           DMA0 (file:DMA0_14CH_MKE10)          ================ */
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
   __IO uint32_t  CR;                           /**< 0000: Control Register                                             */
   __I  uint32_t  ES;                           /**< 0004: Error Status Register                                        */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  ERQ;                          /**< 000C: Enable Request Register                                      */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EEI;                          /**< 0014: Enable Error Interrupt Register                              */
   __O  uint8_t   CEEI;                         /**< 0018: Clear Enable Error Interrupt Register                        */
   __O  uint8_t   SEEI;                         /**< 0019: Set Enable Error Interrupt Register                          */
   __O  uint8_t   CERQ;                         /**< 001A: Clear Enable Request Register                                */
   __O  uint8_t   SERQ;                         /**< 001B: Set Enable Request Register                                  */
   __O  uint8_t   CDNE;                         /**< 001C: Clear DONE Status Bit Register                               */
   __O  uint8_t   SSRT;                         /**< 001D: Set START Bit Register                                       */
   __O  uint8_t   CERR;                         /**< 001E: Clear Error Register                                         */
   __O  uint8_t   CINT;                         /**< 001F: Clear Interrupt Request Register                             */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  INT;                          /**< 0024: Interrupt Request Register                                   */
        uint8_t   RESERVED_3[4];               
   __IO uint32_t  ERR;                          /**< 002C: Error Register                                               */
        uint8_t   RESERVED_4[4];               
   __I  uint32_t  HRS;                          /**< 0034: Hardware Request Status Register                             */
        uint8_t   RESERVED_5[200];             
   __IO uint8_t   DCHPRI3;                      /**< 0100: Channel 3 Priority Register                                  */
   __IO uint8_t   DCHPRI2;                      /**< 0101: Channel 2 Priority Register                                  */
   __IO uint8_t   DCHPRI1;                      /**< 0102: Channel 1 Priority Register                                  */
   __IO uint8_t   DCHPRI0;                      /**< 0103: Channel 0 Priority Register                                  */
   __IO uint8_t   DCHPRI7;                      /**< 0104: Channel 7 Priority Register                                  */
   __IO uint8_t   DCHPRI6;                      /**< 0105: Channel 6 Priority Register                                  */
   __IO uint8_t   DCHPRI5;                      /**< 0106: Channel 5 Priority Register                                  */
   __IO uint8_t   DCHPRI4;                      /**< 0107: Channel 4 Priority Register                                  */
   __IO uint8_t   DCHPRI11;                     /**< 0108: Channel 11 Priority Register                                 */
   __IO uint8_t   DCHPRI10;                     /**< 0109: Channel 10 Priority Register                                 */
   __IO uint8_t   DCHPRI9;                      /**< 010A: Channel 9 Priority Register                                  */
   __IO uint8_t   DCHPRI8;                      /**< 010B: Channel 8 Priority Register                                  */
        uint8_t   RESERVED_6[2];               
   __IO uint8_t   DCHPRI13;                     /**< 010E: Channel 3 Priority Register                                  */
   __IO uint8_t   DCHPRI12;                     /**< 010F: Channel 2 Priority Register                                  */
        uint8_t   RESERVED_7[3824];            
   struct {
      __IO uint32_t  SADDR;                     /**< 1000: Source Address                                               */
      __IO uint16_t  SOFF;                      /**< 1004: Signed Source Address Offset                                 */
      __IO uint16_t  ATTR;                      /**< 1006: Transfer Attributes                                          */
      union {                                   /**< 1000: (size=0004)                                                  */
         __IO uint32_t  NBYTES_MLNO;            /**< 1008: Minor Byte Count (Minor Loop Disabled)                       */
         __IO uint32_t  NBYTES_MLOFFNO;         /**< 1008: Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled) */
         __IO uint32_t  NBYTES_MLOFFYES;        /**< 1008: Signed Minor Loop Offset (Minor Loop and Offset Enabled)     */
      };
      __IO uint32_t  SLAST;                     /**< 100C: Last Source Address Adjustment                               */
      __IO uint32_t  DADDR;                     /**< 1010: Destination Address                                          */
      __IO uint16_t  DOFF;                      /**< 1014: Signed Destination Address Offset                            */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  CITER_ELINKNO;          /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  CITER_ELINKYES;         /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
      __IO uint32_t  DLASTSGA;                  /**< 1018: Last Destination Address Adjustment/Scatter Gather Address   */
      __IO uint16_t  CSR;                       /**< 101C: Control and Status                                           */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  BITER_ELINKNO;          /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  BITER_ELINKYES;         /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
   } TCD[14];                                   /**< 1000: (cluster: size=0x01C0, 448)                                  */
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
/* ------- CR Bit Fields                            ------ */
#define DMA_CR_EDBG_MASK                         (0x2U)                                              /*!< DMA0_CR: EDBG Mask                      */
#define DMA_CR_EDBG_SHIFT                        (1U)                                                /*!< DMA0_CR: EDBG Position                  */
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EDBG_SHIFT))&DMA_CR_EDBG_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ERCA_MASK                         (0x4U)                                              /*!< DMA0_CR: ERCA Mask                      */
#define DMA_CR_ERCA_SHIFT                        (2U)                                                /*!< DMA0_CR: ERCA Position                  */
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_ERCA_SHIFT))&DMA_CR_ERCA_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HOE_MASK                          (0x10U)                                             /*!< DMA0_CR: HOE Mask                       */
#define DMA_CR_HOE_SHIFT                         (4U)                                                /*!< DMA0_CR: HOE Position                   */
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_HOE_SHIFT))&DMA_CR_HOE_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HALT_MASK                         (0x20U)                                             /*!< DMA0_CR: HALT Mask                      */
#define DMA_CR_HALT_SHIFT                        (5U)                                                /*!< DMA0_CR: HALT Position                  */
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_HALT_SHIFT))&DMA_CR_HALT_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CLM_MASK                          (0x40U)                                             /*!< DMA0_CR: CLM Mask                       */
#define DMA_CR_CLM_SHIFT                         (6U)                                                /*!< DMA0_CR: CLM Position                   */
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_CLM_SHIFT))&DMA_CR_CLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_EMLM_MASK                         (0x80U)                                             /*!< DMA0_CR: EMLM Mask                      */
#define DMA_CR_EMLM_SHIFT                        (7U)                                                /*!< DMA0_CR: EMLM Position                  */
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EMLM_SHIFT))&DMA_CR_EMLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ECX_MASK                          (0x10000U)                                          /*!< DMA0_CR: ECX Mask                       */
#define DMA_CR_ECX_SHIFT                         (16U)                                               /*!< DMA0_CR: ECX Position                   */
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_ECX_SHIFT))&DMA_CR_ECX_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CX_MASK                           (0x20000U)                                          /*!< DMA0_CR: CX Mask                        */
#define DMA_CR_CX_SHIFT                          (17U)                                               /*!< DMA0_CR: CX Position                    */
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<DMA_CR_CX_SHIFT))&DMA_CR_CX_MASK) /*!< DMA0_CR                                 */
/* ------- ES Bit Fields                            ------ */
#define DMA_ES_DBE_MASK                          (0x1U)                                              /*!< DMA0_ES: DBE Mask                       */
#define DMA_ES_DBE_SHIFT                         (0U)                                                /*!< DMA0_ES: DBE Position                   */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DBE_SHIFT))&DMA_ES_DBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SBE_MASK                          (0x2U)                                              /*!< DMA0_ES: SBE Mask                       */
#define DMA_ES_SBE_SHIFT                         (1U)                                                /*!< DMA0_ES: SBE Position                   */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SBE_SHIFT))&DMA_ES_SBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SGE_MASK                          (0x4U)                                              /*!< DMA0_ES: SGE Mask                       */
#define DMA_ES_SGE_SHIFT                         (2U)                                                /*!< DMA0_ES: SGE Position                   */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SGE_SHIFT))&DMA_ES_SGE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_NCE_MASK                          (0x8U)                                              /*!< DMA0_ES: NCE Mask                       */
#define DMA_ES_NCE_SHIFT                         (3U)                                                /*!< DMA0_ES: NCE Position                   */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_NCE_SHIFT))&DMA_ES_NCE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DOE_MASK                          (0x10U)                                             /*!< DMA0_ES: DOE Mask                       */
#define DMA_ES_DOE_SHIFT                         (4U)                                                /*!< DMA0_ES: DOE Position                   */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DOE_SHIFT))&DMA_ES_DOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DAE_MASK                          (0x20U)                                             /*!< DMA0_ES: DAE Mask                       */
#define DMA_ES_DAE_SHIFT                         (5U)                                                /*!< DMA0_ES: DAE Position                   */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DAE_SHIFT))&DMA_ES_DAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SOE_MASK                          (0x40U)                                             /*!< DMA0_ES: SOE Mask                       */
#define DMA_ES_SOE_SHIFT                         (6U)                                                /*!< DMA0_ES: SOE Position                   */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SOE_SHIFT))&DMA_ES_SOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SAE_MASK                          (0x80U)                                             /*!< DMA0_ES: SAE Mask                       */
#define DMA_ES_SAE_SHIFT                         (7U)                                                /*!< DMA0_ES: SAE Position                   */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SAE_SHIFT))&DMA_ES_SAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ERRCHN_MASK                       (0xF00U)                                            /*!< DMA0_ES: ERRCHN Mask                    */
#define DMA_ES_ERRCHN_SHIFT                      (8U)                                                /*!< DMA0_ES: ERRCHN Position                */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_CPE_MASK                          (0x4000U)                                           /*!< DMA0_ES: CPE Mask                       */
#define DMA_ES_CPE_SHIFT                         (14U)                                               /*!< DMA0_ES: CPE Position                   */
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_CPE_SHIFT))&DMA_ES_CPE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ECX_MASK                          (0x10000U)                                          /*!< DMA0_ES: ECX Mask                       */
#define DMA_ES_ECX_SHIFT                         (16U)                                               /*!< DMA0_ES: ECX Position                   */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_ECX_SHIFT))&DMA_ES_ECX_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_VLD_MASK                          (0x80000000U)                                       /*!< DMA0_ES: VLD Mask                       */
#define DMA_ES_VLD_SHIFT                         (31U)                                               /*!< DMA0_ES: VLD Position                   */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_VLD_SHIFT))&DMA_ES_VLD_MASK) /*!< DMA0_ES                                 */
/* ------- ERQ Bit Fields                           ------ */
#define DMA_ERQ_ERQ0_MASK                        (0x1U)                                              /*!< DMA0_ERQ: ERQ0 Mask                     */
#define DMA_ERQ_ERQ0_SHIFT                       (0U)                                                /*!< DMA0_ERQ: ERQ0 Position                 */
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ0_SHIFT))&DMA_ERQ_ERQ0_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ1_MASK                        (0x2U)                                              /*!< DMA0_ERQ: ERQ1 Mask                     */
#define DMA_ERQ_ERQ1_SHIFT                       (1U)                                                /*!< DMA0_ERQ: ERQ1 Position                 */
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ1_SHIFT))&DMA_ERQ_ERQ1_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ2_MASK                        (0x4U)                                              /*!< DMA0_ERQ: ERQ2 Mask                     */
#define DMA_ERQ_ERQ2_SHIFT                       (2U)                                                /*!< DMA0_ERQ: ERQ2 Position                 */
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ2_SHIFT))&DMA_ERQ_ERQ2_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ3_MASK                        (0x8U)                                              /*!< DMA0_ERQ: ERQ3 Mask                     */
#define DMA_ERQ_ERQ3_SHIFT                       (3U)                                                /*!< DMA0_ERQ: ERQ3 Position                 */
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ3_SHIFT))&DMA_ERQ_ERQ3_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ4_MASK                        (0x10U)                                             /*!< DMA0_ERQ: ERQ4 Mask                     */
#define DMA_ERQ_ERQ4_SHIFT                       (4U)                                                /*!< DMA0_ERQ: ERQ4 Position                 */
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ4_SHIFT))&DMA_ERQ_ERQ4_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ5_MASK                        (0x20U)                                             /*!< DMA0_ERQ: ERQ5 Mask                     */
#define DMA_ERQ_ERQ5_SHIFT                       (5U)                                                /*!< DMA0_ERQ: ERQ5 Position                 */
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ5_SHIFT))&DMA_ERQ_ERQ5_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ6_MASK                        (0x40U)                                             /*!< DMA0_ERQ: ERQ6 Mask                     */
#define DMA_ERQ_ERQ6_SHIFT                       (6U)                                                /*!< DMA0_ERQ: ERQ6 Position                 */
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ6_SHIFT))&DMA_ERQ_ERQ6_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ7_MASK                        (0x80U)                                             /*!< DMA0_ERQ: ERQ7 Mask                     */
#define DMA_ERQ_ERQ7_SHIFT                       (7U)                                                /*!< DMA0_ERQ: ERQ7 Position                 */
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ7_SHIFT))&DMA_ERQ_ERQ7_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ8_MASK                        (0x100U)                                            /*!< DMA0_ERQ: ERQ8 Mask                     */
#define DMA_ERQ_ERQ8_SHIFT                       (8U)                                                /*!< DMA0_ERQ: ERQ8 Position                 */
#define DMA_ERQ_ERQ8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ8_SHIFT))&DMA_ERQ_ERQ8_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ9_MASK                        (0x200U)                                            /*!< DMA0_ERQ: ERQ9 Mask                     */
#define DMA_ERQ_ERQ9_SHIFT                       (9U)                                                /*!< DMA0_ERQ: ERQ9 Position                 */
#define DMA_ERQ_ERQ9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ9_SHIFT))&DMA_ERQ_ERQ9_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ10_MASK                       (0x400U)                                            /*!< DMA0_ERQ: ERQ10 Mask                    */
#define DMA_ERQ_ERQ10_SHIFT                      (10U)                                               /*!< DMA0_ERQ: ERQ10 Position                */
#define DMA_ERQ_ERQ10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ10_SHIFT))&DMA_ERQ_ERQ10_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ11_MASK                       (0x800U)                                            /*!< DMA0_ERQ: ERQ11 Mask                    */
#define DMA_ERQ_ERQ11_SHIFT                      (11U)                                               /*!< DMA0_ERQ: ERQ11 Position                */
#define DMA_ERQ_ERQ11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ11_SHIFT))&DMA_ERQ_ERQ11_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ12_MASK                       (0x1000U)                                           /*!< DMA0_ERQ: ERQ12 Mask                    */
#define DMA_ERQ_ERQ12_SHIFT                      (12U)                                               /*!< DMA0_ERQ: ERQ12 Position                */
#define DMA_ERQ_ERQ12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ12_SHIFT))&DMA_ERQ_ERQ12_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ13_MASK                       (0x2000U)                                           /*!< DMA0_ERQ: ERQ13 Mask                    */
#define DMA_ERQ_ERQ13_SHIFT                      (13U)                                               /*!< DMA0_ERQ: ERQ13 Position                */
#define DMA_ERQ_ERQ13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ13_SHIFT))&DMA_ERQ_ERQ13_MASK) /*!< DMA0_ERQ                                */
/* ------- EEI Bit Fields                           ------ */
#define DMA_EEI_EEI0_MASK                        (0x1U)                                              /*!< DMA0_EEI: EEI0 Mask                     */
#define DMA_EEI_EEI0_SHIFT                       (0U)                                                /*!< DMA0_EEI: EEI0 Position                 */
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI0_SHIFT))&DMA_EEI_EEI0_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI1_MASK                        (0x2U)                                              /*!< DMA0_EEI: EEI1 Mask                     */
#define DMA_EEI_EEI1_SHIFT                       (1U)                                                /*!< DMA0_EEI: EEI1 Position                 */
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI1_SHIFT))&DMA_EEI_EEI1_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI2_MASK                        (0x4U)                                              /*!< DMA0_EEI: EEI2 Mask                     */
#define DMA_EEI_EEI2_SHIFT                       (2U)                                                /*!< DMA0_EEI: EEI2 Position                 */
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI2_SHIFT))&DMA_EEI_EEI2_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI3_MASK                        (0x8U)                                              /*!< DMA0_EEI: EEI3 Mask                     */
#define DMA_EEI_EEI3_SHIFT                       (3U)                                                /*!< DMA0_EEI: EEI3 Position                 */
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI3_SHIFT))&DMA_EEI_EEI3_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI4_MASK                        (0x10U)                                             /*!< DMA0_EEI: EEI4 Mask                     */
#define DMA_EEI_EEI4_SHIFT                       (4U)                                                /*!< DMA0_EEI: EEI4 Position                 */
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI4_SHIFT))&DMA_EEI_EEI4_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI5_MASK                        (0x20U)                                             /*!< DMA0_EEI: EEI5 Mask                     */
#define DMA_EEI_EEI5_SHIFT                       (5U)                                                /*!< DMA0_EEI: EEI5 Position                 */
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI5_SHIFT))&DMA_EEI_EEI5_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI6_MASK                        (0x40U)                                             /*!< DMA0_EEI: EEI6 Mask                     */
#define DMA_EEI_EEI6_SHIFT                       (6U)                                                /*!< DMA0_EEI: EEI6 Position                 */
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI6_SHIFT))&DMA_EEI_EEI6_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI7_MASK                        (0x80U)                                             /*!< DMA0_EEI: EEI7 Mask                     */
#define DMA_EEI_EEI7_SHIFT                       (7U)                                                /*!< DMA0_EEI: EEI7 Position                 */
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI7_SHIFT))&DMA_EEI_EEI7_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI8_MASK                        (0x100U)                                            /*!< DMA0_EEI: EEI8 Mask                     */
#define DMA_EEI_EEI8_SHIFT                       (8U)                                                /*!< DMA0_EEI: EEI8 Position                 */
#define DMA_EEI_EEI8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI8_SHIFT))&DMA_EEI_EEI8_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI9_MASK                        (0x200U)                                            /*!< DMA0_EEI: EEI9 Mask                     */
#define DMA_EEI_EEI9_SHIFT                       (9U)                                                /*!< DMA0_EEI: EEI9 Position                 */
#define DMA_EEI_EEI9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI9_SHIFT))&DMA_EEI_EEI9_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI10_MASK                       (0x400U)                                            /*!< DMA0_EEI: EEI10 Mask                    */
#define DMA_EEI_EEI10_SHIFT                      (10U)                                               /*!< DMA0_EEI: EEI10 Position                */
#define DMA_EEI_EEI10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI10_SHIFT))&DMA_EEI_EEI10_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI11_MASK                       (0x800U)                                            /*!< DMA0_EEI: EEI11 Mask                    */
#define DMA_EEI_EEI11_SHIFT                      (11U)                                               /*!< DMA0_EEI: EEI11 Position                */
#define DMA_EEI_EEI11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI11_SHIFT))&DMA_EEI_EEI11_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI12_MASK                       (0x1000U)                                           /*!< DMA0_EEI: EEI12 Mask                    */
#define DMA_EEI_EEI12_SHIFT                      (12U)                                               /*!< DMA0_EEI: EEI12 Position                */
#define DMA_EEI_EEI12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI12_SHIFT))&DMA_EEI_EEI12_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI13_MASK                       (0x2000U)                                           /*!< DMA0_EEI: EEI13 Mask                    */
#define DMA_EEI_EEI13_SHIFT                      (13U)                                               /*!< DMA0_EEI: EEI13 Position                */
#define DMA_EEI_EEI13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI13_SHIFT))&DMA_EEI_EEI13_MASK) /*!< DMA0_EEI                                */
/* ------- CEEI Bit Fields                          ------ */
#define DMA_CEEI_CEEI_MASK                       (0xFU)                                              /*!< DMA0_CEEI: CEEI Mask                    */
#define DMA_CEEI_CEEI_SHIFT                      (0U)                                                /*!< DMA0_CEEI: CEEI Position                */
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_CAEE_MASK                       (0x40U)                                             /*!< DMA0_CEEI: CAEE Mask                    */
#define DMA_CEEI_CAEE_SHIFT                      (6U)                                                /*!< DMA0_CEEI: CAEE Position                */
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CAEE_SHIFT))&DMA_CEEI_CAEE_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_CEEI: NOP Mask                     */
#define DMA_CEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_CEEI: NOP Position                 */
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_NOP_SHIFT))&DMA_CEEI_NOP_MASK) /*!< DMA0_CEEI                               */
/* ------- SEEI Bit Fields                          ------ */
#define DMA_SEEI_SEEI_MASK                       (0xFU)                                              /*!< DMA0_SEEI: SEEI Mask                    */
#define DMA_SEEI_SEEI_SHIFT                      (0U)                                                /*!< DMA0_SEEI: SEEI Position                */
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_SAEE_MASK                       (0x40U)                                             /*!< DMA0_SEEI: SAEE Mask                    */
#define DMA_SEEI_SAEE_SHIFT                      (6U)                                                /*!< DMA0_SEEI: SAEE Position                */
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SAEE_SHIFT))&DMA_SEEI_SAEE_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_SEEI: NOP Mask                     */
#define DMA_SEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_SEEI: NOP Position                 */
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_NOP_SHIFT))&DMA_SEEI_NOP_MASK) /*!< DMA0_SEEI                               */
/* ------- CERQ Bit Fields                          ------ */
#define DMA_CERQ_CERQ_MASK                       (0xFU)                                              /*!< DMA0_CERQ: CERQ Mask                    */
#define DMA_CERQ_CERQ_SHIFT                      (0U)                                                /*!< DMA0_CERQ: CERQ Position                */
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_CAER_MASK                       (0x40U)                                             /*!< DMA0_CERQ: CAER Mask                    */
#define DMA_CERQ_CAER_SHIFT                      (6U)                                                /*!< DMA0_CERQ: CAER Position                */
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CAER_SHIFT))&DMA_CERQ_CAER_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERQ: NOP Mask                     */
#define DMA_CERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERQ: NOP Position                 */
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_NOP_SHIFT))&DMA_CERQ_NOP_MASK) /*!< DMA0_CERQ                               */
/* ------- SERQ Bit Fields                          ------ */
#define DMA_SERQ_SERQ_MASK                       (0xFU)                                              /*!< DMA0_SERQ: SERQ Mask                    */
#define DMA_SERQ_SERQ_SHIFT                      (0U)                                                /*!< DMA0_SERQ: SERQ Position                */
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_SAER_MASK                       (0x40U)                                             /*!< DMA0_SERQ: SAER Mask                    */
#define DMA_SERQ_SAER_SHIFT                      (6U)                                                /*!< DMA0_SERQ: SAER Position                */
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SAER_SHIFT))&DMA_SERQ_SAER_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_SERQ: NOP Mask                     */
#define DMA_SERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_SERQ: NOP Position                 */
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_NOP_SHIFT))&DMA_SERQ_NOP_MASK) /*!< DMA0_SERQ                               */
/* ------- CDNE Bit Fields                          ------ */
#define DMA_CDNE_CDNE_MASK                       (0xFU)                                              /*!< DMA0_CDNE: CDNE Mask                    */
#define DMA_CDNE_CDNE_SHIFT                      (0U)                                                /*!< DMA0_CDNE: CDNE Position                */
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_CADN_MASK                       (0x40U)                                             /*!< DMA0_CDNE: CADN Mask                    */
#define DMA_CDNE_CADN_SHIFT                      (6U)                                                /*!< DMA0_CDNE: CADN Position                */
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CADN_SHIFT))&DMA_CDNE_CADN_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_NOP_MASK                        (0x80U)                                             /*!< DMA0_CDNE: NOP Mask                     */
#define DMA_CDNE_NOP_SHIFT                       (7U)                                                /*!< DMA0_CDNE: NOP Position                 */
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_NOP_SHIFT))&DMA_CDNE_NOP_MASK) /*!< DMA0_CDNE                               */
/* ------- SSRT Bit Fields                          ------ */
#define DMA_SSRT_SSRT_MASK                       (0xFU)                                              /*!< DMA0_SSRT: SSRT Mask                    */
#define DMA_SSRT_SSRT_SHIFT                      (0U)                                                /*!< DMA0_SSRT: SSRT Position                */
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_SAST_MASK                       (0x40U)                                             /*!< DMA0_SSRT: SAST Mask                    */
#define DMA_SSRT_SAST_SHIFT                      (6U)                                                /*!< DMA0_SSRT: SAST Position                */
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SAST_SHIFT))&DMA_SSRT_SAST_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_NOP_MASK                        (0x80U)                                             /*!< DMA0_SSRT: NOP Mask                     */
#define DMA_SSRT_NOP_SHIFT                       (7U)                                                /*!< DMA0_SSRT: NOP Position                 */
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_NOP_SHIFT))&DMA_SSRT_NOP_MASK) /*!< DMA0_SSRT                               */
/* ------- CERR Bit Fields                          ------ */
#define DMA_CERR_CERR_MASK                       (0xFU)                                              /*!< DMA0_CERR: CERR Mask                    */
#define DMA_CERR_CERR_SHIFT                      (0U)                                                /*!< DMA0_CERR: CERR Position                */
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_CAEI_MASK                       (0x40U)                                             /*!< DMA0_CERR: CAEI Mask                    */
#define DMA_CERR_CAEI_SHIFT                      (6U)                                                /*!< DMA0_CERR: CAEI Position                */
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CAEI_SHIFT))&DMA_CERR_CAEI_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERR: NOP Mask                     */
#define DMA_CERR_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERR: NOP Position                 */
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERR_NOP_SHIFT))&DMA_CERR_NOP_MASK) /*!< DMA0_CERR                               */
/* ------- CINT Bit Fields                          ------ */
#define DMA_CINT_CINT_MASK                       (0xFU)                                              /*!< DMA0_CINT: CINT Mask                    */
#define DMA_CINT_CINT_SHIFT                      (0U)                                                /*!< DMA0_CINT: CINT Position                */
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_CAIR_MASK                       (0x40U)                                             /*!< DMA0_CINT: CAIR Mask                    */
#define DMA_CINT_CAIR_SHIFT                      (6U)                                                /*!< DMA0_CINT: CAIR Position                */
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CAIR_SHIFT))&DMA_CINT_CAIR_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_NOP_MASK                        (0x80U)                                             /*!< DMA0_CINT: NOP Mask                     */
#define DMA_CINT_NOP_SHIFT                       (7U)                                                /*!< DMA0_CINT: NOP Position                 */
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CINT_NOP_SHIFT))&DMA_CINT_NOP_MASK) /*!< DMA0_CINT                               */
/* ------- INT Bit Fields                           ------ */
#define DMA_INT_INT0_MASK                        (0x1U)                                              /*!< DMA0_INT: INT0 Mask                     */
#define DMA_INT_INT0_SHIFT                       (0U)                                                /*!< DMA0_INT: INT0 Position                 */
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT0_SHIFT))&DMA_INT_INT0_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT1_MASK                        (0x2U)                                              /*!< DMA0_INT: INT1 Mask                     */
#define DMA_INT_INT1_SHIFT                       (1U)                                                /*!< DMA0_INT: INT1 Position                 */
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT1_SHIFT))&DMA_INT_INT1_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT2_MASK                        (0x4U)                                              /*!< DMA0_INT: INT2 Mask                     */
#define DMA_INT_INT2_SHIFT                       (2U)                                                /*!< DMA0_INT: INT2 Position                 */
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT2_SHIFT))&DMA_INT_INT2_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT3_MASK                        (0x8U)                                              /*!< DMA0_INT: INT3 Mask                     */
#define DMA_INT_INT3_SHIFT                       (3U)                                                /*!< DMA0_INT: INT3 Position                 */
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT3_SHIFT))&DMA_INT_INT3_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT4_MASK                        (0x10U)                                             /*!< DMA0_INT: INT4 Mask                     */
#define DMA_INT_INT4_SHIFT                       (4U)                                                /*!< DMA0_INT: INT4 Position                 */
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT4_SHIFT))&DMA_INT_INT4_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT5_MASK                        (0x20U)                                             /*!< DMA0_INT: INT5 Mask                     */
#define DMA_INT_INT5_SHIFT                       (5U)                                                /*!< DMA0_INT: INT5 Position                 */
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT5_SHIFT))&DMA_INT_INT5_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT6_MASK                        (0x40U)                                             /*!< DMA0_INT: INT6 Mask                     */
#define DMA_INT_INT6_SHIFT                       (6U)                                                /*!< DMA0_INT: INT6 Position                 */
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT6_SHIFT))&DMA_INT_INT6_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT7_MASK                        (0x80U)                                             /*!< DMA0_INT: INT7 Mask                     */
#define DMA_INT_INT7_SHIFT                       (7U)                                                /*!< DMA0_INT: INT7 Position                 */
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT7_SHIFT))&DMA_INT_INT7_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT8_MASK                        (0x100U)                                            /*!< DMA0_INT: INT8 Mask                     */
#define DMA_INT_INT8_SHIFT                       (8U)                                                /*!< DMA0_INT: INT8 Position                 */
#define DMA_INT_INT8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT8_SHIFT))&DMA_INT_INT8_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT9_MASK                        (0x200U)                                            /*!< DMA0_INT: INT9 Mask                     */
#define DMA_INT_INT9_SHIFT                       (9U)                                                /*!< DMA0_INT: INT9 Position                 */
#define DMA_INT_INT9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT9_SHIFT))&DMA_INT_INT9_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT10_MASK                       (0x400U)                                            /*!< DMA0_INT: INT10 Mask                    */
#define DMA_INT_INT10_SHIFT                      (10U)                                               /*!< DMA0_INT: INT10 Position                */
#define DMA_INT_INT10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT10_SHIFT))&DMA_INT_INT10_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT11_MASK                       (0x800U)                                            /*!< DMA0_INT: INT11 Mask                    */
#define DMA_INT_INT11_SHIFT                      (11U)                                               /*!< DMA0_INT: INT11 Position                */
#define DMA_INT_INT11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT11_SHIFT))&DMA_INT_INT11_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT12_MASK                       (0x1000U)                                           /*!< DMA0_INT: INT12 Mask                    */
#define DMA_INT_INT12_SHIFT                      (12U)                                               /*!< DMA0_INT: INT12 Position                */
#define DMA_INT_INT12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT12_SHIFT))&DMA_INT_INT12_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT13_MASK                       (0x2000U)                                           /*!< DMA0_INT: INT13 Mask                    */
#define DMA_INT_INT13_SHIFT                      (13U)                                               /*!< DMA0_INT: INT13 Position                */
#define DMA_INT_INT13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT13_SHIFT))&DMA_INT_INT13_MASK) /*!< DMA0_INT                                */
/* ------- ERR Bit Fields                           ------ */
#define DMA_ERR_ERR0_MASK                        (0x1U)                                              /*!< DMA0_ERR: ERR0 Mask                     */
#define DMA_ERR_ERR0_SHIFT                       (0U)                                                /*!< DMA0_ERR: ERR0 Position                 */
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR0_SHIFT))&DMA_ERR_ERR0_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR1_MASK                        (0x2U)                                              /*!< DMA0_ERR: ERR1 Mask                     */
#define DMA_ERR_ERR1_SHIFT                       (1U)                                                /*!< DMA0_ERR: ERR1 Position                 */
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR1_SHIFT))&DMA_ERR_ERR1_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR2_MASK                        (0x4U)                                              /*!< DMA0_ERR: ERR2 Mask                     */
#define DMA_ERR_ERR2_SHIFT                       (2U)                                                /*!< DMA0_ERR: ERR2 Position                 */
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR2_SHIFT))&DMA_ERR_ERR2_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR3_MASK                        (0x8U)                                              /*!< DMA0_ERR: ERR3 Mask                     */
#define DMA_ERR_ERR3_SHIFT                       (3U)                                                /*!< DMA0_ERR: ERR3 Position                 */
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR3_SHIFT))&DMA_ERR_ERR3_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR4_MASK                        (0x10U)                                             /*!< DMA0_ERR: ERR4 Mask                     */
#define DMA_ERR_ERR4_SHIFT                       (4U)                                                /*!< DMA0_ERR: ERR4 Position                 */
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR4_SHIFT))&DMA_ERR_ERR4_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR5_MASK                        (0x20U)                                             /*!< DMA0_ERR: ERR5 Mask                     */
#define DMA_ERR_ERR5_SHIFT                       (5U)                                                /*!< DMA0_ERR: ERR5 Position                 */
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR5_SHIFT))&DMA_ERR_ERR5_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR6_MASK                        (0x40U)                                             /*!< DMA0_ERR: ERR6 Mask                     */
#define DMA_ERR_ERR6_SHIFT                       (6U)                                                /*!< DMA0_ERR: ERR6 Position                 */
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR6_SHIFT))&DMA_ERR_ERR6_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR7_MASK                        (0x80U)                                             /*!< DMA0_ERR: ERR7 Mask                     */
#define DMA_ERR_ERR7_SHIFT                       (7U)                                                /*!< DMA0_ERR: ERR7 Position                 */
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR7_SHIFT))&DMA_ERR_ERR7_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR8_MASK                        (0x100U)                                            /*!< DMA0_ERR: ERR8 Mask                     */
#define DMA_ERR_ERR8_SHIFT                       (8U)                                                /*!< DMA0_ERR: ERR8 Position                 */
#define DMA_ERR_ERR8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR8_SHIFT))&DMA_ERR_ERR8_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR9_MASK                        (0x200U)                                            /*!< DMA0_ERR: ERR9 Mask                     */
#define DMA_ERR_ERR9_SHIFT                       (9U)                                                /*!< DMA0_ERR: ERR9 Position                 */
#define DMA_ERR_ERR9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR9_SHIFT))&DMA_ERR_ERR9_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR10_MASK                       (0x400U)                                            /*!< DMA0_ERR: ERR10 Mask                    */
#define DMA_ERR_ERR10_SHIFT                      (10U)                                               /*!< DMA0_ERR: ERR10 Position                */
#define DMA_ERR_ERR10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR10_SHIFT))&DMA_ERR_ERR10_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR11_MASK                       (0x800U)                                            /*!< DMA0_ERR: ERR11 Mask                    */
#define DMA_ERR_ERR11_SHIFT                      (11U)                                               /*!< DMA0_ERR: ERR11 Position                */
#define DMA_ERR_ERR11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR11_SHIFT))&DMA_ERR_ERR11_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR12_MASK                       (0x1000U)                                           /*!< DMA0_ERR: ERR12 Mask                    */
#define DMA_ERR_ERR12_SHIFT                      (12U)                                               /*!< DMA0_ERR: ERR12 Position                */
#define DMA_ERR_ERR12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR12_SHIFT))&DMA_ERR_ERR12_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR13_MASK                       (0x2000U)                                           /*!< DMA0_ERR: ERR13 Mask                    */
#define DMA_ERR_ERR13_SHIFT                      (13U)                                               /*!< DMA0_ERR: ERR13 Position                */
#define DMA_ERR_ERR13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR13_SHIFT))&DMA_ERR_ERR13_MASK) /*!< DMA0_ERR                                */
/* ------- HRS Bit Fields                           ------ */
#define DMA_HRS_HRS0_MASK                        (0x1U)                                              /*!< DMA0_HRS: HRS0 Mask                     */
#define DMA_HRS_HRS0_SHIFT                       (0U)                                                /*!< DMA0_HRS: HRS0 Position                 */
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS0_SHIFT))&DMA_HRS_HRS0_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS1_MASK                        (0x2U)                                              /*!< DMA0_HRS: HRS1 Mask                     */
#define DMA_HRS_HRS1_SHIFT                       (1U)                                                /*!< DMA0_HRS: HRS1 Position                 */
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS1_SHIFT))&DMA_HRS_HRS1_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS2_MASK                        (0x4U)                                              /*!< DMA0_HRS: HRS2 Mask                     */
#define DMA_HRS_HRS2_SHIFT                       (2U)                                                /*!< DMA0_HRS: HRS2 Position                 */
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS2_SHIFT))&DMA_HRS_HRS2_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS3_MASK                        (0x8U)                                              /*!< DMA0_HRS: HRS3 Mask                     */
#define DMA_HRS_HRS3_SHIFT                       (3U)                                                /*!< DMA0_HRS: HRS3 Position                 */
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS3_SHIFT))&DMA_HRS_HRS3_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS4_MASK                        (0x10U)                                             /*!< DMA0_HRS: HRS4 Mask                     */
#define DMA_HRS_HRS4_SHIFT                       (4U)                                                /*!< DMA0_HRS: HRS4 Position                 */
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS4_SHIFT))&DMA_HRS_HRS4_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS5_MASK                        (0x20U)                                             /*!< DMA0_HRS: HRS5 Mask                     */
#define DMA_HRS_HRS5_SHIFT                       (5U)                                                /*!< DMA0_HRS: HRS5 Position                 */
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS5_SHIFT))&DMA_HRS_HRS5_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS6_MASK                        (0x40U)                                             /*!< DMA0_HRS: HRS6 Mask                     */
#define DMA_HRS_HRS6_SHIFT                       (6U)                                                /*!< DMA0_HRS: HRS6 Position                 */
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS6_SHIFT))&DMA_HRS_HRS6_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS7_MASK                        (0x80U)                                             /*!< DMA0_HRS: HRS7 Mask                     */
#define DMA_HRS_HRS7_SHIFT                       (7U)                                                /*!< DMA0_HRS: HRS7 Position                 */
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS7_SHIFT))&DMA_HRS_HRS7_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS8_MASK                        (0x100U)                                            /*!< DMA0_HRS: HRS8 Mask                     */
#define DMA_HRS_HRS8_SHIFT                       (8U)                                                /*!< DMA0_HRS: HRS8 Position                 */
#define DMA_HRS_HRS8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS8_SHIFT))&DMA_HRS_HRS8_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS9_MASK                        (0x200U)                                            /*!< DMA0_HRS: HRS9 Mask                     */
#define DMA_HRS_HRS9_SHIFT                       (9U)                                                /*!< DMA0_HRS: HRS9 Position                 */
#define DMA_HRS_HRS9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS9_SHIFT))&DMA_HRS_HRS9_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS10_MASK                       (0x400U)                                            /*!< DMA0_HRS: HRS10 Mask                    */
#define DMA_HRS_HRS10_SHIFT                      (10U)                                               /*!< DMA0_HRS: HRS10 Position                */
#define DMA_HRS_HRS10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS10_SHIFT))&DMA_HRS_HRS10_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS11_MASK                       (0x800U)                                            /*!< DMA0_HRS: HRS11 Mask                    */
#define DMA_HRS_HRS11_SHIFT                      (11U)                                               /*!< DMA0_HRS: HRS11 Position                */
#define DMA_HRS_HRS11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS11_SHIFT))&DMA_HRS_HRS11_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS12_MASK                       (0x1000U)                                           /*!< DMA0_HRS: HRS12 Mask                    */
#define DMA_HRS_HRS12_SHIFT                      (12U)                                               /*!< DMA0_HRS: HRS12 Position                */
#define DMA_HRS_HRS12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS12_SHIFT))&DMA_HRS_HRS12_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS13_MASK                       (0x2000U)                                           /*!< DMA0_HRS: HRS13 Mask                    */
#define DMA_HRS_HRS13_SHIFT                      (13U)                                               /*!< DMA0_HRS: HRS13 Position                */
#define DMA_HRS_HRS13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS13_SHIFT))&DMA_HRS_HRS13_MASK) /*!< DMA0_HRS                                */
/* ------- DCHPRI Bit Fields                        ------ */
#define DMA_DCHPRI_CHPRI_MASK                    (0xFU)                                              /*!< DMA0_DCHPRI: CHPRI Mask                 */
#define DMA_DCHPRI_CHPRI_SHIFT                   (0U)                                                /*!< DMA0_DCHPRI: CHPRI Position             */
#define DMA_DCHPRI_CHPRI(x)                      (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_CHPRI_SHIFT))&DMA_DCHPRI_CHPRI_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_DPA_MASK                      (0x40U)                                             /*!< DMA0_DCHPRI: DPA Mask                   */
#define DMA_DCHPRI_DPA_SHIFT                     (6U)                                                /*!< DMA0_DCHPRI: DPA Position               */
#define DMA_DCHPRI_DPA(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_DPA_SHIFT))&DMA_DCHPRI_DPA_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_ECP_MASK                      (0x80U)                                             /*!< DMA0_DCHPRI: ECP Mask                   */
#define DMA_DCHPRI_ECP_SHIFT                     (7U)                                                /*!< DMA0_DCHPRI: ECP Position               */
#define DMA_DCHPRI_ECP(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_ECP_SHIFT))&DMA_DCHPRI_ECP_MASK) /*!< DMA0_DCHPRI                             */
/* ------- DCHPRI1 Bit Fields                       ------ */
#define DMA_DCHPRI1_CHPRI_MASK                   (0xFU)                                              /*!< DMA0_DCHPRI1: CHPRI Mask                */
#define DMA_DCHPRI1_CHPRI_SHIFT                  (0U)                                                /*!< DMA0_DCHPRI1: CHPRI Position            */
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_CHPRI_SHIFT))&DMA_DCHPRI1_CHPRI_MASK) /*!< DMA0_DCHPRI1                            */
#define DMA_DCHPRI1_DPA_MASK                     (0x40U)                                             /*!< DMA0_DCHPRI1: DPA Mask                  */
#define DMA_DCHPRI1_DPA_SHIFT                    (6U)                                                /*!< DMA0_DCHPRI1: DPA Position              */
#define DMA_DCHPRI1_DPA(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_DPA_SHIFT))&DMA_DCHPRI1_DPA_MASK) /*!< DMA0_DCHPRI1                            */
#define DMA_DCHPRI1_ECP_MASK                     (0x80U)                                             /*!< DMA0_DCHPRI1: ECP Mask                  */
#define DMA_DCHPRI1_ECP_SHIFT                    (7U)                                                /*!< DMA0_DCHPRI1: ECP Position              */
#define DMA_DCHPRI1_ECP(x)                       (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_ECP_SHIFT))&DMA_DCHPRI1_ECP_MASK) /*!< DMA0_DCHPRI1                            */
/* ------- SADDR Bit Fields                         ------ */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SADDR: SADDR Mask                  */
#define DMA_SADDR_SADDR_SHIFT                    (0U)                                                /*!< DMA0_SADDR: SADDR Position              */
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK) /*!< DMA0_SADDR                              */
/* ------- SOFF Bit Fields                          ------ */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_SOFF: SOFF Mask                    */
#define DMA_SOFF_SOFF_SHIFT                      (0U)                                                /*!< DMA0_SOFF: SOFF Position                */
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK) /*!< DMA0_SOFF                               */
/* ------- ATTR Bit Fields                          ------ */
#define DMA_ATTR_DSIZE_MASK                      (0x7U)                                              /*!< DMA0_ATTR: DSIZE Mask                   */
#define DMA_ATTR_DSIZE_SHIFT                     (0U)                                                /*!< DMA0_ATTR: DSIZE Position               */
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_DMOD_MASK                       (0xF8U)                                             /*!< DMA0_ATTR: DMOD Mask                    */
#define DMA_ATTR_DMOD_SHIFT                      (3U)                                                /*!< DMA0_ATTR: DMOD Position                */
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SSIZE_MASK                      (0x700U)                                            /*!< DMA0_ATTR: SSIZE Mask                   */
#define DMA_ATTR_SSIZE_SHIFT                     (8U)                                                /*!< DMA0_ATTR: SSIZE Position               */
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SMOD_MASK                       (0xF800U)                                           /*!< DMA0_ATTR: SMOD Mask                    */
#define DMA_ATTR_SMOD_SHIFT                      (11U)                                               /*!< DMA0_ATTR: SMOD Position                */
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK) /*!< DMA0_ATTR                               */
/* ------- NBYTES_MLNO Bit Fields                   ------ */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)                                       /*!< DMA0_NBYTES_MLNO: NBYTES Mask           */
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)                                                /*!< DMA0_NBYTES_MLNO: NBYTES Position       */
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLNO                        */
/* ------- NBYTES_MLOFFNO Bit Fields                ------ */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)                                       /*!< DMA0_NBYTES_MLOFFNO: NBYTES Mask        */
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)                                                /*!< DMA0_NBYTES_MLOFFNO: NBYTES Position    */
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFNO: DMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)                                               /*!< DMA0_NBYTES_MLOFFNO: DMLOE Position     */
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_DMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFNO: SMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)                                               /*!< DMA0_NBYTES_MLOFFNO: SMLOE Position     */
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_SMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
/* ------- NBYTES_MLOFFYES Bit Fields               ------ */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)                                            /*!< DMA0_NBYTES_MLOFFYES: NBYTES Mask       */
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)                                                /*!< DMA0_NBYTES_MLOFFYES: NBYTES Position   */
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)                                       /*!< DMA0_NBYTES_MLOFFYES: MLOFF Mask        */
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)                                               /*!< DMA0_NBYTES_MLOFFYES: MLOFF Position    */
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFYES: DMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)                                               /*!< DMA0_NBYTES_MLOFFYES: DMLOE Position    */
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_DMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFYES: SMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)                                               /*!< DMA0_NBYTES_MLOFFYES: SMLOE Position    */
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_SMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
/* ------- SLAST Bit Fields                         ------ */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SLAST: SLAST Mask                  */
#define DMA_SLAST_SLAST_SHIFT                    (0U)                                                /*!< DMA0_SLAST: SLAST Position              */
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK) /*!< DMA0_SLAST                              */
/* ------- DADDR Bit Fields                         ------ */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_DADDR: DADDR Mask                  */
#define DMA_DADDR_DADDR_SHIFT                    (0U)                                                /*!< DMA0_DADDR: DADDR Position              */
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK) /*!< DMA0_DADDR                              */
/* ------- DOFF Bit Fields                          ------ */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_DOFF: DOFF Mask                    */
#define DMA_DOFF_DOFF_SHIFT                      (0U)                                                /*!< DMA0_DOFF: DOFF Position                */
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK) /*!< DMA0_DOFF                               */
/* ------- CITER_ELINKNO Bit Fields                 ------ */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)                                           /*!< DMA0_CITER_ELINKNO: CITER Mask          */
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)                                                /*!< DMA0_CITER_ELINKNO: CITER Position      */
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK) /*!< DMA0_CITER_ELINKNO                      */
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_CITER_ELINKNO: ELINK Mask          */
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_CITER_ELINKNO: ELINK Position      */
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_ELINK_SHIFT))&DMA_CITER_ELINKNO_ELINK_MASK) /*!< DMA0_CITER_ELINKNO                      */
/* ------- CITER_ELINKYES Bit Fields                ------ */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)                                            /*!< DMA0_CITER_ELINKYES: CITER Mask         */
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)                                                /*!< DMA0_CITER_ELINKYES: CITER Position     */
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_CITER_ELINKYES: LINKCH Mask        */
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_CITER_ELINKYES: LINKCH Position    */
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_CITER_ELINKYES: ELINK Mask         */
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_CITER_ELINKYES: ELINK Position     */
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_ELINK_SHIFT))&DMA_CITER_ELINKYES_ELINK_MASK) /*!< DMA0_CITER_ELINKYES                     */
/* ------- DLASTSGA Bit Fields                      ------ */
#define DMA_DLASTSGA_DLASTSGA_MASK               (0xFFFFFFFFU)                                       /*!< DMA0_DLASTSGA: DLASTSGA Mask            */
#define DMA_DLASTSGA_DLASTSGA_SHIFT              (0U)                                                /*!< DMA0_DLASTSGA: DLASTSGA Position        */
#define DMA_DLASTSGA_DLASTSGA(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_DLASTSGA_DLASTSGA_SHIFT))&DMA_DLASTSGA_DLASTSGA_MASK) /*!< DMA0_DLASTSGA                           */
/* ------- CSR Bit Fields                           ------ */
#define DMA_CSR_START_MASK                       (0x1U)                                              /*!< DMA0_CSR: START Mask                    */
#define DMA_CSR_START_SHIFT                      (0U)                                                /*!< DMA0_CSR: START Position                */
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_CSR_START_SHIFT))&DMA_CSR_START_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTMAJOR_MASK                    (0x2U)                                              /*!< DMA0_CSR: INTMAJOR Mask                 */
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)                                                /*!< DMA0_CSR: INTMAJOR Position             */
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTMAJOR_SHIFT))&DMA_CSR_INTMAJOR_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTHALF_MASK                     (0x4U)                                              /*!< DMA0_CSR: INTHALF Mask                  */
#define DMA_CSR_INTHALF_SHIFT                    (2U)                                                /*!< DMA0_CSR: INTHALF Position              */
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTHALF_SHIFT))&DMA_CSR_INTHALF_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DREQ_MASK                        (0x8U)                                              /*!< DMA0_CSR: DREQ Mask                     */
#define DMA_CSR_DREQ_SHIFT                       (3U)                                                /*!< DMA0_CSR: DREQ Position                 */
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DREQ_SHIFT))&DMA_CSR_DREQ_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ESG_MASK                         (0x10U)                                             /*!< DMA0_CSR: ESG Mask                      */
#define DMA_CSR_ESG_SHIFT                        (4U)                                                /*!< DMA0_CSR: ESG Position                  */
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ESG_SHIFT))&DMA_CSR_ESG_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORELINK_MASK                  (0x20U)                                             /*!< DMA0_CSR: MAJORELINK Mask               */
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)                                                /*!< DMA0_CSR: MAJORELINK Position           */
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORELINK_SHIFT))&DMA_CSR_MAJORELINK_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ACTIVE_MASK                      (0x40U)                                             /*!< DMA0_CSR: ACTIVE Mask                   */
#define DMA_CSR_ACTIVE_SHIFT                     (6U)                                                /*!< DMA0_CSR: ACTIVE Position               */
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ACTIVE_SHIFT))&DMA_CSR_ACTIVE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DONE_MASK                        (0x80U)                                             /*!< DMA0_CSR: DONE Mask                     */
#define DMA_CSR_DONE_SHIFT                       (7U)                                                /*!< DMA0_CSR: DONE Position                 */
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DONE_SHIFT))&DMA_CSR_DONE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORLINKCH_MASK                 (0xF00U)                                            /*!< DMA0_CSR: MAJORLINKCH Mask              */
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)                                                /*!< DMA0_CSR: MAJORLINKCH Position          */
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_BWC_MASK                         (0xC000U)                                           /*!< DMA0_CSR: BWC Mask                      */
#define DMA_CSR_BWC_SHIFT                        (14U)                                               /*!< DMA0_CSR: BWC Position                  */
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK) /*!< DMA0_CSR                                */
/* ------- BITER_ELINKNO Bit Fields                 ------ */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)                                           /*!< DMA0_BITER_ELINKNO: BITER Mask          */
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)                                                /*!< DMA0_BITER_ELINKNO: BITER Position      */
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK) /*!< DMA0_BITER_ELINKNO                      */
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_BITER_ELINKNO: ELINK Mask          */
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_BITER_ELINKNO: ELINK Position      */
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_ELINK_SHIFT))&DMA_BITER_ELINKNO_ELINK_MASK) /*!< DMA0_BITER_ELINKNO                      */
/* ------- BITER_ELINKYES Bit Fields                ------ */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)                                            /*!< DMA0_BITER_ELINKYES: BITER Mask         */
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)                                                /*!< DMA0_BITER_ELINKYES: BITER Position     */
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_BITER_ELINKYES: LINKCH Mask        */
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_BITER_ELINKYES: LINKCH Position    */
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_BITER_ELINKYES: ELINK Mask         */
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_BITER_ELINKYES: ELINK Position     */
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_ELINK_SHIFT))&DMA_BITER_ELINKYES_ELINK_MASK) /*!< DMA0_BITER_ELINKYES                     */
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
/* ================           DMAMUX0 (file:DMAMUX0_14CH_TRIG)       ================ */
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
   __IO uint8_t   CHCFG[14];                    /**< 0000: Channel Configuration Register                               */
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
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /*!< DMAMUX0_CHCFG: SOURCE Mask              */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /*!< DMAMUX0_CHCFG: SOURCE Position          */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)                                             /*!< DMAMUX0_CHCFG: TRIG Mask                */
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)                                                /*!< DMAMUX0_CHCFG: TRIG Position            */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_TRIG_SHIFT))&DMAMUX_CHCFG_TRIG_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /*!< DMAMUX0_CHCFG: ENBL Mask                */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /*!< DMAMUX0_CHCFG: ENBL Position            */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK) /*!< DMAMUX0_CHCFG                           */
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
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_MKE10)                 ================ */
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
#define EWM_CTRL_EWMEN_MASK                      (0x1U)                                              /*!< EWM_CTRL: EWMEN Mask                    */
#define EWM_CTRL_EWMEN_SHIFT                     (0U)                                                /*!< EWM_CTRL: EWMEN Position                */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_EWMEN_SHIFT))&EWM_CTRL_EWMEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_ASSIN_MASK                      (0x2U)                                              /*!< EWM_CTRL: ASSIN Mask                    */
#define EWM_CTRL_ASSIN_SHIFT                     (1U)                                                /*!< EWM_CTRL: ASSIN Position                */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_ASSIN_SHIFT))&EWM_CTRL_ASSIN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INEN_MASK                       (0x4U)                                              /*!< EWM_CTRL: INEN Mask                     */
#define EWM_CTRL_INEN_SHIFT                      (2U)                                                /*!< EWM_CTRL: INEN Position                 */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INEN_SHIFT))&EWM_CTRL_INEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INTEN_MASK                      (0x8U)                                              /*!< EWM_CTRL: INTEN Mask                    */
#define EWM_CTRL_INTEN_SHIFT                     (3U)                                                /*!< EWM_CTRL: INTEN Position                */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INTEN_SHIFT))&EWM_CTRL_INTEN_MASK) /*!< EWM_CTRL                                */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFU)                                             /*!< EWM_SERV: SERVICE Mask                  */
#define EWM_SERV_SERVICE_SHIFT                   (0U)                                                /*!< EWM_SERV: SERVICE Position              */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK) /*!< EWM_SERV                                */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)                                             /*!< EWM_CMPL: COMPAREL Mask                 */
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)                                                /*!< EWM_CMPL: COMPAREL Position             */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK) /*!< EWM_CMPL                                */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)                                             /*!< EWM_CMPH: COMPAREH Mask                 */
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)                                                /*!< EWM_CMPH: COMPAREH Position             */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK) /*!< EWM_CMPH                                */
/**
 * @} */ /* End group EWM_Register_Masks_GROUP 
 */

/* EWM - Peripheral instance base addresses */
#define EWM_BasePtr                    0x40041000UL //!< Peripheral base address
#define EWM                            ((EWM_Type *) EWM_BasePtr) //!< Freescale base pointer
#define EWM_BASE_PTR                   (EWM) //!< Freescale style base pointer
/**
 * @} */ /* End group EWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FB_Peripheral_access_layer_GROUP FB Peripheral Access Layer
* @brief C Struct for FB
* @{
*/

/* ================================================================================ */
/* ================           FB (file:FB_0)                       ================ */
/* ================================================================================ */

/**
 * @brief FlexBus external bus interface
 */
/**
* @addtogroup FB_structs_GROUP FB struct
* @brief Struct for FB
* @{
*/
typedef struct {                                /*       FB Structure                                                 */
   struct {
      __IO uint32_t  CSAR;                      /**< 0000: Chip Select Address Register                                 */
      __IO uint32_t  CSMR;                      /**< 0004: Chip Select Mask Register                                    */
      __IO uint32_t  CSCR;                      /**< 0008: Chip Select Control Register                                 */
   } CS[6];                                     /**< 0000: (cluster: size=0x0048, 72)                                   */
        uint8_t   RESERVED_1[24];              
   __IO uint32_t  CSPMCR;                       /**< 0060: Chip Select port Multiplexing Control Register               */
} FB_Type;

/**
 * @} */ /* End group FB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FB' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FB_Register_Masks_GROUP FB Register Masks
* @brief Register Masks for FB
* @{
*/
/* ------- CSAR Bit Fields                          ------ */
#define FB_CSAR_BA_MASK                          (0xFFFF0000U)                                       /*!< FB_CSAR: BA Mask                        */
#define FB_CSAR_BA_SHIFT                         (16U)                                               /*!< FB_CSAR: BA Position                    */
#define FB_CSAR_BA(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSAR_BA_SHIFT))&FB_CSAR_BA_MASK) /*!< FB_CSAR                                 */
/* ------- CSMR Bit Fields                          ------ */
#define FB_CSMR_V_MASK                           (0x1U)                                              /*!< FB_CSMR: V Mask                         */
#define FB_CSMR_V_SHIFT                          (0U)                                                /*!< FB_CSMR: V Position                     */
#define FB_CSMR_V(x)                             (((uint32_t)(((uint32_t)(x))<<FB_CSMR_V_SHIFT))&FB_CSMR_V_MASK) /*!< FB_CSMR                                 */
#define FB_CSMR_WP_MASK                          (0x100U)                                            /*!< FB_CSMR: WP Mask                        */
#define FB_CSMR_WP_SHIFT                         (8U)                                                /*!< FB_CSMR: WP Position                    */
#define FB_CSMR_WP(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSMR_WP_SHIFT))&FB_CSMR_WP_MASK) /*!< FB_CSMR                                 */
#define FB_CSMR_BAM_MASK                         (0xFFFF0000U)                                       /*!< FB_CSMR: BAM Mask                       */
#define FB_CSMR_BAM_SHIFT                        (16U)                                               /*!< FB_CSMR: BAM Position                   */
#define FB_CSMR_BAM(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSMR_BAM_SHIFT))&FB_CSMR_BAM_MASK) /*!< FB_CSMR                                 */
/* ------- CSCR Bit Fields                          ------ */
#define FB_CSCR_BSTW_MASK                        (0x8U)                                              /*!< FB_CSCR: BSTW Mask                      */
#define FB_CSCR_BSTW_SHIFT                       (3U)                                                /*!< FB_CSCR: BSTW Position                  */
#define FB_CSCR_BSTW(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_BSTW_SHIFT))&FB_CSCR_BSTW_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_BSTR_MASK                        (0x10U)                                             /*!< FB_CSCR: BSTR Mask                      */
#define FB_CSCR_BSTR_SHIFT                       (4U)                                                /*!< FB_CSCR: BSTR Position                  */
#define FB_CSCR_BSTR(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_BSTR_SHIFT))&FB_CSCR_BSTR_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_BEM_MASK                         (0x20U)                                             /*!< FB_CSCR: BEM Mask                       */
#define FB_CSCR_BEM_SHIFT                        (5U)                                                /*!< FB_CSCR: BEM Position                   */
#define FB_CSCR_BEM(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSCR_BEM_SHIFT))&FB_CSCR_BEM_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_PS_MASK                          (0xC0U)                                             /*!< FB_CSCR: PS Mask                        */
#define FB_CSCR_PS_SHIFT                         (6U)                                                /*!< FB_CSCR: PS Position                    */
#define FB_CSCR_PS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_PS_SHIFT))&FB_CSCR_PS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_AA_MASK                          (0x100U)                                            /*!< FB_CSCR: AA Mask                        */
#define FB_CSCR_AA_SHIFT                         (8U)                                                /*!< FB_CSCR: AA Position                    */
#define FB_CSCR_AA(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_AA_SHIFT))&FB_CSCR_AA_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_BLS_MASK                         (0x200U)                                            /*!< FB_CSCR: BLS Mask                       */
#define FB_CSCR_BLS_SHIFT                        (9U)                                                /*!< FB_CSCR: BLS Position                   */
#define FB_CSCR_BLS(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSCR_BLS_SHIFT))&FB_CSCR_BLS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_WS_MASK                          (0xFC00U)                                           /*!< FB_CSCR: WS Mask                        */
#define FB_CSCR_WS_SHIFT                         (10U)                                               /*!< FB_CSCR: WS Position                    */
#define FB_CSCR_WS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WS_SHIFT))&FB_CSCR_WS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_WRAH_MASK                        (0x30000U)                                          /*!< FB_CSCR: WRAH Mask                      */
#define FB_CSCR_WRAH_SHIFT                       (16U)                                               /*!< FB_CSCR: WRAH Position                  */
#define FB_CSCR_WRAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WRAH_SHIFT))&FB_CSCR_WRAH_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_RDAH_MASK                        (0xC0000U)                                          /*!< FB_CSCR: RDAH Mask                      */
#define FB_CSCR_RDAH_SHIFT                       (18U)                                               /*!< FB_CSCR: RDAH Position                  */
#define FB_CSCR_RDAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_RDAH_SHIFT))&FB_CSCR_RDAH_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_ASET_MASK                        (0x300000U)                                         /*!< FB_CSCR: ASET Mask                      */
#define FB_CSCR_ASET_SHIFT                       (20U)                                               /*!< FB_CSCR: ASET Position                  */
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_ASET_SHIFT))&FB_CSCR_ASET_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_EXTS_MASK                        (0x400000U)                                         /*!< FB_CSCR: EXTS Mask                      */
#define FB_CSCR_EXTS_SHIFT                       (22U)                                               /*!< FB_CSCR: EXTS Position                  */
#define FB_CSCR_EXTS(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_EXTS_SHIFT))&FB_CSCR_EXTS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_SWSEN_MASK                       (0x800000U)                                         /*!< FB_CSCR: SWSEN Mask                     */
#define FB_CSCR_SWSEN_SHIFT                      (23U)                                               /*!< FB_CSCR: SWSEN Position                 */
#define FB_CSCR_SWSEN(x)                         (((uint32_t)(((uint32_t)(x))<<FB_CSCR_SWSEN_SHIFT))&FB_CSCR_SWSEN_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_SWS_MASK                         (0xFC000000U)                                       /*!< FB_CSCR: SWS Mask                       */
#define FB_CSCR_SWS_SHIFT                        (26U)                                               /*!< FB_CSCR: SWS Position                   */
#define FB_CSCR_SWS(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSCR_SWS_SHIFT))&FB_CSCR_SWS_MASK) /*!< FB_CSCR                                 */
/* ------- CSPMCR Bit Fields                        ------ */
#define FB_CSPMCR_GROUP5_MASK                    (0xF000U)                                           /*!< FB_CSPMCR: GROUP5 Mask                  */
#define FB_CSPMCR_GROUP5_SHIFT                   (12U)                                               /*!< FB_CSPMCR: GROUP5 Position              */
#define FB_CSPMCR_GROUP5(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP5_SHIFT))&FB_CSPMCR_GROUP5_MASK) /*!< FB_CSPMCR                               */
#define FB_CSPMCR_GROUP4_MASK                    (0xF0000U)                                          /*!< FB_CSPMCR: GROUP4 Mask                  */
#define FB_CSPMCR_GROUP4_SHIFT                   (16U)                                               /*!< FB_CSPMCR: GROUP4 Position              */
#define FB_CSPMCR_GROUP4(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP4_SHIFT))&FB_CSPMCR_GROUP4_MASK) /*!< FB_CSPMCR                               */
#define FB_CSPMCR_GROUP3_MASK                    (0xF00000U)                                         /*!< FB_CSPMCR: GROUP3 Mask                  */
#define FB_CSPMCR_GROUP3_SHIFT                   (20U)                                               /*!< FB_CSPMCR: GROUP3 Position              */
#define FB_CSPMCR_GROUP3(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP3_SHIFT))&FB_CSPMCR_GROUP3_MASK) /*!< FB_CSPMCR                               */
#define FB_CSPMCR_GROUP2_MASK                    (0xF000000U)                                        /*!< FB_CSPMCR: GROUP2 Mask                  */
#define FB_CSPMCR_GROUP2_SHIFT                   (24U)                                               /*!< FB_CSPMCR: GROUP2 Position              */
#define FB_CSPMCR_GROUP2(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP2_SHIFT))&FB_CSPMCR_GROUP2_MASK) /*!< FB_CSPMCR                               */
#define FB_CSPMCR_GROUP1_MASK                    (0xF0000000U)                                       /*!< FB_CSPMCR: GROUP1 Mask                  */
#define FB_CSPMCR_GROUP1_SHIFT                   (28U)                                               /*!< FB_CSPMCR: GROUP1 Position              */
#define FB_CSPMCR_GROUP1(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP1_SHIFT))&FB_CSPMCR_GROUP1_MASK) /*!< FB_CSPMCR                               */
/**
 * @} */ /* End group FB_Register_Masks_GROUP 
 */

/* FB - Peripheral instance base addresses */
#define FB_BasePtr                     0x4000C000UL //!< Peripheral base address
#define FB                             ((FB_Type *) FB_BasePtr) //!< Freescale base pointer
#define FB_BASE_PTR                    (FB) //!< Freescale style base pointer
/**
 * @} */ /* End group FB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FMC_Peripheral_access_layer_GROUP FMC Peripheral Access Layer
* @brief C Struct for FMC
* @{
*/

/* ================================================================================ */
/* ================           FMC (file:FMC_MKE14D7)               ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Controller
 */
/**
* @addtogroup FMC_structs_GROUP FMC struct
* @brief Struct for FMC
* @{
*/
typedef struct {                                /*       FMC Structure                                                */
   __IO uint32_t  PFAPR;                        /**< 0000: Flash Access Protection Register                             */
   __IO uint32_t  PFB0CR;                       /**< 0004: Flash Bank 0 Control Register                                */
   __I  uint32_t  PFB1CR;                       /**< 0008: Flash Bank 1 Control Register                                */
        uint8_t   RESERVED_0[244];             
   struct {
      __IO uint32_t  S0;                        /**< 0100: Cache Tag Storage                                            */
      __IO uint32_t  S1;                        /**< 0104: Cache Tag Storage                                            */
      __IO uint32_t  S2;                        /**< 0108: Cache Tag Storage                                            */
      __IO uint32_t  S3;                        /**< 010C: Cache Tag Storage                                            */
   } TAGVDW[4];                                 /**< 0100: (cluster: size=0x0040, 64)                                   */
        uint8_t   RESERVED_2[192];             
   struct {
      __IO uint32_t  S0U;                       /**< 0200: Cache Data Storage (upper word)                              */
      __IO uint32_t  S0L;                       /**< 0204: Cache Data Storage (lower word)                              */
      __IO uint32_t  S1U;                       /**< 0208: Cache Data Storage (upper word)                              */
      __IO uint32_t  S1L;                       /**< 020C: Cache Data Storage (lower word)                              */
      __IO uint32_t  S2U;                       /**< 0210: Cache Data Storage (upper word)                              */
      __IO uint32_t  S2L;                       /**< 0214: Cache Data Storage (lower word)                              */
      __IO uint32_t  S3U;                       /**< 0218: Cache Data Storage (upper word)                              */
      __IO uint32_t  S3L;                       /**< 021C: Cache Data Storage (lower word)                              */
   } DATAW[4];                                  /**< 0200: (cluster: size=0x0080, 128)                                  */
} FMC_Type;

/**
 * @} */ /* End group FMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FMC_Register_Masks_GROUP FMC Register Masks
* @brief Register Masks for FMC
* @{
*/
/* ------- PFAPR Bit Fields                         ------ */
#define FMC_PFAPR_M0AP_MASK                      (0x3U)                                              /*!< FMC_PFAPR: M0AP Mask                    */
#define FMC_PFAPR_M0AP_SHIFT                     (0U)                                                /*!< FMC_PFAPR: M0AP Position                */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0AP_SHIFT))&FMC_PFAPR_M0AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1AP_MASK                      (0xCU)                                              /*!< FMC_PFAPR: M1AP Mask                    */
#define FMC_PFAPR_M1AP_SHIFT                     (2U)                                                /*!< FMC_PFAPR: M1AP Position                */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1AP_SHIFT))&FMC_PFAPR_M1AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2AP_MASK                      (0x30U)                                             /*!< FMC_PFAPR: M2AP Mask                    */
#define FMC_PFAPR_M2AP_SHIFT                     (4U)                                                /*!< FMC_PFAPR: M2AP Position                */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2AP_SHIFT))&FMC_PFAPR_M2AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3AP_MASK                      (0xC0U)                                             /*!< FMC_PFAPR: M3AP Mask                    */
#define FMC_PFAPR_M3AP_SHIFT                     (6U)                                                /*!< FMC_PFAPR: M3AP Position                */
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3AP_SHIFT))&FMC_PFAPR_M3AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M0PFD_MASK                     (0x10000U)                                          /*!< FMC_PFAPR: M0PFD Mask                   */
#define FMC_PFAPR_M0PFD_SHIFT                    (16U)                                               /*!< FMC_PFAPR: M0PFD Position               */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0PFD_SHIFT))&FMC_PFAPR_M0PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1PFD_MASK                     (0x20000U)                                          /*!< FMC_PFAPR: M1PFD Mask                   */
#define FMC_PFAPR_M1PFD_SHIFT                    (17U)                                               /*!< FMC_PFAPR: M1PFD Position               */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1PFD_SHIFT))&FMC_PFAPR_M1PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2PFD_MASK                     (0x40000U)                                          /*!< FMC_PFAPR: M2PFD Mask                   */
#define FMC_PFAPR_M2PFD_SHIFT                    (18U)                                               /*!< FMC_PFAPR: M2PFD Position               */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2PFD_SHIFT))&FMC_PFAPR_M2PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3PFD_MASK                     (0x80000U)                                          /*!< FMC_PFAPR: M3PFD Mask                   */
#define FMC_PFAPR_M3PFD_SHIFT                    (19U)                                               /*!< FMC_PFAPR: M3PFD Position               */
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3PFD_SHIFT))&FMC_PFAPR_M3PFD_MASK) /*!< FMC_PFAPR                               */
/* ------- PFB0CR Bit Fields                        ------ */
#define FMC_PFB0CR_B0SEBE_MASK                   (0x1U)                                              /*!< FMC_PFB0CR: B0SEBE Mask                 */
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0U)                                                /*!< FMC_PFB0CR: B0SEBE Position             */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0SEBE_SHIFT))&FMC_PFB0CR_B0SEBE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0IPE_MASK                    (0x2U)                                              /*!< FMC_PFB0CR: B0IPE Mask                  */
#define FMC_PFB0CR_B0IPE_SHIFT                   (1U)                                                /*!< FMC_PFB0CR: B0IPE Position              */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0IPE_SHIFT))&FMC_PFB0CR_B0IPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DPE_MASK                    (0x4U)                                              /*!< FMC_PFB0CR: B0DPE Mask                  */
#define FMC_PFB0CR_B0DPE_SHIFT                   (2U)                                                /*!< FMC_PFB0CR: B0DPE Position              */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DPE_SHIFT))&FMC_PFB0CR_B0DPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0ICE_MASK                    (0x8U)                                              /*!< FMC_PFB0CR: B0ICE Mask                  */
#define FMC_PFB0CR_B0ICE_SHIFT                   (3U)                                                /*!< FMC_PFB0CR: B0ICE Position              */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0ICE_SHIFT))&FMC_PFB0CR_B0ICE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DCE_MASK                    (0x10U)                                             /*!< FMC_PFB0CR: B0DCE Mask                  */
#define FMC_PFB0CR_B0DCE_SHIFT                   (4U)                                                /*!< FMC_PFB0CR: B0DCE Position              */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DCE_SHIFT))&FMC_PFB0CR_B0DCE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CRC_MASK                      (0xE0U)                                             /*!< FMC_PFB0CR: CRC Mask                    */
#define FMC_PFB0CR_CRC_SHIFT                     (5U)                                                /*!< FMC_PFB0CR: CRC Position                */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0MW_MASK                     (0x60000U)                                          /*!< FMC_PFB0CR: B0MW Mask                   */
#define FMC_PFB0CR_B0MW_SHIFT                    (17U)                                               /*!< FMC_PFB0CR: B0MW Position               */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0MW_SHIFT))&FMC_PFB0CR_B0MW_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000U)                                          /*!< FMC_PFB0CR: S_B_INV Mask                */
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19U)                                               /*!< FMC_PFB0CR: S_B_INV Position            */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_S_B_INV_SHIFT))&FMC_PFB0CR_S_B_INV_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000U)                                         /*!< FMC_PFB0CR: CINV_WAY Mask               */
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20U)                                               /*!< FMC_PFB0CR: CINV_WAY Position           */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CINV_WAY_SHIFT))&FMC_PFB0CR_CINV_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000U)                                        /*!< FMC_PFB0CR: CLCK_WAY Mask               */
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24U)                                               /*!< FMC_PFB0CR: CLCK_WAY Position           */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CLCK_WAY_SHIFT))&FMC_PFB0CR_CLCK_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000U)                                       /*!< FMC_PFB0CR: B0RWSC Mask                 */
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28U)                                               /*!< FMC_PFB0CR: B0RWSC Position             */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0RWSC_SHIFT))&FMC_PFB0CR_B0RWSC_MASK) /*!< FMC_PFB0CR                              */
/* ------- PFB1CR Bit Fields                        ------ */
#define FMC_PFB1CR_B1MW_MASK                     (0x60000U)                                          /*!< FMC_PFB1CR: B1MW Mask                   */
#define FMC_PFB1CR_B1MW_SHIFT                    (17U)                                               /*!< FMC_PFB1CR: B1MW Position               */
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1MW_SHIFT))&FMC_PFB1CR_B1MW_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1RWSC_MASK                   (0xF0000000U)                                       /*!< FMC_PFB1CR: B1RWSC Mask                 */
#define FMC_PFB1CR_B1RWSC_SHIFT                  (28U)                                               /*!< FMC_PFB1CR: B1RWSC Position             */
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1RWSC_SHIFT))&FMC_PFB1CR_B1RWSC_MASK) /*!< FMC_PFB1CR                              */
/* ------- S0 Bit Fields                            ------ */
#define FMC_S0_valid_MASK                        (0x1U)                                              /*!< FMC_S0: valid Mask                      */
#define FMC_S0_valid_SHIFT                       (0U)                                                /*!< FMC_S0: valid Position                  */
#define FMC_S0_valid(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S0_valid_SHIFT))&FMC_S0_valid_MASK) /*!< FMC_S0                                  */
#define FMC_S0_tag_MASK                          (0x7FFC0U)                                          /*!< FMC_S0: tag Mask                        */
#define FMC_S0_tag_SHIFT                         (6U)                                                /*!< FMC_S0: tag Position                    */
#define FMC_S0_tag(x)                            (((uint32_t)(((uint32_t)(x))<<FMC_S0_tag_SHIFT))&FMC_S0_tag_MASK) /*!< FMC_S0                                  */
/* ------- S1 Bit Fields                            ------ */
#define FMC_S1_valid_MASK                        (0x1U)                                              /*!< FMC_S1: valid Mask                      */
#define FMC_S1_valid_SHIFT                       (0U)                                                /*!< FMC_S1: valid Position                  */
#define FMC_S1_valid(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S1_valid_SHIFT))&FMC_S1_valid_MASK) /*!< FMC_S1                                  */
#define FMC_S1_tag_MASK                          (0x7FFC0U)                                          /*!< FMC_S1: tag Mask                        */
#define FMC_S1_tag_SHIFT                         (6U)                                                /*!< FMC_S1: tag Position                    */
#define FMC_S1_tag(x)                            (((uint32_t)(((uint32_t)(x))<<FMC_S1_tag_SHIFT))&FMC_S1_tag_MASK) /*!< FMC_S1                                  */
/* ------- S2 Bit Fields                            ------ */
#define FMC_S2_valid_MASK                        (0x1U)                                              /*!< FMC_S2: valid Mask                      */
#define FMC_S2_valid_SHIFT                       (0U)                                                /*!< FMC_S2: valid Position                  */
#define FMC_S2_valid(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S2_valid_SHIFT))&FMC_S2_valid_MASK) /*!< FMC_S2                                  */
#define FMC_S2_tag_MASK                          (0x7FFC0U)                                          /*!< FMC_S2: tag Mask                        */
#define FMC_S2_tag_SHIFT                         (6U)                                                /*!< FMC_S2: tag Position                    */
#define FMC_S2_tag(x)                            (((uint32_t)(((uint32_t)(x))<<FMC_S2_tag_SHIFT))&FMC_S2_tag_MASK) /*!< FMC_S2                                  */
/* ------- S3 Bit Fields                            ------ */
#define FMC_S3_valid_MASK                        (0x1U)                                              /*!< FMC_S3: valid Mask                      */
#define FMC_S3_valid_SHIFT                       (0U)                                                /*!< FMC_S3: valid Position                  */
#define FMC_S3_valid(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S3_valid_SHIFT))&FMC_S3_valid_MASK) /*!< FMC_S3                                  */
#define FMC_S3_tag_MASK                          (0x7FFC0U)                                          /*!< FMC_S3: tag Mask                        */
#define FMC_S3_tag_SHIFT                         (6U)                                                /*!< FMC_S3: tag Position                    */
#define FMC_S3_tag(x)                            (((uint32_t)(((uint32_t)(x))<<FMC_S3_tag_SHIFT))&FMC_S3_tag_MASK) /*!< FMC_S3                                  */
/* ------- S0U Bit Fields                           ------ */
#define FMC_S0U_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S0U: data Mask                      */
#define FMC_S0U_data_SHIFT                       (0U)                                                /*!< FMC_S0U: data Position                  */
#define FMC_S0U_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S0U_data_SHIFT))&FMC_S0U_data_MASK) /*!< FMC_S0U                                 */
/* ------- S0L Bit Fields                           ------ */
#define FMC_S0L_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S0L: data Mask                      */
#define FMC_S0L_data_SHIFT                       (0U)                                                /*!< FMC_S0L: data Position                  */
#define FMC_S0L_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S0L_data_SHIFT))&FMC_S0L_data_MASK) /*!< FMC_S0L                                 */
/* ------- S1U Bit Fields                           ------ */
#define FMC_S1U_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S1U: data Mask                      */
#define FMC_S1U_data_SHIFT                       (0U)                                                /*!< FMC_S1U: data Position                  */
#define FMC_S1U_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S1U_data_SHIFT))&FMC_S1U_data_MASK) /*!< FMC_S1U                                 */
/* ------- S1L Bit Fields                           ------ */
#define FMC_S1L_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S1L: data Mask                      */
#define FMC_S1L_data_SHIFT                       (0U)                                                /*!< FMC_S1L: data Position                  */
#define FMC_S1L_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S1L_data_SHIFT))&FMC_S1L_data_MASK) /*!< FMC_S1L                                 */
/* ------- S2U Bit Fields                           ------ */
#define FMC_S2U_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S2U: data Mask                      */
#define FMC_S2U_data_SHIFT                       (0U)                                                /*!< FMC_S2U: data Position                  */
#define FMC_S2U_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S2U_data_SHIFT))&FMC_S2U_data_MASK) /*!< FMC_S2U                                 */
/* ------- S2L Bit Fields                           ------ */
#define FMC_S2L_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S2L: data Mask                      */
#define FMC_S2L_data_SHIFT                       (0U)                                                /*!< FMC_S2L: data Position                  */
#define FMC_S2L_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S2L_data_SHIFT))&FMC_S2L_data_MASK) /*!< FMC_S2L                                 */
/* ------- S3U Bit Fields                           ------ */
#define FMC_S3U_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S3U: data Mask                      */
#define FMC_S3U_data_SHIFT                       (0U)                                                /*!< FMC_S3U: data Position                  */
#define FMC_S3U_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S3U_data_SHIFT))&FMC_S3U_data_MASK) /*!< FMC_S3U                                 */
/* ------- S3L Bit Fields                           ------ */
#define FMC_S3L_data_MASK                        (0xFFFFFFFFU)                                       /*!< FMC_S3L: data Mask                      */
#define FMC_S3L_data_SHIFT                       (0U)                                                /*!< FMC_S3L: data Position                  */
#define FMC_S3L_data(x)                          (((uint32_t)(((uint32_t)(x))<<FMC_S3L_data_SHIFT))&FMC_S3L_data_MASK) /*!< FMC_S3L                                 */
/**
 * @} */ /* End group FMC_Register_Masks_GROUP 
 */

/* FMC - Peripheral instance base addresses */
#define FMC_BasePtr                    0x4001F000UL //!< Peripheral base address
#define FMC                            ((FMC_Type *) FMC_BasePtr) //!< Freescale base pointer
#define FMC_BASE_PTR                   (FMC) //!< Freescale style base pointer
/**
 * @} */ /* End group FMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_MKE_6CH)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (6 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[6];                               /**< 000C: (cluster: size=0x0030, 48)                                   */
        uint8_t   RESERVED_1[16];              
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
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define FTM_SC_PS_MASK                           (0x7U)                                              /*!< FTM0_SC: PS Mask                        */
#define FTM_SC_PS_SHIFT                          (0U)                                                /*!< FTM0_SC: PS Position                    */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CLKS_MASK                         (0x18U)                                             /*!< FTM0_SC: CLKS Mask                      */
#define FTM_SC_CLKS_SHIFT                        (3U)                                                /*!< FTM0_SC: CLKS Position                  */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CPWMS_MASK                        (0x20U)                                             /*!< FTM0_SC: CPWMS Mask                     */
#define FTM_SC_CPWMS_SHIFT                       (5U)                                                /*!< FTM0_SC: CPWMS Position                 */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOIE_MASK                         (0x40U)                                             /*!< FTM0_SC: TOIE Mask                      */
#define FTM_SC_TOIE_SHIFT                        (6U)                                                /*!< FTM0_SC: TOIE Position                  */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOF_MASK                          (0x80U)                                             /*!< FTM0_SC: TOF Mask                       */
#define FTM_SC_TOF_SHIFT                         (7U)                                                /*!< FTM0_SC: TOF Position                   */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK) /*!< FTM0_SC                                 */
/* ------- CNT Bit Fields                           ------ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFU)                                           /*!< FTM0_CNT: COUNT Mask                    */
#define FTM_CNT_COUNT_SHIFT                      (0U)                                                /*!< FTM0_CNT: COUNT Position                */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK) /*!< FTM0_CNT                                */
/* ------- MOD Bit Fields                           ------ */
#define FTM_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< FTM0_MOD: MOD Mask                      */
#define FTM_MOD_MOD_SHIFT                        (0U)                                                /*!< FTM0_MOD: MOD Position                  */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK) /*!< FTM0_MOD                                */
/* ------- CnSC Bit Fields                          ------ */
#define FTM_CnSC_DMA_MASK                        (0x1U)                                              /*!< FTM0_CnSC: DMA Mask                     */
#define FTM_CnSC_DMA_SHIFT                       (0U)                                                /*!< FTM0_CnSC: DMA Position                 */
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_DMA_SHIFT))&FTM_CnSC_DMA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELS_MASK                        (0xCU)                                              /*!< FTM0_CnSC: ELS Mask                     */
#define FTM_CnSC_ELS_SHIFT                       (2U)                                                /*!< FTM0_CnSC: ELS Position                 */
#define FTM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELS_SHIFT))&FTM_CnSC_ELS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSA_MASK                       (0x4U)                                              /*!< FTM0_CnSC: ELSA Mask                    */
#define FTM_CnSC_ELSA_SHIFT                      (2U)                                                /*!< FTM0_CnSC: ELSA Position                */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSB_MASK                       (0x8U)                                              /*!< FTM0_CnSC: ELSB Mask                    */
#define FTM_CnSC_ELSB_SHIFT                      (3U)                                                /*!< FTM0_CnSC: ELSB Position                */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MS_MASK                         (0x30U)                                             /*!< FTM0_CnSC: MS Mask                      */
#define FTM_CnSC_MS_SHIFT                        (4U)                                                /*!< FTM0_CnSC: MS Position                  */
#define FTM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MS_SHIFT))&FTM_CnSC_MS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSA_MASK                        (0x10U)                                             /*!< FTM0_CnSC: MSA Mask                     */
#define FTM_CnSC_MSA_SHIFT                       (4U)                                                /*!< FTM0_CnSC: MSA Position                 */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSB_MASK                        (0x20U)                                             /*!< FTM0_CnSC: MSB Mask                     */
#define FTM_CnSC_MSB_SHIFT                       (5U)                                                /*!< FTM0_CnSC: MSB Position                 */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHIE_MASK                       (0x40U)                                             /*!< FTM0_CnSC: CHIE Mask                    */
#define FTM_CnSC_CHIE_SHIFT                      (6U)                                                /*!< FTM0_CnSC: CHIE Position                */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHF_MASK                        (0x80U)                                             /*!< FTM0_CnSC: CHF Mask                     */
#define FTM_CnSC_CHF_SHIFT                       (7U)                                                /*!< FTM0_CnSC: CHF Position                 */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK) /*!< FTM0_CnSC                               */
/* ------- CnV Bit Fields                           ------ */
#define FTM_CnV_VAL_MASK                         (0xFFFFU)                                           /*!< FTM0_CnV: VAL Mask                      */
#define FTM_CnV_VAL_SHIFT                        (0U)                                                /*!< FTM0_CnV: VAL Position                  */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK) /*!< FTM0_CnV                                */
/* ------- CNTIN Bit Fields                         ------ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFU)                                           /*!< FTM0_CNTIN: INIT Mask                   */
#define FTM_CNTIN_INIT_SHIFT                     (0U)                                                /*!< FTM0_CNTIN: INIT Position               */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK) /*!< FTM0_CNTIN                              */
/* ------- STATUS Bit Fields                        ------ */
#define FTM_STATUS_CH0F_MASK                     (0x1U)                                              /*!< FTM0_STATUS: CH0F Mask                  */
#define FTM_STATUS_CH0F_SHIFT                    (0U)                                                /*!< FTM0_STATUS: CH0F Position              */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH1F_MASK                     (0x2U)                                              /*!< FTM0_STATUS: CH1F Mask                  */
#define FTM_STATUS_CH1F_SHIFT                    (1U)                                                /*!< FTM0_STATUS: CH1F Position              */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH2F_MASK                     (0x4U)                                              /*!< FTM0_STATUS: CH2F Mask                  */
#define FTM_STATUS_CH2F_SHIFT                    (2U)                                                /*!< FTM0_STATUS: CH2F Position              */
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH3F_MASK                     (0x8U)                                              /*!< FTM0_STATUS: CH3F Mask                  */
#define FTM_STATUS_CH3F_SHIFT                    (3U)                                                /*!< FTM0_STATUS: CH3F Position              */
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH4F_MASK                     (0x10U)                                             /*!< FTM0_STATUS: CH4F Mask                  */
#define FTM_STATUS_CH4F_SHIFT                    (4U)                                                /*!< FTM0_STATUS: CH4F Position              */
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH5F_MASK                     (0x20U)                                             /*!< FTM0_STATUS: CH5F Mask                  */
#define FTM_STATUS_CH5F_SHIFT                    (5U)                                                /*!< FTM0_STATUS: CH5F Position              */
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK) /*!< FTM0_STATUS                             */
/* ------- MODE Bit Fields                          ------ */
#define FTM_MODE_FTMEN_MASK                      (0x1U)                                              /*!< FTM0_MODE: FTMEN Mask                   */
#define FTM_MODE_FTMEN_SHIFT                     (0U)                                                /*!< FTM0_MODE: FTMEN Position               */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_INIT_MASK                       (0x2U)                                              /*!< FTM0_MODE: INIT Mask                    */
#define FTM_MODE_INIT_SHIFT                      (1U)                                                /*!< FTM0_MODE: INIT Position                */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_WPDIS_MASK                      (0x4U)                                              /*!< FTM0_MODE: WPDIS Mask                   */
#define FTM_MODE_WPDIS_SHIFT                     (2U)                                                /*!< FTM0_MODE: WPDIS Position               */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_PWMSYNC_MASK                    (0x8U)                                              /*!< FTM0_MODE: PWMSYNC Mask                 */
#define FTM_MODE_PWMSYNC_SHIFT                   (3U)                                                /*!< FTM0_MODE: PWMSYNC Position             */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_CAPTEST_MASK                    (0x10U)                                             /*!< FTM0_MODE: CAPTEST Mask                 */
#define FTM_MODE_CAPTEST_SHIFT                   (4U)                                                /*!< FTM0_MODE: CAPTEST Position             */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTM_MASK                     (0x60U)                                             /*!< FTM0_MODE: FAULTM Mask                  */
#define FTM_MODE_FAULTM_SHIFT                    (5U)                                                /*!< FTM0_MODE: FAULTM Position              */
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTIE_MASK                    (0x80U)                                             /*!< FTM0_MODE: FAULTIE Mask                 */
#define FTM_MODE_FAULTIE_SHIFT                   (7U)                                                /*!< FTM0_MODE: FAULTIE Position             */
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK) /*!< FTM0_MODE                               */
/* ------- SYNC Bit Fields                          ------ */
#define FTM_SYNC_CNTMIN_MASK                     (0x1U)                                              /*!< FTM0_SYNC: CNTMIN Mask                  */
#define FTM_SYNC_CNTMIN_SHIFT                    (0U)                                                /*!< FTM0_SYNC: CNTMIN Position              */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_CNTMAX_MASK                     (0x2U)                                              /*!< FTM0_SYNC: CNTMAX Mask                  */
#define FTM_SYNC_CNTMAX_SHIFT                    (1U)                                                /*!< FTM0_SYNC: CNTMAX Position              */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_REINIT_MASK                     (0x4U)                                              /*!< FTM0_SYNC: REINIT Mask                  */
#define FTM_SYNC_REINIT_SHIFT                    (2U)                                                /*!< FTM0_SYNC: REINIT Position              */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SYNCHOM_MASK                    (0x8U)                                              /*!< FTM0_SYNC: SYNCHOM Mask                 */
#define FTM_SYNC_SYNCHOM_SHIFT                   (3U)                                                /*!< FTM0_SYNC: SYNCHOM Position             */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG0_MASK                      (0x10U)                                             /*!< FTM0_SYNC: TRIG0 Mask                   */
#define FTM_SYNC_TRIG0_SHIFT                     (4U)                                                /*!< FTM0_SYNC: TRIG0 Position               */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG1_MASK                      (0x20U)                                             /*!< FTM0_SYNC: TRIG1 Mask                   */
#define FTM_SYNC_TRIG1_SHIFT                     (5U)                                                /*!< FTM0_SYNC: TRIG1 Position               */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG2_MASK                      (0x40U)                                             /*!< FTM0_SYNC: TRIG2 Mask                   */
#define FTM_SYNC_TRIG2_SHIFT                     (6U)                                                /*!< FTM0_SYNC: TRIG2 Position               */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SWSYNC_MASK                     (0x80U)                                             /*!< FTM0_SYNC: SWSYNC Mask                  */
#define FTM_SYNC_SWSYNC_SHIFT                    (7U)                                                /*!< FTM0_SYNC: SWSYNC Position              */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK) /*!< FTM0_SYNC                               */
/* ------- OUTINIT Bit Fields                       ------ */
#define FTM_OUTINIT_CH0OI_MASK                   (0x1U)                                              /*!< FTM0_OUTINIT: CH0OI Mask                */
#define FTM_OUTINIT_CH0OI_SHIFT                  (0U)                                                /*!< FTM0_OUTINIT: CH0OI Position            */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH1OI_MASK                   (0x2U)                                              /*!< FTM0_OUTINIT: CH1OI Mask                */
#define FTM_OUTINIT_CH1OI_SHIFT                  (1U)                                                /*!< FTM0_OUTINIT: CH1OI Position            */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH2OI_MASK                   (0x4U)                                              /*!< FTM0_OUTINIT: CH2OI Mask                */
#define FTM_OUTINIT_CH2OI_SHIFT                  (2U)                                                /*!< FTM0_OUTINIT: CH2OI Position            */
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH3OI_MASK                   (0x8U)                                              /*!< FTM0_OUTINIT: CH3OI Mask                */
#define FTM_OUTINIT_CH3OI_SHIFT                  (3U)                                                /*!< FTM0_OUTINIT: CH3OI Position            */
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH4OI_MASK                   (0x10U)                                             /*!< FTM0_OUTINIT: CH4OI Mask                */
#define FTM_OUTINIT_CH4OI_SHIFT                  (4U)                                                /*!< FTM0_OUTINIT: CH4OI Position            */
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH5OI_MASK                   (0x20U)                                             /*!< FTM0_OUTINIT: CH5OI Mask                */
#define FTM_OUTINIT_CH5OI_SHIFT                  (5U)                                                /*!< FTM0_OUTINIT: CH5OI Position            */
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH6OI_MASK                   (0x40U)                                             /*!< FTM0_OUTINIT: CH6OI Mask                */
#define FTM_OUTINIT_CH6OI_SHIFT                  (6U)                                                /*!< FTM0_OUTINIT: CH6OI Position            */
#define FTM_OUTINIT_CH6OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH6OI_SHIFT))&FTM_OUTINIT_CH6OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH7OI_MASK                   (0x80U)                                             /*!< FTM0_OUTINIT: CH7OI Mask                */
#define FTM_OUTINIT_CH7OI_SHIFT                  (7U)                                                /*!< FTM0_OUTINIT: CH7OI Position            */
#define FTM_OUTINIT_CH7OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH7OI_SHIFT))&FTM_OUTINIT_CH7OI_MASK) /*!< FTM0_OUTINIT                            */
/* ------- OUTMASK Bit Fields                       ------ */
#define FTM_OUTMASK_CH0OM_MASK                   (0x1U)                                              /*!< FTM0_OUTMASK: CH0OM Mask                */
#define FTM_OUTMASK_CH0OM_SHIFT                  (0U)                                                /*!< FTM0_OUTMASK: CH0OM Position            */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH1OM_MASK                   (0x2U)                                              /*!< FTM0_OUTMASK: CH1OM Mask                */
#define FTM_OUTMASK_CH1OM_SHIFT                  (1U)                                                /*!< FTM0_OUTMASK: CH1OM Position            */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH2OM_MASK                   (0x4U)                                              /*!< FTM0_OUTMASK: CH2OM Mask                */
#define FTM_OUTMASK_CH2OM_SHIFT                  (2U)                                                /*!< FTM0_OUTMASK: CH2OM Position            */
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH3OM_MASK                   (0x8U)                                              /*!< FTM0_OUTMASK: CH3OM Mask                */
#define FTM_OUTMASK_CH3OM_SHIFT                  (3U)                                                /*!< FTM0_OUTMASK: CH3OM Position            */
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH4OM_MASK                   (0x10U)                                             /*!< FTM0_OUTMASK: CH4OM Mask                */
#define FTM_OUTMASK_CH4OM_SHIFT                  (4U)                                                /*!< FTM0_OUTMASK: CH4OM Position            */
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH5OM_MASK                   (0x20U)                                             /*!< FTM0_OUTMASK: CH5OM Mask                */
#define FTM_OUTMASK_CH5OM_SHIFT                  (5U)                                                /*!< FTM0_OUTMASK: CH5OM Position            */
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH6OM_MASK                   (0x40U)                                             /*!< FTM0_OUTMASK: CH6OM Mask                */
#define FTM_OUTMASK_CH6OM_SHIFT                  (6U)                                                /*!< FTM0_OUTMASK: CH6OM Position            */
#define FTM_OUTMASK_CH6OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH6OM_SHIFT))&FTM_OUTMASK_CH6OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH7OM_MASK                   (0x80U)                                             /*!< FTM0_OUTMASK: CH7OM Mask                */
#define FTM_OUTMASK_CH7OM_SHIFT                  (7U)                                                /*!< FTM0_OUTMASK: CH7OM Position            */
#define FTM_OUTMASK_CH7OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH7OM_SHIFT))&FTM_OUTMASK_CH7OM_MASK) /*!< FTM0_OUTMASK                            */
/* ------- COMBINE Bit Fields                       ------ */
#define FTM_COMBINE_COMBINE0_MASK                (0x1U)                                              /*!< FTM0_COMBINE: COMBINE0 Mask             */
#define FTM_COMBINE_COMBINE0_SHIFT               (0U)                                                /*!< FTM0_COMBINE: COMBINE0 Position         */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP0_MASK                   (0x2U)                                              /*!< FTM0_COMBINE: COMP0 Mask                */
#define FTM_COMBINE_COMP0_SHIFT                  (1U)                                                /*!< FTM0_COMBINE: COMP0 Position            */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN0_MASK                (0x4U)                                              /*!< FTM0_COMBINE: DECAPEN0 Mask             */
#define FTM_COMBINE_DECAPEN0_SHIFT               (2U)                                                /*!< FTM0_COMBINE: DECAPEN0 Position         */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP0_MASK                  (0x8U)                                              /*!< FTM0_COMBINE: DECAP0 Mask               */
#define FTM_COMBINE_DECAP0_SHIFT                 (3U)                                                /*!< FTM0_COMBINE: DECAP0 Position           */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN0_MASK                   (0x10U)                                             /*!< FTM0_COMBINE: DTEN0 Mask                */
#define FTM_COMBINE_DTEN0_SHIFT                  (4U)                                                /*!< FTM0_COMBINE: DTEN0 Position            */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN0_MASK                 (0x20U)                                             /*!< FTM0_COMBINE: SYNCEN0 Mask              */
#define FTM_COMBINE_SYNCEN0_SHIFT                (5U)                                                /*!< FTM0_COMBINE: SYNCEN0 Position          */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN0_MASK                (0x40U)                                             /*!< FTM0_COMBINE: FAULTEN0 Mask             */
#define FTM_COMBINE_FAULTEN0_SHIFT               (6U)                                                /*!< FTM0_COMBINE: FAULTEN0 Position         */
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE1_MASK                (0x100U)                                            /*!< FTM0_COMBINE: COMBINE1 Mask             */
#define FTM_COMBINE_COMBINE1_SHIFT               (8U)                                                /*!< FTM0_COMBINE: COMBINE1 Position         */
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP1_MASK                   (0x200U)                                            /*!< FTM0_COMBINE: COMP1 Mask                */
#define FTM_COMBINE_COMP1_SHIFT                  (9U)                                                /*!< FTM0_COMBINE: COMP1 Position            */
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN1_MASK                (0x400U)                                            /*!< FTM0_COMBINE: DECAPEN1 Mask             */
#define FTM_COMBINE_DECAPEN1_SHIFT               (10U)                                               /*!< FTM0_COMBINE: DECAPEN1 Position         */
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP1_MASK                  (0x800U)                                            /*!< FTM0_COMBINE: DECAP1 Mask               */
#define FTM_COMBINE_DECAP1_SHIFT                 (11U)                                               /*!< FTM0_COMBINE: DECAP1 Position           */
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN1_MASK                   (0x1000U)                                           /*!< FTM0_COMBINE: DTEN1 Mask                */
#define FTM_COMBINE_DTEN1_SHIFT                  (12U)                                               /*!< FTM0_COMBINE: DTEN1 Position            */
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN1_MASK                 (0x2000U)                                           /*!< FTM0_COMBINE: SYNCEN1 Mask              */
#define FTM_COMBINE_SYNCEN1_SHIFT                (13U)                                               /*!< FTM0_COMBINE: SYNCEN1 Position          */
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN1_MASK                (0x4000U)                                           /*!< FTM0_COMBINE: FAULTEN1 Mask             */
#define FTM_COMBINE_FAULTEN1_SHIFT               (14U)                                               /*!< FTM0_COMBINE: FAULTEN1 Position         */
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE2_MASK                (0x10000U)                                          /*!< FTM0_COMBINE: COMBINE2 Mask             */
#define FTM_COMBINE_COMBINE2_SHIFT               (16U)                                               /*!< FTM0_COMBINE: COMBINE2 Position         */
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP2_MASK                   (0x20000U)                                          /*!< FTM0_COMBINE: COMP2 Mask                */
#define FTM_COMBINE_COMP2_SHIFT                  (17U)                                               /*!< FTM0_COMBINE: COMP2 Position            */
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN2_MASK                (0x40000U)                                          /*!< FTM0_COMBINE: DECAPEN2 Mask             */
#define FTM_COMBINE_DECAPEN2_SHIFT               (18U)                                               /*!< FTM0_COMBINE: DECAPEN2 Position         */
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP2_MASK                  (0x80000U)                                          /*!< FTM0_COMBINE: DECAP2 Mask               */
#define FTM_COMBINE_DECAP2_SHIFT                 (19U)                                               /*!< FTM0_COMBINE: DECAP2 Position           */
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN2_MASK                   (0x100000U)                                         /*!< FTM0_COMBINE: DTEN2 Mask                */
#define FTM_COMBINE_DTEN2_SHIFT                  (20U)                                               /*!< FTM0_COMBINE: DTEN2 Position            */
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN2_MASK                 (0x200000U)                                         /*!< FTM0_COMBINE: SYNCEN2 Mask              */
#define FTM_COMBINE_SYNCEN2_SHIFT                (21U)                                               /*!< FTM0_COMBINE: SYNCEN2 Position          */
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN2_MASK                (0x400000U)                                         /*!< FTM0_COMBINE: FAULTEN2 Mask             */
#define FTM_COMBINE_FAULTEN2_SHIFT               (22U)                                               /*!< FTM0_COMBINE: FAULTEN2 Position         */
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK) /*!< FTM0_COMBINE                            */
/* ------- DEADTIME Bit Fields                      ------ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FU)                                             /*!< FTM0_DEADTIME: DTVAL Mask               */
#define FTM_DEADTIME_DTVAL_SHIFT                 (0U)                                                /*!< FTM0_DEADTIME: DTVAL Position           */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK) /*!< FTM0_DEADTIME                           */
#define FTM_DEADTIME_DTPS_MASK                   (0xC0U)                                             /*!< FTM0_DEADTIME: DTPS Mask                */
#define FTM_DEADTIME_DTPS_SHIFT                  (6U)                                                /*!< FTM0_DEADTIME: DTPS Position            */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK) /*!< FTM0_DEADTIME                           */
/* ------- EXTTRIG Bit Fields                       ------ */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x1U)                                              /*!< FTM0_EXTTRIG: CH2TRIG Mask              */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                (0U)                                                /*!< FTM0_EXTTRIG: CH2TRIG Position          */
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x2U)                                              /*!< FTM0_EXTTRIG: CH3TRIG Mask              */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                (1U)                                                /*!< FTM0_EXTTRIG: CH3TRIG Position          */
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x4U)                                              /*!< FTM0_EXTTRIG: CH4TRIG Mask              */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                (2U)                                                /*!< FTM0_EXTTRIG: CH4TRIG Position          */
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x8U)                                              /*!< FTM0_EXTTRIG: CH5TRIG Mask              */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                (3U)                                                /*!< FTM0_EXTTRIG: CH5TRIG Position          */
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x10U)                                             /*!< FTM0_EXTTRIG: CH0TRIG Mask              */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                (4U)                                                /*!< FTM0_EXTTRIG: CH0TRIG Position          */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x20U)                                             /*!< FTM0_EXTTRIG: CH1TRIG Mask              */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                (5U)                                                /*!< FTM0_EXTTRIG: CH1TRIG Position          */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x40U)                                             /*!< FTM0_EXTTRIG: INITTRIGEN Mask           */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             (6U)                                                /*!< FTM0_EXTTRIG: INITTRIGEN Position       */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x80U)                                             /*!< FTM0_EXTTRIG: TRIGF Mask                */
#define FTM_EXTTRIG_TRIGF_SHIFT                  (7U)                                                /*!< FTM0_EXTTRIG: TRIGF Position            */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK) /*!< FTM0_EXTTRIG                            */
/* ------- POL Bit Fields                           ------ */
#define FTM_POL_POL0_MASK                        (0x1U)                                              /*!< FTM0_POL: POL0 Mask                     */
#define FTM_POL_POL0_SHIFT                       (0U)                                                /*!< FTM0_POL: POL0 Position                 */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL1_MASK                        (0x2U)                                              /*!< FTM0_POL: POL1 Mask                     */
#define FTM_POL_POL1_SHIFT                       (1U)                                                /*!< FTM0_POL: POL1 Position                 */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL2_MASK                        (0x4U)                                              /*!< FTM0_POL: POL2 Mask                     */
#define FTM_POL_POL2_SHIFT                       (2U)                                                /*!< FTM0_POL: POL2 Position                 */
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL3_MASK                        (0x8U)                                              /*!< FTM0_POL: POL3 Mask                     */
#define FTM_POL_POL3_SHIFT                       (3U)                                                /*!< FTM0_POL: POL3 Position                 */
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL4_MASK                        (0x10U)                                             /*!< FTM0_POL: POL4 Mask                     */
#define FTM_POL_POL4_SHIFT                       (4U)                                                /*!< FTM0_POL: POL4 Position                 */
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL5_MASK                        (0x20U)                                             /*!< FTM0_POL: POL5 Mask                     */
#define FTM_POL_POL5_SHIFT                       (5U)                                                /*!< FTM0_POL: POL5 Position                 */
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL6_MASK                        (0x40U)                                             /*!< FTM0_POL: POL6 Mask                     */
#define FTM_POL_POL6_SHIFT                       (6U)                                                /*!< FTM0_POL: POL6 Position                 */
#define FTM_POL_POL6(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL6_SHIFT))&FTM_POL_POL6_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL7_MASK                        (0x80U)                                             /*!< FTM0_POL: POL7 Mask                     */
#define FTM_POL_POL7_SHIFT                       (7U)                                                /*!< FTM0_POL: POL7 Position                 */
#define FTM_POL_POL7(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL7_SHIFT))&FTM_POL_POL7_MASK) /*!< FTM0_POL                                */
/* ------- FMS Bit Fields                           ------ */
#define FTM_FMS_FAULTF0_MASK                     (0x1U)                                              /*!< FTM0_FMS: FAULTF0 Mask                  */
#define FTM_FMS_FAULTF0_SHIFT                    (0U)                                                /*!< FTM0_FMS: FAULTF0 Position              */
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF1_MASK                     (0x2U)                                              /*!< FTM0_FMS: FAULTF1 Mask                  */
#define FTM_FMS_FAULTF1_SHIFT                    (1U)                                                /*!< FTM0_FMS: FAULTF1 Position              */
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF2_MASK                     (0x4U)                                              /*!< FTM0_FMS: FAULTF2 Mask                  */
#define FTM_FMS_FAULTF2_SHIFT                    (2U)                                                /*!< FTM0_FMS: FAULTF2 Position              */
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF3_MASK                     (0x8U)                                              /*!< FTM0_FMS: FAULTF3 Mask                  */
#define FTM_FMS_FAULTF3_SHIFT                    (3U)                                                /*!< FTM0_FMS: FAULTF3 Position              */
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTIN_MASK                     (0x20U)                                             /*!< FTM0_FMS: FAULTIN Mask                  */
#define FTM_FMS_FAULTIN_SHIFT                    (5U)                                                /*!< FTM0_FMS: FAULTIN Position              */
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_WPEN_MASK                        (0x40U)                                             /*!< FTM0_FMS: WPEN Mask                     */
#define FTM_FMS_WPEN_SHIFT                       (6U)                                                /*!< FTM0_FMS: WPEN Position                 */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF_MASK                      (0x80U)                                             /*!< FTM0_FMS: FAULTF Mask                   */
#define FTM_FMS_FAULTF_SHIFT                     (7U)                                                /*!< FTM0_FMS: FAULTF Position               */
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK) /*!< FTM0_FMS                                */
/* ------- FILTER Bit Fields                        ------ */
#define FTM_FILTER_CH0FVAL_MASK                  (0xFU)                                              /*!< FTM0_FILTER: CH0FVAL Mask               */
#define FTM_FILTER_CH0FVAL_SHIFT                 (0U)                                                /*!< FTM0_FILTER: CH0FVAL Position           */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH1FVAL_MASK                  (0xF0U)                                             /*!< FTM0_FILTER: CH1FVAL Mask               */
#define FTM_FILTER_CH1FVAL_SHIFT                 (4U)                                                /*!< FTM0_FILTER: CH1FVAL Position           */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH2FVAL_MASK                  (0xF00U)                                            /*!< FTM0_FILTER: CH2FVAL Mask               */
#define FTM_FILTER_CH2FVAL_SHIFT                 (8U)                                                /*!< FTM0_FILTER: CH2FVAL Position           */
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH3FVAL_MASK                  (0xF000U)                                           /*!< FTM0_FILTER: CH3FVAL Mask               */
#define FTM_FILTER_CH3FVAL_SHIFT                 (12U)                                               /*!< FTM0_FILTER: CH3FVAL Position           */
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK) /*!< FTM0_FILTER                             */
/* ------- FLTCTRL Bit Fields                       ------ */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x1U)                                              /*!< FTM0_FLTCTRL: FAULT0EN Mask             */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               (0U)                                                /*!< FTM0_FLTCTRL: FAULT0EN Position         */
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x2U)                                              /*!< FTM0_FLTCTRL: FAULT1EN Mask             */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               (1U)                                                /*!< FTM0_FLTCTRL: FAULT1EN Position         */
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x4U)                                              /*!< FTM0_FLTCTRL: FAULT2EN Mask             */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               (2U)                                                /*!< FTM0_FLTCTRL: FAULT2EN Position         */
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x8U)                                              /*!< FTM0_FLTCTRL: FAULT3EN Mask             */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               (3U)                                                /*!< FTM0_FLTCTRL: FAULT3EN Position         */
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x10U)                                             /*!< FTM0_FLTCTRL: FFLTR0EN Mask             */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               (4U)                                                /*!< FTM0_FLTCTRL: FFLTR0EN Position         */
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x20U)                                             /*!< FTM0_FLTCTRL: FFLTR1EN Mask             */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               (5U)                                                /*!< FTM0_FLTCTRL: FFLTR1EN Position         */
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x40U)                                             /*!< FTM0_FLTCTRL: FFLTR2EN Mask             */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               (6U)                                                /*!< FTM0_FLTCTRL: FFLTR2EN Position         */
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x80U)                                             /*!< FTM0_FLTCTRL: FFLTR3EN Mask             */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               (7U)                                                /*!< FTM0_FLTCTRL: FFLTR3EN Position         */
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFVAL_MASK                   (0xF00U)                                            /*!< FTM0_FLTCTRL: FFVAL Mask                */
#define FTM_FLTCTRL_FFVAL_SHIFT                  (8U)                                                /*!< FTM0_FLTCTRL: FFVAL Position            */
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK) /*!< FTM0_FLTCTRL                            */
/* ------- QDCTRL Bit Fields                        ------ */
#define FTM_QDCTRL_QUADEN_MASK                   (0x1U)                                              /*!< FTM0_QDCTRL: QUADEN Mask                */
#define FTM_QDCTRL_QUADEN_SHIFT                  (0U)                                                /*!< FTM0_QDCTRL: QUADEN Position            */
#define FTM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADEN_SHIFT))&FTM_QDCTRL_QUADEN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_TOFDIR_MASK                   (0x2U)                                              /*!< FTM0_QDCTRL: TOFDIR Mask                */
#define FTM_QDCTRL_TOFDIR_SHIFT                  (1U)                                                /*!< FTM0_QDCTRL: TOFDIR Position            */
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_TOFDIR_SHIFT))&FTM_QDCTRL_TOFDIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADIR_MASK                   (0x4U)                                              /*!< FTM0_QDCTRL: QUADIR Mask                */
#define FTM_QDCTRL_QUADIR_SHIFT                  (2U)                                                /*!< FTM0_QDCTRL: QUADIR Position            */
#define FTM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADIR_SHIFT))&FTM_QDCTRL_QUADIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADMODE_MASK                 (0x8U)                                              /*!< FTM0_QDCTRL: QUADMODE Mask              */
#define FTM_QDCTRL_QUADMODE_SHIFT                (3U)                                                /*!< FTM0_QDCTRL: QUADMODE Position          */
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADMODE_SHIFT))&FTM_QDCTRL_QUADMODE_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBPOL_MASK                   (0x10U)                                             /*!< FTM0_QDCTRL: PHBPOL Mask                */
#define FTM_QDCTRL_PHBPOL_SHIFT                  (4U)                                                /*!< FTM0_QDCTRL: PHBPOL Position            */
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBPOL_SHIFT))&FTM_QDCTRL_PHBPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAPOL_MASK                   (0x20U)                                             /*!< FTM0_QDCTRL: PHAPOL Mask                */
#define FTM_QDCTRL_PHAPOL_SHIFT                  (5U)                                                /*!< FTM0_QDCTRL: PHAPOL Position            */
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAPOL_SHIFT))&FTM_QDCTRL_PHAPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBFLTREN_MASK                (0x40U)                                             /*!< FTM0_QDCTRL: PHBFLTREN Mask             */
#define FTM_QDCTRL_PHBFLTREN_SHIFT               (6U)                                                /*!< FTM0_QDCTRL: PHBFLTREN Position         */
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBFLTREN_SHIFT))&FTM_QDCTRL_PHBFLTREN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAFLTREN_MASK                (0x80U)                                             /*!< FTM0_QDCTRL: PHAFLTREN Mask             */
#define FTM_QDCTRL_PHAFLTREN_SHIFT               (7U)                                                /*!< FTM0_QDCTRL: PHAFLTREN Position         */
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAFLTREN_SHIFT))&FTM_QDCTRL_PHAFLTREN_MASK) /*!< FTM0_QDCTRL                             */
/* ------- CONF Bit Fields                          ------ */
#define FTM_CONF_NUMTOF_MASK                     (0x1FU)                                             /*!< FTM0_CONF: NUMTOF Mask                  */
#define FTM_CONF_NUMTOF_SHIFT                    (0U)                                                /*!< FTM0_CONF: NUMTOF Position              */
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_BDMMODE_MASK                    (0xC0U)                                             /*!< FTM0_CONF: BDMMODE Mask                 */
#define FTM_CONF_BDMMODE_SHIFT                   (6U)                                                /*!< FTM0_CONF: BDMMODE Position             */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEEN_MASK                     (0x200U)                                            /*!< FTM0_CONF: GTBEEN Mask                  */
#define FTM_CONF_GTBEEN_SHIFT                    (9U)                                                /*!< FTM0_CONF: GTBEEN Position              */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEOUT_MASK                    (0x400U)                                            /*!< FTM0_CONF: GTBEOUT Mask                 */
#define FTM_CONF_GTBEOUT_SHIFT                   (10U)                                               /*!< FTM0_CONF: GTBEOUT Position             */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK) /*!< FTM0_CONF                               */
/* ------- FLTPOL Bit Fields                        ------ */
#define FTM_FLTPOL_FLT0POL_MASK                  (0x1U)                                              /*!< FTM0_FLTPOL: FLT0POL Mask               */
#define FTM_FLTPOL_FLT0POL_SHIFT                 (0U)                                                /*!< FTM0_FLTPOL: FLT0POL Position           */
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT1POL_MASK                  (0x2U)                                              /*!< FTM0_FLTPOL: FLT1POL Mask               */
#define FTM_FLTPOL_FLT1POL_SHIFT                 (1U)                                                /*!< FTM0_FLTPOL: FLT1POL Position           */
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT2POL_MASK                  (0x4U)                                              /*!< FTM0_FLTPOL: FLT2POL Mask               */
#define FTM_FLTPOL_FLT2POL_SHIFT                 (2U)                                                /*!< FTM0_FLTPOL: FLT2POL Position           */
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT3POL_MASK                  (0x8U)                                              /*!< FTM0_FLTPOL: FLT3POL Mask               */
#define FTM_FLTPOL_FLT3POL_SHIFT                 (3U)                                                /*!< FTM0_FLTPOL: FLT3POL Position           */
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK) /*!< FTM0_FLTPOL                             */
/* ------- SYNCONF Bit Fields                       ------ */
#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x1U)                                              /*!< FTM0_SYNCONF: HWTRIGMODE Mask           */
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             (0U)                                                /*!< FTM0_SYNCONF: HWTRIGMODE Position       */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_CNTINC_MASK                  (0x4U)                                              /*!< FTM0_SYNCONF: CNTINC Mask               */
#define FTM_SYNCONF_CNTINC_SHIFT                 (2U)                                                /*!< FTM0_SYNCONF: CNTINC Position           */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_INVC_MASK                    (0x10U)                                             /*!< FTM0_SYNCONF: INVC Mask                 */
#define FTM_SYNCONF_INVC_SHIFT                   (4U)                                                /*!< FTM0_SYNCONF: INVC Position             */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOC_MASK                    (0x20U)                                             /*!< FTM0_SYNCONF: SWOC Mask                 */
#define FTM_SYNCONF_SWOC_SHIFT                   (5U)                                                /*!< FTM0_SYNCONF: SWOC Position             */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SYNCMODE_MASK                (0x80U)                                             /*!< FTM0_SYNCONF: SYNCMODE Mask             */
#define FTM_SYNCONF_SYNCMODE_SHIFT               (7U)                                                /*!< FTM0_SYNCONF: SYNCMODE Position         */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWRSTCNT_MASK                (0x100U)                                            /*!< FTM0_SYNCONF: SWRSTCNT Mask             */
#define FTM_SYNCONF_SWRSTCNT_SHIFT               (8U)                                                /*!< FTM0_SYNCONF: SWRSTCNT Position         */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWWRBUF_MASK                 (0x200U)                                            /*!< FTM0_SYNCONF: SWWRBUF Mask              */
#define FTM_SYNCONF_SWWRBUF_SHIFT                (9U)                                                /*!< FTM0_SYNCONF: SWWRBUF Position          */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOM_MASK                    (0x400U)                                            /*!< FTM0_SYNCONF: SWOM Mask                 */
#define FTM_SYNCONF_SWOM_SHIFT                   (10U)                                               /*!< FTM0_SYNCONF: SWOM Position             */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWINVC_MASK                  (0x800U)                                            /*!< FTM0_SYNCONF: SWINVC Mask               */
#define FTM_SYNCONF_SWINVC_SHIFT                 (11U)                                               /*!< FTM0_SYNCONF: SWINVC Position           */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWSOC_MASK                   (0x1000U)                                           /*!< FTM0_SYNCONF: SWSOC Mask                */
#define FTM_SYNCONF_SWSOC_SHIFT                  (12U)                                               /*!< FTM0_SYNCONF: SWSOC Position            */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWRSTCNT_MASK                (0x10000U)                                          /*!< FTM0_SYNCONF: HWRSTCNT Mask             */
#define FTM_SYNCONF_HWRSTCNT_SHIFT               (16U)                                               /*!< FTM0_SYNCONF: HWRSTCNT Position         */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWWRBUF_MASK                 (0x20000U)                                          /*!< FTM0_SYNCONF: HWWRBUF Mask              */
#define FTM_SYNCONF_HWWRBUF_SHIFT                (17U)                                               /*!< FTM0_SYNCONF: HWWRBUF Position          */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWOM_MASK                    (0x40000U)                                          /*!< FTM0_SYNCONF: HWOM Mask                 */
#define FTM_SYNCONF_HWOM_SHIFT                   (18U)                                               /*!< FTM0_SYNCONF: HWOM Position             */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWINVC_MASK                  (0x80000U)                                          /*!< FTM0_SYNCONF: HWINVC Mask               */
#define FTM_SYNCONF_HWINVC_SHIFT                 (19U)                                               /*!< FTM0_SYNCONF: HWINVC Position           */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWSOC_MASK                   (0x100000U)                                         /*!< FTM0_SYNCONF: HWSOC Mask                */
#define FTM_SYNCONF_HWSOC_SHIFT                  (20U)                                               /*!< FTM0_SYNCONF: HWSOC Position            */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK) /*!< FTM0_SYNCONF                            */
/* ------- INVCTRL Bit Fields                       ------ */
#define FTM_INVCTRL_INV0EN_MASK                  (0x1U)                                              /*!< FTM0_INVCTRL: INV0EN Mask               */
#define FTM_INVCTRL_INV0EN_SHIFT                 (0U)                                                /*!< FTM0_INVCTRL: INV0EN Position           */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV1EN_MASK                  (0x2U)                                              /*!< FTM0_INVCTRL: INV1EN Mask               */
#define FTM_INVCTRL_INV1EN_SHIFT                 (1U)                                                /*!< FTM0_INVCTRL: INV1EN Position           */
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV2EN_MASK                  (0x4U)                                              /*!< FTM0_INVCTRL: INV2EN Mask               */
#define FTM_INVCTRL_INV2EN_SHIFT                 (2U)                                                /*!< FTM0_INVCTRL: INV2EN Position           */
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV3EN_MASK                  (0x8U)                                              /*!< FTM0_INVCTRL: INV3EN Mask               */
#define FTM_INVCTRL_INV3EN_SHIFT                 (3U)                                                /*!< FTM0_INVCTRL: INV3EN Position           */
#define FTM_INVCTRL_INV3EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV3EN_SHIFT))&FTM_INVCTRL_INV3EN_MASK) /*!< FTM0_INVCTRL                            */
/* ------- SWOCTRL Bit Fields                       ------ */
#define FTM_SWOCTRL_CH0OC_MASK                   (0x1U)                                              /*!< FTM0_SWOCTRL: CH0OC Mask                */
#define FTM_SWOCTRL_CH0OC_SHIFT                  (0U)                                                /*!< FTM0_SWOCTRL: CH0OC Position            */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OC_MASK                   (0x2U)                                              /*!< FTM0_SWOCTRL: CH1OC Mask                */
#define FTM_SWOCTRL_CH1OC_SHIFT                  (1U)                                                /*!< FTM0_SWOCTRL: CH1OC Position            */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OC_MASK                   (0x4U)                                              /*!< FTM0_SWOCTRL: CH2OC Mask                */
#define FTM_SWOCTRL_CH2OC_SHIFT                  (2U)                                                /*!< FTM0_SWOCTRL: CH2OC Position            */
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OC_MASK                   (0x8U)                                              /*!< FTM0_SWOCTRL: CH3OC Mask                */
#define FTM_SWOCTRL_CH3OC_SHIFT                  (3U)                                                /*!< FTM0_SWOCTRL: CH3OC Position            */
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OC_MASK                   (0x10U)                                             /*!< FTM0_SWOCTRL: CH4OC Mask                */
#define FTM_SWOCTRL_CH4OC_SHIFT                  (4U)                                                /*!< FTM0_SWOCTRL: CH4OC Position            */
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OC_MASK                   (0x20U)                                             /*!< FTM0_SWOCTRL: CH5OC Mask                */
#define FTM_SWOCTRL_CH5OC_SHIFT                  (5U)                                                /*!< FTM0_SWOCTRL: CH5OC Position            */
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OC_MASK                   (0x40U)                                             /*!< FTM0_SWOCTRL: CH6OC Mask                */
#define FTM_SWOCTRL_CH6OC_SHIFT                  (6U)                                                /*!< FTM0_SWOCTRL: CH6OC Position            */
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OC_SHIFT))&FTM_SWOCTRL_CH6OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OC_MASK                   (0x80U)                                             /*!< FTM0_SWOCTRL: CH7OC Mask                */
#define FTM_SWOCTRL_CH7OC_SHIFT                  (7U)                                                /*!< FTM0_SWOCTRL: CH7OC Position            */
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OC_SHIFT))&FTM_SWOCTRL_CH7OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH0OCV_MASK                  (0x100U)                                            /*!< FTM0_SWOCTRL: CH0OCV Mask               */
#define FTM_SWOCTRL_CH0OCV_SHIFT                 (8U)                                                /*!< FTM0_SWOCTRL: CH0OCV Position           */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OCV_MASK                  (0x200U)                                            /*!< FTM0_SWOCTRL: CH1OCV Mask               */
#define FTM_SWOCTRL_CH1OCV_SHIFT                 (9U)                                                /*!< FTM0_SWOCTRL: CH1OCV Position           */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OCV_MASK                  (0x400U)                                            /*!< FTM0_SWOCTRL: CH2OCV Mask               */
#define FTM_SWOCTRL_CH2OCV_SHIFT                 (10U)                                               /*!< FTM0_SWOCTRL: CH2OCV Position           */
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OCV_MASK                  (0x800U)                                            /*!< FTM0_SWOCTRL: CH3OCV Mask               */
#define FTM_SWOCTRL_CH3OCV_SHIFT                 (11U)                                               /*!< FTM0_SWOCTRL: CH3OCV Position           */
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OCV_MASK                  (0x1000U)                                           /*!< FTM0_SWOCTRL: CH4OCV Mask               */
#define FTM_SWOCTRL_CH4OCV_SHIFT                 (12U)                                               /*!< FTM0_SWOCTRL: CH4OCV Position           */
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OCV_MASK                  (0x2000U)                                           /*!< FTM0_SWOCTRL: CH5OCV Mask               */
#define FTM_SWOCTRL_CH5OCV_SHIFT                 (13U)                                               /*!< FTM0_SWOCTRL: CH5OCV Position           */
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OCV_MASK                  (0x4000U)                                           /*!< FTM0_SWOCTRL: CH6OCV Mask               */
#define FTM_SWOCTRL_CH6OCV_SHIFT                 (14U)                                               /*!< FTM0_SWOCTRL: CH6OCV Position           */
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OCV_SHIFT))&FTM_SWOCTRL_CH6OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OCV_MASK                  (0x8000U)                                           /*!< FTM0_SWOCTRL: CH7OCV Mask               */
#define FTM_SWOCTRL_CH7OCV_SHIFT                 (15U)                                               /*!< FTM0_SWOCTRL: CH7OCV Position           */
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OCV_SHIFT))&FTM_SWOCTRL_CH7OCV_MASK) /*!< FTM0_SWOCTRL                            */
/* ------- PWMLOAD Bit Fields                       ------ */
#define FTM_PWMLOAD_CH0SEL_MASK                  (0x1U)                                              /*!< FTM0_PWMLOAD: CH0SEL Mask               */
#define FTM_PWMLOAD_CH0SEL_SHIFT                 (0U)                                                /*!< FTM0_PWMLOAD: CH0SEL Position           */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH1SEL_MASK                  (0x2U)                                              /*!< FTM0_PWMLOAD: CH1SEL Mask               */
#define FTM_PWMLOAD_CH1SEL_SHIFT                 (1U)                                                /*!< FTM0_PWMLOAD: CH1SEL Position           */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH2SEL_MASK                  (0x4U)                                              /*!< FTM0_PWMLOAD: CH2SEL Mask               */
#define FTM_PWMLOAD_CH2SEL_SHIFT                 (2U)                                                /*!< FTM0_PWMLOAD: CH2SEL Position           */
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH3SEL_MASK                  (0x8U)                                              /*!< FTM0_PWMLOAD: CH3SEL Mask               */
#define FTM_PWMLOAD_CH3SEL_SHIFT                 (3U)                                                /*!< FTM0_PWMLOAD: CH3SEL Position           */
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH4SEL_MASK                  (0x10U)                                             /*!< FTM0_PWMLOAD: CH4SEL Mask               */
#define FTM_PWMLOAD_CH4SEL_SHIFT                 (4U)                                                /*!< FTM0_PWMLOAD: CH4SEL Position           */
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH5SEL_MASK                  (0x20U)                                             /*!< FTM0_PWMLOAD: CH5SEL Mask               */
#define FTM_PWMLOAD_CH5SEL_SHIFT                 (5U)                                                /*!< FTM0_PWMLOAD: CH5SEL Position           */
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH6SEL_MASK                  (0x40U)                                             /*!< FTM0_PWMLOAD: CH6SEL Mask               */
#define FTM_PWMLOAD_CH6SEL_SHIFT                 (6U)                                                /*!< FTM0_PWMLOAD: CH6SEL Position           */
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH6SEL_SHIFT))&FTM_PWMLOAD_CH6SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH7SEL_MASK                  (0x80U)                                             /*!< FTM0_PWMLOAD: CH7SEL Mask               */
#define FTM_PWMLOAD_CH7SEL_SHIFT                 (7U)                                                /*!< FTM0_PWMLOAD: CH7SEL Position           */
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH7SEL_SHIFT))&FTM_PWMLOAD_CH7SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_LDOK_MASK                    (0x200U)                                            /*!< FTM0_PWMLOAD: LDOK Mask                 */
#define FTM_PWMLOAD_LDOK_SHIFT                   (9U)                                                /*!< FTM0_PWMLOAD: LDOK Position             */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK) /*!< FTM0_PWMLOAD                            */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0x40029000UL //!< Peripheral base address
#define FTM0                           ((FTM_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM1 (file:FTM1_2CH_MKE10)           ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[48];              
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
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM1_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- CNTIN Bit Fields                         ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- MODE Bit Fields                          ------ */
/* ------- SYNC Bit Fields                          ------ */
/* ------- OUTINIT Bit Fields                       ------ */
/* ------- OUTMASK Bit Fields                       ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- DEADTIME Bit Fields                      ------ */
/* ------- EXTTRIG Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FMS Bit Fields                           ------ */
/* ------- FILTER Bit Fields                        ------ */
/* ------- FLTCTRL Bit Fields                       ------ */
/* ------- QDCTRL Bit Fields                        ------ */
/* ------- CONF Bit Fields                          ------ */
/* ------- FLTPOL Bit Fields                        ------ */
/* ------- SYNCONF Bit Fields                       ------ */
/* ------- INVCTRL Bit Fields                       ------ */
/* ------- SWOCTRL Bit Fields                       ------ */
/* ------- PWMLOAD Bit Fields                       ------ */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0x4002A000UL //!< Peripheral base address
#define FTM1                           ((FTM1_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM2 (derived from FTM1)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */

/* FTM2 - Peripheral instance base addresses */
#define FTM2_BasePtr                   0x4002B000UL //!< Peripheral base address
#define FTM2                           ((FTM1_Type *) FTM2_BasePtr) //!< Freescale base pointer
#define FTM2_BASE_PTR                  (FTM2) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM3 (derived from FTM0)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (6 channels)
 */

/* FTM3 - Peripheral instance base addresses */
#define FTM3_BasePtr                   0x4002C000UL //!< Peripheral base address
#define FTM3                           ((FTM_Type *) FTM3_BasePtr) //!< Freescale base pointer
#define FTM3_BASE_PTR                  (FTM3) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTMRA_Peripheral_access_layer_GROUP FTMRA Peripheral Access Layer
* @brief C Struct for FTMRA
* @{
*/

/* ================================================================================ */
/* ================           FTMRA (file:FTMRA)                   ================ */
/* ================================================================================ */

/**
 * @brief FTMRA Family Flash Module
 */
/**
* @addtogroup FTMRA_structs_GROUP FTMRA struct
* @brief Struct for FTMRA
* @{
*/
typedef struct {                                /*       FTMRA Structure                                              */
   __I  uint8_t   FSEC;                         /**< 0000: Flash Security Register                                      */
   __IO uint8_t   FCLKDIV;                      /**< 0001: Flash Clock Divider Register                                 */
   __IO uint8_t   FECCRIX;                      /**< 0002: Flash ECCR Index Register                                    */
   __IO uint8_t   FCCOBIX;                      /**< 0003: Flash Common Command Object Index Register                   */
   __IO uint8_t   FERCNFG;                      /**< 0004: Flash Error Configuration Register                           */
   __IO uint8_t   FCNFG;                        /**< 0005: Flash Configuration Register                                 */
   __IO uint8_t   FERSTAT;                      /**< 0006: Flash Error Status Register                                  */
   __IO uint8_t   FSTAT;                        /**< 0007: Flash Status Register                                        */
   __IO uint8_t   DFPROT;                       /**< 0008: D-Flash Protection Register                                  */
   __IO uint8_t   FPROT;                        /**< 0009: P-Flash Protection Register                                  */
   __IO uint8_t   FCCOBLO;                      /**< 000A: Flash Common Command Object Low Register                     */
   __IO uint8_t   FCCOBHI;                      /**< 000B: Flash Common Command Object High Register                    */
        uint8_t   RESERVED_0[2];               
   __I  uint8_t   FECCRLO;                      /**< 000E: Flash ECC Error Results Low Register                         */
   __I  uint8_t   FECCRHI;                      /**< 000F: Flash ECC Error Results High Register                        */
        uint8_t   RESERVED_1;                  
   __I  uint8_t   FOPT;                         /**< 0011: Flash Option Register                                        */
} FTMRA_Type;

/**
 * @} */ /* End group FTMRA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTMRA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTMRA_Register_Masks_GROUP FTMRA Register Masks
* @brief Register Masks for FTMRA
* @{
*/
/* ------- FSEC Bit Fields                          ------ */
#define FTMRA_FSEC_SEC_MASK                      (0x3U)                                              /*!< FTMRA_FSEC: SEC Mask                    */
#define FTMRA_FSEC_SEC_SHIFT                     (0U)                                                /*!< FTMRA_FSEC: SEC Position                */
#define FTMRA_FSEC_SEC(x)                        (((uint8_t)(((uint8_t)(x))<<FTMRA_FSEC_SEC_SHIFT))&FTMRA_FSEC_SEC_MASK) /*!< FTMRA_FSEC                              */
#define FTMRA_FSEC_RNV_MASK                      (0x3CU)                                             /*!< FTMRA_FSEC: RNV Mask                    */
#define FTMRA_FSEC_RNV_SHIFT                     (2U)                                                /*!< FTMRA_FSEC: RNV Position                */
#define FTMRA_FSEC_RNV(x)                        (((uint8_t)(((uint8_t)(x))<<FTMRA_FSEC_RNV_SHIFT))&FTMRA_FSEC_RNV_MASK) /*!< FTMRA_FSEC                              */
#define FTMRA_FSEC_KEYEN_MASK                    (0xC0U)                                             /*!< FTMRA_FSEC: KEYEN Mask                  */
#define FTMRA_FSEC_KEYEN_SHIFT                   (6U)                                                /*!< FTMRA_FSEC: KEYEN Position              */
#define FTMRA_FSEC_KEYEN(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FSEC_KEYEN_SHIFT))&FTMRA_FSEC_KEYEN_MASK) /*!< FTMRA_FSEC                              */
/* ------- FCLKDIV Bit Fields                       ------ */
#define FTMRA_FCLKDIV_FDIV_MASK                  (0x7FU)                                             /*!< FTMRA_FCLKDIV: FDIV Mask                */
#define FTMRA_FCLKDIV_FDIV_SHIFT                 (0U)                                                /*!< FTMRA_FCLKDIV: FDIV Position            */
#define FTMRA_FCLKDIV_FDIV(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FCLKDIV_FDIV_SHIFT))&FTMRA_FCLKDIV_FDIV_MASK) /*!< FTMRA_FCLKDIV                           */
#define FTMRA_FCLKDIV_FDIVLD_MASK                (0x80U)                                             /*!< FTMRA_FCLKDIV: FDIVLD Mask              */
#define FTMRA_FCLKDIV_FDIVLD_SHIFT               (7U)                                                /*!< FTMRA_FCLKDIV: FDIVLD Position          */
#define FTMRA_FCLKDIV_FDIVLD(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRA_FCLKDIV_FDIVLD_SHIFT))&FTMRA_FCLKDIV_FDIVLD_MASK) /*!< FTMRA_FCLKDIV                           */
/* ------- FECCRIX Bit Fields                       ------ */
#define FTMRA_FECCRIX_ECCRIX_MASK                (0x7U)                                              /*!< FTMRA_FECCRIX: ECCRIX Mask              */
#define FTMRA_FECCRIX_ECCRIX_SHIFT               (0U)                                                /*!< FTMRA_FECCRIX: ECCRIX Position          */
#define FTMRA_FECCRIX_ECCRIX(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRA_FECCRIX_ECCRIX_SHIFT))&FTMRA_FECCRIX_ECCRIX_MASK) /*!< FTMRA_FECCRIX                           */
/* ------- FCCOBIX Bit Fields                       ------ */
#define FTMRA_FCCOBIX_CCOBIX_MASK                (0x7U)                                              /*!< FTMRA_FCCOBIX: CCOBIX Mask              */
#define FTMRA_FCCOBIX_CCOBIX_SHIFT               (0U)                                                /*!< FTMRA_FCCOBIX: CCOBIX Position          */
#define FTMRA_FCCOBIX_CCOBIX(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRA_FCCOBIX_CCOBIX_SHIFT))&FTMRA_FCCOBIX_CCOBIX_MASK) /*!< FTMRA_FCCOBIX                           */
/* ------- FERCNFG Bit Fields                       ------ */
#define FTMRA_FERCNFG_SFDIE_MASK                 (0x1U)                                              /*!< FTMRA_FERCNFG: SFDIE Mask               */
#define FTMRA_FERCNFG_SFDIE_SHIFT                (0U)                                                /*!< FTMRA_FERCNFG: SFDIE Position           */
#define FTMRA_FERCNFG_SFDIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FERCNFG_SFDIE_SHIFT))&FTMRA_FERCNFG_SFDIE_MASK) /*!< FTMRA_FERCNFG                           */
#define FTMRA_FERCNFG_DFDIE_MASK                 (0x2U)                                              /*!< FTMRA_FERCNFG: DFDIE Mask               */
#define FTMRA_FERCNFG_DFDIE_SHIFT                (1U)                                                /*!< FTMRA_FERCNFG: DFDIE Position           */
#define FTMRA_FERCNFG_DFDIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FERCNFG_DFDIE_SHIFT))&FTMRA_FERCNFG_DFDIE_MASK) /*!< FTMRA_FERCNFG                           */
/* ------- FCNFG Bit Fields                         ------ */
#define FTMRA_FCNFG_FSFD_MASK                    (0x1U)                                              /*!< FTMRA_FCNFG: FSFD Mask                  */
#define FTMRA_FCNFG_FSFD_SHIFT                   (0U)                                                /*!< FTMRA_FCNFG: FSFD Position              */
#define FTMRA_FCNFG_FSFD(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FCNFG_FSFD_SHIFT))&FTMRA_FCNFG_FSFD_MASK) /*!< FTMRA_FCNFG                             */
#define FTMRA_FCNFG_FDFD_MASK                    (0x2U)                                              /*!< FTMRA_FCNFG: FDFD Mask                  */
#define FTMRA_FCNFG_FDFD_SHIFT                   (1U)                                                /*!< FTMRA_FCNFG: FDFD Position              */
#define FTMRA_FCNFG_FDFD(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FCNFG_FDFD_SHIFT))&FTMRA_FCNFG_FDFD_MASK) /*!< FTMRA_FCNFG                             */
#define FTMRA_FCNFG_IGNSF_MASK                   (0x10U)                                             /*!< FTMRA_FCNFG: IGNSF Mask                 */
#define FTMRA_FCNFG_IGNSF_SHIFT                  (4U)                                                /*!< FTMRA_FCNFG: IGNSF Position             */
#define FTMRA_FCNFG_IGNSF(x)                     (((uint8_t)(((uint8_t)(x))<<FTMRA_FCNFG_IGNSF_SHIFT))&FTMRA_FCNFG_IGNSF_MASK) /*!< FTMRA_FCNFG                             */
#define FTMRA_FCNFG_ERSAREQ_MASK                 (0x20U)                                             /*!< FTMRA_FCNFG: ERSAREQ Mask               */
#define FTMRA_FCNFG_ERSAREQ_SHIFT                (5U)                                                /*!< FTMRA_FCNFG: ERSAREQ Position           */
#define FTMRA_FCNFG_ERSAREQ(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FCNFG_ERSAREQ_SHIFT))&FTMRA_FCNFG_ERSAREQ_MASK) /*!< FTMRA_FCNFG                             */
#define FTMRA_FCNFG_CCIE_MASK                    (0x80U)                                             /*!< FTMRA_FCNFG: CCIE Mask                  */
#define FTMRA_FCNFG_CCIE_SHIFT                   (7U)                                                /*!< FTMRA_FCNFG: CCIE Position              */
#define FTMRA_FCNFG_CCIE(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FCNFG_CCIE_SHIFT))&FTMRA_FCNFG_CCIE_MASK) /*!< FTMRA_FCNFG                             */
/* ------- FERSTAT Bit Fields                       ------ */
#define FTMRA_FERSTAT_SFDIF_MASK                 (0x1U)                                              /*!< FTMRA_FERSTAT: SFDIF Mask               */
#define FTMRA_FERSTAT_SFDIF_SHIFT                (0U)                                                /*!< FTMRA_FERSTAT: SFDIF Position           */
#define FTMRA_FERSTAT_SFDIF(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FERSTAT_SFDIF_SHIFT))&FTMRA_FERSTAT_SFDIF_MASK) /*!< FTMRA_FERSTAT                           */
#define FTMRA_FERSTAT_DFDIF_MASK                 (0x2U)                                              /*!< FTMRA_FERSTAT: DFDIF Mask               */
#define FTMRA_FERSTAT_DFDIF_SHIFT                (1U)                                                /*!< FTMRA_FERSTAT: DFDIF Position           */
#define FTMRA_FERSTAT_DFDIF(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FERSTAT_DFDIF_SHIFT))&FTMRA_FERSTAT_DFDIF_MASK) /*!< FTMRA_FERSTAT                           */
/* ------- FSTAT Bit Fields                         ------ */
#define FTMRA_FSTAT_MGSTAT_MASK                  (0x3U)                                              /*!< FTMRA_FSTAT: MGSTAT Mask                */
#define FTMRA_FSTAT_MGSTAT_SHIFT                 (0U)                                                /*!< FTMRA_FSTAT: MGSTAT Position            */
#define FTMRA_FSTAT_MGSTAT(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FSTAT_MGSTAT_SHIFT))&FTMRA_FSTAT_MGSTAT_MASK) /*!< FTMRA_FSTAT                             */
#define FTMRA_FSTAT_MGBUSY_MASK                  (0x8U)                                              /*!< FTMRA_FSTAT: MGBUSY Mask                */
#define FTMRA_FSTAT_MGBUSY_SHIFT                 (3U)                                                /*!< FTMRA_FSTAT: MGBUSY Position            */
#define FTMRA_FSTAT_MGBUSY(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FSTAT_MGBUSY_SHIFT))&FTMRA_FSTAT_MGBUSY_MASK) /*!< FTMRA_FSTAT                             */
#define FTMRA_FSTAT_FPVIOL_MASK                  (0x10U)                                             /*!< FTMRA_FSTAT: FPVIOL Mask                */
#define FTMRA_FSTAT_FPVIOL_SHIFT                 (4U)                                                /*!< FTMRA_FSTAT: FPVIOL Position            */
#define FTMRA_FSTAT_FPVIOL(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FSTAT_FPVIOL_SHIFT))&FTMRA_FSTAT_FPVIOL_MASK) /*!< FTMRA_FSTAT                             */
#define FTMRA_FSTAT_ACCERR_MASK                  (0x20U)                                             /*!< FTMRA_FSTAT: ACCERR Mask                */
#define FTMRA_FSTAT_ACCERR_SHIFT                 (5U)                                                /*!< FTMRA_FSTAT: ACCERR Position            */
#define FTMRA_FSTAT_ACCERR(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FSTAT_ACCERR_SHIFT))&FTMRA_FSTAT_ACCERR_MASK) /*!< FTMRA_FSTAT                             */
#define FTMRA_FSTAT_CCIF_MASK                    (0x80U)                                             /*!< FTMRA_FSTAT: CCIF Mask                  */
#define FTMRA_FSTAT_CCIF_SHIFT                   (7U)                                                /*!< FTMRA_FSTAT: CCIF Position              */
#define FTMRA_FSTAT_CCIF(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FSTAT_CCIF_SHIFT))&FTMRA_FSTAT_CCIF_MASK) /*!< FTMRA_FSTAT                             */
/* ------- DFPROT Bit Fields                        ------ */
#define FTMRA_DFPROT_DPS_MASK                    (0x1FU)                                             /*!< FTMRA_DFPROT: DPS Mask                  */
#define FTMRA_DFPROT_DPS_SHIFT                   (0U)                                                /*!< FTMRA_DFPROT: DPS Position              */
#define FTMRA_DFPROT_DPS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_DFPROT_DPS_SHIFT))&FTMRA_DFPROT_DPS_MASK) /*!< FTMRA_DFPROT                            */
#define FTMRA_DFPROT_DPOPEN_MASK                 (0x80U)                                             /*!< FTMRA_DFPROT: DPOPEN Mask               */
#define FTMRA_DFPROT_DPOPEN_SHIFT                (7U)                                                /*!< FTMRA_DFPROT: DPOPEN Position           */
#define FTMRA_DFPROT_DPOPEN(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_DFPROT_DPOPEN_SHIFT))&FTMRA_DFPROT_DPOPEN_MASK) /*!< FTMRA_DFPROT                            */
/* ------- FPROT Bit Fields                         ------ */
#define FTMRA_FPROT_FPLS_MASK                    (0x3U)                                              /*!< FTMRA_FPROT: FPLS Mask                  */
#define FTMRA_FPROT_FPLS_SHIFT                   (0U)                                                /*!< FTMRA_FPROT: FPLS Position              */
#define FTMRA_FPROT_FPLS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_FPLS_SHIFT))&FTMRA_FPROT_FPLS_MASK) /*!< FTMRA_FPROT                             */
#define FTMRA_FPROT_FPLDIS_MASK                  (0x4U)                                              /*!< FTMRA_FPROT: FPLDIS Mask                */
#define FTMRA_FPROT_FPLDIS_SHIFT                 (2U)                                                /*!< FTMRA_FPROT: FPLDIS Position            */
#define FTMRA_FPROT_FPLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_FPLDIS_SHIFT))&FTMRA_FPROT_FPLDIS_MASK) /*!< FTMRA_FPROT                             */
#define FTMRA_FPROT_FPHS_MASK                    (0x18U)                                             /*!< FTMRA_FPROT: FPHS Mask                  */
#define FTMRA_FPROT_FPHS_SHIFT                   (3U)                                                /*!< FTMRA_FPROT: FPHS Position              */
#define FTMRA_FPROT_FPHS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_FPHS_SHIFT))&FTMRA_FPROT_FPHS_MASK) /*!< FTMRA_FPROT                             */
#define FTMRA_FPROT_FPHDIS_MASK                  (0x20U)                                             /*!< FTMRA_FPROT: FPHDIS Mask                */
#define FTMRA_FPROT_FPHDIS_SHIFT                 (5U)                                                /*!< FTMRA_FPROT: FPHDIS Position            */
#define FTMRA_FPROT_FPHDIS(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_FPHDIS_SHIFT))&FTMRA_FPROT_FPHDIS_MASK) /*!< FTMRA_FPROT                             */
#define FTMRA_FPROT_RNV_MASK                     (0x40U)                                             /*!< FTMRA_FPROT: RNV Mask                   */
#define FTMRA_FPROT_RNV_SHIFT                    (6U)                                                /*!< FTMRA_FPROT: RNV Position               */
#define FTMRA_FPROT_RNV(x)                       (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_RNV_SHIFT))&FTMRA_FPROT_RNV_MASK) /*!< FTMRA_FPROT                             */
#define FTMRA_FPROT_FPOPEN_MASK                  (0x80U)                                             /*!< FTMRA_FPROT: FPOPEN Mask                */
#define FTMRA_FPROT_FPOPEN_SHIFT                 (7U)                                                /*!< FTMRA_FPROT: FPOPEN Position            */
#define FTMRA_FPROT_FPOPEN(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FPROT_FPOPEN_SHIFT))&FTMRA_FPROT_FPOPEN_MASK) /*!< FTMRA_FPROT                             */
/* ------- FCCOBLO Bit Fields                       ------ */
#define FTMRA_FCCOBLO_CCOBn_MASK                 (0xFFU)                                             /*!< FTMRA_FCCOBLO: CCOBn Mask               */
#define FTMRA_FCCOBLO_CCOBn_SHIFT                (0U)                                                /*!< FTMRA_FCCOBLO: CCOBn Position           */
#define FTMRA_FCCOBLO_CCOBn(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FCCOBLO_CCOBn_SHIFT))&FTMRA_FCCOBLO_CCOBn_MASK) /*!< FTMRA_FCCOBLO                           */
/* ------- FCCOBHI Bit Fields                       ------ */
#define FTMRA_FCCOBHI_CCOBn_MASK                 (0xFFU)                                             /*!< FTMRA_FCCOBHI: CCOBn Mask               */
#define FTMRA_FCCOBHI_CCOBn_SHIFT                (0U)                                                /*!< FTMRA_FCCOBHI: CCOBn Position           */
#define FTMRA_FCCOBHI_CCOBn(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRA_FCCOBHI_CCOBn_SHIFT))&FTMRA_FCCOBHI_CCOBn_MASK) /*!< FTMRA_FCCOBHI                           */
/* ------- FECCRLO Bit Fields                       ------ */
#define FTMRA_FECCRLO_ECCR_MASK                  (0xFFU)                                             /*!< FTMRA_FECCRLO: ECCR Mask                */
#define FTMRA_FECCRLO_ECCR_SHIFT                 (0U)                                                /*!< FTMRA_FECCRLO: ECCR Position            */
#define FTMRA_FECCRLO_ECCR(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FECCRLO_ECCR_SHIFT))&FTMRA_FECCRLO_ECCR_MASK) /*!< FTMRA_FECCRLO                           */
/* ------- FECCRHI Bit Fields                       ------ */
#define FTMRA_FECCRHI_ECCR_MASK                  (0xFFU)                                             /*!< FTMRA_FECCRHI: ECCR Mask                */
#define FTMRA_FECCRHI_ECCR_SHIFT                 (0U)                                                /*!< FTMRA_FECCRHI: ECCR Position            */
#define FTMRA_FECCRHI_ECCR(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRA_FECCRHI_ECCR_SHIFT))&FTMRA_FECCRHI_ECCR_MASK) /*!< FTMRA_FECCRHI                           */
/* ------- FOPT Bit Fields                          ------ */
#define FTMRA_FOPT_NV_MASK                       (0xFFU)                                             /*!< FTMRA_FOPT: NV Mask                     */
#define FTMRA_FOPT_NV_SHIFT                      (0U)                                                /*!< FTMRA_FOPT: NV Position                 */
#define FTMRA_FOPT_NV(x)                         (((uint8_t)(((uint8_t)(x))<<FTMRA_FOPT_NV_SHIFT))&FTMRA_FOPT_NV_MASK) /*!< FTMRA_FOPT                              */
/**
 * @} */ /* End group FTMRA_Register_Masks_GROUP 
 */

/* FTMRA - Peripheral instance base addresses */
#define FTMRA_BasePtr                  0x40039000UL //!< Peripheral base address
#define FTMRA                          ((FTMRA_Type *) FTMRA_BasePtr) //!< Freescale base pointer
#define FTMRA_BASE_PTR                 (FTMRA) //!< Freescale style base pointer
/**
 * @} */ /* End group FTMRA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x4007F000)        ================ */
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
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
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
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIOA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x4007F000UL //!< Peripheral base address
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
#define GPIOB_BasePtr                  0x4007F040UL //!< Peripheral base address
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
#define GPIOC_BasePtr                  0x4007F080UL //!< Peripheral base address
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
#define GPIOD_BasePtr                  0x4007F0C0UL //!< Peripheral base address
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
#define GPIOE_BasePtr                  0x4007F100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKE10)               ================ */
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
#define I2C_A1_AD_MASK                           (0xFEU)                                             /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          (1U)                                                /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          (0U)                                                /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         (6U)                                                /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_DMAEN_SHIFT))&I2C_C1_DMAEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_WUEN_SHIFT))&I2C_C1_WUEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_RSTA_SHIFT))&I2C_C1_RSTA_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_TXAK_SHIFT))&I2C_C1_TXAK_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TX_MASK                           (0x10U)                                             /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          (4U)                                                /*!< I2C0_C1: TX Position                    */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C1_TX_SHIFT))&I2C_C1_TX_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_MST_MASK                          (0x20U)                                             /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         (5U)                                                /*!< I2C0_C1: MST Position                   */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_C1_MST_SHIFT))&I2C_C1_MST_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICIE_SHIFT))&I2C_C1_IICIE_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /*!< I2C0_C1: IICEN Position                 */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICEN_SHIFT))&I2C_C1_IICEN_MASK) /*!< I2C0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /*!< I2C0_S: RXAK Position                   */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_RXAK_SHIFT))&I2C_S_RXAK_MASK) /*!< I2C0_S                                  */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /*!< I2C0_S: IICIF Position                  */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_S_IICIF_SHIFT))&I2C_S_IICIF_MASK) /*!< I2C0_S                                  */
#define I2C_S_SRW_MASK                           (0x4U)                                              /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          (2U)                                                /*!< I2C0_S: SRW Position                    */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_SRW_SHIFT))&I2C_S_SRW_MASK) /*!< I2C0_S                                  */
#define I2C_S_RAM_MASK                           (0x8U)                                              /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          (3U)                                                /*!< I2C0_S: RAM Position                    */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_RAM_SHIFT))&I2C_S_RAM_MASK) /*!< I2C0_S                                  */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /*!< I2C0_S: ARBL Position                   */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_ARBL_SHIFT))&I2C_S_ARBL_MASK) /*!< I2C0_S                                  */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /*!< I2C0_S: BUSY Position                   */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_BUSY_SHIFT))&I2C_S_BUSY_MASK) /*!< I2C0_S                                  */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /*!< I2C0_S: IAAS Position                   */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK) /*!< I2C0_S                                  */
#define I2C_S_TCF_MASK                           (0x80U)                                             /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          (7U)                                                /*!< I2C0_S: TCF Position                    */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_TCF_SHIFT))&I2C_S_TCF_MASK) /*!< I2C0_S                                  */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         (0U)                                                /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          (0U)                                                /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_RMEN_SHIFT))&I2C_C2_RMEN_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_SBRC_SHIFT))&I2C_C2_SBRC_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_HDRS_SHIFT))&I2C_C2_HDRS_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_ADEXT_SHIFT))&I2C_C2_ADEXT_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /*!< I2C0_C2: GCAEN Position                 */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_GCAEN_SHIFT))&I2C_C2_GCAEN_MASK) /*!< I2C0_C2                                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0x1FU)                                             /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_STOPIE_MASK                      (0x20U)                                             /*!< I2C0_FLT: STOPIE Mask                   */
#define I2C_FLT_STOPIE_SHIFT                     (5U)                                                /*!< I2C0_FLT: STOPIE Position               */
#define I2C_FLT_STOPIE(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STOPIE_SHIFT))&I2C_FLT_STOPIE_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_STOPF_MASK                       (0x40U)                                             /*!< I2C0_FLT: STOPF Mask                    */
#define I2C_FLT_STOPF_SHIFT                      (6U)                                                /*!< I2C0_FLT: STOPF Position                */
#define I2C_FLT_STOPF(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STOPF_SHIFT))&I2C_FLT_STOPF_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_SHEN_MASK                        (0x80U)                                             /*!< I2C0_FLT: SHEN Mask                     */
#define I2C_FLT_SHEN_SHIFT                       (7U)                                                /*!< I2C0_FLT: SHEN Position                 */
#define I2C_FLT_SHEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_FLT_SHEN_SHIFT))&I2C_FLT_SHEN_MASK) /*!< I2C0_FLT                                */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2IE_SHIFT))&I2C_SMB_SHTF2IE_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2_SHIFT))&I2C_SMB_SHTF2_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF1_SHIFT))&I2C_SMB_SHTF1_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SLTF_SHIFT))&I2C_SMB_SLTF_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_SMB_TCKSEL_SHIFT))&I2C_SMB_TCKSEL_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SIICAEN_SHIFT))&I2C_SMB_SIICAEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_ALERTEN_SHIFT))&I2C_SMB_ALERTEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /*!< I2C0_SMB: FACK Position                 */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_FACK_SHIFT))&I2C_SMB_FACK_MASK) /*!< I2C0_SMB                                */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40047000UL //!< Peripheral base address
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
#define I2C1_BasePtr                   0x40048000UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ICS_Peripheral_access_layer_GROUP ICS Peripheral Access Layer
* @brief C Struct for ICS
* @{
*/

/* ================================================================================ */
/* ================           ICS (file:ICS_MKE10)                 ================ */
/* ================================================================================ */

/**
 * @brief Internal clock source
 */
/**
* @addtogroup ICS_structs_GROUP ICS struct
* @brief Struct for ICS
* @{
*/
typedef struct {                                /*       ICS Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __I  uint8_t   S;                            /**< 0004: ICS Status Register                                          */
} ICS_Type;

/**
 * @} */ /* End group ICS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ICS' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ICS_Register_Masks_GROUP ICS Register Masks
* @brief Register Masks for ICS
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define ICS_C1_IREFSTEN_MASK                     (0x1U)                                              /*!< ICS_C1: IREFSTEN Mask                   */
#define ICS_C1_IREFSTEN_SHIFT                    (0U)                                                /*!< ICS_C1: IREFSTEN Position               */
#define ICS_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<ICS_C1_IREFSTEN_SHIFT))&ICS_C1_IREFSTEN_MASK) /*!< ICS_C1                                  */
#define ICS_C1_IRCLKEN_MASK                      (0x2U)                                              /*!< ICS_C1: IRCLKEN Mask                    */
#define ICS_C1_IRCLKEN_SHIFT                     (1U)                                                /*!< ICS_C1: IRCLKEN Position                */
#define ICS_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<ICS_C1_IRCLKEN_SHIFT))&ICS_C1_IRCLKEN_MASK) /*!< ICS_C1                                  */
#define ICS_C1_IREFS_MASK                        (0x4U)                                              /*!< ICS_C1: IREFS Mask                      */
#define ICS_C1_IREFS_SHIFT                       (2U)                                                /*!< ICS_C1: IREFS Position                  */
#define ICS_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<ICS_C1_IREFS_SHIFT))&ICS_C1_IREFS_MASK) /*!< ICS_C1                                  */
#define ICS_C1_RDIV_MASK                         (0x38U)                                             /*!< ICS_C1: RDIV Mask                       */
#define ICS_C1_RDIV_SHIFT                        (3U)                                                /*!< ICS_C1: RDIV Position                   */
#define ICS_C1_RDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_RDIV_SHIFT))&ICS_C1_RDIV_MASK) /*!< ICS_C1                                  */
#define ICS_C1_CLKS_MASK                         (0xC0U)                                             /*!< ICS_C1: CLKS Mask                       */
#define ICS_C1_CLKS_SHIFT                        (6U)                                                /*!< ICS_C1: CLKS Position                   */
#define ICS_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_CLKS_SHIFT))&ICS_C1_CLKS_MASK) /*!< ICS_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define ICS_C2_FRDIV_MASK                        (0xCU)                                              /*!< ICS_C2: FRDIV Mask                      */
#define ICS_C2_FRDIV_SHIFT                       (2U)                                                /*!< ICS_C2: FRDIV Position                  */
#define ICS_C2_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<ICS_C2_FRDIV_SHIFT))&ICS_C2_FRDIV_MASK) /*!< ICS_C2                                  */
#define ICS_C2_LP_MASK                           (0x10U)                                             /*!< ICS_C2: LP Mask                         */
#define ICS_C2_LP_SHIFT                          (4U)                                                /*!< ICS_C2: LP Position                     */
#define ICS_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<ICS_C2_LP_SHIFT))&ICS_C2_LP_MASK) /*!< ICS_C2                                  */
#define ICS_C2_BDIV_MASK                         (0xE0U)                                             /*!< ICS_C2: BDIV Mask                       */
#define ICS_C2_BDIV_SHIFT                        (5U)                                                /*!< ICS_C2: BDIV Position                   */
#define ICS_C2_BDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C2_BDIV_SHIFT))&ICS_C2_BDIV_MASK) /*!< ICS_C2                                  */
/* ------- C3 Bit Fields                            ------ */
#define ICS_C3_SCTRIM_MASK                       (0xFFU)                                             /*!< ICS_C3: SCTRIM Mask                     */
#define ICS_C3_SCTRIM_SHIFT                      (0U)                                                /*!< ICS_C3: SCTRIM Position                 */
#define ICS_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C3_SCTRIM_SHIFT))&ICS_C3_SCTRIM_MASK) /*!< ICS_C3                                  */
/* ------- C4 Bit Fields                            ------ */
#define ICS_C4_SCFTRIM_MASK                      (0x1U)                                              /*!< ICS_C4: SCFTRIM Mask                    */
#define ICS_C4_SCFTRIM_SHIFT                     (0U)                                                /*!< ICS_C4: SCFTRIM Position                */
#define ICS_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<ICS_C4_SCFTRIM_SHIFT))&ICS_C4_SCFTRIM_MASK) /*!< ICS_C4                                  */
#define ICS_C4_CME_MASK                          (0x20U)                                             /*!< ICS_C4: CME Mask                        */
#define ICS_C4_CME_SHIFT                         (5U)                                                /*!< ICS_C4: CME Position                    */
#define ICS_C4_CME(x)                            (((uint8_t)(((uint8_t)(x))<<ICS_C4_CME_SHIFT))&ICS_C4_CME_MASK) /*!< ICS_C4                                  */
#define ICS_C4_RLOLIE_MASK                       (0x40U)                                             /*!< ICS_C4: RLOLIE Mask                     */
#define ICS_C4_RLOLIE_SHIFT                      (6U)                                                /*!< ICS_C4: RLOLIE Position                 */
#define ICS_C4_RLOLIE(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C4_RLOLIE_SHIFT))&ICS_C4_RLOLIE_MASK) /*!< ICS_C4                                  */
#define ICS_C4_FLOLIE_MASK                       (0x80U)                                             /*!< ICS_C4: FLOLIE Mask                     */
#define ICS_C4_FLOLIE_SHIFT                      (7U)                                                /*!< ICS_C4: FLOLIE Position                 */
#define ICS_C4_FLOLIE(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C4_FLOLIE_SHIFT))&ICS_C4_FLOLIE_MASK) /*!< ICS_C4                                  */
/* ------- S Bit Fields                             ------ */
#define ICS_S_CLKST_MASK                         (0xCU)                                              /*!< ICS_S: CLKST Mask                       */
#define ICS_S_CLKST_SHIFT                        (2U)                                                /*!< ICS_S: CLKST Position                   */
#define ICS_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_CLKST_SHIFT))&ICS_S_CLKST_MASK) /*!< ICS_S                                   */
#define ICS_S_IREFST_MASK                        (0x10U)                                             /*!< ICS_S: IREFST Mask                      */
#define ICS_S_IREFST_SHIFT                       (4U)                                                /*!< ICS_S: IREFST Position                  */
#define ICS_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<ICS_S_IREFST_SHIFT))&ICS_S_IREFST_MASK) /*!< ICS_S                                   */
#define ICS_S_RLOCK_MASK                         (0x20U)                                             /*!< ICS_S: RLOCK Mask                       */
#define ICS_S_RLOCK_SHIFT                        (5U)                                                /*!< ICS_S: RLOCK Position                   */
#define ICS_S_RLOCK(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_RLOCK_SHIFT))&ICS_S_RLOCK_MASK) /*!< ICS_S                                   */
#define ICS_S_FLOCK_MASK                         (0x40U)                                             /*!< ICS_S: FLOCK Mask                       */
#define ICS_S_FLOCK_SHIFT                        (6U)                                                /*!< ICS_S: FLOCK Position                   */
#define ICS_S_FLOCK(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_FLOCK_SHIFT))&ICS_S_FLOCK_MASK) /*!< ICS_S                                   */
#define ICS_S_LOLS_MASK                          (0x80U)                                             /*!< ICS_S: LOLS Mask                        */
#define ICS_S_LOLS_SHIFT                         (7U)                                                /*!< ICS_S: LOLS Position                    */
#define ICS_S_LOLS(x)                            (((uint8_t)(((uint8_t)(x))<<ICS_S_LOLS_SHIFT))&ICS_S_LOLS_MASK) /*!< ICS_S                                   */
/**
 * @} */ /* End group ICS_Register_Masks_GROUP 
 */

/* ICS - Peripheral instance base addresses */
#define ICS_BasePtr                    0x40044000UL //!< Peripheral base address
#define ICS                            ((ICS_Type *) ICS_BasePtr) //!< Freescale base pointer
#define ICS_BASE_PTR                   (ICS) //!< Freescale style base pointer
/**
 * @} */ /* End group ICS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup IEVENT_Peripheral_access_layer_GROUP IEVENT Peripheral Access Layer
* @brief C Struct for IEVENT
* @{
*/

/* ================================================================================ */
/* ================           IEVENT (file:IEVENT_0)               ================ */
/* ================================================================================ */

/**
 * @brief Intelligent event controller
 */
/**
* @addtogroup IEVENT_structs_GROUP IEVENT struct
* @brief Struct for IEVENT
* @{
*/
typedef struct {                                /*       IEVENT Structure                                             */
   __IO uint32_t  DRL;                          /**< 0000: iEvent Data Register: Low                                    */
        uint8_t   RESERVED_0[124];             
   __IO uint32_t  CRL;                          /**< 0080: iEvent Control Register: Low                                 */
        uint8_t   RESERVED_1[124];             
   __I  uint32_t  IMXCR0;                       /**< 0100: iEvent Input Mux Configuration Register                      */
   __IO uint32_t  BFECR0;                       /**< 0104: iEvent Boolean Function Eva1ation Configuration Register     */
   __I  uint32_t  IMXCR1;                       /**< 0108: iEvent Input Mux Configuration Register                      */
   __IO uint32_t  BFECR1;                       /**< 010C: iEvent Boolean Function Eva1ation Configuration Register     */
   __I  uint32_t  IMXCR2;                       /**< 0110: iEvent Input Mux Configuration Register                      */
   __IO uint32_t  BFECR2;                       /**< 0114: iEvent Boolean Function Eva1ation Configuration Register     */
   __I  uint32_t  IMXCR3;                       /**< 0118: iEvent Input Mux Configuration Register                      */
   __IO uint32_t  BFECR3;                       /**< 011C: iEvent Boolean Function Eva1ation Configuration Register     */
} IEVENT_Type;

/**
 * @} */ /* End group IEVENT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'IEVENT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup IEVENT_Register_Masks_GROUP IEVENT Register Masks
* @brief Register Masks for IEVENT
* @{
*/
/* ------- DRL Bit Fields                           ------ */
#define IEVENT_DRL_IN_A0_MASK                    (0x1U)                                              /*!< IEVENT_DRL: IN_A0 Mask                  */
#define IEVENT_DRL_IN_A0_SHIFT                   (0U)                                                /*!< IEVENT_DRL: IN_A0 Position              */
#define IEVENT_DRL_IN_A0(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_A0_SHIFT))&IEVENT_DRL_IN_A0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_B0_MASK                    (0x2U)                                              /*!< IEVENT_DRL: IN_B0 Mask                  */
#define IEVENT_DRL_IN_B0_SHIFT                   (1U)                                                /*!< IEVENT_DRL: IN_B0 Position              */
#define IEVENT_DRL_IN_B0(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_B0_SHIFT))&IEVENT_DRL_IN_B0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_C0_MASK                    (0x4U)                                              /*!< IEVENT_DRL: IN_C0 Mask                  */
#define IEVENT_DRL_IN_C0_SHIFT                   (2U)                                                /*!< IEVENT_DRL: IN_C0 Position              */
#define IEVENT_DRL_IN_C0(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_C0_SHIFT))&IEVENT_DRL_IN_C0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_D0_MASK                    (0x8U)                                              /*!< IEVENT_DRL: IN_D0 Mask                  */
#define IEVENT_DRL_IN_D0_SHIFT                   (3U)                                                /*!< IEVENT_DRL: IN_D0 Position              */
#define IEVENT_DRL_IN_D0(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_D0_SHIFT))&IEVENT_DRL_IN_D0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Output_FSM0_MASK              (0x70U)                                             /*!< IEVENT_DRL: Output_FSM0 Mask            */
#define IEVENT_DRL_Output_FSM0_SHIFT             (4U)                                                /*!< IEVENT_DRL: Output_FSM0 Position        */
#define IEVENT_DRL_Output_FSM0(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Output_FSM0_SHIFT))&IEVENT_DRL_Output_FSM0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Ev_Out0_MASK                  (0x80U)                                             /*!< IEVENT_DRL: Ev_Out0 Mask                */
#define IEVENT_DRL_Ev_Out0_SHIFT                 (7U)                                                /*!< IEVENT_DRL: Ev_Out0 Position            */
#define IEVENT_DRL_Ev_Out0(x)                    (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Ev_Out0_SHIFT))&IEVENT_DRL_Ev_Out0_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_A1_MASK                    (0x100U)                                            /*!< IEVENT_DRL: IN_A1 Mask                  */
#define IEVENT_DRL_IN_A1_SHIFT                   (8U)                                                /*!< IEVENT_DRL: IN_A1 Position              */
#define IEVENT_DRL_IN_A1(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_A1_SHIFT))&IEVENT_DRL_IN_A1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_B1_MASK                    (0x200U)                                            /*!< IEVENT_DRL: IN_B1 Mask                  */
#define IEVENT_DRL_IN_B1_SHIFT                   (9U)                                                /*!< IEVENT_DRL: IN_B1 Position              */
#define IEVENT_DRL_IN_B1(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_B1_SHIFT))&IEVENT_DRL_IN_B1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_C1_MASK                    (0x400U)                                            /*!< IEVENT_DRL: IN_C1 Mask                  */
#define IEVENT_DRL_IN_C1_SHIFT                   (10U)                                               /*!< IEVENT_DRL: IN_C1 Position              */
#define IEVENT_DRL_IN_C1(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_C1_SHIFT))&IEVENT_DRL_IN_C1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_D1_MASK                    (0x800U)                                            /*!< IEVENT_DRL: IN_D1 Mask                  */
#define IEVENT_DRL_IN_D1_SHIFT                   (11U)                                               /*!< IEVENT_DRL: IN_D1 Position              */
#define IEVENT_DRL_IN_D1(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_D1_SHIFT))&IEVENT_DRL_IN_D1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Output_FSM1_MASK              (0x7000U)                                           /*!< IEVENT_DRL: Output_FSM1 Mask            */
#define IEVENT_DRL_Output_FSM1_SHIFT             (12U)                                               /*!< IEVENT_DRL: Output_FSM1 Position        */
#define IEVENT_DRL_Output_FSM1(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Output_FSM1_SHIFT))&IEVENT_DRL_Output_FSM1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Ev_Out1_MASK                  (0x8000U)                                           /*!< IEVENT_DRL: Ev_Out1 Mask                */
#define IEVENT_DRL_Ev_Out1_SHIFT                 (15U)                                               /*!< IEVENT_DRL: Ev_Out1 Position            */
#define IEVENT_DRL_Ev_Out1(x)                    (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Ev_Out1_SHIFT))&IEVENT_DRL_Ev_Out1_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_A2_MASK                    (0x10000U)                                          /*!< IEVENT_DRL: IN_A2 Mask                  */
#define IEVENT_DRL_IN_A2_SHIFT                   (16U)                                               /*!< IEVENT_DRL: IN_A2 Position              */
#define IEVENT_DRL_IN_A2(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_A2_SHIFT))&IEVENT_DRL_IN_A2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_B2_MASK                    (0x20000U)                                          /*!< IEVENT_DRL: IN_B2 Mask                  */
#define IEVENT_DRL_IN_B2_SHIFT                   (17U)                                               /*!< IEVENT_DRL: IN_B2 Position              */
#define IEVENT_DRL_IN_B2(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_B2_SHIFT))&IEVENT_DRL_IN_B2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_C2_MASK                    (0x40000U)                                          /*!< IEVENT_DRL: IN_C2 Mask                  */
#define IEVENT_DRL_IN_C2_SHIFT                   (18U)                                               /*!< IEVENT_DRL: IN_C2 Position              */
#define IEVENT_DRL_IN_C2(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_C2_SHIFT))&IEVENT_DRL_IN_C2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_D2_MASK                    (0x80000U)                                          /*!< IEVENT_DRL: IN_D2 Mask                  */
#define IEVENT_DRL_IN_D2_SHIFT                   (19U)                                               /*!< IEVENT_DRL: IN_D2 Position              */
#define IEVENT_DRL_IN_D2(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_D2_SHIFT))&IEVENT_DRL_IN_D2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Output_FSM2_MASK              (0x700000U)                                         /*!< IEVENT_DRL: Output_FSM2 Mask            */
#define IEVENT_DRL_Output_FSM2_SHIFT             (20U)                                               /*!< IEVENT_DRL: Output_FSM2 Position        */
#define IEVENT_DRL_Output_FSM2(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Output_FSM2_SHIFT))&IEVENT_DRL_Output_FSM2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Ev_Out2_MASK                  (0x800000U)                                         /*!< IEVENT_DRL: Ev_Out2 Mask                */
#define IEVENT_DRL_Ev_Out2_SHIFT                 (23U)                                               /*!< IEVENT_DRL: Ev_Out2 Position            */
#define IEVENT_DRL_Ev_Out2(x)                    (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Ev_Out2_SHIFT))&IEVENT_DRL_Ev_Out2_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_A3_MASK                    (0x1000000U)                                        /*!< IEVENT_DRL: IN_A3 Mask                  */
#define IEVENT_DRL_IN_A3_SHIFT                   (24U)                                               /*!< IEVENT_DRL: IN_A3 Position              */
#define IEVENT_DRL_IN_A3(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_A3_SHIFT))&IEVENT_DRL_IN_A3_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_B3_MASK                    (0x2000000U)                                        /*!< IEVENT_DRL: IN_B3 Mask                  */
#define IEVENT_DRL_IN_B3_SHIFT                   (25U)                                               /*!< IEVENT_DRL: IN_B3 Position              */
#define IEVENT_DRL_IN_B3(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_B3_SHIFT))&IEVENT_DRL_IN_B3_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_C3_MASK                    (0x4000000U)                                        /*!< IEVENT_DRL: IN_C3 Mask                  */
#define IEVENT_DRL_IN_C3_SHIFT                   (26U)                                               /*!< IEVENT_DRL: IN_C3 Position              */
#define IEVENT_DRL_IN_C3(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_C3_SHIFT))&IEVENT_DRL_IN_C3_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_IN_D3_MASK                    (0x8000000U)                                        /*!< IEVENT_DRL: IN_D3 Mask                  */
#define IEVENT_DRL_IN_D3_SHIFT                   (27U)                                               /*!< IEVENT_DRL: IN_D3 Position              */
#define IEVENT_DRL_IN_D3(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_IN_D3_SHIFT))&IEVENT_DRL_IN_D3_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Output_FSM3_MASK              (0x70000000U)                                       /*!< IEVENT_DRL: Output_FSM3 Mask            */
#define IEVENT_DRL_Output_FSM3_SHIFT             (28U)                                               /*!< IEVENT_DRL: Output_FSM3 Position        */
#define IEVENT_DRL_Output_FSM3(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Output_FSM3_SHIFT))&IEVENT_DRL_Output_FSM3_MASK) /*!< IEVENT_DRL                              */
#define IEVENT_DRL_Ev_Out3_MASK                  (0x80000000U)                                       /*!< IEVENT_DRL: Ev_Out3 Mask                */
#define IEVENT_DRL_Ev_Out3_SHIFT                 (31U)                                               /*!< IEVENT_DRL: Ev_Out3 Position            */
#define IEVENT_DRL_Ev_Out3(x)                    (((uint32_t)(((uint32_t)(x))<<IEVENT_DRL_Ev_Out3_SHIFT))&IEVENT_DRL_Ev_Out3_MASK) /*!< IEVENT_DRL                              */
/* ------- CRL Bit Fields                           ------ */
#define IEVENT_CRL_Type0_MASK                    (0x3U)                                              /*!< IEVENT_CRL: Type0 Mask                  */
#define IEVENT_CRL_Type0_SHIFT                   (0U)                                                /*!< IEVENT_CRL: Type0 Position              */
#define IEVENT_CRL_Type0(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_Type0_SHIFT))&IEVENT_CRL_Type0_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_OSE0_MASK                     (0x4U)                                              /*!< IEVENT_CRL: OSE0 Mask                   */
#define IEVENT_CRL_OSE0_SHIFT                    (2U)                                                /*!< IEVENT_CRL: OSE0 Position               */
#define IEVENT_CRL_OSE0(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_OSE0_SHIFT))&IEVENT_CRL_OSE0_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_DDB0_MASK                     (0x8U)                                              /*!< IEVENT_CRL: DDB0 Mask                   */
#define IEVENT_CRL_DDB0_SHIFT                    (3U)                                                /*!< IEVENT_CRL: DDB0 Position               */
#define IEVENT_CRL_DDB0(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_DDB0_SHIFT))&IEVENT_CRL_DDB0_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_RO0_MASK                      (0x80U)                                             /*!< IEVENT_CRL: RO0 Mask                    */
#define IEVENT_CRL_RO0_SHIFT                     (7U)                                                /*!< IEVENT_CRL: RO0 Position                */
#define IEVENT_CRL_RO0(x)                        (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_RO0_SHIFT))&IEVENT_CRL_RO0_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_Type1_MASK                    (0x300U)                                            /*!< IEVENT_CRL: Type1 Mask                  */
#define IEVENT_CRL_Type1_SHIFT                   (8U)                                                /*!< IEVENT_CRL: Type1 Position              */
#define IEVENT_CRL_Type1(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_Type1_SHIFT))&IEVENT_CRL_Type1_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_OSE1_MASK                     (0x400U)                                            /*!< IEVENT_CRL: OSE1 Mask                   */
#define IEVENT_CRL_OSE1_SHIFT                    (10U)                                               /*!< IEVENT_CRL: OSE1 Position               */
#define IEVENT_CRL_OSE1(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_OSE1_SHIFT))&IEVENT_CRL_OSE1_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_DDB1_MASK                     (0x800U)                                            /*!< IEVENT_CRL: DDB1 Mask                   */
#define IEVENT_CRL_DDB1_SHIFT                    (11U)                                               /*!< IEVENT_CRL: DDB1 Position               */
#define IEVENT_CRL_DDB1(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_DDB1_SHIFT))&IEVENT_CRL_DDB1_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_RO1_MASK                      (0x8000U)                                           /*!< IEVENT_CRL: RO1 Mask                    */
#define IEVENT_CRL_RO1_SHIFT                     (15U)                                               /*!< IEVENT_CRL: RO1 Position                */
#define IEVENT_CRL_RO1(x)                        (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_RO1_SHIFT))&IEVENT_CRL_RO1_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_Type2_MASK                    (0x30000U)                                          /*!< IEVENT_CRL: Type2 Mask                  */
#define IEVENT_CRL_Type2_SHIFT                   (16U)                                               /*!< IEVENT_CRL: Type2 Position              */
#define IEVENT_CRL_Type2(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_Type2_SHIFT))&IEVENT_CRL_Type2_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_OSE2_MASK                     (0x40000U)                                          /*!< IEVENT_CRL: OSE2 Mask                   */
#define IEVENT_CRL_OSE2_SHIFT                    (18U)                                               /*!< IEVENT_CRL: OSE2 Position               */
#define IEVENT_CRL_OSE2(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_OSE2_SHIFT))&IEVENT_CRL_OSE2_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_DDB2_MASK                     (0x80000U)                                          /*!< IEVENT_CRL: DDB2 Mask                   */
#define IEVENT_CRL_DDB2_SHIFT                    (19U)                                               /*!< IEVENT_CRL: DDB2 Position               */
#define IEVENT_CRL_DDB2(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_DDB2_SHIFT))&IEVENT_CRL_DDB2_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_RO2_MASK                      (0x800000U)                                         /*!< IEVENT_CRL: RO2 Mask                    */
#define IEVENT_CRL_RO2_SHIFT                     (23U)                                               /*!< IEVENT_CRL: RO2 Position                */
#define IEVENT_CRL_RO2(x)                        (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_RO2_SHIFT))&IEVENT_CRL_RO2_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_Type3_MASK                    (0x3000000U)                                        /*!< IEVENT_CRL: Type3 Mask                  */
#define IEVENT_CRL_Type3_SHIFT                   (24U)                                               /*!< IEVENT_CRL: Type3 Position              */
#define IEVENT_CRL_Type3(x)                      (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_Type3_SHIFT))&IEVENT_CRL_Type3_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_OSE3_MASK                     (0x4000000U)                                        /*!< IEVENT_CRL: OSE3 Mask                   */
#define IEVENT_CRL_OSE3_SHIFT                    (26U)                                               /*!< IEVENT_CRL: OSE3 Position               */
#define IEVENT_CRL_OSE3(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_OSE3_SHIFT))&IEVENT_CRL_OSE3_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_DDB3_MASK                     (0x8000000U)                                        /*!< IEVENT_CRL: DDB3 Mask                   */
#define IEVENT_CRL_DDB3_SHIFT                    (27U)                                               /*!< IEVENT_CRL: DDB3 Position               */
#define IEVENT_CRL_DDB3(x)                       (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_DDB3_SHIFT))&IEVENT_CRL_DDB3_MASK) /*!< IEVENT_CRL                              */
#define IEVENT_CRL_RO3_MASK                      (0x80000000U)                                       /*!< IEVENT_CRL: RO3 Mask                    */
#define IEVENT_CRL_RO3_SHIFT                     (31U)                                               /*!< IEVENT_CRL: RO3 Position                */
#define IEVENT_CRL_RO3(x)                        (((uint32_t)(((uint32_t)(x))<<IEVENT_CRL_RO3_SHIFT))&IEVENT_CRL_RO3_MASK) /*!< IEVENT_CRL                              */
/* ------- IMXCR0 Bit Fields                        ------ */
#define IEVENT_IMXCR0_D_Select_MASK              (0xFU)                                              /*!< IEVENT_IMXCR0: D_Select Mask            */
#define IEVENT_IMXCR0_D_Select_SHIFT             (0U)                                                /*!< IEVENT_IMXCR0: D_Select Position        */
#define IEVENT_IMXCR0_D_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR0_D_Select_SHIFT))&IEVENT_IMXCR0_D_Select_MASK) /*!< IEVENT_IMXCR0                           */
#define IEVENT_IMXCR0_C_Select_MASK              (0xF00U)                                            /*!< IEVENT_IMXCR0: C_Select Mask            */
#define IEVENT_IMXCR0_C_Select_SHIFT             (8U)                                                /*!< IEVENT_IMXCR0: C_Select Position        */
#define IEVENT_IMXCR0_C_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR0_C_Select_SHIFT))&IEVENT_IMXCR0_C_Select_MASK) /*!< IEVENT_IMXCR0                           */
#define IEVENT_IMXCR0_B_Select_MASK              (0xF0000U)                                          /*!< IEVENT_IMXCR0: B_Select Mask            */
#define IEVENT_IMXCR0_B_Select_SHIFT             (16U)                                               /*!< IEVENT_IMXCR0: B_Select Position        */
#define IEVENT_IMXCR0_B_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR0_B_Select_SHIFT))&IEVENT_IMXCR0_B_Select_MASK) /*!< IEVENT_IMXCR0                           */
#define IEVENT_IMXCR0_A_Select_MASK              (0xF000000U)                                        /*!< IEVENT_IMXCR0: A_Select Mask            */
#define IEVENT_IMXCR0_A_Select_SHIFT             (24U)                                               /*!< IEVENT_IMXCR0: A_Select Position        */
#define IEVENT_IMXCR0_A_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR0_A_Select_SHIFT))&IEVENT_IMXCR0_A_Select_MASK) /*!< IEVENT_IMXCR0                           */
/* ------- BFECR0 Bit Fields                        ------ */
#define IEVENT_BFECR0_PT3_DC_MASK                (0x3U)                                              /*!< IEVENT_BFECR0: PT3_DC Mask              */
#define IEVENT_BFECR0_PT3_DC_SHIFT               (0U)                                                /*!< IEVENT_BFECR0: PT3_DC Position          */
#define IEVENT_BFECR0_PT3_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT3_DC_SHIFT))&IEVENT_BFECR0_PT3_DC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT3_CC_MASK                (0xCU)                                              /*!< IEVENT_BFECR0: PT3_CC Mask              */
#define IEVENT_BFECR0_PT3_CC_SHIFT               (2U)                                                /*!< IEVENT_BFECR0: PT3_CC Position          */
#define IEVENT_BFECR0_PT3_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT3_CC_SHIFT))&IEVENT_BFECR0_PT3_CC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT3_BC_MASK                (0x30U)                                             /*!< IEVENT_BFECR0: PT3_BC Mask              */
#define IEVENT_BFECR0_PT3_BC_SHIFT               (4U)                                                /*!< IEVENT_BFECR0: PT3_BC Position          */
#define IEVENT_BFECR0_PT3_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT3_BC_SHIFT))&IEVENT_BFECR0_PT3_BC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT3_AC_MASK                (0xC0U)                                             /*!< IEVENT_BFECR0: PT3_AC Mask              */
#define IEVENT_BFECR0_PT3_AC_SHIFT               (6U)                                                /*!< IEVENT_BFECR0: PT3_AC Position          */
#define IEVENT_BFECR0_PT3_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT3_AC_SHIFT))&IEVENT_BFECR0_PT3_AC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT2_DC_MASK                (0x300U)                                            /*!< IEVENT_BFECR0: PT2_DC Mask              */
#define IEVENT_BFECR0_PT2_DC_SHIFT               (8U)                                                /*!< IEVENT_BFECR0: PT2_DC Position          */
#define IEVENT_BFECR0_PT2_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT2_DC_SHIFT))&IEVENT_BFECR0_PT2_DC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT2_CC_MASK                (0xC00U)                                            /*!< IEVENT_BFECR0: PT2_CC Mask              */
#define IEVENT_BFECR0_PT2_CC_SHIFT               (10U)                                               /*!< IEVENT_BFECR0: PT2_CC Position          */
#define IEVENT_BFECR0_PT2_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT2_CC_SHIFT))&IEVENT_BFECR0_PT2_CC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT2_BC_MASK                (0x3000U)                                           /*!< IEVENT_BFECR0: PT2_BC Mask              */
#define IEVENT_BFECR0_PT2_BC_SHIFT               (12U)                                               /*!< IEVENT_BFECR0: PT2_BC Position          */
#define IEVENT_BFECR0_PT2_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT2_BC_SHIFT))&IEVENT_BFECR0_PT2_BC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT2_AC_MASK                (0xC000U)                                           /*!< IEVENT_BFECR0: PT2_AC Mask              */
#define IEVENT_BFECR0_PT2_AC_SHIFT               (14U)                                               /*!< IEVENT_BFECR0: PT2_AC Position          */
#define IEVENT_BFECR0_PT2_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT2_AC_SHIFT))&IEVENT_BFECR0_PT2_AC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT1_DC_MASK                (0x30000U)                                          /*!< IEVENT_BFECR0: PT1_DC Mask              */
#define IEVENT_BFECR0_PT1_DC_SHIFT               (16U)                                               /*!< IEVENT_BFECR0: PT1_DC Position          */
#define IEVENT_BFECR0_PT1_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT1_DC_SHIFT))&IEVENT_BFECR0_PT1_DC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT1_CC_MASK                (0xC0000U)                                          /*!< IEVENT_BFECR0: PT1_CC Mask              */
#define IEVENT_BFECR0_PT1_CC_SHIFT               (18U)                                               /*!< IEVENT_BFECR0: PT1_CC Position          */
#define IEVENT_BFECR0_PT1_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT1_CC_SHIFT))&IEVENT_BFECR0_PT1_CC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT1_BC_MASK                (0x300000U)                                         /*!< IEVENT_BFECR0: PT1_BC Mask              */
#define IEVENT_BFECR0_PT1_BC_SHIFT               (20U)                                               /*!< IEVENT_BFECR0: PT1_BC Position          */
#define IEVENT_BFECR0_PT1_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT1_BC_SHIFT))&IEVENT_BFECR0_PT1_BC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT1_AC_MASK                (0xC00000U)                                         /*!< IEVENT_BFECR0: PT1_AC Mask              */
#define IEVENT_BFECR0_PT1_AC_SHIFT               (22U)                                               /*!< IEVENT_BFECR0: PT1_AC Position          */
#define IEVENT_BFECR0_PT1_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT1_AC_SHIFT))&IEVENT_BFECR0_PT1_AC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT0_DC_MASK                (0x3000000U)                                        /*!< IEVENT_BFECR0: PT0_DC Mask              */
#define IEVENT_BFECR0_PT0_DC_SHIFT               (24U)                                               /*!< IEVENT_BFECR0: PT0_DC Position          */
#define IEVENT_BFECR0_PT0_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT0_DC_SHIFT))&IEVENT_BFECR0_PT0_DC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT0_CC_MASK                (0xC000000U)                                        /*!< IEVENT_BFECR0: PT0_CC Mask              */
#define IEVENT_BFECR0_PT0_CC_SHIFT               (26U)                                               /*!< IEVENT_BFECR0: PT0_CC Position          */
#define IEVENT_BFECR0_PT0_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT0_CC_SHIFT))&IEVENT_BFECR0_PT0_CC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT0_BC_MASK                (0x30000000U)                                       /*!< IEVENT_BFECR0: PT0_BC Mask              */
#define IEVENT_BFECR0_PT0_BC_SHIFT               (28U)                                               /*!< IEVENT_BFECR0: PT0_BC Position          */
#define IEVENT_BFECR0_PT0_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT0_BC_SHIFT))&IEVENT_BFECR0_PT0_BC_MASK) /*!< IEVENT_BFECR0                           */
#define IEVENT_BFECR0_PT0_AC_MASK                (0xC0000000U)                                       /*!< IEVENT_BFECR0: PT0_AC Mask              */
#define IEVENT_BFECR0_PT0_AC_SHIFT               (30U)                                               /*!< IEVENT_BFECR0: PT0_AC Position          */
#define IEVENT_BFECR0_PT0_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR0_PT0_AC_SHIFT))&IEVENT_BFECR0_PT0_AC_MASK) /*!< IEVENT_BFECR0                           */
/* ------- IMXCR1 Bit Fields                        ------ */
#define IEVENT_IMXCR1_D_Select_MASK              (0xFU)                                              /*!< IEVENT_IMXCR1: D_Select Mask            */
#define IEVENT_IMXCR1_D_Select_SHIFT             (0U)                                                /*!< IEVENT_IMXCR1: D_Select Position        */
#define IEVENT_IMXCR1_D_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR1_D_Select_SHIFT))&IEVENT_IMXCR1_D_Select_MASK) /*!< IEVENT_IMXCR1                           */
#define IEVENT_IMXCR1_C_Select_MASK              (0xF00U)                                            /*!< IEVENT_IMXCR1: C_Select Mask            */
#define IEVENT_IMXCR1_C_Select_SHIFT             (8U)                                                /*!< IEVENT_IMXCR1: C_Select Position        */
#define IEVENT_IMXCR1_C_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR1_C_Select_SHIFT))&IEVENT_IMXCR1_C_Select_MASK) /*!< IEVENT_IMXCR1                           */
#define IEVENT_IMXCR1_B_Select_MASK              (0xF0000U)                                          /*!< IEVENT_IMXCR1: B_Select Mask            */
#define IEVENT_IMXCR1_B_Select_SHIFT             (16U)                                               /*!< IEVENT_IMXCR1: B_Select Position        */
#define IEVENT_IMXCR1_B_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR1_B_Select_SHIFT))&IEVENT_IMXCR1_B_Select_MASK) /*!< IEVENT_IMXCR1                           */
#define IEVENT_IMXCR1_A_Select_MASK              (0xF000000U)                                        /*!< IEVENT_IMXCR1: A_Select Mask            */
#define IEVENT_IMXCR1_A_Select_SHIFT             (24U)                                               /*!< IEVENT_IMXCR1: A_Select Position        */
#define IEVENT_IMXCR1_A_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR1_A_Select_SHIFT))&IEVENT_IMXCR1_A_Select_MASK) /*!< IEVENT_IMXCR1                           */
/* ------- BFECR1 Bit Fields                        ------ */
#define IEVENT_BFECR1_PT3_DC_MASK                (0x3U)                                              /*!< IEVENT_BFECR1: PT3_DC Mask              */
#define IEVENT_BFECR1_PT3_DC_SHIFT               (0U)                                                /*!< IEVENT_BFECR1: PT3_DC Position          */
#define IEVENT_BFECR1_PT3_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT3_DC_SHIFT))&IEVENT_BFECR1_PT3_DC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT3_CC_MASK                (0xCU)                                              /*!< IEVENT_BFECR1: PT3_CC Mask              */
#define IEVENT_BFECR1_PT3_CC_SHIFT               (2U)                                                /*!< IEVENT_BFECR1: PT3_CC Position          */
#define IEVENT_BFECR1_PT3_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT3_CC_SHIFT))&IEVENT_BFECR1_PT3_CC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT3_BC_MASK                (0x30U)                                             /*!< IEVENT_BFECR1: PT3_BC Mask              */
#define IEVENT_BFECR1_PT3_BC_SHIFT               (4U)                                                /*!< IEVENT_BFECR1: PT3_BC Position          */
#define IEVENT_BFECR1_PT3_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT3_BC_SHIFT))&IEVENT_BFECR1_PT3_BC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT3_AC_MASK                (0xC0U)                                             /*!< IEVENT_BFECR1: PT3_AC Mask              */
#define IEVENT_BFECR1_PT3_AC_SHIFT               (6U)                                                /*!< IEVENT_BFECR1: PT3_AC Position          */
#define IEVENT_BFECR1_PT3_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT3_AC_SHIFT))&IEVENT_BFECR1_PT3_AC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT2_DC_MASK                (0x300U)                                            /*!< IEVENT_BFECR1: PT2_DC Mask              */
#define IEVENT_BFECR1_PT2_DC_SHIFT               (8U)                                                /*!< IEVENT_BFECR1: PT2_DC Position          */
#define IEVENT_BFECR1_PT2_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT2_DC_SHIFT))&IEVENT_BFECR1_PT2_DC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT2_CC_MASK                (0xC00U)                                            /*!< IEVENT_BFECR1: PT2_CC Mask              */
#define IEVENT_BFECR1_PT2_CC_SHIFT               (10U)                                               /*!< IEVENT_BFECR1: PT2_CC Position          */
#define IEVENT_BFECR1_PT2_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT2_CC_SHIFT))&IEVENT_BFECR1_PT2_CC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT2_BC_MASK                (0x3000U)                                           /*!< IEVENT_BFECR1: PT2_BC Mask              */
#define IEVENT_BFECR1_PT2_BC_SHIFT               (12U)                                               /*!< IEVENT_BFECR1: PT2_BC Position          */
#define IEVENT_BFECR1_PT2_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT2_BC_SHIFT))&IEVENT_BFECR1_PT2_BC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT2_AC_MASK                (0xC000U)                                           /*!< IEVENT_BFECR1: PT2_AC Mask              */
#define IEVENT_BFECR1_PT2_AC_SHIFT               (14U)                                               /*!< IEVENT_BFECR1: PT2_AC Position          */
#define IEVENT_BFECR1_PT2_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT2_AC_SHIFT))&IEVENT_BFECR1_PT2_AC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT1_DC_MASK                (0x30000U)                                          /*!< IEVENT_BFECR1: PT1_DC Mask              */
#define IEVENT_BFECR1_PT1_DC_SHIFT               (16U)                                               /*!< IEVENT_BFECR1: PT1_DC Position          */
#define IEVENT_BFECR1_PT1_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT1_DC_SHIFT))&IEVENT_BFECR1_PT1_DC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT1_CC_MASK                (0xC0000U)                                          /*!< IEVENT_BFECR1: PT1_CC Mask              */
#define IEVENT_BFECR1_PT1_CC_SHIFT               (18U)                                               /*!< IEVENT_BFECR1: PT1_CC Position          */
#define IEVENT_BFECR1_PT1_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT1_CC_SHIFT))&IEVENT_BFECR1_PT1_CC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT1_BC_MASK                (0x300000U)                                         /*!< IEVENT_BFECR1: PT1_BC Mask              */
#define IEVENT_BFECR1_PT1_BC_SHIFT               (20U)                                               /*!< IEVENT_BFECR1: PT1_BC Position          */
#define IEVENT_BFECR1_PT1_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT1_BC_SHIFT))&IEVENT_BFECR1_PT1_BC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT1_AC_MASK                (0xC00000U)                                         /*!< IEVENT_BFECR1: PT1_AC Mask              */
#define IEVENT_BFECR1_PT1_AC_SHIFT               (22U)                                               /*!< IEVENT_BFECR1: PT1_AC Position          */
#define IEVENT_BFECR1_PT1_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT1_AC_SHIFT))&IEVENT_BFECR1_PT1_AC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT0_DC_MASK                (0x3000000U)                                        /*!< IEVENT_BFECR1: PT0_DC Mask              */
#define IEVENT_BFECR1_PT0_DC_SHIFT               (24U)                                               /*!< IEVENT_BFECR1: PT0_DC Position          */
#define IEVENT_BFECR1_PT0_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT0_DC_SHIFT))&IEVENT_BFECR1_PT0_DC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT0_CC_MASK                (0xC000000U)                                        /*!< IEVENT_BFECR1: PT0_CC Mask              */
#define IEVENT_BFECR1_PT0_CC_SHIFT               (26U)                                               /*!< IEVENT_BFECR1: PT0_CC Position          */
#define IEVENT_BFECR1_PT0_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT0_CC_SHIFT))&IEVENT_BFECR1_PT0_CC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT0_BC_MASK                (0x30000000U)                                       /*!< IEVENT_BFECR1: PT0_BC Mask              */
#define IEVENT_BFECR1_PT0_BC_SHIFT               (28U)                                               /*!< IEVENT_BFECR1: PT0_BC Position          */
#define IEVENT_BFECR1_PT0_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT0_BC_SHIFT))&IEVENT_BFECR1_PT0_BC_MASK) /*!< IEVENT_BFECR1                           */
#define IEVENT_BFECR1_PT0_AC_MASK                (0xC0000000U)                                       /*!< IEVENT_BFECR1: PT0_AC Mask              */
#define IEVENT_BFECR1_PT0_AC_SHIFT               (30U)                                               /*!< IEVENT_BFECR1: PT0_AC Position          */
#define IEVENT_BFECR1_PT0_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR1_PT0_AC_SHIFT))&IEVENT_BFECR1_PT0_AC_MASK) /*!< IEVENT_BFECR1                           */
/* ------- IMXCR2 Bit Fields                        ------ */
#define IEVENT_IMXCR2_D_Select_MASK              (0xFU)                                              /*!< IEVENT_IMXCR2: D_Select Mask            */
#define IEVENT_IMXCR2_D_Select_SHIFT             (0U)                                                /*!< IEVENT_IMXCR2: D_Select Position        */
#define IEVENT_IMXCR2_D_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR2_D_Select_SHIFT))&IEVENT_IMXCR2_D_Select_MASK) /*!< IEVENT_IMXCR2                           */
#define IEVENT_IMXCR2_C_Select_MASK              (0xF00U)                                            /*!< IEVENT_IMXCR2: C_Select Mask            */
#define IEVENT_IMXCR2_C_Select_SHIFT             (8U)                                                /*!< IEVENT_IMXCR2: C_Select Position        */
#define IEVENT_IMXCR2_C_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR2_C_Select_SHIFT))&IEVENT_IMXCR2_C_Select_MASK) /*!< IEVENT_IMXCR2                           */
#define IEVENT_IMXCR2_B_Select_MASK              (0xF0000U)                                          /*!< IEVENT_IMXCR2: B_Select Mask            */
#define IEVENT_IMXCR2_B_Select_SHIFT             (16U)                                               /*!< IEVENT_IMXCR2: B_Select Position        */
#define IEVENT_IMXCR2_B_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR2_B_Select_SHIFT))&IEVENT_IMXCR2_B_Select_MASK) /*!< IEVENT_IMXCR2                           */
#define IEVENT_IMXCR2_A_Select_MASK              (0xF000000U)                                        /*!< IEVENT_IMXCR2: A_Select Mask            */
#define IEVENT_IMXCR2_A_Select_SHIFT             (24U)                                               /*!< IEVENT_IMXCR2: A_Select Position        */
#define IEVENT_IMXCR2_A_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR2_A_Select_SHIFT))&IEVENT_IMXCR2_A_Select_MASK) /*!< IEVENT_IMXCR2                           */
/* ------- BFECR2 Bit Fields                        ------ */
#define IEVENT_BFECR2_PT3_DC_MASK                (0x3U)                                              /*!< IEVENT_BFECR2: PT3_DC Mask              */
#define IEVENT_BFECR2_PT3_DC_SHIFT               (0U)                                                /*!< IEVENT_BFECR2: PT3_DC Position          */
#define IEVENT_BFECR2_PT3_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT3_DC_SHIFT))&IEVENT_BFECR2_PT3_DC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT3_CC_MASK                (0xCU)                                              /*!< IEVENT_BFECR2: PT3_CC Mask              */
#define IEVENT_BFECR2_PT3_CC_SHIFT               (2U)                                                /*!< IEVENT_BFECR2: PT3_CC Position          */
#define IEVENT_BFECR2_PT3_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT3_CC_SHIFT))&IEVENT_BFECR2_PT3_CC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT3_BC_MASK                (0x30U)                                             /*!< IEVENT_BFECR2: PT3_BC Mask              */
#define IEVENT_BFECR2_PT3_BC_SHIFT               (4U)                                                /*!< IEVENT_BFECR2: PT3_BC Position          */
#define IEVENT_BFECR2_PT3_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT3_BC_SHIFT))&IEVENT_BFECR2_PT3_BC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT3_AC_MASK                (0xC0U)                                             /*!< IEVENT_BFECR2: PT3_AC Mask              */
#define IEVENT_BFECR2_PT3_AC_SHIFT               (6U)                                                /*!< IEVENT_BFECR2: PT3_AC Position          */
#define IEVENT_BFECR2_PT3_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT3_AC_SHIFT))&IEVENT_BFECR2_PT3_AC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT2_DC_MASK                (0x300U)                                            /*!< IEVENT_BFECR2: PT2_DC Mask              */
#define IEVENT_BFECR2_PT2_DC_SHIFT               (8U)                                                /*!< IEVENT_BFECR2: PT2_DC Position          */
#define IEVENT_BFECR2_PT2_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT2_DC_SHIFT))&IEVENT_BFECR2_PT2_DC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT2_CC_MASK                (0xC00U)                                            /*!< IEVENT_BFECR2: PT2_CC Mask              */
#define IEVENT_BFECR2_PT2_CC_SHIFT               (10U)                                               /*!< IEVENT_BFECR2: PT2_CC Position          */
#define IEVENT_BFECR2_PT2_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT2_CC_SHIFT))&IEVENT_BFECR2_PT2_CC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT2_BC_MASK                (0x3000U)                                           /*!< IEVENT_BFECR2: PT2_BC Mask              */
#define IEVENT_BFECR2_PT2_BC_SHIFT               (12U)                                               /*!< IEVENT_BFECR2: PT2_BC Position          */
#define IEVENT_BFECR2_PT2_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT2_BC_SHIFT))&IEVENT_BFECR2_PT2_BC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT2_AC_MASK                (0xC000U)                                           /*!< IEVENT_BFECR2: PT2_AC Mask              */
#define IEVENT_BFECR2_PT2_AC_SHIFT               (14U)                                               /*!< IEVENT_BFECR2: PT2_AC Position          */
#define IEVENT_BFECR2_PT2_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT2_AC_SHIFT))&IEVENT_BFECR2_PT2_AC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT1_DC_MASK                (0x30000U)                                          /*!< IEVENT_BFECR2: PT1_DC Mask              */
#define IEVENT_BFECR2_PT1_DC_SHIFT               (16U)                                               /*!< IEVENT_BFECR2: PT1_DC Position          */
#define IEVENT_BFECR2_PT1_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT1_DC_SHIFT))&IEVENT_BFECR2_PT1_DC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT1_CC_MASK                (0xC0000U)                                          /*!< IEVENT_BFECR2: PT1_CC Mask              */
#define IEVENT_BFECR2_PT1_CC_SHIFT               (18U)                                               /*!< IEVENT_BFECR2: PT1_CC Position          */
#define IEVENT_BFECR2_PT1_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT1_CC_SHIFT))&IEVENT_BFECR2_PT1_CC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT1_BC_MASK                (0x300000U)                                         /*!< IEVENT_BFECR2: PT1_BC Mask              */
#define IEVENT_BFECR2_PT1_BC_SHIFT               (20U)                                               /*!< IEVENT_BFECR2: PT1_BC Position          */
#define IEVENT_BFECR2_PT1_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT1_BC_SHIFT))&IEVENT_BFECR2_PT1_BC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT1_AC_MASK                (0xC00000U)                                         /*!< IEVENT_BFECR2: PT1_AC Mask              */
#define IEVENT_BFECR2_PT1_AC_SHIFT               (22U)                                               /*!< IEVENT_BFECR2: PT1_AC Position          */
#define IEVENT_BFECR2_PT1_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT1_AC_SHIFT))&IEVENT_BFECR2_PT1_AC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT0_DC_MASK                (0x3000000U)                                        /*!< IEVENT_BFECR2: PT0_DC Mask              */
#define IEVENT_BFECR2_PT0_DC_SHIFT               (24U)                                               /*!< IEVENT_BFECR2: PT0_DC Position          */
#define IEVENT_BFECR2_PT0_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT0_DC_SHIFT))&IEVENT_BFECR2_PT0_DC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT0_CC_MASK                (0xC000000U)                                        /*!< IEVENT_BFECR2: PT0_CC Mask              */
#define IEVENT_BFECR2_PT0_CC_SHIFT               (26U)                                               /*!< IEVENT_BFECR2: PT0_CC Position          */
#define IEVENT_BFECR2_PT0_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT0_CC_SHIFT))&IEVENT_BFECR2_PT0_CC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT0_BC_MASK                (0x30000000U)                                       /*!< IEVENT_BFECR2: PT0_BC Mask              */
#define IEVENT_BFECR2_PT0_BC_SHIFT               (28U)                                               /*!< IEVENT_BFECR2: PT0_BC Position          */
#define IEVENT_BFECR2_PT0_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT0_BC_SHIFT))&IEVENT_BFECR2_PT0_BC_MASK) /*!< IEVENT_BFECR2                           */
#define IEVENT_BFECR2_PT0_AC_MASK                (0xC0000000U)                                       /*!< IEVENT_BFECR2: PT0_AC Mask              */
#define IEVENT_BFECR2_PT0_AC_SHIFT               (30U)                                               /*!< IEVENT_BFECR2: PT0_AC Position          */
#define IEVENT_BFECR2_PT0_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR2_PT0_AC_SHIFT))&IEVENT_BFECR2_PT0_AC_MASK) /*!< IEVENT_BFECR2                           */
/* ------- IMXCR3 Bit Fields                        ------ */
#define IEVENT_IMXCR3_D_Select_MASK              (0xFU)                                              /*!< IEVENT_IMXCR3: D_Select Mask            */
#define IEVENT_IMXCR3_D_Select_SHIFT             (0U)                                                /*!< IEVENT_IMXCR3: D_Select Position        */
#define IEVENT_IMXCR3_D_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR3_D_Select_SHIFT))&IEVENT_IMXCR3_D_Select_MASK) /*!< IEVENT_IMXCR3                           */
#define IEVENT_IMXCR3_C_Select_MASK              (0xF00U)                                            /*!< IEVENT_IMXCR3: C_Select Mask            */
#define IEVENT_IMXCR3_C_Select_SHIFT             (8U)                                                /*!< IEVENT_IMXCR3: C_Select Position        */
#define IEVENT_IMXCR3_C_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR3_C_Select_SHIFT))&IEVENT_IMXCR3_C_Select_MASK) /*!< IEVENT_IMXCR3                           */
#define IEVENT_IMXCR3_B_Select_MASK              (0xF0000U)                                          /*!< IEVENT_IMXCR3: B_Select Mask            */
#define IEVENT_IMXCR3_B_Select_SHIFT             (16U)                                               /*!< IEVENT_IMXCR3: B_Select Position        */
#define IEVENT_IMXCR3_B_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR3_B_Select_SHIFT))&IEVENT_IMXCR3_B_Select_MASK) /*!< IEVENT_IMXCR3                           */
#define IEVENT_IMXCR3_A_Select_MASK              (0xF000000U)                                        /*!< IEVENT_IMXCR3: A_Select Mask            */
#define IEVENT_IMXCR3_A_Select_SHIFT             (24U)                                               /*!< IEVENT_IMXCR3: A_Select Position        */
#define IEVENT_IMXCR3_A_Select(x)                (((uint32_t)(((uint32_t)(x))<<IEVENT_IMXCR3_A_Select_SHIFT))&IEVENT_IMXCR3_A_Select_MASK) /*!< IEVENT_IMXCR3                           */
/* ------- BFECR3 Bit Fields                        ------ */
#define IEVENT_BFECR3_PT3_DC_MASK                (0x3U)                                              /*!< IEVENT_BFECR3: PT3_DC Mask              */
#define IEVENT_BFECR3_PT3_DC_SHIFT               (0U)                                                /*!< IEVENT_BFECR3: PT3_DC Position          */
#define IEVENT_BFECR3_PT3_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT3_DC_SHIFT))&IEVENT_BFECR3_PT3_DC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT3_CC_MASK                (0xCU)                                              /*!< IEVENT_BFECR3: PT3_CC Mask              */
#define IEVENT_BFECR3_PT3_CC_SHIFT               (2U)                                                /*!< IEVENT_BFECR3: PT3_CC Position          */
#define IEVENT_BFECR3_PT3_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT3_CC_SHIFT))&IEVENT_BFECR3_PT3_CC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT3_BC_MASK                (0x30U)                                             /*!< IEVENT_BFECR3: PT3_BC Mask              */
#define IEVENT_BFECR3_PT3_BC_SHIFT               (4U)                                                /*!< IEVENT_BFECR3: PT3_BC Position          */
#define IEVENT_BFECR3_PT3_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT3_BC_SHIFT))&IEVENT_BFECR3_PT3_BC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT3_AC_MASK                (0xC0U)                                             /*!< IEVENT_BFECR3: PT3_AC Mask              */
#define IEVENT_BFECR3_PT3_AC_SHIFT               (6U)                                                /*!< IEVENT_BFECR3: PT3_AC Position          */
#define IEVENT_BFECR3_PT3_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT3_AC_SHIFT))&IEVENT_BFECR3_PT3_AC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT2_DC_MASK                (0x300U)                                            /*!< IEVENT_BFECR3: PT2_DC Mask              */
#define IEVENT_BFECR3_PT2_DC_SHIFT               (8U)                                                /*!< IEVENT_BFECR3: PT2_DC Position          */
#define IEVENT_BFECR3_PT2_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT2_DC_SHIFT))&IEVENT_BFECR3_PT2_DC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT2_CC_MASK                (0xC00U)                                            /*!< IEVENT_BFECR3: PT2_CC Mask              */
#define IEVENT_BFECR3_PT2_CC_SHIFT               (10U)                                               /*!< IEVENT_BFECR3: PT2_CC Position          */
#define IEVENT_BFECR3_PT2_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT2_CC_SHIFT))&IEVENT_BFECR3_PT2_CC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT2_BC_MASK                (0x3000U)                                           /*!< IEVENT_BFECR3: PT2_BC Mask              */
#define IEVENT_BFECR3_PT2_BC_SHIFT               (12U)                                               /*!< IEVENT_BFECR3: PT2_BC Position          */
#define IEVENT_BFECR3_PT2_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT2_BC_SHIFT))&IEVENT_BFECR3_PT2_BC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT2_AC_MASK                (0xC000U)                                           /*!< IEVENT_BFECR3: PT2_AC Mask              */
#define IEVENT_BFECR3_PT2_AC_SHIFT               (14U)                                               /*!< IEVENT_BFECR3: PT2_AC Position          */
#define IEVENT_BFECR3_PT2_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT2_AC_SHIFT))&IEVENT_BFECR3_PT2_AC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT1_DC_MASK                (0x30000U)                                          /*!< IEVENT_BFECR3: PT1_DC Mask              */
#define IEVENT_BFECR3_PT1_DC_SHIFT               (16U)                                               /*!< IEVENT_BFECR3: PT1_DC Position          */
#define IEVENT_BFECR3_PT1_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT1_DC_SHIFT))&IEVENT_BFECR3_PT1_DC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT1_CC_MASK                (0xC0000U)                                          /*!< IEVENT_BFECR3: PT1_CC Mask              */
#define IEVENT_BFECR3_PT1_CC_SHIFT               (18U)                                               /*!< IEVENT_BFECR3: PT1_CC Position          */
#define IEVENT_BFECR3_PT1_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT1_CC_SHIFT))&IEVENT_BFECR3_PT1_CC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT1_BC_MASK                (0x300000U)                                         /*!< IEVENT_BFECR3: PT1_BC Mask              */
#define IEVENT_BFECR3_PT1_BC_SHIFT               (20U)                                               /*!< IEVENT_BFECR3: PT1_BC Position          */
#define IEVENT_BFECR3_PT1_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT1_BC_SHIFT))&IEVENT_BFECR3_PT1_BC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT1_AC_MASK                (0xC00000U)                                         /*!< IEVENT_BFECR3: PT1_AC Mask              */
#define IEVENT_BFECR3_PT1_AC_SHIFT               (22U)                                               /*!< IEVENT_BFECR3: PT1_AC Position          */
#define IEVENT_BFECR3_PT1_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT1_AC_SHIFT))&IEVENT_BFECR3_PT1_AC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT0_DC_MASK                (0x3000000U)                                        /*!< IEVENT_BFECR3: PT0_DC Mask              */
#define IEVENT_BFECR3_PT0_DC_SHIFT               (24U)                                               /*!< IEVENT_BFECR3: PT0_DC Position          */
#define IEVENT_BFECR3_PT0_DC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT0_DC_SHIFT))&IEVENT_BFECR3_PT0_DC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT0_CC_MASK                (0xC000000U)                                        /*!< IEVENT_BFECR3: PT0_CC Mask              */
#define IEVENT_BFECR3_PT0_CC_SHIFT               (26U)                                               /*!< IEVENT_BFECR3: PT0_CC Position          */
#define IEVENT_BFECR3_PT0_CC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT0_CC_SHIFT))&IEVENT_BFECR3_PT0_CC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT0_BC_MASK                (0x30000000U)                                       /*!< IEVENT_BFECR3: PT0_BC Mask              */
#define IEVENT_BFECR3_PT0_BC_SHIFT               (28U)                                               /*!< IEVENT_BFECR3: PT0_BC Position          */
#define IEVENT_BFECR3_PT0_BC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT0_BC_SHIFT))&IEVENT_BFECR3_PT0_BC_MASK) /*!< IEVENT_BFECR3                           */
#define IEVENT_BFECR3_PT0_AC_MASK                (0xC0000000U)                                       /*!< IEVENT_BFECR3: PT0_AC Mask              */
#define IEVENT_BFECR3_PT0_AC_SHIFT               (30U)                                               /*!< IEVENT_BFECR3: PT0_AC Position          */
#define IEVENT_BFECR3_PT0_AC(x)                  (((uint32_t)(((uint32_t)(x))<<IEVENT_BFECR3_PT0_AC_SHIFT))&IEVENT_BFECR3_PT0_AC_MASK) /*!< IEVENT_BFECR3                           */
/**
 * @} */ /* End group IEVENT_Register_Masks_GROUP 
 */

/* IEVENT - Peripheral instance base addresses */
#define IEVENT_BasePtr                 0x40019000UL //!< Peripheral base address
#define IEVENT                         ((IEVENT_Type *) IEVENT_BasePtr) //!< Freescale base pointer
#define IEVENT_BASE_PTR                (IEVENT) //!< Freescale style base pointer
/**
 * @} */ /* End group IEVENT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MKE14D7)               ================ */
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
        uint8_t   RESERVED_0[8];               
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  CR;                           /**< 000C: Control Register                                             */
        uint8_t   RESERVED_1[32];              
   __IO uint32_t  PID;                          /**< 0030: Process ID register                                          */
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
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /*!< MCM_PLASC                               */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /*!< MCM_PLAMC                               */
/* ------- CR Bit Fields                            ------ */
#define MCM_CR_CBRR_MASK                         (0x200U)                                            /*!< MCM_CR: CBRR Mask                       */
#define MCM_CR_CBRR_SHIFT                        (9U)                                                /*!< MCM_CR: CBRR Position                   */
#define MCM_CR_CBRR(x)                           (((uint32_t)(((uint32_t)(x))<<MCM_CR_CBRR_SHIFT))&MCM_CR_CBRR_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMUAP_MASK                      (0x3000000U)                                        /*!< MCM_CR: SRAMUAP Mask                    */
#define MCM_CR_SRAMUAP_SHIFT                     (24U)                                               /*!< MCM_CR: SRAMUAP Position                */
#define MCM_CR_SRAMUAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUAP_SHIFT))&MCM_CR_SRAMUAP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMUWP_MASK                      (0x4000000U)                                        /*!< MCM_CR: SRAMUWP Mask                    */
#define MCM_CR_SRAMUWP_SHIFT                     (26U)                                               /*!< MCM_CR: SRAMUWP Position                */
#define MCM_CR_SRAMUWP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUWP_SHIFT))&MCM_CR_SRAMUWP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMLAP_MASK                      (0x30000000U)                                       /*!< MCM_CR: SRAMLAP Mask                    */
#define MCM_CR_SRAMLAP_SHIFT                     (28U)                                               /*!< MCM_CR: SRAMLAP Position                */
#define MCM_CR_SRAMLAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLAP_SHIFT))&MCM_CR_SRAMLAP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMLWP_MASK                      (0x40000000U)                                       /*!< MCM_CR: SRAMLWP Mask                    */
#define MCM_CR_SRAMLWP_SHIFT                     (30U)                                               /*!< MCM_CR: SRAMLWP Position                */
#define MCM_CR_SRAMLWP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLWP_SHIFT))&MCM_CR_SRAMLWP_MASK) /*!< MCM_CR                                  */
/* ------- PID Bit Fields                           ------ */
#define MCM_PID_PID_MASK                         (0xFFU)                                             /*!< MCM_PID: PID Mask                       */
#define MCM_PID_PID_SHIFT                        (0U)                                                /*!< MCM_PID: PID Position                   */
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x))<<MCM_PID_PID_SHIFT))&MCM_PID_PID_MASK) /*!< MCM_PID                                 */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xE0080000UL //!< Peripheral base address
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
/* ================           MPU (file:MPU_MKE14D7_R8)            ================ */
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
        uint8_t   RESERVED_0[12];              
   struct {
      __I  uint32_t  EAR;                       /**< 0010: Error Address Register, Slave Port n                         */
      __I  uint32_t  EDR;                       /**< 0014: Error Detail Register, Slave Port n                          */
   } SP[5];                                     /**< 0010: (cluster: size=0x0028, 40)                                   */
        uint8_t   RESERVED_2[968];             
   struct {
      __IO uint32_t  WORD0;                     /**< 0400: Region Descriptor n, Word 0                                  */
      __IO uint32_t  WORD1;                     /**< 0404: Region Descriptor n, Word 1                                  */
      __IO uint32_t  WORD2;                     /**< 0408: Region Descriptor n, Word 2                                  */
      __IO uint32_t  WORD3;                     /**< 040C: Region Descriptor n, Word 3                                  */
   } RGD[8];                                    /**< 0400: (cluster: size=0x0080, 128)                                  */
        uint8_t   RESERVED_4[896];             
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
#define MPU_CESR_VLD_MASK                        (0x1U)                                              /*!< MPU_CESR: VLD Mask                      */
#define MPU_CESR_VLD_SHIFT                       (0U)                                                /*!< MPU_CESR: VLD Position                  */
#define MPU_CESR_VLD(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_VLD_SHIFT))&MPU_CESR_VLD_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_NRGD_MASK                       (0xF00U)                                            /*!< MPU_CESR: NRGD Mask                     */
#define MPU_CESR_NRGD_SHIFT                      (8U)                                                /*!< MPU_CESR: NRGD Position                 */
#define MPU_CESR_NRGD(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NRGD_SHIFT))&MPU_CESR_NRGD_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_NSP_MASK                        (0xF000U)                                           /*!< MPU_CESR: NSP Mask                      */
#define MPU_CESR_NSP_SHIFT                       (12U)                                               /*!< MPU_CESR: NSP Position                  */
#define MPU_CESR_NSP(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_HRL_MASK                        (0xF0000U)                                          /*!< MPU_CESR: HRL Mask                      */
#define MPU_CESR_HRL_SHIFT                       (16U)                                               /*!< MPU_CESR: HRL Position                  */
#define MPU_CESR_HRL(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_HRL_SHIFT))&MPU_CESR_HRL_MASK) /*!< MPU_CESR                                */
#define MPU_CESR_SPERR_MASK                      (0xF8000000U)                                       /*!< MPU_CESR: SPERR Mask                    */
#define MPU_CESR_SPERR_SHIFT                     (27U)                                               /*!< MPU_CESR: SPERR Position                */
#define MPU_CESR_SPERR(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_CESR_SPERR_SHIFT))&MPU_CESR_SPERR_MASK) /*!< MPU_CESR                                */
/* ------- EAR Bit Fields                           ------ */
#define MPU_EAR_EADDR_MASK                       (0xFFFFFFFFU)                                       /*!< MPU_EAR: EADDR Mask                     */
#define MPU_EAR_EADDR_SHIFT                      (0U)                                                /*!< MPU_EAR: EADDR Position                 */
#define MPU_EAR_EADDR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EAR_EADDR_SHIFT))&MPU_EAR_EADDR_MASK) /*!< MPU_EAR                                 */
/* ------- EDR Bit Fields                           ------ */
#define MPU_EDR_ERW_MASK                         (0x1U)                                              /*!< MPU_EDR: ERW Mask                       */
#define MPU_EDR_ERW_SHIFT                        (0U)                                                /*!< MPU_EDR: ERW Position                   */
#define MPU_EDR_ERW(x)                           (((uint32_t)(((uint32_t)(x))<<MPU_EDR_ERW_SHIFT))&MPU_EDR_ERW_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EATTR_MASK                       (0xEU)                                              /*!< MPU_EDR: EATTR Mask                     */
#define MPU_EDR_EATTR_SHIFT                      (1U)                                                /*!< MPU_EDR: EATTR Position                 */
#define MPU_EDR_EATTR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EATTR_SHIFT))&MPU_EDR_EATTR_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EMN_MASK                         (0xF0U)                                             /*!< MPU_EDR: EMN Mask                       */
#define MPU_EDR_EMN_SHIFT                        (4U)                                                /*!< MPU_EDR: EMN Position                   */
#define MPU_EDR_EMN(x)                           (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EMN_SHIFT))&MPU_EDR_EMN_MASK) /*!< MPU_EDR                                 */
#define MPU_EDR_EACD_MASK                        (0xFFFF0000U)                                       /*!< MPU_EDR: EACD Mask                      */
#define MPU_EDR_EACD_SHIFT                       (16U)                                               /*!< MPU_EDR: EACD Position                  */
#define MPU_EDR_EACD(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EACD_SHIFT))&MPU_EDR_EACD_MASK) /*!< MPU_EDR                                 */
/* ------- WORD0 Bit Fields                         ------ */
#define MPU_WORD0_SRTADDR_MASK                   (0xFFFFFFE0U)                                       /*!< MPU_WORD0: SRTADDR Mask                 */
#define MPU_WORD0_SRTADDR_SHIFT                  (5U)                                                /*!< MPU_WORD0: SRTADDR Position             */
#define MPU_WORD0_SRTADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MPU_WORD0_SRTADDR_SHIFT))&MPU_WORD0_SRTADDR_MASK) /*!< MPU_WORD0                               */
/* ------- WORD1 Bit Fields                         ------ */
#define MPU_WORD1_ENDADDR_MASK                   (0xFFFFFFE0U)                                       /*!< MPU_WORD1: ENDADDR Mask                 */
#define MPU_WORD1_ENDADDR_SHIFT                  (5U)                                                /*!< MPU_WORD1: ENDADDR Position             */
#define MPU_WORD1_ENDADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MPU_WORD1_ENDADDR_SHIFT))&MPU_WORD1_ENDADDR_MASK) /*!< MPU_WORD1                               */
/* ------- WORD2 Bit Fields                         ------ */
#define MPU_WORD2_M0UM_MASK                      (0x7U)                                              /*!< MPU_WORD2: M0UM Mask                    */
#define MPU_WORD2_M0UM_SHIFT                     (0U)                                                /*!< MPU_WORD2: M0UM Position                */
#define MPU_WORD2_M0UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M0UM_SHIFT))&MPU_WORD2_M0UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M0SM_MASK                      (0x18U)                                             /*!< MPU_WORD2: M0SM Mask                    */
#define MPU_WORD2_M0SM_SHIFT                     (3U)                                                /*!< MPU_WORD2: M0SM Position                */
#define MPU_WORD2_M0SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M0SM_SHIFT))&MPU_WORD2_M0SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M1UM_MASK                      (0x1C0U)                                            /*!< MPU_WORD2: M1UM Mask                    */
#define MPU_WORD2_M1UM_SHIFT                     (6U)                                                /*!< MPU_WORD2: M1UM Position                */
#define MPU_WORD2_M1UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M1UM_SHIFT))&MPU_WORD2_M1UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M1SM_MASK                      (0x600U)                                            /*!< MPU_WORD2: M1SM Mask                    */
#define MPU_WORD2_M1SM_SHIFT                     (9U)                                                /*!< MPU_WORD2: M1SM Position                */
#define MPU_WORD2_M1SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M1SM_SHIFT))&MPU_WORD2_M1SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M2UM_MASK                      (0x7000U)                                           /*!< MPU_WORD2: M2UM Mask                    */
#define MPU_WORD2_M2UM_SHIFT                     (12U)                                               /*!< MPU_WORD2: M2UM Position                */
#define MPU_WORD2_M2UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M2UM_SHIFT))&MPU_WORD2_M2UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M2SM_MASK                      (0x18000U)                                          /*!< MPU_WORD2: M2SM Mask                    */
#define MPU_WORD2_M2SM_SHIFT                     (15U)                                               /*!< MPU_WORD2: M2SM Position                */
#define MPU_WORD2_M2SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M2SM_SHIFT))&MPU_WORD2_M2SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M3UM_MASK                      (0x1C0000U)                                         /*!< MPU_WORD2: M3UM Mask                    */
#define MPU_WORD2_M3UM_SHIFT                     (18U)                                               /*!< MPU_WORD2: M3UM Position                */
#define MPU_WORD2_M3UM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M3UM_SHIFT))&MPU_WORD2_M3UM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M3SM_MASK                      (0x600000U)                                         /*!< MPU_WORD2: M3SM Mask                    */
#define MPU_WORD2_M3SM_SHIFT                     (21U)                                               /*!< MPU_WORD2: M3SM Position                */
#define MPU_WORD2_M3SM(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M3SM_SHIFT))&MPU_WORD2_M3SM_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M4WE_MASK                      (0x1000000U)                                        /*!< MPU_WORD2: M4WE Mask                    */
#define MPU_WORD2_M4WE_SHIFT                     (24U)                                               /*!< MPU_WORD2: M4WE Position                */
#define MPU_WORD2_M4WE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M4WE_SHIFT))&MPU_WORD2_M4WE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M4RE_MASK                      (0x2000000U)                                        /*!< MPU_WORD2: M4RE Mask                    */
#define MPU_WORD2_M4RE_SHIFT                     (25U)                                               /*!< MPU_WORD2: M4RE Position                */
#define MPU_WORD2_M4RE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M4RE_SHIFT))&MPU_WORD2_M4RE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M5WE_MASK                      (0x4000000U)                                        /*!< MPU_WORD2: M5WE Mask                    */
#define MPU_WORD2_M5WE_SHIFT                     (26U)                                               /*!< MPU_WORD2: M5WE Position                */
#define MPU_WORD2_M5WE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M5WE_SHIFT))&MPU_WORD2_M5WE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M5RE_MASK                      (0x8000000U)                                        /*!< MPU_WORD2: M5RE Mask                    */
#define MPU_WORD2_M5RE_SHIFT                     (27U)                                               /*!< MPU_WORD2: M5RE Position                */
#define MPU_WORD2_M5RE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M5RE_SHIFT))&MPU_WORD2_M5RE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M6WE_MASK                      (0x10000000U)                                       /*!< MPU_WORD2: M6WE Mask                    */
#define MPU_WORD2_M6WE_SHIFT                     (28U)                                               /*!< MPU_WORD2: M6WE Position                */
#define MPU_WORD2_M6WE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M6WE_SHIFT))&MPU_WORD2_M6WE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M6RE_MASK                      (0x20000000U)                                       /*!< MPU_WORD2: M6RE Mask                    */
#define MPU_WORD2_M6RE_SHIFT                     (29U)                                               /*!< MPU_WORD2: M6RE Position                */
#define MPU_WORD2_M6RE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M6RE_SHIFT))&MPU_WORD2_M6RE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M7WE_MASK                      (0x40000000U)                                       /*!< MPU_WORD2: M7WE Mask                    */
#define MPU_WORD2_M7WE_SHIFT                     (30U)                                               /*!< MPU_WORD2: M7WE Position                */
#define MPU_WORD2_M7WE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M7WE_SHIFT))&MPU_WORD2_M7WE_MASK) /*!< MPU_WORD2                               */
#define MPU_WORD2_M7RE_MASK                      (0x80000000U)                                       /*!< MPU_WORD2: M7RE Mask                    */
#define MPU_WORD2_M7RE_SHIFT                     (31U)                                               /*!< MPU_WORD2: M7RE Position                */
#define MPU_WORD2_M7RE(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_WORD2_M7RE_SHIFT))&MPU_WORD2_M7RE_MASK) /*!< MPU_WORD2                               */
/* ------- WORD3 Bit Fields                         ------ */
#define MPU_WORD3_VLD_MASK                       (0x1U)                                              /*!< MPU_WORD3: VLD Mask                     */
#define MPU_WORD3_VLD_SHIFT                      (0U)                                                /*!< MPU_WORD3: VLD Position                 */
#define MPU_WORD3_VLD(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD3_VLD_SHIFT))&MPU_WORD3_VLD_MASK) /*!< MPU_WORD3                               */
/* ------- RGDAAC Bit Fields                        ------ */
#define MPU_RGDAAC_M0UM_MASK                     (0x7U)                                              /*!< MPU_RGDAAC: M0UM Mask                   */
#define MPU_RGDAAC_M0UM_SHIFT                    (0U)                                                /*!< MPU_RGDAAC: M0UM Position               */
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0UM_SHIFT))&MPU_RGDAAC_M0UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M0SM_MASK                     (0x18U)                                             /*!< MPU_RGDAAC: M0SM Mask                   */
#define MPU_RGDAAC_M0SM_SHIFT                    (3U)                                                /*!< MPU_RGDAAC: M0SM Position               */
#define MPU_RGDAAC_M0SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0SM_SHIFT))&MPU_RGDAAC_M0SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M1UM_MASK                     (0x1C0U)                                            /*!< MPU_RGDAAC: M1UM Mask                   */
#define MPU_RGDAAC_M1UM_SHIFT                    (6U)                                                /*!< MPU_RGDAAC: M1UM Position               */
#define MPU_RGDAAC_M1UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1UM_SHIFT))&MPU_RGDAAC_M1UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M1SM_MASK                     (0x600U)                                            /*!< MPU_RGDAAC: M1SM Mask                   */
#define MPU_RGDAAC_M1SM_SHIFT                    (9U)                                                /*!< MPU_RGDAAC: M1SM Position               */
#define MPU_RGDAAC_M1SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1SM_SHIFT))&MPU_RGDAAC_M1SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M2UM_MASK                     (0x7000U)                                           /*!< MPU_RGDAAC: M2UM Mask                   */
#define MPU_RGDAAC_M2UM_SHIFT                    (12U)                                               /*!< MPU_RGDAAC: M2UM Position               */
#define MPU_RGDAAC_M2UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2UM_SHIFT))&MPU_RGDAAC_M2UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M2SM_MASK                     (0x18000U)                                          /*!< MPU_RGDAAC: M2SM Mask                   */
#define MPU_RGDAAC_M2SM_SHIFT                    (15U)                                               /*!< MPU_RGDAAC: M2SM Position               */
#define MPU_RGDAAC_M2SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2SM_SHIFT))&MPU_RGDAAC_M2SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M3UM_MASK                     (0x1C0000U)                                         /*!< MPU_RGDAAC: M3UM Mask                   */
#define MPU_RGDAAC_M3UM_SHIFT                    (18U)                                               /*!< MPU_RGDAAC: M3UM Position               */
#define MPU_RGDAAC_M3UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3UM_SHIFT))&MPU_RGDAAC_M3UM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M3SM_MASK                     (0x600000U)                                         /*!< MPU_RGDAAC: M3SM Mask                   */
#define MPU_RGDAAC_M3SM_SHIFT                    (21U)                                               /*!< MPU_RGDAAC: M3SM Position               */
#define MPU_RGDAAC_M3SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3SM_SHIFT))&MPU_RGDAAC_M3SM_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M4WE_MASK                     (0x1000000U)                                        /*!< MPU_RGDAAC: M4WE Mask                   */
#define MPU_RGDAAC_M4WE_SHIFT                    (24U)                                               /*!< MPU_RGDAAC: M4WE Position               */
#define MPU_RGDAAC_M4WE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M4WE_SHIFT))&MPU_RGDAAC_M4WE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M4RE_MASK                     (0x2000000U)                                        /*!< MPU_RGDAAC: M4RE Mask                   */
#define MPU_RGDAAC_M4RE_SHIFT                    (25U)                                               /*!< MPU_RGDAAC: M4RE Position               */
#define MPU_RGDAAC_M4RE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M4RE_SHIFT))&MPU_RGDAAC_M4RE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M5WE_MASK                     (0x4000000U)                                        /*!< MPU_RGDAAC: M5WE Mask                   */
#define MPU_RGDAAC_M5WE_SHIFT                    (26U)                                               /*!< MPU_RGDAAC: M5WE Position               */
#define MPU_RGDAAC_M5WE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M5WE_SHIFT))&MPU_RGDAAC_M5WE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M5RE_MASK                     (0x8000000U)                                        /*!< MPU_RGDAAC: M5RE Mask                   */
#define MPU_RGDAAC_M5RE_SHIFT                    (27U)                                               /*!< MPU_RGDAAC: M5RE Position               */
#define MPU_RGDAAC_M5RE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M5RE_SHIFT))&MPU_RGDAAC_M5RE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M6WE_MASK                     (0x10000000U)                                       /*!< MPU_RGDAAC: M6WE Mask                   */
#define MPU_RGDAAC_M6WE_SHIFT                    (28U)                                               /*!< MPU_RGDAAC: M6WE Position               */
#define MPU_RGDAAC_M6WE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M6WE_SHIFT))&MPU_RGDAAC_M6WE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M6RE_MASK                     (0x20000000U)                                       /*!< MPU_RGDAAC: M6RE Mask                   */
#define MPU_RGDAAC_M6RE_SHIFT                    (29U)                                               /*!< MPU_RGDAAC: M6RE Position               */
#define MPU_RGDAAC_M6RE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M6RE_SHIFT))&MPU_RGDAAC_M6RE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M7WE_MASK                     (0x40000000U)                                       /*!< MPU_RGDAAC: M7WE Mask                   */
#define MPU_RGDAAC_M7WE_SHIFT                    (30U)                                               /*!< MPU_RGDAAC: M7WE Position               */
#define MPU_RGDAAC_M7WE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M7WE_SHIFT))&MPU_RGDAAC_M7WE_MASK) /*!< MPU_RGDAAC                              */
#define MPU_RGDAAC_M7RE_MASK                     (0x80000000U)                                       /*!< MPU_RGDAAC: M7RE Mask                   */
#define MPU_RGDAAC_M7RE_SHIFT                    (31U)                                               /*!< MPU_RGDAAC: M7RE Position               */
#define MPU_RGDAAC_M7RE(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M7RE_SHIFT))&MPU_RGDAAC_M7RE_MASK) /*!< MPU_RGDAAC                              */
/**
 * @} */ /* End group MPU_Register_Masks_GROUP 
 */

/* MPU - Peripheral instance base addresses */
#define MPU_BasePtr                    0x4000D000UL //!< Peripheral base address
#define MPU                            ((MPU_Type *) MPU_BasePtr) //!< Freescale base pointer
#define MPU_BASE_PTR                   (MPU) //!< Freescale style base pointer
/**
 * @} */ /* End group MPU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_FTMRA_0)                 ================ */
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
        uint8_t   RESERVED_0[4];               
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
   __I  uint8_t   FPROT;                        /**< 000E: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   DFPROT;                       /**< 000F: Non-volatile D-Flash Protection Register                     */
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
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /*!< NV_BACKKEY                              */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /*!< NV_FSEC                                 */
/* ------- FOPT Bit Fields                          ------ */
/* ------- FPROT Bit Fields                         ------ */
#define NV_FPROT_FPLS_MASK                       (0x3U)                                              /*!< NV_FPROT: FPLS Mask                     */
#define NV_FPROT_FPLS_SHIFT                      (0U)                                                /*!< NV_FPROT: FPLS Position                 */
#define NV_FPROT_FPLS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLS_SHIFT))&NV_FPROT_FPLS_MASK) /*!< NV_FPROT                                */
#define NV_FPROT_FPLDIS_MASK                     (0x4U)                                              /*!< NV_FPROT: FPLDIS Mask                   */
#define NV_FPROT_FPLDIS_SHIFT                    (2U)                                                /*!< NV_FPROT: FPLDIS Position               */
#define NV_FPROT_FPLDIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLDIS_SHIFT))&NV_FPROT_FPLDIS_MASK) /*!< NV_FPROT                                */
#define NV_FPROT_FPHS_MASK                       (0x18U)                                             /*!< NV_FPROT: FPHS Mask                     */
#define NV_FPROT_FPHS_SHIFT                      (3U)                                                /*!< NV_FPROT: FPHS Position                 */
#define NV_FPROT_FPHS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHS_SHIFT))&NV_FPROT_FPHS_MASK) /*!< NV_FPROT                                */
#define NV_FPROT_FPHDIS_MASK                     (0x20U)                                             /*!< NV_FPROT: FPHDIS Mask                   */
#define NV_FPROT_FPHDIS_SHIFT                    (5U)                                                /*!< NV_FPROT: FPHDIS Position               */
#define NV_FPROT_FPHDIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHDIS_SHIFT))&NV_FPROT_FPHDIS_MASK) /*!< NV_FPROT                                */
#define NV_FPROT_FPOPEN_MASK                     (0x80U)                                             /*!< NV_FPROT: FPOPEN Mask                   */
#define NV_FPROT_FPOPEN_SHIFT                    (7U)                                                /*!< NV_FPROT: FPOPEN Position               */
#define NV_FPROT_FPOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPOPEN_SHIFT))&NV_FPROT_FPOPEN_MASK) /*!< NV_FPROT                                */
/* ------- DFPROT Bit Fields                        ------ */
#define NV_DFPROT_DPS_MASK                       (0x1FU)                                             /*!< NV_DFPROT: DPS Mask                     */
#define NV_DFPROT_DPS_SHIFT                      (0U)                                                /*!< NV_DFPROT: DPS Position                 */
#define NV_DFPROT_DPS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_DFPROT_DPS_SHIFT))&NV_DFPROT_DPS_MASK) /*!< NV_DFPROT                               */
#define NV_DFPROT_DPOPEN_MASK                    (0x80U)                                             /*!< NV_DFPROT: DPOPEN Mask                  */
#define NV_DFPROT_DPOPEN_SHIFT                   (7U)                                                /*!< NV_DFPROT: DPOPEN Position              */
#define NV_DFPROT_DPOPEN(x)                      (((uint8_t)(((uint8_t)(x))<<NV_DFPROT_DPOPEN_SHIFT))&NV_DFPROT_DPOPEN_MASK) /*!< NV_DFPROT                               */
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
/* ================           OSC0 (file:OSC_MKE14)                ================ */
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
#define OSC_CR_OSCINIT_MASK                      (0x1U)                                              /*!< OSC0_CR: OSCINIT Mask                   */
#define OSC_CR_OSCINIT_SHIFT                     (0U)                                                /*!< OSC0_CR: OSCINIT Position               */
#define OSC_CR_OSCINIT(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCINIT_SHIFT))&OSC_CR_OSCINIT_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_HGO_MASK                          (0x2U)                                              /*!< OSC0_CR: HGO Mask                       */
#define OSC_CR_HGO_SHIFT                         (1U)                                                /*!< OSC0_CR: HGO Position                   */
#define OSC_CR_HGO(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_HGO_SHIFT))&OSC_CR_HGO_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_OSCOS_MASK                        (0x10U)                                             /*!< OSC0_CR: OSCOS Mask                     */
#define OSC_CR_OSCOS_SHIFT                       (4U)                                                /*!< OSC0_CR: OSCOS Position                 */
#define OSC_CR_OSCOS(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCOS_SHIFT))&OSC_CR_OSCOS_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_OSCSTEN_MASK                      (0x20U)                                             /*!< OSC0_CR: OSCSTEN Mask                   */
#define OSC_CR_OSCSTEN_SHIFT                     (5U)                                                /*!< OSC0_CR: OSCSTEN Position               */
#define OSC_CR_OSCSTEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCSTEN_SHIFT))&OSC_CR_OSCSTEN_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_OSCEN_MASK                        (0x80U)                                             /*!< OSC0_CR: OSCEN Mask                     */
#define OSC_CR_OSCEN_SHIFT                       (7U)                                                /*!< OSC0_CR: OSCEN Position                 */
#define OSC_CR_OSCEN(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCEN_SHIFT))&OSC_CR_OSCEN_MASK) /*!< OSC0_CR                                 */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40045000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB0 (file:PDB0_2CH_2TRIG_0DAC_3PO)       ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 0 DAC, 3 pulse outputs)
 */
/**
* @addtogroup PDB_structs_GROUP PDB struct
* @brief Struct for PDB
* @{
*/
typedef struct {                                /*       PDB0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulus Register                                             */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
   __IO uint32_t  IDLY;                         /**< 000C: Interrupt Delay Register                                     */
   struct {
      __IO uint32_t  C1;                        /**< 0010: Channel  Control Register 1                                  */
      __IO uint32_t  S;                         /**< 0014: Channel  Status Register                                     */
      __IO uint32_t  DLY[4];                    /**< 0018: Channel Delay  Register                                      */
           uint8_t   RESERVED_0[16];           
   } CH[2];                                     /**< 0010: (cluster: size=0x0050, 80)                                   */
        uint8_t   RESERVED_1[304];             
   __IO uint32_t  POEN;                         /**< 0190: Pulse-Out Enable Register                                    */
   __IO uint32_t  PODLY[3];                     /**< 0194: Pulse-Out  Delay Register                                    */
} PDB_Type;

/**
 * @} */ /* End group PDB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PDB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PDB_Register_Masks_GROUP PDB Register Masks
* @brief Register Masks for PDB
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define PDB_SC_LDOK_MASK                         (0x1U)                                              /*!< PDB0_SC: LDOK Mask                      */
#define PDB_SC_LDOK_SHIFT                        (0U)                                                /*!< PDB0_SC: LDOK Position                  */
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDOK_SHIFT))&PDB_SC_LDOK_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_CONT_MASK                         (0x2U)                                              /*!< PDB0_SC: CONT Mask                      */
#define PDB_SC_CONT_SHIFT                        (1U)                                                /*!< PDB0_SC: CONT Position                  */
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_CONT_SHIFT))&PDB_SC_CONT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_MULT_MASK                         (0xCU)                                              /*!< PDB0_SC: MULT Mask                      */
#define PDB_SC_MULT_SHIFT                        (2U)                                                /*!< PDB0_SC: MULT Position                  */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIE_MASK                        (0x20U)                                             /*!< PDB0_SC: PDBIE Mask                     */
#define PDB_SC_PDBIE_SHIFT                       (5U)                                                /*!< PDB0_SC: PDBIE Position                 */
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIE_SHIFT))&PDB_SC_PDBIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIF_MASK                        (0x40U)                                             /*!< PDB0_SC: PDBIF Mask                     */
#define PDB_SC_PDBIF_SHIFT                       (6U)                                                /*!< PDB0_SC: PDBIF Position                 */
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIF_SHIFT))&PDB_SC_PDBIF_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEN_MASK                        (0x80U)                                             /*!< PDB0_SC: PDBEN Mask                     */
#define PDB_SC_PDBEN_SHIFT                       (7U)                                                /*!< PDB0_SC: PDBEN Position                 */
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEN_SHIFT))&PDB_SC_PDBEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_TRGSEL_MASK                       (0xF00U)                                            /*!< PDB0_SC: TRGSEL Mask                    */
#define PDB_SC_TRGSEL_SHIFT                      (8U)                                                /*!< PDB0_SC: TRGSEL Position                */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PRESCALER_MASK                    (0x7000U)                                           /*!< PDB0_SC: PRESCALER Mask                 */
#define PDB_SC_PRESCALER_SHIFT                   (12U)                                               /*!< PDB0_SC: PRESCALER Position             */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_DMAEN_MASK                        (0x8000U)                                           /*!< PDB0_SC: DMAEN Mask                     */
#define PDB_SC_DMAEN_SHIFT                       (15U)                                               /*!< PDB0_SC: DMAEN Position                 */
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_DMAEN_SHIFT))&PDB_SC_DMAEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_SWTRIG_MASK                       (0x10000U)                                          /*!< PDB0_SC: SWTRIG Mask                    */
#define PDB_SC_SWTRIG_SHIFT                      (16U)                                               /*!< PDB0_SC: SWTRIG Position                */
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_SWTRIG_SHIFT))&PDB_SC_SWTRIG_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEIE_MASK                       (0x20000U)                                          /*!< PDB0_SC: PDBEIE Mask                    */
#define PDB_SC_PDBEIE_SHIFT                      (17U)                                               /*!< PDB0_SC: PDBEIE Position                */
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEIE_SHIFT))&PDB_SC_PDBEIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_LDMOD_MASK                        (0xC0000U)                                          /*!< PDB0_SC: LDMOD Mask                     */
#define PDB_SC_LDMOD_SHIFT                       (18U)                                               /*!< PDB0_SC: LDMOD Position                 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK) /*!< PDB0_SC                                 */
/* ------- MOD Bit Fields                           ------ */
#define PDB_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< PDB0_MOD: MOD Mask                      */
#define PDB_MOD_MOD_SHIFT                        (0U)                                                /*!< PDB0_MOD: MOD Position                  */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK) /*!< PDB0_MOD                                */
/* ------- CNT Bit Fields                           ------ */
#define PDB_CNT_CNT_MASK                         (0xFFFFU)                                           /*!< PDB0_CNT: CNT Mask                      */
#define PDB_CNT_CNT_SHIFT                        (0U)                                                /*!< PDB0_CNT: CNT Position                  */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK) /*!< PDB0_CNT                                */
/* ------- IDLY Bit Fields                          ------ */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)                                           /*!< PDB0_IDLY: IDLY Mask                    */
#define PDB_IDLY_IDLY_SHIFT                      (0U)                                                /*!< PDB0_IDLY: IDLY Position                */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK) /*!< PDB0_IDLY                               */
/* ------- C1 Bit Fields                            ------ */
#define PDB_C1_EN_MASK                           (0xFFU)                                             /*!< PDB0_C1: EN Mask                        */
#define PDB_C1_EN_SHIFT                          (0U)                                                /*!< PDB0_C1: EN Position                    */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_TOS_MASK                          (0xFF00U)                                           /*!< PDB0_C1: TOS Mask                       */
#define PDB_C1_TOS_SHIFT                         (8U)                                                /*!< PDB0_C1: TOS Position                   */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK) /*!< PDB0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define PDB_S_ERR_MASK                           (0xFFU)                                             /*!< PDB0_S: ERR Mask                        */
#define PDB_S_ERR_SHIFT                          (0U)                                                /*!< PDB0_S: ERR Position                    */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK) /*!< PDB0_S                                  */
#define PDB_S_CF_MASK                            (0xFF0000U)                                         /*!< PDB0_S: CF Mask                         */
#define PDB_S_CF_SHIFT                           (16U)                                               /*!< PDB0_S: CF Position                     */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK) /*!< PDB0_S                                  */
/* ------- DLY Bit Fields                           ------ */
#define PDB_DLY_DLY_MASK                         (0xFFFFU)                                           /*!< PDB0_DLY: DLY Mask                      */
#define PDB_DLY_DLY_SHIFT                        (0U)                                                /*!< PDB0_DLY: DLY Position                  */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK) /*!< PDB0_DLY                                */
/* ------- POEN Bit Fields                          ------ */
#define PDB_POEN_POEN_MASK                       (0xFFU)                                             /*!< PDB0_POEN: POEN Mask                    */
#define PDB_POEN_POEN_SHIFT                      (0U)                                                /*!< PDB0_POEN: POEN Position                */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK) /*!< PDB0_POEN                               */
/* ------- PODLY Bit Fields                         ------ */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFU)                                           /*!< PDB0_PODLY: DLY2 Mask                   */
#define PDB_PODLY_DLY2_SHIFT                     (0U)                                                /*!< PDB0_PODLY: DLY2 Position               */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK) /*!< PDB0_PODLY                              */
#define PDB_PODLY_DLY1_MASK                      (0xFFFF0000U)                                       /*!< PDB0_PODLY: DLY1 Mask                   */
#define PDB_PODLY_DLY1_SHIFT                     (16U)                                               /*!< PDB0_PODLY: DLY1 Position               */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK) /*!< PDB0_PODLY                              */
/**
 * @} */ /* End group PDB_Register_Masks_GROUP 
 */

/* PDB0 - Peripheral instance base addresses */
#define PDB0_BasePtr                   0x40025000UL //!< Peripheral base address
#define PDB0                           ((PDB_Type *) PDB0_BasePtr) //!< Freescale base pointer
#define PDB0_BASE_PTR                  (PDB0) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB1 (derived from PDB0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 0 DAC, 3 pulse outputs)
 */

/* PDB1 - Peripheral instance base addresses */
#define PDB1_BasePtr                   0x40026000UL //!< Peripheral base address
#define PDB1                           ((PDB_Type *) PDB1_BasePtr) //!< Freescale base pointer
#define PDB1_BASE_PTR                  (PDB1) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB2 (derived from PDB0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 0 DAC, 3 pulse outputs)
 */

/* PDB2 - Peripheral instance base addresses */
#define PDB2_BasePtr                   0x40027000UL //!< Peripheral base address
#define PDB2                           ((PDB_Type *) PDB2_BasePtr) //!< Freescale base pointer
#define PDB2_BASE_PTR                  (PDB2) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB3 (derived from PDB0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 0 DAC, 3 pulse outputs)
 */

/* PDB3 - Peripheral instance base addresses */
#define PDB3_BasePtr                   0x40028000UL //!< Peripheral base address
#define PDB3                           ((PDB_Type *) PDB3_BasePtr) //!< Freescale base pointer
#define PDB3_BASE_PTR                  (PDB3) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT (file:PIT_4CH_CHAIN_LTMR)        ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (4 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT Structure                                                */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
        uint8_t   RESERVED_0[220];             
   __I  uint32_t  LTMR64H;                      /**< 00E0: PIT Upper Lifetime Timer Register                            */
   __I  uint32_t  LTMR64L;                      /**< 00E4: PIT Lower Lifetime Timer Register                            */
        uint8_t   RESERVED_1[24];              
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[4];                                /**< 0100: (cluster: size=0x0040, 64)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /*!< PIT_MCR: FRZ Mask                       */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /*!< PIT_MCR: FRZ Position                   */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<PIT_MCR_FRZ_SHIFT))&PIT_MCR_FRZ_MASK) /*!< PIT_MCR                                 */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /*!< PIT_MCR: MDIS Mask                      */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /*!< PIT_MCR: MDIS Position                  */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_MCR_MDIS_SHIFT))&PIT_MCR_MDIS_MASK) /*!< PIT_MCR                                 */
/* ------- LTMR64H Bit Fields                       ------ */
#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)                                       /*!< PIT_LTMR64H: LTH Mask                   */
#define PIT_LTMR64H_LTH_SHIFT                    (0U)                                                /*!< PIT_LTMR64H: LTH Position               */
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64H_LTH_SHIFT))&PIT_LTMR64H_LTH_MASK) /*!< PIT_LTMR64H                             */
/* ------- LTMR64L Bit Fields                       ------ */
#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)                                       /*!< PIT_LTMR64L: LTL Mask                   */
#define PIT_LTMR64L_LTL_SHIFT                    (0U)                                                /*!< PIT_LTMR64L: LTL Position               */
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64L_LTL_SHIFT))&PIT_LTMR64L_LTL_MASK) /*!< PIT_LTMR64L                             */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /*!< PIT_LDVAL: TSV Mask                     */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /*!< PIT_LDVAL: TSV Position                 */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /*!< PIT_LDVAL                               */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /*!< PIT_CVAL: TVL Mask                      */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /*!< PIT_CVAL: TVL Position                  */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /*!< PIT_CVAL                                */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /*!< PIT_TCTRL: TEN Mask                     */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /*!< PIT_TCTRL: TEN Position                 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TEN_SHIFT))&PIT_TCTRL_TEN_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /*!< PIT_TCTRL: TIE Mask                     */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /*!< PIT_TCTRL: TIE Position                 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TIE_SHIFT))&PIT_TCTRL_TIE_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /*!< PIT_TCTRL: CHN Mask                     */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /*!< PIT_TCTRL: CHN Position                 */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_CHN_SHIFT))&PIT_TCTRL_CHN_MASK) /*!< PIT_TCTRL                               */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /*!< PIT_TFLG: TIF Mask                      */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /*!< PIT_TFLG: TIF Position                  */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_TFLG_TIF_SHIFT))&PIT_TFLG_TIF_MASK) /*!< PIT_TFLG                                */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40023000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MKE10)                 ================ */
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
   __IO uint8_t   SPMSC1;                       /**< 0000: System Power Management Status and Control 1 Register        */
   __IO uint8_t   SPMSC2;                       /**< 0001: System Power Management Status and Control 2 Register        */
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
/* ------- SPMSC1 Bit Fields                        ------ */
#define PMC_SPMSC1_BGBE_MASK                     (0x1U)                                              /*!< PMC_SPMSC1: BGBE Mask                   */
#define PMC_SPMSC1_BGBE_SHIFT                    (0U)                                                /*!< PMC_SPMSC1: BGBE Position               */
#define PMC_SPMSC1_BGBE(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_BGBE_SHIFT))&PMC_SPMSC1_BGBE_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_BGBDS_MASK                    (0x2U)                                              /*!< PMC_SPMSC1: BGBDS Mask                  */
#define PMC_SPMSC1_BGBDS_SHIFT                   (1U)                                                /*!< PMC_SPMSC1: BGBDS Position              */
#define PMC_SPMSC1_BGBDS(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_BGBDS_SHIFT))&PMC_SPMSC1_BGBDS_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVDE_MASK                     (0x4U)                                              /*!< PMC_SPMSC1: LVDE Mask                   */
#define PMC_SPMSC1_LVDE_SHIFT                    (2U)                                                /*!< PMC_SPMSC1: LVDE Position               */
#define PMC_SPMSC1_LVDE(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDE_SHIFT))&PMC_SPMSC1_LVDE_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVDSE_MASK                    (0x8U)                                              /*!< PMC_SPMSC1: LVDSE Mask                  */
#define PMC_SPMSC1_LVDSE_SHIFT                   (3U)                                                /*!< PMC_SPMSC1: LVDSE Position              */
#define PMC_SPMSC1_LVDSE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDSE_SHIFT))&PMC_SPMSC1_LVDSE_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVDRE_MASK                    (0x10U)                                             /*!< PMC_SPMSC1: LVDRE Mask                  */
#define PMC_SPMSC1_LVDRE_SHIFT                   (4U)                                                /*!< PMC_SPMSC1: LVDRE Position              */
#define PMC_SPMSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDRE_SHIFT))&PMC_SPMSC1_LVDRE_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVWIE_MASK                    (0x20U)                                             /*!< PMC_SPMSC1: LVWIE Mask                  */
#define PMC_SPMSC1_LVWIE_SHIFT                   (5U)                                                /*!< PMC_SPMSC1: LVWIE Position              */
#define PMC_SPMSC1_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWIE_SHIFT))&PMC_SPMSC1_LVWIE_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVWACK_MASK                   (0x40U)                                             /*!< PMC_SPMSC1: LVWACK Mask                 */
#define PMC_SPMSC1_LVWACK_SHIFT                  (6U)                                                /*!< PMC_SPMSC1: LVWACK Position             */
#define PMC_SPMSC1_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWACK_SHIFT))&PMC_SPMSC1_LVWACK_MASK) /*!< PMC_SPMSC1                              */
#define PMC_SPMSC1_LVWF_MASK                     (0x80U)                                             /*!< PMC_SPMSC1: LVWF Mask                   */
#define PMC_SPMSC1_LVWF_SHIFT                    (7U)                                                /*!< PMC_SPMSC1: LVWF Position               */
#define PMC_SPMSC1_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWF_SHIFT))&PMC_SPMSC1_LVWF_MASK) /*!< PMC_SPMSC1                              */
/* ------- SPMSC2 Bit Fields                        ------ */
#define PMC_SPMSC2_LVWV_MASK                     (0x30U)                                             /*!< PMC_SPMSC2: LVWV Mask                   */
#define PMC_SPMSC2_LVWV_SHIFT                    (4U)                                                /*!< PMC_SPMSC2: LVWV Position               */
#define PMC_SPMSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC2_LVWV_SHIFT))&PMC_SPMSC2_LVWV_MASK) /*!< PMC_SPMSC2                              */
#define PMC_SPMSC2_LVDV_MASK                     (0x40U)                                             /*!< PMC_SPMSC2: LVDV Mask                   */
#define PMC_SPMSC2_LVDV_SHIFT                    (6U)                                                /*!< PMC_SPMSC2: LVDV Position               */
#define PMC_SPMSC2_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC2_LVDV_SHIFT))&PMC_SPMSC2_LVDV_MASK) /*!< PMC_SPMSC2                              */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x40054000UL //!< Peripheral base address
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
/* ================           PORTA (file:PORTA_MKE)               ================ */
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
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
        uint8_t   RESERVED_1[28];              
   __IO uint32_t  DFER;                         /**< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /**< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /**< 00C8: Digital Filter Width Register                                */
} PORTA_Type;

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
#define PORT_PCR_PE_MASK                         (0x2U)                                              /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_LK_MASK                         (0x8000U)                                           /*!< PORTA_PCR: LK Mask                      */
#define PORT_PCR_LK_SHIFT                        (15U)                                               /*!< PORTA_PCR: LK Position                  */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /*!< PORTA_PCR: ISF Position                 */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK) /*!< PORTA_PCR                               */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */
/* ------- ISFR Bit Fields                          ------ */
/* ------- DFER Bit Fields                          ------ */
/* ------- DFCR Bit Fields                          ------ */
#define PORT_DFCR_CS_MASK                        (0x1U)                                              /*!< PORTA_DFCR: CS Mask                     */
#define PORT_DFCR_CS_SHIFT                       (0U)                                                /*!< PORTA_DFCR: CS Position                 */
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK) /*!< PORTA_DFCR                              */
/* ------- DFWR Bit Fields                          ------ */
#define PORT_DFWR_FILT_MASK                      (0x1FU)                                             /*!< PORTA_DFWR: FILT Mask                   */
#define PORT_DFWR_FILT_SHIFT                     (0U)                                                /*!< PORTA_DFWR: FILT Position               */
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK) /*!< PORTA_DFWR                              */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40033000UL //!< Peripheral base address
#define PORTA                          ((PORTA_Type *) PORTA_BasePtr) //!< Freescale base pointer
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
#define PORTB_BasePtr                  0x40034000UL //!< Peripheral base address
#define PORTB                          ((PORTA_Type *) PORTB_BasePtr) //!< Freescale base pointer
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
#define PORTC_BasePtr                  0x40035000UL //!< Peripheral base address
#define PORTC                          ((PORTA_Type *) PORTC_BasePtr) //!< Freescale base pointer
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
#define PORTD_BasePtr                  0x40036000UL //!< Peripheral base address
#define PORTD                          ((PORTA_Type *) PORTD_BasePtr) //!< Freescale base pointer
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
/* ================           PORTE (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x40037000UL //!< Peripheral base address
#define PORTE                          ((PORTA_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MKE)                   ================ */
/* ================================================================================ */

/**
 * @brief Reset control module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRSL;                         /**< 0000: RCM System Reset Status Low Register                         */
   __I  uint8_t   SRSH;                         /**< 0001: RCM System Reset Status High Register                        */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   RPFC;                         /**< 0004: RCM RESETb Pin Filter Control Register                       */
   __IO uint8_t   RPFW;                         /**< 0005: RCM RESETb Pin Filter Width Register                         */
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
/* ------- SRSL Bit Fields                          ------ */
#define RCM_SRSL_LVD_MASK                        (0x2U)                                              /*!< RCM_SRSL: LVD Mask                      */
#define RCM_SRSL_LVD_SHIFT                       (1U)                                                /*!< RCM_SRSL: LVD Position                  */
#define RCM_SRSL_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRSL_LVD_SHIFT))&RCM_SRSL_LVD_MASK) /*!< RCM_SRSL                                */
#define RCM_SRSL_LOC_MASK                        (0x4U)                                              /*!< RCM_SRSL: LOC Mask                      */
#define RCM_SRSL_LOC_SHIFT                       (2U)                                                /*!< RCM_SRSL: LOC Position                  */
#define RCM_SRSL_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRSL_LOC_SHIFT))&RCM_SRSL_LOC_MASK) /*!< RCM_SRSL                                */
#define RCM_SRSL_COP_MASK                        (0x20U)                                             /*!< RCM_SRSL: COP Mask                      */
#define RCM_SRSL_COP_SHIFT                       (5U)                                                /*!< RCM_SRSL: COP Position                  */
#define RCM_SRSL_COP(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRSL_COP_SHIFT))&RCM_SRSL_COP_MASK) /*!< RCM_SRSL                                */
#define RCM_SRSL_PIN_MASK                        (0x40U)                                             /*!< RCM_SRSL: PIN Mask                      */
#define RCM_SRSL_PIN_SHIFT                       (6U)                                                /*!< RCM_SRSL: PIN Position                  */
#define RCM_SRSL_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRSL_PIN_SHIFT))&RCM_SRSL_PIN_MASK) /*!< RCM_SRSL                                */
#define RCM_SRSL_POR_MASK                        (0x80U)                                             /*!< RCM_SRSL: POR Mask                      */
#define RCM_SRSL_POR_SHIFT                       (7U)                                                /*!< RCM_SRSL: POR Position                  */
#define RCM_SRSL_POR(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRSL_POR_SHIFT))&RCM_SRSL_POR_MASK) /*!< RCM_SRSL                                */
/* ------- SRSH Bit Fields                          ------ */
#define RCM_SRSH_JTAG_MASK                       (0x1U)                                              /*!< RCM_SRSH: JTAG Mask                     */
#define RCM_SRSH_JTAG_SHIFT                      (0U)                                                /*!< RCM_SRSH: JTAG Position                 */
#define RCM_SRSH_JTAG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRSH_JTAG_SHIFT))&RCM_SRSH_JTAG_MASK) /*!< RCM_SRSH                                */
#define RCM_SRSH_LOCKUP_MASK                     (0x2U)                                              /*!< RCM_SRSH: LOCKUP Mask                   */
#define RCM_SRSH_LOCKUP_SHIFT                    (1U)                                                /*!< RCM_SRSH: LOCKUP Position               */
#define RCM_SRSH_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRSH_LOCKUP_SHIFT))&RCM_SRSH_LOCKUP_MASK) /*!< RCM_SRSH                                */
#define RCM_SRSH_SW_MASK                         (0x4U)                                              /*!< RCM_SRSH: SW Mask                       */
#define RCM_SRSH_SW_SHIFT                        (2U)                                                /*!< RCM_SRSH: SW Position                   */
#define RCM_SRSH_SW(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_SRSH_SW_SHIFT))&RCM_SRSH_SW_MASK) /*!< RCM_SRSH                                */
#define RCM_SRSH_MDMAP_MASK                      (0x8U)                                              /*!< RCM_SRSH: MDMAP Mask                    */
#define RCM_SRSH_MDMAP_SHIFT                     (3U)                                                /*!< RCM_SRSH: MDMAP Position                */
#define RCM_SRSH_MDMAP(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SRSH_MDMAP_SHIFT))&RCM_SRSH_MDMAP_MASK) /*!< RCM_SRSH                                */
#define RCM_SRSH_SACKERR_MASK                    (0x20U)                                             /*!< RCM_SRSH: SACKERR Mask                  */
#define RCM_SRSH_SACKERR_SHIFT                   (5U)                                                /*!< RCM_SRSH: SACKERR Position              */
#define RCM_SRSH_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<RCM_SRSH_SACKERR_SHIFT))&RCM_SRSH_SACKERR_MASK) /*!< RCM_SRSH                                */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /*!< RCM_RPFC: RSTFLTSS Position             */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSS_SHIFT))&RCM_RPFC_RSTFLTSS_MASK) /*!< RCM_RPFC                                */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSS_MASK                   (0x1FU)                                             /*!< RCM_RPFW: RSTFLTSS Mask                 */
#define RCM_RPFW_RSTFLTSS_SHIFT                  (0U)                                                /*!< RCM_RPFW: RSTFLTSS Position             */
#define RCM_RPFW_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSS_SHIFT))&RCM_RPFW_RSTFLTSS_MASK) /*!< RCM_RPFW                                */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x40057000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_MKE10)                 ================ */
/* ================================================================================ */

/**
 * @brief Real-time counter
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulo Register: Contains the modulo value used to reset the count to 0x0000 upon a compare match and set SC[RTIF] status field */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register: Reset or writing different values to SC[RTCLKS] and SC[RTCPS] clear the count to 0x0000 */
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
/* ------- SC Bit Fields                            ------ */
#define RTC_SC_RTCO_MASK                         (0x10U)                                             /*!< RTC_SC: RTCO Mask                       */
#define RTC_SC_RTCO_SHIFT                        (4U)                                                /*!< RTC_SC: RTCO Position                   */
#define RTC_SC_RTCO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCO_SHIFT))&RTC_SC_RTCO_MASK) /*!< RTC_SC                                  */
#define RTC_SC_DMAE_MASK                         (0x20U)                                             /*!< RTC_SC: DMAE Mask                       */
#define RTC_SC_DMAE_SHIFT                        (5U)                                                /*!< RTC_SC: DMAE Position                   */
#define RTC_SC_DMAE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_DMAE_SHIFT))&RTC_SC_DMAE_MASK) /*!< RTC_SC                                  */
#define RTC_SC_RTIE_MASK                         (0x40U)                                             /*!< RTC_SC: RTIE Mask                       */
#define RTC_SC_RTIE_SHIFT                        (6U)                                                /*!< RTC_SC: RTIE Position                   */
#define RTC_SC_RTIE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTIE_SHIFT))&RTC_SC_RTIE_MASK) /*!< RTC_SC                                  */
#define RTC_SC_RTIF_MASK                         (0x80U)                                             /*!< RTC_SC: RTIF Mask                       */
#define RTC_SC_RTIF_SHIFT                        (7U)                                                /*!< RTC_SC: RTIF Position                   */
#define RTC_SC_RTIF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTIF_SHIFT))&RTC_SC_RTIF_MASK) /*!< RTC_SC                                  */
#define RTC_SC_RTCPS_MASK                        (0x700U)                                            /*!< RTC_SC: RTCPS Mask                      */
#define RTC_SC_RTCPS_SHIFT                       (8U)                                                /*!< RTC_SC: RTCPS Position                  */
#define RTC_SC_RTCPS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCPS_SHIFT))&RTC_SC_RTCPS_MASK) /*!< RTC_SC                                  */
#define RTC_SC_RTCLKS_MASK                       (0xC000U)                                           /*!< RTC_SC: RTCLKS Mask                     */
#define RTC_SC_RTCLKS_SHIFT                      (14U)                                               /*!< RTC_SC: RTCLKS Position                 */
#define RTC_SC_RTCLKS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCLKS_SHIFT))&RTC_SC_RTCLKS_MASK) /*!< RTC_SC                                  */
/* ------- MOD Bit Fields                           ------ */
#define RTC_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< RTC_MOD: MOD Mask                       */
#define RTC_MOD_MOD_SHIFT                        (0U)                                                /*!< RTC_MOD: MOD Position                   */
#define RTC_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_MOD_MOD_SHIFT))&RTC_MOD_MOD_MASK) /*!< RTC_MOD                                 */
/* ------- CNT Bit Fields                           ------ */
#define RTC_CNT_CNT_MASK                         (0xFFFFU)                                           /*!< RTC_CNT: CNT Mask                       */
#define RTC_CNT_CNT_SHIFT                        (0U)                                                /*!< RTC_CNT: CNT Position                   */
#define RTC_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CNT_CNT_SHIFT))&RTC_CNT_CNT_MASK) /*!< RTC_CNT                                 */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4002D000UL //!< Peripheral base address
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
/* ================           SIM (file:SIM_MKE14D7)               ================ */
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
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  SOPT2;                        /**< 0004: System Options Register 2                                    */
   __IO uint32_t  SOPT3;                        /**< 0008: System Options Register 3                                    */
   __IO uint32_t  SOPT4;                        /**< 000C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 0010: System Options Register 5                                    */
   __IO uint32_t  SOPT6;                        /**< 0014: System Options Register 6                                    */
   __IO uint32_t  SOPT7;                        /**< 0018: System Options Register 7                                    */
        uint8_t   RESERVED_1[8];               
   __I  uint32_t  SDID;                         /**< 0024: System Device Identification Register                        */
        uint8_t   RESERVED_2[16];              
   __IO uint32_t  SCGC5;                        /**< 0038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 003C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 0040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 0044: System Clock Divider Register 1                              */
        uint8_t   RESERVED_3[12];              
   __I  uint32_t  UIDH;                         /**< 0054: Unique Identification Register High                          */
   __I  uint32_t  UIDMH;                        /**< 0058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 005C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 0060: Unique Identification Register Low                           */
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
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_FLLENSTOP4_MASK                (0x1U)                                              /*!< SIM_SOPT2: FLLENSTOP4 Mask              */
#define SIM_SOPT2_FLLENSTOP4_SHIFT               (0U)                                                /*!< SIM_SOPT2: FLLENSTOP4 Position          */
#define SIM_SOPT2_FLLENSTOP4(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FLLENSTOP4_SHIFT))&SIM_SOPT2_FLLENSTOP4_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_RESETIFE_MASK                  (0x2U)                                              /*!< SIM_SOPT2: RESETIFE Mask                */
#define SIM_SOPT2_RESETIFE_SHIFT                 (1U)                                                /*!< SIM_SOPT2: RESETIFE Position            */
#define SIM_SOPT2_RESETIFE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RESETIFE_SHIFT))&SIM_SOPT2_RESETIFE_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELA13_MASK              (0x30U)                                             /*!< SIM_SOPT2: OBEPADSELA13 Mask            */
#define SIM_SOPT2_OBEPADSELA13_SHIFT             (4U)                                                /*!< SIM_SOPT2: OBEPADSELA13 Position        */
#define SIM_SOPT2_OBEPADSELA13(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELA13_SHIFT))&SIM_SOPT2_OBEPADSELA13_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELA12_MASK              (0xC0U)                                             /*!< SIM_SOPT2: OBEPADSELA12 Mask            */
#define SIM_SOPT2_OBEPADSELA12_SHIFT             (6U)                                                /*!< SIM_SOPT2: OBEPADSELA12 Position        */
#define SIM_SOPT2_OBEPADSELA12(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELA12_SHIFT))&SIM_SOPT2_OBEPADSELA12_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELA3_MASK               (0x300U)                                            /*!< SIM_SOPT2: OBEPADSELA3 Mask             */
#define SIM_SOPT2_OBEPADSELA3_SHIFT              (8U)                                                /*!< SIM_SOPT2: OBEPADSELA3 Position         */
#define SIM_SOPT2_OBEPADSELA3(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELA3_SHIFT))&SIM_SOPT2_OBEPADSELA3_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELA2_MASK               (0xC00U)                                            /*!< SIM_SOPT2: OBEPADSELA2 Mask             */
#define SIM_SOPT2_OBEPADSELA2_SHIFT              (10U)                                               /*!< SIM_SOPT2: OBEPADSELA2 Position         */
#define SIM_SOPT2_OBEPADSELA2(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELA2_SHIFT))&SIM_SOPT2_OBEPADSELA2_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELE1_MASK               (0x3000U)                                           /*!< SIM_SOPT2: OBEPADSELE1 Mask             */
#define SIM_SOPT2_OBEPADSELE1_SHIFT              (12U)                                               /*!< SIM_SOPT2: OBEPADSELE1 Position         */
#define SIM_SOPT2_OBEPADSELE1(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELE1_SHIFT))&SIM_SOPT2_OBEPADSELE1_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_OBEPADSELE0_MASK               (0xC000U)                                           /*!< SIM_SOPT2: OBEPADSELE0 Mask             */
#define SIM_SOPT2_OBEPADSELE0_SHIFT              (14U)                                               /*!< SIM_SOPT2: OBEPADSELE0 Position         */
#define SIM_SOPT2_OBEPADSELE0(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_OBEPADSELE0_SHIFT))&SIM_SOPT2_OBEPADSELE0_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_FBSL_MASK                      (0x30000U)                                          /*!< SIM_SOPT2: FBSL Mask                    */
#define SIM_SOPT2_FBSL_SHIFT                     (16U)                                               /*!< SIM_SOPT2: FBSL Position                */
#define SIM_SOPT2_FBSL(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FBSL_SHIFT))&SIM_SOPT2_FBSL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_TRACECLKSEL_MASK               (0x40000U)                                          /*!< SIM_SOPT2: TRACECLKSEL Mask             */
#define SIM_SOPT2_TRACECLKSEL_SHIFT              (18U)                                               /*!< SIM_SOPT2: TRACECLKSEL Position         */
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TRACECLKSEL_SHIFT))&SIM_SOPT2_TRACECLKSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_RAMSIZE_MASK                   (0x200000U)                                         /*!< SIM_SOPT2: RAMSIZE Mask                 */
#define SIM_SOPT2_RAMSIZE_SHIFT                  (21U)                                               /*!< SIM_SOPT2: RAMSIZE Position             */
#define SIM_SOPT2_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RAMSIZE_SHIFT))&SIM_SOPT2_RAMSIZE_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_FSIZE_MASK                     (0xC000000U)                                        /*!< SIM_SOPT2: FSIZE Mask                   */
#define SIM_SOPT2_FSIZE_SHIFT                    (26U)                                               /*!< SIM_SOPT2: FSIZE Position               */
#define SIM_SOPT2_FSIZE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FSIZE_SHIFT))&SIM_SOPT2_FSIZE_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_TSI0EN_MASK                    (0x10000000U)                                       /*!< SIM_SOPT2: TSI0EN Mask                  */
#define SIM_SOPT2_TSI0EN_SHIFT                   (28U)                                               /*!< SIM_SOPT2: TSI0EN Position              */
#define SIM_SOPT2_TSI0EN(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TSI0EN_SHIFT))&SIM_SOPT2_TSI0EN_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_MAXCLK_MASK                    (0x20000000U)                                       /*!< SIM_SOPT2: MAXCLK Mask                  */
#define SIM_SOPT2_MAXCLK_SHIFT                   (29U)                                               /*!< SIM_SOPT2: MAXCLK Position              */
#define SIM_SOPT2_MAXCLK(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_MAXCLK_SHIFT))&SIM_SOPT2_MAXCLK_MASK) /*!< SIM_SOPT2                               */
/* ------- SOPT3 Bit Fields                         ------ */
#define SIM_SOPT3_FTM0_PDB_MASK                  (0xFU)                                              /*!< SIM_SOPT3: FTM0_PDB Mask                */
#define SIM_SOPT3_FTM0_PDB_SHIFT                 (0U)                                                /*!< SIM_SOPT3: FTM0_PDB Position            */
#define SIM_SOPT3_FTM0_PDB(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM0_PDB_SHIFT))&SIM_SOPT3_FTM0_PDB_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM1_PDB_MASK                  (0xF0U)                                             /*!< SIM_SOPT3: FTM1_PDB Mask                */
#define SIM_SOPT3_FTM1_PDB_SHIFT                 (4U)                                                /*!< SIM_SOPT3: FTM1_PDB Position            */
#define SIM_SOPT3_FTM1_PDB(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM1_PDB_SHIFT))&SIM_SOPT3_FTM1_PDB_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM2_PDB_MASK                  (0xF00U)                                            /*!< SIM_SOPT3: FTM2_PDB Mask                */
#define SIM_SOPT3_FTM2_PDB_SHIFT                 (8U)                                                /*!< SIM_SOPT3: FTM2_PDB Position            */
#define SIM_SOPT3_FTM2_PDB(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM2_PDB_SHIFT))&SIM_SOPT3_FTM2_PDB_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM3_PDB_MASK                  (0xF000U)                                           /*!< SIM_SOPT3: FTM3_PDB Mask                */
#define SIM_SOPT3_FTM3_PDB_SHIFT                 (12U)                                               /*!< SIM_SOPT3: FTM3_PDB Position            */
#define SIM_SOPT3_FTM3_PDB(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM3_PDB_SHIFT))&SIM_SOPT3_FTM3_PDB_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM_SYNC0_MASK                 (0x10000U)                                          /*!< SIM_SOPT3: FTM_SYNC0 Mask               */
#define SIM_SOPT3_FTM_SYNC0_SHIFT                (16U)                                               /*!< SIM_SOPT3: FTM_SYNC0 Position           */
#define SIM_SOPT3_FTM_SYNC0(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM_SYNC0_SHIFT))&SIM_SOPT3_FTM_SYNC0_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM_SYNC1_MASK                 (0x20000U)                                          /*!< SIM_SOPT3: FTM_SYNC1 Mask               */
#define SIM_SOPT3_FTM_SYNC1_SHIFT                (17U)                                               /*!< SIM_SOPT3: FTM_SYNC1 Position           */
#define SIM_SOPT3_FTM_SYNC1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM_SYNC1_SHIFT))&SIM_SOPT3_FTM_SYNC1_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM_SYNC2_MASK                 (0x40000U)                                          /*!< SIM_SOPT3: FTM_SYNC2 Mask               */
#define SIM_SOPT3_FTM_SYNC2_SHIFT                (18U)                                               /*!< SIM_SOPT3: FTM_SYNC2 Position           */
#define SIM_SOPT3_FTM_SYNC2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM_SYNC2_SHIFT))&SIM_SOPT3_FTM_SYNC2_MASK) /*!< SIM_SOPT3                               */
#define SIM_SOPT3_FTM_SYNC3_MASK                 (0x80000U)                                          /*!< SIM_SOPT3: FTM_SYNC3 Mask               */
#define SIM_SOPT3_FTM_SYNC3_SHIFT                (19U)                                               /*!< SIM_SOPT3: FTM_SYNC3 Position           */
#define SIM_SOPT3_FTM_SYNC3(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT3_FTM_SYNC3_SHIFT))&SIM_SOPT3_FTM_SYNC3_MASK) /*!< SIM_SOPT3                               */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_FTM0FLT0_MASK                  (0x1U)                                              /*!< SIM_SOPT4: FTM0FLT0 Mask                */
#define SIM_SOPT4_FTM0FLT0_SHIFT                 (0U)                                                /*!< SIM_SOPT4: FTM0FLT0 Position            */
#define SIM_SOPT4_FTM0FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT0_SHIFT))&SIM_SOPT4_FTM0FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT1_MASK                  (0x2U)                                              /*!< SIM_SOPT4: FTM0FLT1 Mask                */
#define SIM_SOPT4_FTM0FLT1_SHIFT                 (1U)                                                /*!< SIM_SOPT4: FTM0FLT1 Position            */
#define SIM_SOPT4_FTM0FLT1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT1_SHIFT))&SIM_SOPT4_FTM0FLT1_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT2_MASK                  (0x4U)                                              /*!< SIM_SOPT4: FTM0FLT2 Mask                */
#define SIM_SOPT4_FTM0FLT2_SHIFT                 (2U)                                                /*!< SIM_SOPT4: FTM0FLT2 Position            */
#define SIM_SOPT4_FTM0FLT2(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT2_SHIFT))&SIM_SOPT4_FTM0FLT2_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT3_MASK                  (0x8U)                                              /*!< SIM_SOPT4: FTM0FLT3 Mask                */
#define SIM_SOPT4_FTM0FLT3_SHIFT                 (3U)                                                /*!< SIM_SOPT4: FTM0FLT3 Position            */
#define SIM_SOPT4_FTM0FLT3(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT3_SHIFT))&SIM_SOPT4_FTM0FLT3_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM3FLT0_MASK                  (0x1000U)                                           /*!< SIM_SOPT4: FTM3FLT0 Mask                */
#define SIM_SOPT4_FTM3FLT0_SHIFT                 (12U)                                               /*!< SIM_SOPT4: FTM3FLT0 Position            */
#define SIM_SOPT4_FTM3FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM3FLT0_SHIFT))&SIM_SOPT4_FTM3FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM3FLT1_MASK                  (0x2000U)                                           /*!< SIM_SOPT4: FTM3FLT1 Mask                */
#define SIM_SOPT4_FTM3FLT1_SHIFT                 (13U)                                               /*!< SIM_SOPT4: FTM3FLT1 Position            */
#define SIM_SOPT4_FTM3FLT1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM3FLT1_SHIFT))&SIM_SOPT4_FTM3FLT1_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM3FLT2_MASK                  (0x4000U)                                           /*!< SIM_SOPT4: FTM3FLT2 Mask                */
#define SIM_SOPT4_FTM3FLT2_SHIFT                 (14U)                                               /*!< SIM_SOPT4: FTM3FLT2 Position            */
#define SIM_SOPT4_FTM3FLT2(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM3FLT2_SHIFT))&SIM_SOPT4_FTM3FLT2_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM3FLT3_MASK                  (0x8000U)                                           /*!< SIM_SOPT4: FTM3FLT3 Mask                */
#define SIM_SOPT4_FTM3FLT3_SHIFT                 (15U)                                               /*!< SIM_SOPT4: FTM3FLT3 Position            */
#define SIM_SOPT4_FTM3FLT3(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM3FLT3_SHIFT))&SIM_SOPT4_FTM3FLT3_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CH0SRC_MASK                (0x300000U)                                         /*!< SIM_SOPT4: FTM1CH0SRC Mask              */
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               (20U)                                               /*!< SIM_SOPT4: FTM1CH0SRC Position          */
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CH0SRC_SHIFT))&SIM_SOPT4_FTM1CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CH0SRC_MASK                (0xC00000U)                                         /*!< SIM_SOPT4: FTM2CH0SRC Mask              */
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               (22U)                                               /*!< SIM_SOPT4: FTM2CH0SRC Position          */
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CH0SRC_SHIFT))&SIM_SOPT4_FTM2CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0CLKSEL_MASK                (0x1000000U)                                        /*!< SIM_SOPT4: FTM0CLKSEL Mask              */
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               (24U)                                               /*!< SIM_SOPT4: FTM0CLKSEL Position          */
#define SIM_SOPT4_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0CLKSEL_SHIFT))&SIM_SOPT4_FTM0CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CLKSEL_MASK                (0x2000000U)                                        /*!< SIM_SOPT4: FTM1CLKSEL Mask              */
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               (25U)                                               /*!< SIM_SOPT4: FTM1CLKSEL Position          */
#define SIM_SOPT4_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CLKSEL_SHIFT))&SIM_SOPT4_FTM1CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CLKSEL_MASK                (0x4000000U)                                        /*!< SIM_SOPT4: FTM2CLKSEL Mask              */
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               (26U)                                               /*!< SIM_SOPT4: FTM2CLKSEL Position          */
#define SIM_SOPT4_FTM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CLKSEL_SHIFT))&SIM_SOPT4_FTM2CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM3CLKSEL_MASK                (0x8000000U)                                        /*!< SIM_SOPT4: FTM3CLKSEL Mask              */
#define SIM_SOPT4_FTM3CLKSEL_SHIFT               (27U)                                               /*!< SIM_SOPT4: FTM3CLKSEL Position          */
#define SIM_SOPT4_FTM3CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM3CLKSEL_SHIFT))&SIM_SOPT4_FTM3CLKSEL_MASK) /*!< SIM_SOPT4                               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)                                              /*!< SIM_SOPT5: UART0TXSRC Mask              */
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)                                                /*!< SIM_SOPT5: UART0TXSRC Position          */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART0RXSRC_MASK                (0xCU)                                              /*!< SIM_SOPT5: UART0RXSRC Mask              */
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)                                                /*!< SIM_SOPT5: UART0RXSRC Position          */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)                                             /*!< SIM_SOPT5: UART1TXSRC Mask              */
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)                                                /*!< SIM_SOPT5: UART1TXSRC Position          */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1TXSRC_SHIFT))&SIM_SOPT5_UART1TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1RXSRC_MASK                (0xC0U)                                             /*!< SIM_SOPT5: UART1RXSRC Mask              */
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)                                                /*!< SIM_SOPT5: UART1RXSRC Position          */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK) /*!< SIM_SOPT5                               */
/* ------- SOPT6 Bit Fields                         ------ */
#define SIM_SOPT6_CLKDIV_MASK                    (0x7U)                                              /*!< SIM_SOPT6: CLKDIV Mask                  */
#define SIM_SOPT6_CLKDIV_SHIFT                   (0U)                                                /*!< SIM_SOPT6: CLKDIV Position              */
#define SIM_SOPT6_CLKDIV(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT6_CLKDIV_SHIFT))&SIM_SOPT6_CLKDIV_MASK) /*!< SIM_SOPT6                               */
#define SIM_SOPT6_CLKOS_MASK                     (0xF0U)                                             /*!< SIM_SOPT6: CLKOS Mask                   */
#define SIM_SOPT6_CLKOS_SHIFT                    (4U)                                                /*!< SIM_SOPT6: CLKOS Position               */
#define SIM_SOPT6_CLKOS(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT6_CLKOS_SHIFT))&SIM_SOPT6_CLKOS_MASK) /*!< SIM_SOPT6                               */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)                                              /*!< SIM_SOPT7: ADC0TRGSEL Mask              */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)                                                /*!< SIM_SOPT7: ADC0TRGSEL Position          */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC1TRGSEL_MASK                (0xF0U)                                             /*!< SIM_SOPT7: ADC1TRGSEL Mask              */
#define SIM_SOPT7_ADC1TRGSEL_SHIFT               (4U)                                                /*!< SIM_SOPT7: ADC1TRGSEL Position          */
#define SIM_SOPT7_ADC1TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1TRGSEL_SHIFT))&SIM_SOPT7_ADC1TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC2TRGSEL_MASK                (0xF00U)                                            /*!< SIM_SOPT7: ADC2TRGSEL Mask              */
#define SIM_SOPT7_ADC2TRGSEL_SHIFT               (8U)                                                /*!< SIM_SOPT7: ADC2TRGSEL Position          */
#define SIM_SOPT7_ADC2TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC2TRGSEL_SHIFT))&SIM_SOPT7_ADC2TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC3TRGSEL_MASK                (0xF000U)                                           /*!< SIM_SOPT7: ADC3TRGSEL Mask              */
#define SIM_SOPT7_ADC3TRGSEL_SHIFT               (12U)                                               /*!< SIM_SOPT7: ADC3TRGSEL Position          */
#define SIM_SOPT7_ADC3TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC3TRGSEL_SHIFT))&SIM_SOPT7_ADC3TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_CMP0WS_MASK                    (0x30000U)                                          /*!< SIM_SOPT7: CMP0WS Mask                  */
#define SIM_SOPT7_CMP0WS_SHIFT                   (16U)                                               /*!< SIM_SOPT7: CMP0WS Position              */
#define SIM_SOPT7_CMP0WS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_CMP0WS_SHIFT))&SIM_SOPT7_CMP0WS_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_CMP1WS_MASK                    (0xC0000U)                                          /*!< SIM_SOPT7: CMP1WS Mask                  */
#define SIM_SOPT7_CMP1WS_SHIFT                   (18U)                                               /*!< SIM_SOPT7: CMP1WS Position              */
#define SIM_SOPT7_CMP1WS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_CMP1WS_SHIFT))&SIM_SOPT7_CMP1WS_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_CMP2WS_MASK                    (0x300000U)                                         /*!< SIM_SOPT7: CMP2WS Mask                  */
#define SIM_SOPT7_CMP2WS_SHIFT                   (20U)                                               /*!< SIM_SOPT7: CMP2WS Position              */
#define SIM_SOPT7_CMP2WS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_CMP2WS_SHIFT))&SIM_SOPT7_CMP2WS_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_CMP3WS_MASK                    (0xC00000U)                                         /*!< SIM_SOPT7: CMP3WS Mask                  */
#define SIM_SOPT7_CMP3WS_SHIFT                   (22U)                                               /*!< SIM_SOPT7: CMP3WS Position              */
#define SIM_SOPT7_CMP3WS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_CMP3WS_SHIFT))&SIM_SOPT7_CMP3WS_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x10000000U)                                       /*!< SIM_SOPT7: ADC0ALTTRGEN Mask            */
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (28U)                                               /*!< SIM_SOPT7: ADC0ALTTRGEN Position        */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0ALTTRGEN_SHIFT))&SIM_SOPT7_ADC0ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC1ALTTRGEN_MASK              (0x20000000U)                                       /*!< SIM_SOPT7: ADC1ALTTRGEN Mask            */
#define SIM_SOPT7_ADC1ALTTRGEN_SHIFT             (29U)                                               /*!< SIM_SOPT7: ADC1ALTTRGEN Position        */
#define SIM_SOPT7_ADC1ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1ALTTRGEN_SHIFT))&SIM_SOPT7_ADC1ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC2ALTTRGEN_MASK              (0x40000000U)                                       /*!< SIM_SOPT7: ADC2ALTTRGEN Mask            */
#define SIM_SOPT7_ADC2ALTTRGEN_SHIFT             (30U)                                               /*!< SIM_SOPT7: ADC2ALTTRGEN Position        */
#define SIM_SOPT7_ADC2ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC2ALTTRGEN_SHIFT))&SIM_SOPT7_ADC2ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC3ALTTRGEN_MASK              (0x80000000U)                                       /*!< SIM_SOPT7: ADC3ALTTRGEN Mask            */
#define SIM_SOPT7_ADC3ALTTRGEN_SHIFT             (31U)                                               /*!< SIM_SOPT7: ADC3ALTTRGEN Position        */
#define SIM_SOPT7_ADC3ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC3ALTTRGEN_SHIFT))&SIM_SOPT7_ADC3ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_BOID_MASK                       (0xFU)                                              /*!< SIM_SDID: BOID Mask                     */
#define SIM_SDID_BOID_SHIFT                      (0U)                                                /*!< SIM_SDID: BOID Position                 */
#define SIM_SDID_BOID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SDID_BOID_SHIFT))&SIM_SDID_BOID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_DIEID_MASK                      (0x30U)                                             /*!< SIM_SDID: DIEID Mask                    */
#define SIM_SDID_DIEID_SHIFT                     (4U)                                                /*!< SIM_SDID: DIEID Position                */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /*!< SIM_SDID                                */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_EWM_MASK                       (0x2U)                                              /*!< SIM_SCGC5: EWM Mask                     */
#define SIM_SCGC5_EWM_SHIFT                      (1U)                                                /*!< SIM_SCGC5: EWM Position                 */
#define SIM_SCGC5_EWM(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_EWM_SHIFT))&SIM_SCGC5_EWM_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_CMT_MASK                       (0x4U)                                              /*!< SIM_SCGC5: CMT Mask                     */
#define SIM_SCGC5_CMT_SHIFT                      (2U)                                                /*!< SIM_SCGC5: CMT Position                 */
#define SIM_SCGC5_CMT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_CMT_SHIFT))&SIM_SCGC5_CMT_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_IIC0_MASK                      (0x80U)                                             /*!< SIM_SCGC5: IIC0 Mask                    */
#define SIM_SCGC5_IIC0_SHIFT                     (7U)                                                /*!< SIM_SCGC5: IIC0 Position                */
#define SIM_SCGC5_IIC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_IIC0_SHIFT))&SIM_SCGC5_IIC0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_IIC1_MASK                      (0x100U)                                            /*!< SIM_SCGC5: IIC1 Mask                    */
#define SIM_SCGC5_IIC1_SHIFT                     (8U)                                                /*!< SIM_SCGC5: IIC1 Position                */
#define SIM_SCGC5_IIC1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_IIC1_SHIFT))&SIM_SCGC5_IIC1_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_UART0_MASK                     (0x200U)                                            /*!< SIM_SCGC5: UART0 Mask                   */
#define SIM_SCGC5_UART0_SHIFT                    (9U)                                                /*!< SIM_SCGC5: UART0 Position               */
#define SIM_SCGC5_UART0(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_UART0_SHIFT))&SIM_SCGC5_UART0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_UART1_MASK                     (0x400U)                                            /*!< SIM_SCGC5: UART1 Mask                   */
#define SIM_SCGC5_UART1_SHIFT                    (10U)                                               /*!< SIM_SCGC5: UART1 Position               */
#define SIM_SCGC5_UART1(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_UART1_SHIFT))&SIM_SCGC5_UART1_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_UART2_MASK                     (0x800U)                                            /*!< SIM_SCGC5: UART2 Mask                   */
#define SIM_SCGC5_UART2_SHIFT                    (11U)                                               /*!< SIM_SCGC5: UART2 Position               */
#define SIM_SCGC5_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_UART2_SHIFT))&SIM_SCGC5_UART2_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_UART3_MASK                     (0x1000U)                                           /*!< SIM_SCGC5: UART3 Mask                   */
#define SIM_SCGC5_UART3_SHIFT                    (12U)                                               /*!< SIM_SCGC5: UART3 Position               */
#define SIM_SCGC5_UART3(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_UART3_SHIFT))&SIM_SCGC5_UART3_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_SPI0_MASK                      (0x4000U)                                           /*!< SIM_SCGC5: SPI0 Mask                    */
#define SIM_SCGC5_SPI0_SHIFT                     (14U)                                               /*!< SIM_SCGC5: SPI0 Position                */
#define SIM_SCGC5_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_SPI0_SHIFT))&SIM_SCGC5_SPI0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_SPI1_MASK                      (0x8000U)                                           /*!< SIM_SCGC5: SPI1 Mask                    */
#define SIM_SCGC5_SPI1_SHIFT                     (15U)                                               /*!< SIM_SCGC5: SPI1 Position                */
#define SIM_SCGC5_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_SPI1_SHIFT))&SIM_SCGC5_SPI1_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_ACMP0_MASK                     (0x10000U)                                          /*!< SIM_SCGC5: ACMP0 Mask                   */
#define SIM_SCGC5_ACMP0_SHIFT                    (16U)                                               /*!< SIM_SCGC5: ACMP0 Position               */
#define SIM_SCGC5_ACMP0(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_ACMP0_SHIFT))&SIM_SCGC5_ACMP0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_ACMP1_MASK                     (0x20000U)                                          /*!< SIM_SCGC5: ACMP1 Mask                   */
#define SIM_SCGC5_ACMP1_SHIFT                    (17U)                                               /*!< SIM_SCGC5: ACMP1 Position               */
#define SIM_SCGC5_ACMP1(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_ACMP1_SHIFT))&SIM_SCGC5_ACMP1_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_ACMP2_MASK                     (0x40000U)                                          /*!< SIM_SCGC5: ACMP2 Mask                   */
#define SIM_SCGC5_ACMP2_SHIFT                    (18U)                                               /*!< SIM_SCGC5: ACMP2 Position               */
#define SIM_SCGC5_ACMP2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_ACMP2_SHIFT))&SIM_SCGC5_ACMP2_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_ACMP3_MASK                     (0x80000U)                                          /*!< SIM_SCGC5: ACMP3 Mask                   */
#define SIM_SCGC5_ACMP3_SHIFT                    (19U)                                               /*!< SIM_SCGC5: ACMP3 Position               */
#define SIM_SCGC5_ACMP3(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_ACMP3_SHIFT))&SIM_SCGC5_ACMP3_MASK) /*!< SIM_SCGC5                               */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PIT_MASK                       (0x8U)                                              /*!< SIM_SCGC6: PIT Mask                     */
#define SIM_SCGC6_PIT_SHIFT                      (3U)                                                /*!< SIM_SCGC6: PIT Position                 */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PIT_SHIFT))&SIM_SCGC6_PIT_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_CRC_MASK                       (0x10U)                                             /*!< SIM_SCGC6: CRC Mask                     */
#define SIM_SCGC6_CRC_SHIFT                      (4U)                                                /*!< SIM_SCGC6: CRC Position                 */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_CRC_SHIFT))&SIM_SCGC6_CRC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB0_MASK                      (0x20U)                                             /*!< SIM_SCGC6: PDB0 Mask                    */
#define SIM_SCGC6_PDB0_SHIFT                     (5U)                                                /*!< SIM_SCGC6: PDB0 Position                */
#define SIM_SCGC6_PDB0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB0_SHIFT))&SIM_SCGC6_PDB0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB1_MASK                      (0x40U)                                             /*!< SIM_SCGC6: PDB1 Mask                    */
#define SIM_SCGC6_PDB1_SHIFT                     (6U)                                                /*!< SIM_SCGC6: PDB1 Position                */
#define SIM_SCGC6_PDB1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB1_SHIFT))&SIM_SCGC6_PDB1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB2_MASK                      (0x80U)                                             /*!< SIM_SCGC6: PDB2 Mask                    */
#define SIM_SCGC6_PDB2_SHIFT                     (7U)                                                /*!< SIM_SCGC6: PDB2 Position                */
#define SIM_SCGC6_PDB2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB2_SHIFT))&SIM_SCGC6_PDB2_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB3_MASK                      (0x100U)                                            /*!< SIM_SCGC6: PDB3 Mask                    */
#define SIM_SCGC6_PDB3_SHIFT                     (8U)                                                /*!< SIM_SCGC6: PDB3 Position                */
#define SIM_SCGC6_PDB3(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB3_SHIFT))&SIM_SCGC6_PDB3_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM0_MASK                      (0x200U)                                            /*!< SIM_SCGC6: FTM0 Mask                    */
#define SIM_SCGC6_FTM0_SHIFT                     (9U)                                                /*!< SIM_SCGC6: FTM0 Position                */
#define SIM_SCGC6_FTM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM0_SHIFT))&SIM_SCGC6_FTM0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM1_MASK                      (0x400U)                                            /*!< SIM_SCGC6: FTM1 Mask                    */
#define SIM_SCGC6_FTM1_SHIFT                     (10U)                                               /*!< SIM_SCGC6: FTM1 Position                */
#define SIM_SCGC6_FTM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM1_SHIFT))&SIM_SCGC6_FTM1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM2_MASK                      (0x800U)                                            /*!< SIM_SCGC6: FTM2 Mask                    */
#define SIM_SCGC6_FTM2_SHIFT                     (11U)                                               /*!< SIM_SCGC6: FTM2 Position                */
#define SIM_SCGC6_FTM2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM2_SHIFT))&SIM_SCGC6_FTM2_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM3_MASK                      (0x1000U)                                           /*!< SIM_SCGC6: FTM3 Mask                    */
#define SIM_SCGC6_FTM3_SHIFT                     (12U)                                               /*!< SIM_SCGC6: FTM3 Position                */
#define SIM_SCGC6_FTM3(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM3_SHIFT))&SIM_SCGC6_FTM3_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_RTC_MASK                       (0x2000U)                                           /*!< SIM_SCGC6: RTC Mask                     */
#define SIM_SCGC6_RTC_SHIFT                      (13U)                                               /*!< SIM_SCGC6: RTC Position                 */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RTC_SHIFT))&SIM_SCGC6_RTC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_TSI0_MASK                      (0x10000U)                                          /*!< SIM_SCGC6: TSI0 Mask                    */
#define SIM_SCGC6_TSI0_SHIFT                     (16U)                                               /*!< SIM_SCGC6: TSI0 Position                */
#define SIM_SCGC6_TSI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TSI0_SHIFT))&SIM_SCGC6_TSI0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PORTA_MASK                     (0x80000U)                                          /*!< SIM_SCGC6: PORTA Mask                   */
#define SIM_SCGC6_PORTA_SHIFT                    (19U)                                               /*!< SIM_SCGC6: PORTA Position               */
#define SIM_SCGC6_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PORTA_SHIFT))&SIM_SCGC6_PORTA_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PORTB_MASK                     (0x100000U)                                         /*!< SIM_SCGC6: PORTB Mask                   */
#define SIM_SCGC6_PORTB_SHIFT                    (20U)                                               /*!< SIM_SCGC6: PORTB Position               */
#define SIM_SCGC6_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PORTB_SHIFT))&SIM_SCGC6_PORTB_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PORTC_MASK                     (0x200000U)                                         /*!< SIM_SCGC6: PORTC Mask                   */
#define SIM_SCGC6_PORTC_SHIFT                    (21U)                                               /*!< SIM_SCGC6: PORTC Position               */
#define SIM_SCGC6_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PORTC_SHIFT))&SIM_SCGC6_PORTC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PORTD_MASK                     (0x400000U)                                         /*!< SIM_SCGC6: PORTD Mask                   */
#define SIM_SCGC6_PORTD_SHIFT                    (22U)                                               /*!< SIM_SCGC6: PORTD Position               */
#define SIM_SCGC6_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PORTD_SHIFT))&SIM_SCGC6_PORTD_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PORTE_MASK                     (0x800000U)                                         /*!< SIM_SCGC6: PORTE Mask                   */
#define SIM_SCGC6_PORTE_SHIFT                    (23U)                                               /*!< SIM_SCGC6: PORTE Position               */
#define SIM_SCGC6_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PORTE_SHIFT))&SIM_SCGC6_PORTE_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /*!< SIM_SCGC6: ADC0 Mask                    */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /*!< SIM_SCGC6: ADC0 Position                */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC1_MASK                      (0x10000000U)                                       /*!< SIM_SCGC6: ADC1 Mask                    */
#define SIM_SCGC6_ADC1_SHIFT                     (28U)                                               /*!< SIM_SCGC6: ADC1 Position                */
#define SIM_SCGC6_ADC1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC1_SHIFT))&SIM_SCGC6_ADC1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC2_MASK                      (0x20000000U)                                       /*!< SIM_SCGC6: ADC2 Mask                    */
#define SIM_SCGC6_ADC2_SHIFT                     (29U)                                               /*!< SIM_SCGC6: ADC2 Position                */
#define SIM_SCGC6_ADC2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC2_SHIFT))&SIM_SCGC6_ADC2_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC3_MASK                      (0x40000000U)                                       /*!< SIM_SCGC6: ADC3 Mask                    */
#define SIM_SCGC6_ADC3_SHIFT                     (30U)                                               /*!< SIM_SCGC6: ADC3 Position                */
#define SIM_SCGC6_ADC3(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC3_SHIFT))&SIM_SCGC6_ADC3_MASK) /*!< SIM_SCGC6                               */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_FLEXBUS_MASK                   (0x1U)                                              /*!< SIM_SCGC7: FLEXBUS Mask                 */
#define SIM_SCGC7_FLEXBUS_SHIFT                  (0U)                                                /*!< SIM_SCGC7: FLEXBUS Position             */
#define SIM_SCGC7_FLEXBUS(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_FLEXBUS_SHIFT))&SIM_SCGC7_FLEXBUS_MASK) /*!< SIM_SCGC7                               */
#define SIM_SCGC7_DMA_MASK                       (0x2U)                                              /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      (1U)                                                /*!< SIM_SCGC7: DMA Position                 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_DMA_SHIFT))&SIM_SCGC7_DMA_MASK) /*!< SIM_SCGC7                               */
#define SIM_SCGC7_MPU_MASK                       (0x4U)                                              /*!< SIM_SCGC7: MPU Mask                     */
#define SIM_SCGC7_MPU_SHIFT                      (2U)                                                /*!< SIM_SCGC7: MPU Position                 */
#define SIM_SCGC7_MPU(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_MPU_SHIFT))&SIM_SCGC7_MPU_MASK) /*!< SIM_SCGC7                               */
#define SIM_SCGC7_IEVT_MASK                      (0x8U)                                              /*!< SIM_SCGC7: IEVT Mask                    */
#define SIM_SCGC7_IEVT_SHIFT                     (3U)                                                /*!< SIM_SCGC7: IEVT Position                */
#define SIM_SCGC7_IEVT(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_IEVT_SHIFT))&SIM_SCGC7_IEVT_MASK) /*!< SIM_SCGC7                               */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV5_MASK                 (0x3000U)                                           /*!< SIM_CLKDIV1: OUTDIV5 Mask               */
#define SIM_CLKDIV1_OUTDIV5_SHIFT                (12U)                                               /*!< SIM_CLKDIV1: OUTDIV5 Position           */
#define SIM_CLKDIV1_OUTDIV5(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV5_SHIFT))&SIM_CLKDIV1_OUTDIV5_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x30000U)                                          /*!< SIM_CLKDIV1: OUTDIV4 Mask               */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /*!< SIM_CLKDIV1: OUTDIV4 Position           */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV3_MASK                 (0x300000U)                                         /*!< SIM_CLKDIV1: OUTDIV3 Mask               */
#define SIM_CLKDIV1_OUTDIV3_SHIFT                (20U)                                               /*!< SIM_CLKDIV1: OUTDIV3 Position           */
#define SIM_CLKDIV1_OUTDIV3(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV3_SHIFT))&SIM_CLKDIV1_OUTDIV3_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0x3000000U)                                        /*!< SIM_CLKDIV1: OUTDIV2 Mask               */
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)                                               /*!< SIM_CLKDIV1: OUTDIV2 Position           */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV2_SHIFT))&SIM_CLKDIV1_OUTDIV2_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0x30000000U)                                       /*!< SIM_CLKDIV1: OUTDIV1 Mask               */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /*!< SIM_CLKDIV1: OUTDIV1 Position           */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK) /*!< SIM_CLKDIV1                             */
/* ------- UIDH Bit Fields                          ------ */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDH: UID Mask                      */
#define SIM_UIDH_UID_SHIFT                       (0U)                                                /*!< SIM_UIDH: UID Position                  */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDH_UID_SHIFT))&SIM_UIDH_UID_MASK) /*!< SIM_UIDH                                */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDMH: UID Mask                     */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /*!< SIM_UIDMH: UID Position                 */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK) /*!< SIM_UIDMH                               */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDML: UID Mask                     */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /*!< SIM_UIDML: UID Position                 */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK) /*!< SIM_UIDML                               */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDL: UID Mask                      */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /*!< SIM_UIDL: UID Position                  */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK) /*!< SIM_UIDL                                */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40032000UL //!< Peripheral base address
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
/* ================           SMC (file:SMC_MKE14D7)               ================ */
/* ================================================================================ */

/**
 * @brief System mode controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: SMC Power Mode Protection Register                           */
   __IO uint8_t   PMCTRL;                       /**< 0001: SMC Power Mode Control Register                              */
        uint8_t   RESERVED_0;                  
   __I  uint8_t   PMSTAT;                       /**< 0003: SMC Power Mode Status Register                               */
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
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /*!< SMC_PMPROT: AVLP Position               */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK) /*!< SMC_PMPROT                              */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK) /*!< SMC_PMCTRL                              */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_RUN_MASK                      (0x1U)                                              /*!< SMC_PMSTAT: RUN Mask                    */
#define SMC_PMSTAT_RUN_SHIFT                     (0U)                                                /*!< SMC_PMSTAT: RUN Position                */
#define SMC_PMSTAT_RUN(x)                        (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_RUN_SHIFT))&SMC_PMSTAT_RUN_MASK) /*!< SMC_PMSTAT                              */
#define SMC_PMSTAT_STOP_MASK                     (0x2U)                                              /*!< SMC_PMSTAT: STOP Mask                   */
#define SMC_PMSTAT_STOP_SHIFT                    (1U)                                                /*!< SMC_PMSTAT: STOP Position               */
#define SMC_PMSTAT_STOP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_STOP_SHIFT))&SMC_PMSTAT_STOP_MASK) /*!< SMC_PMSTAT                              */
#define SMC_PMSTAT_VLPS_MASK                     (0x10U)                                             /*!< SMC_PMSTAT: VLPS Mask                   */
#define SMC_PMSTAT_VLPS_SHIFT                    (4U)                                                /*!< SMC_PMSTAT: VLPS Position               */
#define SMC_PMSTAT_VLPS(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_VLPS_SHIFT))&SMC_PMSTAT_VLPS_MASK) /*!< SMC_PMSTAT                              */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x40056000UL //!< Peripheral base address
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
/* ================           SPI0 (file:SPI0_MKE16Bit)            ================ */
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
   __IO uint8_t   C1;                           /**< 0000: Control register 1                                           */
   __IO uint8_t   C2;                           /**< 0001: Control register 2                                           */
   __IO uint8_t   BR;                           /**< 0002: Baud rate register                                           */
   __I  uint8_t   S;                            /**< 0003: Status register                                              */
   __IO uint8_t   DH;                           /**< 0004: Data register high                                           */
   __IO uint8_t   DL;                           /**< 0005: Data register low                                            */
   __IO uint8_t   MH;                           /**< 0006: Match register high                                          */
   __IO uint8_t   ML;                           /**< 0007: Match register low                                           */
   __IO uint8_t   C3;                           /**< 0008: Control register 3                                           */
   __IO uint8_t   CI;                           /**< 0009: Clear interrupt register                                     */
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
/* ------- C1 Bit Fields                            ------ */
#define SPI_C1_LSBFE_MASK                        (0x1U)                                              /*!< SPI0_C1: LSBFE Mask                     */
#define SPI_C1_LSBFE_SHIFT                       (0U)                                                /*!< SPI0_C1: LSBFE Position                 */
#define SPI_C1_LSBFE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_LSBFE_SHIFT))&SPI_C1_LSBFE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SSOE_MASK                         (0x2U)                                              /*!< SPI0_C1: SSOE Mask                      */
#define SPI_C1_SSOE_SHIFT                        (1U)                                                /*!< SPI0_C1: SSOE Position                  */
#define SPI_C1_SSOE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SSOE_SHIFT))&SPI_C1_SSOE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_MODE_MASK                         (0xCU)                                              /*!< SPI0_C1: MODE Mask                      */
#define SPI_C1_MODE_SHIFT                        (2U)                                                /*!< SPI0_C1: MODE Position                  */
#define SPI_C1_MODE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MODE_SHIFT))&SPI_C1_MODE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_CPHA_MASK                         (0x4U)                                              /*!< SPI0_C1: CPHA Mask                      */
#define SPI_C1_CPHA_SHIFT                        (2U)                                                /*!< SPI0_C1: CPHA Position                  */
#define SPI_C1_CPHA(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPHA_SHIFT))&SPI_C1_CPHA_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_CPOL_MASK                         (0x8U)                                              /*!< SPI0_C1: CPOL Mask                      */
#define SPI_C1_CPOL_SHIFT                        (3U)                                                /*!< SPI0_C1: CPOL Position                  */
#define SPI_C1_CPOL(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPOL_SHIFT))&SPI_C1_CPOL_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_MSTR_MASK                         (0x10U)                                             /*!< SPI0_C1: MSTR Mask                      */
#define SPI_C1_MSTR_SHIFT                        (4U)                                                /*!< SPI0_C1: MSTR Position                  */
#define SPI_C1_MSTR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MSTR_SHIFT))&SPI_C1_MSTR_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPTIE_MASK                        (0x20U)                                             /*!< SPI0_C1: SPTIE Mask                     */
#define SPI_C1_SPTIE_SHIFT                       (5U)                                                /*!< SPI0_C1: SPTIE Position                 */
#define SPI_C1_SPTIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPTIE_SHIFT))&SPI_C1_SPTIE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPE_MASK                          (0x40U)                                             /*!< SPI0_C1: SPE Mask                       */
#define SPI_C1_SPE_SHIFT                         (6U)                                                /*!< SPI0_C1: SPE Position                   */
#define SPI_C1_SPE(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPE_SHIFT))&SPI_C1_SPE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPIE_MASK                         (0x80U)                                             /*!< SPI0_C1: SPIE Mask                      */
#define SPI_C1_SPIE_SHIFT                        (7U)                                                /*!< SPI0_C1: SPIE Position                  */
#define SPI_C1_SPIE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPIE_SHIFT))&SPI_C1_SPIE_MASK) /*!< SPI0_C1                                 */
/* ------- C2 Bit Fields                            ------ */
#define SPI_C2_SPC0_MASK                         (0x1U)                                              /*!< SPI0_C2: SPC0 Mask                      */
#define SPI_C2_SPC0_SHIFT                        (0U)                                                /*!< SPI0_C2: SPC0 Position                  */
#define SPI_C2_SPC0(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPC0_SHIFT))&SPI_C2_SPC0_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPISWAI_MASK                      (0x2U)                                              /*!< SPI0_C2: SPISWAI Mask                   */
#define SPI_C2_SPISWAI_SHIFT                     (1U)                                                /*!< SPI0_C2: SPISWAI Position               */
#define SPI_C2_SPISWAI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPISWAI_SHIFT))&SPI_C2_SPISWAI_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_RXDMAE_MASK                       (0x4U)                                              /*!< SPI0_C2: RXDMAE Mask                    */
#define SPI_C2_RXDMAE_SHIFT                      (2U)                                                /*!< SPI0_C2: RXDMAE Position                */
#define SPI_C2_RXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_RXDMAE_SHIFT))&SPI_C2_RXDMAE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_BIDIROE_MASK                      (0x8U)                                              /*!< SPI0_C2: BIDIROE Mask                   */
#define SPI_C2_BIDIROE_SHIFT                     (3U)                                                /*!< SPI0_C2: BIDIROE Position               */
#define SPI_C2_BIDIROE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_BIDIROE_SHIFT))&SPI_C2_BIDIROE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_MODFEN_MASK                       (0x10U)                                             /*!< SPI0_C2: MODFEN Mask                    */
#define SPI_C2_MODFEN_SHIFT                      (4U)                                                /*!< SPI0_C2: MODFEN Position                */
#define SPI_C2_MODFEN(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_MODFEN_SHIFT))&SPI_C2_MODFEN_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_TXDMAE_MASK                       (0x20U)                                             /*!< SPI0_C2: TXDMAE Mask                    */
#define SPI_C2_TXDMAE_SHIFT                      (5U)                                                /*!< SPI0_C2: TXDMAE Position                */
#define SPI_C2_TXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_TXDMAE_SHIFT))&SPI_C2_TXDMAE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPIMODE_MASK                      (0x40U)                                             /*!< SPI0_C2: SPIMODE Mask                   */
#define SPI_C2_SPIMODE_SHIFT                     (6U)                                                /*!< SPI0_C2: SPIMODE Position               */
#define SPI_C2_SPIMODE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPIMODE_SHIFT))&SPI_C2_SPIMODE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPMIE_MASK                        (0x80U)                                             /*!< SPI0_C2: SPMIE Mask                     */
#define SPI_C2_SPMIE_SHIFT                       (7U)                                                /*!< SPI0_C2: SPMIE Position                 */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPMIE_SHIFT))&SPI_C2_SPMIE_MASK) /*!< SPI0_C2                                 */
/* ------- BR Bit Fields                            ------ */
#define SPI_BR_SPR_MASK                          (0xFU)                                              /*!< SPI0_BR: SPR Mask                       */
#define SPI_BR_SPR_SHIFT                         (0U)                                                /*!< SPI0_BR: SPR Position                   */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /*!< SPI0_BR                                 */
#define SPI_BR_SPPR_MASK                         (0x70U)                                             /*!< SPI0_BR: SPPR Mask                      */
#define SPI_BR_SPPR_SHIFT                        (4U)                                                /*!< SPI0_BR: SPPR Position                  */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /*!< SPI0_BR                                 */
/* ------- S Bit Fields                             ------ */
#define SPI_S_RFIFOEF_MASK                       (0x1U)                                              /*!< SPI0_S: RFIFOEF Mask                    */
#define SPI_S_RFIFOEF_SHIFT                      (0U)                                                /*!< SPI0_S: RFIFOEF Position                */
#define SPI_S_RFIFOEF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RFIFOEF_SHIFT))&SPI_S_RFIFOEF_MASK) /*!< SPI0_S                                  */
#define SPI_S_TXFULLF_MASK                       (0x2U)                                              /*!< SPI0_S: TXFULLF Mask                    */
#define SPI_S_TXFULLF_SHIFT                      (1U)                                                /*!< SPI0_S: TXFULLF Position                */
#define SPI_S_TXFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TXFULLF_SHIFT))&SPI_S_TXFULLF_MASK) /*!< SPI0_S                                  */
#define SPI_S_TNEAREF_MASK                       (0x4U)                                              /*!< SPI0_S: TNEAREF Mask                    */
#define SPI_S_TNEAREF_SHIFT                      (2U)                                                /*!< SPI0_S: TNEAREF Position                */
#define SPI_S_TNEAREF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TNEAREF_SHIFT))&SPI_S_TNEAREF_MASK) /*!< SPI0_S                                  */
#define SPI_S_RNFULLF_MASK                       (0x8U)                                              /*!< SPI0_S: RNFULLF Mask                    */
#define SPI_S_RNFULLF_SHIFT                      (3U)                                                /*!< SPI0_S: RNFULLF Position                */
#define SPI_S_RNFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RNFULLF_SHIFT))&SPI_S_RNFULLF_MASK) /*!< SPI0_S                                  */
#define SPI_S_MODF_MASK                          (0x10U)                                             /*!< SPI0_S: MODF Mask                       */
#define SPI_S_MODF_SHIFT                         (4U)                                                /*!< SPI0_S: MODF Position                   */
#define SPI_S_MODF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_MODF_SHIFT))&SPI_S_MODF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPTEF_MASK                         (0x20U)                                             /*!< SPI0_S: SPTEF Mask                      */
#define SPI_S_SPTEF_SHIFT                        (5U)                                                /*!< SPI0_S: SPTEF Position                  */
#define SPI_S_SPTEF(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_S_SPTEF_SHIFT))&SPI_S_SPTEF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPMF_MASK                          (0x40U)                                             /*!< SPI0_S: SPMF Mask                       */
#define SPI_S_SPMF_SHIFT                         (6U)                                                /*!< SPI0_S: SPMF Position                   */
#define SPI_S_SPMF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPMF_SHIFT))&SPI_S_SPMF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPRF_MASK                          (0x80U)                                             /*!< SPI0_S: SPRF Mask                       */
#define SPI_S_SPRF_SHIFT                         (7U)                                                /*!< SPI0_S: SPRF Position                   */
#define SPI_S_SPRF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPRF_SHIFT))&SPI_S_SPRF_MASK) /*!< SPI0_S                                  */
/* ------- DH Bit Fields                            ------ */
#define SPI_DH_Bits_MASK                         (0xFFU)                                             /*!< SPI0_DH: Bits Mask                      */
#define SPI_DH_Bits_SHIFT                        (0U)                                                /*!< SPI0_DH: Bits Position                  */
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK) /*!< SPI0_DH                                 */
/* ------- DL Bit Fields                            ------ */
#define SPI_DL_Bits_MASK                         (0xFFU)                                             /*!< SPI0_DL: Bits Mask                      */
#define SPI_DL_Bits_SHIFT                        (0U)                                                /*!< SPI0_DL: Bits Position                  */
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK) /*!< SPI0_DL                                 */
/* ------- MH Bit Fields                            ------ */
#define SPI_MH_Bits_MASK                         (0xFFU)                                             /*!< SPI0_MH: Bits Mask                      */
#define SPI_MH_Bits_SHIFT                        (0U)                                                /*!< SPI0_MH: Bits Position                  */
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK) /*!< SPI0_MH                                 */
/* ------- ML Bit Fields                            ------ */
#define SPI_ML_Bits_MASK                         (0xFFU)                                             /*!< SPI0_ML: Bits Mask                      */
#define SPI_ML_Bits_SHIFT                        (0U)                                                /*!< SPI0_ML: Bits Position                  */
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK) /*!< SPI0_ML                                 */
/* ------- C3 Bit Fields                            ------ */
#define SPI_C3_FIFOMODE_MASK                     (0x1U)                                              /*!< SPI0_C3: FIFOMODE Mask                  */
#define SPI_C3_FIFOMODE_SHIFT                    (0U)                                                /*!< SPI0_C3: FIFOMODE Position              */
#define SPI_C3_FIFOMODE(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_FIFOMODE_SHIFT))&SPI_C3_FIFOMODE_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_RNFULLIEN_MASK                    (0x2U)                                              /*!< SPI0_C3: RNFULLIEN Mask                 */
#define SPI_C3_RNFULLIEN_SHIFT                   (1U)                                                /*!< SPI0_C3: RNFULLIEN Position             */
#define SPI_C3_RNFULLIEN(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLIEN_SHIFT))&SPI_C3_RNFULLIEN_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_TNEARIEN_MASK                     (0x4U)                                              /*!< SPI0_C3: TNEARIEN Mask                  */
#define SPI_C3_TNEARIEN_SHIFT                    (2U)                                                /*!< SPI0_C3: TNEARIEN Position              */
#define SPI_C3_TNEARIEN(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEARIEN_SHIFT))&SPI_C3_TNEARIEN_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_INTCLR_MASK                       (0x8U)                                              /*!< SPI0_C3: INTCLR Mask                    */
#define SPI_C3_INTCLR_SHIFT                      (3U)                                                /*!< SPI0_C3: INTCLR Position                */
#define SPI_C3_INTCLR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C3_INTCLR_SHIFT))&SPI_C3_INTCLR_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x10U)                                             /*!< SPI0_C3: RNFULLF_MARK Mask              */
#define SPI_C3_RNFULLF_MARK_SHIFT                (4U)                                                /*!< SPI0_C3: RNFULLF_MARK Position          */
#define SPI_C3_RNFULLF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLF_MARK_SHIFT))&SPI_C3_RNFULLF_MARK_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x20U)                                             /*!< SPI0_C3: TNEAREF_MARK Mask              */
#define SPI_C3_TNEAREF_MARK_SHIFT                (5U)                                                /*!< SPI0_C3: TNEAREF_MARK Position          */
#define SPI_C3_TNEAREF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEAREF_MARK_SHIFT))&SPI_C3_TNEAREF_MARK_MASK) /*!< SPI0_C3                                 */
/* ------- CI Bit Fields                            ------ */
#define SPI_CI_SPRFCI_MASK                       (0x1U)                                              /*!< SPI0_CI: SPRFCI Mask                    */
#define SPI_CI_SPRFCI_SHIFT                      (0U)                                                /*!< SPI0_CI: SPRFCI Position                */
#define SPI_CI_SPRFCI(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPRFCI_SHIFT))&SPI_CI_SPRFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_SPTEFCI_MASK                      (0x2U)                                              /*!< SPI0_CI: SPTEFCI Mask                   */
#define SPI_CI_SPTEFCI_SHIFT                     (1U)                                                /*!< SPI0_CI: SPTEFCI Position               */
#define SPI_CI_SPTEFCI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPTEFCI_SHIFT))&SPI_CI_SPTEFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RNFULLFCI_MASK                    (0x4U)                                              /*!< SPI0_CI: RNFULLFCI Mask                 */
#define SPI_CI_RNFULLFCI_SHIFT                   (2U)                                                /*!< SPI0_CI: RNFULLFCI Position             */
#define SPI_CI_RNFULLFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_RNFULLFCI_SHIFT))&SPI_CI_RNFULLFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TNEAREFCI_MASK                    (0x8U)                                              /*!< SPI0_CI: TNEAREFCI Mask                 */
#define SPI_CI_TNEAREFCI_SHIFT                   (3U)                                                /*!< SPI0_CI: TNEAREFCI Position             */
#define SPI_CI_TNEAREFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_TNEAREFCI_SHIFT))&SPI_CI_TNEAREFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RXFOF_MASK                        (0x10U)                                             /*!< SPI0_CI: RXFOF Mask                     */
#define SPI_CI_RXFOF_SHIFT                       (4U)                                                /*!< SPI0_CI: RXFOF Position                 */
#define SPI_CI_RXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFOF_SHIFT))&SPI_CI_RXFOF_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TXFOF_MASK                        (0x20U)                                             /*!< SPI0_CI: TXFOF Mask                     */
#define SPI_CI_TXFOF_SHIFT                       (5U)                                                /*!< SPI0_CI: TXFOF Position                 */
#define SPI_CI_TXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFOF_SHIFT))&SPI_CI_TXFOF_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RXFERR_MASK                       (0x40U)                                             /*!< SPI0_CI: RXFERR Mask                    */
#define SPI_CI_RXFERR_SHIFT                      (6U)                                                /*!< SPI0_CI: RXFERR Position                */
#define SPI_CI_RXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFERR_SHIFT))&SPI_CI_RXFERR_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TXFERR_MASK                       (0x80U)                                             /*!< SPI0_CI: TXFERR Mask                    */
#define SPI_CI_TXFERR_SHIFT                      (7U)                                                /*!< SPI0_CI: TXFERR Position                */
#define SPI_CI_TXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFERR_SHIFT))&SPI_CI_TXFERR_MASK) /*!< SPI0_CI                                 */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x4004E000UL //!< Peripheral base address
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
#define SPI1_BasePtr                   0x4004F000UL //!< Peripheral base address
#define SPI1                           ((SPI_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYST_Peripheral_access_layer_GROUP SYST Peripheral Access Layer
* @brief C Struct for SYST
* @{
*/

/* ================================================================================ */
/* ================           SYST (file:SYST)                     ================ */
/* ================================================================================ */

/**
 * @brief System timer
 */
/**
* @addtogroup SYST_structs_GROUP SYST struct
* @brief Struct for SYST
* @{
*/
typedef struct {                                /*       SYST Structure                                               */
   __IO uint32_t  CSR;                          /**< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /**< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /**< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /**< 000C: Calibration Value Register                                   */
} SYST_Type;

/**
 * @} */ /* End group SYST_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYST_Register_Masks_GROUP SYST Register Masks
* @brief Register Masks for SYST
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define SYST_CSR_ENABLE_MASK                     (0x1U)                                              /*!< SYST_CSR: ENABLE Mask                   */
#define SYST_CSR_ENABLE_SHIFT                    (0U)                                                /*!< SYST_CSR: ENABLE Position               */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CSR_ENABLE_SHIFT))&SYST_CSR_ENABLE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_TICKINT_MASK                    (0x2U)                                              /*!< SYST_CSR: TICKINT Mask                  */
#define SYST_CSR_TICKINT_SHIFT                   (1U)                                                /*!< SYST_CSR: TICKINT Position              */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CSR_TICKINT_SHIFT))&SYST_CSR_TICKINT_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_CLKSOURCE_MASK                  (0x4U)                                              /*!< SYST_CSR: CLKSOURCE Mask                */
#define SYST_CSR_CLKSOURCE_SHIFT                 (2U)                                                /*!< SYST_CSR: CLKSOURCE Position            */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_CLKSOURCE_SHIFT))&SYST_CSR_CLKSOURCE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x10000U)                                          /*!< SYST_CSR: COUNTFLAG Mask                */
#define SYST_CSR_COUNTFLAG_SHIFT                 (16U)                                               /*!< SYST_CSR: COUNTFLAG Position            */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_COUNTFLAG_SHIFT))&SYST_CSR_COUNTFLAG_MASK) /*!< SYST_CSR                                */
/* ------- RVR Bit Fields                           ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFU)                                         /*!< SYST_RVR: RELOAD Mask                   */
#define SYST_RVR_RELOAD_SHIFT                    (0U)                                                /*!< SYST_RVR: RELOAD Position               */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_RVR_RELOAD_SHIFT))&SYST_RVR_RELOAD_MASK) /*!< SYST_RVR                                */
/* ------- CVR Bit Fields                           ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFU)                                         /*!< SYST_CVR: CURRENT Mask                  */
#define SYST_CVR_CURRENT_SHIFT                   (0U)                                                /*!< SYST_CVR: CURRENT Position              */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CVR_CURRENT_SHIFT))&SYST_CVR_CURRENT_MASK) /*!< SYST_CVR                                */
/* ------- CALIB Bit Fields                         ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFU)                                         /*!< SYST_CALIB: TENMS Mask                  */
#define SYST_CALIB_TENMS_SHIFT                   (0U)                                                /*!< SYST_CALIB: TENMS Position              */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_TENMS_SHIFT))&SYST_CALIB_TENMS_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_SKEW_MASK                     (0x40000000U)                                       /*!< SYST_CALIB: SKEW Mask                   */
#define SYST_CALIB_SKEW_SHIFT                    (30U)                                               /*!< SYST_CALIB: SKEW Position               */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_SKEW_SHIFT))&SYST_CALIB_SKEW_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_NOREF_MASK                    (0x80000000U)                                       /*!< SYST_CALIB: NOREF Mask                  */
#define SYST_CALIB_NOREF_SHIFT                   (31U)                                               /*!< SYST_CALIB: NOREF Position              */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_NOREF_SHIFT))&SYST_CALIB_NOREF_MASK) /*!< SYST_CALIB                              */
/**
 * @} */ /* End group SYST_Register_Masks_GROUP 
 */

/* SYST - Peripheral instance base addresses */
#define SYST_BasePtr                   0xE000E010UL //!< Peripheral base address
#define SYST                           ((SYST_Type *) SYST_BasePtr) //!< Freescale base pointer
#define SYST_BASE_PTR                  (SYST) //!< Freescale style base pointer
/**
 * @} */ /* End group SYST_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKE14D7)           ================ */
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
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
} UART_Type;

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
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /*!< UART0_BDH: RXEDGIE Position             */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /*!< UART0_BDH                               */
#define UART_BDH_LBKDIE_MASK                     (0x80U)                                             /*!< UART0_BDH: LBKDIE Mask                  */
#define UART_BDH_LBKDIE_SHIFT                    (7U)                                                /*!< UART0_BDH: LBKDIE Position              */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_BDH_LBKDIE_SHIFT))&UART_BDH_LBKDIE_MASK) /*!< UART0_BDH                               */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART0_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x1U)                                              /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         (0U)                                                /*!< UART0_C1: PT Position                   */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /*!< UART0_C1                                */
#define UART_C1_PE_MASK                          (0x2U)                                              /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         (1U)                                                /*!< UART0_C1: PE Position                   */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /*!< UART0_C1                                */
#define UART_C1_ILT_MASK                         (0x4U)                                              /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        (2U)                                                /*!< UART0_C1: ILT Position                  */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /*!< UART0_C1                                */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /*!< UART0_C1: WAKE Position                 */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /*!< UART0_C1                                */
#define UART_C1_M_MASK                           (0x10U)                                             /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          (4U)                                                /*!< UART0_C1: M Position                    */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /*!< UART0_C1                                */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /*!< UART0_C1: RSRC Position                 */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /*!< UART0_C1                                */
#define UART_C1_UARTSWAI_MASK                    (0x40U)                                             /*!< UART0_C1: UARTSWAI Mask                 */
#define UART_C1_UARTSWAI_SHIFT                   (6U)                                                /*!< UART0_C1: UARTSWAI Position             */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C1_UARTSWAI_SHIFT))&UART_C1_UARTSWAI_MASK) /*!< UART0_C1                                */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /*!< UART0_C1: LOOPS Position                */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /*!< UART0_C1                                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        (0U)                                                /*!< UART0_C2: SBK Position                  */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /*!< UART0_C2                                */
#define UART_C2_RWU_MASK                         (0x2U)                                              /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        (1U)                                                /*!< UART0_C2: RWU Position                  */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /*!< UART0_C2                                */
#define UART_C2_RE_MASK                          (0x4U)                                              /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         (2U)                                                /*!< UART0_C2: RE Position                   */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /*!< UART0_C2                                */
#define UART_C2_TE_MASK                          (0x8U)                                              /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         (3U)                                                /*!< UART0_C2: TE Position                   */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /*!< UART0_C2                                */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /*!< UART0_C2: ILIE Position                 */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /*!< UART0_C2                                */
#define UART_C2_RIE_MASK                         (0x20U)                                             /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        (5U)                                                /*!< UART0_C2: RIE Position                  */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TIE_MASK                         (0x80U)                                             /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        (7U)                                                /*!< UART0_C2: TIE Position                  */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /*!< UART0_C2                                */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x1U)                                              /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         (0U)                                                /*!< UART0_S1: PF Position                   */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /*!< UART0_S1                                */
#define UART_S1_FE_MASK                          (0x2U)                                              /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         (1U)                                                /*!< UART0_S1: FE Position                   */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /*!< UART0_S1                                */
#define UART_S1_NF_MASK                          (0x4U)                                              /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         (2U)                                                /*!< UART0_S1: NF Position                   */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /*!< UART0_S1                                */
#define UART_S1_OR_MASK                          (0x8U)                                              /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         (3U)                                                /*!< UART0_S1: OR Position                   */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /*!< UART0_S1                                */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /*!< UART0_S1: IDLE Position                 */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /*!< UART0_S1                                */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /*!< UART0_S1: RDRF Position                 */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /*!< UART0_S1                                */
#define UART_S1_TC_MASK                          (0x40U)                                             /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         (6U)                                                /*!< UART0_S1: TC Position                   */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /*!< UART0_S1                                */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /*!< UART0_S1: TDRE Position                 */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /*!< UART0_S1                                */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        (0U)                                                /*!< UART0_S2: RAF Position                  */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDE_MASK                       (0x2U)                                              /*!< UART0_S2: LBKDE Mask                    */
#define UART_S2_LBKDE_SHIFT                      (1U)                                                /*!< UART0_S2: LBKDE Position                */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDE_SHIFT))&UART_S2_LBKDE_MASK) /*!< UART0_S2                                */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /*!< UART0_S2: BRK13 Position                */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /*!< UART0_S2                                */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /*!< UART0_S2: RWUID Position                */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /*!< UART0_S2                                */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /*!< UART0_S2: RXINV Position                */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /*!< UART0_S2                                */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /*!< UART0_S2: MSBF Position                 */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /*!< UART0_S2                                */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /*!< UART0_S2: RXEDGIF Position              */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDIF_MASK                      (0x80U)                                             /*!< UART0_S2: LBKDIF Mask                   */
#define UART_S2_LBKDIF_SHIFT                     (7U)                                                /*!< UART0_S2: LBKDIF Position               */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDIF_SHIFT))&UART_S2_LBKDIF_MASK) /*!< UART0_S2                                */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /*!< UART0_C3: PEIE Position                 */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /*!< UART0_C3: FEIE Position                 */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /*!< UART0_C3: NEIE Position                 */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /*!< UART0_C3: ORIE Position                 */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /*!< UART0_C3                                */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /*!< UART0_C3                                */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /*!< UART0_C3: TXDIR Position                */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /*!< UART0_C3                                */
#define UART_C3_T8_MASK                          (0x40U)                                             /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         (6U)                                                /*!< UART0_C3: T8 Position                   */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /*!< UART0_C3                                */
#define UART_C3_R8_MASK                          (0x80U)                                             /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         (7U)                                                /*!< UART0_C3: R8 Position                   */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /*!< UART0_C3                                */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFU)                                             /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          (0U)                                                /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART0_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         (0U)                                                /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART0_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FU)                                             /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       (0U)                                                /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x20U)                                             /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        (5U)                                                /*!< UART0_C4: M10 Position                  */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /*!< UART0_C4: MAEN1 Position                */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /*!< UART0_C4                                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_LBKDDMAS_MASK                    (0x8U)                                              /*!< UART0_C5: LBKDDMAS Mask                 */
#define UART_C5_LBKDDMAS_SHIFT                   (3U)                                                /*!< UART0_C5: LBKDDMAS Position             */
#define UART_C5_LBKDDMAS(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C5_LBKDDMAS_SHIFT))&UART_C5_LBKDDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_ILDMAS_MASK                      (0x10U)                                             /*!< UART0_C5: ILDMAS Mask                   */
#define UART_C5_ILDMAS_SHIFT                     (4U)                                                /*!< UART0_C5: ILDMAS Position               */
#define UART_C5_ILDMAS(x)                        (((uint8_t)(((uint8_t)(x))<<UART_C5_ILDMAS_SHIFT))&UART_C5_ILDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_RDMAS_MASK                       (0x20U)                                             /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      (5U)                                                /*!< UART0_C5: RDMAS Position                */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAS_SHIFT))&UART_C5_RDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_TCDMAS_MASK                      (0x40U)                                             /*!< UART0_C5: TCDMAS Mask                   */
#define UART_C5_TCDMAS_SHIFT                     (6U)                                                /*!< UART0_C5: TCDMAS Position               */
#define UART_C5_TCDMAS(x)                        (((uint8_t)(((uint8_t)(x))<<UART_C5_TCDMAS_SHIFT))&UART_C5_TCDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_TDMAS_MASK                       (0x80U)                                             /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      (7U)                                                /*!< UART0_C5: TDMAS Position                */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAS_SHIFT))&UART_C5_TDMAS_MASK) /*!< UART0_C5                                */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x40U)                                             /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    (6U)                                                /*!< UART0_ED: PARITYE Position              */
#define UART_ED_PARITYE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_ED_PARITYE_SHIFT))&UART_ED_PARITYE_MASK) /*!< UART0_ED                                */
#define UART_ED_NOISY_MASK                       (0x80U)                                             /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      (7U)                                                /*!< UART0_ED: NOISY Position                */
#define UART_ED_NOISY(x)                         (((uint8_t)(((uint8_t)(x))<<UART_ED_NOISY_SHIFT))&UART_ED_NOISY_MASK) /*!< UART0_ED                                */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x1U)                                              /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  (0U)                                                /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXCTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXCTSE_SHIFT))&UART_MODEM_TXCTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSE_MASK                   (0x2U)                                              /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  (1U)                                                /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSE_SHIFT))&UART_MODEM_TXRTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSPOL_MASK                 (0x4U)                                              /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                (2U)                                                /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_TXRTSPOL(x)                   (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSPOL_SHIFT))&UART_MODEM_TXRTSPOL_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_RXRTSE_MASK                   (0x8U)                                              /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  (3U)                                                /*!< UART0_MODEM: RXRTSE Position            */
#define UART_MODEM_RXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_RXRTSE_SHIFT))&UART_MODEM_RXRTSE_MASK) /*!< UART0_MODEM                             */
/* ------- IR Bit Fields                            ------ */
#define UART_IR_TNP_MASK                         (0x3U)                                              /*!< UART0_IR: TNP Mask                      */
#define UART_IR_TNP_SHIFT                        (0U)                                                /*!< UART0_IR: TNP Position                  */
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x))<<UART_IR_TNP_SHIFT))&UART_IR_TNP_MASK) /*!< UART0_IR                                */
#define UART_IR_IREN_MASK                        (0x4U)                                              /*!< UART0_IR: IREN Mask                     */
#define UART_IR_IREN_SHIFT                       (2U)                                                /*!< UART0_IR: IREN Position                 */
#define UART_IR_IREN(x)                          (((uint8_t)(((uint8_t)(x))<<UART_IR_IREN_SHIFT))&UART_IR_IREN_MASK) /*!< UART0_IR                                */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x7U)                                              /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              (0U)                                                /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x8U)                                              /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    (3U)                                                /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_RXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFE_SHIFT))&UART_PFIFO_RXFE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x70U)                                             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              (4U)                                                /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x80U)                                             /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    (7U)                                                /*!< UART0_PFIFO: TXFE Position              */
#define UART_PFIFO_TXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFE_SHIFT))&UART_PFIFO_TXFE_MASK) /*!< UART0_PFIFO                             */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x1U)                                              /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   (0U)                                                /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_RXUFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXUFE_SHIFT))&UART_CFIFO_RXUFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXOFE_MASK                    (0x2U)                                              /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   (1U)                                                /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_TXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXOFE_SHIFT))&UART_CFIFO_TXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXOFE_MASK                    (0x4U)                                              /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   (2U)                                                /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXOFE_SHIFT))&UART_CFIFO_RXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x40U)                                             /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 (6U)                                                /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_RXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXFLUSH_SHIFT))&UART_CFIFO_RXFLUSH_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXFLUSH_MASK                  (0x80U)                                             /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 (7U)                                                /*!< UART0_CFIFO: TXFLUSH Position           */
#define UART_CFIFO_TXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXFLUSH_SHIFT))&UART_CFIFO_TXFLUSH_MASK) /*!< UART0_CFIFO                             */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x1U)                                              /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    (0U)                                                /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_RXUF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXUF_SHIFT))&UART_SFIFO_RXUF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXOF_MASK                     (0x2U)                                              /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    (1U)                                                /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_TXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXOF_SHIFT))&UART_SFIFO_TXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXOF_MASK                     (0x4U)                                              /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    (2U)                                                /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXOF_SHIFT))&UART_SFIFO_RXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXEMPT_MASK                   (0x40U)                                             /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  (6U)                                                /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_RXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXEMPT_SHIFT))&UART_SFIFO_RXEMPT_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXEMPT_MASK                   (0x80U)                                             /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  (7U)                                                /*!< UART0_SFIFO: TXEMPT Position            */
#define UART_SFIFO_TXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXEMPT_SHIFT))&UART_SFIFO_TXEMPT_MASK) /*!< UART0_SFIFO                             */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFU)                                             /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                (0U)                                                /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                (0U)                                                /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFU)                                             /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                (0U)                                                /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                (0U)                                                /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x40049000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
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
/* ================           UART1 (file:UART1_MKE14D7)           ================ */
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
        uint8_t   RESERVED_0;                  
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
} UART1_Type;

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
/* ------- MODEM Bit Fields                         ------ */
/* ------- IR Bit Fields                            ------ */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4004A000UL //!< Peripheral base address
#define UART1                          ((UART1_Type *) UART1_BasePtr) //!< Freescale base pointer
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
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4004B000UL //!< Peripheral base address
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
#define UART3_BasePtr                  0x4004C000UL //!< Peripheral base address
#define UART3                          ((UART1_Type *) UART3_BasePtr) //!< Freescale base pointer
#define UART3_BASE_PTR                 (UART3) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer
* @brief C Struct for WDOG
* @{
*/

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MKE10)               ================ */
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
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x1U)                                              /*!< WDOG_STCTRLH: WDOGEN Mask               */
#define WDOG_STCTRLH_WDOGEN_SHIFT                (0U)                                                /*!< WDOG_STCTRLH: WDOGEN Position           */
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WDOGEN_SHIFT))&WDOG_STCTRLH_WDOGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x2U)                                              /*!< WDOG_STCTRLH: CLKSRC Mask               */
#define WDOG_STCTRLH_CLKSRC_SHIFT                (1U)                                                /*!< WDOG_STCTRLH: CLKSRC Position           */
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_CLKSRC_SHIFT))&WDOG_STCTRLH_CLKSRC_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x4U)                                              /*!< WDOG_STCTRLH: IRQRSTEN Mask             */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              (2U)                                                /*!< WDOG_STCTRLH: IRQRSTEN Position         */
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_IRQRSTEN_SHIFT))&WDOG_STCTRLH_IRQRSTEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WINEN_MASK                  (0x8U)                                              /*!< WDOG_STCTRLH: WINEN Mask                */
#define WDOG_STCTRLH_WINEN_SHIFT                 (3U)                                                /*!< WDOG_STCTRLH: WINEN Position            */
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WINEN_SHIFT))&WDOG_STCTRLH_WINEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x10U)                                             /*!< WDOG_STCTRLH: ALLOWUPDATE Mask          */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           (4U)                                                /*!< WDOG_STCTRLH: ALLOWUPDATE Position      */
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_ALLOWUPDATE_SHIFT))&WDOG_STCTRLH_ALLOWUPDATE_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x20U)                                             /*!< WDOG_STCTRLH: DBGEN Mask                */
#define WDOG_STCTRLH_DBGEN_SHIFT                 (5U)                                                /*!< WDOG_STCTRLH: DBGEN Position            */
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DBGEN_SHIFT))&WDOG_STCTRLH_DBGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x40U)                                             /*!< WDOG_STCTRLH: STOPEN Mask               */
#define WDOG_STCTRLH_STOPEN_SHIFT                (6U)                                                /*!< WDOG_STCTRLH: STOPEN Position           */
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_STOPEN_SHIFT))&WDOG_STCTRLH_STOPEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x80U)                                             /*!< WDOG_STCTRLH: WAITEN Mask               */
#define WDOG_STCTRLH_WAITEN_SHIFT                (7U)                                                /*!< WDOG_STCTRLH: WAITEN Position           */
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WAITEN_SHIFT))&WDOG_STCTRLH_WAITEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_STNDBYEN_MASK               (0x100U)                                            /*!< WDOG_STCTRLH: STNDBYEN Mask             */
#define WDOG_STCTRLH_STNDBYEN_SHIFT              (8U)                                                /*!< WDOG_STCTRLH: STNDBYEN Position         */
#define WDOG_STCTRLH_STNDBYEN(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_STNDBYEN_SHIFT))&WDOG_STCTRLH_STNDBYEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x400U)                                            /*!< WDOG_STCTRLH: TESTWDOG Mask             */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              (10U)                                               /*!< WDOG_STCTRLH: TESTWDOG Position         */
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTWDOG_SHIFT))&WDOG_STCTRLH_TESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x800U)                                            /*!< WDOG_STCTRLH: TESTSEL Mask              */
#define WDOG_STCTRLH_TESTSEL_SHIFT               (11U)                                               /*!< WDOG_STCTRLH: TESTSEL Position          */
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTSEL_SHIFT))&WDOG_STCTRLH_TESTSEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x3000U)                                           /*!< WDOG_STCTRLH: BYTESEL Mask              */
#define WDOG_STCTRLH_BYTESEL_SHIFT               (12U)                                               /*!< WDOG_STCTRLH: BYTESEL Position          */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x4000U)                                           /*!< WDOG_STCTRLH: DISTESTWDOG Mask          */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           (14U)                                               /*!< WDOG_STCTRLH: DISTESTWDOG Position      */
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DISTESTWDOG_SHIFT))&WDOG_STCTRLH_DISTESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x8000U)                                           /*!< WDOG_STCTRLL: INTFLG Mask               */
#define WDOG_STCTRLL_INTFLG_SHIFT                (15U)                                               /*!< WDOG_STCTRLL: INTFLG Position           */
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLL_INTFLG_SHIFT))&WDOG_STCTRLL_INTFLG_MASK) /*!< WDOG_STCTRLL                            */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFU)                                       /*!< WDOG_TOVAL: TOVAL Mask                  */
#define WDOG_TOVAL_TOVAL_SHIFT                   (0U)                                                /*!< WDOG_TOVAL: TOVAL Position              */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK) /*!< WDOG_TOVAL                              */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFU)                                           /*!< WDOG_TOVALH: TOVALHIGH Mask             */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)                                                /*!< WDOG_TOVALH: TOVALHIGH Position         */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK) /*!< WDOG_TOVALH                             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFU)                                           /*!< WDOG_TOVALL: TOVALLOW Mask              */
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)                                                /*!< WDOG_TOVALL: TOVALLOW Position          */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK) /*!< WDOG_TOVALL                             */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFU)                                       /*!< WDOG_WIN: WIN Mask                      */
#define WDOG_WIN_WIN_SHIFT                       (0U)                                                /*!< WDOG_WIN: WIN Position                  */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK) /*!< WDOG_WIN                                */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFU)                                           /*!< WDOG_WINH: WINHIGH Mask                 */
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)                                                /*!< WDOG_WINH: WINHIGH Position             */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK) /*!< WDOG_WINH                               */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFU)                                           /*!< WDOG_WINL: WINLOW Mask                  */
#define WDOG_WINL_WINLOW_SHIFT                   (0U)                                                /*!< WDOG_WINL: WINLOW Position              */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK) /*!< WDOG_WINL                               */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFU)                                           /*!< WDOG_REFRESH: WDOGREFRESH Mask          */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           (0U)                                                /*!< WDOG_REFRESH: WDOGREFRESH Position      */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK) /*!< WDOG_REFRESH                            */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFU)                                           /*!< WDOG_UNLOCK: WDOGUNLOCK Mask            */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             (0U)                                                /*!< WDOG_UNLOCK: WDOGUNLOCK Position        */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK) /*!< WDOG_UNLOCK                             */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFU)                                       /*!< WDOG_TMROUT: TIMEROUTHIGH Mask          */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           (0U)                                                /*!< WDOG_TMROUT: TIMEROUTHIGH Position      */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<WDOG_TMROUT_TIMEROUTHIGH_SHIFT))&WDOG_TMROUT_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUT                             */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)                                           /*!< WDOG_TMROUTH: TIMEROUTHIGH Mask         */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)                                                /*!< WDOG_TMROUTH: TIMEROUTHIGH Position     */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUTH                            */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)                                           /*!< WDOG_TMROUTL: TIMEROUTLOW Mask          */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           (0U)                                                /*!< WDOG_TMROUTL: TIMEROUTLOW Position      */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK) /*!< WDOG_TMROUTL                            */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFU)                                           /*!< WDOG_RSTCNT: RSTCNT Mask                */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 (0U)                                                /*!< WDOG_RSTCNT: RSTCNT Position            */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK) /*!< WDOG_RSTCNT                             */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x700U)                                            /*!< WDOG_PRESC: PRESCVAL Mask               */
#define WDOG_PRESC_PRESCVAL_SHIFT                (8U)                                                /*!< WDOG_PRESC: PRESCVAL Position           */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK) /*!< WDOG_PRESC                              */
/**
 * @} */ /* End group WDOG_Register_Masks_GROUP 
 */

/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x4003A000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
/**
 * @} */ /* End group WDOG_Peripheral_access_layer_GROUP 
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


#endif  /* MCU_MKE14D7 */

