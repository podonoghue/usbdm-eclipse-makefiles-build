/**
 * @file    max31855.h
 * @brief   MAX31855 Thermocouple interface
 *
 *  Created on: 18 Sep 2016
 *      Author: podonoghue
 */

#ifndef SOURCES_MAX31855_H_
#define SOURCES_MAX31855_H_

#include "spi.h"

/**
 * Class representing an MAX31855 connected over SPI
 *
 * @tparam pinNum Pin number for PCSn signal
 */
class Max31855 {
public:
   enum ThermocoupleStatus {
      TH_ENABLED,          // Enabled and OK
      TH_OPEN,             // No probe or open circuit
      TH_SHORT_VCC,        // Probe short to Vcc
      TH_SHORT_GND,        // Probe short to Gnd
      TH_MISSING,          // No response - Max31855 not present at that address
      TH_DISABLED=0b111,   // Available but disabled (Temperature reading will still be valid)
   };

protected:

   /** SPI CTAR value */
   uint32_t spiCtarValue = 0;

   /** SPI used for LCD */
   USBDM::Spi &spi;

   /** Number of PCS signal to use */
   const int pinNum;

   /** Used to disable sensor */
   bool  enabled;

   /**
    * Initialise the LCD
    */
   void initialise() {
      spi.setPcsPolarity(pinNum, false);

      IrqProtect protect;
      spi.setSpeed(2500000);
      spi.setMode(USBDM::SPI_MODE0);
      spi.setDelays(0.1*USBDM::us, 0.1*USBDM::us, 0.1*USBDM::us);
      spi.setFrameSize(8);

      // Record CTAR value in case SPI shared
      spiCtarValue = spi.getCTAR0Value();
   }

public:
   /**
    * Constructor
    *
    * @param spi     The SPI to use to communicate with MAX31855
    * @param pinNum  Number of PCS to use
    */
   Max31855(USBDM::Spi *spi, int pinNum) : spi(spi), pinNum(pinNum) {
      initialise();
   }

   /**
    * Convert status to string
    *
    * @param status 3-bit status value from thermocouple
    *
    * @return Short string representing status
    */
   static const char *getStatusName(ThermocoupleStatus status) {
      switch (status) {
      case TH_ENABLED   : return "OK";    // OK!
      case TH_OPEN      : return "Open";  // No probe or open circuit
      case TH_SHORT_VCC : return "Vcc";   // Probe short to Vcc
      case TH_SHORT_GND : return "Gnd";   // Probe short to Gnd
      case TH_MISSING   : return "----";  // No response - Max31855 not present at that address
      case TH_DISABLED  : return "Dis";   // OK but disabled
      default           : return "????";  // Unknown
      }
   }
   /**
    * Enables/disables the sensor
    *
    * @param enable True to enable sensor
    */
   void enable(bool enable=true) {
      enabled = enable;
   }

   /**
    * Toggles the enables state of the sensor
    */
   void toggleEnable() {
      enabled = !enabled;
   }

   /**
    * Check if sensor is enabled
    *
    * @return true => enabled
    */
   bool isEnabled() const {
      return enabled;
   }
   /**
    * Read thermocouple
    *
    * @param temperature   Temperature reading of external probe (.25 degree resolution)
    * @param coldReference Temperature reading of internal cold-junction reference (.0625 degree resolution)
    *
    * @return status flag
    * @note Temperature and cold-junction may be valid even if the thermocouple is disabled (TH_DISABLED).
    */
   ThermocoupleStatus getReading(float &temperature, float &coldReference) {
      uint8_t data[] = {
            0xFF, 0xFF, 0xFF, 0xFF,
      };
      spi.setCTAR0Value(spiCtarValue);
      spi.setPushrValue(SPI_PUSHR_CTAS(0)|SPI_PUSHR_PCS(1<<pinNum));
      spi.txRxBytes(sizeof(data), nullptr, data);

      // Temperature = sign-extended 14-bit value
      temperature = (((int16_t)((data[0]<<8)|data[1]))>>2)/4.0;

      // Cold junction = sign-extended 12-bit value
      coldReference = (((int16_t)((data[2]<<8)|data[3]))>>4)/16.0;

      /*  Raw status
       *    0x000 => OK
       *    0bxx1 => Open circuit
       *    0bx1x => Short to Gnd
       *    0b1xx => Short to Vcc
       *    0b111 => No response - Max31855 not present at that address
       */
      int rawStatus = data[3]&0x07;
      ThermocoupleStatus status = TH_ENABLED;
      if (rawStatus != 0) {
         // Invalid temperature measurement
         temperature = NAN;
      }
      if (rawStatus == 0x111) {
         // No device so no Cold reference
         coldReference = NAN;
         status = TH_MISSING;
      }
      else if (rawStatus & 0b001) {
         //Open
         status = TH_OPEN;
      }
      else if (rawStatus & 0b010) {
         // Ground short
         status = TH_SHORT_GND;
      }
      else if (rawStatus & 0b100) {
         // Vcc short
         status = TH_SHORT_VCC;
      }
      else if (!enabled) {
         // Available but not enabled
         status = TH_DISABLED;
      }
      // Return error flag
      return status;
   }
   /**
    * Read enabled thermocouple
    *
    * @param temperature   Temperature reading of external probe (.25 degree resolution)
    * @param coldReference Temperature reading of internal cold-junction reference (.0625 degree resolution)
    *
    * @return Status of sensor
    * @note Temperature will be zero if the thermocouple is disabled or unusable.
    * @note Cold-junction will be valid even if the thermocouple is disabled (TH_DISABLED).
    */
   ThermocoupleStatus getEnabledReading(float &temperature, float &coldReference) {
      ThermocoupleStatus status = getReading(temperature, coldReference);
      if (status == TH_DISABLED) {
         temperature = 0;
      }
      return status;
   }

   /**
    * Set offset added to temperature reading
    *
    * @param off Offset to set
    *
    * @note This is a non-volatile setting
    */
   void setOffset(int off) {
      offset = off;
   }

   /**
    * Get offset that is added to temperature reading
    *
    * @note Offset as an integer
    */
   int getOffset() {
      return offset;
   }
};

#endif /* SOURCES_MAX31855_H_ */
