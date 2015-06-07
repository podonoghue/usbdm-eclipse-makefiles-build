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

#include "osbdm_defs/osbdm_cfv1.h"

#if (TARGET != CFV1)
#error "Build for wrong target"
#endif

const TargetType_t targetType = T_CFV1;

const DiFeaturesT diFeatures = {
  /* .szIdentification                 = */ (DiStringT)"USBDM CFV1",
  /* .szVersion                        = */ (DiStringT)"1.2.6",
  /* .dnVersion                        = */ (1<<16)+(2<<8)+6,
  /* .pszConfig                        = */ NULL,
  /* .dnConfigArrayItems               = */ 0,
  /* .dccIOChannel                     = */ DI_COMM_NONE,
  /* .fMemorySetMapAvailable           = */ false,
  /* .fMemorySetCpuMapAvailable        = */ false,
  /* .pszMemoryType                    = */ NULL,
  /* .dnMemTypeArrayItems              = */ 0,
  /* .fEnableReadaheadCache            = */ false,
  /* .fTimerInCycles                   = */ false,
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
  /* .fAuxiliaryDownloadPathAvailable  = */ false,
  /* .dcCallback                       = */ DI_CB_MTWKS_EXTENSION|DI_CB_DEBUG|DI_CB_LOG,
  /* .fRegisterClassSupport            = */ false,
  /* .fSingleStepSupport               = */ true,
  /* .fContinueUntilSupport            = */ false,
  /* .fContinueBackgroundSupport       = */ false,
  /* .dnNrCodeBpAvailable              = */ 0, // Code breakpoints
  /* .dnNrDataBpAvailable              = */ 0, // Data read/write breakpoints
  /* .fExecFromCodeBp                  = */ false,
  /* .fExecFromDataBp                  = */ false,
  /* .fUnifiedBpLogic                  = */ true,
  /* .fExecCycleCounterAvailable       = */ false,
  /* .fExecTimeAvailable               = */ false,
  /* .fInstrTraceAvailable             = */ false,
  /* .fRawTraceAvailable               = */ false,
  /* .fCoverageAvailable               = */ false,
  /* .fProfilingAvailable              = */ false,
  /* .fStateSaveRestoreAvailable       = */ false,
  /* .dnStateStoreMaxIndex             = */ 0,
  /* .pdbgBackground                   = */ NULL,
  /* .dnBackgroundArrayItems           = */ 0,
  /* .fDirectDiAccessAvailable         = */ false,  // Direct commands not available
  /* .fApplicationIOAvailable          = */ false,
  /* .fKernelAware                     = */ false,
#ifdef USE_MEE
  /* .fMeeAvailable                    = */ true,
#else
  /* .fMeeAvailable                    = */ false,
#endif
  /* .dnNrCpusAvailable                = */ 1,
  /* .deWordEndianness                 = */ DI_BIG_ENDIAN,
  /* .dnNrHardWareCodeBpAvailable      = */ 1,
  /* .fCodeHardWareBpSkids             = */ false,
  /* .pReserved                        = */ NULL,
};

