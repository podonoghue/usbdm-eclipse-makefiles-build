/*
** ###################################################################
**     Processor:           mcf51ju128
**     Compilers:           CodeWarrior C/C++ for ColdFire
**     Reference manual:    MCF51JF128RM Rev. 1, 11/2010
**     Version:             rev. 1.0, 2011-04-12
**
**     Abstract:
**         This header file implements peripheral memory map for mcf51ju128
**         processor.
**
**     Copyright: 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 0.1 (2011-01-17)
**         Initial version
**     - rev. 1.0 (2011-04-12)
**         Added pragma pack(1) to fix allocation of class/struct members to byte boundary.
**         ADC - added plus-side gain (PG) register;removed all minus-side general calibration value registers (CLMD,CLMS,CLM4,CLM3,CLM2,CLM1,CLM0).
**         DMA - added array DMA_REQC[4] for effective access to single DMA channel control. Added DSR register for byte access to channel status flags.
**         FTM - corrected the naming of CnVH,CnVL FTM_MemMap members and FTM register accessors.
**         FTM - corrected the offset of bank2 registers.
**         SIM - renamed the bit SIM_SCGC2[ANL] to SIM_SCGC2[CMP].
**         VREF - added TRM register.
**
** ###################################################################
*/

/*! \file mcf51ju128.h */
/*! \version 1.0 */
/*! \date 2011-04-12 */
/*! \brief Peripheral memory map for mcf51ju128 */
/*! \detailed This header file implements peripheral memory map for mcf51ju128
      processor. */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MCU_mcf51ju128)  /* Check if memory map has not been already included */
#define MCU_mcf51ju128

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error mcf51ju128 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

#include "core_cfv1.h"

/*! Memory map version 1.0 */
#define MCU_MEM_MAP_VERSION 0x0100u

/* ----------------------------------------------------------------------------
   -- Interrupt vector adresses
   ---------------------------------------------------------------------------- */

/*! \brief Interrupt Vector Adresses Calculation Macro
    \detailed Converts the interrupt vector index to the interrupt vector address. */
#define GetIntVectAddr(Vnum) ((Vnum) * 4)


/* ----------------------------------------------------------------------------
   -- Watchdog reset macro
   ---------------------------------------------------------------------------- */

/*! \brief Resets watchdog.
    \detailed Resets the watchdog counter.
      Call periodically to inform that your application is alive. */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SIM_SRVCOP=0x55U, SIM_SRVCOP=0xAAU)
#endif
#endif /* __RESET_WATCHDOG */



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*! \addtogroup Interrupt_vector_numbers Interrupt vector numbers */
/*! \{ */

/*! Interrupt Number Definitions */
typedef enum {
  INITSP                       = 0,                /*!< Initial supervisor stack pointer */
  INITPC                       = 1,                /*!< Initial program counter */
  Vaccerr                      = 2,                /*!< Access error */
  Vadderr                      = 3,                /*!< Address error */
  Viinstr                      = 4,                /*!< Illegal instruction */
  Vdiv_by_zero                 = 5,                /*!< Divide by zero */
  VReserved6                   = 6,                /*!< Reserved interrupt 6 */
  VReserved7                   = 7,                /*!< Reserved interrupt 7 */
  Vprviol                      = 8,                /*!< Privilege violation */
  Vtrace                       = 9,                /*!< Trace */
  Vunilaop                     = 10,               /*!< Unimplemented line-a opcode */
  Vunilfop                     = 11,               /*!< Unimplemented line-f opcode */
  Vdbgi                        = 12,               /*!< Debug interrupt */
  VReserved13                  = 13,               /*!< Reserved interrupt 13 */
  Vferror                      = 14,               /*!< Format error */
  VReserved15                  = 15,               /*!< Reserved interrupt 15 */
  VReserved16                  = 16,               /*!< Reserved interrupt 16 */
  VReserved17                  = 17,               /*!< Reserved interrupt 17 */
  VReserved18                  = 18,               /*!< Reserved interrupt 18 */
  VReserved19                  = 19,               /*!< Reserved interrupt 19 */
  VReserved20                  = 20,               /*!< Reserved interrupt 20 */
  VReserved21                  = 21,               /*!< Reserved interrupt 21 */
  VReserved22                  = 22,               /*!< Reserved interrupt 22 */
  VReserved23                  = 23,               /*!< Reserved interrupt 23 */
  Vspuri                       = 24,               /*!< Spurious interrupt */
  VReserved25                  = 25,               /*!< Reserved interrupt 25 */
  VReserved26                  = 26,               /*!< Reserved interrupt 26 */
  VReserved27                  = 27,               /*!< Reserved interrupt 27 */
  VReserved28                  = 28,               /*!< Reserved interrupt 28 */
  VReserved29                  = 29,               /*!< Reserved interrupt 29 */
  VReserved30                  = 30,               /*!< Reserved interrupt 30 */
  VReserved31                  = 31,               /*!< Reserved interrupt 31 */
  Vtrap0                       = 32,               /*!< Trap 0 instruction */
  Vtrap1                       = 33,               /*!< Trap 1 instruction */
  Vtrap2                       = 34,               /*!< Trap 2 instruction */
  Vtrap3                       = 35,               /*!< Trap 3 instruction */
  Vtrap4                       = 36,               /*!< Trap 4 instruction */
  Vtrap5                       = 37,               /*!< Trap 5 instruction */
  Vtrap6                       = 38,               /*!< Trap 6 instruction */
  Vtrap7                       = 39,               /*!< Trap 7 instruction */
  Vtrap8                       = 40,               /*!< Trap 8 instruction */
  Vtrap9                       = 41,               /*!< Trap 9 instruction */
  Vtrap10                      = 42,               /*!< Trap 10 instruction */
  Vtrap11                      = 43,               /*!< Trap 11 instruction */
  Vtrap12                      = 44,               /*!< Trap 12 instruction */
  Vtrap13                      = 45,               /*!< Trap 13 instruction */
  Vtrap14                      = 46,               /*!< Trap 14 instruction */
  Vtrap15                      = 47,               /*!< Trap 15 instruction */
  VReserved48                  = 48,               /*!< Reserved interrupt 48 */
  VReserved49                  = 49,               /*!< Reserved interrupt 49 */
  VReserved50                  = 50,               /*!< Reserved interrupt 50 */
  VReserved51                  = 51,               /*!< Reserved interrupt 51 */
  VReserved52                  = 52,               /*!< Reserved interrupt 52 */
  VReserved53                  = 53,               /*!< Reserved interrupt 53 */
  VReserved54                  = 54,               /*!< Reserved interrupt 54 */
  VReserved55                  = 55,               /*!< Reserved interrupt 55 */
  VReserved56                  = 56,               /*!< Reserved interrupt 56 */
  VReserved57                  = 57,               /*!< Reserved interrupt 57 */
  VReserved58                  = 58,               /*!< Reserved interrupt 58 */
  VReserved59                  = 59,               /*!< Reserved interrupt 59 */
  VReserved60                  = 60,               /*!< Reserved interrupt 60 */
  Vunsinstr                    = 61,               /*!< Unsupported instruction */
  VReserved62                  = 62,               /*!< Reserved interrupt 62 */
  VReserved63                  = 63,               /*!< Reserved interrupt 63 */
  Virq                         = 64,               /*!< IRQ */
  Vlvd                         = 65,               /*!< Low Voltage Detect, Low Voltage Warning interrupt */
  Vllwu                        = 66,               /*!< Low Leakage Wakeup */
  Vlol                         = 67,               /*!< MCG Loss of Clock */
  Vflash                       = 68,               /*!< Flash */
  Vdmach0                      = 69,               /*!< DMA Channel 0 */
  Vdmach1                      = 70,               /*!< DMA Channel 1 */
  Vdmach2                      = 71,               /*!< DMA Channel 2 */
  Vdmach3                      = 72,               /*!< DMA Channel 3 */
  Vusb0                        = 73,               /*!< USB0 Status */
  VReserved74                  = 74,               /*!< Reserved interrupt 74 */
  Vftm1fault_ovf               = 75,               /*!< FTM1 Fault&Overflow */
  Vftm1ch0                     = 76,               /*!< FTM1 Channel 0 */
  Vftm1ch1                     = 77,               /*!< FTM1 Channel 1 */
  Vftm1ch2                     = 78,               /*!< FTM1 Channel 2 */
  Vftm1ch3                     = 79,               /*!< FTM1 Channel 3 */
  Vftm1ch4                     = 80,               /*!< FTM1 Channel 4 */
  Vftm1ch5                     = 81,               /*!< FTM1 Channel 5 */
  Vcmp0                        = 82,               /*!< CMP0 */
  Vftm0fault_ovf               = 83,               /*!< FTM0 Fault&Overflow */
  Vftm0ch0                     = 84,               /*!< FTM0 Channel 0 */
  Vftm0ch1                     = 85,               /*!< FTM0 Channel 1 */
  Vspi0                        = 86,               /*!< SPI0 */
  Vsci0                        = 87,               /*!< UART0 */
  Vsai_rx                      = 88,               /*!< I2S Receive */
  Vsai_tx                      = 89,               /*!< I2S Transmit */
  Viic0                        = 90,               /*!< I2C0 */
  Viic2                        = 91,               /*!< I2C2 */
  Vspi1                        = 92,               /*!< SPI1 */
  Vsci1                        = 93,               /*!< UART1 */
  Viic1                        = 94,               /*!< I2C1 */
  Viic3                        = 95,               /*!< I2C3 */
  Vadc0                        = 96,               /*!< ADC0 */
  Vtsi0                        = 97,               /*!< TSI0 */
  Vdac0                        = 98,               /*!< DAC0 */
  Vcmt                         = 99,               /*!< CMT */
  Vpdb0                        = 100,              /*!< PDB0 */
  Vlptmr0                      = 101,              /*!< LPTMR0 */
  Vlptmr1                      = 102,              /*!< LPTMR1 */
  VL7swi                       = 103,              /*!< Level 7 Software Interrupt */
  VL6swi                       = 104,              /*!< Level 6 Software Interrupt */
  VL5swi                       = 105,              /*!< Level 5 Software Interrupt */
  VL4swi                       = 106,              /*!< Level 4 Software Interrupt */
  VL3swi                       = 107,              /*!< Level 3 Software Interrupt */
  VL2swi                       = 108,              /*!< Level 2 Software Interrupt */
  VL1swi                       = 109,              /*!< Level 1 Software Interrupt */
  Vmtim0                       = 110,              /*!< MTIM0 */
  Vusbdcd                      = 111,              /*!< USBDCD */
  Vportab                      = 112,              /*!< EGPIO Port A & EGPIO Port B */
  Vportdc                      = 113,              /*!< EGPIO Port D & EGPIO Port C */
  Vportfe                      = 114               /*!< EGPIO Port F & EGPIO Port E */
} IRQInterruptIndex;

/*! \} */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Peripheral type defines
   ---------------------------------------------------------------------------- */

/*! \addtogroup Peripheral_defines Peripheral type defines */
/*! \{ */


/*
** Start of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
  #pragma pack(1)
#elif defined(__GNUC__)
   #pragma pack(push,1)
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Peripheral ADC */
/*! \{ */

/*! ADC - Peripheral register structure */
typedef struct ADC_MemMap {
  uint32_t SC1[2];                                 /*!< ADC status and control registers 1, array offset: 0x0, array step: 0x4 */
  uint32_t CFG1;                                   /*!< ADC configuration register 1, offset: 0x8 */
  uint32_t CFG2;                                   /*!< Configuration register 2, offset: 0xC */
  uint32_t R[2];                                   /*!< ADC data result register, array offset: 0x10, array step: 0x4 */
  uint32_t CV1;                                    /*!< Compare value registers, offset: 0x18 */
  uint32_t CV2;                                    /*!< Compare value registers, offset: 0x1C */
  uint32_t SC2;                                    /*!< Status and control register 2, offset: 0x20 */
  uint32_t SC3;                                    /*!< Status and control register 3, offset: 0x24 */
  uint32_t OFS;                                    /*!< ADC offset correction register, offset: 0x28 */
  uint32_t PG;                                     /*!< ADC plus-side gain register, offset: 0x2C */
  uint8_t RESERVED_0[4];
  uint32_t CLPD;                                   /*!< ADC plus-side general calibration value register, offset: 0x34 */
  uint32_t CLPS;                                   /*!< ADC plus-side general calibration value register, offset: 0x38 */
  uint32_t CLP4;                                   /*!< ADC plus-side general calibration value register, offset: 0x3C */
  uint32_t CLP3;                                   /*!< ADC plus-side general calibration value register, offset: 0x40 */
  uint32_t CLP2;                                   /*!< ADC plus-side general calibration value register, offset: 0x44 */
  uint32_t CLP1;                                   /*!< ADC plus-side general calibration value register, offset: 0x48 */
  uint32_t CLP0;                                   /*!< ADC plus-side general calibration value register, offset: 0x4C */
} volatile *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros */
/*! \{ */


/* ADC - Register accessors */
#define ADC_SC1_REG(base,index)                  ((base)->SC1[index])
#define ADC_CFG1_REG(base)                       ((base)->CFG1)
#define ADC_CFG2_REG(base)                       ((base)->CFG2)
#define ADC_R_REG(base,index)                    ((base)->R[index])
#define ADC_CV1_REG(base)                        ((base)->CV1)
#define ADC_CV2_REG(base)                        ((base)->CV2)
#define ADC_SC2_REG(base)                        ((base)->SC2)
#define ADC_SC3_REG(base)                        ((base)->SC3)
#define ADC_OFS_REG(base)                        ((base)->OFS)
#define ADC_PG_REG(base)                         ((base)->PG)
#define ADC_CLPD_REG(base)                       ((base)->CLPD)
#define ADC_CLPS_REG(base)                       ((base)->CLPS)
#define ADC_CLP4_REG(base)                       ((base)->CLP4)
#define ADC_CLP3_REG(base)                       ((base)->CLP3)
#define ADC_CLP2_REG(base)                       ((base)->CLP2)
#define ADC_CLP1_REG(base)                       ((base)->CLP1)
#define ADC_CLP0_REG(base)                       ((base)->CLP0)

/*! \} */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Masks ADC Register Masks */
/*! \{ */

/* SC1 Bit Fields */
#define ADC_SC1_ADCH_MASK                        0x1Fu
#define ADC_SC1_ADCH_SHIFT                       0
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK)
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
/* CFG1 Bit Fields */
#define ADC_CFG1_ADICLK_MASK                     0x3u
#define ADC_CFG1_ADICLK_SHIFT                    0
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       0xCu
#define ADC_CFG1_MODE_SHIFT                      2
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     0x10u
#define ADC_CFG1_ADLSMP_SHIFT                    4
#define ADC_CFG1_ADIV_MASK                       0x60u
#define ADC_CFG1_ADIV_SHIFT                      5
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      0x80u
#define ADC_CFG1_ADLPC_SHIFT                     7
/* CFG2 Bit Fields */
#define ADC_CFG2_ADLSTS_MASK                     0x3u
#define ADC_CFG2_ADLSTS_SHIFT                    0
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      0x4u
#define ADC_CFG2_ADHSC_SHIFT                     2
#define ADC_CFG2_ADACKEN_MASK                    0x8u
#define ADC_CFG2_ADACKEN_SHIFT                   3
#define ADC_CFG2_MUXSEL_MASK                     0x10u
#define ADC_CFG2_MUXSEL_SHIFT                    4
/* R Bit Fields */
#define ADC_R_D_MASK                             0xFFFFu
#define ADC_R_D_SHIFT                            0
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK)
/* CV1 Bit Fields */
#define ADC_CV1_CV_MASK                          0xFFFFu
#define ADC_CV1_CV_SHIFT                         0
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV1_CV_SHIFT))&ADC_CV1_CV_MASK)
/* CV2 Bit Fields */
#define ADC_CV2_CV_MASK                          0xFFFFu
#define ADC_CV2_CV_SHIFT                         0
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV2_CV_SHIFT))&ADC_CV2_CV_MASK)
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       0x4u
#define ADC_SC2_DMAEN_SHIFT                      2
#define ADC_SC2_ACREN_MASK                       0x8u
#define ADC_SC2_ACREN_SHIFT                      3
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
/* SC3 Bit Fields */
#define ADC_SC3_AVGS_MASK                        0x3u
#define ADC_SC3_AVGS_SHIFT                       0
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        0x4u
#define ADC_SC3_AVGE_SHIFT                       2
#define ADC_SC3_ADCO_MASK                        0x8u
#define ADC_SC3_ADCO_SHIFT                       3
#define ADC_SC3_CALF_MASK                        0x40u
#define ADC_SC3_CALF_SHIFT                       6
#define ADC_SC3_CAL_MASK                         0x80u
#define ADC_SC3_CAL_SHIFT                        7
/* OFS Bit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFFu
#define ADC_OFS_OFS_SHIFT                        0
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK)
/* PG Bit Fields */
#define ADC_PG_PG_MASK                           0xFFFFu
#define ADC_PG_PG_SHIFT                          0
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK)
/* CLPD Bit Fields */
#define ADC_CLPD_CLPD_MASK                       0x3Fu
#define ADC_CLPD_CLPD_SHIFT                      0
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#define ADC_CLPS_CLPS_MASK                       0x3Fu
#define ADC_CLPS_CLPS_SHIFT                      0
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK)
/* CLP4 Bit Fields */
#define ADC_CLP4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK)
/* CLP3 Bit Fields */
#define ADC_CLP3_CLP3_MASK                       0x1FFu
#define ADC_CLP3_CLP3_SHIFT                      0
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Fields */
#define ADC_CLP2_CLP2_MASK                       0xFFu
#define ADC_CLP2_CLP2_SHIFT                      0
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK)
/* CLP1 Bit Fields */
#define ADC_CLP1_CLP1_MASK                       0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
#define ADC_CLP0_CLP0_MASK                       0x3Fu
#define ADC_CLP0_CLP0_SHIFT                      0
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK)

/*! \} */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/*! Peripheral ADC0 base pointer */
#define ADC0_BASE_PTR                            ((ADC_MemMapPtr)0xFFFF8600u)

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros */
/*! \{ */


/* ADC - Register instance definitions */
/* ADC0 */
#define ADC0_SC1A                                ADC_SC1_REG(ADC0_BASE_PTR,0)
#define ADC0_SC1B                                ADC_SC1_REG(ADC0_BASE_PTR,1)
#define ADC0_CFG1                                ADC_CFG1_REG(ADC0_BASE_PTR)
#define ADC0_CFG2                                ADC_CFG2_REG(ADC0_BASE_PTR)
#define ADC0_RA                                  ADC_R_REG(ADC0_BASE_PTR,0)
#define ADC0_RB                                  ADC_R_REG(ADC0_BASE_PTR,1)
#define ADC0_CV1                                 ADC_CV1_REG(ADC0_BASE_PTR)
#define ADC0_CV2                                 ADC_CV2_REG(ADC0_BASE_PTR)
#define ADC0_SC2                                 ADC_SC2_REG(ADC0_BASE_PTR)
#define ADC0_SC3                                 ADC_SC3_REG(ADC0_BASE_PTR)
#define ADC0_OFS                                 ADC_OFS_REG(ADC0_BASE_PTR)
#define ADC0_PG                                  ADC_PG_REG(ADC0_BASE_PTR)
#define ADC0_CLPD                                ADC_CLPD_REG(ADC0_BASE_PTR)
#define ADC0_CLPS                                ADC_CLPS_REG(ADC0_BASE_PTR)
#define ADC0_CLP4                                ADC_CLP4_REG(ADC0_BASE_PTR)
#define ADC0_CLP3                                ADC_CLP3_REG(ADC0_BASE_PTR)
#define ADC0_CLP2                                ADC_CLP2_REG(ADC0_BASE_PTR)
#define ADC0_CLP1                                ADC_CLP1_REG(ADC0_BASE_PTR)
#define ADC0_CLP0                                ADC_CLP0_REG(ADC0_BASE_PTR)

/* ADC - Register array accessors */
#define ADC0_SC1(index)                          ADC_SC1_REG(ADC0_BASE_PTR,index)
#define ADC0_R(index)                            ADC_R_REG(ADC0_BASE_PTR,index)

/*! \} */ /* end of group ADC_Register_Accessor_Macros */


/*! \} */ /* end of group ADC_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMP
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Peripheral CMP */
/*! \{ */

/*! CMP - Peripheral register structure */
typedef struct CMP_MemMap {
  uint8_t CR0;                                     /*!< CMP Control Register 0, offset: 0x0 */
  uint8_t CR1;                                     /*!< CMP Control Register 1, offset: 0x1 */
  uint8_t FPR;                                     /*!< CMP Filter Period Register, offset: 0x2 */
  uint8_t SCR;                                     /*!< CMP Status and Control Register, offset: 0x3 */
  uint8_t DACCR;                                   /*!< DAC Control Register, offset: 0x4 */
  uint8_t MUXCR;                                   /*!< MUX Control Register, offset: 0x5 */
} volatile *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros */
/*! \{ */


/* CMP - Register accessors */
#define CMP_CR0_REG(base)                        ((base)->CR0)
#define CMP_CR1_REG(base)                        ((base)->CR1)
#define CMP_FPR_REG(base)                        ((base)->FPR)
#define CMP_SCR_REG(base)                        ((base)->SCR)
#define CMP_DACCR_REG(base)                      ((base)->DACCR)
#define CMP_MUXCR_REG(base)                      ((base)->MUXCR)

/*! \} */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Masks CMP Register Masks */
/*! \{ */

/* CR0 Bit Fields */
#define CMP_CR0_HYSTCTR_MASK                     0x3u
#define CMP_CR0_HYSTCTR_SHIFT                    0
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_SMELB_MASK                       0x20u
#define CMP_SCR_SMELB_SHIFT                      5
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK)
#define CMP_MUXCR_MEN_MASK                       0x40u
#define CMP_MUXCR_MEN_SHIFT                      6
#define CMP_MUXCR_PEN_MASK                       0x80u
#define CMP_MUXCR_PEN_SHIFT                      7

/*! \} */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/*! Peripheral CMP0 base pointer */
#define CMP0_BASE_PTR                            ((CMP_MemMapPtr)0xFFFF8530u)

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros */
/*! \{ */


/* CMP - Register instance definitions */
/* CMP0 */
#define CMP0_CR0                                 CMP_CR0_REG(CMP0_BASE_PTR)
#define CMP0_CR1                                 CMP_CR1_REG(CMP0_BASE_PTR)
#define CMP0_FPR                                 CMP_FPR_REG(CMP0_BASE_PTR)
#define CMP0_SCR                                 CMP_SCR_REG(CMP0_BASE_PTR)
#define CMP0_DACCR                               CMP_DACCR_REG(CMP0_BASE_PTR)
#define CMP0_MUXCR                               CMP_MUXCR_REG(CMP0_BASE_PTR)

/*! \} */ /* end of group CMP_Register_Accessor_Macros */


/*! \} */ /* end of group CMP_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMT
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Peripheral CMT */
/*! \{ */

/*! CMT - Peripheral register structure */
typedef struct CMT_MemMap {
  uint8_t CGH1;                                    /*!< CMT Carrier Generator High Data Register 1, offset: 0x0 */
  uint8_t CGL1;                                    /*!< CMT Carrier Generator Low Data Register 1, offset: 0x1 */
  uint8_t CGH2;                                    /*!< CMT Carrier Generator High Data Register 2, offset: 0x2 */
  uint8_t CGL2;                                    /*!< CMT Carrier Generator Low Data Register 2, offset: 0x3 */
  uint8_t OC;                                      /*!< CMT Output Control Register, offset: 0x4 */
  uint8_t MSC;                                     /*!< CMT Modulator Status and Control Register, offset: 0x5 */
  uint8_t CMD1;                                    /*!< CMT Modulator Data Register Mark High, offset: 0x6 */
  uint8_t CMD2;                                    /*!< CMT Modulator Data Register Mark Low, offset: 0x7 */
  uint8_t CMD3;                                    /*!< CMT Modulator Data Register Space High, offset: 0x8 */
  uint8_t CMD4;                                    /*!< CMT Modulator Data Register Space Low, offset: 0x9 */
  uint8_t PPS;                                     /*!< CMT Primary Prescaler Register, offset: 0xA */
  uint8_t DMA;                                     /*!< CMT Direct Memory Access, offset: 0xB */
} volatile *CMT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros */
/*! \{ */


/* CMT - Register accessors */
#define CMT_CGH1_REG(base)                       ((base)->CGH1)
#define CMT_CGL1_REG(base)                       ((base)->CGL1)
#define CMT_CGH2_REG(base)                       ((base)->CGH2)
#define CMT_CGL2_REG(base)                       ((base)->CGL2)
#define CMT_OC_REG(base)                         ((base)->OC)
#define CMT_MSC_REG(base)                        ((base)->MSC)
#define CMT_CMD1_REG(base)                       ((base)->CMD1)
#define CMT_CMD2_REG(base)                       ((base)->CMD2)
#define CMT_CMD3_REG(base)                       ((base)->CMD3)
#define CMT_CMD4_REG(base)                       ((base)->CMD4)
#define CMT_PPS_REG(base)                        ((base)->PPS)
#define CMT_DMA_REG(base)                        ((base)->DMA)

/*! \} */ /* end of group CMT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Masks CMT Register Masks */
/*! \{ */

/* CGH1 Bit Fields */
#define CMT_CGH1_PH_MASK                         0xFFu
#define CMT_CGH1_PH_SHIFT                        0
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK)
/* CGL1 Bit Fields */
#define CMT_CGL1_PL_MASK                         0xFFu
#define CMT_CGL1_PL_SHIFT                        0
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK)
/* CGH2 Bit Fields */
#define CMT_CGH2_SH_MASK                         0xFFu
#define CMT_CGH2_SH_SHIFT                        0
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK)
/* CGL2 Bit Fields */
#define CMT_CGL2_SL_MASK                         0xFFu
#define CMT_CGL2_SL_SHIFT                        0
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK)
/* OC Bit Fields */
#define CMT_OC_IROPEN_MASK                       0x20u
#define CMT_OC_IROPEN_SHIFT                      5
#define CMT_OC_CMTPOL_MASK                       0x40u
#define CMT_OC_CMTPOL_SHIFT                      6
#define CMT_OC_IROL_MASK                         0x80u
#define CMT_OC_IROL_SHIFT                        7
/* MSC Bit Fields */
#define CMT_MSC_MCGEN_MASK                       0x1u
#define CMT_MSC_MCGEN_SHIFT                      0
#define CMT_MSC_EOCIE_MASK                       0x2u
#define CMT_MSC_EOCIE_SHIFT                      1
#define CMT_MSC_FSK_MASK                         0x4u
#define CMT_MSC_FSK_SHIFT                        2
#define CMT_MSC_BASE_MASK                        0x8u
#define CMT_MSC_BASE_SHIFT                       3
#define CMT_MSC_EXSPC_MASK                       0x10u
#define CMT_MSC_EXSPC_SHIFT                      4
#define CMT_MSC_CMTDIV_MASK                      0x60u
#define CMT_MSC_CMTDIV_SHIFT                     5
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK)
#define CMT_MSC_EOCF_MASK                        0x80u
#define CMT_MSC_EOCF_SHIFT                       7
/* CMD1 Bit Fields */
#define CMT_CMD1_MB_MASK                         0xFFu
#define CMT_CMD1_MB_SHIFT                        0
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK)
/* CMD2 Bit Fields */
#define CMT_CMD2_MB_MASK                         0xFFu
#define CMT_CMD2_MB_SHIFT                        0
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK)
/* CMD3 Bit Fields */
#define CMT_CMD3_SB_MASK                         0xFFu
#define CMT_CMD3_SB_SHIFT                        0
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK)
/* CMD4 Bit Fields */
#define CMT_CMD4_SB_MASK                         0xFFu
#define CMT_CMD4_SB_SHIFT                        0
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK)
/* PPS Bit Fields */
#define CMT_PPS_PPSDIV_MASK                      0xFu
#define CMT_PPS_PPSDIV_SHIFT                     0
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK)
/* DMA Bit Fields */
#define CMT_DMA_DMA_MASK                         0x1u
#define CMT_DMA_DMA_SHIFT                        0

/*! \} */ /* end of group CMT_Register_Masks */


/* CMT - Peripheral instance base addresses */
/*! Peripheral CMT base pointer */
#define CMT_BASE_PTR                             ((CMT_MemMapPtr)0xFFFF8420u)

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros */
/*! \{ */


/* CMT - Register instance definitions */
/* CMT */
#define CMT_CGH1                                 CMT_CGH1_REG(CMT_BASE_PTR)
#define CMT_CGL1                                 CMT_CGL1_REG(CMT_BASE_PTR)
#define CMT_CGH2                                 CMT_CGH2_REG(CMT_BASE_PTR)
#define CMT_CGL2                                 CMT_CGL2_REG(CMT_BASE_PTR)
#define CMT_OC                                   CMT_OC_REG(CMT_BASE_PTR)
#define CMT_MSC                                  CMT_MSC_REG(CMT_BASE_PTR)
#define CMT_CMD1                                 CMT_CMD1_REG(CMT_BASE_PTR)
#define CMT_CMD2                                 CMT_CMD2_REG(CMT_BASE_PTR)
#define CMT_CMD3                                 CMT_CMD3_REG(CMT_BASE_PTR)
#define CMT_CMD4                                 CMT_CMD4_REG(CMT_BASE_PTR)
#define CMT_PPS                                  CMT_PPS_REG(CMT_BASE_PTR)
#define CMT_DMA                                  CMT_DMA_REG(CMT_BASE_PTR)

/*! \} */ /* end of group CMT_Register_Accessor_Macros */


/*! \} */ /* end of group CMT_Peripheral */


/* ----------------------------------------------------------------------------
   -- CRC
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Peripheral CRC */
/*! \{ */

/*! CRC - Peripheral register structure */
typedef struct CRC_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t CRC;                                    /*!< CRC Data Register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint16_t CRCH;                                   /*!< CRC_CRCH register., offset: 0x0 */
      uint16_t CRCL;                                   /*!< CRC_CRCL register., offset: 0x2 */
    } ACCESS16BIT;
    struct {                                         /* offset: 0x0 */
      uint8_t CRCHU;                                   /*!< CRC_CRCHU register., offset: 0x0 */
      uint8_t CRCHL;                                   /*!< CRC_CRCHL register., offset: 0x1 */
      uint8_t CRCLU;                                   /*!< CRC_CRCLU register., offset: 0x2 */
      uint8_t CRCLL;                                   /*!< CRC_CRCLL register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    uint32_t GPOLY;                                  /*!< CRC Polynomial Register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint16_t GPOLYH;                                 /*!< CRC_GPOLYH register., offset: 0x4 */
      uint16_t GPOLYL;                                 /*!< CRC_GPOLYL register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    struct {                                         /* offset: 0x4 */
      uint8_t GPOLYHU;                                 /*!< CRC_GPOLYHU register., offset: 0x4 */
      uint8_t GPOLYHL;                                 /*!< CRC_GPOLYHL register., offset: 0x5 */
      uint8_t GPOLYLU;                                 /*!< CRC_GPOLYLU register., offset: 0x6 */
      uint8_t GPOLYLL;                                 /*!< CRC_GPOLYLL register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    uint16_t CTRL;                                   /*!< CRC Control Register, offset: 0x8 */
    uint8_t CTRLHU;                                  /*!< CRC_CTRLHU register., offset: 0x8 */
  };
} volatile *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros */
/*! \{ */


/* CRC - Register accessors */
#define CRC_CRC_REG(base)                        ((base)->CRC)
#define CRC_CRCH_REG(base)                       ((base)->ACCESS16BIT.CRCH)
#define CRC_CRCL_REG(base)                       ((base)->ACCESS16BIT.CRCL)
#define CRC_CRCHU_REG(base)                      ((base)->ACCESS8BIT.CRCHU)
#define CRC_CRCHL_REG(base)                      ((base)->ACCESS8BIT.CRCHL)
#define CRC_CRCLU_REG(base)                      ((base)->ACCESS8BIT.CRCLU)
#define CRC_CRCLL_REG(base)                      ((base)->ACCESS8BIT.CRCLL)
#define CRC_GPOLY_REG(base)                      ((base)->GPOLY)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYH)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYL)
#define CRC_GPOLYHU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHU)
#define CRC_GPOLYHL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHL)
#define CRC_GPOLYLU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLU)
#define CRC_GPOLYLL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLL)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)
#define CRC_CTRLHU_REG(base)                     ((base)->CTRLHU)

/*! \} */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Masks CRC Register Masks */
/*! \{ */

/* CRC Bit Fields */
#define CRC_CRC_LL_MASK                          0xFFu
#define CRC_CRC_LL_SHIFT                         0
#define CRC_CRC_LL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LL_SHIFT))&CRC_CRC_LL_MASK)
#define CRC_CRC_LU_MASK                          0xFF00u
#define CRC_CRC_LU_SHIFT                         8
#define CRC_CRC_LU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LU_SHIFT))&CRC_CRC_LU_MASK)
#define CRC_CRC_HL_MASK                          0xFF0000u
#define CRC_CRC_HL_SHIFT                         16
#define CRC_CRC_HL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HL_SHIFT))&CRC_CRC_HL_MASK)
#define CRC_CRC_HU_MASK                          0xFF000000u
#define CRC_CRC_HU_SHIFT                         24
#define CRC_CRC_HU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HU_SHIFT))&CRC_CRC_HU_MASK)
/* CRCH Bit Fields */
#define CRC_CRCH_CRCH_MASK                       0xFFFFu
#define CRC_CRCH_CRCH_SHIFT                      0
#define CRC_CRCH_CRCH(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCH_CRCH_SHIFT))&CRC_CRCH_CRCH_MASK)
/* CRCL Bit Fields */
#define CRC_CRCL_CRCL_MASK                       0xFFFFu
#define CRC_CRCL_CRCL_SHIFT                      0
#define CRC_CRCL_CRCL(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCL_CRCL_SHIFT))&CRC_CRCL_CRCL_MASK)
/* CRCHU Bit Fields */
#define CRC_CRCHU_CRCHU_MASK                     0xFFu
#define CRC_CRCHU_CRCHU_SHIFT                    0
#define CRC_CRCHU_CRCHU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHU_CRCHU_SHIFT))&CRC_CRCHU_CRCHU_MASK)
/* CRCHL Bit Fields */
#define CRC_CRCHL_CRCHL_MASK                     0xFFu
#define CRC_CRCHL_CRCHL_SHIFT                    0
#define CRC_CRCHL_CRCHL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHL_CRCHL_SHIFT))&CRC_CRCHL_CRCHL_MASK)
/* CRCLU Bit Fields */
#define CRC_CRCLU_CRCLU_MASK                     0xFFu
#define CRC_CRCLU_CRCLU_SHIFT                    0
#define CRC_CRCLU_CRCLU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLU_CRCLU_SHIFT))&CRC_CRCLU_CRCLU_MASK)
/* CRCLL Bit Fields */
#define CRC_CRCLL_CRCLL_MASK                     0xFFu
#define CRC_CRCLL_CRCLL_SHIFT                    0
#define CRC_CRCLL_CRCLL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLL_CRCLL_SHIFT))&CRC_CRCLL_CRCLL_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x100u
#define CRC_CTRL_TCRC_SHIFT                      8
#define CRC_CTRL_WAS_MASK                        0x200u
#define CRC_CTRL_WAS_SHIFT                       9
#define CRC_CTRL_FXOR_MASK                       0x400u
#define CRC_CTRL_FXOR_SHIFT                      10
#define CRC_CTRL_TOTR_MASK                       0x3000u
#define CRC_CTRL_TOTR_SHIFT                      12
#define CRC_CTRL_TOTR(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC000u
#define CRC_CTRL_TOT_SHIFT                       14
#define CRC_CTRL_TOT(x)                          (((uint16_t)(((uint16_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/*! \} */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/*! Peripheral CRC base pointer */
#define CRC_BASE_PTR                             ((CRC_MemMapPtr)0xFFFF8570u)

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros */
/*! \{ */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_CRC                                  CRC_CRC_REG(CRC_BASE_PTR)
#define CRC_GPOLY                                CRC_GPOLY_REG(CRC_BASE_PTR)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC_BASE_PTR)
#define CRC_CRCL                                 CRC_CRCL_REG(CRC_BASE_PTR)
#define CRC_CRCH                                 CRC_CRCH_REG(CRC_BASE_PTR)
#define CRC_CRCLL                                CRC_CRCLL_REG(CRC_BASE_PTR)
#define CRC_CRCLU                                CRC_CRCLU_REG(CRC_BASE_PTR)
#define CRC_CRCHL                                CRC_CRCHL_REG(CRC_BASE_PTR)
#define CRC_CRCHU                                CRC_CRCHU_REG(CRC_BASE_PTR)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC_BASE_PTR)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC_BASE_PTR)
#define CRC_GPOLYLL                              CRC_GPOLYLL_REG(CRC_BASE_PTR)
#define CRC_GPOLYLU                              CRC_GPOLYLU_REG(CRC_BASE_PTR)
#define CRC_GPOLYHL                              CRC_GPOLYHL_REG(CRC_BASE_PTR)
#define CRC_GPOLYHU                              CRC_GPOLYHU_REG(CRC_BASE_PTR)
#define CRC_CTRLHU                               CRC_CTRLHU_REG(CRC_BASE_PTR)

/*! \} */ /* end of group CRC_Register_Accessor_Macros */


/*! \} */ /* end of group CRC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DAC
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Peripheral DAC */
/*! \{ */

/*! DAC - Peripheral register structure */
typedef struct DAC_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    uint8_t DATH;                                    /*!< DAC Data High Register, array offset: 0x0, array step: 0x2 */
    uint8_t DATL;                                    /*!< DAC Data Low Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  uint8_t SR;                                      /*!< DAC Status Register, offset: 0x20 */
  uint8_t C0;                                      /*!< DAC Control Register, offset: 0x21 */
  uint8_t C1;                                      /*!< DAC Control Register 1, offset: 0x22 */
  uint8_t C2;                                      /*!< DAC Control Register 2, offset: 0x23 */
} volatile *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros */
/*! \{ */


/* DAC - Register accessors */
#define DAC_DATH_REG(base,index)                 ((base)->DAT[index].DATH)
#define DAC_DATL_REG(base,index)                 ((base)->DAT[index].DATL)
#define DAC_SR_REG(base)                         ((base)->SR)
#define DAC_C0_REG(base)                         ((base)->C0)
#define DAC_C1_REG(base)                         ((base)->C1)
#define DAC_C2_REG(base)                         ((base)->C2)

/*! \} */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Masks DAC Register Masks */
/*! \{ */

/* DATH Bit Fields */
#define DAC_DATH_DATA_MASK                       0xFu
#define DAC_DATH_DATA_SHIFT                      0
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK)
/* DATL Bit Fields */
#define DAC_DATL_DATA_MASK                       0xFFu
#define DAC_DATL_DATA_SHIFT                      0
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK)
/* SR Bit Fields */
#define DAC_SR_DACBFRPBF_MASK                    0x1u
#define DAC_SR_DACBFRPBF_SHIFT                   0
#define DAC_SR_DACBFRPTF_MASK                    0x2u
#define DAC_SR_DACBFRPTF_SHIFT                   1
#define DAC_SR_DACBFWMF_MASK                     0x4u
#define DAC_SR_DACBFWMF_SHIFT                    2
/* C0 Bit Fields */
#define DAC_C0_DACBBIEN_MASK                     0x1u
#define DAC_C0_DACBBIEN_SHIFT                    0
#define DAC_C0_DACBTIEN_MASK                     0x2u
#define DAC_C0_DACBTIEN_SHIFT                    1
#define DAC_C0_DACBWIEN_MASK                     0x4u
#define DAC_C0_DACBWIEN_SHIFT                    2
#define DAC_C0_LPEN_MASK                         0x8u
#define DAC_C0_LPEN_SHIFT                        3
#define DAC_C0_DACSWTRG_MASK                     0x10u
#define DAC_C0_DACSWTRG_SHIFT                    4
#define DAC_C0_DACTRGSEL_MASK                    0x20u
#define DAC_C0_DACTRGSEL_SHIFT                   5
#define DAC_C0_DACRFS_MASK                       0x40u
#define DAC_C0_DACRFS_SHIFT                      6
#define DAC_C0_DACEN_MASK                        0x80u
#define DAC_C0_DACEN_SHIFT                       7
/* C1 Bit Fields */
#define DAC_C1_DACBFEN_MASK                      0x1u
#define DAC_C1_DACBFEN_SHIFT                     0
#define DAC_C1_DACBFMD_MASK                      0x6u
#define DAC_C1_DACBFMD_SHIFT                     1
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      0x18u
#define DAC_C1_DACBFWM_SHIFT                     3
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        0x80u
#define DAC_C1_DMAEN_SHIFT                       7
/* C2 Bit Fields */
#define DAC_C2_DACBFUP_MASK                      0xFu
#define DAC_C2_DACBFUP_SHIFT                     0
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      0xF0u
#define DAC_C2_DACBFRP_SHIFT                     4
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK)

/*! \} */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/*! Peripheral DAC0 base pointer */
#define DAC0_BASE_PTR                            ((DAC_MemMapPtr)0xFFFF8500u)

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros */
/*! \{ */


/* DAC - Register instance definitions */
/* DAC0 */
#define DAC0_DAT0L                               DAC_DATL_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT0H                               DAC_DATH_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT1L                               DAC_DATL_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT1H                               DAC_DATH_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT2L                               DAC_DATL_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT2H                               DAC_DATH_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT3L                               DAC_DATL_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT3H                               DAC_DATH_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT4L                               DAC_DATL_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT4H                               DAC_DATH_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT5L                               DAC_DATL_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT5H                               DAC_DATH_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT6L                               DAC_DATL_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT6H                               DAC_DATH_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT7L                               DAC_DATL_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT7H                               DAC_DATH_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT8L                               DAC_DATL_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT8H                               DAC_DATH_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT9L                               DAC_DATL_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT9H                               DAC_DATH_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT10L                              DAC_DATL_REG(DAC0_BASE_PTR,10)
#define DAC0_DAT10H                              DAC_DATH_REG(DAC0_BASE_PTR,10)
#define DAC0_DAT11L                              DAC_DATL_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT11H                              DAC_DATH_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT12L                              DAC_DATL_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT12H                              DAC_DATH_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT13L                              DAC_DATL_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT13H                              DAC_DATH_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT14L                              DAC_DATL_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT14H                              DAC_DATH_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT15L                              DAC_DATL_REG(DAC0_BASE_PTR,15)
#define DAC0_DAT15H                              DAC_DATH_REG(DAC0_BASE_PTR,15)
#define DAC0_SR                                  DAC_SR_REG(DAC0_BASE_PTR)
#define DAC0_C0                                  DAC_C0_REG(DAC0_BASE_PTR)
#define DAC0_C1                                  DAC_C1_REG(DAC0_BASE_PTR)
#define DAC0_C2                                  DAC_C2_REG(DAC0_BASE_PTR)

/* DAC - Register array accessors */
#define DAC0_DATH(index)                         DAC_DATH_REG(DAC0_BASE_PTR,index)
#define DAC0_DATL(index)                         DAC_DATL_REG(DAC0_BASE_PTR,index)

/*! \} */ /* end of group DAC_Register_Accessor_Macros */


/*! \} */ /* end of group DAC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMA
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Peripheral DMA */
/*! \{ */

/*! DMA - Peripheral register structure */
typedef struct DMA_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t REQC;                                   /*!< DMA Request Control Register, offset: 0x0 */
    uint8_t REQC_ARR[4];                             /*!< DMA_REQC0 register...DMA_REQC3 register., array offset: 0x0, array step: 0x1 */
  };
  uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    uint32_t SAR;                                    /*!< Source Address Register, array offset: 0x100, array step: 0x10 */
    uint32_t DAR;                                    /*!< Destination Address Register, array offset: 0x104, array step: 0x10 */
    union {                                          /* offset: 0x108, array step: 0x10 */
      uint32_t DSR_BCR;                                /*!< DMA Status Register / Byte Count Register, array offset: 0x108, array step: 0x10 */
      uint8_t DSR;                                     /*!< DMA_DSR0 register...DMA_DSR3 register., array offset: 0x108, array step: 0x10 */
    };
    uint32_t DCR;                                    /*!< DMA Control Register, array offset: 0x10C, array step: 0x10 */
  } DMA[4];
} volatile *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros */
/*! \{ */


/* DMA - Register accessors */
#define DMA_REQC_REG(base)                       ((base)->REQC)
#define DMA_REQC_ARR_REG(base,index2)            ((base)->REQC_ARR[index2])
#define DMA_SAR_REG(base,index)                  ((base)->DMA[index].SAR)
#define DMA_DAR_REG(base,index)                  ((base)->DMA[index].DAR)
#define DMA_DSR_BCR_REG(base,index)              ((base)->DMA[index].DSR_BCR)
#define DMA_DSR_REG(base,index)                  ((base)->DMA[index].DSR)
#define DMA_DCR_REG(base,index)                  ((base)->DMA[index].DCR)

/*! \} */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Masks DMA Register Masks */
/*! \{ */

/* REQC Bit Fields */
#define DMA_REQC_DMAC3_MASK                      0xFu
#define DMA_REQC_DMAC3_SHIFT                     0
#define DMA_REQC_DMAC3(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC3_SHIFT))&DMA_REQC_DMAC3_MASK)
#define DMA_REQC_CFSM3_MASK                      0x80u
#define DMA_REQC_CFSM3_SHIFT                     7
#define DMA_REQC_DMAC2_MASK                      0xF00u
#define DMA_REQC_DMAC2_SHIFT                     8
#define DMA_REQC_DMAC2(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC2_SHIFT))&DMA_REQC_DMAC2_MASK)
#define DMA_REQC_CFSM2_MASK                      0x8000u
#define DMA_REQC_CFSM2_SHIFT                     15
#define DMA_REQC_DMAC1_MASK                      0xF0000u
#define DMA_REQC_DMAC1_SHIFT                     16
#define DMA_REQC_DMAC1(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC1_SHIFT))&DMA_REQC_DMAC1_MASK)
#define DMA_REQC_CFSM1_MASK                      0x800000u
#define DMA_REQC_CFSM1_SHIFT                     23
#define DMA_REQC_DMAC0_MASK                      0xF000000u
#define DMA_REQC_DMAC0_SHIFT                     24
#define DMA_REQC_DMAC0(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC0_SHIFT))&DMA_REQC_DMAC0_MASK)
#define DMA_REQC_CFSM0_MASK                      0x80000000u
#define DMA_REQC_CFSM0_SHIFT                     31
/* REQC_ARR Bit Fields */
#define DMA_REQC_ARR_DMAC_MASK                   0xFu
#define DMA_REQC_ARR_DMAC_SHIFT                  0
#define DMA_REQC_ARR_DMAC(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_REQC_ARR_DMAC_SHIFT))&DMA_REQC_ARR_DMAC_MASK)
#define DMA_REQC_ARR_CFSM_MASK                   0x80u
#define DMA_REQC_ARR_CFSM_SHIFT                  7
/* SAR Bit Fields */
#define DMA_SAR_SAR_MASK                         0xFFFFFFFFu
#define DMA_SAR_SAR_SHIFT                        0
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_SAR_SAR_SHIFT))&DMA_SAR_SAR_MASK)
/* DAR Bit Fields */
#define DMA_DAR_DAR_MASK                         0xFFFFFFFFu
#define DMA_DAR_DAR_SHIFT                        0
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DAR_DAR_SHIFT))&DMA_DAR_DAR_MASK)
/* DSR_BCR Bit Fields */
#define DMA_DSR_BCR_BCR_MASK                     0xFFFFFFu
#define DMA_DSR_BCR_BCR_SHIFT                    0
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK)
#define DMA_DSR_BCR_DONE_MASK                    0x1000000u
#define DMA_DSR_BCR_DONE_SHIFT                   24
#define DMA_DSR_BCR_BSY_MASK                     0x2000000u
#define DMA_DSR_BCR_BSY_SHIFT                    25
#define DMA_DSR_BCR_REQ_MASK                     0x4000000u
#define DMA_DSR_BCR_REQ_SHIFT                    26
#define DMA_DSR_BCR_BED_MASK                     0x10000000u
#define DMA_DSR_BCR_BED_SHIFT                    28
#define DMA_DSR_BCR_BES_MASK                     0x20000000u
#define DMA_DSR_BCR_BES_SHIFT                    29
#define DMA_DSR_BCR_CE_MASK                      0x40000000u
#define DMA_DSR_BCR_CE_SHIFT                     30
/* DCR Bit Fields */
#define DMA_DCR_LCH2_MASK                        0x3u
#define DMA_DCR_LCH2_SHIFT                       0
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK)
#define DMA_DCR_LCH1_MASK                        0xCu
#define DMA_DCR_LCH1_SHIFT                       2
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK)
#define DMA_DCR_LINKCC_MASK                      0x30u
#define DMA_DCR_LINKCC_SHIFT                     4
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK)
#define DMA_DCR_D_REQ_MASK                       0x80u
#define DMA_DCR_D_REQ_SHIFT                      7
#define DMA_DCR_DMOD_MASK                        0xF00u
#define DMA_DCR_DMOD_SHIFT                       8
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK)
#define DMA_DCR_SMOD_MASK                        0xF000u
#define DMA_DCR_SMOD_SHIFT                       12
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK)
#define DMA_DCR_START_MASK                       0x10000u
#define DMA_DCR_START_SHIFT                      16
#define DMA_DCR_DSIZE_MASK                       0x60000u
#define DMA_DCR_DSIZE_SHIFT                      17
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK)
#define DMA_DCR_DINC_MASK                        0x80000u
#define DMA_DCR_DINC_SHIFT                       19
#define DMA_DCR_SSIZE_MASK                       0x300000u
#define DMA_DCR_SSIZE_SHIFT                      20
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK)
#define DMA_DCR_SINC_MASK                        0x400000u
#define DMA_DCR_SINC_SHIFT                       22
#define DMA_DCR_AA_MASK                          0x10000000u
#define DMA_DCR_AA_SHIFT                         28
#define DMA_DCR_CS_MASK                          0x20000000u
#define DMA_DCR_CS_SHIFT                         29
#define DMA_DCR_ERQ_MASK                         0x40000000u
#define DMA_DCR_ERQ_SHIFT                        30
#define DMA_DCR_EINT_MASK                        0x80000000u
#define DMA_DCR_EINT_SHIFT                       31

/*! \} */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/*! Peripheral DMA base pointer */
#define DMA_BASE_PTR                             ((DMA_MemMapPtr)0xFFFFE400u)

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros */
/*! \{ */


/* DMA - Register instance definitions */
/* DMA */
#define DMA_REQC                                 DMA_REQC_REG(DMA_BASE_PTR)
#define DMA_SAR0                                 DMA_SAR_REG(DMA_BASE_PTR,0)
#define DMA_DAR0                                 DMA_DAR_REG(DMA_BASE_PTR,0)
#define DMA_DSR_BCR0                             DMA_DSR_BCR_REG(DMA_BASE_PTR,0)
#define DMA_DCR0                                 DMA_DCR_REG(DMA_BASE_PTR,0)
#define DMA_SAR1                                 DMA_SAR_REG(DMA_BASE_PTR,1)
#define DMA_DAR1                                 DMA_DAR_REG(DMA_BASE_PTR,1)
#define DMA_DSR_BCR1                             DMA_DSR_BCR_REG(DMA_BASE_PTR,1)
#define DMA_DCR1                                 DMA_DCR_REG(DMA_BASE_PTR,1)
#define DMA_SAR2                                 DMA_SAR_REG(DMA_BASE_PTR,2)
#define DMA_DAR2                                 DMA_DAR_REG(DMA_BASE_PTR,2)
#define DMA_DSR_BCR2                             DMA_DSR_BCR_REG(DMA_BASE_PTR,2)
#define DMA_DCR2                                 DMA_DCR_REG(DMA_BASE_PTR,2)
#define DMA_SAR3                                 DMA_SAR_REG(DMA_BASE_PTR,3)
#define DMA_DAR3                                 DMA_DAR_REG(DMA_BASE_PTR,3)
#define DMA_DSR_BCR3                             DMA_DSR_BCR_REG(DMA_BASE_PTR,3)
#define DMA_DCR3                                 DMA_DCR_REG(DMA_BASE_PTR,3)
#define DMA_REQC0                                DMA_REQC_ARR_REG(DMA_BASE_PTR,0)
#define DMA_REQC1                                DMA_REQC_ARR_REG(DMA_BASE_PTR,1)
#define DMA_REQC2                                DMA_REQC_ARR_REG(DMA_BASE_PTR,2)
#define DMA_REQC3                                DMA_REQC_ARR_REG(DMA_BASE_PTR,3)
#define DMA_DSR0                                 DMA_DSR_REG(DMA_BASE_PTR,0)
#define DMA_DSR1                                 DMA_DSR_REG(DMA_BASE_PTR,1)
#define DMA_DSR2                                 DMA_DSR_REG(DMA_BASE_PTR,2)
#define DMA_DSR3                                 DMA_DSR_REG(DMA_BASE_PTR,3)

/* DMA - Register array accessors */
#define DMA_REQC_ARR(index2)                     DMA_REQC_ARR_REG(DMA_BASE_PTR,index2)
#define DMA_SAR(index)                           DMA_SAR_REG(DMA_BASE_PTR,index)
#define DMA_DAR(index)                           DMA_DAR_REG(DMA_BASE_PTR,index)
#define DMA_DSR_BCR(index)                       DMA_DSR_BCR_REG(DMA_BASE_PTR,index)
#define DMA_DSR(index)                           DMA_DSR_REG(DMA_BASE_PTR,index)
#define DMA_DCR(index)                           DMA_DCR_REG(DMA_BASE_PTR,index)

/*! \} */ /* end of group DMA_Register_Accessor_Macros */


/*! \} */ /* end of group DMA_Peripheral */


/* ----------------------------------------------------------------------------
   -- FB
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Peripheral FB */
/*! \{ */

/*! FB - Peripheral register structure */
typedef struct FB_MemMap {
  struct {                                         /* offset: 0x0, array step: 0xC */
    uint32_t CSAR;                                   /*!< Chip select address register, array offset: 0x0, array step: 0xC */
    uint32_t CSMR;                                   /*!< Chip select mask register, array offset: 0x4, array step: 0xC */
    uint32_t CSCR;                                   /*!< Chip select control register, array offset: 0x8, array step: 0xC */
  } CS[2];
} volatile *FB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Accessor_Macros FB - Register accessor macros */
/*! \{ */


/* FB - Register accessors */
#define FB_CSAR_REG(base,index)                  ((base)->CS[index].CSAR)
#define FB_CSMR_REG(base,index)                  ((base)->CS[index].CSMR)
#define FB_CSCR_REG(base,index)                  ((base)->CS[index].CSCR)

/*! \} */ /* end of group FB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Masks FB Register Masks */
/*! \{ */

/* CSAR Bit Fields */
#define FB_CSAR_BA_MASK                          0xFFFF0000u
#define FB_CSAR_BA_SHIFT                         16
#define FB_CSAR_BA(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSAR_BA_SHIFT))&FB_CSAR_BA_MASK)
/* CSMR Bit Fields */
#define FB_CSMR_V_MASK                           0x1u
#define FB_CSMR_V_SHIFT                          0
#define FB_CSMR_WP_MASK                          0x100u
#define FB_CSMR_WP_SHIFT                         8
#define FB_CSMR_BAM_MASK                         0xFFFF0000u
#define FB_CSMR_BAM_SHIFT                        16
#define FB_CSMR_BAM(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSMR_BAM_SHIFT))&FB_CSMR_BAM_MASK)
/* CSCR Bit Fields */
#define FB_CSCR_PS_MASK                          0xC0u
#define FB_CSCR_PS_SHIFT                         6
#define FB_CSCR_PS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_PS_SHIFT))&FB_CSCR_PS_MASK)
#define FB_CSCR_AA_MASK                          0x100u
#define FB_CSCR_AA_SHIFT                         8
#define FB_CSCR_MUX_MASK                         0x200u
#define FB_CSCR_MUX_SHIFT                        9
#define FB_CSCR_WS_MASK                          0xFC00u
#define FB_CSCR_WS_SHIFT                         10
#define FB_CSCR_WS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WS_SHIFT))&FB_CSCR_WS_MASK)
#define FB_CSCR_WRAH_MASK                        0x30000u
#define FB_CSCR_WRAH_SHIFT                       16
#define FB_CSCR_WRAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WRAH_SHIFT))&FB_CSCR_WRAH_MASK)
#define FB_CSCR_RDAH_MASK                        0xC0000u
#define FB_CSCR_RDAH_SHIFT                       18
#define FB_CSCR_RDAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_RDAH_SHIFT))&FB_CSCR_RDAH_MASK)
#define FB_CSCR_ASET_MASK                        0x300000u
#define FB_CSCR_ASET_SHIFT                       20
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_ASET_SHIFT))&FB_CSCR_ASET_MASK)

/*! \} */ /* end of group FB_Register_Masks */


/* FB - Peripheral instance base addresses */
/*! Peripheral FB base pointer */
#define FB_BASE_PTR                              ((FB_MemMapPtr)0xFFFFE800u)

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Accessor_Macros FB - Register accessor macros */
/*! \{ */


/* FB - Register instance definitions */
/* FB */
#define FB_CSAR0                                 FB_CSAR_REG(FB_BASE_PTR,0)
#define FB_CSMR0                                 FB_CSMR_REG(FB_BASE_PTR,0)
#define FB_CSCR0                                 FB_CSCR_REG(FB_BASE_PTR,0)
#define FB_CSAR1                                 FB_CSAR_REG(FB_BASE_PTR,1)
#define FB_CSMR1                                 FB_CSMR_REG(FB_BASE_PTR,1)
#define FB_CSCR1                                 FB_CSCR_REG(FB_BASE_PTR,1)

/* FB - Register array accessors */
#define FB_CSAR(index)                           FB_CSAR_REG(FB_BASE_PTR,index)
#define FB_CSMR(index)                           FB_CSMR_REG(FB_BASE_PTR,index)
#define FB_CSCR(index)                           FB_CSCR_REG(FB_BASE_PTR,index)

/*! \} */ /* end of group FB_Register_Accessor_Macros */


/*! \} */ /* end of group FB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTFL
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Peripheral FTFL */
/*! \{ */

/*! FTFL - Peripheral register structure */
typedef struct FTFL_MemMap {
  uint8_t FOPT;                                    /*!< Flash Option Register, offset: 0x0 */
  uint8_t FSEC;                                    /*!< Flash Security Register, offset: 0x1 */
  uint8_t FCNFG;                                   /*!< Flash Configuration Register, offset: 0x2 */
  uint8_t FSTAT;                                   /*!< Flash Status Register, offset: 0x3 */
  uint8_t FCCOB0;                                  /*!< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB1;                                  /*!< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB2;                                  /*!< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB3;                                  /*!< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB4;                                  /*!< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB5;                                  /*!< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB6;                                  /*!< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB7;                                  /*!< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOB8;                                  /*!< Flash Common Command Object Registers, offset: 0xC */
  uint8_t FCCOB9;                                  /*!< Flash Common Command Object Registers, offset: 0xD */
  uint8_t FCCOBA;                                  /*!< Flash Common Command Object Registers, offset: 0xE */
  uint8_t FCCOBB;                                  /*!< Flash Common Command Object Registers, offset: 0xF */
  uint8_t FPROT0;                                  /*!< Program Flash Protection Registers, offset: 0x10 */
  uint8_t FPROT1;                                  /*!< Program Flash Protection Registers, offset: 0x11 */
  uint8_t FPROT2;                                  /*!< Program Flash Protection Registers, offset: 0x12 */
  uint8_t FPROT3;                                  /*!< Program Flash Protection Registers, offset: 0x13 */
  uint8_t FDPROT;                                  /*!< Data Flash Protection Register, offset: 0x14 */
  uint8_t FEPROT;                                  /*!< EEPROM Protection Register, offset: 0x15 */
} volatile *FTFL_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros */
/*! \{ */


/* FTFL - Register accessors */
#define FTFL_FOPT_REG(base)                      ((base)->FOPT)
#define FTFL_FSEC_REG(base)                      ((base)->FSEC)
#define FTFL_FCNFG_REG(base)                     ((base)->FCNFG)
#define FTFL_FSTAT_REG(base)                     ((base)->FSTAT)
#define FTFL_FCCOB0_REG(base)                    ((base)->FCCOB0)
#define FTFL_FCCOB1_REG(base)                    ((base)->FCCOB1)
#define FTFL_FCCOB2_REG(base)                    ((base)->FCCOB2)
#define FTFL_FCCOB3_REG(base)                    ((base)->FCCOB3)
#define FTFL_FCCOB4_REG(base)                    ((base)->FCCOB4)
#define FTFL_FCCOB5_REG(base)                    ((base)->FCCOB5)
#define FTFL_FCCOB6_REG(base)                    ((base)->FCCOB6)
#define FTFL_FCCOB7_REG(base)                    ((base)->FCCOB7)
#define FTFL_FCCOB8_REG(base)                    ((base)->FCCOB8)
#define FTFL_FCCOB9_REG(base)                    ((base)->FCCOB9)
#define FTFL_FCCOBA_REG(base)                    ((base)->FCCOBA)
#define FTFL_FCCOBB_REG(base)                    ((base)->FCCOBB)
#define FTFL_FPROT0_REG(base)                    ((base)->FPROT0)
#define FTFL_FPROT1_REG(base)                    ((base)->FPROT1)
#define FTFL_FPROT2_REG(base)                    ((base)->FPROT2)
#define FTFL_FPROT3_REG(base)                    ((base)->FPROT3)
#define FTFL_FDPROT_REG(base)                    ((base)->FDPROT)
#define FTFL_FEPROT_REG(base)                    ((base)->FEPROT)

/*! \} */ /* end of group FTFL_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFL Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Masks FTFL Register Masks */
/*! \{ */

/* FOPT Bit Fields */
#define FTFL_FOPT_OPT_MASK                       0xFFu
#define FTFL_FOPT_OPT_SHIFT                      0
#define FTFL_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FOPT_OPT_SHIFT))&FTFL_FOPT_OPT_MASK)
/* FSEC Bit Fields */
#define FTFL_FSEC_SEC_MASK                       0x3u
#define FTFL_FSEC_SEC_SHIFT                      0
#define FTFL_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_SEC_SHIFT))&FTFL_FSEC_SEC_MASK)
#define FTFL_FSEC_FSLACC_MASK                    0xCu
#define FTFL_FSEC_FSLACC_SHIFT                   2
#define FTFL_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_FSLACC_SHIFT))&FTFL_FSEC_FSLACC_MASK)
#define FTFL_FSEC_MEEN_MASK                      0x30u
#define FTFL_FSEC_MEEN_SHIFT                     4
#define FTFL_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_MEEN_SHIFT))&FTFL_FSEC_MEEN_MASK)
#define FTFL_FSEC_KEYEN_MASK                     0xC0u
#define FTFL_FSEC_KEYEN_SHIFT                    6
#define FTFL_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_KEYEN_SHIFT))&FTFL_FSEC_KEYEN_MASK)
/* FCNFG Bit Fields */
#define FTFL_FCNFG_EEERDY_MASK                   0x1u
#define FTFL_FCNFG_EEERDY_SHIFT                  0
#define FTFL_FCNFG_RAMRDY_MASK                   0x2u
#define FTFL_FCNFG_RAMRDY_SHIFT                  1
#define FTFL_FCNFG_PFLSH_MASK                    0x4u
#define FTFL_FCNFG_PFLSH_SHIFT                   2
#define FTFL_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFL_FCNFG_ERSSUSP_SHIFT                 4
#define FTFL_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFL_FCNFG_ERSAREQ_SHIFT                 5
#define FTFL_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFL_FCNFG_RDCOLLIE_SHIFT                6
#define FTFL_FCNFG_CCIE_MASK                     0x80u
#define FTFL_FCNFG_CCIE_SHIFT                    7
/* FSTAT Bit Fields */
#define FTFL_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFL_FSTAT_MGSTAT0_SHIFT                 0
#define FTFL_FSTAT_FPVIOL_MASK                   0x10u
#define FTFL_FSTAT_FPVIOL_SHIFT                  4
#define FTFL_FSTAT_ACCERR_MASK                   0x20u
#define FTFL_FSTAT_ACCERR_SHIFT                  5
#define FTFL_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFL_FSTAT_RDCOLERR_SHIFT                6
#define FTFL_FSTAT_CCIF_MASK                     0x80u
#define FTFL_FSTAT_CCIF_SHIFT                    7
/* FCCOB0 Bit Fields */
#define FTFL_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB0_CCOBn_SHIFT                  0
#define FTFL_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB0_CCOBn_SHIFT))&FTFL_FCCOB0_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFL_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB1_CCOBn_SHIFT                  0
#define FTFL_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB1_CCOBn_SHIFT))&FTFL_FCCOB1_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFL_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB2_CCOBn_SHIFT                  0
#define FTFL_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB2_CCOBn_SHIFT))&FTFL_FCCOB2_CCOBn_MASK)
/* FCCOB3 Bit Fields */
#define FTFL_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB3_CCOBn_SHIFT                  0
#define FTFL_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB3_CCOBn_SHIFT))&FTFL_FCCOB3_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFL_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB4_CCOBn_SHIFT                  0
#define FTFL_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB4_CCOBn_SHIFT))&FTFL_FCCOB4_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFL_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB5_CCOBn_SHIFT                  0
#define FTFL_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB5_CCOBn_SHIFT))&FTFL_FCCOB5_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFL_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB6_CCOBn_SHIFT                  0
#define FTFL_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB6_CCOBn_SHIFT))&FTFL_FCCOB6_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFL_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB7_CCOBn_SHIFT                  0
#define FTFL_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB7_CCOBn_SHIFT))&FTFL_FCCOB7_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFL_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB8_CCOBn_SHIFT                  0
#define FTFL_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB8_CCOBn_SHIFT))&FTFL_FCCOB8_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFL_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB9_CCOBn_SHIFT                  0
#define FTFL_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB9_CCOBn_SHIFT))&FTFL_FCCOB9_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFL_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBA_CCOBn_SHIFT                  0
#define FTFL_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOBA_CCOBn_SHIFT))&FTFL_FCCOBA_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFL_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBB_CCOBn_SHIFT                  0
#define FTFL_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOBB_CCOBn_SHIFT))&FTFL_FCCOBB_CCOBn_MASK)
/* FPROT0 Bit Fields */
#define FTFL_FPROT0_PROT_MASK                    0xFFu
#define FTFL_FPROT0_PROT_SHIFT                   0
#define FTFL_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT0_PROT_SHIFT))&FTFL_FPROT0_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFL_FPROT1_PROT_MASK                    0xFFu
#define FTFL_FPROT1_PROT_SHIFT                   0
#define FTFL_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT1_PROT_SHIFT))&FTFL_FPROT1_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFL_FPROT2_PROT_MASK                    0xFFu
#define FTFL_FPROT2_PROT_SHIFT                   0
#define FTFL_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT2_PROT_SHIFT))&FTFL_FPROT2_PROT_MASK)
/* FPROT3 Bit Fields */
#define FTFL_FPROT3_PROT_MASK                    0xFFu
#define FTFL_FPROT3_PROT_SHIFT                   0
#define FTFL_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT3_PROT_SHIFT))&FTFL_FPROT3_PROT_MASK)
/* FDPROT Bit Fields */
#define FTFL_FDPROT_DPROT_MASK                   0xFFu
#define FTFL_FDPROT_DPROT_SHIFT                  0
#define FTFL_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPROT_DPROT_MASK)
/* FEPROT Bit Fields */
#define FTFL_FEPROT_EPROT_MASK                   0xFFu
#define FTFL_FEPROT_EPROT_SHIFT                  0
#define FTFL_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROT_SHIFT))&FTFL_FEPROT_EPROT_MASK)

/*! \} */ /* end of group FTFL_Register_Masks */


/* FTFL - Peripheral instance base addresses */
/*! Peripheral FTFL base pointer */
#define FTFL_BASE_PTR                            ((FTFL_MemMapPtr)0xFFFF84E0u)

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros */
/*! \{ */


/* FTFL - Register instance definitions */
/* FTFL */
#define FTFL_FOPT                                FTFL_FOPT_REG(FTFL_BASE_PTR)
#define FTFL_FSTAT                               FTFL_FSTAT_REG(FTFL_BASE_PTR)
#define FTFL_FCNFG                               FTFL_FCNFG_REG(FTFL_BASE_PTR)
#define FTFL_FSEC                                FTFL_FSEC_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB0                              FTFL_FCCOB0_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB1                              FTFL_FCCOB1_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB2                              FTFL_FCCOB2_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB3                              FTFL_FCCOB3_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB4                              FTFL_FCCOB4_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB5                              FTFL_FCCOB5_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB6                              FTFL_FCCOB6_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB7                              FTFL_FCCOB7_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB8                              FTFL_FCCOB8_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB9                              FTFL_FCCOB9_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBA                              FTFL_FCCOBA_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBB                              FTFL_FCCOBB_REG(FTFL_BASE_PTR)
#define FTFL_FPROT0                              FTFL_FPROT0_REG(FTFL_BASE_PTR)
#define FTFL_FPROT1                              FTFL_FPROT1_REG(FTFL_BASE_PTR)
#define FTFL_FPROT2                              FTFL_FPROT2_REG(FTFL_BASE_PTR)
#define FTFL_FPROT3                              FTFL_FPROT3_REG(FTFL_BASE_PTR)
#define FTFL_FDPROT                              FTFL_FDPROT_REG(FTFL_BASE_PTR)
#define FTFL_FEPROT                              FTFL_FEPROT_REG(FTFL_BASE_PTR)

/*! \} */ /* end of group FTFL_Register_Accessor_Macros */


/*! \} */ /* end of group FTFL_Peripheral */


/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Peripheral NV */
/*! \{ */

/*! NV - Peripheral register structure */
typedef struct NV_MemMap {
  uint8_t BACKKEY0;                                /*!< Backdoor Comparison Key 0., offset: 0x0 */
  uint8_t BACKKEY1;                                /*!< Backdoor Comparison Key 1., offset: 0x1 */
  uint8_t BACKKEY2;                                /*!< Backdoor Comparison Key 2., offset: 0x2 */
  uint8_t BACKKEY3;                                /*!< Backdoor Comparison Key 3., offset: 0x3 */
  uint8_t BACKKEY4;                                /*!< Backdoor Comparison Key 4., offset: 0x4 */
  uint8_t BACKKEY5;                                /*!< Backdoor Comparison Key 5., offset: 0x5 */
  uint8_t BACKKEY6;                                /*!< Backdoor Comparison Key 6., offset: 0x6 */
  uint8_t BACKKEY7;                                /*!< Backdoor Comparison Key 7., offset: 0x7 */
  uint8_t FPROT0;                                  /*!< Non-volatile P-Flash Protection 0 - High Register, offset: 0x8 */
  uint8_t FPROT1;                                  /*!< Non-volatile P-Flash Protection 0 - Low Register, offset: 0x9 */
  uint8_t FPROT2;                                  /*!< Non-volatile P-Flash Protection 1 - High Register, offset: 0xA */
  uint8_t FPROT3;                                  /*!< Non-volatile P-Flash Protection 1 - Low Register, offset: 0xB */
  uint8_t FDPROT;                                  /*!< Non-volatile D-Flash Protection Register, offset: 0xC */
  uint8_t FEPROT;                                  /*!< Non-volatile EERAM Protection Register, offset: 0xD */
  uint8_t FOPT;                                    /*!< Non-volatile Flash Option Register, offset: 0xE */
  uint8_t FSEC;                                    /*!< Non-volatile Flash Security Register, offset: 0xF */
} volatile *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Accessor_Macros NV - Register accessor macros */
/*! \{ */


/* NV - Register accessors */
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_FPROT0_REG(base)                      ((base)->FPROT0)
#define NV_FPROT1_REG(base)                      ((base)->FPROT1)
#define NV_FPROT2_REG(base)                      ((base)->FPROT2)
#define NV_FPROT3_REG(base)                      ((base)->FPROT3)
#define NV_FDPROT_REG(base)                      ((base)->FDPROT)
#define NV_FEPROT_REG(base)                      ((base)->FEPROT)
#define NV_FOPT_REG(base)                        ((base)->FOPT)
#define NV_FSEC_REG(base)                        ((base)->FSEC)

/*! \} */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Masks NV Register Masks */
/*! \{ */

/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* FPROT0 Bit Fields */
#define NV_FPROT0_PROT_MASK                      0xFFu
#define NV_FPROT0_PROT_SHIFT                     0
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
/* FPROT1 Bit Fields */
#define NV_FPROT1_PROT_MASK                      0xFFu
#define NV_FPROT1_PROT_SHIFT                     0
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK)
/* FPROT2 Bit Fields */
#define NV_FPROT2_PROT_MASK                      0xFFu
#define NV_FPROT2_PROT_SHIFT                     0
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK)
/* FPROT3 Bit Fields */
#define NV_FPROT3_PROT_MASK                      0xFFu
#define NV_FPROT3_PROT_SHIFT                     0
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK)
/* FDPROT Bit Fields */
#define NV_FDPROT_DPROT_MASK                     0xFFu
#define NV_FDPROT_DPROT_SHIFT                    0
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FDPROT_DPROT_SHIFT))&NV_FDPROT_DPROT_MASK)
/* FEPROT Bit Fields */
#define NV_FEPROT_EPROT_MASK                     0xFFu
#define NV_FEPROT_EPROT_SHIFT                    0
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FEPROT_EPROT_SHIFT))&NV_FEPROT_EPROT_MASK)
/* FOPT Bit Fields */
#define NV_FOPT_LPBOOT_MASK                      0x1u
#define NV_FOPT_LPBOOT_SHIFT                     0
#define NV_FOPT_EZPORT_DIS_MASK                  0x2u
#define NV_FOPT_EZPORT_DIS_SHIFT                 1
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      0xCu
#define NV_FSEC_FSLACC_SHIFT                     2
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        0x30u
#define NV_FSEC_MEEN_SHIFT                       4
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)

/*! \} */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/*! Peripheral FTFL_FlashConfig base pointer */
#define FTFL_FlashConfig_BASE_PTR                ((NV_MemMapPtr)0x400u)

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Accessor_Macros NV - Register accessor macros */
/*! \{ */


/* NV - Register instance definitions */
/* FTFL_FlashConfig */
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT3                                NV_FPROT3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT2                                NV_FPROT2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT1                                NV_FPROT1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT0                                NV_FPROT0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FDPROT                                NV_FDPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FEPROT                                NV_FEPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FOPT                                  NV_FOPT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FSEC                                  NV_FSEC_REG(FTFL_FlashConfig_BASE_PTR)

/*! \} */ /* end of group NV_Register_Accessor_Macros */


/*! \} */ /* end of group NV_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTM
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Peripheral FTM */
/*! \{ */

/*! FTM - Peripheral register structure */
typedef struct FTM_MemMap {
  uint8_t SC;                                      /*!< Status and Control, offset: 0x0 */
  union {                                          /* offset: 0x1 */
    struct {                                         /* offset: 0x1 */
      uint8_t CNTH;                                    /*!< Counter High, offset: 0x1 */
      uint8_t CNTL;                                    /*!< Counter Low, offset: 0x2 */
    } CNT_ACCESS8BIT;
    uint16_t CNT;                                    /*!< FTM0_CNT register...FTM1_CNT register., offset: 0x1 */
  };
  union {                                          /* offset: 0x3 */
    struct {                                         /* offset: 0x3 */
      uint8_t MODH;                                    /*!< Modulo High, offset: 0x3 */
      uint8_t MODL;                                    /*!< Modulo Low, offset: 0x4 */
    } MOD_ACCESS8BIT;
    uint16_t MOD;                                    /*!< FTM0_MOD register...FTM1_MOD register., offset: 0x3 */
  };
  struct {                                         /* offset: 0x5, array step: 0x3 */
    uint8_t CnSC;                                    /*!< Channel Status and Control, array offset: 0x5, array step: 0x3 */
    union {                                          /* offset: 0x6, array step: 0x3 */
      struct {                                         /* offset: 0x6, array step: 0x3 */
        uint8_t CnVH;                                    /*!< Channel Value High, array offset: 0x6, array step: 0x3 */
        uint8_t CnVL;                                    /*!< Channel Value Low, array offset: 0x7, array step: 0x3 */
      } CV_ACCESS8BIT;
      uint16_t CnV;                                    /*!< FTM0_C0V register...FTM1_C5V register., array offset: 0x6, array step: 0x3 */
    };
  } CHANNEL[6];
  uint8_t RESERVED_0[9];
  union {                                          /* offset: 0x20 */
    struct {                                         /* offset: 0x20 */
      uint8_t CNTINH;                                  /*!< Counter Initial Value High, offset: 0x20 */
      uint8_t CNTINL;                                  /*!< Counter Initial Value Low, offset: 0x21 */
    } CNTIN_ACCESS8BIT;
    uint16_t CNTIN;                                  /*!< FTM0_CNTIN register...FTM1_CNTIN register., offset: 0x20 */
  };
  uint8_t STATUS;                                  /*!< Capture and Compare Status, offset: 0x22 */
  uint8_t MODE;                                    /*!< Features Mode Selection, offset: 0x23 */
  uint8_t SYNC;                                    /*!< Synchronization, offset: 0x24 */
  uint8_t OUTINIT;                                 /*!< Initial State for Channel Output, offset: 0x25 */
  uint8_t OUTMASK;                                 /*!< Output Mask, offset: 0x26 */
  uint8_t COMBINE[3];                              /*!< Function for Linked Channels, array offset: 0x27, array step: 0x1 */
  uint8_t RESERVED_1[1];
  uint8_t DEADTIME;                                /*!< Deadtime Insertion Control, offset: 0x2B */
  uint8_t EXTTRIG;                                 /*!< External Trigger, offset: 0x2C */
  uint8_t POL;                                     /*!< Channels Polarity, offset: 0x2D */
  uint8_t FMS;                                     /*!< Fault Mode Status, offset: 0x2E */
  uint8_t FILTER[2];                               /*!< Input Capture Filter Control, array offset: 0x2F, array step: 0x1 */
  uint8_t FLTFILTER;                               /*!< Fault Input Filter Control, offset: 0x31 */
  uint8_t FLTCTRL;                                 /*!< Fault Input Control, offset: 0x32 */
  uint8_t QDCTRL;                                  /*!< Quadrature Decoder Control and Status, offset: 0x33 */
} volatile *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros */
/*! \{ */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNTH_REG(base)                       ((base)->CNT_ACCESS8BIT.CNTH)
#define FTM_CNTL_REG(base)                       ((base)->CNT_ACCESS8BIT.CNTL)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MODH_REG(base)                       ((base)->MOD_ACCESS8BIT.MODH)
#define FTM_MODL_REG(base)                       ((base)->MOD_ACCESS8BIT.MODL)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CHANNEL[index].CnSC)
#define FTM_CnVH_REG(base,index)                 ((base)->CHANNEL[index].CV_ACCESS8BIT.CnVH)
#define FTM_CnVL_REG(base,index)                 ((base)->CHANNEL[index].CV_ACCESS8BIT.CnVL)
#define FTM_CnV_REG(base,index)                  ((base)->CHANNEL[index].CnV)
#define FTM_CNTINH_REG(base)                     ((base)->CNTIN_ACCESS8BIT.CNTINH)
#define FTM_CNTINL_REG(base)                     ((base)->CNTIN_ACCESS8BIT.CNTINL)
#define FTM_CNTIN_REG(base)                      ((base)->CNTIN)
#define FTM_STATUS_REG(base)                     ((base)->STATUS)
#define FTM_MODE_REG(base)                       ((base)->MODE)
#define FTM_SYNC_REG(base)                       ((base)->SYNC)
#define FTM_OUTINIT_REG(base)                    ((base)->OUTINIT)
#define FTM_OUTMASK_REG(base)                    ((base)->OUTMASK)
#define FTM_COMBINE_REG(base,index)              ((base)->COMBINE[index])
#define FTM_DEADTIME_REG(base)                   ((base)->DEADTIME)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)
#define FTM_POL_REG(base)                        ((base)->POL)
#define FTM_FMS_REG(base)                        ((base)->FMS)
#define FTM_FILTER_REG(base,index)               ((base)->FILTER[index])
#define FTM_FLTFILTER_REG(base)                  ((base)->FLTFILTER)
#define FTM_FLTCTRL_REG(base)                    ((base)->FLTCTRL)
#define FTM_QDCTRL_REG(base)                     ((base)->QDCTRL)

/*! \} */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Masks FTM Register Masks */
/*! \{ */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((uint8_t)(((uint8_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNTH Bit Fields */
#define FTM_CNTH_COUNT_H_MASK                    0xFFu
#define FTM_CNTH_COUNT_H_SHIFT                   0
#define FTM_CNTH_COUNT_H(x)                      (((uint8_t)(((uint8_t)(x))<<FTM_CNTH_COUNT_H_SHIFT))&FTM_CNTH_COUNT_H_MASK)
/* CNTL Bit Fields */
#define FTM_CNTL_COUNT_L_MASK                    0xFFu
#define FTM_CNTL_COUNT_L_SHIFT                   0
#define FTM_CNTL_COUNT_L(x)                      (((uint8_t)(((uint8_t)(x))<<FTM_CNTL_COUNT_L_SHIFT))&FTM_CNTL_COUNT_L_MASK)
/* CNT Bit Fields */
#define FTM_CNT_CNT_MASK                         0xFFFFu
#define FTM_CNT_CNT_SHIFT                        0
#define FTM_CNT_CNT(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CNT_CNT_SHIFT))&FTM_CNT_CNT_MASK)
/* MODH Bit Fields */
#define FTM_MODH_MOD_H_MASK                      0xFFu
#define FTM_MODH_MOD_H_SHIFT                     0
#define FTM_MODH_MOD_H(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_MODH_MOD_H_SHIFT))&FTM_MODH_MOD_H_MASK)
/* MODL Bit Fields */
#define FTM_MODL_MOD_L_MASK                      0xFFu
#define FTM_MODL_MOD_L_SHIFT                     0
#define FTM_MODL_MOD_L(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_MODL_MOD_L_SHIFT))&FTM_MODL_MOD_L_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnVH Bit Fields */
#define FTM_CnVH_VAL_H_MASK                      0xFFu
#define FTM_CnVH_VAL_H_SHIFT                     0
#define FTM_CnVH_VAL_H(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_CnVH_VAL_H_SHIFT))&FTM_CnVH_VAL_H_MASK)
/* CnVL Bit Fields */
#define FTM_CnVL_VAL_L_MASK                      0xFFu
#define FTM_CnVL_VAL_L_SHIFT                     0
#define FTM_CnVL_VAL_L(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_CnVL_VAL_L_SHIFT))&FTM_CnVL_VAL_L_MASK)
/* CnV Bit Fields */
#define FTM_CnV_C0V_MASK                         0xFFFFu
#define FTM_CnV_C0V_SHIFT                        0
#define FTM_CnV_C0V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C0V_SHIFT))&FTM_CnV_C0V_MASK)
#define FTM_CnV_C1V_MASK                         0xFFFFu
#define FTM_CnV_C1V_SHIFT                        0
#define FTM_CnV_C1V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C1V_SHIFT))&FTM_CnV_C1V_MASK)
#define FTM_CnV_C2V_MASK                         0xFFFFu
#define FTM_CnV_C2V_SHIFT                        0
#define FTM_CnV_C2V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C2V_SHIFT))&FTM_CnV_C2V_MASK)
#define FTM_CnV_C3V_MASK                         0xFFFFu
#define FTM_CnV_C3V_SHIFT                        0
#define FTM_CnV_C3V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C3V_SHIFT))&FTM_CnV_C3V_MASK)
#define FTM_CnV_C4V_MASK                         0xFFFFu
#define FTM_CnV_C4V_SHIFT                        0
#define FTM_CnV_C4V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C4V_SHIFT))&FTM_CnV_C4V_MASK)
#define FTM_CnV_C5V_MASK                         0xFFFFu
#define FTM_CnV_C5V_SHIFT                        0
#define FTM_CnV_C5V(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_C5V_SHIFT))&FTM_CnV_C5V_MASK)
/* CNTINH Bit Fields */
#define FTM_CNTINH_INIT_H_MASK                   0xFFu
#define FTM_CNTINH_INIT_H_SHIFT                  0
#define FTM_CNTINH_INIT_H(x)                     (((uint8_t)(((uint8_t)(x))<<FTM_CNTINH_INIT_H_SHIFT))&FTM_CNTINH_INIT_H_MASK)
/* CNTINL Bit Fields */
#define FTM_CNTINL_INIT_L_MASK                   0xFFu
#define FTM_CNTINL_INIT_L_SHIFT                  0
#define FTM_CNTINL_INIT_L(x)                     (((uint8_t)(((uint8_t)(x))<<FTM_CNTINL_INIT_L_SHIFT))&FTM_CNTINL_INIT_L_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_CNTIN_MASK                     0xFFFFu
#define FTM_CNTIN_CNTIN_SHIFT                    0
#define FTM_CNTIN_CNTIN(x)                       (((uint16_t)(((uint16_t)(x))<<FTM_CNTIN_CNTIN_SHIFT))&FTM_CNTIN_CNTIN_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5
#define FTM_MODE_FAULTM(x)                       (((uint8_t)(((uint8_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE_MASK                 0x1u
#define FTM_COMBINE_COMBINE_SHIFT                0
#define FTM_COMBINE_COMP_MASK                    0x2u
#define FTM_COMBINE_COMP_SHIFT                   1
#define FTM_COMBINE_DECAPEN_MASK                 0x4u
#define FTM_COMBINE_DECAPEN_SHIFT                2
#define FTM_COMBINE_DECAP_MASK                   0x8u
#define FTM_COMBINE_DECAP_SHIFT                  3
#define FTM_COMBINE_DTEN_MASK                    0x10u
#define FTM_COMBINE_DTEN_SHIFT                   4
#define FTM_COMBINE_SYNCEN_MASK                  0x20u
#define FTM_COMBINE_SYNCEN_SHIFT                 5
#define FTM_COMBINE_FAULTEN_MASK                 0x40u
#define FTM_COMBINE_FAULTEN_SHIFT                6
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0
#define FTM_DEADTIME_DTVAL(x)                    (((uint8_t)(((uint8_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#define FTM_DEADTIME_DTPS(x)                     (((uint8_t)(((uint8_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7
/* FILTER Bit Fields */
#define FTM_FILTER_CHevenFVAL_MASK               0xFu
#define FTM_FILTER_CHevenFVAL_SHIFT              0
#define FTM_FILTER_CHevenFVAL(x)                 (((uint8_t)(((uint8_t)(x))<<FTM_FILTER_CHevenFVAL_SHIFT))&FTM_FILTER_CHevenFVAL_MASK)
#define FTM_FILTER_CHoddFVAL_MASK                0xF0u
#define FTM_FILTER_CHoddFVAL_SHIFT               4
#define FTM_FILTER_CHoddFVAL(x)                  (((uint8_t)(((uint8_t)(x))<<FTM_FILTER_CHoddFVAL_SHIFT))&FTM_FILTER_CHoddFVAL_MASK)
/* FLTFILTER Bit Fields */
#define FTM_FLTFILTER_FFVAL_MASK                 0xFu
#define FTM_FLTFILTER_FFVAL_SHIFT                0
#define FTM_FLTFILTER_FFVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FLTFILTER_FFVAL_SHIFT))&FTM_FLTFILTER_FFVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7

/*! \} */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/*! Peripheral FTM0 base pointer */
#define FTM0_BASE_PTR                            ((FTM_MemMapPtr)0xFFFF8440u)
/*! Peripheral FTM1 base pointer */
#define FTM1_BASE_PTR                            ((FTM_MemMapPtr)0xFFFF8480u)

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros */
/*! \{ */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0_BASE_PTR)
#define FTM0_CNTH                                FTM_CNTH_REG(FTM0_BASE_PTR)
#define FTM0_CNTL                                FTM_CNTL_REG(FTM0_BASE_PTR)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0_BASE_PTR)
#define FTM0_MODH                                FTM_MODH_REG(FTM0_BASE_PTR)
#define FTM0_MODL                                FTM_MODL_REG(FTM0_BASE_PTR)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0_BASE_PTR)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0_BASE_PTR,0)
#define FTM0_C0VH                                FTM_CnVH_REG(FTM0_BASE_PTR,0)
#define FTM0_C0VL                                FTM_CnVL_REG(FTM0_BASE_PTR,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0_BASE_PTR,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0_BASE_PTR,1)
#define FTM0_C1VH                                FTM_CnVH_REG(FTM0_BASE_PTR,1)
#define FTM0_C1VL                                FTM_CnVL_REG(FTM0_BASE_PTR,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0_BASE_PTR,1)
#define FTM0_CNTINH                              FTM_CNTINH_REG(FTM0_BASE_PTR)
#define FTM0_CNTINL                              FTM_CNTINL_REG(FTM0_BASE_PTR)
#define FTM0_CNTIN                               FTM_CNTIN_REG(FTM0_BASE_PTR)
#define FTM0_STATUS                              FTM_STATUS_REG(FTM0_BASE_PTR)
#define FTM0_MODE                                FTM_MODE_REG(FTM0_BASE_PTR)
#define FTM0_SYNC                                FTM_SYNC_REG(FTM0_BASE_PTR)
#define FTM0_OUTINIT                             FTM_OUTINIT_REG(FTM0_BASE_PTR)
#define FTM0_OUTMASK                             FTM_OUTMASK_REG(FTM0_BASE_PTR)
#define FTM0_COMBINE0                            FTM_COMBINE_REG(FTM0_BASE_PTR,0)
#define FTM0_DEADTIME                            FTM_DEADTIME_REG(FTM0_BASE_PTR)
#define FTM0_EXTTRIG                             FTM_EXTTRIG_REG(FTM0_BASE_PTR)
#define FTM0_POL                                 FTM_POL_REG(FTM0_BASE_PTR)
#define FTM0_FMS                                 FTM_FMS_REG(FTM0_BASE_PTR)
#define FTM0_FILTER0                             FTM_FILTER_REG(FTM0_BASE_PTR,0)
#define FTM0_FLTFILTER                           FTM_FLTFILTER_REG(FTM0_BASE_PTR)
#define FTM0_FLTCTRL                             FTM_FLTCTRL_REG(FTM0_BASE_PTR)
#define FTM0_QDCTRL                              FTM_QDCTRL_REG(FTM0_BASE_PTR)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1_BASE_PTR)
#define FTM1_CNTH                                FTM_CNTH_REG(FTM1_BASE_PTR)
#define FTM1_CNTL                                FTM_CNTL_REG(FTM1_BASE_PTR)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1_BASE_PTR)
#define FTM1_MODH                                FTM_MODH_REG(FTM1_BASE_PTR)
#define FTM1_MODL                                FTM_MODL_REG(FTM1_BASE_PTR)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1_BASE_PTR)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1_BASE_PTR,0)
#define FTM1_C0VH                                FTM_CnVH_REG(FTM1_BASE_PTR,0)
#define FTM1_C0VL                                FTM_CnVL_REG(FTM1_BASE_PTR,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1_BASE_PTR,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1_BASE_PTR,1)
#define FTM1_C1VH                                FTM_CnVH_REG(FTM1_BASE_PTR,1)
#define FTM1_C1VL                                FTM_CnVL_REG(FTM1_BASE_PTR,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1_BASE_PTR,1)
#define FTM1_C2SC                                FTM_CnSC_REG(FTM1_BASE_PTR,2)
#define FTM1_C2VH                                FTM_CnVH_REG(FTM1_BASE_PTR,2)
#define FTM1_C2VL                                FTM_CnVL_REG(FTM1_BASE_PTR,2)
#define FTM1_C2V                                 FTM_CnV_REG(FTM1_BASE_PTR,2)
#define FTM1_C3SC                                FTM_CnSC_REG(FTM1_BASE_PTR,3)
#define FTM1_C3VH                                FTM_CnVH_REG(FTM1_BASE_PTR,3)
#define FTM1_C3VL                                FTM_CnVL_REG(FTM1_BASE_PTR,3)
#define FTM1_C3V                                 FTM_CnV_REG(FTM1_BASE_PTR,3)
#define FTM1_C4SC                                FTM_CnSC_REG(FTM1_BASE_PTR,4)
#define FTM1_C4VH                                FTM_CnVH_REG(FTM1_BASE_PTR,4)
#define FTM1_C4VL                                FTM_CnVL_REG(FTM1_BASE_PTR,4)
#define FTM1_C4V                                 FTM_CnV_REG(FTM1_BASE_PTR,4)
#define FTM1_C5SC                                FTM_CnSC_REG(FTM1_BASE_PTR,5)
#define FTM1_C5VH                                FTM_CnVH_REG(FTM1_BASE_PTR,5)
#define FTM1_C5VL                                FTM_CnVL_REG(FTM1_BASE_PTR,5)
#define FTM1_C5V                                 FTM_CnV_REG(FTM1_BASE_PTR,5)
#define FTM1_CNTINH                              FTM_CNTINH_REG(FTM1_BASE_PTR)
#define FTM1_CNTINL                              FTM_CNTINL_REG(FTM1_BASE_PTR)
#define FTM1_CNTIN                               FTM_CNTIN_REG(FTM1_BASE_PTR)
#define FTM1_STATUS                              FTM_STATUS_REG(FTM1_BASE_PTR)
#define FTM1_MODE                                FTM_MODE_REG(FTM1_BASE_PTR)
#define FTM1_SYNC                                FTM_SYNC_REG(FTM1_BASE_PTR)
#define FTM1_OUTINIT                             FTM_OUTINIT_REG(FTM1_BASE_PTR)
#define FTM1_OUTMASK                             FTM_OUTMASK_REG(FTM1_BASE_PTR)
#define FTM1_COMBINE0                            FTM_COMBINE_REG(FTM1_BASE_PTR,0)
#define FTM1_COMBINE1                            FTM_COMBINE_REG(FTM1_BASE_PTR,1)
#define FTM1_COMBINE2                            FTM_COMBINE_REG(FTM1_BASE_PTR,2)
#define FTM1_DEADTIME                            FTM_DEADTIME_REG(FTM1_BASE_PTR)
#define FTM1_EXTTRIG                             FTM_EXTTRIG_REG(FTM1_BASE_PTR)
#define FTM1_POL                                 FTM_POL_REG(FTM1_BASE_PTR)
#define FTM1_FMS                                 FTM_FMS_REG(FTM1_BASE_PTR)
#define FTM1_FILTER0                             FTM_FILTER_REG(FTM1_BASE_PTR,0)
#define FTM1_FILTER1                             FTM_FILTER_REG(FTM1_BASE_PTR,1)
#define FTM1_FLTFILTER                           FTM_FLTFILTER_REG(FTM1_BASE_PTR)
#define FTM1_FLTCTRL                             FTM_FLTCTRL_REG(FTM1_BASE_PTR)

/* FTM - Register array accessors */
#define FTM0_CnSC(index)                         FTM_CnSC_REG(FTM0_BASE_PTR,index)
#define FTM1_CnSC(index)                         FTM_CnSC_REG(FTM1_BASE_PTR,index)
#define FTM0_CnVH(index)                         FTM_CnVH_REG(FTM0_BASE_PTR,index)
#define FTM1_CnVH(index)                         FTM_CnVH_REG(FTM1_BASE_PTR,index)
#define FTM0_CnVL(index)                         FTM_CnVL_REG(FTM0_BASE_PTR,index)
#define FTM1_CnVL(index)                         FTM_CnVL_REG(FTM1_BASE_PTR,index)
#define FTM0_CnV(index)                          FTM_CnV_REG(FTM0_BASE_PTR,index)
#define FTM1_CnV(index)                          FTM_CnV_REG(FTM1_BASE_PTR,index)
#define FTM0_COMBINE(index)                      FTM_COMBINE_REG(FTM0_BASE_PTR,index)
#define FTM1_COMBINE(index)                      FTM_COMBINE_REG(FTM1_BASE_PTR,index)
#define FTM0_FILTER(index)                       FTM_FILTER_REG(FTM0_BASE_PTR,index)
#define FTM1_FILTER(index)                       FTM_FILTER_REG(FTM1_BASE_PTR,index)

/*! \} */ /* end of group FTM_Register_Accessor_Macros */


/*! \} */ /* end of group FTM_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Peripheral I2C */
/*! \{ */

/*! I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8_t A1;                                      /*!< I2C Address Register 1, offset: 0x0 */
  uint8_t F;                                       /*!< I2C Frequency Divider register, offset: 0x1 */
  uint8_t C1;                                      /*!< I2C Control Register 1, offset: 0x2 */
  uint8_t S;                                       /*!< I2C Status Register, offset: 0x3 */
  uint8_t D;                                       /*!< I2C Data I/O register, offset: 0x4 */
  uint8_t C2;                                      /*!< I2C Control Register 2, offset: 0x5 */
  uint8_t FLT;                                     /*!< I2C Programmable Input Glitch Filter register, offset: 0x6 */
  uint8_t RA;                                      /*!< I2C Range Address register, offset: 0x7 */
  uint8_t SMB;                                     /*!< I2C SMBus Control and Status register, offset: 0x8 */
  uint8_t A2;                                      /*!< I2C Address Register 2, offset: 0x9 */
  uint8_t SLTH;                                    /*!< I2C SCL Low Timeout Register High, offset: 0xA */
  uint8_t SLTL;                                    /*!< I2C SCL Low Timeout Register Low, offset: 0xB */
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros */
/*! \{ */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/*! \} */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Masks I2C Register Masks */
/*! \{ */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_DMAEN_MASK                        0x1u
#define I2C_C1_DMAEN_SHIFT                       0
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_HDRS_MASK                         0x20u
#define I2C_C2_HDRS_SHIFT                        5
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0xFu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK)
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK)

/*! \} */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/*! Peripheral I2C0 base pointer */
#define I2C0_BASE_PTR                            ((I2C_MemMapPtr)0xFFFF81C0u)
/*! Peripheral I2C1 base pointer */
#define I2C1_BASE_PTR                            ((I2C_MemMapPtr)0xFFFF81D0u)
/*! Peripheral I2C2 base pointer */
#define I2C2_BASE_PTR                            ((I2C_MemMapPtr)0xFFFF81E0u)
/*! Peripheral I2C3 base pointer */
#define I2C3_BASE_PTR                            ((I2C_MemMapPtr)0xFFFF81F0u)

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros */
/*! \{ */


/* I2C - Register instance definitions */
/* I2C0 */
#define I2C0_A1                                  I2C_A1_REG(I2C0_BASE_PTR)
#define I2C0_F                                   I2C_F_REG(I2C0_BASE_PTR)
#define I2C0_C1                                  I2C_C1_REG(I2C0_BASE_PTR)
#define I2C0_S                                   I2C_S_REG(I2C0_BASE_PTR)
#define I2C0_D                                   I2C_D_REG(I2C0_BASE_PTR)
#define I2C0_C2                                  I2C_C2_REG(I2C0_BASE_PTR)
#define I2C0_FLT                                 I2C_FLT_REG(I2C0_BASE_PTR)
#define I2C0_RA                                  I2C_RA_REG(I2C0_BASE_PTR)
#define I2C0_SMB                                 I2C_SMB_REG(I2C0_BASE_PTR)
#define I2C0_A2                                  I2C_A2_REG(I2C0_BASE_PTR)
#define I2C0_SLTH                                I2C_SLTH_REG(I2C0_BASE_PTR)
#define I2C0_SLTL                                I2C_SLTL_REG(I2C0_BASE_PTR)
/* I2C1 */
#define I2C1_A1                                  I2C_A1_REG(I2C1_BASE_PTR)
#define I2C1_F                                   I2C_F_REG(I2C1_BASE_PTR)
#define I2C1_C1                                  I2C_C1_REG(I2C1_BASE_PTR)
#define I2C1_S                                   I2C_S_REG(I2C1_BASE_PTR)
#define I2C1_D                                   I2C_D_REG(I2C1_BASE_PTR)
#define I2C1_C2                                  I2C_C2_REG(I2C1_BASE_PTR)
#define I2C1_FLT                                 I2C_FLT_REG(I2C1_BASE_PTR)
#define I2C1_RA                                  I2C_RA_REG(I2C1_BASE_PTR)
#define I2C1_SMB                                 I2C_SMB_REG(I2C1_BASE_PTR)
#define I2C1_A2                                  I2C_A2_REG(I2C1_BASE_PTR)
#define I2C1_SLTH                                I2C_SLTH_REG(I2C1_BASE_PTR)
#define I2C1_SLTL                                I2C_SLTL_REG(I2C1_BASE_PTR)
/* I2C2 */
#define I2C2_A1                                  I2C_A1_REG(I2C2_BASE_PTR)
#define I2C2_F                                   I2C_F_REG(I2C2_BASE_PTR)
#define I2C2_C1                                  I2C_C1_REG(I2C2_BASE_PTR)
#define I2C2_S                                   I2C_S_REG(I2C2_BASE_PTR)
#define I2C2_D                                   I2C_D_REG(I2C2_BASE_PTR)
#define I2C2_C2                                  I2C_C2_REG(I2C2_BASE_PTR)
#define I2C2_FLT                                 I2C_FLT_REG(I2C2_BASE_PTR)
#define I2C2_RA                                  I2C_RA_REG(I2C2_BASE_PTR)
#define I2C2_SMB                                 I2C_SMB_REG(I2C2_BASE_PTR)
#define I2C2_A2                                  I2C_A2_REG(I2C2_BASE_PTR)
#define I2C2_SLTH                                I2C_SLTH_REG(I2C2_BASE_PTR)
#define I2C2_SLTL                                I2C_SLTL_REG(I2C2_BASE_PTR)
/* I2C3 */
#define I2C3_A1                                  I2C_A1_REG(I2C3_BASE_PTR)
#define I2C3_F                                   I2C_F_REG(I2C3_BASE_PTR)
#define I2C3_C1                                  I2C_C1_REG(I2C3_BASE_PTR)
#define I2C3_S                                   I2C_S_REG(I2C3_BASE_PTR)
#define I2C3_D                                   I2C_D_REG(I2C3_BASE_PTR)
#define I2C3_C2                                  I2C_C2_REG(I2C3_BASE_PTR)
#define I2C3_FLT                                 I2C_FLT_REG(I2C3_BASE_PTR)
#define I2C3_RA                                  I2C_RA_REG(I2C3_BASE_PTR)
#define I2C3_SMB                                 I2C_SMB_REG(I2C3_BASE_PTR)
#define I2C3_A2                                  I2C_A2_REG(I2C3_BASE_PTR)
#define I2C3_SLTH                                I2C_SLTH_REG(I2C3_BASE_PTR)
#define I2C3_SLTL                                I2C_SLTL_REG(I2C3_BASE_PTR)

/*! \} */ /* end of group I2C_Register_Accessor_Macros */


/*! \} */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2S
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Peripheral I2S */
/*! \{ */

/*! I2S - Peripheral register structure */
typedef struct I2S_MemMap {
  uint32_t TCSR;                                   /*!< SAI Transmit Control Register, offset: 0x0 */
  uint32_t TCR1;                                   /*!< SAI Transmit Configuration 1 Register, offset: 0x4 */
  uint32_t TCR2;                                   /*!< SAI Transmit Configuration 2 Register, offset: 0x8 */
  uint32_t TCR3;                                   /*!< SAI Transmit Configuration 3 Register, offset: 0xC */
  uint32_t TCR4;                                   /*!< SAI Transmit Configuration 4 Register, offset: 0x10 */
  uint32_t TCR5;                                   /*!< SAI Transmit Configuration 5 Register, offset: 0x14 */
  uint8_t RESERVED_0[8];
  uint32_t TDR;                                    /*!< SAI Transmit Data Register, offset: 0x20 */
  uint8_t RESERVED_1[28];
  uint32_t TFR;                                    /*!< SAI Transmit FIFO Register, offset: 0x40 */
  uint8_t RESERVED_2[28];
  uint32_t TMR;                                    /*!< SAI Transmit Mask Register, offset: 0x60 */
  uint8_t RESERVED_3[28];
  uint32_t RCSR;                                   /*!< SAI Receive Control Register, offset: 0x80 */
  uint32_t RCR1;                                   /*!< SAI Receive Configuration 1 Register, offset: 0x84 */
  uint32_t RCR2;                                   /*!< SAI Receive Configuration 2 Register, offset: 0x88 */
  uint32_t RCR3;                                   /*!< SAI Receive Configuration 3 Register, offset: 0x8C */
  uint32_t RCR4;                                   /*!< SAI Receive Configuration 4 Register, offset: 0x90 */
  uint32_t RCR5;                                   /*!< SAI Receive Configuration 5 Register, offset: 0x94 */
  uint8_t RESERVED_4[8];
  uint32_t RDR;                                    /*!< SAI Receive Data Register, offset: 0xA0 */
  uint8_t RESERVED_5[28];
  uint32_t RFR;                                    /*!< SAI Receive FIFO Register, offset: 0xC0 */
  uint8_t RESERVED_6[28];
  uint32_t RMR;                                    /*!< SAI Receive Mask Register, offset: 0xE0 */
  uint8_t RESERVED_7[28];
  uint32_t MCR;                                    /*!< SAI MCLK Control Register, offset: 0x100 */
  uint32_t MDR;                                    /*!< MCLK Divide Register, offset: 0x104 */
} volatile *I2S_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros */
/*! \{ */


/* I2S - Register accessors */
#define I2S_TCSR_REG(base)                       ((base)->TCSR)
#define I2S_TCR1_REG(base)                       ((base)->TCR1)
#define I2S_TCR2_REG(base)                       ((base)->TCR2)
#define I2S_TCR3_REG(base)                       ((base)->TCR3)
#define I2S_TCR4_REG(base)                       ((base)->TCR4)
#define I2S_TCR5_REG(base)                       ((base)->TCR5)
#define I2S_TDR_REG(base)                        ((base)->TDR)
#define I2S_TFR_REG(base)                        ((base)->TFR)
#define I2S_TMR_REG(base)                        ((base)->TMR)
#define I2S_RCSR_REG(base)                       ((base)->RCSR)
#define I2S_RCR1_REG(base)                       ((base)->RCR1)
#define I2S_RCR2_REG(base)                       ((base)->RCR2)
#define I2S_RCR3_REG(base)                       ((base)->RCR3)
#define I2S_RCR4_REG(base)                       ((base)->RCR4)
#define I2S_RCR5_REG(base)                       ((base)->RCR5)
#define I2S_RDR_REG(base)                        ((base)->RDR)
#define I2S_RFR_REG(base)                        ((base)->RFR)
#define I2S_RMR_REG(base)                        ((base)->RMR)
#define I2S_MCR_REG(base)                        ((base)->MCR)
#define I2S_MDR_REG(base)                        ((base)->MDR)

/*! \} */ /* end of group I2S_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Masks I2S Register Masks */
/*! \{ */

/* TCSR Bit Fields */
#define I2S_TCSR_FRDE_MASK                       0x1u
#define I2S_TCSR_FRDE_SHIFT                      0
#define I2S_TCSR_FWDE_MASK                       0x2u
#define I2S_TCSR_FWDE_SHIFT                      1
#define I2S_TCSR_FRIE_MASK                       0x100u
#define I2S_TCSR_FRIE_SHIFT                      8
#define I2S_TCSR_FWIE_MASK                       0x200u
#define I2S_TCSR_FWIE_SHIFT                      9
#define I2S_TCSR_FEIE_MASK                       0x400u
#define I2S_TCSR_FEIE_SHIFT                      10
#define I2S_TCSR_SEIE_MASK                       0x800u
#define I2S_TCSR_SEIE_SHIFT                      11
#define I2S_TCSR_WSIE_MASK                       0x1000u
#define I2S_TCSR_WSIE_SHIFT                      12
#define I2S_TCSR_FRF_MASK                        0x10000u
#define I2S_TCSR_FRF_SHIFT                       16
#define I2S_TCSR_FWF_MASK                        0x20000u
#define I2S_TCSR_FWF_SHIFT                       17
#define I2S_TCSR_FEF_MASK                        0x40000u
#define I2S_TCSR_FEF_SHIFT                       18
#define I2S_TCSR_SEF_MASK                        0x80000u
#define I2S_TCSR_SEF_SHIFT                       19
#define I2S_TCSR_WSF_MASK                        0x100000u
#define I2S_TCSR_WSF_SHIFT                       20
#define I2S_TCSR_SR_MASK                         0x1000000u
#define I2S_TCSR_SR_SHIFT                        24
#define I2S_TCSR_FR_MASK                         0x2000000u
#define I2S_TCSR_FR_SHIFT                        25
#define I2S_TCSR_BCE_MASK                        0x10000000u
#define I2S_TCSR_BCE_SHIFT                       28
#define I2S_TCSR_DBGE_MASK                       0x20000000u
#define I2S_TCSR_DBGE_SHIFT                      29
#define I2S_TCSR_STOPE_MASK                      0x40000000u
#define I2S_TCSR_STOPE_SHIFT                     30
#define I2S_TCSR_TE_MASK                         0x80000000u
#define I2S_TCSR_TE_SHIFT                        31
/* TCR1 Bit Fields */
#define I2S_TCR1_TFW_MASK                        0x3u
#define I2S_TCR1_TFW_SHIFT                       0
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK)
/* TCR2 Bit Fields */
#define I2S_TCR2_DIV_MASK                        0xFFu
#define I2S_TCR2_DIV_SHIFT                       0
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK)
#define I2S_TCR2_BCD_MASK                        0x1000000u
#define I2S_TCR2_BCD_SHIFT                       24
#define I2S_TCR2_BCP_MASK                        0x2000000u
#define I2S_TCR2_BCP_SHIFT                       25
#define I2S_TCR2_CLKMODE_MASK                    0xC000000u
#define I2S_TCR2_CLKMODE_SHIFT                   26
#define I2S_TCR2_CLKMODE(x)                      (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_CLKMODE_SHIFT))&I2S_TCR2_CLKMODE_MASK)
/* TCR3 Bit Fields */
#define I2S_TCR3_WDFL_MASK                       0xFu
#define I2S_TCR3_WDFL_SHIFT                      0
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK)
#define I2S_TCR3_TCE_MASK                        0x10000u
#define I2S_TCR3_TCE_SHIFT                       16
/* TCR4 Bit Fields */
#define I2S_TCR4_FSD_MASK                        0x1u
#define I2S_TCR4_FSD_SHIFT                       0
#define I2S_TCR4_FSP_MASK                        0x2u
#define I2S_TCR4_FSP_SHIFT                       1
#define I2S_TCR4_FSE_MASK                        0x8u
#define I2S_TCR4_FSE_SHIFT                       3
#define I2S_TCR4_MF_MASK                         0x10u
#define I2S_TCR4_MF_SHIFT                        4
#define I2S_TCR4_SYWD_MASK                       0x1F00u
#define I2S_TCR4_SYWD_SHIFT                      8
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK)
#define I2S_TCR4_FRSZ_MASK                       0xF0000u
#define I2S_TCR4_FRSZ_SHIFT                      16
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK)
/* TCR5 Bit Fields */
#define I2S_TCR5_FBT_MASK                        0x1F00u
#define I2S_TCR5_FBT_SHIFT                       8
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK)
#define I2S_TCR5_W0W_MASK                        0x1F0000u
#define I2S_TCR5_W0W_SHIFT                       16
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK)
#define I2S_TCR5_WNW_MASK                        0x1F000000u
#define I2S_TCR5_WNW_SHIFT                       24
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK)
/* TDR Bit Fields */
#define I2S_TDR_TDR_MASK                         0xFFFFFFFFu
#define I2S_TDR_TDR_SHIFT                        0
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK)
/* TFR Bit Fields */
#define I2S_TFR_RFP_MASK                         0x7u
#define I2S_TFR_RFP_SHIFT                        0
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK                         0x70000u
#define I2S_TFR_WFP_SHIFT                        16
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK)
/* TMR Bit Fields */
#define I2S_TMR_TWM_MASK                         0xFFFFu
#define I2S_TMR_TWM_SHIFT                        0
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK)
/* RCSR Bit Fields */
#define I2S_RCSR_FRDE_MASK                       0x1u
#define I2S_RCSR_FRDE_SHIFT                      0
#define I2S_RCSR_FWDE_MASK                       0x2u
#define I2S_RCSR_FWDE_SHIFT                      1
#define I2S_RCSR_FRIE_MASK                       0x100u
#define I2S_RCSR_FRIE_SHIFT                      8
#define I2S_RCSR_FWIE_MASK                       0x200u
#define I2S_RCSR_FWIE_SHIFT                      9
#define I2S_RCSR_FEIE_MASK                       0x400u
#define I2S_RCSR_FEIE_SHIFT                      10
#define I2S_RCSR_SEIE_MASK                       0x800u
#define I2S_RCSR_SEIE_SHIFT                      11
#define I2S_RCSR_WSIE_MASK                       0x1000u
#define I2S_RCSR_WSIE_SHIFT                      12
#define I2S_RCSR_FRF_MASK                        0x10000u
#define I2S_RCSR_FRF_SHIFT                       16
#define I2S_RCSR_FWF_MASK                        0x20000u
#define I2S_RCSR_FWF_SHIFT                       17
#define I2S_RCSR_FEF_MASK                        0x40000u
#define I2S_RCSR_FEF_SHIFT                       18
#define I2S_RCSR_SEF_MASK                        0x80000u
#define I2S_RCSR_SEF_SHIFT                       19
#define I2S_RCSR_WSF_MASK                        0x100000u
#define I2S_RCSR_WSF_SHIFT                       20
#define I2S_RCSR_SR_MASK                         0x1000000u
#define I2S_RCSR_SR_SHIFT                        24
#define I2S_RCSR_FR_MASK                         0x2000000u
#define I2S_RCSR_FR_SHIFT                        25
#define I2S_RCSR_BCE_MASK                        0x10000000u
#define I2S_RCSR_BCE_SHIFT                       28
#define I2S_RCSR_DBGE_MASK                       0x20000000u
#define I2S_RCSR_DBGE_SHIFT                      29
#define I2S_RCSR_STOPE_MASK                      0x40000000u
#define I2S_RCSR_STOPE_SHIFT                     30
#define I2S_RCSR_RE_MASK                         0x80000000u
#define I2S_RCSR_RE_SHIFT                        31
/* RCR1 Bit Fields */
#define I2S_RCR1_RFW_MASK                        0x3u
#define I2S_RCR1_RFW_SHIFT                       0
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK)
/* RCR2 Bit Fields */
#define I2S_RCR2_DIV_MASK                        0xFFu
#define I2S_RCR2_DIV_SHIFT                       0
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK)
#define I2S_RCR2_BCD_MASK                        0x1000000u
#define I2S_RCR2_BCD_SHIFT                       24
#define I2S_RCR2_BCP_MASK                        0x2000000u
#define I2S_RCR2_BCP_SHIFT                       25
#define I2S_RCR2_CLKMODE_MASK                    0xC000000u
#define I2S_RCR2_CLKMODE_SHIFT                   26
#define I2S_RCR2_CLKMODE(x)                      (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_CLKMODE_SHIFT))&I2S_RCR2_CLKMODE_MASK)
/* RCR3 Bit Fields */
#define I2S_RCR3_WDFL_MASK                       0xFu
#define I2S_RCR3_WDFL_SHIFT                      0
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK)
#define I2S_RCR3_RCE_MASK                        0x10000u
#define I2S_RCR3_RCE_SHIFT                       16
/* RCR4 Bit Fields */
#define I2S_RCR4_FSD_MASK                        0x1u
#define I2S_RCR4_FSD_SHIFT                       0
#define I2S_RCR4_FSP_MASK                        0x2u
#define I2S_RCR4_FSP_SHIFT                       1
#define I2S_RCR4_FSE_MASK                        0x8u
#define I2S_RCR4_FSE_SHIFT                       3
#define I2S_RCR4_MF_MASK                         0x10u
#define I2S_RCR4_MF_SHIFT                        4
#define I2S_RCR4_SYWD_MASK                       0x1F00u
#define I2S_RCR4_SYWD_SHIFT                      8
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK)
#define I2S_RCR4_FRSZ_MASK                       0xF0000u
#define I2S_RCR4_FRSZ_SHIFT                      16
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK)
/* RCR5 Bit Fields */
#define I2S_RCR5_FBT_MASK                        0x1F00u
#define I2S_RCR5_FBT_SHIFT                       8
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK)
#define I2S_RCR5_W0W_MASK                        0x1F0000u
#define I2S_RCR5_W0W_SHIFT                       16
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK)
#define I2S_RCR5_WNW_MASK                        0x1F000000u
#define I2S_RCR5_WNW_SHIFT                       24
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK)
/* RDR Bit Fields */
#define I2S_RDR_RDR_MASK                         0xFFFFFFFFu
#define I2S_RDR_RDR_SHIFT                        0
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK)
/* RFR Bit Fields */
#define I2S_RFR_RFP_MASK                         0x7u
#define I2S_RFR_RFP_SHIFT                        0
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK)
#define I2S_RFR_WFP_MASK                         0x70000u
#define I2S_RFR_WFP_SHIFT                        16
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK)
/* RMR Bit Fields */
#define I2S_RMR_RWM_MASK                         0xFFFFu
#define I2S_RMR_RWM_SHIFT                        0
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK)
/* MCR Bit Fields */
#define I2S_MCR_MICS_MASK                        0x3000000u
#define I2S_MCR_MICS_SHIFT                       24
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK)
#define I2S_MCR_MOE_MASK                         0x40000000u
#define I2S_MCR_MOE_SHIFT                        30
#define I2S_MCR_DUF_MASK                         0x80000000u
#define I2S_MCR_DUF_SHIFT                        31
/* MDR Bit Fields */
#define I2S_MDR_DIVIDE_MASK                      0xFFFu
#define I2S_MDR_DIVIDE_SHIFT                     0
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_MDR_DIVIDE_SHIFT))&I2S_MDR_DIVIDE_MASK)
#define I2S_MDR_FRACT_MASK                       0xFF000u
#define I2S_MDR_FRACT_SHIFT                      12
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_MDR_FRACT_SHIFT))&I2S_MDR_FRACT_MASK)

/*! \} */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/*! Peripheral I2S0 base pointer */
#define I2S0_BASE_PTR                            ((I2S_MemMapPtr)0xFFFF8200u)

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros */
/*! \{ */


/* I2S - Register instance definitions */
/* I2S0 */
#define I2S0_TCSR                                I2S_TCSR_REG(I2S0_BASE_PTR)
#define I2S0_TCR1                                I2S_TCR1_REG(I2S0_BASE_PTR)
#define I2S0_TCR2                                I2S_TCR2_REG(I2S0_BASE_PTR)
#define I2S0_TCR3                                I2S_TCR3_REG(I2S0_BASE_PTR)
#define I2S0_TCR4                                I2S_TCR4_REG(I2S0_BASE_PTR)
#define I2S0_TCR5                                I2S_TCR5_REG(I2S0_BASE_PTR)
#define I2S0_TDR                                 I2S_TDR_REG(I2S0_BASE_PTR)
#define I2S0_TFR                                 I2S_TFR_REG(I2S0_BASE_PTR)
#define I2S0_TMR                                 I2S_TMR_REG(I2S0_BASE_PTR)
#define I2S0_RCSR                                I2S_RCSR_REG(I2S0_BASE_PTR)
#define I2S0_RCR1                                I2S_RCR1_REG(I2S0_BASE_PTR)
#define I2S0_RCR2                                I2S_RCR2_REG(I2S0_BASE_PTR)
#define I2S0_RCR3                                I2S_RCR3_REG(I2S0_BASE_PTR)
#define I2S0_RCR4                                I2S_RCR4_REG(I2S0_BASE_PTR)
#define I2S0_RCR5                                I2S_RCR5_REG(I2S0_BASE_PTR)
#define I2S0_RDR                                 I2S_RDR_REG(I2S0_BASE_PTR)
#define I2S0_RFR                                 I2S_RFR_REG(I2S0_BASE_PTR)
#define I2S0_RMR                                 I2S_RMR_REG(I2S0_BASE_PTR)
#define I2S0_MCR                                 I2S_MCR_REG(I2S0_BASE_PTR)
#define I2S0_MDR                                 I2S_MDR_REG(I2S0_BASE_PTR)

/*! \} */ /* end of group I2S_Register_Accessor_Macros */


/*! \} */ /* end of group I2S_Peripheral */


/* ----------------------------------------------------------------------------
   -- INTC
   ---------------------------------------------------------------------------- */

/*! \addtogroup INTC_Peripheral INTC */
/*! \{ */

/*! INTC - Peripheral register structure */
typedef struct INTC_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t IMRH;                                   /*!< Interrupt Mask Register High, offset: 0x8 */
  uint32_t IMRL;                                   /*!< Interrupt Mask Register Low, offset: 0xC */
  uint8_t FRC;                                     /*!< Force Interrupt Register, offset: 0x10 */
  uint8_t RESERVED_1[7];
  uint8_t PL6P[2];                                 /*!< INTC Programmable Level 6 Priority Registers, array offset: 0x18, array step: 0x1 */
  uint8_t RESERVED_2[1];
  uint8_t WCR;                                     /*!< INTC Wakeup Control Register, offset: 0x1B */
  uint8_t SIMR;                                    /*!< Set Interrupt Mask Register, offset: 0x1C */
  uint8_t CIMR;                                    /*!< Clear Interrupt Mask Register, offset: 0x1D */
  uint8_t SFRC;                                    /*!< INTC Set Interrupt Force Register, offset: 0x1E */
  uint8_t CFRC;                                    /*!< INTC Clear Interrupt Force Register, offset: 0x1F */
  uint8_t SWIACK;                                  /*!< INTC Software IACK Register, offset: 0x20 */
  uint8_t RESERVED_3[3];
  struct {                                         /* offset: 0x24, array step: 0x4 */
    uint8_t LVLIACK;                                 /*!< INTC Level-n IACK Registers, array offset: 0x24, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } LVLIACK[7];
} volatile *INTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- INTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup INTC_Register_Accessor_Macros INTC - Register accessor macros */
/*! \{ */


/* INTC - Register accessors */
#define INTC_IMRH_REG(base)                      ((base)->IMRH)
#define INTC_IMRL_REG(base)                      ((base)->IMRL)
#define INTC_FRC_REG(base)                       ((base)->FRC)
#define INTC_PL6P_REG(base,index)                ((base)->PL6P[index])
#define INTC_WCR_REG(base)                       ((base)->WCR)
#define INTC_SIMR_REG(base)                      ((base)->SIMR)
#define INTC_CIMR_REG(base)                      ((base)->CIMR)
#define INTC_SFRC_REG(base)                      ((base)->SFRC)
#define INTC_CFRC_REG(base)                      ((base)->CFRC)
#define INTC_SWIACK_REG(base)                    ((base)->SWIACK)
#define INTC_LVLIACK_REG(base,index)             ((base)->LVLIACK[index].LVLIACK)

/*! \} */ /* end of group INTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- INTC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup INTC_Register_Masks INTC Register Masks */
/*! \{ */

/* IMRH Bit Fields */
#define INTC_IMRH_IMR32_MASK                     0x1u
#define INTC_IMRH_IMR32_SHIFT                    0
#define INTC_IMRH_IMR33_MASK                     0x2u
#define INTC_IMRH_IMR33_SHIFT                    1
#define INTC_IMRH_IMR34_MASK                     0x4u
#define INTC_IMRH_IMR34_SHIFT                    2
#define INTC_IMRH_IMR35_MASK                     0x8u
#define INTC_IMRH_IMR35_SHIFT                    3
#define INTC_IMRH_IMR36_MASK                     0x10u
#define INTC_IMRH_IMR36_SHIFT                    4
#define INTC_IMRH_IMR37_MASK                     0x20u
#define INTC_IMRH_IMR37_SHIFT                    5
#define INTC_IMRH_IMR38_MASK                     0x40u
#define INTC_IMRH_IMR38_SHIFT                    6
#define INTC_IMRH_IMR39_MASK                     0x80u
#define INTC_IMRH_IMR39_SHIFT                    7
#define INTC_IMRH_IMR40_MASK                     0x100u
#define INTC_IMRH_IMR40_SHIFT                    8
#define INTC_IMRH_IMR41_MASK                     0x200u
#define INTC_IMRH_IMR41_SHIFT                    9
#define INTC_IMRH_IMR42_MASK                     0x400u
#define INTC_IMRH_IMR42_SHIFT                    10
#define INTC_IMRH_IMR43_MASK                     0x800u
#define INTC_IMRH_IMR43_SHIFT                    11
/* IMRL Bit Fields */
#define INTC_IMRL_IMR0_MASK                      0x1u
#define INTC_IMRL_IMR0_SHIFT                     0
#define INTC_IMRL_IMR1_MASK                      0x2u
#define INTC_IMRL_IMR1_SHIFT                     1
#define INTC_IMRL_IMR2_MASK                      0x4u
#define INTC_IMRL_IMR2_SHIFT                     2
#define INTC_IMRL_IMR3_MASK                      0x8u
#define INTC_IMRL_IMR3_SHIFT                     3
#define INTC_IMRL_IMR4_MASK                      0x10u
#define INTC_IMRL_IMR4_SHIFT                     4
#define INTC_IMRL_IMR5_MASK                      0x20u
#define INTC_IMRL_IMR5_SHIFT                     5
#define INTC_IMRL_IMR6_MASK                      0x40u
#define INTC_IMRL_IMR6_SHIFT                     6
#define INTC_IMRL_IMR7_MASK                      0x80u
#define INTC_IMRL_IMR7_SHIFT                     7
#define INTC_IMRL_IMR8_MASK                      0x100u
#define INTC_IMRL_IMR8_SHIFT                     8
#define INTC_IMRL_IMR9_MASK                      0x200u
#define INTC_IMRL_IMR9_SHIFT                     9
#define INTC_IMRL_IMR10_MASK                     0x400u
#define INTC_IMRL_IMR10_SHIFT                    10
#define INTC_IMRL_IMR11_MASK                     0x800u
#define INTC_IMRL_IMR11_SHIFT                    11
#define INTC_IMRL_IMR12_MASK                     0x1000u
#define INTC_IMRL_IMR12_SHIFT                    12
#define INTC_IMRL_IMR13_MASK                     0x2000u
#define INTC_IMRL_IMR13_SHIFT                    13
#define INTC_IMRL_IMR14_MASK                     0x4000u
#define INTC_IMRL_IMR14_SHIFT                    14
#define INTC_IMRL_IMR15_MASK                     0x8000u
#define INTC_IMRL_IMR15_SHIFT                    15
#define INTC_IMRL_IMR16_MASK                     0x10000u
#define INTC_IMRL_IMR16_SHIFT                    16
#define INTC_IMRL_IMR17_MASK                     0x20000u
#define INTC_IMRL_IMR17_SHIFT                    17
#define INTC_IMRL_IMR18_MASK                     0x40000u
#define INTC_IMRL_IMR18_SHIFT                    18
#define INTC_IMRL_IMR19_MASK                     0x80000u
#define INTC_IMRL_IMR19_SHIFT                    19
#define INTC_IMRL_IMR20_MASK                     0x100000u
#define INTC_IMRL_IMR20_SHIFT                    20
#define INTC_IMRL_IMR21_MASK                     0x200000u
#define INTC_IMRL_IMR21_SHIFT                    21
#define INTC_IMRL_IMR22_MASK                     0x400000u
#define INTC_IMRL_IMR22_SHIFT                    22
#define INTC_IMRL_IMR23_MASK                     0x800000u
#define INTC_IMRL_IMR23_SHIFT                    23
#define INTC_IMRL_IMR24_MASK                     0x1000000u
#define INTC_IMRL_IMR24_SHIFT                    24
#define INTC_IMRL_IMR25_MASK                     0x2000000u
#define INTC_IMRL_IMR25_SHIFT                    25
#define INTC_IMRL_IMR26_MASK                     0x4000000u
#define INTC_IMRL_IMR26_SHIFT                    26
#define INTC_IMRL_IMR27_MASK                     0x8000000u
#define INTC_IMRL_IMR27_SHIFT                    27
#define INTC_IMRL_IMR28_MASK                     0x10000000u
#define INTC_IMRL_IMR28_SHIFT                    28
#define INTC_IMRL_IMR29_MASK                     0x20000000u
#define INTC_IMRL_IMR29_SHIFT                    29
#define INTC_IMRL_IMR30_MASK                     0x40000000u
#define INTC_IMRL_IMR30_SHIFT                    30
#define INTC_IMRL_IMR31_MASK                     0x80000000u
#define INTC_IMRL_IMR31_SHIFT                    31
/* FRC Bit Fields */
#define INTC_FRC_LVL7_MASK                       0x1u
#define INTC_FRC_LVL7_SHIFT                      0
#define INTC_FRC_LVL6_MASK                       0x2u
#define INTC_FRC_LVL6_SHIFT                      1
#define INTC_FRC_LVL5_MASK                       0x4u
#define INTC_FRC_LVL5_SHIFT                      2
#define INTC_FRC_LVL4_MASK                       0x8u
#define INTC_FRC_LVL4_SHIFT                      3
#define INTC_FRC_LVL3_MASK                       0x10u
#define INTC_FRC_LVL3_SHIFT                      4
#define INTC_FRC_LVL2_MASK                       0x20u
#define INTC_FRC_LVL2_SHIFT                      5
#define INTC_FRC_LVL1_MASK                       0x40u
#define INTC_FRC_LVL1_SHIFT                      6
/* PL6P Bit Fields */
#define INTC_PL6P_REQN_MASK                      0x3Fu
#define INTC_PL6P_REQN_SHIFT                     0
#define INTC_PL6P_REQN(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_PL6P_REQN_SHIFT))&INTC_PL6P_REQN_MASK)
/* WCR Bit Fields */
#define INTC_WCR_MASK_MASK                       0x7u
#define INTC_WCR_MASK_SHIFT                      0
#define INTC_WCR_MASK(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_WCR_MASK_SHIFT))&INTC_WCR_MASK_MASK)
#define INTC_WCR_ENB_MASK                        0x80u
#define INTC_WCR_ENB_SHIFT                       7
/* SIMR Bit Fields */
#define INTC_SIMR_SIMR_MASK                      0x3Fu
#define INTC_SIMR_SIMR_SHIFT                     0
#define INTC_SIMR_SIMR(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_SIMR_SIMR_SHIFT))&INTC_SIMR_SIMR_MASK)
#define INTC_SIMR_SALL_MASK                      0x40u
#define INTC_SIMR_SALL_SHIFT                     6
/* CIMR Bit Fields */
#define INTC_CIMR_CIMR_MASK                      0x3Fu
#define INTC_CIMR_CIMR_SHIFT                     0
#define INTC_CIMR_CIMR(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_CIMR_CIMR_SHIFT))&INTC_CIMR_CIMR_MASK)
#define INTC_CIMR_CALL_MASK                      0x40u
#define INTC_CIMR_CALL_SHIFT                     6
/* SFRC Bit Fields */
#define INTC_SFRC_SET_MASK                       0x3Fu
#define INTC_SFRC_SET_SHIFT                      0
#define INTC_SFRC_SET(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_SFRC_SET_SHIFT))&INTC_SFRC_SET_MASK)
/* CFRC Bit Fields */
#define INTC_CFRC_CLR_MASK                       0x3Fu
#define INTC_CFRC_CLR_SHIFT                      0
#define INTC_CFRC_CLR(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_CFRC_CLR_SHIFT))&INTC_CFRC_CLR_MASK)
/* SWIACK Bit Fields */
#define INTC_SWIACK_VECN_MASK                    0x7Fu
#define INTC_SWIACK_VECN_SHIFT                   0
#define INTC_SWIACK_VECN(x)                      (((uint8_t)(((uint8_t)(x))<<INTC_SWIACK_VECN_SHIFT))&INTC_SWIACK_VECN_MASK)
/* LVLIACK Bit Fields */
#define INTC_LVLIACK_VECN_MASK                   0x7Fu
#define INTC_LVLIACK_VECN_SHIFT                  0
#define INTC_LVLIACK_VECN(x)                     (((uint8_t)(((uint8_t)(x))<<INTC_LVLIACK_VECN_SHIFT))&INTC_LVLIACK_VECN_MASK)

/*! \} */ /* end of group INTC_Register_Masks */


/* INTC - Peripheral instance base addresses */
/*! Peripheral INTC base pointer */
#define INTC_BASE_PTR                            ((INTC_MemMapPtr)0xFFFFFFC0u)

/* ----------------------------------------------------------------------------
   -- INTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup INTC_Register_Accessor_Macros INTC - Register accessor macros */
/*! \{ */


/* INTC - Register instance definitions */
/* INTC */
#define INTC_IMRH                                INTC_IMRH_REG(INTC_BASE_PTR)
#define INTC_IMRL                                INTC_IMRL_REG(INTC_BASE_PTR)
#define INTC_FRC                                 INTC_FRC_REG(INTC_BASE_PTR)
#define INTC_PL6P7                               INTC_PL6P_REG(INTC_BASE_PTR,0)
#define INTC_PL6P6                               INTC_PL6P_REG(INTC_BASE_PTR,1)
#define INTC_WCR                                 INTC_WCR_REG(INTC_BASE_PTR)
#define INTC_SIMR                                INTC_SIMR_REG(INTC_BASE_PTR)
#define INTC_CIMR                                INTC_CIMR_REG(INTC_BASE_PTR)
#define INTC_SFRC                                INTC_SFRC_REG(INTC_BASE_PTR)
#define INTC_CFRC                                INTC_CFRC_REG(INTC_BASE_PTR)
#define INTC_SWIACK                              INTC_SWIACK_REG(INTC_BASE_PTR)
#define INTC_LVL1IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,0)
#define INTC_LVL2IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,1)
#define INTC_LVL3IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,2)
#define INTC_LVL4IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,3)
#define INTC_LVL5IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,4)
#define INTC_LVL6IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,5)
#define INTC_LVL7IACK                            INTC_LVLIACK_REG(INTC_BASE_PTR,6)

/* INTC - Register array accessors */
#define INTC_PL6P(index)                         INTC_PL6P_REG(INTC_BASE_PTR,index)
#define INTC_LVLIACK(index)                      INTC_LVLIACK_REG(INTC_BASE_PTR,index)

/*! \} */ /* end of group INTC_Register_Accessor_Macros */


/*! \} */ /* end of group INTC_Peripheral */


/* ----------------------------------------------------------------------------
   -- IRQ
   ---------------------------------------------------------------------------- */

/*! \addtogroup IRQ_Peripheral IRQ */
/*! \{ */

/*! IRQ - Peripheral register structure */
typedef struct IRQ_MemMap {
  uint8_t SC;                                      /*!< Interrupt status and control register, offset: 0x0 */
} volatile *IRQ_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros */
/*! \{ */


/* IRQ - Register accessors */
#define IRQ_SC_REG(base)                         ((base)->SC)

/*! \} */ /* end of group IRQ_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- IRQ Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup IRQ_Register_Masks IRQ Register Masks */
/*! \{ */

/* SC Bit Fields */
#define IRQ_SC_IRQMOD_MASK                       0x1u
#define IRQ_SC_IRQMOD_SHIFT                      0
#define IRQ_SC_IRQIE_MASK                        0x2u
#define IRQ_SC_IRQIE_SHIFT                       1
#define IRQ_SC_IRQACK_MASK                       0x4u
#define IRQ_SC_IRQACK_SHIFT                      2
#define IRQ_SC_IRQF_MASK                         0x8u
#define IRQ_SC_IRQF_SHIFT                        3
#define IRQ_SC_IRQPE_MASK                        0x10u
#define IRQ_SC_IRQPE_SHIFT                       4
#define IRQ_SC_IRQEDG_MASK                       0x20u
#define IRQ_SC_IRQEDG_SHIFT                      5
#define IRQ_SC_IRQPDD_MASK                       0x40u
#define IRQ_SC_IRQPDD_SHIFT                      6

/*! \} */ /* end of group IRQ_Register_Masks */


/* IRQ - Peripheral instance base addresses */
/*! Peripheral IRQ base pointer */
#define IRQ_BASE_PTR                             ((IRQ_MemMapPtr)0xFFFF80A0u)

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros */
/*! \{ */


/* IRQ - Register instance definitions */
/* IRQ */
#define IRQ_SC                                   IRQ_SC_REG(IRQ_BASE_PTR)

/*! \} */ /* end of group IRQ_Register_Accessor_Macros */


/*! \} */ /* end of group IRQ_Peripheral */


/* ----------------------------------------------------------------------------
   -- LLWU
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Peripheral LLWU */
/*! \{ */

/*! LLWU - Peripheral register structure */
typedef struct LLWU_MemMap {
  uint8_t PE1;                                     /*!< LLWU Pin Enable 1 Register, offset: 0x0 */
  uint8_t PE2;                                     /*!< LLWU Pin Enable 2 Register, offset: 0x1 */
  uint8_t PE3;                                     /*!< LLWU Pin Enable 3 Register, offset: 0x2 */
  uint8_t PE4;                                     /*!< LLWU Pin Enable 4 Register, offset: 0x3 */
  uint8_t ME;                                      /*!< LLWU Module Enable Register, offset: 0x4 */
  uint8_t F1;                                      /*!< LLWU Flag 1 Register, offset: 0x5 */
  uint8_t F2;                                      /*!< LLWU Flag 2 Register, offset: 0x6 */
  uint8_t F3;                                      /*!< LLWU Flag 3 Register, offset: 0x7 */
  uint8_t FILT1;                                   /*!< LLWU Pin Filter 1 Register, offset: 0x8 */
  uint8_t FILT2;                                   /*!< LLWU Pin Filter 2 Register, offset: 0x9 */
  uint8_t RST;                                     /*!< LLWU Reset Enable Register, offset: 0xA */
} volatile *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros */
/*! \{ */


/* LLWU - Register accessors */
#define LLWU_PE1_REG(base)                       ((base)->PE1)
#define LLWU_PE2_REG(base)                       ((base)->PE2)
#define LLWU_PE3_REG(base)                       ((base)->PE3)
#define LLWU_PE4_REG(base)                       ((base)->PE4)
#define LLWU_ME_REG(base)                        ((base)->ME)
#define LLWU_F1_REG(base)                        ((base)->F1)
#define LLWU_F2_REG(base)                        ((base)->F2)
#define LLWU_F3_REG(base)                        ((base)->F3)
#define LLWU_FILT1_REG(base)                     ((base)->FILT1)
#define LLWU_FILT2_REG(base)                     ((base)->FILT2)
#define LLWU_RST_REG(base)                       ((base)->RST)

/*! \} */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Masks LLWU Register Masks */
/*! \{ */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE4_MASK                      0x3u
#define LLWU_PE2_WUPE4_SHIFT                     0
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      0xCu
#define LLWU_PE2_WUPE5_SHIFT                     2
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      0xC0u
#define LLWU_PE2_WUPE7_SHIFT                     6
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK)
/* PE3 Bit Fields */
#define LLWU_PE3_WUPE8_MASK                      0x3u
#define LLWU_PE3_WUPE8_SHIFT                     0
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      0xCu
#define LLWU_PE3_WUPE9_SHIFT                     2
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     0x30u
#define LLWU_PE3_WUPE10_SHIFT                    4
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     0xC0u
#define LLWU_PE3_WUPE11_SHIFT                    6
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK)
/* PE4 Bit Fields */
#define LLWU_PE4_WUPE12_MASK                     0x3u
#define LLWU_PE4_WUPE12_SHIFT                    0
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     0xCu
#define LLWU_PE4_WUPE13_SHIFT                    2
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT                    4
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     0xC0u
#define LLWU_PE4_WUPE15_SHIFT                    6
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
/* F1 Bit Fields */
#define LLWU_F1_WUF0_MASK                        0x1u
#define LLWU_F1_WUF0_SHIFT                       0
#define LLWU_F1_WUF1_MASK                        0x2u
#define LLWU_F1_WUF1_SHIFT                       1
#define LLWU_F1_WUF2_MASK                        0x4u
#define LLWU_F1_WUF2_SHIFT                       2
#define LLWU_F1_WUF3_MASK                        0x8u
#define LLWU_F1_WUF3_SHIFT                       3
#define LLWU_F1_WUF4_MASK                        0x10u
#define LLWU_F1_WUF4_SHIFT                       4
#define LLWU_F1_WUF5_MASK                        0x20u
#define LLWU_F1_WUF5_SHIFT                       5
#define LLWU_F1_WUF6_MASK                        0x40u
#define LLWU_F1_WUF6_SHIFT                       6
#define LLWU_F1_WUF7_MASK                        0x80u
#define LLWU_F1_WUF7_SHIFT                       7
/* F2 Bit Fields */
#define LLWU_F2_WUF8_MASK                        0x1u
#define LLWU_F2_WUF8_SHIFT                       0
#define LLWU_F2_WUF9_MASK                        0x2u
#define LLWU_F2_WUF9_SHIFT                       1
#define LLWU_F2_WUF10_MASK                       0x4u
#define LLWU_F2_WUF10_SHIFT                      2
#define LLWU_F2_WUF11_MASK                       0x8u
#define LLWU_F2_WUF11_SHIFT                      3
#define LLWU_F2_WUF12_MASK                       0x10u
#define LLWU_F2_WUF12_SHIFT                      4
#define LLWU_F2_WUF13_MASK                       0x20u
#define LLWU_F2_WUF13_SHIFT                      5
#define LLWU_F2_WUF14_MASK                       0x40u
#define LLWU_F2_WUF14_SHIFT                      6
#define LLWU_F2_WUF15_MASK                       0x80u
#define LLWU_F2_WUF15_SHIFT                      7
/* F3 Bit Fields */
#define LLWU_F3_MWUF0_MASK                       0x1u
#define LLWU_F3_MWUF0_SHIFT                      0
#define LLWU_F3_MWUF1_MASK                       0x2u
#define LLWU_F3_MWUF1_SHIFT                      1
#define LLWU_F3_MWUF2_MASK                       0x4u
#define LLWU_F3_MWUF2_SHIFT                      2
#define LLWU_F3_MWUF3_MASK                       0x8u
#define LLWU_F3_MWUF3_SHIFT                      3
#define LLWU_F3_MWUF4_MASK                       0x10u
#define LLWU_F3_MWUF4_SHIFT                      4
#define LLWU_F3_MWUF5_MASK                       0x20u
#define LLWU_F3_MWUF5_SHIFT                      5
#define LLWU_F3_MWUF6_MASK                       0x40u
#define LLWU_F3_MWUF6_SHIFT                      6
#define LLWU_F3_MWUF7_MASK                       0x80u
#define LLWU_F3_MWUF7_SHIFT                      7
/* FILT1 Bit Fields */
#define LLWU_FILT1_FILTSEL_MASK                  0xFu
#define LLWU_FILT1_FILTSEL_SHIFT                 0
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK)
#define LLWU_FILT1_FILTE_MASK                    0x60u
#define LLWU_FILT1_FILTE_SHIFT                   5
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK)
#define LLWU_FILT1_FILTF_MASK                    0x80u
#define LLWU_FILT1_FILTF_SHIFT                   7
/* FILT2 Bit Fields */
#define LLWU_FILT2_FILTSEL_MASK                  0xFu
#define LLWU_FILT2_FILTSEL_SHIFT                 0
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK)
#define LLWU_FILT2_FILTE_MASK                    0x60u
#define LLWU_FILT2_FILTE_SHIFT                   5
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK)
#define LLWU_FILT2_FILTF_MASK                    0x80u
#define LLWU_FILT2_FILTF_SHIFT                   7
/* RST Bit Fields */
#define LLWU_RST_RSTFILT_MASK                    0x1u
#define LLWU_RST_RSTFILT_SHIFT                   0
#define LLWU_RST_LLRSTE_MASK                     0x2u
#define LLWU_RST_LLRSTE_SHIFT                    1

/*! \} */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/*! Peripheral LLWU base pointer */
#define LLWU_BASE_PTR                            ((LLWU_MemMapPtr)0xFFFF80B0u)

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros */
/*! \{ */


/* LLWU - Register instance definitions */
/* LLWU */
#define LLWU_PE1                                 LLWU_PE1_REG(LLWU_BASE_PTR)
#define LLWU_PE2                                 LLWU_PE2_REG(LLWU_BASE_PTR)
#define LLWU_PE3                                 LLWU_PE3_REG(LLWU_BASE_PTR)
#define LLWU_PE4                                 LLWU_PE4_REG(LLWU_BASE_PTR)
#define LLWU_ME                                  LLWU_ME_REG(LLWU_BASE_PTR)
#define LLWU_F1                                  LLWU_F1_REG(LLWU_BASE_PTR)
#define LLWU_F2                                  LLWU_F2_REG(LLWU_BASE_PTR)
#define LLWU_F3                                  LLWU_F3_REG(LLWU_BASE_PTR)
#define LLWU_FILT1                               LLWU_FILT1_REG(LLWU_BASE_PTR)
#define LLWU_FILT2                               LLWU_FILT2_REG(LLWU_BASE_PTR)
#define LLWU_RST                                 LLWU_RST_REG(LLWU_BASE_PTR)

/*! \} */ /* end of group LLWU_Register_Accessor_Macros */


/*! \} */ /* end of group LLWU_Peripheral */


/* ----------------------------------------------------------------------------
   -- LPTMR
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPTMR_Peripheral LPTMR */
/*! \{ */

/*! LPTMR - Peripheral register structure */
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                    /*!< Low Power Timer Control Status Register, offset: 0x0 */
  uint32_t PSR;                                    /*!< Low Power Timer Prescale Register, offset: 0x4 */
  uint32_t CMR;                                    /*!< Low Power Timer Compare Register, offset: 0x8 */
  uint32_t CNR;                                    /*!< Low Power Timer Counter Register, offset: 0xC */
} volatile *LPTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros */
/*! \{ */


/* LPTMR - Register accessors */
#define LPTMR_CSR_REG(base)                      ((base)->CSR)
#define LPTMR_PSR_REG(base)                      ((base)->PSR)
#define LPTMR_CMR_REG(base)                      ((base)->CMR)
#define LPTMR_CNR_REG(base)                      ((base)->CNR)

/*! \} */ /* end of group LPTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPTMR_Register_Masks LPTMR Register Masks */
/*! \{ */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*! \} */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/*! Peripheral LPTMR0 base pointer */
#define LPTMR0_BASE_PTR                          ((LPTMR_MemMapPtr)0xFFFF84C0u)
/*! Peripheral LPTMR1 base pointer */
#define LPTMR1_BASE_PTR                          ((LPTMR_MemMapPtr)0xFFFF84D0u)

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros */
/*! \{ */


/* LPTMR - Register instance definitions */
/* LPTMR0 */
#define LPTMR0_CSR                               LPTMR_CSR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_PSR                               LPTMR_PSR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_CMR                               LPTMR_CMR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_CNR                               LPTMR_CNR_REG(LPTMR0_BASE_PTR)
/* LPTMR1 */
#define LPTMR1_CSR                               LPTMR_CSR_REG(LPTMR1_BASE_PTR)
#define LPTMR1_PSR                               LPTMR_PSR_REG(LPTMR1_BASE_PTR)
#define LPTMR1_CMR                               LPTMR_CMR_REG(LPTMR1_BASE_PTR)
#define LPTMR1_CNR                               LPTMR_CNR_REG(LPTMR1_BASE_PTR)

/*! \} */ /* end of group LPTMR_Register_Accessor_Macros */


/*! \} */ /* end of group LPTMR_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCG
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Peripheral MCG */
/*! \{ */

/*! MCG - Peripheral register structure */
typedef struct MCG_MemMap {
  uint8_t C1;                                      /*!< MCG Control 1 Register, offset: 0x0 */
  uint8_t C2;                                      /*!< MCG Control 2 Register, offset: 0x1 */
  uint8_t C3;                                      /*!< MCG Control 3 Register, offset: 0x2 */
  uint8_t C4;                                      /*!< MCG Control 4 Register, offset: 0x3 */
  uint8_t C5;                                      /*!< MCG Control 5 Register, offset: 0x4 */
  uint8_t C6;                                      /*!< MCG Control 6 Register, offset: 0x5 */
  uint8_t S;                                       /*!< MCG Status Register, offset: 0x6 */
  uint8_t RESERVED_0[1];
  uint8_t ATC;                                     /*!< MCG Auto Trim Control Register, offset: 0x8 */
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                   /*!< MCG Auto Trim Compare Value High Register, offset: 0xA */
  uint8_t ATCVL;                                   /*!< MCG Auto Trim Compare Value Low Register, offset: 0xB */
} volatile *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros */
/*! \{ */


/* MCG - Register accessors */
#define MCG_C1_REG(base)                         ((base)->C1)
#define MCG_C2_REG(base)                         ((base)->C2)
#define MCG_C3_REG(base)                         ((base)->C3)
#define MCG_C4_REG(base)                         ((base)->C4)
#define MCG_C5_REG(base)                         ((base)->C5)
#define MCG_C6_REG(base)                         ((base)->C6)
#define MCG_S_REG(base)                          ((base)->S)
#define MCG_ATC_REG(base)                        ((base)->ATC)
#define MCG_ATCVH_REG(base)                      ((base)->ATCVH)
#define MCG_ATCVL_REG(base)                      ((base)->ATCVL)

/*! \} */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Masks MCG Register Masks */
/*! \{ */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_EREFS_MASK                        0x4u
#define MCG_C2_EREFS_SHIFT                       2
#define MCG_C2_HGO_MASK                          0x8u
#define MCG_C2_HGO_SHIFT                         3
#define MCG_C2_RANGE_MASK                        0x30u
#define MCG_C2_RANGE_SHIFT                       4
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE_SHIFT))&MCG_C2_RANGE_MASK)
/* C3 Bit Fields */
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
/* C5 Bit Fields */
#define MCG_C5_PRDIV_MASK                        0x1Fu
#define MCG_C5_PRDIV_SHIFT                       0
#define MCG_C5_PRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV_SHIFT))&MCG_C5_PRDIV_MASK)
#define MCG_C5_PLLSTEN_MASK                      0x20u
#define MCG_C5_PLLSTEN_SHIFT                     5
#define MCG_C5_PLLCLKEN_MASK                     0x40u
#define MCG_C5_PLLCLKEN_SHIFT                    6
/* C6 Bit Fields */
#define MCG_C6_VDIV_MASK                         0x1Fu
#define MCG_C6_VDIV_SHIFT                        0
#define MCG_C6_VDIV(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV_SHIFT))&MCG_C6_VDIV_MASK)
#define MCG_C6_CME_MASK                          0x20u
#define MCG_C6_CME_SHIFT                         5
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_LOLIE_MASK                        0x80u
#define MCG_C6_LOLIE_SHIFT                       7
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_OSCINIT_MASK                       0x2u
#define MCG_S_OSCINIT_SHIFT                      1
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_LOCK_MASK                          0x40u
#define MCG_S_LOCK_SHIFT                         6
#define MCG_S_LOLS_MASK                          0x80u
#define MCG_S_LOLS_SHIFT                         7
/* ATC Bit Fields */
#define MCG_ATC_ATMF_MASK                        0x20u
#define MCG_ATC_ATMF_SHIFT                       5
#define MCG_ATC_ATMS_MASK                        0x40u
#define MCG_ATC_ATMS_SHIFT                       6
#define MCG_ATC_ATME_MASK                        0x80u
#define MCG_ATC_ATME_SHIFT                       7
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)

/*! \} */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/*! Peripheral MCG base pointer */
#define MCG_BASE_PTR                             ((MCG_MemMapPtr)0xFFFF8400u)

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros */
/*! \{ */


/* MCG - Register instance definitions */
/* MCG */
#define MCG_C1                                   MCG_C1_REG(MCG_BASE_PTR)
#define MCG_C2                                   MCG_C2_REG(MCG_BASE_PTR)
#define MCG_C3                                   MCG_C3_REG(MCG_BASE_PTR)
#define MCG_C4                                   MCG_C4_REG(MCG_BASE_PTR)
#define MCG_C5                                   MCG_C5_REG(MCG_BASE_PTR)
#define MCG_C6                                   MCG_C6_REG(MCG_BASE_PTR)
#define MCG_S                                    MCG_S_REG(MCG_BASE_PTR)
#define MCG_ATC                                  MCG_ATC_REG(MCG_BASE_PTR)
#define MCG_ATCVH                                MCG_ATCVH_REG(MCG_BASE_PTR)
#define MCG_ATCVL                                MCG_ATCVL_REG(MCG_BASE_PTR)

/*! \} */ /* end of group MCG_Register_Accessor_Macros */


/*! \} */ /* end of group MCG_Peripheral */


/* ----------------------------------------------------------------------------
   -- MTIM
   ---------------------------------------------------------------------------- */

/*! \addtogroup MTIM_Peripheral MTIM */
/*! \{ */

/*! MTIM - Peripheral register structure */
typedef struct MTIM_MemMap {
  uint8_t SC;                                      /*!< MTIM16 status and control register, offset: 0x0 */
  uint8_t CLK;                                     /*!< MTIM16 clock configuration register, offset: 0x1 */
  union {                                          /* offset: 0x2 */
    struct {                                         /* offset: 0x2 */
      uint8_t CNTH;                                    /*!< MTIM16 counter register high, offset: 0x2 */
      uint8_t CNTL;                                    /*!< MTIM16 counter register low, offset: 0x3 */
    } CNT_ACCESS8BIT;
    uint16_t CNT;                                    /*!< MTIM0_CNT register., offset: 0x2 */
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint8_t MODH;                                    /*!< MTIM16 modulo register high, offset: 0x4 */
      uint8_t MODL;                                    /*!< MTIM16 modulo register low, offset: 0x5 */
    } MOD_ACCESS8BIT;
    uint16_t MOD;                                    /*!< MTIM0_MOD register., offset: 0x4 */
  };
} volatile *MTIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MTIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MTIM_Register_Accessor_Macros MTIM - Register accessor macros */
/*! \{ */


/* MTIM - Register accessors */
#define MTIM_SC_REG(base)                        ((base)->SC)
#define MTIM_CLK_REG(base)                       ((base)->CLK)
#define MTIM_CNTH_REG(base)                      ((base)->CNT_ACCESS8BIT.CNTH)
#define MTIM_CNTL_REG(base)                      ((base)->CNT_ACCESS8BIT.CNTL)
#define MTIM_CNT_REG(base)                       ((base)->CNT)
#define MTIM_MODH_REG(base)                      ((base)->MOD_ACCESS8BIT.MODH)
#define MTIM_MODL_REG(base)                      ((base)->MOD_ACCESS8BIT.MODL)
#define MTIM_MOD_REG(base)                       ((base)->MOD)

/*! \} */ /* end of group MTIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MTIM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MTIM_Register_Masks MTIM Register Masks */
/*! \{ */

/* SC Bit Fields */
#define MTIM_SC_TSTP_MASK                        0x10u
#define MTIM_SC_TSTP_SHIFT                       4
#define MTIM_SC_TRST_MASK                        0x20u
#define MTIM_SC_TRST_SHIFT                       5
#define MTIM_SC_TOIE_MASK                        0x40u
#define MTIM_SC_TOIE_SHIFT                       6
#define MTIM_SC_TOF_MASK                         0x80u
#define MTIM_SC_TOF_SHIFT                        7
/* CLK Bit Fields */
#define MTIM_CLK_PS_MASK                         0xFu
#define MTIM_CLK_PS_SHIFT                        0
#define MTIM_CLK_PS(x)                           (((uint8_t)(((uint8_t)(x))<<MTIM_CLK_PS_SHIFT))&MTIM_CLK_PS_MASK)
#define MTIM_CLK_CLKS_MASK                       0x30u
#define MTIM_CLK_CLKS_SHIFT                      4
#define MTIM_CLK_CLKS(x)                         (((uint8_t)(((uint8_t)(x))<<MTIM_CLK_CLKS_SHIFT))&MTIM_CLK_CLKS_MASK)
/* CNTH Bit Fields */
#define MTIM_CNTH_CNTH_MASK                      0xFFu
#define MTIM_CNTH_CNTH_SHIFT                     0
#define MTIM_CNTH_CNTH(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM_CNTH_CNTH_SHIFT))&MTIM_CNTH_CNTH_MASK)
/* CNTL Bit Fields */
#define MTIM_CNTL_CNTL_MASK                      0xFFu
#define MTIM_CNTL_CNTL_SHIFT                     0
#define MTIM_CNTL_CNTL(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM_CNTL_CNTL_SHIFT))&MTIM_CNTL_CNTL_MASK)
/* CNT Bit Fields */
#define MTIM_CNT_CNT_MASK                        0xFFFFu
#define MTIM_CNT_CNT_SHIFT                       0
#define MTIM_CNT_CNT(x)                          (((uint16_t)(((uint16_t)(x))<<MTIM_CNT_CNT_SHIFT))&MTIM_CNT_CNT_MASK)
/* MODH Bit Fields */
#define MTIM_MODH_MODH_MASK                      0xFFu
#define MTIM_MODH_MODH_SHIFT                     0
#define MTIM_MODH_MODH(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM_MODH_MODH_SHIFT))&MTIM_MODH_MODH_MASK)
/* MODL Bit Fields */
#define MTIM_MODL_MODL_MASK                      0xFFu
#define MTIM_MODL_MODL_SHIFT                     0
#define MTIM_MODL_MODL(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM_MODL_MODL_SHIFT))&MTIM_MODL_MODL_MASK)
/* MOD Bit Fields */
#define MTIM_MOD_MOD_MASK                        0xFFFFu
#define MTIM_MOD_MOD_SHIFT                       0
#define MTIM_MOD_MOD(x)                          (((uint16_t)(((uint16_t)(x))<<MTIM_MOD_MOD_SHIFT))&MTIM_MOD_MOD_MASK)

/*! \} */ /* end of group MTIM_Register_Masks */


/* MTIM - Peripheral instance base addresses */
/*! Peripheral MTIM0 base pointer */
#define MTIM0_BASE_PTR                           ((MTIM_MemMapPtr)0xFFFF8410u)

/* ----------------------------------------------------------------------------
   -- MTIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MTIM_Register_Accessor_Macros MTIM - Register accessor macros */
/*! \{ */


/* MTIM - Register instance definitions */
/* MTIM0 */
#define MTIM0_SC                                 MTIM_SC_REG(MTIM0_BASE_PTR)
#define MTIM0_CLK                                MTIM_CLK_REG(MTIM0_BASE_PTR)
#define MTIM0_CNTH                               MTIM_CNTH_REG(MTIM0_BASE_PTR)
#define MTIM0_CNTL                               MTIM_CNTL_REG(MTIM0_BASE_PTR)
#define MTIM0_CNT                                MTIM_CNT_REG(MTIM0_BASE_PTR)
#define MTIM0_MODH                               MTIM_MODH_REG(MTIM0_BASE_PTR)
#define MTIM0_MODL                               MTIM_MODL_REG(MTIM0_BASE_PTR)
#define MTIM0_MOD                                MTIM_MOD_REG(MTIM0_BASE_PTR)

/*! \} */ /* end of group MTIM_Register_Accessor_Macros */


/*! \} */ /* end of group MTIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- MXC
   ---------------------------------------------------------------------------- */

/*! \addtogroup MXC_Peripheral MXC */
/*! \{ */

/*! MXC - Peripheral register structure */
typedef struct MXC_MemMap {
  uint8_t PTAPF1;                                  /*!< Port A Pin Function 1 Register, offset: 0x0 */
  uint8_t PTAPF2;                                  /*!< Port A Pin Function 2 Register, offset: 0x1 */
  uint8_t PTAPF3;                                  /*!< Port A Pin Function 3 Register, offset: 0x2 */
  uint8_t PTAPF4;                                  /*!< Port A Pin Function 4 Register, offset: 0x3 */
  uint8_t PTBPF1;                                  /*!< Port B Pin Function 1 Register, offset: 0x4 */
  uint8_t PTBPF2;                                  /*!< Port B Pin Function 2 Register, offset: 0x5 */
  uint8_t PTBPF3;                                  /*!< Port B Pin Function 3 Register, offset: 0x6 */
  uint8_t PTBPF4;                                  /*!< Port B Pin Function 4 Register, offset: 0x7 */
  uint8_t PTCPF1;                                  /*!< Port C Pin Function 1 Register, offset: 0x8 */
  uint8_t PTCPF2;                                  /*!< Port C Pin Function 2 Register, offset: 0x9 */
  uint8_t PTCPF3;                                  /*!< Port C Pin Function 3 Register, offset: 0xA */
  uint8_t PTCPF4;                                  /*!< Port C Pin Function 4 Register, offset: 0xB */
  uint8_t PTDPF1;                                  /*!< Port D Pin Function 1 Register, offset: 0xC */
  uint8_t PTDPF2;                                  /*!< Port D Pin Function 2 Register, offset: 0xD */
  uint8_t PTDPF3;                                  /*!< Port D Pin Function 3 Register, offset: 0xE */
  uint8_t PTDPF4;                                  /*!< Port D Pin Function 4 Register, offset: 0xF */
  uint8_t PTEPF1;                                  /*!< Port E Pin Function 1 Register, offset: 0x10 */
  uint8_t PTEPF2;                                  /*!< Port E Pin Function 2 Register, offset: 0x11 */
  uint8_t PTEPF3;                                  /*!< Port E Pin Function 3 Register, offset: 0x12 */
  uint8_t PTEPF4;                                  /*!< Port E Pin Function 4 Register, offset: 0x13 */
  uint8_t PTFPF1;                                  /*!< Port F Pin Function 1 Register, offset: 0x14 */
  uint8_t PTFPF2;                                  /*!< Port F Pin Function 2 Register, offset: 0x15 */
  uint8_t PTFPF3;                                  /*!< Port F Pin Function 3 Register, offset: 0x16 */
  uint8_t PTFPF4;                                  /*!< Port F Pin Function 4 Register, offset: 0x17 */
} volatile *MXC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MXC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MXC_Register_Accessor_Macros MXC - Register accessor macros */
/*! \{ */


/* MXC - Register accessors */
#define MXC_PTAPF1_REG(base)                     ((base)->PTAPF1)
#define MXC_PTAPF2_REG(base)                     ((base)->PTAPF2)
#define MXC_PTAPF3_REG(base)                     ((base)->PTAPF3)
#define MXC_PTAPF4_REG(base)                     ((base)->PTAPF4)
#define MXC_PTBPF1_REG(base)                     ((base)->PTBPF1)
#define MXC_PTBPF2_REG(base)                     ((base)->PTBPF2)
#define MXC_PTBPF3_REG(base)                     ((base)->PTBPF3)
#define MXC_PTBPF4_REG(base)                     ((base)->PTBPF4)
#define MXC_PTCPF1_REG(base)                     ((base)->PTCPF1)
#define MXC_PTCPF2_REG(base)                     ((base)->PTCPF2)
#define MXC_PTCPF3_REG(base)                     ((base)->PTCPF3)
#define MXC_PTCPF4_REG(base)                     ((base)->PTCPF4)
#define MXC_PTDPF1_REG(base)                     ((base)->PTDPF1)
#define MXC_PTDPF2_REG(base)                     ((base)->PTDPF2)
#define MXC_PTDPF3_REG(base)                     ((base)->PTDPF3)
#define MXC_PTDPF4_REG(base)                     ((base)->PTDPF4)
#define MXC_PTEPF1_REG(base)                     ((base)->PTEPF1)
#define MXC_PTEPF2_REG(base)                     ((base)->PTEPF2)
#define MXC_PTEPF3_REG(base)                     ((base)->PTEPF3)
#define MXC_PTEPF4_REG(base)                     ((base)->PTEPF4)
#define MXC_PTFPF1_REG(base)                     ((base)->PTFPF1)
#define MXC_PTFPF2_REG(base)                     ((base)->PTFPF2)
#define MXC_PTFPF3_REG(base)                     ((base)->PTFPF3)
#define MXC_PTFPF4_REG(base)                     ((base)->PTFPF4)

/*! \} */ /* end of group MXC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MXC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MXC_Register_Masks MXC Register Masks */
/*! \{ */

/* PTAPF1 Bit Fields */
#define MXC_PTAPF1_A6_MASK                       0xFu
#define MXC_PTAPF1_A6_SHIFT                      0
#define MXC_PTAPF1_A6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF1_A6_SHIFT))&MXC_PTAPF1_A6_MASK)
#define MXC_PTAPF1_A7_MASK                       0xF0u
#define MXC_PTAPF1_A7_SHIFT                      4
#define MXC_PTAPF1_A7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF1_A7_SHIFT))&MXC_PTAPF1_A7_MASK)
/* PTAPF2 Bit Fields */
#define MXC_PTAPF2_A4_MASK                       0xFu
#define MXC_PTAPF2_A4_SHIFT                      0
#define MXC_PTAPF2_A4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF2_A4_SHIFT))&MXC_PTAPF2_A4_MASK)
#define MXC_PTAPF2_A5_MASK                       0xF0u
#define MXC_PTAPF2_A5_SHIFT                      4
#define MXC_PTAPF2_A5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF2_A5_SHIFT))&MXC_PTAPF2_A5_MASK)
/* PTAPF3 Bit Fields */
#define MXC_PTAPF3_A2_MASK                       0xFu
#define MXC_PTAPF3_A2_SHIFT                      0
#define MXC_PTAPF3_A2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF3_A2_SHIFT))&MXC_PTAPF3_A2_MASK)
#define MXC_PTAPF3_A3_MASK                       0xF0u
#define MXC_PTAPF3_A3_SHIFT                      4
#define MXC_PTAPF3_A3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF3_A3_SHIFT))&MXC_PTAPF3_A3_MASK)
/* PTAPF4 Bit Fields */
#define MXC_PTAPF4_A0_MASK                       0xFu
#define MXC_PTAPF4_A0_SHIFT                      0
#define MXC_PTAPF4_A0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF4_A0_SHIFT))&MXC_PTAPF4_A0_MASK)
#define MXC_PTAPF4_A1_MASK                       0xF0u
#define MXC_PTAPF4_A1_SHIFT                      4
#define MXC_PTAPF4_A1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF4_A1_SHIFT))&MXC_PTAPF4_A1_MASK)
/* PTBPF1 Bit Fields */
#define MXC_PTBPF1_B6_MASK                       0xFu
#define MXC_PTBPF1_B6_SHIFT                      0
#define MXC_PTBPF1_B6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF1_B6_SHIFT))&MXC_PTBPF1_B6_MASK)
#define MXC_PTBPF1_B7_MASK                       0xF0u
#define MXC_PTBPF1_B7_SHIFT                      4
#define MXC_PTBPF1_B7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF1_B7_SHIFT))&MXC_PTBPF1_B7_MASK)
/* PTBPF2 Bit Fields */
#define MXC_PTBPF2_B4_MASK                       0xFu
#define MXC_PTBPF2_B4_SHIFT                      0
#define MXC_PTBPF2_B4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF2_B4_SHIFT))&MXC_PTBPF2_B4_MASK)
#define MXC_PTBPF2_B5_MASK                       0xF0u
#define MXC_PTBPF2_B5_SHIFT                      4
#define MXC_PTBPF2_B5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF2_B5_SHIFT))&MXC_PTBPF2_B5_MASK)
/* PTBPF3 Bit Fields */
#define MXC_PTBPF3_B2_MASK                       0xFu
#define MXC_PTBPF3_B2_SHIFT                      0
#define MXC_PTBPF3_B2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF3_B2_SHIFT))&MXC_PTBPF3_B2_MASK)
#define MXC_PTBPF3_B3_MASK                       0xF0u
#define MXC_PTBPF3_B3_SHIFT                      4
#define MXC_PTBPF3_B3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF3_B3_SHIFT))&MXC_PTBPF3_B3_MASK)
/* PTBPF4 Bit Fields */
#define MXC_PTBPF4_B0_MASK                       0xFu
#define MXC_PTBPF4_B0_SHIFT                      0
#define MXC_PTBPF4_B0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF4_B0_SHIFT))&MXC_PTBPF4_B0_MASK)
#define MXC_PTBPF4_B1_MASK                       0xF0u
#define MXC_PTBPF4_B1_SHIFT                      4
#define MXC_PTBPF4_B1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF4_B1_SHIFT))&MXC_PTBPF4_B1_MASK)
/* PTCPF1 Bit Fields */
#define MXC_PTCPF1_C6_MASK                       0xFu
#define MXC_PTCPF1_C6_SHIFT                      0
#define MXC_PTCPF1_C6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF1_C6_SHIFT))&MXC_PTCPF1_C6_MASK)
#define MXC_PTCPF1_C7_MASK                       0xF0u
#define MXC_PTCPF1_C7_SHIFT                      4
#define MXC_PTCPF1_C7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF1_C7_SHIFT))&MXC_PTCPF1_C7_MASK)
/* PTCPF2 Bit Fields */
#define MXC_PTCPF2_C4_MASK                       0xFu
#define MXC_PTCPF2_C4_SHIFT                      0
#define MXC_PTCPF2_C4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF2_C4_SHIFT))&MXC_PTCPF2_C4_MASK)
#define MXC_PTCPF2_C5_MASK                       0xF0u
#define MXC_PTCPF2_C5_SHIFT                      4
#define MXC_PTCPF2_C5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF2_C5_SHIFT))&MXC_PTCPF2_C5_MASK)
/* PTCPF3 Bit Fields */
#define MXC_PTCPF3_C2_MASK                       0xFu
#define MXC_PTCPF3_C2_SHIFT                      0
#define MXC_PTCPF3_C2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF3_C2_SHIFT))&MXC_PTCPF3_C2_MASK)
#define MXC_PTCPF3_C3_MASK                       0xF0u
#define MXC_PTCPF3_C3_SHIFT                      4
#define MXC_PTCPF3_C3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF3_C3_SHIFT))&MXC_PTCPF3_C3_MASK)
/* PTCPF4 Bit Fields */
#define MXC_PTCPF4_C0_MASK                       0xFu
#define MXC_PTCPF4_C0_SHIFT                      0
#define MXC_PTCPF4_C0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF4_C0_SHIFT))&MXC_PTCPF4_C0_MASK)
#define MXC_PTCPF4_C1_MASK                       0xF0u
#define MXC_PTCPF4_C1_SHIFT                      4
#define MXC_PTCPF4_C1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF4_C1_SHIFT))&MXC_PTCPF4_C1_MASK)
/* PTDPF1 Bit Fields */
#define MXC_PTDPF1_D6_MASK                       0xFu
#define MXC_PTDPF1_D6_SHIFT                      0
#define MXC_PTDPF1_D6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF1_D6_SHIFT))&MXC_PTDPF1_D6_MASK)
#define MXC_PTDPF1_D7_MASK                       0xF0u
#define MXC_PTDPF1_D7_SHIFT                      4
#define MXC_PTDPF1_D7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF1_D7_SHIFT))&MXC_PTDPF1_D7_MASK)
/* PTDPF2 Bit Fields */
#define MXC_PTDPF2_D4_MASK                       0xFu
#define MXC_PTDPF2_D4_SHIFT                      0
#define MXC_PTDPF2_D4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF2_D4_SHIFT))&MXC_PTDPF2_D4_MASK)
#define MXC_PTDPF2_D5_MASK                       0xF0u
#define MXC_PTDPF2_D5_SHIFT                      4
#define MXC_PTDPF2_D5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF2_D5_SHIFT))&MXC_PTDPF2_D5_MASK)
/* PTDPF3 Bit Fields */
#define MXC_PTDPF3_D2_MASK                       0xFu
#define MXC_PTDPF3_D2_SHIFT                      0
#define MXC_PTDPF3_D2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF3_D2_SHIFT))&MXC_PTDPF3_D2_MASK)
#define MXC_PTDPF3_D3_MASK                       0xF0u
#define MXC_PTDPF3_D3_SHIFT                      4
#define MXC_PTDPF3_D3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF3_D3_SHIFT))&MXC_PTDPF3_D3_MASK)
/* PTDPF4 Bit Fields */
#define MXC_PTDPF4_D0_MASK                       0xFu
#define MXC_PTDPF4_D0_SHIFT                      0
#define MXC_PTDPF4_D0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF4_D0_SHIFT))&MXC_PTDPF4_D0_MASK)
#define MXC_PTDPF4_D1_MASK                       0xF0u
#define MXC_PTDPF4_D1_SHIFT                      4
#define MXC_PTDPF4_D1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF4_D1_SHIFT))&MXC_PTDPF4_D1_MASK)
/* PTEPF1 Bit Fields */
#define MXC_PTEPF1_E6_MASK                       0xFu
#define MXC_PTEPF1_E6_SHIFT                      0
#define MXC_PTEPF1_E6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF1_E6_SHIFT))&MXC_PTEPF1_E6_MASK)
#define MXC_PTEPF1_E7_MASK                       0xF0u
#define MXC_PTEPF1_E7_SHIFT                      4
#define MXC_PTEPF1_E7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF1_E7_SHIFT))&MXC_PTEPF1_E7_MASK)
/* PTEPF2 Bit Fields */
#define MXC_PTEPF2_E4_MASK                       0xFu
#define MXC_PTEPF2_E4_SHIFT                      0
#define MXC_PTEPF2_E4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF2_E4_SHIFT))&MXC_PTEPF2_E4_MASK)
#define MXC_PTEPF2_E5_MASK                       0xF0u
#define MXC_PTEPF2_E5_SHIFT                      4
#define MXC_PTEPF2_E5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF2_E5_SHIFT))&MXC_PTEPF2_E5_MASK)
/* PTEPF3 Bit Fields */
#define MXC_PTEPF3_E2_MASK                       0xFu
#define MXC_PTEPF3_E2_SHIFT                      0
#define MXC_PTEPF3_E2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF3_E2_SHIFT))&MXC_PTEPF3_E2_MASK)
#define MXC_PTEPF3_E3_MASK                       0xF0u
#define MXC_PTEPF3_E3_SHIFT                      4
#define MXC_PTEPF3_E3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF3_E3_SHIFT))&MXC_PTEPF3_E3_MASK)
/* PTEPF4 Bit Fields */
#define MXC_PTEPF4_E0_MASK                       0xFu
#define MXC_PTEPF4_E0_SHIFT                      0
#define MXC_PTEPF4_E0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF4_E0_SHIFT))&MXC_PTEPF4_E0_MASK)
#define MXC_PTEPF4_E1_MASK                       0xF0u
#define MXC_PTEPF4_E1_SHIFT                      4
#define MXC_PTEPF4_E1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF4_E1_SHIFT))&MXC_PTEPF4_E1_MASK)
/* PTFPF1 Bit Fields */
#define MXC_PTFPF1_F6_MASK                       0xFu
#define MXC_PTFPF1_F6_SHIFT                      0
#define MXC_PTFPF1_F6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF1_F6_SHIFT))&MXC_PTFPF1_F6_MASK)
#define MXC_PTFPF1_F7_MASK                       0xF0u
#define MXC_PTFPF1_F7_SHIFT                      4
#define MXC_PTFPF1_F7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF1_F7_SHIFT))&MXC_PTFPF1_F7_MASK)
/* PTFPF2 Bit Fields */
#define MXC_PTFPF2_F4_MASK                       0xFu
#define MXC_PTFPF2_F4_SHIFT                      0
#define MXC_PTFPF2_F4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF2_F4_SHIFT))&MXC_PTFPF2_F4_MASK)
#define MXC_PTFPF2_F5_MASK                       0xF0u
#define MXC_PTFPF2_F5_SHIFT                      4
#define MXC_PTFPF2_F5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF2_F5_SHIFT))&MXC_PTFPF2_F5_MASK)
/* PTFPF3 Bit Fields */
#define MXC_PTFPF3_F2_MASK                       0xFu
#define MXC_PTFPF3_F2_SHIFT                      0
#define MXC_PTFPF3_F2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF3_F2_SHIFT))&MXC_PTFPF3_F2_MASK)
#define MXC_PTFPF3_F3_MASK                       0xF0u
#define MXC_PTFPF3_F3_SHIFT                      4
#define MXC_PTFPF3_F3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF3_F3_SHIFT))&MXC_PTFPF3_F3_MASK)
/* PTFPF4 Bit Fields */
#define MXC_PTFPF4_F0_MASK                       0xFu
#define MXC_PTFPF4_F0_SHIFT                      0
#define MXC_PTFPF4_F0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF4_F0_SHIFT))&MXC_PTFPF4_F0_MASK)
#define MXC_PTFPF4_F1_MASK                       0xF0u
#define MXC_PTFPF4_F1_SHIFT                      4
#define MXC_PTFPF4_F1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF4_F1_SHIFT))&MXC_PTFPF4_F1_MASK)

/*! \} */ /* end of group MXC_Register_Masks */


/* MXC - Peripheral instance base addresses */
/*! Peripheral MXC base pointer */
#define MXC_BASE_PTR                             ((MXC_MemMapPtr)0xFFFF8080u)

/* ----------------------------------------------------------------------------
   -- MXC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MXC_Register_Accessor_Macros MXC - Register accessor macros */
/*! \{ */


/* MXC - Register instance definitions */
/* MXC */
#define MXC_PTAPF1                               MXC_PTAPF1_REG(MXC_BASE_PTR)
#define MXC_PTAPF2                               MXC_PTAPF2_REG(MXC_BASE_PTR)
#define MXC_PTAPF3                               MXC_PTAPF3_REG(MXC_BASE_PTR)
#define MXC_PTAPF4                               MXC_PTAPF4_REG(MXC_BASE_PTR)
#define MXC_PTBPF1                               MXC_PTBPF1_REG(MXC_BASE_PTR)
#define MXC_PTBPF2                               MXC_PTBPF2_REG(MXC_BASE_PTR)
#define MXC_PTBPF3                               MXC_PTBPF3_REG(MXC_BASE_PTR)
#define MXC_PTBPF4                               MXC_PTBPF4_REG(MXC_BASE_PTR)
#define MXC_PTCPF1                               MXC_PTCPF1_REG(MXC_BASE_PTR)
#define MXC_PTCPF2                               MXC_PTCPF2_REG(MXC_BASE_PTR)
#define MXC_PTCPF3                               MXC_PTCPF3_REG(MXC_BASE_PTR)
#define MXC_PTCPF4                               MXC_PTCPF4_REG(MXC_BASE_PTR)
#define MXC_PTDPF1                               MXC_PTDPF1_REG(MXC_BASE_PTR)
#define MXC_PTDPF2                               MXC_PTDPF2_REG(MXC_BASE_PTR)
#define MXC_PTDPF3                               MXC_PTDPF3_REG(MXC_BASE_PTR)
#define MXC_PTDPF4                               MXC_PTDPF4_REG(MXC_BASE_PTR)
#define MXC_PTEPF1                               MXC_PTEPF1_REG(MXC_BASE_PTR)
#define MXC_PTEPF2                               MXC_PTEPF2_REG(MXC_BASE_PTR)
#define MXC_PTEPF3                               MXC_PTEPF3_REG(MXC_BASE_PTR)
#define MXC_PTEPF4                               MXC_PTEPF4_REG(MXC_BASE_PTR)
#define MXC_PTFPF1                               MXC_PTFPF1_REG(MXC_BASE_PTR)
#define MXC_PTFPF2                               MXC_PTFPF2_REG(MXC_BASE_PTR)
#define MXC_PTFPF3                               MXC_PTFPF3_REG(MXC_BASE_PTR)
#define MXC_PTFPF4                               MXC_PTFPF4_REG(MXC_BASE_PTR)

/*! \} */ /* end of group MXC_Register_Accessor_Macros */


/*! \} */ /* end of group MXC_Peripheral */


/* ----------------------------------------------------------------------------
   -- OSC
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Peripheral OSC */
/*! \{ */

/*! OSC - Peripheral register structure */
typedef struct OSC_MemMap {
  uint8_t CR;                                      /*!< OSC Control Register, offset: 0x0 */
} volatile *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros */
/*! \{ */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)

/*! \} */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Masks OSC Register Masks */
/*! \{ */

/* CR Bit Fields */
#define OSC_CR_SC16P_MASK                        0x1u
#define OSC_CR_SC16P_SHIFT                       0
#define OSC_CR_SC8P_MASK                         0x2u
#define OSC_CR_SC8P_SHIFT                        1
#define OSC_CR_SC4P_MASK                         0x4u
#define OSC_CR_SC4P_SHIFT                        2
#define OSC_CR_SC2P_MASK                         0x8u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSTEN_MASK                     0x20u
#define OSC_CR_EREFSTEN_SHIFT                    5
#define OSC_CR_ERCLKEN_MASK                      0x80u
#define OSC_CR_ERCLKEN_SHIFT                     7

/*! \} */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/*! Peripheral OSC1 base pointer */
#define OSC1_BASE_PTR                            ((OSC_MemMapPtr)0xFFFF8120u)
/*! Peripheral OSC2 base pointer */
#define OSC2_BASE_PTR                            ((OSC_MemMapPtr)0xFFFF8130u)

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros */
/*! \{ */


/* OSC - Register instance definitions */
/* OSC1 */
#define OSC1_CR                                  OSC_CR_REG(OSC1_BASE_PTR)
/* OSC2 */
#define OSC2_CR                                  OSC_CR_REG(OSC2_BASE_PTR)

/*! \} */ /* end of group OSC_Register_Accessor_Macros */


/*! \} */ /* end of group OSC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PCTL
   ---------------------------------------------------------------------------- */

/*! \addtogroup PCTL_Peripheral PCTL */
/*! \{ */

/*! PCTL - Peripheral register structure */
typedef struct PCTL_MemMap {
  uint8_t PUE;                                     /*!< Port Pulling Enable Register, offset: 0x0 */
  uint8_t PUS;                                     /*!< Port Pullup/Pulldown Select Register, offset: 0x1 */
  uint8_t DS;                                      /*!< Port Drive Strength Enable Register, offset: 0x2 */
  uint8_t SRE;                                     /*!< Port Slew Rate Enable Register, offset: 0x3 */
  uint8_t PFE;                                     /*!< Port Passive Filter Enable Register, offset: 0x4 */
  uint8_t IC;                                      /*!< Port Interrupt Control Register, offset: 0x5 */
  uint8_t IPE;                                     /*!< Port Interrupt Pin Enable Register, offset: 0x6 */
  uint8_t IF;                                      /*!< Port Interrupt Flag Register, offset: 0x7 */
  uint8_t IES;                                     /*!< Interrupt Edge Select Register, offset: 0x8 */
  uint8_t DFE;                                     /*!< Port Digital Filter Enable Register, offset: 0x9 */
  uint8_t DFC;                                     /*!< Port Digital Filter Control Register, offset: 0xA */
} volatile *PCTL_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PCTL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PCTL_Register_Accessor_Macros PCTL - Register accessor macros */
/*! \{ */


/* PCTL - Register accessors */
#define PCTL_PUE_REG(base)                       ((base)->PUE)
#define PCTL_PUS_REG(base)                       ((base)->PUS)
#define PCTL_DS_REG(base)                        ((base)->DS)
#define PCTL_SRE_REG(base)                       ((base)->SRE)
#define PCTL_PFE_REG(base)                       ((base)->PFE)
#define PCTL_IC_REG(base)                        ((base)->IC)
#define PCTL_IPE_REG(base)                       ((base)->IPE)
#define PCTL_IF_REG(base)                        ((base)->IF)
#define PCTL_IES_REG(base)                       ((base)->IES)
#define PCTL_DFE_REG(base)                       ((base)->DFE)
#define PCTL_DFC_REG(base)                       ((base)->DFC)

/*! \} */ /* end of group PCTL_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PCTL Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PCTL_Register_Masks PCTL Register Masks */
/*! \{ */

/* PUE Bit Fields */
#define PCTL_PUE_PTPUE_MASK                      0xFFu
#define PCTL_PUE_PTPUE_SHIFT                     0
#define PCTL_PUE_PTPUE(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_PUE_PTPUE_SHIFT))&PCTL_PUE_PTPUE_MASK)
/* PUS Bit Fields */
#define PCTL_PUS_PTPUS_MASK                      0xFFu
#define PCTL_PUS_PTPUS_SHIFT                     0
#define PCTL_PUS_PTPUS(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_PUS_PTPUS_SHIFT))&PCTL_PUS_PTPUS_MASK)
/* DS Bit Fields */
#define PCTL_DS_PTDS_MASK                        0xFFu
#define PCTL_DS_PTDS_SHIFT                       0
#define PCTL_DS_PTDS(x)                          (((uint8_t)(((uint8_t)(x))<<PCTL_DS_PTDS_SHIFT))&PCTL_DS_PTDS_MASK)
/* SRE Bit Fields */
#define PCTL_SRE_PTSRE_MASK                      0xFFu
#define PCTL_SRE_PTSRE_SHIFT                     0
#define PCTL_SRE_PTSRE(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_SRE_PTSRE_SHIFT))&PCTL_SRE_PTSRE_MASK)
/* PFE Bit Fields */
#define PCTL_PFE_PTPFE_MASK                      0xFFu
#define PCTL_PFE_PTPFE_SHIFT                     0
#define PCTL_PFE_PTPFE(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_PFE_PTPFE_SHIFT))&PCTL_PFE_PTPFE_MASK)
/* IC Bit Fields */
#define PCTL_IC_PTMOD_MASK                       0x1u
#define PCTL_IC_PTMOD_SHIFT                      0
#define PCTL_IC_PTIE_MASK                        0x2u
#define PCTL_IC_PTIE_SHIFT                       1
#define PCTL_IC_PTDMAEN_MASK                     0x80u
#define PCTL_IC_PTDMAEN_SHIFT                    7
/* IPE Bit Fields */
#define PCTL_IPE_PTIPE_MASK                      0xFFu
#define PCTL_IPE_PTIPE_SHIFT                     0
#define PCTL_IPE_PTIPE(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_IPE_PTIPE_SHIFT))&PCTL_IPE_PTIPE_MASK)
/* IF Bit Fields */
#define PCTL_IF_PTIF_MASK                        0xFFu
#define PCTL_IF_PTIF_SHIFT                       0
#define PCTL_IF_PTIF(x)                          (((uint8_t)(((uint8_t)(x))<<PCTL_IF_PTIF_SHIFT))&PCTL_IF_PTIF_MASK)
/* IES Bit Fields */
#define PCTL_IES_PTEDG_MASK                      0xFFu
#define PCTL_IES_PTEDG_SHIFT                     0
#define PCTL_IES_PTEDG(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_IES_PTEDG_SHIFT))&PCTL_IES_PTEDG_MASK)
/* DFE Bit Fields */
#define PCTL_DFE_PTDFE_MASK                      0xFFu
#define PCTL_DFE_PTDFE_SHIFT                     0
#define PCTL_DFE_PTDFE(x)                        (((uint8_t)(((uint8_t)(x))<<PCTL_DFE_PTDFE_SHIFT))&PCTL_DFE_PTDFE_MASK)
/* DFC Bit Fields */
#define PCTL_DFC_PTFF_MASK                       0x1Fu
#define PCTL_DFC_PTFF_SHIFT                      0
#define PCTL_DFC_PTFF(x)                         (((uint8_t)(((uint8_t)(x))<<PCTL_DFC_PTFF_SHIFT))&PCTL_DFC_PTFF_MASK)
#define PCTL_DFC_PTCLKS_MASK                     0x80u
#define PCTL_DFC_PTCLKS_SHIFT                    7

/*! \} */ /* end of group PCTL_Register_Masks */


/* PCTL - Peripheral instance base addresses */
/*! Peripheral PCTLA base pointer */
#define PCTLA_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9200u)
/*! Peripheral PCTLB base pointer */
#define PCTLB_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9210u)
/*! Peripheral PCTLC base pointer */
#define PCTLC_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9220u)
/*! Peripheral PCTLD base pointer */
#define PCTLD_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9230u)
/*! Peripheral PCTLE base pointer */
#define PCTLE_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9240u)
/*! Peripheral PCTLF base pointer */
#define PCTLF_BASE_PTR                           ((PCTL_MemMapPtr)0xFFFF9250u)

/* ----------------------------------------------------------------------------
   -- PCTL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PCTL_Register_Accessor_Macros PCTL - Register accessor macros */
/*! \{ */


/* PCTL - Register instance definitions */
/* PCTLA */
#define PCTLA_PUE                                PCTL_PUE_REG(PCTLA_BASE_PTR)
#define PCTLA_PUS                                PCTL_PUS_REG(PCTLA_BASE_PTR)
#define PCTLA_DS                                 PCTL_DS_REG(PCTLA_BASE_PTR)
#define PCTLA_SRE                                PCTL_SRE_REG(PCTLA_BASE_PTR)
#define PCTLA_PFE                                PCTL_PFE_REG(PCTLA_BASE_PTR)
#define PCTLA_IC                                 PCTL_IC_REG(PCTLA_BASE_PTR)
#define PCTLA_IPE                                PCTL_IPE_REG(PCTLA_BASE_PTR)
#define PCTLA_IF                                 PCTL_IF_REG(PCTLA_BASE_PTR)
#define PCTLA_IES                                PCTL_IES_REG(PCTLA_BASE_PTR)
/* PCTLB */
#define PCTLB_PUE                                PCTL_PUE_REG(PCTLB_BASE_PTR)
#define PCTLB_PUS                                PCTL_PUS_REG(PCTLB_BASE_PTR)
#define PCTLB_DS                                 PCTL_DS_REG(PCTLB_BASE_PTR)
#define PCTLB_SRE                                PCTL_SRE_REG(PCTLB_BASE_PTR)
#define PCTLB_PFE                                PCTL_PFE_REG(PCTLB_BASE_PTR)
#define PCTLB_IC                                 PCTL_IC_REG(PCTLB_BASE_PTR)
#define PCTLB_IPE                                PCTL_IPE_REG(PCTLB_BASE_PTR)
#define PCTLB_IF                                 PCTL_IF_REG(PCTLB_BASE_PTR)
#define PCTLB_IES                                PCTL_IES_REG(PCTLB_BASE_PTR)
#define PCTLB_DFE                                PCTL_DFE_REG(PCTLB_BASE_PTR)
#define PCTLB_DFC                                PCTL_DFC_REG(PCTLB_BASE_PTR)
/* PCTLC */
#define PCTLC_PUE                                PCTL_PUE_REG(PCTLC_BASE_PTR)
#define PCTLC_PUS                                PCTL_PUS_REG(PCTLC_BASE_PTR)
#define PCTLC_DS                                 PCTL_DS_REG(PCTLC_BASE_PTR)
#define PCTLC_SRE                                PCTL_SRE_REG(PCTLC_BASE_PTR)
#define PCTLC_PFE                                PCTL_PFE_REG(PCTLC_BASE_PTR)
#define PCTLC_IC                                 PCTL_IC_REG(PCTLC_BASE_PTR)
#define PCTLC_IPE                                PCTL_IPE_REG(PCTLC_BASE_PTR)
#define PCTLC_IF                                 PCTL_IF_REG(PCTLC_BASE_PTR)
#define PCTLC_IES                                PCTL_IES_REG(PCTLC_BASE_PTR)
#define PCTLC_DFE                                PCTL_DFE_REG(PCTLC_BASE_PTR)
#define PCTLC_DFC                                PCTL_DFC_REG(PCTLC_BASE_PTR)
/* PCTLD */
#define PCTLD_PUE                                PCTL_PUE_REG(PCTLD_BASE_PTR)
#define PCTLD_PUS                                PCTL_PUS_REG(PCTLD_BASE_PTR)
#define PCTLD_DS                                 PCTL_DS_REG(PCTLD_BASE_PTR)
#define PCTLD_SRE                                PCTL_SRE_REG(PCTLD_BASE_PTR)
#define PCTLD_PFE                                PCTL_PFE_REG(PCTLD_BASE_PTR)
#define PCTLD_IC                                 PCTL_IC_REG(PCTLD_BASE_PTR)
#define PCTLD_IPE                                PCTL_IPE_REG(PCTLD_BASE_PTR)
#define PCTLD_IF                                 PCTL_IF_REG(PCTLD_BASE_PTR)
#define PCTLD_IES                                PCTL_IES_REG(PCTLD_BASE_PTR)
/* PCTLE */
#define PCTLE_PUE                                PCTL_PUE_REG(PCTLE_BASE_PTR)
#define PCTLE_PUS                                PCTL_PUS_REG(PCTLE_BASE_PTR)
#define PCTLE_DS                                 PCTL_DS_REG(PCTLE_BASE_PTR)
#define PCTLE_SRE                                PCTL_SRE_REG(PCTLE_BASE_PTR)
#define PCTLE_PFE                                PCTL_PFE_REG(PCTLE_BASE_PTR)
#define PCTLE_IC                                 PCTL_IC_REG(PCTLE_BASE_PTR)
#define PCTLE_IPE                                PCTL_IPE_REG(PCTLE_BASE_PTR)
#define PCTLE_IF                                 PCTL_IF_REG(PCTLE_BASE_PTR)
#define PCTLE_IES                                PCTL_IES_REG(PCTLE_BASE_PTR)
/* PCTLF */
#define PCTLF_PUE                                PCTL_PUE_REG(PCTLF_BASE_PTR)
#define PCTLF_PUS                                PCTL_PUS_REG(PCTLF_BASE_PTR)
#define PCTLF_DS                                 PCTL_DS_REG(PCTLF_BASE_PTR)
#define PCTLF_SRE                                PCTL_SRE_REG(PCTLF_BASE_PTR)
#define PCTLF_PFE                                PCTL_PFE_REG(PCTLF_BASE_PTR)
#define PCTLF_IC                                 PCTL_IC_REG(PCTLF_BASE_PTR)
#define PCTLF_IPE                                PCTL_IPE_REG(PCTLF_BASE_PTR)
#define PCTLF_IF                                 PCTL_IF_REG(PCTLF_BASE_PTR)
#define PCTLF_IES                                PCTL_IES_REG(PCTLF_BASE_PTR)

/*! \} */ /* end of group PCTL_Register_Accessor_Macros */


/*! \} */ /* end of group PCTL_Peripheral */


/* ----------------------------------------------------------------------------
   -- PDB
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Peripheral PDB */
/*! \{ */

/*! PDB - Peripheral register structure */
typedef struct PDB_MemMap {
  uint32_t SC;                                     /*!< Status and Control Register, offset: 0x0 */
  uint32_t MOD;                                    /*!< Modulus Register, offset: 0x4 */
  uint32_t CNT;                                    /*!< Counter Register, offset: 0x8 */
  uint32_t IDLY;                                   /*!< Interrupt Delay Register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x10 */
    uint32_t C1;                                     /*!< Channel n Control Register 1, array offset: 0x10, array step: 0x10 */
    uint32_t S;                                      /*!< Channel n Status Register, array offset: 0x14, array step: 0x10 */
    uint32_t DLY[2];                                 /*!< Channel n Delay 0 Register..Channel n Delay 1 Register, array offset: 0x18, array step: index*0x10, index2*0x4 */
  } CH[1];
  struct {                                         /* offset: 0x20, array step: 0x8 */
    uint32_t INTC;                                   /*!< DAC Interval Trigger n Control Register, array offset: 0x20, array step: 0x8 */
    uint32_t INT;                                    /*!< DAC Interval n Register, array offset: 0x24, array step: 0x8 */
  } DAC[1];
  uint32_t POEN;                                   /*!< Pulse-Out n Enable Register, offset: 0x28 */
  uint32_t PODLY;                                  /*!< Pulse-Out n Delay Register, offset: 0x2C */
} volatile *PDB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros */
/*! \{ */


/* PDB - Register accessors */
#define PDB_SC_REG(base)                         ((base)->SC)
#define PDB_MOD_REG(base)                        ((base)->MOD)
#define PDB_CNT_REG(base)                        ((base)->CNT)
#define PDB_IDLY_REG(base)                       ((base)->IDLY)
#define PDB_C1_REG(base,index)                   ((base)->CH[index].C1)
#define PDB_S_REG(base,index)                    ((base)->CH[index].S)
#define PDB_DLY_REG(base,index,index2)           ((base)->CH[index].DLY[index2])
#define PDB_INTC_REG(base,index)                 ((base)->DAC[index].INTC)
#define PDB_INT_REG(base,index)                  ((base)->DAC[index].INT)
#define PDB_POEN_REG(base)                       ((base)->POEN)
#define PDB_PODLY_REG(base)                      ((base)->PODLY)

/*! \} */ /* end of group PDB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Masks PDB Register Masks */
/*! \{ */

/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK)
/* C1 Bit Fields */
#define PDB_C1_EN_MASK                           0xFFu
#define PDB_C1_EN_SHIFT                          0
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          0xFF00u
#define PDB_C1_TOS_SHIFT                         8
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           0xFF0000u
#define PDB_C1_BB_SHIFT                          16
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK)
/* S Bit Fields */
#define PDB_S_ERR_MASK                           0xFFu
#define PDB_S_ERR_SHIFT                          0
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            0xFF0000u
#define PDB_S_CF_SHIFT                           16
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK)
/* DLY Bit Fields */
#define PDB_DLY_DLY_MASK                         0xFFFFu
#define PDB_DLY_DLY_SHIFT                        0
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK)
/* INTC Bit Fields */
#define PDB_INTC_TOE_MASK                        0x1u
#define PDB_INTC_TOE_SHIFT                       0
#define PDB_INTC_EXT_MASK                        0x2u
#define PDB_INTC_EXT_SHIFT                       1
/* INT Bit Fields */
#define PDB_INT_INT_MASK                         0xFFFFu
#define PDB_INT_INT_SHIFT                        0
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK)
/* POEN Bit Fields */
#define PDB_POEN_POEN_MASK                       0xFFu
#define PDB_POEN_POEN_SHIFT                      0
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK)
/* PODLY Bit Fields */
#define PDB_PODLY_DLY2_MASK                      0xFFFFu
#define PDB_PODLY_DLY2_SHIFT                     0
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK)
#define PDB_PODLY_DLY1_MASK                      0xFFFF0000u
#define PDB_PODLY_DLY1_SHIFT                     16
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK)

/*! \} */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/*! Peripheral PDB0 base pointer */
#define PDB0_BASE_PTR                            ((PDB_MemMapPtr)0xFFFF8540u)

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros */
/*! \{ */


/* PDB - Register instance definitions */
/* PDB0 */
#define PDB0_SC                                  PDB_SC_REG(PDB0_BASE_PTR)
#define PDB0_MOD                                 PDB_MOD_REG(PDB0_BASE_PTR)
#define PDB0_CNT                                 PDB_CNT_REG(PDB0_BASE_PTR)
#define PDB0_IDLY                                PDB_IDLY_REG(PDB0_BASE_PTR)
#define PDB0_CH0C1                               PDB_C1_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0S                                PDB_S_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0DLY0                             PDB_DLY_REG(PDB0_BASE_PTR,0,0)
#define PDB0_CH0DLY1                             PDB_DLY_REG(PDB0_BASE_PTR,0,1)
#define PDB0_DACINTC0                            PDB_INTC_REG(PDB0_BASE_PTR,0)
#define PDB0_DACINT0                             PDB_INT_REG(PDB0_BASE_PTR,0)
#define PDB0_PO0EN                               PDB_POEN_REG(PDB0_BASE_PTR)
#define PDB0_PO0DLY                              PDB_PODLY_REG(PDB0_BASE_PTR)

/* PDB - Register array accessors */
#define PDB0_C1(index)                           PDB_C1_REG(PDB0_BASE_PTR,index)
#define PDB0_S(index)                            PDB_S_REG(PDB0_BASE_PTR,index)
#define PDB0_DLY(index,index2)                   PDB_DLY_REG(PDB0_BASE_PTR,index,index2)
#define PDB0_INTC(index)                         PDB_INTC_REG(PDB0_BASE_PTR,index)
#define PDB0_INT(index)                          PDB_INT_REG(PDB0_BASE_PTR,index)

/*! \} */ /* end of group PDB_Register_Accessor_Macros */


/*! \} */ /* end of group PDB_Peripheral */


/* ----------------------------------------------------------------------------
   -- PMC
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Peripheral PMC */
/*! \{ */

/*! PMC - Peripheral register structure */
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                  /*!< Low Voltage Detect Status and Control 1 Register, offset: 0x0 */
  uint8_t LVDSC2;                                  /*!< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  uint8_t REGSC;                                   /*!< Regulator Status and Control Register, offset: 0x2 */
} volatile *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros */
/*! \{ */


/* PMC - Register accessors */
#define PMC_LVDSC1_REG(base)                     ((base)->LVDSC1)
#define PMC_LVDSC2_REG(base)                     ((base)->LVDSC2)
#define PMC_REGSC_REG(base)                      ((base)->REGSC)

/*! \} */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Masks PMC Register Masks */
/*! \{ */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_ACKISO_MASK                    0x8u
#define PMC_REGSC_ACKISO_SHIFT                   3

/*! \} */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/*! Peripheral PMC base pointer */
#define PMC_BASE_PTR                             ((PMC_MemMapPtr)0xFFFF8100u)

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros */
/*! \{ */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_LVDSC1                               PMC_LVDSC1_REG(PMC_BASE_PTR)
#define PMC_LVDSC2                               PMC_LVDSC2_REG(PMC_BASE_PTR)
#define PMC_REGSC                                PMC_REGSC_REG(PMC_BASE_PTR)

/*! \} */ /* end of group PMC_Register_Accessor_Macros */


/*! \} */ /* end of group PMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PT
   ---------------------------------------------------------------------------- */

/*! \addtogroup PT_Peripheral PT */
/*! \{ */

/*! PT - Peripheral register structure */
typedef struct PT_MemMap {
  uint8_t D;                                       /*!< Port Data Register, offset: 0x0 */
  uint8_t DD;                                      /*!< Port Data Direction Register, offset: 0x1 */
  uint8_t PV;                                      /*!< Port Pin Value Register, offset: 0x2 */
} volatile *PT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PT_Register_Accessor_Macros PT - Register accessor macros */
/*! \{ */


/* PT - Register accessors */
#define PT_D_REG(base)                           ((base)->D)
#define PT_DD_REG(base)                          ((base)->DD)
#define PT_PV_REG(base)                          ((base)->PV)

/*! \} */ /* end of group PT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PT_Register_Masks PT Register Masks */
/*! \{ */

/* D Bit Fields */
#define PT_D_PTD_MASK                            0xFFu
#define PT_D_PTD_SHIFT                           0
#define PT_D_PTD(x)                              (((uint8_t)(((uint8_t)(x))<<PT_D_PTD_SHIFT))&PT_D_PTD_MASK)
/* DD Bit Fields */
#define PT_DD_PTDD_MASK                          0xFFu
#define PT_DD_PTDD_SHIFT                         0
#define PT_DD_PTDD(x)                            (((uint8_t)(((uint8_t)(x))<<PT_DD_PTDD_SHIFT))&PT_DD_PTDD_MASK)
/* PV Bit Fields */
#define PT_PV_PTPV_MASK                          0xFFu
#define PT_PV_PTPV_SHIFT                         0
#define PT_PV_PTPV(x)                            (((uint8_t)(((uint8_t)(x))<<PT_PV_PTPV_SHIFT))&PT_PV_PTPV_MASK)

/*! \} */ /* end of group PT_Register_Masks */


/* PT - Peripheral instance base addresses */
/*! Peripheral PTA base pointer */
#define PTA_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8000u)
/*! Peripheral PTB base pointer */
#define PTB_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8010u)
/*! Peripheral PTC base pointer */
#define PTC_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8020u)
/*! Peripheral PTD base pointer */
#define PTD_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8030u)
/*! Peripheral PTE base pointer */
#define PTE_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8040u)
/*! Peripheral PTF base pointer */
#define PTF_BASE_PTR                             ((PT_MemMapPtr)0xFFFF8050u)

/* ----------------------------------------------------------------------------
   -- PT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PT_Register_Accessor_Macros PT - Register accessor macros */
/*! \{ */


/* PT - Register instance definitions */
/* PTA */
#define PTA_D                                    PT_D_REG(PTA_BASE_PTR)
#define PTA_DD                                   PT_DD_REG(PTA_BASE_PTR)
#define PTA_PV                                   PT_PV_REG(PTA_BASE_PTR)
/* PTB */
#define PTB_D                                    PT_D_REG(PTB_BASE_PTR)
#define PTB_DD                                   PT_DD_REG(PTB_BASE_PTR)
#define PTB_PV                                   PT_PV_REG(PTB_BASE_PTR)
/* PTC */
#define PTC_D                                    PT_D_REG(PTC_BASE_PTR)
#define PTC_DD                                   PT_DD_REG(PTC_BASE_PTR)
#define PTC_PV                                   PT_PV_REG(PTC_BASE_PTR)
/* PTD */
#define PTD_D                                    PT_D_REG(PTD_BASE_PTR)
#define PTD_DD                                   PT_DD_REG(PTD_BASE_PTR)
#define PTD_PV                                   PT_PV_REG(PTD_BASE_PTR)
/* PTE */
#define PTE_D                                    PT_D_REG(PTE_BASE_PTR)
#define PTE_DD                                   PT_DD_REG(PTE_BASE_PTR)
#define PTE_PV                                   PT_PV_REG(PTE_BASE_PTR)
/* PTF */
#define PTF_D                                    PT_D_REG(PTF_BASE_PTR)
#define PTF_DD                                   PT_DD_REG(PTF_BASE_PTR)
#define PTF_PV                                   PT_PV_REG(PTF_BASE_PTR)

/*! \} */ /* end of group PT_Register_Accessor_Macros */


/*! \} */ /* end of group PT_Peripheral */


/* ----------------------------------------------------------------------------
   -- RCM
   ---------------------------------------------------------------------------- */

/*! \addtogroup RCM_Peripheral RCM */
/*! \{ */

/*! RCM - Peripheral register structure */
typedef struct RCM_MemMap {
  uint8_t SRS0;                                    /*!< System Reset Status Register 0, offset: 0x0 */
  uint8_t SRS1;                                    /*!< System Reset Status Register 1, offset: 0x1 */
  uint8_t RESERVED_0[2];
  uint8_t RPFC;                                    /*!< Reset Pin Filter Control Register, offset: 0x4 */
  uint8_t RPFW;                                    /*!< Reset Pin Filter Width Register, offset: 0x5 */
  uint8_t RESERVED_1[1];
  uint8_t MR;                                      /*!< Mode Register, offset: 0x7 */
} volatile *RCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros */
/*! \{ */


/* RCM - Register accessors */
#define RCM_SRS0_REG(base)                       ((base)->SRS0)
#define RCM_SRS1_REG(base)                       ((base)->SRS1)
#define RCM_RPFC_REG(base)                       ((base)->RPFC)
#define RCM_RPFW_REG(base)                       ((base)->RPFW)
#define RCM_MR_REG(base)                         ((base)->MR)

/*! \} */ /* end of group RCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup RCM_Register_Masks RCM Register Masks */
/*! \{ */

/* SRS0 Bit Fields */
#define RCM_SRS0_WAKEUP_MASK                     0x1u
#define RCM_SRS0_WAKEUP_SHIFT                    0
#define RCM_SRS0_LVD_MASK                        0x2u
#define RCM_SRS0_LVD_SHIFT                       1
#define RCM_SRS0_LOC_MASK                        0x4u
#define RCM_SRS0_LOC_SHIFT                       2
#define RCM_SRS0_ILAD_MASK                       0x8u
#define RCM_SRS0_ILAD_SHIFT                      3
#define RCM_SRS0_ILOP_MASK                       0x10u
#define RCM_SRS0_ILOP_SHIFT                      4
#define RCM_SRS0_WDOG_MASK                       0x20u
#define RCM_SRS0_WDOG_SHIFT                      5
#define RCM_SRS0_PIN_MASK                        0x40u
#define RCM_SRS0_PIN_SHIFT                       6
#define RCM_SRS0_POR_MASK                        0x80u
#define RCM_SRS0_POR_SHIFT                       7
/* SRS1 Bit Fields */
#define RCM_SRS1_BDFR_MASK                       0x8u
#define RCM_SRS1_BDFR_SHIFT                      3
#define RCM_SRS1_EZPT_MASK                       0x10u
#define RCM_SRS1_EZPT_SHIFT                      4
#define RCM_SRS1_SACKERR_MASK                    0x20u
#define RCM_SRS1_SACKERR_SHIFT                   5
/* RPFC Bit Fields */
#define RCM_RPFC_RSTFLTSRW_MASK                  0x3u
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK)
#define RCM_RPFC_RSTFLTSS_MASK                   0x4u
#define RCM_RPFC_RSTFLTSS_SHIFT                  2
/* RPFW Bit Fields */
#define RCM_RPFW_RSTFLTSEL_MASK                  0x1Fu
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK)
/* MR Bit Fields */
#define RCM_MR_MS_MASK                           0x1u
#define RCM_MR_MS_SHIFT                          0
#define RCM_MR_EZP_MS_MASK                       0x2u
#define RCM_MR_EZP_MS_SHIFT                      1

/*! \} */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/*! Peripheral RCM base pointer */
#define RCM_BASE_PTR                             ((RCM_MemMapPtr)0xFFFF8110u)

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros */
/*! \{ */


/* RCM - Register instance definitions */
/* RCM */
#define RCM_SRS0                                 RCM_SRS0_REG(RCM_BASE_PTR)
#define RCM_SRS1                                 RCM_SRS1_REG(RCM_BASE_PTR)
#define RCM_RPFC                                 RCM_RPFC_REG(RCM_BASE_PTR)
#define RCM_RPFW                                 RCM_RPFW_REG(RCM_BASE_PTR)
#define RCM_MR                                   RCM_MR_REG(RCM_BASE_PTR)

/*! \} */ /* end of group RCM_Register_Accessor_Macros */


/*! \} */ /* end of group RCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- RFSYS
   ---------------------------------------------------------------------------- */

/*! \addtogroup RFSYS_Peripheral RFSYS */
/*! \{ */

/*! RFSYS - Peripheral register structure */
typedef struct RFSYS_MemMap {
  uint32_t REG[8];                                 /*!< Register file register, array offset: 0x0, array step: 0x4 */
} volatile *RFSYS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros */
/*! \{ */


/* RFSYS - Register accessors */
#define RFSYS_REG_REG(base,index)                ((base)->REG[index])

/*! \} */ /* end of group RFSYS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RFSYS Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup RFSYS_Register_Masks RFSYS Register Masks */
/*! \{ */

/* REG Bit Fields */
#define RFSYS_REG_LL_MASK                        0xFFu
#define RFSYS_REG_LL_SHIFT                       0
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK)
#define RFSYS_REG_LH_MASK                        0xFF00u
#define RFSYS_REG_LH_SHIFT                       8
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK)
#define RFSYS_REG_HL_MASK                        0xFF0000u
#define RFSYS_REG_HL_SHIFT                       16
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK)
#define RFSYS_REG_HH_MASK                        0xFF000000u
#define RFSYS_REG_HH_SHIFT                       24
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK)

/*! \} */ /* end of group RFSYS_Register_Masks */


/* RFSYS - Peripheral instance base addresses */
/*! Peripheral RFSYS base pointer */
#define RFSYS_BASE_PTR                           ((RFSYS_MemMapPtr)0xFFFF8060u)

/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros */
/*! \{ */


/* RFSYS - Register instance definitions */
/* RFSYS */
#define RFSYS_REG0                               RFSYS_REG_REG(RFSYS_BASE_PTR,0)
#define RFSYS_REG1                               RFSYS_REG_REG(RFSYS_BASE_PTR,1)
#define RFSYS_REG2                               RFSYS_REG_REG(RFSYS_BASE_PTR,2)
#define RFSYS_REG3                               RFSYS_REG_REG(RFSYS_BASE_PTR,3)
#define RFSYS_REG4                               RFSYS_REG_REG(RFSYS_BASE_PTR,4)
#define RFSYS_REG5                               RFSYS_REG_REG(RFSYS_BASE_PTR,5)
#define RFSYS_REG6                               RFSYS_REG_REG(RFSYS_BASE_PTR,6)
#define RFSYS_REG7                               RFSYS_REG_REG(RFSYS_BASE_PTR,7)

/* RFSYS - Register array accessors */
#define RFSYS_REG(index)                         RFSYS_REG_REG(RFSYS_BASE_PTR,index)

/*! \} */ /* end of group RFSYS_Register_Accessor_Macros */


/*! \} */ /* end of group RFSYS_Peripheral */


/* ----------------------------------------------------------------------------
   -- RGPIO
   ---------------------------------------------------------------------------- */

/*! \addtogroup RGPIO_Peripheral RGPIO */
/*! \{ */

/*! RGPIO - Peripheral register structure */
typedef struct RGPIO_MemMap {
  uint16_t DIR;                                    /*!< RGPIO Data Direction Register, offset: 0x0 */
  uint16_t DATA;                                   /*!< RGPIO Data Register, offset: 0x2 */
  uint16_t ENB;                                    /*!< RGPIO Pin Enable Register, offset: 0x4 */
  uint16_t CLR;                                    /*!< RGPIO Clear Data Register, offset: 0x6 */
  uint8_t RESERVED_0[2];
  uint16_t SET;                                    /*!< RGPIO Set Data Register, offset: 0xA */
  uint8_t RESERVED_1[2];
  uint16_t TOG;                                    /*!< RGPIO Toggle Data Register, offset: 0xE */
} volatile *RGPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RGPIO_Register_Accessor_Macros RGPIO - Register accessor macros */
/*! \{ */


/* RGPIO - Register accessors */
#define RGPIO_DIR_REG(base)                      ((base)->DIR)
#define RGPIO_DATA_REG(base)                     ((base)->DATA)
#define RGPIO_ENB_REG(base)                      ((base)->ENB)
#define RGPIO_CLR_REG(base)                      ((base)->CLR)
#define RGPIO_SET_REG(base)                      ((base)->SET)
#define RGPIO_TOG_REG(base)                      ((base)->TOG)

/*! \} */ /* end of group RGPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RGPIO Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup RGPIO_Register_Masks RGPIO Register Masks */
/*! \{ */

/* DIR Bit Fields */
#define RGPIO_DIR_DIR_MASK                       0xFFFFu
#define RGPIO_DIR_DIR_SHIFT                      0
#define RGPIO_DIR_DIR(x)                         (((uint16_t)(((uint16_t)(x))<<RGPIO_DIR_DIR_SHIFT))&RGPIO_DIR_DIR_MASK)
/* DATA Bit Fields */
#define RGPIO_DATA_DATA_MASK                     0xFFFFu
#define RGPIO_DATA_DATA_SHIFT                    0
#define RGPIO_DATA_DATA(x)                       (((uint16_t)(((uint16_t)(x))<<RGPIO_DATA_DATA_SHIFT))&RGPIO_DATA_DATA_MASK)
/* ENB Bit Fields */
#define RGPIO_ENB_ENB_MASK                       0xFFFFu
#define RGPIO_ENB_ENB_SHIFT                      0
#define RGPIO_ENB_ENB(x)                         (((uint16_t)(((uint16_t)(x))<<RGPIO_ENB_ENB_SHIFT))&RGPIO_ENB_ENB_MASK)
/* CLR Bit Fields */
#define RGPIO_CLR_CLR_MASK                       0xFFFFu
#define RGPIO_CLR_CLR_SHIFT                      0
#define RGPIO_CLR_CLR(x)                         (((uint16_t)(((uint16_t)(x))<<RGPIO_CLR_CLR_SHIFT))&RGPIO_CLR_CLR_MASK)
/* SET Bit Fields */
#define RGPIO_SET_SET_MASK                       0xFFFFu
#define RGPIO_SET_SET_SHIFT                      0
#define RGPIO_SET_SET(x)                         (((uint16_t)(((uint16_t)(x))<<RGPIO_SET_SET_SHIFT))&RGPIO_SET_SET_MASK)
/* TOG Bit Fields */
#define RGPIO_TOG_TOG_MASK                       0xFFFFu
#define RGPIO_TOG_TOG_SHIFT                      0
#define RGPIO_TOG_TOG(x)                         (((uint16_t)(((uint16_t)(x))<<RGPIO_TOG_TOG_SHIFT))&RGPIO_TOG_TOG_MASK)

/*! \} */ /* end of group RGPIO_Register_Masks */


/* RGPIO - Peripheral instance base addresses */
/*! Peripheral RGPIO base pointer */
#define RGPIO_BASE_PTR                           ((RGPIO_MemMapPtr)0xC00000u)

/* ----------------------------------------------------------------------------
   -- RGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RGPIO_Register_Accessor_Macros RGPIO - Register accessor macros */
/*! \{ */


/* RGPIO - Register instance definitions */
/* RGPIO */
#define RGPIO_DIR                                RGPIO_DIR_REG(RGPIO_BASE_PTR)
#define RGPIO_DATA                               RGPIO_DATA_REG(RGPIO_BASE_PTR)
#define RGPIO_ENB                                RGPIO_ENB_REG(RGPIO_BASE_PTR)
#define RGPIO_CLR                                RGPIO_CLR_REG(RGPIO_BASE_PTR)
#define RGPIO_SET                                RGPIO_SET_REG(RGPIO_BASE_PTR)
#define RGPIO_TOG                                RGPIO_TOG_REG(RGPIO_BASE_PTR)

/*! \} */ /* end of group RGPIO_Register_Accessor_Macros */


/*! \} */ /* end of group RGPIO_Peripheral */


/* ----------------------------------------------------------------------------
   -- SIM
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Peripheral SIM */
/*! \{ */

/*! SIM - Peripheral register structure */
typedef struct SIM_MemMap {
  uint8_t SOPT1;                                   /*!< System Options Register 1, offset: 0x0 */
  uint8_t SOPT2;                                   /*!< System Options Register 2, offset: 0x1 */
  uint8_t SOPT3;                                   /*!< System Options Register 3, offset: 0x2 */
  uint8_t SOPT4;                                   /*!< System Options Register 4, offset: 0x3 */
  uint8_t SOPT5;                                   /*!< System Options Register 5, offset: 0x4 */
  uint8_t SOPT6;                                   /*!< System Options Register 6, offset: 0x5 */
  uint8_t SOPT7;                                   /*!< System Options Register 7, offset: 0x6 */
  uint8_t RESERVED_0[3];
  uint8_t COPC;                                    /*!< COP Control Register, offset: 0xA */
  uint8_t SRVCOP;                                  /*!< Service COP Register, offset: 0xB */
  uint8_t RESERVED_1[1];
  uint8_t OSC1;                                    /*!< Oscillator 1 Control Register, offset: 0xD */
  uint8_t RESERVED_2[2];
  uint8_t SDIDH;                                   /*!< Device Identification High Register, offset: 0x10 */
  uint8_t SDIDL;                                   /*!< Device Identification Low Register, offset: 0x11 */
  uint8_t SCGC1;                                   /*!< Clock Gate Control Register 1, offset: 0x12 */
  uint8_t SCGC2;                                   /*!< Clock Gate Control Register 2, offset: 0x13 */
  uint8_t SCGC3;                                   /*!< Clock Gate Control Register 3, offset: 0x14 */
  uint8_t SCGC4;                                   /*!< Clock Gate Control Register 4, offset: 0x15 */
  uint8_t SCGC5;                                   /*!< Clock Gate Control Register 5, offset: 0x16 */
  uint8_t SCGC6;                                   /*!< Clock Gate Control Register 6, offset: 0x17 */
  uint8_t RESERVED_3[2];
  uint8_t CLKOUT;                                  /*!< Clockout Register, offset: 0x1A */
  uint8_t CLKDIV0;                                 /*!< Clock Divider 0 Register, offset: 0x1B */
  uint8_t CLKDIV1;                                 /*!< Clock Divider 1 Register, offset: 0x1C */
  uint8_t RESERVED_4[3];
  uint8_t SPCR;                                    /*!< Flash Configuration Register, offset: 0x20 */
  uint8_t RESERVED_5[3];
  uint8_t UIDH3;                                   /*!< Unique Identification Register, offset: 0x24 */
  uint8_t UIDH2;                                   /*!< Unique Identification Register, offset: 0x25 */
  uint8_t UIDH1;                                   /*!< Unique Identification Register, offset: 0x26 */
  uint8_t UIDH0;                                   /*!< Unique Identification Register, offset: 0x27 */
  uint8_t UIDMH3;                                  /*!< Unique Identification Register, offset: 0x28 */
  uint8_t UIDMH2;                                  /*!< Unique Identification Register, offset: 0x29 */
  uint8_t UIDMH1;                                  /*!< Unique Identification Register, offset: 0x2A */
  uint8_t UIDMH0;                                  /*!< Unique Identification Register, offset: 0x2B */
  uint8_t UIDML3;                                  /*!< Unique Identification Register, offset: 0x2C */
  uint8_t UIDML2;                                  /*!< Unique Identification Register, offset: 0x2D */
  uint8_t UIDML1;                                  /*!< Unique Identification Register, offset: 0x2E */
  uint8_t UIDML0;                                  /*!< Unique Identification Register, offset: 0x2F */
  uint8_t UIDL3;                                   /*!< Unique Identification Register, offset: 0x30 */
  uint8_t UIDL2;                                   /*!< Unique Identification Register, offset: 0x31 */
  uint8_t UIDL1;                                   /*!< Unique Identification Register, offset: 0x32 */
  uint8_t UIDL0;                                   /*!< Unique Identification Register, offset: 0x33 */
} volatile *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros */
/*! \{ */


/* SIM - Register accessors */
#define SIM_SOPT1_REG(base)                      ((base)->SOPT1)
#define SIM_SOPT2_REG(base)                      ((base)->SOPT2)
#define SIM_SOPT3_REG(base)                      ((base)->SOPT3)
#define SIM_SOPT4_REG(base)                      ((base)->SOPT4)
#define SIM_SOPT5_REG(base)                      ((base)->SOPT5)
#define SIM_SOPT6_REG(base)                      ((base)->SOPT6)
#define SIM_SOPT7_REG(base)                      ((base)->SOPT7)
#define SIM_COPC_REG(base)                       ((base)->COPC)
#define SIM_SRVCOP_REG(base)                     ((base)->SRVCOP)
#define SIM_OSC1_REG(base)                       ((base)->OSC1)
#define SIM_SDIDH_REG(base)                      ((base)->SDIDH)
#define SIM_SDIDL_REG(base)                      ((base)->SDIDL)
#define SIM_SCGC1_REG(base)                      ((base)->SCGC1)
#define SIM_SCGC2_REG(base)                      ((base)->SCGC2)
#define SIM_SCGC3_REG(base)                      ((base)->SCGC3)
#define SIM_SCGC4_REG(base)                      ((base)->SCGC4)
#define SIM_SCGC5_REG(base)                      ((base)->SCGC5)
#define SIM_SCGC6_REG(base)                      ((base)->SCGC6)
#define SIM_CLKOUT_REG(base)                     ((base)->CLKOUT)
#define SIM_CLKDIV0_REG(base)                    ((base)->CLKDIV0)
#define SIM_CLKDIV1_REG(base)                    ((base)->CLKDIV1)
#define SIM_SPCR_REG(base)                       ((base)->SPCR)
#define SIM_UIDH3_REG(base)                      ((base)->UIDH3)
#define SIM_UIDH2_REG(base)                      ((base)->UIDH2)
#define SIM_UIDH1_REG(base)                      ((base)->UIDH1)
#define SIM_UIDH0_REG(base)                      ((base)->UIDH0)
#define SIM_UIDMH3_REG(base)                     ((base)->UIDMH3)
#define SIM_UIDMH2_REG(base)                     ((base)->UIDMH2)
#define SIM_UIDMH1_REG(base)                     ((base)->UIDMH1)
#define SIM_UIDMH0_REG(base)                     ((base)->UIDMH0)
#define SIM_UIDML3_REG(base)                     ((base)->UIDML3)
#define SIM_UIDML2_REG(base)                     ((base)->UIDML2)
#define SIM_UIDML1_REG(base)                     ((base)->UIDML1)
#define SIM_UIDML0_REG(base)                     ((base)->UIDML0)
#define SIM_UIDL3_REG(base)                      ((base)->UIDL3)
#define SIM_UIDL2_REG(base)                      ((base)->UIDL2)
#define SIM_UIDL1_REG(base)                      ((base)->UIDL1)
#define SIM_UIDL0_REG(base)                      ((base)->UIDL0)

/*! \} */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Masks SIM Register Masks */
/*! \{ */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_VSTB_MASK                      0x20u
#define SIM_SOPT1_VSTB_SHIFT                     5
#define SIM_SOPT1_SSTB_MASK                      0x40u
#define SIM_SOPT1_SSTB_SHIFT                     6
#define SIM_SOPT1_REGE_MASK                      0x80u
#define SIM_SOPT1_REGE_SHIFT                     7
/* SOPT2 Bit Fields */
#define SIM_SOPT2_RAMSIZE_MASK                   0xF0u
#define SIM_SOPT2_RAMSIZE_SHIFT                  4
#define SIM_SOPT2_RAMSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<SIM_SOPT2_RAMSIZE_SHIFT))&SIM_SOPT2_RAMSIZE_MASK)
/* SOPT3 Bit Fields */
#define SIM_SOPT3_RWE_MASK                       0x1u
#define SIM_SOPT3_RWE_SHIFT                      0
#define SIM_SOPT3_SWE_MASK                       0x2u
#define SIM_SOPT3_SWE_SHIFT                      1
/* SOPT4 Bit Fields */
#define SIM_SOPT4_VLLDBGREQ_MASK                 0x1u
#define SIM_SOPT4_VLLDBGREQ_SHIFT                0
#define SIM_SOPT4_WAITE_MASK                     0x10u
#define SIM_SOPT4_WAITE_SHIFT                    4
#define SIM_SOPT4_STOPE_MASK                     0x20u
#define SIM_SOPT4_STOPE_SHIFT                    5
/* SOPT5 Bit Fields */
#define SIM_SOPT5_F0ECS_MASK                     0x1u
#define SIM_SOPT5_F0ECS_SHIFT                    0
#define SIM_SOPT5_F1ECS_MASK                     0x2u
#define SIM_SOPT5_F1ECS_SHIFT                    1
#define SIM_SOPT5_MECS_MASK                      0xCu
#define SIM_SOPT5_MECS_SHIFT                     2
#define SIM_SOPT5_MECS(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_SOPT5_MECS_SHIFT))&SIM_SOPT5_MECS_MASK)
/* SOPT6 Bit Fields */
#define SIM_SOPT6_PTC5PAD_MASK                   0x1u
#define SIM_SOPT6_PTC5PAD_SHIFT                  0
#define SIM_SOPT6_PTF6PAD_MASK                   0x2u
#define SIM_SOPT6_PTF6PAD_SHIFT                  1
#define SIM_SOPT6_MODTX1_MASK                    0x4u
#define SIM_SOPT6_MODTX1_SHIFT                   2
#define SIM_SOPT6_RX1IN_MASK                     0x8u
#define SIM_SOPT6_RX1IN_SHIFT                    3
#define SIM_SOPT6_MTBASE1_MASK                   0x30u
#define SIM_SOPT6_MTBASE1_SHIFT                  4
#define SIM_SOPT6_MTBASE1(x)                     (((uint8_t)(((uint8_t)(x))<<SIM_SOPT6_MTBASE1_SHIFT))&SIM_SOPT6_MTBASE1_MASK)
#define SIM_SOPT6_MBSL_MASK                      0xC0u
#define SIM_SOPT6_MBSL_SHIFT                     6
#define SIM_SOPT6_MBSL(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_SOPT6_MBSL_SHIFT))&SIM_SOPT6_MBSL_MASK)
/* SOPT7 Bit Fields */
#define SIM_SOPT7_FTM0SYNC_MASK                  0x1u
#define SIM_SOPT7_FTM0SYNC_SHIFT                 0
#define SIM_SOPT7_FTM1SYNC_MASK                  0x2u
#define SIM_SOPT7_FTM1SYNC_SHIFT                 1
#define SIM_SOPT7_I2CDR0_MASK                    0x8u
#define SIM_SOPT7_I2CDR0_SHIFT                   3
#define SIM_SOPT7_I2CDR2_MASK                    0x10u
#define SIM_SOPT7_I2CDR2_SHIFT                   4
#define SIM_SOPT7_ACFTM_MASK                     0x20u
#define SIM_SOPT7_ACFTM_SHIFT                    5
#define SIM_SOPT7_ADTRGS_MASK                    0x40u
#define SIM_SOPT7_ADTRGS_SHIFT                   6
#define SIM_SOPT7_USBBE_MASK                     0x80u
#define SIM_SOPT7_USBBE_SHIFT                    7
/* COPC Bit Fields */
#define SIM_COPC_COPW_MASK                       0x1u
#define SIM_COPC_COPW_SHIFT                      0
#define SIM_COPC_COPCLKS_MASK                    0x2u
#define SIM_COPC_COPCLKS_SHIFT                   1
#define SIM_COPC_COPT_MASK                       0xCu
#define SIM_COPC_COPT_SHIFT                      2
#define SIM_COPC_COPT(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_COPC_COPT_SHIFT))&SIM_COPC_COPT_MASK)
/* SRVCOP Bit Fields */
#define SIM_SRVCOP_SRVCOP_MASK                   0xFFu
#define SIM_SRVCOP_SRVCOP_SHIFT                  0
#define SIM_SRVCOP_SRVCOP(x)                     (((uint8_t)(((uint8_t)(x))<<SIM_SRVCOP_SRVCOP_SHIFT))&SIM_SRVCOP_SRVCOP_MASK)
/* OSC1 Bit Fields */
#define SIM_OSC1_OSC1EREFS_MASK                  0x2u
#define SIM_OSC1_OSC1EREFS_SHIFT                 1
#define SIM_OSC1_OSC1HGO_MASK                    0x4u
#define SIM_OSC1_OSC1HGO_SHIFT                   2
#define SIM_OSC1_OSC1RANGE_MASK                  0x18u
#define SIM_OSC1_OSC1RANGE_SHIFT                 3
#define SIM_OSC1_OSC1RANGE(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_OSC1_OSC1RANGE_SHIFT))&SIM_OSC1_OSC1RANGE_MASK)
#define SIM_OSC1_OSC1EN_MASK                     0x80u
#define SIM_OSC1_OSC1EN_SHIFT                    7
/* SDIDH Bit Fields */
#define SIM_SDIDH_ID_MASK                        0xFu
#define SIM_SDIDH_ID_SHIFT                       0
#define SIM_SDIDH_ID(x)                          (((uint8_t)(((uint8_t)(x))<<SIM_SDIDH_ID_SHIFT))&SIM_SDIDH_ID_MASK)
#define SIM_SDIDH_REV_MASK                       0xF0u
#define SIM_SDIDH_REV_SHIFT                      4
#define SIM_SDIDH_REV(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_SDIDH_REV_SHIFT))&SIM_SDIDH_REV_MASK)
/* SDIDL Bit Fields */
#define SIM_SDIDL_ID_MASK                        0xFFu
#define SIM_SDIDL_ID_SHIFT                       0
#define SIM_SDIDL_ID(x)                          (((uint8_t)(((uint8_t)(x))<<SIM_SDIDL_ID_SHIFT))&SIM_SDIDL_ID_MASK)
/* SCGC1 Bit Fields */
#define SIM_SCGC1_UART0_MASK                     0x1u
#define SIM_SCGC1_UART0_SHIFT                    0
#define SIM_SCGC1_UART1_MASK                     0x2u
#define SIM_SCGC1_UART1_SHIFT                    1
#define SIM_SCGC1_SPI0_MASK                      0x4u
#define SIM_SCGC1_SPI0_SHIFT                     2
#define SIM_SCGC1_SPI1_MASK                      0x8u
#define SIM_SCGC1_SPI1_SHIFT                     3
#define SIM_SCGC1_I2C0_MASK                      0x10u
#define SIM_SCGC1_I2C0_SHIFT                     4
#define SIM_SCGC1_I2C1_MASK                      0x20u
#define SIM_SCGC1_I2C1_SHIFT                     5
#define SIM_SCGC1_I2C2_MASK                      0x40u
#define SIM_SCGC1_I2C2_SHIFT                     6
#define SIM_SCGC1_I2C3_MASK                      0x80u
#define SIM_SCGC1_I2C3_SHIFT                     7
/* SCGC2 Bit Fields */
#define SIM_SCGC2_DAC12B_MASK                    0x1u
#define SIM_SCGC2_DAC12B_SHIFT                   0
#define SIM_SCGC2_ADC_MASK                       0x2u
#define SIM_SCGC2_ADC_SHIFT                      1
#define SIM_SCGC2_VREF_MASK                      0x10u
#define SIM_SCGC2_VREF_SHIFT                     4
#define SIM_SCGC2_TSI_MASK                       0x20u
#define SIM_SCGC2_TSI_SHIFT                      5
#define SIM_SCGC2_CMP_MASK                       0x40u
#define SIM_SCGC2_CMP_SHIFT                      6
#define SIM_SCGC2_I2S_MASK                       0x80u
#define SIM_SCGC2_I2S_SHIFT                      7
/* SCGC3 Bit Fields */
#define SIM_SCGC3_FTM0_MASK                      0x4u
#define SIM_SCGC3_FTM0_SHIFT                     2
#define SIM_SCGC3_FTM1_MASK                      0x8u
#define SIM_SCGC3_FTM1_SHIFT                     3
#define SIM_SCGC3_MTIM_MASK                      0x10u
#define SIM_SCGC3_MTIM_SHIFT                     4
#define SIM_SCGC3_CMT_MASK                       0x20u
#define SIM_SCGC3_CMT_SHIFT                      5
#define SIM_SCGC3_PDB_MASK                       0x40u
#define SIM_SCGC3_PDB_SHIFT                      6
#define SIM_SCGC3_CRC_MASK                       0x80u
#define SIM_SCGC3_CRC_SHIFT                      7
/* SCGC4 Bit Fields */
#define SIM_SCGC4_WDOG_MASK                      0x1u
#define SIM_SCGC4_WDOG_SHIFT                     0
#define SIM_SCGC4_IRQ_MASK                       0x2u
#define SIM_SCGC4_IRQ_SHIFT                      1
#define SIM_SCGC4_DMA_MASK                       0x8u
#define SIM_SCGC4_DMA_SHIFT                      3
#define SIM_SCGC4_FTFL_MASK                      0x80u
#define SIM_SCGC4_FTFL_SHIFT                     7
/* SCGC5 Bit Fields */
#define SIM_SCGC5_MCG_MASK                       0x1u
#define SIM_SCGC5_MCG_SHIFT                      0
#define SIM_SCGC5_OSC1_MASK                      0x2u
#define SIM_SCGC5_OSC1_SHIFT                     1
#define SIM_SCGC5_OSC2_MASK                      0x4u
#define SIM_SCGC5_OSC2_SHIFT                     2
#define SIM_SCGC5_MFBUS_MASK                     0x40u
#define SIM_SCGC5_MFBUS_SHIFT                    6
/* SCGC6 Bit Fields */
#define SIM_SCGC6_PORTA_MASK                     0x1u
#define SIM_SCGC6_PORTA_SHIFT                    0
#define SIM_SCGC6_PORTB_MASK                     0x2u
#define SIM_SCGC6_PORTB_SHIFT                    1
#define SIM_SCGC6_PORTC_MASK                     0x4u
#define SIM_SCGC6_PORTC_SHIFT                    2
#define SIM_SCGC6_PORTD_MASK                     0x8u
#define SIM_SCGC6_PORTD_SHIFT                    3
#define SIM_SCGC6_PORTE_MASK                     0x10u
#define SIM_SCGC6_PORTE_SHIFT                    4
#define SIM_SCGC6_PORTF_MASK                     0x20u
#define SIM_SCGC6_PORTF_SHIFT                    5
#define SIM_SCGC6_USBDCD_MASK                    0x40u
#define SIM_SCGC6_USBDCD_SHIFT                   6
#define SIM_SCGC6_USBOTG_MASK                    0x80u
#define SIM_SCGC6_USBOTG_SHIFT                   7
/* CLKOUT Bit Fields */
#define SIM_CLKOUT_CLKOUTDIV_MASK                0x7u
#define SIM_CLKOUT_CLKOUTDIV_SHIFT               0
#define SIM_CLKOUT_CLKOUTDIV(x)                  (((uint8_t)(((uint8_t)(x))<<SIM_CLKOUT_CLKOUTDIV_SHIFT))&SIM_CLKOUT_CLKOUTDIV_MASK)
#define SIM_CLKOUT_CS_MASK                       0x70u
#define SIM_CLKOUT_CS_SHIFT                      4
#define SIM_CLKOUT_CS(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_CLKOUT_CS_SHIFT))&SIM_CLKOUT_CS_MASK)
/* CLKDIV0 Bit Fields */
#define SIM_CLKDIV0_OUTDIV_MASK                  0xFu
#define SIM_CLKDIV0_OUTDIV_SHIFT                 0
#define SIM_CLKDIV0_OUTDIV(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV0_OUTDIV_SHIFT))&SIM_CLKDIV0_OUTDIV_MASK)
/* CLKDIV1 Bit Fields */
#define SIM_CLKDIV1_USBSRC_MASK                  0x3u
#define SIM_CLKDIV1_USBSRC_SHIFT                 0
#define SIM_CLKDIV1_USBSRC(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV1_USBSRC_SHIFT))&SIM_CLKDIV1_USBSRC_MASK)
#define SIM_CLKDIV1_USBFRAC_MASK                 0x10u
#define SIM_CLKDIV1_USBFRAC_SHIFT                4
#define SIM_CLKDIV1_USBDIV_MASK                  0xE0u
#define SIM_CLKDIV1_USBDIV_SHIFT                 5
#define SIM_CLKDIV1_USBDIV(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV1_USBDIV_SHIFT))&SIM_CLKDIV1_USBDIV_MASK)
/* SPCR Bit Fields */
#define SIM_SPCR_PFSIZE_MASK                     0xFu
#define SIM_SPCR_PFSIZE_SHIFT                    0
#define SIM_SPCR_PFSIZE(x)                       (((uint8_t)(((uint8_t)(x))<<SIM_SPCR_PFSIZE_SHIFT))&SIM_SPCR_PFSIZE_MASK)
#define SIM_SPCR_NVMSIZE_MASK                    0xF0u
#define SIM_SPCR_NVMSIZE_SHIFT                   4
#define SIM_SPCR_NVMSIZE(x)                      (((uint8_t)(((uint8_t)(x))<<SIM_SPCR_NVMSIZE_SHIFT))&SIM_SPCR_NVMSIZE_MASK)
/* UIDH3 Bit Fields */
#define SIM_UIDH3_UID_MASK                       0xFFu
#define SIM_UIDH3_UID_SHIFT                      0
#define SIM_UIDH3_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDH3_UID_SHIFT))&SIM_UIDH3_UID_MASK)
/* UIDH2 Bit Fields */
#define SIM_UIDH2_UID_MASK                       0xFFu
#define SIM_UIDH2_UID_SHIFT                      0
#define SIM_UIDH2_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDH2_UID_SHIFT))&SIM_UIDH2_UID_MASK)
/* UIDH1 Bit Fields */
#define SIM_UIDH1_UID_MASK                       0xFFu
#define SIM_UIDH1_UID_SHIFT                      0
#define SIM_UIDH1_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDH1_UID_SHIFT))&SIM_UIDH1_UID_MASK)
/* UIDH0 Bit Fields */
#define SIM_UIDH0_UID_MASK                       0xFFu
#define SIM_UIDH0_UID_SHIFT                      0
#define SIM_UIDH0_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDH0_UID_SHIFT))&SIM_UIDH0_UID_MASK)
/* UIDMH3 Bit Fields */
#define SIM_UIDMH3_UID_MASK                      0xFFu
#define SIM_UIDMH3_UID_SHIFT                     0
#define SIM_UIDMH3_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDMH3_UID_SHIFT))&SIM_UIDMH3_UID_MASK)
/* UIDMH2 Bit Fields */
#define SIM_UIDMH2_UID_MASK                      0xFFu
#define SIM_UIDMH2_UID_SHIFT                     0
#define SIM_UIDMH2_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDMH2_UID_SHIFT))&SIM_UIDMH2_UID_MASK)
/* UIDMH1 Bit Fields */
#define SIM_UIDMH1_UID_MASK                      0xFFu
#define SIM_UIDMH1_UID_SHIFT                     0
#define SIM_UIDMH1_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDMH1_UID_SHIFT))&SIM_UIDMH1_UID_MASK)
/* UIDMH0 Bit Fields */
#define SIM_UIDMH0_UID_MASK                      0xFFu
#define SIM_UIDMH0_UID_SHIFT                     0
#define SIM_UIDMH0_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDMH0_UID_SHIFT))&SIM_UIDMH0_UID_MASK)
/* UIDML3 Bit Fields */
#define SIM_UIDML3_UID_MASK                      0xFFu
#define SIM_UIDML3_UID_SHIFT                     0
#define SIM_UIDML3_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDML3_UID_SHIFT))&SIM_UIDML3_UID_MASK)
/* UIDML2 Bit Fields */
#define SIM_UIDML2_UID_MASK                      0xFFu
#define SIM_UIDML2_UID_SHIFT                     0
#define SIM_UIDML2_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDML2_UID_SHIFT))&SIM_UIDML2_UID_MASK)
/* UIDML1 Bit Fields */
#define SIM_UIDML1_UID_MASK                      0xFFu
#define SIM_UIDML1_UID_SHIFT                     0
#define SIM_UIDML1_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDML1_UID_SHIFT))&SIM_UIDML1_UID_MASK)
/* UIDML0 Bit Fields */
#define SIM_UIDML0_UID_MASK                      0xFFu
#define SIM_UIDML0_UID_SHIFT                     0
#define SIM_UIDML0_UID(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_UIDML0_UID_SHIFT))&SIM_UIDML0_UID_MASK)
/* UIDL3 Bit Fields */
#define SIM_UIDL3_UID_MASK                       0xFFu
#define SIM_UIDL3_UID_SHIFT                      0
#define SIM_UIDL3_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDL3_UID_SHIFT))&SIM_UIDL3_UID_MASK)
/* UIDL2 Bit Fields */
#define SIM_UIDL2_UID_MASK                       0xFFu
#define SIM_UIDL2_UID_SHIFT                      0
#define SIM_UIDL2_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDL2_UID_SHIFT))&SIM_UIDL2_UID_MASK)
/* UIDL1 Bit Fields */
#define SIM_UIDL1_UID_MASK                       0xFFu
#define SIM_UIDL1_UID_SHIFT                      0
#define SIM_UIDL1_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDL1_UID_SHIFT))&SIM_UIDL1_UID_MASK)
/* UIDL0 Bit Fields */
#define SIM_UIDL0_UID_MASK                       0xFFu
#define SIM_UIDL0_UID_SHIFT                      0
#define SIM_UIDL0_UID(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_UIDL0_UID_SHIFT))&SIM_UIDL0_UID_MASK)

/*! \} */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/*! Peripheral SIM base pointer */
#define SIM_BASE_PTR                             ((SIM_MemMapPtr)0xFFFF80C0u)

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros */
/*! \{ */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SOPT1                                SIM_SOPT1_REG(SIM_BASE_PTR)
#define SIM_SOPT2                                SIM_SOPT2_REG(SIM_BASE_PTR)
#define SIM_SOPT3                                SIM_SOPT3_REG(SIM_BASE_PTR)
#define SIM_SOPT4                                SIM_SOPT4_REG(SIM_BASE_PTR)
#define SIM_SOPT5                                SIM_SOPT5_REG(SIM_BASE_PTR)
#define SIM_SOPT6                                SIM_SOPT6_REG(SIM_BASE_PTR)
#define SIM_SOPT7                                SIM_SOPT7_REG(SIM_BASE_PTR)
#define SIM_COPC                                 SIM_COPC_REG(SIM_BASE_PTR)
#define SIM_SRVCOP                               SIM_SRVCOP_REG(SIM_BASE_PTR)
#define SIM_OSC1                                 SIM_OSC1_REG(SIM_BASE_PTR)
#define SIM_SDIDH                                SIM_SDIDH_REG(SIM_BASE_PTR)
#define SIM_SDIDL                                SIM_SDIDL_REG(SIM_BASE_PTR)
#define SIM_SCGC1                                SIM_SCGC1_REG(SIM_BASE_PTR)
#define SIM_SCGC2                                SIM_SCGC2_REG(SIM_BASE_PTR)
#define SIM_SCGC3                                SIM_SCGC3_REG(SIM_BASE_PTR)
#define SIM_SCGC4                                SIM_SCGC4_REG(SIM_BASE_PTR)
#define SIM_SCGC5                                SIM_SCGC5_REG(SIM_BASE_PTR)
#define SIM_SCGC6                                SIM_SCGC6_REG(SIM_BASE_PTR)
#define SIM_CLKOUT                               SIM_CLKOUT_REG(SIM_BASE_PTR)
#define SIM_CLKDIV0                              SIM_CLKDIV0_REG(SIM_BASE_PTR)
#define SIM_CLKDIV1                              SIM_CLKDIV1_REG(SIM_BASE_PTR)
#define SIM_SPCR                                 SIM_SPCR_REG(SIM_BASE_PTR)
#define SIM_UIDH3                                SIM_UIDH3_REG(SIM_BASE_PTR)
#define SIM_UIDH2                                SIM_UIDH2_REG(SIM_BASE_PTR)
#define SIM_UIDH1                                SIM_UIDH1_REG(SIM_BASE_PTR)
#define SIM_UIDH0                                SIM_UIDH0_REG(SIM_BASE_PTR)
#define SIM_UIDMH3                               SIM_UIDMH3_REG(SIM_BASE_PTR)
#define SIM_UIDMH2                               SIM_UIDMH2_REG(SIM_BASE_PTR)
#define SIM_UIDMH1                               SIM_UIDMH1_REG(SIM_BASE_PTR)
#define SIM_UIDMH0                               SIM_UIDMH0_REG(SIM_BASE_PTR)
#define SIM_UIDML3                               SIM_UIDML3_REG(SIM_BASE_PTR)
#define SIM_UIDML2                               SIM_UIDML2_REG(SIM_BASE_PTR)
#define SIM_UIDML1                               SIM_UIDML1_REG(SIM_BASE_PTR)
#define SIM_UIDML0                               SIM_UIDML0_REG(SIM_BASE_PTR)
#define SIM_UIDL3                                SIM_UIDL3_REG(SIM_BASE_PTR)
#define SIM_UIDL2                                SIM_UIDL2_REG(SIM_BASE_PTR)
#define SIM_UIDL1                                SIM_UIDL1_REG(SIM_BASE_PTR)
#define SIM_UIDL0                                SIM_UIDL0_REG(SIM_BASE_PTR)

/*! \} */ /* end of group SIM_Register_Accessor_Macros */


/*! \} */ /* end of group SIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- SMC
   ---------------------------------------------------------------------------- */

/*! \addtogroup SMC_Peripheral SMC */
/*! \{ */

/*! SMC - Peripheral register structure */
typedef struct SMC_MemMap {
  uint8_t PMPROT;                                  /*!< Power Mode Protection Register, offset: 0x0 */
  uint8_t PMCTRL;                                  /*!< Power Mode Control Register, offset: 0x1 */
  uint8_t VLLSCTRL;                                /*!< VLLS Control Register, offset: 0x2 */
  uint8_t PMSTAT;                                  /*!< Power Mode Status Register, offset: 0x3 */
} volatile *SMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros */
/*! \{ */


/* SMC - Register accessors */
#define SMC_PMPROT_REG(base)                     ((base)->PMPROT)
#define SMC_PMCTRL_REG(base)                     ((base)->PMCTRL)
#define SMC_VLLSCTRL_REG(base)                   ((base)->VLLSCTRL)
#define SMC_PMSTAT_REG(base)                     ((base)->PMSTAT)

/*! \} */ /* end of group SMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SMC_Register_Masks SMC Register Masks */
/*! \{ */

/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLLS_MASK                    0x2u
#define SMC_PMPROT_AVLLS_SHIFT                   1
#define SMC_PMPROT_ALLS_MASK                     0x8u
#define SMC_PMPROT_ALLS_SHIFT                    3
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    0x8u
#define SMC_PMCTRL_STOPA_SHIFT                   3
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
#define SMC_PMCTRL_LPWUI_MASK                    0x80u
#define SMC_PMCTRL_LPWUI_SHIFT                   7
/* VLLSCTRL Bit Fields */
#define SMC_VLLSCTRL_VLLSM_MASK                  0x7u
#define SMC_VLLSCTRL_VLLSM_SHIFT                 0
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK)
#define SMC_VLLSCTRL_RAM2PO_MASK                 0x10u
#define SMC_VLLSCTRL_RAM2PO_SHIFT                4
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0x7Fu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/*! \} */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/*! Peripheral SMC base pointer */
#define SMC_BASE_PTR                             ((SMC_MemMapPtr)0xFFFF8118u)

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros */
/*! \{ */


/* SMC - Register instance definitions */
/* SMC */
#define SMC_PMPROT                               SMC_PMPROT_REG(SMC_BASE_PTR)
#define SMC_PMCTRL                               SMC_PMCTRL_REG(SMC_BASE_PTR)
#define SMC_VLLSCTRL                             SMC_VLLSCTRL_REG(SMC_BASE_PTR)
#define SMC_PMSTAT                               SMC_PMSTAT_REG(SMC_BASE_PTR)

/*! \} */ /* end of group SMC_Register_Accessor_Macros */


/*! \} */ /* end of group SMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SPI
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Peripheral SPI */
/*! \{ */

/*! SPI - Peripheral register structure */
typedef struct SPI_MemMap {
  uint8_t C1;                                      /*!< SPI control register 1, offset: 0x0 */
  uint8_t C2;                                      /*!< SPI control register 2, offset: 0x1 */
  uint8_t BR;                                      /*!< SPI baud rate register, offset: 0x2 */
  uint8_t S;                                       /*!< SPI status register, offset: 0x3 */
  uint8_t DH;                                      /*!< SPI data register high, offset: 0x4 */
  uint8_t DL;                                      /*!< SPI data register low, offset: 0x5 */
  uint8_t MH;                                      /*!< SPI match register high, offset: 0x6 */
  uint8_t ML;                                      /*!< SPI match register low, offset: 0x7 */
  uint8_t C3;                                      /*!< SPI control register 3, offset: 0x8 */
  uint8_t CI;                                      /*!< SPI clear interrupt register, offset: 0x9 */
} volatile *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros */
/*! \{ */


/* SPI - Register accessors */
#define SPI_C1_REG(base)                         ((base)->C1)
#define SPI_C2_REG(base)                         ((base)->C2)
#define SPI_BR_REG(base)                         ((base)->BR)
#define SPI_S_REG(base)                          ((base)->S)
#define SPI_DH_REG(base)                         ((base)->DH)
#define SPI_DL_REG(base)                         ((base)->DL)
#define SPI_MH_REG(base)                         ((base)->MH)
#define SPI_ML_REG(base)                         ((base)->ML)
#define SPI_C3_REG(base)                         ((base)->C3)
#define SPI_CI_REG(base)                         ((base)->CI)

/*! \} */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Masks SPI Register Masks */
/*! \{ */

/* C1 Bit Fields */
#define SPI_C1_LSBFE_MASK                        0x1u
#define SPI_C1_LSBFE_SHIFT                       0
#define SPI_C1_SSOE_MASK                         0x2u
#define SPI_C1_SSOE_SHIFT                        1
#define SPI_C1_CPHA_MASK                         0x4u
#define SPI_C1_CPHA_SHIFT                        2
#define SPI_C1_CPOL_MASK                         0x8u
#define SPI_C1_CPOL_SHIFT                        3
#define SPI_C1_MSTR_MASK                         0x10u
#define SPI_C1_MSTR_SHIFT                        4
#define SPI_C1_SPTIE_MASK                        0x20u
#define SPI_C1_SPTIE_SHIFT                       5
#define SPI_C1_SPE_MASK                          0x40u
#define SPI_C1_SPE_SHIFT                         6
#define SPI_C1_SPIE_MASK                         0x80u
#define SPI_C1_SPIE_SHIFT                        7
/* C2 Bit Fields */
#define SPI_C2_SPC0_MASK                         0x1u
#define SPI_C2_SPC0_SHIFT                        0
#define SPI_C2_SPISWAI_MASK                      0x2u
#define SPI_C2_SPISWAI_SHIFT                     1
#define SPI_C2_RXDMAE_MASK                       0x4u
#define SPI_C2_RXDMAE_SHIFT                      2
#define SPI_C2_BIDIROE_MASK                      0x8u
#define SPI_C2_BIDIROE_SHIFT                     3
#define SPI_C2_MODFEN_MASK                       0x10u
#define SPI_C2_MODFEN_SHIFT                      4
#define SPI_C2_TXDMAE_MASK                       0x20u
#define SPI_C2_TXDMAE_SHIFT                      5
#define SPI_C2_SPIMODE_MASK                      0x40u
#define SPI_C2_SPIMODE_SHIFT                     6
#define SPI_C2_SPMIE_MASK                        0x80u
#define SPI_C2_SPMIE_SHIFT                       7
/* BR Bit Fields */
#define SPI_BR_SPR_MASK                          0xFu
#define SPI_BR_SPR_SHIFT                         0
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK)
#define SPI_BR_SPPR_MASK                         0x70u
#define SPI_BR_SPPR_SHIFT                        4
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK)
/* S Bit Fields */
#define SPI_S_RFIFOEF_MASK                       0x1u
#define SPI_S_RFIFOEF_SHIFT                      0
#define SPI_S_TXFULLF_MASK                       0x2u
#define SPI_S_TXFULLF_SHIFT                      1
#define SPI_S_TNEAREF_MASK                       0x4u
#define SPI_S_TNEAREF_SHIFT                      2
#define SPI_S_RNFULLF_MASK                       0x8u
#define SPI_S_RNFULLF_SHIFT                      3
#define SPI_S_MODF_MASK                          0x10u
#define SPI_S_MODF_SHIFT                         4
#define SPI_S_SPTEF_MASK                         0x20u
#define SPI_S_SPTEF_SHIFT                        5
#define SPI_S_SPMF_MASK                          0x40u
#define SPI_S_SPMF_SHIFT                         6
#define SPI_S_SPRF_MASK                          0x80u
#define SPI_S_SPRF_SHIFT                         7
/* DH Bit Fields */
#define SPI_DH_Bits_MASK                         0xFFu
#define SPI_DH_Bits_SHIFT                        0
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK)
/* DL Bit Fields */
#define SPI_DL_Bits_MASK                         0xFFu
#define SPI_DL_Bits_SHIFT                        0
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK)
/* MH Bit Fields */
#define SPI_MH_Bits_MASK                         0xFFu
#define SPI_MH_Bits_SHIFT                        0
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK)
/* ML Bit Fields */
#define SPI_ML_Bits_MASK                         0xFFu
#define SPI_ML_Bits_SHIFT                        0
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK)
/* C3 Bit Fields */
#define SPI_C3_FIFOMODE_MASK                     0x1u
#define SPI_C3_FIFOMODE_SHIFT                    0
#define SPI_C3_RNFULLIEN_MASK                    0x2u
#define SPI_C3_RNFULLIEN_SHIFT                   1
#define SPI_C3_TNEARIEN_MASK                     0x4u
#define SPI_C3_TNEARIEN_SHIFT                    2
#define SPI_C3_INTCLR_MASK                       0x8u
#define SPI_C3_INTCLR_SHIFT                      3
#define SPI_C3_RNFULLF_MARK_MASK                 0x10u
#define SPI_C3_RNFULLF_MARK_SHIFT                4
#define SPI_C3_TNEAREF_MARK_MASK                 0x20u
#define SPI_C3_TNEAREF_MARK_SHIFT                5
/* CI Bit Fields */
#define SPI_CI_SPRFCI_MASK                       0x1u
#define SPI_CI_SPRFCI_SHIFT                      0
#define SPI_CI_SPTEFCI_MASK                      0x2u
#define SPI_CI_SPTEFCI_SHIFT                     1
#define SPI_CI_RNFULLFCI_MASK                    0x4u
#define SPI_CI_RNFULLFCI_SHIFT                   2
#define SPI_CI_TNEAREFCI_MASK                    0x8u
#define SPI_CI_TNEAREFCI_SHIFT                   3
#define SPI_CI_RXFOF_MASK                        0x10u
#define SPI_CI_RXFOF_SHIFT                       4
#define SPI_CI_TXFOF_MASK                        0x20u
#define SPI_CI_TXFOF_SHIFT                       5
#define SPI_CI_RXFERR_MASK                       0x40u
#define SPI_CI_RXFERR_SHIFT                      6
#define SPI_CI_TXFERR_MASK                       0x80u
#define SPI_CI_TXFERR_SHIFT                      7

/*! \} */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/*! Peripheral SPI0 base pointer */
#define SPI0_BASE_PTR                            ((SPI_MemMapPtr)0xFFFF81A0u)
/*! Peripheral SPI1 base pointer */
#define SPI1_BASE_PTR                            ((SPI_MemMapPtr)0xFFFF81B0u)

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros */
/*! \{ */


/* SPI - Register instance definitions */
/* SPI0 */
#define SPI0_C1                                  SPI_C1_REG(SPI0_BASE_PTR)
#define SPI0_C2                                  SPI_C2_REG(SPI0_BASE_PTR)
#define SPI0_BR                                  SPI_BR_REG(SPI0_BASE_PTR)
#define SPI0_S                                   SPI_S_REG(SPI0_BASE_PTR)
#define SPI0_DH                                  SPI_DH_REG(SPI0_BASE_PTR)
#define SPI0_DL                                  SPI_DL_REG(SPI0_BASE_PTR)
#define SPI0_MH                                  SPI_MH_REG(SPI0_BASE_PTR)
#define SPI0_ML                                  SPI_ML_REG(SPI0_BASE_PTR)
#define SPI0_C3                                  SPI_C3_REG(SPI0_BASE_PTR)
#define SPI0_CI                                  SPI_CI_REG(SPI0_BASE_PTR)
/* SPI1 */
#define SPI1_C1                                  SPI_C1_REG(SPI1_BASE_PTR)
#define SPI1_C2                                  SPI_C2_REG(SPI1_BASE_PTR)
#define SPI1_BR                                  SPI_BR_REG(SPI1_BASE_PTR)
#define SPI1_S                                   SPI_S_REG(SPI1_BASE_PTR)
#define SPI1_DH                                  SPI_DH_REG(SPI1_BASE_PTR)
#define SPI1_DL                                  SPI_DL_REG(SPI1_BASE_PTR)
#define SPI1_MH                                  SPI_MH_REG(SPI1_BASE_PTR)
#define SPI1_ML                                  SPI_ML_REG(SPI1_BASE_PTR)

/*! \} */ /* end of group SPI_Register_Accessor_Macros */


/*! \} */ /* end of group SPI_Peripheral */


/* ----------------------------------------------------------------------------
   -- TSI
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Peripheral TSI */
/*! \{ */

/*! TSI - Peripheral register structure */
typedef struct TSI_MemMap {
  uint32_t GENCS;                                  /*!< General Control and Status Register, offset: 0x0 */
  uint32_t SCANC;                                  /*!< SCAN control register, offset: 0x4 */
  uint32_t PEN;                                    /*!< Pin enable register, offset: 0x8 */
  uint32_t STATUS;                                 /*!< Status Register, offset: 0xC */
  uint8_t RESERVED_0[240];
  uint32_t CNTR1;                                  /*!< Counter Register, offset: 0x100 */
  uint32_t CNTR3;                                  /*!< Counter Register, offset: 0x104 */
  uint32_t CNTR5;                                  /*!< Counter Register, offset: 0x108 */
  uint32_t CNTR7;                                  /*!< Counter Register, offset: 0x10C */
  uint32_t CNTR9;                                  /*!< Counter Register, offset: 0x110 */
  uint32_t CNTR11;                                 /*!< Counter Register, offset: 0x114 */
  uint32_t CNTR13;                                 /*!< Counter Register, offset: 0x118 */
  uint32_t CNTR15;                                 /*!< Counter Register, offset: 0x11C */
  uint32_t THRESHLD[16];                           /*!< Channel n threshold register, array offset: 0x120, array step: 0x4 */
} volatile *TSI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros */
/*! \{ */


/* TSI - Register accessors */
#define TSI_GENCS_REG(base)                      ((base)->GENCS)
#define TSI_SCANC_REG(base)                      ((base)->SCANC)
#define TSI_PEN_REG(base)                        ((base)->PEN)
#define TSI_STATUS_REG(base)                     ((base)->STATUS)
#define TSI_CNTR1_REG(base)                      ((base)->CNTR1)
#define TSI_CNTR3_REG(base)                      ((base)->CNTR3)
#define TSI_CNTR5_REG(base)                      ((base)->CNTR5)
#define TSI_CNTR7_REG(base)                      ((base)->CNTR7)
#define TSI_CNTR9_REG(base)                      ((base)->CNTR9)
#define TSI_CNTR11_REG(base)                     ((base)->CNTR11)
#define TSI_CNTR13_REG(base)                     ((base)->CNTR13)
#define TSI_CNTR15_REG(base)                     ((base)->CNTR15)
#define TSI_THRESHLD_REG(base,index)             ((base)->THRESHLD[index])

/*! \} */ /* end of group TSI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Masks TSI Register Masks */
/*! \{ */

/* GENCS Bit Fields */
#define TSI_GENCS_STPE_MASK                      0x1u
#define TSI_GENCS_STPE_SHIFT                     0
#define TSI_GENCS_STM_MASK                       0x2u
#define TSI_GENCS_STM_SHIFT                      1
#define TSI_GENCS_ESOR_MASK                      0x10u
#define TSI_GENCS_ESOR_SHIFT                     4
#define TSI_GENCS_ERIE_MASK                      0x20u
#define TSI_GENCS_ERIE_SHIFT                     5
#define TSI_GENCS_TSIIE_MASK                     0x40u
#define TSI_GENCS_TSIIE_SHIFT                    6
#define TSI_GENCS_TSIEN_MASK                     0x80u
#define TSI_GENCS_TSIEN_SHIFT                    7
#define TSI_GENCS_SWTS_MASK                      0x100u
#define TSI_GENCS_SWTS_SHIFT                     8
#define TSI_GENCS_SCNIP_MASK                     0x200u
#define TSI_GENCS_SCNIP_SHIFT                    9
#define TSI_GENCS_OVRF_MASK                      0x1000u
#define TSI_GENCS_OVRF_SHIFT                     12
#define TSI_GENCS_EXTERF_MASK                    0x2000u
#define TSI_GENCS_EXTERF_SHIFT                   13
#define TSI_GENCS_OUTRGF_MASK                    0x4000u
#define TSI_GENCS_OUTRGF_SHIFT                   14
#define TSI_GENCS_EOSF_MASK                      0x8000u
#define TSI_GENCS_EOSF_SHIFT                     15
#define TSI_GENCS_PS_MASK                        0x70000u
#define TSI_GENCS_PS_SHIFT                       16
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK)
#define TSI_GENCS_NSCN_MASK                      0xF80000u
#define TSI_GENCS_NSCN_SHIFT                     19
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK)
#define TSI_GENCS_LPSCNITV_MASK                  0xF000000u
#define TSI_GENCS_LPSCNITV_SHIFT                 24
#define TSI_GENCS_LPSCNITV(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_LPSCNITV_SHIFT))&TSI_GENCS_LPSCNITV_MASK)
#define TSI_GENCS_LPCLKS_MASK                    0x10000000u
#define TSI_GENCS_LPCLKS_SHIFT                   28
/* SCANC Bit Fields */
#define TSI_SCANC_AMPSC_MASK                     0x7u
#define TSI_SCANC_AMPSC_SHIFT                    0
#define TSI_SCANC_AMPSC(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMPSC_SHIFT))&TSI_SCANC_AMPSC_MASK)
#define TSI_SCANC_AMCLKS_MASK                    0x18u
#define TSI_SCANC_AMCLKS_SHIFT                   3
#define TSI_SCANC_AMCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMCLKS_SHIFT))&TSI_SCANC_AMCLKS_MASK)
#define TSI_SCANC_AMCLKDIV_MASK                  0x20u
#define TSI_SCANC_AMCLKDIV_SHIFT                 5
#define TSI_SCANC_SMOD_MASK                      0xFF00u
#define TSI_SCANC_SMOD_SHIFT                     8
#define TSI_SCANC_SMOD(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_SMOD_SHIFT))&TSI_SCANC_SMOD_MASK)
#define TSI_SCANC_DELVOL_MASK                    0x70000u
#define TSI_SCANC_DELVOL_SHIFT                   16
#define TSI_SCANC_DELVOL(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_DELVOL_SHIFT))&TSI_SCANC_DELVOL_MASK)
#define TSI_SCANC_EXTCHRG_MASK                   0xF80000u
#define TSI_SCANC_EXTCHRG_SHIFT                  19
#define TSI_SCANC_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_EXTCHRG_SHIFT))&TSI_SCANC_EXTCHRG_MASK)
#define TSI_SCANC_CAPTRM_MASK                    0x7000000u
#define TSI_SCANC_CAPTRM_SHIFT                   24
#define TSI_SCANC_CAPTRM(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_CAPTRM_SHIFT))&TSI_SCANC_CAPTRM_MASK)
#define TSI_SCANC_REFCHRG_MASK                   0xF8000000u
#define TSI_SCANC_REFCHRG_SHIFT                  27
#define TSI_SCANC_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_REFCHRG_SHIFT))&TSI_SCANC_REFCHRG_MASK)
/* PEN Bit Fields */
#define TSI_PEN_PEN0_MASK                        0x1u
#define TSI_PEN_PEN0_SHIFT                       0
#define TSI_PEN_PEN1_MASK                        0x2u
#define TSI_PEN_PEN1_SHIFT                       1
#define TSI_PEN_PEN2_MASK                        0x4u
#define TSI_PEN_PEN2_SHIFT                       2
#define TSI_PEN_PEN3_MASK                        0x8u
#define TSI_PEN_PEN3_SHIFT                       3
#define TSI_PEN_PEN4_MASK                        0x10u
#define TSI_PEN_PEN4_SHIFT                       4
#define TSI_PEN_PEN5_MASK                        0x20u
#define TSI_PEN_PEN5_SHIFT                       5
#define TSI_PEN_PEN6_MASK                        0x40u
#define TSI_PEN_PEN6_SHIFT                       6
#define TSI_PEN_PEN7_MASK                        0x80u
#define TSI_PEN_PEN7_SHIFT                       7
#define TSI_PEN_PEN8_MASK                        0x100u
#define TSI_PEN_PEN8_SHIFT                       8
#define TSI_PEN_PEN9_MASK                        0x200u
#define TSI_PEN_PEN9_SHIFT                       9
#define TSI_PEN_PEN10_MASK                       0x400u
#define TSI_PEN_PEN10_SHIFT                      10
#define TSI_PEN_PEN11_MASK                       0x800u
#define TSI_PEN_PEN11_SHIFT                      11
#define TSI_PEN_PEN12_MASK                       0x1000u
#define TSI_PEN_PEN12_SHIFT                      12
#define TSI_PEN_PEN13_MASK                       0x2000u
#define TSI_PEN_PEN13_SHIFT                      13
#define TSI_PEN_PEN14_MASK                       0x4000u
#define TSI_PEN_PEN14_SHIFT                      14
#define TSI_PEN_PEN15_MASK                       0x8000u
#define TSI_PEN_PEN15_SHIFT                      15
#define TSI_PEN_LPSP_MASK                        0xF0000u
#define TSI_PEN_LPSP_SHIFT                       16
#define TSI_PEN_LPSP(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_LPSP_SHIFT))&TSI_PEN_LPSP_MASK)
/* STATUS Bit Fields */
#define TSI_STATUS_ORNGF0_MASK                   0x1u
#define TSI_STATUS_ORNGF0_SHIFT                  0
#define TSI_STATUS_ORNGF1_MASK                   0x2u
#define TSI_STATUS_ORNGF1_SHIFT                  1
#define TSI_STATUS_ORNGF2_MASK                   0x4u
#define TSI_STATUS_ORNGF2_SHIFT                  2
#define TSI_STATUS_ORNGF3_MASK                   0x8u
#define TSI_STATUS_ORNGF3_SHIFT                  3
#define TSI_STATUS_ORNGF4_MASK                   0x10u
#define TSI_STATUS_ORNGF4_SHIFT                  4
#define TSI_STATUS_ORNGF5_MASK                   0x20u
#define TSI_STATUS_ORNGF5_SHIFT                  5
#define TSI_STATUS_ORNGF6_MASK                   0x40u
#define TSI_STATUS_ORNGF6_SHIFT                  6
#define TSI_STATUS_ORNGF7_MASK                   0x80u
#define TSI_STATUS_ORNGF7_SHIFT                  7
#define TSI_STATUS_ORNGF8_MASK                   0x100u
#define TSI_STATUS_ORNGF8_SHIFT                  8
#define TSI_STATUS_ORNGF9_MASK                   0x200u
#define TSI_STATUS_ORNGF9_SHIFT                  9
#define TSI_STATUS_ORNGF10_MASK                  0x400u
#define TSI_STATUS_ORNGF10_SHIFT                 10
#define TSI_STATUS_ORNGF11_MASK                  0x800u
#define TSI_STATUS_ORNGF11_SHIFT                 11
#define TSI_STATUS_ORNGF12_MASK                  0x1000u
#define TSI_STATUS_ORNGF12_SHIFT                 12
#define TSI_STATUS_ORNGF13_MASK                  0x2000u
#define TSI_STATUS_ORNGF13_SHIFT                 13
#define TSI_STATUS_ORNGF14_MASK                  0x4000u
#define TSI_STATUS_ORNGF14_SHIFT                 14
#define TSI_STATUS_ORNGF15_MASK                  0x8000u
#define TSI_STATUS_ORNGF15_SHIFT                 15
#define TSI_STATUS_ERROF0_MASK                   0x10000u
#define TSI_STATUS_ERROF0_SHIFT                  16
#define TSI_STATUS_ERROF1_MASK                   0x20000u
#define TSI_STATUS_ERROF1_SHIFT                  17
#define TSI_STATUS_ERROF2_MASK                   0x40000u
#define TSI_STATUS_ERROF2_SHIFT                  18
#define TSI_STATUS_ERROF3_MASK                   0x80000u
#define TSI_STATUS_ERROF3_SHIFT                  19
#define TSI_STATUS_ERROF4_MASK                   0x100000u
#define TSI_STATUS_ERROF4_SHIFT                  20
#define TSI_STATUS_ERROF5_MASK                   0x200000u
#define TSI_STATUS_ERROF5_SHIFT                  21
#define TSI_STATUS_ERROF6_MASK                   0x400000u
#define TSI_STATUS_ERROF6_SHIFT                  22
#define TSI_STATUS_ERROF7_MASK                   0x800000u
#define TSI_STATUS_ERROF7_SHIFT                  23
#define TSI_STATUS_ERROF8_MASK                   0x1000000u
#define TSI_STATUS_ERROF8_SHIFT                  24
#define TSI_STATUS_ERROF9_MASK                   0x2000000u
#define TSI_STATUS_ERROF9_SHIFT                  25
#define TSI_STATUS_ERROF10_MASK                  0x4000000u
#define TSI_STATUS_ERROF10_SHIFT                 26
#define TSI_STATUS_ERROF11_MASK                  0x8000000u
#define TSI_STATUS_ERROF11_SHIFT                 27
#define TSI_STATUS_ERROF12_MASK                  0x10000000u
#define TSI_STATUS_ERROF12_SHIFT                 28
#define TSI_STATUS_ERROF13_MASK                  0x20000000u
#define TSI_STATUS_ERROF13_SHIFT                 29
#define TSI_STATUS_ERROF14_MASK                  0x40000000u
#define TSI_STATUS_ERROF14_SHIFT                 30
#define TSI_STATUS_ERROF15_MASK                  0x80000000u
#define TSI_STATUS_ERROF15_SHIFT                 31
/* CNTR1 Bit Fields */
#define TSI_CNTR1_CNTN_MASK                      0xFFFFu
#define TSI_CNTR1_CNTN_SHIFT                     0
#define TSI_CNTR1_CNTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR1_CNTN_SHIFT))&TSI_CNTR1_CNTN_MASK)
#define TSI_CNTR1_CNTN1_MASK                     0xFFFF0000u
#define TSI_CNTR1_CNTN1_SHIFT                    16
#define TSI_CNTR1_CNTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR1_CNTN1_SHIFT))&TSI_CNTR1_CNTN1_MASK)
/* CNTR3 Bit Fields */
#define TSI_CNTR3_CNTN_MASK                      0xFFFFu
#define TSI_CNTR3_CNTN_SHIFT                     0
#define TSI_CNTR3_CNTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR3_CNTN_SHIFT))&TSI_CNTR3_CNTN_MASK)
#define TSI_CNTR3_CNTN1_MASK                     0xFFFF0000u
#define TSI_CNTR3_CNTN1_SHIFT                    16
#define TSI_CNTR3_CNTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR3_CNTN1_SHIFT))&TSI_CNTR3_CNTN1_MASK)
/* CNTR5 Bit Fields */
#define TSI_CNTR5_CNTN_MASK                      0xFFFFu
#define TSI_CNTR5_CNTN_SHIFT                     0
#define TSI_CNTR5_CNTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR5_CNTN_SHIFT))&TSI_CNTR5_CNTN_MASK)
#define TSI_CNTR5_CNTN1_MASK                     0xFFFF0000u
#define TSI_CNTR5_CNTN1_SHIFT                    16
#define TSI_CNTR5_CNTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR5_CNTN1_SHIFT))&TSI_CNTR5_CNTN1_MASK)
/* CNTR7 Bit Fields */
#define TSI_CNTR7_CNTN_MASK                      0xFFFFu
#define TSI_CNTR7_CNTN_SHIFT                     0
#define TSI_CNTR7_CNTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR7_CNTN_SHIFT))&TSI_CNTR7_CNTN_MASK)
#define TSI_CNTR7_CNTN1_MASK                     0xFFFF0000u
#define TSI_CNTR7_CNTN1_SHIFT                    16
#define TSI_CNTR7_CNTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR7_CNTN1_SHIFT))&TSI_CNTR7_CNTN1_MASK)
/* CNTR9 Bit Fields */
#define TSI_CNTR9_CNTN_MASK                      0xFFFFu
#define TSI_CNTR9_CNTN_SHIFT                     0
#define TSI_CNTR9_CNTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR9_CNTN_SHIFT))&TSI_CNTR9_CNTN_MASK)
#define TSI_CNTR9_CNTN1_MASK                     0xFFFF0000u
#define TSI_CNTR9_CNTN1_SHIFT                    16
#define TSI_CNTR9_CNTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR9_CNTN1_SHIFT))&TSI_CNTR9_CNTN1_MASK)
/* CNTR11 Bit Fields */
#define TSI_CNTR11_CNTN_MASK                     0xFFFFu
#define TSI_CNTR11_CNTN_SHIFT                    0
#define TSI_CNTR11_CNTN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR11_CNTN_SHIFT))&TSI_CNTR11_CNTN_MASK)
#define TSI_CNTR11_CNTN1_MASK                    0xFFFF0000u
#define TSI_CNTR11_CNTN1_SHIFT                   16
#define TSI_CNTR11_CNTN1(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_CNTR11_CNTN1_SHIFT))&TSI_CNTR11_CNTN1_MASK)
/* CNTR13 Bit Fields */
#define TSI_CNTR13_CNTN_MASK                     0xFFFFu
#define TSI_CNTR13_CNTN_SHIFT                    0
#define TSI_CNTR13_CNTN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR13_CNTN_SHIFT))&TSI_CNTR13_CNTN_MASK)
#define TSI_CNTR13_CNTN1_MASK                    0xFFFF0000u
#define TSI_CNTR13_CNTN1_SHIFT                   16
#define TSI_CNTR13_CNTN1(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_CNTR13_CNTN1_SHIFT))&TSI_CNTR13_CNTN1_MASK)
/* CNTR15 Bit Fields */
#define TSI_CNTR15_CNTN_MASK                     0xFFFFu
#define TSI_CNTR15_CNTN_SHIFT                    0
#define TSI_CNTR15_CNTN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR15_CNTN_SHIFT))&TSI_CNTR15_CNTN_MASK)
#define TSI_CNTR15_CNTN1_MASK                    0xFFFF0000u
#define TSI_CNTR15_CNTN1_SHIFT                   16
#define TSI_CNTR15_CNTN1(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_CNTR15_CNTN1_SHIFT))&TSI_CNTR15_CNTN1_MASK)
/* THRESHLD Bit Fields */
#define TSI_THRESHLD_HTHH_MASK                   0xFFFFu
#define TSI_THRESHLD_HTHH_SHIFT                  0
#define TSI_THRESHLD_HTHH(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_THRESHLD_HTHH_SHIFT))&TSI_THRESHLD_HTHH_MASK)
#define TSI_THRESHLD_LTHH_MASK                   0xFFFF0000u
#define TSI_THRESHLD_LTHH_SHIFT                  16
#define TSI_THRESHLD_LTHH(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_THRESHLD_LTHH_SHIFT))&TSI_THRESHLD_LTHH_MASK)

/*! \} */ /* end of group TSI_Register_Masks */


/* TSI - Peripheral instance base addresses */
/*! Peripheral TSI0 base pointer */
#define TSI0_BASE_PTR                            ((TSI_MemMapPtr)0xFFFF9400u)

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros */
/*! \{ */


/* TSI - Register instance definitions */
/* TSI0 */
#define TSI0_GENCS                               TSI_GENCS_REG(TSI0_BASE_PTR)
#define TSI0_SCANC                               TSI_SCANC_REG(TSI0_BASE_PTR)
#define TSI0_PEN                                 TSI_PEN_REG(TSI0_BASE_PTR)
#define TSI0_STATUS                              TSI_STATUS_REG(TSI0_BASE_PTR)
#define TSI0_CNTR1                               TSI_CNTR1_REG(TSI0_BASE_PTR)
#define TSI0_CNTR3                               TSI_CNTR3_REG(TSI0_BASE_PTR)
#define TSI0_CNTR5                               TSI_CNTR5_REG(TSI0_BASE_PTR)
#define TSI0_CNTR7                               TSI_CNTR7_REG(TSI0_BASE_PTR)
#define TSI0_CNTR9                               TSI_CNTR9_REG(TSI0_BASE_PTR)
#define TSI0_CNTR11                              TSI_CNTR11_REG(TSI0_BASE_PTR)
#define TSI0_CNTR13                              TSI_CNTR13_REG(TSI0_BASE_PTR)
#define TSI0_CNTR15                              TSI_CNTR15_REG(TSI0_BASE_PTR)
#define TSI0_THRESHLD0                           TSI_THRESHLD_REG(TSI0_BASE_PTR,0)
#define TSI0_THRESHLD1                           TSI_THRESHLD_REG(TSI0_BASE_PTR,1)
#define TSI0_THRESHLD2                           TSI_THRESHLD_REG(TSI0_BASE_PTR,2)
#define TSI0_THRESHLD3                           TSI_THRESHLD_REG(TSI0_BASE_PTR,3)
#define TSI0_THRESHLD4                           TSI_THRESHLD_REG(TSI0_BASE_PTR,4)
#define TSI0_THRESHLD5                           TSI_THRESHLD_REG(TSI0_BASE_PTR,5)
#define TSI0_THRESHLD6                           TSI_THRESHLD_REG(TSI0_BASE_PTR,6)
#define TSI0_THRESHLD7                           TSI_THRESHLD_REG(TSI0_BASE_PTR,7)
#define TSI0_THRESHLD8                           TSI_THRESHLD_REG(TSI0_BASE_PTR,8)
#define TSI0_THRESHLD9                           TSI_THRESHLD_REG(TSI0_BASE_PTR,9)
#define TSI0_THRESHLD10                          TSI_THRESHLD_REG(TSI0_BASE_PTR,10)
#define TSI0_THRESHLD11                          TSI_THRESHLD_REG(TSI0_BASE_PTR,11)
#define TSI0_THRESHLD12                          TSI_THRESHLD_REG(TSI0_BASE_PTR,12)
#define TSI0_THRESHLD13                          TSI_THRESHLD_REG(TSI0_BASE_PTR,13)
#define TSI0_THRESHLD14                          TSI_THRESHLD_REG(TSI0_BASE_PTR,14)
#define TSI0_THRESHLD15                          TSI_THRESHLD_REG(TSI0_BASE_PTR,15)

/* TSI - Register array accessors */
#define TSI0_THRESHLD(index)                     TSI_THRESHLD_REG(TSI0_BASE_PTR,index)

/*! \} */ /* end of group TSI_Register_Accessor_Macros */


/*! \} */ /* end of group TSI_Peripheral */


/* ----------------------------------------------------------------------------
   -- UART
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Peripheral UART */
/*! \{ */

/*! UART - Peripheral register structure */
typedef struct UART_MemMap {
  uint8_t BDH;                                     /*!< UART Baud Rate Registers:High, offset: 0x0 */
  uint8_t BDL;                                     /*!< UART Baud Rate Registers: Low, offset: 0x1 */
  uint8_t C1;                                      /*!< UART Control Register 1, offset: 0x2 */
  uint8_t C2;                                      /*!< UART Control Register 2, offset: 0x3 */
  uint8_t S1;                                      /*!< UART Status Register 1, offset: 0x4 */
  uint8_t S2;                                      /*!< UART Status Register 2, offset: 0x5 */
  uint8_t C3;                                      /*!< UART Control Register 3, offset: 0x6 */
  uint8_t D;                                       /*!< UART Data Register, offset: 0x7 */
  uint8_t MA1;                                     /*!< UART Match Address Registers 1, offset: 0x8 */
  uint8_t MA2;                                     /*!< UART Match Address Registers 2, offset: 0x9 */
  uint8_t C4;                                      /*!< UART Control Register 4, offset: 0xA */
  uint8_t C5;                                      /*!< UART Control Register 5, offset: 0xB */
  uint8_t ED;                                      /*!< UART Extended Data Register, offset: 0xC */
  uint8_t MODEM;                                   /*!< UART Modem Register, offset: 0xD */
  uint8_t RESERVED_0[2];
  uint8_t PFIFO;                                   /*!< UART FIFO Parameters, offset: 0x10 */
  uint8_t CFIFO;                                   /*!< UART FIFO Control Register, offset: 0x11 */
  uint8_t SFIFO;                                   /*!< UART FIFO Status Register, offset: 0x12 */
  uint8_t TWFIFO;                                  /*!< UART FIFO Transmit Watermark, offset: 0x13 */
  uint8_t TCFIFO;                                  /*!< UART FIFO Transmit Count, offset: 0x14 */
  uint8_t RWFIFO;                                  /*!< UART FIFO Receive Watermark, offset: 0x15 */
  uint8_t RCFIFO;                                  /*!< UART FIFO Receive Count, offset: 0x16 */
  uint8_t RESERVED_1[1];
  uint8_t C7816;                                   /*!< UART 7816 Control Register, offset: 0x18 */
  uint8_t IE7816;                                  /*!< UART 7816 Interrupt Enable Register, offset: 0x19 */
  uint8_t IS7816;                                  /*!< UART 7816 Interrupt Status Register, offset: 0x1A */
  union {                                          /* offset: 0x1B */
    uint8_t WP7816_T_TYPE0;                          /*!< UART 7816 Wait Parameter Register, offset: 0x1B */
    uint8_t WP7816_T_TYPE1;                          /*!< UART 7816 Wait Parameter Register, offset: 0x1B */
  };
  uint8_t WN7816;                                  /*!< UART 7816 Wait N Register, offset: 0x1C */
  uint8_t WF7816;                                  /*!< UART 7816 Wait FD Register, offset: 0x1D */
  uint8_t ET7816;                                  /*!< UART 7816 Error Threshold Register, offset: 0x1E */
  uint8_t TL7816;                                  /*!< UART 7816 Transmit Length Register, offset: 0x1F */
} volatile *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Accessor_Macros UART - Register accessor macros */
/*! \{ */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)
#define UART_MA1_REG(base)                       ((base)->MA1)
#define UART_MA2_REG(base)                       ((base)->MA2)
#define UART_C4_REG(base)                        ((base)->C4)
#define UART_C5_REG(base)                        ((base)->C5)
#define UART_ED_REG(base)                        ((base)->ED)
#define UART_MODEM_REG(base)                     ((base)->MODEM)
#define UART_PFIFO_REG(base)                     ((base)->PFIFO)
#define UART_CFIFO_REG(base)                     ((base)->CFIFO)
#define UART_SFIFO_REG(base)                     ((base)->SFIFO)
#define UART_TWFIFO_REG(base)                    ((base)->TWFIFO)
#define UART_TCFIFO_REG(base)                    ((base)->TCFIFO)
#define UART_RWFIFO_REG(base)                    ((base)->RWFIFO)
#define UART_RCFIFO_REG(base)                    ((base)->RCFIFO)
#define UART_C7816_REG(base)                     ((base)->C7816)
#define UART_IE7816_REG(base)                    ((base)->IE7816)
#define UART_IS7816_REG(base)                    ((base)->IS7816)
#define UART_WP7816_T_TYPE0_REG(base)            ((base)->WP7816_T_TYPE0)
#define UART_WP7816_T_TYPE1_REG(base)            ((base)->WP7816_T_TYPE1)
#define UART_WN7816_REG(base)                    ((base)->WN7816)
#define UART_WF7816_REG(base)                    ((base)->WF7816)
#define UART_ET7816_REG(base)                    ((base)->ET7816)
#define UART_TL7816_REG(base)                    ((base)->TL7816)

/*! \} */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Masks UART Register Masks */
/*! \{ */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA1_MA_SHIFT))&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA2_MA_SHIFT))&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK)
/* C7816 Bit Fields */
#define UART_C7816_ISO_7816E_MASK                0x1u
#define UART_C7816_ISO_7816E_SHIFT               0
#define UART_C7816_TTYPE_MASK                    0x2u
#define UART_C7816_TTYPE_SHIFT                   1
#define UART_C7816_INIT_MASK                     0x4u
#define UART_C7816_INIT_SHIFT                    2
#define UART_C7816_ANACK_MASK                    0x8u
#define UART_C7816_ANACK_SHIFT                   3
#define UART_C7816_ONACK_MASK                    0x10u
#define UART_C7816_ONACK_SHIFT                   4
/* IE7816 Bit Fields */
#define UART_IE7816_RXTE_MASK                    0x1u
#define UART_IE7816_RXTE_SHIFT                   0
#define UART_IE7816_TXTE_MASK                    0x2u
#define UART_IE7816_TXTE_SHIFT                   1
#define UART_IE7816_GTVE_MASK                    0x4u
#define UART_IE7816_GTVE_SHIFT                   2
#define UART_IE7816_INITDE_MASK                  0x10u
#define UART_IE7816_INITDE_SHIFT                 4
#define UART_IE7816_BWTE_MASK                    0x20u
#define UART_IE7816_BWTE_SHIFT                   5
#define UART_IE7816_CWTE_MASK                    0x40u
#define UART_IE7816_CWTE_SHIFT                   6
#define UART_IE7816_WTE_MASK                     0x80u
#define UART_IE7816_WTE_SHIFT                    7
/* IS7816 Bit Fields */
#define UART_IS7816_RXT_MASK                     0x1u
#define UART_IS7816_RXT_SHIFT                    0
#define UART_IS7816_TXT_MASK                     0x2u
#define UART_IS7816_TXT_SHIFT                    1
#define UART_IS7816_GTV_MASK                     0x4u
#define UART_IS7816_GTV_SHIFT                    2
#define UART_IS7816_INITD_MASK                   0x10u
#define UART_IS7816_INITD_SHIFT                  4
#define UART_IS7816_BWT_MASK                     0x20u
#define UART_IS7816_BWT_SHIFT                    5
#define UART_IS7816_CWT_MASK                     0x40u
#define UART_IS7816_CWT_SHIFT                    6
#define UART_IS7816_WT_MASK                      0x80u
#define UART_IS7816_WT_SHIFT                     7
/* WP7816_T_TYPE0 Bit Fields */
#define UART_WP7816_T_TYPE0_WI_MASK              0xFFu
#define UART_WP7816_T_TYPE0_WI_SHIFT             0
#define UART_WP7816_T_TYPE0_WI(x)                (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE0_WI_SHIFT))&UART_WP7816_T_TYPE0_WI_MASK)
/* WP7816_T_TYPE1 Bit Fields */
#define UART_WP7816_T_TYPE1_BWI_MASK             0xFu
#define UART_WP7816_T_TYPE1_BWI_SHIFT            0
#define UART_WP7816_T_TYPE1_BWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_BWI_SHIFT))&UART_WP7816_T_TYPE1_BWI_MASK)
#define UART_WP7816_T_TYPE1_CWI_MASK             0xF0u
#define UART_WP7816_T_TYPE1_CWI_SHIFT            4
#define UART_WP7816_T_TYPE1_CWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_CWI_SHIFT))&UART_WP7816_T_TYPE1_CWI_MASK)
/* WN7816 Bit Fields */
#define UART_WN7816_GTN_MASK                     0xFFu
#define UART_WN7816_GTN_SHIFT                    0
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK)
/* WF7816 Bit Fields */
#define UART_WF7816_GTFD_MASK                    0xFFu
#define UART_WF7816_GTFD_SHIFT                   0
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK)
/* ET7816 Bit Fields */
#define UART_ET7816_RXTHRESHOLD_MASK             0xFu
#define UART_ET7816_RXTHRESHOLD_SHIFT            0
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             0xF0u
#define UART_ET7816_TXTHRESHOLD_SHIFT            4
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK)
/* TL7816 Bit Fields */
#define UART_TL7816_TLEN_MASK                    0xFFu
#define UART_TL7816_TLEN_SHIFT                   0
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK)

/*! \} */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/*! Peripheral UART0 base pointer */
#define UART0_BASE_PTR                           ((UART_MemMapPtr)0xFFFF8140u)
/*! Peripheral UART1 base pointer */
#define UART1_BASE_PTR                           ((UART_MemMapPtr)0xFFFF8160u)

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Accessor_Macros UART - Register accessor macros */
/*! \{ */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0_BASE_PTR)
#define UART0_BDL                                UART_BDL_REG(UART0_BASE_PTR)
#define UART0_C1                                 UART_C1_REG(UART0_BASE_PTR)
#define UART0_C2                                 UART_C2_REG(UART0_BASE_PTR)
#define UART0_S1                                 UART_S1_REG(UART0_BASE_PTR)
#define UART0_S2                                 UART_S2_REG(UART0_BASE_PTR)
#define UART0_C3                                 UART_C3_REG(UART0_BASE_PTR)
#define UART0_D                                  UART_D_REG(UART0_BASE_PTR)
#define UART0_MA1                                UART_MA1_REG(UART0_BASE_PTR)
#define UART0_MA2                                UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4                                 UART_C4_REG(UART0_BASE_PTR)
#define UART0_C5                                 UART_C5_REG(UART0_BASE_PTR)
#define UART0_ED                                 UART_ED_REG(UART0_BASE_PTR)
#define UART0_MODEM                              UART_MODEM_REG(UART0_BASE_PTR)
#define UART0_PFIFO                              UART_PFIFO_REG(UART0_BASE_PTR)
#define UART0_CFIFO                              UART_CFIFO_REG(UART0_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_REG(UART0_BASE_PTR)
#define UART0_TWFIFO                             UART_TWFIFO_REG(UART0_BASE_PTR)
#define UART0_TCFIFO                             UART_TCFIFO_REG(UART0_BASE_PTR)
#define UART0_RWFIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO                             UART_RCFIFO_REG(UART0_BASE_PTR)
#define UART0_C7816                              UART_C7816_REG(UART0_BASE_PTR)
#define UART0_IE7816                             UART_IE7816_REG(UART0_BASE_PTR)
#define UART0_IS7816                             UART_IS7816_REG(UART0_BASE_PTR)
#define UART0_WP7816T0                           UART_WP7816_T_TYPE0_REG(UART0_BASE_PTR)
#define UART0_WP7816T1                           UART_WP7816_T_TYPE1_REG(UART0_BASE_PTR)
#define UART0_WN7816                             UART_WN7816_REG(UART0_BASE_PTR)
#define UART0_WF7816                             UART_WF7816_REG(UART0_BASE_PTR)
#define UART0_ET7816                             UART_ET7816_REG(UART0_BASE_PTR)
#define UART0_TL7816                             UART_TL7816_REG(UART0_BASE_PTR)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1_BASE_PTR)
#define UART1_BDL                                UART_BDL_REG(UART1_BASE_PTR)
#define UART1_C1                                 UART_C1_REG(UART1_BASE_PTR)
#define UART1_C2                                 UART_C2_REG(UART1_BASE_PTR)
#define UART1_S1                                 UART_S1_REG(UART1_BASE_PTR)
#define UART1_S2                                 UART_S2_REG(UART1_BASE_PTR)
#define UART1_C3                                 UART_C3_REG(UART1_BASE_PTR)
#define UART1_D                                  UART_D_REG(UART1_BASE_PTR)
#define UART1_MA1                                UART_MA1_REG(UART1_BASE_PTR)
#define UART1_MA2                                UART_MA2_REG(UART1_BASE_PTR)
#define UART1_C4                                 UART_C4_REG(UART1_BASE_PTR)
#define UART1_C5                                 UART_C5_REG(UART1_BASE_PTR)
#define UART1_ED                                 UART_ED_REG(UART1_BASE_PTR)
#define UART1_MODEM                              UART_MODEM_REG(UART1_BASE_PTR)
#define UART1_PFIFO                              UART_PFIFO_REG(UART1_BASE_PTR)
#define UART1_CFIFO                              UART_CFIFO_REG(UART1_BASE_PTR)
#define UART1_SFIFO                              UART_SFIFO_REG(UART1_BASE_PTR)
#define UART1_TWFIFO                             UART_TWFIFO_REG(UART1_BASE_PTR)
#define UART1_TCFIFO                             UART_TCFIFO_REG(UART1_BASE_PTR)
#define UART1_RWFIFO                             UART_RWFIFO_REG(UART1_BASE_PTR)
#define UART1_RCFIFO                             UART_RCFIFO_REG(UART1_BASE_PTR)
#define UART1_C7816                              UART_C7816_REG(UART1_BASE_PTR)
#define UART1_IE7816                             UART_IE7816_REG(UART1_BASE_PTR)
#define UART1_IS7816                             UART_IS7816_REG(UART1_BASE_PTR)
#define UART1_WP7816T0                           UART_WP7816_T_TYPE0_REG(UART1_BASE_PTR)
#define UART1_WP7816T1                           UART_WP7816_T_TYPE1_REG(UART1_BASE_PTR)
#define UART1_WN7816                             UART_WN7816_REG(UART1_BASE_PTR)
#define UART1_WF7816                             UART_WF7816_REG(UART1_BASE_PTR)
#define UART1_ET7816                             UART_ET7816_REG(UART1_BASE_PTR)
#define UART1_TL7816                             UART_TL7816_REG(UART1_BASE_PTR)

/*! \} */ /* end of group UART_Register_Accessor_Macros */


/*! \} */ /* end of group UART_Peripheral */


/* ----------------------------------------------------------------------------
   -- USB
   ---------------------------------------------------------------------------- */

/*! \addtogroup USB_Peripheral USB */
/*! \{ */

/*! USB - Peripheral register structure */
typedef struct USB_MemMap {
  uint8_t PERID;                                   /*!< Peripheral ID Register, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                  /*!< Peripheral ID Complement Register, offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t REV;                                     /*!< Peripheral Revision Register, offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                 /*!< Peripheral Additional Info Register, offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                /*!< OTG Interrupt Status Register, offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                  /*!< OTG Interrupt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                 /*!< OTG Status Register, offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                  /*!< OTG Control Register, offset: 0x1C */
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                   /*!< Interrupt Status Register, offset: 0x80 */
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                   /*!< Interrupt Enable Register, offset: 0x84 */
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                 /*!< Error Interrupt Status Register, offset: 0x88 */
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                   /*!< Error Interrupt Enable Register, offset: 0x8C */
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                    /*!< Status Register, offset: 0x90 */
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                     /*!< Control Register, offset: 0x94 */
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                    /*!< Address Register, offset: 0x98 */
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                /*!< BDT Page Register 1, offset: 0x9C */
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                 /*!< Frame Number Register Low, offset: 0xA0 */
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                 /*!< Frame Number Register High, offset: 0xA4 */
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                   /*!< Token Register, offset: 0xA8 */
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                 /*!< SOF Threshold Register, offset: 0xAC */
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                /*!< BDT Page Register 2, offset: 0xB0 */
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                /*!< BDT Page Register 3, offset: 0xB4 */
  uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    uint8_t ENDPT;                                   /*!< Endpoint Control Register, array offset: 0xC0, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                 /*!< USB Control Register, offset: 0x100 */
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                 /*!< USB OTG Observe Register, offset: 0x104 */
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                 /*!< USB OTG Control Register, offset: 0x108 */
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                 /*!< USB Transceiver Control Register 0, offset: 0x10C */
  uint8_t RESERVED_25[7];
  uint8_t USBFRMADJUST;                            /*!< Frame Adjust Register, offset: 0x114 */
} volatile *USB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USB_Register_Accessor_Macros USB - Register accessor macros */
/*! \{ */


/* USB - Register accessors */
#define USB_PERID_REG(base)                      ((base)->PERID)
#define USB_IDCOMP_REG(base)                     ((base)->IDCOMP)
#define USB_REV_REG(base)                        ((base)->REV)
#define USB_ADDINFO_REG(base)                    ((base)->ADDINFO)
#define USB_OTGISTAT_REG(base)                   ((base)->OTGISTAT)
#define USB_OTGICR_REG(base)                     ((base)->OTGICR)
#define USB_OTGSTAT_REG(base)                    ((base)->OTGSTAT)
#define USB_OTGCTL_REG(base)                     ((base)->OTGCTL)
#define USB_ISTAT_REG(base)                      ((base)->ISTAT)
#define USB_INTEN_REG(base)                      ((base)->INTEN)
#define USB_ERRSTAT_REG(base)                    ((base)->ERRSTAT)
#define USB_ERREN_REG(base)                      ((base)->ERREN)
#define USB_STAT_REG(base)                       ((base)->STAT)
#define USB_CTL_REG(base)                        ((base)->CTL)
#define USB_ADDR_REG(base)                       ((base)->ADDR)
#define USB_BDTPAGE1_REG(base)                   ((base)->BDTPAGE1)
#define USB_FRMNUML_REG(base)                    ((base)->FRMNUML)
#define USB_FRMNUMH_REG(base)                    ((base)->FRMNUMH)
#define USB_TOKEN_REG(base)                      ((base)->TOKEN)
#define USB_SOFTHLD_REG(base)                    ((base)->SOFTHLD)
#define USB_BDTPAGE2_REG(base)                   ((base)->BDTPAGE2)
#define USB_BDTPAGE3_REG(base)                   ((base)->BDTPAGE3)
#define USB_ENDPT_REG(base,index)                ((base)->ENDPOINT[index].ENDPT)
#define USB_USBCTRL_REG(base)                    ((base)->USBCTRL)
#define USB_OBSERVE_REG(base)                    ((base)->OBSERVE)
#define USB_CONTROL_REG(base)                    ((base)->CONTROL)
#define USB_USBTRC0_REG(base)                    ((base)->USBTRC0)
#define USB_USBFRMADJUST_REG(base)               ((base)->USBFRMADJUST)

/*! \} */ /* end of group USB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup USB_Register_Masks USB Register Masks */
/*! \{ */

/* PERID Bit Fields */
#define USB_PERID_ID_MASK                        0x3Fu
#define USB_PERID_ID_SHIFT                       0
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USB_IDCOMP_NID_MASK                      0x3Fu
#define USB_IDCOMP_NID_SHIFT                     0
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USB_REV_REV_MASK                         0xFFu
#define USB_REV_REV_SHIFT                        0
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USB_ADDINFO_IEHOST_MASK                  0x1u
#define USB_ADDINFO_IEHOST_SHIFT                 0
#define USB_ADDINFO_IRQNUM_MASK                  0xF8u
#define USB_ADDINFO_IRQNUM_SHIFT                 3
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IRQNUM_SHIFT))&USB_ADDINFO_IRQNUM_MASK)
/* OTGISTAT Bit Fields */
#define USB_OTGISTAT_AVBUSCHG_MASK               0x1u
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0
#define USB_OTGISTAT_B_SESS_CHG_MASK             0x4u
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2
#define USB_OTGISTAT_SESSVLDCHG_MASK             0x8u
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         0x20u
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5
#define USB_OTGISTAT_ONEMSEC_MASK                0x40u
#define USB_OTGISTAT_ONEMSEC_SHIFT               6
#define USB_OTGISTAT_IDCHG_MASK                  0x80u
#define USB_OTGISTAT_IDCHG_SHIFT                 7
/* OTGICR Bit Fields */
#define USB_OTGICR_AVBUSEN_MASK                  0x1u
#define USB_OTGICR_AVBUSEN_SHIFT                 0
#define USB_OTGICR_BSESSEN_MASK                  0x4u
#define USB_OTGICR_BSESSEN_SHIFT                 2
#define USB_OTGICR_SESSVLDEN_MASK                0x8u
#define USB_OTGICR_SESSVLDEN_SHIFT               3
#define USB_OTGICR_LINESTATEEN_MASK              0x20u
#define USB_OTGICR_LINESTATEEN_SHIFT             5
#define USB_OTGICR_ONEMSECEN_MASK                0x40u
#define USB_OTGICR_ONEMSECEN_SHIFT               6
#define USB_OTGICR_IDEN_MASK                     0x80u
#define USB_OTGICR_IDEN_SHIFT                    7
/* OTGSTAT Bit Fields */
#define USB_OTGSTAT_AVBUSVLD_MASK                0x1u
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0
#define USB_OTGSTAT_BSESSEND_MASK                0x4u
#define USB_OTGSTAT_BSESSEND_SHIFT               2
#define USB_OTGSTAT_SESS_VLD_MASK                0x8u
#define USB_OTGSTAT_SESS_VLD_SHIFT               3
#define USB_OTGSTAT_LINESTATESTABLE_MASK         0x20u
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5
#define USB_OTGSTAT_ONEMSECEN_MASK               0x40u
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6
#define USB_OTGSTAT_ID_MASK                      0x80u
#define USB_OTGSTAT_ID_SHIFT                     7
/* OTGCTL Bit Fields */
#define USB_OTGCTL_OTGEN_MASK                    0x4u
#define USB_OTGCTL_OTGEN_SHIFT                   2
#define USB_OTGCTL_DMLOW_MASK                    0x10u
#define USB_OTGCTL_DMLOW_SHIFT                   4
#define USB_OTGCTL_DPLOW_MASK                    0x20u
#define USB_OTGCTL_DPLOW_SHIFT                   5
#define USB_OTGCTL_DPHIGH_MASK                   0x80u
#define USB_OTGCTL_DPHIGH_SHIFT                  7
/* ISTAT Bit Fields */
#define USB_ISTAT_USBRST_MASK                    0x1u
#define USB_ISTAT_USBRST_SHIFT                   0
#define USB_ISTAT_ERROR_MASK                     0x2u
#define USB_ISTAT_ERROR_SHIFT                    1
#define USB_ISTAT_SOFTOK_MASK                    0x4u
#define USB_ISTAT_SOFTOK_SHIFT                   2
#define USB_ISTAT_TOKDNE_MASK                    0x8u
#define USB_ISTAT_TOKDNE_SHIFT                   3
#define USB_ISTAT_SLEEP_MASK                     0x10u
#define USB_ISTAT_SLEEP_SHIFT                    4
#define USB_ISTAT_RESUME_MASK                    0x20u
#define USB_ISTAT_RESUME_SHIFT                   5
#define USB_ISTAT_ATTACH_MASK                    0x40u
#define USB_ISTAT_ATTACH_SHIFT                   6
#define USB_ISTAT_STALL_MASK                     0x80u
#define USB_ISTAT_STALL_SHIFT                    7
/* INTEN Bit Fields */
#define USB_INTEN_USBRSTEN_MASK                  0x1u
#define USB_INTEN_USBRSTEN_SHIFT                 0
#define USB_INTEN_ERROREN_MASK                   0x2u
#define USB_INTEN_ERROREN_SHIFT                  1
#define USB_INTEN_SOFTOKEN_MASK                  0x4u
#define USB_INTEN_SOFTOKEN_SHIFT                 2
#define USB_INTEN_TOKDNEEN_MASK                  0x8u
#define USB_INTEN_TOKDNEEN_SHIFT                 3
#define USB_INTEN_SLEEPEN_MASK                   0x10u
#define USB_INTEN_SLEEPEN_SHIFT                  4
#define USB_INTEN_RESUMEEN_MASK                  0x20u
#define USB_INTEN_RESUMEEN_SHIFT                 5
#define USB_INTEN_ATTACHEN_MASK                  0x40u
#define USB_INTEN_ATTACHEN_SHIFT                 6
#define USB_INTEN_STALLEN_MASK                   0x80u
#define USB_INTEN_STALLEN_SHIFT                  7
/* ERRSTAT Bit Fields */
#define USB_ERRSTAT_PIDERR_MASK                  0x1u
#define USB_ERRSTAT_PIDERR_SHIFT                 0
#define USB_ERRSTAT_CRC5EOF_MASK                 0x2u
#define USB_ERRSTAT_CRC5EOF_SHIFT                1
#define USB_ERRSTAT_CRC16_MASK                   0x4u
#define USB_ERRSTAT_CRC16_SHIFT                  2
#define USB_ERRSTAT_DFN8_MASK                    0x8u
#define USB_ERRSTAT_DFN8_SHIFT                   3
#define USB_ERRSTAT_BTOERR_MASK                  0x10u
#define USB_ERRSTAT_BTOERR_SHIFT                 4
#define USB_ERRSTAT_DMAERR_MASK                  0x20u
#define USB_ERRSTAT_DMAERR_SHIFT                 5
#define USB_ERRSTAT_BTSERR_MASK                  0x80u
#define USB_ERRSTAT_BTSERR_SHIFT                 7
/* ERREN Bit Fields */
#define USB_ERREN_PIDERREN_MASK                  0x1u
#define USB_ERREN_PIDERREN_SHIFT                 0
#define USB_ERREN_CRC5EOFEN_MASK                 0x2u
#define USB_ERREN_CRC5EOFEN_SHIFT                1
#define USB_ERREN_CRC16EN_MASK                   0x4u
#define USB_ERREN_CRC16EN_SHIFT                  2
#define USB_ERREN_DFN8EN_MASK                    0x8u
#define USB_ERREN_DFN8EN_SHIFT                   3
#define USB_ERREN_BTOERREN_MASK                  0x10u
#define USB_ERREN_BTOERREN_SHIFT                 4
#define USB_ERREN_DMAERREN_MASK                  0x20u
#define USB_ERREN_DMAERREN_SHIFT                 5
#define USB_ERREN_BTSERREN_MASK                  0x80u
#define USB_ERREN_BTSERREN_SHIFT                 7
/* STAT Bit Fields */
#define USB_STAT_ODD_MASK                        0x4u
#define USB_STAT_ODD_SHIFT                       2
#define USB_STAT_TX_MASK                         0x8u
#define USB_STAT_TX_SHIFT                        3
#define USB_STAT_ENDP_MASK                       0xF0u
#define USB_STAT_ENDP_SHIFT                      4
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USB_CTL_USBENSOFEN_MASK                  0x1u
#define USB_CTL_USBENSOFEN_SHIFT                 0
#define USB_CTL_ODDRST_MASK                      0x2u
#define USB_CTL_ODDRST_SHIFT                     1
#define USB_CTL_RESUME_MASK                      0x4u
#define USB_CTL_RESUME_SHIFT                     2
#define USB_CTL_HOSTMODEEN_MASK                  0x8u
#define USB_CTL_HOSTMODEEN_SHIFT                 3
#define USB_CTL_RESET_MASK                       0x10u
#define USB_CTL_RESET_SHIFT                      4
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          0x20u
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5
#define USB_CTL_SE0_MASK                         0x40u
#define USB_CTL_SE0_SHIFT                        6
#define USB_CTL_JSTATE_MASK                      0x80u
#define USB_CTL_JSTATE_SHIFT                     7
/* ADDR Bit Fields */
#define USB_ADDR_ADDR_MASK                       0x7Fu
#define USB_ADDR_ADDR_SHIFT                      0
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       0x80u
#define USB_ADDR_LSEN_SHIFT                      7
/* BDTPAGE1 Bit Fields */
#define USB_BDTPAGE1_BDTBA_MASK                  0xFEu
#define USB_BDTPAGE1_BDTBA_SHIFT                 1
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USB_FRMNUML_FRM_MASK                     0xFFu
#define USB_FRMNUML_FRM_SHIFT                    0
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USB_FRMNUMH_FRM_MASK                     0x7u
#define USB_FRMNUMH_FRM_SHIFT                    0
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USB_TOKEN_TOKENENDPT_MASK                0xFu
#define USB_TOKEN_TOKENENDPT_SHIFT               0
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  0xF0u
#define USB_TOKEN_TOKENPID_SHIFT                 4
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK)
/* SOFTHLD Bit Fields */
#define USB_SOFTHLD_CNT_MASK                     0xFFu
#define USB_SOFTHLD_CNT_SHIFT                    0
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USB_BDTPAGE2_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE2_BDTBA_SHIFT                 0
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USB_BDTPAGE3_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE3_BDTBA_SHIFT                 0
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USB_ENDPT_EPHSHK_MASK                    0x1u
#define USB_ENDPT_EPHSHK_SHIFT                   0
#define USB_ENDPT_EPSTALL_MASK                   0x2u
#define USB_ENDPT_EPSTALL_SHIFT                  1
#define USB_ENDPT_EPTXEN_MASK                    0x4u
#define USB_ENDPT_EPTXEN_SHIFT                   2
#define USB_ENDPT_EPRXEN_MASK                    0x8u
#define USB_ENDPT_EPRXEN_SHIFT                   3
#define USB_ENDPT_EPCTLDIS_MASK                  0x10u
#define USB_ENDPT_EPCTLDIS_SHIFT                 4
#define USB_ENDPT_RETRYDIS_MASK                  0x40u
#define USB_ENDPT_RETRYDIS_SHIFT                 6
#define USB_ENDPT_HOSTWOHUB_MASK                 0x80u
#define USB_ENDPT_HOSTWOHUB_SHIFT                7
/* USBCTRL Bit Fields */
#define USB_USBCTRL_PDE_MASK                     0x40u
#define USB_USBCTRL_PDE_SHIFT                    6
#define USB_USBCTRL_SUSP_MASK                    0x80u
#define USB_USBCTRL_SUSP_SHIFT                   7
/* OBSERVE Bit Fields */
#define USB_OBSERVE_DMPD_MASK                    0x10u
#define USB_OBSERVE_DMPD_SHIFT                   4
#define USB_OBSERVE_DPPD_MASK                    0x40u
#define USB_OBSERVE_DPPD_SHIFT                   6
#define USB_OBSERVE_DPPU_MASK                    0x80u
#define USB_OBSERVE_DPPU_SHIFT                   7
/* CONTROL Bit Fields */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          0x10u
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4
/* USBTRC0 Bit Fields */
#define USB_USBTRC0_USB_RESUME_INT_MASK          0x1u
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_SYNC_DET_MASK                0x2u
#define USB_USBTRC0_SYNC_DET_SHIFT               1
#define USB_USBTRC0_USBRESMEN_MASK               0x20u
#define USB_USBTRC0_USBRESMEN_SHIFT              5
#define USB_USBTRC0_USBRESET_MASK                0x80u
#define USB_USBTRC0_USBRESET_SHIFT               7
/* USBFRMADJUST Bit Fields */
#define USB_USBFRMADJUST_ADJ_MASK                0xFFu
#define USB_USBFRMADJUST_ADJ_SHIFT               0
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK)

/*! \} */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/*! Peripheral USB0 base pointer */
#define USB0_BASE_PTR                            ((USB_MemMapPtr)0xFFFF9000u)

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USB_Register_Accessor_Macros USB - Register accessor macros */
/*! \{ */


/* USB - Register instance definitions */
/* USB0 */
#define USB0_PERID                               USB_PERID_REG(USB0_BASE_PTR)
#define USB0_IDCOMP                              USB_IDCOMP_REG(USB0_BASE_PTR)
#define USB0_REV                                 USB_REV_REG(USB0_BASE_PTR)
#define USB0_ADDINFO                             USB_ADDINFO_REG(USB0_BASE_PTR)
#define USB0_OTGISTAT                            USB_OTGISTAT_REG(USB0_BASE_PTR)
#define USB0_OTGICR                              USB_OTGICR_REG(USB0_BASE_PTR)
#define USB0_OTGSTAT                             USB_OTGSTAT_REG(USB0_BASE_PTR)
#define USB0_OTGCTL                              USB_OTGCTL_REG(USB0_BASE_PTR)
#define USB0_ISTAT                               USB_ISTAT_REG(USB0_BASE_PTR)
#define USB0_INTEN                               USB_INTEN_REG(USB0_BASE_PTR)
#define USB0_ERRSTAT                             USB_ERRSTAT_REG(USB0_BASE_PTR)
#define USB0_ERREN                               USB_ERREN_REG(USB0_BASE_PTR)
#define USB0_STAT                                USB_STAT_REG(USB0_BASE_PTR)
#define USB0_CTL                                 USB_CTL_REG(USB0_BASE_PTR)
#define USB0_ADDR                                USB_ADDR_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE1                            USB_BDTPAGE1_REG(USB0_BASE_PTR)
#define USB0_FRMNUML                             USB_FRMNUML_REG(USB0_BASE_PTR)
#define USB0_FRMNUMH                             USB_FRMNUMH_REG(USB0_BASE_PTR)
#define USB0_TOKEN                               USB_TOKEN_REG(USB0_BASE_PTR)
#define USB0_SOFTHLD                             USB_SOFTHLD_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE2                            USB_BDTPAGE2_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE3                            USB_BDTPAGE3_REG(USB0_BASE_PTR)
#define USB0_ENDPT0                              USB_ENDPT_REG(USB0_BASE_PTR,0)
#define USB0_ENDPT1                              USB_ENDPT_REG(USB0_BASE_PTR,1)
#define USB0_ENDPT2                              USB_ENDPT_REG(USB0_BASE_PTR,2)
#define USB0_ENDPT3                              USB_ENDPT_REG(USB0_BASE_PTR,3)
#define USB0_ENDPT4                              USB_ENDPT_REG(USB0_BASE_PTR,4)
#define USB0_ENDPT5                              USB_ENDPT_REG(USB0_BASE_PTR,5)
#define USB0_ENDPT6                              USB_ENDPT_REG(USB0_BASE_PTR,6)
#define USB0_ENDPT7                              USB_ENDPT_REG(USB0_BASE_PTR,7)
#define USB0_ENDPT8                              USB_ENDPT_REG(USB0_BASE_PTR,8)
#define USB0_ENDPT9                              USB_ENDPT_REG(USB0_BASE_PTR,9)
#define USB0_ENDPT10                             USB_ENDPT_REG(USB0_BASE_PTR,10)
#define USB0_ENDPT11                             USB_ENDPT_REG(USB0_BASE_PTR,11)
#define USB0_ENDPT12                             USB_ENDPT_REG(USB0_BASE_PTR,12)
#define USB0_ENDPT13                             USB_ENDPT_REG(USB0_BASE_PTR,13)
#define USB0_ENDPT14                             USB_ENDPT_REG(USB0_BASE_PTR,14)
#define USB0_ENDPT15                             USB_ENDPT_REG(USB0_BASE_PTR,15)
#define USB0_USBCTRL                             USB_USBCTRL_REG(USB0_BASE_PTR)
#define USB0_OBSERVE                             USB_OBSERVE_REG(USB0_BASE_PTR)
#define USB0_CONTROL                             USB_CONTROL_REG(USB0_BASE_PTR)
#define USB0_USBTRC0                             USB_USBTRC0_REG(USB0_BASE_PTR)
#define USB0_USBFRMADJUST                        USB_USBFRMADJUST_REG(USB0_BASE_PTR)

/* USB - Register array accessors */
#define USB0_ENDPT(index)                        USB_ENDPT_REG(USB0_BASE_PTR,index)

/*! \} */ /* end of group USB_Register_Accessor_Macros */


/*! \} */ /* end of group USB_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBDCD
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Peripheral USBDCD */
/*! \{ */

/*! USBDCD - Peripheral register structure */
typedef struct USBDCD_MemMap {
  uint32_t CONTROL;                                /*!< Control Register, offset: 0x0 */
  uint32_t CLOCK;                                  /*!< Clock Register, offset: 0x4 */
  uint32_t STATUS;                                 /*!< Status Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t TIMER0;                                 /*!< TIMER0 Register, offset: 0x10 */
  uint32_t TIMER1;                                 /*!< , offset: 0x14 */
  uint32_t TIMER2;                                 /*!< , offset: 0x18 */
} volatile *USBDCD_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros */
/*! \{ */


/* USBDCD - Register accessors */
#define USBDCD_CONTROL_REG(base)                 ((base)->CONTROL)
#define USBDCD_CLOCK_REG(base)                   ((base)->CLOCK)
#define USBDCD_STATUS_REG(base)                  ((base)->STATUS)
#define USBDCD_TIMER0_REG(base)                  ((base)->TIMER0)
#define USBDCD_TIMER1_REG(base)                  ((base)->TIMER1)
#define USBDCD_TIMER2_REG(base)                  ((base)->TIMER2)

/*! \} */ /* end of group USBDCD_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Masks USBDCD Register Masks */
/*! \{ */

/* CONTROL Bit Fields */
#define USBDCD_CONTROL_IACK_MASK                 0x1u
#define USBDCD_CONTROL_IACK_SHIFT                0
#define USBDCD_CONTROL_IF_MASK                   0x100u
#define USBDCD_CONTROL_IF_SHIFT                  8
#define USBDCD_CONTROL_IE_MASK                   0x10000u
#define USBDCD_CONTROL_IE_SHIFT                  16
#define USBDCD_CONTROL_START_MASK                0x1000000u
#define USBDCD_CONTROL_START_SHIFT               24
#define USBDCD_CONTROL_SR_MASK                   0x2000000u
#define USBDCD_CONTROL_SR_SHIFT                  25
/* CLOCK Bit Fields */
#define USBDCD_CLOCK_CLOCK_UNIT_MASK             0x1u
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            0
#define USBDCD_CLOCK_CLOCK_SPEED_MASK            0xFFCu
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           2
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_CLOCK_CLOCK_SPEED_SHIFT))&USBDCD_CLOCK_CLOCK_SPEED_MASK)
/* STATUS Bit Fields */
#define USBDCD_STATUS_SEQ_RES_MASK               0x30000u
#define USBDCD_STATUS_SEQ_RES_SHIFT              16
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_RES_SHIFT))&USBDCD_STATUS_SEQ_RES_MASK)
#define USBDCD_STATUS_SEQ_STAT_MASK              0xC0000u
#define USBDCD_STATUS_SEQ_STAT_SHIFT             18
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_STAT_SHIFT))&USBDCD_STATUS_SEQ_STAT_MASK)
#define USBDCD_STATUS_ERR_MASK                   0x100000u
#define USBDCD_STATUS_ERR_SHIFT                  20
#define USBDCD_STATUS_TO_MASK                    0x200000u
#define USBDCD_STATUS_TO_SHIFT                   21
#define USBDCD_STATUS_ACTIVE_MASK                0x400000u
#define USBDCD_STATUS_ACTIVE_SHIFT               22
/* TIMER0 Bit Fields */
#define USBDCD_TIMER0_TUNITCON_MASK              0xFFFu
#define USBDCD_TIMER0_TUNITCON_SHIFT             0
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TUNITCON_SHIFT))&USBDCD_TIMER0_TUNITCON_MASK)
#define USBDCD_TIMER0_TSEQ_INIT_MASK             0x3FF0000u
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            16
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TSEQ_INIT_SHIFT))&USBDCD_TIMER0_TSEQ_INIT_MASK)
/* TIMER1 Bit Fields */
#define USBDCD_TIMER1_TVDPSRC_ON_MASK            0x3FFu
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           0
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TVDPSRC_ON_SHIFT))&USBDCD_TIMER1_TVDPSRC_ON_MASK)
#define USBDCD_TIMER1_TDCD_DBNC_MASK             0x3FF0000u
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            16
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TDCD_DBNC_SHIFT))&USBDCD_TIMER1_TDCD_DBNC_MASK)
/* TIMER2 Bit Fields */
#define USBDCD_TIMER2_CHECK_DM_MASK              0xFu
#define USBDCD_TIMER2_CHECK_DM_SHIFT             0
#define USBDCD_TIMER2_CHECK_DM(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_CHECK_DM_SHIFT))&USBDCD_TIMER2_CHECK_DM_MASK)
#define USBDCD_TIMER2_TVDPSRC_CON_MASK           0x3FF0000u
#define USBDCD_TIMER2_TVDPSRC_CON_SHIFT          16
#define USBDCD_TIMER2_TVDPSRC_CON(x)             (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_TVDPSRC_CON_SHIFT))&USBDCD_TIMER2_TVDPSRC_CON_MASK)

/*! \} */ /* end of group USBDCD_Register_Masks */


/* USBDCD - Peripheral instance base addresses */
/*! Peripheral USBDCD base pointer */
#define USBDCD_BASE_PTR                          ((USBDCD_MemMapPtr)0xFFFF8680u)

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros */
/*! \{ */


/* USBDCD - Register instance definitions */
/* USBDCD */
#define USBDCD_CONTROL                           USBDCD_CONTROL_REG(USBDCD_BASE_PTR)
#define USBDCD_CLOCK                             USBDCD_CLOCK_REG(USBDCD_BASE_PTR)
#define USBDCD_STATUS                            USBDCD_STATUS_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER0                            USBDCD_TIMER0_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER1                            USBDCD_TIMER1_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER2                            USBDCD_TIMER2_REG(USBDCD_BASE_PTR)

/*! \} */ /* end of group USBDCD_Register_Accessor_Macros */


/*! \} */ /* end of group USBDCD_Peripheral */


/* ----------------------------------------------------------------------------
   -- VREF
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Peripheral VREF */
/*! \{ */

/*! VREF - Peripheral register structure */
typedef struct VREF_MemMap {
  uint8_t TRM;                                     /*!< VREF Trim Register, offset: 0x0 */
  uint8_t SC;                                      /*!< VREF Status and Control Register, offset: 0x1 */
} volatile *VREF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros */
/*! \{ */


/* VREF - Register accessors */
#define VREF_TRM_REG(base)                       ((base)->TRM)
#define VREF_SC_REG(base)                        ((base)->SC)

/*! \} */ /* end of group VREF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Masks VREF Register Masks */
/*! \{ */

/* TRM Bit Fields */
#define VREF_TRM_TRIM_MASK                       0x3Fu
#define VREF_TRM_TRIM_SHIFT                      0
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK)
/* SC Bit Fields */
#define VREF_SC_MODE_LV_MASK                     0x3u
#define VREF_SC_MODE_LV_SHIFT                    0
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK)
#define VREF_SC_VREFST_MASK                      0x4u
#define VREF_SC_VREFST_SHIFT                     2
#define VREF_SC_REGEN_MASK                       0x40u
#define VREF_SC_REGEN_SHIFT                      6
#define VREF_SC_VREFEN_MASK                      0x80u
#define VREF_SC_VREFEN_SHIFT                     7

/*! \} */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/*! Peripheral VREF base pointer */
#define VREF_BASE_PTR                            ((VREF_MemMapPtr)0xFFFF8670u)

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros */
/*! \{ */


/* VREF - Register instance definitions */
/* VREF */
#define VREF_TRM                                 VREF_TRM_REG(VREF_BASE_PTR)
#define VREF_SC                                  VREF_SC_REG(VREF_BASE_PTR)

/*! \} */ /* end of group VREF_Register_Accessor_Macros */


/*! \} */ /* end of group VREF_Peripheral */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
   #pragma pack(pop)
#else
  #error Not supported compiler type
#endif

/*! \} */ /* end of group Peripheral_defines */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/*! \addtogroup Backward_Compatibility_Symbols Backward Compatibility */
/*! \{ */

#define ADC_CLMD_REG(base) This_symb_has_been_deprecated
#define ADC_CLMS_REG(base) This_symb_has_been_deprecated
#define ADC_CLM4_REG(base) This_symb_has_been_deprecated
#define ADC_CLM3_REG(base) This_symb_has_been_deprecated
#define ADC_CLM2_REG(base) This_symb_has_been_deprecated
#define ADC_CLM1_REG(base) This_symb_has_been_deprecated
#define ADC_CLM0_REG(base) This_symb_has_been_deprecated
#define ADC_CLMD_CLMD_MASK This_symb_has_been_deprecated
#define ADC_CLMD_CLMD_SHIFT This_symb_has_been_deprecated
#define ADC_CLMD_CLMD(x) This_symb_has_been_deprecated
#define ADC_CLMS_CLMS_MASK This_symb_has_been_deprecated
#define ADC_CLMS_CLMS_SHIFT This_symb_has_been_deprecated
#define ADC_CLMS_CLMS(x) This_symb_has_been_deprecated
#define ADC_CLM4_CLM4_MASK This_symb_has_been_deprecated
#define ADC_CLM4_CLM4_SHIFT This_symb_has_been_deprecated
#define ADC_CLM4_CLM4(x) This_symb_has_been_deprecated
#define ADC_CLM3_CLM3_MASK This_symb_has_been_deprecated
#define ADC_CLM3_CLM3_SHIFT This_symb_has_been_deprecated
#define ADC_CLM3_CLM3(x) This_symb_has_been_deprecated
#define ADC_CLM2_CLM2_MASK This_symb_has_been_deprecated
#define ADC_CLM2_CLM2_SHIFT This_symb_has_been_deprecated
#define ADC_CLM2_CLM2(x) This_symb_has_been_deprecated
#define ADC_CLM1_CLM1_MASK This_symb_has_been_deprecated
#define ADC_CLM1_CLM1_SHIFT This_symb_has_been_deprecated
#define ADC_CLM1_CLM1(x) This_symb_has_been_deprecated
#define ADC_CLM0_CLM0_MASK This_symb_has_been_deprecated
#define ADC_CLM0_CLM0_SHIFT This_symb_has_been_deprecated
#define ADC_CLM0_CLM0(x) This_symb_has_been_deprecated
#define ADC0_CLMD This_symb_has_been_deprecated
#define ADC0_CLMS This_symb_has_been_deprecated
#define ADC0_CLM4 This_symb_has_been_deprecated
#define ADC0_CLM3 This_symb_has_been_deprecated
#define ADC0_CLM2 This_symb_has_been_deprecated
#define ADC0_CLM1 This_symb_has_been_deprecated
#define ADC0_CLM0 This_symb_has_been_deprecated
#define FTM_CVH_REG(base,index) FTM_CnVH_REG(base,index)
#define FTM_CVL_REG(base,index) FTM_CnVL_REG(base,index)
#define FTM_CVH_VAL_H_MASK FTM_CnVH_VAL_H_MASK
#define FTM_CVH_VAL_H_SHIFT FTM_CnVH_VAL_H_SHIFT
#define FTM_CVH_VAL_H(x) FTM_CnVH_VAL_H(x)
#define FTM_CVL_VAL_L_MASK FTM_CnVL_VAL_L_MASK
#define FTM_CVL_VAL_L_SHIFT FTM_CnVL_VAL_L_SHIFT
#define FTM_CVL_VAL_L(x) FTM_CnVL_VAL_L(x)
#define FTM0_CVH(index) FTM0_CnVH(index)
#define FTM1_CVH(index) FTM1_CnVH(index)
#define FTM0_CVL(index) FTM0_CnVL(index)
#define FTM1_CVL(index) FTM1_CnVL(index)
#define SIM_SCGC2_ANL_MASK SIM_SCGC2_CMP_MASK
#define SIM_SCGC2_ANL_SHIFT SIM_SCGC2_CMP_SHIFT

/*! \} */ /* end of group Backward_Compatibility_Symbols */


#else /* #if !defined(MCU_mcf51ju128) */
  /* There is already included the same memory map. Check if it is the same version */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two different versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MCU_mcf51ju128) */

/* mcf51ju128.h, eof. */
