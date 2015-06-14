/*
 * GdbBreakpointsCFV1.cpp
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#include "GdbBreakpoints_CFV1.h"

#include "USBDM_API.h"
#include "ArmDefinitions.h"

#include "UsbdmSystem.h"
#include "GdbBreakpoints.h"

GdbBreakpoints_CFV1::GdbBreakpoints_CFV1(BdmInterfacePtr bdmInterface) : GdbBreakpoints(bdmInterface) {
}

GdbBreakpoints_CFV1::~GdbBreakpoints_CFV1() {
}

static const uint8_t haltOpcode[] = {0x4A, 0xC8};

#define TDR_TRC_HALT (1<<30)
#define TDR_L1T      (1<<14)
#define TDR_L1EBL    (1<<13)
#define TDR_L1EPC    (1<<1)
#define TDR_L1EA_INC (1<<3)
#define TDR_DISABLE  (0)

//! Activate breakpoints. \n
//! This may involve changing target code for RAM breakpoints or
//! modifying target breakpoint hardware
//!
void GdbBreakpoints_CFV1::activateBreakpoints(void) {
   LOGGING_E;
   MemoryBreakInfo *bpPtr;
   if (breakpointsActive) {
      log.print("Breakpoints already active\n");
      return;
   }
   // Memory breakpoints
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      if (bpPtr->inUse) {
         log.print("(%s@%08X)\n", getBreakpointName(memoryBreak), bpPtr->address);
         bdmInterface->readMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,bpPtr->opcode);
         bdmInterface->writeMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,haltOpcode);
         breakpointsActive = true;
      }
   }
   // Hardware breakpoints
   uint32_t tdrValue = TDR_DISABLE;
   if (hardwareBreakpoints[0].inUse) {
      tdrValue |= TDR_TRC_HALT|TDR_L1T|TDR_L1EBL|TDR_L1EPC;
      bdmInterface->writeDReg(CFVx_DRegPBR0, hardwareBreakpoints[0].address&~0x1);
      bdmInterface->writeDReg(CFVx_DRegPBMR, 0x00000000);
      breakpointsActive = true;
      log.print("(%s@%08X)\n", getBreakpointName(hardBreak),
                                              hardwareBreakpoints[0].address&~0x1);
   }
   if (hardwareBreakpoints[1].inUse) {
      tdrValue |= TDR_TRC_HALT|TDR_L1T|TDR_L1EBL|TDR_L1EPC;
      bdmInterface->writeDReg(CFVx_DRegPBR1, hardwareBreakpoints[1].address|0x1);
      breakpointsActive = true;
      log.print("(%s@%08X)\n", getBreakpointName(hardBreak),
                                              hardwareBreakpoints[1].address&~0x1);
   }
   else {
      bdmInterface->writeDReg(CFVx_DRegPBR1,0);
   }
   // Hardware watches
   if (hardwareBreakpoints[2].inUse) {
      tdrValue |= TDR_TRC_HALT|TDR_L1T|TDR_L1EBL|TDR_L1EPC;
      bdmInterface->writeDReg(CFVx_DRegPBR2, hardwareBreakpoints[2].address|0x1);
      breakpointsActive = true;
      log.print("(%s@%08X)\n", getBreakpointName(hardBreak),
                                              hardwareBreakpoints[2].address&~0x1);
   }
   else {
      bdmInterface->writeDReg(CFVx_DRegPBR2,0);
   }
   if (hardwareBreakpoints[3].inUse) {
      tdrValue |= TDR_TRC_HALT|TDR_L1T|TDR_L1EBL|TDR_L1EPC;
      bdmInterface->writeDReg(CFVx_DRegPBR3, hardwareBreakpoints[3].address|0x1);
      breakpointsActive = true;
      log.print("(%s@%08X)\n", getBreakpointName(hardBreak),
                                              hardwareBreakpoints[3].address&~0x1);
   }
   else {
      bdmInterface->writeDReg(CFV1_DRegPBR3,0);
   }
   if (dataWatchPoints[0].inUse) {
      tdrValue |= TDR_TRC_HALT|TDR_L1T|TDR_L1EBL|TDR_L1EA_INC;
      bdmInterface->writeDReg(CFVx_DRegABLR, dataWatchPoints[0].address);
      bdmInterface->writeDReg(CFVx_DRegABHR, dataWatchPoints[0].address+dataWatchPoints[0].size-1);
      breakpointsActive = true;
   }
   bdmInterface->writeDReg(CFVx_DRegTDR, tdrValue);
}

//! De-activate breakpoints. \n
//! This may involve changing target code for RAM breakpoints or
//! modifying target breakpoint hardware.
//!
void GdbBreakpoints_CFV1::deactivateBreakpoints(void) {
   LOGGING_E;
   MemoryBreakInfo *bpPtr;
   if (!breakpointsActive)
      return;
   // Memory breakpoints
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      if (bpPtr->inUse) {
         log.print("MEM@%08X\n", bpPtr->address);
         bdmInterface->writeMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,bpPtr->opcode);
      }
   }
   // Hardware breakpoints
   bdmInterface->writeDReg(CFV1_DRegTDR, TDR_DISABLE);
   breakpointsActive = false;
}
//! RAM based breakpoints leave the PC pointing at the instruction following
//  the HALT instruction.  This routine checks for this situation and adjusts
//! the target PC.
//!
void GdbBreakpoints_CFV1::checkAndAdjustBreakpointHalt(void) {
   LOGGING_Q;
   // Processor halted
   unsigned long pcAddress = 0;
   bdmInterface->readPC(&pcAddress);
   pcAddress -= 2;
   if (breakpointsActive && (findMemoryBreakpoint(pcAddress) != NULL)) {
      log.print("- adjusting PC=%08lX\n", pcAddress);
      bdmInterface->writePC(pcAddress);
   }
}

// Initialise Breakpoint before first use
//
USBDM_ErrorCode GdbBreakpoints_CFV1::initBreakpoints() {
   LOGGING_Q;

   maxNumHardwareBreakPoints = MAX_HARDWARE_BREAKPOINTS;
   maxNumDataWatches         = MAX_DATA_WATCHES;
   log.print("- Number of Hardware breakpoints = %d\n", maxNumHardwareBreakPoints);
   return BDM_RC_OK;
};


int  GdbBreakpoints_CFV1::getNumberOfHardwareBreakpoints() {
   return maxNumHardwareBreakPoints;
}
