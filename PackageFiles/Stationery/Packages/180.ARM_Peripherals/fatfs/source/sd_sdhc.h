/**
 ================================================================================
 * @file    sd_sdhc.h (180.ARM_Peripherals/Snippets/sdhc-example.cpp)
 * @brief   SDHC Interface for FATFS
 ================================================================================
 */
#ifndef INCLUDE_USBDM_SD_SDHC_H_
#define INCLUDE_USBDM_SD_SDHC_H_

#include "ff.h"       // Obtains integer types for FatFs
#include "diskio.h"   // Common include file for FatFs and disk I/O layer

#include "hardware.h"
#include "sdhc.h"

namespace USBDM {

static constexpr uint32_t  SDHC_DEFAULT_BLOCK_SIZE     = 512;

struct SdhcCidRegister {
   uint8_t  mid;     // Card manufacturer : 8-bit code
   char     oid[2];  // Card OEM : 2-character code
   char     pnm[5];  // Product name
   uint8_t  prv;     // Product revision a.b as hex
   uint32_t psn;     // Serial Number
   uint16_t mdt;     // Manufacturing date 8-bit year since 2000, 4-bit month

   constexpr SdhcCidRegister() : mid(0),oid{'\0'},pnm{'\0'},prv(0),psn(0),mdt(0) {
   }

   /**
    * Constructor from SDHC response
    *
    * @param cmdResponse SDHC Response
    */
   constexpr SdhcCidRegister(uint32_t cmdResponse[5]) :
      /* [23:16] => [127:120]   */ mid((cmdResponse[0]>>16)&0xFF),
      /* [15:8]  => [119:112]   */ oid{char(cmdResponse[0]>>8),
      /* [7:0]   => [111:104]   */     char(cmdResponse[0])},
      /* [31:24] => [103:96]    */ pnm{char(cmdResponse[1]>>24),
      /* [23:16] => [95:88]     */     char(cmdResponse[1]>>16),
      /* [15:8]  => [87:80]     */     char(cmdResponse[1]>>8),
      /* [7:0]   => [79:72]     */     char(cmdResponse[1]>>0),
      /* [31:24] => [71:64]     */     char(cmdResponse[2]>>24)},
      /* [23:16] => [63:56]     */ prv((cmdResponse[2]>>16)&0xFF),
      /* [15:0]  => [55:40]     */ psn(((cmdResponse[2]<<16)&0xFFFF0000)+
      /* [31:16] => [39:24]     */     ((cmdResponse[3]>>16)&0xFFFF)),
      /* [15:12] => [23:20]     */
      /* [12:0]  => [19:8]      */ mdt((cmdResponse[3])&0xFFF) {
   }
};

struct SdhcCsdRegister {

   uint8_t  csdStructure;            ///< CSD structure [127:126]
   uint8_t  dataReadAccessTime1;     ///< Data read access-time-1 [119:112]
   uint8_t  dataReadAccessTime2;     ///< Data read access-time-2 in clock cycles (NSAC*100) [111:104]
   uint8_t  transferSpeed;           ///< Maximum data transfer rate [103:96]
   uint16_t cardCommandClass;        ///< Card command classes [95:84]
   uint8_t  readBlockLength;         ///< Maximum read data block length [83:80]
   uint32_t deviceSize;              ///< Device size [73:62],[69:48],[75:48]

   //      uint8_t eraseBlockEnable;         ///< [46:46]
   //      uint8_t eraseSectorSize;          ///< Erase sector size [45:39]
   //      uint8_t writeProtectGroupSize;    ///< Write protect group size [38:32]
   //      uint8_t writeProtectGroupEnable;  ///< [31:31]
   //      uint8_t writeSpeedFactor;         ///< Write speed factor [28:26]
   //      uint8_t writeBlockLength;         ///< Maximum write data block length [25:22]
   //      uint8_t permanentWriteProtect;    ///< [13:13]
   //      uint8_t tempWriteProtect;         ///< [12:12]
   //      uint8_t fileFormat;               ///< File format [11:10]

   // Calculated values
   uint32_t blockCount; ///< Card total block count
   uint32_t blockSize;  ///< Card block size

