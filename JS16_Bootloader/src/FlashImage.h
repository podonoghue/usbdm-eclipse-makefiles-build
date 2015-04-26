#ifndef _S_FILELOADER_H_
#define _S_FILELOADER_H_

#include "Common.h"
#include "UsbdmSystem.h"
#include <string>
#include <string.h>
#include <map>
#include <stdexcept>

using namespace std;

#define PAGE_BIT_OFFSET          (14)
#define PAGE_SIZE                (1U<<PAGE_BIT_OFFSET)
#define PAGE_MASK                (PAGE_SIZE-1U)
#define MAX_PAGE_NUM             (MAX_SFILE_ADDRESS/PAGE_SIZE)
#define MAX_PHYSICAL_PAGE_NUM    (MAX_FLASH_SIZE/PAGE_SIZE)

//! Class used to represent a Flash image containing loaded file(s)
class FlashImage {

public:
   //! Memory space types supported
   enum MemorySpaceType {Unified, Program, Data, Last=Data};

   //! Error codes returned by routines
   enum ErrorCode {
      SFILE_RC_OK = 0,            //!< No error
      SFILE_RC_CHECKSUM,          //!< S-record has incorrect checksum
      SFILE_RC_ILLEGAL_LINE,      //!< S-record has invalid/unsupported record
      SFILE_RC_FILE_OPEN_FAILED,  //!< Hex file failed to open (fopen() failed)
      SFILE_RC_ADDRESS_TOO_LARGE, //!< S-record address is out of range
      SFILE_RC_ILLEGAL_OP,        //!< Illegal operand
   };
   class Enumerator;

private:
   class MemoryPage {
   private:
      uint8_t data[PAGE_SIZE];        // Represents a (Flash) page in target
      uint8_t validBits[PAGE_SIZE/8]; // Indicates valid bytes in data
   public:
      MemoryPage() {
         memset(data, 0xFF, sizeof(data));
         memset(validBits, 0, sizeof(validBits));
      }
      //! Indicates if a page[index] has been written to
      bool isValid(unsigned index) const {
         if (index >= PAGE_SIZE)
            throw runtime_error("Page index out of range");
         return (validBits[index/8] & (1<<(index&0x7)))?true:false;
      }
      //! Sets page[index] to value & marks as valid
      void setValue(unsigned index, uint8_t value) {
         if (index >= PAGE_SIZE)
            throw runtime_error("Page index out of range");
         data[index] = value;
         validBits[index/8] |= (1<<(index&0x7));
      }
      //! Returns contents of page[index] if valid or 0xFF otherwise
      uint8_t getValue(unsigned index) {
         if (index >= PAGE_SIZE)
            throw runtime_error("Page index out of range");
         if (!isValid(index))
            return 0xFF;
         return data[index];
      }
   };

   class MemorySpace {
      friend class Enumerator;
      friend class FlashImage;

   private:
      map<uint32_t,MemoryPage*> memoryPages;               //!< Ptrs to occupied memory pages
      int                       largeModel;                //!< Indicates address > 16bits used
      bool                      empty;                     //!< Memory is blank
      unsigned                  firstAllocatedAddress;     //!< First used memory locations
      unsigned                  lastAllocatedAddress;      //!< Last used memory locations
      uint16_t                  lastPageNumAccessed;       //!< Page # of last page accessed
      MemoryPage               *lastMemoryPageAccessed;    //!< Last page accessed
      unsigned                  byteCount;                 //!< Count of occupied bytes

