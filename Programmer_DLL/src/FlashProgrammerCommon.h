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
   FlashProgrammerCommon();
   virtual ~FlashProgrammerCommon();

   virtual USBDM_ErrorCode    setDeviceData(const DeviceDataConstPtr device);
   virtual USBDM_ErrorCode    setDeviceData(const DeviceDataConstPtr device, UsbdmTclInterperPtr tclInterpreter);
   virtual DeviceDataConstPtr getDeviceData();
   virtual USBDM_ErrorCode    setTargetInterface(BdmInterfacePtr bdmInterface);

   virtual USBDM_ErrorCode    massEraseTarget() { return massEraseTarget(true); };
   virtual uint16_t           getCalculatedTrimValue() { return calculatedClockTrimValue; };

protected:

   class SetProgrammingMode {
   private:
      BdmInterfacePtr bdmInterface;
   public:
      SetProgrammingMode(BdmInterfacePtr bdmInterface) :
      bdmInterface(bdmInterface) {
         LOGGING_E;
         bdmInterface->setProgrammingMode(true);
      }
      ~SetProgrammingMode() {
         LOGGING_E;
         bdmInterface->setProgrammingMode(false);
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
   union ClockParameters {
      ICG_ClockParameters_t icg;
      MCG_ClockParameters_t mcg;
      ICS_ClockParameters_t ics;
   };

   USBDM_ErrorCode setFlashTrimValues(FlashImagePtr flashImage);
   USBDM_ErrorCode configureTargetClock(unsigned long *busFrequency);
   USBDM_ErrorCode dummyTrimLocations(FlashImagePtr flashImage);

   USBDM_ErrorCode configureICS_Clock(unsigned long *busFrequency, ICS_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureICG_Clock(unsigned long *busFrequency, ICG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureMCG_Clock(unsigned long *busFrequency, MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureExternal_Clock(unsigned long  *busFrequency);
   USBDM_ErrorCode trimTargetClock(uint32_t trimAddress, unsigned long targetBusFrequency, uint16_t *returnTrimValue,
         unsigned long *measuredBusFrequency, int do9BitTrim);
   USBDM_ErrorCode trimICS_Clock(ICS_ClockParameters_t *clockParameters);
   USBDM_ErrorCode trimMCG_Clock(MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode trimICG_Clock(ICG_ClockParameters_t *clockParameters);
   
   bool                    flashReady;               //!< Safety check - only TRUE when flash is ready for programming
   DeviceDataConstPtr      device;                   //!< Parameters describing the current device
   UsbdmTclInterperPtr     tclInterpreter;           //!< TCL interpreter
   BdmInterfacePtr         bdmInterface;             //!< Target specific BDM interface
   FlashProgramConstPtr    currentFlashProgram;      //!< Current program for flash operation
   ProgressTimerPtr        progressTimer;            //!< Progress timer
   uint16_t                calculatedClockTrimValue; //!< Clock trim value determined from programmed device

   static const char *getFlashOperationName(FlashOperation flashOperation);

   virtual USBDM_ErrorCode massEraseTarget(bool resetTarget) = 0;

   //=======================================================================
   // Initialises TCL support for current target
   //
   USBDM_ErrorCode initTCL(void);
   //=======================================================================
   // Sets and initialises the TCL interpreter
   //
   USBDM_ErrorCode setTCLInterpreter(UsbdmTclInterperPtr ti);
   //=======================================================================
   //  Release the current TCL interpreter
   //
   USBDM_ErrorCode releaseTCL(void);
   //=======================================================================
   // Executes a TCL script in the current TCL interpreter
   //
   USBDM_ErrorCode runTCLScript(TclScriptConstPtr script);
   //=======================================================================
   // Executes a TCL command previously loaded in the TCL interpreter
   //
   USBDM_ErrorCode runTCLCommand(const char *command);

   USBDM_ErrorCode probeMemory(MemorySpace_t memorySpace, uint32_t address);
};

#endif /* SRC_FLASHPROGRAMMERCOMMON_H_ */
