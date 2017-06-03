/**
 ============================================================================
 * @file   gps-example.cpp
 * @brief  GPS shield demonstration
 *
 *  Created on: 29/11/2015
 *      Author: pgo
 *
 * \section introSection Introduction
 * This is a simple example of the use of the C++ library routines for the Global Positing System shield.\n
 *
 * It may be necessary to change pin mappings to use this example.\n
 * Open Configure.usbdmProject file to change these.\n\n
 *
 * Refer to the individual files for license conditions as they vary.
 *
 * <hr>
 * This example requires use of floating point in printf().\n
 * It is necessary to change the library options to support this.
 *
 * Right-click on project and open Properties.
 *
 * - Select [C/C++ Build->Settings] on left of [Tool Settings] tab
 * - Select [ARM C++ Linker->General] in middle panel
 * - Turn on [Support %f format in printf]
 *
 * (In may be necessary to clean and re-build the project)
 *
 * <hr>
 * \subsection QuickLinks Quick Links
 *
 *   - @htmlonly <a href="https://www.itead.cc/itead-gps-shield.html"><b>ITEAD REB-4216 GPS Shield </b></a> @endhtmlonly
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "gps.h"
#include "delay.h"

using namespace USBDM;

/**
 * This example requires use of floating point in printf()
 * It is necessary to change the library options to support this
 *
 * Right-click on project and open Properties
 *
 * Select [C/C++ Build->Settings] on left of [Tool Settings] tab
 * Select [ARM C++ Linker->General] in middle panel
 * Turn on [Support %f format in printf]
 *
 * (In may be necessary to clean and re-build the project)
 */

// LED connections
#define RED_LED   gpio_LED_RED
#define GREEN_LED gpio_LED_GREEN

int main() {
   printf("Starting\n");

   Gps *gps = new $(demo.cpp.external.gps:Gps0)();

   for(;;) {
      Gps::GpsData gpsData;
      if (gps->getGpsData(gpsData)) {
         Gps::report(gpsData);
      }
   }
}

