/*
 * Main.cpp
 *
 *  Created on: 21/10/2011
 *      Author: podonoghue
 *
 *  Simple program demonstrating use of USBDM API
 *
 *  This program dumps the contents of a chip to stdout in S19 format.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
#include <memory.h> // linux
#else
#include <mem.h> // win
#endif
#include "USBDM_API.h"

// Required API
#define USBDM_API_VERSION_REQUIRED (0x40A00) // Need V4.10.0

// Static check that correct API (header file) is being used
#if (USBDM_API_VERSION < USBDM_API_VERSION_REQUIRED)
#error "This program requires USBDM version 4.10.0 or later"
#endif

// Maximum size of a S-record, should be power of 2
const int maxSrecSize = (1<<4);

// A region of flash to dump
//
typedef struct {
   uint32_t start;  //< start address (inclusive)
   uint32_t end;    //< end address (inclusive)
} MemRange;

// Describes a target & region to dump
//
struct DeviceDescription {
   const char  *name;           // Name of device
   TargetType_t targetType;     // Target e.g. T_HCS12
   uint16_t     interfaceSpeed; // Speed to connect at (kHz)
   unsigned     numRanges;      // Number of entries in ranges
   MemRange     ranges[10];     // Ranges to dump
};

// Target descriptions
DeviceDescription deviceDescriptions[] = {
{     "MC9S08JM60",
      T_HCS08,
      0,
      2,
      {{0x10B0, 0x17FF},
       {0x1960, 0xFFFF},}
},
{
      "MC9S12NE64",
      T_HCS12,
      0,
      2,
      {{0x4000, 0x7FFF},
       {0xC000, 0xFFFF},}
},
{
      "MCF51CN128",
      T_CFV1,
      0,
      1,
      {{0x000000, 0x01FFFF},}
},
{
      "MCF51JF128",
      T_CFV1,
      0,
      1,
      {{0x000000, 0x01FFFF},}
},
{
      "MK40X256",
      T_ARM,
      12000,
      1,
      {{0x000000, 0x03FFFF},}
},
};

// Check error code from USBDM API function
//
// @param rc - error code to access
//
// An error message is printed with line # and the program exited if
// rc indicates any error
//
void check(USBDM_ErrorCode rc, const char *file = NULL, unsigned lineNum = 0) {
   if (rc == BDM_RC_OK) {
      fprintf(stderr, "OK,     [%s:#%4d]\n", file, lineNum);
      return;
   }
   fprintf(stderr, "Failed, [%s:#%4d] Reason= %s\n", file, lineNum,  USBDM_GetErrorString(rc));
   USBDM_Close();
   USBDM_Exit();
   exit(rc);
}

// Convenience macro to add line number information to check()
//
#define CHECK(x) check((x), __FILE__, __LINE__)

// Dump a single S-record to stdout
//
// @param buffer   location of data to dump
// @param address  base address of data
// @param size     number of bytes to dump
//
// @note size must be less than or equal to \ref maxSrecSize
// @note S-records filled with 0xFF are discarded
//
void dumpSrec(uint8_t *buffer, uint32_t address, uint8_t size) {

   // Discard 0xFF filled records (blank Flash)
   bool allFF = true;
   for(int sub=0; sub<size; sub++) {
      if (buffer[sub] != 0xFF ) {
         allFF = false;
         break;
      }
   }
   if ((size == 0) || allFF) {
      return;
   }
   uint8_t *ptr = buffer;
   uint8_t checkSum;
   if ((address) < 0x10000U) {
      printf("S1%02X%04X", size+3, address);
      checkSum = size+3;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else if (address < 0x1000000U) {
      printf("S2%02X%06X", size+4, address);
      checkSum = size+4;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else {
      printf("S3%02X%08X", size+5, address);
      checkSum = size+5;
      checkSum += (address>>24)&0xFF;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   while (size-->0) {
      checkSum += *ptr;
      printf("%02X", *ptr++);
   }
   checkSum = checkSum^0xFF;
   printf("%02X\n", checkSum);
}

// Dump data as S-records to stdout
//
// @param buffer   location of data to dump
// @param address  base address of data
// @param size     number of bytes to dump
//
// @note Regions filled with 0xFF are discarded
//
void dump(uint8_t *buffer, uint32_t address, unsigned size) {
   fprintf(stderr, "dump [0x%06X-0x%06X]\n", address, address+size-1);

   while (size>0) {
      uint8_t oddBytes = address & (maxSrecSize-1);
      uint8_t srecSize = maxSrecSize - oddBytes;
      if (srecSize > size) {
         srecSize = (uint8_t) size;
      }
      dumpSrec(buffer, address, srecSize);
      address += srecSize;
      buffer  += srecSize;
      size    -= srecSize;
   }
}

// Dynamic check for USBDM DLL version
//
// @return BDM_RC_OK if successful
//
USBDM_ErrorCode checkAPI() {
   if (USBDM_DLLVersion() < USBDM_API_VERSION_REQUIRED) {
      fprintf(stderr, "checkAPI(), required Version=%d, DLL version=%d \n",
            USBDM_API_VERSION_REQUIRED, USBDM_DLLVersion());
      return BDM_RC_WRONG_DLL_REVISION;
   }
   return BDM_RC_OK;
}

// Dump the contents of a memory range from target chip
//
void dumpMemoryRange(MemRange &memoryRange) {
   // Buffer for flash image
   uint8_t buffer[0x10000];
   memset(buffer, 0xFF, sizeof(buffer));
   fprintf(stderr, "Range [0x%06X-0x%06X]\n", memoryRange.start, memoryRange.end);
   uint32_t size    = memoryRange.end-memoryRange.start+1;
   uint32_t address = memoryRange.start;
   while (size > 0) {
      uint32_t blockSize = size;
      if (blockSize > sizeof(buffer)) {
         blockSize = sizeof(buffer);
      }
      CHECK(USBDM_ReadMemory(1, blockSize, address, buffer));
      dump(buffer, address, blockSize);
      address += blockSize;
      size    -= blockSize;
   }
}

// Open BDM & Connect with target
//
// @param deviceDescription - Describes device to be connected to
//
void openAndConnect(DeviceDescription &deviceDescription) {
   CHECK(USBDM_Init());
   unsigned deviceCount;
   CHECK(USBDM_FindDevices(&deviceCount));
   CHECK(USBDM_Open(0));

   USBDM_bdmInformation_t bdmInformation = {sizeof(bdmInformation)};

   USBDM_GetBdmInformation(&bdmInformation);
   int ver = bdmInformation.BDMsoftwareVersion;
   fprintf(stderr, "BDM Firmware version = %d.%d.%d\n", (ver>>16)&0xFF,(ver>>8)&0xFF,ver&0xFF);
   CHECK((bdmInformation.BDMsoftwareVersion < USBDM_API_VERSION_REQUIRED)?BDM_RC_WRONG_BDM_REVISION:BDM_RC_OK);

   ver = USBDM_DLLVersion();
   fprintf(stderr, "DLL version = %d.%d.%d\n", (ver>>16)&0xFF,(ver>>8)&0xFF,ver&0xFF);
   CHECK((ver < USBDM_API_VERSION_REQUIRED)?BDM_RC_WRONG_DLL_REVISION:BDM_RC_OK);

   // Example of changing options, requires version >= V4.9.4
   USBDM_ExtendedOptions_t options = {
         sizeof(USBDM_ExtendedOptions_t),
         deviceDescription.targetType};

   CHECK(USBDM_GetDefaultExtendedOptions(&options));
   options.resetDuration         = 500;
   options.resetReleaseInterval  = 200;
   options.resetRecoveryInterval = 200;
   options.targetVdd             = BDM_TARGET_VDD_3V3;
   options.autoReconnect         = AUTOCONNECT_STATUS;
   options.cycleVddOnConnect     = true;
   options.interfaceFrequency    = deviceDescription.interfaceSpeed;
   CHECK(USBDM_SetExtendedOptions(&options));

   CHECK(USBDM_SetTargetType(deviceDescription.targetType));
   CHECK(USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT)));
   bool retry = false;
   USBDM_ErrorCode rc;
   // Retry loop for HCS08/CFV1 targets as may need power-on reset
   do {
      rc = USBDM_Connect();
      if (rc == BDM_RC_SYNC_TIMEOUT) {
         USBDM_ControlPins(PIN_BKGD_LOW);
         fprintf(stderr, "Failed to connect: Error - %s\n"
                         "Please cycle target power & press enter to retry, N to abort: ",
                         USBDM_GetErrorString(rc));
         char buff[1000];
         gets(buff);
         int ch = buff[0];
         retry = (ch != 'N') && (ch != 'n');
         USBDM_ControlPins(PIN_RELEASE);
      }
   } while ((rc != BDM_RC_OK) && retry);
   CHECK(rc);
}

// Dump the contents of a chip
//
// @param deviceDescription - Describes device to be dumped
//
void dumpChip(DeviceDescription &deviceDescription) {
   fprintf(stderr, "Dumping %s\n", deviceDescription.name);

   openAndConnect(deviceDescription);
   for (unsigned sub=0;
        sub<deviceDescription.numRanges;
        sub++) {
      dumpMemoryRange(deviceDescription.ranges[sub]);
   }
   USBDM_Close();
   USBDM_Exit();
}

// Print simple usage message & exit program
//
void usage(void) {
   fprintf(stderr,
         "Usage:  CopyFlash target\n"
         "Targets:\n");
   for (unsigned index=0;
        index < (sizeof(deviceDescriptions)/sizeof(deviceDescriptions[0]));
        index++) {
      fprintf(stderr, "%3d: %s\n", index, deviceDescriptions[index].name);
   }
   CHECK(BDM_RC_ILLEGAL_PARAMS);
}

int main(int argc, char *argv[]) {

   CHECK(checkAPI());

   if (argc != 2) {
      usage();
   }
   unsigned option = atoi(argv[1]);
   if (option>=(sizeof(deviceDescriptions)/sizeof(deviceDescriptions[0]))) {
      usage();
   }
   dumpChip(deviceDescriptions[option]);
   return 0;
}
