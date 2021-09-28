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

   void activateBreakpoints(void) override;
   void deactivateBreakpoints(void) override;
   void checkAndAdjustBreakpointHalt(void) override;
   USBDM_ErrorCode initBreakpoints() override;
   int  getNumberOfHardwareBreakpoints() override;
   int  getNumberOfHardwareWatches() override;
   /**
    * Find a hardware watchpoint that has been matched
    *
    * @param[out] address    Updated with watchpoint address if found
    * @param[out] breakType  Updated with type of watchpoint found
    *
    * @return true  => Watchpoint has been matched since last checked.
    * @return false => Watchpoint has not been matched since last checked.
    */
    virtual bool  findMatchedDataWatchPoint(uint32_t &address, BreakType &breakType) override;

};

#endif /* SRC_GDBBREAKPOINTS_CFV1_H_ */
