/**
 *    FatFS SPI SDCARD interface
 */

#include "ff.h"       // Obtains integer types for FatFs
#include "diskio.h"   // Common include file for FatFs and disk I/O layer

#include "hardware.h"
#include "spi.h"
#include "sd_spi.h"

using namespace USBDM;

/* MMC/SD command (SPI mode) */
#define CMD0_GO_IDLE                      (0)         /* GO_IDLE_STATE */
#define CMD1_SEND_OP_COND                 (1)         /* SEND_OP_COND */
#define ACMD41_SEND_OP_COND               (0x80+41)   /* SEND_OP_COND (SDC) */
#define CMD8_SEND_IF_COND                 (8)         /* SEND_IF_COND */
#define CMD9_SEND_CSD                     (9)         /* SEND_CSD */
#define CMD10_SEND_CID                    (10)        /* SEND_CID */
#define CMD12_STOP_TRANSMISSION           (12)        /* STOP_TRANSMISSION */
#define CMD13_SEND_STATUS                 (13)        /* SEND_STATUS */
#define ACMD13_SD_STATUS                  (0x80+13)   /* SD_STATUS (SDC) */
#define CMD16_SET_BLOCKLEN                (16)        /* SET_BLOCKLEN */
#define CMD17_READ_SINGLE_BLOCK           (17)        /* READ_SINGLE_BLOCK */
#define CMD18_READ_MULTIPLE_BLOCK         (18)        /* READ_MULTIPLE_BLOCK */
#define CMD23_SET_BLOCK_COUNT             (23)        /* SET_BLOCK_COUNT */
#define ACMD23_SET_WR_BLK_ERASE_COUNT     (0x80+23)   /* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24_WRITE_CLOCK                 (24)        /* WRITE_BLOCK */
#define CMD25_WRITE_MULTIPLE_CLOCK        (25)        /* WRITE_MULTIPLE_BLOCK */
#define CMD32_ERASE_ER_BLK_START          (32)        /* ERASE_ER_BLK_START */
#define CMD33_ERASE_ER_BLK_END            (33)        /* ERASE_ER_BLK_END */
#define CMD38_ERASE                       (38)        /* ERASE */
#define CMD55_APP_CMD                     (55)        /* APP_CMD */
#define CMD58_READ_OCR                    (58)        /* READ_OCR */

/**
 * Create SPI base SDCARD interface
 *
 * @param spi  SPI to use
 * @param cs   Gpio for SPI CS
 */
SpiSdcard::SpiSdcard(Spi &spi, const Gpio &cs) : spi(spi), cs(cs) {

   // This method is time consuming as it calculates several derived parameters
   spi.setConfiguration(spiConfig);

   // Peripheral settings to use with above configuration
   spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_None, SpiPeripheralSelectMode_Transaction);

   // Save the derived configuration
   spiCalculatedConfig = spi.getConfiguration();
}

/**
 * Transmit bytes to the card
 *
 * @param buff    Buffer to send
 * @param bc      Number of bytes
 */
void SpiSdcard::xmit_mmc(const uint8_t* buff, unsigned bc ) {
   spi.startTransaction(spiCalculatedConfig);
   spi.txRx(bc, buff, (uint8_t*)nullptr);
   spi.endTransaction();
}

/**
 * Receive bytes from the card (bit-banging)
 *
 * @param buff    Buffer for reception
 * @param bc      Number of bytes
 */
void SpiSdcard::rcvr_mmc(uint8_t *buff, unsigned bc) {
   spi.startTransaction(spiCalculatedConfig);
   spi.txRx(bc, (uint8_t*)nullptr, buff);
   spi.endTransaction();
}

/**
 * Wait for card ready
 *
 * @return true  => Ready
 * @return false => Timeout
 */
bool SpiSdcard::wait_ready (void)
{
   uint8_t d;
   unsigned tmr;

   for (tmr = 5000; tmr; tmr--) {   /* Wait for ready in timeout of 500ms */
      rcvr_mmc(&d, 1);
      if (d == 0xFF) {
         break;
      }
      waitUS(100);
   }
   return tmr > 0;
}

