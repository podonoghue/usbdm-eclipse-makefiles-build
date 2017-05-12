/*! \file
    \brief Header file for DeviceData

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
   | 27 Feb 2010 | Created
   +====================================================================
    \endverbatim
*/

#ifndef DEVICEDATA_HPP_
#define DEVICEDATA_HPP_

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

#if defined(COMPILE_DEVICE_DATA_DLL)
// Building Library
#define DEVICE_DATA_DESCSPEC CPP_DLL_EXPORT
// Incorporating library directly
#elif defined(LINK_DEVICE_DATA_DLL)
//! Link to routines directly
#define DEVICE_DATA_DESCSPEC CPP_DLL_LOCAL
#else
// Dynamically linking to library
#define DEVICE_DATA_DESCSPEC CPP_DLL_IMPORT
#endif

#include <vector>
#include <map>
#include <string>
#include <streambuf>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <tr1/memory>

#include "UsbdmSystem.h"

#include "Common.h"
#include "MyException.h"
#include "USBDM_API.h"
#include "TargetDefines.h"
#include "FlashImage.h"

/**
 * RS08/HCS08/CFV1 clock types
 */
typedef enum {
   CLKINVALID = -1,
   CLKEXT = 0,
   S08ICGV1,S08ICGV2,S08ICGV3,S08ICGV4,
   S08ICSV1,S08ICSV2,S08ICSV2x512,S08ICSV3,S08ICSV4,
   RS08ICSOSCV1,
   RS08ICSV1,
   S08MCGV1,S08MCGV2,S08MCGV3,
   MKMCGV1,
} ClockTypes_t;

/**
 * Memory types
 */
typedef enum {
   MemInvalid  = 0,
   MemRAM      = 1,
   MemEEPROM   = 2,
   MemFLASH    = 3,
   MemFlexNVM  = 4,
   MemFlexRAM  = 5,
   MemROM      = 6,
   MemIO       = 7,
   MemPFlash   = 8,
   MemDFlash   = 9,
   MemXRAM     = 10, // DSC
   MemPRAM     = 11, // DSC
   MemXROM     = 12, // DSC
   MemPROM     = 13, // DSC
} MemType_t;

/**
 * Address types
 */
typedef enum {
  AddrLinear, //<! Linear addresses
  AddrPaged,  //<! Pages addresses
} AddressType;


//! SecurityInfo options when programming
//! These options affect the handling of the NVOPT/NVSEC location
//!
typedef enum {
   SEC_DEFAULT      = 0,   //!< Leave Flash image unchanged
   SEC_SECURED      = 1,   //!< Make Flash image secured
   SEC_UNSECURED    = 2,   //!< Make Flash image unsecured
   SEC_SMART        = 3,   //!< Modify flash image unless already modified
   SEC_INTELLIGENT  = 3,   //!< Modify flash image unless already modified
   SEC_CUSTOM       = 4,   //!< Use custom value
} SecurityOptions_t;

/*
 * ============================================================================================
 */
class DEVICE_DATA_DESCSPEC EnumValuePair;

/**
 * Information on clock types
 */
class DEVICE_DATA_DESCSPEC ClockTypes {
private:
   //! Mappings for Clock types
   static const EnumValuePair clockNames[];

public:
   /**
    *  Determines the clock type from a string description
    */
   static ClockTypes_t        getClockType(const std::string &typeName);
   /**
    *  Determines the clock type from a string description
    */
   static ClockTypes_t        getClockType(const char *typeName);
   /**
    *  Determines the clock name from a clock type
    *
    * @param clockType Clocktype to map to name
    *
    * @return string describing the clock
    */
   static const std::string   getClockName(ClockTypes_t clockType);
   /**
    * Determine clock index from name
    *
    * @return index
    */
   static int                 getClockIndex(const std::string &typeName);
   /**
    * Determine clock index from clock type
    *
    * @return index
    */
   static int                 getClockIndex(ClockTypes_t clockType);

private:
   /**
    *  Empty constructor
    */
   ClockTypes() {};
};

/*
 * ============================================================================================
 */

/**
 * Class Representing shared information in the database
 */
class DEVICE_DATA_DESCSPEC SharedInformationItem {

protected:
   /**
    * Constructor
    */
   SharedInformationItem() {}

public:
   virtual ~SharedInformationItem() {};

   /**
    *  Tests equality (same object)
    */
   int operator==(const SharedInformationItem &other) {
      return this == &other;
   }
};

/**
 * Smart pointer for SharedInformationItem
 */
typedef std::tr1::shared_ptr<SharedInformationItem> SharedInformationItemPtr;

/*
 * ============================================================================================
 */

/**
 * Class Representing TCL script in the database
 */
class DEVICE_DATA_DESCSPEC TclScript : public SharedInformationItem {

private:
   std::string script;     //!< String representing script

public:
   /**
    * Construct script
    *
    * @param script String representing script
    */
   TclScript(std::string script) : script(script) {}
   ~TclScript() {}
   /**
    * Return readable representation
    *
    * @return Description
    */
   const std::string toString() const;
   /**
    * Get script
    *
    * @return string representing the script
    */
   const std::string getScript() const;
};

/**
 * Smart pointer for TclScript
 */
typedef std::tr1::shared_ptr<TclScript>         TclScriptPtr;
/**
 * Smart pointer for TclScript
 */
typedef std::tr1::shared_ptr<const TclScript>   TclScriptConstPtr;


