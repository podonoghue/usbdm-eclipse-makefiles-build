/*
 * USBDM_API_Private.h
 *
 * Private definitions for USBDM_API.c
 *
 *  Created on: 02/10/2009
 *      Author: podonoghue
 */

#ifndef _USBDM_API_PRIVATE_H_
#define _USBDM_API_PRIVATE_H_

#if defined __cplusplus
    extern "C" {
#endif

//! \brief Maximum USB transfer size - entire transfer!
//!
//! Limited by 1-byte size (but buffer is << 256 bytes)
#define MAX_PACKET_SIZE       (255)
//! Limited by BDM RAM
//! Multiple of 64 is nice since transfers may be in 8/64-byte pieces.
#define DEFAULT_PACKET_SIZE   (2*64) // Default to use if more detail isn't available from target
#define MAX_RS08_FLASH_SIZE   (64)

//! BDM command values
//!
//! The following values are the 1st byte in each command.  \n
//! Other parameters are as shown below. \n
//! Each command returns a status value (see \ref  USBDM_ErrorCode) as the first byte
//! followed by any results as indicated below.
//!
typedef enum {
   // Common to all targets
   CMD_USBDM_GET_COMMAND_RESPONSE  = 0,   //!< Status of last/current command
   CMD_USBDM_SET_TARGET            = 1,   //!< Set target,  @param [2] 8-bit target value @ref TargetType_t
   CMD_USBDM_SET_VDD               = 2,   //!< Set target Vdd (immediate effect)
   CMD_USBDM_DEBUG                 = 3,   //!< Debugging commands (parameter determines actual command) @param [2]  Debug command see \ref DebugSubCommands
   CMD_USBDM_GET_BDM_STATUS        = 4,   //!< Get BDM status\n @return [1] 16-bit status value reflecting BDM status
   CMD_USBDM_GET_CAPABILITIES      = 5,   //!< Get capabilities of BDM, see \ref HardwareCapabilities_t
   CMD_USBDM_SET_OPTIONS           = 6,   //!< Set BDM options, see BDM_Options_t
//   CMD_USBDM_GET_SETTINGS          = 7,   //!< Get BDM setting
   CMD_USBDM_CONTROL_PINS          = 8,   //!< Directly control BDM interface levels
   // Reserved 9..11
   CMD_USBDM_GET_VER               = 12,  //!< Sent to ep0 \n Get firmware version in BCD \n
                                          //!< @return [1] 8-bit HW (major+minor) revision \n [2] 8-bit SW (major+minor) version number
   CMD_GET_VER                     = 12,  //!< Deprecated name - Previous version
   // Reserved 13
   CMD_USBDM_ICP_BOOT              = 14,  //!< Sent to ep0 \n
                                          //!< Requests reboot to ICP mode. @param [2..5] must be "BOOT"
   CMD_SET_BOOT                    = 14,  //!< Deprecated - Previous version

   // Target specific versions
   CMD_USBDM_CONNECT               = 15,  //!< Try to connect to the target
   CMD_USBDM_SET_SPEED             = 16,  //!< Sets-up the BDM interface for a new bit rate & tries
                                          //!    to enable ackn feature, @param [2..3] 16-bit tick count
   CMD_USBDM_GET_SPEED             = 17,  //!< Read speed of the target: @return [1..2] 16-bit tick coun

   CMD_CUSTOM_COMMAND              = 18,  //!< Custom command
   // Reserved 19

   CMD_USBDM_READ_STATUS_REG       = 20,  //!< Get BDM status
                                          //! @return [1] 8-bit status byte made up as follows: \n
                                          //!    - (HC08/12/RS08/CFV1) bit0   - ACKN, \n
                                          //!    - (All)               bit1   - target was reset (this bit is cleared after reading),  \n
                                          //!    - (CFVx only)         bit2   - current RSTO value \n
                                          //!    - (HC08/12/RS08/CFV1) bit4-3 - comm status: 00=NOT CONNECTED, 01=SYNC, 10=GUESS,  11=USER SUPPLIED \n
                                          //!    - (All)               bit7   - target has power

   CMD_USBDM_WRITE_CONTROL_REG     = 21,  //!< Write to target Control register

   CMD_USBDM_TARGET_RESET          = 22,  //!< Reset target @param [2] \ref TargetMode_t
   CMD_USBDM_TARGET_STEP           = 23,  //!< Perform single step
   CMD_USBDM_TARGET_GO             = 24,  //!< Start code execution
   CMD_USBDM_TARGET_HALT           = 25,  //!< Stop the CPU and bring it into background mode

   CMD_USBDM_WRITE_REG             = 26,  //!< Write to target register
   CMD_USBDM_READ_REG              = 27,  //!< Read target register

   CMD_USBDM_WRITE_CREG            = 28,  //!< Write target Core register
   CMD_USBDM_READ_CREG             = 29,  //!< Read from target Core register

   CMD_USBDM_WRITE_DREG            = 30,  //!< Write target Debufg register
   CMD_USBDM_READ_DREG             = 31,  //!< Read from target Debug register

   CMD_USBDM_WRITE_MEM             = 32,  //!< Write to target memory
   CMD_USBDM_READ_MEM              = 33,  //!< Read from target memory
   CMD_USBDM_READ_ALL_REGS         = 34,  //!< Read all target core registers

   //CMD_USBDM_TRIM_CLOCK            = 34,  //!< Trim target clock - deleted in V3.2
   //CMD_USBDM_RS08_FLASH_ENABLE     = 35,  //!< Enable target flash programming (Vpp on)
   //CMD_USBDM_RS08_FLASH_STATUS     = 36,  //!< Status of target flash programming
   //CMD_USBDM_RS08_FLASH_DISABLE    = 37,  //!< Stop target flash programming (Vpp off)

   CMD_USBDM_JTAG_GOTORESET        = 38,  //!< Reset JTAG Tap controller
   CMD_USBDM_JTAG_GOTOSHIFT        = 39,  //!< Move JTAG TAP controller to SHIFT-IR/DR
   CMD_USBDM_JTAG_WRITE            = 40,  //!< Write to JTAG chain
   CMD_USBDM_JTAG_READ             = 41,  //!< Read from JTAG chain
   CMD_USBDM_SET_VPP               = 42,  //!< Set VPP level
   CMD_USBDM_JTAG_READ_WRITE       = 43,  //!< Read & Write to JTAG chain (in-out buffer)
   CMD_USBDM_JTAG_EXECUTE_SEQUENCE = 44,  //!< Execute sequence of JTAG commands
} BDMCommands;

//! Debugging sub commands (used with \ref CMD_USBDM_DEBUG )
//! @note Not for general use! (Dangerous - don't try turning on VPP with the wrong chip!)
typedef enum  {
  BDM_DBG_ACKN             = 0,  //!< - Test ACKN
  BDM_DBG_SYNC             = 1,  //!< - Test SYNC
  BDM_DBG_TESTPORT         = 2,  //!< - Test BDM port timing
  BDM_DBG_USBDISCONNECT    = 3,  //!< - Test USB disconnect (don't use!)
  BDM_DBG_STACKSIZE        = 4,  //!< - Determine stack size
  BDM_DBG_VPP_OFF          = 5,  //!< - Remove Flash programming voltage from target
  BDM_DBG_VPP_ON           = 6,  //!< - Apply Flash programming voltage to target
  BDM_DBG_FLASH12V_OFF     = 7,  //!< - Turn 12V flash programming voltage source off
  BDM_DBG_FLASH12V_ON      = 8,  //!< - Turn 12V flash programming voltage source on
  BDM_DBG_VDD_OFF          = 9,  //!< - Turn Target Vdd supply off
  BDM_DBG_VDD3_ON          = 10, //!< - Set Target Vdd supply to 3V3
  BDM_DBG_VDD5_ON          = 11, //!< - Set Target Vdd supply to 5V
  BDM_DBG_CYCLE_POWER      = 12, //!< - Cycle Target Vdd supply off and on
  BDM_DBG_MEASURE_VDD      = 13, //!< - Measure Target Vdd supply
  BDM_DBG_RS08TRIM         = 14, //!< - Calculate RS08 clock trim value
  BDM_DBG_TESTWAITS        = 15, //!< - Tests the software counting delays used for BDM communication. (locks up BDM!)
  BDM_DBG_TESTALTSPEED     = 16, //!< - Test bdmHC12_alt_speed_detect()
  BDM_DBG_TESTBDMTX        = 17, //!< - Test various BDM tx routines with dummy data
  BDM_DBG_SWD              = 18, //!< - SWD tests
} DebugSubCommands;

//! Commands for BDM when in ICP mode
//!
typedef enum {
   ICP_GET_RESULT    =  1,            //!< Get result of last command 
                                      //!< @return [0] 8-bit Error code, see ICP_ErrorCode_t
   ICP_ERASE_PAGE    =  2,            //!< Erase page (must be within a single Flash memory page)
                                      //!<   @param 16-bit Address within Flash page to erase
   ICP_PROGRAM_ROW   =  3,            //!< Program row (must be within a single Flash memory row)
                                      //!<   @param [0..1] 16-bit Address within Flash page to program
                                      //!<   @param [2..3] 16-bit Number of bytes to program
                                      //!<   @param [4..N] data to program
   ICP_VERIFY_ROW    =  4,            //!< Verify row
                                      //!<   @param [0..1] 16-bit Address within Flash page to verify
                                      //!<   @param [2..3] 16-bit Number of bytes to verify
                                      //!<   @param [4..N] data to verify
   ICP_REBOOT        =  5,            //!< Reboot device - device immediately reboots so contact is lost!
   ICP_GET_VER       =  CMD_USBDM_GET_VER,  //!< Get version - must be common to both modes
                                      //!< @return [0] 16-bit Version number major.minor
                                      //!< @return Error code, see ICP_ErrorCode_t
} ICPCommandCodes;

//! Target Status bit masks
//!     9       8       7       6       5        4       3       2       1       0
//! +-------+-------+-------+-------+--------+-------+-------+-------+-------+-------+
//! |      VPP      |     Power     |  Halt  | Communication | Reset | ResDet| Ackn  |
//! +-------+-------+-------+-------+--------+-------+-------+-------+-------+-------+
//!
typedef enum  {
   S_ACKN            = (1<<0),  //!< - Target supports BDM ACK
   S_RESET_DETECT    = (1<<1),  //!< - Target has been reset since status last polled
   S_RESET_STATE     = (1<<2),  //!< - Current state of target reset pin (RESET or RSTO) (active low!)
   S_NOT_CONNECTED   = (0<<3),  //!< - No connection with target
   S_SYNC_DONE       = (1<<3),  //!< - Target communication speed determined by BDM SYNC
   S_GUESS_DONE      = (2<<3),  //!< - Target communication speed guessed
   S_USER_DONE       = (3<<3),  //!< - Target communication speed specified by user
   S_COMM_MASK       = (3<<3),  //!< - Mask for communication state (S_NOT_CONNECTED, S_SYNC_DONE, S_GUESS_DONE or S_USER_DONE)
   S_HALT            = (1<<5),  //!< - Indicates target is halted (CF V2, V3 & V4) - buggy?
   S_POWER_NONE      = (0<<6),  //!< - Target power not present
   S_POWER_EXT       = (1<<6),  //!< - External target power present
   S_POWER_INT       = (2<<6),  //!< - Internal target power on
   S_POWER_ERR       = (3<<6),  //!< - Internal target power error - overcurrent or similar
   S_POWER_MASK      = (3<<6),  //!< - Mask for Power
   S_VPP_OFF         = (0<<8),  //!< - Vpp Off
   S_VPP_STANDBY     = (1<<8),  //!< - Vpp standby (Inverter on)
   S_VPP_ON          = (2<<8),  //!< - Vpp On
   S_VPP_ERR         = (3<<8),  //!< - Vpp Error - not used
   S_VPP_MASK        = (3<<8),  //!< - Mask for Vpp
} StatusBitMasks_t;


//! Part of Hack to reduce USB polling rate
typedef enum {
   BDM_STATUS     = 1,  //!< BDM status should be refreshed
   BDM_STATUSREG  = 2,  //!< BDM status register should be refreshed
   BDM_ACTIVE     = 3,  //!< Both of the above
   BDM_INACTIVE   = 0,
} BDMActivityState_t;

//! Structure for internal state USBDM DLL
typedef struct {
   bool                    initialised;          //!< Indicates if the DLL has been initialised
   int                     powerCycleRetryAbort; //!< Disable connection retries
   int                     useOnlyEp0;           //!< JB16 BDM only use EP0
   TargetType_t            targetType;           //!< Target connected to BDM
   BDMActivityState_t      activityFlag;         //!< Indicates the BDM has been asked to do something interesting
} BDMState_t;

//! Internal state USBDM DLL
extern BDMState_t bdmState;

extern USBDM_bdmInformation_t bdmInfo;

#if defined __cplusplus
    }
#endif

#endif // _USBDM_API_PRIVATE_H_