   public:
      MemorySpace() :
         largeModel(false),
         empty(true),
         firstAllocatedAddress((unsigned )(-1)),
         lastAllocatedAddress(0),
         lastPageNumAccessed((uint16_t )(-1)),
         lastMemoryPageAccessed(NULL),
         byteCount(0)
      {
         initData();
      }
      ~MemorySpace() {
         initData();
      }
      MemoryPage *getmemoryPage(uint32_t pageNum) {
         MemoryPage *memoryPage;
         if ((pageNum == lastPageNumAccessed) && (lastMemoryPageAccessed != NULL)) {
            // Used cached copy
            memoryPage = lastMemoryPageAccessed;
         }
         else {
            map<uint32_t, MemoryPage *>::iterator iter = memoryPages.find(pageNum);
            if (iter == memoryPages.end())
               memoryPage = NULL;
            else
               memoryPage = iter->second;
            // Cache access           lastPageNumAccessed     = pageNum;
            lastMemoryPageAccessed  = memoryPage;
         }
         return memoryPage;
      }
      //! Checks if the memory location is valid (has been written to)
      //!
      //! @param address - 32-bit memory address
      //!
      //! @return\n
      //!         true   => location has been previously written to \n
      //!         false  => location is invalid
      //!
      int isValid(uint32_t address) {
         uint16_t offset;
         uint16_t pageNum;
         addressToPageOffset(address, pageNum, offset);
         MemoryPage *memoryPage = getmemoryPage(pageNum);
         return (memoryPage != NULL) && (memoryPage->isValid(offset));
      }
      Enumerator *getEnumerator() {
         return new Enumerator(*this);
      }
      bool isEmpty() const {
         return empty;
      }
      bool isLargeModel() const {
         return largeModel;
      }
      //! Initialises the memory to empty
      //!
      void initData(void) {
         // Initialise flash image to unused value
         map<uint32_t,MemoryPage*>::iterator it = memoryPages.begin();
         while(it != memoryPages.end()){
            delete it->second;
            it++;
         }
         memoryPages.clear();
         largeModel             = false;
         empty                  = true;
         firstAllocatedAddress  = (unsigned )(-1);
         lastAllocatedAddress   = 0;
         lastPageNumAccessed    = (uint16_t )(-1);
         lastMemoryPageAccessed = NULL;
         byteCount              = 0;
      }
//      //! Checks if  a memory location is already allocated in Flash image
//      //!
//      //! @param address - 32-bit memory address
//      //!
//      //! @return\n
//      //!         true   => location is already allocated \n
//      //!         false  => location does not exist
//      //!
//      int isOccupied(uint32_t address, MemorySpaceType memorySpace=Unified)
//      {
//         uint16_t offset;
//         uint16_t pageNum;
//         addressToPageOffset(address, pageNum, offset);
//         map<uint32_t,MemoryPage*>::const_iterator it = memoryPages.find(pageNum);
//         return (it != memoryPages.end()) && (it->second->isValid(offset));
//      }
      //! Returns an approximate count of occupied bytes
      //!
      unsigned getByteCount(MemorySpaceType memorySpace=Unified) const {
         return byteCount;
      }

      ErrorCode   loadS1S9File(const string &fileName, bool clearBuffer, bool wordAddresses);
      ErrorCode   loadData(uint32_t bufferSize, uint32_t address, const uint8_t data[], bool dontOverwrite = false);
      MemoryPage *allocatePage(uint32_t pageNo);
      uint8_t     getValue(uint32_t address);
      void        setValue(uint32_t address, uint8_t value);
      void dumpRange(unsigned int startAddress, unsigned int endAddress);
   };

public:
   //! Class to enumerate the occupied locations within the memory image
   //! @note may be invalidated by changes to the referenced image
   class Enumerator {
   private:
      MemorySpace     &memoryImage;    //! Associated flash image
      uint32_t        address;

   public:
      //! Construct an enumerator positioned at the start of the occupied flash image
      //!
      //! @note the first call to isValid() will return false if the image is empty
      //!
      Enumerator(MemorySpace &memoryImage) :
         memoryImage(memoryImage),
         address(memoryImage.firstAllocatedAddress) {
      }

      //! Construct an enumerator positioned at a given starting address
      //!
      Enumerator(MemorySpace &memoryImage, uint32_t address) :
         memoryImage(memoryImage),
         address(address) {
         if (address < memoryImage.firstAllocatedAddress)
            address = memoryImage.firstAllocatedAddress;
      }

      //! Get the current location as a flat address
      //!
      uint32_t getAddress() const { return address; }

      //! Get the current location as a word address
      //!
      uint32_t getWordAddress() const {
         if ((address & 0x1) != 0)
            throw runtime_error("Enumerator::getWordAddress()");
         return address/2;
      }

      //! Indicates if the current memory location is valid (occupied)
      //! @return \n
      //!        true  => current location is occupied
      //!        false => current location is unoccupied/unallocated
      int isValid() const {
//         print("enumerator::isValid(0x%06X)\n", address);
         return memoryImage.isValid(address);
      }

