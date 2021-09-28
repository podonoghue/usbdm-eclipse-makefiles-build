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
   LOGGING_F;
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
         log.print("Activating: %s@%08X\n", getBreakpointName(BreakType_softwareBreak), bpPtr->address);
         bdmInterface->readMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,bpPtr->opcode);
         bdmInterface->writeMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,haltOpcode);
         breakpointsActive = true;
      }
   }

   // Hardware breakpoints
   bool fp_cntrl_enabled = false;
   bdmInterface->writeMemory(4, 4, FP_CTRL, getData4x8Le(0));
   for (unsigned breakPtNum=0; breakPtNum<maxNumHardwareBreakPoints; breakPtNum++) {
      if (hardwareBreakpoints[breakPtNum].inUse) {
         if (!fp_cntrl_enabled) {
            bdmInterface->writeMemory(4, 4, FP_CTRL, getData4x8Le(FP_CTRL_ENABLE));
            fp_cntrl_enabled = true;
         }
         log.error("Activating: %s@%08X\n", getBreakpointName(BreakType_hardwareBreak), hardwareBreakpoints[breakPtNum].address&~0x1);
         bdmInterface->writeMemory(4, 4, FP_COMP0+4*breakPtNum, getFpCompAddress(hardwareBreakpoints[breakPtNum].address));
         breakpointsActive = true;
      }
      else {
         bdmInterface->writeMemory(4, 4, FP_COMP0+4*breakPtNum, getData4x8Le(FP_COMP_DISABLE));
      }
   }

   // Enable Trace including Hardware watches
   bool traceEnable = false;
   bdmInterface->writeMemory(4, 4, DEMCR, getData4x8Le(0));
   for (unsigned watchPtNum=0; watchPtNum<maxNumDataWatches; watchPtNum++) {
      if (dataWatchPoints[watchPtNum].inUse) {
         int bpSize = dataWatchPoints[watchPtNum].size;
         uint32_t maskedBits = 0;
         while ((bpSize>>=1)>0) {
            maskedBits++;
         }
         int mode = DWT_FUNCTION_READ_WATCH;
         switch (dataWatchPoints[watchPtNum].type) {
            case BreakType_readWatch:   mode = DWT_FUNCTION_READ_WATCH;  break;
            case BreakType_writeWatch:  mode = DWT_FUNCTION_WRITE_WATCH; break;
            case BreakType_accessWatch: mode = DWT_FUNCTION_RW_WATCH;    break;
            default : break;
         }
         log.print("Activating: %s@%08X, bpSize=%d, maskedBits=%d)\n",
               getBreakpointName(dataWatchPoints[watchPtNum].type),
               dataWatchPoints[watchPtNum].address,
               dataWatchPoints[watchPtNum].size,
               maskedBits);
         if (!traceEnable) {
            bdmInterface->writeMemory(4, 4, DEMCR, getData4x8Le(DEMCR_TRCENA));
            traceEnable = true;
         }
         bdmInterface->writeMemory(4, 4, DWT_COMP0+16*watchPtNum,     getData4x8Le(dataWatchPoints[watchPtNum].address));
         bdmInterface->writeMemory(4, 4, DWT_MASK0+16*watchPtNum,     getData4x8Le(maskedBits));
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
   LOGGING_F;
   MemoryBreakInfo *bpPtr;
   if (!breakpointsActive) {
      // No breakpoints to remove from target
      return;
   }
   // Memory breakpoints
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      if (bpPtr->inUse) {
         log.print("De-activating: %s@%08X\n", getBreakpointName(BreakType_softwareBreak), bpPtr->address);
         bdmInterface->writeMemory(sizeof(haltOpcode),sizeof(haltOpcode),bpPtr->address,bpPtr->opcode);
      }
   }
   // Hardware breakpoints
   bdmInterface->writeMemory(4, 4, FP_CTRL, getData4x8Le(FP_CTRL_DISABLE));
   breakpointsActive = false;
}

/** RAM based breakpoints leave the PC pointing at the instruction following
 *  the HALT instruction.  This routine checks for this situation and adjusts
 *  the target PC.
 */
