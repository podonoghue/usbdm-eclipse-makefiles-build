/*! \file
    \brief Header file for USBDM_API.c

    \verbatim
    Copyright (C) 2010  Peter O'Donoghue

    Based on material from OSBDM-JM60 Target Interface Software Package
    Copyright (C) 2009  Freescale

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   |    May 2010 | Created
   +====================================================================
    \endverbatim
*/

#ifndef _USBDM_API_H_
#define _USBDM_API_H_

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

//==================================================
#if defined __cplusplus
//! Usual C interface for C++
#define EXTERN_C  extern "C"
#else
//! Usual C interface for C
#ifndef EXTERN_C
#define EXTERN_C
#endif
#endif

#if defined(WIN32)
   #if !defined (WINAPI)
      #ifdef __GNUC__
         #define WINAPI __attribute__((__stdcall__))
      #else
         #define WINAPI
      #endif
   #endif
#endif

#ifdef WIN32
   #ifdef USBDM_DLL_EXPORTS
      //! Building the DLL
      #define USBDM_API      EXTERN_C CPP_DLL_EXPORT WINAPI
      #define OSBDM_API_JM60 EXTERN_C CPP_DLL_EXPORT WINAPI
   #else
      //! Importing the DLL
      #define USBDM_API      EXTERN_C CPP_DLL_IMPORT WINAPI
      #define OSBDM_API_JM60 EXTERN_C CPP_DLL_IMPORT WINAPI
   #endif
#else
   #ifdef USBDM_DLL_EXPORTS
      //! Building the DLL
      #define USBDM_API      EXTERN_C CPP_DLL_EXPORT
      #define OSBDM_API_JM60 EXTERN_C CPP_DLL_EXPORT
   #else
      //! Importing the DLL
      #define USBDM_API      EXTERN_C CPP_DLL_IMPORT
      #define OSBDM_API_JM60 EXTERN_C CPP_DLL_IMPORT
   #endif
#endif

//==================================================

#include "USBDM_ErrorMessages.h"
#include <stdint.h>
#include <stdio.h>

