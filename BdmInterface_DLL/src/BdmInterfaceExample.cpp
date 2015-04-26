/*
 * Example.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#include <stdint.h>
#include "BdmInterfaceFactory.h"

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("BdmExampleApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

int main() {
   OpenLog openLog;
   LOGGING;

   log.print("Loading plug-in\n");
   BdmInterfacePtr bdmInterface = BdmInterfaceFactory::createInterface(T_ARM);

   log.print("Initialising BDMn\n");
   bdmInterface->initBdm();
   bdmInterface->connect();

   log.print("Reading PC\n");
   unsigned long pcValue;
   bdmInterface->readPC(&pcValue);
   log.print("Reading Memory\n");
   uint8_t buff[100];
   bdmInterface->readMemory(4, sizeof(buff), 0, buff);

   return 0;
}
