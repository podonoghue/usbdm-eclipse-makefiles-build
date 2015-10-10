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
//      osbdm_base.c
//
//
//  DESCRIPTION
//
//		OSBDM-JM60 USB driver base API
//
//===============================================================================================
//|  1 Dec 2014 | Fixed format in printf()s                                     - pgo 4.10.6.230
//===============================================================================================
//
//----------------------------------------------------------------------------
//
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "USBDM_API.h"
#include "USBDM_API_Private.h"
#include "Names.h"

//#include "osbdm_base.h"
#include "osbdm_def.h"
#include "osbdm_memtype.h"
//#include "osbdm_cfv234.h"
//#include "osbdm_cfv1.h"

//----------------------------------------------------------------------
// OSBDM USB Driver APIs.
//----------------------------------------------------------------------

static TargetType_t targetType = T_CFV1;

// returns version of the DLL in BCD format
//
OSBDM_API_JM60 unsigned char osbdm_DLL_VERSION(void) {
   return(0);
}

// initialises USB and returns number of devices found
// Actually return 2 x #devices -- see below
//
OSBDM_API_JM60 unsigned char osbdm_init(void) {
   LOGGING_Q;
   unsigned int deviceCount;
   USBDM_Init();
   USBDM_FindDevices(&deviceCount);
   deviceCount <<= 1;
   log.print("Usb initialised, found %d device(s)\n", deviceCount);
   return(deviceCount);
}

/* opens a device with given number (0...) */
// Hack for combined CFV1/CFVx USBDM - device number is actually device_no/2
// Odd numbers => CFVx, Even numbers => CFV1
// e.g. 0 => open CFV1 device #0
//      1 => open CFVx device #0
//      2 => open CFV1 device #1
//      3 => open CFVx device #1
//
OSBDM_API_JM60 OsbdmErrT osbdm_open(unsigned char device_no) {
   LOGGING_Q;
   targetType = (device_no&0x01)?T_CFVx:T_CFV1;
   device_no >>= 1;
   log.print("Trying to open %s, device #%d\n", getTargetTypeName(targetType), device_no);
   if (USBDM_Open(device_no>>1) != BDM_RC_OK)
      return osbdm_error_usb_transport;
   else
      return osbdm_error_ok;
}

// initialize BDM
OSBDM_API_JM60 OsbdmErrT osbdm_init_hardware() {
   LOGGING_Q;

   // Set up sensible default since we can't change this
   BDM_Options_t bdmOptions;
   bdmOptions.targetVdd          = BDM_TARGET_VDD_3V3;//BDM_TARGET_VDD_NONE;
   bdmOptions.autoReconnect      = AUTOCONNECT_ALWAYS; // Aggressively auto-connect
   bdmOptions.guessSpeed         = FALSE;
   bdmOptions.cycleVddOnConnect  = FALSE;
   bdmOptions.cycleVddOnReset    = FALSE;
   bdmOptions.leaveTargetPowered = FALSE;
   bdmOptions.useAltBDMClock     = CS_DEFAULT;
   bdmOptions.useResetSignal     = FALSE;

   if (USBDM_SetOptions(&bdmOptions) != BDM_RC_OK)
      return osbdm_error_fail;

   if (USBDM_SetTargetType(targetType) != BDM_RC_OK)
      return osbdm_error_fail;

   // Set conservative speed
   if (targetType == T_CFVx)
      USBDM_SetSpeed(5000);

   if (USBDM_Connect() != BDM_RC_OK)
      return osbdm_error_fail;

   return osbdm_error_ok;
}

/* closes currently open device */
OSBDM_API_JM60 void osbdm_close(void) {
   LOGGING_Q;
   log.print("Trying to close the device\n");
   USBDM_Close();
   USBDM_Exit();
}

/* gets version of the interface (HW and SW) in BCD format */
OSBDM_API_JM60 OsbdmErrT  osbdm_get_version(unsigned int *version) {
   *version = 0x0101;
   return osbdm_error_ok;
}

