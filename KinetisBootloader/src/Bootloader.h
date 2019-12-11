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

   static constexpr uint32_t FLASH_START = 0x08000;
   static constexpr uint32_t FLASH_SIZE  = 0x18000;

   Crc32 crc32;

   /**
    * Locate USB device to program
    *
    * @return nullptr   => failed
    * @return !=nullptr => LIBUSB device handle
    */
   libusb_device_handle *findDevice();

   /**
    * Reset device
    *
    * @param device  LIBUSB device handle
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *resetDevice(libusb_device_handle *device);

   /**
    * Program a block to device
    *
    * @param device  LIBUSB device handle
    * @param message Information to send to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *programBlock(libusb_device_handle *device, CommandMessage &message);

   /**
    * Program a block to device
    *
    * @param device  LIBUSB device handle
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *eraseFlash(libusb_device_handle *device);

   /**
    * Program a block to device
    *
    * @param device  LIBUSB device handle
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *checkVersion(libusb_device_handle *device);

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
   const char *doFlashBlock(
         libusb_device_handle *device,
         FlashImagePtr        flashImage,
         unsigned int         blockSize,
         uint32_t             &flashAddress);

   /**
    * Program a flash image to device
    *
    * @param device        LIBUSB device handle
    * @param flashImage    Flash image being programmed to device
    *
    * @return nullptr   => success
    * @return !=nullptr => failed, error message
    */
   const char *program(
         libusb_device_handle *device,
         FlashImagePtr        flashImage);
};

#endif /* BOOTLOADER_H_ */
