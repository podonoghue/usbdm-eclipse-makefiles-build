/**
 * @file     spi.h (derived from spi-MKL.h)
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
#include "dma.h"
#include "gpio.h"

namespace USBDM {

extern "C" void SPI0_IRQHandler(void);
extern "C" void SPI1_IRQHandler(void);
extern "C" void SPI2_IRQHandler(void);

/**
 * @addtogroup SPI_Group Serial Peripheral Interface
 * @brief C++ Class allowing access to SPI interface
 * @{
 */

/**
 * @brief Base class for representing an SPI interface
 */
class Spi {
   /** Allow access from ISR */
   friend void SPI0_IRQHandler(void);
   /** Allow access from ISR */
   friend void SPI1_IRQHandler(void);
   /** Allow access from ISR */
   friend void SPI2_IRQHandler(void);

protected:
   volatile SPI_Type   *spi;                 //!< SPI hardware
   DMAChannel          *dmacTxChannel;       //!< DMA hardware
   DMAChannel          *dmacRxChannel;       //!< DMA hardware
   uint8_t              dmaSpiRxSlot;        //!<
   uint32_t             interfaceFrequency;  //!< Interface frequency to use

protected:
   /**
    * Constructor
    *
    * @param baseAddress  Base address of SPI
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param rxMuxSource  Receive Mux value
    */
   Spi(volatile SPI_Type *baseAddress, DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, uint8_t rxMuxSource);
   /**
    *  Not used
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
   virtual void txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn=0);
   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   virtual uint32_t txRx(uint32_t data);
};

#if defined(SPI0) && defined(SPI0_SCK_GPIO) && defined(SPI0_MOSI_GPIO) && defined(SPI0_MISO_GPIO)
/**
 *
 * @brief Class for representing an SPI interface
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
class Spi0 : public Spi {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi0(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel);

private:
   /** Use by ISR to access class */
   static Spi0 *thisPtr;

   /** Allow access from ISR */
   friend void SPI0_IRQHandler(void);
};

template<class Gpio>
class Spi0_Gpio : public Spi0 {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi0_Gpio(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel) : Spi0(dmaTxChannel, dmaRxChannel) {
      Gpio::setDigitalOutput();
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
   virtual void txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn=0) {
      Gpio::set();
      Spi0::txRxBytes(dataSize, dataOut, dataIn);
      Gpio::clear();
   }

   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   virtual uint32_t txRx(uint32_t data) {
      Gpio::set();
      uint32_t rc = Spi0::txRx(data);
      Gpio::clear();
      return rc;
   }
};
#endif

#if defined(SPI1) && defined(SPI1_SCK_GPIO) && defined(SPI1_MOSI_GPIO) && defined(SPI1_MISO_GPIO)
/**
 *
 * @brief Class for representing an SPI interface
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
class Spi1 : public Spi {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi1(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel);

private:
   /** Use by ISR to access class */
   static Spi1 *thisPtr;

   /** Allow access from ISR */
   friend void SPI1_IRQHandler(void);
};

template<class Gpio>
class Spi1_Gpio : public Spi1 {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi1_Gpio(DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel) : Spi0(dmaTxChannel, dmaRxChannel) {
      Gpio::setDigitalOutput();
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
   virtual void txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn=0) {
      Gpio::set();
      Spi1::txRxBytes(dataSize, dataOut, dataIn);
      Gpio::clear();
   }
   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   virtual uint32_t txRx(uint32_t data) {
      Gpio::set();
      uint32_t rc = Spi1::txRx(data);
      Gpio::clear();
      return rc;
   }
};
#endif
/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
