/*! \file
   \brief GDI Information

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
 Change History
+==============================================================================
| Revision History
+==============================================================================
| 16 Feb 11 | 4.4.0 Added struct packing changes for Eclipse 10.1         - pgo
+-----------+------------------------------------------------------------------
| 20 Feb 10 | 4.?.? Created                                               - pgo
+==============================================================================
\endverbatim
*/

#ifndef GDI_H_
#define GDI_H_

#ifdef WIN32
   #ifndef WINAPI
   #define WINAPI __stdcall
   #endif
#endif

#if defined __cplusplus
    extern "C" {
#endif

#ifdef __unix__
   #define USBDM_GDI_DECLSPEC extern "C" __attribute__ ((visibility ("default")))
#elif defined _WIN32
   #define USBDM_GDI_DECLSPEC extern "C" WINAPI __declspec(dllexport)
#endif

#include <limits.h>

typedef unsigned char   DiBoolT;
typedef unsigned char   DiUCharT;
typedef unsigned short  DiUInt16T;
#if   INT_MAX  == 0x7fffffff
typedef signed   int    DiInt32T;
typedef unsigned int    DiUInt32T;
#elif LONG_MAX == 0x7fffffff
typedef signed   long   DiInt32T;
typedef unsigned long   DiUInt32T;
#endif

typedef       char * DiStringT;
typedef const char * DiConstStringT;

// 2.3.46 DiReturnT
typedef enum {
   DI_OK                   = 0,
   DI_ERR_STATE            = 1,
   DI_ERR_PARAM            = 2,
   DI_ERR_COMMUNICATION    = 3,
   DI_ERR_NOTSUPPORTED     = 4,
   DI_ERR_NONFATAL         = 5,
   DI_ERR_CANCEL           = 6,
   DI_ERR_FATAL            = 7
} DiReturnT, *pDiReturnT;

// 2.3.15 DiCommChannelT
typedef DiUInt32T DiCommChannelT, *pDiCommChannelT;
#define DI_COMM_NONE          0x0000
#define DI_COMM_RS232         0x0001
#define DI_COMM_RS422         0x0002
#define DI_COMM_RS485         0x0004
#define DI_COMM_TCPIP         0x0008
#define DI_COMM_IPXSPX        0x0010
#define DI_COMM_IPC           0x0020
#define DI_COMM_RPC           0x0040
#define DI_COMM_SCSI          0x0080
#define DI_COMM_CAN           0x0100
#define DI_COMM_I2C           0x0200
#define DI_COMM_PROFIBUS      0x0400
#define DI_COMM_INTERBUS      0x0800
#define DI_COMM_TAP           0x1000
#define DI_COMM_DEVICE_FILE   0x2000
#define DI_COMM_ISA_BUS       0x4000
#define DI_COMM_PARALLEL      0x8000

//  2.3.3 DiAbsFileT
typedef DiUInt32T DiAbsFileT, *pDiAbsFileT;
#define DI_ABSF_NONE                0x0000
#define DI_ABSF_FILENAME            0x0001
#define DI_ABSF_TIOF695             0x0002
#define DI_ABSF_HPMRI695            0x0004
#define DI_ABSF_MOTOROLA_S          0x0008
#define DI_ABSF_INTEL_HEX           0x0010
#define DI_ABSF_TEKTRONIC_HEX       0x0020
#define DI_ABSF_EXT_TEKTRONIC_HEX   0x0040
#define DI_ABSF_BINARY              0x0080

//!  2.3.36 DiMemSpaceT
typedef DiUInt32T DiMemSpaceT;

#define cbDiValueT 8

//!  2.3.52 DiValueT
typedef struct {
DiUCharT val[cbDiValueT];
} DiValueT, *pDiValueT;

//!  2.3.30 DiLAddrT
typedef struct {
   DiValueT v;
} DiLAddrT, *pDiLAddrT;

//! 2.3.5 DiAddrT
typedef struct {
   DiMemSpaceT dmsMemSpace;
   DiLAddrT    dlaLinAddress;
} DiAddrT, *pDiAddrT;

//!  2.3.20 DiDownloadFormatT
typedef struct {
   DiAbsFileT  dafAbsFileFormat;
   DiUInt32T   dnBufferSize;
   DiAddrT     daAddress;
} DiDownloadFormatT, *pDiDownloadFormatT;

//!  2.3.14 DiCallbackT
typedef DiUInt32T DiCallbackT, *pDiCallbackT;

#define DI_CB_NONE            0x0000
#define DI_CB_BREAK           0x0001
#define DI_CB_EXCEPTION       0x0002
#define DI_CB_SYNCHRONIZE     0x0004
#define DI_CB_EXTERNBPSET     0x0008
#define DI_CB_MISCELLANEOUS   0x0010
#define DI_CB_EXITREQUEST     0x0020
#define DI_CB_LOG             0x0040
#define DI_CB_APPLI_INPUT     0x0080
#define DI_CB_APPLI_OUTPUT    0x0100
#define DI_CB_EVAL_EXPR       0x0200
#define DI_CB_ADDRTOSYMBOL    0x0400
#define DI_CB_DEBUG           0x0800
#define DI_CB_RESOURCES       0x1000
#define DI_CB_FEEDBACK        0x2000

typedef void (*CallbackF)(DiCallbackT, ...);

typedef enum
{
DI_FBC_START = 0,
DI_FBC_TICK = 1,
DI_FBC_STOP = 2
} DiFeedbackCommandT, *pDiFeedbackCommandT;

//!  2.2.1.9 Add Callback Procedures
typedef struct {
   DiBoolT     fBgSupport;
   DiMemSpaceT dmsMemSpace;
} DiBackGroundT, *pDiBackGroundT;

//!  2.3.21 DiEndianT
typedef enum {
   DI_UNKNOWN_ENDIANNESS   = 0,
   DI_BIG_ENDIAN           = 1,
   DI_LITTLE_ENDIAN        = 2
} DiEndianT;

#ifdef _WIN32
#if (defined(PACK_STRUCTS) && defined(LEGACY)) || (!defined(PACK_STRUCTS) && !defined(LEGACY))
#error "Inconsistent structure packing requirements"
#endif
#endif

//!  2.3.26 DiFeaturesT
#ifdef PACK_STRUCTS
// For some STUPID reason CW Eclipse 10.x packs the structures differently to
// every other version of Codewarrior
#pragma pack(2)
#endif

typedef struct {
   DiConstStringT    szIdentification;
   DiConstStringT    szVersion;
   DiUInt32T         dnVersion;
   DiConstStringT    *pszConfig;
   DiUInt32T         dnConfigArrayItems;
   DiCommChannelT    dccIOChannel;
   DiBoolT           fMemorySetMapAvailable;
   DiBoolT           fMemorySetCpuMapAvailable;
   DiConstStringT    *pszMemoryType;
   DiUInt32T         dnMemTypeArrayItems;
   DiBoolT           fEnableReadaheadCache;
   DiBoolT           fTimerInCycles;
   DiUInt32T         dnTimerResolutionMantissa;
   DiInt32T          dnTimerResolutionExponent;
   DiDownloadFormatT ddfDownloadFormat;
   DiDownloadFormatT ddfAuxDownloadFormat;
   DiBoolT           fAuxiliaryDownloadPathAvailable;
   DiCallbackT       dcCallback;
   DiBoolT           fRegisterClassSupport;
   DiBoolT           fSingleStepSupport;
   DiBoolT           fContinueUntilSupport;
   DiBoolT           fContinueBackgroundSupport;
   DiUInt32T         dnNrCodeBpAvailable;
   DiUInt32T         dnNrDataBpAvailable;
   DiBoolT           fExecFromCodeBp;
   DiBoolT           fExecFromDataBp;
   DiBoolT           fUnifiedBpLogic;
   DiBoolT           fExecCycleCounterAvailable;
   DiBoolT           fExecTimeAvailable;
   DiBoolT           fInstrTraceAvailable;
   DiBoolT           fRawTraceAvailable;
   DiBoolT           fCoverageAvailable;
   DiBoolT           fProfilingAvailable;
   DiBoolT           fStateSaveRestoreAvailable;
   DiUInt32T         dnStateStoreMaxIndex;
   DiBackGroundT     *pdbgBackground;
   DiUInt32T         dnBackgroundArrayItems;
   DiBoolT           fDirectDiAccessAvailable;
   DiBoolT           fApplicationIOAvailable;
   DiBoolT           fKernelAware;
   DiBoolT           fMeeAvailable;
   DiUInt32T         dnNrCpusAvailable;
   DiEndianT         deWordEndianness;
   DiUInt32T         dnNrHardWareCodeBpAvailable;
   DiBoolT           fCodeHardWareBpSkids;
   void              *pReserved;
} DiFeaturesT, *pDiFeaturesT;
#pragma pack()

//! 2.3.43 DiRegisterInfoT
typedef struct {
   DiConstStringT szRegName;
   DiUInt32T      dnRegNumber;
   DiBoolT        fGdiSupport;
} DiRegisterInfoT, *pDiRegisterInfoT;

//! 2.3.33 DiMemorySpaceInfoT
typedef struct {
   DiConstStringT    szMemSpaceName;
   DiMemSpaceT       dnMemSpaceId;
   DiBoolT           fGdiSupport;
} DiMemorySpaceInfoT, *pDiMemorySpaceInfoT;

//! 2.3.47 DiRs232HandshakeT
typedef enum {
   DI_RS232_NONE     = 0,
   DI_RS232_RTS_CTS  = 1,
   DI_RS232_XON_XOFF = 2
} DiRs232HandshakeT;

//! 2.3.16 DiCommSetupT
typedef struct {
   DiCommChannelT dccType;
   DiBoolT        fCheckConnection;
   union {
      struct {
         DiUInt32T         dummyValue;
      } None;
      struct {
         DiConstStringT    szPortName;
         DiUInt32T         dnBaudRate;
         DiRs232HandshakeT drhHandshake;
         DiUInt32T         dnTimeoutFactor;
         DiBoolT           fExclusiveAccess;
      } Rs232;
      struct {
         /* to be defined */
         DiUInt32T         to_be_defined;
      } Rs422;
      struct {
         /* to be defined */
         DiUInt32T         to_be_defined;
      } Rs485;
      struct {
         DiConstStringT szHost;
         DiConstStringT szPort;
      } TcpIp;
      struct {
         DiConstStringT szHost;
         DiConstStringT szPort;
      } IpxSpx;
      struct {
         DiConstStringT szMsgBox;
      } IPC;
      struct {
         DiConstStringT szHost;
         DiConstStringT szRpcPortNumber;
      } RPC;
      struct {
         DiUInt32T dnScsiId;
         DiUInt32T dnLogicalUnitNumber;
      } SCSI;
      struct {
         DiUInt32T   dnBaudRate;
         DiUInt32T   dnTargetDeviceIdent;
         DiBoolT     fForceLongAddressing;
         DiUInt32T   dnTimeoutFactor;
         DiUInt32T   dnHostInterfaceNumber;
         DiUInt32T   dnHostPortNumber;
      } CAN;
      struct {
         /* to be defined */
         DiUInt32T   to_be_defined;
      } I2C;
      struct {
         /* to be defined */
         DiUInt32T   to_be_defined;
      } Profibus;
      struct {
         /* to be defined */
         DiUInt32T to_be_defined;
      } Interbus;
      struct {
         /* to be defined */
         DiUInt32T to_be_defined;
      } TAP;
      struct {
         DiConstStringT szFileName;
      } DeviceFile;
      struct {
         DiUInt32T dnPortBase;
         DiUInt32T dnMemBase;
      } ISA;
      struct {
         DiConstStringT szPortName;
      } Parallel;
   } u;
} DiCommSetupT, *pDiCommSetupT;

//!  2.3.39 DiMenuItemT
typedef struct {
   DiConstStringT szMenuTitle;
   DiConstStringT szDiCommand;
} DiMenuItemT, *pDiMenuItemT;

//!  2.3.6 DiAddrRangeT
typedef struct {
   DiAddrT     daStart;
   DiUInt32T   dnSize;
} DiAddrRangeT, *pDiAddrRangeT;

//!  2.3.4 DiAccessT
typedef DiUInt32T DiAccessT, *pDiAccessT;

#define DI_ACC_NONE 0x0000
#define DI_ACC_EXECUTE 0x0001
#define DI_ACC_READ 0x0002
#define DI_ACC_WRITE 0x0004

//!  2.3.31 DiMemoryMapItemT
typedef struct {
   DiAddrRangeT   darRange;
   DiConstStringT szMemType;
   DiAccessT      daAccess;
} DiMemoryMapItemT, *pDiMemoryMapItemT;

//!  2.3.32 DiMemoryMapT
typedef struct {
   DiUInt32T         dnNrItems;
   DiMemoryMapItemT  *pdmmiItems;
} DiMemoryMapT, *pDiMemoryMapT;

//! 2.3.34 DiMemoryToCpuItemT
typedef struct {
   DiAddrRangeT   darCpu;
   DiAddrT        daPhysMem;
} DiMemoryToCpuItemT, *pDiMemoryToCpuItemT;

//! 2.3.35 DiMemoryToCpuT
typedef struct {
   DiUInt32T            dnNrItems;
   DiMemoryToCpuItemT   *pdmtciItems;
} DiMemoryToCpuT, *pDiMemoryToCpuT;

//!  2.3.19 DiDownloadCommandT
typedef enum {
   DI_DNLD_INIT      = 0,
   DI_DNLD_WRITE     = 1,
   DI_DNLD_TERMINATE = 2,
   DI_DNLD_ABORT     = 3
} DiDownloadCommandT, *pDiDownloadCommandT;

#define cbDiMaxBitsPerMemT       64
#define cbDiMaxUCharTsPerMemT    ((cbDiMaxBitsPerMemT+7)/8)
//!  2.3.37 DiMemT
typedef struct {
   DiUCharT val[cbDiMaxUCharTsPerMemT];
} DiMemT, *pDiMemT;

//! 2.3.53 DiValueStatusT
typedef DiUInt32T DiValueStatusT, *pDiValueStatusT;
#define DI_VS_DEFINED         0x0000
#define DI_VS_FLOATING        0x0001
#define DI_VS_UNINITIALIZED   0x0002
#define DI_VS_UNKNOWN         0x0003
#define DI_VS_READONLY        0x0004
#define DI_VS_WRITEONLY       0x0005
#define DI_VS_NO_MEMORY       0x0006

//!  2.3.38 DiMemValueT
typedef struct {
   DiMemT         dmValue;
   DiValueStatusT dvsStatus;
} DiMemValueT, *pDiMemValueT;

//!  2.3.44 DiRegisterValueT
typedef struct {
   DiValueT       dvValue;
   DiValueStatusT dvsStatus;
} DiRegisterValueT, *pDiRegisterValueT;

//!  2.3.18 DiDebugInfoT
typedef enum {
   DI_UI_SOURCE   = 0,
   DI_UI_ADDRESS  = 1,
   DI_UI_SYMBOL   = 2,
   DI_UI_STRING   = 3
} DiDebugInfoT, *pDiDebugInfoT;

//!  2.3.51 DiUserInfoT
typedef struct {
   DiDebugInfoT ddiType;
   union {
      struct {
         DiConstStringT szSrcFileName;
         DiUInt32T      dnSrcLineNumber;
         DiAddrT        daSrcAddress;
      } source;
      struct {
         DiAddrT daAddress;
      } instr;
      struct {
         DiConstStringT szSymbolName;
         DiAddrT        daAddress;
      } symbol;
      struct {
         DiConstStringT szString;
      } string;
   } u;
} DiUserInfoT;

//!  2.3.10 DiBpMethodT
typedef enum {
   DI_BPM_HARDWARE   = 0,
   DI_BPM_SOFTWARE   = 1,
   DI_BPM_NONE       = 2
} DiBpMethodT, *pDiBpMethodT;

//!  2.3.13 DiBpTypeT
typedef DiUInt32T DiBpTypeT, *pDiBpTypeT;
#define DI_BPT_EXECUTE        0x0001
#define DI_BPT_READ           0x0002
#define DI_BPT_WRITE          0x0004
#define DI_BPT_VALUE          0x0008
#define DI_BPT_TIME           0x0010
#define DI_BPT_CYCLES         0x0020
#define DI_BPT_INSTRUCTIONS   0x0040
#define DI_BPT_EXTERN         0x0080

//!  2.3.48 DiTimeT
typedef struct {
   DiValueT v;
} DiTimeT, *pDiTimeT;

//!  2.3.12 DiBpT
typedef struct {
   DiBpTypeT dbtBpType;
   union {
      struct {
      DiAddrT     daBp;
      DiUInt32T   dnSize;
      DiBpMethodT dbmBpMethod;
      } exe;
      struct {
      DiAddrT     daBp;
      DiUInt32T   dnSize;
      DiValueT    dnValue;
      } rwv;
      struct {
      DiTimeT     dtTime;
      } tim;
      struct {
      DiValueT    dvCycle;
      } cyc;
      struct {
      DiValueT    dvInstr;
      } inst;
   } u;
} DiBpT, *pDiBpT;

//!  2.3.11 DiBpResultT
typedef struct {
   DiUInt32T   dnBpId;
   DiBpT       dbBp;
} DiBpResultT, *pDiBpResultT;

//!  2.3.23 DiExitCauseT
typedef DiUInt32T DiExitCauseT, *pDiExitCauseT;
#define DI_WAIT_RUNNING       0x0000
#define DI_WAIT_SINGLESTEP    0x0001
#define DI_WAIT_CONTINUEUNTIL 0x0002
#define DI_WAIT_CODEBP        0x0004
#define DI_WAIT_DATABP        0x0008
#define DI_WAIT_CYCLES        0x0010
#define DI_WAIT_TIME          0x0020
#define DI_WAIT_INSTRUCTIONS  0x0040
#define DI_WAIT_USER          0x0080
#define DI_WAIT_EXTERNAL      0x0100
#define DI_WAIT_MISCELLANEOUS 0x0200
#define DI_WAIT_UNKNOWN       0x0400

//!  2.3.24 DiExitStatusT
typedef struct  {
   DiExitCauseT   dscCause;
   DiUInt32T      dwBpId;
   DiConstStringT szReason;
} DiExitStatusT, *pDiExitStatusT;

//!  2.3.28 DiInstrTraceItemT
typedef struct {
   DiAddrT  daPc;
   DiTimeT  dtTime;
} DiInstrTraceItemT, *pDiInstrTraceItemT;

//!  2.3.29 DiInstrTraceT
typedef struct {
   DiUInt32T            dnNrInstr;
   DiInstrTraceItemT    *pditiItems;
} DiInstrTraceT, *pDiInstrTraceT;

//!  2.3.41 DiProfT
typedef struct {
   DiAddrRangeT   darRange;
   DiTimeT        dtTime;
} DiProfT, *pDiProfT;

//!  2.3.42 DiProfileT
typedef struct {
   DiUInt32T   dnEntries;
   pDiProfT    *pdpProf;
} DiProfileT, *pDiProfileT;

//!  2.3.17 DiCoverageT
typedef DiUInt32T DiCoverageT, *pDiCoverageT;
#define DI_COV_UNKNOWN     0x0000
#define DI_COV_EXECUTE     0x0001
#define DI_COV_READ        0x0002
#define DI_COV_WRITE       0x0004
#define DI_COV_ACCESS      0x0008

//!  2.3.49 DiTraceTypeT
typedef enum {
   DI_TRACE_INSTR = 0,
   DI_TRACE_RAW   = 1,
   DI_TRACE_RAW1  = 2,
   DI_TRACE_RAW2  = 3
} DiTraceTypeT, *pDiTraceTypeT;

//!  2.3.40 DiNewFramesT
typedef struct {
   DiUInt32T   dnNrNewFrames;
   DiBoolT     fTraceBufferOverflow;
} DiNewFramesT, *pDiNewFramesT;

//! 2.3.22 DiExecEnvT
typedef struct {
   DiUInt32T        dnNrItems;
   DiConstStringT   *pszName;
} DiExecEnvT, *pDiExecEnvT;

typedef void (*PrintRawTraceF)(DiAddrT daPC, char *szString);

//! Open GDI
//!
//! @param dnGdiVersionH
//! @param dnGdiVersionL
//! @param dnArgc
//! @param szArgv
//! @param UdProcessEvents
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiOpen ( DiUInt32T       dnGdiVersionH,
                    DiUInt32T       dnGdiVersionL,
                    DiUInt32T       dnArgc,
                    DiConstStringT  szArgv[],
                    void (*UdProcessEvents)(void) );

//! Close GDI
//!
//! @param fClose
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiClose ( DiBoolT fClose );

//! Get GDI version
//!
//! @param dnGdiVersion
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiVersion ( DiUInt32T *dnGdiVersion );

//! Get Features Supported by GDI
//!
//! @param pdfFeatures
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiGetFeatures ( pDiFeaturesT pdfFeatures );

//! Set GDI Configuration
//!
//! @param szConfig
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiSetConfig ( DiConstStringT szConfig );

//! Configure I/O System
//!
//! @param pdcCommSetup
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitIO ( pDiCommSetupT pdcCommSetup );

//! Initialize Register Name/Number Map
//!
//! @param dnEntries
//! @param pdriRegister
//! @param dnProgramCounter
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitRegisterMap ( DiUInt32T        dnEntries,
                               DiRegisterInfoT   *pdriRegister,
                               DiUInt32T         dnProgramCounter ) ;

//! Initialize Memory Space Name/Number Map
//!
//! @param dnEntries
//! @param pdmiMemSpace
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiInitMemorySpaceMap ( DiUInt32T            dnEntries,
                                   DiMemorySpaceInfoT   *pdmiMemSpace );

//! 2.2.1.9 Add Callback Procedures
//!
//! @param dcCallbackType
//! @param Callback
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiAddCallback ( DiCallbackT dcCallbackType,
                            CallbackF   Callback ) ;

//! 2.2.1.10 Cancel GDI Procedure
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiCancel ( void ) ;

//! 2.2.1.11 Synchronize UD
//!
//! @param pfUpdate
//!
USBDM_GDI_DECLSPEC
DiReturnT DiGdiSynchronize ( DiBoolT *pfUpdate );

//! 2.2.2.1 Add DI Specific Commands to UD Menu
//!
//! @param pdnNrEntries
//! @param pdmiMenuItem
//!
USBDM_GDI_DECLSPEC
DiReturnT DiDirectAddMenuItem ( DiUInt32T    *pdnNrEntries,
                               pDiMenuItemT *pdmiMenuItem );

//! 2.2.2.2 Send Native Command to DI
//!
//! @param pszCommand
//! @param pduiUserInfo
//!
USBDM_GDI_DECLSPEC
DiReturnT DiDirectCommand ( DiConstStringT pszCommand,
                          DiUserInfoT    *pduiUserInfo ) ;

//! 2.2.2.3 Read String from DI
//!
//! @param dnNrToRead
//! @param pcBuffer
//! @param dnNrRead
//!
USBDM_GDI_DECLSPEC
DiReturnT DiDirectReadNoWait ( DiUInt32T  dnNrToRead,
                             char        *pcBuffer,
                             DiUInt32T   *dnNrRead );

//! 2.2.3.1 Retrieve Error Message
//!
//! @param pszErrorMsg
//!
USBDM_GDI_DECLSPEC
void DiErrorGetMessage ( DiConstStringT *pszErrorMsg );

//! 2.2.4.1 Configure Target Memory
//!
//! @param dmmMap
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemorySetMap ( DiMemoryMapT dmmMap ) ;

//! 2.2.4.2 Retrieve Target Memory Configuration
//!
//! @param pdmmMap
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryGetMap ( DiMemoryMapT *pdmmMap ) ;

//! 2.2.4.3 Configure CPU to Memory Interface
//!
//! @param dmtcMap
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemorySetCpuMap ( DiMemoryToCpuT dmtcMap ) ;

//! 2.2.4.4 Retrieve CPU to Memory Interface
//!
//! @param pdmtcMap
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryGetCpuMap ( DiMemoryToCpuT *pdmtcMap ) ;

//! Description of a target device;

//! 2.2.5.1 Download Application
//!
//! @param fUseAuxiliaryPath
//! @param ddcDownloadCommand
//! @param ddfDownloadFormat
//! @param pchBuffer
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                            DiDownloadCommandT ddcDownloadCommand,
                            DiDownloadFormatT  ddfDownloadFormat,
                            char               *pchBuffer ) ;
