/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_ARM_H_
#define SRC_BDMINTERFACE_ARM_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_ARM : public BdmInterfaceCommon {

public:
   BdmInterface_ARM();
   virtual ~BdmInterface_ARM();

   virtual USBDM_ErrorCode targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retry) override;
   virtual USBDM_ErrorCode writePC(unsigned long regValue) override;
   virtual USBDM_ErrorCode readPC(unsigned long *regValue) override;
   virtual USBDM_ErrorCode setProgrammingMode(bool) override;
};

#endif /* SRC_BDMINTERFACE_ARM_H_ */