#if defined __cplusplus
    extern "C" {
#else
#undef bool
#define bool char //!< Define bool for C to be consistent with C++!
#endif

//! USBDM Version this header describes
#define USBDM_API_VERSION (0x40A06)  // V4.10.6 (in hex xx.xx.xx)

//! Capabilities of the hardware
//!
typedef enum  {
   BDM_CAP_NONE         = (0),
   BDM_CAP_ALL          = (0xFFFF),
   BDM_CAP_HCS12        = (1<<0),   //!< Supports HCS12
   BDM_CAP_RS08         = (1<<1),   //!< 12 V Flash programming supply available (RS08 support)
   BDM_CAP_VDDCONTROL   = (1<<2),   //!< Control over target Vdd
   BDM_CAP_VDDSENSE     = (1<<3),   //!< Sensing of target Vdd
   BDM_CAP_CFVx         = (1<<4),   //!< Support for CFV 1,2 & 3
   BDM_CAP_HCS08        = (1<<5),   //!< Supports HCS08 targets - inverted when queried
   BDM_CAP_CFV1         = (1<<6),   //!< Supports CFV1 targets  - inverted when queried
   BDM_CAP_JTAG         = (1<<7),   //!< Supports JTAG targets
   BDM_CAP_DSC          = (1<<8),   //!< Supports DSC targets
   BDM_CAP_ARM_JTAG     = (1<<9),   //!< Supports ARM targets via JTAG
   BDM_CAP_RST          = (1<<10),  //!< Control & sensing of RESET
   BDM_CAP_PST          = (1<<11),  //!< Supports PST signal sensing
   BDM_CAP_CDC          = (1<<12),  //!< Supports CDC Serial over USB interface
   BDM_CAP_ARM_SWD      = (1<<13),  //!< Supports ARM targets via SWD
   BDM_CAP_S12Z         = (1<<14),  //!< Supports HCS12Z targets via SWD
} HardwareCapabilities_t;

//==========================================================================================
// Targets and visible capabilities supported - related to above but not exactly!
// e.g. CAP_HCS12 => CAP_BDM+CAP_RST_IO
//      CAP_RS08  => CAP_BDM+CAP_FLASH(+CAP_RST_IO)
//      CAP_HCS08 => CAP_BDM(+CAP_RST_IO)
//      CAP_CFVx  => CAP_JTAG_HW+CAP_CFVx_HW+CAP_RST_IO
//      CAP_DSC   => CAP_JTAG_HW+CAP_RST_IO + s/w routines
//      CAP_JTAG  => CAP_JTAG_HW+CAP_RST_IO
//      CAP_ARM   => CAP_JTAG_HW+CAP_RST_IO
//      CAP_RST   => CAP_RST_IO
// TARGET_CAPABILITY
//
#define CAP_HCS12       (1<<0)      //!< Supports HCS12 targets
#define CAP_RS08        (1<<1)      //!< Supports RS08 targets
#define CAP_VDDCONTROL  (1<<2)      //!< Control over target Vdd
#define CAP_VDDSENSE    (1<<3)      //!< Sensing of target Vdd
#define CAP_CFVx        (1<<4)		//!< Supports CFVx
#define CAP_HCS08       (1<<5)		//!< Supports HCS08 targets - inverted when queried
#define CAP_CFV1        (1<<6)		//!< Supports CFV1 targets  - inverted when queried
#define CAP_JTAG        (1<<7)		//!< Supports JTAG targets
#define CAP_DSC         (1<<8)      //!< Supports DSC targets
#define CAP_ARM_JTAG    (1<<9)      //!< Supports ARM targets via JTAG
#define CAP_RST         (1<<10)     //!< Control & sensing of RESET
#define CAP_PST         (1<<11)     //!< Supports PST signal sensing
#define CAP_CDC         (1<<12)     //!< Supports CDC Serial over USB interface
#define CAP_ARM_SWD     (1<<13)     //!< Supports ARM targets via SWD

//===================================================================================
//!  Target microcontroller types
//!
typedef enum {
   T_HC12      = 0,       //!< HC12 or HCS12 target
   T_HCS12     = T_HC12,  //!< HC12 or HCS12 target
   T_HCS08     = 1,       //!< HCS08 target
   T_RS08      = 2,       //!< RS08 target
   T_CFV1      = 3,       //!< Coldfire Version 1 target
   T_CFVx      = 4,       //!< Coldfire Version 2,3,4 target
   T_JTAG      = 5,       //!< JTAG target - TAP is set to \b RUN-TEST/IDLE
   T_EZFLASH   = 6,       //!< EzPort Flash interface (SPI?)
   T_MC56F80xx = 7,       //!< JTAG target with MC56F80xx optimised subroutines
   T_ARM_JTAG  = 8,       //!< ARM target using JTAG
   T_ARM_SWD   = 9,       //!< ARM target using SWD
   T_ARM       = 10,      //!< ARM target using either SWD (preferred) or JTAG as supported
   T_S12Z      = 11,      //!< S12Z target
   T_LAST      = T_S12Z,
   T_ILLEGAL   = 0xFE,    //!< Used to indicate error in selecting target
   T_OFF       = 0xFF,    //!< Turn off interface (no target)
   T_NONE      = 0xFF,
} TargetType_t;

//! Memory space indicator - includes element size
//!
typedef enum {
   // One of the following
   MS_Byte     = 1,        // Byte (8-bit) access
   MS_Word     = 2,        // Word (16-bit) access
   MS_Long     = 4,        // Long (32-bit) access
   // One of the following
   MS_None     = 0<<4,     // Memory space unused/undifferentiated
   MS_Program  = 1<<4,     // Program memory space (e.g. P: on DSC)
   MS_Data     = 2<<4,     // Data memory space (e.g. X: on DSC)
   MS_Global   = 3<<4,     // HCS12 Global addresses (Using BDMPPR register)
   // Fast memory access for HCS08/HCS12 (stopped target, regs. are modified
   MS_Fast     = 1<<7,
   // Masks for above
   MS_SIZE     = 0x7<<0,   // Size
   MS_SPACE    = 0x7<<4,   // Memory space

   // For convenience (DSC)
   MS_PWord    = MS_Word+MS_Program,
   MS_PLong    = MS_Long+MS_Program,
   MS_XByte    = MS_Byte+MS_Data,
   MS_XWord    = MS_Word+MS_Data,
   MS_XLong    = MS_Long+MS_Data,
} MemorySpace_t;

//! Target supports ACKN or uses fixed delay {WAIT} instead
//!
typedef enum {
   WAIT  = 0,   //!< Use WAIT (delay) instead
   ACKN  = 1,   //!< Target supports ACKN feature and it is enabled
} AcknMode_t;

//! Target speed selection
//!
typedef enum {
   SPEED_NO_INFO        = 0,   //!< Not connected
   SPEED_SYNC           = 1,   //!< Speed determined by SYNC
   SPEED_GUESSED        = 2,   //!< Speed determined by trial & error
   SPEED_USER_SUPPLIED  = 3    //!< User has specified the speed to use
} SpeedMode_t;

//! Target RSTO state
//!
typedef enum {
   RSTO_ACTIVE=0,     //!< RSTO* is currently active [low]
   RSTO_INACTIVE=1    //!< RSTO* is currently inactive [high]
} ResetState_t;

//! Target reset status values
//!
typedef enum {
   NO_RESET_ACTIVITY    = 0,   //!< No reset activity since last polled
   RESET_INACTIVE       = NO_RESET_ACTIVITY,
   RESET_DETECTED       = 1    //!< Reset since last polled
} ResetMode_t;

//! Target Halt state
//!
typedef enum {
   TARGET_RUNNING    = 0,   //!< CFVx target running (ALLPST == 0)
   TARGET_HALTED     = 1    //!< CFVx target halted (ALLPST == 1)
} TargetRunState_t;

//! Target Voltage supply state
//!
typedef enum  {
   BDM_TARGET_VDD_NONE      = 0,   //!< Target Vdd not detected
   BDM_TARGET_VDD_EXT       = 1,   //!< Target Vdd external
   BDM_TARGET_VDD_INT       = 2,   //!< Target Vdd internal
   BDM_TARGET_VDD_ERR       = 3,   //!< Target Vdd error
} TargetVddState_t;

//! Auto-reconnect options
//!
typedef enum  {
   AUTOCONNECT_NEVER   = 0,  //!< Only connect explicitly
   AUTOCONNECT_STATUS  = 1,  //!< Reconnect on USBDM_ReadStatusReg()
   AUTOCONNECT_ALWAYS  = 2,  //!< Reconnect before every command
} AutoConnect_t;

//====================================================================================

//! Internal Target Voltage supply selection
//!
typedef enum  {
   BDM_TARGET_VDD_OFF       = 0,     //!< Target Vdd Off
   BDM_TARGET_VDD_3V3       = 1,     //!< Target Vdd internal 3.3V
   BDM_TARGET_VDD_5V        = 2,     //!< Target Vdd internal 5.0V
   BDM_TARGET_VDD_ENABLE    = 0x10,  //!< Target Vdd internal at last set level
   BDM_TARGET_VDD_DISABLE   = 0x11,  //!< Target Vdd Off but previously set level unchanged
} TargetVddSelect_t;

//! Internal Programming Voltage supply selection
//!
typedef enum  {
   BDM_TARGET_VPP_OFF       = 0,   //!< Target Vpp Off
   BDM_TARGET_VPP_STANDBY   = 1,   //!< Target Vpp Standby (Inverter on, Vpp off)
   BDM_TARGET_VPP_ON        = 2,   //!< Target Vpp On
   BDM_TARGET_VPP_ERROR     = 3,   //!< Target Vpp ??
} TargetVppSelect_t;

//! Target BDM Clock selection
//!
typedef enum {
   CS_DEFAULT           = 0xFF,  //!< Use default clock selection (don't modify target's reset default)
   CS_ALT_CLK           =  0,    //!< Force ALT clock (CLKSW = 0)
   CS_NORMAL_CLK        =  1,    //!< Force Normal clock (CLKSW = 1)
} ClkSwValues_t;

//!  Reset mode as used by CMD_USBDM_TARGET_RESET
//!
typedef enum { /* type of reset action required */
   RESET_MODE_MASK       = (3<<0),  //!< Mask for reset mode (SPECIAL/NORMAL)
   RESET_SPECIAL         = (0<<0),  //!< Special mode [BDM active, Target halted]
   RESET_NORMAL          = (1<<0),  //!< Normal mode [usual reset, Target executes]

   RESET_METHOD_MASK     = (7<<2),  //!< Mask for reset type (Hardware/Software/Power)
   RESET_ALL             = (0<<2),  //!< Use all reset strategies as appropriate
   RESET_HARDWARE        = (1<<2),  //!< Use hardware RESET pin reset
   RESET_SOFTWARE        = (2<<2),  //!< Use software (BDM commands) reset
   RESET_POWER           = (3<<2),  //!< Cycle power
   RESET_VENDOR          = (4<<2),  //!< Vendor special method e.g. using MDM-AP for Kinetis
   RESET_DEFAULT         = (7<<2),  //!< Use target specific default method
} TargetMode_t;

//=======================================================================
//
// regNo Parameter values for USBDM_ReadReg()
//
//=======================================================================

//! regNo Parameter for USBDM_ReadReg() with HCS12 target
//!
//! @note CCR is accessed through USBDM_ReadDReg()
typedef enum {
   HCS12_RegPC    = 3,    //!< PC reg
   HCS12_RegD     = 4,    //!< D reg
   HCS12_RegX     = 5,    //!< X reg
   HCS12_RegY     = 6,    //!< Y reg
   HCS12_RegSP    = 7,    //!< SP reg
   HCS12_RegCCR   = 0x80, //!< CCR reg - redirected to USBDM_ReadDReg()
} HCS12_Registers_t;

//! regNo Parameter for USBDM_ReadReg() with HCS12 target
//!
//! @note CCR is accessed through USBDM_ReadDReg()
typedef enum {
   S12Z_RegD0   = 0x0, //!< D0 reg
   S12Z_RegD1   = 0x1, //!< D1 reg
   S12Z_RegD2   = 0x2, //!< D2 reg
   S12Z_RegD3   = 0x3, //!< D3 reg
   S12Z_RegD4   = 0x4, //!< D4 reg
   S12Z_RegD5   = 0x5, //!< D5 reg
   S12Z_RegD6   = 0x6, //!< D6 reg
   S12Z_RegD7   = 0x7, //!< D7 reg
   S12Z_RegX    = 0x8, //!< X reg
   S12Z_RegY    = 0x9, //!< Y reg
   S12Z_RegSP   = 0xA, //!< SP reg
   S12Z_RegPC   = 0xB, //!< PC reg
   S12Z_RegCCR  = 0xC, //!< CCR reg
} S12Z_Registers_t;

//! regNo Parameter for USBDM_ReadReg() with HCS08 target
//!
typedef enum {
   HCS08_RegPC  = 0xB,  //!< PC  reg
   HCS08_RegSP  = 0xF,  //!< SP  reg
   HCS08_RegHX  = 0xC,  //!< HX  reg
   HCS08_RegA   = 8,    //!< A   reg
   HCS08_RegCCR = 9,    //!< CCR reg
} HCS08_Registers_t;

//! regNo Parameter for USBDM_ReadReg() with RS08 target
//!
typedef enum {
   RS08_RegCCR_PC  = 0xB, //!< Combined CCR/PC register
   RS08_RegSPC     = 0xF, //!< Shadow PC
   RS08_RegA       = 8,   //!< A reg
} RS08_Registers_t;

//! regNo Parameter for USBDM_ReadReg() with CFV1 target
//!
typedef enum {
   CFV1_RegD0     = 0,  //!< D0
   CFV1_RegD1     = 1,  //!< D1
   CFV1_RegD2     = 2,  //!< D2
   CFV1_RegD3     = 3,  //!< D3
   CFV1_RegD4     = 4,  //!< D4
   CFV1_RegD5     = 5,  //!< D5
   CFV1_RegD6     = 6,  //!< D6
   CFV1_RegD7     = 7,  //!< D7
   CFV1_RegA0     = 8,  //!< A0
   CFV1_RegA1     = 9,  //!< A1
   CFV1_RegA2     = 10, //!< A2
   CFV1_RegA3     = 11, //!< A3
   CFV1_RegA4     = 12, //!< A4
   CFV1_RegA5     = 13, //!< A5
   CFV1_RegA6     = 14, //!< A6
   CFV1_RegA7     = 15, //!< A7
   CFV1_RegSP     = CFV1_RegA7,
   CFV1_PSTBASE   = 16, //!< Start of PST registers, access as CFV1_PSTBASE+n
   // The following are used internally by the BDM and only available
   // externally from firmware version 4.10.6
   // Takes advantage of the similarity b/w READ_Rn and READ_DREG
   CFV1_RegOTHER_A7  = 0xC0|0,  //!< Other A7 (not active in target)
   CFV1_RegVBR       = 0xC0|1,  //!< Vector Base register
   CFV1_RegCPUCR     = 0xC0|2,  //!< CPUCR
   CFV1_RegMACSR     = 0xC0|4,  //!< MACSR
   CFV1_RegMASK      = 0xC0|5,  //!< MASK
   CFV1_RegACC       = 0xC0|6,  //!< ACC
   CFV1_RegSR        = 0xC0|14, //!< Status register
   CFV1_RegPC        = 0xC0|15, //!< Program Counter
} CFV1_Registers_t;

//! regNo Parameter for USBDM_ReadReg() with CFVx target
//!
typedef enum {
   CFVx_RegD0  = 0,  //!< D0
   CFVx_RegD1  = 1,  //!< D1
   CFVx_RegD2  = 2,  //!< D2
   CFVx_RegD3  = 3,  //!< D3
   CFVx_RegD4  = 4,  //!< D4
   CFVx_RegD5  = 5,  //!< D5
   CFVx_RegD6  = 6,  //!< D6
   CFVx_RegD7  = 7,  //!< D7
   CFVx_RegA0  = 8,  //!< A0
   CFVx_RegA1  = 9,  //!< A1
   CFVx_RegA2  = 10, //!< A2
   CFVx_RegA3  = 11, //!< A3
   CFVx_RegA4  = 12, //!< A4
   CFVx_RegA5  = 13, //!< A5
   CFVx_RegA6  = 14, //!< A6
   CFVx_RegA7  = 15, //!< A7
   CFVx_RegSP  = CFVx_RegA7,
} CFVx_Registers_t;

//! regNo Parameter for ARM_ReadReg() with ARM (Kinetis) target
//!
typedef enum {
   ARM_RegR0     = 0,    //!< R0
   ARM_RegR1     = 1,    //!< R1
   ARM_RegR2     = 2,    //!< R2
   ARM_RegR3     = 3,    //!< R3
   ARM_RegR4     = 4,    //!< R4
   ARM_RegR5     = 5,    //!< R5
   ARM_RegR6     = 6,    //!< R6
   ARM_RegR7     = 7,    //!< R7
   ARM_RegR8     = 8,    //!< R8
   ARM_RegR9     = 9,    //!< R9
   ARM_RegR10    = 10,   //!< R10
   ARM_RegR11    = 11,   //!< R11
   ARM_RegR12    = 12,   //!< R12
   ARM_RegSP     = 13,   //!< SP
   ARM_RegLR     = 14,   //!< LR
   ARM_RegPC     = 15,   //!< PC (Debug return address)
   ARM_RegxPSR   = 16,   //!< xPSR
   ARM_RegMSP    = 17,   //!< Main Stack pointer
   ARM_RegPSP    = 18,   //!< Process Stack pointer
   ARM_RegMISC   = 20,   //!< [31:24]=CONTROL,[23:16]=FAULTMASK,[15:8]=BASEPRI,[7:0]=PRIMASK.
   //
   ARM_RegFPSCR  = 0x21, //!< Floating point control register
   ARM_RegFPS0   = 0x40, //!< Floating point +0..+31

} ARM_Registers_t;

//! startRegIndex, endRegIndex Parameters for USBDM_ReadMultipleRegs() with ARM (Kinetis) target
//!
typedef enum {
   ARM_RegIndexFirstCore  = 0,                          //!< First code reg
   ARM_RegIndexLastCore   = ARM_RegIndexFirstCore+19,   //!< Last core reg (20 regs R0..R12,SP,LR,PC,XPSR,MSP,PSP,MISC)
   ARM_RegIndexFirstFloat = 20,                         //!< First float register
   ARM_RegIndexLastFloat  = ARM_RegIndexFirstFloat+32,  //!< Last float reg (33 regs FPSCR, FPS0..FPS32)
} ARM_RegisterIndex_t;

//! startRegIndex, endRegIndex Parameters for USBDM_ReadMultipleRegs() with Coldfire V1 target
//!
typedef enum {
   CFV1_RegIndexFirstCore  = 0,                          //!< First code reg
   CFV1_RegIndexLastCore   = CFV1_RegIndexFirstCore+17,  //!< Last core reg (18 regs D0..D7,A0..A7,SR,PC)
} CFV1_RegisterIndex_t;

//! startRegIndex, endRegIndex Parameters for USBDM_ReadMultipleRegs() with Coldfire Vx target
//!
typedef enum {
   CFVx_RegIndexFirstCore  = 0,                          //!< First code reg
   CFVx_RegIndexLastCore   = CFV1_RegIndexFirstCore+17,  //!< Last core reg (18 regs D0..D7,A0..A7,SR,PC)
} CFVx_RegisterIndex_t;

//! regNo Parameter for DSC_ReadReg() with DSC target
//! DSC Core registers
//!
typedef enum {
   // Core registers
   DSC_RegX0,
   DSC_FirstCoreRegister = DSC_RegX0,          // 0
   DSC_RegY0,
   DSC_RegY1,
   DSC_RegA0,
   DSC_RegA1,
   DSC_RegA2,
   DSC_RegB0,
   DSC_RegB1,
   DSC_RegB2,
   DSC_RegC0,
   DSC_RegC1,                                  // 10
   DSC_RegC2,
   DSC_RegD0,
   DSC_RegD1,
   DSC_RegD2,
   DSC_RegOMR,
   DSC_RegSR,
   DSC_RegLA,
   DSC_RegLA2, /* read only */
   DSC_RegLC,
   DSC_RegLC2, /* read only */                 //  20
   DSC_RegHWS0,
   DSC_RegHWS1,
   DSC_RegSP,
   DSC_RegN3,
   DSC_RegM01,
   DSC_RegN,
   DSC_RegR0,
   DSC_RegR1,
   DSC_RegR2,
   DSC_RegR3,                                  // 30
   DSC_RegR4,
   DSC_RegR5,
   DSC_RegsHM01,
   DSC_RegsHN,
   DSC_RegsHR0,
   DSC_RegsHR1,
   DSC_RegPC,
   DSC_LastCoreRegister = DSC_RegPC,           // 37
   // JTAG registers
   DSC_RegIDCODE,                              // JTAG Core IDCODE
   // ONCE registers
   DSC_RegOCR,                                 // ONCE Control register
   DSC_FirstONCERegister = DSC_RegOCR,         // 39
   DSC_RegOSCNTR,                              // ONCE Instruction Step Counter
   DSC_RegOSR,                                 // ONCE Status register
   DSC_RegOPDBR,                               // ONCE Program Data Bus Register
   DSC_RegOBASE,                               // ONCE Peripheral Base Address regitsre
   DSC_RegOTXRXSR,                             // ONCE Tx & Rx Status & Control register
   DSC_RegOTX,                                 // ONCE Transmit register (32-bit)
   DSC_RegOTX1,                                // ONCE Transmit register (16-bit)
   DSC_RegORX,                                 // ONCE Receive register (32-bit)
   DSC_RegORX1,                                // ONCE Receive register (16-bit)
   DSC_RegOTBCR,                               // ONCE Trace buffer control register
   DSC_RegOTBPR,                               // ONCE Trace Buffer Pointer register
   DSC_RegOTB,                                 // Trace Buffer Register Stages
   DSC_RegOB0CR,                               // Breakpoint Unit 0 Control register
   DSC_RegOB0AR1,                              // Breakpoint Unit 0 Address register 1
   DSC_RegOB0AR2,                              // Breakpoint Unit 0 Address register 2
   DSC_RegOB0MSK,                              // Breakpoint Unit 0 Mask register
   DSC_RegOB0CNTR,                             // Breakpoint Unit 0 Counter
   DSC_LastONCERegister = DSC_RegOB0CNTR,      // 58

   DSC_GdiStatus = 0x1001,                     // Used by stand-alone programmer - dummied
   DSC_UnknownReg = 0xFFFFFF,
} DSC_Registers_t;

//=======================================================================
//
// regNo Parameter values for USBDM_ReadCReg()
//
//=======================================================================

//! regNo Parameter for USBDM_ReadCReg() with CFV1 target
//!
typedef enum {
   CFV1_CRegOTHER_A7  = 0,  //!< Other A7 (not active in target)
   CFV1_CRegVBR       = 1,  //!< Vector Base register
   CFV1_CRegCPUCR     = 2,  //!< CPUCR
   CFV1_CRegMACSR     = 4,  //!< MACSR
   CFV1_CRegMASK      = 5,  //!< MASK
   CFV1_CRegACC       = 6,  //!< ACC
   CFV1_CRegSR        = 14, //!< Status register
   CFV1_CRegPC        = 15, //!< Program Counter
} CFV1_CRegisters_t;

//! regNo Parameter for USBDM_ReadCReg() with CFVx target
//!
typedef enum {
   CFVx_CRegD0        = 0x80, //!< D0-D7
   CFVx_CRegD1,
   CFVx_CRegD2,
   CFVx_CRegD3,
   CFVx_CRegD4,
   CFVx_CRegD5,
   CFVx_CRegD6,
   CFVx_CRegD7,
   CFVx_CRegA0,               //!< A0-A7
   CFVx_CRegA1,
   CFVx_CRegA2,
   CFVx_CRegA3,
   CFVx_CRegA4,
   CFVx_CRegA5,
   CFVx_CRegA6,
   CFVx_CRegUSER_SP,
   CFVx_CRegOTHER_SP  = 0x800, //!< Other A7 (not active in target)
   CFVx_CRegVBR       = 0x801, //!< Vector Base register
   CFVx_CRegSR        = 0x80E, //!< Status Register
   CFVx_CRegPC        = 0x80F, //!< Program Counter
   CFV1_CRegFLASHBAR  = 0xC04, //!< Flash Base register
   CFV1_CRegRAMBAR    = 0xC05, //!< RAM Base register
   // May be others
} CFVx_CRegisters_t;

//! regNo Parameter for USBDM_ReadCReg() with SWD-ARM target
//!
//! The regNo is actually a AP bus address as follows:
//!   -  A[31:24]  => DP-AP-SELECT[31:24] (AP # Select)
//!   -  A[23:8]   => unused (0)
//!   -  A[7:4]    => DP-AP-SELECT[7:4]   (Bank select within AP)
//!   -  A[3:2]    => APACC[3:2]          (Register select within AP bank)
//!   -  A[1:0]    => unused (0)
//!
typedef enum {
   // AP#0 - Common ARM AHB-AP
   ARM_CRegAHB_AP_CSW      = 0x00000000U,   //!< AHB-AP Control/Status Word register
   ARM_CRegAHB_AP_TAR      = 0x00000004U,   //!< AHB-AP Transfer Address register
   ARM_CRegAHB_AP_DRW      = 0x0000000CU,   //!< AHB-AP Data Read/Write register

   ARM_CRegAHB_AP_CFG      = 0x000000F4U,   //!< AHB-AP Config register
   ARM_CRegAHB_AP_Base     = 0x000000F8U,   //!< AHB-AP IDebug base address register
   ARM_CRegAHB_AP_Id       = 0x000000FCU,   //!< AHB-AP ID Register

   // AP#1 - Kinetis MDM-AP registers
   ARM_CRegMDM_AP_Status   = 0x01000000U,   //!< Status register
   ARM_CRegMDM_AP_Control  = 0x01000004U,   //!< Control register
   ARM_CRegMDM_AP_Ident    = 0x010000FCU,   //!< Identifier register (should read 0x001C_0000)
} ARM_CRegisters_t;

//=======================================================================
//
// regNo Parameter values for USBDM_ReadDReg()
//
//=======================================================================

//! regNo Parameter for USBDM_ReadDReg() with HCS12 target [BD Space]
//!
//! @note: There may be other registers
//!
typedef enum {
   // 8-bit accesses using READ_BD_BYTE
   HCS12_DRegBDMSTS = (int)0xFF01, //!< - BDMSTS (debug status/control) register
   HCS12_DRegCCR    = (int)0xFF06, //!< - Saved Target CCR
   HCS12_DRegBDMINR = (int)0xFF07, //!< - BDM Internal Register Position Register
   // Others may be device dependent
} HCS12_DRegisters_t;

//! regNo Parameter for USBDM_ReadDReg() with HCS08 target [BKPT reg]
//!
typedef enum {
   HCS08_DRegBKPT = 0x0, //!< Breakpoint register
} HCS08_DRegisters_t;

//! regNo Parameter for USBDM_ReadDReg() with RS08 target (BKPT)
//!
typedef enum {
   RS08_DRegBKPT = 0x0, //!< Breakpoint register
} RS08_DRegisters_t;

//! regNo Parameter for USBDM_ReadDReg() with CFV1 target
//!
//! @note: There may be other registers
typedef enum {
   CFV1_DRegCSR        = 0x00,   //!< CSR
   CFV1_DRegXCSR       = 0x01,   //!< XCSR
   CFV1_DRegCSR2       = 0x02,   //!< CSR2
   CFV1_DRegCSR3       = 0x03,   //!< CSR3
   CFV1_DRegBAAR       = 0x05,   //!< BAAR
   CFV1_DRegAATR       = 0x06,   //!< AATR
   CFV1_DRegTDR        = 0x07,   //!< TDR
   CFV1_DRegPBR0       = 0x08,   //!< PBR0
   CFV1_DRegPBMR       = 0x09,   //!< PBMR - mask for PBR0
   CFV1_DRegABHR       = 0x0C,   //!< ABHR
   CFV1_DRegABLR       = 0x0D,   //!< ABLR
   CFV1_DRegDBR        = 0x0E,   //!< DBR
   CFV1_DRegBDMR       = 0x0F,   //!< DBMR - mask for DBR
   CFV1_DRegPBR1       = 0x18,   //!< PBR1
   CFV1_DRegPBR2       = 0x1A,   //!< PBR2
   CFV1_DRegPBR3       = 0x1B,   //!< PBR3

   CFV1_ByteRegs       = 0x1000, //!< Special access to msb
   CFV1_DRegXCSRbyte   = CFV1_ByteRegs+CFV1_DRegXCSR, //!< XCSR.msb
   CFV1_DRegCSR2byte   = CFV1_ByteRegs+CFV1_DRegCSR2, //!< CSR2.msb
   CFV1_DRegCSR3byte   = CFV1_ByteRegs+CFV1_DRegCSR3, //!< CSR3.msb
} CFV1_DRegisters_t;

//! regNo Parameter for USBDM_ReadDReg() with CFV1 target
//!
typedef enum {
   CFVx_DRegCSR    = 0x00, //!< CSR
   CFVx_DRegBAAR   = 0x05, //!< BAAR
   CFVx_DRegAATR   = 0x06, //!< AATR
   CFVx_DRegTDR    = 0x07, //!< TDR
   CFVx_DRegPBR0   = 0x08, //!< PBR0
   CFVx_DRegPBMR   = 0x09, //!< PBMR - mask for PBR0
   CFVx_DRegABHR   = 0x0C, //!< ABHR
   CFVx_DRegABLR   = 0x0D, //!< ABLR
   CFVx_DRegDBR    = 0x0E, //!< DBR
   CFVx_DRegBDMR   = 0x0F, //!< DBMR - mask for DBR
   CFVx_DRegPBR1   = 0x18, //!< PBR1
   CFVx_DRegPBR2   = 0x1A, //!< PBR2
   CFVx_DRegPBR3   = 0x1B, //!< PBR3
} CFVx_DRegisters_t;

//! regNo Parameter for USBDM_ReadDReg() with SWD-ARM target
//!
typedef enum {
   ARM_DRegIDCODE  = 0,    //!< IDCODE  reg - read, SWD-AP only
   ARM_DRegABORT   = 0,    //!< ABORT   reg - write only
   ARM_DRegSTATUS  = 1,    //!< STATUS  reg - read only
   ARM_DRegCONTROL = 1,    //!< CONTROL reg - write only
   ARM_DRegRESEND  = 2,    //!< RESEND  reg - read only
   ARM_DRegSELECT  = 2,    //!< SELECT  reg - write only
   ARM_DRegRDBUFF  = 3,    //!< RDBUFF  reg - read only

   ARM_DRegAPReg0  = 4,    //!< AP reg #0
   ARM_DRegAPReg1  = 5,    //!< AP reg #1
   ARM_DRegAPReg2  = 6,    //!< AP reg #2
   ARM_DRegAPReg3  = 7,    //!< AP reg #3
} ARM_DRegisters_t;

//=======================================================================
//
//=======================================================================


//! State of BDM Communication
//!
typedef struct {
   TargetType_t         target_type;       //!< Type of target (HCS12, HCS08 etc) @deprecated
   AcknMode_t           ackn_state;        //!< Supports ACKN ?
   SpeedMode_t          connection_state;  //!< Connection status & speed determination method
   ResetState_t         reset_state;       //!< Current target RST0 state
   ResetMode_t          reset_recent;      //!< Target reset recently?
   TargetRunState_t     halt_state;        //!< CFVx halted (from ALLPST)?
   TargetVddState_t     power_state;       //!< Target has power?
   TargetVppSelect_t    flash_state;       //!< State of Target Vpp
} USBDMStatus_t;

//=======================================================================
//
//  JTAG Interface
//
//=======================================================================

//! Options used with JTAG commands
//!
typedef enum {
   JTAG_STAY_SHIFT       = 0,     //!< Remain in SHIFT-DR or SHIFT-IR
   JTAG_EXIT_IDLE        = 1,     //!< Exit SHIFT-XX to RUN-TEST/IDLE
   JTAG_EXIT_SHIFT_DR    = 2,     //!< Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
   JTAG_EXIT_SHIFT_IR    = 3,     //!< Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
   JTAG_EXIT_ACTION_MASK = 0x3,   //!< Mask for Exit actions

   JTAG_WRITE_0          = 0x00,  //!< Write 0's when reading - combined with above
   JTAG_WRITE_1          = 0x80,  //!< Write 1's when reading - combined with above
   JTAG_WRITE_MASK       = 0x80,  //!< Mask for Write actions

   JTAG_SHIFT_DR         = 0,     //!< Enter SHIFT-DR (from TEST-LOGIC-RESET or RUN-TEST/IDLE)
   JTAG_SHIFT_IR         = 1,     //!< Enter SHIFT-IR (from TEST-LOGIC-RESET or RUN-TEST/IDLE)
} JTAG_ExitActions_t;


//! Control signal masks for CMD_USBDM_CONTROL_PIN (USBDM_ControlPins())
typedef enum {
   PIN_BKGD_OFFS      = (0),
   PIN_BKGD           = (3<<PIN_BKGD_OFFS),  //!< Mask for BKGD values (PIN_BKGD_LOW, PIN_BKGD_HIGH & PIN_BKGD_3STATE)
   PIN_BKGD_NC        = (0<<PIN_BKGD_OFFS),  //!< No change
   PIN_BKGD_3STATE    = (1<<PIN_BKGD_OFFS),  //!< Set BKGD 3-state
   PIN_BKGD_LOW       = (2<<PIN_BKGD_OFFS),  //!< Set BKGD low
   PIN_BKGD_HIGH      = (3<<PIN_BKGD_OFFS),  //!< Set BKGD high

   PIN_RESET_OFFS     = (2),
   PIN_RESET          = (3<<PIN_RESET_OFFS), //!< Mask for RESET values (PIN_RESET_LOW & PIN_RESET_3STATE)
   PIN_RESET_NC       = (0<<PIN_RESET_OFFS), //!< No change
   PIN_RESET_3STATE   = (1<<PIN_RESET_OFFS), //!< Set Reset 3-state
   PIN_RESET_LOW      = (2<<PIN_RESET_OFFS), //!< Set Reset low
   PIN_RESET_HIGH     = (3<<PIN_RESET_OFFS), //!< Status only - Reset high

   PIN_TA_OFFS        = (4),
   PIN_TA             = (3<<PIN_TA_OFFS),    //!< Mask for TA signal
   PIN_TA_NC          = (0<<PIN_TA_OFFS),    //!< No change
   PIN_TA_3STATE      = (1<<PIN_TA_OFFS),    //!< Set TA 3-state
   PIN_TA_LOW         = (2<<PIN_TA_OFFS),    //!< Set TA low

   PIN_DE_OFFS        = (4),
   PIN_DE             = (3<<PIN_DE_OFFS),    //!< Mask for DE signal
   PIN_DE_NC          = (0<<PIN_DE_OFFS),    //!< No change
   PIN_DE_3STATE      = (1<<PIN_DE_OFFS),    //!< Set DE 3-state
   PIN_DE_LOW         = (2<<PIN_DE_OFFS),    //!< Set DE low

   PIN_TRST_OFFS      = (6),
   PIN_TRST           = (3<<PIN_TRST_OFFS),  //!< Mask for TRST signal (not implemented)
   PIN_TRST_NC        = (0<<PIN_TRST_OFFS),  //!< No change
   PIN_TRST_3STATE    = (1<<PIN_TRST_OFFS),  //!< Set TRST 3-state
   PIN_TRST_LOW       = (2<<PIN_TRST_OFFS),  //!< Set TRST low

   PIN_BKPT_OFFS      = (8),
   PIN_BKPT           = (3<<PIN_BKPT_OFFS),  //!< Mask for BKPT signal
   PIN_BKPT_NC        = (0<<PIN_BKPT_OFFS),  //!< No change
   PIN_BKPT_3STATE    = (1<<PIN_BKPT_OFFS),  //!< Set BKPT 3-state
   PIN_BKPT_LOW       = (2<<PIN_BKPT_OFFS),  //!< Set BKPT low

   PIN_SWD_OFFS       = (10),
   PIN_SWD            = (3<<PIN_SWD_OFFS),   //!< Mask for SWD values (PIN_SWD_LOW, PIN_SWD_HIGH & PIN_SWD_3STATE)
   PIN_SWD_NC         = (0<<PIN_SWD_OFFS),   //!< No change
   PIN_SWD_3STATE     = (1<<PIN_SWD_OFFS),   //!< Set SWD 3-state
   PIN_SWD_LOW        = (2<<PIN_SWD_OFFS),   //!< Set SWD low
   PIN_SWD_HIGH       = (3<<PIN_SWD_OFFS),   //!< Set SWD high

   PIN_SWCLK_OFFS     = (12),
   PIN_SWCLK          = (3<<PIN_SWCLK_OFFS),   //!< Mask for SWD values (PIN_SWCLK_LOW, PIN_SWCLK_HIGH & PIN_SWCLK_3STATE)
   PIN_SWCLK_NC       = (0<<PIN_SWCLK_OFFS),   //!< No change
   PIN_SWCLK_3STATE   = (1<<PIN_SWCLK_OFFS),   //!< Set SWD 3-state
   PIN_SWCLK_LOW      = (2<<PIN_SWCLK_OFFS),   //!< Set SWD low
   PIN_SWCLK_HIGH     = (3<<PIN_SWCLK_OFFS),   //!< Set SWD high

   PIN_NOCHANGE       = 0,    //!< No change to pins (used to get pin status)
   PIN_RELEASE        = -1,   //!< Release all pins (go to default for current target)
} PinLevelMasks_t ;

//! BDM interface options
//!
//! @deprecated
//!
typedef struct {
   // Options passed to the BDM
   int  targetVdd;                //!< Target Vdd (off, 3.3V or 5V)
   int  cycleVddOnReset;          //!< Cycle target Power  when resetting
   int  cycleVddOnConnect;        //!< Cycle target Power if connection problems)
   int  leaveTargetPowered;       //!< Leave target power on exit
   int  autoReconnect;            //!< Automatically re-connect to target (for speed change)
   int  guessSpeed;               //!< Guess speed for target w/o ACKN
   int  useAltBDMClock;           //!< Use alternative BDM clock source in target
   int  useResetSignal;           //!< Whether to use RESET signal on BDM interface
   int  maskInterrupts;           //!< Whether to mask interrupts when  stepping
   int  reserved1[2];             //!< Reserved

   // Options used internally by DLL
   int  manuallyCycleVdd;         //!< Prompt user to manually cycle Vdd on connection problems
   int  derivative_type;          //!< RS08 Derivative
   int  interfaceSpeed;           //!< CFVx/JTAG etc - Interface speed (kHz). \n
   int  miscOptions;              //!< Various misc options
   int  usePSTSignals;            //!< CFVx, PST Signal monitors
   int  reserved2[2];             //!< Reserved
} BDM_Options_t;

//! BDM interface options
//!
typedef struct {
   // Options passed to the BDM
   unsigned           size;                       //!< Size of this structure - must be initialised!
   TargetType_t       targetType;                 //!< Target type
   TargetVddSelect_t  targetVdd;                  //!< Target Vdd (off, 3.3V or 5V)
   bool               cycleVddOnReset;            //!< Cycle target Power  when resetting
   bool               cycleVddOnConnect;          //!< Cycle target Power if connection problems)
   bool               leaveTargetPowered;         //!< Leave target power on exit
   AutoConnect_t      autoReconnect;              //!< Automatically re-connect to target (for speed change)
   bool               guessSpeed;                 //!< Guess speed for target w/o ACKN
   ClkSwValues_t      bdmClockSource;             //!< BDM clock source in target
   bool               useResetSignal;             //!< Whether to use RESET signal on BDM interface
   bool               maskInterrupts;             //!< Whether to mask interrupts when  stepping
   unsigned           interfaceFrequency;         //!< CFVx/JTAG etc - Interface speed (kHz)
   bool               usePSTSignals;              //!< CFVx, PST Signal monitors
   unsigned           powerOffDuration;           //!< How long to remove power (ms)
   unsigned           powerOnRecoveryInterval;    //!< How long to wait after power enabled (ms)
   unsigned           resetDuration;              //!< How long to assert reset (ms)
   unsigned           resetReleaseInterval;       //!< How long to wait after reset release to release other signals (ms)
   unsigned           resetRecoveryInterval;      //!< How long to wait after reset sequence completes (ms)
   unsigned           hcs08sbdfrAddress;          //!< Address to use to access SBDFR register
} USBDM_ExtendedOptions_t;

//! Structure to hold version information for BDM
//! @note bdmHardwareVersion should always equal icpHardwareVersion
typedef struct {
   unsigned char bdmSoftwareVersion; //!< Version of USBDM Firmware
   unsigned char bdmHardwareVersion; //!< Version of USBDM Hardware
   unsigned char icpSoftwareVersion; //!< Version of ICP bootloader Firmware
   unsigned char icpHardwareVersion; //!< Version of Hardware (reported by ICP code)
} USBDM_Version_t;

//! Structure describing characteristics of currently open BDM
typedef struct {
   unsigned                size;                 //!< Size of this structure
   int                     BDMsoftwareVersion;   //!< BDM Firmware version as 3 bytes (4.10.4 => 0x040A04)
   int                     BDMhardwareVersion;   //!< Hardware version reported by BDM firmware
   int                     ICPsoftwareVersion;   //!< ICP Firmware version
   int                     ICPhardwareVersion;   //!< Hardware version reported by ICP firmware
   HardwareCapabilities_t  capabilities;         //!< BDM Capabilities
   unsigned                commandBufferSize;    //!< Size of BDM Communication buffer
   unsigned                jtagBufferSize;       //!< Size of JTAG buffer (if supported)
} USBDM_bdmInformation_t;

// The following functions are available when in BDM mode
//====================================================================
//
//! Initialises USB interface
//!
//! This must be done before any other operations.
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Init(void);
//! Clean up
//!
//! This must be called after all USBDM operations are finished
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Exit(void);

//! Get version of the DLL
//!
//! @return version number (e.g. V4.9.5 => 0x40905)
//!
//! @note Prior to V4.9.5 an 8-bit version number (2 BCD digits, major-minor) was returned\n
//!       This shouldn't be a problem as still monotonic
//!
USBDM_API
unsigned int USBDM_DLLVersion(void);

//! Get version string for DLL
//!
//! @return ptr to static ASCII string
//!
USBDM_API
const char *USBDM_DLLVersionString(void);

//! Gets string describing a USBDM error code
//!
//! @param errorCode - error code returned from USBDM API routine.
//!
//! @return - ptr to static string describing the error.
//!
USBDM_API
const char *USBDM_GetErrorString(USBDM_ErrorCode errorCode);

//=============================================================================
//=============================================================================
//=============================================================================
// USBDM Device handling

//! Find USBDM Devices \n
//! This function creates an internal list of USBDM devices.  The list is held until
//! USBDM_ReleaseDevices() is called. \n
//! USBDM_FindDevices() must be done before any device may be opened.
//!
//! @param deviceCount Number of BDM devices found
//!
//! @return \n
//!     BDM_RC_OK                => OK \n
//!     BDM_RC_NO_USBDM_DEVICE   => No devices found.
//!     other                    => other Error - see \ref USBDM_ErrorCode
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until USBDM_ReleaseDevices() is called
//!
USBDM_API
USBDM_ErrorCode  USBDM_FindDevices(unsigned int *deviceCount);

//! Release USBDM Device list
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_ReleaseDevices(void);

//! Obtain serial number of the currently opened BDM
//!
//! @param deviceSerialNumber  Updated to point to UTF-16LE serial number
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
//! @note deviceDescription points at a statically allocated buffer - do not free
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetBDMSerialNumber(const char **deviceSerialNumber);

//! Obtain description of the currently opened BDM
//!
//! @param deviceDescription  Updated to point to UTF-16LE device description
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
//! @note deviceDescription points at a statically allocated buffer - do not free
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetBDMDescription(const char **deviceDescription);

//! Opens a device
//!
//! @param deviceNo Number (0..N) of device to open.
//! A device must be open before any communication with the device can take place.
//!
//! @note The range of device numbers must be obtained from USBDM_FindDevices() before
//! calling this function.
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_Open(unsigned char deviceNo);

//! Closes currently open device
//!
//! @return \n
//!     BDM_RC_OK => OK
//!
USBDM_API
USBDM_ErrorCode  USBDM_Close(void);

//! Gets BDM software version and type of hardware
//!
//! @param version Version numbers (4 bytes)
//!  - USBDM software version              \n
//!  - USBDM hardware type                 \n
//!  - ICP software version                \n
//!  - ICP hardware type                   \n
//!  USBDM & ICP hardware versions should always agree
//!
//! @return \n
//!     BDM_RC_OK   => OK \n
//!     other       => Error code - see \ref USBDM_ErrorCode
//!
//! @note - This command is directed to EP0 and is also allowed in ICP mode
//!
//! @deprecated: use USBDM_GetBdmInformation()
//!
USBDM_API
USBDM_ErrorCode USBDM_GetVersion(USBDM_Version_t *version);

//! \brief Obtains the Capability vector from the BDM interface
//!
//! @param capabilities : ptr to where to return capability vector see \ref HardwareCapabilities_t
//! @return \n
//!     BDM_RC_OK                 => OK \n
//!     BDM_RC_WRONG_BDM_REVISION => BDM firmware/DLL are incompatible \n
//!     other                     => Error code - see \ref USBDM_ErrorCode
//!
//! @note Uses cached information from when the BDM was opened.
//! @note Can be used to check BDM firmware/DLL compatibility
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetCapabilities(HardwareCapabilities_t *capabilities);

//! \brief Obtains information about the currently open BDM interface
//!
//! @param info ptr to structure to contain the information
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @note The size element of info should be initialised before call.
//! @note Uses cached information from when the BDM was opened.
//!
USBDM_API
USBDM_ErrorCode USBDM_GetBdmInformation(USBDM_bdmInformation_t *info);

//! Set BDM interface options
//!
//! @param newBdmOptions : Options to pass to BDM interface
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @deprecated - Use USBDM_SetExtendedOptions()
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetOptions(BDM_Options_t *newBdmOptions);

//! Get default (target specific) BDM interface options
//!
//! @param bdmOptions : Current options from BDM interface\n
//!                        Note - bdmOptions.size must be initialised \n
//!                             - bdmOptions.targetType may be set
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @note newBdmOptions.targetType should be set if called before USBDM_SetTarget()
//!
USBDM_API
USBDM_ErrorCode USBDM_GetDefaultExtendedOptions(USBDM_ExtendedOptions_t *bdmOptions);

//! Set BDM interface options
//!
//! @param newBdmOptions : Options to pass to BDM interface\n
//!                        Note - size field must be initialised
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_SetExtendedOptions(const USBDM_ExtendedOptions_t *newBdmOptions);

//! Get BDM interface options
//!
//! @param currentBdmOptions : Current options from BDM interface\n
//!                            Note - currentBdmOptions.size must be initialised
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetExtendedOptions(USBDM_ExtendedOptions_t *currentBdmOptions);

//! Sets Target Vdd voltage
//!
//! @param targetVdd => control value for Vdd
//!
//! @return \n
//!     BDM_RC_OK     => OK \n
//!     else          => Various errors
//!
//! @note
//! - BDM_TARGET_VDD_ENABLE & BDM_TARGET_VDD_DISABLE should be used to enable and disable Vdd
//! - BDM_TARGET_VDD_OFF, BDM_TARGET_VDD_3V3 & BDM_TARGET_VDD_5V should be used to set the required Vdd.
//! - It is expected that the USBDM_SetTargetVdd() will be used to set the initial Vdd before calling
//!   USBDM_SetTarget() so that the appropriate power on sequence may be used.
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetTargetVdd(TargetVddSelect_t targetVdd);

//! Sets Target programming voltage
//!
//! @param targetVpp => control value for Vpp
//!
//! @note Before enabling target Vpp it is necessary to do the following: \n
//! - Target device must be set to T_RS08 \n
//! - Target Vdd must be present (internally or externally) \n
//! - The Target Vpp must be first set to BDM_TARGET_VPP_STANDBY then BDM_TARGET_VPP_ON \n
//! The above is checked by the BDM firmware
//!
//! @return \n
//!     BDM_RC_OK     => OK \n
//!     else          => Various errors
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetTargetVpp(TargetVppSelect_t targetVpp);

//! Directly manipulate interface levels
//!
//! @param control       => mask indicating interface levels see \ref InterfaceLevelMasks_t
//! @param duration_10us => time (in 10us ticks) to assert level
//!                         (0 = indefinite)
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note - Only partially implemented in BDM firmware
//! @deprecated - use \ref USBDM_ControlPins()
//!
//USBDM_API
//USBDM_ErrorCode USBDM_ControlInterface(unsigned char duration_10us, unsigned int  control);

//! Directly manipulate interface levels
//!
//! @param control       => mask indicating interface levels see \ref PinLevelMasks_t
//! @param status        => values on pins after action (not yet implemented). May be NULL.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
#if defined __cplusplus
USBDM_API
USBDM_ErrorCode USBDM_ControlPins(unsigned int control, unsigned int *status=0);
#else
USBDM_API
USBDM_ErrorCode USBDM_ControlPins(unsigned int control, unsigned int *status);
#endif
//=============================================================================
//=============================================================================
//=============================================================================
// Target handling

//! Sets target MCU type
//!
//! If the BDM has target power control then it will also:
//!   - Turn on target power
//!   - Halt the target if power has been newly applied (in special mode if appropriate)
//!   - ARM targets have hardware reset active to avoid power-on lockups or COP timeouts
//!
//! @param targetType type of target
//!
//! @return 0 => Success,\n !=0 => Fail
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_SetTargetType(TargetType_t targetType);

//! Execute debug command (various, see DebugSubCommands)
//!
//! @param usb_data - Command for BDM
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_Debug(unsigned char *usb_data);

/*!
 * Send Custom BDM command
 *
 * @param txSize
 * @param rxSize
 * @param data
 */
USBDM_API
USBDM_ErrorCode USBDM_BDMCommand(unsigned int txSize, unsigned int rxSize, unsigned char data[]);

//! Get status of the last command
//!
//! @return \n
//!     BDM_RC_OK          => OK \n
//!     BDM_RC_USB_ERROR   => USB failure \n
//!     other              => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetCommandStatus(void);

//! Fills user supplied structure with state of BDM communication channel
//!
//! @param USBDMStatus Pointer to structure to receive status, see \ref USBDMStatus_t
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetBDMStatus(USBDMStatus_t *USBDMStatus);

//! Connects to Target.
//!
//! This will cause the BDM module to attempt to connect to the Target.
//! In most cases the BDM module will automatically determine the connection
//! speed and successfully connect.  If unsuccessful, it may be necessary
//! to manually set the speed using set_speed().
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_Connect(void);

//! Sets the BDM communication speed.
//!
//! @param frequency => BDM Communication speed in kHz \n
//! - T_CFVx, T_JTAG, T_MC56F80xx : JTAG clock frequency \n
//! - RS08, HCS08, HCS12, CFV1    : BDM interface frequency \n
//!    Usually equal to the CPU Bus frequency. \n
//!    May be unrelated to bus speed if alternative BDM clock is in use. \n
//!    Once a speed is set then automatic speed determination (by sync etc)
//!    is disabled.  Automatic operation is restored by setting a speed of zero. \n
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetSpeed( unsigned long frequency);

//! Get the BDM communication speed in kHz
//!
//! @param frequency => BDM Communication speed in kHz
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetSpeed(unsigned long *frequency /* kHz */);

//! Get the BDM communication speed in Hz
//!
//! @param frequency => BDM Communication speed in Hz
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_GetSpeedHz(unsigned long *frequency /* Hz */);

//! Reads Target Status register byte
//!
//! @param BDMStatusReg => status register value read. \n
//! The register read depends on target:
//!  - HCS12   = BDMSTS, BDM Status register \n
//!  - HCS08   = BDCSCR, BDM Status & Control register \n
//!  - RS08    = BDCSCR, BDM Status & Control register \n
//!  - CFV1    = XCSR[31..24], Extended Configuration/Status Register \n
//!  - CFVx    = CSR, Configuration/Status Register (CSR)
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
//! @note \n
//!    The BDM may resynchronize/reconnect with the target before doing this read.
//!
USBDM_API
USBDM_ErrorCode  USBDM_ReadStatusReg(unsigned long *BDMStatusReg);

//! Write Target Control Register byte
//!
//! @param value => value to write
//! The register written depends on target:
//!  - HCS12 = BDMSTS, BDM Status register \n
//!  - HCS08 = BDCSCR, BDM Status & Control register \n
//!  - RS08  = BDCSCR, BDM Status & Control register \n
//!  - CFV1  = XCSR[31..24], Extended Configuration/Status Register \n
//!  - CFVx  not supported (Access CSR through writeControlReg())
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_WriteControlReg(unsigned int value);

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// Target run control

//! Resets the target to normal or special mode
//!
//! @param target_mode see
//!
//! @return \n
//!     BDM_RC_OK   => OK \n
//!     other       => Error code - see \ref USBDM_ErrorCode
//!
//! @note V4.4 onwards - Communication with the target may be lost.  It is necessary to use
//! USBDM_Connect() to re-connect.  This is no longer done automatically
//! as it may interfere with security checking if attempted too soon after reset.
//!
USBDM_API
USBDM_ErrorCode  USBDM_TargetReset(TargetMode_t target_mode);

//! Steps over a single target instruction
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_TargetStep(void);

//! Starts target execution from current PC address
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_TargetGo(void);

//! Brings the target into active background mode.  The target will be halted.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_TargetHalt(void);

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// Target register Read/Write

//! Write Target Core register
//!
//! @param regNo    Register #
//!  - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
//!  - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
//!  - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
//!  - CFV1      = Core register space D0-D7, A0-A7 see \ref CFV1_Registers_t  \n
//!  - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
//!  - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
//!  - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteReg(unsigned int regNo, unsigned long regValue);

//! Read Target Core register
//!
//! @param regNo    Register #
//!  - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
//!  - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
//!  - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
//!  - CFV1      = Core register space D0-D7, A0-A7, PSTBASE+n, see \ref CFV1_Registers_t  \n
//!  - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
//!  - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
//!  - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note HCS12_RegCCR is accessed through \ref USBDM_ReadDReg()
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadReg(unsigned int regNo, unsigned long *regValue);

//! Read Multiple Core registers
//!
//! @param regValueBuffer Values in Target byte order??
//! @param startRegIndex     Register index (inclusive) to start reading at
//! @param endRegIndex       Register index (inclusive) to stop reading at
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note The indexes mentioned above are magic numbers indexing an arbitrary table.\n
//!       Use only the predefined values provided - \ref ARM_RegisterIndex_t, \ref CFV1_RegisterIndex_t, \ref CFVx_RegisterIndex_t
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex);

