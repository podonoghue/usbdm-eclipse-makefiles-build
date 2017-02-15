/*! \file
   \brief Utility Routines for programming S12z Flash

   FlashProgramming.cpp

   \verbatim
   Copyright (C) 2008  Peter O'Donoghue

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
\endverbatim

\verbatim
+============================================================================================
| Revision History
+============================================================================================
| 4  Mar 16 | Fixed saving/restoring security regions                       - pgo 4.12.1.90
| 29 Mar 15 | Refactored                                                    - pgo 4.10.7.10 
+-----------+--------------------------------------------------------------------------------
| 20 Jan 15 | Cleanup of programming and readback code                      - pgo V4.10.6.250
| 18 Jan 15 | Addition of DSC mass erase using TCL code                     - pgo V4.10.6.250
| 18 Dec 14 | TCL interface changes                                         - pgo V4.10.6.240
|  1 Dec 14 | Corrected logging printfs()                                   - pgo V4.10.6.240
| 15 Sep 14 | Changed error check order in VerifyFlash()                    - pgo V4.10.6.190
| 17 Aug 14 | Changed SDID structure to support multiple masks              - pgo V4.10.6.180
| 12 Jul 14 | Added getCommonFlashProgram(), changed getFlashProgram() etc  - pgo V4.10.6.170
| 26 Feb 14 | 4.10.6.120 removed buffer clearing initSmallTargetBuffer()    - pgo
|  6 Nov 13 | 4.10.6.60 Changes to support PAxx small programmer            - pgo
|  4 Jun 13 | 4.10.5.20 Set controller address in partitionFlexNVM()        - pgo
| 28 Dec 12 | 4.10.4 Changed handling of security area (& erasing)          - pgo
| 28 Dec 12 | 4.10.4 Changed TCL interface error handling                   - pgo
| 16 Dec 12 | 4.10.4 Moved Check of SDID to before Mass erase (HCS08)       - pgo
| 14 Dec 12 | 4.10.4 Added custom security                                  - pgo
| 30 Nov 12 | 4.10.4 Changed logging                                        - pgo
| 30 Oct 12 | 4.10.4 Added MS_FAST option for HCS12/HCS12                   - pgo
| 30 Sep 12 | 4.10.2 RAM write added                                        - pgo
| 26 Aug 12 | 4.10.0 JTAG/SWD combined code                                 - pgo
|  1 Jun 12 | 4.9.5 Now handles arbitrary number of memory regions          - pgo
| 30 May 12 | 4.9.5 Re-write of DSC programming                             - pgo
| 12 Apr 12 | 4.9.4 Changed handling of empty images                        - pgo
| 30 Mar 12 | 4.9.4 Added Intelligent security option                       - pgo
| 25 Feb 12 | 4.9.1 Fixed alignment rounding problem on partial phrases     - pgo
| 10 Feb 12 | 4.9.0 Major changes for HCS12 (Generalised code)              - pgo
| 20 Nov 11 | 4.8.0 Major changes for Coldfire+ (Generalised code)          - pgo
|  4 Oct 11 | 4.7.0 Added progress dialogues                                - pgo
| 23 Apr 11 | 4.6.0 Major changes for CFVx programming                      - pgo
|  6 Apr 11 | 4.6.0 Major changes for ARM programming                       - pgo
|  3 Jan 11 | 4.4.0 Major changes for XML device files etc                  - pgo
| 17 Sep 10 | 4.0.0 Fixed minor bug in isTrimLocation()                     - pgo
| 30 Jan 10 | 2.0.0 Changed to C++                                          - pgo
|           |       Added paged memory support                              - pgo
| 15 Dec 09 | 1.1.1 setFlashSecurity() was modifying image unnecessarily    - pgo
| 14 Dec 09 | 1.1.0 Changed Trim to use linear curve fitting                - pgo
|           |       FTRIM now combined with image value                     - pgo
|  7 Dec 09 | 1.0.3 Changed SOPT value to disable RESET pin                 - pgo
| 29 Nov 09 | 1.0.2 Bug fixes after trim testing                            - pgo
| 17 Nov 09 | 1.0.0 Created                                                 - pgo
+============================================================================================
\endverbatim
*/
#define _WIN32_IE 0x0500 //!< Required for common controls?

#define TARGET S12Z

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <ctype.h>
#include <memory.h>
#include "Common.h"
#include "UsbdmSystem.h"
#include "USBDM_API.h"
#include "TargetDefines.h"
#include "Utils.h"
#include "Names.h"
#include "ProgressTimer.h"
#include "SimpleSRecords.h"
#if (TARGET == ARM)
#include "STM32F100xx.h"
#include "ArmDefinitions.h"
#elif TARGET == MC56F80xx
#include "USBDM_DSC_API.h"
#endif
#include "UsbdmTclInterpreterFactory.h"
#include "WxPlugin.h"
#ifdef GDI
#include "GDI.h"
#include "MetrowerksInterface.h"
#endif
#include "Names.h"
#include "PluginHelper.h"

#include "FlashProgrammer_S12Z.h"

static const TargetType_t targetType = T_S12Z;

#pragma pack(1)
//! Header at the start of flash programming code (describes flash code)
struct LargeTargetImageHeader {
   uint32_t         loadAddress;       //!< Address where to load this image
   uint32_t         entry;             //!< Pointer to entry routine (for currently loaded routine)
   uint32_t         capabilities;      //!< Capabilities of routine
   uint32_t         watchdogAddress;   //!< Address of CPMUCOP register
   uint32_t         calibFactor;       //!< Calibration factor for speed determination
   uint32_t         flashData;         //!< Pointer to information about operation
};

//! Header at the start of timing data (controls program action & holds result)
struct LargeTargetTimingDataHeader {
   uint16_t         flags;             //!< Controls actions of routine
   uint16_t         errorCode;         //!< Error code from action
   uint16_t         controller;        //!< Ptr to flash controller (unused)
   uint32_t         timingCount;       //!< Timing count
};

//! Header at the start of flash programming buffer (controls program action)
struct LargeTargetFlashDataHeader {
   uint32_t         flags;             //!< Controls actions of routine
   uint32_t         controller;        //!< Ptr to flash controller
   uint32_t         frequency;         //!< Target frequency (kHz)
   uint16_t         errorCode;         //!< Error code from action
   uint16_t         sectorSize;        //!< Size of flash sectors (minimum erase size)
   uint32_t         address;           //!< Memory address being accessed (reserved/page/address)
   uint32_t         dataSize;          //!< Size of memory range being accessed
   uint32_t         dataAddress;       //!< Ptr to data to program
};
//! Holds program execution result
struct ResultStruct {
   uint32_t         flags;             //!< Incomplete actions of routine
   uint32_t         reserved1;
   uint32_t         reserved2;
   uint16_t         errorCode;         //!< Error code from action
   uint16_t         padding;
};
#pragma pack()

/* ======================================================================
 * Notes on BDM clock source (for default CLKSW):
 *
 *  CPU    BDM clock
 *  ----------------------
 *  RS08   bus clock
 *  HCS08  bus clock
 *  HC12   bus clock
 *  CFV1   bus clock
 *
 */
//=======================================================================================

inline uint16_t swap16(uint16_t data) {
   return ((data<<8)&0xFF00) + ((data>>8)&0xFF);
}
inline uint32_t swap32(uint32_t data) {
   return ((data<<24)&0xFF000000) + ((data<<8)&0xFF0000) + ((data>>8)&0xFF00) + ((data>>24)&0xFF);
}

inline uint32_t getData32Be(uint8_t *data) {
   return (data[0]<<24)+(data[1]<<16)+(data[2]<<8)+data[3];
}
inline uint32_t getData32Le(uint8_t *data) {
   return (data[3]<<24)+(data[2]<<16)+(data[1]<<8)+data[0];
}
inline uint32_t getData16Be(uint8_t *data) {
   return (data[0]<<8)+data[1];
}
inline uint32_t getData16Le(uint8_t *data) {
   return (data[1]<<8)+data[0];
}
inline uint32_t getData32Be(uint16_t *data) {
   return (data[0]<<16)+data[1];
}
inline uint32_t getData32Le(uint16_t *data) {
   return (data[1]<<16)+data[0];
}
inline const uint8_t *getData4x8Le(uint32_t data) {
   static uint8_t data8[4];
   data8[0]= data;
   data8[1]= data>>8;
   data8[2]= data>>16;
   data8[3]= data>>24;
   return data8;
}
inline const uint8_t *getData4x8Be(uint32_t data) {
   static uint8_t data8[4];
   data8[0]= data>>24;
   data8[1]= data>>16;
   data8[2]= data>>8;
   data8[3]= data;
   return data8;
}
inline const uint8_t *getData2x8Le(uint32_t data) {
   static uint8_t data8[2];
   data8[0]= data;
   data8[1]= data>>8;
   return data8;
}
inline const uint8_t *getData2x8Be(uint32_t data) {
   static uint8_t data8[2];
   data8[0]= data>>8;
   data8[1]= data;
   return data8;
}

#if (TARGET == ARM) || (TARGET == MC56F80xx)
#define targetToNative16(x) (x)
#define targetToNative32(x) (x)
#define nativeToTarget16(x) (x)
#define nativeToTarget32(x) (x)

inline uint32_t getData32Target(uint8_t *data) {
   return getData32Le(data);
}
inline uint32_t getData16Target(uint8_t *data) {
   return *data;
}
inline uint32_t getData32Target(uint16_t *data) {
   return getData32Le(data);
}
inline uint32_t getData16Target(uint16_t *data) {
   return *data;
}
#else
#define targetToNative16(x) swap16(x)
#define targetToNative32(x) swap32(x)
#define nativeToTarget16(x) swap16(x)
#define nativeToTarget32(x) swap32(x)

inline uint32_t getData32Target(uint8_t *data) {
   return getData32Be(data);
}
inline uint32_t getData16Target(uint8_t *data) {
   return getData16Be(data);
}
#endif

//=======================================================================
//
FlashProgrammer_S12Z::FlashProgrammer_S12Z() :
      initTargetDone(false),
      currentFlashOperation(OpNone),
      currentFlashAlignment(0),
      doRamWrites(false),
      securityNeedsSelectiveErase(false) {
   LOGGING_E;
}

//=======================================================================
//
FlashProgrammer_S12Z::~FlashProgrammer_S12Z() {
   LOGGING_E;
}

