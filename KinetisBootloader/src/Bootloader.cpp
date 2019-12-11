/*
 * Bootloader.cpp
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#include "Bootloader.h"
#include "libusb.h"
#include "CommandMessage.h"

static constexpr uint8_t   EP_OUT      = LIBUSB_ENDPOINT_OUT|1;  // EP #1 OUT
static constexpr uint8_t   EP_IN       = LIBUSB_ENDPOINT_IN |2;  // EP #2 IN

static constexpr uint16_t  VENDOR_ID   = 0x16D0;    // Vendor (actually MCS)
static constexpr uint16_t  PRODUCT_ID  = 0x4325;    // Product ID

Bootloader::Bootloader() {
}

Bootloader::~Bootloader() {
}

/**
 * Locate USB device to program
 *
 *
 * @return nullptr   => failed
 * @return !=nullptr => LIBUSB device handle
 */
libusb_device_handle *Bootloader::findDevice() {

   libusb_device **devs;
   int rc;

   ssize_t cnt = libusb_get_device_list(NULL, &devs);
   if (cnt <= 0){
      return nullptr;
   }

   libusb_device_handle *device = nullptr;
   libusb_device *dev;
   unsigned i=0;
   while ((dev = devs[i++]) != NULL) {
      struct libusb_device_descriptor desc;
      rc = libusb_get_device_descriptor(dev, &desc);
      if (rc < 0) {
         fprintf(stderr, "failed to get device descriptor");
         return nullptr;
      }
      fprintf(stderr, "%04x:%04x (bus %d, device %d)\n",
            desc.idVendor, desc.idProduct,
            libusb_get_bus_number(dev), libusb_get_device_address(dev));
      if ((desc.idVendor == VENDOR_ID) && (desc.idProduct == PRODUCT_ID)) {
         rc = libusb_open(dev, &device);
         break;
      }
   }
   if (device != nullptr) {
      rc = libusb_set_configuration(device, 1);
      if (rc < 0) {
         libusb_close(device);
         device = nullptr;
      }
      rc = libusb_claim_interface(device, 0);
      if (rc < 0) {
         libusb_close(device);
         device = nullptr;
      }
   }
   if (cnt > 0) {
      libusb_free_device_list(devs, 1);
   }
   return device;
}

/**
 * Program a block to device
 *
 * @param device  LIBUSB device handle
 * @param message Information to send to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::programBlock(libusb_device_handle *device, CommandMessage &message) {
   int rc = 0;

   int bytesSent   = 0;
   int bytesToSend = sizeof(SimpleCommandMessage)+message.byteLength;
   rc = libusb_bulk_transfer(device, EP_OUT, (uint8_t*)&message, bytesToSend, &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if (bytesSent != bytesToSend) {
      return "Incomplete transmission";
   }

   ResponseStatus response = {};

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(device, EP_IN, (uint8_t*)&response, sizeof(response), &bytesReceived, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(ResponseStatus)) {
      return "Incomplete reception";
   }
   if (response.status != Status_OK) {
      return "Operation failed on device";
   }

   return nullptr;
}

/**
 * Program a block to device
 *
 * @param device  LIBUSB device handle
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::eraseFlash(libusb_device_handle *device) {
   int rc = 0;

   SimpleCommandMessage  command = {
         /* command      */ Command_EraseFlash,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   rc = libusb_bulk_transfer(device, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }

   ResponseStatus response = {};

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(device, EP_IN, (uint8_t*)&response, sizeof(response), &bytesReceived, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(ResponseStatus)) {
      return "Incomplete reception";
   }
   if (response.status != Status_OK) {
      return "Operation failed on device";
   }

   return nullptr;
}

/**
 * Reset device
 *
 * @param device  LIBUSB device handle
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::resetDevice(libusb_device_handle *device) {
   int rc = 0;

   SimpleCommandMessage  command = {
         /* command      */ Command_Reset,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   rc = libusb_bulk_transfer(device, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }
   return nullptr;
}

