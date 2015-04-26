/*!
 * \brief Header file for CmdTable.c
*/
#ifndef _NAMES_H_
#define _NAMES_H_

#include "USBDM_API.h"
#include "USBDM_DSC_API.h"

#include "DeviceData.h"

#if defined(LOG) || defined(NEED_ALL_NAMES)
char const *getCommandName(unsigned char command);
char const *getDebugCommandName(unsigned char cmd);
char const *getDFUCommandName(unsigned char command);
char const *getCFV1RegName( unsigned int regAddr );
char const *getCFVxRegName( unsigned int regAddr );
char const *getARMRegName( unsigned int regAddr );
char const *getHCS12RegName( unsigned int regAddr );
char const *getS12ZRegName( unsigned int regAddr );
char const *getHCS08RegName( unsigned int regAddr );
char const *getRS08RegName( unsigned int regAddr );
char const *getDSCRegName( unsigned int regAddr);
char const *getRegName( unsigned int targetType, unsigned int regAddr );
char const *getHCS12DebugRegName( unsigned int regAddr );
char const *getCFV1DebugRegName( unsigned int regAddr );
char const *getCFVxDebugRegName( unsigned int regAddr );
char const *getSWDDebugRegName( unsigned int regAddr );
char const *getCFV1ControlRegName( unsigned int regAddr );
char const *getCFVxControlRegName( unsigned int regAddr );
char const *getARMControlRegName( unsigned int regAddr );
char const *getRS08_BDCSCR_Name( unsigned int BDCSCR);
char const *getHCS08_BDCSCR_Name( unsigned int BDCSCR);
char const *getHCS12ZVM_BDMSTS_Name( unsigned int BDMSTS);
char const *getHCS12_BDMSTS_Name( unsigned int BDMSTS);
char const *getCFV1_XCSR_Name( unsigned int XCSR);
char const *getCFVx_CSR_Name( unsigned int CSR);
char const *getStatusRegName(unsigned int targetType, unsigned int value);
char const *getCapabilityName(unsigned int cmd);
char const *getControlLevelName(InterfaceLevelMasks_t level);
char const *getClockSelectName(ClkSwValues_t level);
char const *getVoltageStatusName(TargetVddState_t level);
char const *getVoltageSelectName(TargetVddSelect_t level);
char const *getVppSelectName(TargetVppSelect_t level);
char const *getPinLevelName(PinLevelMasks_t level);
char const *getExitAction(int action);
char const *getDHCSRName(uint32_t dhcsrValue);
char const *getDEMCRName(uint32_t demcrValue);
char const *getMDM_APControlName(uint32_t mdmApValue);
char const *getMDM_APStatusName(uint32_t mdmApValue);
char const *getARM_CTRL_STATUSRName(uint32_t value);
char const *getAutoConnectName(AutoConnect_t mode);
char const *getMemSpaceName(MemorySpace_t memSpace);
char const *getMemSpaceAbbreviatedName(MemorySpace_t memSpace);
char const *getStatusRegName(unsigned int targetType, unsigned int value);
const char *getSRSLName(uint32_t srslValue);
const char *getSRSHName(uint32_t srshValue);
const char *printBdmOptions(const USBDM_ExtendedOptions_t *options);
const char *getOnceStatusName(int status);

