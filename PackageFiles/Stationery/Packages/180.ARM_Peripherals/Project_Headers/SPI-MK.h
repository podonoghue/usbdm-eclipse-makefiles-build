/****************************************************************************************************//**
 * @file     spi.h
 *
 * @brief    Abstracion layer for I2C interface
 *
 * @version  V0.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "derivative.h"
#include "pin_mapping.h"

/**
 * @addtogroup SPI_Group Serial Peripheral Interface
 * @brief C++ Class allowing access to SPI interface
 * @{
 */

/**
 * @brief Class representing an SPI interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  SPI *spi = new SPI_0();
 *  spi->setSpeed(400000);
 *
 *  // Transmit message (reception discarded)
 *  const uint8_t outBuffer[] = {1,2,3,4};
 *  spi->txRxBytes(sizeof(outBuffer), outBuffer);
 *
 *  // Receive message (transmission of 0xFF)
 *  uint8_t inBuffer[100];
 *  spi->txRxBytes(sizeof(inBuffer), 0, inBuffer);
 *
 *  // Transmit and receive message
 *  uint8_t inoutBuffer[100] = {1,2,3,4};
 *  spi->txRxBytes(sizeof(inoutBuffer), inoutBuffer, inoutBuffer);
 *
 *  @endcode
 */
class SPI {
protected:
   volatile  SPI_Type *spi;
   uint32_t  spiBaudValue;
   uint32_t  interfaceFrequency;
   uint32_t  pushrMask;

protected:
   /**
    * Constructor
    *
    * @param baseAddress  Base address of SPI
    */
   SPI(volatile SPI_Type  *baseAddress);
   
public:
   /**
    * Sets Communication speed for SPI
    *
    * @param frequency => Frequency in Hz (0 => use default value)
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   void setSpeed(uint32_t frequency);
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

/**
 * Class representing SPI0
 */
class SPI_0 : public SPI {
public:
   /**
    * Constructor
    */
   SPI_0();
};

#ifdef SPI1
/**
 * Class representing SPI1
 */
class SPI_1 : public SPI {
public:
   /**
    * Constructor
    */
   SPI_1();
};
#endif

/**
 * @}
 */

#endif /* SPI_H_ */