   // CSD version 1 only
   //      uint8_t  deviceSizeMultiplier;    ///< Device size multiplier [49:47]
   //      uint8_t  readCurrentVddMin;       ///< Maximum read current at VDD min [61:59]
   //      uint8_t  readCurrentVddMax;       ///< Maximum read current at VDD max [58:56]
   //      uint8_t  writeCurrentVddMin;      ///< Maximum write current at VDD min [55:53]
   //      uint8_t  writeCurrentVddMax;      ///< Maximum write current at VDD max [52:50]

   uint16_t flags;                  ///< Flags in _sd_csd_flag

   SdhcCsdRegister() :
      csdStructure(0), dataReadAccessTime1(0), dataReadAccessTime2(0),
      transferSpeed(0), cardCommandClass(0), readBlockLength(0),
      deviceSize(0), blockCount(0), blockSize(0), flags(0) {
   }

   /**
    * Constructor from SDHC response
    *
    * @param cmdResponse SDHC Response
    */
   SdhcCsdRegister(uint32_t cmdResponse[5]) :
               /* [23:22]  => [127:126] */  csdStructure((cmdResponse[0]>>22)&0x3),
               /* [15:8]   => [119:112] */  dataReadAccessTime1((cmdResponse[0]>>8)&0xFF),
               /* [7:0]    => [111:104] */  dataReadAccessTime2((cmdResponse[0]>>0)&0xFF),
               /* [31:24]  => [103:96]  */  transferSpeed((cmdResponse[1]>>24)&0xFF),
               /* [23:12]  => [95:84]   */  cardCommandClass((cmdResponse[1]>>12)&0xFFF),
               /* [11:8]   => [83:80]   */  readBlockLength((cmdResponse[1]>>8)&0xF),
//            /* [6:6]    => [46:46]   */  eraseBlockEnable((cmdResponse[2]>>6)&0x1),
//            /* [5:0]    => [45:40]   */  eraseSectorSize((cmdResponse[2]>>0)&0x3F),
//            /* [31:31]  => [39:39]   */  eraseSectorSize((cmdResponse[3]>>31)&0x1),
//            /* [30:24]  => [38:32]   */  writeProtectGroupSize((cmdResponse[3]>>24)&0x7F),
//            /* [23:23]  => [31:31]   */  writeProtectGroupEnable((cmdResponse[3]>>23)&0x1),
//            /* [20:18]  => [28:26]   */  writeSpeedFactor((cmdResponse[3]>>18)&0x7),
//            /* [17:14]  => [25:22]   */  writeBlockLength((cmdResponse[3]>>14)&0xF),
//            /* [5:5]    => [13:13]   */  permanentWriteProtect((cmdResponse[3]>>5)&0x1),
//            /* [4:4]    => [12:12]   */  tempWriteProtect((cmdResponse[3]>>4)&0x1),
//            /* [3:2]    => [11:10]   */  fileFormat((cmdResponse[3]>>2)&0x3),
               flags(0) {

      uint8_t  deviceSizeMultiplier=0;    ///< Device size multiplier [49:47]

      switch (csdStructure ) {
         case 0: // Ver 1
            /* [1:0]   => [73:72] */ deviceSize = ((cmdResponse[1]>>0)&0x3) +
            /* [31:22] => [71:62] */              ((cmdResponse[2]>>22)&0x3FF);
            /* [9:7]   => [49:47] */ deviceSizeMultiplier = ((cmdResponse[2]>>7)&0x7);

            /* Get card total block count and block size. */
            blockCount = ((deviceSize + 1U) << (deviceSizeMultiplier + 2U));
            blockSize = (1U << (readBlockLength));
            if (blockSize != SDHC_DEFAULT_BLOCK_SIZE) {
               // Covert so we are using a block size of 512b
               blockCount = (blockCount * blockSize);
               blockSize = SDHC_DEFAULT_BLOCK_SIZE;
               blockCount = (blockCount / blockSize);
            }
            break;

         case 1: // Ver 2
            /* [29:8] => [69:48] */  deviceSize = ((cmdResponse[2]>>8)&0x3FFFFF);

            blockSize = SDHC_DEFAULT_BLOCK_SIZE;

            if (deviceSize >= 0xFFFFU) {
               flags |= 1;
            }

            blockCount = ((deviceSize + 1U) * 1024U);
            break;

         case 2: // Ver 3

            /* [3:0]  => [75:72] */ deviceSize = ((cmdResponse[1]>>0)&0xF)+
            /* [31:8] => [71:48] */              ((cmdResponse[2]>>8)&0xFFFFFF);

            blockSize = SDHC_DEFAULT_BLOCK_SIZE;

            if (deviceSize >= 0xFFFFU) {
               flags |= 1;
            }

            blockCount = ((deviceSize + 1U) * 1024U);
            break;
      }
   }
};

struct __attribute__((packed, aligned(4))) SdhcR1Response {
   union {
      uint32_t value;
      struct {
         uint8_t                    : 3;   ///< [2:0]
         uint8_t AKE_SEQ_ERROR      : 1;   ///< [3]      Error in the sequence of the authentication process
         uint8_t                    : 1;   ///< [4]
         uint8_t APP_CMD            : 1;   ///< [5]      The card will expect ACMD, or an indication that the command has been interpreted as ACMD
         uint8_t FX_EVENT           : 1;   ///< [6]      Extension Functions may set this bit to get host to deal with events.
         uint8_t                    : 1;   ///< [7]
         uint8_t READY_FOR_DATA     : 1;   ///< [8]      Corresponds to buffer empty signalling on the bus
         uint8_t CURRENT_STATE      : 4;   ///< [12:9]   The state of the card when receiving the command.
         uint8_t ERASE_RESET        : 1;   ///< [13]     An erase sequence was cleared before executing because an out of
         ///                                                      before executing because an out of erase sequence command was received
         uint8_t CARD_ECC_DISABLED  : 1;   ///< [14]     The command has been executed without using the internal ECC.
         uint8_t WP_ERASE_SKIP      : 1;   ///< [15]     Set when only partial address space was erased due to existing write protect
         uint8_t CSD_OVERWRITE      : 1;   ///< [16]     Can be either one of the following errors:
         ///                                                      - The read only section of the CSD does not match the card content.
         ///                                                      - An attempt to reverse the copy (set as original) or permanent WP (unprotected) bits was made.
         uint8_t                    : 2;   ///< [18:17]
         uint8_t ERROR              : 1;   ///< [19]     A general or an unknown error occurred during the operation.
         uint8_t CC_ERROR           : 1;   ///< [20]     Internal card controller error
         uint8_t CARD_ECC_FAILED    : 1;   ///< [21]     Card internal ECC was applied but failed to correct the data.
         uint8_t ILLEGAL_COMMAND    : 1;   ///< [22]     Command not legal for the card state
         uint8_t COM_CRC_ERROR      : 1;   ///< [23]     The CRC check of the previous command failed
         uint8_t LOCK_UNLOCK_FAILED : 1;   ///< [24]     Set when a sequence or password error has been detected in lock/unlock card command.
         uint8_t CARD_IS_LOCKED     : 1;   ///< [25]     When set, signals that the card is locked by the host
         uint8_t WP_VIOLATION       : 1;   ///< [26]     Set when the host attempts to write to a write protected area
         uint8_t ERASE_PARAM        : 1;   ///< [27]     An invalid selection of write-blocks for erase occurred.
         uint8_t ERASE_SEQ_ERROR    : 1;   ///< [28]     An error in the sequence of erase commands occurred.
         uint8_t BLOCK_LEN_ERROR    : 1;   ///< [29]     The transferred block length is not allowed for this card, or number of transferred
         ///                                                      bytes does not match the block length.
         uint8_t ADDRESS_ERROR      : 1;   ///< [30]     A mis-aligned address which did not match the block length was used in the command.
         uint8_t OUT_OF_RANGE       : 1;   ///< [31]     The command's argument was out of the allowed range for this card.
      };
   };
   //                                          3322'2222'2222'1111'1111'11
   //                                          1098'7654'3210'9876'5432'1098'7654'3210
   static constexpr uint32_t AllErrorsMask = 0b1111'1111'1111'1001'0010'0000'0000'1000;

