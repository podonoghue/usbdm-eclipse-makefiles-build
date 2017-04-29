/*
 * GdbHandlerCFV1.cpp
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#include <string.h>

#include "GdbHandler_CFV1.h"
#include "TargetDefines.h"
#include "Names.h"
#include "signals.h"
#include "GdbBreakpoints_CFV1.h"

GdbHandler *createCFV1GdbHandler(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbHandler::GdbCallback gdbCallBackPtr, IGdbTty *tty) {
   return new GdbHandler_CFV1(gdbInOut, bdmInterface, deviceInterface, gdbCallBackPtr, tty);
}

GdbHandler_CFV1::GdbHandler_CFV1(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbCallback gdbCallBackPtr, IGdbTty *tty) :
   GdbHandlerCommon(T_CFVx, gdbInOut, bdmInterface, deviceInterface, new GdbBreakpoints_CFV1(bdmInterface), gdbCallBackPtr, tty) {
}

GdbHandler_CFV1::~GdbHandler_CFV1() {
}

// Target is BE != Native
//=============================
/*
 * Convert 16-bit value Native <-> Target
 */
uint16_t GdbHandler_CFV1::targetToNative16(uint16_t data) {
   return ((data<<8)&0xFF00) + ((data>>8)&0xFF);
}
/*
 * Convert 32-bit value Native <-> Target
 */
uint32_t GdbHandler_CFV1::targetToNative32(uint32_t data) {
   return ((data<<24)&0xFF000000) + ((data<<8)&0xFF0000) + ((data>>8)&0xFF00) + ((data>>24)&0xFF);
}
/*
 * read 32-bit value from memory buffer in target format
 */
uint32_t GdbHandler_CFV1::getTarget32Bits(uint8_t buff[], int offset) {
   uint32_t value = (buff[offset]<<24) + (buff[offset+1]<<16) +(buff[offset+2]<<8) +buff[offset+3];
   return targetToNative32(value);
}

// Target is BE == BE
//=================================
/*
 * Convert 16-bit value Target <-> BIG-ENDIAN
 */
uint16_t GdbHandler_CFV1::targetToBE16(uint16_t data) {
   return data;
}
//=================================
/*
 * Convert 32-bit value Target <-> BIG-ENDIAN
 */
uint32_t GdbHandler_CFV1::targetToBE32(uint32_t data) {
   return data;
}

USBDM_ErrorCode GdbHandler_CFV1::initialise() {

   USBDM_ErrorCode rc = GdbHandlerCommon::initialise();
   // Ignore Secured as may still be able to program device after mass-erase
   if ((rc != BDM_RC_OK)&&(rc != BDM_RC_SECURED)) {
      return rc;
   }
   return BDM_RC_OK;
}

USBDM_ErrorCode GdbHandler_CFV1::resetTarget(TargetMode_t mode) {
   LOGGING;

   USBDM_ErrorCode rc = GdbHandlerCommon::resetTarget(mode);
   if (rc != BDM_RC_OK) {
      return rc;
   }

   // CFV1 targets are confused by the following sequence:
   // - Reset target
   // - Write to PC
   // - This prevents the SP being loaded when the program continues
   reportGdbPrintf(GdbHandler::M_INFO, "Loading PC & SP\n");
   log.print("Loading PC & SP\n");
   uint8_t buff[8];
   USBDM_ErrorCode rc2 = bdmInterface->readMemory(MS_Byte, 0x8, 0, buff);
   if (rc2 == BDM_RC_OK) {
      uint32_t resetSP = get32bitBE(buff+0);
      uint32_t resetPC = get32bitBE(buff+4);
      log.print("Writing PC=0x%08X, SP=-x%08X\n", resetPC, resetSP);
      writeSP(resetSP); // This will be SSP after reset
      writePC(resetPC);
   }
   return rc;
}

void GdbHandler_CFV1::continueTarget(void) {
   LOGGING_Q;

   GdbHandlerCommon::continueTarget();
}

/*! Mask/unmask interrupts (in SR)
 *
 * @param disableInterrupts - true/false -> disable/enable interrupts
 */
void GdbHandler_CFV1::maskInterrupts(bool disableInterrupts) {
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
      CFV1_RegD0,CFV1_RegD1,CFV1_RegD2,CFV1_RegD3,
      CFV1_RegD4,CFV1_RegD5,CFV1_RegD6,CFV1_RegD7,
      CFV1_RegA0,CFV1_RegA1,CFV1_RegA2,CFV1_RegA3,
      CFV1_RegA4,CFV1_RegA5,CFV1_RegA6,CFV1_RegA7,
      0x100+CFV1_CRegSR, CFV1_RegPC,         // +0x100 indicates bdmInterface->readCReg/bdmInterface->writeCReg
};

