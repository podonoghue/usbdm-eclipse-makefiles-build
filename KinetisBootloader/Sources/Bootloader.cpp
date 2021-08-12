/*
 ============================================================================
 * @file     Bootloader.cpp
 *
 * Kinetis bootloader
 *
 *  Created on: 7 Dec 2019
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "usb.h"
#include "UsbCommandMessage.h"
#include "flash.h"
#include "crc.h"

using namespace USBDM;

/** ICP button - checked during boot */
using IcpButton = GpioD<5, USBDM::ActiveLow>;

/** Debug pin */
//using DebugPin  = GpioD<4,  USBDM::ActiveLow>;

/**
 * Report command to console
 *
 * @param message Command message to describe
 */
static void writeCommandMessage(UsbCommandMessage &message) {
   console.WRITE(getCommandName(message.command));
   if (message.byteLength>0) {
      console.
      WRITE(" [0x").WRITE(message.startAddress, Radix_16).
      WRITE("..0x").WRITE(message.startAddress+message.byteLength-1, Radix_16).
      WRITE("]");
      //   console.writeArray(message.data, message.byteLength, message.startAddress);
   }
   console.WRITELN();
}

/** Start of Flash region being used for image */
static constexpr unsigned FLASH_BUFFER_START =  0x4000;

/** Size of Flash region being used for image */
static constexpr unsigned FLASH_BUFFER_SIZE  = 0x1C000;

/**
 * Calculates CRC32 over a range of memory
 *
 * @param start Start address
 * @param size  Size of region to run CRC over
 *
 * @return 32-bit CRC value
 */
uint32_t calcuateCRC32(uint8_t *start, uint32_t size) {
   using Crc = Crc0;

   // Calculate CRC32
   Crc::configure_Crc32();
   return Crc::calculateCrc((uint32_t *)start, size);
}

/**
 * Check if flash region has valid checksum
 *
 * @return true  => CRC  is valid i.e. Flash image is verified
 * @return false => CRC  is invalid i.e. Flash image is not verified
 */
bool isFlashValid() {
   // CRC value in Flash to verify against
   uint32_t flashCrc = *((uint32_t *)(FLASH_BUFFER_START+FLASH_BUFFER_SIZE-4));

   // Calculate current CRC
   uint32_t calculatedCrc = calcuateCRC32((uint8_t *)FLASH_BUFFER_START, FLASH_BUFFER_SIZE-4);

   // Should agree
   return calculatedCrc == flashCrc;
}

/**
 * Program a region of the flash image
 *
 * @param command Command containing information about region to program
 *
 * @return true  => Successfully programmed
 * @return false => Programming failed
 */
bool programFlash(UsbCommandMessage command) {
   if (command.startAddress < FLASH_BUFFER_START) {
      return false;
   }
   if ((command.startAddress+command.byteLength) > (FLASH_BUFFER_START+FLASH_BUFFER_SIZE)) {
      return false;
   }
   FlashDriverError_t rc;
   rc = Flash::programRange(command.data, (uint8_t *)(command.startAddress), command.byteLength);
   if (rc != FLASH_ERR_OK) {
      return false;
   }
   return true;
}

/**
 * Boot into user program mode if:
 *  - Flash image is valid and
 *  - ICP button not pressed
 *
 *  @note Does not return if ICP mode is not detected
 *  @note Called from system code before peripherals are initialised
 */
void checkICP() {

   // Enable pull-up and wait a while
   IcpButton::setInput(PinPull_Up);
   waitMS(100);

   if (isFlashValid() && IcpButton::isReleased()) {

      // Find the reset code */
      void (*f)() = (void (*)())(((uint32_t *)FLASH_BUFFER_START)[1]);

      // Call it
      f();
   }
}

#ifndef SCB_AIRCR_VECTKEY
#define SCB_AIRCR_VECTKEY(x) (((x)<<SCB_AIRCR_VECTKEY_Pos)&SCB_AIRCR_VECTKEY_Msk)
#endif

/**
 * Reset system
 */
static void resetSystem() {

   /* Request system reset */
   SCB->AIRCR = SCB_AIRCR_VECTKEY(0x5FA) | SCB_AIRCR_SYSRESETREQ_Msk;

   /* Wait until reset */
   for(;;) {
      __asm__("nop");
   }
}

/**
 * Structure of Boot information in Flash memory
 */
struct BootInformation {
   uint32_t reserved;
   uint32_t softwareVersion;
   uint32_t hardwareVersion;
   uint32_t checksum;
};

/**
 * Get Boot information from fixed Flash location in loaded image
 *
 * @return Non-nullptr => Pointer to read-only structure in Flash
 * @return nullptr     => Loaded flash image is not valid
 */
