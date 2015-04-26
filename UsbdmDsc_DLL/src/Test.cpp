/*! \file
    \brief Tests for MC56F00xx EONCE debugging interface

    \verbatim
    Copyright (C) 2009  Peter O'Donoghue

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

    Change History
   +====================================================================
   |   1 Jun 2009 | Created
   +====================================================================
    \endverbatim
*/
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/progdlg.h>

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <commctrl.h>
#include <math.h>

#include "Common.h"
#include "USBDM_API.h"
#include "USBDM_AUX.h"
#include "Log.h"
#include "TestUsbdmApp.h"
#include "USBDMDialogue.h"
#include "version.h"
#include "USBDM_DSC_API.h"
#include "USBDM_DSC_API_Private.h"
#include "DSC_Utilities.h"
#include "USBDMDialogue.h"

//! Does a basic check of all registers
//!
USBDM_ErrorCode basicTestRegisterReadWrite(void) {

   enableLogging(true);
   print("basicTestRegisterReadWrite()\n");
   int regNo;
   int writeRegValue = 0x12345678;

   print("Register:w        Write           Read   \n"
         "=========================================\n");

   for (regNo = DSC_RegX0; regNo<=DSC_RegPC; regNo++) {
//   for (regNo = DSC_RegX0; regNo<=DSC_RegX0; regNo++) {
//   for (;;) {
//      regNo = DSC_RegX0;
      enableLogging(false);
      if (regNo == DSC_RegOMR)
         continue;
      if (regNo == DSC_RegSR)
         continue;
      const char *name    = DSC_GetRegisterName((DSC_Registers_t)regNo);
      uint8_t registerSize     = DSC_GetRegisterSize((DSC_Registers_t)regNo);
      JTAG32 regWriteData(writeRegValue, registerSize);

      writeCoreReg((DSC_Registers_t)regNo, writeRegValue);
      uint32_t temp;
      readCoreReg((DSC_Registers_t)regNo, &temp);
      JTAG32 regReadData(temp, registerSize);

      enableLogging(true);
      print("%6s:%-2d %14s ", name, registerSize, regWriteData.toString());
      print("%14s\n", regReadData.toString());
   }
   print("doJTAG() - done test sequence\n");
   return BDM_RC_OK;
}

//! Register read-write test
//!
USBDM_ErrorCode testRegisterReadWrite(DSC_Registers_t regNo) {
uint32_t writeValue, readValue;
USBDM_ErrorCode rc  = BDM_RC_OK;
const char *name    = DSC_GetRegisterName((DSC_Registers_t)regNo);
uint8_t registerSize     = DSC_GetRegisterSize((DSC_Registers_t)regNo);
uint32_t maxValue        = (1UL<<registerSize);
const int numTests  = 100;       // Number of tests to do
int seed            = 10000;     // Choose a seed value
int i;
int errCount = 0;

   srand(seed);            // Initialize random number generator
//   enableLogging(true);

   // Register read/write test
   fprintf(stderr, "Testing Register: %s", name);
   for (i=0; i<numTests; i++) {
      writeValue = trunc(((double)rand()/
                          ((double)(RAND_MAX)+(double)(1)))*(maxValue));
      writeValue ^= writeValue>>16;
      rc = writeCoreReg(regNo, writeValue);
      if (rc != BDM_RC_OK)
         break;
      rc = readCoreReg(regNo, &readValue);
      if (rc != BDM_RC_OK)
         break;
//      fprintf(stderr, "testValue = %X\n", writeValue);
      if ((i&0xFFF) == 0)
         fprintf(stderr, "\n%6d", i);
      if ((i&0xFF) == 0)
         fprintf(stderr, ".");
//      fprintf(stderr, "%X\n", writeValue);
      if (writeValue != readValue) {
         errCount++;
         fprintf(stderr, "\n%10d:Failed - Wrote 0x%4.4X, Read 0x%4.4X\n", i, writeValue, readValue);
         // Try reading register again - see if read only error
         rc = readCoreReg(regNo, &readValue);
         if (rc != BDM_RC_OK)
            break;
         if (writeValue != readValue) {
            fprintf(stderr, "%10d:2nd read failed - Wrote 0x%4.4X, Read 0x%4.4X\n", i, writeValue, readValue);
         }
      }
      if (errCount>5) {
         rc = BDM_RC_FAIL;
         break;
      }
   }
   if (rc == BDM_RC_OK)
      fprintf(stderr, "Pass\n");
   return rc;
}

