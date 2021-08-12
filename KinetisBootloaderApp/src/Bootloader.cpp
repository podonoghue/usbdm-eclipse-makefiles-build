/*! \file
    \brief Bootloader for Kinetis devices

    Bootloader.cpp

    \verbatim
    Copyright (C) 2020 Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    \endverbatim

    \verbatim
   Change History
   -=========================================================================================
   | 10 Dec 2019 | Initial work                                              - pgo
   +=========================================================================================
   \endverbatim
 */
#include <stdio.h>

#include "libusb.h"
#include "Bootloader.h"
#include "UsbCommandMessage.h"

static constexpr uint8_t   EP_OUT      = LIBUSB_ENDPOINT_OUT|1;  // EP #1 OUT
static constexpr uint8_t   EP_IN       = LIBUSB_ENDPOINT_IN |2;  // EP #2 IN

static constexpr uint16_t  VENDOR_ID   = 0x16D0;    // Vendor (actually MCS)
static constexpr uint16_t  PRODUCT_ID  = 0x4327;    // Product ID

Bootloader::Bootloader() {
}

Bootloader::~Bootloader() {
}

/**
 * Locate USB device to program
 * Assumes libusb has been initialised.
 *
 * @return nullptr   => failed
 * @return !=nullptr => LIBUSB device handle
 */
libusb_device_handle *Bootloader::findDevice() {

   libusb_device_handle *device = nullptr;
   libusb_device **deviceList = nullptr;
   ssize_t deviceCount = 0;
   int rc = 0;

   do {
      deviceCount = libusb_get_device_list(libusbContext, &deviceList);
      if (deviceCount <= 0){
         fprintf(stderr, "No suitable devices found\n");
         continue;
      }
      // Reserve device
      device = libusb_open_device_with_vid_pid(libusbContext, VENDOR_ID, PRODUCT_ID);
      if (device == nullptr) {
         fprintf(stderr, "Device failed to open\n");
         continue;
      }
      // Find out if kernel driver is attached
      if(libusb_kernel_driver_active(device, 0) == 1) {
         fprintf(stderr, "Kernel Driver Active\n");
         // Detach it
         if(libusb_detach_kernel_driver(device, 0) == 0) {
            fprintf(stderr, "Kernel Driver Detached!\n");
         }
      }
      rc = libusb_set_configuration(device, 1);
      if (rc < 0) {
         fprintf(stderr, "Set configuration failed - %s\n", libusb_error_name(rc));
         continue;
      }
      rc = libusb_claim_interface(device, 0);
      if (rc < 0) {
         fprintf(stderr, "Claim interface failed - %s\n", libusb_error_name(rc));
         continue;
      }
   } while (false);

   // We can now free the list
   libusb_free_device_list(deviceList, true);

   if (rc < 0) {
      libusb_close(device);
      device = nullptr;
   }
   return device;
}

/**
 * Program a block to device.
 * Assumes device has been opened
 *
 * @param message Information to send to device
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::programBlock(UsbCommandMessage &message) {
   int rc = 0;

   int bytesSent   = 0;
   int bytesToSend = sizeof(SimpleCommandMessage)+message.byteLength;
   rc = libusb_bulk_transfer(deviceHandle, EP_OUT, (uint8_t*)&message, bytesToSend, &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if (bytesSent != bytesToSend) {
      return "Incomplete transmission";
   }

   ResponseStatus response = {};

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(deviceHandle, EP_IN, (uint8_t*)&response, sizeof(response), &bytesReceived, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(ResponseStatus)) {
      return "Incomplete reception";
   }
   if (response.status != UsbCommandStatus_OK) {
      return "Operation failed on device";
   }

   return nullptr;
}

/**
 * Erase device flash
 * Assumes device has been opened
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::eraseFlash() {
   int rc = 0;

   SimpleCommandMessage  command = {
         /* command      */ UsbCommand_EraseFlash,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   rc = libusb_bulk_transfer(deviceHandle, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }

   ResponseStatus response = {};

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(deviceHandle, EP_IN, (uint8_t*)&response, sizeof(response), &bytesReceived, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(ResponseStatus)) {
      return "Incomplete reception";
   }
   if (response.status != UsbCommandStatus_OK) {
      return "Operation failed on device";
   }

   return nullptr;
}