static BootInformation *getBootInformation() {

   if (isFlashValid()) {
      BootInformation *imageVersion =
            ((BootInformation *)(FLASH_BUFFER_START+FLASH_BUFFER_SIZE-sizeof(BootInformation)));
      return imageVersion;
   }
   return nullptr;
}

/** Buffer for USB command */
static UsbCommandMessage command;

enum UsbState {UsbStartUp, UsbIdle, UsbWaiting};

void pollUsb() {

   //   console.WRITE("Flash image is ").WRITELN(isFlashValid()?"valid":"invalid");
   //   console.WRITELN("Starting USB boot-loader");

   static UsbState usbState = UsbStartUp;

   // Call-back to record USB user events
   static auto cb = [](const UsbImplementation::UserEvent) {
      // Restart USB transfers on reset etc.
      usbState = UsbIdle;
      return E_NO_ERROR;
   };

   if (usbState == UsbStartUp) {
      // Start USB
      console.WRITELN("UsbStartUp");
      UsbImplementation::initialise();
      UsbImplementation::setUserCallback(cb);
      checkError();
      usbState = UsbIdle;
      return;
   }
   // Check for USB connection
   if (!UsbImplementation::isConfigured()) {
      console.WRITELN("Not configured");
      // No connection
      return;
   }

   int size;

   if (usbState != UsbWaiting) {
      // UsbIdle
      // Set up to receive a message
      Usb0::startReceiveBulkData(sizeof(command), (uint8_t *)&command);
      usbState = UsbWaiting;
      return;
   }

   // UsbWaiting

   // Check if we have received a message
   size = Usb0::pollReceiveBulkData();
   if (size < 0) {
      // No message - USB still ready
      return;
   }

   // *****************************
   // We have a message to process
   // *****************************


   // Default to OK small response
   ResponseMessage    response;
   response.status     = UsbCommandStatus_OK;
   response.byteLength = 0;
   unsigned responseSize = sizeof(ResponseStatus);

   do {
      if (size < (int)sizeof(command.command)) {
         // Incomplete command?
         console.WRITELN("Incomplete command");
         response.status = UsbCommandStatus_Failed;
         continue;
      }
      // Report message on console
      writeCommandMessage(command);

      switch(command.command) {
         default:
            console.WRITE("Unexpected command: ").WRITELN(command.command);
            response.status = UsbCommandStatus_Failed;
            continue;

         case UsbCommand_Nop:
            continue;

         case UsbCommand_Identify:
         {
            response.bootHardwareVersion  = HW_SOLDER_STATION_V1;
            response.bootSoftwareVersion  = BOOTLOADER_V3;
            response.flashStart           = FLASH_BUFFER_START;
            response.flashSize            = FLASH_BUFFER_SIZE;

            BootInformation *bootInformation = getBootInformation();
            if (bootInformation != nullptr) {
               response.imageHardwareVersion = bootInformation->hardwareVersion;
               response.imageSoftwareVersion = bootInformation->softwareVersion;
            }
            else {
               response.imageHardwareVersion = 0;
               response.imageSoftwareVersion = 0;
            }
            responseSize = command.byteLength + sizeof(ResponseIdentify);
            continue;
         }

         case UsbCommand_EraseFlash:
            if (Flash::eraseRange((uint8_t *)FLASH_BUFFER_START, FLASH_BUFFER_SIZE) != FLASH_ERR_OK) {
               response.status = UsbCommandStatus_Failed;
            }
            continue;

         case UsbCommand_ProgramBlock:
            if (!programFlash(command)) {
               response.status = UsbCommandStatus_Failed;
               console.WRITELN("Flash programming failed");
            }
            continue;

         case UsbCommand_ReadBlock:
            if (response.byteLength > sizeof(command.data)) {
               // Illegal block size
               response.status = UsbCommandStatus_Failed;
               console.WRITELN("Read block too large");
               continue;
            }
            response.byteLength  = command.byteLength;
            responseSize         = command.byteLength + sizeof(ResponseStatus);
            memcpy(response.data, (uint8_t *)(command.startAddress), command.byteLength);
            continue;

         case UsbCommand_Reset:
            resetSystem();
            continue;
      }
   } while (false);

   // Send response
   ErrorCode rc = Usb0::sendBulkData(responseSize, (uint8_t *)&response, 1000);
   if (rc != 0) {
      console.WRITE("sendBulkData() failed, reason = ").WRITELN(getErrorMessage(rc));
   }
   usbState = UsbIdle;
}

int main() {
//   console.setBaudRate(115200);
   for(;;) {
      pollUsb();
   }
}
