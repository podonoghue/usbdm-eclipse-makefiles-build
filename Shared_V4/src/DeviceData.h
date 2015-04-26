/*
 * DeviceData.hpp
 *
 *  Created on: 27/02/2010
 *      Author: podonoghue
 */

#ifndef DEVICEDATA_HPP_
#define DEVICEDATA_HPP_
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

//! RS08/HCS08/CFV1 clock types
//!
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

//! memory types
//!
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

typedef enum {
  AddrLinear,
  AddrPaged,
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
class EnumValuePair;

//! Information on clock types
//!
class ClockTypes {
private:
   //! Mappings for Clock types
   static const EnumValuePair clockNames[];

public:
   static ClockTypes_t        getClockType(const std::string &typeName);
   static ClockTypes_t        getClockType(const char *typeName);
   static const std::string   getClockName(ClockTypes_t clockType);
   static int                 getClockIndex(const std::string &typeName);
   static int                 getClockIndex(ClockTypes_t clockType);
   ClockTypes() {};
};

/*
 * ============================================================================================
 */
class SharedInformationItem {

public:
   SharedInformationItem() {}
   virtual ~SharedInformationItem() {};
   int operator==(const SharedInformationItem &other) {
      return this == &other;
   }
};

typedef std::tr1::shared_ptr<SharedInformationItem> SharedInformationItemPtr;

/*
 * ============================================================================================
 */
class TclScript : public SharedInformationItem {

private:
   std::string script;

public:
   TclScript(std::string script) : script(script) {}
   ~TclScript() {}
   const std::string toString() const;
   const std::string getScript() const;
};
typedef std::tr1::shared_ptr<TclScript>         TclScriptPtr;
typedef std::tr1::shared_ptr<const TclScript>   TclScriptConstPtr;

/*
 * ============================================================================================
 */
class RegisterDescription: public SharedInformationItem {

private:
   std::string description;
   unsigned    lastRegisterIndex;

public:
   RegisterDescription(std::string description, unsigned lastRegisterIndex) :
      description(description),
      lastRegisterIndex(lastRegisterIndex) {}
   ~RegisterDescription() {}
   const std::string toString() const;
   const std::string getDescription() const;
   unsigned          getLastRegisterIndex() const;
};
typedef std::tr1::shared_ptr<RegisterDescription>         RegisterDescriptionPtr;
typedef std::tr1::shared_ptr<const RegisterDescription>   RegisterDescriptionConstPtr;

/*
 * ============================================================================================
 */
class FlashProgram: public SharedInformationItem {

private:
   std::string flashProgram;

public:
   FlashProgram(std::string script) :
      flashProgram(script) {}
   ~FlashProgram() {}
   const std::string toString() const;
   const std::string getFlashProgram() const;
};
typedef std::tr1::shared_ptr<FlashProgram>       FlashProgramPtr;
typedef std::tr1::shared_ptr<const FlashProgram> FlashProgramConstPtr;

/*
 * ============================================================================================
 */
class SecurityDescription: public SharedInformationItem {

private:
   std::string securityDescription;

public:
   SecurityDescription(std::string desc) : securityDescription(desc) {}
    ~SecurityDescription() {}
    const std::string toString() const;
    const std::string getSecurityDescription() const;
    void              setSecurityDescription(std::string s);
};

typedef std::tr1::shared_ptr<SecurityDescription>       SecurityDescriptionPtr;
typedef std::tr1::shared_ptr<const SecurityDescription> SecurityDescriptionConstPtr;

/*
 * ============================================================================================
 */
class GnuInfoList: public SharedInformationItem {

public:
   GnuInfoList() {}
   ~GnuInfoList() {}
   const std::string toString() const;
};

typedef std::tr1::shared_ptr<GnuInfoList>       GnuInfoListPtr;
typedef std::tr1::shared_ptr<const GnuInfoList> GnuInfoListConstPtr;

/*
 * ============================================================================================
 */
class GnuInfo {

public:
   GnuInfo() {}
    ~GnuInfo() {}
    const std::string toString() const;
};

typedef std::tr1::shared_ptr<GnuInfo>       GnuInfoPtr;
typedef std::tr1::shared_ptr<const GnuInfo> GnuInfoConstPtr;
/*
 * ============================================================================================
 */

class SecurityInfo: public SharedInformationItem {

public:
   enum SecType {unsecure, secure, custom};

private:
   unsigned    size;
   SecType     mode;
   std::string securityInfo;

public:
   SecurityInfo() : size(0), mode(custom), securityInfo("") {}
   SecurityInfo(int size, SecType mode, std::string securityInfo);
   SecurityInfo(const SecurityInfo& other);
   ~SecurityInfo() {}

   const std::string toString() const;
   std::string       getSecurityInfo() const;
   void              setSecurityInfo(const std::string &securityInfo);
   const uint8_t    *getData() const;
   void              setData(unsigned size, uint8_t *data);
   void              setMode(SecType mode);
   unsigned          getSize() const;
   SecType           getMode() const;
};
typedef std::tr1::shared_ptr<SecurityInfo> SecurityInfoPtr;
typedef std::tr1::shared_ptr<const SecurityInfo> SecurityInfoConstPtr;
/*
 * ============================================================================================
 */

class SecurityEntry: public SharedInformationItem {
private:
   SecurityDescriptionPtr  securityDescription;
   SecurityInfoPtr         unsecureInformation;
   SecurityInfoPtr         secureInformation;
   SecurityInfoPtr         customSecureInformation;

public:
   SecurityEntry(SecurityDescriptionPtr securityDesc,
                 SecurityInfoPtr        unsecureInfo,
                 SecurityInfoPtr        secureInfo)
    : securityDescription(securityDesc),
      unsecureInformation(unsecureInfo),
      secureInformation(secureInfo) {}
   SecurityEntry() {}
    ~SecurityEntry() {}
    const std::string           toString() const;
    SecurityDescriptionConstPtr getSecurityDescription()     const;
    SecurityInfoConstPtr        getUnsecureInformation()     const;
    SecurityInfoConstPtr        getSecureInformation()       const;
    SecurityInfoConstPtr        getCustomSecureInformation() const;
    SecurityDescriptionPtr      getSecurityDescription();
    SecurityInfoPtr             getUnsecureInformation();
    SecurityInfoPtr             getSecureInformation();
    SecurityInfoPtr             getCustomSecureInformation();
    void                        setCustomSecureInformation(SecurityInfoPtr ptr);
};

typedef std::tr1::shared_ptr<SecurityEntry> SecurityEntryPtr;
typedef std::tr1::shared_ptr<const SecurityEntry> SecurityEntryConstPtr;
/*
 * ============================================================================================
 */

class FlexNVMInfo: public SharedInformationItem {

public:
   class EeepromSizeValue {
   public:
      std::string    description;   // Description of this value
      uint8_t        value;         // EEPROM Data Set Size (as used in Program Partition command)
      unsigned       size;          // EEEPROM size in bytes (FlexRAM used for EEPROM emulation)
      EeepromSizeValue(std::string description, uint8_t value, unsigned size);
   };
   class FlexNvmPartitionValue {
   public:
      std::string    description;  // Description of this value
      uint8_t        value;        // FlexNVM Partition Code (as used in Program Partition command)
      unsigned       backingStore; // EEPROM backing store size in bytes
      FlexNvmPartitionValue(std::string description, uint8_t value, unsigned backingStore);
   };

private:
    unsigned backingRatio;
    std::vector<EeepromSizeValue>      eeepromSizeValues;
    std::vector<FlexNvmPartitionValue> flexNvmPartitionValues;

public:
    FlexNVMInfo(int backingRatio = 16) : backingRatio(backingRatio) {}
    ~FlexNVMInfo() {}

    const std::string toString() const;

    //! Returns list of permitted EEEPROM values for use in partition command
    //!
    //! @return vector of permitted values
    //!
    const std::vector<FlexNVMInfo::EeepromSizeValue> &getEeepromSizeValues() const;

    //! Returns list of permitted Partition values for use in partition command
    //!
    //! @return vector of permitted values
    //!
    const std::vector<FlexNVMInfo::FlexNvmPartitionValue> &getFlexNvmPartitionValues() const;

    void addEeepromSizeValues(const EeepromSizeValue &eeepromSizeValue);
    void addFlexNvmPartitionValues(const FlexNvmPartitionValue &flexNvmPartitionValue);

    unsigned getBackingRatio() const;
    void setBackingRatio(unsigned  backingRatio);
};
typedef std::tr1::shared_ptr<FlexNVMInfo> FlexNVMInfoPtr;
typedef std::tr1::shared_ptr<const FlexNVMInfo> FlexNVMInfoConstPtr;

/*
 * ============================================================================================
 */

// Represents a collection of related memory ranges
//
// This may be used to represent a non-contiguous range of memory locations that are related
// e.g. two ranges of Flash that are controlled by the same Flash controller as occurs in some HCS08s
//
class MemoryRegion: public SharedInformationItem {

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
   uint8_t                  alignment;              //!< Memory programming alignment requirement (1,2,4 etc)
   mutable uint32_t         lastIndexUsed;          //!< Last used memoryRanges index
   FlashProgramConstPtr     flashProgram;           //!< Region-specific flash algorithm
   SecurityEntryPtr         securityInformation;    //!< Region-specific security data
   FlexNVMInfoConstPtr      flexNVMInfo;

private:
   //! Find the index of the memory range containing the given address
   //!
   //! @param address - address to look for
   //!
   //! @return range index or -1 if not found
   //!
   //! @note - Uses cache
   //!
   int findMemoryRangeIndex(uint32_t address) const;

public:
   MemoryRegion (MemType_t type = MemInvalid,
                 uint32_t  registerAddress = 0,
                 uint32_t  pageAddress = 0,
                 uint32_t  securityAddress = 0,
                 uint32_t  sectorSize = 0,
                 uint8_t   alignment = 1) :
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

   //! Add a memory range to this memory region
   //!
   //! @param startAddress - start address (inclusive)
   //! @param endAddress   - end address (inclusive)
   //! @param pageNo       - page number (if used)
   //!
   void addRange (uint32_t startAddress, uint32_t endAddress, uint16_t pageNo=DefaultPageNo);

   //! Check if an address is within this memory region
   //! @param address - address to check
   //!
   //! @return true/false result
   //!
   bool contains(uint32_t address) const;

   //! Find the last contiguous address relative to the address
   //!
   //! @param address        Start address to check
   //! @param lastContinuous The end address of the largest contiguous memory range including address
   //! @param memorySpace    Memory space to check
   //!
   //! @return true  = start address is within memory
   //!         false = start address is not within memory
   //!
   bool findLastContiguous(uint32_t address, uint32_t *lastContinuous, MemorySpace_t memorySpace = MS_None) const;

   //! Get page number for address
   //! @param address - address to check
   //!
   //! @return MemoryRegion::NoPageNo if not paged/within memory
   //!
   uint16_t getPageNo(uint32_t address) const;

   //! Obtain string describing the memory type
   //!
   //! @param memoryType - Memory type
   //!
   //! @return - ptr to static string describing type
   //!
   static const char *getMemoryTypeName(MemType_t memoryType);

   //! Get name of memory type
   //!
   const char *getMemoryTypeName(void) const;

   //! Indicates if a programmable type e.g Flash, eeprom etc.
   //!
   //! @param memoryType - Memory type
   //!
   //! @return - true/false result
   //!
   static bool isProgrammableMemory(MemType_t memoryType);

   //! Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
   //!
   //! @return - true/false result
   //!
   bool isProgrammableMemory() const;

   //! Indicates if a simple writable type e.g RAM etc.
   //!
   //! @param memoryType - Memory type
   //!
   //! @return - true/false result
   //!
   static bool isWritableMemory(MemType_t memoryType);

   //! Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
   //!
   //! @return - true/false result
   //!
   bool isWritableMemory() const;

   //! Get security address (Flash location)
   //!
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
   uint8_t     getAlignment()      const;

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
   const SecurityInfoConstPtr          getSecureInfo()          const;
   const SecurityInfoConstPtr          getUnsecureInfo()        const;
   const SecurityInfoConstPtr          getCustomSecureInfo()    const;

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
class TargetSDID {

public:
   uint32_t mask; // 0 => wildcard
   uint32_t value;
   TargetSDID(uint32_t mask, uint32_t value) : mask(mask), value(value) {}
};

//! Information about a target device
//!
class DeviceData {

public:
   //! How to handle erasing of flash before programming
   typedef enum  {
      eraseNone,        //! Don't erase
      eraseMass,        //! Mass erase / unsecure
      eraseAll,         //! Erase all flash arrays
      eraseSelective,   //! Erase flash block selectively
   } EraseOptions;

   //! Get readable names for erase options
   static const char *getEraseOptionName(EraseOptions option);

   //! Structure to hold FlexNVM information
   class FlexNVMParameters {
   public:
      uint8_t eeepromSize;
      uint8_t partionValue;
   public:
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
   uint16_t                      clockTrimValue;         //!< Clock trim value calculated for a particular device
   std::vector<MemoryRegionPtr>  memoryRegions;          //!< Different memory regions e.g. EEPROM, RAM etc.
   mutable MemoryRegionConstPtr  lastMemoryRegionUsed;   //!< To improve memory searches
   TclScriptConstPtr             flashScripts;           //!< Flash script
   FlashProgramConstPtr          commonFlashProgram;     //!< Common flash code
   FlexNVMParameters             flexNVMParameters;      //!< FlexNVM partitioning values
   FlexNVMInfoConstPtr           flexNVMInfo;            //!< Table describing FlexNVM partitioning
   std::vector<TargetSDID>       targetSDIDs;            //!< System Device Identification Register values (0=> don't know/care)
   RegisterDescriptionConstPtr   registerDescription;    //!< Register description

public:
   static const DeviceData       defaultDevice;
   static const unsigned int     BDMtoBUSFactor = 1;     //!< Factor relating measured BDM frequency to Target BUS frequency\n
                                                         //!< busFrequency = connectionFreq * BDMtoBUSFactor
public:
   const std::string              getTargetName() const;
   const std::string              getAliasName() const;
   const TargetType_t             getTargetType() const;
   bool                           isHidden() const;
   uint32_t                       getRamStart() const;
   uint32_t                       getRamEnd() const;
   ClockTypes_t                   getClockType() const;
   uint32_t                       getClockAddress() const;
   uint32_t                       getClockTrimNVAddress() const;
   uint16_t                       getClockTrimValue() const;
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

   void                           addMemoryRegion(MemoryRegionPtr pMemoryRegion);
   void                           setTargetName(const std::string &name);
   void                           setAliasName(const std::string &name);
   void                           setHidden(bool value = true);
   void                           setRamStart(uint32_t addr);
   void                           setRamEnd(uint32_t addr);
   void                           setClockType(ClockTypes_t type);
   void                           setClockAddress(uint32_t addr);
   void                           setClockTrimNVAddress(uint32_t addr);
   void                           setClockTrimValue(uint16_t value);
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
   DeviceData *shallowCopy(const DeviceData&);
};

typedef std::tr1::shared_ptr<DeviceData> DeviceDataPtr;
typedef std::tr1::shared_ptr<const DeviceData> DeviceDataConstPtr;

/*
 * ============================================================================================
 */

//! Database of device information
//!
class DeviceDataBase {

private:
   std::vector<DeviceDataPtr>                            deviceData;         //! List of devices
   std::map<const std::string, SharedInformationItemPtr> sharedInformation;  //! Shared information referenced by devices
   DeviceDataPtr                                         defaultDevice;      //! Generic 'default' device
   TargetType_t                                          targetType;

   DeviceDataBase (DeviceDataBase &);                                        //! No copying
   DeviceDataBase &operator=(DeviceDataBase &);                              //! No assignment
   void loadDeviceData();

private:
   SharedInformationItemPtr getSharedData(std::string key) const;

public:
   DeviceDataBase(const TargetType_t targetType) : targetType(targetType) {
      loadDeviceData();
   };
   ~DeviceDataBase();

   std::vector<DeviceDataPtr>::const_iterator begin() const;
   std::vector<DeviceDataPtr>::const_iterator end() const;

   DeviceDataConstPtr          findDeviceFromName(const std::string &targetName) const;
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
   SecurityDescriptionPtr      getSecurityDescription(std::string key);
   SecurityInfoConstPtr        getSecurityInfo(std::string key) const;
   MemoryRegionPtr             getMemoryRegion(std::string key);
   TclScriptConstPtr           getTclScript(std::string key) const;
   RegisterDescriptionConstPtr getRegisterDescription(std::string key) const;
   FlashProgramConstPtr        getFlashProgram(std::string key) const;
   FlexNVMInfoConstPtr         getFlexNVMInfo(std::string key) const;
};

typedef std::tr1::shared_ptr<DeviceDataBase> DeviceDataBasePtr;

#endif /* DEVICEDATA_HPP_ */
