/*
 * GdbHandlerARM.cpp
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#include <string.h>
#include <time.h>
#include <errno.h>
#include "GdbHandler_ARM.h"
#include "ArmDefinitions.h"
#include "Names.h"
#include "signals.h"
#include "GdbBreakpoints_ARM.h"

GdbHandler *createARMGdbHandler(
      GdbHandler::GdbHandlerOwner    &owner,
      GdbInOut                       *gdbInOut,
      BdmInterfacePtr                 bdmInterface,
      DeviceInterfacePtr              deviceInterface,
      IGdbTty                        *tty) {
   return new GdbHandler_ARM(owner, gdbInOut, bdmInterface, deviceInterface, tty);
}

GdbHandler_ARM::GdbHandler_ARM(
      GdbHandlerOwner     &owner,
      GdbInOut            *gdbInOut,
      BdmInterfacePtr      bdmInterface,
      DeviceInterfacePtr   deviceInterface,
      IGdbTty              *tty) :
      GdbHandlerCommon(
            T_ARM,
            owner,
            gdbInOut,
            bdmInterface,
            deviceInterface,
            new GdbBreakpoints_ARM(bdmInterface),
            tty,
            DeviceData::resetHardware) {
   isKinetisDevice = false;
}

GdbHandler_ARM::~GdbHandler_ARM() {
}

// Target is LE == Native
//=============================
/**
 * Convert a 16-bit number between native <=> target endian
 *
 * @param data Value to convert
 *
 * @return Converted value
 */
uint16_t GdbHandler_ARM::targetToFromNative16(uint16_t data) {
   return data;
}

/**
 * Convert a 32-bit number between native <=> target endian
 *
 * @param data Value to convert
 *
 * @return Converted value
 */
uint32_t GdbHandler_ARM::targetToFromNative32(uint32_t data) {
   return data;
}

/**
 * Extract a 32-bit value from byte buffer in target byte order
 *
 * @param[in]  buff    Buffer to read value from
 * @param[out] value   32-bit value from buffer
 */
void GdbHandler_ARM::extractTarget32Bits(uint8_t buff[], uint32_t &value) {
   // Little-endian
   value = buff[0] + (buff[1]<<8) +(buff[2]<<16) +(buff[3]<<24);
}

/**
 * Encode a 32-bit value into byte buffer in target byte order
 *
 * @param[out] value   32-bit value to enter
 * @param[in]  buff    Buffer to add value to
 */
void GdbHandler_ARM::encodeTarget32Bits(uint32_t value, uint8_t buff[]) {
   // Little-endian
   buff[0] = static_cast<uint8_t>(value);
   buff[1] = static_cast<uint8_t>(value>>8);
   buff[2] = static_cast<uint8_t>(value>>16);
   buff[3] = static_cast<uint8_t>(value>>24);
}

// Target is LE != BE
//=================================
/*
 * Convert 16-bit value Target <-> BIG-ENDIAN
 */
uint16_t GdbHandler_ARM::targetToBE16(uint16_t data) {
   return ((data<<8)&0xFF00) + ((data>>8)&0xFF);
}
//=================================
/*
 * Convert 32-bit value Target <-> BIG-ENDIAN
 */
uint32_t GdbHandler_ARM::targetToBE32(uint32_t data) {
   return ((data<<24)&0xFF000000) + ((data<<8)&0xFF0000) + ((data>>8)&0xFF00) + ((data>>24)&0xFF);
}

/**
 * Configure the MDM_AP register for Kinetis targets
 *
 * @return
 */
USBDM_ErrorCode GdbHandler_ARM::configureMDM_AP() {

   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;

   unsigned long mdm_ap_ident;
   rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Ident, &mdm_ap_ident);
   isKinetisDevice = (rc == BDM_RC_OK) && ((mdm_ap_ident & 0xFFFFFF00)== 0x001C0000);
   log.print("Kinetis device? %s\n", isKinetisDevice?"true":"false");
   reportGdbPrintf(M_BORINGINFO, "Found Kinetis device\n");
   configureKinetisMDM_AP(false);

   return rc;
}

USBDM_ErrorCode GdbHandler_ARM::initialise() {
   LOGGING_F;

   USBDM_ErrorCode rc = GdbHandlerCommon::initialise();

   // Ignore secured as may still be able to program device after mass-erase
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      resetTarget();
      rc = GdbHandlerCommon::initialise();
   }
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      // In case target is in LLSx or VLLSx with debug interface unavailable
      resetTarget(DeviceData::resetHardware);
      rc = GdbHandlerCommon::initialise();
   }
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      return rc;
   }
   return configureMDM_AP();
}

USBDM_ErrorCode GdbHandler_ARM::resetTarget(DeviceData::ResetMethod resetMethod) {
   LOGGING;

   USBDM_ErrorCode rc = GdbHandlerCommon::resetTarget(resetMethod);
   if (rc != BDM_RC_OK) {
      rc = GdbHandlerCommon::resetTarget(DeviceData::resetHardware);
   }
   if (rc != BDM_RC_OK) {
      reportGdbPrintf(M_ERROR, "Failed to reset target - rc = %s\n", bdmInterface->getErrorString(rc));
      return rc;
   }
   registerBufferSize = 0;
   return configureKinetisMDM_AP(false);
}

USBDM_ErrorCode GdbHandler_ARM::continueTarget(void) {
   LOGGING_Q;

   configureKinetisMDM_AP(true);

   return GdbHandlerCommon::continueTarget();
}

/**
 * Mask/unmask interrupts (in DHCSR)
 *
 * @param disableInterrupts - true/false -> disable/enable interrupts
 */
void GdbHandler_ARM::maskInterrupts(bool disableInterrupts) {
   const uint8_t disableInts[4] = {DHCSR_C_MASKINTS|DHCSR_C_HALT|DHCSR_C_DEBUGEN,0x00,0x5F,0xA0};
   const uint8_t enableInts[4]  = {                 DHCSR_C_HALT|DHCSR_C_DEBUGEN,0x00,0x5F,0xA0};

   if (disableInterrupts) {
      bdmInterface->writeMemory(MS_Long, 4, DHCSR, disableInts);
   }
   else {
      bdmInterface->writeMemory(MS_Long, 4, DHCSR, enableInts);
   }
   // For debug checking
//   uint8_t temp[4];
//   bdmInterface->writeMemory(MS_Long, 4, DHCSR, temp);
}

