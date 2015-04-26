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

#include "ArmDefinitions.h"

#if (TARGET != ARM)
#error "Build for wrong target"
#endif

const TargetType_t targetType = T_ARM;

const DiFeaturesT diFeatures = {
  /* .szIdentification                 = */ (DiStringT)"USBDM ARM",
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
   U32c            value(drvValue);
   USBDM_ErrorCode rc  = BDM_RC_OK;

   log.print("(0x%X(%d) <= 0x%08X)\n", dnRegNumber, dnRegNumber, (uint32_t)value);

   CHECK_ERROR_STATE();
   ARM_Registers_t regNum = (ARM_Registers_t)dnRegNumber;
   long unsigned dataValue;
   switch (dnRegNumber) {
      // These regs are read together so need RMW sequence
      case arm_RegCONTROL :
         USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue &= ~(0xFF<<24);
         dataValue |= (value&0xFF)<<24;
         rc = USBDM_WriteReg(ARM_RegMISC, dataValue);
         break;
      case arm_RegFAULTMASK :
         USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue &= ~(0xFF<<16);
         dataValue |= (value&0xFF)<<16;
         value = dataValue;
         rc = USBDM_WriteReg(ARM_RegMISC, dataValue);
         break;
      case arm_RegBASEPRI :
         USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue &= ~(0xFF<<8);
         dataValue |= (value&0xFF)<<8;
         value = dataValue;
         rc = USBDM_WriteReg(ARM_RegMISC, dataValue);
         break;
      case arm_RegPRIMASK :
         USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue &= ~(0xFF);
         dataValue |= (value&0xFF);
         value = dataValue;
         rc = USBDM_WriteReg(ARM_RegMISC, dataValue);
         break;
      default:
         rc = USBDM_WriteReg(regNum, value);
         break;
   }
   log.print("%s(%d) <= 0x%08X\n", getARMRegName(regNum), regNum, (uint32_t)value);
   if (rc != BDM_RC_OK) {
      log.error("%s(0x%X) Failed, reason= %s\n",
            getARMRegName(regNum), regNum, USBDM_GetErrorString(rc));
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
   ARM_Registers_t   regNum    = (ARM_Registers_t)dnRegNumber;

   if (forceMassErase) {
      // Dummy register reads until device in unsecured
      *drvValue = (U32c)dataValue;
      return setErrorState(DI_OK);
   }
   CHECK_ERROR_STATE();

   switch (dnRegNumber) {
      // These regs are read together so need RMW sequence
      case arm_RegCONTROL :
         rc = USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue = (dataValue>>24)&0xFF;
         break;
      case arm_RegFAULTMASK :
         rc = USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue = (dataValue>>16)&0xFF;
         break;
      case arm_RegBASEPRI :
         rc = USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue = (dataValue>>8)&0xFF;
         break;
      case arm_RegPRIMASK :
         rc = USBDM_ReadReg(ARM_RegMISC, &dataValue);
         dataValue = (dataValue)&0xFF;
         break;
      default:
         rc = USBDM_ReadReg(regNum, &dataValue);
         break;
   }
   if (rc != BDM_RC_OK) {
      log.print("(0x%X) => error\n", dnRegNumber);
      return setErrorState(DI_ERR_NONFATAL, rc);
   }
   *drvValue = (U32c)dataValue;
   log.print("%s(%d) => 0x%08X\n", getARMRegName(regNum), regNum, (uint32_t)dataValue);
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


//! Reads a word from ARM target memory
//!
//! @param address  - 32-bit address (aligned)
//! @param data     - pointer to buffer for word
//!
//! @return error code
//!
static USBDM_ErrorCode armReadMemoryWord(unsigned long address, unsigned long *data) {
   LOGGING_Q;

   uint8_t           buff[4];
   USBDM_ErrorCode   rc = USBDM_ReadMemory(4, 4, address, buff);

   *data = (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
   switch(address) {
   case DEMCR:
      log.print("(DEMCR, %s)\n", getDEMCRName(*data));
      break;
   case DHCSR:
      log.print("(DHCSR, %s)\n", getDHCSRName(*data));
      break;
   default: break;
   }
   return rc;
}

#if 0
//! Writes a word to ARM target memory
//!
//! @note Assumes aligned address
//! @note Breaks transfers on 2**10 boundary as TAR may not increment across this boundary
//!
//! @param address - 32-bit address
//! @param data    - ptr to buffer containing words
//!
//! @return error code
//!
static USBDM_ErrorCode armWriteMemoryWord(unsigned long address, unsigned long data) {
   uint8_t         buff[4] = {(data)&0xFF, (data>>8)&0xFF, (data>>16)&0xFF, (data>>24)&0xFF};
   USBDM_ErrorCode rc      = USBDM_WriteMemory(4, 4, address, buff);

   switch(address) {
   case DEMCR:
      log.print("(DEMCR, %s)\n", getDEMCRName(data));
      break;
   case DHCSR:
      log.print("(DHCSR, %s)\n", getDHCSRName(data));
      break;
   default: break;
   }
   return rc;
}
#endif

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
   static int           failureCount   = 0;

   // Defaults
   pdesExitStatus->dscCause = DI_WAIT_UNKNOWN;
   pdesExitStatus->dwBpId   = 0x1000400; // bkpt ID?
   pdesExitStatus->szReason = (DiStringT)"Unknown state";

   unsigned long dhcsr;
   BDMrc = armReadMemoryWord(DHCSR, &dhcsr);
   if (BDMrc != BDM_RC_OK) {
      log.print("Failed, autoReconnect=%s\n", bdmOptions.autoReconnect?"T":"F");
   }
   if ((BDMrc != BDM_RC_OK) && (bdmOptions.autoReconnect)) {
      log.print("Doing autoReconnect\n");
      if (bdmInterface->targetConnectWithRetry(BdmInterface::retryAlways) != BDM_RC_OK) {
         log.print("(BdmInterface::retryAlways)=> re-connect failed\n");
      }
      else {
         log.print("Re-connect OK\n");
         // retry after connect
         BDMrc = armReadMemoryWord(DHCSR, &dhcsr);
      }
   }
   if (BDMrc != BDM_RC_OK) {
      log.print("Failed, rc=%s, failureCount=%d\n",
            USBDM_GetErrorString(BDMrc), failureCount);
      mtwksDisplayLine("DiExecGetStatus() - Failed, rc=%s, failureCount=%d\n",
            USBDM_GetErrorString(BDMrc), failureCount);
      if (failureCount++ > 10) {
         // Give up after 10 tries!
         log.print("Returning FATAL error\n");
         return setErrorState(DI_ERR_FATAL, BDMrc);
      }
      else {
         return setErrorState(DI_ERR_NONFATAL, BDMrc);
      }
   }
   // Reset on OK dhcsr
   failureCount = 0;
   if ((dhcsr & DHCSR_S_SLEEP) != 0) {
      // Stopped - low power sleep, treated as special
      pdesExitStatus->dscCause = DI_WAIT_EXTERNAL|DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->szReason = (DiStringT)"Target Stopped (Low power)...";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_EXTERNAL|DI_WAIT_MISCELLANEOUS, (%s)\n",
               pdesExitStatus->szReason);
      }
   }
   else if ((dhcsr & (DHCSR_S_HALT|DHCSR_S_LOCKUP)) != 0) {
      // Processor in debug halt
      pdesExitStatus->dscCause = DI_WAIT_MISCELLANEOUS;
      pdesExitStatus->szReason = (DiStringT)"Debug Halted";
      if (lastStatus != pdesExitStatus->dscCause) {
         log.print("Status change => DI_WAIT_MISCELLANEOUS, (%s)\n",
               pdesExitStatus->szReason);
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

