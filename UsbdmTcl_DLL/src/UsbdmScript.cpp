/*
 * UsbdmScript.cpp
 *
 *  Created on: 17 Apr 2015
 *      Author: podonoghue
 */

#include "UsbdmTclInterpreterFactory.h"
#include "BdmInterfaceFactory.h"

/*
 * ===========================================================
 */
#ifdef INTERACTIVE

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("UsbdmScript.log", "USBDM TCL Interpreter");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
//      UsbdmSystem::Log::closeLogFile();
   }
};

/*
 * ===========================================================
 */

int main(int argc, char *argv[]) {
   OpenLog ol;
   LOGGING;
   log.print("Creating TCL interpreter\n");
   UsbdmTclInterperPtr ti = UsbdmTclInterperFactory::createInteractiveUsbdmTclInterpreter(BdmInterfaceFactory::createInterface(T_OFF));
   log.print("Creating TCL interpreter - done\n");
   ti->main(argc, argv);
   log.print("ti->main() completed\n");
}
#endif