/* resets the target*/
OSBDM_API_JM60 OsbdmErrT osbdm_target_reset(ResetT reset_mode) {
   LOGGING_Q;
   TargetMode_t targetMode;

   switch (reset_mode) {
      case eSoftReset_to_NormalMode  : targetMode =  (TargetMode_t)(RESET_NORMAL|RESET_SOFTWARE);  break;
      case eHardReset_to_DebugMode   : targetMode =  (TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE); break;
      case eHardReset_to_NormalMode  : targetMode =  (TargetMode_t)(RESET_NORMAL|RESET_HARDWARE);  break;
      case ePowerReset_to_DebugMode  : targetMode =  (TargetMode_t)(RESET_SPECIAL|RESET_POWER);    break;
      case ePowerReset_to_NormalMode : targetMode =  (TargetMode_t)(RESET_NORMAL|RESET_POWER);     break;
      default:
      case eSoftReset_to_DebugMode   : targetMode =  (TargetMode_t)(RESET_SPECIAL|RESET_SOFTWARE); break;
   }

   if (targetType == T_CFVx) {
      // Bug in Codesourcery - ask for software reset on a CFVx which only has hardware!
      targetMode = (TargetMode_t)((targetMode & ~RESET_METHOD_MASK) | RESET_HARDWARE);
   }
   if (USBDM_TargetReset(targetMode) != BDM_RC_OK)
      return osbdm_error_fail;

   if (USBDM_Connect() != BDM_RC_OK)
      return osbdm_error_fail;

   return osbdm_error_ok;
}

#define OSBDM_CMD_GET_STATUS   0x10 // returns a block of status information for the BDM and it's current state

/* fills user supplied structure with actual state of BDM communication channel */
/* returns 0 on success and non-zero on failure */
//OSBDM_API_JM60 unsigned char osbdm_bdm_sts(bdm_status_t *bdm_status) {
OSBDM_API_JM60 OsbdmErrT osbdm_status(unsigned char *result){

   USBDMStatus_t status;
   if (USBDM_GetBDMStatus(&status) != BDM_RC_OK)
      return osbdm_error_fail;

   unsigned long csrValue;
   if (USBDM_ReadDReg(CFVx_DRegCSR, &csrValue) != BDM_RC_OK)
      return osbdm_error_fail;

//   Get bdm/target status information to be sent to the host
//
//   data[+2] will be loaded with bytes as follows:
//      0-4 = CSR register
//      5 = last SPI error status (eStatus)
//      6 = PST Status
//      7 = unused
//      8 = unused
//      9 = unused
//      A = unused

   // UGLY - dummy a direct response from the osbdm BDM!!!!
   int index = 0;
   result[index++]  = OSBDM_CMD_GET_STATUS;
   result[index++]  = 12;
   result[index++]  = (uint8_t)(csrValue>>24);
   result[index++]  = (uint8_t)(csrValue>>16);
   result[index++]  = (uint8_t)(csrValue>>8);
   result[index++]  = (uint8_t)(csrValue);
   result[index++]  = 0;
   result[index++]  = status.halt_state?0xF:0x00;

//   print("osbdm_status()x - 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n",
//         result[2], result[3], result[4], result[5], result[6], result[7]);

   return osbdm_error_ok;
}

#if 0
//
//	unit of speed is KHz.
//
OSBDM_API_JM60 OsbdmErrT osbdm_get_speed(unsigned long *speed) {
   unsigned long val;

   if(osbdm_send1(CMD_GET_SPEED)) return osbdm_error_usb_transport;
   if(osbdm_usb_recv_ep2(6, usb_data2)) return osbdm_error_usb_transport;	// receive result
   if (usb_data2[0] != CMD_GET_SPEED) return osbdm_error_cmd_failed;

   val = BufToUlong(usb_data2+2);
   if (val == 0){
      *speed =0;
      return osbdm_error_fail;
   }

   *speed = (unsigned long) ( 60.0 * 2 * 128 *1000.0 /(unsigned long)(val&0xFFFF) );
   return osbdm_error_ok;
}


