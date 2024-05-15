/**
 * FATFS Example
 * Basic example using FATFS routines directly
 */
#include <string.h>
#include <time.h>
#include "ff.h"      /* Declarations of Fat_fs API */

#include "hardware.h"
using namespace USBDM;

FATFS FatFs;      /* FatFs work area needed for each volume */
FIL   Fil;        /* File object needed for each open file */

// Change as needed
using Led = RGB_Blue;

/**
 * Create a file with given contents
 *
 * @param filename   Name of file
 * @param text       Contents
 * @param size       Size of text in bytes
 *
 * @return Status
 */
FRESULT writeFile(const char *filename, const char *text, unsigned size) {

   UINT    byteCount;
   FRESULT rc;

   // Create a file
   rc = f_open(&Fil, filename, FA_WRITE | FA_CREATE_ALWAYS);
   if (rc != FR_OK) {
      console.writeln("Failed open");
      return rc;
   }

   // Write data to the file (truncate null char at end)
   rc = f_write(&Fil, text, size, &byteCount);
   if (rc != FR_OK) {
      console.writeln("Failed write");
      return rc;
   }

   // Close the file
   rc = f_close(&Fil);
   if (rc != FR_OK) {
      console.writeln("Failed close");
      return rc;
   }

   if ((rc == FR_OK) && (byteCount == size)) {
      // Light LED if data written OK
      Led::on();
      console.writeln("Write of '", filename, "' completed successfully");
   }
   else {
      console.writeln("Write of '", filename, "' failed");
      return FR_DISK_ERR;
   }

   return FR_OK;
}

/**
 * Read a file and verify contents
 *
 * @param filename   Name of file
 * @param text       Contents to check against
 * @param size       Size of text in bytes
 *
 * @return Status
 */
FRESULT readFile(const char *filename, const char *text, unsigned size) {

   UINT    byteCount;
   FRESULT rc;

   // Create a file
   rc = f_open(&Fil, filename, FA_OPEN_EXISTING|FA_READ);
   if (rc != FR_OK) {
      console.writeln("Failed open");
      return rc;
   }

   // Write data to the file (truncate null char at end)
   char buffer[100] = {0};
   rc = f_read(&Fil, buffer, size, &byteCount);
   if (rc != FR_OK) {
      console.writeln("Failed read");
      return rc;
   }

   // Close the file
   rc = f_close(&Fil);
   if (rc != FR_OK) {
      console.writeln("Failed close");
      return rc;
   }

   if ((byteCount == size) && (strcmp(buffer,text) == 0)) {
      // Light LED if data written OK
      Led::on();
      console.writeln("Verify of '", filename, "' completed successfully");
   }
   else {
      console.writeln("Verify of '", filename, "' failed");
      return FR_DISK_ERR;
   }
   return FR_OK;
}


int main (void) {

   console.writeln("\nStarting");

   Led::setOutput();

   // Give a work area to the default drive
   FRESULT rc = f_mount(&FatFs, "", 0);
   if (rc != FR_OK) {
      console.writeln("Failed mount");
      __BKPT();
   }

   static const char *filename1 = "cow_one.txt";
   static const char *filename2 = "cow_two.txt";

   const char message1[] = "How now brown cow!\r\n";
   const char message2[] = "Oh no, another cow!\r\n";

   rc = writeFile(filename1, message1, sizeof(message1)-1);
   if (rc != FR_OK) {
      __BKPT();
   }
   console.writeln("Waiting a few seconds for time-stamp to change...");
   waitMS(4000);
   rc = writeFile(filename2, message2, sizeof(message2)-1);
   if (rc != FR_OK) {
      __BKPT();
   }
   rc = readFile(filename1, message1, sizeof(message1)-1);
   if (rc != FR_OK) {
      __BKPT();
   }
   rc = readFile(filename2, message2, sizeof(message2)-1);
   if (rc != FR_OK) {
      __BKPT();
   }

   for (;;) {
      __BKPT();
   }
}

