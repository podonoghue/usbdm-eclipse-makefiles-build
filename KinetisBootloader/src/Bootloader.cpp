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
//      fprintf(stderr, "%04x:%04x (bus %d, device %d)\n",
//            desc.idVendor, desc.idProduct,
//            libusb_get_bus_number(dev), libusb_get_device_address(dev));
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
   if (device == nullptr) {
      fprintf(stderr, "Device failed to open\n");
   }
   return device;
}

/**
 * Program a block to device
 *
 * @param message Information to send to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::programBlock(CommandMessage &message) {
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
 * Erase device flash
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::eraseFlash() {
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
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::resetDevice() {
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
 * Read version and flash size information from device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::getDeviceInformation() {
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
   flashStart        = response.flashStart;
   flashSize         = response.flashSize;
   hardwareVersion   = response.hardwareVersion;
   bootloaderVersion = response.bootloaderVersion;

   fprintf(stderr, "Hardware Version = %s, Bootloader Version = %d, Flash[0x%08X..0x%08X]\n",
         getHardwareType(hardwareVersion), bootloaderVersion, flashStart, flashStart+flashSize-1);
   fflush(stderr);

   return nullptr;
}

/**
 * Program image to device
 *
 * @param flashImage    Flash image being programmed to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::programFlash(FlashImagePtr flashImage) {

   // OK for empty image
   if (flashSize==0) {
      return nullptr;
   }
   const char *errrorMessage = nullptr;

   fprintf(stderr, "Processing [0x%06X..0x%06X]\n", flashStart, (flashStart)+flashSize-1);

   // Maximum size of data to write
   unsigned int maxSplitBlockSize = sizeof(CommandMessage::data);

   uint32_t flashAddress   = flashStart;
   uint32_t bytesToProgram = flashSize;
   while (bytesToProgram>0) {
      uint32_t splitBlockSize = bytesToProgram;
      if (splitBlockSize>maxSplitBlockSize) {
         splitBlockSize = maxSplitBlockSize;
      }
      CommandMessage  command = {
            /* command      */ Command_ProgramBlock,
            /* startAddress */ flashAddress,
            /* byteLength   */ splitBlockSize,
            /* data         */ {}
      };
      bool empty = true;
      for (unsigned index=0; index<maxSplitBlockSize; index++) {
         uint8_t byte;
         if ((flashAddress+index) == (flashStart+flashSize-4)) {
            empty = false;

            // Replace last 4 bytes with CRC
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
         empty = empty && (byte == 0xFF);
         command.data[index] = byte;
      }
      if (empty) {
         fprintf(stderr, "Skipping splitBlock [0x%06X..0x%06X]\n",
               command.startAddress, command.startAddress+command.byteLength-1);
         fflush(stderr);
      }
      else {
         fprintf(stderr, "Programming splitBlock [0x%06X..0x%06X]\n",
               command.startAddress, command.startAddress+command.byteLength-1);
         fflush(stderr);

         errrorMessage = programBlock(command);
         if (errrorMessage != nullptr) {
            break;
         }
      }
      flashAddress    += splitBlockSize;
      bytesToProgram  -= splitBlockSize;
   }
   return errrorMessage;
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
   device = findDevice();
   if (device == nullptr) {
      return "Device not found";
   }
   do {
      errorMessage = getDeviceInformation();
      if (errorMessage != nullptr) {
         break;
      }
      if ((flashImage->getFirstAllocatedAddress()<flashStart) ||
          (flashImage->getLastAllocatedAddress()>(flashStart+flashSize-1))) {
         errorMessage = "Flash image extends beyond target flash memory";
         break;
      }
      errorMessage = eraseFlash();
      if (errorMessage != nullptr) {
         break;
      }
      errorMessage = programFlash(flashImage);
      if (errorMessage != nullptr) {
         break;
      }
      errorMessage = resetDevice();
      if (errorMessage != nullptr) {
         break;
      }
   } while(false);

   if (device != nullptr) {
      libusb_close(device);
      device = nullptr;
   }

   libusb_exit(nullptr);

   return errorMessage;
}
