/*! \file
    \brief Header file for BdmInterface

    \verbatim
    Copyright (C) 2010  Peter O'Donoghue

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
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/

#ifndef BDM_INTERFACE_H
#define BDM_INTERFACE_H

#include <memory>
#include <string.h>
#include <vector>
#include <stdint.h>

#include "USBDM_API.h"
#include "AppSettings.h"
#include "BdmInformation.h"
#include "ModuleInfo.h"

/**
 * Class representing an interface to the BDM for a particular device type
 */
class BdmInterface {

public:
   /**
    * Callback prototype
    *
    * A function confirming to this prototype may be provided to the interface.\n
    * The function will be called to determine actions to take on an error condition.\n
    *
    * May display a dialogue for user response to error.\n
    * Should return UsbdmWxConstants value\n
    *
    * A return value of UsbdmWxConstants::NO will mean to abort operation.
    */
   typedef long (*Callback)(std::string message, std::string  caption, long style);

   /**
    * Indicates action to take when connection fails.
    */
   enum RetryMode {
      retryMask            = 0x0F,     //!< Mask for basic options
      retryAlways          = 0,        //!< Always retry - on error the user has already been informed.
      retryNever           = 1,        //!< Never retry - the user has not been informed of any error (quiet)
      retryNotPartial      = 2,        //!< Don't retry on partial connection (BDM_RC_SECURED,BDM_RC_BDM_EN_FAILED)
      retryByReset         = (1<<4),   //!< Retry silently using reset if necessary (if supported by target to entry debug mode)
      retryByPower         = (1<<5),   //!< Retry by cycling BDM controlled power & prompting user
      retryWithInit        = (1<<6),   //!< Option for ARM & DSC - do DSC/ARM_Initialise() first
      retryDelayedCheck    = (1<<8),   //!< Delay check for connection after sync
//    retryWithReset       = (1<<7),   //!< Immediately reset to special mode - useful to avoid Watchdog timeout
   };

   /**
    * Indicates action to take when connection fails.
    */
   enum {
      OPTIONS_NO_CONFIG_DISPLAY = 0x00001,
   };

protected:
   /**
    * Protected constructor
    */
   BdmInterface() {};

public:
   virtual ~BdmInterface() {};

   /**
    * Get reference to module specific information
    */
   virtual ModuleInfo                &getModuleInfo() const = 0;

  /**
   * Gets string describing a USBDM error code
   *
   * @param rc - error code returned from USBDM API routine.
   *
   * @return pointer to static string describing the error.
   */
   virtual char const                *getErrorString(USBDM_ErrorCode rc) = 0;

  /**
   * Gets string describing connection strategy
   *
   * @param mode - Retry mode to describe
   *
   * @return pointer to static string describing the strategy.
   */
   virtual char const                *getConnectionRetryName(RetryMode mode) = 0;

  /**
   * Get descriptive version of the USBDM interface DLL
   *
   * @return description of the USBDM version
   */
   virtual std::string                getDllVersionString() = 0;

  /**
   * Get version of the USBDM interface DLL
   *
   *  @return version number (e.g. V4.9.5 => 0x40905)
   */
   virtual unsigned int               getDllVersion() = 0;

  /**
   * Gets BDM software version and type of hardware
   *
   *  @return description of the USBDM version
   */
   virtual std::string                getBdmVersionString() = 0;

  /**
   * Obtains information about the currently open BDM interface
   *
   *  @param information ptr to structure to contain the information
   *
   *  @return
   *      BDM_RC_OK => OK \n
   *      other     => Error code - see \ref USBDM_ErrorCode
   *
   *  @note The size element of information should be initialised before call.
   *  @note Uses cached information from when the BDM was opened.
   */
   virtual USBDM_ErrorCode            getBdmInformation(USBDM_bdmInformation_t &information) = 0;

   /**
    * Set callback used on errors
    *
    * @param callback - Callback function to use in case of errors (may be NULL)
    *
    * @note If a NULL callback is set then an internal GUI dialogue is used to query the user for action
    */
   virtual void                       setCallback(Callback callback) = 0;