/*
 * ============================================================================================
 */

/**
 * Class Representing a Target register description (used by GDB) in the database
 */
class DEVICE_DATA_DESCSPEC RegisterDescription: public SharedInformationItem {

private:
   std::string description;         //!< Description of registers as required by GDB
   unsigned    lastRegisterIndex;   //!< Index of last register

public:
   /**
    * Construct description
    *
    * @param description         Description of registers as required by GDB
    * @param lastRegisterIndex   Index of last register
    */
   RegisterDescription(std::string description, unsigned lastRegisterIndex) :
      description(description),
      lastRegisterIndex(lastRegisterIndex) {}
   ~RegisterDescription() {}
   /**
    * Returns description in readable form
    *
    * @return string
    */
   const std::string toString() const;
   /**
    * Get GDB register description
    *
    * @return String description
    */
   const std::string getDescription() const;
   /**
    * Get index of last register in description
    *
    * @return index
    */
   unsigned          getLastRegisterIndex() const;
};
/**
 * Smart pointer for RegisterDescription
 */
typedef std::tr1::shared_ptr<RegisterDescription>         RegisterDescriptionPtr;
/**
 * Smart pointer for RegisterDescription
 */
typedef std::tr1::shared_ptr<const RegisterDescription>   RegisterDescriptionConstPtr;

/*
 * ============================================================================================
 */

/**
 * Class Representing a Flash program in the database
 */
class DEVICE_DATA_DESCSPEC FlashProgram: public SharedInformationItem {

private:
   std::string flashProgram;  //!< String representing the flash program (SRECs)

public:
   /**
    * Construct Flash program entry
    *
    * @param program Flash program (SRECs)
    */
   FlashProgram(std::string program) :
      flashProgram(program) {}
   ~FlashProgram() {}
   /**
    * Returns the flash program as a string
    *
    * @return Readable string representing the flash program
    */
   const std::string toString() const;
   /**
    * Returns the flash program as a string
    *
    * @return Flash program as string
    */
   const std::string getFlashProgram() const;
};
/**
 * Smart pointer for FlashProgram
 */
typedef std::tr1::shared_ptr<FlashProgram>       FlashProgramPtr;
/**
 * Smart pointer for FlashProgram
 */
typedef std::tr1::shared_ptr<const FlashProgram> FlashProgramConstPtr;

/*
 * ============================================================================================
 */
/**
 * Class Representing a Security description in the database
 */
class DEVICE_DATA_DESCSPEC SecurityDescription: public SharedInformationItem {

private:
   std::string securityDescription;    //!< String describing entry

public:
   /**
    * Construct security description
    *
    * @param desc Description
    */
   SecurityDescription(std::string desc) : securityDescription(desc) {}
   ~SecurityDescription() {}
   const std::string toString() const;
   /**
    * Get security description
    *
    * @return Description
    */
   const std::string getSecurityDescription() const;
   /**
    * Set security description
    *
    * @param desc Description
    */
   void setSecurityDescription(std::string desc);
};

/**
 * Smart pointer for SecurityDescription
 */
typedef std::tr1::shared_ptr<SecurityDescription>       SecurityDescriptionPtr;
/**
 * Smart pointer for SecurityDescription
 */
typedef std::tr1::shared_ptr<const SecurityDescription> SecurityDescriptionConstPtr;

/*
 * ============================================================================================
 */
///**
// * Class representing a list of GNU information in the database
// */
//class DEVICE_DATA_DESCSPEC GnuInfoList: public SharedInformationItem {
//
//public:
//   GnuInfoList() {}
//   ~GnuInfoList() {}
//   const std::string toString() const;
//};
//
///**
// * Smart pointer for GnuInfoList
// */
//typedef std::tr1::shared_ptr<GnuInfoList>       GnuInfoListPtr;
///**
// * Smart pointer for GnuInfoList
// */
//typedef std::tr1::shared_ptr<const GnuInfoList> GnuInfoListConstPtr;

/*
 * ============================================================================================
 */
///**
// * Class representing GNU information in the database
// */
//class DEVICE_DATA_DESCSPEC GnuInfo {
//
//public:
//   GnuInfo() {}
//    ~GnuInfo() {}
//    /*
//     *
//     */
//    const std::string toString() const;
//};
//
///**
// * Smart pointer for GnuInfo
// */
//typedef std::tr1::shared_ptr<GnuInfo>       GnuInfoPtr;
///**
// * Smart pointer for GnuInfo
// */
//typedef std::tr1::shared_ptr<const GnuInfo> GnuInfoConstPtr;
/*
 * ============================================================================================
 */

/**
 * Class representing checksum entry in database
 */
class DEVICE_DATA_DESCSPEC ChecksumInfo: public SharedInformationItem {

public:
   //! Type of security value
   enum ChecksumType {
      twoComplementByteSum,  // Calculated as 2's complement of a range of bytes
   };

private:
   uint32_t      startAddress;    //!< Address of start of checksum range
   uint32_t      endAddress;      //!< Address of end of checksum range
   uint32_t      locationAddress; //!< Address of location to store checksum value
   ChecksumType  type;            //!< Type of checksum

public:
   /**
    * Create checksum information
    *
    *  @param startAddress Address of start of checksum range
    *  @param endAddress   Address of end of checksum range
    *  @param valueAddress Address of location to store checksum value
    *  @param type         Type of checksum
    */
   ChecksumInfo(uint32_t startAddress, uint32_t endAddress, uint32_t locationAddress, ChecksumType type);
   /**
    * Copy constructor
    *
    * @param other Other to copy
    */
   ChecksumInfo(const ChecksumInfo& other);
   /**
    * Destructor
    */
   ~ChecksumInfo() {}
   /**
    * Returns a description as a string
    *
    * @return Readable string representing the checksum
    */
   const std::string toString() const;
   /**
    * Update the checksum within the given image
    *
    * @return FlashImage to update
    */
   USBDM_ErrorCode updateChecksum(FlashImagePtr flashImage) const;
   /**
    * Get location of checksum information
    *
    * @return size
    */
   unsigned getlocation() const;
   /**
    * Get size of security information
    *
    * @return size
    */
   unsigned getSize() const;
};
/**
 * Smart pointer for ChecksumInfo
 */
