/*
 * FlashProgrammerCommon.h
 *
 *  Created on: 29 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_FLASHPROGRAMMERCOMMON_H_
#define SRC_FLASHPROGRAMMERCOMMON_H_

#include "FlashProgrammer.h"
#include "UsbdmTclInterpreter.h"
#include "BdmInterface.h"
#include "ProgressTimer.h"

class ProgressTimer;

class FlashProgrammerCommon : public FlashProgrammer {

public:
   FlashProgrammerCommon(DeviceData::EraseMethod defaultEraseMethod, DeviceData::ResetMethod defaultResetMethod);
   virtual ~FlashProgrammerCommon();

   virtual USBDM_ErrorCode    releaseDeviceData() override;
   virtual USBDM_ErrorCode    setDeviceData(const DeviceDataConstPtr device) override;
   virtual USBDM_ErrorCode    setDeviceData(const DeviceDataConstPtr device, UsbdmTclInterperPtr tclInterpreter) override;
   virtual DeviceDataConstPtr getDeviceData() override;
   virtual USBDM_ErrorCode    setTargetInterface(BdmInterfacePtr bdmInterface) override;

   virtual USBDM_ErrorCode    massEraseTarget()  override { return massEraseTarget(true); };
   virtual uint16_t           getCalculatedTrimValue()  override { return calculatedClockTrimValue; };
   virtual USBDM_ErrorCode    setFlashTrimValues(FlashImagePtr flashImage);

private:

   /**
    * Modifies the Security locations in the flash image according to required security options of flashRegion
    *
    * @param flashImage    Flash contents to be programmed.
    * @param flashRegion   The memory region involved (to determine security area if any)
    */
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion);

   /**
    * Modifies the Security locations in the flash image according to required security options
    *
    * @param flashImage  Flash image to be modified
    *
    * @return error code see \ref USBDM_ErrorCode.
    *
    * @note: This MUST be done after mass erase (if used) as target memory is checked!
    */
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage);

