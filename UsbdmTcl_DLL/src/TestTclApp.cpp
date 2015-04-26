/*
 * TestTclApp.cpp
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterfaceFactory.h"
#include "UsbdmTclInterpreterFactory.h"
#include <string>
#include <fstream>
#include <streambuf>

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("ExampleApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
//      UsbdmSystem::Log::closeLogFile();
   }
};

//char const *script =
//      "proc a {} {\n"
//      "  puts \"hello from proc a\"\n"
//      "}\n"
//      "proc b {} {\n"
//      "  puts \"hello from proc b\"\n"
//      "}\n"
//      "proc c {} {\n"
//      "  puts \"hello from proc c\"\n"
//      "  a\n"
//      "  b\n"
//      "}\n"
//      "proc d {} {\n"
//      "  puts \"hello from proc c\"\n"
//      "  a\n"
//      "  bb\n"
//      "}\n"
//      ;

int main(void) {
   OpenLog openLog;
   LOGGING;

   std::ifstream t("Kinetis-KExx-flash-scripts.tcl");
   std::string script((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

   log.print("Creating BdmInterfacePtr\n");
   BdmInterfacePtr bdmInterface = BdmInterfaceFactory::createInterface(T_ARM);
   bdmInterface->initBdm();

   log.print("Creating UsbdmTclInterperPtr\n");
   UsbdmTclInterperPtr p = UsbdmTclInterperFactory::createUsbdmTclInterper(bdmInterface);

   log.print("evalTclScript - \n[script]\n");
   p->evalTclScript(script.c_str());
   log.print("getTclResult - \n[%s]\n", p->getTclResult());

   log.print("evalTclScript - \n[%s]\n", "initTarget \"\"");
   p->evalTclScript("initTarget \"\"");
   log.print("getTclResult - \n[%s]\n", p->getTclResult());

   log.print("evalTclScript - \n[%s]\n", "massEraseTarget");
   p->evalTclScript("massEraseTarget");
   log.print("getTclResult - \n[%s]\n", p->getTclResult());

//   log.print("evalTclScript - \n[%s]\n", script);
//   p->evalTclScript(script.c_str());
//
//   log.print("evalTclScript - \n[puts \"hello\"\n a]\n");
//   p->evalTclScript("puts \"hello\"\n a");
//
//   log.print("evalTclScript - \n[puts \"hello\"\n b]\n");
//   p->evalTclScript("puts \"hello\"\n b");
//
//   log.print("evalTclScript - \n[puts \"hello\"\n c]\n");
//   p->evalTclScript("puts \"hello\"\n c");
//
//   log.print("evalTclScript - \n[puts \"hello\"\n d]\n");
//   p->evalTclScript("puts \"hello\"\n d");

   return 0;
}
