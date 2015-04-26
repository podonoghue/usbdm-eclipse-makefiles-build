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
#define USBDM_API_VERSION_REQUIRED (0x40905) // Need V4.9.5

// Static check that correct API (header file) is being used
#if (USBDM_API_VERSION < USBDM_API_VERSION_REQUIRED)
#error "This program requires USBDM version 4.9.5 or later"
#endif

//! Maximum size of a S-record, should be power of 2
const int maxSrecSize = (1<<4);

//! Buffer for flash image
uint8_t buffer[0x3FFFF];

//! A region of flash to dump
//!
typedef struct {
   uint16_t start;
   uint16_t end;
} MemRange;

// List of flash regions to dump
MemRange memRanges[] = {
      {0x10B0, 0x17FF},
      {0x1960, 0xFFFF},
};

//! Check error code from USBDM API function
//!
//! @param rc - error code to access
//!
//! An error message is printed with line # and the program exited if
//! rc indicates any error
//!
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

//! Convenience macro to add line number information to check()
//!
#define CHECK(x) check((x), __FILE__, __LINE__)

//! Dump a single S-record to stdout
//!
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note size must be less than or equal to \ref maxSrecSize
//! @note S-records filled with 0xFF are discarded
//!
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

//! Dump data as S-records to stdout
//!
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note Regions filled with 0xFF are discarded
//!
void dump(uint8_t *buffer, uint32_t address, unsigned size) {
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

int main(void) {
const int deviceNumber = 0; // USBDM device to open, devices enumerated from 0...

   CHECK(USBDM_Init());
   unsigned deviceCount;
   CHECK(USBDM_FindDevices(&deviceCount));
   // May check deviceCount here if desired or let USBDM_Open() fail
   CHECK(USBDM_Open(deviceNumber));

   USBDM_bdmInformation_t bdmInformation = {sizeof(bdmInformation)};
   USBDM_GetBdmInformation(&bdmInformation);
   CHECK((bdmInformation.BDMsoftwareVersion < 0x40905)?BDM_RC_WRONG_BDM_REVISION:BDM_RC_OK);

   // Change any options here (>V4.9.4)
   USBDM_ExtendedOptions_t options = {sizeof(USBDM_ExtendedOptions_t), T_ARM};
   CHECK(USBDM_GetDefaultExtendedOptions(&options));
   options.resetDuration         = 1000;
   options.resetReleaseInterval  = 500;
   options.resetRecoveryInterval = 1500;
   options.targetVdd             = BDM_TARGET_VDD_3V3;
   options.autoReconnect         = AUTOCONNECT_STATUS;
   CHECK(USBDM_SetExtendedOptions(&options));
   CHECK(USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE));

   CHECK(USBDM_SetTargetType(T_CFV1));
   CHECK(USBDM_TargetReset((TargetMode_t)(RESET_DEFAULT|RESET_SPECIAL)));
   CHECK(USBDM_Connect());
   memset(buffer, 0xFF, sizeof(buffer));
   for (unsigned sub=0; sub<sizeof(memRanges)/sizeof(memRanges[0]); sub++) {
      fprintf(stderr, "Range [0x%06X-0x%06X]\n",
              memRanges[sub].start, memRanges[sub].end);
      CHECK(USBDM_ReadMemory(1,
                             memRanges[sub].end-memRanges[sub].start+1,
                             memRanges[sub].start,
                             buffer+memRanges[sub].start));
   }
   USBDM_Close();
   USBDM_Exit();
   dump(buffer, 0x0000, sizeof(buffer));
   return 0;
}
