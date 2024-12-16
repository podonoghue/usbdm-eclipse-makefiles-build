//============================================================================
// Name        : JB16_Bootloader.cpp
// Author      : Peter O'Donoghue
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "ICP.h"
#include "Names.h"
#include "FlashImageFactory.h"
#include "ProgressDialogueFactory.h"
#include "JB16_Bootloader.h"

USBDM_ErrorCode programBlock(FlashImagePtr flashImage, uint32_t size, uint32_t startBlock, ProgressDialoguePtr callBack) {
   LOGGING;
   uint8_t buffer[256];
   memset(buffer, 0xFF, sizeof(buffer));
   USBDM_ErrorCode rc = BDM_RC_OK;
   while(size>0) {
      uint32_t blockSize = size;
      if (blockSize > sizeof(buffer)) {
         blockSize = sizeof(buffer);
      }
      log.print("Programming block [0x%04X...0x%04X]\n", startBlock, startBlock+blockSize-1);
      // Copy data to buffer
      for (uint32_t index=0; index<blockSize; index++) {
         buffer[index] = flashImage->getValue(startBlock+index);
      }
      // Program buffer
      rc = ICP_Program(startBlock, blockSize, buffer, callBack);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      startBlock += blockSize;
      size       -= blockSize;
   }
   return rc;
}

USBDM_ErrorCode programFlashImage(FlashImagePtr flashImage, ProgressDialoguePtr callBack) {
   LOGGING_Q;
   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();
   USBDM_ErrorCode progRc = BDM_RC_OK;
   while (enumerator->isValid()) {
      // Start address of block to program to flash
      uint32_t startBlock = enumerator->getAddress();

      // Find end of block to program
      enumerator->lastValid();
      uint32_t blockSize = enumerator->getAddress() - startBlock + 1;

      //log.print("Block size = %4.4X (%d)\n", blockSize, blockSize);
      if (blockSize>0) {
         // Program block [startBlock..endBlock]
         progRc = programBlock(flashImage, blockSize, startBlock, callBack);
         if (progRc != BDM_RC_OK) {
            log.print("programming failed, Reason= %s\n", UsbdmSystem::getErrorString(progRc));
            break;
         }
      }
      // Move to start of next occupied range
      enumerator->nextValid();
   }
   return progRc;
}

USBDM_ErrorCode ProgramDevice(std::string filePath) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   log.print("Loading file \'%s\'\n", filePath.c_str());
   FlashImagePtr flashImage = FlashImageFactory::createFlashImage(T_ARM);
   rc = flashImage->loadFile(filePath.c_str(), true);
   if (rc != BDM_RC_OK) {
      log.print("main() - Failed to load file, Reason: %s\n", flashImage->getErrorString(rc));
      return rc;
   }
   log.print("Total Bytes = %d\n", flashImage->getByteCount());

   flashImage->fillUnused(flashImage->getLastAllocatedAddress()-flashImage->getFirstAllocatedAddress()+1,
                          flashImage->getFirstAllocatedAddress(), 0xFF);

   do {
      ProgressDialoguePtr progressCallback = ProgressDialogueFactory::create("Accessing Target", flashImage->getByteCount());

      progressCallback->update(0, "Initialising...");
      log.print("Initialising\n");
      rc = ICP_Init();
      if (rc != BDM_RC_OK) {
         continue;
      }
      log.print("Locating devices\n");
      unsigned devCount;
      rc = ICP_FindDevices(&devCount);
      if (rc != BDM_RC_OK) {
         continue;
      }
      log.print("Found %d devices\n", devCount);
      progressCallback->update(0, "Opening device...");
      log.print("Opening device\n");
      rc = ICP_Open(0);
      if (rc != BDM_RC_OK) {
         continue;
      }
      progressCallback->update(0, "Erasing device...");
      log.print("Erasing device\n");
      rc = ICP_MassErase(progressCallback);
      if (rc != BDM_RC_OK) {
         continue;
      }
      progressCallback->update(0, "Programming device...");
      log.print("Programming device\n");
      rc = programFlashImage(flashImage, progressCallback);
      if (rc != BDM_RC_OK) {
         continue;
      }
   } while (false);
   log.print("Closing device\n");
   ICP_Close();
   ICP_Exit();
   return rc;
}

USBDM_ErrorCode RebootDevice() {
   LOGGING;
   USBDM_ErrorCode rc;

   do {
      log.print("Initialising\n");
      rc = ICP_Init();
      if (rc != BDM_RC_OK) {
         continue;
      }
      log.print("Locating devices\n");
      unsigned devCount;
      rc = ICP_FindUsbdmDevices(&devCount);
      if (rc != BDM_RC_OK) {
         continue;
      }
      log.print("Found %d devices\n", devCount);
      log.print("Opening device\n");
      rc = ICP_Open(0);
      if (rc != BDM_RC_OK) {
         continue;
      }
      log.print("Rebooting device - ignore errors\n");
      ICP_Reboot();
   } while (false);
   log.print("Closing device\n");
   ICP_Close();
   ICP_Exit();
   return rc;
}