/**
 * De-select the card and release SPI bus
 */
void SpiSdcard::deselect (void) {

   uint8_t d;

   cs.high();         /* Set CS# high */
   rcvr_mmc(&d, 1);   /* Dummy clock (force DO hi-z for multiple slave SPI) */
}

/**
 * Select the card and wait for ready
 *
 * @return true  => Ready
 * @return false => Timeout
 */
int SpiSdcard::select (void) {
   uint8_t d;

   cs.low();         /* Set CS# low */
   rcvr_mmc(&d, 1);   /* Dummy clock (force DO enabled) */
   if (wait_ready()) {
      return 1;   /* Wait for card ready */
   }
   deselect();
   return 0;         /* Failed */
}

/**
 * Receive a data packet from the card
 *
 * @param buff Data buffer to store received data
 * @param btr  Byte count
 *
 * @return 1:OK, 0:Failed
 */
int SpiSdcard::rcvr_datablock (uint8_t *buff, unsigned btr) {
   uint8_t d[2];
   unsigned tmr;


   for (tmr = 1000; tmr; tmr--) {   /* Wait for data packet in timeout of 100ms */
      rcvr_mmc(d, 1);
      if (d[0] != 0xFF) {
         break;
      }
      waitUS(100);
   }
   if (d[0] != 0xFE) {
      return 0;      /* If not valid data token, return with error */
   }

   rcvr_mmc(buff, btr);         /* Receive the data block into buffer */
   rcvr_mmc(d, 2);               /* Discard CRC */

   return 1;                  /* Return with success */
}

/**
 * Send a data packet to the card
 *
 * @param buff    512 byte data block to be transmitted
 * @param token   Data/Stop token
 *
 * @return  1:OK, 0:Failed
 */
int SpiSdcard::xmit_datablock (const uint8_t *buff, uint8_t token) {

   uint8_t d[2];

   if (!wait_ready()) return 0;

   d[0] = token;
   xmit_mmc(d, 1);            /* Xmit a token */
   if (token != 0xFD) {      /* Is it data token? */
      xmit_mmc(buff, 512);   /* Xmit the 512 byte data block to MMC */
      rcvr_mmc(d, 2);         /* Xmit dummy CRC (0xFF,0xFF) */
      rcvr_mmc(d, 1);         /* Receive data response */
      if ((d[0] & 0x1F) != 0x05) {  /* If not accepted, return with error */
         return 0;
      }
   }
   return 1;
}

/**
 * Send a command packet to the card
 *
 * @param cmd  Command byte to send (bit7===1: Indicates an application specific command)
 * @param arg  Argument for command
 *
 * @return Status value from card (bit7==1:Send failed)
 */
uint8_t SpiSdcard::send_cmd (uint8_t cmd, uint32_t arg) {

   uint8_t n, d, buf[6];

   if (cmd & 0x80) {   /* ACMD<n> is the command sequence of CMD55_APP_CMD-CMD<n> */
      cmd &= 0x7F;
      n = send_cmd(CMD55_APP_CMD, 0);
      if (n > 1) {
         return n;
      }
   }

   /* Select the card and wait for ready except to stop multiple block read */
   if (cmd != CMD12_STOP_TRANSMISSION) {
      deselect();
      if (!select()) {
         return 0xFF;
      }
   }

   /* Send a command packet */
   buf[0] = 0x40 | cmd;             /* Start + Command index */
   buf[1] = (uint8_t)(arg >> 24);   /* Argument[31..24] */
   buf[2] = (uint8_t)(arg >> 16);   /* Argument[23..16] */
   buf[3] = (uint8_t)(arg >> 8);    /* Argument[15..8] */
   buf[4] = (uint8_t)arg;           /* Argument[7..0] */
   n = 0x01;                        /* Dummy CRC + Stop */
   if (cmd == CMD0_GO_IDLE) {
      n = 0x95;      /* (valid CRC for CMD0_GO_IDLE(0)) */
   }
   if (cmd == CMD8_SEND_IF_COND) {
      n = 0x87;      /* (valid CRC for CMD8_SEND_IF_COND(0x1AA)) */
   }
   buf[5] = n;
   xmit_mmc(buf, 6);

   /* Receive command response */
   if (cmd == CMD12_STOP_TRANSMISSION) {
      rcvr_mmc(&d, 1);   /* Skip a stuff byte when stop reading */
   }
   n = 10; /* Wait for a valid response in timeout of 10 attempts */
   do
      rcvr_mmc(&d, 1);
   while ((d & 0x80) && --n);

   return d;         /* Return with the response value */
}

