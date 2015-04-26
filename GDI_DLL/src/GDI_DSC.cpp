/*! \file
   \brief Entry points for USBDM library

   USBDM_GDI.cpp

   \verbatim
   USBDM GDI interface DLL
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
Change History
-============================================================================================
|  Dec 21 2012 | Fixed Reset PC Hack in HCS08 & CFV1                               - pgo V4.10.4
|  Dec 21 2012 | Removed Mass Erase as separate operation                          - pgo V4.10.4
|  Nov 30 2012 | Changed logging                                                   - pgo V4.10.4
|  Oct  8 2012 | Modified ARM accesses to use maximum aligned sizes                - pgo V4.10.2
|  May  7 2012 | Changed to using RESET_DEFAULT for ARM in DiExecResetChild()      - pgo V4.9.5
|  Mar 30 2012 | Fixed block address error in DIMemoryWrite() when flashing        - pgo V4.9.4
|  Mar 30 2012 | Changed to USBDM_SetExtendedOptions() etc.                        - pgo V4.9.4
|  Mar 24 2012 | Added actions to PROCESS_DETACH (for DSC programmer)              - pgo V4.9.4
|  Jan 14 2012 | Ported to DSC                                                     - pgo V4.9
|  Jul 16 2011 | Extended TargetConnect strategies & Messages HCSxx                - pgo V4.7
|  Jul  3 2011 | Changes to DSC code in DLL                                        - pgo V4.7
|  Jul  3 2011 | Changes related to CFVx recovery from sleeping                    - pgo V4.7
|  Jul  2 2011 | Added halt/connect in DiExecResetChild() - HCS08                  - pgo V4.7
|  Jun 30 2011 | Added checks for WAIT/WFE states                                  - pgo V4.7
|  Jun 30 2011 | Re-arranged connection code to avoid spurious secured error       - pgo V4.7
|  Jun    2011 | Added autoconnect on DiGdiGetStatus                               - pgo
+============================================================================================
\endverbatim
*/

#include <string.h>

#include "Common.h"
#include "UsbdmSystem.h"
#include "Version.h"
#include "USBDM_API.h"
#include "GDI_Common.h"
#include "Metrowerks.h"
#include "MetrowerksInterface.h"
#include "U32c.h"
#include "TargetDefines.h"
#include "Names.h"

#if (TARGET != CFVx) && !defined(LEGACY)
// Flash programming is not supported on above targets
#define FLASH_PROGRAMMING 1
#endif

#ifdef FLASH_PROGRAMMING
//#include "FlashProgramming.h"
#endif
#include "USBDM_DSC_API.h"
//#include "DSC_Utilities.h"

#if (TARGET != MC56F80xx)
#error "Build for wrong target"
#endif

const TargetType_t targetType = T_MC56F80xx;

