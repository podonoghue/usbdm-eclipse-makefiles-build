/*
 * JTAGUtilities.cpp
 *
 *  Created on: 29/03/2011
 *      Author: podonoghue
 */
#include <list>
#include "Common.h"

#include "USBDM_API.h"
#include "UsbdmSystem.h"

#define MAX_JTAG_IR_CHAIN_LENGTH (200)
#define MAX_JTAG_CHAIN_LENGTH (200)

//! Run identify command on JTAG device
USBDM_ErrorCode jtagIdentifyCommand(unsigned &numDevice, std::list<uint32_t> &deviceList) {
   LOGGING_Q;
   uint8_t  temp;
   const uint8_t  BYPASSCommand[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
   const uint8_t  Zeroes[]        = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
   const uint8_t  allOnes[] = {0xFFU};
   uint8_t    irReg[MAX_JTAG_IR_CHAIN_LENGTH];
   int device;
   int deviceCount;
   int irLength;
   int sub;

   // Find number of JTAG devices
   //===========================================================================
   // Force all devices to bypass mode (Command is all '1's)
   // This assumes the instruction chain length is limited to < 3x80 bits
   USBDM_JTAG_Reset();
   USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_EXIT_IDLE|JTAG_WRITE_1, BYPASSCommand);

   // Fill bypass register chain with 0 - stay in SHIFT-DR
   // This assumes the data chain length (in bypass) is limited to < 2x80 bits (<160 devices!)
   USBDM_JTAG_SelectShift(JTAG_SHIFT_DR);
   USBDM_JTAG_Write(8*sizeof(Zeroes), JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);
   USBDM_JTAG_Write(8*sizeof(Zeroes), JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);

   // Write a single one into bypass chain
   USBDM_JTAG_Write(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, allOnes); // Write a single one into chain

   // Keep reading single bits until we find the '1'
   deviceCount = 0;
   do {
      USBDM_JTAG_Read(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp); // Read a single bit
      deviceCount++;
   } while ((temp == 0) && (deviceCount <= MAX_JTAG_CHAIN_LENGTH));

   if (deviceCount > MAX_JTAG_CHAIN_LENGTH) {
      log.print("Too many devices found - JTAG chain is probably open\n");
      return BDM_JTAG_TOO_MANY_DEVICES;
   }
   log.print("Number of devices => %d\n", deviceCount);
   numDevice = deviceCount;

   // Find total length JTAG IRs
   //===========================================================================
   //
   // Fill IR chain with 1's - stay in SHIFT-IR
   // This assumes the instruction chain length is limited to < 3x80 bits
   USBDM_JTAG_Reset();
   USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);
   USBDM_JTAG_Write(8*sizeof(BYPASSCommand), JTAG_STAY_SHIFT|JTAG_WRITE_1, BYPASSCommand);

   // Write a single 0 into bypass chain
   USBDM_JTAG_Write(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, Zeroes);

   // Keep reading single bits until we find the '1'
   irLength = 0;
   do {
      temp = 0xAA;
      USBDM_JTAG_Read(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp); // Read a single bit
      irLength++;
   } while ((temp == 1) && (irLength <= MAX_JTAG_IR_CHAIN_LENGTH));

   log.print("initialiseJTAGChain(): Total length of JTAG IRs => %d bits\n", irLength);

   // Read the JTAG IRs
   //===========================================================================
   //
   USBDM_JTAG_Reset();
   USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   USBDM_JTAG_Read(irLength, JTAG_STAY_SHIFT|JTAG_WRITE_1, irReg);

   log.print("initialiseJTAGChain(): JTAG IR chain => \'");
   for (sub=0; sub < (irLength+7)/8; sub++) {
      int bitNum, bitsThisByte;
      if (sub == 0)
         bitsThisByte = (irLength-1)%8+1;
      else
         bitsThisByte = 8;
      //fprintf(stderr, "bitsThisByte=%d, ", bitsThisByte);
      for (bitNum=bitsThisByte-1; bitNum >= 0; bitNum--)
         log.print("%d", ((irReg[sub])&(1<<bitNum))?1:0);
      log.print(" ");
   }
   log.print("\'\n");

   // Get the IDCODE for each device
   // The number of devices should agree with the above!
   USBDM_JTAG_Reset();   // Loads IDCODE/BYPASS command into IR
   USBDM_JTAG_SelectShift(JTAG_SHIFT_DR);  // Shifting IDCODE register
   for (device = 0; device < deviceCount; device++) {
      USBDM_JTAG_Read(1, JTAG_STAY_SHIFT|JTAG_WRITE_1, &temp);       // Read a single bit
      //log.print("Temp = %x\n",temp);
      if (temp == 0) {// In BYPASS - No IDCODE
         log.print("Device #%2d: JTAG IDCODE instruction not supported\n", device+1);
      }
      else {
         uint8_t inBuffer[10];
         uint32_t temp;
         USBDM_JTAG_Read(31, JTAG_STAY_SHIFT|JTAG_WRITE_1, inBuffer); // Read rest of IDCODE
         //log.print("Buff = %lX\n",inBuffer);
         temp = (inBuffer[0]<<24)+(inBuffer[1]<<16)+(inBuffer[2]<<8)+inBuffer[3];
         temp = (temp<<1) | 0x1;
         log.print("Device #%2d: JTAG IDCODE = %8.8X\n", device+1, temp);
         deviceList.insert(deviceList.end(),temp);
      }
   }
   USBDM_JTAG_Read(1, JTAG_EXIT_IDLE|JTAG_WRITE_1, &temp);  // Return JTAG to idle state
   return BDM_RC_OK;
}