      //! Sets the iterator to the given address
      //! @return \n
      //!        true  => current location is occupied
      //!        false => current location is unoccupied/unallocated
      int setAddress(uint32_t addr) {
//         print("enumerator::isValid(0x%06X)\n", address);
         address = addr;
         if (!memoryImage.isValid(address))
            return nextValid();
         return true;
      }
      bool nextValid();
      void lastValid();
   };

private:
   string         sourceFilename;       //!< Name of last file loaded
   string         sourcePath;           //!< Path of last file loaded
   MemorySpace    memorySpaces[Last+1]; //!< Multiple memory spaces are supported

   //! Maps Address to PageNum:offset
   //!
   //! @param address - 32-bit address
   //! @param pageNum - page number portion of address
   //! @param offset  - offset within page
   //!
   //! @note - These values do NOT refer to the paging structure used by the target!
   //!
   static void addressToPageOffset(uint32_t address, uint16_t &pageNum, uint16_t & offset)
   {
      offset  = address & PAGE_MASK;
      pageNum = address >> PAGE_BIT_OFFSET;
      //      printf("%8.8X=>%2.2X:%4.4X\n", address, pageNum, offset);
   }

   //! Maps PageNum:offset to Address
   //!
   //! @param pageNum - page number portion of address
   //! @param offset  - offset within page
   //!
   //! @return address - 32-bit address
   //!
   //! @note - These values do NOT refer to the paging structure used by the target!
   //!
   static uint32_t pageOffsetToAddress(uint16_t pageNum, uint16_t offset)
   {
      if (offset>=PAGE_SIZE)
         throw runtime_error("Page offset too large\n");
      return (pageNum << PAGE_BIT_OFFSET) + offset;
   }

   MemoryPage *getmemoryPage(uint32_t pageNum, MemorySpaceType memorySpace) {
      return memorySpaces[memorySpace].getmemoryPage(pageNum);
   }

   MemoryPage *allocatePage(uint32_t pageNo, MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].allocatePage(pageNo);
   }

