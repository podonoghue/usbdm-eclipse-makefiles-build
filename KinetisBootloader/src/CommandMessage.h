/*
 * CommandMessage.h
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */

#ifndef SOURCES_COMMANDMESSAGE_H_
#define SOURCES_COMMANDMESSAGE_H_

#include <stdint.h>

static constexpr uint16_t HW_LOGIC_BOARD_V2 = 1;
static constexpr uint16_t BOOTLOADER_V1     = 1;

/**
 * Commands available
 */
enum Command : uint32_t {
   Command_Nop,            // No operation
   Command_Identify,       // Identify boot-loader and hardware versions
   Command_EraseFlash,     // Erase all of flash image
   Command_ReadBlock,      // Read block from flash
   Command_ProgramBlock,   // Program block to flash
   Command_Reset,          // Reset device
};

/**
 * Result of command
 */
enum Status : uint32_t {
   Status_OK,    //!< Status_OK
   Status_Failed,//!< Status_Failed
};

/**
 * Get command name as string
 *
 * @param command
 *
 * @return Name as string
 *
 * @note return value is a pointer to a STATIC object - do not free
 */
static inline const char *getCommandName(Command command) {
   static const char *names[] = {
         "Command_Nop",
         "Command_Identify",
         "Command_EraseFlash",
         "Command_ReadBlock",
         "Command_ProgramBlock",
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
struct CommandMessage {
   Command  command;       // Command to execute
   uint32_t startAddress;  // Target memory address
   uint32_t byteLength;    // Size of data
   uint8_t  data[1024];    // Data (up to 1 flash block)
};

/**
 * Simple USB command message
 */
struct SimpleCommandMessage {
   Command  command;       // Command to execute
   uint32_t startAddress;  // Target memory address
   uint32_t byteLength;    // Size of data
};

/**
 * General USB response message
 */
struct ResponseMessage {
   Status   status;        // Last status
   uint32_t byteLength;    // Size of data
   union {
      struct {
         uint16_t hardwareVersion;    // Hardware version
         uint16_t bootloaderVersion;  // Boot-loader version
      };
      uint8_t  data[1024];    // Data
   };
};

/**
 * USB status response message
 */
struct ResponseStatus {
   Status   status;        // Last status
   uint32_t byteLength;    // Size of data
};

/**
 * USB identify response message
 */
struct ResponseIdentify {
   Status   status;             // Last status
   uint32_t byteLength;         // Size of data (not used)
   uint16_t hardwareVersion;    // Hardware version
   uint16_t bootloaderVersion;  // Boot-loader version
};
#pragma pack(pop)

#endif /* SOURCES_COMMANDMESSAGE_H_ */