const DiFeaturesT diFeatures = {
  /* .szIdentification                 = */ (DiStringT)"USBDM DSC",
  /* .szVersion                        = */ (DiStringT)"1.2.6",
  /* .dnVersion                        = */ (1<<16)+(2<<8)+6,
  /* .pszConfig                        = */ NULL,
  /* .dnConfigArrayItems               = */ 0,
  /* .dccIOChannel                     = */ DI_COMM_NONE,
  /* .fMemorySetMapAvailable           = */ FALSE,
  /* .fMemorySetCpuMapAvailable        = */ FALSE,
  /* .pszMemoryType                    = */ NULL,
  /* .dnMemTypeArrayItems              = */ 0,
  /* .fEnableReadaheadCache            = */ FALSE,
  /* .fTimerInCycles                   = */ FALSE,
  /* .dnTimerResolutionMantissa        = */ 128,
  /* .dnTimerResolutionExponent        = */ 0,
  /* .ddfDownloadFormat = */    {
                  /* .dafAbsFileFormat = */ DI_ABSF_BINARY,
                  /* .dnBufferSize     = */ 1000,
                  /* .daAddress        = */ {0},
                 },
  /* .ddfAuxDownloadFormat = */ {
                  /* .dafAbsFileFormat = */ DI_ABSF_NONE,
                  /* .dnBufferSize     = */ 0,
                  /* .daAddress        = */ {0,{{{0}}}},
                 },
  /* .fAuxiliaryDownloadPathAvailable  = */ FALSE,
  /* .dcCallback                       = */ DI_CB_MTWKS_EXTENSION|DI_CB_DEBUG|DI_CB_LOG,
  /* .fRegisterClassSupport            = */ FALSE,
  /* .fSingleStepSupport               = */ TRUE,
  /* .fContinueUntilSupport            = */ FALSE,
  /* .fContinueBackgroundSupport       = */ FALSE,
  /* .dnNrCodeBpAvailable              = */ 0, // Code breakpoints
  /* .dnNrDataBpAvailable              = */ 0, // Data read/write breakpoints
  /* .fExecFromCodeBp                  = */ FALSE,
  /* .fExecFromDataBp                  = */ FALSE,
  /* .fUnifiedBpLogic                  = */ TRUE,
  /* .fExecCycleCounterAvailable       = */ FALSE,
  /* .fExecTimeAvailable               = */ FALSE,
  /* .fInstrTraceAvailable             = */ FALSE,
  /* .fRawTraceAvailable               = */ FALSE,
  /* .fCoverageAvailable               = */ FALSE,
  /* .fProfilingAvailable              = */ FALSE,
  /* .fStateSaveRestoreAvailable       = */ FALSE,
  /* .dnStateStoreMaxIndex             = */ 0,
  /* .pdbgBackground                   = */ NULL,
  /* .dnBackgroundArrayItems           = */ 0,
  /* .fDirectDiAccessAvailable         = */ FALSE,  // Direct commands not available
  /* .fApplicationIOAvailable          = */ FALSE,
  /* .fKernelAware                     = */ FALSE,
#ifdef USE_MEE
  /* .fMeeAvailable                    = */ TRUE,
#else
  /* .fMeeAvailable                    = */ FALSE,
#endif
  /* .dnNrCpusAvailable                = */ 1,
  /* .deWordEndianness                 = */ DI_BIG_ENDIAN,
  /* .dnNrHardWareCodeBpAvailable      = */ 0, // No hardware code breakpoints!
  /* .fCodeHardWareBpSkids             = */ FALSE,
  /* .pReserved                        = */ NULL,
};

#ifndef LEGACY
int regMap[] = {
/* 00 */ DSC_RegA2 ,
/* 01 */ DSC_RegB2 ,
/* 02 */ DSC_RegC2 ,
/* 03 */ DSC_RegD2,
/* 04 */ DSC_RegA0 ,
/* 05 */ DSC_RegA1 ,
/* 06 */ DSC_RegB0 ,
/* 07 */ DSC_RegB1 ,
/* 08 */ DSC_RegC0 ,
/* 09 */ DSC_RegC1 ,
/* 0A */ DSC_RegD0 ,
/* 0B */ DSC_RegD1 ,
/* 0C */ DSC_RegY0 ,
/* 0D */ DSC_RegY1 ,
/* 0E */ -1 ,
/* 0F */ DSC_RegN3 ,
/* 10 */ DSC_RegM01 ,
/* 11 */ DSC_RegOMR ,
/* 12 */ DSC_RegSR ,
/* 13 */ DSC_RegLC ,
/* 14 */ DSC_RegLC2 ,
/* 15 */ DSC_RegPC,
/* 16 */ -1 ,
/* 17 */ DSC_RegR0 ,
/* 18 */ DSC_RegR1 ,
/* 19 */ DSC_RegR2 ,
/* 1A */ DSC_RegR3 ,
/* 1B */ DSC_RegR4 ,
/* 1C */ DSC_RegR5 ,
/* 1D */ DSC_RegN ,
/* 1E */ DSC_RegSP   ,
/* 1F */ DSC_RegLA ,
/* 20 */ DSC_RegLA2 ,
/* 21 */ DSC_RegHWS0 ,
/* 22 */ DSC_RegHWS1 ,
/* 23 */ -1 ,
/* 24 */ -1 ,
/* 25 */ -1 ,
/* 26 */ -1 ,
/* 27 */ -1 ,
/* 28 */ -1 ,
/* 29 */ DSC_RegOCR  ,
/* 2A */ -1 ,
/* 2B */ DSC_RegOSR ,
/* 2C */ -1 ,
/* 2D */ -1 ,
/* 2E */ DSC_RegOTBPR   ,
/* 2F */ -1 ,
/* 30 */ DSC_RegOB0CR ,
/* 31 */ DSC_RegOB0AR1 ,
/* 32 */ DSC_RegOB0AR2 ,
/* 33 */ DSC_RegOB0MSK   ,
/* 34 */ DSC_RegOB0CNTR  ,
/* 35 */ -1 ,
/* 36 */ -1 ,
/* 37 */ -1 ,
/* 38 */ -1 ,
/* 39 */ -1 ,
/* 3A */ -1 ,
/* 3B */ -1 ,
/* 3C */ -1 ,
/* 3D */ -1 ,
/* 3E */ -1 ,
/* 3F */ -1 ,
/* 40 */ -1 ,
/* 41 */ -1 ,
/* 42 */ -1 ,
/* 43 */ -1 ,
/* 44 */ -1 ,
/* 45 */ -1 ,
/* 46 */ -1 ,
/* 47 */ -1 ,
/* 48 */ -1 ,
/* 49 */ -1 ,
/* 4A */ -1 ,
/* 4B */ -1 ,
/* 4C */ -1 ,
/* 4D */ -1 ,
};