typedef std::tr1::shared_ptr<ChecksumInfo> ChecksumInfoPtr;
/**
 * Smart pointer for ChecksumInfo
 */
typedef std::tr1::shared_ptr<const ChecksumInfo> ChecksumInfoConstPtr;
/*
 * ============================================================================================
 */
/**
 * Class representing security information in the database
 */
class DEVICE_DATA_DESCSPEC SecurityInfo: public SharedInformationItem {

public:
   //! Type of security value
   enum SecType {
      unsecure,     //!< Unsecure value
      secure,       //!< Secure value
      custom,       //!< Custom value
      lpcChecksum,  //!< Custom value
   };

private:
   unsigned    size;          //!< Size of entry in bytes
   SecType     mode;          //!< Type of entry
   std::string securityInfo;  //!< String representing the values

public:
   /**
    * Create empty security information
    */
   SecurityInfo() : size(0), mode(custom), securityInfo("") {}
   /**
    * Create security information
    *
    * @param   size           Size of entry in bytes
    * @param   mode           Type of entry
    * @param   securityInfo   String representing the values
    */
   SecurityInfo(int size, SecType mode, std::string securityInfo);
   /**
    * Copy constructor
    *
    * @param other Other to copy
    */
   SecurityInfo(const SecurityInfo& other);
   /**
    * Destructor
    */
   ~SecurityInfo() {}
   /**
    * Returns the flash program as a string
    *
    * @return Readable string representing the flash program
    */
   const std::string toString() const;
   /**
    * Get security values as string
    *
    * @return string
    */
   std::string       getSecurityInfo() const;
   /**
    * Set security value
    *
    * @param securityInfo Values to set
    */
   void              setSecurityInfo(const std::string &securityInfo);
   /**
    * Get security values as array of uint8_t
    *
    * @return constant array
    */
   const uint8_t    *getData() const;
   /**
    * Set security value
    *
    * @param size Size of security information
    * @param data Values to set
    */
   void              setData(unsigned size, uint8_t *data);
   /**
    * Set security mode
    *
    * @param mode Mode to set
    */
   void              setMode(SecType mode);
   /**
    * Get security mode
    *
    * @return mode
    */
   SecType           getMode() const;
   /**
    * Get size of security information
    *
    * @return size
    */
   unsigned          getSize() const;
};
/**
 * Smart pointer for SecurityInfo
 */
typedef std::tr1::shared_ptr<SecurityInfo> SecurityInfoPtr;
/**
 * Smart pointer for SecurityInfo
 */
typedef std::tr1::shared_ptr<const SecurityInfo> SecurityInfoConstPtr;
/*
 * ============================================================================================
 */

/**
 * Class representing security information in the database
 */
class DEVICE_DATA_DESCSPEC SecurityEntry: public SharedInformationItem {
private:
   SecurityDescriptionPtr  securityDescription;       //!< Description of entry
   SecurityInfoPtr         unsecureInformation;       //!< Unsecure information
   SecurityInfoPtr         secureInformation;         //!< Secure information
   SecurityInfoPtr         customSecureInformation;   //!< Custom security information
   SecurityInfoPtr         checksum;                  //!< Checksum for LPC devices

public:
   /**
    * Create security entry
    *
    * @param securityDesc  Description of entry
    * @param unsecureInfo  Unsecure information
    * @param secureInfo    Secure information
    */
   SecurityEntry(SecurityDescriptionPtr securityDesc,
                 SecurityInfoPtr        unsecureInfo,
                 SecurityInfoPtr        secureInfo)
    : securityDescription(securityDesc),
      unsecureInformation(unsecureInfo),
      secureInformation(secureInfo) {}
   /**
    * Create security entry
    *
    * @param securityDesc  Description of entry
    * @param unsecureInfo  Unsecure information
    * @param secureInfo    Secure information
    */
   SecurityEntry(SecurityDescriptionPtr securityDesc,
                 SecurityInfoPtr        lpcChecksum)
    : securityDescription(securityDesc),
      checksum(lpcChecksum) {}
   /**
    * Construct emty entry
    */
   SecurityEntry() {}
    ~SecurityEntry() {}

