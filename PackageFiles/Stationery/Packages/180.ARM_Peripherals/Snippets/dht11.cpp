/*
 * dht11.cpp
 *
 *  Created on: 19Nov.,2017
 *      Author: podonoghue
 */

#include "hardware.h"
using namespace USBDM;

using Gpio  = GpioC<0>;
using Debug = GpioC<1>;

class DHT11 {

public:
   DHT11() {
      // Set up as open-drain output pin with high state initially
      Gpio::setInOut(PinPull_Up, PinDriveStrength_Low, PinDriveMode_OpenDrain);
      Gpio::high();
      Gpio::setOut();

      // Wait 1 s start-up time for sensor
      waitMS(1000);
   }

   ErrorCode doMeasurement(uint16_t &humidity, uint16_t &temperature) {

      const unsigned windowTime  = (unsigned) convertUSToTicks(50);
      const unsigned releaseTime = (unsigned) convertUSToTicks(20);

      // Drive low
      Gpio::low();
      waitMS(18);

      // 3-state & allow rise time
      Gpio::high();
      waitTicks(releaseTime);

      Debug::high();

      // Wait for ACK (low) from sensor
      if (!waitTicks(1000, Gpio::isLow)) {
         Debug::low();
         return E_NO_COMMUNICATION;
      }
      // Wait for end of ACK from sensor
      if (!waitTicks(1000, Gpio::isHigh)) {
         Debug::low();
         return E_NO_COMMUNICATION;
      }
      Debug::low();
      Debug::high();
      Debug::low();

//      uint8_t data = 0;

      // Receive 5 bytes
      uint8_t bytes[5];
      uint8_t *bPtr = bytes;
      for (int byte=0; byte<5; byte++) {
         // Receive 8 bits/byte
         for (int bit=0; bit<8; bit++) {
            // Wait for data line low from sensor
            if (!waitTicks(1000, Gpio::isLow)) {
               return E_NO_COMMUNICATION;
            }
            unsigned t = getTicks();
            // Wait for data line high from sensor
            if (!waitTicks(1000, Gpio::isHigh)) {
               return E_NO_COMMUNICATION;
            }
            Debug::toggle();
            // Time to response
            t = getTicks()-t;
            *bPtr <<= 1;
            *bPtr |= (t>windowTime);
         }
      }
      humidity    = 0;
      temperature = 0;
      return E_NO_ERROR;
   }
};

int main() {
   Debug::setOutput();
   DHT11 dht11{};
   uint16_t humidity;
   uint16_t temperature;

   for (;;) {
      if (dht11.doMeasurement(humidity, temperature) == E_NO_ERROR) {
         console.writeln("Failed measurement");
      }
      waitMS(200);
   }
}