//! Write Target Control register
//!
//! @param regNo    Register #
//!    - HCS12     = not used \n
//!    - HCS08     = not used \n
//!    - RS08      = not used \n
//!    - CFV1      = Control register space, see \ref CFV1_CRegisters_t\n
//!    - CFVx      = Control register space, see \ref CFVx_CRegisters_t
//!    - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
//!    - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
//!
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteCReg(unsigned int regNo, unsigned long regValue);

//! Read Target Control register
//!
//! @param regNo    Register # or address
//!    - HCS12     = not used \n
//!    - HCS08     = not used \n
//!    - RS08      = not used \n
//!    - CFV1      = Control register space, see \ref CFV1_CRegisters_t\n
//!    - CFVx      = Control register space, see \ref CFVx_CRegisters_t \n
//!    - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
//!    - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
//!
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadCReg(unsigned int regNo, unsigned long *regValue);

//! Write Target Debug register
//!
//! @param regNo    Register #
//!   - HCS12     = BD memory space, see \ref HCS12_DRegisters_t   \n
//!   - HCS08     = BKPT register, see \ref HCS08_DRegisters_t   \n
//!   - RS08      = BKPT register, see \ref RS08_DRegisters_t   \n
//!   - CFV1      = Debug register space, see \ref CFV1_DRegisters_t\n
//!   - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
//!   - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
//!   - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteDReg(unsigned int regNo, unsigned long regValue);