//! Does a basic read/write check of all registers
//!
USBDM_ErrorCode testAllRegisterReadWrite(void) {
   int regNo;

   enableLogging(true);

   print("testAllRegisterReadWrite()\n");
   print("Register:w        Write           Read   \n"
         "=========================================\n");

   wxProgressDialog dialogue(_("Register Test"),
                             _("testing..."),
                             DSC_RegPC,
                             NULL,
                             wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_AUTO_HIDE
                             );


   for (regNo = DSC_RegX0; regNo<=DSC_RegPC; regNo++) {
      if (regNo == DSC_RegOMR) // Crashes target?
         continue;
      if (regNo == DSC_RegSR) // Crashes target?
         continue;
      testRegisterReadWrite((DSC_Registers_t)regNo);
      dialogue.Update(regNo, wxEmptyString);
   }

   dialogue.Show(false);

   print("testAllRegisterReadWrite() - done test sequence\n");
   return BDM_RC_OK;
}

//! Memory read-write test
//!
USBDM_ErrorCode testMemoryReadWrite(MemorySpace_t memorySpace, uint32_t address, uint32_t rangeSize) {
USBDM_ErrorCode rc = BDM_RC_OK;
unsigned i,j;
uint8_t writeBuffer[rangeSize];
uint8_t readBuffer[rangeSize];
uint32_t maxValue             = (1UL<<8);  // Array is filled with 8-bit random #s
const unsigned numTests  = 1000*2/3;  // Number of tests to do
int seed                 = 10000;     // Choose a seed value
unsigned reportInterval = (numTests/100);

   if (reportInterval == 0)
      reportInterval = 1;

   srand(seed);            // Initialise random number generator

   const wxChar *memorySpaceName = _("Unknown");
   switch(memorySpace&MS_SPACE) {
      case MS_Program: memorySpaceName = _("Program(P)"); break;
      case MS_Data:    memorySpaceName = _("Data(X)"); break;
   }
   const wxChar *elementSize = _("?");
   switch(memorySpace&MS_SIZE) {
      case MS_Byte:    elementSize = _("Byte"); break;
      case MS_Word:    elementSize = _("Word"); break;
      case MS_Long:    elementSize = _("Long"); break;
   }
   wxString message;
   message.Printf(_("Testing Memory %s:%s\n\n"), memorySpaceName, elementSize);

   wxProgressDialog dialogue(_("Memory Read/Write Test"),
                             message,
                             numTests,
                             NULL,
                             wxPD_APP_MODAL|wxPD_ELAPSED_TIME|wxPD_AUTO_HIDE
                             );

   enableLogging(true);
   for (i=0; i<numTests; i++) {
      // Fill array with random stuff
      for(j=0; j<rangeSize; j++) {
         writeBuffer[j] = trunc(((double)rand()/
                                ((double)(RAND_MAX)+(double)(1)))*(maxValue));
      }
      DSC_WriteMemory(memorySpace, rangeSize, address, writeBuffer);
//      DSC_WriteMemory(MS_XWord, rangeSize, address>, writeBuffer);
      if (rc != BDM_RC_OK)
         break;
      DSC_ReadMemory(memorySpace, rangeSize, address, readBuffer);
//      DSC_ReadMemory(MS_XWord, rangeSize, address>>1, readBuffer);
      if (rc != BDM_RC_OK)
         break;
      for(j=0; j<rangeSize; j++) {
         if (readBuffer[j] != writeBuffer[j]) {
            rc = BDM_RC_FAIL;
            break;
         }
      }
      if ((i&0xFFF) == 0)
         fprintf(stderr, "\n0x%2.2X: ", (i>>8));
      if ((i&0xFF) == 0)
         fprintf(stderr, ".");
      if (rc != BDM_RC_OK) {
         fprintf(stderr, "Failed @0x%X\n", i);
         break;
      }
      if ((i % reportInterval) == 0) {
         message.Printf(_("Testing Memory %s:%s\n\n"
                          "Test # %d."), memorySpaceName, elementSize, i);
         dialogue.Update(i, message);
      }
   }
   dialogue.Show(false);

   return rc;
}