#if (TARGET == HCS08) || (TARGET == HCS12)
//=======================================================================
//! Gets the page number portion of a physical address (Flash)
//!
//! @param memoryRegionPtr - memory region to check
//! @param physicalAddress - address to examine
//! @param pageNo          - corresponding page number
//!
USBDM_ErrorCode FlashProgrammer_S12Z::getPageAddress(MemoryRegionConstPtr memoryRegionPtr, uint32_t physicalAddress, uint8_t *pageNo) {
   LOGGING_Q;
   *pageNo = 0x00;
   if ((memoryRegionPtr == NULL) || !memoryRegionPtr->contains(physicalAddress)) {
      log.error("A=0x%06X - Invalid Flash address\n", physicalAddress);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (memoryRegionPtr->getAddressType() != AddrPaged) {
      log.print("A=0x%06X - Not paged\n", physicalAddress);
      return PROGRAMMING_RC_OK;
   }
   uint32_t ppageAddress = memoryRegionPtr->getPageAddress();
   if (ppageAddress == 0) {
      log.print("A=0x%06X - Not mapped\n", physicalAddress);
      return PROGRAMMING_RC_OK;
   }
   uint32_t virtualAddress = (physicalAddress&0xFFFF);
   uint16_t pageNum16 = memoryRegionPtr->getPageNo(physicalAddress);
   if (pageNum16 == MemoryRegion::NoPageNo) {
      log.print("A=0x%06X - No page #!\n", physicalAddress);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   *pageNo = (uint8_t)pageNum16;
   log.print("(0x%06X) - PPAGE=%2.2X (Mapped Address=%06X)\n", physicalAddress, *pageNo, ((*pageNo)<<16)|virtualAddress);

   return PROGRAMMING_RC_OK;
}

//=======================================================================
//! Set PAGE registers (PPAGE/EPAGE)
//!
//! @param physicalAddress - memory address being accessed
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::setPageRegisters(uint32_t physicalAddress) {
   LOGGING_Q;

   // Process each flash region
   USBDM_ErrorCode rc = BDM_RC_OK;
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      if (memoryRegionPtr && memoryRegionPtr->contains(physicalAddress)) {
         if (memoryRegionPtr->getAddressType() != AddrPaged) {
            return PROGRAMMING_RC_OK;
         }
         uint32_t ppageAddress   = memoryRegionPtr->getPageAddress();
         uint32_t virtualAddress = (physicalAddress&0xFFFF);
         if (ppageAddress == 0) {
            // Not paged memory
            log.print("Not mapped (VirtAddr=PhyAddr=%06X)\n", physicalAddress);
            return PROGRAMMING_RC_OK;
         }
         uint16_t pageNum16 = memoryRegionPtr->getPageNo(physicalAddress);
         if (pageNum16 == MemoryRegion::NoPageNo) {
            return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
         }
         uint8_t pageNum = (uint8_t)pageNum16;
         log.print("Setting E/PPAGE(0x%04X)=%2.2X (PhyAddr=%06X, VirAddr=%04X)\n", ppageAddress, pageNum, physicalAddress, virtualAddress);
         if (bdmInterface->writeMemory(1, 1, ppageAddress, &pageNum) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_PPAGE_FAIL;
         }
         uint8_t pageNumRead;
         if (bdmInterface->readMemory(1, 1, ppageAddress, &pageNumRead) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_PPAGE_FAIL;
         }
         if (pageNum != pageNumRead) {
            return PROGRAMMING_RC_ERROR_PPAGE_FAIL;
         }
         return BDM_RC_OK;
      }
   }
   return rc;
}
#endif

//=============================================================================
//! Connects to the target. \n
//! - Resets target to special mode
//! - Connects
//! - Runs initialisation script
//!
//! @return error code, see \ref USBDM_ErrorCode \n
//!   BDM_OK                       => Success \n
//!   PROGRAMMING_RC_ERROR_SECURED => Device is connected but secured (target connection speed may have been approximated)\n
//!                           USBDM_getStatus() may be used to determine connection method.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::resetAndConnectTarget(void) {
   LOGGING;
   USBDM_ErrorCode rc;

   if (device->getTargetName().empty()) {
      return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }
   flashReady     = false;
   initTargetDone = false;

   // Reset to special mode to allow unlocking of Flash
   bdmInterface->connect();
   rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   if (rc != BDM_RC_OK) {
      bdmInterface->connect();
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE));
   }
   if (rc == BDM_RC_SECURED) {
      log.error("... Device is secured\n");
      return PROGRAMMING_RC_ERROR_SECURED;
   }
   if (rc != BDM_RC_OK) {
      log.error( "... Failed Reset, %s!\n", bdmInterface->getErrorString(rc));
      return rc; //PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   // Try auto Connect to target
   // BDM_RC_BDM_EN_FAILED usually means a secured device
   rc = bdmInterface->connect();
   switch (rc) {
   case BDM_RC_SECURED:
   case BDM_RC_BDM_EN_FAILED:
      // Treat as secured & continue
      log.error( "... Partial Connect, rc = %s!\n", bdmInterface->getErrorString(rc));
      rc = PROGRAMMING_RC_ERROR_SECURED;
      break;
   case BDM_RC_OK:
      rc = PROGRAMMING_RC_OK;
      break;
   default:
      log.error( "... Failed Connect, rc = %s!\n", bdmInterface->getErrorString(rc));
      return rc; //PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   // Use TCL script to set up target
   USBDM_ErrorCode rc2 = initialiseTarget();
   if (rc2 != PROGRAMMING_RC_OK) {
      rc = rc2;
   }
   return rc;
}

//=============================================================================
//! Reads the System Device Identification Register
//!
//! @param targetSDID - location to return SDID
//! @param doInit - reset & re-connect to target first
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//! @note Assumes the target has been reset in SPECIAL mode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::readTargetChipId(uint32_t *targetSDID, bool doInit) {
   LOGGING_E;
   doInit = doInit || (targetType == T_ARM);
   const int SDIDLength = 4;
   uint8_t SDIDValue[SDIDLength];

   *targetSDID = 0x0000;

   if (device->getTargetName().empty()) {
      log.error("Target name not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (doInit) {
      USBDM_ErrorCode rc = resetAndConnectTarget();
      if (rc != PROGRAMMING_RC_OK) {
         log.error("Failed resetAndConnectTarget()\n");
         return rc;
      }
   }
   if (bdmInterface->readMemory(SDIDLength, SDIDLength, device->getSDIDAddress(), SDIDValue) !=  BDM_RC_OK) {
      log.error("A=0x%06X - Failed bdmInterface->readMemory()\n", device->getSDIDAddress());
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   uint32_t testValue;
   if (SDIDLength == 4) {
      *targetSDID = getData32Target(SDIDValue);
      testValue = *targetSDID;
   }
   else {
      *targetSDID = getData16Target(SDIDValue);
      testValue   = (uint32_t)(int32_t)(int16_t)*targetSDID;
   }
   // Do a sanity check on SDID (may get these values if secured w/o any error being signaled)
   if ((testValue == 0xFFFFFFFF) || (testValue == 0x0)) {
      log.error("A=0x%06X - Value invalid (0x%08X)\n", device->getSDIDAddress(), testValue);
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   log.print("A=0x%06X => 0x%08X\n", device->getSDIDAddress(), testValue);
   return PROGRAMMING_RC_OK;
}

//=============================================================================
//! Check the target SDID agrees with device parameters
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes the target has been connected to
//!
USBDM_ErrorCode FlashProgrammer_S12Z::confirmSDID() {
   LOGGING_E;
   uint32_t targetSDID;
   USBDM_ErrorCode rc;

   if (device->getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Don't check Target SDID if zero
   if ((device->getSDID().mask == 0x0000) || (device->getSDID().value == 0x0000)) {
      log.print("V=0x0000 => Skipping check\n");
      return PROGRAMMING_RC_OK;
   }
   // Get SDID from target
   rc = readTargetChipId(&targetSDID);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("M=0x%8.8X, V=0x%8.8X => Failed, error reading SDID, reason = %s\n",
                     device->getSDID().mask,
                     device->getSDID().value,
            bdmInterface->getErrorString(rc));
      // Return this error even though the cause may be different
      return PROGRAMMING_RC_ERROR_WRONG_SDID;
   }
   if (!device->isThisDevice(targetSDID)) {
      log.error("M=0x%8.8X, V=0x%8.8X => Failed (Target SDID=0x%8.8X)\n",
            device->getSDID().mask,
            device->getSDID().value,
            targetSDID);
      return PROGRAMMING_RC_ERROR_WRONG_SDID;
   }
   log.print("V=%8.8X => OK\n", targetSDID);
   return PROGRAMMING_RC_OK;
}

//=============================================================================
//! Prepares the target \n
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes target has been reset & connected
//!
USBDM_ErrorCode FlashProgrammer_S12Z::initialiseTarget() {
   LOGGING;
   USBDM_ErrorCode rc;
   if (initTargetDone) {
      log.print("Already done, skipped\n");
      return PROGRAMMING_RC_OK;
   }
#if (TARGET == RS08) || (TARGET == HCS08) || (TARGET == S12Z) || (TARGET == HCS12) || (TARGET == CFV1)
   uint8_t          mask;
#if TARGET == RS08
   mask = RS08_BDCSCR_CLKSW;
#elif TARGET == HCS08
   mask = HC08_BDCSCR_CLKSW;
#elif TARGET == HCS12
   mask = HC12_BDMSTS_CLKSW;
#elif TARGET == S12Z
   mask = HC12_BDMSTS_CLKSW;
#elif TARGET == CFV1
   mask = CFV1_XCSR_CLKSW;
#endif

   unsigned long BDMStatusReg;
   rc = bdmInterface->readStatusReg(&BDMStatusReg);
   if ((BDMStatusReg&mask) == 0) {
      log.print("Setting BDCSCR_CLKSW\n");
      BDMStatusReg |= mask;
      rc = bdmInterface->writeControlReg(BDMStatusReg);
      rc = bdmInterface->connect();
   }
#endif
   char args[200] = "initTarget \"";
   char *argPtr = args+strlen(args);

   // Add address of each flash region
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      if (!memoryRegionPtr->isProgrammableMemory()) {
         continue;
      }
      sprintf(argPtr, "{%s 0x%04X} ",
            memoryRegionPtr->getMemoryTypeName(),
            memoryRegionPtr->getDummyAddress()&0xFFFF);
      argPtr += strlen(argPtr);
   }
   *argPtr++ = '\"';
   *argPtr++ = '\0';

   rc = runTCLCommand(args);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Failed - initTarget TCL failed\n");
      return rc;
   }
   initTargetDone = true;
   return rc;
}

//=============================================================================
//! Prepares the target for Flash and eeprom operations. \n
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes target has been reset & connected
//!
USBDM_ErrorCode FlashProgrammer_S12Z::initialiseTargetFlash() {
   LOGGING;
   USBDM_ErrorCode rc;

   // Check if already configured
   if (flashReady) {
      return PROGRAMMING_RC_OK;
   }
#if (TARGET==RS08) || (TARGET==HCS08) || (TARGET==HCS12) || (TARGET==S12Z) || (TARGET==CFV1)
   unsigned long busFrequency = 0;
#if (TARGET==RS08) || (TARGET==HCS08) || (TARGET==CFV1)
   // Configure the target clock for Flash programming
   rc = configureTargetClock(&busFrequency);
#elif (TARGET==HCS12)  || (TARGET==S12Z)
   // Configure the target clock for Flash programming
   rc = getTargetBusSpeed(&busFrequency);
   if (rc == PROGRAMMING_RC_ERROR_SPEED_APPROX) {
      // Estimated speed is not sufficiently accurate for programming

      // Check if user has supplied a speed to use
      if (device->getConnectionFreq() == 0)
         return PROGRAMMING_RC_ERROR_SPEED_APPROX;

      // Set user supplied speed & confirm SDID as basic communication check
      bdmInterface->setSpeedHz(device->getConnectionFreq()/1000);
      if (confirmSDID() != PROGRAMMING_RC_OK)
         return PROGRAMMING_RC_ERROR_SPEED_APPROX;

      busFrequency = device->getConnectionFreq()*device->getBDMtoBUSFactor();
      log.print("Using user-supplied bus speed = %lu kHz\n",
            busFrequency/1000);
   }
   else
#endif
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Failed to get speed\n");
      return rc;
   }
   // Convert to kHz
   uint32_t targetBusFrequency = (uint32_t)round(busFrequency/1000.0);
   flashOperationInfo.targetBusFrequency = targetBusFrequency;

   log.print("Target Bus Frequency = %ld kHz\n", (unsigned long)targetBusFrequency);
#endif

   char buffer[100];
   sprintf(buffer, "initFlash %d", flashOperationInfo.targetBusFrequency);
   rc = runTCLCommand(buffer);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Failed, initFlash TCL failed\n");
      return rc;
   }
   // Flash is now ready for programming
   flashReady = TRUE;
   return PROGRAMMING_RC_OK;
}

//=======================================================================
//! \brief Does Mass Erase of Target memory using TCL script.
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::massEraseTarget(bool resetTarget) {
   LOGGING;

   if (resetTarget) {
      resetAndConnectTarget();
   }
   SetProgrammingMode pmode(bdmInterface);

   if (progressTimer != NULL) {
      progressTimer->restart("Mass Erasing Target");
   }
   USBDM_ErrorCode rc = initialiseTarget();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Do Mass erase using TCL script
   rc = runTCLCommand("massEraseTarget");
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
// Don't reset device as it may only be temporarily unsecured!
   return PROGRAMMING_RC_OK;
}

//==============================================================================
// Flag masks
#define DO_INIT_FLASH         (1<<0) // Do initialisation of flash
#define DO_ERASE_BLOCK        (1<<1) // Erase entire flash block e.g. Flash, FlexNVM etc
#define DO_ERASE_RANGE        (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE  (1<<3) // Blank check region
#define DO_PROGRAM_RANGE      (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE       (1<<5) // Verify range
#define DO_PARTITION_FLEXNVM  (1<<7) // Program FlexNVM DFLASH/EEPROM partitioning
#define DO_TIMING_LOOP        (1<<8) // Counting loop to determine clock speed

// 9 - 14 reserved
#define IS_COMPLETE           (1<<15)

// Capability masks
#define CAP_ERASE_BLOCK        (1<<1)
#define CAP_ERASE_RANGE        (1<<2)
#define CAP_BLANK_CHECK_RANGE  (1<<3)
#define CAP_PROGRAM_RANGE      (1<<4)
#define CAP_VERIFY_RANGE       (1<<5)
#define CAP_PARTITION_FLEXNVM  (1<<7)
#define CAP_TIMING             (1<<8)

#define CAP_DSC_OVERLAY        (1<<11) // Indicates DSC code in pMEM overlays xRAM
#define CAP_DATA_FIXED         (1<<12) // Indicates TargetFlashDataHeader is at fixed address
//
#define CAP_RELOCATABLE        (1<<15) // Code may be relocated

#define OPT_SMALL_CODE         (0x80)
#define OPT_PAGED_ADDRESSES    (0x40)
#define OPT_WDOG_ADDRESS       (0x20)