;
//! 2.2.5.2 Write Data to Target Memory
//!
//! @param daTarget        Target memory address
//! @param pdmvBuffer      Data to write
//! @param dnBufferItems   Number of units to write
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryWrite ( DiAddrT      daTarget,
                         DiMemValueT  *pdmvBuffer,
                         DiUInt32T    dnBufferItems );

//! 2.2.5.3 Read Data from Target Memory
//!
//! @param daTarget
//! @param pdmvBuffer
//! @param dnBufferItems
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMemoryRead ( DiAddrT       daTarget,
                        DiMemValueT   *pdmvBuffer,
                        DiUInt32T     dnBufferItems ) ;

//! 2.2.6.1 Write Value to Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterWrite ( DiUInt32T        dnRegNumber,
                           DiRegisterValueT drvValue ) ;

//! 2.2.6.2 Read Value from Register
//!
//! @param dnRegNumber
//! @param drvValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterRead ( DiUInt32T         dnRegNumber,
                          pDiRegisterValueT drvValue ) ;

//! 2.2.6.3 Create Register Class
//!
//! @param pdnRegClassId
//! @param pdnRegisterId
//! @param dnRegisterIdEntries
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassCreate ( DiUInt32T *pdnRegClassId,
                                 DiUInt32T *pdnRegisterId,
                                 DiUInt32T dnRegisterIdEntries ) ;

