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
//      osbdm_memtype.h
// 
//
//  DESCRIPTION
//
//		OSBDM Memory Type
//
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_MEMTYPE_H__
#define __OSBDM_MEMTYPE_H__

//
// definitions
// 

typedef enum  {	
	MEM_RAM			=0,			// Memory
	MEM_REG			=1,			// Register
	MEM_CREG		=2,			// Control Register
	MEM_DREG		=3,			// Debug Register
	MEM_P			=10,		// Program Memory 
	MEM_P_FLASH		=11, 		// Program Flash Memory
	MEM_X			=12,		// Data Memory 
	MEM_X_FLASH		=13			// Data Flash Memory
} OsbdmMemT;


#endif //__OSBDM_MEMTYPE_H__
