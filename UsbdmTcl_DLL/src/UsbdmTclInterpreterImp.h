/*
 * UsbdmTclInterpreterImp.h
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_USBDM_TCL_INTERPRETER_IMP_H_
#define SRC_USBDM_TCL_INTERPRETER_IMP_H_

#include "UsbdmTclInterpreter.h"

#include <stdio.h>
#include <tr1/memory>
#include <tcl.h>
#include <map>

#include "BdmInterfaceFactory.h"

class UsbdmTclInterpreterImp: public UsbdmTclInterpreter {

public:
   virtual USBDM_ErrorCode  evalTclScript(const char *script);
   virtual const char      *getTclResult();
   virtual int              main(int argc, char *argv[]);

   UsbdmTclInterpreterImp(bool doInit=true);
   virtual ~UsbdmTclInterpreterImp();
   virtual void setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut);
   virtual void redirectStdOut();

   /**
    * Indicates if this is the single interactive interpreter
    */
   virtual bool isInteractive(void) {
      return interactiveInterpreter.get() == this;
   }

   /**
    * Sets this interpreter as the single interactive interpreter
    */
   virtual void setInteractive(bool isInteractive = true) {
      LOGGING;
      if (interactiveInterpreter != 0) {
         throw new MyException("Only one interpreter may be set as interactive");
      }
      interactiveInterpreter.reset(this);
   }

   static UsbdmTclInterperPtr getInteractiveInterpreter() {
      LOGGING;
      log.print("interactiveInterpreter = %p\n", interactiveInterpreter.get());
      return interactiveInterpreter;
   }

protected:
   std::tr1::shared_ptr<Tcl_Interp>  interp;
   Tcl_Channel                       tclChannel;       // Used as a TCL channel for STDERR & STDOUT

   UsbdmTclInterperPtr tclInterper;
   static UsbdmTclInterperPtr interactiveInterpreter;

   static void    registerUSBDMCommands(Tcl_Interp *interp);
   static int     appInitProc(Tcl_Interp *interp);
   static int     setTCLExecutable();
   static void    deleteInterpreter(Tcl_Interp *interp);
};

typedef std::tr1::shared_ptr<UsbdmTclInterpreter> UsbdmTclInterperPtr;

#endif /* SRC_USBDM_TCL_INTERPRETER_IMP_H_ */