   /**
    * Set Connection timeout
    *
    * @param value - How long to wait for an unresponsive target
    */
   virtual void                       setConnectionTimeout(unsigned value) = 0;

   /**
    * Get connection timeout value
    *
    * @return timeout in seconds
    */
   virtual unsigned                   getConnectionTimeout() = 0;

   /**
    * The interface sets options to cause the target to ignore interrupts when stepping.
    *
    * @param disableInterrupts TRUE to disable interrupts when stepping
    *
    */
   virtual void                       setMaskISR(bool disableInterrupts) = 0;

   /**
    * Indicates if the target is ignoring interrupts when stepping
    *
    * @return MaskISR value
    */
   virtual bool                       isMaskISR() = 0;

   /**
    * Targets recovering from VLLSx suspend go throug ha reset sequence.
    * Setting this option the BDM attempts to halt during the reset recovery
    *
    * @param  catchVLLSx TRUE to capture resets
    */
   virtual void                       setCatchVLLSx(bool catchVLLSx) = 0;

   /**
    * Indicates if catch VLLSx is active
    *
    * @return catch VLLSx value
    */
   virtual bool                       isCatchVLLSx() const = 0;

   /**
    * Sets option to close GDB server when the session ends
    *
    * @param  exitOnClose TRUE to exit GDB on session closure
    */
   virtual void                       setExitOnClose(bool exitOnClose) = 0;

   /**
    * Indicates if GDB session closure ends the GDB server
    */
   virtual bool                       isExitOnClose() const = 0;
   /**
    * Set port number for GDB server to monitor
    *
    * @param port Port number
    */
   virtual void                       setGdbServerPort(int port) = 0;
   /**
    * Get port number that GDB server monitors
    *
    * @return Port number
    */
   virtual int                        getGdbServerPort() = 0;
   /**
    * Set port number that TTY connection is to use
    *
    * @param port Port number
    */
   virtual void                       setGdbTtyPort(int port) = 0;
   /**
    * Gets port number that TTY connection is to use
    *
    * @return Port number
    */
   virtual int                        getGdbTtyPort() = 0;
   /**
    * Load setting from settings object
    *
    * @param settings Settings object to use
    */
   virtual void                       loadSettings(const AppSettings &settings) = 0;

   /**
    * Save settings to settings object
    *
    * @param settings Settings object to use
    */
   virtual void                       saveSettings(AppSettings &settings) = 0;

   /**
    * Locate connected BDMs
    *
    * @param bdmInformation vector containing description of BDMs
    *
    * @return error code, 0 on success
    */
   virtual USBDM_ErrorCode            findBDMs(std::vector<BdmInformation> &bdmInformation) = 0;

   /**
    * Set serial number of BDM to use
    *
    * @param serialNumber  Serial number of preferred or required BDM
    * @param matchRequired If set, the opened BDM must have the given serial number, otherwise
    *                      the serial number is treated as a preferred BDM
    */
   virtual void                       setBdmSerialNumber(const std::string serialNumber, bool matchRequired = false) = 0;

   /**
    * Get serial number of preferred/required BDM
    *
    * @return serial number
    */
   virtual std::string               &getBdmSerialNumber() = 0;

   /**
    * Indicates if the serial number must match when being opened
    *
    * @return serial number
    */
   virtual bool                       getBdmMatchRequired() = 0;

   /**
    *  Opens & initialises the currently selected BDM (based on serial number)
    *
    *  Entry - Assumes .bdmInformation contains required information
    *
    *  @return Error code indicating outcome.  The dialogue callback is used on any error
    */
   virtual USBDM_ErrorCode            initBdm() = 0;

   /**
    *  Close BDM
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode            closeBdm() = 0;

   /**
    * Get a reference to the internal BDM options
    *
    *  @return Reference to BDM options
    */
   virtual USBDM_ExtendedOptions_t   &getBdmOptions() = 0;