//! Read Target Debug register
//!
//! @param regNo    Register #
//!   - HCS12     = BD memory space, see \ref HCS12_DRegisters_t   \n
//!   - HCS08     = BKPT register, see \ref HCS08_DRegisters_t   \n
//!   - RS08      = BKPT register, see \ref RS08_DRegisters_t   \n
//!   - CFV1      = Debug register space, see \ref CFV1_DRegisters_t\n
//!   - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
//!   - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
//!   - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadDReg(unsigned int regNo, unsigned long *regValue);

//! Write data to target memory
//!
//! @param memorySpace = Size of data elements (1/2/4 bytes)
//! @param byteCount   = Number of _bytes_ to transfer
//! @param address     = Memory address
//! @param data        = Ptr to block of data to write
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteMemory( unsigned int        memorySpace,
                                   unsigned int        byteCount,
                                   unsigned int        address,
                                   unsigned const char *data);

//! Read data from target memory
//!
//! @param memorySpace = Size of data (1/2/4 bytes)
//! @param byteCount   = Number of bytes to transfer
//! @param address     = Memory address
//! @param data        = Where to place data
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadMemory( unsigned int  memorySpace,
                                  unsigned int  byteCount,
                                  unsigned int  address,
                                  unsigned char *data);

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// JTAG Entry points
//

