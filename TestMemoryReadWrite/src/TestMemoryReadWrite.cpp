/*
 * test.cpp
 *
 *  Created on: 06/05/2011
 *      Author: podonoghue
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "USBDM_API.h"
#include "Names.h"

//! Check error code from USBDM API function
//!
//! @param rc - error code to access
//!
//! An error message is printed with line # and the program exited if
//! rc indicates any error
//!
void check(USBDM_ErrorCode rc, const char *file = NULL, unsigned lineNum = 0) {
   if (rc == BDM_RC_OK) {
      fprintf(stdout, "OK,     [%s:#%4d]\n", file, lineNum);
      fflush(stdout);
      return;
   }
   fprintf(stdout, "Failed, [%s:#%4d] Reason= %s\n", file, lineNum,  USBDM_GetErrorString(rc));
   fflush(stdout);
   USBDM_Close();
   USBDM_Exit();
   exit(rc);
}

//! Convenience macro to add line number information to check()
//!
#define CHECK(x) check((x), __FILE__, __LINE__)

//! Set target Type
static void setTargetCommand(TargetType_t targetType, unsigned interfaceSpeed) {

   USBDM_ErrorCode  rc;
   unsigned int deviceCount, deviceNum;

   CHECK(USBDM_Init());
   CHECK(USBDM_FindDevices(&deviceCount));
   for (deviceNum=0; deviceNum<deviceCount; deviceNum++) {
      rc = USBDM_Open(deviceNum);
      if (rc == BDM_RC_OK) {
         break;
      }
   }
   check(rc);
   fprintf(stdout, "Opened device #%d\n", deviceNum);

   //! Options to use with BDM
   static USBDM_ExtendedOptions_t bdmOptions = {
      sizeof(USBDM_ExtendedOptions_t),
      targetType,
   };

   CHECK(USBDM_GetDefaultExtendedOptions(&bdmOptions));

   bdmOptions.targetVdd          = BDM_TARGET_VDD_3V3;
   bdmOptions.autoReconnect      = AUTOCONNECT_STATUS;
   bdmOptions.interfaceFrequency = interfaceSpeed;
   CHECK(USBDM_SetExtendedOptions(&bdmOptions));
   CHECK(USBDM_SetTargetType(targetType));
}

USBDM_ErrorCode testMemoryReadWrite(long &count, uint32_t address, uint32_t size) {
   #define MAX_BUFF (0x20000)
   uint8_t buffer1[MAX_BUFF];
   uint8_t buffer2[MAX_BUFF];
   USBDM_ErrorCode  rc;
   long testsDone = 0;

   if (size >= MAX_BUFF) {
      size = MAX_BUFF-1;
   }
   do {
      for (unsigned sub=0; sub<size; sub++) {
         buffer1[sub] = rand() & 0xFF;
      }
      MemorySpace_t memSpaces[] = {MS_Byte, MS_Word, MS_Long};
      MemorySpace_t memorySize = memSpaces[rand()%3];
      uint32_t startAddress    = address + rand()%size;
      uint32_t endAddress      = startAddress + rand()%size - 1;
      if (endAddress > (address+size-1)) {
         endAddress = (address+size-1);
      }
      unsigned int blockSize = endAddress - startAddress + 1;
      // Make aligned
      startAddress &= ~(memorySize-1);
      blockSize    &= ~(memorySize-1);
//      fprintf(stdout, "%10ld: Testing %s:[0x%8X..0x%8X]\n", testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1);
      rc = USBDM_WriteMemory(memorySize,blockSize,startAddress,buffer1);
      if (rc == BDM_RC_USB_RETRY_OK) {
         fprintf(stdout, "%10ld: Failed write (rerty OK) %s:[0x%8X..0x%8X], rc = %s\n",
                testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1,
                USBDM_GetErrorString(rc));
         rc = BDM_RC_OK;
      }
      if (rc != BDM_RC_OK) {
         fprintf(stdout, "%10ld: Failed write %s:[0x%8X..0x%8X], rc = %s\n",
                testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1,
                USBDM_GetErrorString(rc));
      }
      else {
         rc = USBDM_ReadMemory(memorySize,blockSize,startAddress,buffer2);
         if (rc == BDM_RC_USB_RETRY_OK) {
            fprintf(stdout, "%10ld: Failed read %s:[0x%8X..0x%8X], rc = %s\n",
                   testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1,
                   USBDM_GetErrorString(rc));
            rc = BDM_RC_OK;
         }
         if (rc != BDM_RC_OK) {
            fprintf(stdout, "%10ld: Failed read %s:[0x%8X..0x%8X], rc = %s\n",
                   testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1,
                   USBDM_GetErrorString(rc));
         }
         else {
            if (memcmp(buffer1, buffer2, blockSize) != 0) {
               rc = BDM_RC_FAIL;
               fprintf(stdout, "%10ld: Failed verify %s:[0x%8X..0x%8X]\n", testsDone, getMemSpaceName(memorySize), startAddress, startAddress+blockSize-1);
            }
         }
      }
      fprintf(stdout, "."); fflush(stdout);
      if (count > 0) {
         count--;
      }
      testsDone++;
      if ((testsDone % 50) == 0) {
         fprintf(stdout, ": %4ld\n", testsDone); fflush(stdout);
      }
   } while (((rc == BDM_RC_OK)||(rc == BDM_RC_USB_RETRY_OK)) && (count != 0));

   count = testsDone;
   return rc;
}

void doTest(long &count, TargetType_t targetType, unsigned interfaceSpeed, uint32_t address, uint32_t size) {
   fprintf(stdout, "doTest([0x%08X..0x%08X])\n", address, address+size-1);
   setTargetCommand(targetType, interfaceSpeed);
   CHECK(USBDM_Connect());
   CHECK(USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT)));
   // Only necessary for some targets where the connection speed may change after reset
   CHECK(USBDM_Connect());
   if (targetType == T_CFVx) {
      CHECK(USBDM_WriteCReg(CFV1_CRegFLASHBAR, 0x00000000+0x61));
      CHECK(USBDM_WriteCReg(CFV1_CRegRAMBAR,   0x20000000+0x21));
   }
#if 0
   unsigned long frequency;
   CHECK(USBDM_GetSpeed(&frequency));
   fprintf(stdout, "Initial Frequency = %ld kHz\n", frequency);

//   rc = USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_SOFTWARE));
   CHECK(USBDM_TargetGo());
   CHECK(USBDM_Connect());
   CHECK(USBDM_GetSpeed(&frequency));
   fprintf(stdout, "Final Frequency   = %ld kHz\n", frequency);

   CHECK(USBDM_TargetHalt());
//   CHECK((USBDM_WriteControlReg(0x05));

   CHECK(USBDM_GetSpeed(&frequency));
   fprintf(stdout, "Final Frequency   = %ld kHz\n", frequency);
#endif

   // Initialise random seed
//   srand ( time(NULL) );

   CHECK(testMemoryReadWrite(count, address, size));

   CHECK(USBDM_Close());
}

struct TestData {
   const char *name;
   uint32_t startAddress;
   uint32_t size;
   unsigned interfaceSpeed;
};

TestData testData[] = {
   /* T_HCS12     */ {"HCS12     ", 0x00000000, 0x00000000,     0},
   /* T_HCS08     */ {"HCS08     ", 0x00000000, 0x00000000,     0},
   /* T_RS08      */ {"RS08      ", 0x00000000, 0x00000000,     0},
   /* T_CFV1      */ {"CFV1      ", 0x00000000, 0x00000000,     0},
   /* T_CFVx      */ {"CFVx      ", 0x20000000, 0x00010000,  500},
   /* T_JTAG      */ {"JTAG      ", 0x00000000, 0x00000000,  4000},
   /* T_EZFLASH   */ {"EZFLASH   ", 0x00000000, 0x00000000,  4000},
   /* T_MC56F80xx */ {"MC56F80xx ", 0x00000000, 0x00000000,  4000},
   /* T_ARM_JTAG  */ {"ARM_JTAG  ", 0x00000000, 0x00000000,  4000},
   /* T_ARM_SWD   */ {"ARM_SWD   ", 0x00000000, 0x00000000, 12000},
   /* T_ARM       */ {"ARM       ", 0x00000000, 0x00000000, 12000},
   /* T_S12Z      */ {"S12Z      ", 0x00000000, 0x00000000,     0},
};

void doTest(long int &numTests, TargetType_t targetType) {
   doTest(numTests, targetType, testData[targetType].interfaceSpeed, testData[targetType].startAddress, testData[targetType].size );
}

int main(void) {

#define TARGET_TYPE T_CFVx

   long numTests = 1000;

   struct timeval timeStart;
   struct timeval timeEnd;
   if (gettimeofday(&timeStart, NULL) < 0) {
      return -1;
   }
   doTest(numTests, TARGET_TYPE);

   fprintf(stdout, "Testing Passed after %ld read/writes\n", numTests);

   CHECK(USBDM_Close());
   if (gettimeofday(&timeEnd, NULL) < 0) {
      return -1;
   }
   double elapsedTime = (timeEnd.tv_sec-timeStart.tv_sec) + ((timeEnd.tv_usec-timeStart.tv_usec)/1000000.0);
   fprintf(stdout, "Elapsed Time = %f\n", elapsedTime);
   return 0;
}
