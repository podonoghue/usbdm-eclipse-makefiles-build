/*
 * max31855.h
 *
 *  Created on: 18 Sep 2016
 *      Author: podonoghue
 */

#ifndef SOURCES_MAX31855_H_
#define SOURCES_MAX31855_H_

/**
 * Class representing an MAX31855 connected over SPI
 *
 * @tparam pinNum Pin number for PCSn signal
 */
class Max31855 {

protected:

   /** SPI CTAR value */
   uint32_t spiCtarValue = 0;

   /** SPI used for LCD */
   USBDM::Spi *spi;

   /* Number of PCS signal to use */
   int pinNum;

   /**
    * Initialise the LCD
    */
   void initialise() {
      USBDM::waitMS(200);

      spi->setPcsPolarity(pinNum, false);
      spi->setSpeed(1000000);
      spi->setMode(USBDM::SPI_MODE0);
      spi->setDelays(0.5*USBDM::us, 0.5*USBDM::us, 0.5*USBDM::us);
      spi->setFrameSize(16);

      // Record CTAR value in case SPI shared
      spiCtarValue = spi->getCTAR0Value();
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
    * @return Short string repsenting status
    */
   static const char *getStatusName(int status) {
      switch (status&0x07) {
      case 0  : return "OK";
      case 1  : return "Open";
      case 2  : return "Gnd";
      case 4  : return "Vcc";
      case 7  : return "---";
      default : return "???";
      }
   }
   /**
    * Read thermocouple
    *
    * @param temperature   Temperature reading as signed number (14-bit resolution)
    * @param coldReference Temperature reading of internal cold-junction reference (12-bit resolution)
    *
    * @return error flag from sensor 0 => OK, 0bxx1=>Open circuit, 0bx1x=>Short to Gnd, 0b1xx=>Short to Vcc
    */
   int getReading(int &temperature, int &coldReference) {
      uint8_t data[] = {
            0xFF, 0xFF, 0xFF, 0xFF,
      };
      spi->setCTAR0Value(spiCtarValue);
      spi->setPushrValue(SPI_PUSHR_CTAS(0)|SPI_PUSHR_PCS(1<<pinNum));
      spi->txRxBytes(sizeof(data), nullptr, data);

      // Sign-extended 14-bit value
      temperature = ((int16_t)((data[0]<<8)|data[1]))>>2;

      // Sign-extended 12-bit value
      coldReference = ((int16_t)((data[2]<<8)|data[3]))>>4;

      // Error flag
      return data[3]&0x07;
   }
};

#endif /* SOURCES_MAX31855_H_ */
