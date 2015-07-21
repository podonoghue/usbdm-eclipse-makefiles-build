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
#include "dma.h"
#include "gpio.h"

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
 *  SPI *spi0 = new SPI_0(new DMAChannel0(), new DMAChannel1());
 *  spi0->setSpeed(400000);
 *
 *  // Transmit message (reception discarded)
 *  const uint8_t outBuffer[100] = {1,2,3,4};
 *  spi->txRxBytes(sizeof(outBuffer), outBuffer);
 *
 *  // Transmit and receive message
 *  uint8_t inoutBuffer[100] = {1,2,3,4};
 *  spi->txRxBytes(sizeof(inoutBuffer), inoutBuffer, inoutBuffer);
 *
 *  @endcode
 */
class SPI {
protected:
   volatile SPI_Type             *spi;
   DMAChannel                    *dmacTxChannel;
   DMAChannel                    *dmacRxChannel;
   uint8_t                        dmaSpiRxSlot;
   DigitalIO                     *pcs;
   uint32_t                       interfaceFrequency;

protected:
   /**
    * Constructor
    *
    * @param baseAddress  Base address of SPI
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param rxMuxSource  Receive Mux value
    * @param pcs          Manual PCS select signal
    */
   SPI(volatile SPI_Type *baseAddress, DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, uint8_t rxMuxSource, DigitalIO *pcs);
   /**
    *
    */
   void poll();

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
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   uint32_t txRx(uint32_t data);
};

/**
 * Class representing SPI0
 */
class SPI_0 : public SPI {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param pcs          Manual PCS select signal
    */
   SPI_0(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, DigitalIO *pcs=0);
private:
   static SPI_0 *thisPtr;
   /**
    * Interrupt handler
    */
   friend void SPI0_IRQHandler(void);
};

#ifdef SPI1
/**
 * Class representing SPI1
 */
class SPI_1 : public SPI {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param pcs          Manual PCS select signal
    */
   SPI_1(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, DigitalIO *pcs=0);
private:
   static SPI_1 *thisPtr;
   /**
    * Interrupt handler
    */
   friend void SPI1_IRQHandler(void);
};

#endif

/**
 * @}
 */

#endif /* SPI_H_ */