   constexpr SdhcR1Response(uint32_t value) : value(value) {
   }
};

struct __attribute__((packed, aligned(4))) SdhcR6Response {
   union {
      uint32_t value;
   public:
      struct {
         uint8_t                     : 3;   ///< [2:0]
         uint8_t  AKE_SEQ_ERROR      : 1;   ///< [3]      Error in the sequence of the authentication process
         uint8_t                     : 1;   ///< [4]
         uint8_t  APP_CMD            : 1;   ///< [5]      The card will expect ACMD, or an indication that the command has been interpreted as ACMD
         uint8_t  FX_EVENT           : 1;   ///< [6]      Extension Functions may set this bit to get host to deal with events.
         uint8_t                     : 1;   ///< [7]
         uint8_t  READY_FOR_DATA     : 1;   ///< [8]      Corresponds to buffer empty signalling on the bus
         uint8_t  CURRENT_STATE      : 4;   ///< [12:9]   The state of the card when receiving the command.
         uint8_t  ERROR              : 1;   ///< [13]     A general or an unknown error occurred during the operation.
         uint8_t  ILLEGAL_COMMAND    : 1;   ///< [14]     Command not legal for the card state
         uint8_t  COM_CRC_ERROR      : 1;   ///< [15]     The CRC check of the previous command failed
         uint16_t RCA                : 16;  ///< [31:16]  RCA
      };
      struct {
         uint16_t status;
         uint16_t rca;
      };
   };
   //                                          1111'11
   //                                          5432'1098'7654'3210
   static constexpr uint32_t AllErrorsMask = 0b1110'0000'0000'1000;
   constexpr SdhcR6Response(uint32_t value) : value(value) {
   }
};

struct __attribute__((packed, aligned(4))) SdhcR7Response {

