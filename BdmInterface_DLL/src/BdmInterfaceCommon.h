/*
 * BdmInterfaceCommon.h
 *
 *  Created on: 12 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACECOMMON_H_
#define SRC_BDMINTERFACECOMMON_H_

#include "BdmInterface.h"
#include "WxPluginFactory.h"

class BdmInterfaceCommon: public BdmInterface {

public:
   BdmInterfaceCommon(TargetType_t targetType);
   virtual ~BdmInterfaceCommon();

   virtual char const                *getErrorString(USBDM_ErrorCode rc);
   virtual char const                *getConnectionRetryName(RetryMode mode);

   virtual std::string                getDllVersionString();
   virtual unsigned int               getDllVersion();
   virtual std::string                getBdmVersionString();
   virtual USBDM_ErrorCode            getBdmInformation(USBDM_bdmInformation_t &information);

   virtual void                       setCallback(Callback callback);
   virtual void                       setConnectionTimeout(unsigned value);
   virtual unsigned                   getConnectionTimeout();
   virtual void                       setMaskISR(bool disableInterrupts);
   virtual bool                       isMaskISR(void);
   virtual void                       setCatchVLLSx(bool catchVLLSx);
   virtual bool                       isCatchVLLSx() const;
   virtual void                       setExitOnClose(bool exitOnClose);
   virtual bool                       isExitOnClose() const;
   virtual void                       setGdbServerPort(int port);
   virtual int                        getGdbServerPort();

   virtual void                       loadSettings(const AppSettings &settings);
   virtual void                       saveSettings(AppSettings &settings);

   virtual USBDM_ErrorCode            findBDMs(std::vector<BdmInformation> &bdmInformation);
   virtual void                       setBdmSerialNumber(std::string serialNumber, bool matchRequired = false);
   virtual std::string               &getBdmSerialNumber();
   virtual bool                       getBdmMatchRequired();
   virtual USBDM_ErrorCode            initBdm(void);
   virtual USBDM_ErrorCode            closeBdm(void);
   virtual USBDM_ExtendedOptions_t   &getBdmOptions();

   virtual USBDM_ErrorCode            getBDMStatus(USBDMStatus_t *usbdmStatus);

   virtual USBDM_ErrorCode            targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retry=retryAlways);
   virtual USBDM_ErrorCode            targetConnectWithRetry(RetryMode retry=retryAlways);
   virtual USBDM_ErrorCode            targetConnectWithDelayedConfirmation(RetryMode retryMode);
   virtual USBDM_ErrorCode            retryConnection(USBDMStatus_t *usbdmStatus);

   virtual USBDM_ErrorCode            setTargetVdd(TargetVddSelect_t targetVdd);
   virtual USBDM_ErrorCode            setTargetVpp(TargetVppSelect_t targetVpp);
   virtual USBDM_ErrorCode            controlPins(unsigned int control, unsigned int *status=0);
   virtual USBDM_ErrorCode            getCapabilities(HardwareCapabilities_t *capabilities);
   
   virtual USBDM_ErrorCode            reset(TargetMode_t mode);
   virtual USBDM_ErrorCode            connect();
   virtual USBDM_ErrorCode            getSpeedHz(unsigned long int *speed);
   virtual USBDM_ErrorCode            setSpeedHz(unsigned long int speed);
   virtual USBDM_ErrorCode            halt();
   virtual USBDM_ErrorCode            go();
   virtual USBDM_ErrorCode            step();
   virtual USBDM_ErrorCode            readStatusReg(unsigned long *bdmStatus);
   virtual USBDM_ErrorCode            writeControlReg(unsigned int controlValue);
   virtual USBDM_ErrorCode            writeReg(unsigned int reg, unsigned long value);
   virtual USBDM_ErrorCode            writeCReg(unsigned int reg, unsigned long value);
   virtual USBDM_ErrorCode            writeDReg(unsigned int reg, unsigned long value);
   virtual USBDM_ErrorCode            readReg(unsigned int reg, unsigned long *value);
   virtual USBDM_ErrorCode            readCReg(unsigned int reg, unsigned long *value);
   virtual USBDM_ErrorCode            readDReg(unsigned int reg, unsigned long *value);
   virtual USBDM_ErrorCode            readMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data);
   virtual USBDM_ErrorCode            writeMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data);
   virtual USBDM_ErrorCode            writePC(unsigned long regValue);
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue);
   virtual USBDM_ErrorCode            bdmCommand(unsigned txSize, unsigned rxSize, uint8_t data[]);
   virtual USBDM_ErrorCode            readMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex);

   virtual USBDM_ErrorCode            jtagExecuteSequence(uint8_t length, const uint8_t *sequence, uint8_t inLength, uint8_t *inBuffer);
   virtual USBDM_ErrorCode            jtagRead( uint8_t bitCount, uint8_t exit, uint8_t *buffer);
   virtual USBDM_ErrorCode            jtagReadWrite( uint8_t bitCount, uint8_t exit, const uint8_t *outBuffer, uint8_t *inBuffer);
   virtual USBDM_ErrorCode            jtagReset();
   virtual USBDM_ErrorCode            jtagSelectShift(uint8_t mode);
   virtual USBDM_ErrorCode            jtagWrite(uint8_t bitCount, uint8_t exit, const uint8_t *buffer);

   virtual USBDM_ErrorCode            getIdcode(unsigned int *regValue);
   virtual USBDM_ErrorCode            getStatus(unsigned int *status);

protected:
   USBDM_ExtendedOptions_t    bdmOptions;              //!< Current BDM options
   unsigned                   connectionTimeout;       //!< Timeout to use on GDB connection
   bool                       catchVLLSx;              //!< Indicates the target should halt on VLLSx resets
   std::string                bdmSerialNumber;         //!< Serial number of BDM to use
   bool                       bdmMatchRequired;        //!< If true then opened BDM must match serial number
   unsigned int               gdbServerPort;           //!< Port for GDB server
   bool                       exitOnClose;             //!< Indicates GDB server should exit when connection closed
   bool                       extendedRetry;           //!< Indicates if extend retries should be done

   Callback                   callbackPtr;             //!< Callback function for errors
   WxPluginPtr                wxPlugin;

protected:
   long                       callback(std::string message, std::string  caption, long style);

   USBDM_ErrorCode            readBDMSerialNumber(std::string &serialNumber);
   USBDM_ErrorCode            readBDMDescription(std::string &description);

   USBDM_ErrorCode            openBySerialNumber(const std::string &serialnumber, bool mustMatch = false);
   USBDM_ErrorCode            openBySerialNumberWithRetry(const std::string &serialnumber, bool mustMatch = false);
   USBDM_ErrorCode            setOptionsWithRetry(USBDM_ExtendedOptions_t *bdmOptions);
   USBDM_ErrorCode            setTargetTypeWithRetry();
   int                        handleError(USBDM_ErrorCode rc);
   USBDM_ErrorCode            probeMemory(MemorySpace_t memorySpace, uint32_t address);

};

#endif /* SRC_BDMINTERFACECOMMON_H_ */
