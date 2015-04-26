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


#if (TARGET != HCS12)
#error "Build for wrong target"
#endif

const TargetType_t targetType = T_HCS12;

const DiFeaturesT diFeatures = {
  /* .szIdentification                 = */ (DiStringT)"USBDM HCS12",
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
  /* .dnNrCodeBpAvailable              = */ 1, // Code breakpoints
  /* .dnNrDataBpAvailable              = */ 1, // Data read/write breakpoints
  /* .fExecFromCodeBp                  = */ TRUE,
  /* .fExecFromDataBp                  = */ TRUE,
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

#if TARGET == ARM
// ARM Register numbers used by Codewarrior
//
#define arm_RegPRIMASK 19
#define arm_RegFAULTMASK  20
#define arm_RegBASEPRI 21
#define arm_RegCONTROL 22
#endif

//! 2.2.6.1 Write Value to Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterWrite ( DiUInt32T        dnRegNumber,
                            DiRegisterValueT drvValue ) {
   LOGGING;
   U32c  value(drvValue);
   USBDM_ErrorCode rc = BDM_RC_OK;
   unsigned long hxValue= 0;

   log.print("DiRegisterWrite(0x%X(%d) <= 0x%08X)\n", dnRegNumber, dnRegNumber, (uint32_t)value);

   CHECK_ERROR_STATE();

   // H & X are a special cases that require a read of HX before write
   if ((dnRegNumber == 3)||(dnRegNumber == 4)) { // X or H
      rc = USBDM_ReadReg(HCS08_RegHX, &hxValue);
      if (rc != BDM_RC_OK) {
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
      if (dnRegNumber == 4) { // H
         value = (hxValue&0x00FFU)+((value<<8)&0xFF00U);
      }
      else { // X
         value = (hxValue&0xFF00U)+(value&0x00FFU);
      }
   }
   switch (dnRegNumber) {
      case 0   : /*  PC */
         if (!pcWritten) {
            log.print("Saving initial PC write = 0x%08X)\n", (uint32_t)value);
            pcWritten    = true;
            pcResetValue = value;
         }
         rc = USBDM_WriteReg(HCS08_RegPC,  value);
         break;
      case 1   : /*  SP */ rc = USBDM_WriteReg(HCS08_RegSP,  value); break;
      case 2   : /*   A */ rc = USBDM_WriteReg(HCS08_RegA,   value); break;
      case 3   : /*   X */ rc = USBDM_WriteReg(HCS08_RegHX,  value); break;
      case 4   : /*   H */ rc = USBDM_WriteReg(HCS08_RegHX,  value); break;
      case 5   : /* CCR */ rc = USBDM_WriteReg(HCS08_RegCCR, value); break;
      default  : /*   ? */ return setErrorState(DI_ERR_PARAM, ("Illegal register identifier"));
   }
   if (rc != BDM_RC_OK) {
      log.error("0x%X Failed, reason= %s\n",
           dnRegNumber, USBDM_GetErrorString(rc));
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
   unsigned long dataValue = 0xDEADBEEF;
   USBDM_ErrorCode rc = BDM_RC_OK;
   LOGGING;
   log.print("0x%X(%d)\n", dnRegNumber, dnRegNumber);

   if (forceMassErase) {
      // HCS08 doesn't allow register reads of secured device
      // Dummy register reads until device is unsecured
      *drvValue = (U32c)dataValue;
      return setErrorState(DI_OK);
   }
   CHECK_ERROR_STATE();

   switch (dnRegNumber) {
      case 0   : /*  PC */ rc = USBDM_ReadReg(HCS08_RegPC,  &dataValue); break;
      case 1   : /*  SP */ rc = USBDM_ReadReg(HCS08_RegSP,  &dataValue); break;
      case 2   : /*   A */ rc = USBDM_ReadReg(HCS08_RegA,   &dataValue); break;
      case 3   : /*   X */ rc = USBDM_ReadReg(HCS08_RegHX,  &dataValue);
                           dataValue  &= 0xFF; // X
                           break;
      case 4   : /*   H */ rc = USBDM_ReadReg(HCS08_RegHX,  &dataValue);
                           dataValue  = (dataValue>>8) & 0xFF; // H
                           break;
      case 5   : /* CCR */ rc = USBDM_ReadReg(HCS08_RegCCR, &dataValue); break;
      default  : /*   ? */ return setErrorState(DI_ERR_PARAM, ("Illegal register identifier"));
   }
   if (rc != BDM_RC_OK) {
      log.print("DiRegisterRead(0x%X) => error\n", dnRegNumber);
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   *drvValue = (U32c)dataValue;
   log.print("0x%lX(%ld) => 0x%08lX\n", (unsigned long)dnRegNumber, (unsigned long)dnRegNumber, (unsigned long)dataValue);
   return setErrorState(DI_OK);
}

static uint32_t  currentBreakPointAddress;
static DiUInt32T breakpointId = 0; // 0 => no breakpoint set

//!  2.2.7.1 Set Breakpoint
//!
//! @param pdnBreakpointId
//! @param dbBreakpoint
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointSet ( DiBpResultT *pdnBreakpointId,
                             DiBpT        dbBreakpoint ) {
   LOGGING_E;
   unsigned long bdmscrValue;
   U32c bkptAddress;
   unsigned long breakpointModifier = HC08_BDCSCR_FTS;

   CHECK_ERROR_STATE();

   if (dbBreakpoint.dbtBpType & DI_BPT_EXECUTE) {
      // Execute breakpoint
      bkptAddress        = dbBreakpoint.u.exe.daBp;
      breakpointModifier = 0;
   }
   else if (dbBreakpoint.dbtBpType & (DI_BPT_READ|DI_BPT_WRITE|DI_BPT_VALUE)) {
      // Data read/write bkpt
      bkptAddress = dbBreakpoint.u.rwv.daBp;
   }
   else
      return setErrorState(DI_ERR_PARAM, ("Illegal breakpoint type"));

   // Can only support 1 breakpoint
   if (breakpointId != 0) {
      log.print("DiBreakpointSet(0x%4X) - Too many breakpoints\n", (uint32_t)bkptAddress);
      return setErrorState(DI_ERR_PARAM, ("Too many breakpoints"));
   }

   breakpointId = 1;

   USBDM_WriteDReg(HCS08_DRegBKPT, (uint32_t)bkptAddress);
   currentBreakPointAddress = bkptAddress;
   USBDM_ReadStatusReg(&bdmscrValue);
   USBDM_WriteControlReg(bdmscrValue|HC08_BDCSCR_BKPTEN|breakpointModifier);
   log.print("DiBreakpointSet(0x%4X, #%d:%s)\n",
         (uint32_t)bkptAddress, breakpointId, breakpointModifier?"E/D":"E");
   pdnBreakpointId->dbBp   = dbBreakpoint;
   pdnBreakpointId->dnBpId = breakpointId;
   return setErrorState(DI_OK);
}

//!  2.2.7.2 Clear a Breakpoint
//!
//! @param dnBreakpointId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClear ( DiUInt32T dnBreakpointId ) {
   LOGGING_E;

unsigned long bdmscrValue;

   CHECK_ERROR_STATE();

   if (dnBreakpointId != breakpointId)
      return setErrorState(DI_ERR_PARAM, ("Clearing non-existent breakpoint"));

   breakpointId = 0;

   USBDM_ReadStatusReg(&bdmscrValue);
   USBDM_WriteControlReg(bdmscrValue&~(HC08_BDCSCR_BKPTEN|HC08_BDCSCR_FTS));

   return setErrorState(DI_OK);
}

//!  2.2.7.3 Clear All Breakpoints
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClearAll ( void ) {
   LOGGING_E;

   CHECK_ERROR_STATE();

   return DiBreakpointClear(breakpointId);
}

//!  2.2.8.2 Execute a Single Step
//!
//! @param dnNrInstructions
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecSingleStep ( DiUInt32T dnNrInstructions ) {
   LOGGING_Q;
   log.print("(%d)\n", dnNrInstructions);

   USBDM_ErrorCode BDMrc;
   long unsigned ccrValue;
   long unsigned pcValue;
   unsigned char currentOpcode;
   const int interruptMask = (1<<3);
   const int tapOpcode  = 0x84;
   const int tpaOpcode  = 0x85;
   const int seiOpcode  = 0x9B;
   const int cliOpcode  = 0x9A;
   const int waitOpcode = 0x8F;
   const int rtiOpcode  = 0x80;
   const int swiOpcode  = 0x83;
   const int stopOpcode = 0x8E;

   CHECK_ERROR_STATE();
#if (TARGET == MC56F80xx)
   BDMrc = DSC_TargetStepN(dnNrInstructions);
#else
   if (dnNrInstructions>1) {
      log.print("DiExecSingleStep() - Only a single step is supported!\n");
      return setErrorState(DI_ERR_PARAM, ("Only a single step is allowed"));
   }
/*
 * Cases to consider when masking interrupts during step
 *
 * +--------+-----------+---------+-----------------------------------------------------+
 * | Opcode | Initial I | Final I | Problem - action                                    |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | ---    |     1     |    X    | None - no action (interrupts already masked)        |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | CLI    |     0     |    ?    | It may be possible for an interrupt to occur,       |
 * | WAIT   |           |         | setting I-flag which is then incorrectly cleared.   |
 * | STOP   |           |         | (I don't think it applies to CLI but be safe.)      |
 * | SWI    |           |         | - don't 'fix' CCR                                   |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | RTI    |     0     |    1    | Contrived but possible situation. I flag            |
 * |        |           |         | incorrectly cleared - don't 'fix' CCR               |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | SEI    |     0     |    1    | The instruction may set I-flag which is then        |
 * | TAP    |     0     |    1    | incorrectly cleared - don't 'fix' CCR               |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | TPA    |     0     |    X    | The wrong value is transferred to A - fix A         |
 * +--------+-----------+---------+-----------------------------------------------------+
 * | ---    |     0     |    0    | CCR change - clear I-flag in new CCR                |
 * +--------+-----------+---------+-----------------------------------------------------+
 */
   if (bdmOptions.maskInterrupts) {
      log.print("DiExecSingleStep() - checking if interrupt masking needed\n");
      USBDM_ReadReg(HCS08_RegCCR, &ccrValue);
      if ((ccrValue&interruptMask) != 0) {
         // Interrupts already masked - just step
         BDMrc = USBDM_TargetStep();
      }
      else {
         // Mask interrupts
         log.print("DiExecSingleStep() - masking interrupts\n");
         USBDM_WriteReg(HCS08_RegCCR, ccrValue|interruptMask);
         // Get current instruction opcode
         USBDM_ReadReg(HCS08_RegPC, &pcValue);
         USBDM_ReadMemory(1,1,pcValue,&currentOpcode);
         // Do a step
         BDMrc = USBDM_TargetStep();
         switch(currentOpcode) {
            case cliOpcode  :
            case waitOpcode :
            case seiOpcode  :
            case tapOpcode  :
            case rtiOpcode  :
            case swiOpcode  : // Not ever stepped - treated as subroutine?
            case stopOpcode :
               log.print("DiExecSingleStep() - skipping CCR restore\n");
               // Don't 'fix' CCR as updated by instruction or int ack
               break;
            case tpaOpcode :
               // Fix A & CCR  (clear I flag)
               log.print("DiExecSingleStep() - fixing A & CCR reg\n");
               USBDM_WriteReg(HCS08_RegA, ccrValue&~interruptMask);
               USBDM_WriteReg(HCS08_RegCCR, ccrValue&~interruptMask);
               break;
            default :
               // Fix CCR (clear I flag)
               // Unmask interrupts
               log.print("DiExecSingleStep() - fixing CCR reg\n");
               USBDM_ReadReg(HCS08_RegCCR, &ccrValue);
               USBDM_WriteReg(HCS08_RegCCR, ccrValue&~interruptMask);
               break;
         }
      }
   }
   else
      BDMrc = USBDM_TargetStep();
#endif
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
   USBDM_ErrorCode BDMrc;
   static DiExitCauseT lastStatus = DI_WAIT_USER;

   // Defaults
   pdesExitStatus->dscCause = DI_WAIT_RUNNING; //DI_WAIT_UNKNOWN;
   pdesExitStatus->dwBpId   = 0x1000400; // bkpt ID?
   pdesExitStatus->szReason = (DiStringT)"unknown state";

   if (bdmOptions.autoReconnect) {
      USBDM_ErrorCode bdmRc = bdmInterface->targetConnectWithRetry(softConnectOptions);
      if (bdmRc != BDM_RC_OK) {
         log.print("=> DI_ERR_COMMUNICATION\n");
         return setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      }
   }
   USBDMStatus_t USBDMStatus;
   USBDM_GetBDMStatus(&USBDMStatus);
//   pdesExitStatus->szReason = (DiStringT)getBDMStatusName(&USBDMStatus);

   if (USBDMStatus.connection_state == SPEED_NO_INFO) {
      log.print("=> NO_INFO\n");
      return setErrorState(DI_OK);
//      log.print("DiExecGetStatus()=>DI_ERR_COMMUNICATION\n");
//      return setErrorState(DI_ERR_NONFATAL, "Connection with target lost");
   }
   if (USBDMStatus.reset_recent == RESET_DETECTED) {
      log.print("=> Target has been reset\n");
      mtwksDisplayLine("Target RESET detected\n");
   }
   unsigned long status;
   BDMrc = USBDM_ReadStatusReg(&status);
   if (BDMrc != BDM_RC_OK) {
      log.print("=> Status read failed\n");
      return setErrorState(DI_OK);
//      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   if ((status&HC08_BDCSCR_ENBDM) == 0) {
      log.print("=> ENBDM=0\n");
      return setErrorState(DI_OK);
//      log.print("DiExecGetStatus()=>DI_ERR_NONFATAL\n");
//      return setErrorState(DI_ERR_NONFATAL, "Connection with target lost");
   }
   if ((status&HC12_BDMSTS_BDMACT) != 0) {
      // Halted - in debug halted mode
      pdesExitStatus->dscCause = DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->szReason = (DiStringT)"Debug Halted";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_MISCELLANEOUS, (%s)\n", pdesExitStatus->szReason);
#if (TARGET==CFV1) && defined(CONVERT_RESETS_TO_EXCEPTIONS)
         // Read-write PC on halt
         // This causes Illegal Operand and Address Errors to be converted from
         // Resets to Exceptions.
         // Without this code the debugger is a bit misleading as it halts at the
         // start of the exception handler but then does the reset on resume!
         unsigned long PCValue;
         USBDM_ReadCReg(CFV1_CRegPC, &PCValue);
         USBDM_WriteCReg(CFV1_CRegPC, PCValue);
#endif
      }
   }
   else if ((status&HC08_BDCSCR_WS) != 0) {
      // Stopped - low power sleep, treated as running
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Target Stopped (Low power)...";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_RUNNING, (%s)\n", pdesExitStatus->szReason);
      }
   }
   else {
      // Processor executing
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Running";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_RUNNING, (%s)\n", pdesExitStatus->szReason);
      }
   }
   lastStatus = pdesExitStatus->dscCause;
   return setErrorState(DI_OK);
}
