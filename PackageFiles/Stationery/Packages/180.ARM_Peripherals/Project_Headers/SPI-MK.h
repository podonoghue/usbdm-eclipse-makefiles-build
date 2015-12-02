/**
 * @file     spi.h (derived from spi-MK.h)
 *
 * @brief    Abstracion layer for SPI interface
 *
 * @version   1.1.0
 * @date     2015/12
 */

#ifndef INCLUDE_USBDM_SPI_H_
#define INCLUDE_USBDM_SPI_H_

#include <stdint.h>
#include "derivative.h"
#include "gpio.h"

namespace USBDM {

static const uint32_t DEFAULT_SPI_FREQUENCY = 10000000;     //!< Default SPI frequency 10 MHz

/**
 * @addtogroup SPI_Group Serial Peripheral Interface
 * @brief C++ Class allowing access to SPI interface
 * @{
 */

/**
 * @brief Base class for representing an SPI interface
 */
class Spi {
protected:
   volatile  SPI_Type *spi;
   uint32_t  spiBaudValue;
   uint32_t  interfaceFrequency;  //!< Interface frequency to use
   uint32_t  pushrMask;

protected:
   /**
    * Constructor
    *
    * @param baseAddress  Base address of SPI
    */
   Spi(volatile SPI_Type  *baseAddress);
   
public:
   /**
    * Sets Communication speed for SPI
    *
    * @param frequency => Frequency in Hz (0 => use default value)
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   void setSpeed(uint32_t frequency = DEFAULT_SPI_FREQUENCY);
   /**
    * Gets current speed of interface
    *
    * @return Speed in Hz
    */
   uint32_t getSpeed(void) {
      return interfaceFrequency;
   }
   /**
    * Set value combined with data for PUSHR register
    * For example this may be used to control which CTAR is used or which SPI_PCSx signal is asserted
    *
    * @param pushrMask Value to combine with Tx data before writing to PUSHR register
    *                  For example, SPI_PUSHR_CTAS(1)|SPI_PUSHR_PCS(1<<2)
    */
   void setPushrValue(uint32_t pushrMask) {
      this->pushrMask = pushrMask;
   }
   /**
    *  Transmit and receive a series of bytes
    *
    *  @param dataSize  Number of bytes to transfer
    *  @param dataOut   Transmit bytes (may be NULL for Rx only)
    *  @param dataIn    Receive byte buffer (may be NULL for Tx only)
    *
    *  Note: dataIn may use same buffer as dataOut
    */
   void txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn=0);

   /**
    *  Transmit and receive a series of 16-bit values
    *
    *  @param dataSize  Number of values to transfer
    *  @param dataOut   Transmit values (may be NULL for Rx only)
    *  @param dataIn    Receive buffer (may be NULL for Tx only)
    */
   void txRxWords(uint32_t dataSize, const uint16_t *dataOut, uint16_t *dataIn=0);

   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   uint32_t txRx(uint32_t data);

   static const uint32_t mask = ~(SPI_CTAR_BR_MASK|SPI_CTAR_PBR_MASK|SPI_CTAR_DBR_MASK);

   /*! Set SPI.CTAR0 value
    *
    * @param ctar 32-bit CTAR value (excluding baud related settings)
    *     e.g. setCTAR0Value(SPI_CTAR_SLAVE_FMSZ(8-1)|SPI_CTAR_PBR_CPOL|SPI_CTAR_PBR_MASK_CPHA)
    */
   void setCTAR0Value(uint32_t ctar) {
      spi->CTAR[0] = spiBaudValue|(ctar&mask);
   }

   /*! Set SPI.CTAR1 value
    *
    * @param ctar 32-bit CTAR value (excluding baud related settings)
    *     e.g. setCTAR1Value(SPI_CTAR_SLAVE_FMSZ(8-1)|SPI_CTAR_PBR_CPOL|SPI_CTAR_PBR_MASK_CPHA)
    */
   void setCTAR1Value(uint32_t ctar) {
      spi->CTAR[1] = spiBaudValue|(ctar&mask);
   }

   void on() {

   }

   void off() {

   }
};

#if defined(SPI0) && defined(SPI0_SCK_GPIO) && defined(SPI0_SIN_GPIO) && defined(SPI0_SOUT_GPIO)
/**
 * Class representing SPI0
 */
class Spi0 : public Spi {
public:
   /**
    * Constructor
    */
   Spi0();
};
#endif

#if defined(SPI1) && defined(SPI1_SCK_GPIO) && defined(SPI1_SIN_GPIO) && defined(SPI1_SOUT_GPIO)
/**
 * Class representing SPI1
 */
class Spi1 : public Spi {
public:
   /**
    * Constructor
    */
   Spi1();
};
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* SPI_H_ */
