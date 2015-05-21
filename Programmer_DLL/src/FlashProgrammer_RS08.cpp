/*! \file
   \brief Utility Routines for programming RS08 Flash

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
| 29 Mar 15 | Refactored                                                    - pgo 4.10.7.10 
+-----------+--------------------------------------------------------------------------------
| 18 Dec 14 | TCL interface changes                                         - pgo V4.10.6.240
| 17 Aug 14 | Changed SDID structure to support multiple masks              - pgo V4.10.6.180
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

#define TARGET RS08

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
#include "wxPlugin.h"
#ifdef GDI
#include "GDI.h"
#include "MetrowerksInterface.h"
#endif
#include "Names.h"
#include "PluginHelper.h"

#include "FlashProgrammer_RS08.h"

static const TargetType_t targetType = T_HCS12;


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

FlashProgrammer_RS08::FlashProgrammer_RS08() :
      initTargetDone(false),
      targetBusFrequency(0),
      doRamWrites(false),
      securityNeedsSelectiveErase(false) {
   LOGGING_E;
}


//=======================================================================
FlashProgrammer_RS08::~FlashProgrammer_RS08() {
   LOGGING_E;
}

//=======================================================================
//! Calculate delay value for Flash programming. \n
//! See flash program for calculation method.
//!
//! @param delayValue  = Delay value passed to target program
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_RS08::calculateFlashDelay(uint8_t *delayValue) {
   LOGGING_Q;

   unsigned long bdmFrequency;
   double busFrequency;
   USBDM_ErrorCode rc;

   rc = bdmInterface->getSpeedHz(&bdmFrequency);
   if (rc != BDM_RC_OK) {
      return PROGRAMMING_RC_ERROR_BDM;
   }
   busFrequency = bdmFrequency;

   // The values are chosen to satisfy Tprog including loop overhead above.
   // The other delays are less critical (minimums only)
   // Assuming bus freq. = ~4 MHz clock => 250 ns, 4cy = 1us
   // For 30us@4MHz, 4x30 = 120 cy, N = (4x30-30-10)/4 = 20
   double tempValue = round(((busFrequency*30E-6)-30-10)/4);
   if ((tempValue<0) || (tempValue>255)) {
      // must be 8 bits
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   *delayValue = tempValue;
   log.print("FlashProgrammer_RS08::calculateFlashDelay() => busFreq=%f Hz, delValue=%d\n", busFrequency, *delayValue);

   return PROGRAMMING_RC_OK;
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
USBDM_ErrorCode FlashProgrammer_RS08::resetAndConnectTarget(void) {
   LOGGING;
   USBDM_ErrorCode rc;

   if (parameters.getTargetName().empty()) {
      return PROGRAMMING_RC_ERROR_ILLEGAL_PARAMS;
   }
   flashReady     = false;
   initTargetDone = false;

   // Reset to special mode to allow unlocking of Flash
#if (TARGET == ARM)
   rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   if ((rc != BDM_RC_OK) && (rc != BDM_RC_SECURED)) {
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE));
   }
#elif TARGET == MC56F80xx
   rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   if ((rc != BDM_RC_OK) && (rc != BDM_RC_SECURED)) {
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE));
   }
#elif (TARGET == CFVx) || (TARGET == HC12)
   rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   if (rc != BDM_RC_OK) {
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE));
   }
#else
   bdmInterface->connect();
   rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
   if (rc != BDM_RC_OK) {
      bdmInterface->connect();
      rc = bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE));
   }
#endif
   if (rc == BDM_RC_SECURED) {
      log.error("... Device is secured\n");
      return PROGRAMMING_RC_ERROR_SECURED;
   }
   if (rc != BDM_RC_OK) {
      log.error( "... Failed Reset, %s!\n", bdmInterface->getErrorString(rc));
      return rc; //PROGRAMMING_RC_ERROR_BDM_CONNECT;
   }
   // Try auto Connect to target
#if TARGET == MC56F80xx
   rc = bdmInterface->connect();
#else
   // BDM_RC_BDM_EN_FAILED usually means a secured device
   rc = bdmInterface->connect();
#endif
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
USBDM_ErrorCode FlashProgrammer_RS08::readTargetChipId(uint32_t *targetSDID) {
   LOGGING_E;
   bool doInit = (targetType == T_ARM);
   const int SDIDLength = 2;
   uint8_t SDIDValue[SDIDLength];

   *targetSDID = 0x0000;

   if (parameters.getTargetName().empty()) {
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
   if (bdmInterface->readMemory(SDIDLength, SDIDLength, parameters.getSDIDAddress(), SDIDValue) !=  BDM_RC_OK) {
      log.error("A=0x%06X - Failed bdmInterface->readMemory()\n", parameters.getSDIDAddress());
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
      log.error("A=0x%06X - Value invalid (0x%08X)\n", parameters.getSDIDAddress(), testValue);
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   log.print("A=0x%06X => 0x%08X\n", parameters.getSDIDAddress(), testValue);
   return PROGRAMMING_RC_OK;
}

//=============================================================================
//! Check the target SDID agrees with device parameters
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes the target has been connected to
//!
USBDM_ErrorCode FlashProgrammer_RS08::confirmSDID() {
   LOGGING_E;
   uint32_t targetSDID;
   USBDM_ErrorCode rc;

//   mtwksDisplayLine("confirmSDID() - #1\n");
   if (parameters.getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
//   mtwksDisplayLine("confirmSDID() - #2\n");
   // Don't check Target SDID if zero
   if ((parameters.getSDID().mask == 0x0000) || (parameters.getSDID().value == 0x0000)) {
      log.print("V=0x0000 => Skipping check\n");
      return PROGRAMMING_RC_OK;
   }
   // Get SDID from target
   rc = readTargetChipId(&targetSDID);
   if (rc != PROGRAMMING_RC_OK) {
      log.error("M=0x%8.8X, V=0x%8.8X => Failed, error reading SDID, reason = %s\n",
                     parameters.getSDID().mask,
                     parameters.getSDID().value,
            bdmInterface->getErrorString(rc));
      // Return this error even though the cause may be different
      return PROGRAMMING_RC_ERROR_WRONG_SDID;
   }
   if (!parameters.isThisDevice(targetSDID)) {
      log.error("M=0x%8.8X, V=0x%8.8X => Failed (Target SDID=0x%8.8X)\n",
            parameters.getSDID().mask,
            parameters.getSDID().value,
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
USBDM_ErrorCode FlashProgrammer_RS08::initialiseTarget() {
   LOGGING;
   USBDM_ErrorCode rc;
   if (initTargetDone) {
      log.print("Already done, skipped\n");
      return PROGRAMMING_RC_OK;
   }
   initTargetDone = true;

#if (TARGET == HCS08)
   char args[200] = "initTarget \"";
   char *argPtr = args+strlen(args);

   // Add address of each flash region
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = parameters.getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      if (!memoryRegionPtr->isProgrammableMemory()) {
         continue;
      }
      sprintf(argPtr, " 0x%04X",
            memoryRegionPtr->getDummyAddress()&0xFFFF);
      argPtr += strlen(argPtr);
   }
   *argPtr++ = '\"';
   *argPtr++ = '\0';
#elif (TARGET == HCS12) || (TARGET == S12Z)
   char args[200] = "initTarget \"";
   char *argPtr = args+strlen(args);

   // Add address of each flash region
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = parameters.getMemoryRegion(index);
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
         parameters.getWatchdogAddress(),
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
   return rc;
}

//=============================================================================
//! Prepares the target for Flash and eeprom operations. \n
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note Assumes target has been reset & connected
//!
USBDM_ErrorCode FlashProgrammer_RS08::initialiseTargetFlash() {
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
      if (parameters.getConnectionFreq() == 0)
         return PROGRAMMING_RC_ERROR_SPEED_APPROX;

      // Set user supplied speed & confirm SDID as basic communication check
      bdmInterface->setSpeedHz(parameters.getConnectionFreq()/1000);
      if (confirmSDID() != PROGRAMMING_RC_OK)
         return PROGRAMMING_RC_ERROR_SPEED_APPROX;

      busFrequency = parameters.getConnectionFreq()*parameters.getBDMtoBUSFactor();
      log.print("Using user-supplied bus speed = %lud kHz\n",
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
//   this->flashData.frequency = targetBusFrequency;

   log.print("Target Bus Frequency = %ld kHz\n", (unsigned long)targetBusFrequency);
#endif

   char buffer[100];
   sprintf(buffer, "initFlash %d", targetBusFrequency);
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
USBDM_ErrorCode FlashProgrammer_RS08::massEraseTarget(void) {
   LOGGING;

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
//! Program to download to target RAM
//! This program is used to program the target Flash from a
//! buffer also in target RAM.
//!
static const uint8_t  RS08_flashProgram[48] = {
//                 ;********************************************************************************
//                 ; Fast RAM ($0 - $D)
//                 ;
//                 ; Programming parameters (values given are dummies for testing)
//                 ;
//                 ; This area of memory is re-written for each block (<= 8 bytes) written to flash
//                 ; The last byte (SourceAddr) is used as a flag to control execution as well as the
//                 ; source buffer address/count.  It is the last byte written by the BDM to start programming.
//                 ; The values must lie within a single flash page (64 byte modulo)
//                 ;
//                 ; Example values are for a write of 6 bytes [$11,$22,$33,$44,$55,$66] => [$3F3A..$3F3F]
//                 ;
// 0000     FLCRAddress       dc.b     HIGH_6_13(FLCR)                 ; Page # for FLCR Reg
// 0001     Buffer            dc.b     $11,$22,$33,$44,$55,$66,$77,$88 ; Buffer for data to program (<= 8 bytes)
// 0009     DestinationAddr   dc.b     MAP_ADDR_6(Destination)         ; Address in Paging Window for destination
// 000A     DestinationPage   dc.b     HIGH_6_13(Destination)          ; Page for destination
// 000B     DelayValue        dc.b     22                              ; Delay value (4MHz=>N=22, 8MHz=>N=44)
// 000C     SourceAddr        dc.b     Buffer                          ; Address in Zero Page buffer for source
// 000D     ByteCount         dc.b     BufferSize                      ; # of byte to write <page & buffer size
//
//                 ;********************************************************************************
//                 ; Flash programming code in Z-Page RAM
//                 ;
//                         //       org   RAMStart
//                         // Start:
/* 0000 */ 0x8D,           //     clr   ByteCount                  ; Set Idle mode
//                         // Idle:
/* 0001 */ 0xCD,           //     lda   ByteCount
/* 0002 */ 0x37,0xFD,      //     beq   Idle                       ; Wait for some bytes to program
/* 0004 */ 0xC0,           //     lda   FLCRAddress
/* 0005 */ 0xFF,           //     sta   PAGESEL                    ;
/* 0006 */ 0x10,0xD1,      //     bset  FLCR_PGM,MAP_ADDR_6(FLCR)  ; Enable Flash programming
/* 0008 */ 0xCA,           //     lda   DestinationPage            ; Set window to page to program
/* 0009 */ 0xFF,           //     sta   PAGESEL
/* 000A */ 0x3F,0xC0,      //     clr   MAP_ADDR_6(0)              ; Dummy write to Flash block
/* 000C */ 0xAD,0x1C,      //     bsr   delay30us                  ; Wait Tnvs
/* 000E */ 0x16,0xD1,      //     bset  FLCR_HVEN,MAP_ADDR_6(FLCR) ; Enable Flash high voltage
/* 0010 */ 0xAD,0x18,      //     bsr   delay30us                  ; Wait Tpgs
//                         // Loop:                                ; Copy byte to flash (program)
/* 0012 */ 0xCA,           //     lda   DestinationPage            ; 2 cy - Set window to page to program
/* 0013 */ 0xFF,           //     sta   PAGESEL                    ; 2 cy
/* 0014 */ 0xCC,           //     lda   SourceAddr                 ; 3 cy
/* 0015 */ 0xEF,           //     sta   X                          ; 2 cy
/* 0016 */ 0xCE,           //     lda   D[X]                       ; 3 cy
/* 0017 */ 0x4E,0x09,0x0F, //     mov   DestinationAddr,X          ; 5 cy
/* 001A */ 0xEE,           //     sta   D[X]                       ; 2 cy
/* 001B */ 0xAD,0x0D,      //     bsr   delay30us                  ; 3 cy    - Wait Tprog
/* 001D */ 0x29,           //     inc   DestinationAddr            ; 4 cy    - Update ptrs/counter
/* 001E */ 0x2C,           //     inc   SourceAddr
/* 001F */ 0x3B,0x0D,0xF0, //     dbnz  ByteCount,Loop             ; 4 cy    - Finished? - no, loop for next byte
/* 0022 */ 0x11,0xD1,      //     bclr  FLCR_PGM,MAP_ADDR_6(FLCR)  ; Disable Flash programming
/* 0024 */ 0xAD,0x04,      //     bsr   delay30us                  ; Wait Tnvh
/* 0026 */ 0x17,0xD1,      //     bclr  FLCR_HVEN,MAP_ADDR_6(FLCR) ; Disable High voltage
/* 0028 */ 0x30,0xD6,      //     bra   Start                      ; Back for more
//
//                 ;*********************************************************************
//                 ; A short delay (~30us) sufficient to satisfy all the required delays
//                 ; The PAGESEL register is set to point at the FLCR page
//                 ;
//                 ;         Tnvs  > 5us
//                 ;         Tpgs  > 10us
//                 ;         Tnvh  > 5us
//                 ;  40us > Tprog > 20us
//                 ;
//                 ; The delay may be adjusted through DelayValue
//                 ; The values are chosen to satisfy Tprog including loop overhead above (30).
//                 ; The other delays are less critical (minimums only)
//                 ; Example:
//                 ; bus freq. = ~4 MHz clock => 250 ns, 4cy = 1us
//                 ; For 30us@4MHz, 4x30 = 120 cy, so N = (4x30-30-10)/4 = 20
//                 ; Examples (30xFreq-40)/4:
//                 ;  20 MHz   N=140
//                 ;   8 MHz   N=50
//                 ;   4 MHz   N=20
//                 ;   2 MHz   N=5
//                        // delay30us:
/* 002A */ 0xCB,          //      lda   DelayValue              ;   3 cy
/* 002B */ 0x4B,0xFE,     //      dbnza *                       ; 4*N cy
/* 002D */ 0xC0,          //      lda   FLCRAddress             ;   2 cy
/* 002E */ 0xFF,          //      sta   PAGESEL                 ;   2 cy
/* 002F */ 0xBE,          //      rts                           ;   3 cy
};

