/*
 ============================================================================
 * @file    oled-example.cpp (180.ARM_Peripherals/Snippets/oled-example.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "oled.h"

using namespace USBDM;

// I2C interface connecting to OLED
I2c0 i2c{};

// OLED - dimensions of OLED are determined by constants in oled.h
Oled oled{i2c};

int main() {

   for(int count = 0;;count++) {
      oled.writeln("Hello");
   }
   return 0;
}