//=======================================================================
//! Loads the default Flash programming code to target memory
//!
//! @param  flashOperation    Intended operation in case of partial loading
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Will load device program code or flashRegion specific if necessary
//! @note - see loadTargetProgram(MemoryRegionConstPtr, FlashOperation) for details
//!
USBDM_ErrorCode FlashProgrammer_S12Z::loadTargetProgram(FlashOperation flashOperation) {
   LOGGING;
   FlashProgramConstPtr flashProgram = device->getFlashProgram();
   if (!flashProgram) {
      log.error("No flash program found for target\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return loadTargetProgram(flashProgram, flashOperation);
}

//==============================================================================
//! Loads the given Flash programming code to target memory
//!
//! @param  memoryRegionPtr   Memory region to load programming code for
//! @param  flashOperation    Intended operation in case of partial loading
//!
//!
//! @return error code, see \ref USBDM_ErrorCode
//! @note - see loadTargetProgram(MemoryRegionConstPtr, FlashOperation) for details
//!
USBDM_ErrorCode FlashProgrammer_S12Z::loadTargetProgram(MemoryRegionConstPtr memoryRegionPtr, FlashOperation flashOperation) {
   LOGGING_Q;

   FlashProgramConstPtr flashProgram = memoryRegionPtr->getFlashprogram();
   if (!flashProgram) {
      // Try to get device general routines
      flashProgram = device->getCommonFlashProgram();
   }
   if (!flashProgram) {
      log.error("Failed, no flash program found for target\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return loadTargetProgram(flashProgram, flashOperation);
}

//==============================================================================
//! Loads the given Flash programming code to target memory
//!
//! @param  flashProgram      Flash program to load
//! @param  flashOperation    Intended operation in case of partial loading
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Assumes the target has been connected to
//!         Confirms download (if necessary) and checks RAM boundaries.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::loadTargetProgram(FlashProgramConstPtr flashProgram, FlashOperation flashOperation) {
   LOGGING;
   uint8_t     buffer[4000] = {0};

   log.print("Op=%s\n", getFlashOperationName(flashOperation));
   switch(flashOperation) {
      case OpSelectiveErase:
      case OpBlockErase:
      case OpBlankCheck:
      case OpProgram:
      case OpVerify:
      case OpPartitionFlexNVM:
      case OpTiming:
         break;
      default:
         currentFlashOperation = OpNone;
         log.print("No target program load needed\n");
         return BDM_RC_OK;
   }
   // Reload flash code if
   //  - code changed
   //  - operation changed
   //  - alignment changed
   if (currentFlashProgram != flashProgram)  {
      log.print("Reloading due to change in flash code\n");
   }
   else if ((currentFlashOperation == OpNone) || (currentFlashOperation != flashOperation)) {
      log.print("Reloading due to change in flash operation\n");
   }
   else if (currentFlashAlignment != flashOperationInfo.alignment) {
      log.print("Reloading due to change in flash alignment\n");
   }
   else {
      log.print("Re-using existing code\n");
      return PROGRAMMING_RC_OK;
   }
   currentFlashOperation = OpNone;

   unsigned size; // In uint8_t
   uint32_t loadAddress;
   USBDM_ErrorCode rc = loadSRec(flashProgram->getFlashProgram().c_str(),
                                 buffer,
                                 sizeof(buffer)/sizeof(buffer[0]),
                                 &size,
                                 &loadAddress);
   if (rc !=  BDM_RC_OK) {
      log.error("Failed, loadSRec() failed\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }

   memset(&targetProgramInfo, 0, sizeof(targetProgramInfo));

#if TARGET == MC56F80xx
   MemorySpace_t memorySpace = MS_XWord;
#else
   MemorySpace_t memorySpace = MS_Byte;
#endif
   // Probe RAM buffer
   rc = probeMemory(memorySpace, device->getRamStart());
   if (rc == BDM_RC_OK) {
      rc = probeMemory(memorySpace, device->getRamEnd());
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, probeMemory() failed\n");
      return rc;
   }
#if (TARGET==HCS08)
   LoadInfoStruct *infoPtr = (LoadInfoStruct *)buffer;
   targetProgramInfo.smallProgram = (infoPtr->flags&OPT_SMALL_CODE) != 0;
   if (targetProgramInfo.smallProgram) {
      return loadSmallTargetProgram(buffer, loadAddress, size, flashProgram, flashOperation);
   }
   else {
      return loadLargeTargetProgram(buffer, loadAddress, size, flashProgram, flashOperation);
   }
#else
   targetProgramInfo.smallProgram = false;
   return loadLargeTargetProgram(buffer, loadAddress, size, flashProgram, flashOperation);
#endif
}

//=======================================================================
//! Loads the given Flash programming code to target memory
//!
//! @param  buffer            buffer containing program image
//! @param  loadAddress       address to load image at
//! @param  size              size of image (in uint8_t)
//! @param  flashProgram      flash program corresponding to image
//! @param  flashOperation    intended operation in case of partial loading
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Assumes the target has been connected to
//!         Confirms download (if necessary) and checks RAM upper boundary.
//!         targetProgramInfo is updated with load information
//!
//! Target Memory map
//! +---------------------------------------------------+ -+
//! |   LargeTargetImageHeader  flashProgramHeader;     |  |
//! +---------------------------------------------------+   > Unchanging written once
//! |   Flash program code....                          |  |
//! +---------------------------------------------------+ -+
//!
USBDM_ErrorCode FlashProgrammer_S12Z::loadLargeTargetProgram(uint8_t    *buffer,
                                                        uint32_t              loadAddress,
                                                        uint32_t              size,
                                                        FlashProgramConstPtr  flashProgram,
                                                        FlashOperation        flashOperation) {
   LOGGING;
   log.print("Op=%s\n", getFlashOperationName(flashOperation));

   // Find 'header' in download image
   uint32_t headerAddress = loadAddress; // Header is at start image
   LargeTargetImageHeader *headerPtr = (LargeTargetImageHeader*) (buffer+(headerAddress-loadAddress));
   if (headerPtr > (LargeTargetImageHeader*)(buffer+size)) {
      log.error("Header ptr out of range\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Save the programming data structure
   uint32_t codeLoadAddress   = targetToNative32(headerPtr->loadAddress);
   uint32_t codeEntry         = targetToNative32(headerPtr->entry);
   uint32_t capabilities      = targetToNative32(headerPtr->capabilities);
   uint32_t dataHeaderAddress = targetToNative32(headerPtr->flashData);
   uint32_t calibFactor       = targetToNative32(headerPtr->calibFactor);

   log.print("Loaded Image (unmodified) :\n");
   log.print("   flashProgramHeader headerAddress   = 0x%08X\n",     headerAddress);
   log.print("   flashProgramHeader.loadAddress     = 0x%08X\n",     codeLoadAddress);
   log.print("   flashProgramHeader.entry           = 0x%08X\n",     codeEntry);
   log.print("   flashProgramHeader.capabilities    = 0x%08X(%s)\n", capabilities, getProgramCapabilityNames(capabilities));
   log.print("   flashProgramHeader.flashData       = 0x%08X\n",     dataHeaderAddress);

   if (codeLoadAddress != loadAddress) {
      log.error("Inconsistent actual (0x%06X) and image load addresses (0x%06X).\n",
            loadAddress, codeLoadAddress);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   uint32_t codeLoadSize = size*sizeof(uint8_t);

   if ((capabilities&CAP_RELOCATABLE)!=0) {
      // Relocate Code
      codeLoadAddress = (device->getRamStart()+3)&~3; // Relocate to start of RAM
      if (loadAddress != codeLoadAddress) {
         log.print("Loading at non-default address, load@0x%04X (relocated from=%04X)\n",
               codeLoadAddress, loadAddress);
         // Relocate entry point
         codeEntry += codeLoadAddress - loadAddress;
      }
   }
#if TARGET != MC56F80xx
   if ((codeLoadAddress < device->getRamStart()) || (codeLoadAddress > device->getRamEnd())) {
      log.error("Image load address is invalid.\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if ((codeEntry < device->getRamStart()) || (codeEntry > device->getRamEnd())) {
      log.error("Image Entry point is invalid.\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
#endif
#if TARGET == MC56F80xx
   // Update location of where programming info will be located
   if ((capabilities&CAP_DSC_OVERLAY)!=0) {
      // Loading code into shared RAM - load data offset by code size
      log.print(" - loading data into overlayed RAM @ 0x%06X\n", dataHeaderAddress);
   }
   else {
      // Loading code into separate program RAM - load data RAM separately
      log.print(" - loading data into separate RAM @ 0x%06X\n", dataHeaderAddress);
   }
#else
   if ((capabilities&CAP_DATA_FIXED)==0) {
      // Relocate Data Entry to immediately after code
      dataHeaderAddress = (codeLoadAddress + size + 1)&~0x1;
      log.print("Relocating flashData @ 0x%06X\n", dataHeaderAddress);
   }
#endif

   // Required flash flashAlignmentMask
   uint32_t flashAlignmentMask = flashOperationInfo.alignment-1;
   uint32_t procAlignmentMask  = 1-1;

   // Save location of entry point
   targetProgramInfo.entry        = codeEntry;
   // Were to load flash buffer (including header)
   targetProgramInfo.headerAddress  = dataHeaderAddress;
   // Save offset of RAM data buffer
   uint32_t dataLoadAddress = dataHeaderAddress+sizeof(LargeTargetFlashDataHeader);
   // Align buffer address to worse case alignment for processor read
   dataLoadAddress = (dataLoadAddress+procAlignmentMask)&~procAlignmentMask;
   targetProgramInfo.dataOffset   = dataLoadAddress-dataHeaderAddress;
   // Save maximum size of the buffer (in uint8_t)
   targetProgramInfo.maxDataSize  = device->getRamEnd()-dataLoadAddress+1;
   // Align buffer size to worse case alignment for processor read
   targetProgramInfo.maxDataSize  = targetProgramInfo.maxDataSize&~procAlignmentMask;
   // Align buffer size to flash alignment requirement
   targetProgramInfo.maxDataSize  = targetProgramInfo.maxDataSize&~flashAlignmentMask;
   // Save target program capabilities
   targetProgramInfo.capabilities = capabilities;
   // Save clock calibration factor
   targetProgramInfo.calibFactor    = calibFactor;

   log.print("AlignmentMask=0x%08X\n",
         flashAlignmentMask);
   log.print("Program code[0x%06X...0x%06X]\n",
         codeLoadAddress, codeLoadAddress+size-1);
   log.print("Parameters[0x%06X...0x%06X]\n",
         targetProgramInfo.headerAddress,
         targetProgramInfo.headerAddress+targetProgramInfo.dataOffset-1);
   log.print("RAM buffer[0x%06X...0x%06X]\n",
         targetProgramInfo.headerAddress+targetProgramInfo.dataOffset,
         targetProgramInfo.headerAddress+targetProgramInfo.dataOffset+targetProgramInfo.maxDataSize-1);
   log.print("Entry=0x%06X\n", targetProgramInfo.entry);

   // RS08, HCS08, HCS12 are byte aligned
   // MC56F80xx deals with word addresses which are always aligned
   if ((codeLoadAddress & procAlignmentMask) != 0) {
      log.error("CodeLoadAddress is not aligned\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (((targetProgramInfo.headerAddress+targetProgramInfo.dataOffset) & procAlignmentMask) != 0) {
      log.error("FlashProgramHeader.dataOffset is not aligned\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
#if (TARGET != ARM)
   if ((targetProgramInfo.entry & procAlignmentMask) != 0){
      log.error("FlashProgramHeader.entry is not aligned\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
#else
   if ((targetProgramInfo.entry & procAlignmentMask) != 1){
      log.error("FlashProgramHeader.entry is not aligned\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
#endif
   // Sanity check buffer
   if (((uint32_t)(targetProgramInfo.headerAddress+targetProgramInfo.dataOffset)<device->getRamStart()) ||
       ((uint32_t)(targetProgramInfo.headerAddress+targetProgramInfo.dataOffset+targetProgramInfo.maxDataSize-1)>device->getRamEnd())) {
      log.error("Data buffer location [0x%06X..0x%06X] is outside target RAM [0x%06X-0x%06X]\n",
            targetProgramInfo.headerAddress+targetProgramInfo.dataOffset,
            targetProgramInfo.headerAddress+targetProgramInfo.dataOffset+targetProgramInfo.maxDataSize-1,
            device->getRamStart(), device->getRamEnd());
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if ((dataLoadAddress+40) > device->getRamEnd()) {
      log.error("Data buffer is too small [0x%X..0x%X] \n", dataLoadAddress, device->getRamEnd());
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
#if TARGET == MC56F80xx
   MemorySpace_t memorySpace = MS_PWord;
#elif TARGET == ARM
   MemorySpace_t memorySpace = MS_Long;
#elif (TARGET == S12Z)
   MemorySpace_t memorySpace = (MemorySpace_t)MS_Word;
#elif (TARGET == HCS08) || (TARGET == HCS12)
   MemorySpace_t memorySpace = (MemorySpace_t)(MS_Fast|MS_Byte);
#else
   MemorySpace_t memorySpace = MS_Byte;
#endif
   headerPtr->flashData       = nativeToTarget32(targetProgramInfo.headerAddress);
   headerPtr->watchdogAddress = nativeToTarget32(device->getWatchdogAddress());

   log.print("Loaded Image (modified) :\n");
   log.print("   flashProgramHeader.loadAddress     = 0x%08X\n",      targetToNative32(headerPtr->loadAddress));
   log.print("   flashProgramHeader.entry           = 0x%08X\n",      targetToNative32(headerPtr->entry));
   log.print("   flashProgramHeader.capabilities    = 0x%08X(%s)\n",  capabilities,getProgramCapabilityNames(capabilities));
   log.print("   flashProgramHeader.flashData       = 0x%08X\n",      targetToNative32(headerPtr->flashData));
   log.print("   flashProgramHeader.watchdogAddress = 0x%08X\n",      targetToNative32(headerPtr->watchdogAddress));

   if (currentFlashProgram != flashProgram)  {
      log.print("Reloading due to change in flash code\n");
      // Write the flash programming code to target memory
      USBDM_ErrorCode rc = bdmInterface->writeMemory(memorySpace, codeLoadSize, codeLoadAddress, (uint8_t *)buffer);
      if (rc != BDM_RC_OK) {
         log.print("bdmInterface->writeMemory() Failed, rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
         return PROGRAMMING_RC_ERROR_BDM_WRITE;
      }
   }
   else {
      log.print("Suppressing code load as unchanged\n");
   }
   currentFlashProgram   = flashProgram;
   currentFlashOperation = flashOperation;
   currentFlashAlignment = flashOperationInfo.alignment;

   // Loaded routines support extended operations
   targetProgramInfo.programOperation = DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE;
   return BDM_RC_OK;
}

//=======================================================================
//! Loads the given Flash programming code to target memory
//!
//! @param  buffer            buffer containing data to load
//! @param  loadAddress       address to load at
//! @param  size              size of data in buffer
//! @param  flashProgram      program to load
//! @param  flashOperation    operation to do
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Assumes the target has been connected to
//!         Confirms down-load (if necessary) and checks RAM upper boundary.
//!
//! Target Memory map (RAM buffer)
//! +-----------------------------------------+ -+
//! |   SmallTagetFlashDataHeader flashData;  |   > Write/Read
//! +-----------------------------------------+ -+
//! |   Data to program....                   |   > Write
//! +-----------------------------------------+ -+
//! |   Flash program code....                |   > Unchanging written once
//! +-----------------------------------------+ -+
//!
USBDM_ErrorCode FlashProgrammer_S12Z::loadSmallTargetProgram(uint8_t    *buffer,
                                                        uint32_t              loadAddress,
                                                        uint32_t              size,
                                                        FlashProgramConstPtr  flashProgram,
                                                        FlashOperation        flashOperation) {
   LOGGING;

   log.error("Not supported\n");
   return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
}

//! \brief Maps a Flash action vector to Text
//!
//! @param actions => action to describe
//!
//! @return pointer to static string buffer describing the actions
//!
const char *FlashProgrammer_S12Z::getProgramActionNames(unsigned int actions) {
unsigned index;
static char buff[250] = "";
static const char *actionTable[] = {
"DO_INIT_FLASH|",         // Do initialisation of flash
"DO_ERASE_BLOCK|",        // Mass erase device
"DO_ERASE_RANGE|",        // Erase range (including option region)
"DO_BLANK_CHECK_RANGE|",  // Blank check region
"DO_PROGRAM_RANGE|",      // Program range (including option region)
"DO_VERIFY_RANGE|",       // Verify range
"??|",
"DO_PARTITION_FLEXNVM|",  // Partition FlexNVM boundary
"DO_TIMING_LOOP|",        // Execute timing loop on target
};
   buff[0] = '\0';
   for (index=0;
        index<sizeof(actionTable)/sizeof(actionTable[0]);
         index++) {
      uint32_t mask = 1<<index;
      if ((actions&mask) != 0) {
         strcat(buff,actionTable[index]);
         actions &= ~mask;
      }
   }
   if (actions&IS_COMPLETE) {
      actions &= ~IS_COMPLETE;
      strcat(buff,"IS_COMPLETE|");
   }
   if (actions != 0) {
      strcat(buff,"???");
   }
   return buff;
}

//! \brief Maps a Flash capability vector to Text
//!
//! @param actions => actions to describe
//!
//! @return pointer to static string buffer describing actions
//!
const char *FlashProgrammer_S12Z::getProgramCapabilityNames(unsigned int actions) {
   unsigned index;
   static char buff[250] = "";
   static const char *actionTable[] = {
         "??|",                     // Do initialisation of flash
         "CAP_ERASE_BLOCK|",        // Mass erase device
         "CAP_ERASE_RANGE|",        // Erase range (including option region)
         "CAP_BLANK_CHECK_RANGE|",  // Blank check region
         "CAP_PROGRAM_RANGE|",      // Program range (including option region)
         "CAP_VERIFY_RANGE|",       // Verify range
         "??|",
         "DO_PARTITION_FLEXNVM|",   // Un/lock flash with default security options  (+mass erase if needed)
         "CAP_TIMING|",             // Lock flash with default security options
   };

   buff[0] = '\0';
   for (index=0;
         index<sizeof(actionTable)/sizeof(actionTable[0]);
         index++) {
      if ((actions&(1<<index)) != 0) {
         strcat(buff,actionTable[index]);
      }
   }
   if (actions&CAP_DSC_OVERLAY) {
      strcat(buff,"CAP_DSC_OVERLAY|");
   }
   if (actions&CAP_DATA_FIXED) {
      strcat(buff,"CAP_DATA_FIXED|");
   }
   if (actions&CAP_RELOCATABLE) {
      strcat(buff,"CAP_RELOCATABLE");
   }
   return buff;
}

USBDM_ErrorCode FlashProgrammer_S12Z::convertTargetErrorCode(FlashDriverError_t rc) {

   switch (rc) {
   case FLASH_ERR_OK                : return PROGRAMMING_RC_OK;
   case FLASH_ERR_LOCKED            : return PROGRAMMING_RC_ERROR_SECURED;               // Flash is still locked
   case FLASH_ERR_ILLEGAL_PARAMS    : return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;        // Parameters illegal
   case FLASH_ERR_PROG_FAILED       : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;  // STM - Programming operation failed - general
   case FLASH_ERR_PROG_WPROT        : return PROGRAMMING_RC_ERROR_SECURED;               // STM - Programming operation failed - write protected
   case FLASH_ERR_VERIFY_FAILED     : return PROGRAMMING_RC_ERROR_FAILED_VERIFY;         // Verify failed
   case FLASH_ERR_ERASE_FAILED      : return PROGRAMMING_RC_ERROR_NOT_BLANK;             // Not blank after erase
   case FLASH_ERR_TRAP              : return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED; // Program trapped (illegal instruction/location etc.)
   case FLASH_ERR_PROG_ACCERR       : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;  // Kinetis/CFVx - Programming operation failed - ACCERR
   case FLASH_ERR_PROG_FPVIOL       : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;  // Kinetis/CFVx - Programming operation failed - FPVIOL
   case FLASH_ERR_PROG_MGSTAT0      : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;  // Kinetis - Programming operation failed - MGSTAT0
   case FLASH_ERR_CLKDIV            : return PROGRAMMING_RC_ERROR_NO_VALID_FCDIV_VALUE;  // CFVx - Clock divider not set
   case FLASH_ERR_ILLEGAL_SECURITY  : return PROGRAMMING_RC_ERROR_ILLEGAL_SECURITY;      // CFV1+,Kinetis - Illegal value for security location
   case FLASH_ERR_UNKNOWN           : return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED; // Unspecified error
   case FLASH_ERR_TIMEOUT           : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;  // Unspecified error
   default                          : return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;
   }
}

USBDM_ErrorCode FlashProgrammer_S12Z::initLargeTargetBuffer(uint8_t *buffer) {
   LOGGING;
   LargeTargetFlashDataHeader *pFlashHeader = (LargeTargetFlashDataHeader*)buffer;

   memset(pFlashHeader, 0, sizeof(LargeTargetFlashDataHeader));

   pFlashHeader->errorCode       = nativeToTarget16(-1);
   pFlashHeader->controller      = nativeToTarget32(flashOperationInfo.controller);
   pFlashHeader->frequency       = nativeToTarget32(flashOperationInfo.targetBusFrequency);
   pFlashHeader->sectorSize      = nativeToTarget16(flashOperationInfo.sectorSize);
   pFlashHeader->address         = nativeToTarget32(flashOperationInfo.flashAddress);
   pFlashHeader->dataSize        = nativeToTarget32(flashOperationInfo.dataSize);
   pFlashHeader->dataAddress     = nativeToTarget32(targetProgramInfo.headerAddress+targetProgramInfo.dataOffset);

   uint32_t operation = 0;
   switch(currentFlashOperation) {
   case OpNone:
   case OpWriteRam:
   default:
      log.error("Unexpected operation %s\n", getFlashOperationName(currentFlashOperation));
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   case OpSelectiveErase:
      operation = DO_INIT_FLASH|DO_ERASE_RANGE;
      break;
   case OpProgram:
      operation = DO_INIT_FLASH|targetProgramInfo.programOperation;
      break;
   case OpVerify:
      operation = DO_INIT_FLASH|DO_VERIFY_RANGE;
      break;
   case OpBlankCheck:
      operation = DO_INIT_FLASH|DO_BLANK_CHECK_RANGE;
      break;
   case OpBlockErase:
      operation = DO_INIT_FLASH|DO_ERASE_BLOCK;
      break;
#if (TARGET == MC56F80xx) || (TARGET == HCS12) || (TARGET == CFVx)
   case OpTiming:
      operation = DO_TIMING_LOOP;
      break;
#endif
#if (TARGET==ARM) || (TARGET==CFV1)
   case OpPartitionFlexNVM:
      operation = DO_INIT_FLASH|DO_PARTITION_FLEXNVM;
      // Frequency field used for partition information
      pFlashHeader->frequency = nativeToTarget32(flashOperationInfo.flexNVMPartition);
      break;
#endif
   }
   pFlashHeader->flags = nativeToTarget32(operation);

   log.print("flashOperationInfo.flashAddress = 0x%08X\n", flashOperationInfo.flashAddress);
   log.print("pFlashHeader->address = 0x%08X\n", pFlashHeader->address);

   log.print("Loaded parameters:\n");
   log.print("   currentFlashOperation  = %s\n",        getFlashOperationName(currentFlashOperation));
   log.print("   flags                  = %s\n",        getProgramActionNames(targetToNative32(pFlashHeader->flags)));
   log.print("   controller             = 0x%08X\n",    targetToNative32(pFlashHeader->controller));
   log.print("   frequency              = %d (0x%X)\n", targetToNative32(pFlashHeader->frequency),targetToNative32(pFlashHeader->frequency));
   log.print("   sectorSize             = 0x%04X\n",    targetToNative16(pFlashHeader->sectorSize));
   log.print("   address                = 0x%08X\n",    targetToNative32(pFlashHeader->address));
   log.print("   dataSize               = 0x%08X\n",    targetToNative32(pFlashHeader->dataSize));
   log.print("   dataAddress            = 0x%08X\n",    targetToNative32(pFlashHeader->dataAddress));
   pFlashHeader->errorCode = (uint16_t)-1;
   return BDM_RC_OK;
}

USBDM_ErrorCode FlashProgrammer_S12Z::initSmallTargetBuffer(uint8_t *buffer) {
   LOGGING_Q;
   log.error("Small buffer not supported\n");
   return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
}

//=======================================================================
//! \brief Executes program on target.
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @param pBuffer  - buffer including space for header describing operation (may be NULL)
//! @param dataSize - size of data following header in uint8_t units
//!
USBDM_ErrorCode FlashProgrammer_S12Z::executeTargetProgram(uint8_t *pBuffer, uint32_t dataSize) {
   LOGGING;
   log.print("dataSize=0x%X\n", dataSize);

   USBDM_ErrorCode rc = BDM_RC_OK;
   uint8_t buffer[1000] = {0};
   if (pBuffer == NULL) {
      if (dataSize != 0) {
         log.error("Error: No buffer but size non-zero\n");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
      pBuffer = buffer;
   }
   if (targetProgramInfo.smallProgram) {
      rc = initSmallTargetBuffer(pBuffer);
   }
   else {
      rc = initLargeTargetBuffer(pBuffer);
   }
   if (rc != BDM_RC_OK) {
      return rc;
   }
   log.print("Writing Header+Data\n");

   MemorySpace_t memorySpace = MS_Word;

   // Write the flash parameters & data to target memory
   if (bdmInterface->writeMemory(memorySpace,
                   (targetProgramInfo.dataOffset+dataSize)*sizeof(uint8_t),
                   targetProgramInfo.headerAddress,
                   (uint8_t *)pBuffer) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   // Set target PC to start of code & verify
   long unsigned targetRegPC;
   if (bdmInterface->writePC(targetProgramInfo.entry) != BDM_RC_OK) {
      log.error("PC write failed\n");
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   if (bdmInterface->readPC(&targetRegPC) != BDM_RC_OK) {
      log.error("PC read failed\n");
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   if ((targetProgramInfo.entry) != targetRegPC) {
      log.error("PC verify failed\n");
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
#if defined(LOG) && 0
   USBDMStatus_t status;
   bdmInterface->getBDMStatus(&status);

   for (int num=0; num<1000; num++) {
      unsigned long currentPC;
      rc = bdmInterface->readPC(&currentPC);
      if (rc != BDM_RC_OK) {
         log.error("bdmInterface->readPC() Failed, rc=%s\n",
               bdmInterface->getErrorString(rc));
//         report("executeTargetProgram()");
         return rc;
      }
      if ((currentPC<(targetRegPC-0x1000))||(currentPC>(targetRegPC+0x1000))) {
         log.error("Read PC out of range, PC=0x%08lX\n", currentPC);
//         report("executeTargetProgram()");
         return PROGRAMMING_RC_ERROR_BDM;
      }
      uint8_t  iBuffer[10];
      rc = bdmInterface->readMemory(1, sizeof(iBuffer), currentPC, iBuffer);
      if (rc != BDM_RC_OK) {
         log.error("bdmInterface->readMemory() Failed, rc=%s\n",
               bdmInterface->getErrorString(rc));
//         report("executeTargetProgram()");
         return rc;
      }
      log.print("Step: PC=0x%06lX => %02X %02X %02X %02X\n",
             currentPC, iBuffer[0], iBuffer[1], iBuffer[2], iBuffer[3]);

      USBDM_ErrorCode rc = bdmInterface->step();
      if (rc != BDM_RC_OK) {
         log.error("TargetStep() Failed, rc=%s\n",
               bdmInterface->getErrorString(rc));
         return rc;
      }
   }
#endif
   // Execute the Flash program on target
   if (bdmInterface->go() != BDM_RC_OK) {
      log.error("bdmInterface->go() failed\n");
      return PROGRAMMING_RC_ERROR_BDM;
   }
   progressTimer->progress(0, NULL);
#ifdef LOG
   log.print("Polling");
   int dotCount = 50;
#endif
   // Wait for target stop at execution completion
   int timeout = 400; // x 10 ms
   unsigned long runStatus;
   do {
      UsbdmSystem::milliSleep(10);
#ifdef LOG
      log.printq(".");
      if (progressTimer != 0) {
         progressTimer->progress(0);
      }
      if (++dotCount == 100) {
         log.printq("\n");
         dotCount = 0;
      }
#endif
      if (bdmInterface->readStatusReg(&runStatus) != BDM_RC_OK) {
         log.printq("\n");
         log.error("Status read failed\n");
         break;
      }
      progressTimer->progress(0, NULL);
   } while (((runStatus&HC12_BDMSTS_BDMACT) == 0) && (--timeout>0));
   log.printq("\n");
   bdmInterface->halt();
   unsigned long value;
   bdmInterface->connect();
   bdmInterface->readPC(&value);
   log.print("Start PC = 0x%08lX, end PC = 0x%08lX\n", (unsigned long)targetRegPC, (unsigned long)value);

   // Read the flash parameters back from target memory
   ResultStruct executionResult;
   if (bdmInterface->readMemory(memorySpace, sizeof(ResultStruct),
                  targetProgramInfo.headerAddress,
                  (uint8_t*)&executionResult) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   uint16_t errorCode = targetToNative16(executionResult.errorCode);
   if ((timeout <= 0) && (errorCode == FLASH_ERR_OK)) {
      errorCode = FLASH_ERR_TIMEOUT;
      log.error("Error, Timeout waiting for completion.\n");
   }
   if (targetProgramInfo.smallProgram) {
      log.print("Complete, errCode=%d\n", errorCode);
   }
   else {
      uint32_t flags = targetToNative32(executionResult.flags);
      if ((flags != IS_COMPLETE) && (errorCode == FLASH_ERR_OK)) {
         errorCode = FLASH_ERR_UNKNOWN;
         log.error("Error, Unexpected flag result.\n");
      }
      log.print("Complete, flags = 0x%08X(%s), errCode=%d\n",
            flags, getProgramActionNames(flags),
            errorCode);
   }
   rc = convertTargetErrorCode((FlashDriverError_t)errorCode);
   if (rc != BDM_RC_OK) {
      log.error("Raw error code - %d\n", errorCode);
      log.error("Error - %s\n", bdmInterface->getErrorString(rc));
#if (TARGET == MC56F80xx) && 0
      executionResult.data = targetToNative16(executionResult.data);
      executionResult.dataSize = targetToNative16(executionResult.dataSize);
      log.print("   Address = 0x%06X, Data = 0x%04X\n", executionResult.data, executionResult.dataSize);
#endif
#if TARGET == CFV1
      uint8_t SRSreg;
      bdmInterface->readMemory(1, 1, 0xFF9800, &SRSreg);
      log.error("SRS = 0x%02X\n", SRSreg);
#endif
#if TARGET == HCS08
      uint8_t SRSreg;
      bdmInterface->readMemory(1, 1, 0x1800, &SRSreg);
      log.error("SRS = 0x%02X\n", SRSreg);
#endif
   }
#if defined(LOG) && 0
   uint8_t stackBuffer[50];
   bdmInterface->readMemory(memorySpace, sizeof(stackBuffer), 0x3F0, stackBuffer);
#endif
   return rc;
}

#if (TARGET == CFVx) || (TARGET == HCS12) || (TARGET == S12Z) || (TARGET == MC56F80xx) || (TARGET == ARM)
//=======================================================================
//! \brief Determines the target execution speed
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Assumes flash programming code has already been loaded to target.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::determineTargetSpeed(void) {
   LOGGING;
   uint32_t targetBusFrequency = 0;

   flashOperationInfo.alignment = 1;
   flashOperationInfo.dataSize  = 0;

   // Load flash programming code to target
   USBDM_ErrorCode rc = loadTargetProgram(OpTiming);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   LargeTargetTimingDataHeader timingData = {0};
   timingData.flags      = nativeToTarget16(DO_TIMING_LOOP|IS_COMPLETE); // IS_COMPLETE as check - should be cleared
   timingData.controller = nativeToTarget16(-1);                         // Dummy value - not used

   log.print("flags      = 0x%08X(%s)\n",
         targetToNative16(timingData.flags), getProgramActionNames(targetToNative16(timingData.flags))
         );
   MemorySpace_t memorySpace = MS_Word;
   // Write the flash parameters & data to target memory
   if (bdmInterface->writeMemory(memorySpace, sizeof(LargeTargetTimingDataHeader),
                   targetProgramInfo.headerAddress, (uint8_t*)&timingData) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   // Set target PC to start of code & verify
   if (bdmInterface->writePC(targetProgramInfo.entry) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_WRITE;
   }
   // Execute the Flash program on target for 1 second
   if (bdmInterface->go() != BDM_RC_OK) {
      log.error("bdmInterface->go failed\n");
      return PROGRAMMING_RC_ERROR_BDM;
   }
   UsbdmSystem::milliSleep(1000);
   if (bdmInterface->halt() != BDM_RC_OK) {
      log.error("bdmInterface->halt failed\n");
      return PROGRAMMING_RC_ERROR_BDM;
   }
   // Read the flash parameters back from target memory
   LargeTargetTimingDataHeader timingDataResult;
   if (bdmInterface->readMemory(memorySpace, sizeof(timingDataResult),
                  targetProgramInfo.headerAddress, (uint8_t*)&timingDataResult) != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   timingDataResult.flags        = targetToNative16(timingDataResult.flags);
   timingDataResult.errorCode    = targetToNative16(timingDataResult.errorCode);
   timingDataResult.timingCount  = targetToNative32(timingDataResult.timingCount);

   log.print("Complete, flags = 0x%08X(%s), errCode=%d\n",
         timingDataResult.flags,
         getProgramActionNames(timingDataResult.flags),
         timingDataResult.errorCode);
   unsigned long value;
   bdmInterface->readPC(&value);
   log.print("Start PC = 0x%08lX, end PC = 0x%08lX\n", (unsigned long)targetProgramInfo.entry, (unsigned long)value);
   if ((timingDataResult.flags != DO_TIMING_LOOP) && (timingDataResult.errorCode == FLASH_ERR_OK)) {
      timingDataResult.errorCode    = FLASH_ERR_UNKNOWN;
      log.error("Error, Unexpected flag result\n");
   }
   if (timingDataResult.errorCode != FLASH_ERR_OK) {
      log.error("Error\n");
      return convertTargetErrorCode((FlashDriverError_t)timingDataResult.errorCode);
   }
   // Round appropriately (approx 3 digits)
   targetBusFrequency = 20*int(0.5+((200.0 * timingDataResult.timingCount)/targetProgramInfo.calibFactor));
   flashOperationInfo.targetBusFrequency = targetBusFrequency;
   log.print("Count = %d(0x%X) => Bus Frequency = %d kHz\n",
         timingDataResult.timingCount, timingDataResult.timingCount, targetBusFrequency);
   return PROGRAMMING_RC_OK;
}
#endif

//=======================================================================
//! Erase Target Flash memory
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::eraseFlash(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;
   progressTimer->restart("Erasing all flash blocks...");

   // Process each flash region
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      if (!memoryRegionPtr->isProgrammableMemory()) {
         continue;
      }
      log.print("Erasing %s[0x%06X...]\n", memoryRegionPtr->getMemoryTypeName(), memoryRegionPtr->getMemoryRange(0)->start);

      uint32_t addressFlag  = 0;
      uint32_t flashAddress = memoryRegionPtr->getDummyAddress();

#if (TARGET == HCS08) || (TARGET == HCS12)
      if (memoryRegionPtr->getAddressType() == AddrLinear) {
         addressFlag |= ADDRESS_LINEAR;
      }
      if (memoryRegionPtr->getMemoryType() == MemEEPROM) {
         addressFlag |= ADDRESS_EEPROM;
      }
#endif
#if (TARGET == MC56F80xx)
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if (memoryType == MemXROM) {
         // Flag used to indicate data (X:) address
         log.print("Setting MemXROM address\n");
         addressFlag |= ADDRESS_DATA;
      }
#endif
#if (TARGET == CFV1) || (TARGET == ARM)
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if ((memoryType == MemFlexNVM) || (memoryType == MemDFlash)) {
         // Flag needed for DFLASH/flexNVM access
         addressFlag  |= (1<<23);
         flashAddress  = 0;
      }
#endif
      flashOperationInfo.flashAddress      = flashAddress|addressFlag;
      flashOperationInfo.controller        = memoryRegionPtr->getRegisterAddress();
      flashOperationInfo.sectorSize        = memoryRegionPtr->getSectorSize();
      flashOperationInfo.alignment         = memoryRegionPtr->getAlignment();
      flashOperationInfo.pageAddress       = memoryRegionPtr->getPageAddress();
      flashOperationInfo.dataSize          = 0;
      flashOperationInfo.flexNVMPartition  = (uint32_t)-1;

      rc = loadTargetProgram(memoryRegionPtr, OpBlockErase);
      if (rc != PROGRAMMING_RC_OK) {
         log.error("loadTargetProgram() failed \n");
         return rc;
      }
      rc = executeTargetProgram();
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
   return rc;
}

#if (TARGET == CFV1) || (TARGET == ARM) || (TARGET == HCS08) || (TARGET == S12Z) || (TARGET == MC56F80xx)
//=======================================================================
//! Selective erases the target memory security areas.
//! This is only of use when the target is unsecured but the security
//! needs to be modified.
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::selectiveEraseFlashSecurity(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (!securityNeedsSelectiveErase) {
      log.print("Security areas are valid - no erasure required\n");
      return BDM_RC_OK;
   }
   progressTimer->restart("Erasing all flash security areas...");
   // Process each flash region
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      if (!memoryRegionPtr->isProgrammableMemory()) {
         continue;
      }
      uint32_t securityAddress = memoryRegionPtr->getSecurityAddress();
      if (securityAddress == 0) {
         continue;
      }
      SecurityInfoConstPtr securityInfo = memoryRegionPtr->getSecureInfo();
      uint32_t securitySize = securityInfo->getSize();
      if (securityInfo == NULL) {
         continue;
      }
      log.print("Erasing security area %s[0x%06X..0x%06X]\n",
            memoryRegionPtr->getMemoryTypeName(), securityAddress, securityAddress+securitySize-1);

      flashOperationInfo.controller        = memoryRegionPtr->getRegisterAddress();
      flashOperationInfo.sectorSize        = memoryRegionPtr->getSectorSize();
      flashOperationInfo.alignment         = memoryRegionPtr->getAlignment();
      flashOperationInfo.pageAddress       = memoryRegionPtr->getPageAddress();
      flashOperationInfo.dataSize          = securitySize;
      flashOperationInfo.flexNVMPartition  = (uint32_t)-1;

      rc = loadTargetProgram(memoryRegionPtr, OpSelectiveErase);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
      uint32_t addressFlag = 0;

#if (TARGET == HCS08) || (TARGET == HCS12)
      if (memoryRegionPtr->getAddressType() == AddrLinear) {
         addressFlag |= ADDRESS_LINEAR;
      }
      if (memoryRegionPtr->getMemoryType() == MemEEPROM) {
         addressFlag |= ADDRESS_EEPROM;
      }
#endif
#if (TARGET == MC56F80xx)
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if (memoryType == MemXROM) {
         // Flag used to indicate data (X:) address
         log.print("Setting MemXROM address\n");
         addressFlag |= ADDRESS_DATA;
      }
#endif
#if (TARGET == CFV1) || (TARGET == ARM)
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if ((memoryType == MemFlexNVM) || (memoryType == MemDFlash)) {
         // Flag need for DFLASH/flexNVM access
         addressFlag |= ADDRESS_A23;
      }
#endif
      flashOperationInfo.flashAddress = securityAddress|addressFlag;
      if (flashOperationInfo.sectorSize == 0) {
         log.error("sectorSize must not be zero\n");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
      rc = executeTargetProgram();
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
   return rc;
}
#endif

#if (TARGET == CFV1) || (TARGET == ARM)
//=======================================================================
//! Program FlashNVM partion (DFlash/EEPROM backing store)
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
//! @note - Assumes flash programming code has already been loaded to target.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::partitionFlexNVM() {
   LOGGING;
   uint8_t eeepromSize  = device->getFlexNVMParameters().eeepromSize;
   uint8_t partionValue = device->getFlexNVMParameters().partionValue;
   USBDM_ErrorCode rc = BDM_RC_OK;
   if ((eeepromSize==0xFF)&&(partionValue==0xFF)) {
      log.print("Skipping FlexNVM parameter programming as unprogrammed values\n");
      return BDM_RC_OK;
   }
   log.print("eeepromSize=0x%02X, partionValue=0x%02X\n", eeepromSize, partionValue);
   progressTimer->restart("Partitioning DFlash...");

   // Find flexNVM region
   MemoryRegionConstPtr memoryRegionPtr;
   for (int index=0; ; index++) {
      memoryRegionPtr = device->getMemoryRegion(index);
      if ((memoryRegionPtr == NULL) ||
          (memoryRegionPtr->getMemoryType() == MemFlexNVM)) {
         break;
      }
   }
   if (memoryRegionPtr == NULL) {
      log.print("No FlexNVM Region found\n");
      return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }
   MemType_t memoryType = memoryRegionPtr->getMemoryType();
   log.print("Partitioning %s\n", MemoryRegion::getMemoryTypeName(memoryType));
   rc = loadTargetProgram(memoryRegionPtr, OpPartitionFlexNVM);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   flashOperationInfo.flexNVMPartition  = (eeepromSize<<24UL)|(partionValue<<16UL);
   flashOperationInfo.controller = memoryRegionPtr->getRegisterAddress();
   rc = executeTargetProgram();
   if (rc == PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND) {
      // This usually means this error - more useful message
      rc = PROGRAMMING_RC_FLEXNVM_CONFIGURATION_FAILED;
   }
   return rc;
}
#endif

#if (TARGET == HCS12)
//=======================================================================
//! Checks for unsupported device
//!
USBDM_ErrorCode FlashProgrammer_S12Z::checkUnsupportedTarget() {
   LOGGING;
   USBDM_ErrorCode rc;
   uint32_t targetSDID;
#define brokenUF32_SDID (0x6311)
//#define brokenUF32_SDID (0x3102) // for testing using C128

   // Get SDID from target
   rc = readTargetChipId(&targetSDID);
   if (rc != PROGRAMMING_RC_OK)
      return rc;

   // It's fatal to try unsecuring this chip using the BDM or
   // unsafe to program it to the secure state.
   // See errata MUCts01498
   if ((targetSDID == brokenUF32_SDID) &&
       ((device->getSecurity() != SEC_UNSECURED) ||
        (checkTargetUnSecured() != PROGRAMMING_RC_OK))) {
      log.error("Can't unsecure/secure UF32 due to hardware bug - See errata MUCts01498\n");
      return PROGRAMMING_RC_ERROR_CHIP_UNSUPPORTED;
   }
   return PROGRAMMING_RC_OK;
}
#endif

#if (TARGET == MC56F80xx) || (TARGET == HCS12) || (TARGET == S12Z)
//==================================================================================
//! Determines the target frequency by either of these methods: \n
//!   -  BDM SYNC Timing \n
//!   -  Execution of a timing program on target (only if unsecured & no SYNC)
//!
//! @param busFrequency  : Target bus frequency (in Hz)
//!
//! @return error code, see \ref USBDM_ErrorCode \n
//!      - PROGRAMMING_RC_OK                 - speed accurately determined \n
//!      - PROGRAMMING_RC_ERROR_SPEED_APPROX - speed estimated (not suitable for programming) \n
//!      - PROGRAMMING_RC_ERROR_FAILED_CLOCK - speed timing program failed
//!
//! @note - Assumes the target has been initialised. \n
//!       - Re-connects to target.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::getTargetBusSpeed(unsigned long *busFrequency) {
   LOGGING;
   unsigned long connectionFrequency;
   USBDMStatus_t bdmStatus;
   USBDM_ErrorCode rc;

   // Check target connection
   // BDM_RC_BDM_EN_FAILED may mean the target is secured
   rc = bdmInterface->connect();
   if (((rc != BDM_RC_OK) && (rc != BDM_RC_BDM_EN_FAILED)) ||
       (bdmInterface->getBDMStatus(&bdmStatus) != BDM_RC_OK)) {
      log.error("Failed connection\n");
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }

   // If BDM SYNC worked then use that speed
   if ((bdmStatus.connection_state == SPEED_SYNC) &&
       (bdmInterface->getSpeedHz(&connectionFrequency) == BDM_RC_OK)) {
      // Use speed determined by BDM SYNC pulse
      *busFrequency = device->getBDMtoBUSFactor()*connectionFrequency;
      log.print("Using SYNC method, Bus Frequency = %ld kHz\n",
            (unsigned long)round(*busFrequency/1000.0));
      return PROGRAMMING_RC_OK;
   }

   // We can only approximate the target speed if secured & guessed
   if ((checkTargetUnSecured() == PROGRAMMING_RC_ERROR_SECURED) &&
       (bdmStatus.connection_state == SPEED_GUESSED) &&
       (bdmInterface->getSpeedHz(&connectionFrequency) == BDM_RC_OK)) {
      // Use speed determined by BDM guessing
      *busFrequency = device->getBDMtoBUSFactor()*connectionFrequency;
      log.print(" - Using Approximate method, Bus Frequency = %ld kHz\n",
            (unsigned long)round(*busFrequency/1000.0));
      return PROGRAMMING_RC_ERROR_SPEED_APPROX;
   }
   // We must have a connection for the next method
   if (rc != BDM_RC_OK) {
      log.error("Failed connection\n");
      return PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   //
   // Try to determine target speed by down-loading a timing program to the target
   //
   USBDM_ErrorCode flashRc = determineTargetSpeed();
   if (flashRc != PROGRAMMING_RC_OK) {
      log.error("Failed connection\n");
      return flashRc;
   }
   *busFrequency = 1000*flashOperationInfo.targetBusFrequency;

   log.print(" - Using Timing Program method, Bus Frequency = %ld kHz\n",
        (unsigned long)round(*busFrequency/1000.0));

   return PROGRAMMING_RC_OK;
}
#endif

//=======================================================================
//! Check security state of target
//!
//! @return PROGRAMMING_RC_OK => device is unsecured           \n
//!         PROGRAMMING_RC_ERROR_SECURED => device is secured  \n
//!         else error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::checkTargetUnSecured() {
   LOGGING;
   USBDM_ErrorCode rc = initialiseTarget();
   if (rc != PROGRAMMING_RC_OK)
      return rc;
   rc = runTCLCommand("isUnsecure");
   if (rc != PROGRAMMING_RC_OK) {
      log.print("Secured\n");
      return rc;
   }
   log.print("Unsecured\n");
   return PROGRAMMING_RC_OK;
}

//===========================================================================================================
//! Modifies the Security locations in the flash image according to required security options of flashRegion
//!
//! @param flashImage    Flash contents to be programmed.
//! @param flashRegion   The memory region involved (to determine security area if any)
//!
USBDM_ErrorCode FlashProgrammer_S12Z::setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion) {
   LOGGING;
   uint32_t securityAddress = flashRegion->getSecurityAddress();

   if (securityAddress == 0) {
      log.print("No security area, not modifying flash image\n");
      return PROGRAMMING_RC_OK;
   }
   SecurityInfoConstPtr securityInfo;
   bool dontOverwrite =  false;
   switch (device->getSecurity()) {
      case SEC_SECURED:
         log.print("Setting image as secured\n");
         securityInfo = flashRegion->getSecureInfo();
         break;
      case SEC_UNSECURED:
         log.print("Setting image as unsecured\n");
         securityInfo = flashRegion->getUnsecureInfo();
         break;
      case SEC_CUSTOM:
         log.print("Setting image security to custom value\n");
         securityInfo = flashRegion->getCustomSecureInfo();
         break;
      case SEC_INTELLIGENT:
         log.print("Setting image as intelligently unsecured\n");
         securityInfo = flashRegion->getUnsecureInfo();
         dontOverwrite = true;
         break;
      case SEC_DEFAULT:
         log.print("Leaving flash image unchanged\n");
         securityInfo = flashRegion->getUnsecureInfo();
         break;
      default:
         log.error("Unexpected securityInfo value");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (securityInfo == NULL) {
      log.error("Error - No settings for security area!\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   int size = securityInfo->getSize();
   if (device->getSecurity() == SEC_DEFAULT) {
      // Check if security area exists in image
      // If so - selective erase if needed
      for(int index=0; index<size; index++) {
         if (flashImage->isValid(securityAddress+index)) {
            log.print("Security area may need erasing\n");
            securityNeedsSelectiveErase = true;
            break;
         }
      }
      return BDM_RC_OK;
   }
   /*
    * Create expected security area contents
    *
    * This will based on the security info for the present security option.
    * For SEC_INTELLIGENT information will be overwritten by the flash image information (if present).
    */
   uint8_t securityData[size];
   memcpy(securityData, securityInfo->getData(), size);
   if (dontOverwrite) {
      // Copy any existing data from flash image
      for(int index=0; index<size; index++) {
         if (flashImage->isValid(securityAddress+index)) {
            securityData[index] = flashImage->getValue(securityAddress+index);
         }
      }
   }

   uint8_t memory[size];
   bdmInterface->readMemory(MS_Byte, size, securityAddress, memory);
   // Save contents of current security area in Flash image
   recordSecurityArea(flashImage, securityAddress, size);
   if (memcmp(securityData, memory, size) == 0) {
      if ((device->getEraseOption() == DeviceData::eraseMass) ||
          (device->getEraseOption() == DeviceData::eraseNone)) {
         // Clear security area in image to prevent re-programming
         log.print("Removing security area from image as already valid and not being erased\n");
         for(int index=0; index<size; index++) {
            flashImage->remove(securityAddress+index);
         }
      }
      else {
         // eraseAll & eraseSelective will erase areas anyway so we have to re-program
         log.print("Security area is already valid but will be erased anyway (eraseAll or eraseSelective)\n");
         flashImage->loadDataBytes(size, securityAddress, securityData, dontOverwrite);
      }
   }
   else {
      log.print("Security area may need erasing\n");
      // Force erase of security area when mass erased (if necessary)
      securityNeedsSelectiveErase = true;
      flashImage->loadDataBytes(size, securityAddress, securityData, dontOverwrite);
#ifdef LOG
      log.print("Setting security region, \n"
            "              mem[0x%06lX-0x%06lX] = \n", (unsigned long)securityAddress, (unsigned long)(securityAddress+size/sizeof(uint8_t)-1));
      flashImage->dumpRange(securityAddress, securityAddress+size-1);
#endif
   }
   return PROGRAMMING_RC_OK;
}

//===============================================================================================
//! Modifies the Security locations in the flash image according to required security options
//!
//! @param flashImage  -  Flash image to be modified
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::setFlashSecurity(FlashImagePtr flashImage) {
   LOGGING;
   // Process each flash region
   USBDM_ErrorCode rc = BDM_RC_OK;
   securityNeedsSelectiveErase = false; // Assume security areas are valid
   rc = checkNoSecurityAreas();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      rc = setFlashSecurity(flashImage, memoryRegionPtr);
      if (rc != BDM_RC_OK) {
         log.print("Failed to set security for %s\n", memoryRegionPtr->getMemoryTypeName());
         break;
      }
   }
   return rc;
}

//==================================================================================
//! Applies a flash operation to a block of Target Flash memory
//!
//! @param flashImage       Description of flash contents to be processed.
//! @param blockSize        Size of block to process (bytes)
//! @param flashAddress     Start address of block in memory to process
//! @param flashOperation   Operation to do on flash
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
//! @note - Assumes flash programming code has already been loaded to target.
//! @note - The memory range must be within one page for paged devices.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doFlashBlock(FlashImagePtr flashImage,
                                                   unsigned int    blockSize,
                                                   uint32_t       &flashAddress,
                                                   FlashOperation  flashOperation) {
   LOGGING;
   log.print("op=%s, [0x%06X..0x%06X]\n", getFlashOperationName(flashOperation), flashAddress, flashAddress+blockSize-1);

   if (!flashReady) {
      log.error(" - Error, Flash not ready\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // OK for empty block
   if (blockSize==0) {
      return PROGRAMMING_RC_OK;
   }
   //
   // Find flash region to program - this will recurse to handle sub regions
   //
   MemorySpace_t memorySpace       = MS_None;     // Memory space for target access
   uint32_t      memoryAddressMask = 0xFFFFFFFF;  // Mask to apply to flash address to get memory address

#if (TARGET == MC56F80xx)
   // MC56F80xx map DATA addresses as high addresses in flashImage
   if (flashAddress >= FlashImage::DataOffset) {
      memorySpace       = MS_XWord;
      memoryAddressMask = 0x00FFFFFF;
   }
   else {
      memorySpace       = MS_PWord;
   }
#endif
   // Locate containing Memory region (Programmable or RAM)
   MemoryRegionConstPtr memoryRegionPtr = device->getMemoryRegionFor(flashAddress&memoryAddressMask, memorySpace);
   if (memoryRegionPtr == NULL) {
      log.error("Block %s[0x%06X...] is not within target memory.\n", getMemSpaceName(memorySpace), flashAddress&memoryAddressMask);
      return PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
   }
   uint32_t lastContiguous;  // Last contiguous address in memory space
   if (!memoryRegionPtr->findLastContiguous(flashAddress&memoryAddressMask, &lastContiguous, memorySpace)) {
      // This should never fail!
      log.error("Block %s[0x%06X...] is within target memory BUT location not found!.\n", getMemSpaceName(memorySpace), flashAddress&memoryAddressMask);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }

   // Check if block crosses boundary and will need to be split
   if (((flashAddress&memoryAddressMask)+blockSize-1) > lastContiguous) {
      // The block is split into a contiguous block + rest. Each is handled by recursion
      log.print("  ...Block crosses FLASH boundary - recursing\n");
      uint32_t firstBlockSize = lastContiguous - flashAddress + 1;
      USBDM_ErrorCode rc;
      rc = doFlashBlock(flashImage, firstBlockSize, flashAddress, flashOperation);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
      rc = doFlashBlock(flashImage, blockSize-firstBlockSize, flashAddress, flashOperation);
      return rc;
   }

   /*
    * We have a memory block to process
    * Check that operation is suitable for this phase
    */
   if (memoryRegionPtr->isProgrammableMemory()) {
      /*
       * ROM type
       */
      switch (flashOperation) {
         case OpBlankCheck:
         case OpProgram:
         case OpSelectiveErase:
         case OpVerify:
            // OK operation on ROM
            break;
         case OpWriteRam:
            // Assume to be done in later RAM phase
            log.print("  ...Skipping block %s[0x%06X..0x%06X] as ROM memory assumed processed in earlier phase\n",
                  memoryRegionPtr->getMemoryTypeName(), (flashAddress&memoryAddressMask), (flashAddress&memoryAddressMask)+blockSize-1);
            // No further processing of this block
            flashAddress += blockSize;
            return BDM_RC_OK;
         default:
            // Unexpected
            log.error("  ...Unexpected flashOperation\n");
            return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
   }
   else if (memoryRegionPtr->isWritableMemory() && doRamWrites) {
      /*
       * RAM type & writes enabled
       */
         switch (flashOperation) {
         case OpBlankCheck:
         case OpProgram:
         case OpSelectiveErase:
            // Assume done in earlier Flash pass or not applicable
            log.print("  ...Skipping block %s[0x%06X..0x%06X] as RAM memory assumed processed in later phase\n",
                  memoryRegionPtr->getMemoryTypeName(), (flashAddress&memoryAddressMask), (flashAddress&memoryAddressMask)+blockSize-1);
            // No further processing of this block
            flashAddress += blockSize;
            return BDM_RC_OK;
         case OpWriteRam:
         case OpVerify:
            // OK Operation on RAM
            break;
         default:
            // Unexpected
            log.error("  ...Unexpected ramOperation\n");
            return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
         }
   }
   else {
      // Unexpected
      log.error("Block %s[0x%06X..0x%06X] is not within target memory\n",
            memoryRegionPtr->getMemoryTypeName(), (flashAddress&memoryAddressMask), (flashAddress&memoryAddressMask)+blockSize-1);
      return PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
   }

   /*
    * Have block and suitable operation
    */
   MemType_t memoryType = memoryRegionPtr->getMemoryType();
   log.print("Processing %s[0x%06X..0x%06X]\n",
         MemoryRegion::getMemoryTypeName(memoryType), (flashAddress&memoryAddressMask), (flashAddress&memoryAddressMask)+blockSize-1);

   flashOperationInfo.controller = memoryRegionPtr->getRegisterAddress();
   flashOperationInfo.alignment  = memoryRegionPtr->getAlignment();
   flashOperationInfo.sectorSize = memoryRegionPtr->getSectorSize();

   if ((flashOperation == OpSelectiveErase) && (flashOperationInfo.sectorSize == 0)) {
      log.error("Error: sector size is 0\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode rc = loadTargetProgram(memoryRegionPtr, flashOperation);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }

   // Maximum size of data to write
   unsigned int maxSplitBlockSize = targetProgramInfo.maxDataSize;

   // Buffer for memory write (header+buffer)
   uint8_t  buffer[100+maxSplitBlockSize];
   memset(buffer, 0, sizeof(buffer));
   uint8_t *bufferData = buffer+targetProgramInfo.dataOffset;

   uint32_t alignMask = memoryRegionPtr->getAlignment()-1;
   log.print("Align mask = 0x%08X\n", alignMask);

   // splitBlockSize must be aligned
   maxSplitBlockSize &= ~alignMask;

   // Calculate any odd padding bytes at start of block
   unsigned int oddBytes = flashAddress & alignMask;

   uint32_t addressFlag = 0;        // Modifier for target memory address

#if (TARGET == HCS08) || (TARGET == HCS12)
   if (memoryRegionPtr->getMemoryType() == MemEEPROM) {
      log.print("Setting EEPROM address flag\n");
      addressFlag |= ADDRESS_EEPROM;
   }
   // Set up linear address
   if (memoryRegionPtr->getAddressType() == AddrLinear) {
      // Set Linear address
      log.print("Setting Linear address\n");
      addressFlag |= ADDRESS_LINEAR;
   }
#endif
#if (TARGET == MC56F80xx)
      if (memoryType == MemXROM) {
         // Flag used to indicate data (X:) address
         log.print("Setting MemXROM address\n");
         addressFlag |= ADDRESS_DATA;
      }
#endif
#if (TARGET == CFV1)
   if ((memoryType == MemFlexNVM) || (memoryType == MemDFlash)) {
      // Flag needed for DFLASH/FlexNVM access on CFV1
      addressFlag |= ADDRESS_A23;
   }
#endif
   // Round start address off to alignment requirements
   flashAddress  &= ~alignMask;

   // Pad block size with odd leading bytes
   blockSize += oddBytes;

   // Pad block size to alignment requirements
   blockSize = (blockSize+alignMask)&~alignMask;

   progressTimer->progress(0, NULL);

   while (blockSize>0) {
      unsigned flashIndex  = 0;
      unsigned size        = 0;
      // Determine size of block to process
      unsigned int splitBlockSize = blockSize;
      if ((flashOperation == OpProgram)||(flashOperation == OpVerify)||(flashOperation == OpWriteRam)) {
         // Requires data transfer using buffer
         if (splitBlockSize>maxSplitBlockSize) {
            splitBlockSize = maxSplitBlockSize;
         }
         // Pad any odd leading elements as 0xFF..
         for (flashIndex=0; flashIndex<oddBytes; flashIndex++) {
            bufferData[flashIndex] = (uint8_t)-1;
         }
         // Copy flash data to buffer
         for(flashIndex=0; flashIndex<splitBlockSize; flashIndex++) {
            bufferData[flashIndex] = flashImage->getValue(flashAddress+flashIndex);
         }
         // Pad trailing elements to aligned address
         for (; (flashIndex&alignMask) != 0; flashIndex++) {
            bufferData[flashIndex] = flashImage->getValue(flashAddress+flashIndex);
         }
         // Actual data bytes to write
         size = flashIndex;
      }
      else {
         // No data transfer so no size limits
         flashIndex  = (blockSize+alignMask)&~alignMask;
         size = 0;
      }
      uint32_t targetAddress = flashAddress&memoryAddressMask;

#if (TARGET == HCS08) || (TARGET == HCS12)
      // Map paged address
      if (memoryRegionPtr->getAddressType() != AddrLinear) {
         uint8_t pageNo;
         rc = getPageAddress(memoryRegionPtr, flashAddress, &pageNo);
         if (rc != PROGRAMMING_RC_OK) {
            return rc;
         }
         targetAddress = (pageNo<<16)|(flashAddress&0xFFFF);
      }
#endif
      flashOperationInfo.flashAddress = addressFlag|targetAddress;
      flashOperationInfo.dataSize     = flashIndex;
      if (splitBlockSize==0) {
         log.error(" - Error: splitBlockSize size is 0\n");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
      flashOperationInfo.pageAddress  = memoryRegionPtr->getPageAddress();
      USBDM_ErrorCode rc = BDM_RC_OK;

      if (flashOperation == OpWriteRam) {
         /*
          * RAM Writes
          */
         log.print("ramBlock splitBlock %s, %s[0x%06X..0x%06X]\n",
               MemoryRegion::getMemoryTypeName(memoryType), getMemSpaceName(memorySpace), targetAddress, targetAddress+splitBlockSize-1);
#if (TARGET == ARM)
         rc = bdmInterface->writeMemory(MS_Long, splitBlockSize*sizeof(uint8_t), targetAddress, (const uint8_t *)bufferData);
#elif (TARGET == MC56F80xx)
         rc = bdmInterface->writeMemory(memorySpace, splitBlockSize*sizeof(uint8_t), targetAddress, (const uint8_t *)bufferData);
//         log.printDump((const uint8_t *)bufferData, splitBlockSize*sizeof(uint8_t), targetAddress, WORD_ADDRESS);
#else
         rc = bdmInterface->writeMemory(MS_Word, splitBlockSize*sizeof(uint8_t), targetAddress, (const uint8_t *)bufferData);
#endif
      }
      else {
         /*
          * Flash writes
          */
         log.print("splitBlock %s[0x%06X..0x%06X]\n",
               MemoryRegion::getMemoryTypeName(memoryType), (flashAddress&memoryAddressMask), (flashAddress&memoryAddressMask)+splitBlockSize-1);
         log.print("flashOperationInfo.flashAddress = 0x%08X\n", flashOperationInfo.flashAddress);
         rc = executeTargetProgram(buffer, size);
      }
      if (rc != PROGRAMMING_RC_OK) {
         log.error("Error rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
         return rc;
      }
      // Advance to next block of data
      flashAddress  += splitBlockSize;
      blockSize     -= splitBlockSize;
      oddBytes       = 0; // No odd bytes on subsequent blocks
      progressTimer->progress(splitBlockSize*sizeof(uint8_t), NULL);
   }
   return PROGRAMMING_RC_OK;
}

//==============================================================================
//! Apply a flash operation to target based upon occupied flash addresses
//!
//! @param flashImage       Flash image to use
//! @param flashOperation   Operation to do on flash
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::applyFlashOperation(FlashImagePtr flashImage, FlashOperation  flashOperation) {
   LOGGING;
   USBDM_ErrorCode rc = PROGRAMMING_RC_OK;
   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();

   log.print("Op=%s, Total Bytes = %d\n", getFlashOperationName(flashOperation), flashImage->getByteCount());
   // Go through each allocated block of memory applying operation
   while (enumerator->isValid()) {
      // Start address of block to program to flash
      uint32_t startBlock = enumerator->getAddress();
      // Find end of block to process
      enumerator->lastValid();
      uint32_t blockSize = enumerator->getAddress() - startBlock + 1;
      if (blockSize>0) {
         // Process block [startBlock..endBlock]
         rc = doFlashBlock(flashImage, blockSize, startBlock, flashOperation);
         if (rc != PROGRAMMING_RC_OK) {
            log.error("applyFlashOperation() - Error \n");
            break;
         }
      }
      else {
         log.print("applyFlashOperation() - empty block\n");
      }
      enumerator->setAddress(startBlock);
   }
   return rc;
}

//==============================================================================
//! Blank check, program and verify target from flash image
//!
//! @param flashImage Flash image to program
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doProgram(FlashImagePtr flashImage) {
   LOGGING;
   // Load target flash code to check programming options
   flashOperationInfo.alignment = 2;
   USBDM_ErrorCode rc;
   rc = loadTargetProgram(OpBlankCheck);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if ((targetProgramInfo.programOperation&DO_BLANK_CHECK_RANGE) == 0) {
      // Do separate blank check if not done by program operation
      rc = doBlankCheck(flashImage);
   }
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if ((targetProgramInfo.programOperation&DO_VERIFY_RANGE) == 0) {
      progressTimer->restart("Programming");
   }
   else {
      progressTimer->restart("Programming && Verifying...");
   }
   rc = applyFlashOperation(flashImage, OpProgram);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Programming failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   if ((targetProgramInfo.programOperation&DO_VERIFY_RANGE) == 0) {
      // Do separate verify operation
      progressTimer->restart("Verifying...");
      rc = doVerify(flashImage);
   }
   return rc;
}

//==============================================================================
//! Selective erase target.  Area erased is determined from flash image
//!
//! @param flashImage - Flash image used to determine regions to erase
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! Todo This is sub-optimal as it may erase the same sector multiple times.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doSelectiveErase(FlashImagePtr flashImage) {
   LOGGING;
   progressTimer->restart("Selective Erasing...");

   USBDM_ErrorCode rc;
   rc = applyFlashOperation(flashImage, OpSelectiveErase);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Selective erase failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//==================================================================================
//! doReadbackVerify - Verifies the Target memory against memory image
//!
//! @param flashImage Description of flash contents to be verified.
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//! @note Assumes target connection has been established
//! @note Assumes call-back has been set up if used.
//! @note If target clock trimming is enabled then the Non-volatile clock trim
//!       locations are ignored.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doReadbackVerify(FlashImagePtr flashImage) {
   LOGGING;
   const unsigned MAX_BUFFER=0x800;
   uint8_t buffer[MAX_BUFFER];
   int checkResult = TRUE;
   int blockResult;

   flashImage->printMemoryMap();

   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();
   //ToDo - handle linear addressing on HCS12
   if (!enumerator->isValid()) {
      log.print("Empty Memory region\n");
      flashImage->printMemoryMap();
   }
   while (enumerator->isValid()) {
      uint32_t imageAddress    = enumerator->getAddress();
      uint32_t memoryAddress;

#if (TARGET==HCS08)||(TARGET==HC12)
      USBDM_ErrorCode rc = setPageRegisters(imageAddress);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
#endif

      uint32_t      offset      = 0;
      MemorySpace_t memorySpace = MS_None;

#if (TARGET==RS08)
      memorySpace = MS_Byte;
#elif (TARGET == MC56F80xx)
      if (imageAddress >= FlashImage::DataOffset) {
         memorySpace = MS_XWord;
         offset      = FlashImage::DataOffset;
      }
      else {
         memorySpace = MS_PWord;
         offset      = 0;
      }
#elif (TARGET == ARM)
      memorySpace = MS_Long;
#elif (TARGET == HCS08) || (TARGET == HCS12)
      memorySpace = (MemorySpace_t)(MS_Fast|MS_Byte);
#elif (TARGET == S12Z)
      memorySpace = MS_Word;
#else
      memorySpace = MS_Word;
#endif

      // Find end of block to verify
      enumerator->lastValid();
      unsigned regionSize = enumerator->getAddress() - imageAddress + 1;

      memoryAddress = imageAddress-offset;
      log.print("Verifying Block %s[0x%8.8X..0x%8.8X]\n", getMemSpaceName(memorySpace), memoryAddress, memoryAddress+regionSize-1);

      __attribute__((unused))
      bool  reportedError = false;

      while (regionSize>0) {
         // Get memory block containing address
         MemoryRegionConstPtr memRegion = device->getMemoryRegionFor(memoryAddress, memorySpace);
         if (memRegion == NULL) {
            log.error("Verifying Block %s[0x%8.8X..0x%8.8X] - Not in valid memory region\n", getMemSpaceName(memorySpace), memoryAddress, memoryAddress+regionSize-1);
            return PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
         }
#if (TARGET == ARM)
         if (memRegion->getAlignment()<memorySpace) {
            memorySpace = (MemorySpace_t)memRegion->getAlignment();
         }
#endif
         // Get size of continuous block containing address
         uint32_t lastContinuous=0;
         memRegion->findLastContiguous(memoryAddress, &lastContinuous);
         uint32_t continousBlockSize = lastContinuous+1-(memoryAddress);

         unsigned blockSize = regionSize;
         if (blockSize > continousBlockSize) {
            blockSize = continousBlockSize;
         }

         if (blockSize > MAX_BUFFER) {
            blockSize = MAX_BUFFER;
         }
#if (TARGET != MC56F80xx)
         // Change alignment to match item if necessary
         if ((imageAddress & ((memorySpace&MS_SIZE)-1)) != 0) {
            // Unaligned start address
            memorySpace = (MemorySpace_t)((memorySpace&~MS_SIZE)|MS_Byte);
         }
         if (((imageAddress+blockSize) & ((memorySpace&MS_SIZE)-1)) != 0) {
            // Unaligned end address
            memorySpace = (MemorySpace_t)((memorySpace&~MS_SIZE)|MS_Byte);
         }
#endif
         if (bdmInterface->readMemory(memorySpace, blockSize*sizeof(uint8_t), memoryAddress, (uint8_t *)buffer) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_READ;
         }
         blockResult = TRUE;
         uint32_t testIndex;
         for (testIndex=0; testIndex<blockSize; testIndex++) {
            if (flashImage->getValue(imageAddress+testIndex) != buffer[testIndex]) {
               blockResult = FALSE;
#ifndef LOG
               break;
#else
               if (!reportedError) {
                  log.print("First failed location[0x%8.8X]=>failed, image=%2.2X != target=%2.2X\n",
                     imageAddress+testIndex,
                     (uint8_t)(flashImage->getValue(imageAddress+testIndex)),
                     buffer[testIndex]);
                  // Dump region around error
                  flashImage->dumpRange((imageAddress+testIndex-31)&~0xFUL, (imageAddress+testIndex+31)|0xF);
                  reportedError = true;
               }
#endif
            }
         }
         log.print("Verified Sub-block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), memoryAddress, memoryAddress+blockSize-1, blockResult?"OK":"FAIL");
         checkResult    = checkResult && blockResult;
         regionSize    -= blockSize;
         imageAddress  += blockSize;
         memoryAddress  = imageAddress-offset;
         progressTimer->progress(blockSize, NULL);
#ifndef LOG
         if (!checkResult) {
            break;
         }
#endif
      }
#ifndef LOG
      if (!checkResult) {
         break;
      }
#endif
      // Advance to start of next occupied region
      enumerator->nextValid();
   }
   return checkResult?PROGRAMMING_RC_OK:PROGRAMMING_RC_ERROR_FAILED_VERIFY;
}

//==============================================================================
//! Verify target against flash image
//!
//! @param flashImage Flash image to verify
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doTargetVerify(FlashImagePtr flashImage) {
   LOGGING;
   USBDM_ErrorCode rc = applyFlashOperation(flashImage, OpVerify );
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Target Verifying failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//==============================================================================
//! Verify target against flash image
//!
//! @param flashImage Flash image to verify
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doVerify(FlashImagePtr flashImage) {
   LOGGING;
   USBDM_ErrorCode rc = PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   progressTimer->restart("Verifying...");

   // Try target verify then read-back verify
//   rc = doTargetVerify(flashImage);
   if (rc == PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS) {
     rc = doReadbackVerify(flashImage);
   }
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Verifying failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//==============================================================================
//! Blank check target against flash image
//!
//! @param flashImage - Flash image to verify
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doBlankCheck(FlashImagePtr flashImage) {
   LOGGING;
   progressTimer->restart("Blank Checking...");

   USBDM_ErrorCode rc = applyFlashOperation(flashImage, OpBlankCheck);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Blank check failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//==============================================================================
//! Write RAM portion of image
//!
//! @param flashImage - Flash image to verify
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_S12Z::doWriteRam(FlashImagePtr flashImage) {
   LOGGING;
   progressTimer->restart("Writing RAM...");

   USBDM_ErrorCode rc = applyFlashOperation(flashImage, OpWriteRam);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("Failed, Reason= %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//=======================================================================
//! Verify Target Flash memory
//!
//! @param flashImage        - Description of flash contents to be verified.
//! @param progressCallBack  - Callback function to indicate progress
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//! @note If target clock trimming is enabled then the Non-volatile clock trim
//!       locations are ignored.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::verifyFlash(FlashImagePtr flashImage,
                                                  CallBackT     progressCallBack) {
   LOGGING;
   USBDM_ErrorCode rc;
   if ((this == NULL) || (device->getTargetName().empty())) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   log.print("===========================================================\n");
   log.print("\tprogressCallBack = %p\n",                 progressCallBack);
   log.print("\tDevice = \'%s\'\n",                       device->getTargetName().c_str());
   log.print("\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n",   device->getClockTrimFreq(),
                                                          device->getClockTrimNVAddress(),
                                                          device->getClockAddress());
   log.print("\tRam[%4.4X...%4.4X]\n",                    device->getRamStart(), device->getRamEnd());
   log.print("\tErase=%s\n",                              DeviceData::getEraseOptionName(device->getEraseOption()));
   log.print("\tSecurity=%s\n",                           getSecurityName(device->getSecurity()));
   log.print("\tTotal bytes=%d\n",                        flashImage->getByteCount());
   log.print("===========================================================\n");

   this->doRamWrites = false;
   progressTimer.reset(new ProgressTimer(progressCallBack, flashImage->getByteCount()));
   progressTimer->restart("Initialising...");

   flashReady = FALSE;
   currentFlashProgram.reset();

   rc = initTCL();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   if (device->getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Set up the target for Flash operations
   USBDM_ErrorCode rcReset = resetAndConnectTarget();

   // Delay checking some errors until after security check so
   // error message is more meaningful
   if ((rcReset != BDM_RC_OK) &&
         (rcReset != PROGRAMMING_RC_ERROR_SECURED) &&      // Secured device
         (rcReset != BDM_RC_SECURED) &&                    // Secured device
         (rcReset != BDM_RC_BDM_EN_FAILED) &&              // BDM enable failed (on HCS devices)
         (rcReset != BDM_RC_RESET_TIMEOUT_RISE)            // Reset pulsing on Kinetis etc.
   ) {
      return rcReset;
   }
   rc = checkTargetUnSecured();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Do deferred error check
   if (rcReset != PROGRAMMING_RC_OK) {
      return rcReset;
   }
   // Modify flash image according to security options - to be consistent with what is programmed
   do {
      rc = setFlashSecurity(flashImage);
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#if (TARGET == CFV1) || (TARGET == HCS08)
      // Modify flash image according to trim options - to be consistent with what is programmed
      rc = dummyTrimLocations(flashImage);
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#endif
      // Set up for Flash operations (clock etc)
      rc = initialiseTargetFlash();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
      rc = doVerify(flashImage);
   } while (false);
   restoreSecurityAreas(flashImage);

   log.print("Verifying Time = %3.2f s, rc = %d\n", progressTimer->elapsedTime(), rc);

   return rc;
}

//=======================================================================
//! Program Target Flash memory
//!
//! @param flashImage        - Description of flash contents to be programmed.
//! @param progressCallBack  - Callback function to indicate progress
//! @param doRamWrites       - Whether to do writes to RAM
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//! @note The FTRIM etc. locations in the flash image may be modified with trim values.
//! @note Security locations within the flash image may be modified to effect the protection options.
//!
USBDM_ErrorCode FlashProgrammer_S12Z::programFlash(FlashImagePtr flashImage,
                                              CallBackT    progressCallBack,
                                              bool         doRamWrites) {
   LOGGING;

   SetProgrammingMode pmode(bdmInterface);

   if ((this == NULL) || (device->getTargetName().empty())) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
//   if (parameters.getEraseOption() == DeviceData::eraseNone) {
//      parameters.setSecurity(SEC_DEFAULT);
//   }
#ifdef GDI
   mtwksDisplayLine("===========================================================\n"
         "Programming target\n"
         "\tDevice = \'%s\'\n"
         "\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n"
         "\tRam[%4.4X...%4.4X]\n"
         "\tErase=%s\n"
         "\tSecurity=%s\n"
         "\tTotal bytes=%d\n"
         "\tdoRamWrites=%s\n",
         device->getTargetName().c_str(),
         device->getClockTrimFreq(),
         device->getClockTrimNVAddress(),
         device->getClockAddress(),
         device->getRamStart(),
         device->getRamEnd(),
         DeviceData::getEraseOptionName(device->getEraseOption()),
         getSecurityName(device->getSecurity()),
         flashImage->getByteCount(),
         doRamWrites?"T":"F");
#else
   log.print("===========================================================\n");
   log.print("\tprogressCallBack = %p\n",                 progressCallBack);
   log.print("\tDevice = \'%s\'\n",                       device->getTargetName().c_str());
   log.print("\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n",   device->getClockTrimFreq(),
                                                          device->getClockTrimNVAddress(),
                                                          device->getClockAddress());
   log.print("\tRam[%4.4X...%4.4X]\n",                    device->getRamStart(), device->getRamEnd());
   log.print("\tErase=%s\n",                              DeviceData::getEraseOptionName(device->getEraseOption()));
   log.print("\tSecurity=%s\n",                           getSecurityName(device->getSecurity()));
   log.print("\tTotal bytes=%d\n",                        flashImage->getByteCount());
   log.print("\tdoRamWrites=%s\n",                        doRamWrites?"T":"F");
   log.print("===========================================================\n");

   flashImage->printMemoryMap();
#endif

   this->doRamWrites = doRamWrites;
   progressTimer.reset(new ProgressTimer(progressCallBack, flashImage->getByteCount()));
   progressTimer->restart("Initialising...");

   flashReady = FALSE;
   currentFlashProgram.reset();

   USBDM_ErrorCode rc;

   rc = initTCL();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   if (device->getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Connect to target
   rc = resetAndConnectTarget();

   // Ignore some errors if mass erasing target as it is possible to mass
   // erase some targets without a complete debug connection
   if ((rc != BDM_RC_OK) &&
       ((device->getEraseOption() != DeviceData::eraseMass) ||
        ((rc != PROGRAMMING_RC_ERROR_SECURED) &&      // Secured device
         (rc != BDM_RC_SECURED) &&                    // Secured device
         (rc != BDM_RC_BDM_EN_FAILED) &&              // BDM enable failed (on HCS devices)
         (rc != BDM_RC_RESET_TIMEOUT_RISE)            // Reset pulsing on Kinetis etc.
         ))) {
      return rc;
   }
   bool secured = checkTargetUnSecured() != PROGRAMMING_RC_OK;

   // Check target security
   if (secured && (device->getEraseOption() != DeviceData::eraseMass)) {
      // Can't program if secured
      return PROGRAMMING_RC_ERROR_SECURED;
   }
#if (TARGET == HCS12)
   // Check for nasty chip of death
   rc = checkUnsupportedTarget();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
#if (TARGET == RS08) || (TARGET == HCS08) || (TARGET == HCS12) || (TARGET == MC56F80xx)
   // Check target SDID (RS08/HCS08/HCS12 allows SDID to be read on secured device)
   rc = confirmSDID();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
   // Mass erase if selected
   if (device->getEraseOption() == DeviceData::eraseMass) {
      rc = massEraseTarget(false);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
#if (TARGET == CFV1) || (TARGET == ARM) || (TARGET == CFVx) || (TARGET == MC56F80xx) || (TARGET == S12Z)
   // Check target SDID
   rc = confirmSDID();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
   double eraseTime = 0;
   do {
      // Modify flash image according to security options
      rc = setFlashSecurity(flashImage);
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#if (TARGET == CFVx) || (TARGET == MC56F80xx)// || (TARGET == ARM)
      rc = determineTargetSpeed();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#endif
#if (TARGET == RS08) || (TARGET == CFV1) || (TARGET == HCS08)
      // Calculate clock trim values & update memory image
      // log.print("setFlashTrimValues() - trimming\n");
      progressTimer->restart("Calculating Clock Trim");

      rc = setFlashTrimValues(flashImage);
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#endif
      // Set up for Flash operations (clock etc)
      rc = initialiseTargetFlash();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
      //
      // The above leaves the Flash ready for programming
      //
#if (TARGET==ARM) || (TARGET == CFV1) || (TARGET == S12Z) || (TARGET == MC56F80xx)
      if (device->getEraseOption() == DeviceData::eraseMass) {
         // Erase the security area as Mass erase programs it to a non-blank value
         rc = selectiveEraseFlashSecurity();
         if (rc != PROGRAMMING_RC_OK) {
            break;
         }
      }
#if (TARGET==ARM) || (TARGET == CFV1)
      // Program EEPROM/DFLASH Split
      rc = partitionFlexNVM();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#endif
#endif
      if (device->getEraseOption() == DeviceData::eraseAll) {
         // Erase all flash arrays
         rc = eraseFlash();
      }
      else if (device->getEraseOption() == DeviceData::eraseSelective) {
         // Selective erase area to be programmed - this may have collateral damage!
         rc = doSelectiveErase(flashImage);
      }
      if (rc != PROGRAMMING_RC_OK) {
         log.error("Erasing failed, Reason= %s\n", bdmInterface->getErrorString(rc));
         break;
      }
      eraseTime = progressTimer->totalTime();
      if (eraseTime <= 0.0) {
         eraseTime = 0.05;
      }
#ifdef GDI
      mtwksDisplayLine("Erase Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
            eraseTime, flashImage->getByteCount()/(1024*eraseTime),  rc);
#endif
#ifdef LOG
      log.print("Erase Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
            eraseTime, flashImage->getByteCount()/(1+1024*eraseTime),  rc);
#endif
      // Program flash
      rc = doProgram(flashImage);
      if (rc != PROGRAMMING_RC_OK) {
         log.error("Programming failed, Reason= %s\n", bdmInterface->getErrorString(rc));
         break;
      }
      if (doRamWrites){
         rc = doWriteRam(flashImage);
         if (rc != PROGRAMMING_RC_OK) {
            log.error("RAM write failed, Reason= %s\n", bdmInterface->getErrorString(rc));
            break;
         }
      }
   } while (false);
   restoreSecurityAreas(flashImage);

   double programTime = progressTimer->totalTime() - eraseTime;
   if (programTime <= 0.0) {
      programTime = 0.05;
   }
#if (TARGET == RS08) || (TARGET == HCS08) || (TARGET == CFV1)
   if (device->getClockTrimFreq() != 0) {
#ifdef GDI
      mtwksDisplayLine(" - Device Trim Value = %2.2X.%1X\n", calculatedClockTrimValue>>1, calculatedClockTrimValue&0x01);
#endif
      log.print("Device Trim Value = %2.2X.%1X\n", calculatedClockTrimValue>>1, calculatedClockTrimValue&0x01);
   }
#endif

#ifdef GDI
   mtwksDisplayLine("Programming & verifying Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
         programTime, flashImage->getByteCount()/(1024*programTime),  rc);
#endif

   log.print("Programming & verifying Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
         programTime, flashImage->getByteCount()/(1+1024*programTime),  rc);

   return rc;
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(FlashProgrammer_S12Z *pp) {
   return TcreatePluginInstance<FlashProgrammer_S12Z>(pp);
}