//	unit of speed is KHz.
OSBDM_API_JM60 OsbdmErrT osbdm_set_speed(unsigned long speed) {
   unsigned long val;

   // Example - to set oscillator at 4Mhz (which is 4000Khz):

   // (1 / 4,000) * 256 / (1/60,000) = freq to set in 60Mhz ticks
   // (1 / 4,000) * 15360000 = 3840 (0xF00, which is the value sent from the PC)

   //val = (unsigned long) (1.0 / speed) * 15360.0;  // speed in MHz
   val = (unsigned long) (1.0 / speed * 256 * 60.0 * 1000.0);  // speed in KHz

   usb_data[0] = CMD_SET_SPEED;
   *(unsigned long *) (usb_data+1) =  val;
   if(osbdm_usb_send_ep1(5, usb_data)) return osbdm_error_usb_transport;	// tx data
   if(osbdm_usb_recv_ep2(2, usb_data2)) return osbdm_error_usb_transport;	// receive result
   if (usb_data2[0] != CMD_SET_SPEED) return osbdm_error_cmd_failed;
   return osbdm_error_ok;
}

// configure paramater
OSBDM_API_JM60
OsbdmErrT osbdm_config(unsigned char config_type, unsigned char config_param, unsigned long param_value) {

   usb_data[0] = CMD_CONFIG;
   usb_data[1] = config_type;
   usb_data[2] = config_param;
   *(unsigned long *) (usb_data+3) =  param_value;

   if(osbdm_usb_send_ep1(7, usb_data)) return osbdm_error_usb_transport;	// tx data
   if(osbdm_usb_recv_ep2(2, usb_data2)) return osbdm_error_usb_transport;	// receive result
   if (usb_data2[0] != CMD_CONFIG) return osbdm_error_cmd_failed;
   return osbdm_error_ok;
}
#endif

/* starts target execution from current PC address */
OSBDM_API_JM60 OsbdmErrT osbdm_target_go(void) {
   if (USBDM_TargetGo() != BDM_RC_OK)
      return osbdm_error_fail;
   else
      return osbdm_error_ok;
}

/* steps over a single target instruction */
OSBDM_API_JM60 OsbdmErrT osbdm_target_step(void) {
   if (USBDM_TargetStep() != BDM_RC_OK)
      return osbdm_error_fail;
   else
      return osbdm_error_ok;
}

/* brings the target into active background mode */
OSBDM_API_JM60 OsbdmErrT osbdm_target_halt(void) {
   if (USBDM_TargetHalt() != BDM_RC_OK)
      return osbdm_error_fail;
   else
      return osbdm_error_ok;
}

/*------------------------------------------------------------------------------------
	Write Memory

	type:  kind of memory to be written (see commands.h)

		MEM_RAM	   Normal Memory
		MEM_REG		Normal Register
		MEM_CREG		Control Register
		MEM_DREG		Debug Register


	width:	width of writes (8/16/32)
	addr:	address to start writing to
	data:	pointer to the data
	size:   number of BYTES total to be written

 */