    /**
     * Get readable description
     *
     * @return string
     */
    const std::string           toString() const;
    /**
     * Get security description
     *
     * @return string
     */
    SecurityDescriptionConstPtr getSecurityDescription()     const;
    /**
     * Get unsecure information
     *
     * @return string
     */
    SecurityInfoConstPtr        getUnsecureInformation()     const;
    /**
     * Get secure information
     *
     * @return string
     */
    SecurityInfoConstPtr        getSecureInformation()       const;
    /**
     * Get custom secure information
     *
     * @return string
     */
    SecurityInfoConstPtr        getCustomSecureInformation() const;
    /**
     * Get security description
     *
     * @return string
     */
    SecurityDescriptionPtr      getSecurityDescription();
    /**
     * Get unsecure information
     *
     * @return string
     */
    SecurityInfoPtr             getUnsecureInformation();
    /**
     * Get custom secure information
     *
     * @return string
     */
    SecurityInfoPtr             getSecureInformation();
    /**
     * Get custom secure information
     *
     * @return string
     */
    SecurityInfoPtr             getCustomSecureInformation();
    /**
     * Set custom secure information
     *
     * @param securityInfo
     */
    void                        setCustomSecureInformation(SecurityInfoPtr securityInfo);
};

/**
 * Smart pointer for SecurityEntry
 */
typedef std::tr1::shared_ptr<SecurityEntry> SecurityEntryPtr;
/**
 * Smart pointer for SecurityEntry
 */
typedef std::tr1::shared_ptr<const SecurityEntry> SecurityEntryConstPtr;
/*
 * ============================================================================================
 */

/**
 * Class representing Flex Memory information in the database
 */
class DEVICE_DATA_DESCSPEC FlexNVMInfo: public SharedInformationItem {

public:
   /**
    * EEEPROM size entry
    */
   class EeepromSizeValue {
   public:
      std::string    description;   //!< Description of this value
      uint8_t        value;         //!< EEPROM Data Set Size (as used in Program Partition command)
      unsigned       size;          //!< EEEPROM size in bytes (FlexRAM used for EEPROM emulation)
      /**
       * Create EEEPROM size entry
       *
       * @param description   Readable description
       * @param value         Value used in programming
       * @param size          Size represented by this value
       */
      EeepromSizeValue(std::string description, uint8_t value, unsigned size);
   };
   /**
    * FLEX NVM partition entry
    */
   class FlexNvmPartitionValue {
   public:
      std::string    description;  //!< Description of this value
      uint8_t        value;        //!< FlexNVM Partition Code (as used in Program Partition command)
      unsigned       backingStore; //!< EEPROM backing store size in bytes
      /**
       * Create FLEX NVM partition entry
       *
       * @param description   Readable description
       * @param value         Value used in programming
       * @param backingStore  Backing store size for this entry
       */
      FlexNvmPartitionValue(std::string description, uint8_t value, unsigned backingStore);
   };

private:
    unsigned                           backingRatio;           //!< Ratio of EEEPROM to backing EEPROM
    std::vector<EeepromSizeValue>      eeepromSizeValues;      //!< Vector of EEEPROM values
    std::vector<FlexNvmPartitionValue> flexNvmPartitionValues; //!< Vector of FLEX NVM partition values

public:
    /**
     * Create FLEX NVM information
     *
     * @param backingRatio Ratio between EEEPROM and backing EEPROM
     */
    FlexNVMInfo(int backingRatio = 16) : backingRatio(backingRatio) {}
    ~FlexNVMInfo() {}
    /**
     * Provides readable description of object
     *
     * @return string
     */
    const std::string toString() const;
    /**
     * Returns list of permitted EEEPROM values for use in partition command
     *
     * @return vector of permitted values
     */
    const std::vector<FlexNVMInfo::EeepromSizeValue> &getEeepromSizeValues() const;
    /**
     *  Returns list of permitted Partition values for use in partition command
     *
     * @return vector of permitted values
     */
    const std::vector<FlexNVMInfo::FlexNvmPartitionValue> &getFlexNvmPartitionValues() const;
    /**
     * Add EEPROM size value
     *
     * @param eeepromSizeValue value to add
     */
    void addEeepromSizeValues(const EeepromSizeValue &eeepromSizeValue);
    /**
     * Add FLEX NVM partition value
     *
     * @param flexNvmPartitionValue value to add
     */
    void addFlexNvmPartitionValues(const FlexNvmPartitionValue &flexNvmPartitionValue);
    /*
     * Get backing ratio
     *
     * @return Current ratio
     */
    unsigned getBackingRatio() const;
    /**
     * Set backing ratio
     *
     * @param backingRatio Ratio to set
     */
    void setBackingRatio(unsigned  backingRatio);
};
/**
 * Smart pointer for FlexNVMInfo
 */
typedef std::tr1::shared_ptr<FlexNVMInfo> FlexNVMInfoPtr;
/**
 * Smart pointer for FlexNVMInfo
 */
typedef std::tr1::shared_ptr<const FlexNVMInfo> FlexNVMInfoConstPtr;

/*
 * ============================================================================================
 */

/**
 * Represents a collection of related memory ranges
 *
 * This may be used to represent a non-contiguous range of memory locations that are related
 * e.g. two ranges of Flash that are controlled by the same Flash controller as occurs in some HCS08s
 */