void GdbBreakpoints_ARM::checkAndAdjustBreakpointHalt(void) {
   LOGGING_Q;
   unsigned long pcAddress;
   unsigned char currentInstruction[2];
   bdmInterface->readPC(&pcAddress);
   bdmInterface->readMemory(MS_Word, 2, pcAddress, currentInstruction);
   if ((currentInstruction[0] == haltOpcode[0]) && (currentInstruction[1] == haltOpcode[1])) {
      // Adjust location for hosted BKPT #0xAB
      pcAddress += 2;
      log.print("- adjusting PC=%08lX\n", pcAddress);
      bdmInterface->writePC(pcAddress);
   }
}

// Initialise Breakpoint before first use
//
USBDM_ErrorCode GdbBreakpoints_ARM::initBreakpoints() {
   LOGGING;

   clearAllBreakpoints();

   maxNumHardwareBreakPoints = 0;
   maxNumDataWatches         = 0;

   uint32_t fp_ctrl_value = readU32(FP_CTRL);
   maxNumHardwareBreakPoints = FP_CTRL_NUM_CODE(fp_ctrl_value);
   if (maxNumHardwareBreakPoints>MAX_HARDWARE_BREAKPOINTS) {
      maxNumHardwareBreakPoints = MAX_HARDWARE_BREAKPOINTS;
   }
   log.print("FP_CTRL = 0x%08X, Number of Hardware breakpoints = %d\n", fp_ctrl_value, maxNumHardwareBreakPoints);

   // Enable DWT and ITM unit
   bdmInterface->writeMemory(4, 4, DEMCR, getData4x8Le(DEMCR_TRCENA));

   uint32_t dwt_ctrl_value = readU32(DWT_CTRL);
   maxNumDataWatches = DWT_CTRL_NUMCOMP(dwt_ctrl_value);
   if (maxNumDataWatches>MAX_DATA_WATCHES) {
      maxNumDataWatches = MAX_DATA_WATCHES;
   }
   log.print("DWT_CTRL = 0x%08X, Number of Data watchpoints = %d\n", dwt_ctrl_value, maxNumDataWatches);
   return BDM_RC_OK;
}

/**
 * Find a hardware watchpoint that has been matched
 *
 * @param[out] address    Updated with watchpoint address if found
 * @param[out] breakType  Updated with type of watchpoint if found
 *
 * @return true  => Watchpoint has been matched since last checked.
 * @return false => Watchpoint has not been matched since last checked.
 */
bool GdbBreakpoints_ARM::findMatchedDataWatchPoint(uint32_t &address, BreakType &breakType) {
   LOGGING;
   for (unsigned bpNum = 0; bpNum<maxNumDataWatches; bpNum++) {
      DataBreakInfo *bpPtr = dataWatchPoints+bpNum;
      if (bpPtr->inUse) {
         // Check for match on target
         uint32_t dwt_function = readU32(DWT_FUNCTION0+16*bpNum);
         if (dwt_function&DWT_FUNCTION_MATCHED) {
            uint32_t dwt_comp = readU32(DWT_COMP0+16*bpNum);
            uint32_t dwt_mask = readU32(DWT_MASK0+16*bpNum);

            // Return watch type
            switch (dwt_function&DWT_FUNCTION_MASK) {
               case DWT_FUNCTION_READ_WATCH:    breakType = BreakType_readWatch;   break;
               case DWT_FUNCTION_WRITE_WATCH:   breakType = BreakType_writeWatch;  break;
               case DWT_FUNCTION_RW_WATCH:      breakType = BreakType_accessWatch; break;
               default : continue;
            }
            // Return watch address
            address = dwt_comp;

            log.error("bp#%d: dwt_function=0x%08X (match)\n", bpNum, dwt_function);
            log.error("bp#%d: dwt_comp    =0x%08X\n", bpNum, dwt_comp);
            log.error("bp#%d: dwt_mask    =0b%08X\n", bpNum, dwt_mask);

            if (dwt_comp != bpPtr->address) {
               log.error("Unexpected match address. Found 0x%08X, Expected 0x%08X", dwt_comp, bpPtr->address);
            }
            return true;
         }
      }
   }
   return false;
}

int  GdbBreakpoints_ARM::getNumberOfHardwareBreakpoints() {
   return maxNumHardwareBreakPoints;
}

int  GdbBreakpoints_ARM::getNumberOfHardwareWatches() {
   return maxNumDataWatches;
}
