/*! \file
   \brief Compatibility wrapper for TBDML.dll library

   \verbatim
   TBDML interface DLL
   Copyright (C) 2008  Peter O'Donoghue

   Based on
      Opensource BDM  - interface DLL

   which is based on
      TBDML interface DLL by
      Copyright (C) 2005  Daniel Malik

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
|  7 Aug 2009 | Created                                                   - pgo
+==============================================================================
\endverbatim
*/
#include <math.h>

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "TBDML.h"
#include "TargetDefines.h"
#include "BdmInterface.h"
//#include "hcs12UnsecureDialogue.h"
#include "BdmInterfaceFactory.h"
#include "GdiDialoguePluginFactory.h"
#include "UsbdmWxConstants.h"
#include "Utils.h"

static bool askUnsecure = TRUE;

BdmInterfacePtr bdmInterface;

//! Get version of the DLL in BCD format
//!
//! @return 8-bit version number (2 BCD digits, major-minor)
//!
TBDML_API unsigned int  _tbdml_dll_version(void){
	return bdmInterface->getDllVersion();
}

//! Initialises USB interface
//!
//! This must be done before any device may be opened.
//!
//! @return Number of BDM devices found - Always 1!
//!
TBDML_API unsigned char _tbdml_init(void) {
   LOGGING;

   // This is a dummy return
   // Device count etc is done later
   return 1;
}

//! Opens a device
//!
//! @param device_no Number (0..N) of device to open.
//! A device must be open before any communication with the device can take place.
//! @note The range of device numbers must be obtained from init() before calling
//! this function.
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_open(unsigned char device_no) {
   LOGGING;

   // Enable prompting to unsecure device
   askUnsecure = TRUE;

   // Opening of devices is deferred until the target is set.
   // The user can then choose the BDM etc
   return BDM_RC_OK;
}

//! Closes currently open device
//!
TBDML_API void _tbdml_close(void) {
   LOGGING;
   bdmInterface.reset();
}

//! Get software version and type of hardware
//!
//! @return 16-bit version number (2 bytes)   \n
//!  - LSB = USBDM firmware version           \n
//!  - MSB = Hardware version
//!
TBDML_API unsigned int  _tbdml_get_version(void) {
   LOGGING_E;
   USBDM_bdmInformation_t bdmInformation;
   bdmInterface->getBdmInformation(bdmInformation);
   return (bdmInformation.BDMhardwareVersion<<8) |
           bdmInformation.BDMsoftwareVersion;
}

static USBDM_ErrorCode openTargetWithConfig(BdmInterfacePtr bdmInterface) {
   LOGGING;

   AppSettingsPtr appSettings(new AppSettings("TBDML_Config.cfg", "TBDML Configuration"));
   appSettings->load();
   GdiDialoguePluginPtr dialogue = GdiDialoguePluginFactory::createPlugin();
   bool forceDisplay = false;

   USBDM_ErrorCode rc;
   do {
      rc = dialogue->execute(bdmInterface, appSettings, forceDisplay);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      forceDisplay = true;
      appSettings->save();
      rc = bdmInterface->initBdm();
   } while (rc != BDM_RC_OK);
   return rc;
}

