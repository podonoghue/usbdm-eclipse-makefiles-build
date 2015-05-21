/*! \file
    \brief Header file for FlashImage.cpp

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
// Incorprating library directly
#elif defined(LINK_USBDM_FLASH_DLL)
//! Link to routines directly
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_LOCAL
#else
// Dynamically linking to library
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_IMPORT
#endif

#include <tr1/memory>
#include <stdint.h>
#include <string>

#include "USBDM_API.h"

/*! Represents a memory image containing loaded file(s)
 */
class USBDM_FLASHIMAGE_DECLSPEC FlashImage {

public:
   static const uint32_t DataOffset    =  (0x02000000UL);  // Offset used for DSC Data region

   class Enumerator {
   //! Class to enumerate the occupied locations within the memory image
   //! @note may be invalidated by changes to the referenced image
   protected:
      Enumerator() {};

   public:
      virtual ~Enumerator() {};

      virtual uint32_t   getAddress() const = 0;
      virtual bool       isValid() const = 0;
      virtual bool       setAddress(uint32_t addr) = 0;
      virtual bool       nextValid() = 0;
      virtual void       lastValid() = 0;
   };

protected:
   FlashImage() {};

public:
   virtual ~FlashImage() {};

   virtual void                 setTargetType(TargetType_t targetType) = 0;

   virtual USBDM_ErrorCode      loadFile(const std::string &filePath, TargetType_t  targetType, bool clearBuffer=true) = 0;
   virtual void                 clear() = 0;
   virtual bool                 isEmpty() const = 0;
   virtual bool                 isValid(uint32_t address) = 0;
   virtual unsigned             getByteCount() const = 0;

   virtual uint8_t              getValue(uint32_t address) = 0;
   virtual void                 setValue(uint32_t address, uint8_t value) = 0;
   virtual void                 remove(uint32_t address) = 0;

   virtual Enumerator          *getEnumerator(uint32_t address = 0) = 0;

   virtual void                 printMemoryMap() = 0;
   virtual const std::string   &getSourcePathname() const = 0;
   virtual void                 dumpRange(uint32_t startAddress, uint32_t endAddress) = 0;

   virtual USBDM_ErrorCode      loadData(uint32_t bufferSize, uint32_t address, const uint8_t  data[], bool dontOverwrite = false) = 0;
   virtual USBDM_ErrorCode      loadDataBytes(uint32_t bufferSize, uint32_t address, const uint8_t data[], bool dontOverwrite = false) = 0;
};

typedef std::tr1::shared_ptr<FlashImage> FlashImagePtr;

#endif // FLASHIMAGE_H_
