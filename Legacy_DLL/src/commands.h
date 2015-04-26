/*! \file
    \brief Command and Error codes for BDM communication over USB
*/
#ifndef _COMMANDS_H_
#define _COMMANDS_H_

/* command format:

1   byte : command number (see below)
n   bytes: command parameters (data)

   Data format:
      Colfire V2, V3 & V4
         All 16-bit and 32-bit data is transferred in Big-endian,
         i.e. MSB on lower address (first) and LSB on higher address (next)
         data must be converted properly on Intel machines (PCs)
      HCS12, HCS08, RS08 & Coldfire V1
            All 16-bit word data is transferred in Intel Little-endian,
              i.e. LSB on lower and MSB on higher address
*/

//! \brief Maximum USB transfer size - entire transfer!
//!
//! Limited by RAM, Multiple of 64 is nice since transfers may be in 8/64-byte pieces.
#define MAX_PACKET_SIZE       (2*64)
#define MAX_DATA_SIZE         (MAX_PACKET_SIZE-5) //!< Max data transfer (HC12/HC08/RS08)
#define MAX_CF_DATA_SIZE      (MAX_PACKET_SIZE-7) //!< Max data transfer (Coldfire V1)
#define MAX_CFx_DATA_SIZE     (MAX_PACKET_SIZE-1) //!< Max data transfer (Coldfire V2,3,4)

