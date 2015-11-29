#include <stdio.h>
#include <string.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "Gps.h"
#include "delay.h"

/**
 * See examples in Snippets directory
 */

// LED connections
#define RED_LED   USBDM::gpio_LED_RED
#define GREEN_LED USBDM::gpio_LED_GREEN

int main() {
   printf("Starting\n");

   USBDM::Gps *gps = new USBDM::$(demo.cpp.gps.interface)();

   for(;;) {
      USBDM::Gps::GpsData gpsData;
      if (gps->getGpsData(gpsData)) {
         USBDM::Gps::report(gpsData);
      }
   }
}