//! 2.2.6.4 Delete Register Class
//!
//! @param dnRegClassId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassDelete ( DiUInt32T dnRegClassId ) ;

//! 2.2.6.5 Write Value to Register Class
//!
//! @param dnRegClassId
//! @param pdrvClassValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassWrite ( DiUInt32T         dnRegClassId,
                                DiRegisterValueT  *pdrvClassValue ) ;

//! 2.2.6.6 Read Value from Register Class
//!
//! @param dnRegClassId
//! @param pdrvClassValue
//!
USBDM_GDI_DECLSPEC
DiReturnT DiRegisterClassRead ( DiUInt32T          dnRegClassId,
                               DiRegisterValueT   *pdrvClassValue ) ;

//!  2.2.7.1 Set Breakpoint
//!
//! @param pdnBreakpointId
//! @param dbBreakpoint
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointSet ( DiBpResultT *pdnBreakpointId,
                           DiBpT        dbBreakpoint ) ;

//!  2.2.7.2 Clear a Breakpoint
//!
//! @param dnBreakpointId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClear ( DiUInt32T dnBreakpointId ) ;

//!  2.2.7.3 Clear All Breakpoints
//!
USBDM_GDI_DECLSPEC
DiReturnT DiBreakpointClearAll ( void ) ;

