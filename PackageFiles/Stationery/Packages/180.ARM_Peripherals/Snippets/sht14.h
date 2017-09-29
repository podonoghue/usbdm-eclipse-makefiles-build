/*
 * sht14.h
 *
 *  Created on: 29Sep.,2017
 *      Author: podonoghue
 */

#ifndef SOURCES_SHT14_H_
#define SOURCES_SHT14_H_

#include "hardware.h"
#include "i2c.h"
#include "formatted_io.h"

namespace USBDM {

/**
 * Indicates which measurement to make
 */
enum Sht14MeasurementType : uint8_t {
   Sht14MeasurementType_Temperature = 0b11110011,  //!< Sht14MeasurementTypeTemperature
   Sht14MeasurementType_Humidity    = 0b11110101,  //!< Sht14MeasurementTypeHumidity
};

/**
 * Controls resolution of measurements\n
 * RH = relative humidity, T = temperature
 */
enum Sht14Resolution {
   Sht14Resolution_rh12_t14 = 0b00000000,//!< RH = 12bits, T = 14bits
   Sht14Resolution_rh8_t12  = 0b00000001,//!< RH =  8bits, T = 12bits
   Sht14Resolution_rh10_t13 = 0b10000000,//!< RH = 10bits, T = 13bits
   Sht14Resolution_rh11_t11 = 0b10000001,//!< RH = 11bits, T = 11bits
};

/**
 * Controls internal heater
 */
enum Sht14Heater {
   Sht14Heater_Disabled = 0b000,
   Sht14Heater_Enabled  = 0b100,
};
/**
 * Controls OTP reload
 */
enum Sht14OtpReload {
   Sht14OtpReload_Disabled = 0b010,
   Sht14OtpReload_Enabled  = 0b000,
};

class Sht14 {

private:
   static constexpr uint8_t ADDRESS = 0x80;

   /**
    * Commands
    */
   enum commands {
      MEASURE_TEMPERATURE_HOLD   = 0b11100011,//!< MEASURE_TEMPERATURE_HOLD
      MEASURE_HUMIDITY_HOLD      = 0b11100101,//!< MEASURE_HUMIDITY_HOLD
      MEASURE_TEMPERATURE_NOHOLD = 0b11110011,//!< MEASURE_TEMPERATURE_NOHOLD
      MEASURE_HUMIDITY_NOHOLD    = 0b11110101,//!< MEASURE_HUMIDITY_NOHOLD
      WRITE_USER_REGISTER        = 0b11100110,//!< WRITE_USER_REGISTER
      READ_USER_REGISTER         = 0b11100111,//!< READ_USER_REGISTER
      SOFT_RESET                 = 0b11111110,//!< SOFT_RESET
   };
   I2c *i2c;

   /**
    * Set command to interface
    *
    * @param command Command to send
    */
   void sendCommand(uint8_t command) {
      i2c->startTransaction();
      i2c->transmit(ADDRESS, sizeof(command), &command);
      i2c->endTransaction();
   }

public:
   /**
    * @param i2c
    */
   Sht14(I2c *i2c, Sht14Resolution sht14Resolution) : i2c(i2c) {
      configure(sht14Resolution);
   }

   void softReset() {
      sendCommand(SOFT_RESET);
   }

   /**
    * Configure SHT14
    *
    * @param sht14Resolution  Resolution to use for measurements (affects speed)
    * @param sht14Heater      Controls internal heater
    * @param sht14OtpReload   Controls of OTP is reloaded on each measurement
    */
   void configure(
         Sht14Resolution sht14Resolution,
         Sht14Heater sht14Heater=Sht14Heater_Disabled,
         Sht14OtpReload sht14OtpReload= Sht14OtpReload_Disabled) {

      i2c->startTransaction();
      uint8_t userRegisterRead = READ_USER_REGISTER;
      i2c->txRx(ADDRESS, 1, &userRegisterRead, sizeof(userRegisterRead), &userRegisterRead);

      uint8_t userRegisterWrite[2] = {WRITE_USER_REGISTER};
      userRegisterWrite[1] |= (userRegisterRead&0b00111000)|sht14Resolution|sht14Heater|sht14OtpReload;
      i2c->transmit(ADDRESS, sizeof(userRegisterWrite), userRegisterWrite);
      i2c->endTransaction();
   }

