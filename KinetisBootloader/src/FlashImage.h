/** \file
    \brief Header file for FlashImage

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

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
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/

#ifndef  FLASHIMAGE_H_
#define  FLASHIMAGE_H_

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

#if defined(COMPILE_FLASH_IMAGE_DLL)
// Buiding Library
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_EXPORT
// Incorporating library directly
#elif defined(LINK_USBDM_FLASH_DLL)
//! Link to routines directly
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_LOCAL
#else
// Dynamically linking to library
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_IMPORT
#endif

#include <memory>
#include <stdint.h>
#include <string>

#include "USBDM_API.h"

/**
 * Represents a memory image containing loaded file(s)
 */
class USBDM_FLASHIMAGE_DECLSPEC FlashImage {

public:
   static const uint32_t DataOffset    =  (0x02000000UL);  // Offset used for DSC Data region

   /**
    *  Class to enumerate the occupied locations within the memory image
    *
    *  @note may be invalidated by changes to the referenced image
    */
   class Enumerator {
   protected:
      /**
       *  Construct an enumerator positioned at a given starting address
       *  Note: if address is unallocated then the Enumerator is advanced to next allocated address
       */
      Enumerator() {};

   public:
      virtual ~Enumerator() {};

      /**
       * Get the current location as a flat address
       */
      virtual uint32_t   getAddress() const = 0;
      /**
       * Indicates if the current memory location is valid (occupied)
       *
       * @return \n
       *         true  => current location is occupied
       *        false => current location is unoccupied/unallocated
       */
      virtual bool       isValid() const = 0;
      /**
       * Sets the iterator to the given address
       *
       *  @return \n
       *         true  => current location is occupied
       *         false => current location is unoccupied/unallocated
       */
      virtual bool       setAddress(uint32_t addr) = 0;
      /**
       * Advance to next occupied flash location
       *
       * @return \n
       *        true  => advanced to next occupied location
       *        false => no occupied locations remain, enumerator is left at last \e unoccupied location
       */
      virtual bool       nextValid() = 0;
      /**
       *  Advance location to just before the next unoccupied flash location or page boundary
       *  Assumes current location is occupied.
       */
      virtual void       lastValid() = 0;
   };
   typedef std::shared_ptr<FlashImage::Enumerator> EnumeratorPtr;

protected:
   /**
    *   Constructor - creates an empty Flash image
    */
   FlashImage() {};

public:
   virtual ~FlashImage() {};

   /**
    *   Set target type of image
    *
    *   @param targetType - Target type to set
    */
   virtual void                 setTargetType(TargetType_t targetType) = 0;
   /**
    * Get string describing the error code
    *
    * @param rc - Error code
    *
    * @return String describing the error
    */
   virtual char const          *getErrorString(USBDM_ErrorCode rc) = 0;
   /**
    *  Load a S19 or ELF file into the buffer. \n
    *
    *  @param filePath      : Path of file to load
    *  @param clearBuffer   : Clear buffer before loading
    *
    *  @return error code see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode      loadFile(const std::string &filePath, bool clearBuffer=true) = 0;
   /**
    *  Save image buffer as a S19 file. \n
    *
    *  @param filePath      : Path of file to load
    *  @param discardFF     : Discard sizable blocks of consecutive 0xFF values (assumed blank)
    *
    *  @return error code see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode      saveFile(const std::string &filePath, bool discardFF=true) = 0;
   /**
    *  Initialises the memory to empty
    */
   virtual void clear() = 0;
   /**
    * Check if image is entirely empty (never written to)
    *
    * @return true=>image is entirely empty,\n
    *               image is not empty
    */
   virtual bool isEmpty() const = 0;
   /**
    *  Checks if the memory location is valid (has been written to)
    *
    *  @param address - 32-bit memory address
    *
    *  @return\n
    *          true   => location has been previously written to \n
    *          false  => location is invalid
    */
   virtual bool isValid(uint32_t address) = 0;
   /**
    *  Returns an approximate count of occupied bytes
    */
   virtual unsigned getByteCount() const = 0;
   /**
    *  Obtain the value of a Flash memory location
    *
    *  @param address - 32-bit memory address
    *
    *  @return - uint8_t value (a dummy value of 0xFF is quietly returned for unallocated locations)
    */
   virtual uint8_t  getValue(uint32_t address) = 0;

   /**
    *   Set a Flash memory location
    *
    *   @param address - 32-bit memory address
    *   @param value   - uint8_t value to write to image
    *
    *   @note Allocates a memory location if necessary
    */
   virtual void setValue(uint32_t address, uint8_t value) = 0;
   /**
    * Remove a Flash memory location (set to unprogrammed)
    *
    * @param address - 32-bit memory address
    */
   virtual void                 remove(uint32_t address) = 0;
   /**
    *   Gets an enumerator for the memory
    *   The enumerator is positioned at the 1st valid location after the given address
    */
   virtual EnumeratorPtr       getEnumerator(uint32_t address = 0) = 0;

   /**
    *  Prints a summary of the Flash memory allocated/used.
    */
   virtual void                 printMemoryMap() = 0;
   /**
    *  Get pathname of last file loaded
    */
   virtual const std::string   &getSourcePathname() const = 0;
   /**
    *  Dump the contents of a range of memory to log file
    *
    * @param startAddress - start of range
    * @param endAddress   - end of range
    *
    */
   virtual void                 dumpRange(uint32_t startAddress, uint32_t endAddress) = 0;
   /**
    * Load data into Flash image
    *
    * @param bufferSize    - size of data to load (in uint8_t)
    * @param address       - address to load at
    * @param data          - data to load
    * @param dontOverwrite - produce error if overwriting existing data
    */
   virtual USBDM_ErrorCode      loadData(uint32_t bufferSize, uint32_t address, const uint8_t  data[], bool dontOverwrite = false) = 0;
   /**
    * Load data into Flash image from byte array
    *
    * @param bufferSize    - size of data to load (in bytes)
    * @param address       - address to load at (byte/word address)
    * @param data          - data to load
    * @param dontOverwrite - true to prevent overwriting data
    *
    * @note This is only of use if uint8_t is not a byte
    */
   virtual USBDM_ErrorCode      loadDataBytes(uint32_t bufferSize, uint32_t address, const uint8_t data[], bool dontOverwrite = false) = 0;

   /**
    * Get first allocated address
    *
    * @return - first allocated address
    */
   virtual unsigned getFirstAllocatedAddress() = 0;

   /**
    * Get last allocated address
    *
    * @return - last allocated address
    */
   virtual unsigned getLastAllocatedAddress() = 0;

   /**
    *  Fills a range of memory with a value
    *
    *  @param fillValue - value to use for fill
    *  @param size      - size of range to fill
    *  @param address   -  start address of range
    */
   virtual void fill(uint32_t size, uint32_t address, uint8_t fillValue = 0xFF) = 0;
   /**
    *  Fills unused bytes within a range of memory with a value
    *
    *  @param fillValue - value to use for fill
    *  @param size      - size of range to fill
    *  @param address   -  start address of range
    */
   virtual void fillUnused(uint32_t size, uint32_t address, uint8_t fillValue = 0xFF) = 0;
};

typedef std::shared_ptr<FlashImage> FlashImagePtr;

#endif // FLASHIMAGE_H_
