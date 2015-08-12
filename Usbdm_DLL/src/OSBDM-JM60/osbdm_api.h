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
//      osbdm_api.h
// 
//
//  DESCRIPTION
//
//		OSBDM USB driver API
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_API_H__
#define __OSBDM_API_H__

//
// OSBDM USB Driver Definitions
//
#include "osbdm_def.h"		

//
// Interface
//
unsigned char		osbdmAPI_api_version(void); 					// returns OSBDM Driver dll version in BCD format
OsbdmErrT			osbdmAPI_open(unsigned char device_no);
OsbdmErrT			osbdmAPI_close(void);
OsbdmErrT			osbdmAPI_init(unsigned char *device_count);
OsbdmErrT			osbdmAPI_connect(CoreT core_type);
OsbdmErrT			osbdmAPI_osbdmJM60_version(unsigned int *version);		// returns version of HW (MSB) and SW (LSB) of the Firmware USB interface in BCD format 
OsbdmErrT			osbdmAPI_get_status(ConnectStateT *status);
OsbdmErrT			osbdmAPI_get_speed(unsigned long *speed);			// speed in KHz
OsbdmErrT			osbdmAPI_set_speed(unsigned long speed);			// speed in KHz
OsbdmErrT			osbdmAPI_stop(void);
OsbdmErrT			osbdmAPI_run(void);
OsbdmErrT			osbdmAPI_step(void);
OsbdmErrT			osbdmAPI_reset(ResetT type);
OsbdmErrT			osbdmAPI_read_mem(unsigned char mem_space, unsigned int addr, unsigned int byte_count, SizeT access_size, unsigned char *buffer); 
OsbdmErrT			osbdmAPI_write_mem(unsigned char mem_space, unsigned int addr, unsigned int byte_count, SizeT access_size, unsigned char *buffer);
OsbdmErrT			osbdmAPI_read_reg(unsigned int regid, SizeT regsize, unsigned long *value);    // read core register
OsbdmErrT			osbdmAPI_write_reg(unsigned int regid,  SizeT regsize, unsigned long value);	// write core register

OsbdmErrT		    osbdmAPI_config(unsigned char config_type, unsigned char config_param, unsigned long param_value);

OsbdmErrT			osbdmAPI_core_mode(CoreModeT *core_mode);  
OsbdmErrT			osbdmAPI_secure_mode(SecureModeT *secure_mode);  

#endif //__OSBDM_API_H__
