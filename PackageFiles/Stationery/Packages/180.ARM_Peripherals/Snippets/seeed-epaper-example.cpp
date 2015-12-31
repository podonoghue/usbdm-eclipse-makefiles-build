/**
 *  \mainpage Seed Studio e-Paper shield demonstration
 *
 * \section introSection Introduction
 * This is a simple example of the use of the C++ library routines for the Seeed Studio e-Paper displays.\n
 * With some modification it should be usable with other e-Paper displays from PervasiveDisplays.
 *
 * To use the Seeed Studio panel with the FRDM boards it is necessary to remove the 6-pin connector used for the spi signals and add links
 * to connect the required signals to the correct SPI pins.\n
 *   Arduino D11 = MOSI\n
 *   Arduino D12 = MISO\n
 *   Arduino D13 = SCK\n\n
 *
 * It may be necessary to change pin mappings to use this example.\n
 * See @ref seeed_sld00200p.h for required pin mapping of individual GPIOs used with this module.\n
 * Open @ref pin_mapping.h file in the Configuration Editor to change these.\n\n
 *
 * Refer to the individual files for license conditions as they vary.
 *
 * <hr>
 * \subsection QuickLinks Quick Links
 *
 *   - @htmlonly <a href="http://www.seeedstudio.com/wiki/Small_e-Paper_Shield"><b>Seeed Studio e-Paper Wiki</b></a> @endhtmlonly
 *   - @htmlonly <a href="http://www.pervasivedisplays.com"><b>PervasiveDisplays</b></a> @endhtmlonly
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "epaper.h"
#include "delay.h"

int main() {
   // Instantiate SPI interface class
   USBDM::Spi *spi = new USBDM::$(demo.cpp.external.spi)();

   // Set higher speed to improve draw rate
   spi->setSpeed(1000000);

   // Epaper display
   USBDM::EPaper *epaper = new USBDM::EPaper(spi, USBDM::EPD_2_7_DATA);

   epaper->clearDisplay();
   for (int count=0;;count++) {
      epaper->clearCanvas();
      epaper->drawCircle(100,100,20);
      epaper->drawString("Hello", 100, 100);
      epaper->drawNumber(count, 150,100);
      epaper->displayCanvas();
      USBDM::waitMS(1000);
   }
}
