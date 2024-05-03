/*
 * FatFs.h
 *
 *  C++ Wrapper for FATFS
 */

#ifndef STARTUP_CODE_FATFS_H_
#define STARTUP_CODE_FATFS_H_

#include "formatted_io.h"
#include "ff.h"      /* Declarations of Fat_fs API */

namespace USBDM {

namespace FATFS_NS {
class Volume {

   FATFS Fat_fs;        // Fat_fs work area needed for each volume
   const TCHAR* path;   // Path of volume

public:

   /**
    * Create (Mount) a Logical Drive
    *
    * @param path Logical drive number to be mounted/unmounted e.g. "3:".
    *             May be "" for default drive.
    *             This must be a statically allocated string as it is 'kept' for later use
    */
   Volume(const TCHAR* path) : path(path) {

      // Delayed mount - always succeeds
      f_mount(&Fat_fs, path, 0);
   }

   ~Volume() {
      f_unmount(path);
   }

};

/**
 * Create File object
 *
 * @tparam size Size of internal buffer (multiple of 512 bytes)
 */
template<unsigned size>
class File : public FormattedIO {

   static_assert((size%512)==0, "size must be a multiple of 512");

   FIL       fp;                    // FatFS File object structure
   uint8_t   buffer[size];          // I/O Buffer
   uint8_t  *bPtr     = nullptr;    // Buffer pointer
   BYTE     &mode     = fp.flag;    // Access mode
   unsigned  dataSize = 0;          // Amount of valid data in buffer in read mode

   /**
    * Check input buffer state and fills as necessary
    *
    * @return true  => data available
    * @return false => no data available
    */
   bool checkAndFillBuffer() {
      if constexpr (size > 0) {
         if ((bPtr != nullptr) && (unsigned(bPtr-buffer)<dataSize)) {
            return true;
         }
         // No data currently available - try reading more
         f_read(&fp, &buffer, size, &dataSize);
         if (dataSize == 0) {
            // EOF or error
            bPtr = nullptr;
            return false;
         }
         else {
            // Data read
            bPtr = buffer;
            return true;
         }
      }
      return false;
   }

   /**
    * Check if character is available
    *
    * @return true  Character available i.e. _readChar() will not block
    * @return false No character available
    */
   virtual bool _isCharAvailable() override {
      if ((mode&FA_READ)==0) {
         // Not opened in read mode
         return -1;
      }
      if constexpr (size>0) {
         return checkAndFillBuffer();
      }
      else {
         return !f_eof(&fp);
      }
   }

   /**
    * Receives a character (non-blocking)
    *
    * @return Character received or -1 on EOF
    */
   virtual int _readChar() override {
      if ((mode&FA_READ)==0) {
         // Not opened in read mode
         return -1;
      }
      if constexpr (size == 0) {
         UINT bw;
         char ch;
         f_read(&fp, &ch, 1, &bw);
         if (bw != 1) {
            return -1;
         }
         return ch;
      }
      else {
         if ((bPtr == nullptr) || (unsigned(bPtr-buffer)>=dataSize)) {
            // No data available
            f_read(&fp, &buffer, size, &dataSize);
            if (dataSize == 0) {
               // EOF or error
               bPtr = nullptr;
               return -1;
            }
            else {
               // Valid data read
               bPtr = buffer;
            }
         }
         return *bPtr++;
      }
   }

   /**
    * Writes a character (blocking)
    *
    * @param[in]  ch - character to send
    */
   virtual void _writeChar(char ch) override {
      if ((mode&FA_WRITE)==0) {
         // Not opened in write mode
         return;
      }
      if constexpr (size == 0) {
         UINT bw;
         f_write(&fp, &ch, 1, &bw);
      }
      else {
         if ((bPtr == nullptr) || (bPtr>=(buffer+size))) {
            // Flush buffer
            sync();
         }
         *bPtr++ = ch;
      }
   }

public:

   File() {
      // No echo or blocking
      flags = 0;
   }

   ~File() {
      // Flush and close
      close();
   }

   /**
    * Open a file
    *
    * @param path [IN] File name
    * @param mode [IN] Mode flags
    *
    * @return Error code
    *
    * Mode flags:
    * FA_READ           Specifies read access to the file. Data can be read from the file.
    * FA_WRITE          Specifies write access to the file. Data can be written to the file.
    * FA_OPEN_EXISTING  Opens a file. The function fails if the file is not existing. (Default)
    * FA_CREATE_NEW     Creates a new file. The function fails with FR_EXIST if the file is existing.
    * FA_CREATE_ALWAYS  Creates a new file. If the file is existing, it will be truncated and overwritten.
    * FA_OPEN_ALWAYS    Opens the file if it is existing. If not, a new file will be created.
    * FA_OPEN_APPEND    Same as FA_OPEN_ALWAYS except the read/write pointer is set end of the file.
    */
   FRESULT open(const TCHAR* path,  BYTE mode) {
      FRESULT rc = f_open(&fp, path, mode);
      dataSize = 0;
      if (rc == FR_OK) {
         bPtr = buffer;
      }
      else {
         bPtr = nullptr;
      }
      return rc;
   }

   /**
    * Close associated file
    *
    * @return Error code
    */
   FRESULT close() {
      flushOutput();
      bPtr = nullptr;
      return f_close(&fp);
   }


   /**
    * Flushes the cached information of a file opened for write
    *
    * @return Error code
    */
   FRESULT sync () {
      if ((mode&FA_WRITE)==0) {
         // Not opened in write mode
         return FR_OK;
      }
      if constexpr (size != 0) {
         UINT bw;
         if (bPtr != nullptr) {
            // Flush data in buffer
            f_write(&fp, buffer, bPtr-buffer, &bw);
            bPtr = buffer;
         }
      }
      return f_sync(&fp);
   }

   /**
    * Check if at end of file
    *
    * @return true if at EOF
    */
   bool eof () {
      return bool(f_eof(&fp));
   }

   /**
    * Moves the file read/write pointer. \n
    * It can also be used to expand the file size (cluster pre-allocation).
    *
    * @param offset  Byte offset from top of the file to set read/write pointer.
    *
    * @return Error code
    */
   FRESULT seek(FSIZE_t offset) {
      sync();
      bPtr = nullptr;
      return f_lseek(&fp, offset);
   }

   /**
    * Moves the file read/write pointer to the start of the file.
    *
    * @return Error code
    */
   FRESULT rewind() {
      return seek(0);
   }

   /**
    *  Gets size of open file.
    *
    * @return Size of file
    */
   FSIZE_t getSize() {

      return fp.obj.objsize;
   }

   /**
    *  Gets the current read/write pointer of a file.
    *
    * @return Current read/write pointer
    */
   FSIZE_t getReadWritePosition() {

      return fp.fptr;
   }

   /**
    *  Checks for an error on a file.
    *
    * @return Status
    */
   FRESULT getError() {

      return fp.err;
   }

   /**
    * Truncate the file size to the current file read/write pointer.
    *
    * @return Error code
    */
   FRESULT truncate() {
      sync();
      bPtr = nullptr;
      return f_truncate(&fp);
   }

   /**
    * Allocate a contiguous block to the file
    *
    * @param fileSize  File size to expanded to
    * @param flags     Allocation mode - Prepare to allocate (0) or Allocate now (1).
    *
    * @return Error code
    */
   FRESULT expand(FSIZE_t fileSize, uint8_t flags) {
      sync();
      bPtr = nullptr;
      return f_expand(&fp, fileSize, flags);
   }

   virtual USBDM::FormattedIO& flushOutput() override {
      sync();
      return *this;
   }

