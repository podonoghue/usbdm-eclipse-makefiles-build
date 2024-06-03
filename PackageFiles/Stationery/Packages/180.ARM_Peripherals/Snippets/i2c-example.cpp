/*
 ============================================================================
 * @file    i2c-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using I2C interface
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "i2c.h"

using namespace USBDM;

// Address (LSB = R/W bit) // 0x1D for FRDM_MK20D50? 0x1C for FRDM_MK22F
static const unsigned I2C_ADDRESS = 0x1D<<1;

bool complete = false;

//#define USE_INTERRUPT

#ifdef USE_INTERRUPT
void i2cCallback(ErrorCode errorCode) {
   __asm__("nop");
   console.writeln("Complete, rc = ", getErrorMessage(errorCode));
   complete = true;
}
#endif

int main() {
#define SELECT 0

   static constexpr I2c0::Init i2cInit = {
#ifdef USE_INTERRUPT
      NvicPriority_Normal,
      i2cCallback,
#endif

      400_kHz,                  // Speed
      I2cBusRole_Controller ,   // Bus Role Select - Controller mode
   };

   I2c0 i2c{i2cInit};

   for(;;) {
#if SELECT == 0
      {
         /*
          * Transmits 4 bytes and receives 2 bytes using different buffers
          * This will use a repeated start at turnover
          */
         static const uint8_t txData[] = { 0xA1,0xB2,0xC3,0xD4,};
         uint8_t rxData[2] = {};

         complete = false;
         i2c.startTransaction();
         i2c.txRx(I2C_ADDRESS, txData, rxData);
         i2c.endTransaction();

#ifdef USE_INTERRUPT
         while (!complete) {
            console.write(".");
            waitUS(100);
         }
         console.writeln();
#endif
      }
#elif SELECT == 1
      {
         /*
          * Transmits 2 bytes and receives 4 bytes into same buffer
          * This will use a repeated start at turnover
          */
         uint8_t data[4] = { 0xA1,0xB2, };

         i2c.startTransaction();
         i2c.txRx(I2C_ADDRESS, 2, sizeof(data), data);
         i2c.endTransaction();

#ifdef USE_INTERRUPT
         while (!complete) {
            console.write(".");
            waitUS(100);
         }
         console.writeln();
#endif
      }
#elif SELECT == 2
      {
         /*
          * Transmits 4 bytes
          */
         static const uint8_t data[] = { 0xA1,0xB2,0xC3,0xD4,};

         i2c.startTransaction();
         i2c.transmit(I2C_ADDRESS, data);
         i2c.endTransaction();

#ifdef USE_INTERRUPT
         while (!complete) {
            console.write(".");
            waitUS(100);
         }
         console.writeln();
#endif
      }
#else
      {
         /*
          * Receive 4 bytes
          */
         uint8_t data[4] = {};

         i2c.startTransaction();
         i2c.receive(I2C_ADDRESS, data);
         i2c.endTransaction();

#ifdef USE_INTERRUPT
         while (!complete) {
            console.write(".");
            waitUS(100);
         }
         console.writeln();
#endif

      }
#endif
      waitMS(100);
   }
}