/**
 * Program a block to device
 *
 * @param device  LIBUSB device handle
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::checkVersion(libusb_device_handle *device) {
   int rc = 0;

   SimpleCommandMessage  command = {
         /* command      */ Command_Identify,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   rc = libusb_bulk_transfer(device, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }

   ResponseIdentify response = {};

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(device, EP_IN, (uint8_t*)&response, sizeof(response), &bytesReceived, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(response)) {
      return "Incomplete reception";
   }
   if (response.status != Status_OK) {
      return "Operation failed on device";
   }
   fprintf(stderr, "Hardware Version = %s, Bootloader Version = %d\n",
         getHardwareType(response.hardwareVersion), response.bootloaderVersion);
   fflush(stderr);
   return nullptr;
}

/**
 * Program a block to device
 *
 * @param device        LIBUSB device handle
 * @param flashImage    Flash image being programmed to device
 * @param blockSize     Size of block to program
 * @param flashAddress  Address to program
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::doFlashBlock(
      libusb_device_handle *device,
      FlashImagePtr        flashImage,
      unsigned int         blockSize,
      uint32_t             &flashAddress) {

   // OK for empty block
   if (blockSize==0) {
      return nullptr;
   }

   const char *errrorMessage = nullptr;

   /*
    * Have block and suitable operation
    */
   fprintf(stderr, "Processing [0x%06X..0x%06X]\n",
         (flashAddress), (flashAddress)+blockSize-1);

   // Maximum size of data to write
   unsigned int maxSplitBlockSize = sizeof(CommandMessage::data);

   CommandMessage  command = {
         /* command      */ Command_ProgramBlock,
         /* startAddress */ 0,
         /* byteLength   */ 0,
         /* data         */ {}
   };

   while (blockSize>0) {
      uint32_t splitBlockSize = blockSize;
      if (splitBlockSize>maxSplitBlockSize) {
         splitBlockSize = maxSplitBlockSize;
      }
      command.command      = Command_ProgramBlock;
      command.startAddress = flashAddress;
      command.byteLength   = splitBlockSize;

      for (unsigned index=0; index<maxSplitBlockSize; index++) {
         uint8_t byte;
         if ((flashAddress+index) == (FLASH_START+FLASH_SIZE-4)) {
            uint32_t crc = crc32.getCrc();
            fprintf(stderr, "crc = 0x%08X\n", crc);
            command.data[index++] = (uint8_t)crc;
            command.data[index++] = (uint8_t)(crc>>8);
            command.data[index++] = (uint8_t)(crc>>16);
            command.data[index++] = (uint8_t)(crc>>24);
            break;
         }
         byte = flashImage->getValue(flashAddress+index);
         crc32.addByte(byte);
         command.data[index] = byte;
      }
      fprintf(stderr, "splitBlock [0x%06X..0x%06X]\n",
            command.startAddress, command.startAddress+command.byteLength-1);
      fflush(stderr);

      errrorMessage = programBlock(device, command);

      flashAddress += splitBlockSize;
      blockSize    -= splitBlockSize;
   }

