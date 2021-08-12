/*! \file
    \brief PC Application for Bootloader on Kinetis devices

    Bootloader.h

    \verbatim
    Copyright (C) 2019 Peter O'Donoghue

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
   |  9 Dec 2019 | Initial work                                              - pgo
   +=========================================================================================
   \endverbatim
 */

#ifndef BOOTLOADER_H_
#define BOOTLOADER_H_

#include "FlashImage.h"
#include "libusb.h"
#include "UsbCommandMessage.h"
#include "crc32b.h"

class Bootloader {

public:
   Bootloader();
   virtual ~Bootloader();

   /**
    * Program a flash image to device
    *
    * @param flashImage    Flash image being programmed to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *download(FlashImagePtr flashImage);

   /**
    * Get information about the device
    *
    * @param[out] identity
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *getDeviceInformation(ResponseIdentify &identity);

private:
   Bootloader(const Bootloader &other) = delete;
   Bootloader(Bootloader &&other) = delete;
   Bootloader& operator=(const Bootloader &other) = delete;
   Bootloader& operator=(Bootloader &&other) = delete;

   libusb_context *libusbContext = nullptr;
   libusb_device_handle *deviceHandle = nullptr;
   uint32_t flashStart           = 0;
   uint32_t flashSize            = 0;
   uint16_t hardwareVersion      = 0;
   uint16_t bootloaderVersion    = 0;
   uint32_t existingImageVersion = 0;

   Crc32 crc32;

   /**
    * Locate USB device to program
    *
    * @return nullptr   => Failed
    * @return !=nullptr => LIBUSB device handle
    */
   libusb_device_handle *findDevice();

   /**
    * Reset device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *resetDevice();

   /**
    * Program a block to device
    *
    * @param message Information to send to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *programBlock(UsbCommandMessage &message);

   /**
    * Erase device flash
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *eraseFlash();

   /**
    * Get information about the device
    * Assumes device has been opened
    *
    * @param[out] identity
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *queryDeviceInformation(ResponseIdentify &identity);

   /**
    * Program image to device
    *
    * @param flashImage    Flash image being programmed to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *programFlash(FlashImagePtr flashImage);
};

#endif /* BOOTLOADER_H_ */