OSBDM_API_JM60 OsbdmErrT osbdm_write_block(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long size) {
   LOGGING_Q;

   unsigned int elementSize = width/8;
   unsigned int byteCount   = size;
   USBDM_ErrorCode rc;
   unsigned long value;

   log.print("t=%d, w=%d, a=0x%08lX, s=%02lX \n", type, width, addr, size);
//osbdm_write_block() - t=0, w=8, a=0x00800000, s=704
   // Register writes need data as a single unsigned long
   // ToDo check byte order
   switch (byteCount) {
      case 1  : value = data[0]; break;
      case 2  : value = (data[1]<<8) + data[0]; break;
      case 4  : value = (data[3]<<24) + (data[2]<<16) + (data[1]<<8) + data[0]; break;
      default : value = 0; break; // unused
   }

//   print("osbdm_write_block() - t=%d, w=%d, a=0x%08X, s=%02X \n", type, width, addr, size);

   switch (type) {
   case MEM_RAM :
      rc = USBDM_WriteMemory(elementSize, byteCount, addr, data);
      break;
   case MEM_REG :
      rc = USBDM_WriteReg(addr, value);
      break;
   case MEM_CREG :
      rc = USBDM_WriteCReg(addr, value);
      break;
   case MEM_DREG :
      rc = USBDM_WriteDReg(addr, value);
      break;
   default:
      return osbdm_error_invalid_parameter;
   }
   if (rc != BDM_RC_OK)
      return osbdm_error_fail;
   else
      return osbdm_error_ok;
}

#if 0
/*------------------------------------------------------------------------------------
	Fill Memory

	type:  kind of memory to be read (see commands.h)

		MEM_RAM			Normal Memory

	addr:	address to start filling from
	width:	width of Fills (8/16/32)
	data:	pointer to hold data
	count:  number of units to be filled

 */
OSBDM_API_JM60 OsbdmErrT osbdm_write_fill(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long count){
   osbdm_mem_header(CMD_FILL, type, addr, width, count);	// prepare usb header for this memory command
   switch (width) {
   case 8:
      *(usb_data+MEM_HEADER_SIZE) = data[0];
      break;
   case 16:
      *(usb_data+MEM_HEADER_SIZE)   = data[0];
      *(usb_data+MEM_HEADER_SIZE+1) = data[1];
      break;
   case 32:
   default:
      *(usb_data+MEM_HEADER_SIZE)   = data[0];
      *(usb_data+MEM_HEADER_SIZE+1) = data[1];
      *(usb_data+MEM_HEADER_SIZE+2) = data[2];
      *(usb_data+MEM_HEADER_SIZE+3) = data[3];
      break;
   }

   if(osbdm_usb_send_ep1(MEM_HEADER_SIZE+(width/8), usb_data)) return osbdm_error_usb_transport;	// Tx data
   return osbdm_getreply(CMD_FILL);	// receive reply from command
}
#endif

void writeAsBytes(unsigned byteCount, unsigned char *data, unsigned long value) {
   // Register reads return data as a single unsigned long
   // ToDo check byte order
   switch (byteCount) {
   case 1 :
      data[0] = value;
      break;
   case 2 :
      data[1] = (value>>8);
      data[0] = value;
      break;
   case 4 :
      data[3] = (value>>24);
      data[2] = (value>>16);
      data[1] = (value>>8);
      data[0] = value;
      break;
   }

}

/*------------------------------------------------------------------------------------
	Read Memory

	type:  kind of memory to be read (see commands.h)

		MEM_RAM			Normal Memory
		MEM_REG			Normal Register
		MEM_CREG		Control Register
		MEM_DREG		Debug Register

	addr:	  address to start reading from
	width:  width of Reads (8/16/32)
	data:	  pointer to hold data
	size:   number of BYTES total to be read

 */
