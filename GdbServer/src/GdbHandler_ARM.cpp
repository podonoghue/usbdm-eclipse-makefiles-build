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

GdbHandler *createARMGdbHandler(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbHandler::GdbCallback gdbCallBackPtr, IGdbTty *tty) {
   return new GdbHandler_ARM(gdbInOut, bdmInterface, deviceInterface, gdbCallBackPtr, tty);
}

GdbHandler_ARM::GdbHandler_ARM(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbCallback gdbCallBackPtr, IGdbTty *tty) :
   GdbHandlerCommon(T_ARM, gdbInOut, bdmInterface, deviceInterface, new GdbBreakpoints_ARM(bdmInterface), gdbCallBackPtr, tty) {
   isKinetisDevice = false;
}

GdbHandler_ARM::~GdbHandler_ARM() {
}

// Target is LE == Native
//=============================
/*
 * Convert 16-bit value Native <-> Target
 */
uint16_t GdbHandler_ARM::targetToNative16(uint16_t data) {
   return data;
}
/*
 * Convert 32-bit value Native <-> Target
 */
uint32_t GdbHandler_ARM::targetToNative32(uint32_t data) {
   return data;
}
/*
 * read 32-bit value from memory buffer in target format
 */
uint32_t GdbHandler_ARM::getTarget32Bits(uint8_t buff[], int offset) {
   uint32_t value = buff[offset] + (buff[offset+1]<<8) +(buff[offset+2]<<16) +(buff[offset+3]<<24);
   return targetToNative32(value);
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
   configureKinetisMDM_AP();

   return rc;
}

USBDM_ErrorCode GdbHandler_ARM::initialise() {
   LOGGING;

   USBDM_ErrorCode rc = GdbHandlerCommon::initialise();

   // Ignore Secured as may still be able to program device after mass-erase
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      return rc;
   }
   return configureMDM_AP();
}

USBDM_ErrorCode GdbHandler_ARM::resetTarget(TargetMode_t mode) {
   LOGGING;

   USBDM_ErrorCode rc = GdbHandlerCommon::resetTarget(mode);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   return configureKinetisMDM_AP();
}

USBDM_ErrorCode GdbHandler_ARM::continueTarget(void) {
   LOGGING_Q;

   configureKinetisMDM_AP();

   return GdbHandlerCommon::continueTarget();
}

/*! Mask/unmask interrupts (in DHCSR)
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

#define CACHED_PC_VALUE_OFFSET  (registerBuffer+(4*ARM_RegPC))
#define CACHED_R0_VALUE_OFFSET  (registerBuffer+(4*ARM_RegR0))
#define CACHED_R1_VALUE_OFFSET  (registerBuffer+(4*ARM_RegR1))

/*!  Sets up the register description from device XML
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

bool GdbHandler_ARM::isValidRegister(unsigned regNo) {
   if (regNo >= sizeof(registerMap)/sizeof(registerMap[0])) {
      return false;
   }
   return registerMap[regNo]>=0;
}

//! Read register into string buffer as hex chars
//!
//! @param regNo    - number of register to read (GDB numbering)
//! @param buffPtr  - reference to pointer to buffer
//!
//! @return Error code
//!
//! @note The pointer is incremented by size of register
//! @note Bytes are read in target byte order
//!
USBDM_ErrorCode GdbHandler_ARM::readReg(unsigned regNo, char *&buffPtr) {
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
   memcpy(buffPtr, &regValue, 4);
   buffPtr += 4;
   return rc;
}

/*
 *  Get cached value of PC
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_ARM::getCachedPC() {
   return get32bitLE(CACHED_PC_VALUE_OFFSET);
}

/*
 *  Get cached value of R0
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_ARM::getCachedR0() {
   return get32bitLE(CACHED_R0_VALUE_OFFSET);
}

/*
 *  Get cached value of R1
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_ARM::getCachedR1() {
   return get32bitLE(CACHED_R1_VALUE_OFFSET);
}

/**
 * Configure the MDM_AP register for Kinetis targets
 *
 * @return
 */
