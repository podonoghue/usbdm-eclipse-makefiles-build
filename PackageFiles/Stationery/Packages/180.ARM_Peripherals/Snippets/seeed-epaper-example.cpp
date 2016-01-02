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
 * It may be necessary to change pin mappings to use this example. \n
 * See below for required pin mapping of individual GPIOs used with this module.\n
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

using EPD_PANEL_ON   = USBDM::gpio_D2;   //!< ON/OFF EPD Power
using EPD_BORDER     = USBDM::gpio_D3;   //!< Border to EPD
using EPD_PWM        = USBDM::ftm_D5;    //!< PWM to EPD
using EPD_RESETn     = USBDM::gpio_D6;   //!< Reset to EPD
using EPD_BUSY       = USBDM::gpio_D7;   //!< Busy flag from EPD
using EPD_DISCHARGE  = USBDM::gpio_D8;   //!< Discharge to EPD
using EPD_CSn        = USBDM::gpio_D10;  //!< EPD SPI CS*

using SD_CSn         = USBDM::gpio_D4;   //!< SD SPI CS*
using GT20L16_CSn    = USBDM::gpio_D9;   //!< GT20L16 SPI CS*

using S8120CN_TEMP   = USBDM::adc_A0;    //!< Temperature sensor

/**
 * Convenience wrapper for USBDM::EPaper - Just instantiates with above port mappings
 */
class EPaper : public USBDM::EPaper_T<S8120CN_TEMP> {
public:
   EPaper(USBDM::Spi *spi, const USBDM::EpdData &epdData) :
      EPaper_T(
         // Character generator ROM
         new USBDM::GT20L16_T<GT20L16_CSn>(spi),
         // Low-level interface
         new USBDM::Epd_T<EPD_BUSY, EPD_RESETn, EPD_DISCHARGE, EPD_BORDER, EPD_PANEL_ON, EPD_PWM, EPD_CSn>(spi, epdData)) {
   }
};

int main() {
   // Instantiate SPI interface class
   USBDM::Spi *spi = new USBDM::$(demo.cpp.external.spi)();

   // Set higher speed to improve draw rate
   spi->setSpeed(1000000);

   // Instantiate ePaper for 2.7" display
   USBDM::EPaper *epaper = new ::EPaper(spi, USBDM::EPD_2_7_DATA);

   epaper->clearDisplay();
   for (int count=0;;count++) {
      epaper->clearCanvas();
      epaper->drawCircle(100,100,20);
      epaper->drawString("Hello", 100, 100);
      epaper->drawNumber(count, 150,100);
      epaper->displayCanvas();
      USBDM::waitMS(40000);
   }
}
