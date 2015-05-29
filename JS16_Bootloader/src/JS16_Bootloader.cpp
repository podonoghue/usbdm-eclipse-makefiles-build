//============================================================================
// Name        : JS16_Bootloader.cpp
// Author      : Peter O'Donoghue
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "UsbdmSystem.h"
#include "ICP.h"
#include "Names.h"
#include "FlashImageFactory.h"
#include "JS16_Bootloader.h"

ICP_ErrorType programBlock(FlashImagePtr flashImageDescription, uint32_t size, uint32_t startBlock) {
   LOGGING;
   uint8_t buffer[256];
   memset(buffer, 0xFF, sizeof(buffer));
   ICP_ErrorType rc = RC_OK;
   while(size>0) {
      uint32_t blockSize = size;
      if (blockSize > sizeof(buffer)) {
         blockSize = sizeof(buffer);
      }
      log.print("Programming block [0x%04X...0x%04X]\n", startBlock, startBlock+blockSize-1);
      // Copy data to buffer
      for (uint32_t index=0; index<blockSize; index++) {
         buffer[index] = flashImageDescription->getValue(startBlock+index);
      }
      // Program buffer
      rc = ICP_Program(startBlock, blockSize, buffer);
      if (rc != RC_OK) {
         return rc;
      }
      startBlock += blockSize;
      size       -= blockSize;
   }
   return rc;
}

ICP_ErrorType loadFile(FlashImagePtr flashImageDescription) {
   LOGGING_Q;
   FlashImage::EnumeratorPtr enumerator = flashImageDescription->getEnumerator();
   ICP_ErrorType progRc = RC_OK;
   while (enumerator->isValid()) {
      // Start address of block to program to flash
      uint32_t startBlock = enumerator->getAddress();

      // Find end of block to program
      enumerator->lastValid();
      uint32_t blockSize = enumerator->getAddress() - startBlock + 1;

      //log.print("Block size = %4.4X (%d)\n", blockSize, blockSize);
      if (blockSize>0) {
         // Program block [startBlock..endBlock]
         progRc = programBlock(flashImageDescription, blockSize, startBlock);
         if (progRc != RC_OK) {
            log.print("loadFile() - programming failed, Reason= %s\n", ICP_GetErrorName(progRc));
            break;
         }
      }
      // Move to start of next occupied range
      enumerator->nextValid();
   }
   return progRc;
}

ICP_ErrorType ProgramFlash(std::string filePath) {
   LOGGING_Q;
   ICP_ErrorType rc;

   log.print("Loading file \'%s\'\n", filePath.c_str());
   FlashImagePtr flashImageDescription = FlashImageFactory::createFlashImage(T_ARM);
   USBDM_ErrorCode Flashrc = flashImageDescription->loadFile(filePath.c_str(), true);
   if (Flashrc != BDM_RC_OK) {
      log.print("main() - Failed to load file, Reason: %s\n", flashImageDescription->getErrorString(Flashrc));
      return ICP_RC_FILE_NOT_FOUND;
   }
   log.print("Total Bytes = %d\n", flashImageDescription->getByteCount());

   do {
      log.print("Initialising\n");
      rc = ICP_Init();
      if (rc != RC_OK) {
         continue;
      }
      log.print("Locating devices\n");
      unsigned devCount;
      rc = ICP_FindDevices(&devCount);
      if (rc != RC_OK) {
         continue;
      }
      log.print("Found %d devices\n", devCount);
      log.print("Opening device\n");
      rc = ICP_Open(0);
      if (rc != RC_OK) {
         continue;
      }
      log.print("Erasing device\n");
      rc = ICP_MassErase();
      if (rc != RC_OK) {
         continue;
      }
      log.print("Programming device\n");
      rc = loadFile(flashImageDescription);
      if (rc != RC_OK) {
         continue;
      }
   } while (false);
   log.print("Closing device\n");
   ICP_Close();
   ICP_Exit();
   return rc;
}
