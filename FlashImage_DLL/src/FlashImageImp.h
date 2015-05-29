/*
 * FlashImage.h
 */

#ifndef  _FLASHIMAGE_IMP_H_
#define  _FLASHIMAGE_IMP_H_

#include <stdio.h>

#include "FlashImage.h"

class  MemoryPage;
class  EnumeratorImp;
typedef std::tr1::shared_ptr<MemoryPage> MemoryPagePtr;

class FlashImageImp : public FlashImage {

   friend MemoryPage;
   friend EnumeratorImp;

protected:
   static const int                  PageBitOffset =  (15-sizeof(uint8_t));  // 2**14 = 16K pages
   static const unsigned             PageSize      =  (1U<<PageBitOffset);
   static const int                  PageMask      =  (PageSize-1U);
   static const int                  maxSrecSize   = (1<<4);//! Maximum size of a S-record (2^N)

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
   virtual MemoryPagePtr         getmemoryPage(uint32_t pageNum);
   virtual MemoryPagePtr         allocatePage(uint32_t pageNum);
   virtual USBDM_ErrorCode       loadFile(const std::string &filePath, bool clearBuffer=true);
   virtual USBDM_ErrorCode       saveFile(const std::string &filePath, bool discardFF=true);
   virtual uint8_t               getValue(uint32_t address);
   virtual void                  setValue(uint32_t address, uint8_t value);
   virtual void                  remove(uint32_t address);
   virtual void                  dumpRange(uint32_t startAddress, uint32_t endAddress);
   virtual USBDM_ErrorCode       loadData(uint32_t bufferSize, uint32_t address, const uint8_t  data[], bool dontOverwrite = false);
   virtual USBDM_ErrorCode       loadDataBytes(uint32_t bufferSize, uint32_t address, const uint8_t data[], bool dontOverwrite = false);

protected:
   static const char*      get_pFlagsName(unsigned int flags);
   static const char*      get_ptTypeName(unsigned int type);

   uint32_t                targetToNative(uint32_t &);
   uint16_t                targetToNative(uint16_t &);
   int32_t                 targetToNative(int32_t &);
   int16_t                 targetToNative(int16_t &);

   void                    fixElfHeaderSex(Elf32_Ehdr *elfHeader);
   void                    printElfHeader(Elf32_Ehdr *elfHeader);
   void                    printElfProgramHeader(Elf32_Phdr *programHeader);
   void                    fixElfProgramHeaderSex(Elf32_Phdr *programHeader);
   USBDM_ErrorCode         loadElfBlock(FILE *fp, long fOffset, Elf32_Word size, Elf32_Addr addr);
   USBDM_ErrorCode         loadElfBlock(Elf32_Phdr *programHeader);
   USBDM_ErrorCode         loadElfFile(const std::string &fileName);
   USBDM_ErrorCode         checkTargetType(Elf32_Half e_machine, TargetType_t targetType);
   USBDM_ErrorCode         loadS1S9File(const std::string &fileName);
   static void             addressToPageOffset(uint32_t address, uint16_t &pageNum, uint16_t &offset);
   static uint32_t         pageOffsetToAddress(uint16_t pageNum, uint16_t offset);
   void                    writeSrec(uint8_t *buffer, uint32_t address, unsigned size);
   void                    writeData(uint8_t *buffer, uint32_t address, unsigned size);
};

typedef std::tr1::shared_ptr<FlashImage> FlashImagePtr;

#endif // _FLASHIMAGE_IMP_H_