static const char defaultTargetRegsXML[] =
      "<?xml version=\"1.0\"?>\n"
      "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
      "<feature name=\"org.gnu.gdb.arm.m-profile\" >\n"
      "   <struct id=\"misc.type\">\n"
      "      <field name=\"primask\"   type = \"uint8\"    />\n"
      "      <field name=\"basepri\"   type = \"uint8\"    />\n"
      "      <field name=\"faultmask\" type = \"uint8\"    />\n"
      "      <field name=\"control\"   type = \"uint8\"    />\n"
      "   </struct>\n"
      "   <reg name=\"r0\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r1\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r2\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r3\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r4\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r5\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r6\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r7\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r8\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r9\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r10\"  bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r11\"  bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"r12\"  bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"sp\"   bitsize=\"32\" type=\"data_ptr\" group=\"general\" />\n"
      "   <reg name=\"lr\"   bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"pc\"   bitsize=\"32\" type=\"code_ptr\" group=\"general\" />\n"
      "   <reg name=\"xpsr\" bitsize=\"32\" type=\"uint32\"   group=\"general\" />\n"
      "   <reg name=\"msp\"  bitsize=\"32\" type=\"data_ptr\" group=\"general\" />\n"
      "   <reg name=\"psp\"  bitsize=\"32\" type=\"data_ptr\" group=\"general\" />\n"
      "   <reg name=\"misc\" bitsize=\"32\" type=\"misc.type\" group=\"general\" />\n"
      "   \n"
      "</feature>\n";

// Maps GDB register numbers to USBDM register numbers (or -1 if invalid)
static int registerMap[] = {
      ARM_RegR0,   ARM_RegR1,   ARM_RegR2,  ARM_RegR3,
      ARM_RegR4,   ARM_RegR5,   ARM_RegR6,  ARM_RegR7,
      ARM_RegR8,   ARM_RegR9,   ARM_RegR10, ARM_RegR11,
      ARM_RegR12,  ARM_RegSP,   ARM_RegLR,  ARM_RegPC, // r0-r12,sp,lr,pc
      ARM_RegxPSR, ARM_RegMSP,  ARM_RegPSP,            // psr, main sp, process sp
      ARM_RegMISC,   // [31:24]=CONTROL,[23:16]=FAULTMASK,[15:8]=BASEPRI,[7:0]=PRIMASK.
      ARM_RegFPSCR,
      ARM_RegFPS0+0x00, ARM_RegFPS0+0x01, ARM_RegFPS0+0x02, ARM_RegFPS0+0x03,
      ARM_RegFPS0+0x04, ARM_RegFPS0+0x05, ARM_RegFPS0+0x06, ARM_RegFPS0+0x07,
      ARM_RegFPS0+0x08, ARM_RegFPS0+0x09, ARM_RegFPS0+0x0A, ARM_RegFPS0+0x0B,
      ARM_RegFPS0+0x0C, ARM_RegFPS0+0x0D, ARM_RegFPS0+0x0E, ARM_RegFPS0+0x0F,
      ARM_RegFPS0+0x10, ARM_RegFPS0+0x11, ARM_RegFPS0+0x12, ARM_RegFPS0+0x13,
      ARM_RegFPS0+0x14, ARM_RegFPS0+0x15, ARM_RegFPS0+0x16, ARM_RegFPS0+0x17,
      ARM_RegFPS0+0x18, ARM_RegFPS0+0x19, ARM_RegFPS0+0x1A, ARM_RegFPS0+0x1B,
      ARM_RegFPS0+0x1C, ARM_RegFPS0+0x1D, ARM_RegFPS0+0x1E, ARM_RegFPS0+0x1F,
};

/**  Sets up the register description from device XML
 *   or hard-coded default
 */
bool GdbHandler_ARM::initRegisterDescription(void) {
   LOGGING_E;

   if (GdbHandlerCommon::initRegisterDescription()) {
      return true;
   }
   reportGdbPrintf("Using default register description\n");
   strcpy(targetRegsXML, defaultTargetRegsXML);
   targetRegsXMLSize  = sizeof(defaultTargetRegsXML);
   targetLastRegIndex = (sizeof(registerMap)/sizeof(registerMap[0]))-1;

   return true;
}

/**
 * Indicates if regNo identifies a valid target register
 *
 * @param regNo   GDB register number (index)
 *
 * @return true  => Valid register index
 * @return false => Invalid register index
 */
bool GdbHandler_ARM::isValidRegister(unsigned regNo) {
   if (regNo >= sizeof(registerMap)/sizeof(registerMap[0])) {
      return false;
   }
   return registerMap[regNo]>=0;
}

/**
 *  Read register into string buffer as hex chars
 *
 *  @param regNo    - number of register to read (GDB numbering)
 *  @param buffPtr  - reference to pointer to buffer
 *
 *  @return Error code
 *
 *  @note The pointer is incremented by size of register
 *  @note Bytes are written to buffer in target byte order
 */
USBDM_ErrorCode GdbHandler_ARM::readReg(unsigned regNo, uint8_t *&buffPtr) {
   LOGGING_Q;
   unsigned long regValue;

   if (!isValidRegister(regNo)) {
      log.print("reg[%d] => Invalid GDB register number\n", regNo);
      reportGdbPrintf(GdbHandler::M_ERROR, BDM_RC_ILLEGAL_PARAMS, "Invalid GDB register number. ");
      memset(buffPtr, 0x00, 4);
      return BDM_RC_ILLEGAL_PARAMS;
   }
   int usbdmRegNo = registerMap[regNo];

   USBDM_ErrorCode rc;
   rc = bdmInterface->readReg((ARM_Registers_t)usbdmRegNo, &regValue);
   log.print("%s(0x%02X) => %08lX\n", getARMRegName(usbdmRegNo), usbdmRegNo, regValue);
   if (rc == BDM_RC_TARGET_BUSY) {
      // Special case - target running so regs can't be read
      // Return dummy information so GDB doesn't abort
      log.print("Register read(%d) failed, reason = %s\n", regNo, bdmInterface->getErrorString(rc));
      reportGdbPrintf(GdbHandler::M_WARN, rc, "Register read failed - ignored. ");
      regValue = 0;
      rc = BDM_RC_OK;
   }
   else if (rc != BDM_RC_OK) {
      log.print("Register read(%d) failed, reason = %s\n", regNo, bdmInterface->getErrorString(rc));
      reportGdbPrintf(GdbHandler::M_ERROR, rc, "Register read failed. ");
      regValue = 0;
   }
   encodeTarget32Bits(regValue, buffPtr);
   buffPtr += 4;
   return rc;
}