   /**
    * Get a default set of BDM options
    *
    *  @param options - structure to hold options
    *
    *  @return Error code indicating outcome.
    */
   virtual USBDM_ErrorCode getDefaultBdmOptions(USBDM_ExtendedOptions_t *options) = 0;

   /**
    * Get BDMStatus (HCS/CF interface only)
    *
    * @param usbdmStatus BDM status
    *
    * @return error code
    */
   virtual USBDM_ErrorCode            getBDMStatus(USBDMStatus_t *usbdmStatus) = 0;

   /**
    * Get retry mode to use for initial target connection
    *  Only available after initBdm()
    *
    * @return Retry mode
    */
   virtual RetryMode getInitialConnectRetryMode() = 0;

   /**
    * Get retry mode to use for usual (re-connect) target connection
    *  Only available after initBdm()
    *
    * @return Retry mode
    */
   virtual RetryMode getSoftConnectRetryMode() = 0;

  /**
   * Connects to Target (RS08/HCS08/HCS12/CFV1/CFVx only)
   *
   *  @note If there are connection problems, the user may be prompted to cycle
   *        the target power on some targets.
   *
   *  @param retryMode   How hard to retry \n
   *      The following are silent retries: \n
   *        retryNever      - give up after basic attempt, target state not affected \n
   *       +retryByReset    - quietly retry after hardware reset (if supported by target and allows debug entry). May be combined with others. \n
   *        retryNotPartial - give up quietly if device may be secured (BDM_RC_SECURED or BDM_RC_BDM_EN_FAILED) \n
   *      The following is interactive:\n
   *        retryAlways     - retry with dialogue prompt to user \n
   *
   *  @return
   *      BDM_RC_OK => OK \n
   *      other     => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            targetConnectWithRetry(RetryMode retryMode=retryAlways) = 0;

  /**
   * Connect to target with a delayed check
   *
   *  @param retryMode   How hard to retry \n
   *      The following are silent retries: \n
   *        retryNever      - give up after basic attempt, target state not affected \n
   *       +retryByReset    - quietly retry after hardware reset (if supported by target and allows debug entry). May be combined with others. \n
   *        retryNotPartial - give up quietly if device may be secured (BDM_RC_SECURED or BDM_RC_BDM_EN_FAILED) \n
   *      The following is interactive:\n
   *        retryAlways     - retry with dialogue prompt to user \n
   *
   *  @note - The delayed check is to help detect watch-dog timeouts that can cause the
   *          BDM to get a connection but then loose it before anything useful can be done.
   *
   *  @return
   *      DI_OK                  => OK \n
   *      BDM_RC_BDM_EN_FAILED   => Usually indicates an initial connection that is lost before re-check
   *      other                  => Some other more varied error
   */
   virtual USBDM_ErrorCode            targetConnectWithDelayedConfirmation(RetryMode retryMode) = 0;

  /**
   * Releases reset etc using correct Special Mode sequence and then retries connection
   *
   *  @return
   *      DI_OK                  => OK \n
   *      BDM_RC_BDM_EN_FAILED   => Usually indicates an initial connection that is lost before re-check
   *      other                  => Some other more varied error
   */
   virtual USBDM_ErrorCode            retryConnection(USBDMStatus_t *usbdmStatus) = 0;

  /*  Low-level
   * =================================================================
   */

  /**
   * Sets Target Vdd voltage
   *
   *  @param targetVdd => control value for Vdd
   *
   *  @return
   *      BDM_RC_OK     => OK \n
   *      else          => Various errors
   *
   *  @note
   *  - BDM_TARGET_VDD_ENABLE & BDM_TARGET_VDD_DISABLE should be used to enable and disable Vdd
   *  - BDM_TARGET_VDD_OFF, BDM_TARGET_VDD_3V3 & BDM_TARGET_VDD_5V should be used to set the required Vdd.
   *  - It is expected that the USBDM_SetTargetVdd() will be used to set the initial Vdd before calling
   *    USBDM_SetTarget() so that the appropriate power on sequence may be used.
   */
   virtual USBDM_ErrorCode            setTargetVdd(TargetVddSelect_t targetVdd) = 0;

