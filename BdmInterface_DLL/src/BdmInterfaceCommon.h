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
#include "USBDM_ErrorMessages.h"

class BdmInterfaceCommon: public BdmInterface {

private:
   static ModuleInfo moduleInfo;

public:
   BdmInterfaceCommon(TargetType_t targetType);
   virtual ~BdmInterfaceCommon();

   /**
    * Get reference to module specific information
    */
   virtual ModuleInfo                &getModuleInfo() const override { return moduleInfo; }

   virtual char const                *getErrorString(USBDM_ErrorCode rc) override;
   virtual char const                *getConnectionRetryName(RetryMode mode) override;

   virtual std::string                getDllVersionString() override;
   virtual unsigned int               getDllVersion() override;
   virtual std::string                getBdmVersionString() override;
   virtual USBDM_ErrorCode            getBdmInformation(USBDM_bdmInformation_t &information) override;

   virtual void                       setCallback(Callback callback) override;
   virtual void                       setConnectionTimeout(unsigned value) override;
   virtual unsigned                   getConnectionTimeout() override;
   virtual void                       setMaskISR(bool disableInterrupts) override;
   virtual bool                       isMaskISR(void) override;
   virtual void                       setCatchVLLSx(bool catchVLLSx) override;
   virtual bool                       isCatchVLLSx() const override;
   virtual void                       setExitOnClose(bool exitOnClose) override;
   virtual bool                       isExitOnClose() const override;
   virtual void                       setGdbServerPort(int port) override;
   virtual int                        getGdbServerPort() override;
   virtual void                       setGdbTtyPort(int port) override;
   virtual int                        getGdbTtyPort() override;

   virtual void                       loadSettings(const AppSettings &settings) override;
   virtual void                       saveSettings(AppSettings &settings) override;

   virtual USBDM_ErrorCode            findBDMs(std::vector<BdmInformation> &bdmInformation) override;
   virtual void                       setBdmSerialNumber(std::string serialNumber, bool matchRequired = false) override;
   virtual std::string               &getBdmSerialNumber() override;
   virtual bool                       getBdmMatchRequired() override;
   virtual USBDM_ErrorCode            initBdm(void) override;
   virtual USBDM_ErrorCode            closeBdm(void) override;
   virtual USBDM_ExtendedOptions_t   &getBdmOptions() override;
   virtual USBDM_ErrorCode            getDefaultBdmOptions(USBDM_ExtendedOptions_t *options) override;

   virtual USBDM_ErrorCode            getBDMStatus(USBDMStatus_t *usbdmStatus) override;
   virtual RetryMode                  getInitialConnectRetryMode() override;
   virtual RetryMode                  getSoftConnectRetryMode() override;
   virtual USBDM_ErrorCode            targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retry=retryAlways);
   virtual USBDM_ErrorCode            targetConnectWithRetry(RetryMode retry=retryAlways) override;
   virtual USBDM_ErrorCode            targetConnectWithDelayedConfirmation(RetryMode retryMode) override;
   virtual USBDM_ErrorCode            retryConnection(USBDMStatus_t *usbdmStatus) override;

   virtual USBDM_ErrorCode            setTargetVdd(TargetVddSelect_t targetVdd) override;
   virtual USBDM_ErrorCode            setTargetVpp(TargetVppSelect_t targetVpp) override;
   virtual USBDM_ErrorCode            controlPins(unsigned int control, unsigned int *status=0) override;
   virtual USBDM_ErrorCode            getCapabilities(HardwareCapabilities_t *capabilities) override;
   
   virtual USBDM_ErrorCode            reset(TargetMode_t mode) override;
   virtual USBDM_ErrorCode            connect() override;
   virtual USBDM_ErrorCode            basicConnect() override;
   virtual USBDM_ErrorCode            getSpeedHz(unsigned long int *speed) override;
   virtual USBDM_ErrorCode            setSpeedHz(unsigned long int speed) override;
   virtual USBDM_ErrorCode            halt() override;
   virtual USBDM_ErrorCode            go() override;
   virtual USBDM_ErrorCode            step() override;
   virtual USBDM_ErrorCode            readStatusReg(unsigned long *bdmStatus) override;
   virtual USBDM_ErrorCode            writeControlReg(unsigned int controlValue) override;
   virtual USBDM_ErrorCode            writeReg(unsigned int reg, unsigned long value) override;
   virtual USBDM_ErrorCode            writeCReg(unsigned int reg, unsigned long value) override;
   virtual USBDM_ErrorCode            writeDReg(unsigned int reg, unsigned long value) override;
   virtual USBDM_ErrorCode            readReg(unsigned int reg, unsigned long *value) override;
   virtual USBDM_ErrorCode            readCReg(unsigned int reg, unsigned long *value) override;
   virtual USBDM_ErrorCode            readDReg(unsigned int reg, unsigned long *value) override;
   virtual USBDM_ErrorCode            readMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data) override;
   virtual USBDM_ErrorCode            writeMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data) override;
   virtual USBDM_ErrorCode            writePC(unsigned long regValue) override;
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue) override;
   virtual USBDM_ErrorCode            bdmCommand(unsigned txSize, unsigned rxSize, uint8_t data[]) override;
   virtual USBDM_ErrorCode            readMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex) override;

   virtual USBDM_ErrorCode            jtagExecuteSequence(uint8_t length, const uint8_t *sequence, uint8_t inLength, uint8_t *inBuffer) override;
   virtual USBDM_ErrorCode            jtagRead( uint8_t bitCount, uint8_t exit, uint8_t *buffer) override;
   virtual USBDM_ErrorCode            jtagReadWrite( uint8_t bitCount, uint8_t exit, const uint8_t *outBuffer, uint8_t *inBuffer) override;
   virtual USBDM_ErrorCode            jtagReset() override;
   virtual USBDM_ErrorCode            jtagSelectShift(uint8_t mode) override;
   virtual USBDM_ErrorCode            jtagWrite(uint8_t bitCount, uint8_t exit, const uint8_t *buffer) override;

   virtual USBDM_ErrorCode            getIdcode(unsigned int *regValue) override;
   virtual USBDM_ErrorCode            getStatus(unsigned int *status) override;

   virtual USBDM_ErrorCode            setProgrammingMode(bool) override;

protected:
   USBDM_ExtendedOptions_t    bdmOptions;              //!< Current BDM options
   unsigned                   connectionTimeout;       //!< Timeout to use on GDB connection
   bool                       catchVLLSx;              //!< Indicates the target should halt on VLLSx resets
   std::string                bdmSerialNumber;         //!< Serial number of BDM to use
   bool                       bdmMatchRequired;        //!< If true then opened BDM must match serial number
   unsigned int               gdbServerPort;           //!< Port for GDB server
   unsigned int               ttyServerPort;           //!< Port for Semi-hosting TTY server connection
   bool                       exitOnClose;             //!< Indicates GDB server should exit when connection closed
   bool                       extendedRetry;           //!< Indicates if extend retries should be done

   Callback                   callbackPtr;             //!< Callback function for errors
   WxPluginPtr                wxPlugin;

   RetryMode                  initialConnectRetryMode;
   RetryMode                  softConnectRetryMode;

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
   USBDM_ErrorCode            setProgrammingBdmOptions();
   USBDM_ErrorCode            restoreBdmOptions();
};

#endif /* SRC_BDMINTERFACECOMMON_H_ */
