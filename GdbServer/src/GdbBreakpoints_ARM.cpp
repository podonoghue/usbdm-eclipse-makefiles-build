/*
 * GdbBreakpointsARM.cpp
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#include "GdbBreakpoints_ARM.h"

#include "USBDM_API.h"
#include "ArmDefinitions.h"

#include "UsbdmSystem.h"
#include "GdbBreakpoints.h"

GdbBreakpoints_ARM::GdbBreakpoints_ARM(BdmInterfacePtr bdmInterface) : GdbBreakpoints(bdmInterface) {
}

GdbBreakpoints_ARM::~GdbBreakpoints_ARM() {
}

//! Converts a uint32_t value to an array of 4 uint8_t in litteEndian order
//!
//! @param data - value to convert
//!
//! @return ptr to static buffer containing value
//!
inline const uint8_t *getData4x8Le(uint32_t data) {
   static uint8_t data8[4];
   data8[0]= data;
   data8[1]= data>>8;
   data8[2]= data>>16;
   data8[3]= data>>24;
   return data8;
}

//! Converts an array of 4 uint8_t values in litteEndian order to a uint32_t
//!
//! @param data - value to convert
//!
//! @return ptr to static buffer containing value
//!
inline uint32_t getU32Le(uint8_t data[]) {
   return data[0]+(data[1]<<8)+(data[2]<<16)+(data[3]<<24);
}

static const uint8_t haltOpcode[] = {0x00, 0xBE};

const uint8_t *getFpCompAddress(uint32_t address) {
   uint32_t fpCompValue = address&FP_COMP_ADDR_MASK;
   fpCompValue |= (address&0x02)?FP_COMP_BKPT_UPPER:FP_COMP_BKPT_LOWER;
   fpCompValue |= FP_COMP_ENABLE;
   return getData4x8Le(fpCompValue);
}

//! Activate breakpoints. \n
//! This may involve changing target code for RAM breakpoints or
//! modifying target breakpoint hardware
//!
void GdbBreakpoints_ARM::activateBreakpoints(void) {
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
   uint32_t fp_ctrl = FP_CTRL_DISABLE;
   for (unsigned breakPtNum=0; breakPtNum<maxNumHardwareBreakPoints; breakPtNum++) {
      if (hardwareBreakpoints[breakPtNum].inUse) {
         log.print("Activating: %s@%08X\n", getBreakpointName(hardBreak),
                                                 hardwareBreakpoints[breakPtNum].address&~0x1);
         fp_ctrl = FP_CTRL_ENABLE;
         bdmInterface->writeMemory(4, 4, FP_COMP0+4*breakPtNum, getFpCompAddress(hardwareBreakpoints[breakPtNum].address));
         breakpointsActive = true;
      }
      else {
         bdmInterface->writeMemory(4, 4, FP_COMP0+4*breakPtNum, getData4x8Le(FP_COMP_DISABLE));
      }
   }
   bdmInterface->writeMemory(4, 4, FP_CTRL, getData4x8Le(fp_ctrl));
   // Hardware watches
   for (unsigned watchPtNum=0; watchPtNum<maxNumDataWatches; watchPtNum++) {
      if (dataWatchPoints[watchPtNum].inUse) {
         unsigned size       = dataWatchPoints[watchPtNum].size;
         unsigned bpSize     = 1;
         unsigned sizeValue  = 0;
         while ((bpSize<size) && (sizeValue<15)) {
            sizeValue++;
            bpSize <<= 1;
         }
         int mode = DWT_FUNCTION_READ_WATCH;
         switch (dataWatchPoints[watchPtNum].type) {
         case readWatch:   mode = DWT_FUNCTION_READ_WATCH;  break;
         case writeWatch:  mode = DWT_FUNCTION_WRITE_WATCH; break;
         case accessWatch: mode = DWT_FUNCTION_RW_WATCH;    break;
         default : break;
         }
         log.print("Activating: %s@%08X, bpSize=%d, sizeValue=%d)\n",
               getBreakpointName(dataWatchPoints[watchPtNum].type),
               dataWatchPoints[watchPtNum].address&(~(bpSize-1)),
               bpSize, sizeValue );
         bdmInterface->writeMemory(4, 4, DWT_COMP0+16*watchPtNum,     getData4x8Le(dataWatchPoints[watchPtNum].address));
         bdmInterface->writeMemory(4, 4, DWT_MASK0+16*watchPtNum,     getData4x8Le(sizeValue));
         bdmInterface->writeMemory(4, 4, DWT_FUNCTION0+16*watchPtNum, getData4x8Le(mode));
         breakpointsActive = true;
      }
      else {
         bdmInterface->writeMemory(4, 4, DWT_FUNCTION0+16*watchPtNum, getData4x8Le(DWT_FUNCTION_NONE));
      }
   }
}

//! De-activate breakpoints. \n
//! This may involve changing target code for RAM breakpoints or
//! modifying target breakpoint hardware.
//!
void GdbBreakpoints_ARM::deactivateBreakpoints(void) {
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
   bdmInterface->writeMemory(4, 4, FP_CTRL, getData4x8Le(FP_CTRL_DISABLE));
   breakpointsActive = false;
}
//! RAM based breakpoints leave the PC pointing at the instruction following
//  the HALT instruction.  This routine checks for this situation and adjusts
//! the target PC.
//!
void GdbBreakpoints_ARM::checkAndAdjustBreakpointHalt(void) {
   LOGGING_Q;
   unsigned long pcAddress;
   unsigned char currentInstruction[2];
   bdmInterface->readPC(&pcAddress);
   bdmInterface->readMemory(MS_Word, 2, pcAddress, currentInstruction);
   if ((currentInstruction[0] == 0xAB) && (currentInstruction[1] == 0xBE)) {
      // Adjust location for hosted BKPT #0xAB
      pcAddress += 2;
      log.print("- adjusting PC=%08lX\n", pcAddress);
      bdmInterface->writePC(pcAddress);
   }
}

// Initialise Breakpoint before first use
//
USBDM_ErrorCode GdbBreakpoints_ARM::initBreakpoints() {
   LOGGING_Q;

   clearAllBreakpoints();

   uint8_t readDataBuff[4];
   maxNumHardwareBreakPoints = 0;
   maxNumDataWatches         = 0;

   USBDM_ErrorCode rc = bdmInterface->readMemory(4, 4, FP_CTRL, readDataBuff);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   uint32_t fp_ctrl_value = getU32Le(readDataBuff);
   maxNumHardwareBreakPoints = (((fp_ctrl_value>>(12-4)))&(0x7<<4))+(((fp_ctrl_value>>(4-0)))&(0xF<<0));
   if (maxNumHardwareBreakPoints>MAX_HARDWARE_BREAKPOINTS) {
      maxNumHardwareBreakPoints = MAX_HARDWARE_BREAKPOINTS;
   }
   log.print("- FP_CTRL = 0x%08X, Number of Hardware breakpoints = %d\n", fp_ctrl_value, maxNumHardwareBreakPoints);
   rc = bdmInterface->readMemory(4, 4, DWT_CTRL, readDataBuff);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   uint32_t dwt_ctrl_value = getU32Le(readDataBuff);
   maxNumDataWatches = (((dwt_ctrl_value>>28))&0xF);
   if (maxNumDataWatches>MAX_DATA_WATCHES) {
      maxNumDataWatches = MAX_DATA_WATCHES;
   }
   log.print("- DWT_CTRL = 0x%08X, Number of Data watchpoints = %d\n", dwt_ctrl_value, maxNumDataWatches);
   return BDM_RC_OK;
}

int  GdbBreakpoints_ARM::getNumberOfHardwareBreakpoints() {
   return maxNumHardwareBreakPoints;
}
