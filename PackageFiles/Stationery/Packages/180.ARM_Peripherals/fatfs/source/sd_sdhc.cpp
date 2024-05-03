/**
================================================================================
* @file    sdhc-example.cpp (180.ARM_Peripherals/Snippets/sdhc-example.cpp)
* @brief   SDHC Controller example for MK28_FRDM
*
*  Created on: 20/11/2021
*      Author: podonoghue
================================================================================
*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <memory.h>
#include "fatfs.h"
#include "hardware.h"
#include "sdhc.h"
#include "diskio.h"
#include "mpu.h"

#include "sd_sdhc.h"

using namespace USBDM;

static_assert(FF_MIN_SS==FF_MAX_SS);
static_assert(FF_MIN_SS==SDHC_DEFAULT_BLOCK_SIZE);

/**
 * Set SD Card active
 * Sends 80 clocks to the card to set it to the active state.
 * This function must be called each time the card is inserted to ensure that
 * the card can receive the command correctly.
 */
void SdhcInterface::setCardActive() {

   sdhc.setInitialise(SdhcInitialise_active);
   while(sdhc.getInitialise()) {
      // Wait until complete (flag to clear)
      __asm__("nop");
   }
}

/**
 * Execute a non-data command
 *
 * @param sdhcCommand         Command to execute
 * @param sdhcCommandArgument Argument for command (defaults to 0)
 *
 * @return E_NO_ERROR      Successfully executed command
 * @return E_TIMEOUT       Timeout while executing command (no response from card)
 * @return E_ILLEGAL_PARAM Failed to execute command due to invalid parameters
 * @return E_ERROR         Failed to execute command (error during execution etc)
 */
