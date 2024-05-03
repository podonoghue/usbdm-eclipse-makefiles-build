/**
 *    FatFS SPI SDCARD interface
 */
#ifndef INCLUDE_USBDM_SD_SPI_H_
#define INCLUDE_USBDM_SD_SPI_H_

#include "ff.h"       // Obtains integer types for FatFs
#include "diskio.h"   // Common include file for FatFs and disk I/O layer

#include "hardware.h"
#include "spi.h"

namespace USBDM {

class SpiSdcard : public SdInterface {

private:

   enum CardType {
      MMC             = 0xb0,
      SDv1            = 0xb1,
      SDv2            = 0xb2,
      BlockAddressed  = 0xb3,
   };

   Spi         &spi;
   const Gpio  &cs;

   DSTATUS     Stat     = STA_NOINIT;   /* Disk status */
   uint8_t     cardType = 0;            /* b0:MMC, b1:SDv1, b2:SDv2, b3:Block addressing */

   static constexpr Spi0::SerialInit spiConfig{ 10_MHz,  SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_8_bits};

   SpiCalculatedConfiguration spiCalculatedConfig;

   /**
    * Transmit bytes to the card
    *
    * @param buff    Buffer to send
    * @param bc      Number of bytes
    */
   void xmit_mmc(const uint8_t* buff, unsigned bc );

   /**
    * Receive bytes from the card (bit-banging)
    *
    * @param buff    Buffer for reception
    * @param bc      Number of bytes
    */
   void rcvr_mmc (uint8_t *buff, unsigned bc);

   /**
    * Wait for card ready
    *
    * @return true  => Ready
    * @return false => Timeout
    */
   bool wait_ready (void);

   /**
    * De-select the card and release SPI bus
    */
   void deselect (void);

   /**
    * Select the card and wait for ready
    *
    * @return true  => Ready
    * @return false => Timeout
    */
   int select (void);

   /**
    * Receive a data packet from the card
    *
    * @param buff Data buffer to store received data
    * @param btr  Byte count
    *
    * @return 1:OK, 0:Failed
    */
   int rcvr_datablock (uint8_t *buff, unsigned btr);

   /**
    * Send a data packet to the card
    *
    * @param buff    512 byte data block to be transmitted
    * @param token   Data/Stop token
    *
    * @return  1:OK, 0:Failed
    */
   int xmit_datablock (const uint8_t *buff, uint8_t token);

   /**
    * Send a command packet to the card
    *
    * @param cmd  Command byte to send (bit7===1: Indicates an application specific command)
    * @param arg  Argument for command
    *
    * @return Status value from card (bit7==1:Send failed)
    */
   uint8_t send_cmd (uint8_t cmd, uint32_t arg);

public:

   virtual ~SpiSdcard() = default;

   /**
    * Create SPI base SDCARD interface
    *
    * @param spi  SPI to use
    * @param cs   Gpio for SPI CS
    */
   SpiSdcard(Spi &spi, const Gpio &cs);

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

#endif // INCLUDE_USBDM_SD_SPI_H_
