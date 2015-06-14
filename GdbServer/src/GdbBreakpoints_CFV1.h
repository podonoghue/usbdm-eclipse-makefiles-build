/*
 * GdbBreakpointsCFV1.h
 *
 *  Created on: 28 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBBREAKPOINTS_CFV1_H_
#define SRC_GDBBREAKPOINTS_CFV1_H_

#include "GdbBreakpoints.h"

class GdbBreakpoints_CFV1: public GdbBreakpoints {
public:
   GdbBreakpoints_CFV1(BdmInterfacePtr bdmInterface);
   virtual ~GdbBreakpoints_CFV1();

   void activateBreakpoints(void);
   void deactivateBreakpoints(void);
   void checkAndAdjustBreakpointHalt(void);
   USBDM_ErrorCode initBreakpoints();
   int  getNumberOfHardwareBreakpoints();
};

#endif /* SRC_GDBBREAKPOINTS_CFV1_H_ */
