/*
 * UsbCommandMessage.h
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#ifndef SOURCES_USBCOMMANDMESSAGE_H_
#define SOURCES_USBCOMMANDMESSAGE_H_

#include <stdint.h>

static constexpr uint16_t HW_LOGIC_BOARD_V2 = 1;
static constexpr uint16_t HW_LOGIC_BOARD_V3 = 2;
static constexpr uint16_t HW_LOGIC_BOARD_V4 = 3;
static constexpr uint16_t BOOTLOADER_V1     = 1;

/**
 * Commands available
 */
enum UsbCommand : uint32_t {
   UsbCommand_Nop,            //! No operation
   UsbCommand_Identify,       //! Identify boot-loader and hardware versions etc
   UsbCommand_EraseFlash,     //! Erase all of flash image
   UsbCommand_ReadBlock,      //! Read block from flash
   UsbCommand_ProgramBlock,   //! Program block to flash
   UsbCommand_Reset,          //! Reset device
};

/**
 * Result of command
 */
enum UsbCommandStatus : uint32_t {
   UsbCommandStatus_OK,          //!< OK result
   UsbCommandStatus_Failed,      //!< Failed
};

static constexpr unsigned MAX_MESSAGE_DATA = 1024;

/**
 * Get command name as string
 *
 * @param command
 *
 * @return Name as string
 *
 * @note return value is a pointer to a STATIC object - do not free
 */
static inline const char *getCommandName(UsbCommand command) {
   static const char *names[] = {
         "UsbCommand_Nop",
         "UsbCommand_Identify",
         "UsbCommand_EraseFlash",
         "UsbCommand_ReadBlock",
         "UsbCommand_ProgramBlock",
         "UsbCommand_Reset",
   };
   const char *name = "Unknown";
   if (command < (sizeof(names)/sizeof(names[0]))) {
      name = names[command];
   }
   return name;
}

/**
 * Get hardware type as string
 *
 * @param hardwareVersion Version being queried
 *
 * @return Name as string
 *
 * @note return value is a pointer to a STATIC object - do not free
 */
static inline const char *getHardwareType(uint16_t hardwareVersion) {
   static const char *names[] = {
         "Unknown",
         "HW_LOGIC_BOARD_V2",
         "HW_LOGIC_BOARD_V3",
         "HW_LOGIC_BOARD_V4",
   };
   const char *name = "Unknown";
   if (hardwareVersion < (sizeof(names)/sizeof(names[0]))) {
      name = names[hardwareVersion];
   }
   return name;
}

#pragma pack(push, 1)

/**
 * General USB command message
 */
struct UsbCommandMessage {
   UsbCommand  command;              // Command to execute
   uint32_t startAddress;            // Target memory address
   uint32_t byteLength;              // Size of data
   uint8_t  data[MAX_MESSAGE_DATA];  // Data (up to 1 flash block)
};

/**
 * Simple USB command message
 */
struct SimpleCommandMessage {
   UsbCommand  command;    // Command to execute
   uint32_t startAddress;  // Target memory address
   uint32_t byteLength;    // Size of data
};

/**
 * General USB response message
 */
struct ResponseMessage {
   UsbCommandStatus   status;        // Status
   uint32_t           byteLength;    // Size of data
   union {
      struct {
         uint32_t bootHardwareVersion;  // Hardware version
         uint32_t bootSoftwareVersion;  // Boot-loader software version
         uint32_t flashStart;           // Start of flash region
         uint32_t flashSize;            // Size of flash region
         uint32_t imageHardwareVersion; // Hardware version from loaded image
         uint32_t imageSoftwareVersion; // Software version from loaded image
      };
      uint8_t  data[MAX_MESSAGE_DATA];    // Data
   };
};

/**
 * USB status response message
 */
struct ResponseStatus {
   UsbCommandStatus   status;        // Status
   uint32_t           byteLength;    // Size of data
};

/**
 * USB identify response message
 */
struct ResponseIdentify {
   UsbCommandStatus   status;     // Status
   uint32_t byteLength;           // Size of data (not used)
   uint32_t bootHardwareVersion;  // Hardware version
   uint32_t bootSoftwareVersion;  // Boot-loader software version
   uint32_t flashStart;           // Start of flash region
   uint32_t flashSize;            // Size of flash region
   uint32_t imageHardwareVersion; // Hardware version from loaded image
   uint32_t imageSoftwareVersion; // Software version from loaded image
};
#pragma pack(pop)

#endif /* SOURCES_USBCOMMANDMESSAGE_H_ */
