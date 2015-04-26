/*
 * Shared.cpp
 *
 *  Created on: 18/12/2012
 *      Author: PODonoghue
 */

#ifndef BDM_INTERFACE_H
#define BDM_INTERFACE_H

#include <tr1/memory>
#include <string.h>
#include <vector>
#include <stdint.h>

#include "USBDM_API.h"
#include "AppSettings.h"
#include "BdmInformation.h"

class BdmInterface {

public:
   typedef long (*Callback)(std::string message, std::string  caption, long style);

   enum RetryMode {
      retryMask            = 0x0F,     // Mask for basic options
      retryAlways          = 0,        // Always retry - on error the user has already been informed.
      retryNever           = 1,        // Never retry - the user has not been informed of any error (quiet)
      retryNotPartial      = 2,        // Don't retry on partial connection (BDM_RC_SECURED,BDM_RC_BDM_EN_FAILED)
      retryByReset         = (1<<4),   // Retry silently using reset if necessary (if supported by target to entry debug mode)
      retryByPower         = (1<<5),   // Retry by cycling BDM controlled power & prompting user
      retryWithInit        = (1<<6),   // Option for ARM & DSC - do DSC/ARM_Initialise() first
      retryDelayedCheck    = (1<<8),   // Delay check for connection after sync
      //   retryWithReset = (1<<7),  // Immediately reset to special mode - useful to avoid Watchdog timeout
   };

   enum {
      OPTIONS_NO_CONFIG_DISPLAY = 0x00001,
   };

protected:
   BdmInterface() {};

public:
   virtual ~BdmInterface() {};

   // Returns pointer to static string
   virtual char const                *getErrorString(USBDM_ErrorCode rc) = 0;
   virtual char const                *getConnectionRetryName(RetryMode mode) = 0;

   virtual std::string                getDllVersionString() = 0;
   virtual unsigned int               getDllVersion() = 0;
   virtual std::string                getBdmVersionString() = 0;
   virtual USBDM_ErrorCode            getBdmInformation(USBDM_bdmInformation_t &information) = 0;

   virtual void                       setCallback(Callback callback) = 0;
   virtual void                       setConnectionTimeout(unsigned value) = 0;
   virtual unsigned                   getConnectionTimeout() = 0;
   virtual void                       setMaskISR(bool disableInterrupts) = 0;
   virtual bool                       isMaskISR(void) = 0;
   virtual void                       setCatchVLLSx(bool catchVLLSx) = 0;
   virtual bool                       isCatchVLLSx() const = 0;
   virtual void                       setExitOnClose(bool exitOnClose) = 0;
   virtual bool                       isExitOnClose() const = 0;
   virtual void                       setGdbServerPort(int port) = 0;
   virtual int                        getGdbServerPort() = 0;

   virtual void                       loadSettings(const AppSettings &settings) = 0;
   virtual void                       saveSettings(AppSettings &settings) = 0;

   virtual USBDM_ErrorCode            findBDMs(std::vector<BdmInformation> &bdmInformation) = 0;
   virtual void                       setBdmSerialNumber(std::string serialNumber, bool matchRequired = false) = 0;
   virtual std::string               &getBdmSerialNumber() = 0;
   virtual bool                       getBdmMatchRequired() = 0;
   virtual USBDM_ErrorCode            initBdm(void) = 0;
   virtual USBDM_ErrorCode            closeBdm(void) = 0;
   virtual USBDM_ExtendedOptions_t   &getBdmOptions() = 0;

   virtual USBDM_ErrorCode            getBDMStatus(USBDMStatus_t *usbdmStatus) = 0;

//   virtual USBDM_ErrorCode            targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retry=retryAlways) = 0;
   virtual USBDM_ErrorCode            targetConnectWithRetry(RetryMode retry=retryAlways) = 0;
   virtual USBDM_ErrorCode            targetConnectWithDelayedConfirmation(RetryMode retryMode) = 0;
   virtual USBDM_ErrorCode            retryConnection(USBDMStatus_t *usbdmStatus) = 0;

   // Low-level
   virtual USBDM_ErrorCode            setTargetVdd(TargetVddSelect_t targetVdd) = 0;
   virtual USBDM_ErrorCode            setTargetVpp(TargetVppSelect_t targetVpp) = 0;
   virtual USBDM_ErrorCode            controlPins(unsigned int control, unsigned int *status=0) = 0;
   virtual USBDM_ErrorCode            getCapabilities(HardwareCapabilities_t *capabilities) = 0;
   
   virtual USBDM_ErrorCode            reset(TargetMode_t mode) = 0;
   virtual USBDM_ErrorCode            connect() = 0;
   virtual USBDM_ErrorCode            getSpeedHz(unsigned long int *speed) = 0;
   virtual USBDM_ErrorCode            setSpeedHz(unsigned long int speed) = 0;
   virtual USBDM_ErrorCode            halt() = 0;
   virtual USBDM_ErrorCode            go() = 0;
   virtual USBDM_ErrorCode            step() = 0;
   virtual USBDM_ErrorCode            readStatusReg(unsigned long *bdmStatus) = 0;
   virtual USBDM_ErrorCode            writeControlReg(unsigned int controlValue) = 0;
   virtual USBDM_ErrorCode            writeReg(unsigned int reg, unsigned long value)  = 0;
   virtual USBDM_ErrorCode            writeCReg(unsigned int reg, unsigned long value) = 0;
   virtual USBDM_ErrorCode            writeDReg(unsigned int reg, unsigned long value) = 0;
   virtual USBDM_ErrorCode            readReg(unsigned int reg, unsigned long *value)  = 0;
   virtual USBDM_ErrorCode            readCReg(unsigned int reg, unsigned long *value) = 0;
   virtual USBDM_ErrorCode            readDReg(unsigned int reg, unsigned long *value) = 0;
   virtual USBDM_ErrorCode            readMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data) = 0;
   virtual USBDM_ErrorCode            writeMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data) = 0;
   virtual USBDM_ErrorCode            writePC(unsigned long regValue) = 0;
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue) = 0;
   virtual USBDM_ErrorCode            bdmCommand(unsigned txSize, unsigned rxSize, uint8_t data[]) = 0;
   virtual USBDM_ErrorCode            readMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex) = 0;

   // JTAG
   virtual USBDM_ErrorCode            jtagExecuteSequence(uint8_t length, const uint8_t *sequence, uint8_t inLength, uint8_t *inBuffer) = 0;
   virtual USBDM_ErrorCode            jtagRead( uint8_t bitCount, uint8_t exit, uint8_t *buffer) = 0;
   virtual USBDM_ErrorCode            jtagReadWrite( uint8_t bitCount, uint8_t exit, const uint8_t *outBuffer, uint8_t *inBuffer) = 0;
   virtual USBDM_ErrorCode            jtagReset() = 0;
   virtual USBDM_ErrorCode            jtagSelectShift(uint8_t mode) = 0;
   virtual USBDM_ErrorCode            jtagWrite(uint8_t bitCount, uint8_t exit, const uint8_t *buffer) = 0;

   virtual USBDM_ErrorCode            getIdcode(unsigned int *regValue) = 0;
   virtual USBDM_ErrorCode            getStatus(unsigned int *status) = 0;

};

typedef std::tr1::shared_ptr<BdmInterface> BdmInterfacePtr;

#endif /* BDM_INTERFACE_H */