//=======================================================================
//!  Relocate (apply fixups) to program image
//!
//!  @param buffer - writable copy of RS08_flashProgram for patching
//!
void FlashProgrammer_RS08::RS08_doFixups(uint8_t buffer[]) {
   // A bit ugly
   buffer[0x07] = RS08_WIN_ADDR(flashMemoryRegionPtr->getFLCRAddress());
   buffer[0x0F] = RS08_WIN_ADDR(flashMemoryRegionPtr->getFLCRAddress());
   buffer[0x23] = RS08_WIN_ADDR(flashMemoryRegionPtr->getFLCRAddress());
   buffer[0x27] = RS08_WIN_ADDR(flashMemoryRegionPtr->getFLCRAddress());
}

//=======================================================================
//! Loads the Flash programming code to target memory
//!
//!  This routine does the following:
//!   - Downloads the Flash programming code into the direct memory of
//!     the RS08 target and then verifies this by reading it back.
//!   - Starts the target program execution (program will be idle).
//!   - Instructs the BDM to enable the Flash programming voltage
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note - Assumes the target has been initialised for programming.
//!         Confirms download and checks RAM upper boundary.
//!
USBDM_ErrorCode FlashProgrammer_RS08::loadAndStartExecutingTargetProgram() {
   LOGGING;
   USBDM_ErrorCode BDMrc;
   uint8_t programImage[sizeof(RS08_flashProgram)];
   uint8_t verifyBuffer[sizeof(RS08_flashProgram)];

   log.print("FlashProgrammer_RS08::loadAndExecuteTargetProgram()\n");

   // Create & patch image of program for target memory
   memcpy(programImage, RS08_flashProgram, sizeof(RS08_flashProgram));
   // Patch relocated addresses
   RS08_doFixups(programImage);

   // Write Flash programming code to Target memory
   BDMrc = bdmInterface->writeMemory(1,
                          sizeof(programImage),
                          parameters.getRamStart(),
                          programImage );
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM_WRITE;

   // Read back to verify
   BDMrc = bdmInterface->readMemory(1,
                         sizeof(programImage),
                         parameters.getRamStart(),
                         verifyBuffer );
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM_READ;

   // Verify correctly loaded
   if (memcmp(verifyBuffer,
              programImage,
              sizeof(programImage)) != 0) {
      log.print("FlashProgrammer_RS08::loadAndExecuteTargetProgram() - program load verify failed\n");
      return PROGRAMMING_RC_ERROR_BDM_READ;
   }
   // Start flash code on target
   BDMrc = bdmInterface->writePC(parameters.getRamStart());
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM_WRITE;

   BDMrc = bdmInterface->go();
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM;

   BDMrc = bdmInterface->setTargetVpp(BDM_TARGET_VPP_STANDBY);
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM;

   BDMrc = bdmInterface->setTargetVpp(BDM_TARGET_VPP_ON);
   if (BDMrc != BDM_RC_OK)
      return PROGRAMMING_RC_ERROR_BDM;

   return PROGRAMMING_RC_OK;
}