USBDM_ErrorCode testTargetExecution(void) {
static const uint8_t program[] = {
  0xE8,0x0A,0x00,0xE4, //    do #10,endloop
  0x87,0x44,0x00,0x7B, //    move.w   #123,X0
  0xE7,0x80,           //    move.w   #0,Y1
  0x7A,0xC0,           //    add      X0,Y0
};                     // endloop
uint8_t check[sizeof(program)];
USBDM_ErrorCode rc;
uint32_t omrRegValue;
uint32_t loadAddress    = 0x8000;
uint32_t executeAddress = 0x8000;
OnceStatus_t status;

   rc = DSC_WriteMemory(MS_PWord, sizeof(program), loadAddress, program);
   if (rc != BDM_RC_OK)
      return rc;
   rc = DSC_ReadMemory(MS_PWord, sizeof(program), loadAddress, check);
   if (rc != BDM_RC_OK)
      return rc;
//   rc = readMem(1, executeAddress, 2, sizeof(program), check);
//   if (rc != BDM_RC_OK)
//      return rc;

//   enableLogging(true);
   readCoreReg(DSC_RegOMR, &omrRegValue);
   writeCoreReg(DSC_RegOMR, omrRegValue|0x0080);
   readCoreReg(DSC_RegOMR, &omrRegValue);

   writeCoreReg(DSC_RegPC, executeAddress);
   readCoreReg(DSC_RegPC, &executeAddress);

   rc = enableONCE(&status);

   int i;
   for (i=0; i<10;i++) {
      DSC_TargetGo();
//      Sleep(100);
      readCoreReg(DSC_RegPC, &executeAddress);
      rc = enableONCE(&status);
   }

   rc = DSC_TargetHalt();
   readCoreReg(DSC_RegPC, &executeAddress);
   rc = enableONCE(&status);

   return BDM_RC_OK;
}

USBDM_ErrorCode testMemoryRead(void) {
static uint8_t fillMemory[] = {
      11,
         3, 0xe4,0x10,0xAA,0xAA,0xAA,0xAA, //  move.l #$AAAAAAAA,A
         3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
         2, 0x87,0x56,0x12,0x34,           //  move.w #$1234,A0
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x00, //  move.w A0,X:>>$8000
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x01, //  move.w A0,X:>>$8001
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x02, //  move.w A0,X:>>$8002
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x03, //  move.w A0,X:>>$8003
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x04, //  move.w A0,X:>>$8004
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x05, //  move.w A0,X:>>$8005
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x06, //  move.w A0,X:>>$8006
         3, 0xE0,0x30,0xD6,0xFC,0x80,0x07, //  move.w A0,X:>>$8007
   };
const uint8_t referenceData[] = {0x12, 0x34, 0x12, 0x34, 0x12, 0x34, 0x12, 0x34,
                            0x12, 0x34, 0x12, 0x34, 0x12, 0x34, 0x12, 0x34,
};
uint8_t buffer[100];
USBDM_ErrorCode rc;

   rc = DSC_ExecuteTargetInstruction(fillMemory);
   if (rc != BDM_RC_OK)
      return rc;

   // 'Manually' fill memory with data
   rc = DSC_ReadMemory(MS_XWord, sizeof(referenceData), 0x8000, buffer);
   if (rc != BDM_RC_OK)
      return rc;

   print("testMemoryRead() - Data should be:\n");
   printDump(referenceData, sizeof(referenceData), 0x8000, WORD_ADDRESS|WORD_DISPLAY);

   // Read the data back
   print("testMemoryRead() - Data is:\n");
   printDump(buffer, sizeof(referenceData), 0x8000, WORD_ADDRESS|WORD_DISPLAY);
   return rc;
}

//================================================================================
//================================================================================
//================================================================================

extern USBDM_ErrorCode readCoreRegX(void);
extern USBDM_ErrorCode writeCoreRegX(void);
extern USBDM_ErrorCode testTargetExecutionSpeed(void);

static USBDMStatus_t USBDMStatus;
static dscInfo_t     dscInformation;

//!  Display USBDM Configuration dialogue
//!  @note the target device is not opened.
//!
//!  Displays an error dialogue on failure.
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
static USBDM_ErrorCode configureBDM(void) {
USBDM_ErrorCode bdmRC = BDM_RC_OK;

   print("configureBDM()\n");

   USBDM_Init();

   // Create the USBDM Dialogue
   USBDMDialogue dialogue(T_MC56F80xx, _("USBDM Configure"));

   //   SetTopWindow(dialogue);
   dialogue.Create(NULL);
   bdmRC = dialogue.execute("Unused", "Dummy");

//   dialogue.getBDMOptions(bdmOptions);

   if (bdmRC != BDM_RC_OK) {
      USBDM_Exit();
   }

   return bdmRC;
}