//!  2.2.8.1 Reset
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecResetChild ( void ) ;

//!  2.2.8.2 Execute a Single Step
//!
//! @param dnNrInstructions
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecSingleStep ( DiUInt32T dnNrInstructions ) ;

//!  2.2.8.3 Continue Execution Until
//!
//! @param addrUntil
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinueUntil ( DiAddrT addrUntil ) ;

//!  2.2.8.4 Continue Execution
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinue ( void ) ;

//!  2.2.8.5 Continue Execution in Background
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecContinueBackground ( void ) ;

//!  2.2.8.6 Get DI Execution/Exit Status
//!
//! @param pdesExitStatus
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecGetStatus ( pDiExitStatusT pdesExitStatus ) ;

//!  2.2.8.7 Stop Execution
//!
USBDM_GDI_DECLSPEC
DiReturnT DiExecStop ( void ) ;

//!  2.2.9.1 Switch Trace System On/Off
//!
//! @param fOn
//!
USBDM_GDI_DECLSPEC
DiReturnT DiTraceSwitchOn ( DiBoolT fOn ) ;

//!  2.2.9.2 Get Instruction Trace
//!
//! @param dnNrInstr
//! @param pditInstrTrace
//!
USBDM_GDI_DECLSPEC
DiReturnT DiTraceGetInstructions ( DiUInt32T       dnNrInstr,
                                  pDiInstrTraceT  pditInstrTrace ) ;

