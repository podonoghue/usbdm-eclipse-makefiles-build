/*
 * Main.cpp
 *
 *  Created on: 21/10/2011
 *      Author: podonoghue
 *
 *  Simple program demonstrating use of USBDM Higher-level API
 *
 *  The program programs a file to the target device
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "MyException.h"
#include "FlashImageFactory.h"
#include "FlashProgrammerFactory.h"
#include "BdmInterfaceFactory.h"
#include "DeviceInterface.h"
#include "UsbdmWxConstants.h"

/*! Check error code from USBDM API function
 *
 *  @param rc - error code to access
 *
 *  An error message is printed with line # and the program exited if rc indicates any error
 */
void check(USBDM_ErrorCode rc, const char *file = NULL, unsigned lineNum = 0) {
   if (rc == BDM_RC_OK) {
      fprintf(stderr, "OK,     [%s:#%4d]\n", file, lineNum);
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

/*!
 * This callback will cause connections etc to fail quietly on error rather
 * than use a WxWidget dialogue
 */
long nullCallback(std::string message, std::string caption, long style) {
   (void) style;
   fprintf(stderr, "Failing on error message %s:%s\n", caption.c_str(), message.c_str());
   return UsbdmWxConstants::NO;
}

int main(void) {
   Logger logger;
   const TargetType_t TARGET_TYPE = T_ARM;
   const char*        FLASH_IMAGE = "TestMK20.elf";
   const char*        INTERFACE   = "USBDM-OPENSDA-61168";
   const char*        DEVICE      = "FRDM_K20D50M";

   try {
      fprintf(stderr, "Creating interface\n");
      BdmInterfacePtr bdmInterface(BdmInterfaceFactory::createInterface(TARGET_TYPE, nullCallback));
      bdmInterface->setBdmSerialNumber(INTERFACE, false);

      fprintf(stderr, "Changing interface options\n");
      USBDM_ExtendedOptions_t &bdmOptions(bdmInterface->getBdmOptions());
      bdmOptions.targetVdd          = BDM_TARGET_VDD_3V3;
      bdmOptions.leaveTargetPowered = true;

      fprintf(stderr, "Creating empty flash image\n");
      FlashImagePtr flashImage(FlashImageFactory::createFlashImage(TARGET_TYPE));

      fprintf(stderr, "Loading image from \'%s\' \n", FLASH_IMAGE);
      CHECK(flashImage->loadFile(FLASH_IMAGE, TARGET_TYPE));

      fprintf(stderr, "Creating device database\n");
      DeviceInterfacePtr deviceInterface(new DeviceInterface(TARGET_TYPE));

      fprintf(stderr, "Selecting device \'%s\'\n", DEVICE);
      CHECK(deviceInterface->setCurrentDeviceByName(DEVICE));

      fprintf(stderr, "Creating programmer\n");
      FlashProgrammerPtr flashProgrammer(FlashProgrammerFactory::createFlashProgrammer(bdmInterface));

      fprintf(stderr, "Setting programmer device data \'%s\'\n", deviceInterface->getCurrentDevice()->getTargetName().c_str());
      CHECK(flashProgrammer->setDeviceData(deviceInterface->getCurrentDevice()));

      fprintf(stderr, "Initialising BDM interface\n");
      CHECK(bdmInterface->initBdm());

      fprintf(stderr, "Programming\n");
      CHECK(flashProgrammer->programFlash(flashImage));

      fprintf(stderr, "Resetting target\n");
      CHECK(bdmInterface->reset((TargetMode_t)(RESET_NORMAL|RESET_DEFAULT)));

      fprintf(stderr, "Done - Target should be executing\n");
   }
   catch(MyException &error) {
      fprintf(stderr, "Exception %s \n", error.what());
   }
   catch(MyException *error) {
      fprintf(stderr, "Exception %s \n", error->what());
   }
   catch(std::runtime_error &error) {
      fprintf(stderr, "Exception %s \n", error.what());
   }
}
