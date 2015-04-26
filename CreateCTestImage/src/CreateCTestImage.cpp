/*
 * CreateCTestImage.cpp
 *
 * A simple program to create C include file containing arrays of random dat of various sizes.
 *
 *  Created on: 09/12/2011
 *      Author: podonoghue
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Dump dummy data as S-records to fp
//
// @param size size of array to produce
//
void dumpBytes(FILE *fp, const char *arrayName, uint32_t size) {
   unsigned count;
   fprintf(stderr, "file size = %d\n", size);

   fprintf(fp, "static const unsigned char %s[] = {\n", arrayName);
   for(count=0; count<size; count++) {
      uint8_t data = (uint8_t)((255.0 * rand())/(RAND_MAX+1.0));
      fprintf(fp, "0x%2.2X, ", data);
      if ((count % 20) == 19) {
         fprintf(fp, "\n");
      }
   }
   fprintf(fp, "};\n\n");
}

void usage(void) {
   fprintf(stderr, "\n\nUsage:\n"
                   "CreateFlashTestImage\n\n");
   exit(1);
}

struct arrayEntry {
   const char *name;
   const unsigned size;
};

const unsigned int K = (1<<10);

arrayEntry arrays[] = {
      {"1K",     1*K},
      {"2K",     2*K},
      {"4K",     4*K},
      {"8K",     8*K},
      {"16K",   16*K},
      {"32K",   32*K},
      {"64K",   64*K},
      {"128K", 128*K},
      {"256K", 256*K},
};

int main(int argc, char *argv[]) {
   srand ((unsigned int)time(NULL));

   // Must have at least a filename and size remaining
   if (argc > 1) {
      usage();
   }
   for (unsigned index=0; index<(sizeof(arrays)/sizeof(arrays[0])); index++) {
      char fileName[100];
      strcpy(fileName, arrays[index].name);
      strcat(fileName, ".h");
      FILE *fp = fopen(fileName, "wt");
      if (fp == NULL){
         fprintf(stderr, "Failed to open \'%s\'\n", fileName);
         usage();
      }
      printf("Producing image file: %s\n", fileName);
      char arrayName[100];
      strcpy(arrayName, "data_");
      strcat(arrayName, arrays[index].name);
      dumpBytes(fp, arrayName, arrays[index].size);
      fclose(fp);
   }
   return 0;
}


