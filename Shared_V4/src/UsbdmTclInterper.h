/*
 * usbdmTcl.h
 *
 *  Created on: 06/04/2011
 *      Author: podonoghue
 */

#ifndef USBDMTCLINTERPRETER_H_
#define USBDMTCLINTERPRETER_H_

#include "USBDM_API.h"
#include "BdmInterface.h"

class UsbdmTclInterper {

public:
   virtual USBDM_ErrorCode evalTclScript(const char *script) = 0;
   virtual const char *getTclResult() = 0;
   virtual int main(int argc, char *argv[]) = 0;
   virtual ~UsbdmTclInterper() {};

protected:
   UsbdmTclInterper() {};
};

typedef std::tr1::shared_ptr<UsbdmTclInterper> UsbdmTclInterperPtr;

#endif /* USBDMTCLINTERPRETER_H_ */
