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

static constexpr uint32_t DEFAULT_SPI_FREQUENCY = 10000000;     //!< Default SPI frequency 10 MHz

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
   Spi(volatile SPI_Type *baseAddress, DMAChannel *dmaTxChannel, DMAChannel *dmaRxChannel, uint8_t rxMuxSource) :
      spi(baseAddress),
      dmacTxChannel(dmaTxChannel),
      dmacRxChannel(dmaRxChannel),
      dmaSpiRxSlot(rxMuxSource),
      interfaceFrequency(DEFAULT_SPI_FREQUENCY) {
   }
   /**
    * Initialise the SPI
    */
   void init() {
      setSpeed();   // Use default speed
      spi->C2 = SPI_C2_MODFEN_MASK|SPI_C2_TXDMAE_MASK|SPI_C2_RXDMAE_MASK;
      spi->C1 = SPI_C1_SPE_MASK|SPI_C1_MSTR_MASK;//|SPI0_C1_SSOE_VALUE;//|SPI_C1_CPHA_MASK|SPI_C1_CPOL_MASK;
   }

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

/**
 * @brief Template class representing a SPI interface
 *
 * @tparam  spiBasePtr     Base address of SPI hardware
 * @tparam  spiClockReg    Address of SIM register controlling SPI hardware clock
 * @tparam  spiClockMask   Clock mask for SIM clock register
 * @tparam  SpiSCK         Pcr used for SCK signal
 * @tparam  SpiMISO        Pcr used for MISO signal
 * @tparam  SpiMOSI        Pcr used for MOSI signal
 * @tparam  Rest...        GpioX used for PCSx
 */
template<uint32_t spiBasePtr, uint32_t spiClockReg, uint32_t spiClockMask, typename SpiSCK, typename  SpiMISO, typename  SpiMOSI, typename ... Rest>
class Spi_T : public Spi {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param rxMuxSource  Receive Mux value (Tx mux value is assumed to be rxMuxSource+1)
    */
   Spi_T(USBDM::DMAChannel *dmaTxChannel, USBDM::DMAChannel *dmaRxChannel, uint8_t rxMuxSource) :
      Spi(reinterpret_cast<volatile SPI_Type*>(spiBasePtr), dmaTxChannel, dmaRxChannel, rxMuxSource) {

      // Configure SPI pins
      processPcrs<SpiSCK, SpiMISO, SpiMOSI, Rest...>();

      // Enable SPI module clock
      *reinterpret_cast<volatile uint32_t*>(spiClockReg) |= spiClockMask;

      init();
   }
};

#if defined(SPI0) && (SPI0_SCK_PIN_SEL!=0) && (SPI0_MOSI_PIN_SEL!=0) && (SPI0_MISO_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI0 interface with PCS
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0<USBDM::spi0_PCS0>(new USBDM::DMAChannel0(), new USBDM::DMAChannel1(), USBDM::DMA_SLOT_SPI0_Receive);
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCS...        Pcr used for PCSx
 */
template<typename ... PCS>
class Spi0_T : public Spi_T<SPI0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI0_CLOCK_REG), SPI0_CLOCK_MASK, spi0_SCK, spi0_MOSI, spi0_MISO, PCS...> {

protected:
   class Spi0_T *thisPtr;

public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param rxMuxSource  Receive Mux value (Tx mux value is assumed to be rxMuxSource+1)
    */
   Spi0_T(USBDM::DMAChannel *dmaTxChannel, USBDM::DMAChannel *dmaRxChannel, uint8_t rxMuxSource=USBDM::DMA0_SLOT_SPI0_Receive) :
      Spi_T<SPI0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI0_CLOCK_REG), SPI0_CLOCK_MASK, spi0_SCK, spi0_MOSI, spi0_MISO, PCS...>(dmaTxChannel, dmaRxChannel, rxMuxSource) {
      NVIC_EnableIRQ(SPI0_IRQn);
      NVIC_SetPriority(SPI0_IRQn, 2);
   }
};

/**
 * @brief Alias for SPI0 interface without PCS
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0(new USBDM::DMAChannel0(), new USBDM::DMAChannel1(), USBDM::DMAChannel::DMA_SLOT_SPI0_Rx);
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 */
using Spi0 = Spi0_T<>;