/**
 * Get Disk Status
 *
 * @param drv     Physical drive number (Always 0)
 *
 * @return  Status
 */
DSTATUS SpiSdcard::disk_status () {
   return Stat;
}

/**
 * Read Sector(s)
 *
 * @param drv     Physical drive number (Always 0)
 * @param buff    Buffer for data
 * @param sector  Start sector number (LBA)
 * @param count   Sector count (1..128)
 *
 * @return  Status
 */
DRESULT SpiSdcard::disk_read (uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) {

   uint8_t cmd;
   uint32_t sect = (uint32_t)startBlock;

   if (disk_status() & STA_NOINIT) {
      return RES_NOTRDY;
   }
   if (!(cardType & CT_BLOCK)) {
      sect *= 512;   /* Convert LBA to byte address if needed */
   }

   cmd = blockCount > 1 ? CMD18_READ_MULTIPLE_BLOCK : CMD17_READ_SINGLE_BLOCK;         /*  READ_MULTIPLE_BLOCK : READ_SINGLE_BLOCK */
   if (send_cmd(cmd, sect) == 0) {
      do {
         if (!rcvr_datablock(buffer, 512)) {
            break;
         }
         buffer += 512;
      } while (--blockCount);
      if (cmd == CMD18_READ_MULTIPLE_BLOCK) {
         send_cmd(CMD12_STOP_TRANSMISSION, 0);   /* STOP_TRANSMISSION */
      }
   }
   deselect();

   return blockCount ? RES_ERROR : RES_OK;
}

/**
 * Write Sector(s)
 *
 * @param drv     Physical drive number (Always 0)
 * @param buff    Buffer for data
 * @param sector  Start sector number (LBA)
 * @param count   Sector count (1..128)
 *
 * @return  Status
 */
DRESULT SpiSdcard::disk_write(const uint8_t *buffer, uint32_t startBlock, uint32_t blockCount) {

   uint32_t sect = (uint32_t)startBlock;

   if (disk_status() & STA_NOINIT) {
      return RES_NOTRDY;
   }
   if (!(cardType & CT_BLOCK)) sect *= 512;   /* Convert LBA to byte address if needed */

   if (blockCount == 1) {   /* Single block write */
      if ((send_cmd(CMD24_WRITE_CLOCK, sect) == 0)   /* WRITE_BLOCK */
            && xmit_datablock(buffer, 0xFE))
         blockCount = 0;
   }
   else {            /* Multiple block write */
      if (cardType & CT_SDC) send_cmd(ACMD23_SET_WR_BLK_ERASE_COUNT, blockCount);
      if (send_cmd(CMD25_WRITE_MULTIPLE_CLOCK, sect) == 0) {   /* WRITE_MULTIPLE_BLOCK */
         do {
            if (!xmit_datablock(buffer, 0xFC)) {
               break;
            }
            buffer += 512;
         } while (--blockCount);
         if (!xmit_datablock(0, 0xFD))   /* STOP_TRAN token */
            blockCount = 1;
      }
   }
   deselect();

   return blockCount ? RES_ERROR : RES_OK;
}

/**
 * Initialise Disk Drive
 *
 * @param drv  Physical drive number (0)
 *
 * @return Status
 */
