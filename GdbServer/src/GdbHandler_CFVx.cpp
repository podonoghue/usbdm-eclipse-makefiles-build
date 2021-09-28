/*
 * GdbHandlerCFV1.cpp
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#include <string.h>

#include "GdbHandler_CFVx.h"
#include "TargetDefines.h"
#include "Names.h"
#include "signals.h"
#include "GdbBreakpoints_CFV1.h"

GdbHandler *createCFVxGdbHandler(
      GdbHandler::GdbHandlerOwner    &owner,
      GdbInOut                       *gdbInOut,
      BdmInterfacePtr                 bdmInterface,
      DeviceInterfacePtr              deviceInterface,
      IGdbTty                        *tty) {
   return new GdbHandler_CFVx(owner, gdbInOut, bdmInterface, deviceInterface, tty);
}

GdbHandler_CFVx::GdbHandler_CFVx(
      GdbHandlerOwner      &owner,
      GdbInOut             *gdbInOut,
      BdmInterfacePtr       bdmInterface,
      DeviceInterfacePtr    deviceInterface,
      IGdbTty              *tty) :
   GdbHandlerCommon(
         T_CFVx,
         owner,
         gdbInOut,
         bdmInterface,
         deviceInterface,
         new GdbBreakpoints_CFV1(bdmInterface),
         tty,
         DeviceData::resetHardware) {
}

GdbHandler_CFVx::~GdbHandler_CFVx() {
}

// Target is BE != Native
//=============================
/*
 * Convert 16-bit value Native <-> Target
 */
uint16_t GdbHandler_CFVx::targetToFromNative16(uint16_t data) {
   return ((data<<8)&0xFF00) + ((data>>8)&0xFF);
}
/*
 * Convert 32-bit value Native <-> Target
 */
uint32_t GdbHandler_CFVx::targetToFromNative32(uint32_t data) {
   return ((data<<24)&0xFF000000) + ((data<<8)&0xFF0000) + ((data>>8)&0xFF00) + ((data>>24)&0xFF);
}

/**
 * Extract a 32-bit value from byte buffer in target byte order
 *
 * @param[in]  buff    Buffer to read value from
 * @param[out] value   32-bit value from buffer
 */
void GdbHandler_CFVx::extractTarget32Bits(uint8_t buff[], uint32_t &value) {
   // Big-endian
   value = buff[3] + (buff[2]<<8) +(buff[1]<<16) +(buff[0]<<24);
}

/**
 * Encode a 32-bit value into byte buffer in target byte order
 *
 * @param[out] value   32-bit value to enter
 * @param[in]  buff    Buffer to add value to
 */
void GdbHandler_CFVx::encodeTarget32Bits(uint32_t value, uint8_t buff[]) {
   // Big-endian
   buff[3] = static_cast<uint8_t>(value);
   buff[2] = static_cast<uint8_t>(value>>8);
   buff[1] = static_cast<uint8_t>(value>>16);
   buff[0] = static_cast<uint8_t>(value>>24);
}


// Target is BE == BE
//=================================
/*
 * Convert 16-bit value Target <-> BIG-ENDIAN
 */
uint16_t GdbHandler_CFVx::targetToBE16(uint16_t data) {
   return data;
}
//=================================
/*
 * Convert 32-bit value Target <-> BIG-ENDIAN
 */
uint32_t GdbHandler_CFVx::targetToBE32(uint32_t data) {
   return data;
}