  /**
   * Sets Target programming voltage
   *
   *  @param targetVpp => control value for Vpp
   *
   *  @note Before enabling target Vpp it is necessary to do the following: \n
   *  - Target device must be set to T_RS08 \n
   *  - Target Vdd must be present (internally or externally) \n
   *  - The Target Vpp must be first set to BDM_TARGET_VPP_STANDBY then BDM_TARGET_VPP_ON \n
   *  The above is checked by the BDM firmware
   *
   *  @return
   *      BDM_RC_OK     => OK \n
   *      else          => Various errors
   */
   virtual USBDM_ErrorCode            setTargetVpp(TargetVppSelect_t targetVpp) = 0;

  /**
   * Directly manipulate interface levels
   *
   *  @param control       => mask indicating interface levels see \ref PinLevelMasks_t
   *  @param status        => values on pins after action (not yet implemented). May be NULL.
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            controlPins(unsigned int control, unsigned int *status=0) = 0;

  /**
   * Obtains the Capability vector from the BDM interface
   *
   *  @param capabilities : ptr to where to return capability vector see \ref HardwareCapabilities_t
   *
   *  @return
   *      BDM_RC_OK                 => OK \n
   *      BDM_RC_WRONG_BDM_REVISION => BDM firmware/DLL are incompatible \n
   *      other                     => Error code - see \ref USBDM_ErrorCode
   *
   *  @note Uses cached information from when the BDM was opened.
   *  @note Can be used to check BDM firmware/DLL compatibility
   */
   virtual USBDM_ErrorCode            getCapabilities(HardwareCapabilities_t *capabilities) = 0;


  /**
   * Resets the target to normal or special mode
   *
   *  @param mode see
   *
   *  @return
   *      BDM_RC_OK   => OK \n
   *      other       => Error code - see \ref USBDM_ErrorCode
   *
   *  @note V4.4 onwards - Communication with the target may be lost.  It is necessary to use
   *  USBDM_Connect() to re-connect.  This is no longer done automatically
   *  as it may interfere with security checking if attempted too soon after reset.
   */
   virtual USBDM_ErrorCode            reset(TargetMode_t mode = (TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT)) = 0;

   /**
    * Connects to Target.
    *
    *  This will cause the BDM module to attempt to connect to the Target.
    *  In most cases the BDM module will automatically determine the connection
    *  speed and successfully connect.  If unsuccessful, it may be necessary
    *  to manually set the speed using set_speed().
    *
    *  @return
    *      BDM_RC_OK  => OK \n
    *      other      => Error code - see \ref USBDM_ErrorCode
    */
    virtual USBDM_ErrorCode            connect() = 0;

    /**
     * Connects to Target.
     *
     *  This will cause the BDM module to attempt to connect to the Target.
     *  ARM-SWD - Does JTAG to Serial Wire switching only
     *  Other targets same as connect()
     *
     *  @return
     *      BDM_RC_OK  => OK \n
     *      other      => Error code - see \ref USBDM_ErrorCode
     */
     virtual USBDM_ErrorCode            basicConnect() = 0;