protected:

   /**
    * Restores the contents of the security areas to their saved values
    * All records are cleared
    *
    * @param flashImage    Flash contents to be programmed.
    */
   void restoreSecurityAreas(FlashImagePtr flashImage);

   /**
    * Class to modify and restore flash image in constructor/destructor
    */
   class SecurityModifier {
   private:
      FlashProgrammerCommon &programmer;
      FlashImagePtr         flashImage;
      USBDM_ErrorCode rc = PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;

   public:
      SecurityModifier(FlashProgrammerCommon &programmer, FlashImagePtr flashImage) :
         programmer(programmer), flashImage(flashImage) {
         rc = programmer.setFlashSecurity(flashImage);
      }

      ~SecurityModifier() {
         programmer.restoreSecurityAreas(flashImage);
      }

      USBDM_ErrorCode getRc() { return rc; }
   };

   static const int MaxSecurityAreaSize = 100;  //<! Maximum size of a security area that may be saved

   /**
    * Used to save a region of a flash image modified for security
    */
   struct SecurityDataCache {
      static const uint16_t BLANK = 0xFFFF;
      uint32_t address;                   //!< Start address of security area
      uint32_t size;                      //!< Size of area
      uint16_t data[MaxSecurityAreaSize]; //!< Security area data (BLANK indicates empty/invalid location)
   };

   /**
    * Class used to set/unset programming mode based on construction/destruction
    */
   class SetProgrammingMode {
   private:
      static bool currentMode;

      BdmInterfacePtr bdmInterface;
      bool            lastmode;

   public:
      SetProgrammingMode(BdmInterfacePtr bdmInterface) :
         bdmInterface(bdmInterface),
         lastmode(currentMode) {

         LOGGING_E;
         bdmInterface->setProgrammingMode(true);
         currentMode = true;
      }
      ~SetProgrammingMode() {
         LOGGING_E;
         bdmInterface->setProgrammingMode(lastmode);
         currentMode = lastmode;
      }
   };

   //! Structure for MCGCG parameters
   struct MCG_ClockParameters_t {
      uint8_t  mcgC1;
      uint8_t  mcgC2;
      uint8_t  mcgC3;
      uint8_t  mcgTrim;
      uint8_t  mcgSC;
      uint8_t  mcgCT;
   } ;
   //! Structure for ICGCG parameters
   struct ICG_ClockParameters_t {
      uint8_t  icgC1;        //!< ICSC1 value
      uint8_t  icgC2;        //!< ICSC1 value
      uint16_t icgFilter;    //!< Not used
      uint8_t  icgTrim;      //!< Trim value
   } ;
   //! Structure for ICSCG parameters
   struct ICS_ClockParameters_t {
      uint8_t  icsC1;        //!< ICSC1 value
      uint8_t  icsC2;        //!< ICSC2 value
      uint8_t  icsTrim;      //!< ICSTRM value
      uint8_t  icsSC;        //!< ICSSC value (FTRIM)
   } ;
   //! Structure for MKEICS parameters
   struct MKEICS_ClockParameters_t {
      uint8_t  scTrim;       //!< ICS_C3.SCTRIM
      uint8_t  scFtrim;      //!< ICS_C4.SCFTRIM
   } ;
   union ClockParameters {
      ICG_ClockParameters_t    icg;
      MCG_ClockParameters_t    mcg;
      ICS_ClockParameters_t    ics;
      MKEICS_ClockParameters_t mkeIcs;
   };

   USBDM_ErrorCode configureTargetClock(unsigned long *busFrequency);
   USBDM_ErrorCode dummyTrimLocations(FlashImagePtr flashImage);

   USBDM_ErrorCode configureICS_Clock(unsigned long *busFrequency, ICS_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureICG_Clock(unsigned long *busFrequency, ICG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureMCG_Clock(unsigned long *busFrequency, MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureExternal_Clock(unsigned long  *busFrequency);
   USBDM_ErrorCode trimTargetClock(
         uint32_t trimAddress, unsigned long targetBusFrequency, uint16_t *returnTrimValue,
         unsigned long *measuredBusFrequency, int do9BitTrim);
   USBDM_ErrorCode trimMKEICS_Clock(MKEICS_ClockParameters_t *clockParameters);
   USBDM_ErrorCode trimICS_Clock(ICS_ClockParameters_t *clockParameters);
   USBDM_ErrorCode trimMCG_Clock(MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode trimICG_Clock(ICG_ClockParameters_t *clockParameters);

   /**
    * Checks that there are no modified security areas
    *
    * @return error code if security areas are present
    */
   USBDM_ErrorCode checkNoSecurityAreas(void);

   /**
    * Record the original contents of a security area for later restoration
    *
    * @param flashImage Flash image meing manipulated
    * @param address    Start address of security area
    * @param size       Size of area
    *
    * @return error code see \ref USBDM_ErrorCode.
    */
   USBDM_ErrorCode recordSecurityArea(FlashImagePtr flashImage, const uint32_t address, const uint32_t size);
   bool                       flashReady;               //!< Safety check - only TRUE when flash is ready for programming
   DeviceDataConstPtr         device;                   //!< Parameters describing the current device
   UsbdmTclInterperPtr        tclInterpreter;           //!< TCL interpreter
   BdmInterfacePtr            bdmInterface;             //!< Target specific BDM interface
   FlashProgramConstPtr       currentFlashProgram;      //!< Current program for flash operation
   ProgressTimerPtr           progressTimer;            //!< Progress timer
   uint16_t                   calculatedClockTrimValue; //!< Clock trim value determined from programmed device
   unsigned                   securityAreaCount;
   SecurityDataCache          securityData[2];

   const DeviceData::EraseMethod   defaultEraseMethod;   //!< Default erase method if none found for device
   const DeviceData::ResetMethod   defaultResetMethod;   //!< Default reset method if none found for device

   uint32_t                ramStart; //!< Start of RAM region for programming
   uint32_t                ramEnd;   //!< End of RAM region for programming

   bool                    securityNeedsSelectiveErase;  //!< Indicates security area needs to be selectively erased

   static const char *getFlashOperationName(FlashOperation flashOperation);

   virtual USBDM_ErrorCode massEraseTarget(bool resetTarget) = 0;

   /**
    * Get erase method to use
    *
    * @return erase method
    */
   DeviceData::EraseMethod getEraseMethod();

   /**
    * Get reset method to use
    *
    * @return reset method
    */
   DeviceData::ResetMethod getResetMethod();

   /*
    * Initialises TCL support for current target
    */
   USBDM_ErrorCode initTCL();
   /*
    * Sets and initialises the TCL interpreter
    */
   USBDM_ErrorCode setTCLInterpreter(UsbdmTclInterperPtr ti);
   /*
    * Release the current TCL interpreter
    */
   USBDM_ErrorCode releaseTCL(void);
   /**
    * Executes a TCL command previously loaded in the TCL interpreter
    *
    * @param command Command to execute.  This would usually be the name of a TCL function.
    *                A non-zero return code is interpreted as an error and flagged
    *
    * @return  Error code
    */
   USBDM_ErrorCode runTCLCommand(const char *command);

   /**
    * Executes a TCL command previously loaded in the TCL interpreter
    *
    * @param command Command to execute.  This would usually be the name of a TCL function.
    * @param result  The return code is the result from the TCL command
    *
    * @return  Error code on failed execution
    */
   USBDM_ErrorCode runTCLCommandWithRc(const char *command, int &result);

   /*
    * Probe memory location to check if RAM
    */
   USBDM_ErrorCode probeMemory(MemorySpace_t memorySpace, uint32_t address);
};

#endif /* SRC_FLASHPROGRAMMERCOMMON_H_ */