USBDM_ErrorCode GdbHandler_ARM::configureKinetisMDM_AP() {

   LOGGING_E;
   USBDM_ErrorCode rc = BDM_RC_OK;

   if (isKinetisDevice) {
      unsigned long mdm_ap_control;
      rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
      if (rc != BDM_RC_OK) {
         log.error("Reading MDM_AP_Control failed, rc=%s", bdmInterface->getErrorString(rc));
         return rc;
      }
      // Clear flags
      rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, mdm_ap_control|MDM_AP_Control_VLLDBGACK|MDM_AP_Control_Status_Ack);
      if (bdmInterface->isCatchVLLSx()) {
         // Set monitor LLS & VLLSx
         // LLS   - flag is set but execution continues
         // VLLSx - flag sets and core halts
         log.print("Activating MDM_AP_Control_VLLDBGREQ\n");
         rc = bdmInterface->writeCReg(ARM_CRegMDM_AP_Control, mdm_ap_control|MDM_AP_Control_VLLDBGREQ);
         if (rc != BDM_RC_OK) {
            log.error("Reading MDM_AP_Control failed, rc=%s", bdmInterface->getErrorString(rc));
            return rc;
         }
      }
   }
   return rc;
}

//! Write to target register
//!
//! @param regNo     - number of register to read (GDB numbering)
//! @param regValue  - value to write
//!
void GdbHandler_ARM::writeReg(unsigned regNo, unsigned long regValue) {
   LOGGING;
   if (!isValidRegister(regNo))
      return;
   int usbdmRegNo = registerMap[regNo];

   bdmInterface->writeReg((ARM_Registers_t)usbdmRegNo, regValue);
   log.print("%s(0x%02X) <= %08lX\n", getARMRegName(usbdmRegNo), usbdmRegNo, regValue);
   regValue = targetToBE32(regValue);
}

