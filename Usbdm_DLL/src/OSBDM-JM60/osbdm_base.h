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
//      osbdm_base.h
// 
//
//  DESCRIPTION
//
//		OSBDM USB driver dll
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_BASE_H__
#define __OSBDM_BASE_H__

//
// OSBDM USB Driver Definitions
//
#include "osbdm_def.h"		

//
// OSBDM USB driver base dll API
//	

unsigned char	osbdm_DLL_VERSION(void); 				// returns DLL version in BCD.
 
OsbdmErrT		osbdm_open(unsigned char device_no);
void			osbdm_close();
unsigned char	osbdm_init();
OsbdmErrT		osbdm_init_hardware(void);
OsbdmErrT		osbdm_get_speed(unsigned long *speed);   // in KHz
OsbdmErrT		osbdm_set_speed(unsigned long  speed);   // in KHz

OsbdmErrT		osbdm_write_block(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long size);
OsbdmErrT		osbdm_read_block(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long size);
OsbdmErrT		osbdm_write_fill(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long count);

OsbdmErrT		osbdm_write_32(unsigned char type, unsigned long address, unsigned long data);
OsbdmErrT		osbdm_write_16(unsigned char type, unsigned long address, unsigned short data);
OsbdmErrT		osbdm_write_8(unsigned char type, unsigned long address, unsigned char data);
OsbdmErrT	    osbdm_read_32(unsigned char type, unsigned long address, unsigned long *data);
OsbdmErrT 	    osbdm_read_16(unsigned char type, unsigned long address, unsigned short *data);
OsbdmErrT		osbdm_read_8(unsigned char type, unsigned long address, unsigned char *data);

OsbdmErrT		osbdm_target_halt();
OsbdmErrT		osbdm_target_go();
OsbdmErrT		osbdm_target_step();

OsbdmErrT		osbdm_target_reset(ResetT resetmode);
OsbdmErrT		osbdm_status(unsigned char *data);
OsbdmErrT		osbdm_get_version(unsigned char *version_info);				/* returns version of HW (MSB) and SW (LSB) of the interface in BCD format */

OsbdmErrT		osbdm_config(unsigned char config_type, unsigned char config_param, unsigned long param_value);
 
 
 // To-Be-Depricated
 unsigned char		osbdm_write32(unsigned char type, unsigned long address, unsigned long data);
 unsigned char		osbdm_write16(unsigned char type, unsigned long address, unsigned short data);
 unsigned char		osbdm_write8(unsigned char type, unsigned long address, unsigned char data);
 unsigned long		osbdm_read32(unsigned char type, unsigned long address);
 unsigned short		osbdm_read16(unsigned char type, unsigned long address);
 unsigned char		osbdm_read8(unsigned char type, unsigned long address);
 unsigned long		osbdm_read_bd(unsigned int address); 	// reads from the BDM area of memory
 unsigned char		osbdm_write_bd(unsigned int address, unsigned long data); // writes to the BDM area of memory, returns 0 on success and non-zero on failure
 
 

#endif //__OSBDM_BASE_H__