/**
 *  Get cached value of register from cache
 *  Note: Assumes cache valid
 *
 *  @param reg Register number
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_ARM::getCachedRegister(ARM_Registers_t reg) {
   if (registerBufferSize == 0) {
      readRegs();
   }
   return get32bitLE((registerBuffer+(4*reg)));
}

void GdbHandler_ARM::debug_print_regs() {
   static const char *regNames[] = {
         "R0",
         "R1",
         "R2",
         "R3",
         "R4",
         "R5",
         "R6",
         "R7",
         "R8",
         "R9",
         "R10",
         "R11",
         "R12",
         "SP",
         "LR",
         "PC",
         "xPSR",
         "MSP",
         "PSP",
         "???",
         "MISC",
   };
   for (int reg=ARM_RegR0; reg<=ARM_RegMISC; reg++) {
      reportGdbPrintf(M_INFO, "%-10s = 0x%08X\n", regNames[reg], getCachedRegister((ARM_Registers_t)reg));
   }
}

/**
 *  Get cached value of PC
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_ARM::getCachedPC() {
   return getCachedRegister(ARM_RegPC);
}

/**
 * Get register values of important registers for stop reporting etc.
 *
 * @return Static string describing values.
 */
const char *GdbHandler_ARM::getImportantRegisters() {
   if (registerBufferSize == 0) {
      readRegs();
   }
   static char buff[100];
   char *cPtr = buff;
   static const ARM_Registers_t regsToReport[] = {ARM_RegPC, ARM_RegSP, ARM_RegLR};
   for (unsigned index=0; index<(sizeof(regsToReport)/sizeof(regsToReport[0])); index++) {
      cPtr += sprintf(cPtr, "%02X:%08X", regsToReport[index], targetToBE32(getCachedRegister(regsToReport[index])));
      *cPtr++ = ';';
   }
   return buff;
}

/**
 * Configure the MDM_AP register for Kinetis targets
 *
 * @param resume Modifies mdm_ap_control bits that would stop the target
 *
 * @return Error code
 */
