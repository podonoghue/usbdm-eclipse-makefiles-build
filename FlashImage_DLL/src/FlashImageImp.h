/** \file
    \brief Header file for FlashImageImp.cpp

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
#ifndef  _FLASHIMAGE_IMP_H_
#define  _FLASHIMAGE_IMP_H_

#include <stdio.h>

#include "FlashImage.h"

class  MemoryPage;
class  EnumeratorImp;
typedef std::shared_ptr<MemoryPage> MemoryPagePtr;

class FlashImageImp : public FlashImage {

   template <typename T> class MallocWrapper {
   private:
      T *&ptr;
   public:
      MallocWrapper(T *&ptr) : ptr(ptr) {
      }

      T *alloc(size_t size) {
         free();
         ptr = (T*)malloc(size);
         UsbdmSystem::Log::print("Allocated %ld @0x%p\n", (long)size, ptr);
         return ptr;
      }
      void free() {
         if (ptr != 0) {
            UsbdmSystem::Log::print("Freeing @0x%p\n", ptr);
            ::free(ptr);
            ptr = 0;
         }
      }
      ~MallocWrapper() {
         free();
      }
   };

   class Openfile {
   private:
      FILE *fp;
   public:
      Openfile(const char* filePath, const char* modes) {
         fp = fopen(filePath, modes);
         UsbdmSystem::Log::print("Opened %s (fp=%p)\n", filePath, fp);
      }
      FILE *getfp() {
         return  fp;
      }
      ~Openfile() {
//         UsbdmSystem::Log::print("Closing file (fp=%p)\n", fp);
         if (fp != 0) {
            fclose(fp);
         }
      }
   };

   friend MemoryPage;
   friend EnumeratorImp;

protected:
   static const int                  PAGE_BIT_OFFSET =  (15-sizeof(uint8_t));  // 2**14 = 16K pages
   static const unsigned             PAGE_SIZE       =  (1U<<PAGE_BIT_OFFSET);
   static const int                  PAGE_MASK       =  (PAGE_SIZE-1U);
   static const int                  MAX_SREC_SIZE   =  (1<<4);//! Maximum size of a S-record (2^N)

protected:
   TargetType_t                      targetType;
   bool                              wordAddresses;
   std::map<uint32_t,MemoryPagePtr>  memoryPages;            //!< Pointers to occupied memory pages
   unsigned                          firstAllocatedAddress;  //!< First used memory locations
   unsigned                          lastAllocatedAddress;   //!< Last used memory locations
   uint16_t                          lastPageNumAccessed;    //!< Page # of last page accessed
   MemoryPagePtr                     lastMemoryPageAccessed; //!< Last page accessed
   unsigned                          elementCount;           //!< Count of occupied bytes
   bool                              littleEndian;           //!< Target is little-endian
   std::string                       sourceFilename;         //!< Name of last file loaded
   std::string                       sourcePath;             //!< Path of last file loaded
   bool                              allowOverwrite;
   FILE                             *fp;
   bool                              discardFF;
   bool                              printHeader;
   Elf32_Ehdr                        elfHeader;
   Elf32_Shdr                        stringSectionHeader;
   Elf32_Phdr                       *programHeaders;
   char                             *symTable;

public:
   FlashImageImp();
   virtual ~FlashImageImp();

   virtual void                  setTargetType(TargetType_t targetType);
   virtual char const           *getErrorString(USBDM_ErrorCode rc);
   virtual void                  clear();
   virtual bool                  isValid(uint32_t address);
   virtual EnumeratorPtr         getEnumerator(uint32_t address = 0);
   virtual bool                  isEmpty() const;
   virtual void                  printMemoryMap();
   virtual unsigned              getByteCount() const;
   virtual const std::string    &getSourcePathname() const;
   virtual USBDM_ErrorCode       loadFile(const std::string &filePath, bool clearBuffer, bool forceLinearToPaged);
   virtual USBDM_ErrorCode       saveFile(const std::string &filePath, bool discardFF=true);
   virtual uint8_t               getValue(uint32_t address);
   virtual void                  setValue(uint32_t address, uint8_t value);
   virtual void                  remove(uint32_t address);
   virtual void                  dumpRange(uint32_t startAddress, uint32_t endAddress);
   virtual USBDM_ErrorCode       loadData(uint32_t bufferSize, uint32_t address, const uint8_t  data[], bool dontOverwrite = false);
   virtual USBDM_ErrorCode       loadDataBytes(uint32_t bufferSize, uint32_t address, const uint8_t data[], bool dontOverwrite = false);
   virtual unsigned              getFirstAllocatedAddress() { return firstAllocatedAddress; }
   virtual unsigned              getLastAllocatedAddress()  { return lastAllocatedAddress; }
   virtual void                  fill(uint32_t size, uint32_t address, uint8_t fillValue = 0xFF);
   virtual void                  fillUnused(uint32_t size, uint32_t address, uint8_t fillValue = 0xFF);

protected:
   virtual MemoryPagePtr   getmemoryPage(uint32_t pageNum);
   virtual MemoryPagePtr   allocatePage(uint32_t pageNum);
   uint32_t                targetToNative(uint32_t &);
   uint16_t                targetToNative(uint16_t &);
   int32_t                 targetToNative(int32_t &);
   int16_t                 targetToNative(int16_t &);

   void                    fixElfHeaderSex(Elf32_Ehdr *elfHeader);
   void                    printElfHeader(Elf32_Ehdr *elfHeader);
   void                    printElfProgramHeader(Elf32_Phdr *programHeader, uint32_t loadAddress=-1);
   void                    printElfSectionHeader(Elf32_Shdr *programHeader);
   const char *            getElfString(unsigned index);

   void                    fixElfProgramHeaderSex(Elf32_Phdr *programHeader);
   void                    fixElfSectionHeaderSex(Elf32_Shdr *elfsHeader);
   USBDM_ErrorCode         loadElfBlock(FILE *fp, long fOffset, Elf32_Word size, Elf32_Addr addr);
   USBDM_ErrorCode         loadElfBlockByProgramHeader(Elf32_Phdr *programHeader);
   Elf32_Phdr              *findRelatedProgramHeader(Elf32_Shdr *sectionHeader);

   USBDM_ErrorCode         loadElfBlockBySectionHeader(Elf32_Shdr *sectionHeader);
   USBDM_ErrorCode         recordElfProgramBlock(Elf32_Phdr *programHeader);
   USBDM_ErrorCode         loadElfFile(const std::string &fileName);
   USBDM_ErrorCode         checkTargetType(Elf32_Half e_machine, TargetType_t targetType);
   USBDM_ErrorCode         loadS1S9File(const std::string &fileName, bool forceLinearToPaged);
   USBDM_ErrorCode         loadAbsoluteFile(const std::string &fileName);

   static void             addressToPageOffset(uint32_t address, uint16_t &pageNum, uint16_t &offset);
   static uint32_t         pageOffsetToAddress(uint16_t pageNum, uint16_t offset);
   void                    writeSrec(uint8_t *buffer, uint32_t address, unsigned size);
   void                    writeData(uint8_t *buffer, uint32_t address, unsigned size);
   Elf32_Addr              getLoadAddress(Elf32_Shdr *sectionHeader);
};

typedef std::shared_ptr<FlashImage> FlashImagePtr;

#endif // _FLASHIMAGE_IMP_H_