ErrorCode SdhcInterface::executeCommand(const SdhcCommand sdhcCommand, const uint32_t &sdhcCommandArgument) {

   if (sdhcCommand&SDHC_XFERTYP_DPSEL_MASK) {
      // Should be a data transfer
      return E_ILLEGAL_PARAM;
   }
   if (sdhcCommand&SDHC_XFERTYP_ACMD_MASK) {
      // Prefix ACMDx with CMD55_APP_CMD command
      ErrorCode rc = checkR1Command(executeCommand(SdhcCommand_CMD55_APP_CMD, cardRelativeAddress<<16));
      if (rc != E_NO_ERROR) {
         return rc;
      }
   }
   /*
    * The host driver can issue CMD0, CMD12, CMD13 (for memory) and CMD52 (for SDIO) when the
    * DAT lines are busy during a data transfer.
    * These commands can be issued when Command Inhibit (CIHB=CmdInhibit) is clear.
    * Other commands shall be issued when Command Data Inhibit (CDIHB=DatCmdInhibit) is clear.
    */
   const SdhcStateFlags checkFlag = (sdhcCommand&SDHC_XFERTYP_BUSYCHK_MASK)?
         SdhcStateFlags::CmdInhibit:
         SdhcStateFlags::CmdInhibit|SdhcStateFlags::DatCmdInhibit;
   while (sdhc.getState()&checkFlag) {
      __asm__("nop");
   }
   static constexpr SdhcStatusFlag errorFlags =
         SdhcStatusFlag::AutoCommand12Error|
         SdhcStatusFlag::CommandCrcError|
         SdhcStatusFlag::CommandEndBitError|
         SdhcStatusFlag::CommandIndexError|
         SdhcStatusFlag::CommandTimeoutError|
         SdhcStatusFlag::TransferComplete;

   // Clear out special flag bits
   SdhcCommand finalSdhcCommand = SdhcCommand(sdhcCommand&0x3FFF'FFFF);

   sdhc.clearInterruptStatus(SdhcStatusFlag(-1));
   const Sdhc0::TransferInit transferInit {
      finalSdhcCommand,                            // (sdhc_xfertyp_command) Command Index - WRITE_BLOCK (CMD24,R1)
      SdhcCommandType_Normal ,                     // (sdhc_xfertyp_cmdtyp) Command Type - Normal other commands
      SdhcAutoCmd12Enable_Disable ,                // (sdhc_xfertyp_ac12en) Auto CMD12 Enable - Disable
      SdhcDmaEnable_Disable ,                      // (sdhc_xfertyp_dmaen) DMA Enable - Disable
      SdhcCommandArgument(sdhcCommandArgument) ,   // (sdhc_cmdarg_cmdarg) Command Argument
   };
   lastCommand = sdhcCommand;
   sdhc.configure(transferInit);

   // Wait for command complete or error
   SdhcStatusFlag sdhcStatusFlag;
   do {
      sdhcStatusFlag = sdhc.getInterruptStatus();
   } while (!(sdhcStatusFlag&(errorFlags|SdhcStatusFlag::CommandComplete)));

   if (sdhcStatusFlag&SdhcStatusFlag::CommandTimeoutError) {
      // If command not recognised ...
      return E_TIMEOUT;
   }
   return (sdhcStatusFlag&errorFlags)?E_ERROR:E_NO_ERROR;
}

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
ErrorCode SdhcInterface::executeCommand(
      const SdhcCommand       &sdhcCommand,
      const uint32_t          &sdhcCommandArgument,
      Adma2Descriptor         *descriptors) {

   // Calculate total transfer size in bytes
   uint32_t transferSize = 0;
   Adma2Descriptor *descript=descriptors;
   int limit=0;
   while (true) {
      transferSize += descript->length;
      if (descript->end) {
         break;
      }
      descript++;
      if (++limit>10) {
         // Too many descriptors!
         return E_ILLEGAL_PARAM;
      }
   };

   if (!(sdhcCommand&SDHC_XFERTYP_DPSEL_MASK)) {
      // Should not be a data transfer
      return E_ILLEGAL_PARAM;
   }
   if (sdhcCommand&SDHC_XFERTYP_ACMD_MASK) {
      // Prefix ACMDx with CMD55_APP_CMD command
      ErrorCode rc = executeCommand(SdhcCommand_CMD55_APP_CMD, 0);
      if (rc != E_NO_ERROR) {
         return rc;
      }
   }
   /*
    * The host driver can issue CMD0, CMD12, CMD13 (for memory) and CMD52 (for SDIO) when the
    * DAT lines are busy during a data transfer.
    * These commands can be issued when Command Inhibit (CIHB=CmdInhibit) is clear.
    * Other commands shall be issued when Command Data Inhibit (CDIHB=DatCmdInhibit) is clear.
    */
   const SdhcStateFlags checkFlag = (sdhcCommand&SDHC_XFERTYP_BUSYCHK_MASK)?
         SdhcStateFlags::CmdInhibit:
         SdhcStateFlags::CmdInhibit|SdhcStateFlags::DatCmdInhibit;
   while (sdhc.getState()&checkFlag) {
      __asm__("nop");
   }

   // Flags for errors that need to be checked
   static constexpr SdhcStatusFlag errorFlags =
         SdhcStatusFlag::AutoCommand12Error|
         SdhcStatusFlag::CommandCrcError|
         SdhcStatusFlag::CommandEndBitError|
         SdhcStatusFlag::CommandIndexError|
         SdhcStatusFlag::CommandTimeoutError|
         SdhcStatusFlag::DmaError;

   // Clear out special flag bits
   SdhcCommand finalSdhcCommand = SdhcCommand(sdhcCommand&0x3FFF'FFFF);

   sdhc.clearInterruptStatus(SdhcStatusFlag(-1));
   const Sdhc0::TransferInit transferInit {
      finalSdhcCommand,                            // (sdhc_xfertyp_command) Command Index - WRITE_BLOCK (CMD24,R1)
      SdhcCommandArgument(sdhcCommandArgument) ,   // (sdhc_cmdarg_cmdarg) Command Argument
      SdhcCommandType_Normal ,                     // (sdhc_xfertyp_cmdtyp) Command Type - Normal other commands
      SdhcAutoCmd12Enable_Enable ,                 // (sdhc_xfertyp_ac12en) Auto CMD12 Enable - Disable
      SdhcDmaEnable_Enable ,                       // (sdhc_xfertyp_dmaen) DMA Enable - Disable
      SdhcAdmaSystemAddress(uint32_t(descriptors)),
      SdhcBlockCount(transferSize/SDHC_DEFAULT_BLOCK_SIZE),
      SdhcBlockSize(SDHC_DEFAULT_BLOCK_SIZE),
   };
//      console.writeln("xfertyp.cmdindx = 0x", transferInit.xfertyp>>24, Radix_16);
//      console.writeln("xfertyp         = 0x", transferInit.xfertyp&0xFFFFFF, Radix_16);
//      console.writeln("cmdarg          = 0x", transferInit.cmdarg,  Radix_16);
//      console.writeln("adsaddr         = 0x", transferInit.adsaddr, Radix_16);
//      console.writeln("dsaddr          = 0x", transferInit.dsaddr,  Radix_16);
//      console.writeln("blkattr(cnt,sz) =   ", transferInit.blkattr>>16, ", ", transferInit.blkattr&0xFFFF);
//
//      console.writeln("address         = 0x", descriptors->address,  Radix_16);
//      console.writeln("length          = 0x", descriptors->length,   Radix_16, " (", descriptors->length/(transferInit.blkattr&0xFFFF), " blocks)");
//      console.writeln("valid           =   ", descriptors->valid);
//      console.writeln("end             =   ", descriptors->end);
//      console.writeln("action          =   ", descriptors->getActionName());
//      console.writeln("interrupt       =   ", descriptors->interrupt);

   sdhc.configure(transferInit);

   // Wait for command complete or error
   SdhcStatusFlag sdhcStatusFlag;
   do {
      sdhcStatusFlag = sdhc.getInterruptStatus();
   } while (!(sdhcStatusFlag&(errorFlags|SdhcStatusFlag::CommandComplete)));

   // Wait for transfer complete or error
   do {
      sdhcStatusFlag = sdhc.getInterruptStatus();
   } while (!(sdhcStatusFlag&(errorFlags|SdhcStatusFlag::TransferComplete)));

   if (sdhcStatusFlag&SdhcStatusFlag::CommandTimeoutError) {
      // If command not recognised ...
      return E_TIMEOUT;
   }
   return (sdhcStatusFlag&errorFlags)?E_ERROR:E_NO_ERROR;
}

/**
 * Get response value from SD card from last command
 *
 * @param response      Buffer for response 1-4 bytes
 *
 * @return E_ILLEGAL_PARAM is no response for this command
 */
ErrorCode SdhcInterface::getResponse(uint32_t response[]) {

   switch(lastCommand&(SDHC_XFERTYP_RSPTYP_MASK|SDHC_XFERTYP_CICEN_MASK|SDHC_XFERTYP_CCCEN_MASK)) {
      case SdhcResponse_None:
         response[0] = 0;
         return E_ILLEGAL_PARAM;
         break;
      default: // 48 bits - returns 32
         response[0] = sdhc.getCommandResponse(0);
         break;
      case SdhcResponse_R2: // 136 bits - returns 128 bits right-justified as 4 uint32_t BE!
         //                                      Register bits => Response bits
         response[0] = sdhc.getCommandResponse(3); // [23:0]   => [127:104]
         response[1] = sdhc.getCommandResponse(2); // [31:0]   => [103:72]
         response[2] = sdhc.getCommandResponse(1); // [31:0]   => [71:40]
         response[3] = sdhc.getCommandResponse(0); // [31:0]   => [39:8]
         break;
      case SdhcResponse_R1b: // 48 bits - returns 32
         response[0] = sdhc.getCommandResponse(0);
         break;
   }
   return E_NO_ERROR;
}

/**
 * Report information about a SD card from CID register (for debug)
 *
 * @param cid  Contents of card CID register
 */
void SdhcInterface::reportCard(const SdhcCidRegister &cid) {
   console.writeln("Manufacturer ID   : 0x", cid.mid, Radix_16);
   console.writeln("OEM ID            : ", cid.oid[0],cid.oid[1]);
   console.writeln("Product Name      : ", cid.pnm[0],cid.pnm[1],cid.pnm[2],cid.pnm[3],cid.pnm[4]);
   console.writeln("Revision          : 0x", cid.prv, Radix_16);
   console.writeln("Serial No         : ", cid.psn);
   console.writeln("Date              : ", 2000+(((cid.mdt>>4)&0xFF)), ".", (cid.mdt&0xF));
}

/**
 * Get name of SD card state (for debug)
 *
 * @param state   State of SD card
 *
 * @return  Pointer to static string
 */
const char *SdhcInterface::getStateName(uint8_t state) {
   static const char *stateName[] = {
         "Idle","Ready","Identification",                                              // Card Identification Mode
         "Stand-by","Transfer","Send-data","Receive-data","Programming","Disconnect",  // Data Transfer Mode
         "Inactive",                                                                   // Inactive Mode
         "-","-","-","-","-","-",
   };
   return stateName[state&0xF];
}

/**
 * Query SD card state and report to console (for debug)
 *
 * @param msg  Message for report
 */
void SdhcInterface::reportState(const char *msg) {

   //============= CMD13
   ErrorCode rc = executeCommand(SdhcCommand_CMD13_SEND_STATUS, cardRelativeAddress<<16);
   if (rc != E_NO_ERROR) {
      console.writeln("Failed to get status");
   }
   uint32_t response[4];
   rc = getResponse(response);
   if (rc != E_NO_ERROR) {
      console.writeln(msg, "Failed CMD13 response");
   }
   SdhcR1Response sdhcR1Response{response[0]};
   console.writeln(msg," State = ", getStateName(sdhcR1Response.CURRENT_STATE));
}

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
ErrorCode SdhcInterface::checkR1Command(ErrorCode rcFromCommand) {

   if (rcFromCommand != E_NO_ERROR) {
      return rcFromCommand;
   }

   // Response buffer
   uint32_t response[4];

   ErrorCode rc = getResponse(response);
   if (rc != E_NO_ERROR) {
      return rc;
   }

   SdhcR1Response sdhcR1Response(response[0]);
   if ((sdhcR1Response.value&SdhcR1Response::AllErrorsMask) != 0) {
      return E_ERROR;
   }
   return E_NO_ERROR;
}

/**
 * Process response from R6 type command.
 * This will check the rc provided and then check the command response from SD card
 * The Card Relative Address is updated
 *
 * @param rcFromCommand Return value from command execution
 *
 * @return  E_NO_ERROR     Command executed successfully
 * @return  RES_NOTRDY Command execution failed or card response indicated errors
 *
 * @note sdhcR6Response is updated with R6 response (if command executed)
 */
ErrorCode SdhcInterface::processR6Command(ErrorCode rcFromCommand) {

   if (rcFromCommand != E_NO_ERROR) {
      return rcFromCommand;
   }

   // Response buffer
   uint32_t response[4];

   ErrorCode rc = getResponse(response);
   if (rc != E_NO_ERROR) {
      return rc;
   }

   SdhcR6Response sdhcR6Response(response[0]);
   if (sdhcR6Response.status&SdhcR6Response::AllErrorsMask) {
      return E_ERROR;
   }
   cardRelativeAddress = sdhcR6Response.RCA;
   return E_NO_ERROR;
}

uint8_t __attribute__((aligned(4))) dataBuffer[SDHC_DEFAULT_BLOCK_SIZE];

/**
 * Read blocks from card
 *
 * @param buffer        Buffer for data read
 * @param blockNumber   Number of 1st block
 * @param blockCount    Number of blocks
 *
 * @return
 */
DRESULT SdhcInterface::SD_Read(uint8_t *buffer, uint32_t blockNumber, uint16_t blockCount) {
//   console.writeln("Reading ", blockCount, " blocks starting at B#", blockNumber, " to 0x", buffer);
   Adma2Descriptor descriptor[] {
      Adma2Descriptor{
      Adma2Action::transferData,
      uint32_t(buffer),
      uint16_t(blockCount*SDHC_DEFAULT_BLOCK_SIZE),
      Adma2Option::endWithInterrupt
      },
   };
   ErrorCode rc = executeCommand(SdhcCommand_CMD18_READ_MULTIPLE_BLOCK, blockNumber, descriptor);
   return (rc==E_NO_ERROR)?RES_OK:RES_ERROR;
}

/**
 * Write blocks to card
 *
 * @param buffer        Buffer for data write
 * @param blockNumber   Number of 1st block
 * @param blockCount    Number of blocks
 *
 * @return
 */
DRESULT SdhcInterface::SD_Write(const uint8_t *buffer, uint32_t blockNumber, uint16_t blockCount) {
   console.writeln("Writing ", blockCount, " blocks starting at B#", blockNumber, " from 0x", buffer);
   Adma2Descriptor descriptor[] {
      Adma2Descriptor{
      Adma2Action::transferData,
      uint32_t(buffer),
      uint16_t(blockCount*SDHC_DEFAULT_BLOCK_SIZE),
      Adma2Option::endWithInterrupt
      },
   };
   ErrorCode rc = executeCommand(SdhcCommand_CMD25_WRITE_MULTIPLE_BLOCK, blockNumber, descriptor);
   return (rc==E_NO_ERROR)?RES_OK:RES_ERROR;
}

/**
 * Initialise Disk Drive
 *
 * @return  E_NO_ERROR     Disk initialised successfully
 * @return  RES_NOTRDY Disk initialisation failed
 */
DSTATUS SdhcInterface::disk_initialize() {

   // Assume failed
   Stat = RES_NOTRDY;

//   setTransferInterrupt(true);

   // Response buffer
   uint32_t response[4];

   // 80 clocks to card
   setCardActive();

   //============= CMD0
   // Idle mode
   ErrorCode rc = executeCommand(SdhcCommand_CMD0_GO_IDLE_STATE,0);
   if (rc != E_NO_ERROR) {
      return rc;
   }

   // Acceptable voltage range
   SdhcOcrValue acmd41Args =
         SdhcOcrValue::Supports_3_2V_3_3V|
         SdhcOcrValue::Supports_3_3V_3_4V;

   //============= CMD8
   // Success => CCS=1 SDHC or SDXC card
   // Success => CCS=0 SDSC card
   // Timeout => Assume SDSC card

   //=================================================
   // card-identification-mode
   //=================================================

   //Check pattern + 2.7-3.6V
   constexpr SdhcR7Response cmd8Arg{0xAA,SdhcR7Response::V2_7_3_6,false,false};
   rc = executeCommand(SdhcCommand_CMD8_SEND_IF_COND, cmd8Arg.value);
   if ((rc != E_NO_ERROR)&&(rc != E_TIMEOUT)) {
      // Card ID failed
      return rc;
   }
   if (rc != E_TIMEOUT) {
      // Check response - should equal command sent
      getResponse(response);
      SdhcR7Response sdhcR7Response(response[0]);
      if (sdhcR7Response != cmd8Arg) {
         // Not OK with proposed voltage or error in check pattern
         return E_ERROR;
      }
      // Turn on check capacity in ACMD41 command
      acmd41Args = acmd41Args | SdhcOcrValue::CardCapacityStatus;
   }

   //============= ACMD41
   // Get Busy, voltage range
   int retry;
   for (retry=12; retry>0; retry--) {

      // Get busy & voltage compliance
      rc = executeCommand(SdhcCommand_ACMD41_SD_APP_OP_COND, uint32_t(acmd41Args));
      if (rc != E_NO_ERROR) {
         // Unusable card
         return rc;
      }
      // Check Busy, voltage range
      getResponse(response);
      if (!(SdhcOcrValue(response[0])&SdhcOcrValue::Ready)) {
         // Card still initialising - wait
         waitMS(100);
         // Try again
         continue;
      }
      bool okVoltage = (SdhcOcrValue(response[0])&(SdhcOcrValue::Supports_3_2V_3_3V|SdhcOcrValue::Supports_3_3V_3_4V));
      if (!okVoltage) {
         // Not suitable
         return E_ERROR;
      }
      if (SdhcOcrValue(response[0])&SdhcOcrValue::CardCapacityStatus) {
         // => SDHC or SDXC card
         cardFlags =  CardFlags(cardFlags | Detected_SDHC_SDXC);
      }
      // Found memory card
      break;
   }
   if (retry == 0) {
      // Failed to initialise memory
      return E_ERROR;
   }

   //============= CMD2
   rc = executeCommand(SdhcCommand_CMD2_ALL_SEND_CID,0);
   if (rc != E_NO_ERROR) {
//      console.writeln("Unable to read CID");
      return rc;
   }
   getResponse(response);
   cid = SdhcCidRegister(response);
   reportCard(cid);

   //============= CMD3
   rc = processR6Command(executeCommand(SdhcCommand_CMD3_SEND_RELATIVE_ADDR,0));
   if (rc != E_NO_ERROR) {
      return rc;
   }

   //=================================================
   // data-transfer-mode  State = Stand-by
   //=================================================

   //============= CMD9
   rc = executeCommand(SdhcCommand_CMD9_SEND_CSD, cardRelativeAddress<<16);
   if (rc != E_NO_ERROR) {
      return rc;
   }
   getResponse(response);
   csd = SdhcCsdRegister(response);

   //============= CMD7
   rc = checkR1Command(executeCommand(SdhcCommand_CMD7_SELECT_CARD, cardRelativeAddress<<16));
   if (rc != E_NO_ERROR) {
      return rc;
   }

   //=================================================
   // data-transfer-mode  State = Transfer
   //=================================================

   rc = sdhc.setSdhcFrequency(25_MHz);
   if (rc != E_NO_ERROR) {
      return rc;
   }

   //============= ACMD6
   rc = checkR1Command(executeCommand(SdhcCommand_ACMD6_SET_BUS_WIDTH, ACMD6_ARG_BUS_WIDTH_4));
   if (rc != E_NO_ERROR) {
      return rc;
   }

   sdhc.setTransferWidth(SdhcTransferWidth_4BitMode);

   //============= CMD16
   rc = checkR1Command(executeCommand(SdhcCommand_CMD16_SET_BLOCKLEN, csd.blockSize));
   if (rc != E_NO_ERROR) {
      return rc;
   }

   sdhc.setTransferWidth(SdhcTransferWidth_4BitMode);

   Stat = RES_OK;

   return E_NO_ERROR;
}

/**
 * Get Disk Status
 *
 * @return  Status
 */
DSTATUS SdhcInterface::disk_status () {
   return Stat;
}

/**
 * Read Blocks
 *
 * @param buffer      Pointer to the read data buffer
 * @param startBlock  Block sector number
 * @param blockCount  Number of blocks to read
 *
 * @return  Error code
 */
DRESULT SdhcInterface::disk_read (uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) {

   // Check if non-aligned address => double buffer
   bool doubleBuffer = (((intptr_t)buffer) & (sizeof(uint32_t) - 1U)) != 0;

   uint32_t  currentBlockNum = startBlock;   // Block number of 1st block in current transfer
   uint8_t  *currentBuffer   = buffer;       // Where to place data from current transfer
   uint32_t  blocksLeft      = blockCount;   // Number of blocks left to transfer

   while (blocksLeft>0) {

      uint32_t blocksThisTransfer;

      if (doubleBuffer) {
         // Double-buffer each block individually
         blocksThisTransfer = 1U;
         memset(dataBuffer, 0U, SDHC_DEFAULT_BLOCK_SIZE);
      }
      else {
         if (blocksLeft > csd.readBlockLength) {
            blocksThisTransfer = csd.readBlockLength;
         }
         else {
            blocksThisTransfer = blocksLeft;
         }
      }
      DRESULT rc = SD_Read(doubleBuffer?dataBuffer:currentBuffer, currentBlockNum, blocksThisTransfer);
      if (rc != RES_OK) {
         return rc;
      }
      if (doubleBuffer) {
//         console.writeln("Copy buffer to ", currentBuffer);
         memcpy(currentBuffer, dataBuffer, SDHC_DEFAULT_BLOCK_SIZE);
      }

      // Update counts
      currentBuffer     += blocksThisTransfer * SDHC_DEFAULT_BLOCK_SIZE;
      currentBlockNum   += blocksThisTransfer;
      blocksLeft        -= blocksThisTransfer;
   }
   return RES_OK;
}

/**
 * Write Blocks
 *
 * @param buffer      Pointer to the read data buffer
 * @param startBlock  Block sector number
 * @param blockCount  Number of blocks to read
 *
 * @return  Error code
 */
DRESULT SdhcInterface::disk_write(const uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) {

   // Check if non-aligned address => double buffer
   bool doubleBuffer = (((intptr_t)buffer) & (sizeof(uint32_t) - 1U)) != 0;

   uint32_t       currentBlockNum = startBlock;   // Block number of 1st block in current transfer
   const uint8_t *currentBuffer   = buffer;       // Where to place data from current transfer
   uint32_t       blocksLeft      = blockCount;   // Number of blocks left to transfer

   while (blocksLeft>0) {

      uint32_t blocksThisTransfer;

      if (doubleBuffer) {
         // Double-buffer each block individually
         blocksThisTransfer = 1U;
         memset(dataBuffer, 0U, SDHC_DEFAULT_BLOCK_SIZE);
      }
      else {
         if (blocksLeft > csd.readBlockLength) {
            blocksThisTransfer = csd.readBlockLength;
         }
         else {
            blocksThisTransfer = blocksLeft;
         }
      }
      if (doubleBuffer) {
//         console.writeln("Copy buffer from ", currentBuffer);
         memcpy(dataBuffer, currentBuffer, SDHC_DEFAULT_BLOCK_SIZE);
      }
      DRESULT rc = SD_Write(doubleBuffer?dataBuffer:currentBuffer, currentBlockNum, blocksThisTransfer);
      if (rc != RES_OK) {
         return rc;
      }

      // Update counts
      currentBuffer     += blocksThisTransfer * SDHC_DEFAULT_BLOCK_SIZE;
      currentBlockNum   += blocksThisTransfer;
      blocksLeft        -= blocksThisTransfer;
   }
   return RES_OK;
}

/**
 * IO Control Functions
 *
 * @param ctrl Select action
 * @param buff buffer for result
 *
 * @return  Error code
 */
DRESULT SdhcInterface::disk_ioctl (BYTE ctrl, void* buff) {

   /* Check if card is in the socket */
   if (disk_status() & STA_NOINIT) {
      return RES_NOTRDY;
   }

   switch (ctrl) {

      case CTRL_SYNC :
         /* Make sure that no pending write process */
         return RES_OK;
         break;

      case GET_SECTOR_COUNT :
         /* Get number of sectors on the disk (uint32_t) */
         *(uint32_t*)buff = (csd.blockSize / csd.blockSize);
         return RES_OK;

      case GET_BLOCK_SIZE :
         /* Get erase block size in unit of sector (uint32_t) */
         *(uint32_t*)buff = csd.blockSize;
         return RES_OK;
   }
   return RES_PARERR;
}
