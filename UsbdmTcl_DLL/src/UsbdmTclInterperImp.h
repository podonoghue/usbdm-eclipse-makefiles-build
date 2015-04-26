/*
 * UsbdmTclInterperImp.h
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_USBDMTCLINTERPERIMP_H_
#define SRC_USBDMTCLINTERPERIMP_H_

#include "UsbdmTclInterper.h"

#include <stdio.h>
#include <tr1/memory>

#include "BdmInterfaceFactory.h"

#include "tcl.h"

class UsbdmTclInterperImp: public UsbdmTclInterper {

public:
   virtual USBDM_ErrorCode  evalTclScript(const char *script);
   virtual const char      *getTclResult();
   virtual int              main(int argc, char *argv[]);

   UsbdmTclInterperImp(BdmInterfacePtr bdmInterface);
   UsbdmTclInterperImp();
   virtual ~UsbdmTclInterperImp();

protected:
   std::tr1::shared_ptr<Tcl_Interp>  interp;
   Tcl_Channel                       tclChannel;       // Used as a TCL channel for STDERR & STDOUT
   FILE                             *logFile;          // TCL logging?

   static void    registerUSBDMCommands(Tcl_Interp *interp);
   static int     appInitProc(Tcl_Interp *interp);
   static int     setTCLExecutable();
};

typedef std::tr1::shared_ptr<UsbdmTclInterper> UsbdmTclInterperPtr;

#endif /* SRC_USBDMTCLINTERPERIMP_H_ */