//! JTAG - Moves the TAP to \b TEST-LOGIC-RESET state
//! TMS=11111, TDI=00000 or similar
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note This uses the CMD_USBDM_JTAG_GOTORESET to move the TAP, it does
//!       not use TRST.
//!
USBDM_API
USBDM_ErrorCode  USBDM_JTAG_Reset(void);

//! JTAG - move the TAP to \b SHIFT-DR or \b SHIFT-IR state
//! SHIFT_DR => TMS=100,  TDI=0 (Actually TMS=0000_0100)
//! SHIFT_IR => TMS=1100, TDI=0 (Actually TMS=0000_1100)
//!
//! @param mode Action, ref \ref JTAG_ExitActions_t \n
//!      - SHIFT_DR - Enter SHIFT-DR \n
//!      - SHIFT_IR - Enter SHIFT-IR \n
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note - Requires the tap to be initially in \b TEST-LOGIC-RESET or \b RUN-TEST/IDLE
//!
USBDM_API
USBDM_ErrorCode  USBDM_JTAG_SelectShift(unsigned char mode);

//! JTAG - write data to JTAG shift register
//! STAY_SHIFT    => TMS=Nx0,       TDI=NxData
//! EXIT_SHIFT_DR => TMS=Nx0,11100  TDI=NxData,00000
//! EXIT_SHIFT_IR => TMS=Nx0,111100 TDI=NxData,000000
//! EXIT_IDLE     => TMS=Nx0,10     TDI=NxData,00
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param buffer Pointer to data buffer.  The data is shifted in LSB (last byte) first,
//!                unused bits (if any) are in the MSB (first) byte;
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_Write(unsigned char       bitCount,
                                 unsigned char       exit,
                                 const unsigned char *buffer);

