/**
 ============================================================================
 * @file    dac-example.cpp
 * @brief   Basic C++ demo using DAC class
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "dac.h"

static const int values[] = {
      2048,2403,2748,3072,3364,3616,3821,3972,
      4064,4095,4064,3972,3821,3616,3364,3072,
      2748,2403,2048,1693,1348,1024,732,480,
      275,124,32,1,32,124,275,480,
      732,1024,1348,1693,
};

using dac = USBDM::Dac0;

int main() {
   dac::configure();
   for(;;) {
      for (uint i=0; i<(sizeof(values)/sizeof(values[0])); i++) {
         dac::setValue(values[i]);
      }
   }
   for(;;) {}
   return 0;
}

