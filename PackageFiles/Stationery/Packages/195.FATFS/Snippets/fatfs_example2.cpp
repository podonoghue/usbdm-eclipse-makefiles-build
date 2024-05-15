/**
 * FATFS Example
 * Uses FATFS_NS::Directory, FATFS_NS::Volume, FATFS_NS::File C++ wrapper classes
 */
#include <time.h>
#include "hardware.h"
#include "fatfs.h"

using namespace USBDM;

FRESULT createFile(const char *filename) {

   FRESULT rc;

   console.writeln("Creating file \"", filename, "\"");

   // Create FatFS file
   FATFS_NS::File<512> file;

   // Open file on default volume
   rc = file.open(filename, FA_WRITE | FA_CREATE_ALWAYS);
   if (rc != FR_OK) {
      console.writeln("Failed file.open(\"", filename, "\", FA_WRITE | FA_CREATE_ALWAYS)");
      return rc;
   }
   // Write some data
   for (int count=0; count<100; count++) {
//      console.writeln("Count = ", count);
      file.writeln("Count = ", count);
   }
   // Close file
//   rc = file.close();
//   if (rc != FR_OK) {
//      console.writeln("Failed file.close()");
//      return rc;
//   }
   return rc;
}

FRESULT readFile(const char *filename) {

   FRESULT rc;

   console.writeln("Reading file \"", filename, "\"");

   // Create FatFS file
   FATFS_NS::File<512> file;

   // Open file
   rc = file.open(filename, FA_READ);
   if (rc != FR_OK) {
      console.writeln("Failed file.open(\"", filename, "\", FA_READ)");
      return rc;
   }
   // Read line-by-line and echo to console
   char buffer[100];
   for (int count=0; count<100; count++) {
      int num = file.gets(buffer);
      if (num == 0) {
         break;
      }
      console.writeln(buffer);
   }
//   rc = file.close();
//   if (rc != FR_OK) {
//      console.writeln("Failed file.close()");
//      return rc;
//   }
   return rc;
}

FRESULT copyFile(const char *oldFilename, const char *newFilename) {

   FRESULT rc;

   console.writeln("copying file \"", oldFilename, "\" to \"", newFilename, "\"");

   // Create FatFS file
   FATFS_NS::File<512> oldFile;
   FATFS_NS::File<512> newFile;

   // Open source file
   rc = oldFile.open(oldFilename, FA_READ);
   if (rc != FR_OK) {
      console.writeln("Failed file.open(\"", oldFilename, "\", FA_READ)");
      return rc;
   }
   // Open destination file
   rc = newFile.open(newFilename, FA_WRITE|FA_CREATE_ALWAYS);
   if (rc != FR_OK) {
      console.writeln("Failed file.open(\"", newFilename, "\", FA_WRITE|FA_CREATE_ALWAYS)");
      return rc;
   }

   for(;;) {
      uint8_t buffer[1000];
      unsigned byteCount;
      rc = oldFile.read(buffer, byteCount);
      if (rc != FR_OK) {
         break;
      }
      rc = newFile.write(buffer, byteCount, byteCount);
      if (rc != FR_OK) {
         break;
      }
   }
   return (rc==FR_NOT_READY)?FR_OK:rc;
}

// Create FatFS volume to use (default)
static FATFS_NS::Volume *volume;

// Choose SD card interface
#define DRIVE "sd1:"

int main (void) {

   volume =  new FATFS_NS::Volume(DRIVE);

   FRESULT rc;

   console.writeln("\nStarting");

   static const char *filenames[] = {
         DRIVE "testLoop1.txt",
         DRIVE "testLoop2.txt",
         DRIVE "testLoop3.txt",
         DRIVE "testXxxx3.txt",
   };

   for (unsigned index=0; index<sizeofArray(filenames); index++) {
      rc = createFile(filenames[index]);
      if (rc != FR_OK) {
         __BKPT();
      }
      rc = readFile(filenames[index]);
      if (rc != FR_OK) {
         __BKPT();
      }
   }

   rc = copyFile(filenames[0], DRIVE "fileCopy.txt");
   if (rc != FR_OK) {
      __BKPT();
   }

   static const char *dirname = DRIVE "/";

   FATFS_NS::Directory directory;

   rc = directory.open(dirname);
   if (rc != FR_OK) {
      console.writeln("Failed directory.open(\"", dirname, "\")");
      __BKPT();
   }

   static constexpr IntegerFormat sizeFormat {
      Width_10,
      Padding_LeadingSpaces,
   };
   console.writeln(
         "\nDirectory contents\n"
         " File size : Name");
   do {
      rc = directory.readdir();
      if (rc == FR_DONE) {
         // No more items
         break;
      }
      if (rc != FR_OK) {
         console.writeln("Failed directory.readdir()");
         __BKPT();
      }
      console.writeln(directory.fno.fsize, sizeFormat, " : ", directory.fno.fname);
   } while(true);

   static const char *pattern = "testLoop?.txt";
   console.writeln("\nDirectory contents matching \"", pattern, "\"\n"
         " File size : Name");

   rc = directory.findfirst(dirname, pattern);
   if (rc != FR_OK) {
      console.writeln("Failed directory.findfirst(\"", dirname, "\")");
      __BKPT();
   }
   while (rc != FR_DONE) {
      if (rc != FR_OK) {
         console.writeln("Failed directory.findnext()");
         __BKPT();
      }
      console.writeln(directory.fno.fsize, sizeFormat, " : ", directory.fno.fname);
      rc = directory.findnext();
   }

   for (;;) {
      __WFI();
   }
}
