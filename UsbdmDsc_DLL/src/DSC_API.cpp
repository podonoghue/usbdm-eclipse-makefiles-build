/*! \file
    \brief MC56F00xx EONCE debugging interface

    \verbatim
    Copyright (C) 2009  Peter O'Donoghue

    Some of the following is based on material from OSBDM-JM60
       Target Interface Software Package
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
   +===============================================================================
   |  17 Apr 2012 | Changed readMemory & writeMemory methods with fixes     V4.9.5
   |   9 Apr 2012 | Added USBDM_ExtendedOptions_t use                       V4.9.4
   |   9 Apr 2012 | Added RESET_DEFAULT to TargetReset()                    V4.9.4
   |  20 Feb 2012 | Check for target power in DSC_Initialise()              V4.9.1
   |  16 Jun 2012 | Minor corrections to logging                            V4.9
   |   1 Jun 2009 | Created
   +===============================================================================
    \endverbatim
*/
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "Common.h"
#include "UsbdmSystem.h"
#include "Names.h"
#include "USBDM_API.h"
#include "USBDM_DSC_API.h"
#include "USBDM_DSC_API_Private.h"
#include "JTAGSequence.h"
#include "Utils.h"

struct EonceRegisterDetails_t {
   uint8_t      address;
   uint8_t      length;
   const char  *name;
};

#ifdef LOG_JTAG
#define MAX_EXECUTION_WAIT (10)  // Time to wait for execution to complete
#else
#define MAX_EXECUTION_WAIT (32) // Time to wait for execution to complete
#endif

static USBDM_ErrorCode saveVolatileTargetRegs(void);
static USBDM_ErrorCode restoreVolatileTargetRegs(void);

// EONCE Command register details
//-------------------------------------------------------------------
#define ONCE_CMD_LENGTH  (8)

// The following bit masks may be combined
#define ONCE_CMD_READ       (1<<7)
#define ONCE_CMD_WRITE      (0<<7)
#define ONCE_CMD_GO         (1<<6)
#define ONCE_CMD_EXIT       (1<<5)

// Register field - some commonly used regs here
#define OPDBR_ADDRESS       (0x04)
#define OTX_ADDRESS         (0x07)   // tx to target OTX/ORX register
#define OTX1_ADDRESS        (0x09)
#define ORX_ADDRESS         (0x0B)   // rx from target OTX/ORX register
#define ORX1_ADDRESS        (0x0D)
#define ONCE_CMD_NOREG      (0x1F)   // used for no register

// EONCE_OCR register details
//--------------------------------------------------------------------
#define OCR_ERLO            (1<<7)
#define OCR_PWU             (1<<5)
#define OCR_DEVEN           (1<<4)
#define OCR_LTE             (1<<3)
#define OCR_ISC_0           (0x00)
#define OCR_ISC_1           (0x01)
#define OCR_ISC_2           (0x02)
#define OCR_ISC_3           (0x03)
#define OCR_ISC_4           (0x04)
#define OCR_ISC_SINGLE_STEP (0x05)
#define OCR_ISC_6           (0x06)
#define OCR_ISC_7           (0x07)

#define DSC_CoreRegisterCount (DSC_LastCoreRegister-DSC_FirstCoreRegister+1)

//==============================================
// Target register details

// Flash
#define HFM_BASE            (0xF400)
#define FM_CLKDIV           (HFM_BASE+0x00)
#define FM_CNFG             (HFM_BASE+0x01)
#define FM_SECLO            (HFM_BASE+0x04)
#define FM_SECHI            (HFM_BASE+0x03)
#define FM_PROT             (HFM_BASE+0x10)
#define FM_USTAT            (HFM_BASE+0x13)
#define FM_CMD              (HFM_BASE+0x14)
#define FM_DATA             (HFM_BASE+0x18)
#define FM_IFR_OPT0         (HFM_BASE+0x1A)
#define FM_TST_SIG          (HFM_BASE+0x1D)


#define FM_CMD_RDARY1       (0x05) // Erase Verify (All Ones)
#define FM_CMD_RDARYM       (0x06) // Data Compress Flash Unit Data
#define FM_CMD_PGM          (0x20) // Word Program
#define FM_CMD_PGERS        (0x40) // Page Erase
#define FM_CMD_MASERS       (0x41) // Mass Erase
#define FM_CMD_RDARYMI      (0x66) // Data Compress Factory Stored Configuration Data

// COP
#define  COP_CTRL           (0x00F140)   // COP
#define  COP_TOUT           (0x00F141)   // COP
#define  COP_CNTR           (0x00F142)   // COP

// GPIOA
#define  GPIOA_PUR          (0x00F180)   // GPIOA
#define  GPIOA_DR           (0x00F181)   // GPIOA
#define  GPIOA_DDR          (0x00F182)   // GPIOA
#define  GPIOA_PER          (0x00F183)   // GPIOA
#define  GPIOA_IENR         (0x00F185)   // GPIOA
#define  GPIOA_IPOLR        (0x00F186)   // GPIOA
#define  GPIOA_IPR          (0x00F187)   // GPIOA
#define  GPIOA_IESR         (0x00F188)   // GPIOA
#define  GPIOA_RAWDATA      (0x00F18A)   // GPIOA
#define  GPIOA_DRIVE        (0x00F18B)   // GPIOA
#define  GPIOA_IFE          (0x00F18C)   // GPIOA
#define  GPIOA_SLEW         (0x00F18D)   // GPIOA

const static EonceRegisterDetails_t eonceRegisterDetails[DSC_CoreRegisterCount] = {
    {0x01,    8,   "ocr"},
    {0x02,   24,   "oscntr"},
    {0x03,   16,   "osr"},
    {0x04,   16,   "opdbr"}, /* 16, 32, or 48 */
    {0x05,    8,   "obase"},
    {0x06,    8,   "otxrxsr"},
    {0x07,   32,   "otx"},
    {0x09,   16,   "otx1"},
    {0x0b,   32,   "orx"},
    {0x0d,   16,   "orx1"},
    {0x0e,   16,   "otbcr"},
    {0x0f,    8,   "otbpr"},
    {0x10,   21,   "otb"},
    {0x11,   24,   "ob0cr"},
    {0x12,   24,   "ob0ar1"},
    {0x13,   32,   "ob0ar2"},
    {0x14,   32,   "ob0msk"},
    {0x15,   16,   "ob0cntr"},
#if 0
    {0x17,   24,   "ob1cr"},
    {0x18,   24,   "ob1ar1"},
    {0x19,   32,   "ob1ar2"},
    {0x1a,   32,   "ob1msk"},
    {0x1b,   16,   "ob1cntr"},

    {0x1d,   24,   "ob2cr"},
    {0x1e,   24,   "ob2ar1"},
    {0x20,   32,   "ob2ar2"},
    {0x21,   32,   "ob2msk"},
    {0x22,   16,   "ob2cntr"},

    {0x24,   24,   "ob3cr"},
    {0x25,   24,   "ob3ar1"},
    {0x26,   32,   "ob3ar2"},
    {0x27,   32,   "ob3msk"},
    {0x28,   16,   "ob3cntr"},
#endif
};

struct targetRegisterDetails_t {
   const char *name;
   unsigned    width;
} ;

static const targetRegisterDetails_t targetRegisterDetails[DSC_CoreRegisterCount] = {
    {"x0",     16},   // X0
    {"y0",     16},   // Y0
    {"y1",     16},   // Y1
    {"a0",     16},   // A0
    {"a1",     16},   // A1
    {"a2",      4},   // A2
    {"b0",     16},   // B0
    {"b1",     16},   // B1
    {"b2",      4},   // B2
    {"c0",     16},   // C0
    {"c1",     16},   // C1
    {"c2",      4},   // C2
    {"d0",     16},   // D0
    {"d1",     16},   // D1
    {"d2",      4},   // D2
    {"omr",    16},   // OMR
    {"sr",     16},   // SR
    {"la",     24},   // LA
    {"la2",    24},   // LA2
    {"lc",     16},   // LC
    {"lc2",    16},   // LC2
    {"hws0",   24},   // HWS0
    {"hws1",   24},   // HWS1
    {"sp",     24},   // SP
    {"n3",     16},   // N3
    {"m01",    16},   // M01
    {"n ",     24},   // N
    {"r0",     24},   // R0
    {"r1",     24},   // R1
    {"r2",     24},   // R2
    {"r3",     24},   // R3
    {"r4",     24},   // R4
    {"r5",     24},   // R5
    {"shm01",  16},   // SHM01
    {"shn",    24},   // SHN
    {"shr0",   24},   // SHR0
    {"shr1",   24},   // SHR1
    {"pc",     21},   // PC
};

typedef const struct sequence_tag {
    int instructionCount;
    uint8_t  sequence[20];
} sequence_type;