USBDM_ErrorCode GdbHandler_ARM::configureKinetisMDM_AP(bool resume) {

   LOGGING_F;
   USBDM_ErrorCode rc = BDM_RC_OK;

   log.error("Resume = %s\n", resume?"true":"false");

   if (isKinetisDevice) {
      unsigned long mdm_ap_control;
      unsigned long mdm_ap_status;

      bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
      bdmInterface->readCReg(ARM_CRegMDM_AP_Status,  &mdm_ap_status);

      log.error("E:mdm_ap_status  = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
      log.error("E:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

      // Set stop on VLLSx reset
      // MDM_AP_CONTROL.VLLSx flag sets and core halts
      log.error("Activating MDM_AP_Control_VLLDBGREQ\n");
      reportGdbPrintf(M_BORINGINFO, "Activating MDM_AP_Control_VLLDBGREQ\n");

      // Request Hold in reset after VLLSx exit (reset)
      uint32_t clearFlags = MDM_AP_Control_VLLDBGACK|MDM_AP_Control_LLS_VLLSx_Ack;
      uint32_t baseValue  = MDM_AP_Control_VLLDBGREQ;

      // Whether to continue afterwards
      clearFlags |= resume?0:MDM_AP_Control_Debug_Request;

      log.error("mdm_ap_control <= %s(0x%08X)\n", getMDM_APControlName(clearFlags), clearFlags);
      rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, baseValue|clearFlags);
      log.error("mdm_ap_control <= %s(0x%08X)\n", getMDM_APControlName(baseValue), baseValue);
      rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, baseValue);

      bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
      bdmInterface->readCReg(ARM_CRegMDM_AP_Status,  &mdm_ap_status);

      log.error("F:mdm_ap_status  = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
      log.error("F:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);
   }
   return rc;
}

/**
 * Write to target register
 *
 * @param regNo     - number of register to read (GDB numbering)
 * @param regValue  - value to write
 */
void GdbHandler_ARM::writeReg(unsigned regNo, unsigned long regValue) {
   LOGGING;
   if (!isValidRegister(regNo))
      return;
   int usbdmRegNo = registerMap[regNo];

   bdmInterface->writeReg((ARM_Registers_t)usbdmRegNo, regValue);
   log.print("%s(0x%02X) <= %08lX\n", getARMRegName(usbdmRegNo), usbdmRegNo, regValue);
}

/**
 *  Reads a word from ARM target memory
 *
 *  @param address  - 32-bit address (aligned)
 *  @param data     - pointer to buffer for word
 *
 *  @return error code
 */
USBDM_ErrorCode GdbHandler_ARM::armReadMemoryWord(uint32_t address, uint32_t &data) {
   LOGGING_Q;
   uint8_t buff[4];
   USBDM_ErrorCode rc = bdmInterface->readMemory(4, 4, address, buff);
   data = (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
   switch(address) {
   case DEMCR:
      log.print("DEMCR => %s)\n", getDEMCRName(data));
      break;
   case DHCSR:
      log.print("DHCSR => %s)\n", getDHCSRName(data));
      break;
   default: break;
   }
   return rc;
}

/**
 * Halt target
 * May use Kinetis specific method
 *
 * @return
 */
USBDM_ErrorCode GdbHandler_ARM::haltTarget() {
   LOGGING;

   USBDM_ErrorCode   rc;

   // Read status for debugging
   auto readStatus = [&log, this] () {
      log.print("readStatus\n");
      // Read status (for debug)

      unsigned long  mdm_ap_status;
      USBDM_ErrorCode rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
      if (rc != BDM_RC_OK) {
         log.print("Failed to read mdm_ap_status, rc = %s(%d)\n", bdmInterface->getErrorString(rc), rc);
      }
      else {
         log.print("mdm_ap_status - %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
      }
   };

   // Try ARM debug halt method
   rc = bdmInterface->halt();
   if (rc != BDM_RC_OK) {
      log.print("Failed to halt target, rc = %s(%d)\n", bdmInterface->getErrorString(rc), rc);

      if (bdmInterface->connect() != BDM_RC_OK) {
         log.print("Re-connect failed\n");
      }
      else {
         log.print("Re-connect OK\n");
      }
      rc = bdmInterface->halt();
   }

   if ((rc != BDM_RC_OK) && isKinetisDevice) {
      // Use Kinetis specific debug (halt) method

      log.print("Halt failed, asserting MDM_AP_Control_Debug_Request\n");
      unsigned long  mdm_ap_control;

      do {
         readStatus();
         rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         if (rc != BDM_RC_OK) {
            break;
         }
         log.print("Original mdm_ap_control - %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);
         mdm_ap_control &= ~(MDM_AP_Control_Debug_Request|MDM_AP_Control_VLLDBGACK);

         rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, mdm_ap_control|MDM_AP_Control_Debug_Request);
         if (rc != BDM_RC_OK) {
            break;
         }
         // Release Kinetis specific debug (halt) method
         rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, mdm_ap_control);
         if (rc != BDM_RC_OK) {
            break;
         }
      } while (false);
      if (rc != BDM_RC_OK) {
         log.print("Target access failed, rc = %s(%d)\n", bdmInterface->getErrorString(rc), rc);
      }
      readStatus();
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed to halt target, rc = %s(%d)\n", bdmInterface->getErrorString(rc), rc);
      reportGdbPrintf(M_ERROR, "Failed to halt target - %s\n", bdmInterface->getErrorString(rc));
   }
   return rc;
}

/**
 * Get run state by polling target\n
 * Will attempt simple re-connect if necessary
 *
 * @return Status of target T_HALT, T_RUNNING etc
 *
 * @return T_NOCONNECTION Unable to connect to target - may be in LLSx or VLLSx.
 * @return T_RUNNING      Currently executing
 * @return T_HALT         Currently in debug halt
 * @return T_RESET        Currently in reset
 * @return T_WAIT         Currently in sleep (WAIT)
 * @return T_STOP         Currently in deep-sleep (STOP)
 * @return T_VLPR         Currently in low-power run (VLPR)
 * @return T_VLPW         Currently in low power sleep (VLPW)
 * @return T_VLPS         Currently in low power deep-sleep (VLPS)
 * @return T_LLSxEXIT     Running - Exited LLSx state
 * @return T_VLLSxEXIT    Running - Exited VLLSx state
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::getTargetStatus() {
   LOGGING;
   struct mdm_ap_control_t {
      union {
         uint32_t value;
         struct {
            /*  0 */ unsigned flash_erase:1;
            /*  1 */ unsigned debug_disable:1;
            /*  2 */ unsigned debug_req:1;
            /*  3 */ unsigned reset_req:1;
            /*  4 */ unsigned core_hold_reset:1;
            /*  5 */ unsigned vlls_debug_req:1;
            /*  6 */ unsigned vlls_debug_ack:1;
            /*  7 */ unsigned lls_vlls_stat_ack:1;
         };
      };
   };

   struct  mdm_ap_status_t {
      union {
         uint32_t value;
         struct {
            /*  0 */ unsigned mass_erase_ack:1;
            /*  1 */ unsigned flash_ready:1;
            /*  2 */ unsigned sys_security:1;
            /*  3 */ unsigned sys_reset_n:1;
            /*  4 */ unsigned :1;
            /*  5 */ unsigned mass_erase_en:1;
            /*  6 */ unsigned backdoor_en:1;
            /*  7 */ unsigned lp_enable:1;
            /*  8 */ unsigned very_low_power_mode:1;
            /*  9 */ unsigned lls_exit:1;
            /* 10 */ unsigned vllsx_exit:1;
            /* 11 */ unsigned :1;
            /* 12 */ unsigned :1;
            /* 13 */ unsigned :1;
            /* 14 */ unsigned :1;
            /* 15 */ unsigned :1;
            /* 16 */ unsigned halted:1;
            /* 17 */ unsigned sleepdeep:1;
            /* 18 */ unsigned sleep:1;
         };
      };
   };

   static GdbTargetStatus  lastStatus = GdbTargetStatus_NOCONNECTION;
   GdbTargetStatus         status     = GdbTargetStatus_NOCONNECTION;

   USBDM_ErrorCode         rc = BDM_RC_OK;
   do {
      if (isKinetisDevice) {
         /**
          *  Use Kinetis MDM_AP
          */
         unsigned long mdm_ap_status;
         rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         if (rc != BDM_RC_OK) {
            log.error("Failed MDM_AP_Status read - No connection\n");
            status = GdbTargetStatus_NOCONNECTION;
            break;
         }

         unsigned long mdm_ap_control;
         rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);

//         if (rc != BDM_RC_OK) {
//            log.print("Failed MDM_AP_Status read - Doing autoReconnect\n");
//            if (bdmInterface->connect() != BDM_RC_OK) {
//               log.print("Re-connect failed\n");
//            }
//            else {
//               log.print("Re-connect OK\n");
//               // retry after connect
//               rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
//            }
//         }
         if (rc != BDM_RC_OK) {
            log.error("Failed ARM_CRegMDM_AP_Control read - No connection\n");
            status = GdbTargetStatus_NOCONNECTION;
            break;
         }
         if (mdm_ap_status == 0) {
            // This seems to occur after VLLSx exit
            bdmInterface->connect();
            if (rc != BDM_RC_OK) {
               log.error("Failed Connect with mdm_ap_status == 0\n");
               status = GdbTargetStatus_NOCONNECTION;
               break;
            }
         }
         log.print("mdm_ap_status  - %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status),   mdm_ap_status);
         log.print("mdm_ap_control - %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         // For debugger
//         volatile mdm_ap_status_t  mdm_ap_status_x;
//         volatile mdm_ap_control_t mdm_ap_control_x;
//         mdm_ap_status_x.value  = mdm_ap_status;
//         mdm_ap_control_x.value = mdm_ap_control;

         if (mdm_ap_status&MDM_AP_Status_VLLSx_Mode_Exit) {
            // Target is being held in reset until mdm-ap_control.VLLDBGACK is written
            // Debug hardware loses state!
            // Sticky bit cleared by mdm-ap_control.LLS_VLLSx_Ack
            status =  GdbTargetStatus_VLLSxEXIT;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_LLS_Mode_Exit) {
            // Target has exited LLSx mode and is executing
            // Debug hardware keeps state from before LLS entry
            // Sticky bit cleared by mdm-ap_control.LLS_VLLSx_Ack
            status =  GdbTargetStatus_LLSxEXIT;
            break;
         }
         if ((mdm_ap_status&MDM_AP_Status_Core_Halted) || (mdm_ap_control&MDM_AP_Control_Debug_Request))  {
            // Target is halted
            status =  GdbTargetStatus_HALT;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_Core_SLEEPDEEP) {
            // Target is halted in STOP/VLPS mode
            // Interprets STOP with LP_Enable as Pseudo-VLPS when in debug mode
            // See Reference manual MDM-AP Status description
            status = (mdm_ap_status&(MDM_AP_Status_VLP_Mode|MDM_AP_Status_LP_Enable))?GdbTargetStatus_VLPS:GdbTargetStatus_STOP;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_Core_SLEEPING) {
            // Target is halted in WAIT/VLPW mode
            status = (mdm_ap_status&MDM_AP_Status_VLP_Mode)?GdbTargetStatus_VLPW:GdbTargetStatus_WAIT;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_VLP_Mode) {
            // Target is halted in VLPR mode
            status = GdbTargetStatus_VLPR;
            break;
         }
         if ((mdm_ap_status&MDM_AP_Status_System_Reset) == 0) {
            // Target is currently in RESET state
            status =  GdbTargetStatus_RESET;
            break;
         }
         status =  GdbTargetStatus_RUNNING;
         break;
      }

      uint32_t dhcsr;
      USBDM_ErrorCode rc = armReadMemoryWord(DHCSR, dhcsr);
      log.print("dhcsr = 0x%08u\n", dhcsr);
      if (rc != BDM_RC_OK) {
         log.error("Doing autoReconnect\n");
         if (bdmInterface->connect() != BDM_RC_OK) {
            log.error("Re-connect failed\n");
         }
         else {
            log.print("Re-connect OK\n");
            // retry after connect
            rc = armReadMemoryWord(DHCSR, dhcsr);
         }
      }
      if (rc != BDM_RC_OK) {
         status = GdbTargetStatus_NOCONNECTION;
         break;
      }
      if ((dhcsr & DHCSR_S_SLEEP) != 0) {
         status = GdbTargetStatus_WAIT;
         break;
      }
      if ((dhcsr & (DHCSR_S_HALT|DHCSR_S_LOCKUP)) != 0) {
         status = GdbTargetStatus_HALT;
         break;
      }
      status = GdbTargetStatus_RUNNING;
      break;
   } while (0);

   if (status != lastStatus) {
      log.error("Status changed => %s\n", getStatusName(status));
      lastStatus = status;
   }
   return status;
}