class DEVICE_DATA_DESCSPEC MemoryRegion: public SharedInformationItem {

private:
   MemoryRegion(MemoryRegion &);
//   MemoryRegion &operator=(MemoryRegion &);

public:
   static const uint16_t DefaultPageNo = 0xFFFF;
   static const uint16_t NoPageNo      = 0xFFFE;
   class MemoryRange {
      public:
         uint32_t start;
         uint32_t end;
         uint16_t pageNo;
   };
   std::vector<MemoryRange> memoryRanges;           //!< Memory ranges making up this region
   MemType_t                type;                   //!< Type of memory regions
   AddressType              addressType;            //!< Linear/Paged addressing
   uint32_t                 registerAddress;        //!< Control register addresses
   uint32_t                 pageAddress;            //!< Paging register address
   uint32_t                 securityAddress;        //!< Non-volatile option address
   uint32_t                 sectorSize;             //!< Size of sectors i.e. minimum erasable unit
   uint32_t                 alignment;              //!< Memory programming alignment requirement (1,2,4 etc)
   mutable uint32_t         lastIndexUsed;          //!< Last used memoryRanges index
   FlashProgramConstPtr     flashProgram;           //!< Region-specific flash algorithm
   SecurityEntryPtr         securityInformation;    //!< Region-specific security data
   ChecksumInfoPtr          checksumInfo;           //!< Checksum information
   FlexNVMInfoConstPtr      flexNVMInfo;

private:
   /**
    *  Find the index of the memory range containing the given address
    *
    * @param address - address to look for
    *
    * @return range index or -1 if not found
    *
    * @note - Uses cache
    */
   int findMemoryRangeIndex(uint32_t address) const;

public:
   /**
    * Constructor for memory region
    *
    * @param type
    * @param registerAddress
    * @param pageAddress
    * @param securityAddress
    * @param sectorSize
    * @param alignment
    */
   MemoryRegion (MemType_t type = MemInvalid,
                 uint32_t  registerAddress = 0,
                 uint32_t  pageAddress = 0,
                 uint32_t  securityAddress = 0,
                 uint32_t  sectorSize = 0,
                 uint32_t  alignment = 1) :
      type(type),
      addressType(AddrPaged),
      registerAddress(registerAddress),
      pageAddress(pageAddress),
      securityAddress(securityAddress),
      sectorSize(sectorSize),
      alignment(alignment),
      lastIndexUsed((uint32_t)-1)
   { }

   friend std::ostream & operator <<(std::ostream & s, const MemoryRegion mr);

   /**
    *  Add a memory range to this memory region
    *
    * @param startAddress - start address (inclusive)
    * @param endAddress   - end address (inclusive)
    * @param pageNo       - page number (if used)
    */
   void addRange (uint32_t startAddress, uint32_t endAddress, uint16_t pageNo=DefaultPageNo);

   /**
    *  Check if an address is within this memory region
    * @param address - address to check
    *
    * @return true/false result
    */
   bool contains(uint32_t address) const;

   /**
    *  Find the last contiguous address relative to the address
    *
    * @param address        Start address to check
    * @param lastContinuous The end address of the largest contiguous memory range including address
    * @param memorySpace    Memory space to check
    *
    * @return true  = start address is within memory
    *         false = start address is not within memory
    */
   bool findLastContiguous(uint32_t address, uint32_t *lastContinuous, MemorySpace_t memorySpace = MS_None) const;

   /**
    *  Get page number for address
    *
    * @param address - address to check
    *
    * @return MemoryRegion::NoPageNo if not paged/within memory
    */
   uint16_t getPageNo(uint32_t address) const;

   /**
    *  Obtain string describing the memory type
    *
    * @param memoryType - Memory type
    *
    * @return - ptr to static string describing type
    */
   static const char *getMemoryTypeName(MemType_t memoryType);

   /**
    *  Get name of memory type
    */
   const char *getMemoryTypeName(void) const;

   /**
    *  Indicates if a programmable type e.g Flash, eeprom etc.
    *
    * @param memoryType - Memory type
    *
    * @return - true/false result
    */
   static bool isProgrammableMemory(MemType_t memoryType);

   /**
    *  Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
    *
    * @return - true/false result
    */
   bool isProgrammableMemory() const;

   /**
    *  Indicates if a simple writable type e.g RAM etc.
    *
    * @param memoryType - Memory type
    *
    * @return - true/false result
    */
   static bool isWritableMemory(MemType_t memoryType);

   /**
    *  Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
    *
    * @return - true/false result
    */
   bool isWritableMemory() const;

   /**
    *  Get security address (Flash location)
    */
   uint32_t    getSecurityAddress()   const;

   // Only available on Flash & EEPROM
   uint32_t    getFCLKDIVAddress() const;
   uint32_t    getFSECAddress()    const;
   uint32_t    getFTSTMODAddress() const;
   uint32_t    getFCNFGAddress()   const;
   uint32_t    getFPROTAddress()   const;
   uint32_t    getFSTATAddress()   const;
   uint32_t    getFCMDAddress()    const;
   uint32_t    getFADDRAddress()   const;
   uint32_t    getFDATAAddress()   const;
   uint32_t    getDummyAddress()   const;
   uint32_t    getSectorSize()     const;
   AddressType getAddressType()    const;
   // Get memory region data alignment (1,2,4 etc)
   uint32_t    getAlignment()      const;

   uint32_t    getFOPTAddress()    const;
   uint32_t    getFLCRAddress()    const;

   bool        valid() const;
   void        setSecurityAddress(uint32_t address);
   MemType_t   getMemoryType() const;

   static bool isCompatibleType(MemType_t memType, MemorySpace_t memorySpace);
   bool        isCompatibleType(MemorySpace_t memorySpace) const;
   uint32_t    getPageAddress() const;
   uint32_t    getRegisterAddress() const;

   const MemoryRange                  *getMemoryRange(unsigned index) const;
   const MemoryRange                  *getMemoryRangeFor(uint32_t address) const;

