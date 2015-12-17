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
   /**
    * Evaluates a TCL script
    *
    * @param script String containing the script to evaluate in the interpreter
    */
   virtual USBDM_ErrorCode  evalTclScript(const char *script);
   /**
    * @param interp Interpreter to get result from
    *
    * @return a point to the result string (a static buffer)
    */
   virtual const char      *getTclResult();
   /**
    * Main function used for interactive TCL interpreter
    */
   virtual int              main(int argc, char *argv[]);
   /**
    * Create instance of the TCL interpreter
    *
    * @param doInit - Used to suppress initialisation. Should be true if used with
    *                 UsbdmTclInterpreterImp::main() for shell as it does its own initialisation
    */
   UsbdmTclInterpreterImp(bool doInit=true);
   /**
    * Destructor
    */
   virtual ~UsbdmTclInterpreterImp();
   /**
    * Set BDM interface to use to communication with BDM
    *
    * @param bdmInterface The interface
    * @param doRedirect   Redirect stdout to log file or nul if no log file open
    */
   virtual void setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut);
   /**
    * Redirect stdout to log file or nul if no log file open
    */
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
   /**
    * Get the unique interactive interpreter
    *
    * @return Smart pointer to interpreter
    */
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
   /**
    * Register USBDM commands in TCL interpreter
    *
    * @param interp The interpreter to use
    */
   static void    registerUSBDMCommands(Tcl_Interp *interp);
   /**
    * Callback use for TCL interpreter
    *
    * @param interp The interpreter to use
    */
   static int     appInitProc(Tcl_Interp *interp);
   /**
    * Does setup for TCL interpreter
    */
   static int     setTCLExecutable();
   /**
    * Smart pointer callback to do clean up of TCL interpreter
    *
    * @param interp The interpreter
    */
   static void    deleteInterpreter(Tcl_Interp *interp);
};

typedef std::tr1::shared_ptr<UsbdmTclInterpreter> UsbdmTclInterperPtr;

#endif /* SRC_USBDM_TCL_INTERPRETER_IMP_H_ */