//! Reads a word from ARM target memory
//!
//! @param address  - 32-bit address (aligned)
//! @param data     - pointer to buffer for word
//!
//! @return error code
//!
USBDM_ErrorCode GdbHandler_ARM::armReadMemoryWord(unsigned long address, unsigned long *data) {
   LOGGING_Q;
   uint8_t buff[4];
   USBDM_ErrorCode rc = bdmInterface->readMemory(4, 4, address, buff);
   *data = (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
   switch(address) {
   case DEMCR:
      log.print("DEMCR => %s)\n", getDEMCRName(*data));
      break;
   case DHCSR:
      log.print("DHCSR => %s)\n", getDHCSRName(*data));
      break;
   default: break;
   }
   return rc;
}

//! Get run state by polling target
//!
//! @return status - status of target T_UNKNOWN/T_SLEEP/T_HALT/T_RUNNING
//!
GdbHandler::GdbTargetStatus GdbHandler_ARM::getTargetStatus() {
   LOGGING_Q;

   static GdbTargetStatus  lastStatus = T_UNKNOWN;
   GdbTargetStatus         status     = T_UNKNOWN;

   USBDM_ErrorCode         rc = BDM_RC_OK;

   do {
      if (isKinetisDevice) {
         unsigned long mdm_ap_status;
         rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
         if (rc != BDM_RC_OK) {
            log.print("Doing autoReconnect\n");
            if (bdmInterface->connect() != BDM_RC_OK) {
               log.print("Re-connect failed\n");
            }
            else {
               log.print("Re-connect OK\n");
               // retry after connect
               rc = bdmInterface->readCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
            }
         }
         if (rc != BDM_RC_OK) {
            status = T_NOCONNECTION;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_Core_Halted) {
            status =  T_HALT;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_VLLSx_Mode_Exit) {
            status =  T_VLLSxRESET;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_LLS_Mode_Exit) {
            status =  T_LLSxRESET;
            break;
         }
         if (mdm_ap_status&MDM_AP_Status_Core_SLEEPDEEP) {
            if (mdm_ap_status&MDM_AP_Status_VLP_Mode) {
               status =  T_VLPS;
               break;
            }
            else {
               status =  T_STOP;
               break;
            }
         }
         if (mdm_ap_status&MDM_AP_Status_Core_SLEEPING) {
            if (mdm_ap_status&MDM_AP_Status_VLP_Mode) {
               status =  T_VLPW;
               break;
            }
            else {
               status =  T_WAIT;
               break;
            }
         }
         if (mdm_ap_status&MDM_AP_Status_VLP_Mode) {
            status =  T_VLPR;
            break;
         }
         if ((mdm_ap_status&MDM_AP_Status_System_Reset) == 0) {
            status =  T_RESET;
            break;
         }
         status =  T_RUNNING;
         break;
      }

      unsigned long dhcsr;
      USBDM_ErrorCode rc = armReadMemoryWord(DHCSR, &dhcsr);
      if (rc != BDM_RC_OK) {
         log.print("Doing autoReconnect\n");
         if (bdmInterface->connect() != BDM_RC_OK) {
            log.print("Re-connect failed\n");
         }
         else {
            log.print("Re-connect OK\n");
            // retry after connect
            rc = armReadMemoryWord(DHCSR, &dhcsr);
         }
      }
      if (rc != BDM_RC_OK) {
         status = T_NOCONNECTION;
         break;
      }
      if ((dhcsr & DHCSR_S_SLEEP) != 0) {
         status = T_WAIT;
         break;
      }
      if ((dhcsr & (DHCSR_S_HALT|DHCSR_S_LOCKUP)) != 0) {
         status = T_HALT;
         break;
      }
      status = T_RUNNING;
      break;
   } while (0);
   
   if (status != lastStatus) {
      log.print("Status changed => %s\n", getStatusName(status));
      lastStatus = status;
   }
   return status;
}

//#define REPORT_LONG_LOCATION

void GdbHandler_ARM::reportLocation(char mode, int reason) {
   LOGGING_Q;
   char buff[100];
   char *cPtr = buff;

   cPtr += sprintf(buff, "%c%2.2X", mode, reason);
#if defined(REPORT_LONG_LOCATION)
   static const int regsToReport[] = {15, 14, 13, 16}; // PC, LR, SP, PSR
   for (unsigned index=0; index<(sizeof(regsToReport)/sizeof(regsToReport[0])); index++) {
      cPtr += sprintf(cPtr, "%X:", regsToReport[index]);
      cPtr += readReg(regsToReport[index], cPtr);
      *cPtr++ = ';';
   }
#endif
   *cPtr++ = '\0';
   gdbInOut->sendGdbString(buff);
}

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
   bool atHostedBreak = (targetToNative16(opcode) == SEMI_HOSTING_OPCODE);
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
 *         T_USER_INPUT    if halted waiting for user input
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::handleHostedBreak() {
   LOGGING_Q;
   unsigned long pc,r0,r1;
   time_t theTime;

   if (targetBreakPending) {
      // Change to halt
      return T_HALT;
   }
   if (readPC(&pc) != BDM_RC_OK) {
      return T_HALT;
   }
   if (readR0(&r0) != BDM_RC_OK) {
      return T_HALT;
   }
   if (readR1(&r1) != BDM_RC_OK) {
      return T_HALT;
   }
   log.print("pc=0x%08lX, r0=0x%08lX, r1=0x%08lX\n", pc, r0, r1);

   if (runState != Running) {
      // Only check for Hosted break when actually halting
      log.print("Ignored as not running\n");
      return T_HALT;
   }
   // Default to Halted
   GdbTargetStatus targetStatus = T_HALT;

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
//      targetStatus = T_USER_INPUT;
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
//      targetStatus = T_USER_INPUT;
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
      runState = Running;
      return T_RUNNING;
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
   bool looping = false;
   if (runState == Running) {
      // Target has just halted - cache registers
      readRegs();
      uint32_t currentPC = getCachedPC();
      looping = (currentPC == lastStoppedPC);
      lastStoppedPC = currentPC;
   }
   switch(runState) {
   case Halted :  // halted -> halted
      // No change
      break;
   case UserInput: // already halted
      // No change
      return T_USER_INPUT;
   case Breaking : // user breaking -> halted
      reportLocation('T', TARGET_SIGNAL_INT);
      log.print("Target has halted (from breaking) @0x%08X\n", lastStoppedPC);
      reportGdbPrintf(M_INFO, "Target has halted (due to user break)  @0x%08X\n", lastStoppedPC);
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = Halted;
      break;
   case Stepping : // stepping -> halted
      // GDB has a bug where stepping on an empty loop will cause an infinite loop of trying to step to the next location
      // This detects the PC not changing on step and return TARGET_SIGNAL_INT rather than TARGET_SIGNAL_TRAP to abort stepping
      if (looping) {
            reportLocation('T', TARGET_SIGNAL_INT);
         }
         else {
            reportLocation('T', TARGET_SIGNAL_TRAP);
         }
      log.print("Target has halted (from stepping) @0x%08X\n", lastStoppedPC);
      reportGdbPrintf(M_BORINGINFO, "Target has halted (from stepping) @0x%08X\n", lastStoppedPC);
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = Halted;
      break;
   default:       // ???     -> halted
   case Running : // running -> halted
      if (atBreakpoint(getCachedPC())) {
         reportLocation('T', TARGET_SIGNAL_TRAP);
      }
      else {
         reportLocation('T', TARGET_SIGNAL_INT);
      }
      log.print("Target has halted (from running) @%s\n", getCachedPcAsString());
      reportGdbPrintf(M_INFO, "Target has halted (from running)  @%s\n", getCachedPcAsString());
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = Halted;
      break;
   }
   targetBreakPending = false;
   return T_HALT;
}

/*!
 *   Check for change in target run state
 *   - Polls target
 *   - Report changes to GDB
 *   - Updates gdbTargetStatus (Global)
 *
 *   @return Target status
 */
GdbHandler::GdbTargetStatus GdbHandler_ARM::pollTarget(void) {
   LOGGING;
   static int  unsuccessfulPollCount = 0;                    // Count of unsuccessful polls of the target
   static bool resetAttempted = false;                       // Set if reset already tried
   int         timeoutLimit   = getConnectionTimeout() * 10; // Scale to 100 ms ticks

   if (targetBreakPending) {
      // Halt target
      bdmInterface->halt();
   }
   GdbTargetStatus gdbTargetStatus = getTargetStatus();
   log.print("gdbTargetStatus(on poll) = %s\n", getStatusName(gdbTargetStatus));
   log.print("runState(on entry)       = %s\n", getRunStateName(runState));

   if (gdbTargetStatus == T_NOCONNECTION) {
      if (resetAttempted) {
         return T_NOCONNECTION;
      }
      if ((unsuccessfulPollCount++ < timeoutLimit) || (timeoutLimit == 0)) {
         return T_UNKNOWN;
      }
      reportGdbPrintf((GdbMessageLevel)(M_ERROR|M_DIALOGUE), "Resetting target due to connection failure\n");
      usbdmResetTarget(true);
      resetAttempted = true;
      return T_UNKNOWN;
   }
   resetAttempted = false;
   unsuccessfulPollCount = 0;

   if ((gdbTargetStatus == T_VLLSxRESET) || (gdbTargetStatus == T_LLSxRESET)) {
      configureKinetisMDM_AP();
      // Re-establish breakpoints as lost on reset
      notifyBreakpointsCleared();
      activateBreakpoints();
   }
   if ((gdbTargetStatus == T_HALT)) {
      // Check for semi-hosting
      unsigned long pc;
      readPC(&pc);
      if (checkHostedBreak(pc)) {
         gdbTargetStatus = handleHostedBreak();
      }
   }
   if ((gdbTargetStatus == T_HALT)) {
      gdbTargetStatus = handleHalted();
   }
   log.print("gdbTargetStatus(on exit) = %s\n", getStatusName(gdbTargetStatus));
   log.print("runState(on exit)        = %s\n", getRunStateName(runState));
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
