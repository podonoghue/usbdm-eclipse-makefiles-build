/*! \file
   \brief Utility Routines for programming CFVx Flash

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
| 14 Apr 17 | Fixed loadTargetProgram() for OpWriteRam                      - pgo 4.12.1.170
| 4  Mar 16 | Fixed saving/restoring security regions                       - pgo 4.12.1.90
| 29 Mar 15 | Refactored                                                    - pgo 4.11.1.10
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

#define TARGET CFVx

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
#include "UsbdmTclInterpreterFactory.h"
#include "WxPlugin.h"
#ifdef GDI
#include "GDI.h"
#include "MetrowerksInterface.h"
#endif
#include "Names.h"
#include "PluginHelper.h"

#include "FlashProgrammer_CFVx.h"

static const TargetType_t targetType = T_CFVx;

ModuleInfo FlashProgrammer_CFVx::moduleInfo;

#pragma pack(1)
//! Header at the start of flash programming code (describes flash code)
struct LargeTargetImageHeader {
   uint32_t         loadAddress;       //!< Address where to load this image
   uint32_t         entry;             //!< Pointer to entry routine (for currently loaded routine)
   uint32_t         capabilities;      //!< Capabilities of routine
   uint16_t         reserved;
   uint32_t         calibFactor;       //!< Calibration factor for speed determination
   uint32_t         flashData;         //!< Pointer to information about operation
};

//! Header at the start of timing data (controls program action & holds result)
struct LargeTargetTimingDataHeader {
   uint32_t         flags;             //!< Controls actions of routine
   uint16_t         errorCode;         //!< Error code from action
   uint16_t         res1;
   uint32_t         res2;
   uint32_t         timingCount;       //!< Timing count
};

//! Header at the start of flash programming buffer (controls program action)
struct LargeTargetFlashDataHeader {
   uint32_t         flags;             //!< Controls actions of routine
   uint16_t         errorCode;         //!< Error code from action
   uint16_t         sectorSize;        //!< Size of Flash memory sectors (smallest erasable block)
   uint32_t         reserved1;
   uint32_t         controller;        //!< Ptr to flash controller
   uint32_t         frequency;         //!< Target frequency (kHz)
   uint32_t         address;           //!< Memory address being accessed (reserved/page/address)
   uint32_t         dataSize;          //!< Size of memory range being accessed
   uint32_t         dataAddress;       //!< Ptr to data to program
};
//! Holds program execution result
struct ResultStruct {
   uint32_t          flags;             //!< Incomplete actions of routine
   uint16_t          errorCode;        //!< Error code from action
   uint16_t          reserved1;
   uint32_t          reserved2;
};

//!
struct LoadInfoStruct {
   uint8_t          flags;                   //!< B7 => small program
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

/**
 * Get 32-bit target value from buffer i.e. converts from target to native format
 *
 * @param data Pointer to 1st byte of data in target format
 *
 * @return Data value in native format
 */
inline uint32_t getData32Target(uint8_t *data) {
   return getData32Be(data);
}
/**
 * Get 16-bit target value from buffer i.e. converts from target to native format
 *
 * @param data Pointer to 1st byte of data in target format
 *
 * @return Data value in native format
 */
inline uint32_t getData16Target(uint8_t *data) {
   return getData16Be(data);
}
#endif

//=======================================================================
//
FlashProgrammer_CFVx::FlashProgrammer_CFVx() :
      FlashProgrammerCommon(DeviceData::eraseAll, DeviceData::resetHardware),
      initTargetDone(false),
      currentFlashOperation(OpNone),
      currentFlashAlignment(0),
      doRamWrites(false),
      securityNeedsSelectiveErase(false) {
   LOGGING_E;
}