   const FlashProgramConstPtr          getFlashprogram()        const;
   const SecurityDescriptionConstPtr   getSecurityDescription() const;
   const ChecksumInfoPtr               getChecksumInfo()        const;
   const SecurityInfoConstPtr          getSecureInfo()          const;
   const SecurityInfoConstPtr          getUnsecureInfo()        const;
   const SecurityInfoConstPtr          getCustomSecureInfo()    const;

   void setChecksumInfo(const ChecksumInfoPtr value);
   void setFlashProgram(FlashProgramConstPtr program);
   void setAddressType(AddressType type);

   void setSecurityEntry(SecurityEntryPtr info);
   void setflexNVMInfo(FlexNVMInfoConstPtr info);

   SecurityEntryConstPtr   getSecurityEntry() const;
   SecurityEntryPtr        getSecurityEntry();
   FlexNVMInfoConstPtr     getflexNVMInfo() const;
};

typedef std::tr1::shared_ptr<MemoryRegion> MemoryRegionPtr;
typedef std::tr1::shared_ptr<const MemoryRegion> MemoryRegionConstPtr;

/*
 * ============================================================================================
 */
class DEVICE_DATA_DESCSPEC TargetSDID {

public:
   uint32_t mask; // 0 => wildcard
   uint32_t value;
   TargetSDID(uint32_t mask, uint32_t value) : mask(mask), value(value) {}
};

/*
 * ============================================================================================
 */
class EraseMethods;

/**
 * Smart pointer for EraseMethods
 */
typedef std::tr1::shared_ptr<EraseMethods>         EraseMethodsPtr;
/**
 * Smart pointer for EraseMethods
 */
typedef std::tr1::shared_ptr<const EraseMethods>   EraseMethodsConstPtr;


/*
 * ============================================================================================
 */
class ResetMethods;

/**
 * Smart pointer for ResetMethods
 */
typedef std::tr1::shared_ptr<ResetMethods>         ResetMethodsPtr;
/**
 * Smart pointer for ResetMethods
 */
typedef std::tr1::shared_ptr<const ResetMethods>   ResetMethodsConstPtr;

/*
 * ============================================================================================
 */

class DeviceData;

typedef std::tr1::shared_ptr<DeviceData> DeviceDataPtr;
typedef std::tr1::shared_ptr<const DeviceData> DeviceDataConstPtr;

//! Information about a target device
//!
class DEVICE_DATA_DESCSPEC DeviceData {

public:
   //! How to handle erasing of flash before programming
   typedef enum  {
      eraseNone,        //! Don't erase
      eraseMass,        //! Mass erase / unsecure
      eraseAll,         //! Erase all flash arrays
      eraseSelective,   //! Erase flash block selectively
   } EraseOptions;

   //! How to reset target
   typedef enum  {
      resetHardware,    //! Use hardware reset
      resetSoftware,    //! Use software reset
      defaultCustom,    //! Use device default reset method
      resetNone,        //! Use hardware reset
   } ResetOptions;

   //! Get readable names for erase options
   static const char *getEraseOptionName(EraseOptions option);

   //! Structure to hold FlexNVM information
   class FlexNVMParameters {
   public:
      uint8_t eeepromSize;    //!< EEPROM size value
      uint8_t partionValue;   //!< Partition value
   public:
      /**
       * Default Constructor
       */
      FlexNVMParameters() : eeepromSize(0xFF), partionValue(0xFF) {}
   };

private:
   TargetType_t                  targetType;             //!< Type of target
   std::string                   targetName;             //!< Name of target
   std::string                   aliasName;              //!< Name of real target if alias
   bool                          hidden;                 //!< Device is hidden in programmer
   uint32_t                      ramStart;               //!< Start of internal RAM
   uint32_t                      ramEnd;                 //!< End of internal RAM
   ClockTypes_t                  clockType;              //!< Type of clock
   uint32_t                      clockAddress;           //!< Address of Clock register block
   uint32_t                      clockTrimNVAddress;     //!< Address of Non-volatile storage of trim value
   unsigned long int             clockTrimFreq;          //!< Trim frequency in Hz of the _internal_ clock e.g. 32.7 kHz (0 => no trim required)
   bool                          connectionFreqGiven;    //!< Use connectionFreq if needed
   unsigned long int             connectionFreq;         //!< BDM connection frequency in Hz
   uint32_t                      watchdogAddress;        //!< Address of watchdog (COPCTL, WDOG etc) register
   uint32_t                      SDIDAddress;            //!< Address of SDID register
   SecurityOptions_t             security;               //!< Determines security options of programmed target (modifies NVFOPT value)
   EraseOptions                  eraseOption;            //!< How to handle erasing of flash before programming
   std::vector<MemoryRegionPtr>  memoryRegions;          //!< Different memory regions e.g. EEPROM, RAM etc.
   mutable MemoryRegionConstPtr  lastMemoryRegionUsed;   //!< To improve memory searches
   TclScriptConstPtr             flashScripts;           //!< Flash script
   FlashProgramConstPtr          commonFlashProgram;     //!< Common flash code
   FlexNVMParameters             flexNVMParameters;      //!< FlexNVM partitioning values
   FlexNVMInfoConstPtr           flexNVMInfo;            //!< Table describing FlexNVM partitioning
   std::vector<TargetSDID>       targetSDIDs;            //!< System Device Identification Register values (0=> don't know/care)
   RegisterDescriptionConstPtr   registerDescription;    //!< Register description
   uint32_t                      hcs08sbdfrAddress;      //!< HCS08 SBDFR register address
   EraseMethodsConstPtr          eraseMethods;           //!< Possible erase methods
   ResetMethodsConstPtr          resetMethods;           //!< Possible reset methods

public:
   static const DeviceData       defaultDevice;
   static const unsigned int     BDMtoBUSFactor = 1;     //!< Factor relating measured BDM frequency to Target BUS frequency\n
                                                         //!< busFrequency = connectionFreq * BDMtoBUSFactor
public:
   static uint32_t                getDefaultHCS08sbdfrAddress();
   uint32_t                       getHCS08sbdfrAddress() const;
   void                           setHCS08sbdfrAddress(uint32_t address);