   /**
    * Read block of data
    *
    * @param buffer     Buffer for data read
    * @param buffSize   Number of bytes to read
    * @param bytesRead  Actual bytes written
    *
    * @return FR_DONE Indicates no further items available.
    * @return Error code
    */
   FRESULT read(uint8_t *buffer, size_t buffSize, size_t &bytesRead) {
      FRESULT rc = f_read(&fp, buffer, buffSize, &bytesRead);
      return rc;
   }

   /**
    * Read block of data
    *
    * @tparam buffSize  Number of bytes to read (inferred)
    *
    * @param buffer     Buffer for data read
    * @param bytesRead  Actual bytes written
    *
    * @return FR_DONE Indicates no further data available.
    * @return Error code
    */
   template<unsigned buffSize>
   FRESULT read(uint8_t (&buffer)[buffSize], unsigned &bytesRead ) {
      FRESULT rc = read(buffer, buffSize, bytesRead);
      if (rc != FR_OK) {
         return rc;
      }
      return (bytesRead>0)?FR_OK:FR_NOT_READY;
   }

   /**
    * Write block of data
    *
    * @param buffer        Data to write
    * @param buffSize      Number of bytes to write
    * @param bytesWritten  Number of bytes actually written
    * @return
    */
   FRESULT write(uint8_t *buffer, size_t buffSize, size_t &bytesWritten) {
      sync();
      FRESULT rc = f_write(&fp, buffer, buffSize, &bytesWritten);
      return rc;
   }

   /**
    * Write block of data
    *
    * @param buffer        Data to write
    * @param buffSize      Number of bytes to write
    * @param bytesWritten  Number of bytes actually written
    * @return
    */
   template<size_t buffSize>
   FRESULT write(uint8_t (&buffer)[buffSize], size_t &bytesWritten) {
      return write(buffer, buffSize, bytesWritten);
   }

};

class Directory {

   // Directory object
   DIR     dir;

public:

   // File information structure
   FILINFO fno;

   Directory() {
   }

   ~Directory() {
      close();
   }

   /**
    * Open directory
    *
    * @param path [IN] Directory name
    *
    * @return Error code
    */
   FRESULT open(const TCHAR* path) {
      return f_opendir(&dir, path);
   }

   /**
    * Close directory
    *
    * @return Error code
    */
   FRESULT close() {
      return f_closedir(&dir);
   }

   /**
    * Read an item from the directory and advance to next item.
    * The item is available as fno field.
    *
    * @return FR_DONE Indicates no further items available.
    * @return Error code
    */
   FRESULT readdir() {

      FRESULT rc = f_readdir(&dir, &fno);
      if (rc != FR_OK) {
         return rc;
      }
      return (fno.fname[0] != '\0')?FR_OK:FR_DONE;
   }

   /**
    * Reset directory item read index
    *
    * @return Error code
    */
   FRESULT rewinddir() {

      return f_readdir(&dir, nullptr);
   }

   /**
    * Search directory for an item.
    * The item is available as fno field.
    *
    * @param path    Pointer to the directory name to be opened
    * @param pattern Pointer to the matching pattern string
    *
    * @return FR_DONE Indicates no item found.
    * @return Error code
    */
   FRESULT findfirst(const TCHAR* path, const TCHAR* pattern) {

      FRESULT rc = f_findfirst(&dir, &fno, path, pattern);
      if (rc != FR_OK) {
         return rc;
      }
      return (fno.fname[0] != '\0')?FR_OK:FR_DONE;
   }

   /**
    * Search for next matched object.
    * This routine may only be used after first calling findfirst().
    *
    * @return FR_DONE Indicates no item found.
    * @return Error code
    */
   FRESULT findnext() {

      FRESULT rc = f_findnext(&dir, &fno);
      if (rc != FR_OK) {
         return rc;
      }
      return (fno.fname[0] != '\0')?FR_OK:FR_DONE;
   }

};

} // namespace USBDM::FATFS
} // namespace USBDM

#endif /* STARTUP_CODE_FATFS_H_ */
