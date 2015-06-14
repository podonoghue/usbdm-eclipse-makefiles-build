/*
 * GdbBreakpointsARM.h
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBBREAKPOINTS_ARM_H_
#define SRC_GDBBREAKPOINTS_ARM_H_

#include "GdbBreakpoints.h"

class GdbBreakpoints_ARM: public GdbBreakpoints {
public:
   GdbBreakpoints_ARM(BdmInterfacePtr bdmInterface);
   virtual ~GdbBreakpoints_ARM();

   void activateBreakpoints(void);
   void deactivateBreakpoints(void);
   void checkAndAdjustBreakpointHalt(void);
   USBDM_ErrorCode initBreakpoints();
   int  getNumberOfHardwareBreakpoints();
};

#endif /* SRC_GDBBREAKPOINTS_ARM_H_ */