// Register reads
// Each sequence writes the given register to otx/otx1
static sequence_type targetReadRegSequence[DSC_CoreRegisterCount] = {
   {1,{3,0xE7,0x7F,0xD4,0x7C,0xFF,0xFF}},   // X0     move.w  X0,X:>>otx1
   {1,{3,0xE7,0x7F,0xD5,0x7C,0xFF,0xFF}},   // Y0     move.w  Y0,X:>>otx1
   {1,{3,0xE7,0x7F,0xD7,0x7C,0xFF,0xFF}},   // Y1     move.w  Y1,X:>>otx1
   {1,{3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   // A0     move.w  A0,X:>>otx1
   {1,{3,0xE7,0x7F,0xD0,0x7C,0xFF,0xFF}},   // A1     move.w  A1,X:>>otx1
   {1,{3,0xE7,0x7F,0xD4,0xFC,0xFF,0xFF}},   // A2     move.w  A2,X:>>otx1
   {1,{3,0xE7,0x7F,0xD7,0xFC,0xFF,0xFF}},   // B0     move.w  B0,X:>>otx1
   {1,{3,0xE7,0x7F,0xD1,0x7C,0xFF,0xFF}},   // B1     move.w  B1,X:>>otx1
   {1,{3,0xE7,0x7F,0xD5,0xFC,0xFF,0xFF}},   // B2     move.w  B2,X:>>otx1
   {2,{1,0x7C,0x20,                         // C0     tfr     C,A
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {2,{1,0x7C,0x20,                         // C1     tfr     C,A
       3,0xE7,0x7F,0xD0,0x7C,0xFF,0xFF}},   //        move.w  A1,X:>>otx1
   {2,{1,0x7C,0x20,                         // C2     tfr     C,A
       3,0xE7,0x7F,0xD4,0xFC,0xFF,0xFF}},   //        move.w  A2,X:>>otx1
   {2,{1,0x7C,0x30,                         // D0     tfr     D,A
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {2,{1,0x7C,0x30,                         // D1     tfr     D,A
       3,0xE7,0x7F,0xD0,0x7C,0xFF,0xFF}},   //        move.w  A1,X:>>otx1
   {2,{1,0x7C,0x30,                         // D2     tfr     D,A
       3,0xE7,0x7F,0xD4,0xFC,0xFF,0xFF}},   //        move.w  A2,X:>>otx1
   {2,{1,0x86,0x9C,                         // OMR    move.w  OMR,A0
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {2,{1,0x86,0x9D,                         // SR     move.w  SR,A0
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {2,{1,0x8C,0x1F,                         // LA     moveu.w LA,R4
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
   {2,{3,0xE4,0x1C,0xDB,0xAD,0xFF,0xBA,     // LA2    move.l  #$ffbadbad,R4
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
   {2,{1,0x8C,0x1E,                         // LC     moveu.w LC,R4
       3,0xE7,0x7F,0xDC,0x7C,0xFF,0xFF}},   //        move.w  R4,X:>>otx1
   {2,{2,0x87,0x4C,0xAB,0xAD,               // LC2    moveu.w  #$abad,R4
       3,0xE7,0x7F,0xDC,0x7C,0xFF,0xFF}},   //        move.w  R4,X:>>otx1
   {2,{3,0xE4,0x1C,0xDB,0xAD,0xFF,0xBA,     // HWS0   move.l  #$ffbadbad,R4
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
   {2,{3,0xE4,0x1C,0xDB,0xAD,0xFF,0xBA,     // HWS1   move.l  #$ffbadbad,R4
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
   {2,{1,0x81,0xBC,                         // SP     tfra    SP,R4
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
   {2,{1,0x86,0x99,                         // N3     move.w  N3,A0
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {2,{1,0x86,0x9A,                         // M01    move.w  M01,A0
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF}},   //        move.w  A0,X:>>otx1
   {1,{3,0xE3,0x7F,0xDE,0x7D,0xFF,0xFF}},   // N      move.l  N,X:>>otx
   {1,{3,0xE3,0x7F,0xD8,0x7D,0xFF,0xFF}},   // R0     move.l  R0,X:>>otx
   {1,{3,0xE3,0x7F,0xD9,0x7D,0xFF,0xFF}},   // R1     move.l  R1,X:>>otx
   {1,{3,0xE3,0x7F,0xDA,0x7D,0xFF,0xFF}},   // R2     move.l  R2,X:>>otx
   {1,{3,0xE3,0x7F,0xDB,0x7D,0xFF,0xFF}},   // R3     move.l  R3,X:>>otx
   {1,{3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   // R4     move.l  R4,X:>>otx
   {1,{3,0xE3,0x7F,0xDD,0x7D,0xFF,0xFF}},   // R5     move.l  R5,X:>>otx
   {4,{1,0xE7,0x06,                         // SHM01  swap    shadows
       1,0x86,0x9A,                         //        move.w  M01,A0
       3,0xE7,0x7F,0xD6,0xFC,0xFF,0xFF,     //        move.w  A0,X:>>otx1
       1,0xE7,0x06}},                       //        swap    shadows
   {5,{1,0xE7,0x06,                         // SHN    swap    shadows
       3,0xE3,0x7F,0xDE,0x7D,0xFF,0xFF,     //        move.l  N,X:>>otx
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x06}},                       //        swap    shadows
   {5,{1,0xE7,0x06,                         // SHR0   swap    shadows
       3,0xE3,0x7F,0xD8,0x7D,0xFF,0xFF,     //        move.l  R0,X:>>otx
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x06}},                       //        swap    shadows
   {5,{1,0xE7,0x06,                         // SHR1   swap    shadows
       3,0xE3,0x7F,0xD9,0x7D,0xFF,0xFF,     //        move.l  R1,X:>>otx
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x00,                         //        nop
       1,0xE7,0x06}},                       //        swap    shadows
   {2,{1,0xE7,0x16,                         // PC     move.l  PC,R4  // must be R4!
       3,0xE3,0x7F,0xDC,0x7D,0xFF,0xFF}},   //        move.l  R4,X:>>otx
};
// Register Writes
// These write a value in R4 into the given register
static sequence_type targetWriteRegSequence[DSC_CoreRegisterCount] = {
   {1,{1,0x84,0x0C,}},     // X0    move.w  R4,X0
   {1,{1,0x85,0x0C,}},     // X1    move.w  R4,Y0
   {1,{1,0x87,0x0C,}},     // X2    move.w  R4,Y1
   {1,{1,0x86,0x8C,}},     // A0    move.w  R4,A0
   {1,{1,0x80,0x8C,}},     // A1    move.w  R4,A1
   {1,{1,0x84,0x8C,}},     // A2    move.w  R4,A2
   {1,{1,0x87,0x8C,}},     // B0    move.w  R4,B0
   {1,{1,0x81,0x8C,}},     // B1    move.w  R4,B1
   {1,{1,0x85,0x8C,}},     // B2    move.w  R4,B2
   {3,{1,0x7C,0x20,        // C0    tfr     C,A
       1,0x86,0x8C,        //       move.w  R4,A0
       1,0x7D,0x00,}},     //       tfr     A,C
   {3,{1,0x7C,0x20,        // C1    tfr     C,A
       1,0x80,0x8C,        //       move.w  R4,A1
       1,0x7D,0x00,}},     //       tfr     A,C
   {3,{1,0x7C,0x20,        // C2    tfr     C,A
       1,0x84,0x8C,        //       move.w  R4,A2
       1,0x7D,0x00,}},     //       tfr     A,C
   {3,{1,0x7C,0x30,        // D0    tfr     D,A
       1,0x86,0x8C,        //       move.w  R4,A0
       1,0x7D,0x80,}},     //       tfr     A,D
   {3,{1,0x7C,0x30,        // D1    tfr     D,A
       1,0x80,0x8C,        //       move.w  R4,A1
       1,0x7D,0x80,}},     //       tfr     A,D
   {3,{1,0x7C,0x30,        // D2    tfr     D,A
       1,0x84,0x8C,        //       move.w  R4,A2
       1,0x7D,0x80,}},     //       tfr     A,D
   {1,{1,0x8C,0x8C,}},     // OMR   moveu.w R4,OMR
   {3,{1,0x8D,0x8C,        // SR    moveu.w R4,SR
       1,0xE7,0x00,        //       nop
       1,0xE7,0x00,}},     //       nop
   {1,{1,0x8F,0x8C,}},     // LA    moveu.w R4,LA
   {1,{1,0xE7,0x00,}},     // LA2   nop
   {1,{1,0x8E,0x8C,}},     // LC    moveu.w R4,LC
   {1,{1,0xE7,0x00,}},     // LC2   nop
   {1,{1,0xE7,0x00,}},     // HWS0  nop
   {1,{1,0xE7,0x00,}},     // HWS1  nop
   {1,{1,0x81,0xAB,}},     // SP    tfra    R4,SP
   {1,{1,0x89,0x8C,}},     // N3    moveu.w R4,N3
   {1,{1,0x8A,0x8C,}},     // M01   moveu.w R4,M01
   {1,{1,0x81,0xAA,}},     // N     tfra    R4,N
   {1,{1,0x81,0xA0,}},     // R0    tfra    R4,R0
   {1,{1,0x81,0xA1,}},     // R1    tfra    R4,R1
   {1,{1,0x81,0xA2,}},     // R2    tfra    R4,R2
   {1,{1,0x81,0xA3,}},     // R3    tfra    R4,R3
   {1,{1,0xE7,0x00,}},     // R4    nop
   {1,{1,0x81,0xA9,}},     // R5    tfra    R4,R5
   {5,{1,0xE7,0x06,        // SHM01 swap    shadows
       1,0x8A,0x8C,        //       moveu.w R4,M01
       1,0xE7,0x00,        //       nop
       1,0xE7,0x00,        //       nop
       1,0xE7,0x06,}},     //       swap    shadows
   {5,{1,0xE7,0x06,        // SHN   swap    shadows
       1,0x81,0xAA,        //       tfra    R4,N
       1,0xE7,0x00,        //       nop
       1,0xE7,0x00,        //       nop
       1,0xE7,0x06,}},     //       swap    shadows
   {5,{1,0xE7,0x06,        // SHR0  swap    shadows
       1,0x81,0xA0,        //       tfra    R4,R0
       1,0xE7,0x00,        //       nop
       1,0xE7,0x00,        //       nop
       1,0xE7,0x06,}},     //       swap    shadows
   {5,{1,0xE7,0x06,        // SHR1  swap    shadows
       1,0x81,0xA1,        //       tfra    R4,R1
       1,0xE7,0x00,        //       nop
       1,0xE7,0x00,        //       nop
       1,0xE7,0x06,}},     //       swap    shadows
   {1,{1,0xE7,0x17,}},     // PC    move.l  R4,PC
};

//! Registers saved when BDM is active
//!
static struct {
   bool valid;
   uint32_t A0;
   uint32_t A1;
   uint32_t A2;
   uint32_t R0;
   uint32_t R4;
//   uint32_t PC;
   uint16_t X0;
} volatileRegs = {false};

//! BDM JTAG Cache state
enum CacheState_t {CacheFree, MemAccessCached} ;

//! BDM JTAG Cache state
static CacheState_t cacheState = CacheFree;

// Cached core IDCODE
static uint32_t coreIdcode = 0xFFFFFFFF;

//Aliases for Cached routines
#define JTAG_SUB_EXECUTE     JTAG_SUBA       //!< Execute a series of target instructions (firmware implemented)
#define JTAG_SUB_MEM_READ    JTAG_SUBB       //!< Read a block from target memory
#define JTAG_SUB_MEM_WRITE   JTAG_SUBC       //!< Write a block to target memory
#define JTAG_CALL_EXECUTE    JTAG_CALL_SUBA
#define JTAG_CALL_MEM_READ   JTAG_CALL_SUBB
#define JTAG_CALL_MEM_WRITE  JTAG_CALL_SUBC

static USBDM_ErrorCode loadCache(CacheState_t loadType);

//! Buffer for JTAG sequences
static uint8_t JTAGSequence[300];

//! Information describing the interface
//!
static dscInfo_t dscInfo = {sizeof(dscInfo_t), 100, 100};

//! BDM options
//!
static USBDM_ExtendedOptions_t bdmOptions;

//! Obtain string describing the given register's name
//!
//! @param regNo - The register number
//!
//! @return - ptr to static string describing the register
//!
const char *getRegisterName(DSC_Registers_t regNo) {
uint8_t regIndex;

   if ((regNo >= DSC_FirstCoreRegister) && (regNo <= DSC_LastCoreRegister)) {
      regIndex         = regNo - DSC_FirstCoreRegister;
      return targetRegisterDetails[regIndex].name;
   }
   else if ((regNo >= DSC_FirstONCERegister) && (regNo <= DSC_LastONCERegister)) {
      regIndex         = regNo - DSC_FirstONCERegister;
      return eonceRegisterDetails[regIndex].name;
   }
   else if (regNo == DSC_RegIDCODE) {
      return "IDCODE";
   }
   else if (regNo == DSC_GdiStatus) {
      return "GdiStatus";
   }
   return "Illegal register";
}

//! Obtain size of given register in bits
//!
//! @param regNo - The register number
//!
//! @return - size of the register in bits
//!
unsigned getRegisterSize(DSC_Registers_t regNo) {
uint8_t regIndex;

   if ((regNo >= DSC_FirstCoreRegister) && (regNo <= DSC_LastCoreRegister)) {
      regIndex = regNo - DSC_FirstCoreRegister;
      return targetRegisterDetails[regIndex].width;
   }
   else if ((regNo >= DSC_FirstONCERegister) && (regNo <= DSC_LastONCERegister)) {
      regIndex = regNo - DSC_FirstONCERegister;
      return eonceRegisterDetails[regIndex].length;
   }
   else if (regNo == DSC_RegIDCODE) {
      return 32;
   }
   return 0;
}

//! Converts an OnceStatus_t to a string for debug
//!
USBDM_DSC_API
const char *DSC_GetOnceStatusName(OnceStatus_t status) {
   switch (status) {
      case executeMode        : return "executeMode";
      case stopMode           : return "stopMode";
      case externalAccessMode : return "externalAccessMode";
      case debugMode          : return "debugMode";
      default                 : return "illegal";
   }
}

////! Converts ?? to a string for debug
////!
//const char *getOSCRText(uint32_t value) {
//static char buff[20];
//static const char *mode[] = {"Running", "Wait/Stop", "BusWait", "Debug"};
//   snprintf(buff, sizeof(buff), "%s,%s%s%s%s%s%s",
//               mode[(value>>6)&0x03],
//               (value&(1<<5))?"Cache-hit,":"",
//               (value&(1<<4))?"Trace,":"",
//               (value&(1<<3))?"Break,":"",
//               (value&(1<<2))?"Debug,":"",
//               (value&(1<<1))?"Interrupts-on,":"",
//               (value&(1<<0))?"Trace-on,":""
//              );
//   return buff;
//}

const char *getOCRString(uint32_t regvalue) {
static char buffer[100];
static const char *names[] = {"ISC_NONE", "ISC1?", "ISC2?", "ISC3?",
                              "ISC4?", "ISC_SINGLE_STEP", "ISC6?", "ISC7?"};

   snprintf(buffer, sizeof(buffer), "%s%s%s%s%s",
               (regvalue&OCR_ERLO)?"ERLO|":"",
               (regvalue&OCR_PWU)?"PWU|":"",
               (regvalue&OCR_DEVEN)?"DEVEN|":"",
               (regvalue&OCR_LTE)?"LTE|":"",
               names[regvalue&OCR_ISC_MASK]
               );
   return buffer;
}

const char *getOSRString(uint32_t regvalue) {
static char buffer[100];
   snprintf(buffer, sizeof(buffer), "%s%s%s",
               (regvalue&OSR_CZ)?"CounterZero|":"",
               (regvalue&OSR_CS)?"CounterStopped|":"",
               (regvalue&OSR_TBFL)?"TraceBufferFull":""
               );
   return buffer;
}

const char *getKnownAddress(MemorySpace_t memorySpace, uint32_t address) {
static char buffer[40];
MemorySpace_t memSpace = (MemorySpace_t)(memorySpace&MS_SPACE);
MemorySpace_t memSize  = (MemorySpace_t)(memorySpace&MS_SIZE);

   if (memSpace == MS_Data)
      switch (address) {
         case FM_CLKDIV:     return   "X:HFM_CLKD";
         case FM_CNFG:       return   "X:HFM_CR";
         case FM_SECHI:      return   "X:HFM_SECHI";
         case FM_SECLO:      return   "X:HFM_SECLO";
         case FM_PROT:       return   "X:HFM_PROT";
         case FM_USTAT:      return   "X:HFM_USTAT";
         case FM_CMD:        return   "X:HFM_CMD";
         case FM_DATA:       return   "X:HFM_DATA";
         case FM_IFR_OPT0:   return   "X:HFM_IFR_OPT0";
         case COP_CTRL:      return   "X:COP_CTRL";
         case COP_CNTR:      return   "X:COP_CNTR";
         case COP_TOUT:      return   "X:COP_TOUT";
         case GPIOA_PER:     return   "X:GPIOA_PER";
         default:
            break;
      }
   const char *spaceName = "?:";
   switch (memSpace) {
   case MS_Program :
      spaceName = "P:";
      break;
   case MS_Data:
      spaceName = "X:";
      break;
   default:
      spaceName = "?:";
      break;
   }
   const char *sizeName = "?:";
   switch (memSize) {
   case MS_Byte :
      sizeName = "1:";
      break;
   case MS_Word:
      sizeName = "2:";
      break;
   case MS_Long:
      sizeName = "4:";
      break;
   default:
      break;
   }
   snprintf(buffer, sizeof(buffer), "%s%s%6.6X", spaceName, sizeName, address);
   return buffer;
}

//! Read ONCE register
//!
//! @param regNo    - Register number
//! @param regValue - Value from register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode readONCEReg(DSC_Registers_t regNo, unsigned long *regValue) {
USBDM_ErrorCode rc;
JTAG32 regData(0,32);

   if ((regNo<DSC_FirstONCERegister) || (regNo>DSC_LastONCERegister))
      return BDM_RC_ILLEGAL_PARAMS;

   uint8_t regIndex       = regNo - DSC_FirstONCERegister;
   uint8_t command        = eonceRegisterDetails[regIndex].address|ONCE_CMD_READ;
   uint8_t length         = eonceRegisterDetails[regIndex].length;

   uint8_t readRegisterSequence[] = {
      (uint8_t)JTAG_MOVE_DR_SCAN,                          // Access ONCE (DR-CHAIN)
      (uint8_t)JTAG_SET_EXIT_SHIFT_DR,
      (uint8_t)JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), command, // ONCE Command to Read register + RegNo
      (uint8_t)JTAG_SET_EXIT_IDLE,
      (uint8_t)JTAG_SHIFT_IN_Q(length),                    // Shift-in data value
      (uint8_t)JTAG_END
   };
   // Read EONCE register
   rc = executeJTAGSequence(sizeof(readRegisterSequence), readRegisterSequence,
                            BITS_TO_BYTES(length), regData.getData(length));
   if (rc != BDM_RC_OK)
      return rc;
   *regValue = (uint32_t)regData;
//   if (regNo == DSC_RegOCR) {
//      log.print("(%s) => %s (%s)\n", getRegisterName(regNo), getOCRString(*regValue), regData.toString());
//   }
//   else if (regNo == DSC_RegOSR) {
//      log.print("(%s) => %s (%s)\n", getRegisterName(regNo), getOSRString(*regValue), regData.toString());
//   }
//   else {
//      log.print("(%s) => %s\n", getRegisterName(regNo), regData.toString());
//   }
   return BDM_RC_OK;
}

//! Write ONCE register
//!
//! @param regNo     - Register number
//! @param modifiers - Modifier for command byte to ONCE register
//! @param regValue  - Value for register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode writeONCEReg(DSC_Registers_t regNo, uint32_t regValue, uint8_t modifiers) {
   LOGGING_Q;

   if ((regNo<DSC_FirstONCERegister) || (regNo>DSC_LastONCERegister)) {
      log.print("(%d, %s) => \n", regNo, getRegisterName(regNo));
      return BDM_RC_ILLEGAL_PARAMS;
   }
   uint8_t regIndex       = regNo - DSC_FirstONCERegister;
   uint8_t command        = eonceRegisterDetails[regIndex].address|ONCE_CMD_WRITE|modifiers;
   uint8_t length         = eonceRegisterDetails[regIndex].length;
//   const char *name  = eonceRegisterDetails[regIndex].name;
   JTAG32 regData(regValue,length);

//   if (regNo == DSC_RegOCR) {
//      log.print("(%s) <= %s (%s)\n", getRegisterName(regNo), getOCRString(regValue), regData.toString());
//   }
//   else {
//      log.print("(%s) <= (0x%X) %s\n", name, (uint32_t)regData, regData.toString());
//   }
   uint8_t writeRegisterSequence[] = {
         (uint8_t)JTAG_MOVE_DR_SCAN,            // Write to ONCE (DR-CHAIN)
         (uint8_t)JTAG_SET_EXIT_SHIFT_DR,
         (uint8_t)JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), command, // ONCE command - Write register+RegNo+modifier
         (uint8_t)JTAG_SET_EXIT_IDLE,
         (uint8_t)JTAG_SHIFT_OUT_Q(length),     // Shift-out data value
/* 6 */  (uint8_t)JTAG_NOP,   // 4-byte space for value to write (1-32 bits)
         (uint8_t)JTAG_NOP,
         (uint8_t)JTAG_NOP,
         (uint8_t)JTAG_NOP,
         (uint8_t)JTAG_END, // Terminate sequence
   };
   // Copy value to write
   regData.copyToArray(writeRegisterSequence+6);

   // Write EONCE register
   return executeJTAGSequence(sizeof(writeRegisterSequence), writeRegisterSequence,
                              0, NULL);
}

#define TARGET_STATUS_EXECUTE   (0x01)
#define TARGET_STATUS_STOP      (0x05)
#define TARGET_STATUS_EX_ACCESS (0x09)
#define TARGET_STATUS_DEBUG     (0x0D)

//! Converts the status returned from the Core JTAG
//! into OnceStatus_t values
//!
OnceStatus_t convertStatus(uint8_t coreStatus) {
   switch(coreStatus) {
      case TARGET_STATUS_EXECUTE:   return executeMode;
      case TARGET_STATUS_STOP:      return stopMode;
      case TARGET_STATUS_EX_ACCESS: return externalAccessMode;
      case TARGET_STATUS_DEBUG:     return debugMode;
      default:                      return unknownMode;
   }
}

#ifdef LOG_JTAG
   #define TARGET_DEBUG_REQUEST_RECOVERY_TIME (1)
#else
   #define TARGET_DEBUG_REQUEST_RECOVERY_TIME (100)
#endif

//! Set Core JTAG-IR to DebugRequest
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode targetDebugRequest(OnceStatus_t *status) {
   LOGGING_Q;

   static const uint8_t requestDebugSequence[] = {
      JTAG_MOVE_IR_SCAN,    // Write debug request command to IR
      JTAG_SET_EXIT_IDLE,
      JTAG_SHIFT_IN_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_DEBUG_REQUEST_COMMAND,
      JTAG_END,
   };
   JTAG32 coreStatus(0,JTAG_CORE_COMMAND_LENGTH);
   USBDM_ErrorCode rc;

   // Send Debug Request to core
   rc = executeJTAGSequence(sizeof(requestDebugSequence), requestDebugSequence,
                            BITS_TO_BYTES(JTAG_CORE_COMMAND_LENGTH),
                            coreStatus.getData(JTAG_CORE_COMMAND_LENGTH));
   *status = convertStatus((uint32_t)coreStatus);
   log.print("Core status = %s\n", DSC_GetOnceStatusName(*status));
   return rc;
}

//! Release DebugRequest to target (set enable ONCE)
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode targetDebugRelease(OnceStatus_t *status) {
   LOGGING_Q;
   static const uint8_t releaseDebugSequence[] = {
      JTAG_MOVE_IR_SCAN,    // Write debug request command to IR
      JTAG_SET_EXIT_IDLE,
      JTAG_SHIFT_IN_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,
      JTAG_END,
   };
   JTAG32 coreStatus(0,JTAG_CORE_COMMAND_LENGTH);
   USBDM_ErrorCode rc;

   // Send Debug Request to core
   rc = executeJTAGSequence(sizeof(releaseDebugSequence), releaseDebugSequence,
                            BITS_TO_BYTES(JTAG_CORE_COMMAND_LENGTH),
                            coreStatus.getData(JTAG_CORE_COMMAND_LENGTH));
   *status = convertStatus((uint32_t)coreStatus);
   log.print("Core status = %s\n", DSC_GetOnceStatusName(*status));
   return rc;
}

//! Send DebugRequest to target
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode forceDebugRequest(void) {
   LOGGING_Q;
   OnceStatus_t    status;
   USBDM_ErrorCode rc;
   int             iterationLimit = 20;

   do {
      // Send Debug Request to core
      rc = targetDebugRequest(&status);
   } while (((rc == BDM_RC_OK) && (status != debugMode)) && (iterationLimit-->0));
   if (((rc != BDM_RC_OK) || (status != debugMode))) {
      log.print("targetDebugRequest(): Failed!\n");
      if (rc == BDM_RC_OK) {
         rc = BDM_RC_NO_CONNECTION;
      }
   }
   rc = targetDebugRelease(&status);
   if (((rc != BDM_RC_OK) || (status != debugMode))) {
      log.print("targetDebugRelease(): Failed!\n");
      if (rc == BDM_RC_OK) {
         rc = BDM_RC_NO_CONNECTION;
      }
   }
   return rc;
}

//! Enable ONCE in JTAG chain & obtain target status
//!
//! @param status - Target status from JTAG command
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode enableONCE(OnceStatus_t *status) {
   LOGGING_Q;
   static const uint8_t enableEONCESequence[] = {
      JTAG_MOVE_IR_SCAN,                   // Write enable EONCE command to IR
      JTAG_SET_EXIT_IDLE,
      JTAG_SHIFT_IN_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,
      JTAG_END
   };
   JTAG32 coreStatus(0,JTAG_CORE_COMMAND_LENGTH);
   USBDM_ErrorCode rc;
   static OnceStatus_t lastStatus = unknownMode;
   bool statusChange;

   *status = unknownMode;
   rc = executeJTAGSequence(sizeof(enableEONCESequence), enableEONCESequence,
                            BITS_TO_BYTES(JTAG_CORE_COMMAND_LENGTH),
                            coreStatus.getData(JTAG_CORE_COMMAND_LENGTH));
   if (rc != BDM_RC_OK) {
      log.error("Failed: executeJTAGSequence() failed\n");
      return rc;
   }

   *status = convertStatus((uint32_t)coreStatus);
   statusChange = *status != lastStatus;
   lastStatus = *status;

   if (statusChange) {
      log.print("Core status change => %s\n", DSC_GetOnceStatusName(*status));
   }
   switch(*status) {
      case executeMode :
      case externalAccessMode:
         volatileRegs.valid = false;
         return BDM_RC_OK;
      case debugMode:
      case stopMode:
//         if (statusChange)
//            saveVolatileTargetRegs();
         return BDM_RC_OK;
      default:
      case unknownMode:
         log.print("Failed: status unknown\n");
         return BDM_RC_NO_CONNECTION;
   }
   return BDM_RC_OK;
}

//! Enable ONCE in JTAG chain & obtain target status
//!
//! @param status - Target status from JTAG command
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetStatus(OnceStatus_t *status) {
   LOGGING_Q;

   USBDM_ErrorCode rc = enableONCE(status);
   if (rc == BDM_RC_OK) {
      log.print("=> %s\n", DSC_GetOnceStatusName(*status));
   }
   else {
      log.print("Failed, rc = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}

#ifdef LOG_JTAG
   #define TEST_LOGIC_RESET_RECOVERY_NOPS (1)
#else
   #define TEST_LOGIC_RESET_RECOVERY_NOPS (50) // ~1.16 ms
#endif

//! Read IDCODE from JTAG TAP
//!
//! @param idCode   - 32-bit IDCODE returned from TAP
//! @param resetTAP - Optionally resets the TAP to RUN-TEST/IDLE before reading IDCODE
//!                   This will enable the MASTER TAP!
//!
//! @note - resetTAP=true will enable the Master TAP & disable the Code TAP
//! @note - Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_ErrorCode readIDCODE(uint32_t *idCode, uint8_t commandRegLength, int resetTAP) {
   LOGGING_Q;
   uint8_t readCoreIdCodeSequence[] = {
      (uint8_t)JTAG_TEST_LOGIC_RESET,                          // Reset TAP
   // (uint8_t)  JTAG_REPEAT_Q(TEST_LOGIC_RESET_RECOVERY_NOPS), // ~2.26ms
   // (uint8_t)     JTAG_NOP,
   // (uint8_t)  JTAG_END_REPEAT,
      (uint8_t)JTAG_MOVE_IR_SCAN,                              // Write IDCODE command to IR
      (uint8_t)JTAG_SET_EXIT_SHIFT_DR,
      (uint8_t)JTAG_SHIFT_OUT_Q(commandRegLength), (uint8_t)JTAG_IDCODE_COMMAND,
      (uint8_t)JTAG_SET_EXIT_IDLE,                             // Read IDCODE from DR
      (uint8_t)JTAG_SHIFT_IN_Q(32),
      (uint8_t)JTAG_END
   };

   JTAG32 idcode(0,32);
   USBDM_ErrorCode rc;

   if (resetTAP)
      readCoreIdCodeSequence[0] = JTAG_TEST_LOGIC_RESET;
   else
      readCoreIdCodeSequence[0] = JTAG_NOP;

   rc = executeJTAGSequence(sizeof(readCoreIdCodeSequence), readCoreIdCodeSequence,
                            4, idcode.getData(32), false);
   if (rc != BDM_RC_OK) {
      log.print("Failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   log.print("IDCODE = %s\n", idcode.toString());
   *idCode = idcode;

   return rc;
}

//! Enable the Core TAP using the TLM
//!
//! @note - Resets the TAPs before enabling Core TAP
//! @note - It appears that the sequence must end with a EXIT_SHIFT_DR?
//! @note Leaves Core TAP in RUN-TEST/IDLE to TLM action??
//!
USBDM_ErrorCode enableCoreTAP() {
   LOGGING_E;

   JTAG32 idcode(0,32);
   const static uint8_t selectCoreTapSequence[] = {
      JTAG_TEST_LOGIC_RESET,               // Reset TAP
      JTAG_REPEAT_16(TEST_LOGIC_RESET_RECOVERY_NOPS), // ~2.26ms
         JTAG_NOP,
      JTAG_END_REPEAT,
      JTAG_MOVE_IR_SCAN,                   // Write TLM command to IR
      JTAG_SET_EXIT_SHIFT_DR,
      JTAG_SHIFT_OUT_Q(JTAG_MASTER_COMMAND_LENGTH), JTAG_TLM_SELECT_COMMAND,
      JTAG_SET_EXIT_IDLE,               // Select Core TAP
      JTAG_SHIFT_OUT_Q(TLM_REGISTER_LENGTH), TLM_SLAVE_SELECT_MASK,
      JTAG_END
   };
   USBDM_ErrorCode rc;
   rc = executeJTAGSequence(sizeof(selectCoreTapSequence), selectCoreTapSequence,
                            0, NULL);
   if (rc != BDM_RC_OK) {
      log.print("Failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   return rc;
}

#if 0
// The following JTAG routine will execute a sequence of instructions on the target
// Optimized for speed rather than size!
// For efficiency reasons this routine has been replaced by hard coded
// executeTargetInstructionSequence() function in BDM firmware
static const uint8_t executeTargetInstructionSequence[] = {
         // Execute an instruction consisting of M words
   /* 0*/JTAG_SUBD,                    // Parameters = Instruction length in words, instr. words...
               // Enable ONCE & mode to SHIFT-DR
   /* 1*/      JTAG_SET_EXIT_SHIFT_DR,
   /* 2*/      JTAG_SHIFT_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,

               // Each word of instruction but last
   /* 4*/      JTAG_REPEAT_DP,         // M - For each word of instruction
   /* 5*/         JTAG_IF_ITER_NEQ_Q(1), // Not last word
   /* 7*/            JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), OPDBR_ADDRESS|ONCE_CMD_WRITE,
   /* 9*/            JTAG_SHIFT_OUT_DP, 16,  // Instruction word from outDataPtr
   /*11*/         JTAG_END_IF,
   /*12*/      JTAG_END_REPEAT,

               // Last word of instruction
   /*13*/      JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), OPDBR_ADDRESS|ONCE_CMD_WRITE|ONCE_CMD_GO,
   /*15*/      JTAG_SET_EXIT_SHIFT_IR, // Exit SCAN-DR & enter SCAN-IR after last word
   /*16*/      JTAG_SHIFT_OUT_DP, 16,  // Instruction word from outDataPtr

               // Dummy read Target status
   /*18*/      JTAG_SHIFT_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,
   /*20*/      JTAG_SHIFT_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,

               // Wait for instruction execution to complete
   /*22*/      JTAG_REPEAT_Q(MAX_EXECUTION_WAIT),         // Wait for execution to complete
   /*24*/         JTAG_SHIFT_IN_OUT_VARA, JTAG_CORE_COMMAND_LENGTH, CORE_ENABLE_ONCE_COMMAND, // Read Target status
   /*27*/         JTAG_IF_VARA_EQ_Q(TARGET_STATUS_DEBUG),
                     JTAG_RETURN,
   /*31*/         JTAG_END_IF,
   /*32*/      JTAG_END_REPEAT,

               // Move TAP to RUN-TEST/IDLE here as setting ERROR will abort execution
   /*33*/      JTAG_SET_EXIT_IDLE,
   /*34*/      JTAG_SHIFT_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND,

               // Determine error reason
   /*36*/      JTAG_IF_VARA_EQ_Q(TARGET_STATUS_EXECUTE),   // Target executing?
   /*38*/         JTAG_SET_ERROR, BDM_RC_TARGET_BUSY,      //   Set error & exit
   /*40*/      JTAG_END_IF,
   /*40*/      JTAG_IF_VARA_EQ_Q(TARGET_STATUS_EX_ACCESS), // Target doing external access?
   /*42*/         JTAG_SET_ERROR, BDM_RC_TARGET_BUSY,      //   Set error & exit
   /*44*/      JTAG_END_IF,
   /*45*/      JTAG_IF_VARA_EQ_Q(TARGET_STATUS_STOP),      // Target stopped?
   /*47*/         JTAG_SET_ERROR, BDM_RC_TARGET_BUSY,      //   Set error & exit
   /*49*/      JTAG_END_IF,
   /*50*/      JTAG_SET_ERROR, BDM_RC_NO_CONNECTION,       //   Set error & exit
   /*52*/JTAG_END_SUB,

         // Execute a sequence of N instructions
   /*53*/JTAG_SUBA,
   /*54*/   JTAG_MOVE_IR_SCAN,         // Move to SCAN-IR
   /*55*/   JTAG_REPEAT_DP,            // N times
   /*56*/      JTAG_CALL_SUBD,
   /*57*/   JTAG_END_REPEAT,

            // Leave TAP in RUN-TEST/IDLE
   /*58*/   JTAG_SET_EXIT_IDLE,
   /*59*/   JTAG_SHIFT_OUT_Q(JTAG_CORE_COMMAND_LENGTH), CORE_ENABLE_ONCE_COMMAND, // Dummy command
   /*61*/JTAG_END_SUB,

   /*62*/JTAG_SAVE_SUB,  // Save subroutines
   /*63*/JTAG_END,

//       Parameters taken from DP
// /*50*/   2, // # of instructions
//          // Length  Instruction data...
// /*51*/        2,    0x87,0x44, 0xAA,0x34,
// /*56*/        3,    0xE7,0x7F, 0xD4,0x7C, 0xFF,0xFF,
};

#endif

static bool DSC_InitialiseDone = false;

//! Initialise
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_Initialise(void) {
   LOGGING_E;

   USBDM_ErrorCode rc = BDM_RC_OK;

   DSC_InitialiseDone = false;

   // Check for target power
   USBDMStatus_t status;
   rc = USBDM_GetBDMStatus(&status);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if ((status.power_state != BDM_TARGET_VDD_EXT)&&(status.power_state != BDM_TARGET_VDD_INT)) {
      return BDM_RC_VDD_NOT_PRESENT;
   }

   volatileRegs.valid = false;

   cacheState = CacheFree;
   rc = loadCache(MemAccessCached);
   if (rc != BDM_RC_OK) {
      return rc;
   }

   DSC_GetInfo(NULL);

   bdmOptions.size = sizeof(bdmOptions);
   bdmOptions.targetType = T_MC56F80xx;
   rc = USBDM_GetExtendedOptions(&bdmOptions);

   if (rc != BDM_RC_OK) {
      return rc;
   }
   DSC_InitialiseDone = true;
   return rc;
}

//!  Execute a series of target instructions
//!
//! @param instructionSequence - Instruction sequence in the following form:\n
//!      - [0] L        - # of instructions
//!      - [1] M        - # of words in instruction
//!      - [2..2*M+1]   - code for instruction
//!      - The above two lines may be repeated  a further (L-1) times
//!
//! @note - These instructions are executed one at a time using the ONCE interface!
//! @note - Assumes JTAG_SUB_EXECUTE is already present or hard-coded in BDM
//! @note - Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note - Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
USBDM_ErrorCode executeTargetInstruction(uint8_t *instructionSequence) {
   LOGGING;

   static const uint8_t callSequence[] = {
   // Main
   /*41*/JTAG_CALL_EXECUTE,
   /*42*/JTAG_END,
   };
   uint8_t *copyPtr  = JTAGSequence;
   uint8_t *sequence = instructionSequence;

   memcpy(copyPtr, callSequence, sizeof(callSequence));
   copyPtr += sizeof(callSequence);

   uint8_t instructionCount = *sequence++;
   *copyPtr++ = instructionCount;

   while (instructionCount-- > 0) {
      uint8_t instructionLength = *sequence++;
      *copyPtr++ = instructionLength; // Copy instruction length
      if ((copyPtr+2*instructionLength)>= JTAGSequence+sizeof(JTAGSequence))
         return BDM_RC_JTAG_TOO_LARGE;
      while(instructionLength-- > 0){
         *copyPtr++ = *sequence++; // Copy instruction word
         *copyPtr++ = *sequence++;
      }
   }
   return executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence, 0, NULL);
}

//!  Execute a series of target instructions
//!
//! @param instructionSequence - Instruction sequence in the following form:\n
//!      - [0] L        - # of instructions
//!      - [1] M        - # of words in 1st instruction
//!      - [2..2*M+1]   - code for 1st instruction
//!      - The above two lines may be repeated  a further (L-1) times
//!
//! @note - These instructions are executed one at a time using the ONCE interface!
//! @note - Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note - Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
USBDM_ErrorCode testTargetExecutionSpeed(void) {
   LOGGING_E;

   static const uint8_t testSequence[] = {
   // Main
      JTAG_SAVE_OUT_DP_VARC,
      JTAG_REPEAT_16(254),
         JTAG_RESTORE_DP_VARC,
         JTAG_CALL_EXECUTE,
      JTAG_END_REPEAT,
   JTAG_END,
   5,1,0xE7,0x06,                         // SHR0   swap    shadows
     3,0xE3,0x7F,0xD8,0x7D,0xFF,0xFF,     //        move.l  R0,X:>>otx
     1,0xE7,0x00,                         //        nop
     1,0xE7,0x00,                         //        nop
     1,0xE7,0x06,                         //        swap    shadows
//   1,1,0xE7,0x00,  //        nop
   };
   return executeJTAGSequence(sizeof(testSequence), testSequence, 0, NULL);
}

#if 0
static void printVolatileRegs(void) {
   log.print("   A0 => %4.4X\n", volatileRegs.A0);
   log.print("   A1 => %4.4X\n", volatileRegs.A1);
   log.print("   A2 => %1.1X\n", volatileRegs.A2);
   log.print("   PC => %6.6X\n", volatileRegs.PC);
   log.print("   R0 => %6.6X\n", volatileRegs.R0);
   log.print("   R4 => %6.6X\n", volatileRegs.R4);
}
#endif

static uint8_t copyReadRegInfo(DSC_Registers_t regNo, uint8_t *&copyPtr) {
   uint8_t registerSize     = getRegisterSize(regNo);
   uint8_t regIndex         = regNo - DSC_FirstCoreRegister;
   uint8_t instructionCount = targetReadRegSequence[regIndex].instructionCount;
   const uint8_t *sequence  = targetReadRegSequence[regIndex].sequence;

   *copyPtr++ = instructionCount;
   while (instructionCount-- > 0) {
      unsigned instructionLength = *sequence++;
      *copyPtr++ = instructionLength;  // Copy instruction length
      while(instructionLength-- > 0){
         *copyPtr++ = *sequence++;     // Copy instruction word
         *copyPtr++ = *sequence++;
      }
   }
   *copyPtr++ = (registerSize>16)?(ONCE_CMD_READ|OTX_ADDRESS):
                                  (ONCE_CMD_READ|OTX1_ADDRESS);
   *copyPtr++ = registerSize;

   return registerSize;
}

//! Read Multiple Core register via ONCE & target execution
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
static USBDM_ErrorCode saveVolatileTargetRegs(void) {
   LOGGING_Q;

   // Execute target instruction to transfer registers to memory-mapped EONCE reg OTX
   // Read OTX/OTX1
   static const uint8_t readCoreRegSequence[] = {

         // For each register
         JTAG_REPEAT_DP,
            // Process a register
   /*41*/   JTAG_CALL_EXECUTE,         // Execute target instruction: move Reg -> OTX/OTX1

            // Read EONCE reg OTX/OTX1
   /*42*/   JTAG_MOVE_DR_SCAN,         // Move to SCAN-DR (EONCE)
   /*43*/   JTAG_SET_EXIT_SHIFT_DR,
   /*44*/   JTAG_SHIFT_OUT_DP, ONCE_CMD_LENGTH,      // Command for Read Register - either OTX/OTX1
   /*46*/   JTAG_SET_EXIT_IDLE,
   /*47*/   JTAG_SHIFT_IN_DP, 0,       // Data size to read
         JTAG_END_REPEAT,
   /*49*/JTAG_END

// /*50*/   5, // # of registers
// /*50*/   2, // # of instructions for 1st reg
//          // Length  Instruction data...
// /*51*/        2,    0x87,0x44, 0xAA,0x34,
// /*56*/        3,    0xE7,0x7F, 0xD4,0x7C, 0xFF,0xFF,
//          // Read result from OTX/OTX1
// /*63*/   OTX1_ADDRESS|ONCE_CMD_READ,  16,
     // etc...
};
USBDM_ErrorCode rc;
uint16_t registerSize = 0;
uint8_t outBuffer[100];

   if (volatileRegs.valid) // registers already cached
      return BDM_RC_OK;

   log.print("\n");

   uint8_t* copyPtr = JTAGSequence;

   memcpy(copyPtr, readCoreRegSequence, sizeof(readCoreRegSequence));
   copyPtr += sizeof(readCoreRegSequence);

   *copyPtr++ = 6; // The number of registers to save
//   registerSize  = copyReadRegInfo(DSC_RegPC, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegA0, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegA1, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegA2, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegR0, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegR4, copyPtr);
   registerSize += copyReadRegInfo(DSC_RegX0, copyPtr);

   rc = executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence,
                            BITS_TO_BYTES(registerSize), outBuffer, false);
   if (rc != BDM_RC_OK)
      return rc;

   uint8_t const *outPtr   = outBuffer;
//   volatileRegs.PC    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegPC));
   volatileRegs.A0    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegA0));
   volatileRegs.A1    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegA1));
   volatileRegs.A2    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegA2));
   volatileRegs.R0    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegR0));
   volatileRegs.R4    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegR4));
   volatileRegs.X0    = (uint32_t)JTAG32(outPtr, getRegisterSize(DSC_RegX0));
   volatileRegs.valid = true;

//   printVolatileRegs();
   return rc;
}

//! Read Core register via OnCE & target execution
//!
//! @param regNo     - Register number
//! @param regValue  - Value for register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
USBDM_ErrorCode readCoreReg(DSC_Registers_t regNo, unsigned long *regValue) {
   LOGGING_Q;

   // Execute target instruction to transfer register to memory-mapped EONCE reg OTX
   // Read OTX/OTX1
   static const uint8_t readCoreRegSequence[] = {
         // Main
   /*41*/JTAG_CALL_EXECUTE,                  // Execute target instruction: move Reg -> OTX/OTX1
         // Read EONCE reg OTX/OTX1
   /*42*/JTAG_MOVE_DR_SCAN,                  // Move to SCAN-DR (EONCE)
   /*43*/JTAG_SET_EXIT_SHIFT_DR,
   /*44*/JTAG_SHIFT_OUT_DP, ONCE_CMD_LENGTH, // Command for Read Register - either OTX/OTX1
   /*46*/JTAG_SET_EXIT_IDLE,
   /*47*/JTAG_SHIFT_IN_DP, 0,                // Data size to read
   /*49*/JTAG_END

// /*50*/   2, // # of instructions
//          // Length  Instruction data...
// /*51*/        2,    0x87,0x44, 0xAA,0x34,
// /*56*/        3,    0xE7,0x7F, 0xD4,0x7C, 0xFF,0xFF,
//          // Read result from OTX/OTX1
// /*63*/   OTX1_ADDRESS|ONCE_CMD_READ,  16,
};
USBDM_ErrorCode rc;
uint8_t registerSize;

   if ((regNo<DSC_FirstCoreRegister) || (regNo>DSC_LastCoreRegister))
      return BDM_RC_ILLEGAL_PARAMS;

   uint8_t* copyPtr = JTAGSequence;

   memcpy(copyPtr, readCoreRegSequence, sizeof(readCoreRegSequence));
   copyPtr += sizeof(readCoreRegSequence);

   registerSize = copyReadRegInfo(regNo, copyPtr);

   JTAG32 regData(0, registerSize);

   rc = executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence,
                            BITS_TO_BYTES(registerSize), regData.getData(registerSize),
                            false);

//   log.print("(%s) => %s\n", getRegisterName(regNo), regData.toString());
   *regValue = regData;

   return rc;
}

static void copyWriteRegInfo(DSC_Registers_t regNo, uint32_t regValue, uint8_t *&copyPtr) {
   LOGGING_Q;

   uint8_t regIndex         = regNo - DSC_FirstCoreRegister;
   uint8_t instructionCount = targetWriteRegSequence[regIndex].instructionCount;
   const uint8_t *sequence  = targetWriteRegSequence[regIndex].sequence;

   if (regValue & 0xFF800000) {
      regValue |= 0xFF000000;
   }

   *copyPtr++ = instructionCount+1;   // # of instructions (+1 for MOVE #dd,R4)

   // Target code to load 32-bit value into R4
   *copyPtr++ = 3;      // 3 words long
   *copyPtr++ = 0xE4;   // opcode = move #<value>,R4
   *copyPtr++ = 0x1C;

   // V - value to load into register
   *copyPtr++ = (uint8_t)(regValue>>8);  // Immediate value
   *copyPtr++ = (uint8_t)(regValue);
   *copyPtr++ = (uint8_t)(regValue>>24);
   *copyPtr++ = (uint8_t)(regValue>>16);

   // I - Target instruction(s) to transfer value to Reg
   while (instructionCount-- > 0) {
      unsigned instructionLength = *sequence++;
      *copyPtr++ = instructionLength; // Copy instruction length
      while(instructionLength-- > 0) {
         *copyPtr++ = *sequence++; // Copy instruction word
         *copyPtr++ = *sequence++;
      }
   }
}

//! Write Multiple Core registers
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
static USBDM_ErrorCode restoreVolatileTargetRegs(void) {
   LOGGING_Q;

   // Execute target instructions to load register
   static const uint8_t writeCoreRegSequence[] = {
         // For each register
         JTAG_REPEAT_DP,
            JTAG_CALL_EXECUTE,  // Execute instructions routine
         JTAG_END_REPEAT,

         JTAG_END,

   // The following is repeated N times
            // Target code to load 32-bit value into R4
//   /*18*/      M,      // M instruction(s)
//   /*19*/      3,      // 1st 3 words long
//   /*20*/      0xE4,   // opcode = move #<value>,R4
//   /*21*/      0x1C,

//   22        V,  (uint8_t)(address>>8),  // Value
//   23        V,  (uint8_t)(address),
//   24        V,  (uint8_t)(address>>24),
//   25        V,  (uint8_t)(address>>16),

//             I,   // Target instruction(s) to transfer value to target Reg
//             ...
//             I+,
};
USBDM_ErrorCode rc;

   if (!volatileRegs.valid) // No register to restore
      return BDM_RC_OK;

   log.print("\n");

   uint8_t* copyPtr = JTAGSequence;

   memcpy(copyPtr, writeCoreRegSequence, sizeof(writeCoreRegSequence));
   copyPtr += sizeof(writeCoreRegSequence);

   *copyPtr++ = 6; // The number of registers
   copyWriteRegInfo(DSC_RegA0, volatileRegs.A0, copyPtr);
   copyWriteRegInfo(DSC_RegA1, volatileRegs.A1, copyPtr);
   copyWriteRegInfo(DSC_RegA2, volatileRegs.A2, copyPtr);
   copyWriteRegInfo(DSC_RegR0, volatileRegs.R0, copyPtr);
//   copyWriteRegInfo(DSC_RegPC, volatileRegs.PC, copyPtr);
   copyWriteRegInfo(DSC_RegR4, volatileRegs.R4, copyPtr);
   copyWriteRegInfo(DSC_RegX0, volatileRegs.X0, copyPtr);

   rc = executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence,
                            0, NULL, false);
   if (rc != BDM_RC_OK)
      return rc;

   volatileRegs.valid = false;
   return BDM_RC_OK;
}

//! Write Core register via ONCE & target execution
//!
//! @param regNo     - Register number
//! @param regValue  - Value for register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE, EONCE register selected
//!
USBDM_ErrorCode writeCoreReg(DSC_Registers_t regNo, uint32_t regValue) {
   LOGGING_Q;

   // Execute target instructions to load register
   static const uint8_t writeCoreRegSequence[] = {
   /*41*/JTAG_CALL_EXECUTE,  // Execute instructions routine
   /*43*/JTAG_END,

            // Target code to load 32-bit value into R4
//   /*18*/      1,      // 1 instruction
//   /*19*/      3,      // 3 words long
//   /*20*/      0xE4,   // opcode = move #<value>,R4
//   /*21*/      0x1C,

//   22        V,  (uint8_t)(address>>8),  // Value
//   23        V,  (uint8_t)(address),
//   24        V,  (uint8_t)(address>>24),
//   25        V,  (uint8_t)(address>>16),

//             I,   // Target instruction(s) to transfer value to Reg
//             ...
//             I+,
};
   if ((regNo<DSC_FirstCoreRegister) || (regNo>DSC_LastCoreRegister))
      return BDM_RC_ILLEGAL_PARAMS;

//   enableLogging(true);

   JTAG32 regData(regValue, getRegisterSize(regNo));

   log.print("(%s) <= %s\n", getRegisterName(regNo), regData.toString());

   uint8_t* copyPtr = JTAGSequence;

   memcpy(copyPtr, writeCoreRegSequence, sizeof(writeCoreRegSequence));
   copyPtr += sizeof(writeCoreRegSequence);

   copyWriteRegInfo(regNo, regValue, copyPtr);

   return executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence,
                              0, NULL, false);
}

////! Swaps the Endianess of a buffer
////!
////! @param buffer       - buffer to operate on
////! @param elementSize  - size of the elements (# of bytes)
////! @param nuBytes      - size of the buffer in bytes
////!
//static void swapLongwordEndian(const uint8_t *from, uint8_t *to, uint8_t numBytes) {
//
//   unsigned index;
//   for (index =0; index<numBytes; index += 4) {
//      uint8_t t;
//      t           = from[index];
//      to[index]   = from[index+3];
//      to[index+3] = t;
//      t           = from[index+1];
//      to[index+1] = from[index+2];
//      to[index+2] = t;
//   }
//}

////! Swap word endianess of a buffer
////!
////! @param from  source buffer
////! @param to    destination buffer - may be same as from
////!
//static void swapWordEndian(const uint8_t *from, uint8_t *to, unsigned size) {
//   for (unsigned sub=0; sub < size; sub+=2) {
//      uint8_t t;
//      t         = from[sub];
//      to[sub]   = from[sub+1];
//      to[sub+1] = t;
//   }
//}

#if 0
//=========================================================
//! JTAG sequence to read target memory
//!
#if 0
static const uint8_t readTargetMemorySequenceX[] = {
   /* 0*/ JTAG_SUB_MEM_READ,
   /* 1*/    JTAG_PUSH_DP_8,       // = L, # of bytes/words/longwords to read (<=255)
   /* 2*/    JTAG_SAVE_OUT_DP_VARC,    // = I, Save start of read instruction sequence
   /* 3*/    JTAG_REPEAT,          // Uses L value saved above
   /* 4*/       JTAG_RESTORE_DP_VARC,               // Restore to start of read sequence
   /* 5*/       JTAG_CALL_EXECUTE,                  // = I, Read a target memory location
                // Read EONCE reg OTX/OTX1
   /* 6*/       JTAG_MOVE_DR_SCAN,                  // Move to SCAN-DR (EONCE)
   /* 7*/       JTAG_SET_EXIT_SHIFT_DR,             // Exit SCAN-DR & re-enter SCAN-DR after each transaction
   /* 8*/       JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH),(ONCE_CMD_READ|OTX_ADDRESS), // Command Read OTX
   /*10*/       JTAG_SET_EXIT_IDLE,
   /*11*/       JTAG_SHIFT_IN_DP, 0,                // = S, Size to read
   /*12*/    JTAG_END_REPEAT,
   /*14*/ JTAG_END_SUB,
          JTAG_SAVE_SUB,
          JTAG_END,

//   /*18*/      2,      // 2 instructions
//
//            // Target code to point R4 at otx
//   /*19*/      3,                    // 3 words long
//   /*20*/      0xE4,0x1C,            // move #X:otx,R4
//               0xFF,0xFE,0x00,0xFF,
//
//            // Target code to load starting memory address into R0
//   /*19*/      3,           // 3 words long
//   /*20*/      0xE4, 0x18,  // opcode = move #<address>,R0

//   22        A,  (uint8_t)(address>>8),  // Starting address
//   23        A,  (uint8_t)(address),
//   24        A,  (uint8_t)(address>>24),
//   25        A,  (uint8_t)(address>>16),

//   26        L,  // # of bytes/words/longwords to read (<=255)
//   27        I,  // # of instructions in target code sequence
//   28        I      x, ddddddd  // Target instruction sequence (#words+data...)
//             ...      .......
//             I      x, ddddddd
//   +N+1      S   // Size of data 8/16/32-bits
};
#endif
static const uint8_t readTargetMemorySequence[] = {
//   /* 0*/ JTAG_SUB_MEM_READ,
//   /* 1*/    JTAG_PUSH_DP_8,       // = L, # of bytes/words/longwords to read (<=255)
//   /* 2*/    JTAG_SAVE_OUT_DP_VARC,    // = I, Save start of read instruction sequence
//   /* 3*/    JTAG_REPEAT,          // Uses L value saved above
//   /* 4*/       JTAG_RESTORE_DP_VARC,               // Restore to start of read sequence
//   /* 5*/       JTAG_CALL_EXECUTE,                  // = I, Read a target memory location
//                // Read EONCE reg OTX/OTX1
//   /* 6*/       JTAG_MOVE_DR_SCAN,                  // Move to SCAN-DR (EONCE)
//   /* 7*/       JTAG_SET_EXIT_SHIFT_DR,             // Exit SCAN-DR & re-enter SCAN-DR after each transaction
//   /* 8*/       JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH),(ONCE_CMD_READ|OTX_ADDRESS), // Command Read OTX
//   /*10*/       JTAG_SET_EXIT_IDLE,
//   /*11*/       JTAG_SHIFT_IN_DP, 0,                // = S, Size to read
//   /*12*/    JTAG_END_REPEAT,
//   /*14*/ JTAG_END_SUB,

//          JTAG_SET_BUSY,   // Flag that execution may take a while
   /*15*/ JTAG_CALL_EXECUTE,    // Execute instruction(s) - Point R4 at otx, Start address in R0
   /*15*/ JTAG_READ_MEM,        // Execute read memory routine
//   /*16*/ JTAG_CALL_MEM_READ,   // Execute read memory routine
   /*17*/ JTAG_END,             // Terminate code sequence

   /*18*/      2,      // 2 instructions

            // Target code to point R4 at otx
   /*19*/      3,                    // 3 words long
   /*20*/      0xE4,0x1C,            // move #X:otx,R4
               0xFF,0xFE,0x00,0xFF,

            // Target code to load starting memory address into R0
   /*19*/      3,           // 3 words long
   /*20*/      0xE4, 0x18,  // opcode = move #<address>,R0

//   22        A,  (uint8_t)(address>>8),  // Starting address
//   23        A,  (uint8_t)(address),
//   24        A,  (uint8_t)(address>>24),
//   25        A,  (uint8_t)(address>>16),

//   26        L,  // # of bytes/words/longwords to read (<=255)
//   27        I,  // # of instructions in target code sequence
//   28        I      x, ddddddd  // Target instruction sequence (#words+data...)
//             ...      .......
//             I      x, ddddddd
//   +N+1      S   // Size of data 8/16/32-bits
};

// X Memory Reads
// Target code to transfer an 8/16/32-bit value from X:(R0)+ into otx/otx1
// Assumes R4 points at otx
//
static const uint8_t readXMem8[]  = {
      2, 1, 0xF8,0xA0,             // readxb    moveu.bp  X:(R0)+,A
         1, 0xD0,0x1C,             //           move.w    A1,X:(R4)
};
static const uint8_t readXMem16[] = {
      2, 1, 0xF6,0x80,             // readxw    move.w    X:(R0)+,A0
         1, 0xD6,0x9C,             //           move.w    A0,X:(R4)
};
static const uint8_t readXMem32[] = {
      2, 1, 0xF0,0x20,             // readxl    move.l    X:(R0)+,A
         1, 0xD0,0x3C,             //           move.l    A10,X:(R4)
};
// P Memory Reads
// Target code to transfer a 16-bit value from P:(R0)+ into otx1
static const uint8_t readPMem16[] = {
      2, 1, 0x83,0x68,             // readpw    move.w    P:(R0)+,A1
         1, 0xD0,0x1C,             //           move.w    A1,X:(R4)
};

// Overhead required for the Read sequence
//                                        Fixed array                 +A+L       +I          +S
#define JTAG_READ_MEMORY_HEADER_SIZE (sizeof(readTargetMemorySequence)+4+1+sizeof(readXMem32)+1)

//================================================================================
//! Read X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//! @note Size is limited to dscInfo.maxMemoryReadSize
//!
USBDM_ErrorCode readMemoryBlock(unsigned int        memorySpace,
                                unsigned int        numBytes,
                                unsigned int        address,
                                unsigned char       *buffer) {
MemorySpace_t memSpace     = (MemorySpace_t)memorySpace;
int           elementSize  = memorySpace&MS_SIZE;
USBDM_ErrorCode rc;

//   log.print("(A=%s, S=%d, #=%d)\n", getKnownAddress(memSpace,address), elementSize, numBytes);

   if (numBytes > dscInfo.maxMemoryReadSize) {
      log.print("Buffer overflow, MaxDataSize = %u\n",
            dscInfo.maxMemoryReadSize);
      return BDM_RC_ILLEGAL_PARAMS;
   }

   rc = loadCache(MemAccessCached);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   saveVolatileTargetRegs();

   // Copy main routine
   uint8_t* copyPtr = JTAGSequence;
   memcpy(copyPtr, readTargetMemorySequence, sizeof(readTargetMemorySequence));
   copyPtr += sizeof(readTargetMemorySequence);

   // A, Append Starting Address
   *copyPtr++ = (uint8_t)(address>>8);
   *copyPtr++ = (uint8_t)(address);
   *copyPtr++ = (uint8_t)(address>>24);
   *copyPtr++ = (uint8_t)(address>>16);

   // L, # of bytes/words/longwords to read (<=255)
   *copyPtr++ = numBytes/elementSize;

   rc   = BDM_RC_ILLEGAL_PARAMS; // Set up for parameter validation fail
   switch (memSpace&MS_SPACE) {
      case MS_Data: // X: Data space
         switch (elementSize) {
            case MS_Byte:
               memcpy(copyPtr, readXMem8, sizeof(readXMem8));
               copyPtr += sizeof(readXMem8);
               rc = BDM_RC_OK;
               break;
            case MS_Word:
               if ((numBytes & 0x01) == 0) {
                  memcpy(copyPtr, readXMem16, sizeof(readXMem16));
                  copyPtr += sizeof(readXMem16);
                  rc = BDM_RC_OK;
               }
               break;
            case MS_Long:
               if (((address & 0x01) == 0) && ((numBytes & 0x03) == 0)) {
                  memcpy(copyPtr, readXMem32, sizeof(readXMem32));
                  copyPtr += sizeof(readXMem32);
                  rc = BDM_RC_OK;
               }
               break;
            default:
               break;
         }
         break;
      case MS_Program:    // P: Program space
         switch (elementSize) {
         case MS_Long: // Treat as word
         case MS_Word:
            elementSize = MS_Word;
            *(copyPtr-1) = numBytes/elementSize; // correct number of elements
            if ((numBytes & 0x01) == 0) {
               memcpy(copyPtr, readPMem16, sizeof(readPMem16));
               copyPtr += sizeof(readPMem16);
               rc = BDM_RC_OK;
            }
            break;
         default:
            break;
         }
         break;
      default:
         break;
   }
   if (rc != BDM_RC_OK) {
      log.print("(A=%s, S=%d, #=%d) - Illegal operands\n", getKnownAddress(memSpace,address), elementSize, numBytes);
      return rc;
   }
   // Size of data elements 8/16/32-bits
   *copyPtr++ = 8*elementSize;

   // Execute the code
   rc = executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence, numBytes, (uint8_t*)buffer);
   if (rc != BDM_RC_OK) {
      log.print("Failed, rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
//   // JTAG interface is big-endian but DSC is little-endian
//   switch (elementSize) {
//   case 2  : swapWordEndian(buffer, buffer, numBytes);     break;
//   case 4  : swapLongwordEndian(buffer, buffer, numBytes); break;
//   default : break;
//   }
   return rc;
}
#else
// Overhead required for the Read sequence
#define JTAG_READ_MEMORY_HEADER_SIZE 8

//================================================================================
//! Read X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//! @note Size is limited to dscInfo.maxMemoryReadSize
//!
USBDM_ErrorCode readMemoryBlock(unsigned int   memorySpace,
                                unsigned int   numBytes,
                                unsigned int   address,
                                unsigned char *buffer) {
   LOGGING_Q;

   if (memorySpace == MS_PLong) {
      // Treat as word access
      memorySpace = MS_PWord;
   }
 /*
  *    +-----------------------+
  *    |    JTAG_READ_MEM      |
  *    +-----------------------+
  *    |    JTAG_END           |
  *    +-----------------------+
  *    |                       |
  *    +--                   --+
  *    |                       |
  *    +--  Memory Address   --+
  *    |                       |
  *    +--                  ---+
  *    |                       |
  *    +-----------------------+
  *    |  # of memory elements |
  *    +-----------------------+
  *    |   Memory Space        |
  *    +-----------------------+
  */
   uint8_t JTAGSequence[JTAG_READ_MEMORY_HEADER_SIZE] = {
    /* 0 */     (uint8_t)JTAG_READ_MEM,
    /* 1 */     (uint8_t)JTAG_END,
    /* 2 */     (uint8_t)(address>>24),  // Address
    /* 3 */     (uint8_t)(address>>16),
    /* 4 */     (uint8_t)(address>>8),
    /* 5 */     (uint8_t)address,
    /* 6 */     (uint8_t)0,              // # Elements
    /* 7 */     (uint8_t)memorySpace,    // Memory space
      };
   USBDM_ErrorCode rc = BDM_RC_ILLEGAL_PARAMS; // Assume illegal parameters
   switch(memorySpace&MS_SIZE) {
      case MS_Long:
         if ((address&0x01) == 0) {
            JTAGSequence[6] = numBytes/4;
            rc = BDM_RC_OK;
         }
         break;
      case MS_Word:
         JTAGSequence[6] = numBytes/2;
         rc = BDM_RC_OK;
         break;
      case MS_Byte:
         JTAGSequence[6] = numBytes/1;
         rc = BDM_RC_OK;
         break;
      default:
         break;
   }
   if (rc == BDM_RC_OK) {
      rc = executeJTAGSequence(sizeof(JTAGSequence), JTAGSequence,
                               numBytes, (uint8_t*)buffer);
   }
   if (rc != BDM_RC_OK) {
      log.print("Failed, rc = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}
#endif

//================================================================================
//! Read X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address (byte = byte address, word/long = word address)
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_ReadMemory(unsigned int        memorySpace,
                               unsigned int        numBytes,
                               unsigned int        address,
                               unsigned char       *buffer) {
   LOGGING_Q;

   MemorySpace_t  memSpace     = (MemorySpace_t) memorySpace;
   int            elementSize  = memorySpace&MS_SIZE;
   unsigned char *bufferPtr = buffer;
   unsigned int  bytesDone = 0;
   unsigned int  currentAddress = address;

   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("(A=%s, S=%d, #=%d)\n", getKnownAddress(memSpace,currentAddress), elementSize, numBytes);

   saveVolatileTargetRegs();

   while (bytesDone<numBytes) {
      unsigned int blockSize = numBytes-bytesDone;
      if (blockSize>dscInfo.maxMemoryReadSize) {
         blockSize = dscInfo.maxMemoryReadSize;
      }
      rc = readMemoryBlock(memSpace, blockSize, currentAddress, bufferPtr);
      if (rc != BDM_RC_OK) {
         break;
      }
      bytesDone += blockSize;
      bufferPtr += blockSize;
      if ((memorySpace&MS_SIZE) == MS_Byte) {
         // Byte currentAddress advanced by count of bytes written
         currentAddress  += blockSize;
      }
      else {
         // Address advanced by count of words written
         currentAddress  += blockSize/2;
      }
   }
   if (elementSize == MS_Byte) {
      log.printDump((uint8_t*)buffer, numBytes, address, UsbdmSystem::BYTE_ADDRESS|UsbdmSystem::BYTE_DISPLAY);
   }
   else {
      log.printDump((uint8_t*)buffer, numBytes, address, UsbdmSystem::WORD_ADDRESS|UsbdmSystem::WORD_DISPLAY);
   }
   return rc;
}

#if 0
//====================================================================================
// X Memory Write
// Target code to transfer an 8/16/32-bit value from otx/otx1 to X:(R0)+
static const uint8_t writeXMem8[]  = {
   3, 1, 0xB4,0x0C,                 // writexb  move.w      X:(R4+1),X0
      1, 0x5E,0x28,                 //          lsrr.w      #8,X0
      1, 0xD4,0xA0,                 //          move.bp     X0,X:(R0)+
};
static const uint8_t writeXMem16[] = {
   2, 1, 0xB4,0x0C,                 // writexw  move.w      X:(R4+1),X0
      1, 0xD4,0x00,                 //          move.w      X0,X:(R0)+
      0,0,0,
};
static const uint8_t writeXMem32[] = {
   2, 1, 0xF0,0x3C,                 // writexl  move.l      X:(R4),A
      1, 0xD0,0x20,                 //          move.l      A10,X:(R0)+
      0,0,0,
};
// P Memory Write
// Target code to transfer a 16-bit value from otx1 to P:(R0)+
static const uint8_t writePMem16[] = {
   2, 1, 0xB4,0x0C,                 // writepw  move.w      X:(R4+1),X0
      1, 0x84,0x60,                 //          move.w      X0,P:(R0)+
      0,0,0,
};
#if 0
static const uint8_t writeTargetMemorySequenceX[] = {
      JTAG_SUB_MEM_READ,
         JTAG_SAVE_OUT_DP_VARC,                                    // = I, Ptr to instruction sequence for write OTX/OTX1->(R0)+
         JTAG_SKIP_DP_Q(sizeof(writeXMem16)),                  // Skip over instruction sequence
         JTAG_LOAD_VARA_DP_8,                                  // = S, size of data

         JTAG_REPEAT_DP,      // = L, # of bytes/words/longwords to write (<=255)
            // Write value to EONCE reg OTX/OTX1
            JTAG_MOVE_DR_SCAN,                                 // Move to SCAN-DR (access EONCE)
            JTAG_SET_EXIT_SHIFT_DR,                            // Exit SCAN-DR & re-enter SCAN-DR after each transaction
            JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), (ORX_ADDRESS|ONCE_CMD_WRITE),  // Command Write ORX

            JTAG_SET_EXIT_IDLE,
            JTAG_SHIFT_OUT_DP_VARA,                            // = D, Write data byte/word/long to OTX
            JTAG_SAVE_DP_VARD,                                 // Save ptr to memory data for next iteration

            // Execute target instructions to copy OTX/OTX1 -> (R0)+
            JTAG_RESTORE_DP_VARC,                              // Point to instruction sequence
            JTAG_CALL_EXECUTE,                                 // Execute sequence - write a target memory location

            JTAG_RESTORE_DP_VARD,                              // Restore memory data DP
         JTAG_END_REPEAT,
      JTAG_END_SUB,

      JTAG_SAVE_SUB,  // Save subroutines
      JTAG_END,

//   /*33*/      2,      // 2 instructions

//   // Target code to point R4 at otx (otx1 requires +1 offset)
//   /*34*/      3,                              // 3 words long
//   /*34*/      0xE4,0x1C,0xFF,0xFE,0x00,0xFF,  // move #X:otx,R4

//   // Target code to load starting memory address into R0
//   /*42*/      3,                // 3 words long
//   /*43*/      0xE4, 0x18,       // move #<address>,R0
//   47        A,  (uint8_t)(address>>8),  // Starting address
//   48        A,  (uint8_t)(address),
//   49        A,  (uint8_t)(address>>24),
//   50        A,  (uint8_t)(address>>16),

//                      // Instruction sequence to copy OTX/OTX1 -> (R0)+
//   53        I,       // # of instructions for each value transferred
//   54        I        x, ddddddd  // Target instruction sequence (#words+data)
//             ...      ...
//             I        x, ddddddd

//   xx        S,       // size of data to write (8/16/32 bits)

//   xx        L,       // # of bytes/words/longwords to write (<=255)

//   xx        D,       // 1st byte/word/longword data to write
//             ...      ...
//   +N+M      D+       // last byte/word/longword data to write
   };
#endif
static const uint8_t writeTargetMemorySequence[] = {
   //  Main
   //    JTAG_SET_BUSY,        // Flag that execution may take a while
   /* 0*/JTAG_CALL_EXECUTE,    // Execute to move #X:otx,R4, move #<address>,R0
   /* 1*/JTAG_WRITE_MEM,       // Execute write memory routine
   /* 2*/JTAG_END,             // Terminate sequence

   /* 3*/      2,      // 2 instructions

   // Target code to point R4 at otx (otx1 requires +1 offset)
   /* 4*/      3,                              // 3 words long
   /* 5*/      0xE4,0x1C,0xFF,0xFE,0x00,0xFF,  // move #X:otx,R4

   // Target code to load starting memory address into R0
   /*11*/      3,                // 3 words long
   /*12*/      0xE4, 0x18,       // move #<address>,R0

//   13        A,  (uint8_t)(address>>8),  // Starting address
//   14        A,  (uint8_t)(address),
//   15        A,  (uint8_t)(address>>24),
//   16        A,  (uint8_t)(address>>16),
//          -------------
//                      // Instruction sequence to copy OTX/OTX1 -> (R0)+
//   17        I,       // # of instructions for each value transferred
//   18        I        x, ddddddd  // Target instruction sequence (#words+data)
//             ...      ...
//             I        x, ddddddd

//   xx        S,       // size of data to write (8/16/32 bits)

//   xx        L,       // # of bytes/words/longwords to write (<=255)

//   xx        D,       // 1st byte/word/longword data to write
//             ...      ...
//   +N+M      D+       // last byte/word/longword data to write
   };
// Overhead required for the Read sequence
//                                       Fixed array                    +A       +I           +S+L
#define JTAG_WRITE_MEMORY_HEADER_SIZE (sizeof(writeTargetMemorySequence)+4+sizeof(writeXMem16)+1+1)

//================================================================================
//! Write X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//! @note Size is limited to dscInfo.maxMemoryWriteSize
//!
USBDM_ErrorCode writeMemoryBlock(unsigned int         memorySpace,
                                 unsigned int         numBytes,
                                 unsigned int         address,
                                 const unsigned char *buffer) {

   MemorySpace_t   memSpace     = (MemorySpace_t) memorySpace;
   int             elementSize  = memorySpace&MS_SIZE;
   USBDM_ErrorCode rc;
   // D - memory data - words are written littleEndian!
   uint8_t tBuffer[dscInfo.maxMemoryWriteSize+10];

   log.print("(A=%s, S=%d, #=%d)\n", getKnownAddress(memSpace,address), elementSize, numBytes);

   if (numBytes > dscInfo.maxMemoryWriteSize) {
      log.error("Buffer size too large\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }

   rc = loadCache(MemAccessCached);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   uint8_t* copyPtr=JTAGSequence;
   memcpy(copyPtr, writeTargetMemorySequence, sizeof(writeTargetMemorySequence));
   copyPtr += sizeof(writeTargetMemorySequence);

   //  A, Load starting address into R0
   *copyPtr++ = (uint8_t)(address>>8);   // Starting Address
   *copyPtr++ = (uint8_t)(address);
   *copyPtr++ = (uint8_t)(address>>24);
   *copyPtr++ = (uint8_t)(address>>16);

   rc   = BDM_RC_ILLEGAL_PARAMS; // Set up for parameter validation fail
   switch (memSpace&MS_SPACE) {
      case MS_Data: // X: Data space
         switch (elementSize) {
            case MS_Byte:
               memcpy(copyPtr, writeXMem8, sizeof(writeXMem8));
               copyPtr += sizeof(writeXMem8);
               memcpy(tBuffer, buffer, numBytes);
               rc = BDM_RC_OK;
               break;
            case MS_Word:
               if ((numBytes & 0x01) == 0) {
                  memcpy(copyPtr, writeXMem16, sizeof(writeXMem16));
                  copyPtr += sizeof(writeXMem16);
                  memcpy(tBuffer, buffer, numBytes);
                  //swapWordEndian(buffer, tBuffer, numBytes); // Words are written littleEndian
                  rc = BDM_RC_OK;
               }
               break;
            case MS_Long:
               if ((numBytes & 0x03) == 0) {
                  memcpy(copyPtr, writeXMem32, sizeof(writeXMem32));
                  copyPtr += sizeof(writeXMem32);
                  memcpy(tBuffer, buffer, numBytes);
                  //swapLongwordEndian(buffer, tBuffer, numBytes); // Words are written littleEndian
                  rc = BDM_RC_OK;
               }
               break;
            default:
               break;
         }
         break;
      case MS_Program:    // P: Program space
         switch (elementSize) {
         case MS_Word:
         case MS_Long: // Treat as Word
            elementSize = MS_Word;
            if ((numBytes & 0x01) == 0) {
               memcpy(copyPtr, writePMem16, sizeof(writePMem16));
               copyPtr += sizeof(writePMem16);
               memcpy(tBuffer, buffer, numBytes);
               //swapWordEndian(buffer, tBuffer, numBytes); // Words are written littleEndian
               rc = BDM_RC_OK;
            }
            break;
         default:
            break;
         }
         break;
      default:
         break;
   }
   if (rc != BDM_RC_OK) {
      log.error("(A=%s, S=%d, #=%d) - Illegal operands\n", getKnownAddress(memSpace,address), elementSize, numBytes);
      return rc;
   }
   // S, size of data to write (8/16/32 bits)
   *copyPtr++ = 8*elementSize;

   // L, # of bytes/words/longwords to read (<=255)
   *copyPtr++ = numBytes/elementSize;

   // D - memory data
   memcpy(copyPtr, tBuffer, numBytes); // Rest of the data to write
   copyPtr += numBytes;

   rc = executeJTAGSequence(copyPtr-JTAGSequence, JTAGSequence,
                            0, NULL);
   if (rc != BDM_RC_OK) {
      log.error("Failed, rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   return rc;
}
#else
// Overhead required for the Write sequence
#define JTAG_WRITE_MEMORY_HEADER_SIZE 8

//================================================================================
//! Write X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//! @note Size is limited to dscInfo.maxMemoryWriteSize
//!
USBDM_ErrorCode writeMemoryBlock(unsigned int         memorySpace,
                                 unsigned int         numBytes,
                                 unsigned int         address,
                                 const unsigned char *buffer) {
   LOGGING_Q;

   if (memorySpace == MS_PLong) {
      // Treat as word access
      memorySpace = MS_PWord;
   }
 /*
  *    +-----------------------+
  *    |    JTAG_WRITE_MEM     |
  *    +-----------------------+
  *    |    JTAG_END           |
  *    +-----------------------+
  *    |                       |
  *    +--                   --+
  *    |                       |
  *    +--  Memory Address   --+
  *    |                       |
  *    +--                  ---+
  *    |                       |
  *    +-----------------------+
  *    |  # of memory elements |
  *    +-----------------------+
  *    |   Memory Space        |
  *    +-----------------------+
  *    | ..................... |
  *    = ...... data ......... =
  *    | ..................... |
  *    +-----------------------+
  */
   uint8_t JTAGSequence[JTAG_WRITE_MEMORY_HEADER_SIZE+300] = {
    /* 0 */     (uint8_t)JTAG_WRITE_MEM,
    /* 1 */     (uint8_t)JTAG_END,
    /* 2 */     (uint8_t)(address>>24),  // Address
    /* 3 */     (uint8_t)(address>>16),
    /* 4 */     (uint8_t)(address>>8),
    /* 5 */     (uint8_t)address,
    /* 6 */     (uint8_t)0,              // # Elements
    /* 7 */     (uint8_t)memorySpace,    // Memory space
    /* 8 */                     // data .... (offset = JTAG_WRITE_MEMORY_HEADER_SIZE!)
         };
   if ((numBytes+JTAG_WRITE_MEMORY_HEADER_SIZE) > sizeof(JTAGSequence)) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   USBDM_ErrorCode rc = BDM_RC_ILLEGAL_PARAMS; // Assume illegal parameters
   switch(memorySpace&MS_SIZE) {
      case MS_Long:
         if ((address&0x01) == 0) {
            JTAGSequence[6] = numBytes/4;
            rc = BDM_RC_OK;
         }
         break;
      case MS_Word:
         JTAGSequence[6] = numBytes/2;
         rc = BDM_RC_OK;
         break;
      case MS_Byte:
         JTAGSequence[6] = numBytes/1;
         rc = BDM_RC_OK;
         break;
      default:
         break;
   }
   if (rc == BDM_RC_OK) {
      memcpy(JTAGSequence+JTAG_WRITE_MEMORY_HEADER_SIZE, buffer, numBytes);
      rc = executeJTAGSequence(numBytes+JTAG_WRITE_MEMORY_HEADER_SIZE, JTAGSequence, 0, NULL);
   }
   if (rc != BDM_RC_OK) {
      log.print("Failed, rc = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}
#endif

//================================================================================
//! Write X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param numBytes    - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param buffer      - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_WriteMemory(unsigned int         memorySpace,
                                unsigned int         numBytes,
                                unsigned int         address,
                                const unsigned char *buffer) {
   LOGGING_Q;

   MemorySpace_t memSpace     = (MemorySpace_t) memorySpace;
   int           elementSize  = memorySpace&MS_SIZE;

   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("(A=%s, S=%d, #=%d)\n", getKnownAddress(memSpace,address), elementSize, numBytes);
   log.printDump((uint8_t*)buffer, numBytes, address, UsbdmSystem::WORD_ADDRESS|UsbdmSystem::WORD_DISPLAY);

   saveVolatileTargetRegs();

   while (numBytes>0) {
      unsigned int blockSize = numBytes;
      if (blockSize>dscInfo.maxMemoryWriteSize) {
         blockSize = dscInfo.maxMemoryWriteSize;
      }
      rc = writeMemoryBlock(memSpace, blockSize, address, buffer);
      if (rc != BDM_RC_OK)
         break;
      numBytes -= blockSize;
      buffer   += blockSize;
      if ((memorySpace&MS_SIZE) == MS_Byte) {
         // Byte address advanced by count of bytes written
         address  += blockSize;
      }
      else {
         // Address advanced by count of words written
         address  += blockSize/2;
      }
   }
   return rc;
}

#if 0
//! These routines are cached in BDM to reduce USB traffic
//!
static const uint8_t targetMemorySequence[] = {
   // JTAG_SUB_EXECUTE - Instruction execution routine - now firmware implemented
   // SUBB - Read Memory routine
#if 1
   JTAG_SUB_MEM_READ,
      JTAG_PUSH_DP_8,       // = L, # of bytes/words/longwords to read (<=255)
      JTAG_SAVE_OUT_DP_VARC,    // = I, Save start of read instruction sequence
      JTAG_REPEAT,          // Uses L value saved above
         JTAG_RESTORE_DP_VARC,               // Restore to start of read sequence
         JTAG_CALL_EXECUTE,                  // = I, Read a target memory location
         // Read EONCE reg OTX/OTX1
         JTAG_MOVE_DR_SCAN,                  // Move to SCAN-DR (EONCE)
         JTAG_SET_EXIT_SHIFT_DR,             // Exit SCAN-DR & re-enter SCAN-DR after each transaction
         JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH),(ONCE_CMD_READ|OTX_ADDRESS), // Command Read OTX
         JTAG_SET_EXIT_IDLE,
         JTAG_SHIFT_IN_DP, 0,                // = S, Size to read
      JTAG_END_REPEAT,
   JTAG_END_SUB,

#endif
#if 1
   // SUBC - Write Memory routine
   JTAG_SUB_MEM_WRITE,
      JTAG_SAVE_OUT_DP_VARC,                                // = I, Ptr to instruction sequence for write OTX/OTX1->(R0)+
      JTAG_SKIP_DP_Q(sizeof(writeXMem16)),                  // Skip over instruction sequence
      JTAG_LOAD_VARA_DP_8,                                  // = S, size of data

      JTAG_REPEAT_DP,      // = L, # of bytes/words/longwords to write (<=255)
         // Write value to EONCE reg OTX/OTX1
         JTAG_MOVE_DR_SCAN,                                 // Move to SCAN-DR (access EONCE)
         JTAG_SET_EXIT_SHIFT_DR,                            // Exit SCAN-DR & re-enter SCAN-DR after each transaction
         JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH), (ORX_ADDRESS|ONCE_CMD_WRITE),  // Command Write ORX

         JTAG_SET_EXIT_IDLE,
         JTAG_SHIFT_OUT_DP_VARA,                            // = D, Write data byte/word/long to OTX
         JTAG_SAVE_OUT_DP_VARD,                             // Save ptr to memory data for next iteration

         // Execute target instructions to copy OTX/OTX1 -> (R0)+
         JTAG_RESTORE_DP_VARC,                              // Point to instruction sequence
         JTAG_CALL_EXECUTE,                                 // Execute sequence - write a target memory location

         JTAG_RESTORE_DP_VARD,                              // Restore memory data DP
      JTAG_END_REPEAT,
   JTAG_END_SUB,

   JTAG_SAVE_SUB,  // Save subroutines
   JTAG_END,
#endif
};
#endif

//=====================================================================================================================
//! Used to cache memory read/write JTAG sequences
//!
//! @param loadType - Type of routine to load
//!
static USBDM_ErrorCode loadCache(CacheState_t loadType) {
   LOGGING_Q;

   USBDM_ErrorCode rc = BDM_RC_OK;

   // Check if already loaded
   if (loadType == cacheState) {
//      log.print("Cache already loaded\n");
      return BDM_RC_OK;
   }
   switch (loadType) {
      case CacheFree       :
         break;
      case MemAccessCached  :
//         log.print("Loading targetMemorySequence, %d bytes\n", sizeof(targetMemorySequence));
//         rc = executeJTAGSequence(sizeof(targetMemorySequence), targetMemorySequence, 0, NULL);
         break;
   }
   if (rc != BDM_RC_OK) {
      log.print("Failed loading, reason = %s\n", USBDM_GetErrorString(rc));
      cacheState = CacheFree;
   }
   else {
      log.print("OK\n");
      cacheState = loadType;
   }
   return rc;
}

//! Obtain information about the DSC interface
//!
//! @param dscInfo_ structure to populate
//!
//! @note the size entry in info must be set before the call
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetInfo(dscInfo_t *dscInfo_) {
   LOGGING_Q;

   USBDM_ErrorCode rc;

   USBDM_bdmInformation_t bdmInfo = {sizeof(USBDM_bdmInformation_t), 0};

   // Get maximum JTAG sequence length
   rc = USBDM_GetBdmInformation(&bdmInfo);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Calculate permitted read & write length in bytes
   // Allow for JTAG header + USB header (5 bytes) & make multiple of 4
   dscInfo.maxMemoryReadSize  = (bdmInfo.jtagBufferSize-JTAG_READ_MEMORY_HEADER_SIZE-5)  & ~3;
   dscInfo.maxMemoryWriteSize = (bdmInfo.jtagBufferSize-JTAG_WRITE_MEMORY_HEADER_SIZE-5) & ~3;
   if (dscInfo_ != NULL) {
      if (dscInfo_->size > sizeof(dscInfo_t)) {
         return BDM_RC_ILLEGAL_PARAMS;
      }
      memset(dscInfo_, 0, dscInfo_->size);
      *dscInfo_ = dscInfo;
   }
   log.print("usbdmBufferSize = %u\n", bdmInfo.jtagBufferSize);
   log.print("JTAG_READ_MEMORY_HEADER_SIZE=%d, MaxDataSize = %u\n",  0, dscInfo.maxMemoryReadSize);
   log.print("JTAG_WRITE_MEMORY_HEADER_SIZE=%d, MaxDataSize = %u\n", JTAG_WRITE_MEMORY_HEADER_SIZE, dscInfo.maxMemoryWriteSize);

   return BDM_RC_OK;
}

//! Connect to target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetIdcode(uint32_t *idcode) {
   LOGGING_Q;

   USBDM_ErrorCode rc = DSC_Connect();
   *idcode = coreIdcode;
   return rc;
}

//! Connect to target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_Connect(void){
   LOGGING_E;

   USBDM_ErrorCode rc;
   uint32_t idCode;
   OnceStatus_t onceStatus;

   if (!DSC_InitialiseDone) {
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         return  rc;
      }
   }
   rc = readIDCODE(&idCode, JTAG_MASTER_COMMAND_LENGTH, true);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   log.print("Master IDCODE = %8.8X\n", idCode);
   rc = enableCoreTAP();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = readIDCODE(&idCode, JTAG_CORE_COMMAND_LENGTH, false);
   if (rc != BDM_RC_OK) {
      coreIdcode = 0xFFFFFFFF;
      return rc;
   }
   coreIdcode = idCode;
   log.print("Core IDCODE = %8.8X\n", coreIdcode);

   rc = enableONCE(&onceStatus);
   if (rc == BDM_RC_OK) {
      log.print("enableONCE() status => %s\n", DSC_GetOnceStatusName(onceStatus));
   }
   else {
      log.print("enableONCE() rc = %d (%s)\n", rc, USBDM_GetErrorString(rc));
   }
   return rc;
}

//! Reset Target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetReset(TargetMode_t targetMode) {
   LOGGING_Q;

   USBDM_ErrorCode rc;
   uint32_t idCode;
   OnceStatus_t status;

   if (!DSC_InitialiseDone) {
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         return  rc;
      }
   }
   log.print("(%s)\n", getTargetModeName(targetMode));

   TargetMode_t resetMethod = (TargetMode_t)(targetMode&RESET_METHOD_MASK);
   TargetMode_t resetMode   = (TargetMode_t)(targetMode&RESET_MODE_MASK);
   if (resetMethod == RESET_DEFAULT) {
      resetMethod = RESET_HARDWARE;
   }
   log.print("Modified=(%s)\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));

   volatileRegs.valid = false;

   do {
      // Apply reset
      USBDM_ControlPins(PIN_RESET_LOW);
      milliSleep(bdmOptions.resetDuration);

      // Reset JTAG interface & select core TAP
      rc = enableCoreTAP();
      if (rc != BDM_RC_OK) {
         continue;
      }
      rc = readIDCODE(&idCode, JTAG_CORE_COMMAND_LENGTH, false);
      if (rc != BDM_RC_OK) {
         coreIdcode = 0xFFFFFFFF;
         continue;
      }
      coreIdcode = idCode;
      log.print("Core IDCODE = %8.8X\n", coreIdcode);

      if (resetMode == RESET_SPECIAL) {
         // Do debug request so target resets in debug mode
         rc = targetDebugRequest(&status);
      }
   } while (false);

   USBDM_ControlPins(PIN_RELEASE);
   milliSleep(bdmOptions.resetRecoveryInterval);
   if (rc == BDM_RC_OK) {
      rc = DSC_Connect();
   }
   return rc;
}

//! Read Register
//!
//! @param regNo     - Register number
//! @param regValue  - Value from register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_ReadRegister(unsigned int regNum, unsigned long *regValue) {
   LOGGING_Q;

   USBDM_ErrorCode rc = BDM_RC_ILLEGAL_PARAMS;
   DSC_Registers_t regNo = (DSC_Registers_t)regNum;

   if ((regNo >= DSC_FirstCoreRegister) && (regNo <= DSC_LastCoreRegister)) {
      // Save core register before access as needs to USE code registers
      saveVolatileTargetRegs();
      switch(regNo) {
         case DSC_RegA0: *regValue = volatileRegs.A0; rc = BDM_RC_OK; break;
         case DSC_RegA1: *regValue = volatileRegs.A1; rc = BDM_RC_OK; break;
         case DSC_RegA2: *regValue = volatileRegs.A2; rc = BDM_RC_OK; break;
//         case DSC_RegPC: *regValue = volatileRegs.PC; rc = BDM_RC_OK; break;
         case DSC_RegR0: *regValue = volatileRegs.R0; rc = BDM_RC_OK; break;
         case DSC_RegR4: *regValue = volatileRegs.R4; rc = BDM_RC_OK; break;
         case DSC_RegX0: *regValue = volatileRegs.X0; rc = BDM_RC_OK; break;
         default:        rc = readCoreReg(regNo, regValue);           break;
      }
   }
   else if ((regNo >= DSC_FirstONCERegister) && (regNo <= DSC_LastONCERegister)) {
      rc = readONCEReg((DSC_Registers_t)regNo, regValue);
   }
   else if (regNo == DSC_RegIDCODE) {
      uint32_t idcode = 0;
      rc = readIDCODE(&idcode, JTAG_CORE_COMMAND_LENGTH, false);
      *regValue = idcode;
   }
   else if (regNo == DSC_GdiStatus) {
      //ToDo: Should check if target OK
      *regValue = 1;
      rc = BDM_RC_OK;
   }
   if (rc == BDM_RC_OK) {
      log.print("(%s(0x%lX)) => 0x%lX\n", getRegisterName(regNo), (unsigned long)regNo, (unsigned long)*regValue);
   }
   else {
      log.print("(%d(0x%X)) - illegal\n", (uint32_t)regNo, (uint32_t)regNo);
      *regValue = 0;
   }
   return rc;
}

//! Write Register
//!
//! @param regNum    - Register number
//! @param regValue  - Value for register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_WriteRegister(unsigned int regNum, unsigned long regValue) {
   LOGGING_Q;

   DSC_Registers_t regNo = (DSC_Registers_t)regNum;

   if ((regNo >= DSC_FirstCoreRegister) && (regNo <= DSC_LastCoreRegister)) {
      // Save core register before access as needs to USE code registers
      saveVolatileTargetRegs();
      log.print("(%s(0x%lX), 0x%lX) - doing CORE reg\n", getRegisterName(regNo), (unsigned long)regNo, (unsigned long)regValue);
      switch(regNo) {
         case DSC_RegA0: volatileRegs.A0 = regValue; return BDM_RC_OK;
         case DSC_RegA1: volatileRegs.A1 = regValue; return BDM_RC_OK;
         case DSC_RegA2: volatileRegs.A2 = regValue; return BDM_RC_OK;
//         case DSC_RegPC: volatileRegs.PC = regValue; return BDM_RC_OK;
         case DSC_RegR0: volatileRegs.R0 = regValue; return BDM_RC_OK;
         case DSC_RegR4: volatileRegs.R4 = regValue; return BDM_RC_OK;
         case DSC_RegX0: volatileRegs.X0 = regValue; return BDM_RC_OK;
         default:
            return writeCoreReg((DSC_Registers_t)regNo, regValue);
      }
   }
   else if ((regNo >= DSC_FirstONCERegister) && (regNo <= DSC_LastONCERegister)) {
      log.print("(%s, 0x%lX) - doing ONCE reg\n", getRegisterName(regNo), (unsigned long)regValue);
      return writeONCEReg((DSC_Registers_t)regNo, regValue, 0);
   }
   log.print("(%lu(0x%lX)) <= %lX, - illegal\n", (unsigned long)regValue, (unsigned long)regNo, (unsigned long)regNo);
   return BDM_RC_ILLEGAL_PARAMS;
}

//! Start Target execution at current PC
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetGo() {
   LOGGING_E;

   static const uint8_t writeONCESequence[] = {
         JTAG_MOVE_DR_SCAN,                  // Write to ONCE (DR-CHAIN)
         JTAG_SET_EXIT_IDLE,
         JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH),  // ONCE command
            ONCE_CMD_EXIT|ONCE_CMD_NOREG,
         JTAG_END,                           // Terminate sequence
   };
USBDM_ErrorCode rc;
unsigned long currentOCR;

// Clear single-step
   rc = readONCEReg(DSC_RegOCR, &currentOCR);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = writeONCEReg(DSC_RegOCR, (currentOCR|OCR_PWU)&~OCR_ISC_SINGLE_STEP, 0);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   restoreVolatileTargetRegs();

   // Write EONCE command register - Leave debug & execute
   return executeJTAGSequence(sizeof(writeONCESequence), writeONCESequence, 0, NULL, false);
}

USBDM_DSC_API
USBDM_ErrorCode DSC_TargetStep(void) {
   LOGGING_Q;

   return DSC_TargetStepN(1);
}
//! Execute N instructions from current PC
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetStepN(unsigned numSteps) {
   LOGGING_Q;
   static const uint8_t writeONCESequence[] = {
      JTAG_MOVE_DR_SCAN,                  // Write to ONCE (DR-CHAIN)
      JTAG_SET_EXIT_IDLE,
      JTAG_SHIFT_OUT_Q(ONCE_CMD_LENGTH),
         ONCE_CMD_EXIT|ONCE_CMD_NOREG,    // ONCE command
      JTAG_END,                           // Terminate sequence
      };
   USBDM_ErrorCode rc;
   //uint32_t oldPC, newPC;
   unsigned long currentOCR;

   log.print("(%d)\n", numSteps);

   // Set single-step mode
   // Clear single-step
   rc = readONCEReg(DSC_RegOCR, &currentOCR);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = writeONCEReg(DSC_RegOCR, currentOCR|OCR_PWU|OCR_ISC_SINGLE_STEP, 0);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Set step count
   rc = writeONCEReg(DSC_RegOSCNTR, numSteps-1, 0);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   restoreVolatileTargetRegs();

   // Write EONCE command register - Leave debug & execute
   rc = executeJTAGSequence(sizeof(writeONCESequence), writeONCESequence, 0, NULL, false);
   return rc;
}

//! Halts target execution
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetHalt(void) {
   LOGGING_E;

   USBDM_ErrorCode rc;
   rc = forceDebugRequest();
//   if (rc == BDM_RC_OK)
//      saveVolatileTargetRegs();
   return rc;
}

#if 0
USBDM_ErrorCode targetMassErase(void) {
uint8_t buffer[10];
const uint8_t zeroValue[]          = {0x00, 0x00};
const uint8_t allOnesValue[]       = {0xFF, 0xFF};
const uint8_t massEraseCommand[]   = {0x00, FM_CMD_MASERS};
const uint8_t eraseVerifyCommand[] = {0x00, FM_CMD_RDARY1};
const uint8_t clkdivValue[]        = {0x00, 0x27};
const uint8_t ustatValue[]         = {0x00, 0x80};
int timeout;

   DSC_WriteMemory(MS_XWord, 2, FM_CLKDIV, clkdivValue);
   DSC_ReadMemory( MS_XWord, 2, FM_CLKDIV, buffer);
   if (buffer[1] != (clkdivValue[1]|0x80))
      return BDM_RC_FAIL;
   DSC_WriteMemory(MS_XWord, 2, FM_CNFG, zeroValue);
   DSC_WriteMemory(MS_XWord, 2, FM_PROT, zeroValue);
   DSC_ReadMemory( MS_XWord, 2, FM_USTAT, buffer);
   if (buffer[1] != 0xC0)
      return BDM_RC_FAIL;

   DSC_WriteMemory(MS_PWord, 2, 0x000000, allOnesValue);
   DSC_WriteMemory(MS_XWord, 2, FM_CMD,   massEraseCommand);
   DSC_WriteMemory(MS_XWord, 2, FM_USTAT, ustatValue);
   timeout = 40;
   do {
      DSC_ReadMemory( MS_XWord, 2, FM_USTAT, buffer);
   } while ((--timeout>0) && (buffer[1] != 0xC0));
   if (buffer[1] != 0xC0)
      return BDM_RC_FAIL;

   DSC_WriteMemory(MS_PWord, 2, 0x000000, allOnesValue);
   DSC_WriteMemory(MS_XWord, 2, FM_CMD,   eraseVerifyCommand);
   DSC_WriteMemory(MS_XWord, 2, FM_USTAT, ustatValue);
   timeout = 40;
   do {
      DSC_ReadMemory(MS_XWord, 2, FM_USTAT, buffer);
   } while ((--timeout>0) && (buffer[1] != 0xC4));
   if (buffer[1] != 0xC4)
      return BDM_RC_FAIL;

   return BDM_RC_OK;
}
#endif

//! Set log file for messages
//!
USBDM_DSC_API
void DSC_SetLogFile(FILE *fp) {
   if (fp == 0) {
      UsbdmSystem::Log::setLogFileHandle(USBDM_GetLogFile());
   }
   else {
      UsbdmSystem::Log::setLogFileHandle(fp);
   }
}

//! Get current log file for messages
//!
USBDM_DSC_API
FILE *DSC_GetLogFile(void) {
   return UsbdmSystem::Log::getLogFileHandle();
}