DSTATUS SpiSdcard::disk_initialize() {

   uint8_t n, ty, cmd, buf[4];
   unsigned tmr;
   DSTATUS s;

   // 10ms init
   waitMS(10);

   for (n = 10; n; n--) {
      rcvr_mmc(buf, 1);   /* Apply 80 dummy clocks and the card gets ready to receive command */
   }

   for (n = 10; n; n--) {
      /* Enter Idle state */
      if (send_cmd(CMD0_GO_IDLE, 0) == 0b1) {
         break;
      }
   }

   ty = 0;
   if (n>0) {
      /* OK entered Idle state */
      if (send_cmd(CMD8_SEND_IF_COND, 0x1AA) == 1) {   /* SDv2? */
         rcvr_mmc(buf, 4);                     /* Get trailing return value of R7 resp */
         if (buf[2] == 0x01 && buf[3] == 0xAA) {      /* The card can work at vdd range of 2.7-3.6V */
            for (tmr = 1000; tmr; tmr--) {         /* Wait for leaving idle state (ACMD41_SEND_OP_COND with HCS bit) */
               if (send_cmd(ACMD41_SEND_OP_COND, 1UL << 30) == 0) {
                  break;
               }
               waitMS(1);
            }
            if (tmr && send_cmd(CMD58_READ_OCR, 0) == 0) {   /* Check CCS bit in the OCR */
               rcvr_mmc(buf, 4);
               ty = (buf[0] & 0x40) ? CT_SDC2 | CT_BLOCK : CT_SDC2;   /* SDv2+ */
            }
         }
      } else {                     /* SDv1 or MMCv3 */
         if (send_cmd(ACMD41_SEND_OP_COND, 0) <= 1)    {
            ty = CT_SDC2; cmd = ACMD41_SEND_OP_COND;   /* SDv1 */
         } else {
            ty = CT_MMC3; cmd = CMD1_SEND_OP_COND;   /* MMCv3 */
         }
         for (tmr = 1000; tmr; tmr--) {         /* Wait for leaving idle state */
            if (send_cmd(cmd, 0) == 0) {
               break;
            }
            waitMS(1);
         }
         if (!tmr || send_cmd(CMD16_SET_BLOCKLEN, 512) != 0)   /* Set R/W block length to 512 */
            ty = 0;
      }
   }
   cardType = ty;
   s = ty ? 0 : STA_NOINIT;
   Stat = s;

   deselect();

   return s;
}

/**
 * Miscellaneous Functions
 *
 * @param drv     Physical drive number (Always 0)
 * @param ctrl    Control code
 * @param buff    Buffer to send/receive control data
 *
 * @return  Status
 */
DRESULT SpiSdcard::disk_ioctl (uint8_t ctrl, void *buff) {

   DRESULT res;
   uint8_t n, csd[16];
   uint32_t cs;

   if (disk_status() & STA_NOINIT) return RES_NOTRDY;   /* Check if card is in the socket */

   res = RES_ERROR;
   switch (ctrl) {
      case CTRL_SYNC :      /* Make sure that no pending write process */
         if (select()) res = RES_OK;
         break;

      case GET_SECTOR_COUNT :   /* Get number of sectors on the disk (uint32_t) */
         if ((send_cmd(CMD9_SEND_CSD, 0) == 0) && rcvr_datablock(csd, 16)) {
            if ((csd[0] >> 6) == 1) {   /* SDC ver 2.00 */
               cs = csd[9] + ((WORD)csd[8] << 8) + ((uint32_t)(csd[7] & 63) << 16) + 1;
               *(LBA_t*)buff = cs << 10;
            } else {               /* SDC ver 1.XX or MMC */
               n = (csd[5] & 15) + ((csd[10] & 128) >> 7) + ((csd[9] & 3) << 1) + 2;
               cs = (csd[8] >> 6) + ((WORD)csd[7] << 2) + ((WORD)(csd[6] & 3) << 10) + 1;
               *(LBA_t*)buff = cs << (n - 9);
            }
            res = RES_OK;
         }
         break;

      case GET_BLOCK_SIZE :   /* Get erase block size in unit of sector (uint32_t) */
         *(uint32_t*)buff = 128;
         res = RES_OK;
         break;

      default:
         res = RES_PARERR;
   }

   deselect();

   return res;
}