OSBDM_API_JM60 OsbdmErrT osbdm_read_block(unsigned char type, unsigned char width, unsigned long addr, unsigned char *data, unsigned long size){
   LOGGING_Q;
   unsigned int elementSize = width/8;
   unsigned int byteCount   = size;
   USBDM_ErrorCode rc;
   unsigned long value;
//   unsigned long bdmStatusReg;
   log.print("t=%d, w=%d, a=0x%08lX, s=%02lX \n", type, width, addr, size);

//   USBDM_ReadStatusReg(&bdmStatusReg); // Cause resync

   switch (type) {
   case MEM_RAM :
      rc = USBDM_ReadMemory(elementSize, byteCount, addr, data);
      break;
   case MEM_REG :
      rc = USBDM_ReadReg(addr, &value);
      writeAsBytes(byteCount, data, value);
      break;
   case MEM_CREG :
      rc = USBDM_ReadCReg(addr, &value);
      writeAsBytes(byteCount, data, value);
      break;
   case MEM_DREG :
      if ((byteCount == 1) &&
            (CFV1_DRegXCSR <= addr) && (addr <= CFV1_DRegCSR3)){ // Special CFV1_DRegXCSRbyte etc
         addr += CFV1_ByteRegs;
      }
      if (addr == CFV1_DRegXCSRbyte)
         rc = USBDM_ReadStatusReg(&value);
      else
         rc = USBDM_ReadDReg(addr, &value);
      writeAsBytes(byteCount, data, value);
      break;
   default:
      return osbdm_error_invalid_parameter;
   }
   if (rc != BDM_RC_OK)
      return osbdm_error_fail;
   return osbdm_error_ok;
}

// write a single 32-bit value to target memory
OSBDM_API_JM60 OsbdmErrT	osbdm_write_32(unsigned char type, unsigned long address, unsigned long value) {
   LOGGING_Q;
   unsigned char byteData[4];
   // ToDo check byte order
   byteData[3] = (value>>24);
   byteData[2] = (value>>16);
   byteData[1] = (value>>8);
   byteData[0] = value;
   log.print("t=%d, a=0x%08lX, v=%08lX \n", type, address, value);
   return osbdm_write_block(type, 32, address, byteData, 4);
}

// write a single 16-bit value to target memory
OSBDM_API_JM60 OsbdmErrT	osbdm_write_16(unsigned char type, unsigned long address, unsigned short value) {
   LOGGING_Q;
   unsigned char byteData[2];
   // ToDo check byte order
   byteData[1] = (value>>8);
   byteData[0] = value;
   log.print("t=%d, a=0x%08lX, v=%04X \n", type, address, value);
   return osbdm_write_block(type, 16, address, byteData, 2);
}

// write a single 8-bit value to target memory
OSBDM_API_JM60 OsbdmErrT	osbdm_write_8(unsigned char type, unsigned long address, unsigned char value) {
   LOGGING_Q;
   log.print("t=%d, a=0x%08lX, v=%02X \n", type, address, value);
   return osbdm_write_block(type, 8, address, &value, 1);
}


// read a single 32-bit value from target memory/register
OSBDM_API_JM60 OsbdmErrT	osbdm_read_32(unsigned char type, unsigned long address, unsigned long *data) {
   LOGGING_Q;
   unsigned char byteData[4] = {0};
   OsbdmErrT rc = osbdm_read_block(type, 32, address, byteData, 4);
   // ToDo check byte order
   *data = (byteData[3]<<24) + (byteData[2]<<16) + (byteData[1]<<8) + byteData[0];
   log.print("t=%d, a=0x%08lX, v=%08lX \n", type, address, *data);
   return rc;
}

// read a single 16-bit value to target memory
OSBDM_API_JM60 OsbdmErrT osbdm_read_16(unsigned char type, unsigned long address, unsigned short *data){
   LOGGING_Q;
   unsigned char byteData[2] = {0};
   OsbdmErrT rc = osbdm_read_block(type, 16, address, byteData, 2);
   // ToDo check byte order
   *data = (byteData[1]<<8) + byteData[0];
   log.print("t=%d, a=0x%08lX, v=%04X \n", type, address, *data);
   return rc;
}

// read a single 8-bit value to target memory
OSBDM_API_JM60 OsbdmErrT	osbdm_read_8(unsigned char type, unsigned long address, unsigned char *data){
   LOGGING_Q;
   unsigned char byteData[1] = {0};
   OsbdmErrT rc = osbdm_read_block(type, 8, address, byteData, 1);
   *data = byteData[0];
   log.print("t=%d, a=0x%08lX, v=%02X \n", type, address, *data);
   return rc;
}