USBDM_ErrorCode GdbHandler_CFVx::initialise() {

   USBDM_ErrorCode rc = GdbHandlerCommon::initialise();
   // Ignore Secured as may still be able to program device after mass-erase
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      return rc;
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandler_CFVx::resetTarget(DeviceData::ResetMethod resetMethod) {
   LOGGING;

   USBDM_ErrorCode rc = GdbHandlerCommon::resetTarget(resetMethod);
   if (rc != BDM_RC_OK) {
      // Retry with hardware reset
      rc = GdbHandlerCommon::resetTarget(DeviceData::resetHardware);
   }
   return rc;
}

USBDM_ErrorCode GdbHandler_CFVx::continueTarget(void) {
   LOGGING_Q;

   return GdbHandlerCommon::continueTarget();
}

/*! Mask/unmask interrupts (in SR)
 *
 * @param disableInterrupts - true/false -> disable/enable interrupts
 */
void GdbHandler_CFVx::maskInterrupts(bool disableInterrupts) {
   unsigned long csrValue;

   bdmInterface->readDReg(CFV1_DRegCSR, &csrValue);

   if (disableInterrupts) {
      bdmInterface->writeDReg(CFV1_DRegCSR, csrValue|CFV1_CSR_IPI);
   }
   else {
      bdmInterface->writeDReg(CFV1_DRegCSR, csrValue&~CFV1_CSR_IPI);
   }
   // For debug checking
//   bdmInterface->readDReg(CFV1_DRegCSR, &csrValue);
}

static const char defaultTargetRegsXML[] =
      "<?xml version=\"1.0\"?>\n"
      "<!DOCTYPE feature SYSTEM \"gdb-target.dtd\">\n"
      "<feature name=\"org.gnu.gdb.coldfire.core\">\n"
      "   <struct id=\"ps.type\" size=\"4\">\n"
      "      <field name=\"C\"  start=\"0\"  end=\"0\"/>\n"
      "      <field name=\"V\"  start=\"1\"  end=\"1\"/>\n"
      "      <field name=\"Z\"  start=\"2\"  end=\"2\"/>\n"
      "      <field name=\"N\"  start=\"3\"  end=\"3\"/>\n"
      "      <field name=\"X\"  start=\"4\"  end=\"4\"/>\n"
      "      <field name=\"I\"  start=\"8\"  end=\"10\"/>\n"
      "      <field name=\"M\"  start=\"12\" end=\"12\"/>\n"
      "      <field name=\"S\"  start=\"13\" end=\"13\"/>\n"
      "      <field name=\"T0\" start=\"14\" end=\"14\"/>\n"
      "      <field name=\"T1\" start=\"15\" end=\"15\"/>\n"
      "   </struct>\n"
      "   <reg name=\"d0\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d1\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d2\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d3\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d4\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d5\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d6\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"d7\" bitsize=\"32\" type=\"uint32\"     group=\"general\" />\n"
      "   <reg name=\"a0\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"a1\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"a2\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"a3\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"a4\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"a5\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"fp\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   <reg name=\"sp\" bitsize=\"32\" type=\"data_ptr\"   group=\"general\" />\n"
      "   \n"
      "   <reg name=\"ps\" bitsize=\"32\" type=\"ps.type\"  group=\"general\" />\n"
      "   <reg name=\"pc\" bitsize=\"32\" type=\"code_ptr\" group=\"general\" />\n"
      "   \n"
      "</feature>\n";

// Maps GDB register numbers to USBDM register numbers (or -1 if invalid)
static int registerMap[] = {
      CFVx_RegD0,CFVx_RegD1,CFVx_RegD2,CFVx_RegD3,
      CFVx_RegD4,CFVx_RegD5,CFVx_RegD6,CFVx_RegD7,
      CFVx_RegA0,CFVx_RegA1,CFVx_RegA2,CFVx_RegA3,
      CFVx_RegA4,CFVx_RegA5,CFVx_RegA6,CFVx_RegA7,
      0x100+CFVx_CRegSR, 0x100+CFVx_CRegPC,        // +0x100 indicates bdmInterface->readCReg
};

#define CACHED_PC_VALUE_OFFSET  (registerBuffer+(4*17))
#define CACHED_D0_VALUE_OFFSET  (registerBuffer+(4*CFVx_RegD0))
#define CACHED_D1_VALUE_OFFSET  (registerBuffer+(4*CFVx_RegD1))

/*!  Sets up the register description from device XML
 *   or hard-coded default
 */
bool GdbHandler_CFVx::initRegisterDescription(void) {
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

bool GdbHandler_CFVx::isValidRegister(unsigned regNo) {
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
USBDM_ErrorCode GdbHandler_CFVx::readReg(unsigned regNo, uint8_t *&buffPtr) {
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

   if (usbdmRegNo < 0x100) {
      rc = bdmInterface->readReg((CFV1_Registers_t)usbdmRegNo, &regValue);
      log.print("%s => %08lX\n", getCFVxRegName(usbdmRegNo), regValue);
   }
   else {
      usbdmRegNo -= 0x100;
      rc = bdmInterface->readCReg((CFV1_Registers_t)(usbdmRegNo), &regValue);
      log.print("%s => %08lX\n", getCFVxControlRegName(usbdmRegNo), regValue);
   }
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
   regValue = targetToFromNative32(regValue);
   memcpy(buffPtr, &regValue, 4);
   buffPtr += 4;
   return rc;
}

void GdbHandler_CFVx::debug_print_regs() {
// ToDo Implement this
}

/*
 *  Get cached value of PC
 *  Note: Assumes cache valid
 *
 *  @return 32-bit value
 */
uint32_t GdbHandler_CFVx::getCachedPC() {
   return get32bitBE(CACHED_PC_VALUE_OFFSET);
}

/**
 * Get register values of important registers for stop reporting etc.
 *
 * @return Static string describing values.
 */
const char *GdbHandler_CFVx::getImportantRegisters() {
   static char buff[100];

   snprintf(buff, sizeof(buff), " ");
   return buff;
}

//! Write to target register
//!
//! @param regNo     - number of register to read (GDB numbering)
//! @param regValue  - value to write
//!
void GdbHandler_CFVx::writeReg(unsigned regNo, unsigned long regValue) {
   LOGGING;
   if (!isValidRegister(regNo))
      return;
   int usbdmRegNo = registerMap[regNo];

   if (usbdmRegNo < 0x100) {
      bdmInterface->writeReg((CFV1_Registers_t)usbdmRegNo, regValue);
      log.print("reg[%d] <= %08lX\n", regNo, regValue);
   }
   else {
      bdmInterface->writeCReg((CFV1_Registers_t)(usbdmRegNo-0x100), regValue);
      log.print("reg[%d] <= %08lX\n", regNo, regValue);
   }
}

//! Get run state by polling target
//!
//! @return status - status of target T_UNKNOWN/T_SLEEP/T_HALT/T_RUNNING
//!
GdbHandler::GdbTargetStatus GdbHandler_CFVx::getTargetStatus(void) {
   LOGGING_Q;

   static GdbTargetStatus  lastStatus = GdbTargetStatus_UNKNOWN;
   GdbTargetStatus         status     = GdbTargetStatus_UNKNOWN;

   do {
      USBDM_ErrorCode rc = bdmInterface->connect();
      if (rc == BDM_RC_CF_NOT_READY) {
         // Returns this response after an attempted operation while running
         status = GdbTargetStatus_RUNNING;
         break;
      }
      if (rc != BDM_RC_OK) {
         log.print("Connect failed, rc = %s\n", bdmInterface->getErrorString(rc));
         status = GdbTargetStatus_UNKNOWN;
         break;
      }
      // Crude - Assume if register read succeeds then target is halted
      unsigned long value;
      rc = bdmInterface->readReg(CFVx_RegD0, &value);
      if (rc == BDM_RC_OK) {
         status = GdbTargetStatus_HALT;
         break;
      }
      status = GdbTargetStatus_RUNNING;
      break;
   } while (0);

   if (status != lastStatus) {
      log.print("Status changed => %s\n", getStatusName(status));
      lastStatus = status;
   }
   return status;
}

//#define REPORT_LONG_LOCATION

/**
 *
 * @param mode          Indicates the reply mode e.g. S T etc
 * @param signal        Signal value e.g. TARGET_SIGNAL_TRAP TARGET_SIGNAL_INT
 * @param stopReason    Optional Reason for stop if T=TARGET_SIGNAL_TRAP
 */
void GdbHandler_CFVx::reportHalt(char mode, int signal) {
   LOGGING_Q;
   char buff[100];
   char *cPtr = buff;

   cPtr += sprintf(buff, "%c%2.2X", mode, signal);
#if defined(REPORT_LONG_LOCATION)
   static const int regsToReport[] = {17, 15, 14, 16}; // PC, SP, FP, SR
   for (unsigned index=0; index<(sizeof(regsToReport)/sizeof(regsToReport[0])); index++) {
      cPtr += sprintf(cPtr, "%X:", regsToReport[index]);
      cPtr += readReg(regsToReport[index], cPtr);
      *cPtr++ = ';';
   }
#endif
   *cPtr++ = '\0';
   gdbInOut->sendGdbString(buff);
}
/**
 * Checks if target at a semi-hosting break
 */
bool GdbHandler_CFVx::checkHostedBreak(uint32_t currentPC) {
   return false;
}

/**
 * Handles target halted due to semi-hosting break
 */
GdbHandler::GdbTargetStatus GdbHandler_CFVx::handleHostedBreak() {
   return GdbTargetStatus_HALT;
}

/**
 * Handles target halted apart from semi-hosting break
 */
GdbHandler::GdbTargetStatus GdbHandler_CFVx::handleHalted() {
   LOGGING;
   bool looping = false;
   if (runState != RunState_Halted) {
      // Target has just halted - cache registers
      readRegs();
      uint32_t currentPC = getCachedPC();
      looping = (currentPC == lastStoppedPC);
      lastStoppedPC = currentPC;
   }
   switch(runState) {
   case RunState_Halted :  // halted -> halted
      // No change
      break;
   case RunState_Stepping : // stepping -> halted
      // GDB has a bug where stepping on an empty loop will cause an infinite loop of trying to step to the next location
      // This detects the PC not changing on step and return TARGET_SIGNAL_INT rather than TARGET_SIGNAL_TRAP to abort stepping
      if (looping) {
            reportHalt('T', TARGET_SIGNAL_INT);
         }
         else {
            reportHalt('T', TARGET_SIGNAL_TRAP);
         }
      log.print("Target has halted (from stepping) @0x%08X\n", lastStoppedPC);
      reportGdbPrintf(M_BORINGINFO, "Target has halted (from stepping) @0x%08X\n", lastStoppedPC);
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = RunState_Halted;
      break;
   default:       // ???     -> halted
   case RunState_Running : // running -> halted
      if (atBreakpoint(getCachedPC())) {
         reportHalt('T', TARGET_SIGNAL_TRAP);
      }
      else {
         reportHalt('T', TARGET_SIGNAL_INT);
      }
      log.print("Target has halted (from running) @%s\n", getCachedPcAsString());
      reportGdbPrintf(M_INFO, "Target has halted (from running)  @%s\n", getCachedPcAsString());
      deactivateBreakpoints();
      checkAndAdjustBreakpointHalt();
      runState = RunState_Halted;
      break;
   }
   forceTargetHalt = false;
   return GdbTargetStatus_HALT;
}

/*!
 *   Check for change in target run state
 *   - Polls target
 *   - Report changes to GDB
 *   - Updates gdbTargetStatus (Global)
 *
 *   @return Target status
 */
GdbHandler::GdbTargetStatus GdbHandler_CFVx::pollTarget(void) {
   LOGGING;
   static int  unsuccessfulPollCount = 0;                    // Count of unsuccessful polls of the target
   static bool resetAttempted = false;                       // Set if reset already tried
   int         timeoutLimit   = getConnectionTimeout() * 10; // Scale to 100 ms ticks

   if (forceTargetHalt) {
      // Halt target
      bdmInterface->halt();
   }
   GdbTargetStatus gdbTargetStatus = getTargetStatus();
   log.print("gdbTargetStatus(on poll) = %s\n", getStatusName(gdbTargetStatus));
   log.print("runState(on entry)       = %s\n", getRunStateName(runState));

   if (gdbTargetStatus == GdbTargetStatus_NOCONNECTION) {
      if (resetAttempted) {
         return GdbTargetStatus_NOCONNECTION;
      }
      if ((unsuccessfulPollCount++ < timeoutLimit) || (timeoutLimit == 0)) {
         return GdbTargetStatus_UNKNOWN;
      }
      reportGdbPrintf((GdbMessageLevel)(M_ERROR|M_DIALOGUE), "Resetting target due to connection failure\n");
      resetTarget();
      resetAttempted = true;
      return GdbTargetStatus_UNKNOWN;
   }
   resetAttempted = false;
   unsuccessfulPollCount = 0;

   if ((gdbTargetStatus == GdbTargetStatus_HALT)) {
      // Check for semi-hosting
      unsigned long pc;
      readPC(&pc);
      if (checkHostedBreak(pc)) {
         gdbTargetStatus = handleHostedBreak();
      }
   }
   if ((gdbTargetStatus == GdbTargetStatus_HALT)) {
      gdbTargetStatus = handleHalted();
   }
   log.print("gdbTargetStatus(on exit) = %s\n", getStatusName(gdbTargetStatus));
   log.print("runState(on exit)        = %s\n", getRunStateName(runState));
   return gdbTargetStatus;
}

USBDM_ErrorCode GdbHandler_CFVx::writePC(unsigned long value) {
   return bdmInterface->writeCReg(CFVx_CRegPC, value);
}

USBDM_ErrorCode GdbHandler_CFVx::readPC(unsigned long *value) {
   return bdmInterface->readCReg(CFVx_CRegPC, value);
}

USBDM_ErrorCode GdbHandler_CFVx::writeSP(unsigned long value) {
   return bdmInterface->writeReg(CFVx_RegSP, value);
}

USBDM_ErrorCode GdbHandler_CFVx::updateTarget() {
   return BDM_RC_OK;
}

bool GdbHandler_CFVx::atMemoryBreakpoint() {
   return false;
}
