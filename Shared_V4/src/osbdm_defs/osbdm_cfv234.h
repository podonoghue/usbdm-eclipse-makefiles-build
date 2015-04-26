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
//      osbdm_cfv234.h
// 
//
//  DESCRIPTION
//
//		OSBDM CFV2-4 Specific header
//
//
//
//----------------------------------------------------------------------------
//

#ifndef __OSBDM_CFV234_H__
#define __OSBDM_CFV234_H__

//
// definitions
//


//
// CFV234 register numbers
//
typedef enum {
    cfv234regID_d0,			// 0		
    cfv234regID_d1,					
    cfv234regID_d2,					
    cfv234regID_d3,					
    cfv234regID_d4,					
    cfv234regID_d5,					
    cfv234regID_d6,					
    cfv234regID_d7,					
    cfv234regID_a0,					
    cfv234regID_a1,					
    cfv234regID_a2,					
    cfv234regID_a3,					
    cfv234regID_a4,					
    cfv234regID_a5,					
    cfv234regID_a6,					
    cfv234regID_a7,			// 15
    cfv234regID_pc = 16,
    cfv234regID_sr = 19,
	cfv234regID_FIRST_CONTROL_REG   = 0x1000,
	cfv234regID_FIRST_DEBUG_REG     = 0x2000

}cfv234regID;
 
/* Debug Registers (BDM command: READ_DREG, WRITE_DREG) */
/* Actual register number correspond to 0x2000 plus the 5 bit DRc encoding.
*/

/* Control Registers (BDM command: READ_CREG, WRITE_CREG) */
/* Actual register number correspond to 0x1000 plus the 12-bit Rc field 
   and is the same as that used by the MOVEC instruction.
*/


#endif //__OSBDM_CFV234_H__

