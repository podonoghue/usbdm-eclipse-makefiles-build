/*
 * TestFlashImage.cpp
 *
 *  Created on: 28Dec.,2016
 *      Author: podonoghue
 */

#include "MyException.h"
#include "FlashImageFactory.h"

/*! Check error code from USBDM API function
 *
 *  @param rc - error code to access
 *
 *  An error message is printed with line # and the program exited if rc indicates any error
 */
void check(USBDM_ErrorCode rc, const char *file = NULL, unsigned lineNum = 0) {
   if (rc == BDM_RC_OK) {
//      fprintf(stderr, "OK,     [%s:#%4d]\n", file, lineNum);
      return;
   }
   char buff[1000];
   snprintf(buff, sizeof(buff), "Failed, [%s:#%4d] Reason= %s", file, lineNum,  UsbdmSystem::getErrorString(rc));
   fprintf(stderr, "%s\n", buff);
   UsbdmSystem::Log::print("%s\n", buff);
   throw MyException(buff);
}

/*!
 *  Convenience macro to add line number information to check()
 */
#define CHECK(x) check((x), __FILE__, __LINE__)

class Logger {
public:
   Logger() {
      UsbdmSystem::Log::openLogFile("result.log");
   }
   ~Logger() {
      UsbdmSystem::Log::closeLogFile();
   }
};

string replaceExt(string& ss, const string& newExt) {
   string::size_type i = ss.rfind('.');
   string t(ss);
   if (i != string::npos) {
      t = t.substr(0, i);
   }
   t.append(".");
   return t.append(newExt);
}

int main(int argc, const char *argv[]) {
   Logger logger;

   if (argc<2) {
      CHECK(BDM_RC_ILLEGAL_PARAMS);
   }
   string sourceFilename(argv[1]);
   string destinationFilename;

   if (argc==3) {
      destinationFilename = string(argv[2]);
   }
   else {
      destinationFilename = replaceExt(sourceFilename, string("sx"));
   }
//   fprintf(stderr, "Creating empty flash image\n");
   FlashImagePtr flashImage(FlashImageFactory::createFlashImage(T_S12Z));

//   fprintf(stderr, "Loading image from \'%s\' \n", (const char *)sourceFilename.c_str());
   CHECK(flashImage->loadFile(sourceFilename.c_str(), T_S12Z));

//   fprintf(stderr, "Saving image to \'%s\' \n", (const char *)destinationFilename.c_str());
   fprintf(stderr, "\'%s\' => \'%s\' \n", (const char *)sourceFilename.c_str(), (const char *)destinationFilename.c_str());
   CHECK(flashImage->saveFile(destinationFilename, false));
}