DSC_Registers_t mapReg(unsigned cwRegNo) {
   int mappedRegNo = -1;
   if (cwRegNo < sizeof(regMap)/sizeof(regMap[0]))
      mappedRegNo = regMap[cwRegNo];
   if (mappedRegNo<0) {
      UsbdmSystem::Log::print("mapReg(0x%X) - Unknown reg\n", cwRegNo);
      return DSC_UnknownReg;
   }
   return (DSC_Registers_t)mappedRegNo;
}
#else
DSC_Registers_t mapReg(unsigned cwRegNo) {
   return (DSC_Registers_t)cwRegNo;
}
#endif

//! 2.2.6.1 Write Value to Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterWrite ( DiUInt32T        dnRegNumber,
                            DiRegisterValueT drvValue ) {
   LOGGING_Q;
   U32c            regValue(drvValue);
   DSC_Registers_t regNum = mapReg(dnRegNumber);
   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("(0x%lX,%s) => %lX\n", (unsigned long)dnRegNumber, getDSCRegName(regNum), (unsigned long)regValue);

   CHECK_ERROR_STATE();

   if ((regNum == DSC_RegPC) && !pcWritten) {
      pcWritten    = true;
      pcResetValue = regValue;
   }
   if (regNum == DSC_UnknownReg) {
//      rc = BDM_RC_OK;
      rc = BDM_RC_ILLEGAL_PARAMS;
   }
   else {
      rc = bdmInterface->writeReg(regNum, (uint32_t)regValue);
   }
   if (rc != BDM_RC_OK) {
      log.error("0x%X,%s Failed, reason= %s\n",
            dnRegNumber, getDSCRegName(regNum), USBDM_GetErrorString(rc));
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   return setErrorState(DI_OK);
}

//! 2.2.6.2 Read Value from Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterRead ( DiUInt32T         dnRegNumber,
                           pDiRegisterValueT drvValue ) {
   LOGGING;
   unsigned long     dataValue = 0xDEADBEEF;
   DSC_Registers_t regNum = mapReg(dnRegNumber);
   USBDM_ErrorCode   rc        = BDM_RC_OK;
   log.print("0x%X(%d)\n", dnRegNumber, dnRegNumber);
//   log.print("DiRegisterRead(%s)\n", DSC_GetRegisterName(regNum));

   CHECK_ERROR_STATE();

   if (regNum == DSC_UnknownReg) {
      dataValue = dnRegNumber;
//      rc = BDM_RC_OK;
      rc = BDM_RC_ILLEGAL_PARAMS;
   }
   else {
      rc = bdmInterface->readReg(regNum, &dataValue);
   }
   if (rc != BDM_RC_OK) {
      log.print("DiRegisterRead(0x%X,%s) Failed, reason= %s\n",
            dnRegNumber, getDSCRegName(regNum), USBDM_GetErrorString(rc));
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   *drvValue = (U32c)dataValue;
   log.print("(0x%X,%s) => %8lX\n", dnRegNumber, getDSCRegName(regNum), dataValue);
   return setErrorState(DI_OK);
}

//!  2.2.7.1 Set Breakpoint
//!
//! @param pdnBreakpointId
//! @param dbBreakpoint
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointSet ( DiBpResultT *pdnBreakpointId,
                             DiBpT        dbBreakpoint ) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.7.2 Clear a Breakpoint
//!
//! @param dnBreakpointId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClear ( DiUInt32T dnBreakpointId ) {

   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.7.3 Clear All Breakpoints
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClearAll ( void ) {

   LOGGING_Q;
   log.print("- not implemented\n");
   return setErrorState(DI_ERR_NOTSUPPORTED);
}

//!  2.2.8.2 Execute a Single Step
//!
//! @param dnNrInstructions
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecSingleStep ( DiUInt32T dnNrInstructions ) {
   LOGGING_Q;

   USBDM_ErrorCode BDMrc;
   log.print("(%d)\n", dnNrInstructions);

   CHECK_ERROR_STATE();

   if (dnNrInstructions>1) {
      log.print("() - Only a single step is supported!\n");
      return setErrorState(DI_ERR_PARAM, ("Only a single step is allowed"));
   }
   BDMrc = USBDM_TargetStep();
   if (BDMrc != BDM_RC_OK) {
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   return setErrorState(DI_OK);
}

//!  2.2.8.6 Get DI Execution/Exit Status
//!
//! @param pdesExitStatus
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecGetStatus ( pDiExitStatusT pdesExitStatus ) {
   LOGGING;

   USBDM_ErrorCode      BDMrc;
   static DiExitCauseT  lastStatus     = DI_WAIT_USER;
   static int pollCount = 0;

   // Defaults
   pdesExitStatus->dscCause = DI_WAIT_UNKNOWN;
   pdesExitStatus->dwBpId   = 0x1000400; // bkpt ID?
   pdesExitStatus->szReason = (DiStringT)"unknown state";

// Removed as prevents CW retry strategy
//   CHECK_ERROR_STATE();

   // Update status or autoconnect (includes status update)
//   if (bdmOptions.autoReconnect)
//      DIrc = targetConnect();
//   else
//      DIrc = getBDMStatus(&USBDMStatus);

//   if (DIrc != DI_OK) {
//      log.print("DiExecGetStatus()=> connect()/getStatus() failed\n");
//      return DIrc;
//   }

//   pdesExitStatus->szReason = (DiStringT)getBDMStatusName(&USBDMStatus);

   unsigned int status;
   BDMrc = bdmInterface->getStatus(&status);
   if (BDMrc != BDM_RC_OK) {
      log.print("DiExecGetStatus() - Failed, BDMrc=%s\n", USBDM_GetErrorString(BDMrc));
      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   OnceStatus_t onceStatus = (OnceStatus_t)status;
   switch (onceStatus) {
   case stopMode:
   case debugMode:
   case unknownMode:
   default:
      // Halted - in debug halted mode
      pdesExitStatus->dscCause = DI_WAIT_UNKNOWN; // for DSC
      pdesExitStatus->szReason = (DiStringT)"Debug Halted";
      if ((lastStatus != pdesExitStatus->dscCause) || (pollCount++>20)) {
         pollCount = 0;
//         log.print("DiExecGetStatus() - %s\n", getOnceStatusName(onceStatus));
         log.print("DiExecGetStatus() status change => DI_WAIT_MISCELLANEOUS, (%s)\n",
               pdesExitStatus->szReason);
      }
      break;
   case executeMode :
   case externalAccessMode:
      // Processor executing
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Running";
      if ((lastStatus != pdesExitStatus->dscCause) || (pollCount++>20)) {
         pollCount = 0;
//         log.print("DiExecGetStatus() - %s\n", getOnceStatusName(onceStatus));
         log.print("DiExecGetStatus() status change => DI_WAIT_RUNNING, (%s)\n",
               pdesExitStatus->szReason);
      }
      break;
   }
   log.print("Reason = %s\n", pdesExitStatus->szReason);
   lastStatus = pdesExitStatus->dscCause;
   return setErrorState(DI_OK);
}