//!  2.2.9.3 Get Raw Trace
//!
//! @param dnNrFrames
//! @param dttTraceType
//! @param PrintRawTrace
//!
USBDM_GDI_DECLSPEC
DiReturnT DiTracePrintRawInfo ( DiUInt32T       dnNrFrames,
                               DiTraceTypeT    dttTraceType,
                               PrintRawTraceF  PrintRawTrace ) ;

//!  2.2.9.4 Get Number of New Trace Frames
//!
//! @param dttTraceType
//! @param dnNrMaxFrames
//! @param pdnfNewFrames
//!
USBDM_GDI_DECLSPEC
DiReturnT DiTraceGetNrOfNewFrames ( DiTraceTypeT   dttTraceType,
                                   DiUInt32T      dnNrMaxFrames,
                                   pDiNewFramesT  pdnfNewFrames ) ;

//!  2.2.10.1 Switch Coverage On/Off
//!
//! @param fOn
//!
USBDM_GDI_DECLSPEC
DiReturnT DiCoverageSwitchOn ( DiBoolT fOn ) ;

//!  2.2.10.2 Get Coverage Information
//!
//! @param daStart
//! @param dnSize
//! @param pdcCoverage
//!
USBDM_GDI_DECLSPEC
DiReturnT DiCoverageGetInfo ( DiAddrT     daStart,
                             DiUInt32T   dnSize,
                             DiCoverageT *pdcCoverage ) ;

