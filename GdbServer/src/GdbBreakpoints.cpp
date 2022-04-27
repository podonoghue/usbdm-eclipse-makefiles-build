/*
 * GdbBreakpoints.cpp
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#include <memory.h>

#include "GdbBreakpoints.h"
#include "UsbdmSystem.h"

/**
 * Constructor
 *
 * @param bdmInterface
 */
GdbBreakpoints::GdbBreakpoints(BdmInterfacePtr bdmInterface) : bdmInterface(bdmInterface) {
   breakpointsActive          = false;
   maxNumDataWatches          = 0;
   maxNumHardwareBreakPoints  = 0;
   memset(memoryBreakpoints,   0, sizeof(memoryBreakpoints));
   memset(hardwareBreakpoints, 0, sizeof(hardwareBreakpoints));
   memset(dataWatchPoints,     0, sizeof(dataWatchPoints));
}

/**
 * Destructor
 */
GdbBreakpoints::~GdbBreakpoints() {
}

/**
 * Get name describing breakpoint type
 *
 * @param type Type to get name of
 *
 * @return Name of type (Pointer to static string)
 */
const char *GdbBreakpoints::getBreakpointName(BreakType type) {
static const char *names[] = {
      "memoryBreak", "hardBreak", "writeWatch", "readWatch", "watch"
};
const char *typeName = "Invalid";

   if ((unsigned)type < sizeof(names)/sizeof(names[0]))
      typeName = names[type];
   return typeName;
}

/**
 * Get name describing breakpoint type as used by GDB
 *
 * @param type Type to get name of
 *
 * @return Name of type (Pointer to static string)
 */
const char *GdbBreakpoints::getGdbBreakpointName(BreakType type) {
static const char *names[] = {
      "swbreak", "hwbreak", "watch", "rwatch", "awatch"
};
const char *typeName = "Invalid";

   if ((unsigned)type < sizeof(names)/sizeof(names[0]))
      typeName = names[type];
   return typeName;
}

/**
 * Clear all breakpoint entries
 */
void GdbBreakpoints::clearAllBreakpoints(void) {
   clearAllMemoryBreakpoints();
   clearAllHardwareBreakpoints();
   clearAllDataWatchPoints();
}

//===========================================================
// RAM based software breakpoints based on HALT instruction
//

/**
 * Clear all memory instruction breakpoint entries
 */
void GdbBreakpoints::clearAllMemoryBreakpoints(void) {
   MemoryBreakInfo *bpPtr;
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

/**
 * Check if there is a memory instruction breakpoint at the given address
 *
 * @param address Address to check
 *
 * @return Breakpoint entry or nullptr of not found
 */
GdbBreakpoints::MemoryBreakInfo *GdbBreakpoints::findMemoryBreakpoint(uint32_t address) {
   LOGGING_Q;
   MemoryBreakInfo *bpPtr;
   for (bpPtr = memoryBreakpoints;
        bpPtr < memoryBreakpoints+MAX_MEMORY_BREAKPOINTS;
        bpPtr++) {
      if (bpPtr->inUse && (bpPtr->address == address))
         return bpPtr;
   }
   return nullptr;
}

/**
 * Check if memory instruction breakpoint at given address
 *
 * @param pcAddress  Address to check
 *
 * @return true  => Breakpoint exists at the address
 * @return false => No breakpoint exists at the address
 */
bool GdbBreakpoints::atMemoryBreakpoint(unsigned long  pcAddress) {
   return (findMemoryBreakpoint(pcAddress) != nullptr);
}

/**
 * Find a free memory instruction breakpoint entry
 *
 * @return Pointer to free entry or nullptr if none available
 */
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
   return nullptr;
}

//================================================================
// Hardware PC breakpoints using breakpoint hardware
//

/**
 * Clear all hardware instruction breakpoint entries
 */
void GdbBreakpoints::clearAllHardwareBreakpoints(void) {
   HardwareBreakInfo *bpPtr;
   for (bpPtr = hardwareBreakpoints;
        bpPtr < hardwareBreakpoints+MAX_HARDWARE_BREAKPOINTS;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

/**
 * Check there is a hardware instruction breakpoint at the given address
 *
 * @param address
 *
 * @return Breakpoint ptr or null of not found
 */
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
   return nullptr;
}

/**
 * Find a free hardware instruction breakpoint entry
 *
 * @return Pointer to free entry or nullptr if none available
 */
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
   return nullptr;
}

/**
 * Check if there is a instruction breakpoint at given address
 *
 * @param address
 *
 * @return
 */
bool GdbBreakpoints::atBreakpoint(uint32_t address) {
   return (findHardwareBreakpoint(address) != 0) || (findMemoryBreakpoint(address) != 0);
}

//================================================================
// Hardware data read/write/access watchpoint
//
/**
 * Clear all hardware watchpoint entries
 */
void GdbBreakpoints::clearAllDataWatchPoints(void) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+MAX_DATA_WATCHES;
        bpPtr++) {
      bpPtr->inUse = false;
   }
}