//! JTAG - read data from JTAG shift register
//! SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!      - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
//!      - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param buffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_Read( unsigned char bitCount,
                                 unsigned char exit,
                                 unsigned char *buffer);

//! JTAG - read/write data from/to JTAG shift register
//! SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!      - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
//!      - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param inBuffer  Pointer to buffer for data written to the device (first bit in LSB of the last byte in the buffer)
//!  @param outBuffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!  @note inbuffer and outbuffer may be the same location
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_ReadWrite( unsigned char bitCount,
                                      unsigned char exit,
                                      const unsigned char *outBuffer,
                                      unsigned char *inBuffer);

//! Execute JTAG Sequence
//!  @param length   - JTAG sequence length.
//!  @param sequence - Pointer to sequence.
//!  @param inLength - Expected length of input data
//!  @param inBuffer - Returned values
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_ExecuteSequence(unsigned char       length,
                                           const unsigned char *sequence,
                                           unsigned char       inLength,
                                           unsigned char       *inBuffer);

//=====================================================================================================
// Logging

//! Get current log file for messages
//!
USBDM_API
FILE *USBDM_GetLogFile(void);

//! Set log file for messages
//!
USBDM_API
void USBDM_SetLogFile(FILE *fp);

//=====================================================================================================
// ICP functions