//!  2.2.11.1 Switch Profiling On/Off
//!
//! @param fOn
//!
USBDM_GDI_DECLSPEC
DiReturnT DiProfilingSwitchOn ( DiBoolT fOn ) ;

//!  2.2.11.2 Get Profiling Information
//!
//! @param pdpProfile
//!
USBDM_GDI_DECLSPEC
DiReturnT DiProfileGetInfo ( DiProfileT *pdpProfile ) ;

//!  2.2.12.1 Open a State Resource
//!
//! @param pdnStateHandle
//! @param szStateName
//!
USBDM_GDI_DECLSPEC
DiReturnT DiStateOpen ( DiUInt32T      *pdnStateHandle,
                      DiConstStringT  szStateName ) ;

//!  2.2.12.2 Save DI State
//!
//! @param dnStateHandle
//! @param dnIndex
//!
USBDM_GDI_DECLSPEC
DiReturnT DiStateSave ( DiUInt32T dnStateHandle,
                       DiUInt32T dnIndex ) ;

//!  2.2.12.3 Restore DI State
//!
//! @param dnStateHandle
//! @param dnIndex
//!
USBDM_GDI_DECLSPEC
DiReturnT DiStateRestore ( DiUInt32T dnStateHandle,
                          DiUInt32T dnIndex ) ;