//! Sets target MCU type
//!
//! @param target_type type of target
//!
//! @return 0 => Success,\n !=0 => Fail
//!
//! @note A dialog box will open to allow the user to configure the BDM
//!    The user may be prompted to supply power to target
//!
TBDML_API unsigned char _tbdml_set_target_type(TargetType_t _targetType) {
   LOGGING;

   bdmInterface = BdmInterfaceFactory::createInterface(T_HCS12);
   USBDM_ErrorCode rc = openTargetWithConfig(bdmInterface);
   if (rc != BDM_RC_OK) {
      log.error("Failed, rc = %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

//! Get status of the last command
//!
//! @return 0 => Success,\n 1 => Failure
//!
TBDML_API unsigned char _tbdml_get_last_sts(void) {
   LOGGING_E;
   //TODO - replace
   return USBDM_GetCommandStatus();
}

//! Fills user supplied structure with state of BDM communication channel
//!
//! @param bdm_status Pointer to structure to receive status
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_bdm_sts(bdm_status_t *bdmStatus) {
   LOGGING_Q;

   USBDMStatus_t USBDMStatus;
   USBDM_ErrorCode rc = bdmInterface->targetConnectWithRetry(BdmInterface::retryAlways);
   if (rc == BDM_RC_OK) {
      rc = bdmInterface->getBDMStatus(&USBDMStatus);
   }
   if (rc == BDM_RC_OK) {
      bdmStatus->ackn_state       = USBDMStatus.ackn_state;
      bdmStatus->connection_state = USBDMStatus.connection_state;
      bdmStatus->reset_state      = USBDMStatus.reset_recent;
   }
   else {
      log.print("Status read failed\n");
      bdmStatus->ackn_state       = WAIT;
      bdmStatus->connection_state = SPEED_NO_INFO;
      bdmStatus->reset_state      = NO_RESET_ACTIVITY;
   }
   return rc;
}

//======================================================================
//======================================================================
//======================================================================

//! Connects to Target.
//!
//! This will cause the BDM module to attempt to connect to the Target.
//! In most cases the BDM module will automatically determine the connection
//! speed and successfully connect.  If unsuccessful, it may be necessary
//! to manually set the speed using set_speed().
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_target_sync(void) {
   LOGGING_E;

   return bdmInterface->targetConnectWithRetry();
}

//! Sets the communication speed.
//!
//! @param crystal_frequency crystal frequency in MHz.
//! This is used to determine the BDM communication speed (assumed
//! to be half the crystal frequency given).
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_set_speed(float crystal_frequency) {
   LOGGING_E;

   int speed;
   speed = floor((1000000/2)*crystal_frequency); // Convert to BDM comm freq in Hz
   return bdmInterface->setSpeedHz(speed);    // Set BDM coms speed in Hz
}

//! Determine crystal frequency of the target
//!
//! @return Crystal Frequency of target in MHz
//!
TBDML_API float _tbdml_get_speed(void) {
   LOGGING_Q;

   unsigned long speed;
   bdmInterface->getSpeedHz(&speed); // BDM comms speed in Hz
   return 2*speed/1000000.0;         // Convert to crystal freq in MHz
}

//! Resets the target to normal or special mode
//!
//! @param target_mode see \ref target_mode_e
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_target_reset(TargetMode_t targetMode) {
   LOGGING_E;

   USBDM_ErrorCode rc = bdmInterface->reset(targetMode);

   // Automatically connect after a reset
   if (rc == BDM_RC_OK)
      rc = bdmInterface->connect();
   return rc;
}

//! Steps over a single target instruction
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_target_step(void) {
   LOGGING_E;

   return bdmInterface->step();
}

//! Starts target execution from current PC address
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_target_go(void) {
   LOGGING_E;

   return bdmInterface->go();
}

//! Brings the target into active background mode.  The target will be halted.
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_target_halt(void) {
   LOGGING_E;

   return bdmInterface->halt();
}

//! (HCS12) Reads contents of core registers
//!
//! @param  registers   pointer to structure to receive the register values
//!
//! @return 0 => Success,\n !=0 => Fail
//!
TBDML_API unsigned char _tbdml_read_regs(registers_t *registers) {
   LOGGING_E;
   uint8_t rc;
   unsigned long value;

   rc = bdmInterface->readReg(HCS12_RegPC, &value);
   if (rc != BDM_RC_OK)
      return rc;
   registers->hc12.pc  = (uint16_t)value;
   rc = bdmInterface->readReg(HCS12_RegSP, &value);
   if (rc != BDM_RC_OK)
      return rc;
   registers->hc12.sp  = (uint16_t)value;
   rc = bdmInterface->readReg(HCS12_RegX, &value);
   if (rc != BDM_RC_OK)
      return rc;
   registers->hc12.ix  = (uint16_t)value;
   rc = bdmInterface->readReg(HCS12_RegY, &value);
   if (rc != BDM_RC_OK)
      return rc;
   registers->hc12.iy  = (uint16_t)value;
   rc = bdmInterface->readReg(HCS12_RegD, &value);
   if (rc != BDM_RC_OK)
      return rc;
   registers->hc12.d   = (uint16_t)value;
   rc = bdmInterface->readDReg(0xFF06,&value);
   if (rc != BDM_RC_OK)
      return rc;
	registers->hc12.ccr = (uint8_t)value;

   return BDM_RC_OK;
}

//! (HCS12, HCS08 & RS08) Writes PC (HCS12, HC08), CCR+PC (RS08)
//!
//! @param value 16-bit value
//!
TBDML_API void _tbdml_write_reg_pc(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeReg(HCS12_RegPC, value);
}

//! (HCS12, HCS08 & RS08) Writes SP (HCS12, HCS08), Shadow PC (RS08)
//!
//! @param value 16-bit value
//!
TBDML_API void _tbdml_write_reg_sp(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeReg(HCS12_RegSP, value);
}

//! (HCS12) Writes IY
//!
//! @param value 16-bit value
//!
TBDML_API void _tbdml_write_reg_y(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeReg(HCS12_RegY, value);
}

//! (HCS12 & HCS08) Writes IX (HCS12), H:X (HCS08)
//!
//! @param value 16-bit value
//!
TBDML_API void _tbdml_write_reg_x(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeReg(HCS12_RegX, value);
}

//! (HCS12, HCS08 & RS08) Writes D=B:A (HCS12) or A (HCS08, RS08)
//!
//! @param value 16-bit / 8-bit value
//!
TBDML_API void _tbdml_write_reg_d(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeReg(HCS12_RegD, value);
}

//! (HCS12 & HCS08) Writes CCR
//!
//! @param value 8-bit value
//!
TBDML_API void _tbdml_write_reg_ccr(unsigned int value) {
   LOGGING_E;

   bdmInterface->writeDReg(0xFF06,value);
}
//! (HCS12, HC08 & RS08) Reads one byte from memory
//!
//! @param address 16-bit memory address
//!
//! @return 8-bit value
//!
TBDML_API unsigned char _tbdml_read_byte(unsigned int address) {
   LOGGING_E;

   uint8_t value;
   bdmInterface->readMemory( 1, 1, address, &value);
   return value;
}

//! (HCS12, HC08 & RS08) Writes one byte to memory
//!
//! For HCS12 & HC08 this writes to RAM.
//! For RS08 this may write to RAM or Flash if preceded by a call to mem_dlstart().
//!
//! @param address 16-bit memory address
//! @param data    8-bit data value
//!

TBDML_API void _tbdml_write_byte( unsigned int  address,
                                  unsigned char data) {
   LOGGING_E;

   bdmInterface->writeMemory( 1, 1, address, &data);
}

//! (HCS12, HC08 & RS08) Reads block as bytes from memory
//!
//! @param addr    16-bit memory address
//! @param count   8-bit byte count
//! @param data    Pointer to buffer to contain data
//!
TBDML_API void _tbdml_read_block( unsigned int addr,
                                  unsigned int count,
                                  unsigned char *data) {
   LOGGING_E;

   bdmInterface->readMemory( 1, count, addr, data);
}

//! (HCS12, HC08 & RS08) Writes a block of data to memory
//!
//! For HCS12 & HC08 this writes to RAM.
//!
//! @param addr    16-bit memory address
//! @param count   8-bit byte count
//! @param data    Pointer to buffer containing data
//!
TBDML_API void _tbdml_write_block( unsigned int addr,
                                   unsigned int count,
                                   unsigned char *data) {
   LOGGING_E;

   bdmInterface->writeMemory( 1, count, addr, data);
}

//! (HCS12) Reads one word from memory (address must be aligned)
//!
//! @param address 16-bit memory address
//!
//! @return 16-bit data value
//!
TBDML_API unsigned int _tbdml_read_word(unsigned int address) {
   LOGGING_E;

   uint8_t buffer[2];

   bdmInterface->readMemory( 2, 2, address, buffer);
   return (buffer[0]<<8)+buffer[1];
}

//! (HCS12) Writes one word to memory (address must be aligned)
//!
//! @param address 16-bit memory address
//! @param data 16-bit data value
//!
TBDML_API void _tbdml_write_word(unsigned int address, unsigned int data) {
   LOGGING_E;

   uint8_t buffer[2];
   buffer[0] = data>>8;
   buffer[1] = data;
   bdmInterface->writeMemory( 2, 2, address, buffer);
}

#define HC12_BDMSTS     0xFF01   //!< Address of HC12 BDM Status register

//! (HCS12) Reads one byte from the BDM address space
//!
//! @param address 16-bit memory address
//! @return 8-bit data value
//!
//! @note Access to BDMSTS register address is mapped to bdmInterface->readStatusReg()
//!
TBDML_API unsigned char _tbdml_read_bd(unsigned int address) {
   LOGGING_Q;

   uint8_t rc;
   unsigned long value;

   if (address == HC12_BDMSTS) {
      rc = bdmInterface->readStatusReg(&value);
   }
   else {
      rc = bdmInterface->readDReg(address, &value);
   }
   log.print("@%4.4X => %2.2X\n", address, (int)value);

   if (rc != BDM_RC_OK) {
      return 0;
   }
	return (uint8_t)value;
}

//! (HCS12) Writes one byte to the BDM address space
//!
//! @param address 16-bit memory address
//! @param data    8-bit data value
//!
//! @return 0 => Success,\n !=0 => Fail
//!
//! @note Access to Control register address is mapped to bdmInterface->writeControlReg()
//!
TBDML_API unsigned char _tbdml_write_bd(unsigned int address, unsigned char data) {

   if (address == HC12_BDMSTS)
      return bdmInterface->writeControlReg(data);
   else
      return bdmInterface->writeDReg(address, data);
}

#ifdef _WIN32
#include <windef.h>

extern "C" WINAPI __declspec(dllexport)
BOOL DllMain(HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved) {
   static bool IOpenedLogFile = false;

   switch (fdwReason) {
      case DLL_PROCESS_ATTACH:
         if (UsbdmSystem::Log::getLogFileHandle() == 0) {
            IOpenedLogFile = true;
            UsbdmSystem::Log::openLogFile("TBDML.log", "TBDML Log");
         }
         UsbdmSystem::Log::print("tbdml::DLL_PROCESS_ATTACH @0x%p\n", hDLLInst);
         break;
      case DLL_PROCESS_DETACH:
         UsbdmSystem::Log::print("tbdml::DLL_PROCESS_DETACH @0x%p\n", hDLLInst);
         if (IOpenedLogFile) {
            UsbdmSystem::Log::closeLogFile();
         }
         break;
      case DLL_THREAD_ATTACH:
         UsbdmSystem::Log::print("tbdml::DLL_THREAD_ATTACH @0x%p\n", hDLLInst);
         break;
      case DLL_THREAD_DETACH:
         UsbdmSystem::Log::print("tbdml::DLL_THREAD_DETACH @0x%p\n", hDLLInst);
         break;
   }
   return TRUE;
}
#endif
