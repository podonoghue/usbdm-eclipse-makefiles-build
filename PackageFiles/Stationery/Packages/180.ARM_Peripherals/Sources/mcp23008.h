/**
 * @file mcp23008.h
 *
 * C++ interface for MCP23008 I2C GPIO expander
 */

#ifndef SOURCES_MCP23008_H_
#define SOURCES_MCP23008_H_

#include "i2c.h"

namespace USBDM {

/**
 * The controls the incrementing function of the address pointer on register read/write
 */
enum Mcp23008Sequential {
   Mcp23008Sequential_Enable  = 0<<5, //!< Sequential enabled, address pointer increments
   Mcp23008Sequential_Disable = 1<<5, //!< Sequential disabled, address pointer does not increment
};

/**
 * Slew Rate control bit for I2C SDA output.
 * If enabled, the SDA slew rate will be controlled when driving from a high to a low.
 */
enum Mcp23008SlewRate {
   Mcp23008SlewRate_Fast  = 1<<4, //!< Slew rate disabled i.e. fast transition
   Mcp23008SlewRate_Slow  = 0<<4, //!< Slew rate enabled i.e. slow transition
};

/**
 * Controls the polarity and drive mode of the IRQ pin
 */
enum Mcp23008Interrupt {
   Mcp23008Interrupt_OpenDrain   = 0b10<<1, //!< IRQ pin is open-drain and active-low
   Mcp23008Interrupt_ActiveLow   = 0b00<<1, //!< IRQ pin is push-pull and active-low
   Mcp23008Interrupt_ActiveHigh  = 0b01<<1, //!< IRQ pin is push-pull and active-high
};

class mcp23008 {

private:
   // Address (LSB = R/W bit)
   const unsigned MCP23008_ADDRESS;

   // I2C Interface to use
   I2c &i2c;

   /**
    * Device register addresses
    */
   enum RegAddress {
      IODIR_ADDR,  //!< IODIR_ADDR
      IPOL_ADDR,   //!< IPOL_ADDR
      GPINTEN_ADDR,//!< GPINTEN_ADDR
      DEFVAL_ADDR, //!< DEFVAL_ADDR
      INTCON_ADDR, //!< INTCON_ADDR
      IOCON_ADDR,  //!< IOCON_ADDR
      GPPU_ADDR,   //!< GPPU_ADDR
      INTF_ADDR,   //!< INTF_ADDR
      INTCAP_ADDR, //!< INTCAP_ADDR
      GPIO_ADDR,   //!< GPIO_ADDR
      OLAT_ADDR,   //!< OLAT_ADDR
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
      i2c.transmit(MCP23008_ADDRESS, sizeof(txData), txData);
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
      i2c.txRx(MCP23008_ADDRESS, sizeof(txData), txData, sizeof(rxData), rxData);
      i2c.endTransaction();

      value = rxData[0];
   }

public:

   /**
    * Create the MCP23008 interface
    *
    * @param[in] i2cInterface        I2C interface to use for communication
    * @param[in] i2cAddress          Bottom 3-bits of I2C address (determined by pin-strapping)
    * @param[in] mcp23008SlewRate    Slew rate control for SDA pin (defaults to fast)
    * @param[in] mcp23008Interrupt   IRQ pin mode (defaults to open-drain)
    */
   constexpr mcp23008(
         USBDM::I2c        &i2cInterface,
         uint8_t            i2cAddress        = 0b000,
         Mcp23008SlewRate   mcp23008SlewRate  = Mcp23008SlewRate_Fast,
         Mcp23008Interrupt  mcp23008Interrupt = Mcp23008Interrupt_OpenDrain
         ) :
            MCP23008_ADDRESS((0b0100000|(i2cAddress&0b111))<<1),
            i2c(i2cInterface) {

      writeReg(
            IOCON_ADDR,
            mcp23008SlewRate|mcp23008Interrupt|Mcp23008Sequential_Disable);
   }

   /**
    * Set GPIO direction
    *
    * @param[in] mask Bit-mask controlling pin direction (0=> out, 1=> in)
    */
   void setDirection(uint8_t mask) {
      writeReg(IODIR_ADDR, mask);
   }

   /**
    * Write output data to GPIO pins
    *
    * @param[in] data  Data value to output to pins (if configured as output)
    */
   void writeData(uint8_t data) {
      writeReg(GPIO_ADDR, data);
   }

   /**
    * Read input data from GPIO pins
    *
    * @param[out] data Data read
    */
   void readData(uint8_t &data) {
      readReg(GPIO_ADDR, data);
   }

   /**
    * Read the state of output latch for GPIO pins
    *
    * @param[out] data State read
    *
    * @note This will not be the pin value if the pin is configured as an input.
    */
   void readState(uint8_t &data) {
      readReg(OLAT_ADDR, data);
   }

   /**
    * Set GPIO pin polarity
    *
    * @param[in] mask Bit-mask controlling polarity of input pins (0=> normal, 1=> inverted)
    */
   void setInputPolarity(uint8_t mask) {
      writeReg(IPOL_ADDR, mask);
   }

   /**
    * Set GPIO pin pull-ups
    *
    * @param[in] mask Bit-mask controlling pull-ups (0=> Disabled, 1=> Enabled)
    */
   void setPullUps(uint8_t mask) {
      writeReg(GPPU_ADDR, mask);
   }

   /**
    *
    * @param[out] flags       Bit-mask reflecting the pins generating the current interrupt conditions
    * @param[out] gpioState   State of the GPIO Port value at the (first) interrupt
    *
    * @note Flags show the current interrupt condition of all pins enabled for interrupts.
    *       Multiple bits may be set but only the first will have led to an update of the gpioState.
    *
    * @note GpioState captures the GPIO port value at the time the (first) interrupt occurred.
    *       The value is updated only when an interrupt occurs and remained unchanged until cleared.
    *       The value is cleared by this method or readData().
    */
   void pollInterruptState(uint8_t &flags, uint8_t &gpioState) {
      readReg(INTCAP_ADDR, gpioState);
      readReg(INTF_ADDR, flags);
   }

   /**
    * Configure the pin interrupt function.
    * Enabled pins may be configured to generate an interrupt when they differ
    * from a default value or when they change i.e. differ from their previous value.
    *
    * @param[in] enableMask    Pin enable bit-mask 0=> disable, 1=> enable
    * @param[in] modeMask      Comparison method bit-mask 0=> Against previous pin value, 1=> Against default value
    * @param[in] defaultMask   Default (reference) bit-mask for pins (IRQ when pin differs)
    *
    * @note Only pins configured as inputs may generate interrupts.
    */
   void configureInterruptOnChange(
         uint8_t enableMask,
         uint8_t modeMask,
         uint8_t defaultMask = 0
   ) {
      // Disable before changes
      writeReg(GPINTEN_ADDR,  0);
      writeReg(DEFVAL_ADDR,   defaultMask);
      writeReg(INTCON_ADDR,   modeMask);
      writeReg(GPINTEN_ADDR,  enableMask);
   }

}; // class mcp23008

} // End namespace USBDM

#endif /* SOURCES_MCP23008_H_ */
