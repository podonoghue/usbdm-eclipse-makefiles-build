/* OSBDM-JM60 Windows USB Library
 * Copyright (C) 2009  Freescale
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

//----------------------------------------------------------------------------
//
//
//  FILE
//
//      osbdm_def.h
// 
//
//  DESCRIPTION
//
//		OSBDM USB driver definitions
//
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_DEF_H__
#define __OSBDM_DEF_H__

#define OSBDMUSB_VERSION	0x10		// version of the OSBDM USB DLL 

//#include "osbdm_memtype.h"
//#include "osbdm_configparam.h"

typedef enum  {
    osbdm_error_ok,
	osbdm_error_fail,
	osbdm_error_invalid_parameter,
	osbdm_error_invalid_target,
	osbdm_error_not_supported,
	osbdm_error_usb_transport,
	osbdm_error_cmd_failed,
	osbdm_error_bdm_not_enabled,
    osbdm_error_undefined
} OsbdmErrT;


typedef enum  {			// type of reset mode
	eSoftReset_to_DebugMode, 		
	eSoftReset_to_NormalMode, 		
	eHardReset_to_DebugMode, 
	eHardReset_to_NormalMode, 
	ePowerReset_to_DebugMode,
	ePowerReset_to_NormalMode	// not implemented yet
} ResetT; 


typedef enum {			// status of flash programming algo execution */
	FP_DONE,
	FP_RUNNING,
	FP_TIMEOUT,
	FP_UNKNOWN
} FlashStateT;

typedef enum {			// status of VPP flash programming voltage */
	VPP_DISABLED,		// VPP is not supplied to the target.
	VPP_ENABLED,		// VPP is supplied to the target.
	VPP_TIMEOUT,		// VPP is turned off automatically due to timeout (6 msec).
	VPP_UNKNOWN
} VppStateT;


typedef enum  {
    eCFv234,
	eCFv1,
	eS08,
	eRS08,
    eS12,
	eDSC,
	eCoreTypeUnknown
} CoreT;

typedef enum  {
    eByte,			// 1 byte 
    eWord,			// 2 bytes 
	eLong			// 4 bytes 
} SizeT;

typedef enum  {			// type of core run state 
	eDebug,				
	eRunning,
	eWait,
	eStopped,
	eWaitOrStopped,
	eBusy,
	eCoreModeUndefined 
} CoreModeT;

typedef enum  {			// type of secure mode
	eSecured,				
	eUnsecured,
	eSecureModeUndefined, 
} SecureModeT;


typedef enum {			//target reset detection state 
	xRESET_INACTIVE,
	xRESET_DETECTED,
	xRESET_UNDEFINED
} TargetResetDetectT;

typedef enum {			//target connection state 
	NO_CONNECTION = 0,
	SYNC		  = 1,
	RESERVED      = 2,
	MANUAL_SETUP  = 3,
	CONNECT_UNDEFINED,
} TargetConnectStateT;


typedef struct {		 //  Target BDM Communication state
	TargetResetDetectT	reset_state;
	TargetConnectStateT	connect_state;
	unsigned int		osbdmJM60_version;  // VERSION = (VERSION_HW+256*VERSION_SW):  intel endianism
	FlashStateT		flash_state;
	VppStateT		Vpp_state;
} ConnectStateT;

typedef struct {
	ConnectStateT	connect_state;
	CoreT		coreid;
} OsbdmInfoT;



#endif //__OSBDM_DEF_H__