#define CACHED_PC_VALUE_OFFSET  (registerBuffer+(4*17))
#define CACHED_D0_VALUE_OFFSET  (registerBuffer+(4*CFV1_RegD0))
#define CACHED_D1_VALUE_OFFSET  (registerBuffer+(4*CFV1_RegD1))

/*!  Sets up the register description from device XML
 *   or hard-coded default
 */
bool GdbHandler_CFV1::initRegisterDescription(void) {
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

bool GdbHandler_CFV1::isValidRegister(unsigned regNo) {
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
USBDM_ErrorCode GdbHandler_CFV1::readReg(unsigned regNo, char *&buffPtr) {
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
      log.print("%s => %08lX\n", getCFV1RegName(usbdmRegNo), regValue);
   }
   else {
      rc = bdmInterface->readCReg((CFV1_Registers_t)(usbdmRegNo-0x100), &regValue);
      log.print("%s => %08lX\n", getCFV1ControlRegName(usbdmRegNo-0x100), regValue);
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
   regValue = targetToNative32(regValue);
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
uint32_t GdbHandler_CFV1::getCachedPC() {
   return get32bitBE(CACHED_PC_VALUE_OFFSET);
}

//! Write to target register
//!
//! @param regNo     - number of register to read (GDB numbering)
//! @param regValue  - value to write
//!
void GdbHandler_CFV1::writeReg(unsigned regNo, unsigned long regValue) {
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
GdbHandler::GdbTargetStatus GdbHandler_CFV1::getTargetStatus() {
   LOGGING_Q;

   static GdbTargetStatus  lastStatus = T_UNKNOWN;
   GdbTargetStatus         status     = T_UNKNOWN;

   do {
      unsigned long value;
      USBDM_ErrorCode rc = bdmInterface->readStatusReg(&value);
      if (rc != BDM_RC_OK) {
         log.print("Doing autoReconnect\n");
         if (bdmInterface->connect() != BDM_RC_OK) {
            log.print("Re-connect failed\n");
         }
         else {
            // retry after connect
            log.print("Re-connect OK\n");
            rc = bdmInterface->readStatusReg(&value);
         }
      }
      if (rc != BDM_RC_OK) {
         log.print("Failed, rc = %s\n", bdmInterface->getErrorString(rc));
         status = T_UNKNOWN;
         break;
      }
      if ((value & CFV1_XCSR_ENBDM) == 0) {
         log.print("ENBDM=0\n");
         status = T_UNKNOWN;
         break;
      }
      if (value&CFV1_XCSR_RUNSTATE) {
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

void GdbHandler_CFV1::reportLocation(char mode, int reason) {
   LOGGING_Q;
   char buff[100];
   char *cPtr = buff;

   cPtr += sprintf(buff, "%c%2.2X", mode, reason);
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
bool GdbHandler_CFV1::checkHostedBreak(uint32_t currentPC) {
   return false;
}

/**
 * Handles target halted due to semi-hosting break
 */
GdbHandler::GdbTargetStatus GdbHandler_CFV1::handleHostedBreak() {
   return T_HALT;
}

/**
 * Handles target halted apart from semi-hosting break
 */
GdbHandler::GdbTargetStatus GdbHandler_CFV1::handleHalted() {
   LOGGING;
   bool looping = false;
   if (runState != Halted) {
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
GdbHandler::GdbTargetStatus GdbHandler_CFV1::pollTarget(void) {
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

USBDM_ErrorCode GdbHandler_CFV1::writePC(unsigned long value) {
   return bdmInterface->writeReg(CFV1_RegPC, value);
}

USBDM_ErrorCode GdbHandler_CFV1::readPC(unsigned long *value) {
   return bdmInterface->readReg(CFV1_RegPC, value);
}

USBDM_ErrorCode GdbHandler_CFV1::writeSP(unsigned long value) {
   return bdmInterface->writeReg(CFV1_RegSP, value);
}

USBDM_ErrorCode GdbHandler_CFV1::updateTarget() {
   return BDM_RC_OK;
}

bool GdbHandler_CFV1::atMemoryBreakpoint() {
   return false;
}