   enum VoltageRange : uint8_t {
      V2_7_3_6        = 0b0001,
            LowVoltageRange = 0b0010,
   };

   union {
      uint32_t value;
   public:
      uint8_t checkPattern;                     ///< [7:0]    Echo back of check pattern (from command)
      struct {
         VoltageRange VOLTAGE_RANGE      : 4;   ///< [11:8]   Voltage accepted
         bool         PCIe_SUPPORT       : 1;   ///< [12]     Card responds PCIe acceptance
         bool         PCIe_1_2V_SUPPORT  : 1;   ///< [13]     Card responds whether it supports VDD3 (1.2V power rail)
         uint16_t                        : 16;  ///< [31:14]
      };
   };
   constexpr SdhcR7Response(uint32_t value) : value(value) {
   }
   constexpr SdhcR7Response(uint8_t checkPattern, VoltageRange voltageRange, bool pciSupport, bool support1_8V) :
            value(checkPattern+(voltageRange<<8)+(pciSupport<<12)+(support1_8V<<13)) {
   }
   bool operator==(const SdhcR7Response &other) const {
      return value == other.value;
   }
   bool operator!=(const SdhcR7Response &other) const {
      return value != other.value;
   }
};

/* ADMA2 descriptor table
 * |----------------|---------------|-------------|--------------------------|
 * | Address field  |     Length    | Reserved    |         Attribute        |
 * |----------------|---------------|-------------|--------------------------|
 * |63            32|31           16|15         06|05  |04  |03|02 |01 |00   |
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 * | 32-bit address | 16-bit length | 0000000000  |Act2|Act1| 0|Int|End|Valid|
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 *
 *
 * | Act2 | Act1 |     Comment     | Operation                                                         |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   0  | No op           | Don't care                                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   1  | Reserved        | Read this line and go to next one                                 |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   0  | Transfer data   | Transfer data with address and length set in this descriptor line |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   1  | Link descriptor | Link to another descriptor                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 */

/**
 * Action indication for ADMA2 descriptor
 */
enum class Adma2Action : uint8_t {
   nop             = 0b00<<4,  ///< No operation
   transferData    = 0b10<<4,  ///< Descriptor describes a transfer
   linkDescriptor  = 0b11<<4,  ///< Descriptor links to another Descriptor
};

/**
 * Options for ADMA2 descriptor
 */
enum class Adma2Option : uint8_t {
   interrupt   = 1<<2,
   end         = 1<<1,
   endWithInterrupt = (1<<1)|(1<<2),
   none        = 0,
};

/**
 * ADMA1 Descriptor
 * This would usually be an array of descriptors.
 */
struct __attribute__((packed, aligned(4))) Adma2Descriptor{
private:
   // For debug
   enum class Adma2Action : uint8_t {
      nop             = 0b00,  ///< No operation
      transferData    = 0b10,  ///< Descriptor describes a transfer
      linkDescriptor  = 0b11,  ///< Descriptor links to another Descriptor
   };
public:
   union {
      const uint32_t attribute;
      struct {
         const bool        valid       : 1;  //!< Indicates entry is valid
         const bool        end         : 1;  //!< Indicates last entry
         const bool        interrupt   : 1;  //!< Request interrupt
         const uint8_t                 : 1;
         const Adma2Action action      : 2;  //!< Describes the action to take
         const uint16_t                : 10;
         const uint16_t length         ;   //!< Size of data (transfer)
      };
   };
   const uint32_t address       = 0;   //!< Address of data (transfer) or link to next entry (link)