//===================================================================
//! Extended process for connecting to the target
//!
//! This procedure will prompt the user to
//! cycle the target power supply if necessary.  The
//! BKGD line will be held low while this is occurring.
//!
//! @return \n
//!     DI_OK              => OK \n
//!     DI_ERR_FATAL       => Error see \ref currentErrorString
//!
static USBDM_ErrorCode targetConnect(void){
USBDM_ErrorCode rc;

   print( "   targetConnect()\n" );

   do {
      rc = getBDMStatus(&USBDMStatus);
      if (rc != BDM_RC_OK)
         break;

      rc = DSC_TargetConnect();
      if (rc != BDM_RC_OK) {
         rc = DSC_TargetConnect(); // retry
      }
      if (rc != BDM_RC_OK)
         break;

      dscInformation.size = sizeof(dscInfo_t);
      rc = DSC_GetInfo(&dscInformation);
      if (rc != BDM_RC_OK)
         break;
   } while (0);

   return rc;
}

//! \brief xx
//!
static USBDM_ErrorCode doJTAG(void) {
USBDM_ErrorCode rc;
JTAG32 idcode(0,32);
OnceStatus_t onceStatus;
JTAG32 regValue(0,32);
//uint32_t regValueU32;
uint32_t idCode;
//uint8_t buffer1[1000];
//uint8_t buffer2[1000];
int retry;

   enableLogging(true);

   do {

      // Close any existing connection
      USBDM_Close();

      rc = configureBDM();
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = USBDM_SetTargetTypeWithRetry(T_MC56F80xx);
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = targetConnect();
      if (rc != BDM_RC_OK) {
         break;
      }

//      unsigned char data[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, };
//      do {
//         USBDM_JTAG_Write(10, JTAG_STAY_SHIFT, data);
//         USBDM_JTAG_Write(40, JTAG_EXIT_IDLE|JTAG_WRITE_1, data);
//         USBDM_JTAG_Write(10, JTAG_EXIT_SHIFT_DR, data);
//         USBDM_JTAG_Write(10, JTAG_EXIT_SHIFT_IR, data);
//         Sleep(1000);
//      } while (1);

#if 0
      // Connection test using low-level routines.
      unsigned char dummyData[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, };
      unsigned char idCodeCommand[]       = {JTAG_IDCODE_COMMAND};
      unsigned char tlmSelectCommand[]    = {JTAG_TLM_SELECT_COMMAND};
      unsigned char tlmSlaveSelectValue[] = {TLM_SLAVE_SELECT_MASK};

      do {
         unsigned char buff[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, };
         USBDM_JTAG_Reset();
         USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
         USBDM_JTAG_ReadWrite(JTAG_MASTER_COMMAND_LENGTH, JTAG_EXIT_SHIFT_DR|JTAG_WRITE_0, idCodeCommand, buff);
         USBDM_JTAG_ReadWrite(JTAG_IDCODE_LENGTH, JTAG_EXIT_IDLE|JTAG_WRITE_0, dummyData, buff);
         print("Master IDCODE = 0x%2.2X%2.2X%2.2X%2.2X\n", buff[0], buff[1], buff[2], buff[3]);

         USBDM_JTAG_Reset();
         USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
         USBDM_JTAG_ReadWrite(JTAG_MASTER_COMMAND_LENGTH, JTAG_EXIT_SHIFT_DR|JTAG_WRITE_0, idCodeCommand, buff);
         USBDM_JTAG_ReadWrite(JTAG_IDCODE_LENGTH, JTAG_EXIT_IDLE|JTAG_WRITE_0, dummyData, buff);
         print("Master IDCODE = 0x%2.2X%2.2X%2.2X%2.2X\n", buff[0], buff[1], buff[2], buff[3]);

         USBDM_JTAG_Reset();
         USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
         USBDM_JTAG_ReadWrite(JTAG_MASTER_COMMAND_LENGTH, JTAG_EXIT_SHIFT_DR|JTAG_WRITE_0, tlmSelectCommand,    buff);
         USBDM_JTAG_ReadWrite(TLM_REGISTER_LENGTH,        JTAG_EXIT_IDLE|JTAG_WRITE_0, tlmSlaveSelectValue, buff);

         USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
         USBDM_JTAG_ReadWrite(JTAG_CORE_COMMAND_LENGTH,   JTAG_EXIT_SHIFT_DR|JTAG_WRITE_0, idCodeCommand, buff);
         USBDM_JTAG_ReadWrite(JTAG_IDCODE_LENGTH,         JTAG_EXIT_IDLE|JTAG_WRITE_0, dummyData,     buff);
         print("Slave IDCODE  = 0x%2.2X%2.2X%2.2X%2.2X\n", buff[0], buff[1], buff[2], buff[3]);

         USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
         USBDM_JTAG_ReadWrite(JTAG_CORE_COMMAND_LENGTH,   JTAG_EXIT_SHIFT_DR|JTAG_WRITE_0, idCodeCommand, buff);
         USBDM_JTAG_ReadWrite(JTAG_IDCODE_LENGTH,         JTAG_EXIT_IDLE|JTAG_WRITE_0, dummyData,     buff);
         print("Slave IDCODE  = 0x%2.2X%2.2X%2.2X%2.2X\n", buff[0], buff[1], buff[2], buff[3]);

         Sleep(1000);
      } while (1);
#endif

      // =============================================
      // Connect to target ONCE
      retry = 10;
      do {
         // Reset target
         print("Resetting target\n");
         rc = USBDM_TargetReset(RESET_HARDWARE);
         if (rc != BDM_RC_OK) {
            continue;
         }
         // Check master IDCODE (with reset)
         rc = readIDCODE(&idCode, JTAG_MASTER_COMMAND_LENGTH, true);
         if (rc != BDM_RC_OK) {
            continue;
         }
         print("doJTAG() Master IDCODE = %8.8X\n", idCode);
         if (idCode != 0x01C0601D) {
            rc = BDM_RC_NO_CONNECTION;
            continue;
         }
         // Change to core TAP controller
         rc = enableCoreTAP();
         if (rc != BDM_RC_OK) {
            continue;
         }
         // Check core IDCODE
         rc = readIDCODE(&idCode, JTAG_CORE_COMMAND_LENGTH, false);
         if (rc != BDM_RC_OK) {
            continue;
         }
         print("doJTAG() Core IDCODE = %8.8X\n", idCode);
         if (idCode != 0x02211004) {
            rc = BDM_RC_NO_CONNECTION;
            continue;
         }
         // Stop target running
         print("doJTAG() Debug request\n");
         rc = targetDebugRequest();
         if (rc != BDM_RC_OK) {
            continue;
         }
         // Select ONCE in TAP chain
         print("doJTAG() Enable ONCE\n");
         rc = enableONCE(&onceStatus);
         if (rc != BDM_RC_OK) {
            continue;
         }
         // Download JTAG code to BDM
         rc = DSC_Initialise();
         if (rc != BDM_RC_OK) {
            continue;
         }
      } while ((rc != BDM_RC_OK) && (--retry>0));

      if (rc != BDM_RC_OK)
         return rc;

#ifdef LOG_JTAG
#define MEM_RANGE (2)
#else
#define MEM_RANGE (152)  // Limited by DSC buffer size!
#endif
      enableLogging(true);
//      testTargetExecutionSpeed();
//      targetMassErase();
//      testMemoryRead();
      if (testMemoryReadWrite(MS_XByte, 0x8000<<1, MEM_RANGE) != BDM_RC_OK)
         return rc;
      if (testMemoryReadWrite(MS_XWord, 0x8000,    MEM_RANGE) != BDM_RC_OK)
         return rc;
      if (testMemoryReadWrite(MS_XLong, 0x8000,    MEM_RANGE) != BDM_RC_OK)
         return rc;
      if (testMemoryReadWrite(MS_PWord, 0x8000,    MEM_RANGE) != BDM_RC_OK)
         return rc;
      enableLogging(false);

//      testAllRegisterReadWrite();
//      basicTestRegisterReadWrite();
//      rc = testRegisterReadWrite(DSC_RegR0);
      if (rc!= BDM_RC_OK)
         break;
//      testMemoryReadWrite(MS_XWord,0x8000,100);
//      testTargetExecution();



#if 0
      // Writing a 32-bit value to otx
      uint8_t testCode1[] = {
         2,
            3, 0xe4,0x10,0x56,0x78,0x12,0x34, //  move.l #0x12345678,A
            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
      };

      // Writing a 16-bit value to otx1
      // Sets otx to $AAAAAAAA first!
      uint8_t testCode2[] = {
         5,
            3, 0xe4,0x10,0xAA,0xAA,0xAA,0xAA, //  move.l #$AAAAAAAA,A
            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
            3, 0xe4,0x10,0xBB,0xBB,0xBB,0xBB, //  move.l #$BBBBBBBB,A
            2, 0x87,0x50,0x12,0x34,           //  move.w #$1234,A1
            3, 0xE7,0x7F,0xD0,0x7C,0xFF,0xFF, //  move.w A1,X:>>otx1
      };

      // 16-bit X-memory read/write access
      uint8_t testCode3[] = {
         4,//7,
            3, 0xe4,0x10,0xAA,0xAA,0xAA,0xAA, //  move.l #$AAAAAAAA,A
            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
            2, 0x87,0x56,0x12,0x34,           //  move.w #$1234,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x00, //  move.w A0,X:>>$8000
//            3, 0xE4,0x10,0xBB,0xBB,0xBB,0xBB, //  move.l #$BBBBBBBB,A
//            3, 0xE0,0x30,0xF6,0xFC,0x80,0x00, //  move.w X:>>$8000,A0
//            3, 0xE7,0x7F,0xD6,0xFC,0xFF,0xFF, //  move.w A0,X:>>otx1
      };

      // 32-bit rtx/otx read/write access
      uint8_t testCode4[] = {
         4,//5,
            3, 0xE4,0x10,0xBB,0xBB,0xBB,0xBB,  //  move.l   #$BBBBBBBB,A
            3, 0xE4,0x11,0xAA,0xAA,0xAA,0xAA,  //  move.l   #$AAAAAAAA,B
            3, 0xE3,0x7F,0xF0,0x7D,0xFF,0xFF,  //  move.l   X:>>otx,A
            3, 0xE3,0x7F,0xD1,0x7D,0xFF,0xFF,  //  move.l   B10,X:>>otx
//            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF,  //  move.l   A10,X:>>otx
      };

      uint8_t initMemory[] = {
         10,
            3, 0xe4,0x10,0xAA,0xAA,0xAA,0xAA, //  move.l #$AAAAAAAA,A
            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
            2, 0x87,0x56,0x12,0x34,           //  move.w #$1234,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x00, //  move.w A0,X:>>$8000
            2, 0x87,0x56,0x56,0x78,           //  move.w #$5678,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x01, //  move.w A0,X:>>$8001
            2, 0x87,0x56,0x9A,0xBC,           //  move.w #$9ABC,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x02, //  move.w A0,X:>>$8002
            2, 0x87,0x56,0xDE,0xF0,           //  move.w #$DEF0,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x03, //  move.w A0,X:>>$8003
      };

      uint8_t fillMemory0[] = {
         11,
            3, 0xe4,0x10,0xAA,0xAA,0xAA,0xAA, //  move.l #$AAAAAAAA,A
            3, 0xE3,0x7F,0xD0,0x7D,0xFF,0xFF, //  move.l A10,X:>>otx
            2, 0x87,0x56,0x00,0x00,           //  move.w #$1234,A0
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x00, //  move.w A0,X:>>$8000
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x01, //  move.w A0,X:>>$8001
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x02, //  move.w A0,X:>>$8002
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x03, //  move.w A0,X:>>$8003
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x04, //  move.w A0,X:>>$8004
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x05, //  move.w A0,X:>>$8005
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x06, //  move.w A0,X:>>$8006
            3, 0xE0,0x30,0xD6,0xFC,0x80,0x07, //  move.w A0,X:>>$8007
      };


//      rc = writeONCEReg(DSC_RegORX, 0, 0x12345678);
//      if (rc != BDM_RC_OK) {
//         break;
//      }
      rc = executeTargetInstruction(fillMemory0);
      if (rc != BDM_RC_OK) {
         break;
      }
//      uint32_t value;
//      rc = readONCEReg(DSC_RegOTX1, &value);
//      if (rc != BDM_RC_OK) {
//         break;
//      }
//      rc = readONCEReg(DSC_RegOTX, &value);
//      if (rc != BDM_RC_OK) {
//         break;
//      }
//      enableLogging(false);

      buffer1[0]  = 0xAA;
      buffer1[1]  = 0xBB;
      buffer1[2]  = 0xCC;
      buffer1[3]  = 0xDD;
      buffer1[4]  = 0xEE;
      buffer1[5]  = 0xFF;
      buffer1[6]  = 0x11;
      buffer1[7]  = 0x22;
      buffer1[8]  = 0x33;
      buffer1[9]  = 0x44;
      buffer1[10] = 0x44;
      buffer1[11] = 0x44;

      buffer2[0] = 0x00;
      buffer2[1] = 0x00;
      buffer2[2] = 0x00;
      buffer2[3] = 0x00;
      buffer2[4] = 0x00;
      buffer2[5] = 0x00;
      buffer2[6] = 0x00;
      buffer2[7] = 0x00;
      buffer2[8] = 0x00;
      buffer2[9] = 0x00;
      buffer2[10] = 0x44;
      buffer2[11] = 0x44;

      //
//      enableLogging(false);
//      writeMem(0, 0x8002<<1, 1, 10, buffer1);
      writeMem(0, 0x8001, 2, 8, buffer1);    // OK
//      writeMem(0, 0x8001, 4, 8, buffer1);    // OK
//      enableLogging(false);

      memset(buffer2,0xCC,sizeof(buffer2));  readMem(0, 0x8000<<1, 1, 16, buffer2);    // OK - byte swapped as expected
      memset(buffer2,0xCC,sizeof(buffer2));  readMem(0, 0x8000,    4, 16, buffer2);    // OK
      memset(buffer2,0xCC,sizeof(buffer2));  readMem(0, 0x8000,    2, 16, buffer2);    // OK

      memset(buffer2,0xCC,sizeof(buffer2));  readMem(1, 0x1000,    2, 16, buffer2);    // OK

//      enableLogging(true);
      printDump(buffer2, 16, 0x8000, WORD_ADDRESS|WORD_DISPLAY);
//      enableLogging(false);

//      readXMem(0x8000, 1, 40, buffer);
//      readXMem(0x8000, 2, 40, buffer);
//      readXMem(0x8000, 4, 40, buffer);

      uint32_t i, j;
#endif

   } while(false);
   if (rc != BDM_RC_OK)
      print("Failure: %s\n", USBDM_GetErrorString(rc));

   rc = USBDM_Close();
   if (rc != BDM_RC_OK)
      print("Failure: %s\n", USBDM_GetErrorString(rc));

   rc = USBDM_Exit();
   if (rc != BDM_RC_OK)
      print("Failure: %s\n", USBDM_GetErrorString(rc));

   return rc;
}

