/*
 ============================================================================
 * @file    sht14-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "sht14.h"
#include "string.h"
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

const char *floatToString(float num) {
   static char buffer[20];
   char *ptr = buffer;
   int value = round(100*num);
   ptr = console.setPadding(Padding_LeadingSpaces).setWidth(3).ltoa(ptr, value/100);
   *ptr++ = '.';
   ptr = console.setPadding(Padding_LeadingZeroes).setWidth(2).ltoa(ptr, value%100);
   console.reset();
   return buffer;
}

int main() {

   I2c *i2c = new I2c0;
   Sht14 *sensor = new Sht14(i2c, Sht14Resolution_rh12_t14);

   for(;;) {
      float humidity=0, temperature=0;
#if 0
      // Split transactions
      sensor->startMeasurement(Sht14MeasurementType_Temperature);
      waitMS(70);
      while (sensor->getMeasurementResult(Sht14MeasurementType_Temperature, temperature) == E_NO_ACK);

      sensor->startMeasurement(Sht14MeasurementType_Humidity);
      waitMS(50);
      while(sensor->getMeasurementResult(Sht14MeasurementType_Humidity, humidity) == E_NO_ACK);
#endif
#if 0
      // Separate measurements
      sensor->doMeasurement(Sht14MeasurementType_Humidity, humidity);
      sensor->doMeasurement(Sht14MeasurementType_Temperature, temperature);
#endif
      // Combined measurements
      sensor->doMeasurement(humidity, temperature);
      console.write("Humidity = ").write(floatToString(humidity)).write(", Temperature = ").writeln(floatToString(temperature));
      waitMS(100);
   }

}
