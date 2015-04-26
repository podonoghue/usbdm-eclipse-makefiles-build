/*
 * FlashImage.h
 */

#ifndef  _FLASHIMAGE_H_
#define  _FLASHIMAGE_H_

#include <tr1/memory>
#include <stdint.h>
#include <string>

#include "USBDM_API.h"

#if !defined(CPP_DLL_LOCAL)
   //! Functions exported from a library
   #define CPP_DLL_EXPORT __declspec(dllexport)
   //! Functions local to a library
   #define CPP_DLL_LOCAL // __attribute__ ((visibility ("hidden")))
   //! Functions imported from a library
   #define CPP_DLL_IMPORT __declspec(dllimport)
#endif

#if defined(COMPILE_FLASH_IMAGE_DLL)
   //! Create Library
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_EXPORT
#elif defined(LINK_USBDM_FLASH_DLL)
   //! Link to routines directly
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_LOCAL
#else
   //! Link against Library
#define USBDM_FLASHIMAGE_DECLSPEC CPP_DLL_IMPORT
#endif

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

#endif // _FLASHIMAGE_H_