#else // defined(LOG) || defined(NEED_ALL_NAMES)
// Dummy the routines if logging is not required
static inline char const *getCommandName(unsigned char command)                         { return ""; }
static inline char const *getDebugCommandName(unsigned char cmd)                        { return ""; }
static inline char const *getRS08RegName( unsigned int regAddr )                        { return ""; }
static inline char const *getDSCRegName( unsigned int regAddr)                          { return ""; }
static inline char const *getHCS08RegName( unsigned int regAddr )                       { return ""; }
static inline char const *getHCS12RegName( unsigned int regAddr )                       { return ""; }
static inline char const *getCFV1RegName( unsigned int regAddr )                        { return ""; }
static inline char const *getCFVxRegName( unsigned int regAddr )                        { return ""; }
static inline char const *getARMRegName( unsigned int regAddr )                         { return ""; }
static inline char const *getRegName( unsigned int targetType, unsigned int regAddr )   { return ""; }
static inline char const *getHCS12DebugRegName( unsigned int regAddr )                  { return ""; }
static inline char const *getCFV1DebugRegName( unsigned int regAddr )                   { return ""; }
static inline char const *getCFVxDebugRegName( unsigned int regAddr )                   { return ""; }
static inline char const *getSWDDebugRegName( unsigned int regAddr )                    { return ""; }
static inline char const *getCFV1ControlRegName( unsigned int regAddr )                 { return ""; }
static inline char const *getCFVxControlRegName( unsigned int regAddr )                 { return ""; }
static inline char const *getARMControlRegName( unsigned int regAddr )                  { return ""; }
static inline char const *getSWDControlRegName( unsigned int regAddr )                  { return ""; }
static inline char const *getRS08_BDCSCR_Name( unsigned int BDCSCR)                     { return ""; }
static inline char const *getHCS08_BDCSCR_Name( unsigned int BDCSCR)                    { return ""; }
static inline char const *getHCS12_BDMSTS_Name( unsigned int BDMSTS)                    { return ""; }
static inline char const *getCFV1_XCSR_Name( unsigned int XCSR)                         { return ""; }
static inline char const *getCFVx_CSR_Name( unsigned int CSR)                           { return ""; }
static inline char const *getStatusRegName(unsigned int targetType, unsigned int value) { return ""; }
static inline char const *getCapabilityName(unsigned int vector)                        { return ""; }
static inline char const *getControlLevelName(InterfaceLevelMasks_t level)              { return ""; }
static inline char const *getClockSelectName(ClkSwValues_t level)                       { return ""; }
static inline char const *getVoltageSelectName(TargetVddSelect_t level)                 { return ""; }
static inline char const *getVppSelectName(TargetVppSelect_t level)                     { return ""; }
static inline char const *getPinLevelName(PinLevelMasks_t level)                        { return ""; }
static inline char const *getExitAction(int action)                                     { return ""; }
static inline char const *getMemSpaceName(MemorySpace_t memSpace)                       { return ""; }
static inline const char *getMemSpaceAbbreviatedName(MemorySpace_t memSpace)            { return ""; }
static inline const char *getDHCSRName(uint32_t dhcsrValue)                             { return ""; }
static inline const char *getDEMCRName(uint32_t demcrValue)                             { return ""; }
static inline char const *getMDM_APControlName(uint32_t mdmApValue)                     { return ""; }
static inline char const *getMDM_APStatusName(uint32_t mdmApValue)                      { return ""; }
static inline char const *getARM_CTRL_STATUSRName(uint32_t demcrValue)                  { return ""; }
static inline char const *getS12ZRegName( unsigned int regAddr )                        { return ""; }
static inline char const *getSRSLName(uint32_t srslValue)                               { return ""; }
static inline char const *getSRSHName(uint32_t srshValue)                               { return ""; }
static inline char const *printBdmOptions(const USBDM_ExtendedOptions_t *options)       { return ""; }
static inline char const *getOnceStatusName(int status)                                 { return ""; }
#endif

char const *getTargetModeName(TargetMode_t type);
char const *getHardwareDescription(unsigned int hardwareVersion);
char const *getBriefHardwareDescription(unsigned int hardwareVersion);
char const *getTargetTypeName( unsigned int type );
char const *getBDMStatusName(USBDMStatus_t *USBDMStatus);
char const *getICPErrorName(unsigned char error);
char const *getConnectionStateName(SpeedMode_t level);
char const *getSecurityName(SecurityOptions_t level);

#endif // _NAMES_H_