#if 0
//! Connects to the target core JTAG
//!
//! @param exitAction - mode to leave core JTAG chain in
//!
//! @note This will persist until the TAP is reset - USBDM_JTAG_Reset() etc.
//!
USBDM_ErrorCode targetConnect() {
unsigned int masterIR_Length;
unsigned int masterDR_Length;
unsigned int coreIR_Length;
unsigned int coreDR_Length;
uint8_t buffer[4];
uint32_t idcodeValue;
static const uint8_t JTAG_TLM_SELECT_COMMAND[] = {0x05};
static const uint8_t TLM_SLAVE_SELECT_MASK[]   = {0x02};
static const uint8_t JTAG_IDCODE_COMMAND[1]   = {0x02};
USBDM_ErrorCode rc;

   // Start from scratch
   rc = USBDM_JTAG_Reset();
   if (rc != BDM_RC_OK)
      return rc;

   // Check IR Chain length
   // Should be a single 8-bit instruction register
   rc = USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   if (rc != BDM_RC_OK)
      return rc;
   rc = findChainLength(&masterIR_Length, JTAG_EXIT_IDLE);
   if (rc != BDM_RC_OK)
      return rc;
   print("targetConnect(): Length of JTAG Master IR => %d\n", masterIR_Length);
   if (masterIR_Length != 8)
      return BDM_RC_FAIL;

   // Read IDCODE and check length
   // Should be a single 32-bit IDCODE if a single device
   rc = USBDM_JTAG_Reset(); // Automatically loads IDCODE command
   if (rc != BDM_RC_OK)
      return rc;

   rc = USBDM_JTAG_SelectShift(JTAG_SHIFT_DR);
   if (rc != BDM_RC_OK)
      return rc;
   rc = USBDM_JTAG_Read(32, JTAG_STAY_SHIFT, buffer);
   if (rc != BDM_RC_OK)
      return rc;
   idcodeValue = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
   rc = findChainLength(&masterDR_Length, JTAG_EXIT_SHIFT_IR);
   if (rc != BDM_RC_OK)
      return rc;
   print("targetConnect(): Length of JTAG Master IDCODE => %d\n", masterDR_Length);
   if (masterDR_Length != 32)
      return BDM_RC_FAIL;
   print("targetConnect(): Master IDCODE => %8.8X\n", idcodeValue);

   // Write TLM_SEL command to IR chain, switch to DR chain, write TLM select register
   rc = USBDM_JTAG_Write(8, JTAG_EXIT_SHIFT_DR, JTAG_TLM_SELECT_COMMAND);
   if (rc != BDM_RC_OK)
      return rc;
   rc = USBDM_JTAG_Write(4, JTAG_EXIT_IDLE, TLM_SLAVE_SELECT_MASK);
   if (rc != BDM_RC_OK)
      return rc;
   print("targetConnect(): Target Core JTAG enabled\n");

   //
   // Core JTAG is now active
   //

   // Check IR Chain length
   // Should be a single 4-bit instruction register
   USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   rc = findChainLength(&coreIR_Length, JTAG_STAY_SHIFT);
   print("targetConnect(): Length of JTAG Core IR => %d\n", coreIR_Length);
   if (coreIR_Length != 4)
      return BDM_RC_FAIL;

   // Write IDCODE command to IR chain, switch to DR chain,
   // get IDCODE, measure length, back to idle
   USBDM_JTAG_Write(4, JTAG_EXIT_SHIFT_DR, JTAG_IDCODE_COMMAND);
   rc = USBDM_JTAG_Read(32, JTAG_STAY_SHIFT, buffer);
   if (rc != BDM_RC_OK)
      return rc;
   idcodeValue = (buffer[0]<<24)+(buffer[1]<<16)+(buffer[2]<<8)+buffer[3];
   rc = findChainLength(&coreDR_Length, JTAG_EXIT_IDLE);
   if (rc != BDM_RC_OK)
      return rc;
   print("targetConnect(): Length of JTAG Core IDCODE => %d\n", coreDR_Length);
   if (coreDR_Length != 32)
      return BDM_RC_FAIL;
   print("targetConnect(): Core IDCODE => %8.8X\n", idcodeValue);

   //
   // The core TAP is now selected - until USBDM_JTAG_Reset();
   //
   return BDM_RC_OK;
}

