/*
 * BdmInterfaceARM.h
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACE_CFVx_H_
#define SRC_BDMINTERFACE_CFVx_H_

#include "BdmInterfaceCommon.h"

class BdmInterface_CFVx: public BdmInterfaceCommon {

public:
   BdmInterface_CFVx();
   virtual ~BdmInterface_CFVx();

   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
};

#endif /* SRC_BDMINTERFACE_CFVx_H_ */
