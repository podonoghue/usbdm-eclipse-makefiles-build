/*
 * CreateFlashTestImage.cpp
 *
 * A program to create S1S9 image files of random data
 *
 *  Created on: 09/12/2011
 *      Author: podonoghue
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int maxSrecSize = 32; // Maximum number of bytes per data S-record
bool wordAddresses = false;
bool altName       = false;

      uint32_t  securityStartAddress = 0xFF0F;
      uint32_t  securitySize         = 0;
const uint8_t  *securityValues       = NULL;

      uint32_t  resetStartAddress = 0xFF0F;
      uint32_t  resetSize         = 0;
const uint8_t  *resetValues       = NULL;

// From http://www.amelek.gda.pl/avr/uisp/srecord.htm
//  S0 Record.
//  The type of record is 'S0' (0x5330).
//  The address field is unused and will be filled with zeros (0x0000).
//  The header information within the data field is divided into the following subfields.
//        mname is char[20] and is the module name.
//        ver is char[2] and is the version number.
//        rev is char[2] and is the revision number.
//        description is char[0-36] and is a text comment.
//
//    Each of the subfields is composed of ASCII bytes whose associated characters, when paired, represent
//    one byte hexadecimal values in the case of the version and revision numbers, or represent the hexadecimal
//    values of the ASCII characters comprising the module name and description.


void dumpS0Rec(FILE *fp, char description[36]) {
   uint8_t checkSum;
   char mname[20] = "DummySREC";
   char ver = 1;
   char rev = 1;
   int descriptionLength = strlen(description);
   if (descriptionLength>36) {
      descriptionLength = 36;
   }
   int size = sizeof(mname)+1+1+descriptionLength;
   int address = 0;
   fprintf(fp, "S0%02X%04X", size+3, address);
   checkSum = size+3;
   checkSum += (address>>8)&0xFF;
   checkSum += (address)&0xFF;
   int sub;
   for(sub=0;sub<20;sub++) {
      uint8_t data = mname[sub];
      checkSum += data;
      fprintf(fp, "%02X", data);
   }
   uint8_t data = ver;
   checkSum += data;
   fprintf(fp, "%02X", data);
   data = rev;
   checkSum += data;
   fprintf(fp, "%02X", data);
   for(sub=0;sub<descriptionLength;sub++) {
      uint8_t data = description[sub];
      checkSum += data;
      fprintf(fp, "%02X", data);
   }
   checkSum = checkSum^0xFF;
   fprintf(fp, "%02X\n", checkSum);
}

void dumpS9Rec(FILE *fp, uint16_t address) {
   uint8_t checkSum;
   int size = 0;

   fprintf(fp, "S9%02X%04X", size+3, address);
   checkSum = size+3;
   checkSum += (address>>8)&0xFF;
   checkSum += (address)&0xFF;
   checkSum = checkSum^0xFF;
   fprintf(fp, "%02X\n", checkSum);
}

// Dump a single S-record (S1,S2,S3) to fp
//
// @param address  base address of data
// @param size     number of bytes to dumpBytes
//
// @note size must be less than or equal to \ref maxSrecSize
//
void dumpSrec(FILE *fp, uint32_t address, uint8_t size) {

   if (size == 0)
      return;

   uint8_t checkSum;
   if ((address) < 0x10000U) {
      fprintf(fp, "S1%02X%04X", size+3, address);
      checkSum = size+3;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else if (address < 0x1000000U) {
      fprintf(fp, "S2%02X%06X", size+4, address);
      checkSum = size+4;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else {
      fprintf(fp, "S3%02X%08X", size+5, address);
      checkSum = size+5;
      checkSum += (address>>24)&0xFF;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   while (size-->0) {
      uint8_t data = (uint8_t)((255.0 * rand())/(RAND_MAX+1.0));
      if ((securityStartAddress <= address) && (address < (securityStartAddress+securitySize))) {
         data = securityValues[address-securityStartAddress];
      }
      if ((resetStartAddress <= address) && (address < (resetStartAddress+resetSize))) {
         data = resetValues[address-resetStartAddress];
      }
      checkSum += data;
      address++;
      fprintf(fp, "%02X", data);
   }
   checkSum = checkSum^0xFF;
   fprintf(fp, "%02X\n", checkSum);
}

// Dump dummy data as S-records to fp
//
// @param startAddress  start address of data (inclusive)
// @param endAddress    end address of data (inclusive)
//
void dumpBytes(FILE *fp, uint32_t startAddress, uint32_t endAddress) {
   uint32_t address = startAddress;

   while (address<=endAddress) {
      uint32_t size     = endAddress-address+1;
      uint8_t  oddBytes = address & (maxSrecSize-1);
      uint8_t  srecSize = maxSrecSize - oddBytes;
      if (srecSize > size)
         srecSize = (uint8_t) size;
      dumpSrec(fp, address, srecSize);
      address += srecSize;
      size    -= srecSize;
   }
}

// Dump dummy data as S-records to fp
//
// @param startAddress  start address of data (inclusive)
// @param endAddress    end address of data (inclusive)
//
void dumpWords(FILE *fp, uint32_t startAddress, uint32_t endAddress) {
   uint32_t address = startAddress;

   while (address<=endAddress) {
      uint32_t size     = 2*(endAddress-address+1);
      uint8_t  oddBytes = (2*address) & (maxSrecSize-1);
      uint8_t  srecSize = maxSrecSize - oddBytes;
      if (srecSize > size)
         srecSize = (uint8_t) size;
      dumpSrec(fp, address, srecSize);
      address += srecSize/2;
      size    -= srecSize/2;
   }
}

void usage(void) {
   fprintf(stderr, "\n\nUsage:\n"
                   "CreateDummyImage [-alt] [-word] [-hcs08|-hcs12|-kin|-cfv1] imageFile.s19 [startAddress endAddress]*\n\n"
                   "-alt   - Create file with alternative name\n" 
                   "-word  - create image with word addresses (DSC)\n"
                   "-hcs08 - set image as unsecured for hcs08 devices\n"
                   "-s12z  - set image as unsecured for s12z devices\n"
                   "-hcs12 - set image as unsecured for hcs12 devices\n"
                   "-kin   - set image as unsecured for kinetis devices\n"
                   "-cfv1  - set image as unsecured for coldfire V1 devices\n\n"
           );
   exit(1);
}
int main(int argc, char *argv[]) {
   int argNum;

   srand ((unsigned int)time(NULL));

   for(argNum=1;argNum<argc;) {
      if (strcasecmp(argv[argNum], "-word") == 0) {
         wordAddresses = true;
         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-alt") == 0) {
         altName = true;
         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-hcs08") == 0) {
         static const uint8_t  newSecurityValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE };
         securityStartAddress = 0xFFB0;
         securitySize         = sizeof(newSecurityValues);
         securityValues       = newSecurityValues;

         static const uint8_t  newResetValues[]   = {
               0xFF, 0xFF,};
         resetStartAddress = 0xFFFE;
         resetSize         = sizeof(newResetValues);
         resetValues       = newResetValues;

         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-hcs12") == 0) {
         static const uint8_t  newSecurityValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE };
         securityStartAddress = 0xFF00;
         securitySize         = sizeof(newSecurityValues);
         securityValues       = newSecurityValues;

         static const uint8_t  newResetValues[]   = {
               0xFF, 0xFF,};
         resetStartAddress = 0xFFFE;
         resetSize         = sizeof(newResetValues);
         resetValues       = newResetValues;

         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-s12z") == 0) {
         static const uint8_t  newSecurityValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE };
         securityStartAddress = 0xFFFE00;
         securitySize         = sizeof(newSecurityValues);
         securityValues       = newSecurityValues;

         static const uint8_t  newResetValues[]   = {
               0xFF, 0xFF,};
         resetStartAddress = 0xFFFFFE;
         resetSize         = sizeof(newResetValues);
         resetValues       = newResetValues;

         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-kin") == 0) {
         static const uint8_t  newSecurityValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
               0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF };
         securityStartAddress = 0x0400;
         securitySize         = sizeof(newSecurityValues);
         securityValues       = newSecurityValues;

         static const uint8_t  newResetValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
         resetStartAddress = 0x00000000;
         resetSize         = sizeof(newResetValues);
         resetValues       = newResetValues;

         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-cfv1") == 0) {
         static const uint8_t  newSecurityValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
               0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF };
         securityStartAddress = 0x0400;
         securitySize         = sizeof(newSecurityValues);
         securityValues       = newSecurityValues;

         static const uint8_t  newResetValues[]   = {
               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,};
         resetStartAddress = 0x00000000;
         resetSize         = sizeof(newResetValues);
         resetValues       = newResetValues;

         argNum++;
      }
      else if (strcasecmp(argv[argNum], "-cfvx") == 0) {
         // ToDo: Not done yet
         argNum++;
      }
      else {
         break;
      }
   }
   // Must have at least a filename remaining
   if (argNum >= argc) {
      fprintf(stderr, "\nInsufficient arguments (found = %d, argc = %d)\n", argNum, argc);
      usage();
   }
   char fileName[2000];
   strncpy(fileName, argv[argNum++], sizeof(fileName)-10);
   if (altName) {
      strcat(fileName, "_Alt");
   }
   strcat(fileName, ".sx");
   FILE *fp = fopen(fileName, "wt");
   if (fp == NULL){
      fprintf(stderr, "\nFaild to open \"%s\"\n", fileName);
      usage();
   }
   printf("Producing image file: %s\n", fileName);
   dumpS0Rec(fp, fileName);

   // Remaining parameters must be in pairs
   if (((argc-argNum)%2) != 0) {
      fprintf(stderr, "\nodd number of memory range arguments\n");
      usage();
      fclose(fp);
   }
   char *cp;
   for(;argNum<argc-1; argNum+=2) {
      uint32_t startAddress = strtol(argv[argNum  ], &cp, 0);
      uint32_t endAddress   = strtol(argv[argNum+1], &cp, 0);
      if (wordAddresses) {
         dumpWords(fp, startAddress, endAddress);
      }
      else {
         dumpBytes(fp, startAddress, endAddress);
      }
   }
   dumpS9Rec(fp, 0x0000);
   fclose(fp);
   return 0;
}