  /**
   * Get the BDM communication speed in Hz
   *
   *  @param frequency => BDM Communication speed in kHz
   *
   *  @return
   *      BDM_RC_OK  => OK \n
   *      other      => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            getSpeedHz(unsigned long int *frequency) = 0;

  /**
   * Sets the BDM communication speed.
   *
   *  @param frequency => BDM Communication speed in Hz \n
   *  - T_CFVx, T_JTAG, T_MC56F80xx : JTAG clock frequency \n
   *  - RS08, HCS08, HCS12, CFV1    : BDM interface frequency \n
   *     Usually equal to the CPU Bus frequency. \n
   *     May be unrelated to bus speed if alternative BDM clock is in use. \n
   *     Once a speed is set then automatic speed determination (by sync etc)
   *     is disabled.  Automatic operation is restored by setting a speed of zero. \n
   *
   *  @return
   *      BDM_RC_OK  => OK \n
   *      other      => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            setSpeedHz(unsigned long int frequency) = 0;

  /**
   * Brings the target into active background mode.  The target will be halted.
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            halt() = 0;

  /**
   * Starts target execution from current PC address
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            go() = 0;

  /**
   * Steps over a single target instruction
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            step() = 0;

  /**
   * Reads Target Status register byte
   *
   *  @param bdmStatus => status register value read. \n
   *  The register read depends on target:
   *   - HCS12   = BDMSTS, BDM Status register \n
   *   - HCS08   = BDCSCR, BDM Status & Control register \n
   *   - RS08    = BDCSCR, BDM Status & Control register \n
   *   - CFV1    = XCSR[31..24], Extended Configuration/Status Register \n
   *   - CFVx    = CSR, Configuration/Status Register (CSR)
   *
   *  @return
   *      BDM_RC_OK  => OK \n
   *      other      => Error code - see \ref USBDM_ErrorCode
   *
   *  @note \n
   *     The BDM may resynchronize/reconnect with the target before doing this read.
   */
   virtual USBDM_ErrorCode            readStatusReg(unsigned long *bdmStatus) = 0;

  /**
   * Write Target Control Register byte
   *
   *  @param controlValue => value to write
   *  The register written depends on target:
   *   - HCS12 = BDMSTS, BDM Status register \n
   *   - HCS08 = BDCSCR, BDM Status & Control register \n
   *   - RS08  = BDCSCR, BDM Status & Control register \n
   *   - CFV1  = XCSR[31..24], Extended Configuration/Status Register \n
   *   - CFVx  not supported (Access CSR through writeControlReg())
   *
   *  @return
   *      BDM_RC_OK  => OK \n
   *      other      => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writeControlReg(unsigned int controlValue) = 0;

  /**
   * Write Target Core register
   *
   *  @param regNo    Register #
   *   - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
   *   - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
   *   - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
   *   - CFV1      = Core register space D0-D7, A0-A7 see \ref CFV1_Registers_t  \n
   *   - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
   *   - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
   *   - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writeReg(unsigned int regNo, unsigned long regValue)  = 0;

  /**
   * Write Target Control register
   *
   *  @param regNo    Register #
   *     - HCS12     = not used
   *     - HCS08     = not used
   *     - RS08      = not used
   *     - CFV1      = Control register space, see \ref CFV1_CRegisters_t
   *     - CFVx      = Control register space, see \ref CFVx_CRegisters_t
   *     - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
   *     - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
   *
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writeCReg(unsigned int regNo, unsigned long regValue) = 0;

  /**
   * Write Target Debug register
   *
   *  @param regNo    Register #
   *    - HCS12     = BD memory space, see \ref HCS12_DRegisters_t
   *    - HCS08     = BKPT register, see \ref HCS08_DRegisters_t
   *    - RS08      = BKPT register, see \ref RS08_DRegisters_t
   *    - CFV1      = Debug register space, see \ref CFV1_DRegisters_t
   *    - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
   *    - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
   *    - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writeDReg(unsigned int regNo, unsigned long regValue) = 0;

  /**
   * Read Target Core register
   *
   *  @param regNo    Register #
   *   - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
   *   - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
   *   - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
   *   - CFV1      = Core register space D0-D7, A0-A7, PSTBASE+n, see \ref CFV1_Registers_t  \n
   *   - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
   *   - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
   *   - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   *
   *  @note HCS12_RegCCR is accessed through \ref USBDM_ReadDReg()
   */
   virtual USBDM_ErrorCode            readReg(unsigned int regNo, unsigned long *regValue)  = 0;

