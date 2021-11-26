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
#include "hardware.h"

using namespace USBDM;


void testsdhc() {
}

int main() {
   console.writeln("Configuring sdhc Controller\n");

   sdhcCardDetect.setInput(PinPull_Up);
   Sdhc::enable();

   SimInfo::setSdhcClock(SimSdhcClockSource_System);
   SimInfo::getSdhcClock();

   for(;;) {
      __BKPT();
   }

   return 0;
}