//! Set BDM for ICP mode & immediately reboots - used in BDM mode only
//!
//! The BDM resets in ICP mode after this command
//! @note Communication is lost.
//!
USBDM_API
void USBDM_RebootToICP(void);

//
// The following functions are available in ICP mode only
//

//! ICP mode - erase BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to erase
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref USBDM_ErrorCode
//!
//! @note Flash memory alignment requirements should be taken into account.  The
//! range erased should be a multiple of the Flash erase block size.
//!
USBDM_API
USBDM_ErrorCode  USBDM_ICP_Erase( unsigned int addr,
                                  unsigned int count);

//! ICP mode - program BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to program
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_ICP_Program( unsigned int  addr,
                                    unsigned int  count,
                                    unsigned char *data);

//! ICP mode - verify BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to verify
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode  USBDM_ICP_Verify( unsigned int  addr,
                                   unsigned int  count,
                                   unsigned char *data);

//! ICP mode - reboot
//!
//! The BDM does a normal reset
//!
//! Used in ICP mode to reset to normal (BDM) mode.
//! @note Communication is lost.  \n
//!       The BDM will do the usual flash validity checks before entering BDM mode so if flash is not correctly
//!        programmed the BDM may remain in ICP mode.
//!
USBDM_API
void USBDM_ICP_Reboot( void );

#ifdef __cplusplus
// Only available to C++

/*!
 *  Class ICP callback
 *
 *  Used to indicate error status and progress
 */
class ProgressDialogue;

//====================================================================
//! ICP mode - Set ICP Callback function
//!
//! @param icpCallBack_    callback function used to indicate progress
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!
//! @note The callback is cleared after each ICP operation completes
//!
USBDM_API
void USBDM_ICP_SetCallback(ProgressDialogue *icpCallBack);

#ifdef COMMANDLINE
void dll_initialize(HINSTANCE _hDLLInst);
void dll_uninitialize(void);
#endif // COMMANDLINE
#endif //__cplusplus

#if defined __cplusplus
    }
#endif

#endif //_USBDM_API_H_