//==================================================================================
//! Write data to RS08 Flash memory - (within a single page of Flash, & buffer size)
//!
//! @param byteCount   = Number of bytes to transfer
//! @param address     = Memory address
//! @param data        = Ptr to block of data to write
//! @param delayValue  = Delay value for target program
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_RS08::writeFlashBlock( unsigned int        byteCount,
                                               unsigned int        address,
                                               unsigned const char *data,
                                               uint8_t             delayValue) {
   LOGGING;
   int rc;
   uint8_t flashCommand[14]  = {0x00};
   uint8_t flashStatus;
//   const uint32_t PTADAddress  = 0x10;
//   const uint32_t PTADDAddress = 0x11;
//   const uint32_t PTCDAddress  = 0x4A;
//   const uint32_t PTCDDAddress = 0x4B;
//   const uint8_t  zero    = 0x00;
//   const uint8_t  allOnes = 0xFF;

   log.print("FlashProgrammer_RS08::writeFlashBlock(count=0x%X(%d), addr=[0x%06X..0x%06X])\n",
         byteCount, byteCount, address, address+byteCount-1);
   log.printDump(data, byteCount, address);

   // 0000     FLCRAddress       dc.b     HIGH_6_13(FLCR)                 ; Page # for FLCR Reg
   // 0001     Buffer            dc.b     $11,$22,$33,$44,$55,$66,$77,$88 ; Buffer for data to program (<= 8 bytes)
   // 0009     DestinationAddr   dc.b     MAP_ADDR_6(Destination)         ; Address in Paging Window for destination
   // 000A     DestinationPage   dc.b     HIGH_6_13(Destination)          ; Page for destination
   // 000B     DelayValue        dc.b     22                              ; Delay value (4MHz=>N=22, 8MHz=>N=44)
   // 000C     SourceAddr        dc.b     Buffer                          ; Address in Zero Page buffer for source
   // 000D     ByteCount         dc.b     BufferSize                      ; # of byte to write <page & buffer size

   // Set up data to write
   flashCommand[0x0] = RS08_PAGENO(flashMemoryRegionPtr->getFLCRAddress());
   if (byteCount<=8) {
      // Use tiny buffer
      unsigned int sub;
      for(sub=1; sub<=byteCount; sub++) {
         flashCommand[sub] = *data++;
      }
   }
   flashCommand[0x9] = RS08_WIN_ADDR(address);
   flashCommand[0xA] = RS08_PAGENO(address);
   flashCommand[0xB] = delayValue;
   flashCommand[0xC] = 1; // default to tiny buffer
   flashCommand[0xD] = byteCount;

   // If any of the following fail disable flash voltage
   do {
      // Transfer data to flash programming code
//      bdmInterface->writeMemory(1, 1, PTADAddress,  &allOnes);
//      bdmInterface->writeMemory(1, 1, PTCDAddress,  &allOnes);
      if (byteCount>8) {
         // Using large buffer
         rc = bdmInterface->writeMemory(1,
                                byteCount,
                                parameters.getRamStart()+sizeof(RS08_flashProgram),
                                data);
         if (rc != BDM_RC_OK)
            break;
         // Set buffer address
         flashCommand[0xC] = parameters.getRamStart()+sizeof(RS08_flashProgram);
      }
      // Write command data - triggers flash write
      rc = bdmInterface->writeMemory(1, sizeof(flashCommand), 0, flashCommand);
      if (rc != BDM_RC_OK)
         break;

      // Poll for completion - should be complete on 1st poll!
      int reTry = 2;
      do {
         if (byteCount>8) {
            milliSleep( 5 /* ms */);
         }
         rc = bdmInterface->readMemory(1, sizeof(flashStatus), 0xD, &flashStatus);
      } while ((rc == BDM_RC_OK) && (flashStatus != 0) && (reTry-->0) );

//      bdmInterface->writeMemory(1, 1, PTCDAddress,  &zero);

      if (rc != BDM_RC_OK)
         break;

      // Check status
      if (flashStatus != 0) {
         rc = BDM_RC_FAIL;
         break;
      }
   } while (FALSE);

   if (rc != BDM_RC_OK) {
      // Kill flash voltage on any error
      bdmInterface->setTargetVpp(BDM_TARGET_VPP_OFF);
#ifdef LOG
      {
         unsigned long temp;
         // re-sync and try to get some useful info from target
         bdmInterface->connect();
         bdmInterface->readMemory(1, sizeof(flashStatus), 0xD, &flashStatus);
         bdmInterface->readReg(RS08_RegA, &temp);
         bdmInterface->readMemory(1, sizeof(flashCommand), 0, flashCommand);
      }
#endif
      return PROGRAMMING_RC_ERROR_FAILED_FLASH_COMMAND;
   }
   return PROGRAMMING_RC_OK;
}