//! Find length of current JTAG chain
//! Assumes <32 bits in chain
//!
//! @param chainLength - measured length of chain
//! @param exitAction - mode to leave core JTAG chain in
//!
USBDM_ErrorCode findChainLength(unsigned int *chainLength,
                                JTAG_ExitActions_t exitAction) {
static const uint8_t allOnes[]   = {0xFF,0xFF,0xFF,0xFF,0xFF};
static const uint8_t allZeroes[sizeof(allOnes)] = {0};
             uint8_t testValue[sizeof(allOnes)];
int bitFound;
unsigned int length;
USBDM_ErrorCode rc;

   // Fill chain with 0's
   rc = USBDM_JTAG_Write(8*sizeof(allOnes), JTAG_STAY_SHIFT, allZeroes);
   if (rc != BDM_RC_OK)
      return rc;
   // Flush with 1's, read out the zeroes
   rc = USBDM_JTAG_ReadWrite(8*sizeof(allZeroes), exitAction, allOnes, testValue);
   if (rc != BDM_RC_OK)
      return rc;
   // Find first 1
   length = 0;
   do {
      uint8_t testByte = testValue[sizeof(allZeroes)-(length/8)-1];
      bitFound = (testByte != 0);
      if (!bitFound) {
         length += 8;
      }
      else {
         uint8_t mask = 0x01;
         while ((testByte&mask) == 0) {
            length++;
            mask <<= 1;
         }
      }
   } while ((!bitFound) && (length<32));
   *chainLength = length;
   return BDM_RC_OK;
}