//#define REPORT_LONG_LOCATION

//void GdbHandler_ARM::reportThreadLocation(int signal, int threadID, const char* stopReason) {
//   LOGGING_Q;
//   char buff[100];
//   char *cPtr = buff;
//
//   cPtr += sprintf(buff, "T%2.2X", signal);
//   if (stopReason != nullptr) {
//      cPtr += sprintf(cPtr, "thread:%d;%s:0", threadID, stopReason);
//   }
//#if defined(REPORT_LONG_LOCATION)
//   static const int regsToReport[] = {15, 14, 13, 16}; // PC, LR, SP, PSR
//   for (unsigned index=0; index<(sizeof(regsToReport)/sizeof(regsToReport[0])); index++) {
//      cPtr += sprintf(cPtr, "%X:", regsToReport[index]);
//      cPtr += readReg(regsToReport[index], cPtr);
//      *cPtr++ = ';';
//   }
//#endif
//   *cPtr++ = '\0';
//   gdbInOut->sendGdbString(buff);
//}
//
///**
// *
// * @param mode          Indicates the reply mode e.g. S T etc
// * @param signal        Signal value e.g. TARGET_SIGNAL_TRAP TARGET_SIGNAL_INT
// * @param stopReason    Optional Reason for stop if T=TARGET_SIGNAL_TRAP
// */
//void GdbHandler_ARM::reportLocation(char mode, int signal, const char* stopReason) {
//   LOGGING_Q;
//   char buff[100];
//   char *cPtr = buff;
//
//   cPtr += sprintf(buff, "%c%2.2X", mode, signal);
//   if (stopReason != nullptr) {
//      cPtr += sprintf(cPtr, "%s:0", stopReason);
//   }
//#if defined(REPORT_LONG_LOCATION)
//   static const int regsToReport[] = {15, 14, 13, 16}; // PC, LR, SP, PSR
//   for (unsigned index=0; index<(sizeof(regsToReport)/sizeof(regsToReport[0])); index++) {
//      cPtr += sprintf(cPtr, "%X:", regsToReport[index]);
//      cPtr += readReg(regsToReport[index], cPtr);
//      *cPtr++ = ';';
//   }
//#endif
//   *cPtr++ = '\0';
//   gdbInOut->sendGdbString(buff);
//}

#define SEMI_HOSTING_OPCODE      (0xBEAB)

#define SEMI_HOSTED_CLOSE        (0x02)
#define SEMI_HOSTED_CLOCK        (0x10)
#define SEMI_HOSTED_ELAPSED      (0x30)
#define SEMI_HOSTED_ERRNO        (0x13)
#define SEMI_HOSTED_FLEN         (0x0C)
#define SEMI_HOSTED_GET_CMDLINE  (0x15)
#define SEMI_HOSTED_HEAPINFO     (0x16)
#define SEMI_HOSTED_ISERROR      (0x08)
#define SEMI_HOSTED_ISTTY        (0x09)
#define SEMI_HOSTED_OPEN         (0x01)
#define SEMI_HOSTED_READ         (0x06)
#define SEMI_HOSTED_READC        (0x07)
#define SEMI_HOSTED_REMOVE       (0x0E)
#define SEMI_HOSTED_RENAME       (0x0F)
#define SEMI_HOSTED_SEEK         (0x0A)
#define SEMI_HOSTED_SYSTEM       (0x12)
#define SEMI_HOSTED_TICKFREQ     (0x31)
#define SEMI_HOSTED_TIME         (0x11)
#define SEMI_HOSTED_TMPNAM       (0x0D)
#define SEMI_HOSTED_WRITE        (0x05)
#define SEMI_HOSTED_WRITEC       (0x03)
#define SEMI_HOSTED_WRITE0       (0x04)

struct HeapInfoBlock {
    uint32_t heap_base;
    uint32_t heap_limit;
    uint32_t stack_base;
    uint32_t stack_limit;
};
HeapInfoBlock heapInfo = {0};

struct OpenInfoBlock {
   uint32_t name;
   uint32_t mode;
   uint32_t length;
};
OpenInfoBlock openInfoBlock = {0};

struct ReadInfoBlock {
   uint32_t handle;
   uint32_t dataPtr;
   uint32_t length;
};
ReadInfoBlock readInfoBlock = {0};

struct WriteInfoBlock {
   uint32_t handle;
   uint32_t dataPtr;
   uint32_t length;
};
WriteInfoBlock writeInfoBlock = {0};