//=======================================================================
//! Programs a block of Target Flash memory
//! The data is subdivided based upon buffer size and Flash alignment
//!
//! @param flashImage Description of flash contents to be programmed.
//! @param blockSize             Size of block to program (bytes)
//! @param flashAddress          Start address of block to program
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
//! @note - Assumes flash programming code has already been loaded to target.
//!
USBDM_ErrorCode FlashProgrammer_RS08::programBlock(FlashImagePtr flashImage,
                                              unsigned int   blockSize,
                                              uint32_t       flashAddress) {
   LOGGING;
   unsigned int bufferSize;
   unsigned int bufferAddress;
   uint8_t delayValue;
   unsigned int splitBlockSize;
   uint8_t buffer[RS08_FLASH_PAGE_SIZE];
   USBDM_ErrorCode rc;

   log.print("FlashProgrammer_RS08::programBlock() [0x%06X..0x%06X]\n", flashAddress, flashAddress+blockSize-1);

   if (!flashReady) {
      log.print("FlashProgrammer_RS08::doFlashBlock() - Error, Flash not ready\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // OK for empty block
   if (blockSize==0) {
      return PROGRAMMING_RC_OK;
   }
   rc = calculateFlashDelay(&delayValue);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   //
   // Find flash region to program - this will recurse to handle sub regions
   //
   MemoryRegionConstPtr memoryRegionPtr;
   for (int index=0; ; index++) {
      memoryRegionPtr = parameters.getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
            log.print("FlashProgrammer_RS08::programBlock() - Block not within target memory\n");
            return PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
         }
      uint32_t lastContiguous;
      if (memoryRegionPtr->findLastContiguous(flashAddress, &lastContiguous)) {
         // Check if programmable
         if (!memoryRegionPtr->isProgrammableMemory()) {
               log.print("FlashProgrammer_RS08::programBlock() - Block not programmable memory\n");
               return PROGRAMMING_RC_ERROR_OUTSIDE_TARGET_FLASH;
         }
         // Check if block crosses boundary and will need to be split
         if ((flashAddress+blockSize-1) > lastContiguous) {
            log.print("FlashProgrammer_RS08::doFlashBlock() - Block crosses FLASH boundary - recursing\n");
            uint32_t firstBlockSize = lastContiguous - flashAddress + 1;
            USBDM_ErrorCode rc;
            rc = programBlock(flashImage, firstBlockSize, flashAddress);
            if (rc != PROGRAMMING_RC_OK) {
               return rc;
            }
            flashAddress += firstBlockSize;
            rc = programBlock(flashImage, blockSize-firstBlockSize, flashAddress);
            return rc;
         }
         break;
      }
   }
   MemType_t memoryType = memoryRegionPtr->getMemoryType();
   log.print("FlashProgrammer_RS08::doFlashBlock() - Processing %s\n", MemoryRegion::getMemoryTypeName(memoryType));
   // Initially assume buffer directly follows program in direct memory
   bufferAddress = parameters.getRamStart() + sizeof(RS08_flashProgram);

   // Calculate available space
   bufferSize = parameters.getRamEnd() - bufferAddress + 1;

   if (bufferSize <= 8) {
      // Use small buffer in Tiny RAM
      bufferSize    = 8;
      bufferAddress = 1;
   }
   // Limit buffer to a single flash page
   if (bufferSize>RS08_FLASH_PAGE_SIZE) {
      bufferSize = RS08_FLASH_PAGE_SIZE;
   }
   while (blockSize > 0) {
      // Data block must lie within a single Flash page
      splitBlockSize = RS08_FLASH_PAGE_SIZE - (flashAddress%RS08_FLASH_PAGE_SIZE); // max # of bytes remaining in this page

      // Has to fit in buffer
      if (splitBlockSize>bufferSize) {
         splitBlockSize = bufferSize;
      }
      // Can't write more than we have left
      if (splitBlockSize>blockSize) {
         splitBlockSize = blockSize;
      }
      // Copy flash data to buffer
      unsigned int sub;
      for(sub=0; sub<splitBlockSize; sub++) {
         buffer[sub] = flashImage->getValue(flashAddress+sub);
      }
      // Write block to flash
      rc = writeFlashBlock(splitBlockSize, flashAddress, buffer, delayValue);
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
      // Advance to next block of data
      flashAddress += splitBlockSize;
      blockSize    -= splitBlockSize;
      progressTimer->progress(splitBlockSize, NULL);
   };
   return PROGRAMMING_RC_OK;
}

//! \brief Does Blank Check of Target Flash.
//!
//! @return error code, see \ref USBDM_ErrorCode
//!
//! @note The target is not reset so current security state persists after erase.
//!
USBDM_ErrorCode FlashProgrammer_RS08::blankCheckTarget() {
   LOGGING;
   const unsigned bufferSize = 0x400;
   uint8_t buffer[bufferSize];
   log.print("FlashProgrammer_RS08::blankCheckMemory():Blank checking target memory...\n");

   int memoryRegionIndex;
   MemoryRegionConstPtr memoryRegionPtr;
   for (memoryRegionIndex = 0;
        (memoryRegionPtr = parameters.getMemoryRegion(memoryRegionIndex));
        memoryRegionIndex++) {
      MemType_t memoryType = memoryRegionPtr->getMemoryType();
      if ((memoryType == MemFLASH) || (memoryType == MemEEPROM)) {
         int memoryRangeIndex;
         const MemoryRegion::MemoryRange *memoryRange;
         for (memoryRangeIndex = 0;
              (memoryRange = memoryRegionPtr->getMemoryRange(memoryRangeIndex));
              memoryRangeIndex++) {
            uint32_t address = memoryRange->start;
            uint32_t memSize = 1 + memoryRange->end-memoryRange->start;
            while (memSize >0) {
               unsigned blockSize = memSize;
               if (blockSize>bufferSize)
                  blockSize = bufferSize;
               USBDM_ErrorCode rc = bdmInterface->readMemory(1, blockSize, address, buffer);
               if (rc != BDM_RC_OK) {
                  log.print("FlashProgrammer_RS08::blankCheckMemory():Memory is not blank!\n");
                  return PROGRAMMING_RC_ERROR_NOT_BLANK;
               }
               for (unsigned index=0; index<blockSize; index++) {
                  if (buffer[index] != 0xFF)
                     return PROGRAMMING_RC_ERROR_NOT_BLANK;
               }
               address += blockSize;
               memSize -= blockSize;
            }
         }
      }
   }
   return PROGRAMMING_RC_OK;
}
//=======================================================================
//! Check security state of target
//!
//! @return PROGRAMMING_RC_OK => device is unsecured           \n
//!         PROGRAMMING_RC_ERROR_SECURED => device is secured  \n
//!         else error code see \ref USBDM_ErrorCode
//!
//! @note Assumes the target device has already been opened & USBDM options set.
//!
USBDM_ErrorCode FlashProgrammer_RS08::checkTargetUnSecured() {
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

const int MaxSecurityAreaSize = 100;
struct SecurityDataCache {
   uint32_t address;                   //!< start address of security area
   uint32_t size;                      //!< size of area
   uint8_t  data[MaxSecurityAreaSize]; //!< security area data
};
unsigned securityAreaCount = 0;
SecurityDataCache securityData[2];

//===========================================================================================================
//! Clears the record of modified security areas
//!
void FlashProgrammer_RS08::deleteSecurityAreas(void) {
   securityAreaCount = 0;
}

//===========================================================================================================
//! Record the original contents of a security area for later restoration
//!
//! @param address    Start address of security area
//! @param size       Size of area
//! @param data       Security area data
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
USBDM_ErrorCode FlashProgrammer_RS08::recordSecurityArea(const uint32_t address, const int size, const uint8_t *data) {
   if (securityAreaCount >= sizeof(securityData)/sizeof(securityData[0])) {
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (size > MaxSecurityAreaSize) {
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
  securityData[securityAreaCount].address = address;
  securityData[securityAreaCount].size    = size;
  memcpy(securityData[securityAreaCount].data, data, size);
  securityAreaCount++;
  return PROGRAMMING_RC_OK;
}

//===========================================================================================================
//! Restores the contents of the security areas to their original values
//!
//! @param flashImage    Flash contents to be programmed.
//!
void FlashProgrammer_RS08::restoreSecurityAreas(FlashImagePtr flashImage) {
   LOGGING_Q;
   for (unsigned index=0; index<securityAreaCount; index++) {
      log.print("Restoring security area in image [0x%06X...0x%06X]\n",
            securityData[index].address, securityData[index].address+securityData[index].size-1);
      flashImage->loadDataBytes(securityData[index].size, securityData[index].address, securityData[index].data);
   }
}

//===========================================================================================================
//! Modifies the Security locations in the flash image according to required security options of flashRegion
//!
//! @param flashImage    Flash contents to be programmed.
//! @param flashRegion   The memory region involved (to determine security area if any)
//!
USBDM_ErrorCode FlashProgrammer_RS08::setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion) {
   LOGGING;
   uint32_t securityAddress = flashRegion->getSecurityAddress();

   if (securityAddress == 0) {
      log.print("No security area, not modifying flash image\n");
      return PROGRAMMING_RC_OK;
   }
   SecurityInfoConstPtr securityInfo;
   bool dontOverwrite =  false;
   switch (parameters.getSecurity()) {
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
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (securityInfo == NULL) {
      log.error("Error - No settings for security area!\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   int size = securityInfo->getSize();
   if (parameters.getSecurity() == SEC_DEFAULT) {
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
   uint8_t data[size];
   memcpy(data, securityInfo->getData(), size);
   if (dontOverwrite) {
      // Copy any existing data from memory array
      for(int index=0; index<size; index++) {
         if (flashImage->isValid(securityAddress+index)) {
            data[index] = flashImage->getValue(securityAddress+index);
         }
      }
   }
   uint8_t memory[size];
   bdmInterface->readMemory(MS_Byte, size, securityAddress, memory);
   // Save contents of current security area in Flash
   recordSecurityArea(securityAddress, size, memory);
   if (memcmp(data, memory, size) == 0) {
      if ((parameters.getEraseOption() == DeviceData::eraseMass) ||
          (parameters.getEraseOption() == DeviceData::eraseNone)) {
         // Clear security area in image to prevent re-programming
         log.print("Clearing security area as already valid and not being erased\n");
         for(int index=0; index<size; index++) {
            flashImage->remove(securityAddress+index);
         }
      }
      else {
         // eraseAll & eraseSelective will erase areas anyway so we have to re-program
         log.print("Security area is already valid but will be erased anyway (eraseAll or eraseSelective)\n");
         flashImage->loadDataBytes(size, securityAddress, data, dontOverwrite);
      }
   }
   else {
      log.print("Security area may need erasing\n");
      // Force erase of security area when mass erased (if necessary)
      securityNeedsSelectiveErase = true;
      flashImage->loadDataBytes(size, securityAddress, data, dontOverwrite);
#ifdef LOG
      log.print("Setting security region, \n"
            "              mem[0x%06lX-0x%06lX] = \n", (unsigned long)securityAddress, (unsigned long)(securityAddress+size/sizeof(uint8_t)-1));
      log.printDump(data, size, securityAddress);
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
USBDM_ErrorCode FlashProgrammer_RS08::setFlashSecurity(FlashImagePtr flashImage) {
   LOGGING;
   // Process each flash region
   USBDM_ErrorCode rc = BDM_RC_OK;
   securityNeedsSelectiveErase = false; // Assume security areas are valid
   deleteSecurityAreas();
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = parameters.getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      rc = setFlashSecurity(flashImage, memoryRegionPtr);
      if (rc != BDM_RC_OK) {
         break;
      }
   }
   return rc;
}

//=======================================================================
//! Checks if a block of Target Flash memory is blank [== 0xFF]
//!
//! @param flashImage  Used to determine memory model
//! @param blockSize              Size of block to check
//! @param flashAddress           Start address of block to program
//!
//! @return error code see \ref USBDM_ErrorCode.
//!
//! @note - Assumes flash programming code has already been loaded to target.
//!
USBDM_ErrorCode FlashProgrammer_RS08::blankCheckBlock(FlashImagePtr flashImage,
                                                 unsigned int  blockSize,
                                                 unsigned int  flashAddress){
   LOGGING;
   #define CHECKBUFFSIZE 0x8000
   uint8_t buffer[CHECKBUFFSIZE];
   unsigned int currentBlockSize;
   unsigned int index;

   log.print("FlashProgrammer_RS08::blankCheckBlock() - Blank checking block[0x%04X..0x%04X]\n", flashAddress,
                                                     flashAddress+blockSize-1);
   while (blockSize>0) {
      currentBlockSize = blockSize;
      if (currentBlockSize > CHECKBUFFSIZE)
         currentBlockSize = CHECKBUFFSIZE;
      if (bdmInterface->readMemory(1, currentBlockSize, flashAddress, buffer)!= BDM_RC_OK)
         return PROGRAMMING_RC_ERROR_BDM_READ;
      for (index=0; index<currentBlockSize; index++) {
         if (buffer[index] != 0xFF) {
            log.print("FlashProgrammer_RS08::blankCheckBlock() - Blank checking [0x%4.4X] => 0x%2.2X - failed\n",
                            flashAddress+index, buffer[index]);
            return PROGRAMMING_RC_ERROR_NOT_BLANK;
         }
      }
      flashAddress += currentBlockSize;
      blockSize    -= currentBlockSize;
   }
   return PROGRAMMING_RC_OK;
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
USBDM_ErrorCode FlashProgrammer_RS08::doReadbackVerify(FlashImagePtr flashImage) {
   LOGGING;
   const unsigned MAX_BUFFER=0x800;
   uint8_t buffer[MAX_BUFFER];
   int checkResult = TRUE;
   int blockResult;

   FlashImage::Enumerator *enumerator = flashImage->getEnumerator();
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

      while (regionSize>0) {
         // Get memory block containing address
         MemoryRegionConstPtr memRegion = parameters.getMemoryRegionFor(memoryAddress, memorySpace);
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
#endif
//               log.print("Verifying location[0x%8.8X]=>failed, image=%2.2X != target=%2.2X\n",
//                     imageAddress+testIndex,
//                     (uint8_t)(flashImage->getValue(imageAddress+testIndex]),
//                     buffer[testIndex]);
            }
         }
         log.print("Verifying Sub-block %s[0x%8.8X..0x%8.8X] => %s\n", getMemSpaceName(memorySpace), memoryAddress, memoryAddress+blockSize-1, blockResult?"OK":"FAIL");
         if (!blockResult) {
            log.printDump((const uint8_t *)buffer, blockSize*sizeof(uint8_t), memoryAddress);
         }
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
   if (enumerator != NULL) {
      delete enumerator;
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
USBDM_ErrorCode FlashProgrammer_RS08::doVerify(FlashImagePtr flashImage) {
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
USBDM_ErrorCode FlashProgrammer_RS08::verifyFlash(FlashImagePtr flashImage,
                                             CallBackT    progressCallBack) {
   LOGGING;
   USBDM_ErrorCode rc;
   if ((this == NULL) || (parameters.getTargetName().empty())) {
      log.print("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   log.print("===========================================================\n");
   log.print("\tprogressCallBack = %p\n",                 progressCallBack);
   log.print("\tDevice = \'%s\'\n",                       parameters.getTargetName().c_str());
   log.print("\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n",   parameters.getClockTrimFreq(),
                                                               parameters.getClockTrimNVAddress(),
                                                               parameters.getClockAddress());
   log.print("\tRam[%4.4X...%4.4X]\n",                    parameters.getRamStart(), parameters.getRamEnd());
   log.print("\tErase=%s\n",                              DeviceData::getEraseOptionName(parameters.getEraseOption()));
   log.print("\tSecurity=%s\n",                           getSecurityName(parameters.getSecurity()));
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
   if (parameters.getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Set up the target for Flash operations
   rc = resetAndConnectTarget();

   // Delay checking some errors until after security check
   if ((rc != BDM_RC_OK) &&
       (rc != PROGRAMMING_RC_ERROR_SECURED) &&      // Secured device
       (rc != BDM_RC_SECURED) &&                    // Secured device
       (rc != BDM_RC_BDM_EN_FAILED) &&              // BDM enable failed (on HCS devices)
       (rc != BDM_RC_RESET_TIMEOUT_RISE)            // Reset pulsing on Kinetis etc.
       ) {
      return rc;
   }
   USBDM_ErrorCode rcSecurity = checkTargetUnSecured();
   if (rcSecurity != PROGRAMMING_RC_OK) {
      return rcSecurity;
   }
   // Do deferred error check
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   // Modify flash image according to security options - to be consistent with what is programmed
   rc = setFlashSecurity(flashImage);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#if (TARGET == CFV1) || (TARGET == HCS08)
   // Modify flash image according to trim options - to be consistent with what is programmed
   rc = dummyTrimLocations(flashImage);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
//#if (TARGET == CFVx) || (TARGET == MC56F80xx)
//   rc = determineTargetSpeed();
//   if (rc != PROGRAMMING_RC_OK) {
//      return rc;
//   }
//#endif
   // Set up for Flash operations (clock etc)
   rc = initialiseTargetFlash();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   rc = doVerify(flashImage);

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
USBDM_ErrorCode FlashProgrammer_RS08::programFlash(FlashImagePtr flashImage,
                                              CallBackT    progressCallBack,
                                              bool         doRamWrites) {
   LOGGING;

   USBDM_ErrorCode rc;
   bool targetBlank = false;
   if ((this == NULL) || (parameters.getTargetName().empty())) {
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
         parameters.getTargetName().c_str(),
         parameters.getClockTrimFreq(),
         parameters.getClockTrimNVAddress(),
         parameters.getClockAddress(),
         parameters.getRamStart(),
         parameters.getRamEnd(),
         DeviceData::getEraseOptionName(parameters.getEraseOption()),
         getSecurityName(parameters.getSecurity()),
         flashImage->getByteCount(),
         doRamWrites?"T":"F");
#else
   log.print("===========================================================\n");
   log.print("\tprogressCallBack = %p\n",                 progressCallBack);
   log.print("\tDevice = \'%s\'\n",                       parameters.getTargetName().c_str());
   log.print("\tTrim, F=%ld, NVA@%4.4X, clock@%4.4X\n",   parameters.getClockTrimFreq(),
                                                               parameters.getClockTrimNVAddress(),
                                                               parameters.getClockAddress());
   log.print("\tRam[%4.4X...%4.4X]\n",                    parameters.getRamStart(), parameters.getRamEnd());
   log.print("\tErase=%s\n",                              DeviceData::getEraseOptionName(parameters.getEraseOption()));
   log.print("\tSecurity=%s\n",                           getSecurityName(parameters.getSecurity()));
   log.print("\tTotal bytes=%d\n",                        flashImage->getByteCount());
   log.print("\tdoRamWrites=%s\n",                        doRamWrites?"T":"F");
   log.print("===========================================================\n");
#endif

   this->doRamWrites = doRamWrites;
   progressTimer.reset(new ProgressTimer(progressCallBack, flashImage->getByteCount()));
   progressTimer->restart("Initialising...");

   flashReady = FALSE;
   currentFlashProgram.reset();

   rc = initTCL();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   if (parameters.getTargetName().empty()) {
      log.error("Error: device parameters not set\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   // Connect to target
   rc = resetAndConnectTarget();

   // Ignore some errors if mass erasing target as it is possible to mass
   // erase some targets without a complete debug connection
   if ((rc != BDM_RC_OK) &&
       ((parameters.getEraseOption() != DeviceData::eraseMass) ||
        ((rc != PROGRAMMING_RC_ERROR_SECURED) &&      // Secured device
         (rc != BDM_RC_SECURED) &&                    // Secured device
         (rc != BDM_RC_BDM_EN_FAILED) &&              // BDM enable failed (on HCS devices)
         (rc != BDM_RC_RESET_TIMEOUT_RISE)            // Reset pulsing on Kinetis etc.
         ))) {
      return rc;
   }
   bool secured = checkTargetUnSecured() != PROGRAMMING_RC_OK;

   // Check target security
   if (secured && (parameters.getEraseOption() != DeviceData::eraseMass)) {
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
   if (parameters.getEraseOption() == DeviceData::eraseMass) {
      rc = massEraseTarget();
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
#if !defined(LOG)
      // Suppress blank check unless logging
      targetBlank = true;
#endif
   }
#if (TARGET == CFV1) || (TARGET == ARM) || (TARGET == CFVx) || (TARGET == MC56F80xx) || (TARGET == S12Z)
   // Check target SDID
   rc = confirmSDID();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
   // Modify flash image according to security options
   rc = setFlashSecurity(flashImage);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#if (TARGET == CFVx) || (TARGET == MC56F80xx)// || (TARGET == ARM)
   rc = determineTargetSpeed();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
#if (TARGET == RS08) || (TARGET == CFV1) || (TARGET == HCS08) || (TARGET == ARM)
   // Calculate clock trim values & update memory image
   // log.print("setFlashTrimValues() - trimming\n");
   progressTimer->restart("Calculating Clock Trim");

   rc = setFlashTrimValues(flashImage);
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
   // Set up for Flash operations (clock etc)
   rc = initialiseTargetFlash();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   //
   // The above leaves the Flash ready for programming
   //
#if (TARGET==ARM) || (TARGET == CFV1) || (TARGET == S12Z) || (TARGET == MC56F80xx)
   if (parameters.getEraseOption() == DeviceData::eraseMass) {
      // Erase the security area as Mass erase programs it to a non-blank value
      rc = selectiveEraseFlashSecurity();
      if (rc != PROGRAMMING_RC_OK) {
         return rc;
      }
   }
   // Program EEPROM/DFLASH Split
   rc = partitionFlexNVM();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
#endif
   // Load default flash programming code to target
   rc = loadAndStartExecutingTargetProgram();
   if (rc != PROGRAMMING_RC_OK) {
      return rc;
   }
   log.print("Erase Time = %3.2f s\n", progressTimer->elapsedTime());

   // Program flash
   FlashImage::Enumerator *enumerator = flashImage->getEnumerator();

   progressTimer->restart("Programming...");
   log.print("Total Bytes = %d\n", flashImage->getByteCount());
   while(enumerator->isValid()) {
      // Start address of block to program to flash
      uint32_t startBlock = enumerator->getAddress();

      // Find end of block to program
      enumerator->lastValid();
      uint32_t blockSize = enumerator->getAddress() - startBlock + 1;

      //log.print("Block size = %4.4X (%d)\n", blockSize, blockSize);
      if (blockSize>0) {
         // Program block [startBlock..endBlock]
         if (!targetBlank) {
            // Need to check if range is currently blank
            // It is not permitted to re-program flash
            rc = blankCheckBlock(flashImage, blockSize, startBlock);
            if (rc != PROGRAMMING_RC_OK) {
               bdmInterface->setTargetVpp(BDM_TARGET_VPP_OFF);
               return rc;
            }
         }
         rc = programBlock(flashImage, blockSize, startBlock);
         if (rc != PROGRAMMING_RC_OK) {
            bdmInterface->setTargetVpp(BDM_TARGET_VPP_OFF);
            log.print("FlashProgrammer_RS08::programFlash() - programming failed, Reason= %s\n", bdmInterface->getErrorString(rc));
            break;
         }
      }
      // Advance to start of next occupied region
      enumerator->nextValid();
   }
   bdmInterface->setTargetVpp(BDM_TARGET_VPP_OFF);

   delete enumerator;
   enumerator = NULL;

   if (rc != PROGRAMMING_RC_OK) {
      log.print("Erasing failed, Reason= %s\n", bdmInterface->getErrorString(rc));
      return rc;
   }
#if (TARGET == RS08) || (TARGET == HCS08) || (TARGET == CFV1)
   if (parameters.getClockTrimFreq() != 0) {
      uint16_t trimValue = parameters.getClockTrimValue();
#ifdef GDI
      mtwksDisplayLine("FlashProgrammer_RS08::programFlash() - Device Trim Value = %2.2X.%1X\n", trimValue>>1, trimValue&0x01);
#endif
      log.print("Device Trim Value = %2.2X.%1X\n", trimValue>>1, trimValue&0x01);
   }
#endif

#ifdef GDI
   mtwksDisplayLine("Programming Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
         progressTimer->elapsedTime(), flashImage->getByteCount()/(1024*progressTimer->elapsedTime()),  rc);
#endif

   log.print("Programming Time = %3.2f s, Speed = %2.2f kBytes/s, rc = %d\n",
         progressTimer->elapsedTime(), flashImage->getByteCount()/(1024*progressTimer->elapsedTime()),  rc);

   rc = doVerify(flashImage);

#ifdef GDI
   mtwksDisplayLine("FlashProgrammer_RS08::programFlash() - Verifying Time = %3.2f s, rc = %d\n", progressTimer->elapsedTime(), rc);
#endif

   log.print("Verifying Time = %3.2f s, rc = %d\n", progressTimer->elapsedTime(), rc);
   return rc;
}

//=======================================================================
//! Set device data for flash operations
//!
//! @param theParameters   -   data describing the device
//!
//! @return error code see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode FlashProgrammer_RS08::setDeviceData(const DeviceData &theParameters) {
   LOGGING_Q;
   currentFlashProgram.reset();
   parameters = theParameters;
   log.print("Target=%s\n", parameters.getTargetName().c_str());
   releaseTCL();
   initTCL();
   // Find the flash region to obtain flash parameters
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr;
      memoryRegionPtr = parameters.getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
            break;
         }
      if (memoryRegionPtr->isProgrammableMemory()) {
         flashMemoryRegionPtr = memoryRegionPtr;
         break;
      }
   }
   if (flashMemoryRegionPtr == NULL) {
      log.print("FlashProgrammer_RS08::setDeviceData() - No flash memory found\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   return PROGRAMMING_RC_OK;
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<FlashProgrammer_RS08>(pp);
}
