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
   +============================================================================
   |  16 Jun 2012 | Minor corrections to getKnownAddress                    V4.9
   |   1 Jun 2009 | Created
   +============================================================================
    \endverbatim
*/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "Common.h"
#define  bool int
#include "USBDM_API.h"
#include "USBDM_DSC_API.h"
#include "USBDM_DSC_API_Private.h"
#include "DSC_Utilities.h"

#define DSC_CoreRegisterCount (DSC_LastCoreRegister-DSC_FirstCoreRegister+1)

typedef struct {
   uint8_t          address;
   uint8_t          length;
   const char  *name;
} EonceRegisterDetails_t;

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

typedef struct {
   const char *name;
   unsigned    width;
} targetRegisterDetails_t;

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

//! Obtain string describing the given register's name
//!
//! @param regNo - The register number
//!
//! @return - ptr to static string describing the register
//!
const char *DSC_GetRegisterName(DSC_Registers_t regNo) {
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
unsigned DSC_GetRegisterSize(DSC_Registers_t regNo) {
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

#if 0
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
#endif

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

const char *getMemorySpaceName(MemorySpace_t memorySpace) {
   switch (memorySpace&MS_SPACE) {
   case MS_None :
      return "";
   case MS_Program :
      return "P";
   case MS_Data:
      return "X";
   default:
      return "?";
   }
}

const char *getKnownAddress(MemorySpace_t memorySpace, uint32_t address) {
static char buffer[40];
MemorySpace_t memSpace = (MemorySpace_t)(memorySpace&MS_SPACE);
MemorySpace_t memSize  = (MemorySpace_t)(memorySpace&MS_SIZE);

   if (memSpace == MS_Data)
      switch (address) {
         case FM_CLKDIV:  return   "X:FM_CLKDIV";
         case FM_CNFG:    return   "X:FM_CNFG";
         case FM_SECLO:   return   "X:FM_SECLO";
         case FM_SECHI:   return   "X:FM_SECHI";
         case FM_PROT:    return   "X:FM_PROT";
         case FM_USTAT:   return   "X:FM_USTAT";
         case FM_CMD:     return   "X:FM_CMD";
         case FM_RES1:    return   "X:FM_RES1";
         case COP_CTRL:   return   "X:COP_CTRL";
         case COP_CNTR:   return   "X:COP_CNTR";
         case COP_TOUT:   return   "X:COP_TOUT";
         case GPIOA_PER:  return   "X:GPIOA_PER";
         default:
            break;
      }
   const char *spaceName = getMemorySpaceName(memorySpace);
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
   snprintf(buffer, sizeof(buffer), "%s:%s:%6.6X", spaceName, sizeName, address);
   return buffer;
}