//! BDM command values
//!
//! The following values are the 1st byte in each command.  Other parameters are as shown below. \n
//!  Each command returns a status value (see \ref  ErrorCodes) as the first byte followed by any results as indicated below.
//!
typedef enum {
   // The following few were actually used as error codes - replaced by BDM_RC_...
   //CMD_OK         = 0,       //!< deprecated
   //CMD_ERR_SUM    = 1,       //!< deprecated, USB has CRC16 in place
   //CMD_FAILED     = 2,       //!< deprecated, command execution failed (incorrect parameters,  target not responding, etc.)
   //CMD_UNKNOWN    = 3,       //!< deprecated, unknown command
                               //   0 .. 7 Reserved for error codes

   // Common commands
   CMD_DEBUG            =  8, //!< Debugging commands (parameter determines actual command) @param [2]  Debug command see \ref DebugSubCommands
   CMD_OPTION           = 10, //!< Set/clear various options (only has affect after next \ref CMD_SET_TARGET) \n
                              //!    @param [2]  Option command see \ref OptionCommands
   CMD_GET_VER          = 12, //!< Get firmware version in BCD @return [1] 8-bit HW (major+minor) revision \n [2] 8-bit SW (major+minor) version number
   CMD_GET_LAST_STATUS  = 13, //!< Get status from last command @return [0] 8-bit Error code see \ref  ErrorCodes
   CMD_SET_BOOT         = 14, //!< Requests reboot to ICP mode. @param [2..5] must be "BOOT"

                              //   15 .. 29 Reserved for error codes
   CMD_SET_TARGET       = 30, //!< Set target,  @param [2] 8-bit target value @ref target_type_e

/* BDM/debugging related commands */
   CMD_CONNECT          = 31, //!< Try to connect to the target
//   CMD_READ_SPEED       = 32    //!< deprecated, speed has higher resolution now
   CMD_RESET            = 33, //!< Reset target @param [2] 0=>reset to Special Mode, 1=>reset to Normal mode
   CMD_GET_STATUS       = 34, //!< Get BDM status
                              //! @return [1] 8-bit status byte made up as follows: \n
                              //!    - (HC08/12/RS08/CFV1) bit0   - ACKN, \n
                              //!    - (All)               bit1   - target was reset (this bit is cleared after reading),  \n
                              //!    - (CFVx only)         bit2   - current RSTO value \n
                              //!    - (HC08/12/RS08/CFV1) bit4-3 - comm status: 00=NOT CONNECTED, 01=SYNC, 10=GUESS,  11=USER SUPPLIED \n
                              //!    - (All)               bit7   - target has power
   CMD_READ_BD          = 35, //!< Read from BDM address space @param [2..3] 16-bit address, @return [3] 8-bit value read from address;
   CMD_WRITE_BD         = 36, //!< Write to BDM address space @param [2..3] 16-bit address, @param [4] 8-bit value to write;
   //CMD_GO     = 37               //!<  deprecated
   //CMD_STEP  = 38                //!<  deprecated
   CMD_HALT             = 39, //!< Stop the CPU and bring it into background mode
   //CMD_SET_SPEED        = 40, //!< deprecated
   CMD_READ_SPEED       = 41, //!< Read speed of the target: @return [1..2] 16-bit tick count see \ref SYNC_MULTIPLE
   CMD_GO               = 42, //!< Start code execution
   CMD_STEP             = 44, //!< Perform single step
   CMD_SET_SPEED1       = 46, //!< Sets-up the BDM interface for a new bit rate & tries
                              //!    to enable ackn feature, @param [2..3] 16-bit tick count see \ref SYNC_MULTIPLE
   CMD_SET_DERIVATIVE   = 47, //!< Set RS08 derivative @param [2] 8-bit derivative see \ref rs08_derivative_type_e

   /* CPU related commands */
   CMD_READ_8           = 50, //!< Read byte from memory @param [2..3] 16-bit address @return [1] 8-bit value read from address
   CMD_READ_16          = 51, //!< (HC12 only) Read word from memory @param [2..3] 16-bit address @return [1..2] 16-bit value read from address
   //CMD_READ_BLOCK           //!< 52 deprecated
   CMD_READ_REGS        = 53, //!< Reads all target registers, @return [1..N] multiple 16-bit values: upper bytes are 0 when not used \n
                              //!    HC/S12(X): PC, SP, IX, IY, D(B:A), CCR;  \n
                              //!    HCS08: PC, SP, H:X, A, CCR;  \n
                              //!    RS08: CCR+PC, SPC, 0, A ;
   //CMD_READ_BLOCK_FAST      //!< 54 deprecated
   CMD_READ_BLOCK1      = 55, //!< Read a block of memory @param [2..3] 16-bit address, @param [4] 8-bit count of bytes to read,
                              //!< @return [1..N] block of bytes from given address,
                              //!<    count MUST be <= \ref MAX_PACKET_SIZE-1
   CMD_WRITE_8          = 60, //!< Write 8-bit value to memory @param [2..3] 16-bit address @param [4] 8-bit value to write
   CMD_WRITE_16         = 61, //!< Write 16-bit value to memory @param [2..3] 16-bit address @param [4..5] 16-bit value to write
   //CMD_WRITE_BLOCK          //!< 62 deprecated
   //CMD_WRITE_REGS           //!< 63 deprecated
   //CMD_WRITE_BLOCK_FAST     //!< 64 deprecated
   CMD_WRITE_BLOCK1     = 65, //!< Write a block to memory @param [2..3] 16-bit address @param [4] 8-bit count of bytes,
                              //!<   @param [5..N+4] block of bytes to write, \n
                              //!<    count MUST be <= \ref MAX_PACKET_SIZE-5
   /*
    * HC12 CPU individual register write commands
    * (added for debugger interfaces which need access to individual registers rather than whole block)
    */
   CMD_WRITE_REG_PC     = 80, //!< Write to PC, @param [2..3] 16-bit PC value
   CMD_WRITE_REG_SP     = 81, //!< Write to SP, @param [2..3] 16-bit SP value
   CMD_WRITE_REG_X      = 82, //!< Write to X,  @param [2..3] 16-bit IX (H:X) value
   CMD_WRITE_REG_Y      = 83, //!< Write to Y,  @param [2..3] 16-bit IY value
   CMD_WRITE_REG_D      = 84, //!< Write to D,  @param [2..3] 16-bit B:A (x:A) value
   CMD_WRITE_REG_CCR    = 85, //!< Write to CCR,  @param [2..3] 16-bit CCR (x:CCR) value

   // Coldfire V1
   CMD_CF_READ_CSR2     = 86, //!< Read CFv1 CSR2 @return [1] 8-bit value
   CMD_CF_READ_CSR3     = 87, //!< Read CFv1 CSR3 @return [1] 8-bit value
   CMD_CF_WRITE_CSR2    = 88, //!< Write CFv1 CSR2 @param [2] value
   CMD_CF_WRITE_CSR3    = 89, //!< Write CFv1 CSR3 @param [2] value
   CMD_CF_READ_REG      = 90, //!< Read CFv1 Register @param [2] 8-bit register # @return [1..4] 32-bit value
   CMD_CF_READ_CREG     = 91, //!< Read CFv1 Control register @param [2] 8-bit register # @return [1..4] 32-bit value
   CMD_CF_READ_DREG     = 92, //!< Read CFv1 Debug register @param [2] 8-bit reg # @return [1..4] 32-bit value
   CMD_CF_READ_XCSR     = 93, //!< Read CFv1 Extended status register @return [1] 8-bit value
   CMD_CF_WRITE_REG     = 94, //!< Write CFv1 Register @param [2] 8-bit reg # @param [3..6] 32-bit value
   CMD_CF_WRITE_CREG    = 95, //!< Write CFv1 Control register @param [2] 8-bit reg # @param [3..6] 32-bit value
   CMD_CF_WRITE_DREG    = 96, //!< Write CFv1 Debug register @param [2] 8-bit reg # @param [3..6] 32-bit value
   CMD_CF_READ_MEM      = 97, //!< Read CFv1 Memory @param [2..4] 24-bit address @param [5] 8-bit data unit size @param block size is implied by USB transfer size
                              //!< @return [1..N] block of bytes from given address,
                              //!<    block size MUST be <= \ref MAX_PACKET_SIZE-1
   CMD_CF_WRITE_MEM     = 98, //!< Write CFv1 Memory @param [2..4] 24-bit address @param [5] 8-bit data unit size (1,2,4) @param [6] 8-bit block size @param [7..N+6] block of data,
                              //!<    block size MUST be <= \ref MAX_PACKET_SIZE-7
   CMD_CF_WRITE_XCSR    = 99, //!< Write CFv1 Extended Control register @param [2] 8-bit value

   // S08
   CMD_READ_STATUS      = 100, //!< Read target status register ( BDCSC, BDMSTS or XCSR as appropriate) @return [1] 8-bit value
   CMD_WRITE_CONTROL    = 101, //!< Write target control register ( BDCSC, BDMSTS or XCSR as appropriate) @param [2] 8-bit value
   CMD_WRITE_BKPT       = 102, //!< Write breakpoint register @param [2..5] 32-bit value
   CMD_READ_BKPT        = 103, //!< Read breakpoint register @return [1..4] 32-bit value

   //RS08
   CMD_READ_SPC         = 104, //!< Read shadow PC @return [1..2] 16-bit value
   CMD_WRITE_SPC        = 105, //!< Write shadow PC @param [2..3] 16-bit value
   CMD_READ_CCR_PC      = 106, //!< Read CCR/PC @return [1..2]16-bit value
   CMD_WRITE_CCR_PC     = 107, //!< Write CCR/PC @param [2..3]16-bit value
   //CMD_READ_BLOCK       = 108, //!< Not Used see CMD_READ_BLOCK1!
   //CMD_WRITE_BLOCK      = 109, //!< Not Used see CMD_WRITE_BLOCK1!
   CMD_MASS_ERASE       = 110, //!< Mass erase target, not used?
   //CMD_VPPOFF           = 111, //!< Not Used - Turn off Target programming voltage
   //CMD_RS08_POG           // 112, -- unused?
   CMD_FLASH_DLSTART    = 113, //!< Used before programming RS08 FLash memory (mass erase + leaves Vpp on)
   CMD_FLASH_DLEND      = 114, //!< Used to indicate end of RS08 Flash programming (Program clock trim, Vpp off)
   TCMD_NEXT_DLDATA     = 115, //!< Check if ready to program next block of Flash memory - broken.

   // Coldfire V2, 3 & 4
   CMD_CFVx_RESYNCHRONIZE     = 120, //!< resynchronize communication with the target (in case of noise, etc.)
   CMD_CFVx_RESET             = 121, //!< Reset target @param [2] 0=>reset to Special Mode, 1=>reset to Normal mode
   CMD_CFVx_GO                = 122, //!< Start code execution
   CMD_CFVx_STEP              = 123, //!< Perform single step
   CMD_CFVx_HALT              = 124, //!< Stop the CPU and bring it into background mode
   CMD_CFVx_ASSERT_TA         = 125, //!< @param [2] 8-bit duration of the TA assertion in 10 us increments

   CMD_CFVx_READ_MEM8         = 130, //!< @param [2..5] 32bit address, @return [1] 8bit value read from address
   CMD_CFVx_READ_MEM16        = 131, //!< @param [2..5] 32bit address, @return [1..2] 16bit value read from address
   CMD_CFVx_READ_MEM32        = 132, //!< @param [2..5] 32bit address, @return [1..4] 32bit value read from address

   CMD_CFVx_READ_MEMBLOCK8    = 133, //!< @param [2..5] 32bit address, @return [1..N] block of 8bit values read from the address and onwards
   CMD_CFVx_READ_MEMBLOCK16   = 134, //!< @param [2..5] 32bit address, @return [1..N] block of 16bit values read from the address and onwards
   CMD_CFVx_READ_MEMBLOCK32   = 135, //!< @param [2..5] 32bit address, @return [1..N] block of 32bit values read from the address and onwards

   CMD_CFVx_WRITE_MEM8        = 136, //!< @param [2..5] 32bit address, @param [6] 8-bit value to be written to the address
   CMD_CFVx_WRITE_MEM16       = 137, //!< @param [2..5] 32bit address, @param [6..7] 16-bit value to be written to the address
   CMD_CFVx_WRITE_MEM32       = 138, //!< @param [2..5] 32bit address, @param [6..9] 32-bit value to be written to the address

   CMD_CFVx_WRITE_MEMBLOCK8   = 139, //!< @param [2..5] 32bit address, @param [6..N+5] block of 8-bit values to be written from the address
   CMD_CFVx_WRITE_MEMBLOCK16  = 140, //!< @param [2..5] 32bit address, @param [6..N+5] block of 16-bit values to be written from the address
   CMD_CFVx_WRITE_MEMBLOCK32  = 141, //!< @param [2..5] 32bit address, @param [6..N+5] block of 32-bit values to be written from the address

   CMD_CFVx_READ_REG          = 142, //!< @param [2] 8-bit register number, @return [1..4] 32-bit register contents
   CMD_CFVx_WRITE_REG         = 143, //!< @param [2] 8-bit register number, @param [3..6] 32-bit register contents to be written
   CMD_CFVx_READ_CREG         = 144, //!< @param [2..3] 16-bit register address, @return [1..4] 32-bit control register contents
   CMD_CFVx_WRITE_CREG        = 145, //!< @param [2..3] 16-bit register address, @param [4..7] 32-bit control register contents to be written
   CMD_CFVx_READ_DREG         = 146, //!< @param [2] 8-bit register number to read, @return [1..4] 32-bit debug module register contents
   CMD_CFVx_WRITE_DREG        = 147, //!< @param [2] 8-bit register number to write, @param [3..6] 32-bit debug module register contents to be written
   CMD_CFVx_SET_SPEED         = 148, //!< @param [2..3] frequency in kHz

   /* JTAG commands */
   CMD_JTAG_GOTORESET    = 150, //!< Takes the TAP to \b TEST-LOGIC-RESET state,
                                //!  @note use \ref CMD_SET_TARGET with \ref T_JTAG target to take TAP back to \b RUN-TEST/IDLE
   CMD_JTAG_GOTOSHIFT    = 151, //!< Takes the TAP to \b SHIFT-DR or \b SHIFT-IR state \n
                                //!  @param [2] 8-bit path option; \n - ==0 : go to \b SHIFT-DR, \n - !=0 : go to \b SHIFT-IR
                                //!  @note (requires the tap to be in \b RUN-TEST/IDLE)
   CMD_JTAG_WRITE        = 152, //!< Write data to JTAG shift register
                                //!  @param [2] 8-bit exit option \n - ==0 : stay in \b SHIFT-xx, \n - !=0 : go to \b RUN-TEST/IDLE, \n
                                //!  @param [3] 8-bit count of \b bits to shift in
                                //!  @param [4..N+3] the data to be shifted in (shifted in LSB (last byte) first,
                                //!                  unused bits (if any) are in the MSB (first) byte;
                                //!  @note (requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state)
   CMD_JTAG_READ         = 153, //!< Read data fro JTAG shift register
                                //!  @param [2] 8-bit exit option \n - ==0 : stay in \b SHIFT-xx, \n - !=0 : go to \b RUN-TEST/IDLE, \n
                                //!  @param [3] 8-bit count of \b bits to shift out
                                //!  @return [1..N] data read out of the device (first bit in LSB of the last byte in the buffer)
                                //!  @note (requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state)
} BDMCommands;

//! Target Status bit masks for \ref CMD_GET_STATUS
//!
typedef enum  {
   S_ACKN            = (1<<0),  //!< Target supports BDM ACK
   S_RESET_DETECT    = (1<<1),  //!< Target has been reset since status last polled
   S_RESET_STATE     = (1<<2),  //!< Current state of target reset pin (RESET or RSTO) (active low!)
   S_NOT_CONNECTED   = (0<<3),  //!< No connection with target
   S_SYNC_DONE       = (1<<3),  //!< Target communication speed determined by BDM SYNC
   S_GUESS_DONE      = (2<<3),  //!< Target communication speed guessed
   S_USER_DONE       = (3<<3),  //!< Target communication speed specified by user
   S_COMM_MASK       = (3<<3),  //!< Mask for communication state
   S_RES5            = (1<<5),  //!< - unused
   S_RES6            = (1<<6),  //!< - unused
   S_POWER           = (1<<7)   //!< Target power present
} status_bit_masks;

#endif