   const char *getActionName() {
      const char *actionNames[] = {
            "Nop","Reserved","Transfer","Link",
      };
      return actionNames[action];
   }

   /**
    * Default constructor - creates 'invalid' entry
    */
   constexpr Adma2Descriptor() : attribute(uint8_t(Adma2Option::none)) {
   };

   /**
    * Constructor for ADMA2 descriptor
    *
    * @param action   Describes the action to take
    * @param address  Address of data (transfer) or link to next entry (link)
    * @param length   Size of data (transfer)
    * @param option   interrupt and/or end options
    */
   constexpr Adma2Descriptor(
         USBDM::Adma2Action  action,
         uint32_t       address,
         uint16_t       length,
         Adma2Option    option=Adma2Option::none) :
               attribute(uint16_t(action)|uint16_t(option)|1|(length<<16)),address(address) {
   }
};

class SdhcInterface : public SdInterface {

private:

   const SdhcBasicInfo &sdhc;

   static constexpr SdhcDmaMode dmaMode = SdhcDmaMode_Adma2;

   static constexpr uint32_t  SDHC_XFERTYP_ACMD_MASK     = 1<<31;
   static constexpr uint32_t  SDHC_XFERTYP_BUSYCHK_MASK  = 1<<30;

   // ACMD6 Arguments
   static constexpr uint32_t ACMD6_ARG_BUS_WIDTH_1 = 0;
   static constexpr uint32_t ACMD6_ARG_BUS_WIDTH_4 = 2;

   // This is used for response size when being retrieved
   SdhcCommand lastCommand = SdhcCommand(0);

   DSTATUS     Stat     = STA_NOINIT;   /* Fat_FS Disk status */

   enum CardFlags : uint8_t {
      Detected_SDHC_SDXC = (1<<0),
   };

   CardFlags cardFlags = CardFlags(0);

   uint16_t  cardRelativeAddress  = 0;

   // CID from SD card
   SdhcCidRegister cid;

   // CSD from SD card
   SdhcCsdRegister csd;

   // Internal buffer for unaligned transfers
   uint8_t __attribute__((aligned(4))) dataBuffer[SDHC_DEFAULT_BLOCK_SIZE];

   /**
    * Enable status flags and optionally, associated interrupts
    *
    * @param usingInterruptSignal Determines if interrupts are enabled
    */
   void setTransferInterrupt(bool usingInterruptSignal);

   /**
    * Set SD Card active
    * Sends 80 clocks to the card to set it to the active state.
    * This function must be called each time the card is inserted to ensure that
    * the card can receive the command correctly.
    */
   void setCardActive();

   /**
    * Execute a non-data command
    *
    * @param sdhcCommand         Command to execute
    * @param sdhcCommandArgument Argument for command
    *
    * @return E_NO_ERROR      Successfully executed command
    * @return E_TIMEOUT       Timeout while executing command (no response from card)
    * @return E_ILLEGAL_PARAM Failed to execute command due to invalid parameters
    * @return E_ERROR         Failed to execute command (error during execution etc)
    */
   ErrorCode executeCommand(const SdhcCommand sdhcCommand, const uint32_t &sdhcCommandArgument);

   /**
    * Execute a data command
    *
    * @param sdhcCommand         Command to execute
    * @param sdhcCommandArgument Argument for command
    * @param descriptors         ADMA2 Descriptor for data transfer
    *
    * @return E_NO_ERROR Successfully executed command
    * @return E_TIMEOUT  Timeout while executing command (no response from card)
    * @return E_ERROR    Failed to execute command (invalid parameters or error during execution etc)
    */
   ErrorCode executeCommand(
         const SdhcCommand       &sdhcCommand,
         const uint32_t          &sdhcCommandArgument,
         Adma2Descriptor         *descriptors);