struct IsTtyInfoBlock {
   uint32_t handle;
};
IsTtyInfoBlock isTtyInfoBlock = {0};

struct CloseInfoBlock {
   uint32_t handle;
};
CloseInfoBlock closeInfoBlock = {0};

static uint32_t semiHostingErrno = 0;

/**
 * Checks if target at a semi-hosting break
 */
bool GdbHandler_ARM::checkHostedBreak(uint32_t currentPC) {
   LOGGING_Q;
   uint16_t opcode;
   if (bdmInterface->readMemory(MS_Word, 2, currentPC, (uint8_t *)&opcode) != BDM_RC_OK) {
      return false;
   }
   bool atHostedBreak = (targetToFromNative16(opcode) == SEMI_HOSTING_OPCODE);
   if (atHostedBreak) {
      log.print("detected\n");
   }
   return atHostedBreak;
}

/**
 * Handles target halted due to semi-hosting break
 * May quietly continue target
 *
 * @return T_HALT          on error or no action
 *         T_RUNNING       if restarted
 *         GdbTargetStatus_USER_INPUT    if halted waiting for user input
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::handleHostedBreak() {
   LOGGING_Q;
   unsigned long pc,r0,r1;
   time_t theTime;

   if (forceTargetHalt) {
      // Change to halt
      return GdbTargetStatus_HALT;
   }
   if (readPC(&pc) != BDM_RC_OK) {
      return GdbTargetStatus_HALT;
   }
   if (readR0(&r0) != BDM_RC_OK) {
      return GdbTargetStatus_HALT;
   }
   if (readR1(&r1) != BDM_RC_OK) {
      return GdbTargetStatus_HALT;
   }
   log.print("pc=0x%08lX, r0=0x%08lX, r1=0x%08lX\n", pc, r0, r1);

   if (runState != RunState_Running) {
      // Only check for Hosted break when actually halting
      log.print("Ignored as not running\n");
      return GdbTargetStatus_HALT;
   }
   // Default to Halted
   GdbTargetStatus targetStatus = GdbTargetStatus_HALT;

   bool adjustPCandContinue = false;
   char commandBuff[2000];
   uint32_t buffLength;
   char *p;
   bool success;
   int handle = -1;
   unsigned long ch;
   int len;

   switch(r0) {
   case SEMI_HOSTED_HEAPINFO:
      log.print("Semi-hosting heapInfo\n");
      reportGdbPrintf(M_INFO, "Semi-hosting heapInfo\n");
      bdmInterface->readMemory(MS_Byte, sizeof(heapInfo), r1, (uint8_t *)&heapInfo);
      log.print("heap[0x%08X-0x%08X], stack[0x%08X-0x%08X]\n",
            heapInfo.heap_base, heapInfo.heap_limit,
            heapInfo.stack_base, heapInfo.stack_limit);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_OPEN:
      log.print("Semi-hosting open\n");
      reportGdbPrintf(M_INFO, "Semi-hosting open\n");
      bdmInterface->readMemory(MS_Byte, sizeof(openInfoBlock), r1, (uint8_t *)&openInfoBlock);
      len = openInfoBlock.length+1;
      if (len>(int)sizeof(commandBuff)) {
         len = (int)sizeof(commandBuff);
      }
      bdmInterface->readMemory(MS_Byte, len, openInfoBlock.name, (uint8_t *)commandBuff);
      log.print("name=%s, mode=0x%08X\n", commandBuff, openInfoBlock.mode);
      // Only accept 'tt' => tty
      if (strcmp(commandBuff, ":tt") == 0) {
         if (openInfoBlock.mode < 4) {
            // Read mode - stdin
            success = tty->openInput();
            handle = IGdbTty::STD_IN;
         }
         else {
            // Write mode - stdout, errout
            if (!tty->isOutputOpen()) {
               success = tty->openOutput();
               handle = IGdbTty::STD_OUT;
            }
            else {
               success = tty->openError();
               handle = IGdbTty::STD_ERR;
            }
         }
         if (!success) {
            semiHostingErrno = EIO;
            bdmInterface->writeReg(ARM_RegR0, -1);
            reportGdbPrintf(M_ERROR, "Semi-hosting open - error opening \'tt\'\n");
         }
         else {
            bdmInterface->writeReg(ARM_RegR0, handle);
         }
      }
      else {
         semiHostingErrno = EINVAL;
         bdmInterface->writeReg(ARM_RegR0, -1);
         reportGdbPrintf(M_ERROR, "Semi-hosting open - error, Illegal device \'%s\'\n", commandBuff);
      }
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_CLOSE:
      log.print("Semi-hosting close %ld\n", r0);
      reportGdbPrintf(M_INFO, "Semi-hosting close %d\n", r0);
      bdmInterface->readMemory(MS_Byte, sizeof(closeInfoBlock), r1, (uint8_t *)&closeInfoBlock);
      switch (closeInfoBlock.handle) {
      case IGdbTty::STD_IN:
         tty->closeInput();
         break;
      case IGdbTty::STD_OUT:
         tty->closeOutput();
         break;
      case IGdbTty::STD_ERR:
         tty->closeError();
         break;
      }
      bdmInterface->writeReg(ARM_RegR0, 0);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_READC:
      log.print("Semi-hosting readc\n");
      reportGdbPrintf(M_INFO, "Semi-hosting readc\n");
      bdmInterface->writeReg(ARM_RegR0, tty->getChar());
      adjustPCandContinue = true;
//      targetStatus = GdbTargetStatus_USER_INPUT;
//      runState = UserInput;
      break;

   case SEMI_HOSTED_READ:
      log.print("Semi-hosting read\n");
      reportGdbPrintf(M_INFO, "Semi-hosting read\n");
      bdmInterface->readMemory(MS_Byte, sizeof(readInfoBlock), r1, (uint8_t *)&readInfoBlock);
      log.print("handle=%d, data=0x%08X, length=%d\n", readInfoBlock.handle, readInfoBlock.dataPtr, readInfoBlock.length);
      switch (readInfoBlock.handle) {
      case IGdbTty::STD_IN:
         len = tty->gets(commandBuff, readInfoBlock.length);
         break;
      case IGdbTty::STD_OUT:
      case IGdbTty::STD_ERR:
      default:
         len = EOF;
         break;
      }
      buffLength = readInfoBlock.length;
      if (len==EOF) {
         // Indicates EOF
         len = readInfoBlock.length;
      }
      // Indicates EOF
      bdmInterface->writeReg(ARM_RegR0, len);
//      adjustPCandContinue = false;
//      targetStatus = GdbTargetStatus_USER_INPUT;
//      runState = UserInput;
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_WRITEC:
      log.print("Semi-hosting writec\n");
      reportGdbPrintf(M_INFO, "Semi-hosting writec\n");
      bdmInterface->readReg(ARM_RegR0, &ch);
      tty->putChar(ch);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_WRITE:
      log.print("Semi-hosting write\n");
      reportGdbPrintf(M_INFO, "Semi-hosting write\n");
      bdmInterface->readMemory(MS_Byte, sizeof(writeInfoBlock), r1, (uint8_t *)&writeInfoBlock);
      log.print("handle=%d, data=0x%08X, length=%d\n", writeInfoBlock.handle, writeInfoBlock.dataPtr, writeInfoBlock.length);
      switch (writeInfoBlock.handle) {
      default:
      case IGdbTty::STD_IN:
         log.print("Semi-hosting write - wrong handle\n");
         success = false;
         break;
      case IGdbTty::STD_OUT:
      case IGdbTty::STD_ERR:
         success = true;
         buffLength = writeInfoBlock.length;
         if (buffLength>sizeof(commandBuff)) {
            buffLength = sizeof(commandBuff);
         }
         bdmInterface->readMemory(MS_Byte, buffLength, writeInfoBlock.dataPtr, (uint8_t *)commandBuff);
         commandBuff[buffLength] = '\0';
         tty->puts(commandBuff);
         log.print("Semi-hosting write - %s\n", commandBuff);
         break;
      }
      bdmInterface->writeReg(ARM_RegR0, success?0:-1);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_WRITE0:
      log.print("Semi-hosting write0\n");
      reportGdbPrintf(M_INFO, "Semi-hosting write0\n");
      p = commandBuff;
      do {
         // Read message a few bytes at a time to help prevent overrun without
         // being horribly inefficient
         char buff[22];
         bdmInterface->readMemory(MS_Byte, sizeof(buff)-1, r1, (uint8_t *)buff);
         buff[sizeof(buff)-1] = '\0';
         strcat(p, buff);
         int len = strlen(buff);
         p += len;
         if ((len == 0) || (p >= (commandBuff+sizeof(commandBuff)))) {
            break;
         }
      } while (1);
      *p = '\0';
      tty->puts(commandBuff);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_GET_CMDLINE:
      log.print("Semi-hosting get_cmdline\n");
      reportGdbPrintf(M_INFO, "Semi-hosting get_cmdline\n");
      bdmInterface->readMemory(MS_Byte, sizeof(isTtyInfoBlock), r1, (uint8_t *)&isTtyInfoBlock);
      // Just assume TTY
      bdmInterface->writeReg(ARM_RegR0, 1);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_ISTTY:
      log.print("Semi-hosting is_tty\n");
      reportGdbPrintf(M_INFO, "Semi-hosting is_tty\n");
      switch (r1) {
      case IGdbTty::STD_IN:
      case IGdbTty::STD_OUT:
      case IGdbTty::STD_ERR:
         success = true;
         break;
      default:
         success = false;
         break;
      }
      bdmInterface->writeReg(ARM_RegR0, success?1:0);
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_ERRNO:
      log.print("Semi-hosting errno %d\n", semiHostingErrno);
      reportGdbPrintf(M_INFO, "Semi-hosting errno %d\n", semiHostingErrno);
      bdmInterface->writeReg(ARM_RegR0, semiHostingErrno);
      semiHostingErrno = 0;
      adjustPCandContinue = true;
      break;

   case SEMI_HOSTED_TIME:
      log.print("Semi-hosting time\n\n");
      reportGdbPrintf(M_INFO, "Semi-hosting time\n");
      theTime = time(0);
      bdmInterface->writeReg(ARM_RegR0, (unsigned long)theTime);
      adjustPCandContinue = true;
      break;

   default:
      log.print("Semi-hosting ????\n");
      bdmInterface->writeReg(ARM_RegR0, -1);
      adjustPCandContinue = true;
      break;
   }
   if (adjustPCandContinue) {
      log.print("Adjusting PC and continuing \n");
      // Adjust PC past break
      writePC(pc+2);
      // Restart
      bdmInterface->go();
      runState = RunState_Running;
      return GdbTargetStatus_RUNNING;
   }
   else {
      log.print("Not restarting at hosted break \n");
   }
   return targetStatus;
}

/**
 * Handles target halted apart from semi-hosting break
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::handleHalted() {
   LOGGING;

   switch(runState) {
   case RunState_Halted :  // halted -> halted
      // Ignore
      break;
   case RunState_UserInput: // already halted for user input
      // Ignore
      return GdbTargetStatus_USER_INPUT;
   case RunState_Stepping : // stepping -> halted
      log.error("Target has halted (from stepping) @0x%08X\n", getCachedPC());
      reportGdbPrintf(M_BORINGINFO, "Target has halted (from %s) @0x%08X\n", getRunStateName(runState), getCachedPC());
      readRegs();
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = RunState_Halted;
      vStoppedAvailable = true;
      if (forceTargetHalt) {
         // Breaks stepping of empty loops
         reportHalt('T', TARGET_SIGNAL_INT);
         forceTargetHalt = false;
      }
      else {
         // Usual indication step has completed
         reportHalt('T', TARGET_SIGNAL_TRAP);
      }
      break;
   default:       // ???     -> halted
   case RunState_Running : // running -> halted
      log.error("Target has halted (from running) @0x%08X\n", getCachedPC());
      reportGdbPrintf(M_INFO, "Target has halted (from %s) @0x%08X\n", getRunStateName(runState), getCachedPC());
      readRegs();
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = RunState_Halted;
      vStoppedAvailable = true;
      if (atBreakpoint(getCachedPC())) {
         // Indicates breakpoint reached
         reportHalt('T', TARGET_SIGNAL_TRAP);
      }
      else {
         // Other reason for halt
         reportHalt('T', TARGET_SIGNAL_INT);
      }
      forceTargetHalt = false;
      break;
   }
   return GdbTargetStatus_HALT;
}

/**
 *   Check for change in target run state
 *   - Polls target
 *   - Report changes to GDB
 *   - Updates gdbTargetStatus (Global)
 *
 *   @return Target status
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::pollTarget(void) {
   LOGGING_Q;
   static int      unsuccessfulPollCount = 0;                    // Count of unsuccessful polls of the target
   static int      unsuccessfulHaltCount = 0;                    // Count of unsuccessful attempts to halt the target
   static bool     resetAttempted = false;                       // Set if reset already tried
   static int      recursed = 0;
   static RunState lastRunState = RunState::RunState_Halted;

   int         timeoutLimit   = getConnectionTimeout() * 10; // Scale to 100 ms ticks

   static GdbTargetStatus gdbTargetStatus = GdbTargetStatus::GdbTargetStatus_UNKNOWN;

   static constexpr int BREAK_TIMEOUT = 10; // 1 seconds

   if (recursed>0) {
      log.error("Recursed\n");
      return gdbTargetStatus;
   }
   recursed++;

   if (lastRunState != runState) {
      unsuccessfulPollCount = 0;
   }
   log.print("runState(on entry)       = %s, pollCount = %d\n", getRunStateName(runState), unsuccessfulPollCount);

   do {
      gdbTargetStatus = getTargetStatus();
      log.print("gdbTargetStatus(on poll) = %s\n", getStatusName(gdbTargetStatus));

      if (forceTargetHalt && (gdbTargetStatus != GdbTargetStatus_HALT)) {
         if (++unsuccessfulHaltCount<BREAK_TIMEOUT) {
            // Halt target again
            log.error("forceTargetHalt=T, gdbTargetStatus(on poll) = %s\n", getStatusName(gdbTargetStatus));
            log.error("Breaking - halting target (retry = %d)\n", unsuccessfulHaltCount);
            reportGdbPrintf(M_WARN, "Breaking - halting target\n");
            haltTarget();

            // Leave to next poll
            break;
         }
         // Give up trying to halt target - force reset
         log.error("Halting target unsuccessful - forcing reset\n");
         reportGdbPrintf(M_ERROR, "Halting target unsuccessful - forcing reset\n");
         unsuccessfulHaltCount = 0;
         forceTargetHalt       = false;
         resetAttempted        = false;
         resetTarget();

         // Check again in a while
         break;
      }

      if (gdbTargetStatus == GdbTargetStatus_NOCONNECTION) {
         if (resetAttempted) {
            log.error("Reset already attempted - giving up\n");
            // Already attempted reset - just give up
            break;
         }
         gdbTargetStatus = GdbTargetStatus_UNKNOWN;

         // Decide whether to reset target or continue waiting
         // This is necessary to support LLSx & VLLSx modes where communication is lost
         if (unsuccessfulPollCount < timeoutLimit) {
            // Still in timeout
            // Continue waiting
            unsuccessfulPollCount++;
            log.error("No connection - Still polling\n");
            break;
         }
         if (timeoutLimit == 0) {
            // No timeout
            // Continue waiting
            log.error("No connection - No timeout\n");
            break;
         }
         // Timeout exhausted
         reportGdbPrintf(M_ERROR, "Reseting target due to connection failure\n");
         log.error("Reseting target due to connection failure\n");
         resetTarget();
         resetAttempted = true;
         gdbTargetStatus = getTargetStatus();
         break;
      }
      resetAttempted        = false;
      unsuccessfulPollCount = 0;

      // At this point GdbTargetStatus_NOCONNECTION has been converted to GdbTargetStatus_UNKNOWN

      if (gdbTargetStatus == GdbTargetStatus_VLLSxEXIT) {
         log.error("VLLSx Exit detected\n");
         reportGdbPrintf(M_INFO, "VLLSx Exit detected\n");

         unsigned long mdm_ap_status;
         bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         log.error("1:mdm_ap_status = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
         unsigned long mdm_ap_control;
         bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         log.error("1:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         log.error("2:mdm_ap_status = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
         bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         log.error("2:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         // Re-establish breakpoints as lost on exit
         reportGdbPrintf(M_INFO, "Activating Breakpoints\n");
         notifyBreakpointsCleared();
         activateBreakpoints();

         bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         log.error("3:mdm_ap_status = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
         bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         log.error("3:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         // Configure VLLS exit capture and release from VLLS reset
         configureKinetisMDM_AP(!bdmInterface->isCatchVLLSx());

         bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         log.error("4:mdm_ap_status = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
         bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         log.error("4:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         log.error("5:mdm_ap_status = %s(0x%08lX)\n", getMDM_APStatusName(mdm_ap_status), mdm_ap_status);
         bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
         log.error("5:mdm_ap_control = %s(0x%08lX)\n", getMDM_APControlName(mdm_ap_control), mdm_ap_control);

         break;
      }
      if (gdbTargetStatus == GdbTargetStatus_LLSxEXIT) {
         log.print("LLSx Exit detected\n");
         reportGdbPrintf(M_INFO, "LLSx Exit detected\n");
         configureKinetisMDM_AP(true);
         break;
      }
      if (gdbTargetStatus == GdbTargetStatus_HALT) {
         // Check for semi-hosting
         unsigned long pc;
         readPC(&pc);
         if (checkHostedBreak(pc)) {
            gdbTargetStatus = handleHostedBreak();
         }
      }
      if (gdbTargetStatus == GdbTargetStatus_HALT) {
         gdbTargetStatus = handleHalted();
      }
      if (gdbTargetStatus == GdbTargetStatus_RUNNING) {
         runState = RunState_Running;
      }
   } while (false);

   if (lastRunState != runState) {
      log.error("gdbTargetStatus(on exit) = %s\n", getStatusName(gdbTargetStatus));
      log.error("runState(on exit)        = %s\n", getRunStateName(runState));
   }

   lastRunState = runState;

   recursed--;

   return gdbTargetStatus;
}

USBDM_ErrorCode GdbHandler_ARM::writePC(unsigned long value) {
   return bdmInterface->writeReg(ARM_RegPC, value);
}

USBDM_ErrorCode GdbHandler_ARM::readPC(unsigned long *value) {
   return bdmInterface->readReg(ARM_RegPC, value);
}

USBDM_ErrorCode GdbHandler_ARM::writeSP(unsigned long value) {
   return bdmInterface->writeReg(ARM_RegSP, value);
}

USBDM_ErrorCode GdbHandler_ARM::readR0(unsigned long *value) {
   return bdmInterface->readReg(ARM_RegR0, value);
}

USBDM_ErrorCode GdbHandler_ARM::readR1(unsigned long *value) {
   return bdmInterface->readReg(ARM_RegR1, value);
}

USBDM_ErrorCode GdbHandler_ARM::updateTarget() {
   return BDM_RC_OK;
}

bool GdbHandler_ARM::atMemoryBreakpoint() {
   return false;
}
