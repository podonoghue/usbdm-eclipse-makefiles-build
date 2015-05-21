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

   UsbdmTclInterperPtr ti = UsbdmTclInterperFactory::createInteractiveTclInterper(BdmInterfaceFactory::createInterface(T_OFF));
   ti->main(argc, argv);
}
#endif


