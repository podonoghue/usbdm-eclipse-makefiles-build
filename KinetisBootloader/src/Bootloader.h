/*
 * Bootloader.h
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#ifndef BOOTLOADER_H_
#define BOOTLOADER_H_

#include "FlashImage.h"
#include "libusb.h"
#include "CommandMessage.h"
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

private:
   Bootloader(const Bootloader &other) = delete;
   Bootloader(Bootloader &&other) = delete;
   Bootloader& operator=(const Bootloader &other) = delete;
   Bootloader& operator=(Bootloader &&other) = delete;

   libusb_device_handle *device = nullptr;
   uint32_t flashStart        = 0;
   uint32_t flashSize         = 0;
   uint16_t hardwareVersion   = 0;
   uint16_t bootloaderVersion = 0;

   Crc32 crc32;

   /**
    * Locate USB device to program
    *
    * @return nullptr   => failed
    * @return !=nullptr => LIBUSB device handle
    */
   static libusb_device_handle *findDevice();

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
   const char *programBlock(CommandMessage &message);

   /**
    * Erase device flash
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *eraseFlash();

   /**
    * Program a block to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *getDeviceInformation();

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
