/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */

#include "hardware.h"

// Uncomment following lines to enable different interfaces
// It will also be necessary to configure appropriate interfaces in
// 'Configure.usbdmProject' to connect to the actual SDCARD interface:
// - userSpi          SPI interface (as instance)
// - sdhc             SDHC interface (as instance, PUPs on pins)
// - sdhcCardDetect   GPIO for SDCARD detect (as instance)
// - _gettimeofday()  RTC (or provide dummy routine) 
//#define SDCARD_SPI   // Enable SD-CARD interface using SPI
//#define SDCARD_SDHC  // Enable SD-CARD interface using SDHC

#if !defined SDCARD_SPI && !defined SDCARD_SDHC
#error "Enable the appropriate interfaces above"
#endif

#ifdef SDCARD_SPI
#include "sd_spi.h"     // SD-CARD interface using SPI
#endif // SDCARD_SPI

#ifdef SDCARD_SDHC
#include "sd_sdhc.h"    // SD-CARD interface using SDHC
#endif // SDCARD_SDHC

// Table of device names for FATFS
const char* VolumeStr[FF_VOLUMES] = {
#if defined SDCARD_SPI || defined SDCARD_SDHC
      "sd",
#endif // defined SDCARD_SPI || defined SDCARD_SDHC

#if defined SDCARD_SPI && defined SDCARD_SDHC
      "sd1",
#endif // defined SDCARD_SPI || defined SDCARD_SDHC
};

/**
 * Get SD Interface base upon drive number
 *
 * @param pdrv  Physical drive number (0)
 *
 * @return SD Interface or null if illegal pdrv
 */
USBDM::SdInterface *getSdInterface(BYTE pdrv) {
#ifdef SDCARD_SPI

   // SD card interface using SPI
   static USBDM::SpiSdcard spiSdcard(USBDM::userSpi, USBDM::sdCardCS);

#endif // SDCARD_SPI

#ifdef SDCARD_SDHC

   // SD card interface using SDHC
   static USBDM::SdhcInterface sdhcSdcard{USBDM::sdhc};

#endif // SDCARD_SDHC

   // Table of SD Interfaces
   USBDM::SdInterface * const sdInterfaces[] {
#if defined SDCARD_SPI
         &spiSdcard,
#endif // defined SDCARD_SPI || defined SDCARD_SDHC

#if defined SDCARD_SDHC
         &sdhcSdcard,
#endif // defined SDCARD_SPI || defined SDCARD_SDHC
   };

   if (pdrv<USBDM::sizeofArray(sdInterfaces)) {
      // Return requested interface
      return sdInterfaces[pdrv];
   }
   // Not available
   return nullptr;
}

/**
 * Initialise Disk Drive
 *
 * @param pdrv  Physical drive number (0)
 *
 * @return Status
 */
DSTATUS disk_initialize (BYTE pdrv) {

   USBDM::SdInterface *sdInterface = getSdInterface(pdrv);
   return sdInterface?sdInterface->disk_initialize():STA_NOINIT;
}

/**
 * Get Drive Status
 *
 * @param pdrv Physical drive number to identify the drive
 *
 * @return Error code
 */
DSTATUS disk_status (BYTE pdrv) {

   USBDM::SdInterface *sdInterface = getSdInterface(pdrv);
   return sdInterface?sdInterface->disk_status():STA_NOINIT;
}

/**
 * Read Sector(s)
 *
 * @param pdrv    Physical drive number
 * @param buff    Buffer for data
 * @param sector  Start sector number (LBA)
 * @param count   Sector count (1..128)
 *
 * @return  Status
 */
DRESULT disk_read (BYTE pdrv, BYTE *buff, LBA_t sector, UINT count) {

   USBDM::SdInterface *sdInterface = getSdInterface(pdrv);
   return sdInterface?sdInterface->disk_read(buff, sector, count):RES_PARERR;
}

#if FF_FS_READONLY == 0

/**
 * Write Sector(s)
 *
 * @param pdrv    Physical drive number
 * @param buff    Buffer for data
 * @param sector  Start sector number (LBA)
 * @param count   Sector count (1..128)
 *
 * @return  Status
 */
DRESULT disk_write (BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count) {

   USBDM::SdInterface *sdInterface = getSdInterface(pdrv);
   return sdInterface?sdInterface->disk_write(buff, sector, count):RES_PARERR;
}

#endif

/**
 * Miscellaneous Functions
 *
 * @param pdrv    Physical drive number (Always 0)
 * @param ctrl    Control code
 * @param buff    Buffer to send/receive control data
 *
 * @return  Status
 */
DRESULT disk_ioctl (BYTE pdrv, BYTE ctrl, void *buff ) {

   USBDM::SdInterface *sdInterface = getSdInterface(pdrv);
   return sdInterface?sdInterface->disk_ioctl(ctrl, buff):RES_PARERR;
}