   const std::string              getTargetName() const;
   const std::string              getAliasName() const;
   TargetType_t                   getTargetType() const;
   bool                           isHidden() const;
   uint32_t                       getRamStart() const;
   uint32_t                       getRamEnd() const;
   ClockTypes_t                   getClockType() const;
   uint32_t                       getClockAddress() const;
   uint32_t                       getClockTrimNVAddress() const;
   unsigned long                  getClockTrimFreq() const;  /*Hz*/
   unsigned long                  getConnectionFreq() const; /*Hz*/
   SecurityOptions_t              getSecurity() const;
   EraseOptions                   getEraseOption() const;
   uint32_t                       getWatchdogAddress() const;
   uint32_t                       getSDIDAddress() const;
   unsigned int                   getBDMtoBUSFactor() const;
   FlashProgramConstPtr           getCommonFlashProgram() const;
   FlashProgramConstPtr           getFlashProgram() const;
   TclScriptConstPtr              getFlashScripts() const;
   FlexNVMInfoConstPtr            getflexNVMInfo() const;
   FlexNVMParameters              getFlexNVMParameters() const;
   const std::vector<TargetSDID>& getTargetSDIDs() const;
   bool                           isAlias(void) const;
   RegisterDescriptionConstPtr    getRegisterDescription() const;
   MemoryRegionConstPtr           getMemoryRegion(unsigned index) const;
   MemoryRegionPtr                getMemoryRegion(unsigned index);
   MemoryRegionConstPtr           getMemoryRegionFor(uint32_t address, MemorySpace_t memorySpace=MS_None) const;
   const std::vector<TargetSDID>  getSDIDs() const;
   TargetSDID                     getSDID(unsigned index=0) const;

   uint32_t                       getDefaultClockTrimFreq(ClockTypes_t clockType) const;
   uint32_t                       getDefaultClockTrimNVAddress(ClockTypes_t clockType) const;
   uint32_t                       getDefaultClockAddress(ClockTypes_t clockType) const;
   uint32_t                       getDefaultClockTrimFreq() const;
   uint32_t                       getDefaultClockTrimNVAddress() const;
   uint32_t                       getDefaultClockAddress() const;

   bool                           isThisDevice(std::map<uint32_t,uint32_t> targetSDIDs, bool acceptZero=true) const ;
   bool                           isThisDevice(uint32_t targetSDID, bool acceptZero=true) const ;

   MemType_t                      getMemoryType(uint32_t address, MemorySpace_t memorySpace=MS_None);
   uint16_t                       getPageNo(uint32_t address);

   void                           addSDID(uint32_t mask, uint32_t value);
   void                           setEraseMethods(EraseMethodsConstPtr methods);
   EraseMethodsConstPtr           getEraseMethods() const;
   void                           setResetMethods(ResetMethodsConstPtr methods);
   ResetMethodsConstPtr           getResetMethods() const;

   void                           addMemoryRegion(MemoryRegionPtr pMemoryRegion);
   void                           setTargetName(const std::string &name);
   void                           setAliasName(const std::string &name);
   void                           setHidden(bool value = true);
   void                           setRamStart(uint32_t addr);
   void                           setRamEnd(uint32_t addr);
   void                           setClockType(ClockTypes_t type);
   void                           setClockAddress(uint32_t addr);
   void                           setClockTrimNVAddress(uint32_t addr);
   void                           setClockTrimFreq(unsigned long hertz /*Hz*/);
   void                           setConnectionFreq(unsigned long hertz /*Hz*/);
   void                           setSecurity(SecurityOptions_t option);
   void                           setCustomSecurity(const std::string &securityValue);
   void                           setEraseOption(EraseOptions option);
   void                           setWatchdogAddress(uint32_t addr);
   void                           setSDIDAddress(uint32_t addr);
   void                           setFlashScripts(TclScriptConstPtr script);
   void                           setCommonFlashProgram(FlashProgramConstPtr program);
   void                           setflexNVMInfo(FlexNVMInfoConstPtr info);
   void                           setFlexNVMParameters(const FlexNVMParameters &param);
   void                           setTargetSDIDs(const std::vector<TargetSDID> &list);
   void                           setRegisterDescription(RegisterDescriptionConstPtr desc);

   const std::string              toString() const;

   DeviceData(TargetType_t targetType=T_ILLEGAL, const std::string &targetName="" );

   virtual ~DeviceData() {}
   DeviceDataPtr shallowCopy() const;
};

/*
 * ============================================================================================
 */

/**
 * Database of device information
 */
class DEVICE_DATA_DESCSPEC DeviceDataBase {

private:
   std::vector<DeviceDataPtr>                            deviceData;         //!< List of devices
   std::map<const std::string, SharedInformationItemPtr> sharedInformation;  //!< Shared information referenced by devices
//   DeviceDataPtr                                         defaultDevice;      //!< Generic 'default' device
   TargetType_t                                          targetType;         //!< Target type

