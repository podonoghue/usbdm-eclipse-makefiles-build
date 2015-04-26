/*
 * GdbBreakpoints.cpp
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#include <memory.h>

#include "GdbBreakpoints.h"
#include "UsbdmSystem.h"

GdbBreakpoints::GdbBreakpoints(BdmInterfacePtr bdmInterface) : bdmInterface(bdmInterface) {
   breakpointsActive          = false;
   maxNumDataWatches          = 0;
   maxNumHardwareBreakPoints  = 0;
   memset(memoryBreakpoints,   0, sizeof(memoryBreakpoints));
   memset(hardwareBreakpoints, 0, sizeof(hardwareBreakpoints));
   memset(dataWatchPoints,     0, sizeof(dataWatchPoints));
}

GdbBreakpoints::~GdbBreakpoints() {
}

const char *GdbBreakpoints::getBreakpointName(BreakType type) {
static const char *names[] = {
      "memoryBreak", "hardBreak", "writeWatch", "readWatch", "accessWatch"
};
const char *typeName = "Invalid";

   if ((unsigned)type < sizeof(names)/sizeof(names[0]))
      typeName = names[type];
   return typeName;
}

void GdbBreakpoints::clearAllBreakpoints(void) {
   clearAllMemoryBreakpoints();
   clearAllHardwareBreakpoints();
   clearAllDataWatchPoints();
}

//===========================================================
// RAM based software breakpoints based on HALT instruction
//

void GdbBreakpoints::clearAllMemoryBreakpoints(void) {
   MemoryBreakInfo *bpPtr;
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

GdbBreakpoints::MemoryBreakInfo *GdbBreakpoints::findMemoryBreakpoint(uint32_t address) {
   LOGGING_Q;
   MemoryBreakInfo *bpPtr;
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
//      if (bpPtr->inUse)
//         log.print(" - checking PC=0x%08X against 0x%08X\n",
//                           address, bpPtr->address);
      if (bpPtr->inUse && (bpPtr->address == address))
         return bpPtr;
   }
   return NULL;
}

bool GdbBreakpoints::atMemoryBreakpoint(unsigned long  pcAddress) {
   return (findMemoryBreakpoint(pcAddress) != NULL);
}

GdbBreakpoints::MemoryBreakInfo *GdbBreakpoints::findFreeMemoryBreakpoint(void) {
   LOGGING_Q;
   MemoryBreakInfo *bpPtr;
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      if (!bpPtr->inUse)
         return bpPtr;
   }
   log.print(" - no free breakpoints\n");
   return NULL;
}

//================================================================
// Hardware PC breakpoints using breakpoint hardware
//

void GdbBreakpoints::clearAllHardwareBreakpoints(void) {
   HardwareBreakInfo *bpPtr;
   for (bpPtr = hardwareBreakpoints;
        bpPtr < hardwareBreakpoints+MAX_HARDWARE_BREAKPOINTS;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

GdbBreakpoints::HardwareBreakInfo *GdbBreakpoints::findHardwareBreakpoint(uint32_t address) {
   HardwareBreakInfo *bpPtr;
   for (bpPtr = hardwareBreakpoints;
        bpPtr < hardwareBreakpoints+maxNumHardwareBreakPoints;
        bpPtr++) {
//      if (bpPtr->inUse)
//         log.print("- checking PC=0x%08X against 0x%08X\n",
//                           address, bpPtr->address);
      if (bpPtr->inUse && (bpPtr->address == address))
         return bpPtr;
   }
//   log.print("- not found\n");
   return NULL;
}

GdbBreakpoints::HardwareBreakInfo *GdbBreakpoints::findFreeHardwareBreakpoint(void) {
   LOGGING_Q;
   HardwareBreakInfo *bpPtr;
   for (bpPtr = hardwareBreakpoints;
        bpPtr < hardwareBreakpoints+maxNumHardwareBreakPoints;
        bpPtr++) {
      if (!bpPtr->inUse)
         return bpPtr;
   }
   log.print(" - no free breakpoints\n");
   return NULL;
}

bool GdbBreakpoints::atBreakpoint(uint32_t address) {
   return (findHardwareBreakpoint(address) != 0) || (findMemoryBreakpoint(address) != 0);
}

//================================================================
// Hardware data read/write/access watchpoint
//
void GdbBreakpoints::clearAllDataWatchPoints(void) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+MAX_DATA_WATCHES;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

GdbBreakpoints::DataBreakInfo *GdbBreakpoints::findDataWatchPoint(uint32_t address) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+maxNumDataWatches;
        bpPtr++) {
      if (bpPtr->inUse && (bpPtr->address == address))
         return bpPtr;
   }
   return NULL;
}

GdbBreakpoints::DataBreakInfo *GdbBreakpoints::findFreeDataWatchPoint(void) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+maxNumDataWatches;
        bpPtr++) {
      if (!bpPtr->inUse)
         return bpPtr;
   }
   return NULL;
}

//! Insert breakpoint
//!
//! @param type     one of memoryBreak, hardBreak, writeWatch, readWatch, accessWatch
//! @param address  address for breakpoint/watchpoint
//! @param size     range to watch (watchpoint only)
//!
//! @return true  => OK\n
//!         false => error
//!
//! @note writeWatch, readWatch, accessWatch not currently working
//!
int GdbBreakpoints::insertBreakpoint(BreakType type, uint32_t address, unsigned size) {
   LOGGING_Q;
   log.print("(%s, a=%08X, s=%d)\n", getBreakpointName(type), address, size);

   switch (type) {
   case memoryBreak: {
      if (findMemoryBreakpoint(address)) {
         log.print("- already set - ignored\n");
         return true; // Already set - ignore
      }
      MemoryBreakInfo *bpPtr = findFreeMemoryBreakpoint();
      if (bpPtr == NULL) {
         return false; // Too many breakpoints
      }
      bpPtr->address = address;
      bpPtr->inUse   = true;
      return true; // Done
      }
      break;
   case hardBreak: {
      if (findHardwareBreakpoint(address)) {
         log.print("- already set - ignored\n");
         return true; // Already set - ignore
      }
      HardwareBreakInfo *bpPtr = findFreeHardwareBreakpoint();
      if (bpPtr == NULL) {
         return false; // Too many breakpoints
      }
      bpPtr->address = address;
      bpPtr->inUse   = true;
      return true; // Done
      }
      break;
   case writeWatch:
   case readWatch:
   case accessWatch: {
      DataBreakInfo *bpPtr = findDataWatchPoint(address);
      if (bpPtr != NULL) {
         if (size > bpPtr->size)
            bpPtr->size = size;
         if (type != bpPtr->type)
            bpPtr->type = accessWatch;
         return true; // Already set - update
      }
      bpPtr = findFreeDataWatchPoint();
      if (bpPtr == NULL) {
         return false; // Too many breakpoints
      }
      bpPtr->address = address;
      bpPtr->size    = size;
      bpPtr->type    = (BreakType)type;
      bpPtr->inUse   = true;
      return true; // Done
      }
      break;
   default:
      return false; // Unknown type
   }
}

//! Remove breakpoint
//!
//! @param type     one of memoryBreak, hardBreak, writeWatch, readWatch, accessWatch
//! @param address  address for breakpoint/watchpoint
//! @param size     not used
//!
int GdbBreakpoints::removeBreakpoint(BreakType type, uint32_t address, unsigned size) {
   LOGGING_Q;
   log.print("(%s, a=%08X, s=%d)\n", getBreakpointName(type), address, size);
   switch (type) {
   case memoryBreak: {
      MemoryBreakInfo *bpPtr = findMemoryBreakpoint(address);
      if (bpPtr == NULL) {
         return false; // Non-existent breakpoint
      }
      bpPtr->inUse     = false;
      bpPtr->address   = 0;
      bpPtr->opcode[0] = 0;
      bpPtr->opcode[1] = 0;
      log.print("(t=MEM, a=%08X, s=%d) - done\n", address, size);
      return true; // Done
   }
   break;
   case hardBreak: {
      HardwareBreakInfo *bpPtr = findHardwareBreakpoint(address);
      if (bpPtr == NULL) {
         return false; // Non-existent breakpoint
      }
      bpPtr->inUse     = false;
      log.print("(t=HW, a=%08X, s=%d) - done\n", address, size);
      return true; // Done
      }
      break;
   case writeWatch:
   case readWatch:
   case accessWatch: {
      DataBreakInfo *bpPtr = findDataWatchPoint(address);
      if (bpPtr == NULL) {
         return false; // Non-existent breakpoint
      }
      bpPtr->inUse     = false;
      return true; // Done
      }
      break;
   default:
      return false; // Unknown type
   }
}

/**!
 * Used to notify that the breakpoints have been clear by an outside event
 *
 */
void GdbBreakpoints::notifyBreakpointsCleared() {
   breakpointsActive = false;
}