#endif

/*
 * Application instance implementation
 */
IMPLEMENT_APP_CONSOLE( TestUsbdmApp )

/*
 * TestUsbdmApp type definition
 */
IMPLEMENT_CLASS( TestUsbdmApp, wxApp )

/*
 * TestUsbdmApp event table definition
 */
BEGIN_EVENT_TABLE( TestUsbdmApp, wxApp )
END_EVENT_TABLE()

/*
 * Constructor for TestUsbdmApp
 */
TestUsbdmApp::TestUsbdmApp()
{
   fprintf(stderr, "TestUsbdmApp::TestUsbdmApp()\n");
}

/*
 * Member initialisation
 */
bool TestUsbdmApp::OnInit() {
   fprintf(stderr, "TestUsbdmApp::OnInit()\n");

   SetAppName(_("usbdm"));

   openLogFile(_("DSC_Tester.log"), _("DSC_Tester"));
   print("main():Starting\n");

//
//   USBDM_Init();
//   USBDM_FindDevices(&numDevices);
//   fprintf(stderr, "TestUsbdmApp::OnInit() - Found %d devices\n", numDevices);

   return true;
}

/*
 * main loop for TestUsbdmApp
 */
int TestUsbdmApp::OnRun() {
   USBDM_ErrorCode rc;
   int getYesNo;

   do {
      getYesNo = wxMessageBox(_("Run test?"),
                              _("USBDM Test"),
                              wxICON_INFORMATION|wxYES_NO,
                              NULL
                              );
      if (getYesNo == wxYES) {
         rc = doJTAG();
         print("doJTAG() Result = %s\n", USBDM_GetErrorString(rc));
         if (rc != BDM_RC_OK) {
            wxMessageBox(_("Test Failed"),
                         _("USBDM Test Result"),
                         wxICON_INFORMATION|wxOK,
                         NULL
                         );
         }
      }
   } while(getYesNo == wxYES);

   print("OnRun():Complete\n");

   return 0;
}

/*
 * Cleanup for TestUsbdmApp
 */
int TestUsbdmApp::OnExit() {
   USBDM_Close();

   fprintf(stderr, "TestUsbdmApp::OnExit()\n");
   closeLogFile();
   wxApp::Exit();

   return 0;
}