//=======================================================================
//
FlashProgrammer_CFVx::~FlashProgrammer_CFVx() {
   LOGGING_E;
}

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
USBDM_ErrorCode FlashProgrammer_CFVx::resetAndConnectTarget(void) {
   LOGGING;
   USBDM_ErrorCode rc;

   if (device == nullptr) {
      return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }
   if (device->getTargetName().empty()) {
      return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }
   flashReady     = false;
   initTargetDone = false;

   TargetMode_t targetMode;

   DeviceData::ResetMethod resetMethod = getResetMethod();
   log.print("Setting reset method to %s\n", DeviceData::getResetMethodName(resetMethod));
   switch (resetMethod) {
      default:
      case DeviceData::resetTargetDefault:
         log.error("Unexpected reset method %s, defaulting to hardware\n", DeviceData::getResetMethodName(resetMethod));
         // no break
      case DeviceData::resetHardware:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE);
         break;
      case DeviceData::resetSoftware:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_SOFTWARE);
         break;
      case DeviceData::resetVendor:
         targetMode = (TargetMode_t)(RESET_SPECIAL|RESET_VENDOR);
         break;
   }

   // Reset to special mode to allow unlocking of Flash
   rc = bdmInterface->reset(targetMode);
   if (rc != BDM_RC_OK) {
      // Try again with hardware reset
      log.print("failed reset with %s, retry with hardware\n", DeviceData::getResetMethodName(resetMethod));
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
USBDM_ErrorCode FlashProgrammer_CFVx::readTargetChipId(uint32_t *targetSDID, bool doInit) {
   LOGGING_E;
   doInit = doInit || (targetType == T_ARM);
   const int SDIDLength = 2;
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
USBDM_ErrorCode FlashProgrammer_CFVx::confirmSDID() {
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
USBDM_ErrorCode FlashProgrammer_CFVx::initialiseTarget() {
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
#if (TARGET == HCS08) || (TARGET == HCS12) || (TARGET == S12Z)
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
#elif (TARGET == RS08)
   char args[200] = "initTarget ";
   char *argPtr = args+strlen(args);
   sprintf(argPtr, "0x%04X 0x%04X 0x%04X",
         device->getWatchdogAddress(),
         flashMemoryRegionPtr->getFOPTAddress(),
         flashMemoryRegionPtr->getFLCRAddress()
         );
   argPtr += strlen(argPtr);
   *argPtr++ = '\0';
#else
   char args[] = "initTarget \"\"";
#endif

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
USBDM_ErrorCode FlashProgrammer_CFVx::initialiseTargetFlash() {
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
   flashReady = true;
   return PROGRAMMING_RC_OK;
}

/**
 * Does Mass Erase of Target memory using TCL script.
 *
 *  @param resetTarget Whether to reset target before action
 *
 *  @return error code, see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashProgrammer_CFVx::massEraseTarget(bool resetTarget) {
   LOGGING;

   if (resetTarget) {
      resetAndConnectTarget();
   }
   SetProgrammingMode pmode(bdmInterface);

   if (progressTimer != NULL) {
      progressTimer->restart("Mass Erasing Target");
   }
   do {
      // Temporarily switch to JTAG mode
      bdmInterface->getBdmOptions().targetType = T_JTAG;
      USBDM_ErrorCode rc = bdmInterface->initBdm();
      if(rc != BDM_RC_OK) {
         continue;
      }
      // Do Mass erase using TCL script
      rc = runTCLCommand("massEraseTarget");
      if (rc != PROGRAMMING_RC_OK) {
         continue;
      }
   } while (0);
   bdmInterface->getBdmOptions().targetType = T_CFVx;

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

// 24-30 reserved
#define IS_COMPLETE           (1U<<31)

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
#define CAP_RELOCATABLE        (1<<31) // Code may be relocated

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
USBDM_ErrorCode FlashProgrammer_CFVx::loadTargetProgram(FlashOperation flashOperation) {
   LOGGING;
   FlashProgramConstPtr flashProgram = device->getFlashProgram();
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
USBDM_ErrorCode FlashProgrammer_CFVx::loadTargetProgram(MemoryRegionConstPtr memoryRegionPtr, FlashOperation flashOperation) {
   LOGGING_Q;

   FlashProgramConstPtr flashProgram = memoryRegionPtr->getFlashprogram();
   if (!flashProgram) {
      // Try to get device general routines
      flashProgram = device->getCommonFlashProgram();
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
USBDM_ErrorCode FlashProgrammer_CFVx::loadTargetProgram(FlashProgramConstPtr flashProgram, FlashOperation flashOperation) {
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
         // All other operations don't require target Flash code
         currentFlashOperation = OpNone;
         log.print("No target program load needed\n");
         return BDM_RC_OK;
   }
   // Check if we have a target flash programming code for this region
   if (!flashProgram) {
      log.error("Failed, no flash program found for target memory region\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
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
   uint32_t imageAddress;
   USBDM_ErrorCode rc = loadSRec(flashProgram->getFlashProgram().c_str(),
                                 buffer,
                                 sizeof(buffer)/sizeof(buffer[0]),
                                 &size,
                                 &imageAddress);
   if (rc !=  BDM_RC_OK) {
      log.error("Failed, loadSRec() failed\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }

   // Find RAM region to use
   device->getRamRegionFor(imageAddress, ramStart, ramEnd);
   log.print("Using RAM region [0x%8X..0x%8X]\n", ramStart, ramEnd);

   memset(&targetProgramInfo, 0, sizeof(targetProgramInfo));

   MemorySpace_t memorySpace = MS_Byte;
   // Probe RAM buffer
   rc = probeMemory(memorySpace, ramStart);
   if (rc == BDM_RC_OK) {
      rc = probeMemory(memorySpace, ramEnd);
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, probeMemory() failed\n");
      return rc;
   }
   targetProgramInfo.smallProgram = false;
   return loadLargeTargetProgram(buffer, imageAddress, size, flashProgram, flashOperation);
}

//=======================================================================
//! Loads the given Flash programming code to target memory
//!
//! @param  buffer            buffer containing program image
//! @param  imageAddress      address of start of image (may be relocated)
//! @param  imageSize         size of image (in uint8_t)s
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
//! +---------------------------------------------------+   > Unchanging for repeated operations
//! |   Flash program code....                          |  |
//! +---------------------------------------------------+ -+
//!
USBDM_ErrorCode FlashProgrammer_CFVx::loadLargeTargetProgram(
                                                        uint8_t    *buffer,
                                                        uint32_t              imageAddress,
                                                        uint32_t              imageSize,
                                                        FlashProgramConstPtr  flashProgram,
                                                        FlashOperation        flashOperation) {
   LOGGING;
   log.print("Op=%s\n", getFlashOperationName(flashOperation));

   // Find 'header' in download image
   uint32_t headerAddress = getData32Target(buffer);
   LargeTargetImageHeader *headerPtr = (LargeTargetImageHeader*) (buffer+(headerAddress-imageAddress));
   if (headerPtr > (LargeTargetImageHeader*)(buffer+imageSize)) {
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

   if (codeLoadAddress != imageAddress) {
      log.error("Inconsistent actual (0x%06X) and image load addresses (0x%06X).\n",
            imageAddress, codeLoadAddress);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   uint32_t codeLoadSize = imageSize*sizeof(uint8_t);

   if ((capabilities&CAP_RELOCATABLE) !=0 ) {
      // Relocate Code
      codeLoadAddress = (ramStart+3)&~3; // Relocate to start of RAM
      if (imageAddress != codeLoadAddress) {
         log.print("Loading at non-default address, load@0x%04X (relocated from=%04X)\n",
               codeLoadAddress, imageAddress);
         // Relocate entry point
         codeEntry += codeLoadAddress - imageAddress;
      }
   }
   if ((codeLoadAddress < ramStart) || (codeLoadAddress > ramEnd)) {
      log.error("Image load address (0x%8X) is invalid: range [0x%8X, 0x%8X].\n", codeLoadAddress, ramStart, ramEnd);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if ((codeEntry < ramStart) || (codeEntry > ramEnd)) {
      log.error("Image Entry point (0x%8X) is invalid: range [0x%8X, 0x%8X].\n", codeEntry, ramStart, ramEnd);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if ((capabilities&CAP_DATA_FIXED)==0) {
      // Relocate Data Entry to immediately after code
      dataHeaderAddress = codeLoadAddress + imageSize;
      log.print("Relocating flashData @ 0x%06X\n", dataHeaderAddress);
   }

   // Required flash flashAlignmentMask
   uint32_t flashAlignmentMask = flashOperationInfo.alignment-1;
   uint32_t procAlignmentMask  = 2-1;

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
   targetProgramInfo.maxDataSize  = ramEnd-dataLoadAddress+1;
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
         codeLoadAddress, codeLoadAddress+imageSize-1);
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
   if ((targetProgramInfo.entry & procAlignmentMask) != (targetType == T_ARM)?1:0){
      log.error("FlashProgramHeader.entry is not aligned\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Sanity check buffer
   if (((uint32_t)(targetProgramInfo.headerAddress+targetProgramInfo.dataOffset)<ramStart) ||
       ((uint32_t)(targetProgramInfo.headerAddress+targetProgramInfo.dataOffset+targetProgramInfo.maxDataSize-1)>ramEnd)) {
      log.error("Data buffer location [0x%06X..0x%06X] is outside target RAM [0x%06X-0x%06X]\n",
            targetProgramInfo.headerAddress+targetProgramInfo.dataOffset,
            targetProgramInfo.headerAddress+targetProgramInfo.dataOffset+targetProgramInfo.maxDataSize-1,
            ramStart, ramEnd);
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if ((dataLoadAddress+40) > ramEnd) {
      log.error("Data buffer is too small [0x%X..0x%X] \n", dataLoadAddress, ramEnd);
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

   log.print("Loaded Image (modified) :\n");
   log.print("   flashProgramHeader.loadAddress     = 0x%08X\n",      targetToNative32(headerPtr->loadAddress));
   log.print("   flashProgramHeader.entry           = 0x%08X\n",      targetToNative32(headerPtr->entry));
   log.print("   flashProgramHeader.capabilities    = 0x%08X(%s)\n",  capabilities,getProgramCapabilityNames(capabilities));
   log.print("   flashProgramHeader.flashData       = 0x%08X\n",      targetToNative32(headerPtr->flashData));

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
USBDM_ErrorCode FlashProgrammer_CFVx::loadSmallTargetProgram(
                                  uint8_t              *buffer,
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
const char *FlashProgrammer_CFVx::getProgramActionNames(unsigned int actions) {
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
const char *FlashProgrammer_CFVx::getProgramCapabilityNames(unsigned int actions) {
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

USBDM_ErrorCode FlashProgrammer_CFVx::convertTargetErrorCode(FlashDriverError_t rc) {

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

//=======================================================================
static bool usePSTSignals = false;
//! Check CFVx run status
//!
//! @return BDM_RC_OK   - halted\n
//!         BDM_RC_BUSY - running\n
//!         other       - error
//!
USBDM_ErrorCode FlashProgrammer_CFVx::getRunStatus(void) {
   LOGGING;
   USBDMStatus_t USBDMStatus;
   USBDM_ErrorCode rc = bdmInterface->getBDMStatus(&USBDMStatus);
   if (rc != BDM_RC_OK) {
      log.error("Failed, rc=%s\n", bdmInterface->getErrorString(rc));
      return rc;
   }
   if (usePSTSignals) {
      // Check processor state using PST signals
      if (USBDMStatus.halt_state == TARGET_RUNNING) {
		   return BDM_RC_BUSY;
      }
      else {
         return BDM_RC_OK;
      }
   }
   else {
      // Probe D0 register - if fail assume processor running!
      unsigned long int dummy;
      rc = bdmInterface->readReg(CFVx_RegD0, &dummy);
      if (rc == BDM_RC_OK) {
         // Processor halted
         return BDM_RC_OK;
      }
      else /* if (rc == BDM_RC_CF_BUS_ERROR) */{
         // Processor executing
         return BDM_RC_BUSY;
      }
   }
}

USBDM_ErrorCode FlashProgrammer_CFVx::initLargeTargetBuffer(uint8_t *buffer) {
   LOGGING;
   LargeTargetFlashDataHeader *pFlashHeader = (LargeTargetFlashDataHeader*)buffer;

   pFlashHeader->errorCode       = nativeToTarget16(-1);
   pFlashHeader->controller      = nativeToTarget32(flashOperationInfo.controller);
//   pFlashHeader->watchdogAddress = nativeToTarget16(parameters.getWatchdogAddress());
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
// log.print("   watchdogAddress        = 0x%08X\n",    targetToNative32(pFlashHeader->watchdogAddress));
   log.print("   frequency              = %d (0x%X)\n", targetToNative32(pFlashHeader->frequency),targetToNative32(pFlashHeader->frequency));
   log.print("   sectorSize             = 0x%04X\n",    targetToNative16(pFlashHeader->sectorSize));
   log.print("   address                = 0x%08X\n",    targetToNative32(pFlashHeader->address));
   log.print("   dataSize               = 0x%08X\n",    targetToNative32(pFlashHeader->dataSize));
   log.print("   dataAddress            = 0x%08X\n",    targetToNative32(pFlashHeader->dataAddress));
   pFlashHeader->errorCode = (uint16_t)-1;
   return BDM_RC_OK;
}

USBDM_ErrorCode FlashProgrammer_CFVx::initSmallTargetBuffer(uint8_t *buffer) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::executeTargetProgram(uint8_t *pBuffer, uint32_t dataSize) {
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

   for (int num=0; num<100; num++) {

//      UsbdmSystem::milliSleep(10);

      unsigned long currentPC;
      rc = bdmInterface->readPC(&currentPC);
      if (rc != BDM_RC_OK) {
         log.error("bdmInterface->readPC() Failed, rc=%s\n",
               bdmInterface->getErrorString(rc));
//         report("executeTargetProgram()");
         return rc;
      }
      if ((currentPC<(targetRegPC-0x1000))||(currentPC>(targetRegPC+0x1000))) {
         log.error("Read PC out of range, PC=0x%08X\n", currentPC);
//         report("executeTargetProgram()");
         return PROGRAMMING_RC_ERROR_BDM;
      }
      uint8_t  iBuffer[8];
      rc = bdmInterface->readMemory(1, sizeof(iBuffer), currentPC, (uint8_t *)iBuffer);
      if (rc != BDM_RC_OK) {
         log.error("bdmInterface->readMemory() Failed, rc=%s\n",
               bdmInterface->getErrorString(rc));
//         report("executeTargetProgram()");
         return rc;
      }
      log.print("Step: PC=0x%06X => %02X %02X %02X %02X\n",
             currentPC, iBuffer[0], iBuffer[1], iBuffer[2], iBuffer[3]);

      USBDM_ErrorCode rc = bdmInterface->go();
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
   } while ((getRunStatus() == BDM_RC_BUSY) && (--timeout>0));
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
USBDM_ErrorCode FlashProgrammer_CFVx::determineTargetSpeed(void) {
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
   timingData.flags      = nativeToTarget32(DO_TIMING_LOOP|IS_COMPLETE); // IS_COMPLETE as check - should be cleared

   log.print("flags      = 0x%08X(%s)\n",
         targetToNative32(timingData.flags), getProgramActionNames(targetToNative32(timingData.flags))
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
   timingDataResult.flags        = targetToNative32(timingDataResult.flags);
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
   targetBusFrequency = 50*int(0.5+((250.0 * timingDataResult.timingCount)/targetProgramInfo.calibFactor));
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
USBDM_ErrorCode FlashProgrammer_CFVx::eraseFlash(void) {
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

//#if (TARGET == CFV1) || (TARGET == ARM) || (TARGET == HCS08) || (TARGET == HCS12) || (TARGET == S12Z) || (TARGET == MC56F80xx)
//=======================================================================
//! Selective erases the target memory security areas.
//! This is only of use when the target is unsecured but the security
//! needs to be modified.
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_CFVx::selectiveEraseFlashSecurity(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (!securityNeedsSelectiveErase) {
      log.print("Security areas are blank/correct - no erasure required\n");
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
      uint32_t securityRegionAddress = memoryRegionPtr->getSecurityAddress();
      if (securityRegionAddress == 0) {
         continue;
      }
      SecurityInfoConstPtr securityInfo = memoryRegionPtr->getSecureInfo();
      uint32_t securitySize = securityInfo->getSize();
      if (securityInfo == NULL) {
         continue;
      }
      log.print("Erasing security area %s[0x%06X..0x%06X]\n",
            memoryRegionPtr->getMemoryTypeName(), securityRegionAddress, securityRegionAddress+securitySize-1);

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
#if (TARGET == CFV1) || (TARGET == ARM)
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if ((memoryType == MemFlexNVM) || (memoryType == MemDFlash)) {
         // Flag need for DFLASH/flexNVM access
         addressFlag |= ADDRESS_A23;
      }
#endif
      flashOperationInfo.flashAddress = securityRegionAddress|addressFlag;
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
//#endif


//=======================================================================
//! Check security state of target
//!
//! @return PROGRAMMING_RC_OK => device is unsecured           \n
//!         PROGRAMMING_RC_ERROR_SECURED => device is secured  \n
//!         else error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//!
USBDM_ErrorCode FlashProgrammer_CFVx::checkTargetUnSecured() {
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
USBDM_ErrorCode FlashProgrammer_CFVx::doFlashBlock(
                                                  FlashImagePtr    flashImage,
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
   if (flashOperation != OpWriteRam) {
      USBDM_ErrorCode rc = loadTargetProgram(memoryRegionPtr, flashOperation);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
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
#elif (TARGET == CFV1)
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
USBDM_ErrorCode FlashProgrammer_CFVx::applyFlashOperation(FlashImagePtr flashImage, FlashOperation flashOperation) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::doProgram(FlashImagePtr flashImage) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::doSelectiveErase(FlashImagePtr flashImage) {
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
//! doImageCheck - Checks the memory image against the target memory range
//!
//! @param flashImage Description of flash contents to be checked.
//!
//! @return error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//! @note Assumes target connection has been established
//! @note Assumes call-back has been set up if used.
USBDM_ErrorCode FlashProgrammer_CFVx::doImageCheck(FlashImagePtr flashImage) {
   LOGGING;

   flashImage->printMemoryMap();

   FlashImage::EnumeratorPtr imageEnumerator = flashImage->getEnumerator();
   if (!imageEnumerator->isValid()) {
      log.print("Empty Memory region\n");
      flashImage->printMemoryMap();
   }

   USBDM_ErrorCode checkResult = BDM_RC_OK;

   while (imageEnumerator->isValid()) {
      // Process region in flash image

      uint32_t imageAddress  = imageEnumerator->getAddress();

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

      // Find end of image block to check
      imageEnumerator->lastValid();
      unsigned regionSize = imageEnumerator->getAddress() - imageAddress + 1;

      while (regionSize>0) {
         // Get memory block containing address
         MemoryRegionConstPtr memRegion = device->getMemoryRegionFor(imageAddress, memorySpace);
         if (memRegion == nullptr) {
            // Start not in range
            checkResult = PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
            log.error("Checked Block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), imageAddress, imageAddress+regionSize-1, bdmInterface->getErrorString(checkResult));
            break;
         }
         // Get size of continuous block containing address
         uint32_t lastContinuous=0;
         memRegion->findLastContiguous(imageAddress, &lastContinuous);
         uint32_t continousBlockSize = lastContinuous+1-(imageAddress);

         // Calculate region checked
         unsigned blockSize = regionSize;
         if (blockSize > continousBlockSize) {
            blockSize = continousBlockSize;
         }
         log.error("Checked Block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), imageAddress, imageAddress+regionSize-1, bdmInterface->getErrorString(BDM_RC_OK));

         // Advance to next block in region
         regionSize    -= blockSize;
         imageAddress  += blockSize;
      }
#ifndef LOG
      if (checkResult != BDM_RC_OK) {
         break;
      }
#endif
      // Advance to start of next occupied region
      imageEnumerator->nextValid();
   }
   return checkResult;
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
USBDM_ErrorCode FlashProgrammer_CFVx::doReadbackVerify(FlashImagePtr flashImage) {
   LOGGING;
   const unsigned MAX_BUFFER=0x800;
   uint8_t buffer[MAX_BUFFER];
   USBDM_ErrorCode checkResult = BDM_RC_OK;

#ifdef LOG
   // Used to suppress multiple error messages
   bool            reportedError = false;
#endif

   flashImage->printMemoryMap();

   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();
   if (!enumerator->isValid()) {
      log.print("Empty Memory region\n");
      flashImage->printMemoryMap();
   }

   while (enumerator->isValid()) {
      // Check each memory region in image

      uint32_t imageAddress = enumerator->getAddress();

#if (TARGET==HCS08)||(TARGET==HC12)
      USBDM_ErrorCode rc = setPageRegisters(imageAddress);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
#endif

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

      while (regionSize>0) {
         // Get memory block containing address
         MemoryRegionConstPtr memRegion = device->getMemoryRegionFor(imageAddress, memorySpace);
         if (memRegion == NULL) {
            checkResult = PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
            log.error("Verifying Block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), imageAddress, imageAddress+regionSize-1, bdmInterface->getErrorString(checkResult));
            break;
         }
#if (TARGET == ARM)
         if (memRegion->getAlignment()<memorySpace) {
            memorySpace = (MemorySpace_t)memRegion->getAlignment();
         }
#endif
         // Get size of continuous block containing address
         uint32_t lastContinuous=0;
         memRegion->findLastContiguous(imageAddress, &lastContinuous);
         uint32_t continousBlockSize = lastContinuous+1-(imageAddress);

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
         if (bdmInterface->readMemory(memorySpace, blockSize*sizeof(uint8_t), imageAddress, (uint8_t *)buffer) != BDM_RC_OK) {
            return PROGRAMMING_RC_ERROR_BDM_READ;
         }
         USBDM_ErrorCode blockResult = BDM_RC_OK;
         uint32_t testIndex;
         for (testIndex=0; testIndex<blockSize; testIndex++) {
            if (flashImage->getValue(imageAddress+testIndex) != buffer[testIndex]) {
               blockResult = PROGRAMMING_RC_ERROR_FAILED_VERIFY;
#ifndef LOG
               break;
#else
               if (!reportedError) {
                  log.print("First failed location[0x%8.8X]=>failed, image=%2.2X != target=%2.2X\n",
                     imageAddress+testIndex,
                     (uint8_t)(flashImage->getValue(imageAddress+testIndex)),
                     buffer[testIndex]);
                  // Dump region around error
                  uint32_t start = 0;
                  if ((imageAddress+testIndex)>31) {
                     start = (imageAddress+testIndex-31);
                  }
                  uint32_t end = 0xFFFFFFFF;
                  if ((imageAddress+testIndex)<(end-31)) {
                     end = imageAddress+testIndex;
                  }
                  start &= ~0xFUL;
                  end   |= 0xFUL;
                  log.print("Image[0x%08X..0x%08X]\n", start, end);
                  flashImage->dumpRange(start, end);
                  reportedError = true;
                  uint8_t tBuff[end-start+1];
                  if (bdmInterface->readMemory(memorySpace, (end-start+1), start, (uint8_t *)tBuff) == BDM_RC_OK) {
                     log.printDump(tBuff, (end-start+1), start);
                  }
               }
#endif
            }
         }
         log.print("Verified Sub-block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), imageAddress, imageAddress+blockSize-1, bdmInterface->getErrorString(blockResult));
         if (checkResult == BDM_RC_OK) {
            // Only record first error
            checkResult = blockResult;
         }
         regionSize    -= blockSize;
         imageAddress  += blockSize;
         progressTimer->progress(blockSize, NULL);
#ifndef LOG
         if (checkResult != BDM_RC_OK) {
            break;
         }
#endif
      }
#ifndef LOG
      if (checkResult != BDM_RC_OK) {
         break;
      }
#endif
      // Advance to start of next occupied region
      enumerator->nextValid();
   }
   return checkResult;
}

//==============================================================================
//! Verify target against flash image
//!
//! @param flashImage Flash image to verify
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_CFVx::doTargetVerify(FlashImagePtr flashImage) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::doVerify(FlashImagePtr flashImage) {
   LOGGING;
   progressTimer->restart("Verifying...");

   //TODO - Review handling of linear addresses

   // Try target verify then read-back verify
   // This is a bit of a hack to cope with linear addressing failing doReadbackVerify()
//   rc = doTargetVerify(flashImage);
//   if (rc == PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS) {
//     rc = doReadbackVerify(flashImage);
//   }
   // Check target SDID to make sure correct memory map is in use
   USBDM_ErrorCode rc = confirmSDID();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }

   rc = doReadbackVerify(flashImage);
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
USBDM_ErrorCode FlashProgrammer_CFVx::doBlankCheck(FlashImagePtr flashImage) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::doWriteRam(FlashImagePtr flashImage) {
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
USBDM_ErrorCode FlashProgrammer_CFVx::verifyFlash(FlashImagePtr flashImage,
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
   log.print("\tReset=%s\n",                              DeviceData::getResetMethodName(getResetMethod()));
   log.print("\tSecurity=%s\n",                           getSecurityName(device->getSecurity()));
   log.print("\tTotal bytes=%d\n",                        flashImage->getByteCount());
   log.print("===========================================================\n");

   this->doRamWrites = false;
   progressTimer.reset(new ProgressTimer(progressCallBack, flashImage->getByteCount()));
   progressTimer->restart("Initialising...");

   flashReady = false;
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
      SecurityModifier modifier(*this, flashImage);
      rc = modifier.getRc();
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
USBDM_ErrorCode FlashProgrammer_CFVx::programFlash(FlashImagePtr flashImage,
                                              CallBackT    progressCallBack,
                                              bool         doRamWrites) {
   LOGGING;

   SetProgrammingMode pmode(bdmInterface);

   if ((device == nullptr) || (device->getTargetName().empty())) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
//   if (parameters.getEraseMethod() == DeviceData::eraseNone) {
//      parameters.setSecurity(SEC_DEFAULT);
//   }
#ifdef GDI
   mtwksDisplayLine("===========================================================\n"
         "Programming target\n"
         "\tDevice = \'%s\'\n"
         "\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n"
         "\tErase=%s\n"
         "\tReset=%s\n"
         "\tSecurity=%s\n"
         "\tTotal bytes=%d\n"
         "\tdoRamWrites=%s\n",
         device->getTargetName().c_str(),
         device->getClockTrimFreq(),
         device->getClockTrimNVAddress(),
         device->getClockAddress(),
         DeviceData::getEraseMethodName(getEraseMethod()),
         DeviceData::getResetMethodName(getResetMethod()),
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
   log.print("\tErase=%s\n",                              DeviceData::getEraseMethodName(getEraseMethod()));
   log.print("\tReset=%s\n",                              DeviceData::getResetMethodName(getResetMethod()));
   log.print("\tSecurity=%s\n",                           getSecurityName(device->getSecurity()));
   log.print("\tTotal bytes=%d\n",                        flashImage->getByteCount());
   log.print("\tdoRamWrites=%s\n",                        doRamWrites?"T":"F");
   log.print("===========================================================\n");

   flashImage->printMemoryMap();
#endif

   this->doRamWrites = doRamWrites;
   progressTimer.reset(new ProgressTimer(progressCallBack, flashImage->getByteCount()));
   progressTimer->restart("Initialising...");

   flashReady = false;
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
       ((getEraseMethod() != DeviceData::eraseMass) ||
        ((rc != PROGRAMMING_RC_ERROR_SECURED) &&      // Secured device
         (rc != BDM_RC_SECURED) &&                    // Secured device
         (rc != BDM_RC_BDM_EN_FAILED) &&              // BDM enable failed (on HCS devices)
         (rc != BDM_RC_RESET_TIMEOUT_RISE)            // Reset pulsing on Kinetis etc.
         ))) {
      return rc;
   }
   bool secured = checkTargetUnSecured() != PROGRAMMING_RC_OK;

   // Check target security
   if (secured && (getEraseMethod() != DeviceData::eraseMass)) {
      // Can't program if secured
      return PROGRAMMING_RC_ERROR_SECURED;
   }
#if (TARGET == HCS12)
   // Check for nasty chip of death
   rc = checkUnsupportedTarget(device->getSecurity());
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif

   bool targetChecked = false;
#if (TARGET == RS08) || (TARGET == HCS08) || (TARGET == HCS12) || (TARGET == MC56F80xx)
   // Check target SDID before mass erasing (RS08/HCS08/HCS12 allows SDID to be read on secured device)
   rc = confirmSDID();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   targetChecked = true;
#endif

   // Check if image matches device before modifying device!
   rc = doImageCheck(flashImage);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }

   // Mass erase if selected
   if (getEraseMethod() == DeviceData::eraseMass) {
      // Mass erase and (temporarily) unsecure device
      rc = massEraseTarget(true);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
   if (!targetChecked) {
      // Check target SDID
      rc = confirmSDID();
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
   double eraseTime = 0;
   do {
      // Modify flash image according to security options
      // Note: This MUST be done after mass erase if used!
      SecurityModifier modifier(*this, flashImage);
      rc = modifier.getRc();
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
      // Erase the security area as necessary
      rc = selectiveEraseFlashSecurity();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#if (TARGET==ARM) || (TARGET == CFV1)
      // Program EEPROM/DFLASH Split
      rc = partitionFlexNVM();
      if (rc != PROGRAMMING_RC_OK) {
         break;
      }
#endif
      if (getEraseMethod() == DeviceData::eraseAll) {
         // Erase all flash arrays
         rc = eraseFlash();
      }
      else if (getEraseMethod() == DeviceData::eraseSelective) {
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
size_t CPP_DLL_EXPORT createPluginInstance(FlashProgrammer_CFVx *pp) {
   return TcreatePluginInstance<FlashProgrammer_CFVx>(pp);
}