//   uint32_t alignMask = 16-1;
//
//   // splitBlockSize must be aligned
//   maxSplitBlockSize &= ~alignMask;
//
//   // Calculate any odd padding bytes at start of block
//   unsigned int oddBytes = flashAddress & alignMask;
//
//   // Round start address off to alignment requirements
//   flashAddress  &= ~alignMask;
//
//   // Pad block size with odd leading bytes
//   blockSize += oddBytes;
//
//   // Pad block size to alignment requirements
//   blockSize = (blockSize+alignMask)&~alignMask;
//
//   while (blockSize>0) {
//      unsigned flashIndex  = 0;
//
//      CommandMessage  command = {
//            /* command      */ Command_ProgramBlock,
//            /* startAddress */ 0,
//            /* byteLength   */ 0,
//            /* data         */ {}
//      };
//
//      // Buffer for memory write (header+buffer)
//      uint8_t *bufferData = command.data;
//
//      // Determine size of block to process
//      unsigned int splitBlockSize = blockSize;
//
//      // Requires data transfer using buffer
//      if (splitBlockSize>maxSplitBlockSize) {
//         splitBlockSize = maxSplitBlockSize;
//      }
//      // Pad any odd leading elements as 0xFF.
//      for (flashIndex=0; flashIndex<oddBytes; flashIndex++) {
//         crc32.addByte((uint8_t)-1);
//         bufferData[flashIndex] = (uint8_t)-1;
//      }
//      // Copy flash data to buffer
//      for(flashIndex=0; flashIndex<splitBlockSize; flashIndex++) {
//         uint8_t byte = flashImage->getValue(flashAddress+flashIndex);
//         crc32.addByte(byte);
//         bufferData[flashIndex] = byte;
//      }
//      // Pad trailing elements to aligned address
//      for (; (flashIndex&alignMask) != 0; flashIndex++) {
//         uint8_t byte = flashImage->getValue(flashAddress+flashIndex);
//         crc32.addByte(byte);
//         bufferData[flashIndex] = byte;
//      }
//      // Actual data bytes to write
//      uint32_t targetAddress = flashAddress;
//
//      if (splitBlockSize==0) {
//         return " - Error: splitBlockSize size is 0\n";
//      }
//
//      command.command      = Command_ProgramBlock;
//      command.startAddress = targetAddress;
//      command.byteLength   = flashIndex;
//
//      /*
//       * Flash writes
//       */
//      fprintf(stderr, "splitBlock [0x%06X..0x%06X]\n",
//            (flashAddress), (flashAddress)+splitBlockSize-1);
//      fflush(stderr);
//
//      errrorMessage = programBlock(device, command);
//      if (errrorMessage != nullptr) {
//         return errrorMessage;
//      }
//
//      // Advance to next block of data
//      flashAddress  += splitBlockSize;
//      blockSize     -= splitBlockSize;
//      oddBytes       = 0; // No odd bytes on subsequent blocks
//   }
   return errrorMessage;
}

/**
 * Program a flash image to device
 *
 * @param device        LIBUSB device handle
 * @param flashImage    Flash image being programmed to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::program(
      libusb_device_handle *device,
      FlashImagePtr        flashImage) {

   const char *errorMessage  = nullptr;

   uint32_t currentAddress = FLASH_START;
   errorMessage = doFlashBlock(device, flashImage, FLASH_SIZE, currentAddress);

//   FlashImage::EnumeratorPtr enumerator = flashImage->getEnumerator();
//   // Go through each allocated block of memory
//   while (enumerator->isValid()) {
//      // Start address of block to program to flash
//      uint32_t startBlock = enumerator->getAddress();
//
//      // Find end of block to process
//      enumerator->lastValid();
//      uint32_t blockSize = enumerator->getAddress() - startBlock + 1;
//      if (blockSize>0) {
//         // Process block [startBlock..endBlock]
//         errorMessage = doFlashBlock(device, flashImage, blockSize, startBlock);
//         if (errorMessage != nullptr) {
//            fprintf(stderr, "program() - %s\n", errorMessage);
//            break;
//         }
//      }
//      else {
//         fprintf(stderr, "program() - empty block\n");
//      }
//      enumerator->setAddress(startBlock);
//   }

   return errorMessage;
}

/**
 * Program a flash image to device
 *
 * @param flashImage    Flash image being programmed to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::download(FlashImagePtr flashImage) {

   const char *errorMessage = nullptr;

   int rc = libusb_init(NULL);
   if (rc < 0) {
      return "Libusb failed initialisation";
   }

   libusb_device_handle *device = nullptr;

   device = findDevice();

   do {
      errorMessage = checkVersion(device);
      if (errorMessage != nullptr) {
         break;
      }
      errorMessage = eraseFlash(device);
      if (errorMessage != nullptr) {
         break;
      }
      errorMessage = program(device, flashImage);
      if (errorMessage != nullptr) {
         break;
      }
      errorMessage = resetDevice(device);
      if (errorMessage != nullptr) {
         break;
      }
   } while(false);

   if (device != nullptr) {
      libusb_close(device);
   }

   libusb_exit(nullptr);

   return errorMessage;
}
