/**
 * @file gps-example.cpp
 */
#include <stdio.h>
#include <string.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
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

   Gps *gps = new $(demo.cpp.external.gps)();

   for(;;) {
      Gps::GpsData gpsData;
      if (gps->getGpsData(gpsData)) {
         Gps::report(gpsData);
      }
   }
}

