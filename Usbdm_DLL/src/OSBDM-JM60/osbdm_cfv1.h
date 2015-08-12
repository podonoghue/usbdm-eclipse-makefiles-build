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
//      osbdm_cfv1.h
// 
//
//  DESCRIPTION
//
//		OSBDM CFV1 Specific header
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_CFV1_H__
#define __OSBDM_CFV1_H__

//
// definitions
//


//
// CFV1 register numbers
//
typedef enum {
    cfv1regID_d0, // 0		
    cfv1regID_d1,					
    cfv1regID_d2,					
    cfv1regID_d3,					
    cfv1regID_d4,					
    cfv1regID_d5,					
    cfv1regID_d6,					
    cfv1regID_d7,					
    cfv1regID_a0,					
    cfv1regID_a1,					
    cfv1regID_a2,					
    cfv1regID_a3,					
    cfv1regID_a4,					
    cfv1regID_a5,					
    cfv1regID_a6,					
    cfv1regID_a7,					
    cfv1regID_pc,			// 16	
    cfv1regID_sr = 19,	
	cfv1regID_FIRST_CONTROL_REG = 0x1000,
	cfv1regID_FIRST_DEBUG_REG = 0x2000, 
	cfv1regID_FIRST_DEBUG_regID_BYTE = 0x2101,
    cfv1regID_xcsr_byte = 0x2101,			
    cfv1regID_csr2_byte = 0x2102,					
    cfv1regID_csr3_byte = 0x2103

}cfv1regID;

/* Debug Registers (BDM command: READ_DREG, WRITE_DREG) */
/* Actual register number correspond to 0x2000 plus the 5 bit DRc encoding.
*/

/* Control Registers (BDM command: READ_CREG, WRITE_CREG) */
/* Actual register number correspond to 0x1000 plus the 5-bit CRN field. 
 */

	
#endif //__OSBDM_CFV1_H__