public:
   //=====================================================================
   //! Constructor - creates an empty Flash image
   //!
   FlashImage(void) {
      initData();
   }

   //=====================================================================
   //! ~Constructor
   //!
   ~FlashImage() {
      initData();
   }

   //=====================================================================
   // ! Check if image is entirely empty (never written to)
   bool isEmpty() const {
      bool blank = true;
      for (int memorySpace=Unified; memorySpace<=Last; memorySpace++) {
         blank = blank && memorySpaces[memorySpace].isEmpty();
      }
      return blank;
   }

   //=====================================================================
   // ! Check if image is entirely empty (never written to)
   bool isEmpty(MemorySpaceType memorySpace) const {
      return memorySpaces[memorySpace].isEmpty();
   }

   //=====================================================================
   //! Indicates if the current memory location is valid (has been written to)
   //! @return \n
   //!        true  => current location is occupied
   //!        false => current location is unoccupied/unallocated
   int isValid(uint32_t address, MemorySpaceType memorySpace) {
      return memorySpaces[memorySpace].isValid(address);
   }

   //! Get pathname of last file loaded
   const string & getSourcePathname() const {
      return sourcePath;
   }

   void dumpRange(unsigned int startAddress, unsigned int endAddress, MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].dumpRange(startAddress, endAddress);
   }

   //=====================================================================
   //! Initialise the Flash image to empty
   //
   void initData(void) {
      // Initialise flash image to unused value
      for (int memorySpace=Unified; memorySpace<=Last; memorySpace++) {
         memorySpaces[memorySpace].initData();
      }
   }

   //=====================================================================
   //! Returns an approximate count of occupied bytes
   //!
   unsigned getByteCount(MemorySpaceType memorySpace=Unified) const {
      return memorySpaces[memorySpace].byteCount;
   }

   //=====================================================================
   //! Load S1-9 file
   //!
   //! @param filePath    - Path to file
   //! @param clearBuffer - Clear the buffer before loading
   //! @param memorySpace - Memory space to load into
   //!
   //! @return - Error code
   //!
   ErrorCode loadS1S9File(const string &filePath, bool clearBuffer = true, MemorySpaceType memorySpace=Unified) {
      sourceFilename = "";
      sourcePath     = "";
      ErrorCode rc = memorySpaces[memorySpace].loadS1S9File(filePath, clearBuffer, false);
      if (rc == SFILE_RC_OK) {
         sourcePath      = filePath;
         sourceFilename  = filePath; //!Todo Fix
      }
      return rc;
   }

   //=====================================================================
   //! Load S1-9 file
   //!
   //! @param filePath    - Path to file
   //! @param clearBuffer - Clear the buffer before loading
   //! @param memorySpace - Memory space to load into
   //!
   //! @return - Error code
   //!
   ErrorCode loadWordS1S9File(const string &filePath, bool clearBuffer = true, MemorySpaceType memorySpace=Unified) {
      sourceFilename = "";
      sourcePath     = "";
      ErrorCode rc = memorySpaces[memorySpace].loadS1S9File(filePath, clearBuffer, true);
      if (rc == SFILE_RC_OK) {
         sourcePath      = filePath;
         sourceFilename  = filePath; //!Todo Fix
      }
      return rc;
   }

   //=====================================================================
   //! Obtain the value of a Flash memory location
   //!
   //! @param address - 32-bit memory address
   //! @param memorySpace  - memory space
   //!
   //! @return - 8-bit value (dummy value of 0xFF if unallocated address)
   //!
   uint8_t getValue(uint32_t address, MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].getValue(address);
   }

   //=====================================================================
   //! Obtain the value of a Flash memory location
   //!
   //! @param wordAddress - 32-bit memory word address
   //! @param memorySpace  - memory space
   //!
   //! @return - 16-bit value (dummy value of 0xFFFF if unallocated address)
   //!
   uint16_t getWordValue(uint32_t wordAddress, MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].getValue(wordAddress)+(memorySpaces[memorySpace].getValue(wordAddress+1)<<8);
   }

   //=====================================================================
   //! Set a Flash memory location
   //!
   //! @param address - 32-bit memory byte address
   //! @param value   - 8-bit value to write to image
   //! @param memorySpace  - memory space
   //!
   //! @note Allocates a memory location if necessary
   //!
   void setValue(uint32_t address, uint8_t value, MemorySpaceType memorySpace=Unified) {
      memorySpaces[memorySpace].setValue(address, value);
   }

   //=====================================================================
   //! Set a Flash memory location
   //!
   //! @param wordAddress - 32-bit memory word address
   //! @param value       - 16-bit value to write to image
   //! @param memorySpace  - memory space
   //!
   //! @note Allocates a memory location if necessary
   //!
   void setWordValue(uint32_t wordAddress, uint16_t value, MemorySpaceType memorySpace=Unified) {
      memorySpaces[memorySpace].setValue(2*wordAddress,   value);
      memorySpaces[memorySpace].setValue(2*wordAddress+1, value>>8);
   }

   //=====================================================================
   //! Load data into Flash image
   //!
   //! @param bufferSize   - size of data to load (in bytes)
   //! @param address      - byte address to load at
   //! @param data         - data to load
   //! @param memorySpace  - memory space
   ErrorCode loadData(uint32_t        bufferSize,
                      uint32_t        address,
                      const uint8_t   data[],
                      bool            dontOverwrite = false,
                      MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].loadData(bufferSize, address, data, dontOverwrite);
   }

   //=====================================================================
   //! Load data into Flash image
   //!
   //! @param bufferSize   - size of data to load (in bytes)
   //! @param wordAddress  - word address to load at
   //! @param data         - data to load
   //! @param memorySpace  - memory space
   ErrorCode loadDataWords(uint32_t        bufferSize,
                           uint32_t        wordAddress,
                           const uint8_t   data[],
                           bool            dontOverwrite = false,
                           MemorySpaceType memorySpace=Unified) {
      if ((bufferSize&0x01) != 0)
         throw runtime_error("Size must be even");
      return memorySpaces[memorySpace].loadData(bufferSize, 2*wordAddress, data, dontOverwrite);
   }

   Enumerator *getEnumerator(MemorySpaceType memorySpace=Unified) {
      return memorySpaces[memorySpace].getEnumerator();
   }

   static const char *getErrorMessage(ErrorCode errorNum);
   void printMemoryMap(void) const;
};
#endif // _S_FILELOADER_H_


