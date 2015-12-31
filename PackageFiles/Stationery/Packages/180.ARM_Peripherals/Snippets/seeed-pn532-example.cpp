/**
 * \mainpage Seed Studio PN535 shield demonstration
 *
 * \section introSection Introduction
 * This is a simple example of the use of the C++ library routines for the PN535 shield from seeed studio.\n
 *
 * To use the Seeed Studio panel with the FRDM boards it is necessary to remove the 6-pin connector used for the spi signals and add links
 * to connect the required signals to the correct SPI pins.\n
 *   Arduino D11 = MOSI\n
 *   Arduino D12 = MISO\n
 *   Arduino D13 = SCK\n\n
 *
 * It may be necessary to change pin mappings to use this example.\n
 * Open @ref pin_mapping.h file in the Configuration Editor to change these.\n\n
 *
 * Refer to the individual files for license conditions as they vary.
 *
 * <hr>
 * \subsection QuickLinks Quick Links
 *
 *   - @htmlonly <a href="http://www.seeedstudio.com/depot/nfc-shield-v20-p-1370.html"><b>Seeed Studio shield</b></a> @endhtmlonly
 */
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "delay.h"
#include "pn532.h"

/**
 * PN535 connected using Arduino D10 pin as chip-select
 */
using PN532 = USBDM::PN532_T<USBDM::gpio_D10>;

/**
 * Report PN532 device firmware version
 */
void reportFirmwareVersion(PN532 *nfc) {
   PN532::FirmwareVersion firmwareVersion;

   memset(&firmwareVersion, 0, sizeof(firmwareVersion));
   if (nfc->getFirmwareVersion(firmwareVersion)) {
      printf("Firmware version ic=0x%02X,  ver=0x%02X,  rev=0x%02X, (%s, %s, %s,)\n",
            firmwareVersion.ic, firmwareVersion.ver, firmwareVersion.rev,
            (firmwareVersion.support&(1<<2))?"ISO18092":"-",
            (firmwareVersion.support&(1<<1))?"ISO/IEC14443 Type B":"-",
            (firmwareVersion.support&(1<<0))?"ISO/IEC14443 Type A":"-" );
   }
   else {
      printf("getFirmwareVersion() failed\n");
   }
}

int main() {
   printf("\n\nStarting\n\n");
   // Instantiate SPI interface class
   USBDM::Spi *spi = new USBDM::$(demo.cpp.external.spi)();
   PN532 *nfc = new PN532(spi);

   reportFirmwareVersion(nfc);

   bool rc;

   static const PN532::SamConfiguration samConfiguration = {
         0x01, // Normal mode
         20,   // Timeout = 1s (20 x 50 milliseconds)
         true, // Use IRQ pin
   };
   rc = nfc->samConfiguration(samConfiguration);

//   static const uint8_t config[] = {
//         PN532::RF_MAX_RETRY,
//         255,           // MxRtyATR
//         1,             // MxRtyPSL
//         255,           // MxRtyPassiveActivation (255=infinite)
//   };
//   rc = nfc->rfConfiguration(sizeof(config), config);

   // Report cards detected
   PN532::Uid lastUid = {0};
   for(;;) {
      PN532::Uid uid;
      rc = nfc->readPassiveTargetID(uid, 200);
      if (rc) {
         if (lastUid.compareTo(uid) != 0) {
            lastUid = uid;
            printf("uidLength=%d, uid=0x%02X%02X%02X%02X\n", uid.length, uid.uid[0], uid.uid[1], uid.uid[2], uid.uid[3]);
         }
      }
      USBDM::waitMS(100);
   }
}
