/*
 * GdbBreakpoints.h
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBBREAKPOINTS_H_
#define SRC_GDBBREAKPOINTS_H_

#include <stdint.h>

#include "USBDM_API.h"
#include "BdmInterface.h"

class GdbBreakpoints {
public:
   GdbBreakpoints(BdmInterfacePtr bdmInterface);
   virtual ~GdbBreakpoints();

   typedef enum {
      BreakType_softwareBreak,    /// Execution breakpoint implemented as SWI in RAM
      BreakType_hardwareBreak,    /// Execution breakpoint implemented by hardware
      BreakType_writeWatch,       /// Data write watch-point implemented in hardware
      BreakType_readWatch,        /// Data read watch-point implemented in hardware
      BreakType_accessWatch       /// Data access watch-point implemented in hardware
   } BreakType;

   virtual void            activateBreakpoints(void) = 0;
   virtual void            deactivateBreakpoints(void) = 0;
   virtual void            checkAndAdjustBreakpointHalt(void) = 0;
   virtual USBDM_ErrorCode initBreakpoints() = 0;

   /**
    * Clear all breakpoint entries
    */
   virtual void            clearAllBreakpoints(void);
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
   virtual int             insertBreakpoint(BreakType type, uint32_t address, unsigned size);
   /**
    * Remove breakpoint
    *
    * @param type     one of memoryBreak, hardBreak, writeWatch, readWatch, accessWatch
    * @param address  address for breakpoint/watchpoint
    * @param size     not used
    */
   virtual int             removeBreakpoint(BreakType type, uint32_t address, unsigned size);
   /**
    * Used to notify that the breakpoints have been removed from target by an outside event e.g. VLLSx Modes Exit
    */
   virtual void            notifyBreakpointsMadeInactive();
   /**
    * Check if memory instruction breakpoint at given address
    *
    * @param pcAddress  Address to check
    *
    * @return true  => Breakpoint exists at the address
    * @return false => No breakpoint exists at the address
    */
   virtual bool            atMemoryBreakpoint(unsigned long  pcAddress);
   /**
    * Check if there is a breakpoint at given address
    *
    * @param address
    *
    * @return
    */
   virtual bool            atBreakpoint(uint32_t address);

   /**
    * Find a hardware watchpoint that has been matched
    *
    * @param[out] address    Updated with watchpoint address if found
    * @param[out] breakType  Updated with type of watchpoint found
    *
    * @return true  => Watchpoint has been matched since last checked.
    * @return false => Watchpoint has not been matched since last checked.
    */
   virtual bool  findMatchedDataWatchPoint(uint32_t &address, BreakType &breakType) = 0;

   /**
    * Get name describing breakpoint type
    *
    * @param type Type to get name of
    *
    * @return Name of type (Pointer to static string)
    */
   static  const char     *getBreakpointName(BreakType type);
   /**
    * Get name describing breakpoint type as used by GDB
    *
    * @param type Type to get name of
    *
    * @return Name of type (Pointer to static string)
    */
   static  const char     *getGdbBreakpointName(BreakType type);
   /**
    * Get number of hardware instruction breakpoint available in target
    *
    * @return Number available
    */
   virtual int             getNumberOfHardwareBreakpoints() = 0;
   /**
    * Get number of hardware watches available in target
    *
    * @return Number available
    */
   virtual int             getNumberOfHardwareWatches() = 0;

protected:
   static const unsigned MAX_MEMORY_BREAKPOINTS   = 10;
   static const unsigned MAX_HARDWARE_BREAKPOINTS = 10;
   static const unsigned MAX_DATA_WATCHES         = 16;

   unsigned maxNumHardwareBreakPoints;
   unsigned maxNumDataWatches;

   typedef struct {
      bool  inUse;
      uint32_t   address;
      uint8_t    opcode[2];
   } MemoryBreakInfo;

   typedef struct {
      bool  inUse;
      uint32_t   address;
   } HardwareBreakInfo;

   typedef struct {
      bool        inUse;
      BreakType   type;
      uint32_t    address;
      uint32_t    size;
   } DataBreakInfo;

   MemoryBreakInfo    memoryBreakpoints[MAX_MEMORY_BREAKPOINTS];
   HardwareBreakInfo  hardwareBreakpoints[MAX_HARDWARE_BREAKPOINTS];
   DataBreakInfo      dataWatchPoints[MAX_DATA_WATCHES];

   /// Indicates breakpoints are active in target
   bool               breakpointsActive;
   BdmInterfacePtr    bdmInterface;

   /**
    * Clear all memory instruction breakpoint entries
    */
   void               clearAllMemoryBreakpoints(void);
   /**
    * Check if there is a memory instruction breakpoint at the given address
    *
    * @param address Address to check
    *
    * @return Breakpoint entry or nullptr of not found
    */
   MemoryBreakInfo   *findMemoryBreakpoint(uint32_t address);
   /**
    * Find a free memory instruction breakpoint entry
    *
    * @return Pointer to free entry or nullptr if none available
    */
   MemoryBreakInfo   *findFreeMemoryBreakpoint(void);
   /**
    * Clear all hardware instruction breakpoint entries
    */
   void               clearAllHardwareBreakpoints(void);
   /**
    * Check there is a hardware instruction breakpoint at the given address
    *
    * @param address
    *
    * @return Breakpoint ptr or null of not found
    */
   HardwareBreakInfo *findHardwareBreakpoint(uint32_t address);
   /**
    * Find a free hardware instruction breakpoint entry
    *
    * @return Pointer to free entry or nullptr if none available
    */
   HardwareBreakInfo *findFreeHardwareBreakpoint(void);
   /**
    * Clear all hardware watchpoint entries
    */
   void               clearAllDataWatchPoints(void);
   /**
    * Check if there is a hardware watchpoint at the given address
    *
    * @param address Address to check
    *
    * @return Breakpoint entry or nullptr of not found
    */
   DataBreakInfo     *findDataWatchPoint(uint32_t address);
   /**
    * Find a free hardware watchpoint breakpoint entry
    *
    * @return Pointer to free entry or nullptr if none available
    */
   DataBreakInfo     *findFreeDataWatchPoint(void);

};

#endif /* SRC_GDBBREAKPOINTS_H_ */
