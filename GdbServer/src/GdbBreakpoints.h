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

   typedef enum {memoryBreak, hardBreak, writeWatch, readWatch, accessWatch} BreakType;

   virtual void            activateBreakpoints(void) = 0;
   virtual void            deactivateBreakpoints(void) = 0;
   virtual void            checkAndAdjustBreakpointHalt(void) = 0;
   virtual USBDM_ErrorCode initBreakpoints() = 0;

   virtual void            clearAllBreakpoints(void);
   virtual int             insertBreakpoint(BreakType type, uint32_t address, unsigned size);
   virtual int             removeBreakpoint(BreakType type, uint32_t address, unsigned size);
   virtual void            notifyBreakpointsCleared();
   virtual bool            atMemoryBreakpoint(unsigned long  pcAddress);
   virtual bool            atBreakpoint(uint32_t address);

   static  const char     *getBreakpointName(BreakType type);

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

   bool               breakpointsActive;
   BdmInterfacePtr    bdmInterface;

   void               clearAllMemoryBreakpoints(void);
   MemoryBreakInfo   *findMemoryBreakpoint(uint32_t address);
   MemoryBreakInfo   *findFreeMemoryBreakpoint(void);
   void               clearAllHardwareBreakpoints(void);
   HardwareBreakInfo *findHardwareBreakpoint(uint32_t address);
   HardwareBreakInfo *findFreeHardwareBreakpoint(void);
   void               clearAllDataWatchPoints(void);
   DataBreakInfo     *findDataWatchPoint(uint32_t address);
   DataBreakInfo     *findFreeDataWatchPoint(void);
};

#endif /* SRC_GDBBREAKPOINTS_H_ */