  /**
   * Read Target Control register
   *
   *  @param regNo    Register # or address
   *     - HCS12     = not used
   *     - HCS08     = not used
   *     - RS08      = not used
   *     - CFV1      = Control register space, see \ref CFV1_CRegisters_t
   *     - CFVx      = Control register space, see \ref CFVx_CRegisters_t
   *     - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
   *     - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
   *
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            readCReg(unsigned int regNo, unsigned long *regValue) = 0;

  /**
   * Read Target Debug register
   *
   *  @param regNo    Register #
   *    - HCS12     = BD memory space, see \ref HCS12_DRegisters_t
   *    - HCS08     = BKPT register, see \ref HCS08_DRegisters_t
   *    - RS08      = BKPT register, see \ref RS08_DRegisters_t
   *    - CFV1      = Debug register space, see \ref CFV1_DRegisters_t
   *    - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
   *    - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
   *    - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            readDReg(unsigned int regNo, unsigned long *regValue) = 0;

  /**
   * Read data from target memory
   *
   *  @param memorySpace = Size of data (1/2/4 bytes)
   *  @param byteCount   = Number of bytes to transfer
   *  @param address     = Memory address
   *  @param data        = Where to place data
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            readMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data) = 0;

  /**
   * Write data to target memory
   *
   *  @param memorySpace = Size of data elements (1/2/4 bytes)
   *  @param byteCount   = Number of _bytes_ to transfer
   *  @param address     = Memory address
   *  @param data        = Ptr to block of data to write
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writeMemory( unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data) = 0;

  /**
   * Write Target Program Counter
   *
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            writePC(unsigned long regValue) = 0;

   /**
   *  Read Target Program Counter
   *
   *  @param regValue 8/16/32-bit value
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            readPC(unsigned long *regValue) = 0;

   /**
    * Send Custom BDM command
    *
    * @param txSize     Number of bytes to transmit
    * @param rxSize     Number of bytes for receive
    * @param data       Buffer for data in/out
    */
   virtual USBDM_ErrorCode            bdmCommand(unsigned txSize, unsigned rxSize, uint8_t data[]) = 0;

  /**
   * Read Multiple Core registers
   *
   *  @param regValueBuffer    Values in Target byte order??
   *  @param startRegIndex     Register index (inclusive) to start reading at
   *  @param endRegIndex       Register index (inclusive) to stop reading at
   *
   *  @return error code
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   *
   *  @note The indexes mentioned above are magic numbers indexing an arbitrary table.\n
   *        Use only the predefined values provided - \ref ARM_RegisterIndex_t, \ref CFV1_RegisterIndex_t, \ref CFVx_RegisterIndex_t
   */
   virtual USBDM_ErrorCode            readMultipleRegs(uint8_t regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex) = 0;

   // JTAG
   //==============================================================================================

  /**
   * Execute JTAG Sequence
   *   @param length   - JTAG sequence length.
   *   @param sequence - Pointer to sequence.
   *   @param inLength - Expected length of input data
   *   @param inBuffer - Returned values
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            jtagExecuteSequence(uint8_t length, const uint8_t *sequence, uint8_t inLength, uint8_t *inBuffer) = 0;

  /**
   *  JTAG - read data from JTAG shift register
   *  SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
   *
   *   @param exit action after shift, see \ref JTAG_ExitActions_t \n
   *       - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
   *       - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
   *       - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
   *       - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
   *
   *   @param bitCount 8-bit count of \b bits to shift in. [>0]\n
   *                   It is not possible to do 0 bits.
   *   @param buffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
   *   @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            jtagRead( uint8_t bitCount, uint8_t exit, uint8_t *buffer) = 0;

  /**
   *  JTAG - read/write data from/to JTAG shift register
   *  SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
   *
   *   @param exit action after shift, see \ref JTAG_ExitActions_t \n
   *       - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
   *       - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
   *       - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
   *       - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
   *
   *   @param bitCount 8-bit count of \b bits to shift in. [>0]\n
   *                   It is not possible to do 0 bits.
   *   @param inBuffer  Pointer to buffer for data written to the device (first bit in LSB of the last byte in the buffer)
   *   @param outBuffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
   *   @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
   *   @note inbuffer and outbuffer may be the same location
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            jtagReadWrite( uint8_t bitCount, uint8_t exit, const uint8_t *outBuffer, uint8_t *inBuffer) = 0;

  /**
   *  JTAG - Moves the TAP to \b TEST-LOGIC-RESET state
   *  TMS=11111, TDI=00000 or similar
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   *
   *  @note This uses the CMD_USBDM_JTAG_GOTORESET to move the TAP, it does
   *        not use TRST.
   */
   virtual USBDM_ErrorCode            jtagReset() = 0;