   /**
    * Trigger a measurement
    *
    * @param sht14MeasurementType  Measurement to make
    *
    * @return E_NO_ERROR Measurement started correctly
    */
   ErrorCode startMeasurement(Sht14MeasurementType sht14MeasurementType) {
      i2c->startTransaction();
      ErrorCode rc =  i2c->transmit(ADDRESS, 1, (uint8_t*)&sht14MeasurementType);
      i2c->endTransaction();
      return rc;
   }

   /**
    * Get measurement result
    *
    * @param result Result, either humidity or temperature
    *
    * @return E_NO_ACK   Measurement not yet completed
    * @return E_NO_ERROR Measurement value returned
    */
   ErrorCode getMeasurementResult(Sht14MeasurementType sht14MeasurementType, float &result) {

      uint8_t measurementResult[3];

      i2c->startTransaction();
      ErrorCode rc = i2c->receive(ADDRESS, sizeof(measurementResult), measurementResult);

      if (rc == E_NO_ERROR) {
         int iResult;
         switch (sht14MeasurementType) {
            case Sht14MeasurementType_Humidity:
               iResult = (measurementResult[0]<<8)|(measurementResult[0]&0b11111100);
               result  = -6.0 + 125.0*iResult/(1<<16);
               break;

            case Sht14MeasurementType_Temperature:
               iResult = (measurementResult[0]<<8)|(measurementResult[0]&0b11111100);
               result  = -46.85 + 175.72*iResult/(1<<16);
               break;
         }
      }
      i2c->endTransaction();
      return rc;
   }

   /**
    * Do measurement
    *
    * @param sht14MeasurementType   Measurement to make
    * @param result                 Result, either humidity or temperature
    *
    * @return E_NO_ERROR Measurement value returned
    *
    * @note This is a slow operation involving polling ~ 100's ms
    */
   ErrorCode doMeasurement(Sht14MeasurementType sht14MeasurementType, float &result) {
      ErrorCode rc = startMeasurement(sht14MeasurementType);
      if (rc != E_NO_ERROR) {
         return rc;
      }
      do {
         rc = getMeasurementResult(sht14MeasurementType, result);
      } while (rc == E_NO_ACK);
      return rc;
   }

   /**
    * Trigger a set of measurements and return the results\n
    * The I2C bus is held while doing the measurement
    *
    * @param humidity      Humidity in percent
    * @param temperature   Temperature in Celsius
    *
    * @note This is a slow operation involving polling ~ 100's ms
    */
   void doMeasurement(float &humidity, float &temperature) {
      i2c->startTransaction();

      uint8_t doTempMeasurement[3] = {MEASURE_TEMPERATURE_HOLD};
      i2c->txRx(ADDRESS, 1, doTempMeasurement, sizeof(doTempMeasurement), doTempMeasurement);

      uint8_t doHumidityMeasurement[3] = {MEASURE_HUMIDITY_HOLD};
      i2c->txRx(ADDRESS, 1, doHumidityMeasurement, sizeof(doHumidityMeasurement), doHumidityMeasurement);

      int iTemperature = (doTempMeasurement[0]<<8)|(doTempMeasurement[0]&0b11111100);
      temperature = -46.85 + 175.72*iTemperature/(1<<16);

      int iHumidity    = (doHumidityMeasurement[0]<<8)|(doHumidityMeasurement[0]&0b11111100);
      humidity    = -6.0 + 125.0*iHumidity/(1<<16);

      i2c->endTransaction();
   }

};

} // End namespace

#endif /* SOURCES_SHT14_H_ */
