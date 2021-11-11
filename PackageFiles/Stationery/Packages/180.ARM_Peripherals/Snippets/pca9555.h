/**
 * @file mcp23008.h
 *
 * C++ interface for MCP23008 I2C GPIO expander
 */

#ifndef SOURCES_PCA9555_H_
#define SOURCES_PCA9555_H_

#include "i2c.h"

namespace USBDM {

/**
 * The controls the incrementing function of the address pointer on register read/write
 */
enum Pca9555Sequential {
   Pca9555Sequential_Enable  = 0<<5, //!< Sequential enabled, address pointer increments
   Pca9555Sequential_Disable = 1<<5, //!< Sequential disabled, address pointer does not increment
};

/**
 * Slew Rate control bit for I2C SDA output.
 * If enabled, the SDA slew rate will be controlled when driving from a high to a low.
 */
enum Pca9555SlewRate {
   Pca9555SlewRate_Fast  = 1<<4, //!< Slew rate disabled i.e. fast transition
   Pca9555SlewRate_Slow  = 0<<4, //!< Slew rate enabled i.e. slow transition
};

/**
 * Controls the polarity and drive mode of the IRQ pin
 */
enum Pca9555Interrupt {
   Pca9555Interrupt_OpenDrain   = 0b10<<1, //!< IRQ pin is open-drain and active-low
   Pca9555Interrupt_ActiveLow   = 0b00<<1, //!< IRQ pin is push-pull and active-low
   Pca9555Interrupt_ActiveHigh  = 0b01<<1, //!< IRQ pin is push-pull and active-high
};

class Pca9555 {

private:
   // Address (LSB = R/W bit)
   const unsigned pca95555Address;

   // I2C Interface to use
   I2c &i2c;

   /**
    * Device register addresses
    */
   enum RegAddress {
      INPUT_PORT0,
      INPUT_PORT1,
      OUTPUT_PORT0,
      OUTPUT_PORT1,
      POLARITY_INVERSION0,
      POLARITY_INVERSION1,
      CONFIGURATION0,
      CONFIGURATION1,
   };

   /**
    * Write MCP23008 Register
    *
    * @param[in]  address Register address
    * @param[in]  value   Value to write to register
    */
   void writeReg(RegAddress address, uint8_t value) {
      uint8_t txData[] = {address, value};

      i2c.startTransaction();
      i2c.transmit(pca95555Address, txData);
      i2c.endTransaction();
   }

   /**
    * Read MCP23008 Register
    *
    * @param[in]  address  Register address
    * @param[out] value    Value read from register
    */
   void readReg(RegAddress address, uint8_t &value) {
      uint8_t txData[]  = {address};
      uint8_t rxData[1] = {};

      i2c.startTransaction();
      i2c.txRx(pca95555Address, txData, rxData);
      i2c.endTransaction();

      value = rxData[0];
   }

public:

   /**
    * Create the MCP23008 interface
    *
    * @param[in] i2cInterface        I2C interface to use for communication
    * @param[in] i2cAddress          Bottom 3-bits of I2C address (determined by pin-strapping)
    */
   constexpr Pca9555(
         USBDM::I2c        &i2cInterface,
         uint8_t            i2cAddress        = 0b000
         ) :
            pca95555Address((0b010'0000|(i2cAddress&0b111))<<1),
            i2c(i2cInterface) {
   }

   /**
    * Set PORT0 direction
    *
    * @param[in] mask Bit-mask controlling pin direction (1=> out, 0=> in)
    */
   void setDirection0(uint8_t mask) {
      writeReg(CONFIGURATION0, ~mask);
   }

   /**
    * Set PORT1 direction
    *
    * @param[in] mask Bit-mask controlling pin direction (1=> out, 0=> in)
    */
   void setDirection1(uint8_t mask) {
      writeReg(CONFIGURATION1, ~mask);
   }

   /**
    * Write output data to PORT0 pins
    *
    * @param[in] data  Data value to output to pins (if configured as output)
    */
   void writeData0(uint8_t data) {
      writeReg(OUTPUT_PORT0, data);
   }

   /**
    * Write output data to PORT1 pins
    *
    * @param[in] data  Data value to output to pins (if configured as output)
    */
   void writeData1(uint8_t data) {
      writeReg(OUTPUT_PORT1, data);
   }

   /**
    * Read input data from PORT0 pins
    *
    * @param[out] data Data read
    */
   void readData0(uint8_t &data) {
      readReg(INPUT_PORT0, data);
   }

   /**
    * Read input data from PORT pins
    *
    * @param[out] data Data read
    */
   void readData1(uint8_t &data) {
      readReg(INPUT_PORT1, data);
   }

   /**
    * Read the state of output latch for PORT0 pins
    *
    * @param[out] data State read
    *
    * @note This will not be the pin value if the pin is configured as an input.
    */
   void readState0(uint8_t &data) {
      readReg(OUTPUT_PORT0, data);
   }

   /**
    * Read the state of output latch for PORT1 pins
    *
    * @param[out] data State read
    *
    * @note This will not be the pin value if the pin is configured as an input.
    */
   void readState1(uint8_t &data) {
      readReg(OUTPUT_PORT0, data);
   }

   /**
    * Set PORT0 input polarity
    *
    * @param[in] mask Bit-mask controlling polarity of input pins (0=> normal, 1=> inverted)
    */
   void setInputPolarity0(uint8_t mask) {
      writeReg(POLARITY_INVERSION0, mask);
   }

   /**
    * Set PORT1 input polarity
    *
    * @param[in] mask Bit-mask controlling polarity of input pins (0=> normal, 1=> inverted)
    */
   void setInputPolarity1(uint8_t mask) {
      writeReg(POLARITY_INVERSION1, mask);
   }

}; // class pca9555

} // End namespace USBDM

#endif /* SOURCES_PCA9555_H_ */