  /**
   *  JTAG - move the TAP to \b SHIFT-DR or \b SHIFT-IR state
   *  SHIFT_DR => TMS=100,  TDI=0 (Actually TMS=0000_0100)
   *  SHIFT_IR => TMS=1100, TDI=0 (Actually TMS=0000_1100)
   *
   *  @param mode Action, ref \ref JTAG_ExitActions_t \n
   *       - SHIFT_DR - Enter SHIFT-DR \n
   *       - SHIFT_IR - Enter SHIFT-IR
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   *
   *  @note - Requires the tap to be initially in \b TEST-LOGIC-RESET or \b RUN-TEST/IDLE
   */
   virtual USBDM_ErrorCode            jtagSelectShift(uint8_t mode) = 0;

  /**
   *  JTAG - write data to JTAG shift register
   *  STAY_SHIFT    => TMS=Nx0,       TDI=NxData
   *  EXIT_SHIFT_DR => TMS=Nx0,11100  TDI=NxData,00000
   *  EXIT_SHIFT_IR => TMS=Nx0,111100 TDI=NxData,000000
   *  EXIT_IDLE     => TMS=Nx0,10     TDI=NxData,00
   *
   *   @param exit action after shift, see \ref JTAG_ExitActions_t \n
   *       - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
   *       - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
   *       - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
   *
   *   @param bitCount 8-bit count of \b bits to shift in. [>0]\n
   *                   It is not possible to do 0 bits.
   *   @param buffer Pointer to data buffer.  The data is shifted in LSB (last byte) first,
   *                 unused bits (if any) are in the MSB (first) byte;
   *   @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
   *
   *  @return
   *      BDM_RC_OK    => OK \n
   *      other        => Error code - see \ref USBDM_ErrorCode
   */
   virtual USBDM_ErrorCode            jtagWrite(uint8_t bitCount, uint8_t exit, const uint8_t *buffer) = 0;

   /**
    *  Get JTAG IDCODE
    *
    *  @param idCode - Where to return IDCODE
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode            getIdcode(unsigned int *idCode) = 0;

   /**
    *  Get DSC status
    *
    *  @param status - Where to return status
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode            getStatus(unsigned int *status) = 0;

   /**
    *  Set interface to 'programming mode'
    *  This changes the interface settings as needed for programming.
    *  This is needed because some settings are incompatible with programming
    *  Don't need to use this unless you have changed the settings from the default
    *
    *  @param mode  true sets programming mode, false restores previous settings
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode            setProgrammingMode(bool mode) = 0;

   /**
    * Send miscellaneous commands to BDM interface.
    *
    *  @param size     Size of Tx/Rx data buffer. Must be <= 20.
    *  @param [in/out] usb_data - Command for BDM \n
    *                   Send Format    [command, data...]
    *                   Receive Format [result...]
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode  miscellaneousCommand(unsigned size, uint8_t usb_data[]) = 0;

   /**
    * Enable or disable serial interface on BDM
    *
    * @param enable true to enable
    *
    * @return Previous state off serial interface
    */
   virtual bool enableSerialInterface(bool enable) = 0;
};

typedef std::shared_ptr<BdmInterface> BdmInterfacePtr;

#endif /* BDM_INTERFACE_H */