/**
 * Reset device
 * Assumes device has been opened
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::resetDevice() {
   int rc = 0;

   SimpleCommandMessage  command = {
         /* command      */ UsbCommand_Reset,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   rc = libusb_bulk_transfer(deviceHandle, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 10000);
   if (rc < 0) {
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }
   return nullptr;
}

/**
 * Get information about the device
 * Assumes device has been opened
 *
 * @param[out] identity
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::queryDeviceInformation(ResponseIdentify &identity) {

   SimpleCommandMessage  command = {
         /* command      */ UsbCommand_Identify,
         /* startAddress */ 0,
         /* byteLength   */ 0,
   };

   int bytesSent = 0;
   int rc = libusb_bulk_transfer(deviceHandle, EP_OUT, (uint8_t*)&command, sizeof(command), &bytesSent, 5000);
   if (rc < 0) {
      fprintf(stderr, "Bulk transfer (OUT) failed - %s\n", libusb_error_name(rc));
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesSent != sizeof(command)) {
      return "Incomplete transmission";
   }

   int bytesReceived = 0;
   rc = libusb_bulk_transfer(deviceHandle, EP_IN, (uint8_t*)&identity, sizeof(identity), &bytesReceived, 5000);
   if (rc < 0) {
      fprintf(stderr, "Bulk transfer (IN) failed - %s\n", libusb_error_name(rc));
      return libusb_error_name(rc);
   }
   if ((unsigned)bytesReceived < sizeof(identity)) {
      return "Incomplete reception";
   }
   if (identity.status != UsbCommandStatus_OK) {
      return "Operation failed on device";
   }

   flashStart           = identity.flashStart;
   flashSize            = identity.flashSize;
   hardwareVersion      = identity.bootHardwareVersion;
   bootloaderVersion    = identity.bootSoftwareVersion;
   existingImageVersion = identity.imageSoftwareVersion;

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
   unsigned int maxSplitBlockSize = sizeof(UsbCommandMessage::data);

   uint32_t flashAddress   = flashStart;
   uint32_t bytesToProgram = flashSize;
   while (bytesToProgram>0) {
      uint32_t splitBlockSize = bytesToProgram;
      if (splitBlockSize>maxSplitBlockSize) {
         splitBlockSize = maxSplitBlockSize;
      }
      UsbCommandMessage  command = {
            /* command      */ UsbCommand_ProgramBlock,
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

   int rc = libusb_init(&libusbContext);
   if (rc < 0) {
      return "Libusb failed initialisation";
   }
   deviceHandle = findDevice();
   if (deviceHandle == nullptr) {
      return "Device not found";
   }
   do {
      ResponseIdentify identity;
      errorMessage = queryDeviceInformation(identity);
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

   rc = libusb_release_interface(deviceHandle, 0);
   if (rc < 0) {
      fprintf(stderr, "Release interface failed - %s\n", libusb_error_name(rc));
   }

   libusb_close(deviceHandle);
   deviceHandle = nullptr;

   libusb_exit(libusbContext);
   libusbContext = nullptr;

   return errorMessage;
}

/**
 * Get information about the device
 *
 * @param[out] identity
 *
 * @return nullptr   => success
 * @return !=nullptr => failed, error message
 */
const char *Bootloader::getDeviceInformation(ResponseIdentify &identity) {

   const char *errorMessage = nullptr;

   int rc = libusb_init(&libusbContext);
   if (rc < 0) {
      return "Libusb failed initialisation";
   }
   // Set verbosity level to 3, as suggested in the documentation
   libusb_set_debug(libusbContext, 3);
   deviceHandle = findDevice();
   if (deviceHandle == nullptr) {
      return "Device not found";
   }
   do {
      const char *errorMessage = queryDeviceInformation(identity);
      if (errorMessage) {
         continue;
      }
      fprintf(stderr, "Hardware Version = %s, Bootloader Version = %d, Flash[0x%08X..0x%08X], Image Version = %d\n",
            getHardwareType(hardwareVersion), bootloaderVersion, flashStart, flashStart+flashSize-1, existingImageVersion);
      fflush(stderr);
   } while (false);

   libusb_close(deviceHandle);
   deviceHandle = nullptr;

   libusb_exit(libusbContext);
   libusbContext = nullptr;

   return errorMessage;
}
