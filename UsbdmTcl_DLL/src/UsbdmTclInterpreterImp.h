/*
 * UsbdmTclInterpreterImp.h
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_USBDMTCLINTERPRETERIMP_H_
#define SRC_USBDMTCLINTERPRETERIMP_H_

#include "UsbdmTclInterpreter.h"

#include <stdio.h>
#include <tr1/memory>

#include "BdmInterfaceFactory.h"

#include "tcl.h"

class UsbdmTclInterpreterImp: public UsbdmTclInterpreter {

public:
   virtual USBDM_ErrorCode  evalTclScript(const char *script);
   virtual const char      *getTclResult();
   virtual int              main(int argc, char *argv[]);

   UsbdmTclInterpreterImp(bool doInit=true);
   virtual ~UsbdmTclInterpreterImp();
   virtual void setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut);
   virtual void redirectStdOut();

protected:
   std::tr1::shared_ptr<Tcl_Interp>  interp;
   Tcl_Channel                       tclChannel;       // Used as a TCL channel for STDERR & STDOUT

   static void    registerUSBDMCommands(Tcl_Interp *interp);
   static int     appInitProc(Tcl_Interp *interp);
   static int     setTCLExecutable();
   static void    deleteInterpreter(Tcl_Interp *interp);
};

typedef std::tr1::shared_ptr<UsbdmTclInterpreter> UsbdmTclInterperPtr;

#endif /* SRC_USBDMTCLINTERPRETERIMP_H_ */