   /**
    * Get response value from SD card from last command
    *
    * @param response      Buffer for response 1-4 bytes
    *
    * @return E_ILLEGAL_PARAM is no response for this command
    */
   ErrorCode getResponse(uint32_t response[]);

   /**
    * Report information about a SD card from CID register
    *
    * @param cid  Contents of card CID register
    */
   static void reportCard(const SdhcCidRegister &cid);

   /**
    * Get name of SD card state
    *
    * @param state   State of SD card
    *
    * @return  Pointer to static string
    */
   const char *getStateName(uint8_t state);

   /**
    * Query SD card state and report
    *
    * @param msg  Message for report
    */
   void reportState(const char *msg);

   /**
    * Check response from R1 type command.
    * This will check the rc provided and then check the command response from SD card
    *
    * @param rcFromCommand Return value from command execution
    *
    * @return  E_NO_ERROR      Command executed successfully
    * @return  RES_NOTRDY  Command execution failed or card response indicated errors
    *
    * @note sdhcR1Response is updated with R1 response (if command executed)
    */
   ErrorCode checkR1Command(ErrorCode rcFromCommand);

   /**
    * Check response from R6 type command.
    * This will check the rc provided and then check the command response from SD card
    *
    * @param rcFromCommand Return value from command execution
    *
    * @return  E_NO_ERROR     Command executed successfully
    * @return  RES_NOTRDY Command execution failed or card response indicated errors
    *
    * @note sdhcR6Response is updated with R6 response (if command executed)
    */
   ErrorCode processR6Command(ErrorCode rcFromCommand);

   /**
    * Read blocks from card
    *
    * @param buffer        Buffer for data read
    * @param blockNumber   Number of 1st block
    * @param blockCount    Number of blocks
    *
    * @return
    */
   DRESULT SD_Read(uint8_t *buffer, uint32_t blockNumber, uint16_t blockCount);

   /**
    * Write blocks to card
    *
    * @param buffer        Buffer for data write
    * @param blockNumber   Number of 1st block
    * @param blockCount    Number of blocks
    *
    * @return
    */
   DRESULT SD_Write(const uint8_t *buffer, uint32_t blockNumber, uint16_t blockCount);

