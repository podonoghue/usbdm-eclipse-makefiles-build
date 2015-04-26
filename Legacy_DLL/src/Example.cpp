/*
 * Example.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#include "UsbdmSystem.h"
#ifdef TBDML
#include "TBDML.h"
#endif
#ifdef OSBDM
#include "OpensourceBDM.h"
#endif

using namespace std;

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("Legacy_DLLApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
//      UsbdmSystem::Log::closeLogFile();
   }
};

int main(void) {
   OpenLog openLog;
   LOGGING;

#ifdef TBDML
   int rc = 0;
   do {
      _tbdml_init();
      _tbdml_open(0);
      rc = _tbdml_set_target_type(T_HCS12);
      _tbdml_close();
   } while (rc == 0);
#endif
#ifdef OSBDM
   int rc = 0;
   do {
      _opensourcebdm_init();
      _opensourcebdm_open(0);
      _opensourcebdm_set_target_type(T_HCS08);
      _opensourcebdm_set_target_type(T_CFV1);
      _opensourcebdm_close();
   } while (rc == 0);
#endif

   return 0;
}