/**
 * @brief Template class representing a SPI0 interface with GPIO used as select signal
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0Gpio_T<USBDM::GpioC<3>, false>(new USBDM::DMAChannel0(), new USBDM::DMAChannel1());
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  Gpio        Gpio used as select signal
 * @tparam  enableValue Value used as selected level
 */
template<typename Gpio, bool enableValue=false>
class Spi0Gpio_T : public Spi0 {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi0Gpio_T(USBDM::DMAChannel *dmaTxChannel, USBDM::DMAChannel *dmaRxChannel) :
      Spi0(dmaTxChannel, dmaRxChannel) {
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
      Gpio::write(enableValue);
      Spi::txRxBytes(dataSize, dataOut, dataIn=0);
      Gpio::write(!enableValue);
   }
   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   virtual uint32_t txRx(uint32_t data) {
      Gpio::write(enableValue);
      uint32_t rv = Spi::txRx(data);
      Gpio::write(!enableValue);
      return rv;
   }
};
#endif // defined(SPI0) && (SPI0_SCK_PIN_SEL!=0) && (SPI0_MOSI_PIN_SEL!=0) && (SPI0_MISO_PIN_SEL!=0)

#if defined(SPI1) && (SPI1_SCK_PIN_SEL!=0) && (SPI1_MOSI_PIN_SEL!=0) && (SPI1_MISO_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI1 interface with PCS
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1<USBDM::spi1_PCS0>(new USBDM::DMAChannel0(), new USBDM::DMAChannel1(), USBDM::DMA_SLOT_SPI1_Receive);
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCS...        Pcr used for PCSx
 */
template<typename ... PCS>
class Spi1_T : public Spi_T<SPI1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI1_CLOCK_REG), SPI1_CLOCK_MASK, spi1_SCK, spi1_MOSI, spi1_MISO, PCS...> {

protected:
   class Spi1_T *thisPtr;

public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    * @param rxMuxSource  Receive Mux value
    */
   Spi1_T(USBDM::DMAChannel *dmaTxChannel, USBDM::DMAChannel *dmaRxChannel, uint8_t rxMuxSource=USBDM::DMA0_SLOT_SPI1_Receive) :
      Spi_T<SPI1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI1_CLOCK_REG), SPI1_CLOCK_MASK, spi1_SCK, spi1_MOSI, spi1_MISO, PCS...>(dmaTxChannel, dmaRxChannel, rxMuxSource) {
      NVIC_EnableIRQ(SPI1_IRQn);
      NVIC_SetPriority(SPI1_IRQn, 2);
   }
};

/**
 * @brief Alias for SPI0 interface without PCS
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1(new USBDM::DMAChannel0(), new USBDM::DMAChannel1(), 3);
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 */
using Spi1 = Spi1_T<>;

/**
 * @brief Template class representing a SPI1 interface with GPIO used as select signal
 *
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1Gpio_T<USBDM::GpioC<3>, false>(new USBDM::DMAChannel0(), new USBDM::DMAChannel1());
 *
 * uint8_t txData[] = {1,2,3,4};
 * uint8_t rxData[sizeof(txData)];
 *
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  Gpio        Gpio used as select signal
 * @tparam  enableValue Value used as selected level
 */
template<typename Gpio, bool enableValue=false>
class Spi1Gpio_T : public Spi1 {
public:
   /**
    * Constructor
    *
    * @param dmaTxChannel DMA Channel for transmission
    * @param dmaRxChannel DMA Channel for reception
    */
   Spi1Gpio_T(USBDM::DMAChannel *dmaTxChannel, USBDM::DMAChannel *dmaRxChannel) :
      Spi1(dmaTxChannel, dmaRxChannel) {
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
      Gpio::write(enableValue);
      Spi::txRxBytes(dataSize, dataOut, dataIn=0);
      Gpio::write(!enableValue);
   }
   /**
    * Transmit and receive an 8-bit value over SPI
    *
    * @param data - Data to send
    *
    * @return Data received
    */
   virtual uint32_t txRx(uint32_t data) {
      Gpio::write(enableValue);
      uint32_t rv = Spi::txRx(data);
      Gpio::write(!enableValue);
      return rv;
   }
};
#endif // defined(SPI1) && (SPI1_SCK_PIN_SEL!=0) && (SPI1_MOSI_PIN_SEL!=0) && (SPI1_MISO_PIN_SEL!=0)
/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