/**
 * Check if there is a hardware watchpoint at the given address
 *
 * @param address Address to check
 *
 * @return Breakpoint entry or nullptr of not found
 */
GdbBreakpoints::DataBreakInfo *GdbBreakpoints::findDataWatchPoint(uint32_t address) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+maxNumDataWatches;
        bpPtr++) {
      if (bpPtr->inUse && (bpPtr->address == address))
         return bpPtr;
   }
   return nullptr;
}

/**
 * Find a free hardware watchpoint breakpoint entry
 *
 * @return Pointer to free entry or nullptr if none available
 */
GdbBreakpoints::DataBreakInfo *GdbBreakpoints::findFreeDataWatchPoint(void) {
   DataBreakInfo *bpPtr;
   for (bpPtr = dataWatchPoints;
        bpPtr < dataWatchPoints+maxNumDataWatches;
        bpPtr++) {
      if (!bpPtr->inUse)
         return bpPtr;
   }
   return nullptr;
}

/**
 * Insert breakpoint
 *
 * @param type     one of memoryBreak, hardBreak, writeWatch, readWatch, accessWatch
 * @param address  address for breakpoint/watchpoint
 * @param size     range to watch (watchpoint only)
 *
 * @return true  => OK\n
 *         false => error
 *
 * @note writeWatch, readWatch, accessWatch not currently working
 */
int GdbBreakpoints::insertBreakpoint(BreakType type, uint32_t address, unsigned size) {
   LOGGING_Q;
   log.print("(%s, a=0x%08X, s=%d)\n", getBreakpointName(type), address, size);
   switch (type) {
   case BreakType_softwareBreak: {
      if (findMemoryBreakpoint(address)) {
         log.print("- already set - ignored\n");
         return true; // Already set - ignore
      }
      MemoryBreakInfo *bpPtr = findFreeMemoryBreakpoint();
      if (bpPtr == nullptr) {
         return false; // Too many breakpoints
      }
      bpPtr->address = address;
      bpPtr->inUse   = true;
      return true; // Done
      }
      break;
   case BreakType_hardwareBreak: {
      if (findHardwareBreakpoint(address)) {
         log.print("- already set - ignored\n");
         return true; // Already set - ignore
      }
      HardwareBreakInfo *bpPtr = findFreeHardwareBreakpoint();
      if (bpPtr == nullptr) {
         return false; // Too many breakpoints
      }
      bpPtr->address = address;
      bpPtr->inUse   = true;
      return true; // Done
      }
      break;
   case BreakType_writeWatch:
   case BreakType_readWatch:
   case BreakType_accessWatch: {
      int first1 = __builtin_ffs(size);
      if ((first1 == 0) || ((size & ~(1<<(first1-1))) != 0)) {
         // Must be a power of 2 in size
         return false;
      }
      DataBreakInfo *bpPtr = findDataWatchPoint(address);
      if (bpPtr != nullptr) {
         bpPtr->size = size;
         bpPtr->type = BreakType_accessWatch;
         return true; // Already set - update
      }
      bpPtr = findFreeDataWatchPoint();
      if (bpPtr == nullptr) {
         log.error("Too many watchpoints");
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
/**
 * Remove breakpoint
 *
 * @param type     one of memoryBreak, hardBreak, writeWatch, readWatch, accessWatch
 * @param address  address for breakpoint/watchpoint
 * @param size     not used
 */
int GdbBreakpoints::removeBreakpoint(BreakType type, uint32_t address, unsigned size) {
   LOGGING_Q;
   log.print("(%s, a=0x%08X, s=%d)\n", getBreakpointName(type), address, size);
   switch (type) {
   case BreakType_softwareBreak: {
      MemoryBreakInfo *bpPtr = findMemoryBreakpoint(address);
      if (bpPtr == nullptr) {
         return false; // Non-existent breakpoint
      }
      bpPtr->inUse     = false;
      bpPtr->address   = 0;
      bpPtr->opcode[0] = 0;
      bpPtr->opcode[1] = 0;
//      log.print("(%s, a=%08X, s=%d) - done\n", getBreakpointName(type), address, size);
      return true; // Done
   }
   break;
   case BreakType_hardwareBreak: {
      HardwareBreakInfo *bpPtr = findHardwareBreakpoint(address);
      if (bpPtr == nullptr) {
         return false; // Non-existent breakpoint
      }
      bpPtr->inUse     = false;
//      log.print("(%s, a=%08X, s=%d) - done\n", getBreakpointName(type), address, size);
      return true; // Done
      }
      break;
   case BreakType_writeWatch:
   case BreakType_readWatch:
   case BreakType_accessWatch: {
      DataBreakInfo *bpPtr = findDataWatchPoint(address);
      if (bpPtr == nullptr) {
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

/**
 * Used to notify that the breakpoints have been removed from target by an outside event e.g. reset
 */
void GdbBreakpoints::notifyBreakpointsMadeInactive() {
   breakpointsActive = false;
}

