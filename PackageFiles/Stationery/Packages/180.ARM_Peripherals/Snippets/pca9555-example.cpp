/*
 ============================================================================
 * @file    PCA9555-example.cpp (180.ARM_Peripherals/Snippets/PCA9555-example.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "PCA9555.h"

using namespace USBDM;

// I2C interface connecting to OLED
I2c0 i2c{};

// PCA9555 interface
Pca9555 pca9555{i2c};

int main() {

   for(int count = 0;;count++) {
      pca9555.setDirection0(0b11110000);
      pca9555.writeData0(0b10100000);
      uint8_t data;
      pca9555.readData0(data);
   }
   return 0;
}