   /**
    * Initialisation value for Sdhc
    * This value is created from Configure.usbdmProject settings
    */
   static constexpr SdhcBasicInfo::Init initValue = {
         SdhcWakeupOnCardRemoval_Disabled ,             // (sdhc_proctl_wecrm) Wakeup Event Enable On SD Card Removal
         SdhcWakeupOnCardInsertion_Disabled ,           // (sdhc_proctl_wecins) Wakeup Event Enable On SD Card Insertion
         SdhcWakeupOnCardInterrupt_Disabled ,           // (sdhc_proctl_wecint) Wakeup Event Enable On Card Interrupt
         SdhcInterruptAtBlockGap_Disabled ,             // (sdhc_proctl_iabg) Interrupt At Block Gap
         SdhcReadWaitControl_StopClock ,                // (sdhc_proctl_rwctl) Read Wait Control
         SdhcContinueRequest_NoEffect ,                 // (sdhc_proctl_creq) Continue Request
         SdhcStopAtBlockGapRequest_Transfer ,           // (sdhc_proctl_sabgreq) Stop At Block Gap Request
         dmaMode ,                                      // (sdhc_proctl_dmas) DMA Select
         SdhcEndianMode_LittleEndianMode ,              // (sdhc_proctl_emode) Endian Mode
         SdhcCardDetectMode_Disabled ,                  // (sdhc_proctl_d3cd) DAT3 as Card Detection Pin
         SdhcTransferWidth_1BitMode ,                   // (sdhc_proctl_dtw) Data Transfer Width
         SdhcDataTimeout_SDCLKx2_27 ,                   // (sdhc_sysctl_dtocv) Data Timeout Counter Value
         SdhcClockPrescaler_DivBy32 ,                   // (sdhc_sysctl_sdclkfs) SDCLK Prescale Select - Base clock divided by 32
         SdhcSysctlDvs_DivBy10 ,                        // (sdhc_sysctl_dvs) SDCLK Clock Divisor - Prescale clock divided by 10
         SdhcPeripheralClock_NotAutomaticallyGatedOff , // (sdhc_sysctl_peren) Peripheral Clock Enable
         SdhcSystemClock_NotAutomaticallyGatedOff ,     // (sdhc_sysctl_hcken) System Clock Enable
         SdhcBusClock_NotAutomaticallyGatedOff ,        // (sdhc_sysctl_ipgen) IPG Clock Enable

         SdhcStatusFlagEnable::CommandIndexError |      // (sdhc_irqstaten) Interrupt Status Flag Enables
         SdhcStatusFlagEnable::CommandCrcError |
         SdhcStatusFlagEnable::CommandEndBitError |
         SdhcStatusFlagEnable::CommandTimeoutError |
         SdhcStatusFlagEnable::CommandComplete |
         SdhcStatusFlagEnable::DataTimeoutError |
         SdhcStatusFlagEnable::DataCrcError |
         SdhcStatusFlagEnable::DataEndBitError |
         SdhcStatusFlagEnable::CommandComplete |
         SdhcStatusFlagEnable::TransferComplete |
         SdhcStatusFlagEnable::AutoCommand12Error |
         SdhcStatusFlagEnable::BufferReadReady |
         SdhcStatusFlagEnable::BufferWriteReady |
         SdhcStatusFlagEnable::DmaError |
         SdhcStatusFlagEnable::DmaComplete,

         SdhcInterruptEnable::CommandIndexError |       // (sdhc_irqsigen) Interrupt Enables
         SdhcInterruptEnable::CommandCrcError |
         SdhcInterruptEnable::CommandEndBitError |
         SdhcInterruptEnable::CommandTimeoutError |
         SdhcInterruptEnable::CommandComplete |
         SdhcInterruptEnable::DataTimeoutError |
         SdhcInterruptEnable::DataCrcError |
         SdhcInterruptEnable::DataEndBitError |
         SdhcInterruptEnable::CommandComplete |
         SdhcInterruptEnable::TransferComplete |
         SdhcInterruptEnable::AutoCommand12Error |
         SdhcInterruptEnable::BufferReadReady |
         SdhcInterruptEnable::BufferWriteReady |
         SdhcInterruptEnable::DmaError |
         SdhcInterruptEnable::DmaComplete,

         SdhcWriteWaterLevel(128) ,                 // (sdhc_wml_wrwml) Write Watermark Level
         SdhcReadWaterLevel(128) ,                  // (sdhc_wml_rdwml) Read Watermark Level
         SdhcExactBlockNumberForCmd53_Disabled,     // (sdhc_vendor_exblknu) SDIO CMD53 Exact Block Number Block Read Enable For SDIO CMD53 - Exact block read for SDIO CMD53
         NvicPriority_Disabled,                     // (irqLevel) IRQ priority level - Normal
   };

public:

   /**
    * Create SDHC Interface for SD card
    *
    * @tparam T      Type of SDHC (Inferred)
    * @param sdhc    SDHC Interface to use
    */
   template<typename T>
   SdhcInterface(const T &sdhc) : sdhc(sdhc) {
      sdhc.configure(initValue);
   }

   /**
    * Destructor
    */
   virtual ~SdhcInterface() = default;

   /**
    * Initialise Disk Drive
    *
    * @return  E_NO_ERROR     Disk initialised successfully
    * @return  RES_NOTRDY Disk initialisation failed
    */
   virtual DSTATUS disk_initialize() override;

   /**
    * Get Disk Status
    *
    * @param drv     Physical drive number (Always 0)
    *
    * @return  Status
    */
   virtual DSTATUS disk_status() override;

   /**
    * Read Blocks
    *
    * @param buffer      Pointer to the read data buffer
    * @param startBlock  Block sector number
    * @param blockCount  Number of blocks to read
    *
    * @return  Error code
    */
   virtual DRESULT disk_read(uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) override;

   /**
    * Write Blocks
    *
    * @param buffer      Pointer to the read data buffer
    * @param startBlock  Block sector number
    * @param blockCount  Number of blocks to read
    *
    * @return  Error code
    */
   virtual DRESULT disk_write(const uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) override;

   /**
    * IO Control Functions
    *
    * @param ctrl Select action
    * @param buff buffer for result
    *
    * @return  Error code
    */
   virtual DRESULT disk_ioctl(uint8_t ctrl, void *buff) override;
};

} // namespace USBDM

#endif // INCLUDE_USBDM_SD_SDHC_H_

