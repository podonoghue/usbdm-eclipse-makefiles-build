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

   virtual void activateBreakpoints(void) override;
   virtual void deactivateBreakpoints(void) override;
   virtual void checkAndAdjustBreakpointHalt(void) override;
   virtual USBDM_ErrorCode initBreakpoints() override;
   virtual int  getNumberOfHardwareBreakpoints() override;
   virtual int  getNumberOfHardwareWatches() override;
   /**
    * Find a hardware watchpoint that has been matched
    *
    * @param[out] address    Updated with watchpoint address if found
    * @param[out] breakType  Updated with type of watchpoint if found
    *
    * @return true  => Watchpoint has been matched since last checked.
    * @return false => Watchpoint has not been matched since last checked.
    */
    virtual bool findMatchedDataWatchPoint(uint32_t &address, BreakType &breakType) override;

protected:
    /**
     * Converts an array of 4 uint8_t values in litteEndian order to a uint32_t
     *
     * @param data - value to convert
     *
     * @return ptr to static buffer containing value
     */
    uint32_t getU32Le(uint8_t data[]) {
       return data[0]+(data[1]<<8)+(data[2]<<16)+(data[3]<<24);
    }

    /**
     * Read a 32-bit value from target memory
     *
     * @param address Address to read from
     *
     * @return 32-bit value
     */
    uint32_t readU32(uint32_t address) {
       // Check for match on target
       uint8_t data[4];
       bdmInterface->readMemory(4, 4, address, data);
       return getU32Le(data);
    };
};

#endif /* SRC_GDBBREAKPOINTS_ARM_H_ */