   DeviceDataBase (DeviceDataBase &);                                        //!< No copying
   DeviceDataBase &operator=(DeviceDataBase &);                              //!< No assignment
   void loadDeviceData();

private:
   SharedInformationItemPtr getSharedData(std::string key) const;

public:
   /**
    * Constructs device database for given target type
    *
    * @param targetType Type of target device
    */
   DeviceDataBase(const TargetType_t targetType) : targetType(targetType) {
      loadDeviceData();
   };
   ~DeviceDataBase();

   /**
    * Obtain iterator for start of database
    *
    *  @return iterator positioned at start
    */
   std::vector<DeviceDataPtr>::const_iterator begin() const;
   /**
    * Obtain iterator for end of database
    *
    *  @return iterator positioned at end
    */
   std::vector<DeviceDataPtr>::const_iterator end() const;

   /** Searches the known devices for a device with given name
    *
    * @param targetName - Name of device
    *
    * @returns entry found or NULL if no suitable device found
    *
    * @note - If the device is an alias then it will return the true device
    */
   DeviceDataConstPtr          findDeviceFromName(const std::string &targetName) const;
   /** Searches the known devices for a device with given name
    *
    * @param targetName - Name of device
    *
    * @returns index or -1 if not found
    */
   int                         findDeviceIndexFromName(const std::string &targetName) const;
   const DeviceData           &operator[](unsigned index) const;
   DeviceDataPtr               getDefaultDevice();
   void                        setDefaultDevice(DeviceDataPtr defaultDevice);
   unsigned                    getNumDevice() const;
   void                        listDevices() const;
   DeviceDataPtr               addDevice(DeviceDataPtr device);
   SharedInformationItemPtr    addSharedData(std::string key, SharedInformationItemPtr pSharedData);
   SharedInformationItemPtr    addSharedData(std::string key, SharedInformationItem *sharedData);
   SecurityEntryPtr            getSecurityEntry(std::string key);
   ChecksumInfoPtr             getChecksumEntry(std::string key);
   SecurityDescriptionPtr      getSecurityDescription(std::string key);
   SecurityInfoConstPtr        getSecurityInfo(std::string key) const;
   MemoryRegionPtr             getMemoryRegion(std::string key);
   TclScriptConstPtr           getTclScript(std::string key) const;
   RegisterDescriptionConstPtr getRegisterDescription(std::string key) const;
   FlashProgramConstPtr        getFlashProgram(std::string key) const;
   FlexNVMInfoConstPtr         getFlexNVMInfo(std::string key) const;
   ResetMethodsConstPtr        getResetMethods(std::string key) const;
   EraseMethodsConstPtr        getEraseMethods(std::string key) const;
};

typedef std::tr1::shared_ptr<DeviceDataBase> DeviceDataBasePtr;

/*
 * ============================================================================================
 */

/**
 * Class representing erase methods in the database
 */
class DEVICE_DATA_DESCSPEC EraseMethods : public SharedInformationItem {
   unsigned                 fMethod;
   DeviceData::EraseOptions fDefaultMethod;

public:
   EraseMethods() : fMethod(0), fDefaultMethod(DeviceData::EraseOptions::eraseNone) {
   }
   /**
    * Add erase method
    */
   void addMethod(DeviceData::EraseOptions method) {
      fMethod |= (1<<((int)method));
   }
   /**
    * Add default erase method
    */
   void addDefaultMethod(DeviceData::EraseOptions method) {
      fMethod       |= (1<<((int)method));
      fDefaultMethod = method;
   }
   /**
    * Remove erase method
    */
   void removeMethod(DeviceData::EraseOptions method) {
      fMethod &= ~(1<<((int)method));
   }
   /**
    * Checks if a method is included
    */
   bool includesMethod(DeviceData::EraseOptions method) const {
      return (fMethod & (1<<((int)method))) != 0;
   }
   /**
    * Get default method
    */
   DeviceData::EraseOptions getDefaultMethod(DeviceData::ResetOptions method) const {
      return fDefaultMethod;
   }
};

/*
 * ============================================================================================
 */

/**
 * Class Representing Reset methods in the database
 */
class DEVICE_DATA_DESCSPEC ResetMethods : public SharedInformationItem {
   unsigned                 fMethod;
   DeviceData::ResetOptions fDefaultMethod;

public:
   /**
    * Create default empty
    */
   ResetMethods() : fMethod(0), fDefaultMethod(DeviceData::ResetOptions::defaultCustom) {
   }
   /**
    * Add method
    */
   void addMethod(DeviceData::ResetOptions method) {
      fMethod |= (1<<((int)method));
   }
   /**
    * Add default erase method
    */
   void addDefaultMethod(DeviceData::ResetOptions method) {
      fMethod |= (1<<((int)method));
      fDefaultMethod = method;
   }
   /**
    * Remove erase method
    */
   void removeMethod(DeviceData::ResetOptions method) {
      fMethod &= ~(1<<((int)method));
   }
   /**
    * Checks if a method is included
    */
   bool isIncludedMethod(DeviceData::ResetOptions method) {
      return (fMethod & (1<<((int)method))) != 0;
   }
   /**
    * Get default method
    */
   bool getDefaultMethod(DeviceData::ResetOptions method) {
      return fDefaultMethod;
   }
};

#endif /* DEVICEDATA_HPP_ */