//!  2.2.12.4 Close a State Resource
//!
//! @param fDelete
//!
USBDM_GDI_DECLSPEC
DiReturnT DiStateClose ( DiBoolT fDelete ) ;

//!  2.2.13 Get Acceptable Communication Settings
//!
//! @param dccType
//! @param szAttr
//! @param pszEntries
//! @param pReserved
//!
USBDM_GDI_DECLSPEC
DiReturnT DiCommGetAcceptableSettings ( DiCommChannelT    dccType,
                                      DiConstStringT   szAttr,
                                      DiConstStringT   *pszEntries[],
                                      void             *pReserved ) ;

//!  2.2.16.1 Enumerate Execution Environments
//!
//! @param pdExecEnv
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeEnumExecEnv ( DiExecEnvT *pdExecEnv ) ;

//!  2.2.16.2 Connect to Execution Environment
//!
//! @param dnExecId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeConnect ( DiUInt32T dnExecId );

//!  2.2.16.3 Get Features Supported by Execution Environment
//!
//! @param dnExecId
//! @param pdfFeatures
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeGetFeatures ( DiUInt32T    dnExecId,
                            pDiFeaturesT pdfFeatures ) ;

//!  2.2.16.4 Configure I/O System to Execution Environment
//!
//! @param dnExecId
//! @param pdcCommSetup
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeInitIO ( DiUInt32T      dnExecId,
                       pDiCommSetupT  pdcCommSetup ) ;

//!  2.2.16.5 Set Current Connection
//!
//! @param dnExecId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeSelect ( DiUInt32T dnExecId ) ;

//!  2.2.16.6 Disconnect from Execution Environment
//!
//! @param dnExecId
//! @param fClose
//!
USBDM_GDI_DECLSPEC
DiReturnT DiMeeDisconnect ( DiUInt32T  dnExecId,
                           DiBoolT    fClose );

//!  2.2.16.7 Connect to CPU
//!
//! @param dnCpuId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiCpuSelect ( DiUInt32T dnCpuId ) ;

//!  2.2.16.8 Get Current CPU
//!
//! @param dnCpuId
//!
USBDM_GDI_DECLSPEC
DiReturnT DiCpuCurrent ( DiUInt32T *dnCpuId ) ;

//!  2.2.17 Future GDI Extensions
//!
//! @param information
//!
USBDM_GDI_DECLSPEC
DiReturnT DiProcess ( void *information ) ;

#if defined __cplusplus
    }
#endif

#endif /* GDI_H_ */