#if TARGET == ARM
// ARM Register numbers used by Codewarrior
//
#define arm_RegPRIMASK     19
#define arm_RegFAULTMASK   20
#define arm_RegBASEPRI     21
#define arm_RegCONTROL     22
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
   U32c            value(drvValue);
   USBDM_ErrorCode rc  = BDM_RC_OK;

   log.print("(0x%X(%d) <= 0x%08X)\n", dnRegNumber, dnRegNumber, (uint32_t)value);

   CHECK_ERROR_STATE();

   if (dnRegNumber>cfv1regID_FIRST_DEBUG_regID_BYTE) {
      switch (dnRegNumber) {
         case cfv1regID_xcsr_byte :
            rc = bdmInterface->writeControlReg(value);
            if (rc != BDM_RC_OK) {
               log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                     "XCSR.byte", dnRegNumber, bdmInterface->getErrorString(rc));
               return setErrorState(DI_ERR_NONFATAL, rc);
            }
            break;
         case cfv1regID_csr2_byte :
            rc = bdmInterface->writeDReg(CFV1_DRegCSR2byte,value);
            if (rc != BDM_RC_OK) {
               log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                     "CSR2.byte", dnRegNumber, bdmInterface->getErrorString(rc));
               return setErrorState(DI_ERR_NONFATAL, rc);
            }
            break;
         case cfv1regID_csr3_byte :
            rc = bdmInterface->writeDReg(CFV1_DRegCSR3byte,value);
            if (rc != BDM_RC_OK) {
               log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                     "CSR3.byte", dnRegNumber, bdmInterface->getErrorString(rc));
               return setErrorState(DI_ERR_NONFATAL, rc);
            }
            break;
         default                  :
            log.print("DiRegisterWrite(Illegal Reg# 0x%X(%d)\n", dnRegNumber, dnRegNumber);
            rc = BDM_RC_ILLEGAL_PARAMS;
            break;
      }
   }
   else if (dnRegNumber>cfv1regID_FIRST_DEBUG_REG) {
      int regNum = dnRegNumber-cfv1regID_FIRST_DEBUG_REG;
      rc = bdmInterface->writeDReg(regNum,value);
      if (rc != BDM_RC_OK) {
         log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
               getCFV1DebugRegName(regNum), dnRegNumber, bdmInterface->getErrorString(rc));
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
   }
   else if (dnRegNumber > cfv1regID_FIRST_CONTROL_REG) {
      int regNum = dnRegNumber-cfv1regID_FIRST_CONTROL_REG;
      rc = bdmInterface->writeCReg(regNum,value);
      if (rc != BDM_RC_OK) {
         log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
               getCFV1ControlRegName(regNum), dnRegNumber, bdmInterface->getErrorString(rc));
         return setErrorState(DI_ERR_NONFATAL, rc);
      }
   }
   else {
      switch (dnRegNumber) {
         case cfv1regID_pc : /*  PC */
            if (!pcWritten) {
               log.print("Saving initial PC write = 0x%08X)\n", (uint32_t)value);
               pcWritten    = true;
               pcResetValue = value;
            }
            rc = bdmInterface->writeCReg(CFV1_CRegPC,value);
            if (rc != BDM_RC_OK) {
               log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                     "PC", dnRegNumber, bdmInterface->getErrorString(rc));
               return setErrorState(DI_ERR_NONFATAL, rc);
            }
            break;
         case cfv1regID_sr :
            rc = bdmInterface->writeCReg(CFV1_CRegSR,value);
            if (rc != BDM_RC_OK) {
               log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                     "SR", dnRegNumber, bdmInterface->getErrorString(rc));
               return setErrorState(DI_ERR_NONFATAL, rc);
            }
            break;
         default : // D0-7, A0-7
            if (dnRegNumber>15) {
               log.print("DiRegisterWrite(Illegal Reg# 0x%X(%d)\n", dnRegNumber, dnRegNumber);
               rc = BDM_RC_ILLEGAL_PARAMS;
            }
            else {
               rc = bdmInterface->writeReg(dnRegNumber,value);
               if (rc != BDM_RC_OK) {
                  log.print("DiRegisterWrite(%s(0x%X)) Failed, reason= %s\n",
                        getCFV1RegName(dnRegNumber), dnRegNumber, bdmInterface->getErrorString(rc));
                  return setErrorState(DI_ERR_NONFATAL, rc);
               }
            }
            break;
      }
   }
   if (rc != BDM_RC_OK) {
      log.error("0x%X Failed, reason= %s\n",
           dnRegNumber, bdmInterface->getErrorString(rc));
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
   log.print("0x%X(%d)\n", dnRegNumber, dnRegNumber);

   unsigned long     dataValue = 0xDEADBEEF;
   USBDM_ErrorCode   rc        = BDM_RC_OK;
   log.print("0x%X(%d)\n", dnRegNumber, dnRegNumber);

   if (forceMassErase) {
      // Dummy register reads until device in unsecured
      *drvValue = (U32c)dataValue;
      return setErrorState(DI_OK);
   }
   CHECK_ERROR_STATE();

   if (dnRegNumber>cfv1regID_FIRST_DEBUG_regID_BYTE)
      switch (dnRegNumber) {
         case cfv1regID_xcsr_byte :
            rc = bdmInterface->readStatusReg(&dataValue);
            break;
         case cfv1regID_csr2_byte :
            rc = bdmInterface->readDReg(CFV1_DRegCSR2byte,&dataValue);
            break;
         case cfv1regID_csr3_byte :
            rc = bdmInterface->readDReg(CFV1_DRegCSR3byte,&dataValue);
            break;
         default                  :
            log.print("DiRegisterRead(Illegal Reg# 0x%X(%d)\n", dnRegNumber, dnRegNumber);
            rc = BDM_RC_ILLEGAL_PARAMS;
            break;
      }
   else if (dnRegNumber>cfv1regID_FIRST_DEBUG_REG)
      rc = bdmInterface->readDReg(dnRegNumber-cfv1regID_FIRST_DEBUG_REG,&dataValue);
   else if (dnRegNumber > cfv1regID_FIRST_CONTROL_REG)
      rc = bdmInterface->readCReg(dnRegNumber-cfv1regID_FIRST_CONTROL_REG,&dataValue);
   else {
      switch (dnRegNumber) {
         case cfv1regID_pc :
            rc = bdmInterface->readCReg(CFV1_CRegPC,&dataValue);
            break;
         case cfv1regID_sr :
            rc = bdmInterface->readCReg(CFV1_CRegSR,&dataValue);
            break;
         default : // D0-7, A0-7
            if (dnRegNumber>15) {
               log.print("DiRegisterRead(Illegal Reg# 0x%X(%d)\n", dnRegNumber, dnRegNumber);
               rc = BDM_RC_ILLEGAL_PARAMS;
            }
            else
               rc = bdmInterface->readReg(dnRegNumber,&dataValue);
            break;
      }
   }
   if (rc != BDM_RC_OK) {
      log.print("DiRegisterRead(0x%X) => error\n", dnRegNumber);
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   *drvValue = (U32c)dataValue;
   log.print("0x%lX(%ld) => 0x%08lX\n", (unsigned long)dnRegNumber, (unsigned long)dnRegNumber, (unsigned long)dataValue);
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
   BDMrc = bdmInterface->step();
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

   // Defaults
   pdesExitStatus->dscCause = DI_WAIT_UNKNOWN;
   pdesExitStatus->dwBpId   = 0; // bkpt ID?
   pdesExitStatus->szReason = (DiStringT)"unknown state";
   if (bdmInterface->getBdmOptions().autoReconnect) {
      USBDM_ErrorCode bdmRc = bdmInterface->targetConnectWithRetry(softConnectOptions);
      if (bdmRc != BDM_RC_OK) {
         log.print("=> DI_ERR_COMMUNICATION\n");
         return setErrorState(DI_ERR_COMMUNICATION, bdmRc);
      }
   }
   log.print("Calling bdmInterface->getBDMStatus()\n");
   USBDMStatus_t USBDMStatus;
   bdmInterface->getBDMStatus(&USBDMStatus);
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
   BDMrc = bdmInterface->readStatusReg(&status);
   if (BDMrc != BDM_RC_OK) {
      log.print("=> Status read failed\n");
      return setErrorState(DI_OK);
//      return setErrorState(DI_ERR_NONFATAL, BDMrc);
   }
   if ((status&CFV1_XCSR_ENBDM) == 0) {
      log.print("=> ENBDM=0\n");
      return setErrorState(DI_OK);
//      log.print("DiExecGetStatus()=>DI_ERR_NONFATAL\n");
//      return setErrorState(DI_ERR_NONFATAL, "Connection with target lost");
   }
   if ((status&CFV1_XCSR_STOP) != 0) {
      // Stopped - low power sleep, treated as running
//      pdesExitStatus->dscCause = DI_WAIT_EXTERNAL|DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Target Stopped (Low power)...";
      if (lastStatus != pdesExitStatus->dscCause) {
//         log.print("DiExecGetStatus() status change => DI_WAIT_EXTERNAL|DI_WAIT_MISCELLANEOUS, (%s)\n",
         log.print("DiExecGetStatus() status change => DI_WAIT_RUNNING, (%s)\n",
               pdesExitStatus->szReason);
      }
   }
   else if ((status&CFV1_XCSR_HALT) != 0) {
      // Halted - in debug halted mode
      pdesExitStatus->dscCause = DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->szReason = (DiStringT)"Debug Halted";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_MISCELLANEOUS, (%s)\n",
               pdesExitStatus->szReason);
#if (TARGET==CFV1) && defined(CONVERT_RESETS_TO_EXCEPTIONS)
         // Read-write PC on halt
         // This causes Illegal Operand and Address Errors to be converted from
         // Resets to Exceptions.
         // Without this code the debugger is a bit misleading as it halts at the
         // start of the exception handler but then does the reset on resume!
         unsigned long PCValue;
         bdmInterface->readCReg(CFV1_CRegPC, &PCValue);
         bdmInterface->writeCReg(CFV1_CRegPC, PCValue);
#endif
      }
   }
   else {
      // Processor executing
      pdesExitStatus->dscCause = DI_WAIT_RUNNING;
      pdesExitStatus->szReason = (DiStringT)"Running";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_RUNNING, (%s)\n",
               pdesExitStatus->szReason);
      }
   }
   log.print("Reason = %s\n", pdesExitStatus->szReason);
   lastStatus = pdesExitStatus->dscCause;
   return setErrorState(DI_OK);
}

