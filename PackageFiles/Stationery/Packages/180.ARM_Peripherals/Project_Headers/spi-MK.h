/**
 * @file     spi.h (derived from spi-MK.h)
 *
 * @brief    Abstraction layer for SPI interface
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

static constexpr uint32_t SPI_CPHA = SPI_CTAR_CPHA_MASK;     // Clock phase    - First edge on SPSCK occurs at the start of the first cycle of a data transfer
static constexpr uint32_t SPI_CPOL = SPI_CTAR_CPOL_MASK;     // Clock polarity - Active-low SPI clock (idles high)
static constexpr uint32_t SPI_LSBF = SPI_CTAR_LSBFE_MASK;    // LSB transmitted  first

static constexpr uint32_t SPI_MODE0 (0       |0);
static constexpr uint32_t SPI_MODE1 (0       |SPI_CPHA);
static constexpr uint32_t SPI_MODE2 (SPI_CPOL|0);
static constexpr uint32_t SPI_MODE3 (SPI_CPOL|SPI_CPHA);

static constexpr uint32_t DEFAULT_SPI_FREQUENCY = 10000000;     //!< Default SPI frequency 10 MHz
static constexpr uint32_t DEFAULT_SPI_MODE      = SPI_MODE0;    //!< Default SPI mode for TxRx
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
   volatile  SPI_Type *spi;       //!< SPI hardware
   uint32_t  spiBaudValue;        //!< Current Baud Rate
   uint32_t  interfaceFrequency;  //!< Interface frequency to use
   uint32_t  pushrMask;           //!< Value to combine with data

protected:
   /**
    * Constructor
    *
    * @param baseAddress - Base address of SPI
    */
   Spi(volatile SPI_Type *baseAddress) :
      spi(baseAddress), spiBaudValue(0), pushrMask(SPI_PUSHR_PCS_MASK) {
   }

public:
   virtual void enablePins() = 0;
   virtual void disablePins() = 0;
   /**
    * Sets Communication speed for SPI
    *
    * @param frequency => Frequency in Hz (0 => use default value)
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    * Note: This will only have effect the next time a CTAR is changed
    */
   void setSpeed(uint32_t frequency = DEFAULT_SPI_FREQUENCY);
   /**
    * Sets Communication mode for SPI
    *
    * @param mode => Mode to set combination of spi_CPHA etc
    */
   void setMode(uint32_t mode=DEFAULT_SPI_MODE) {
      // Sets the default CTAR value with 8 bits
      setCTAR0Value((mode & (SPI_CPHA|SPI_CPOL|SPI_LSBF))|SPI_CTAR_FMSZ(8-1));
   }
   /**
    * Gets current speed of interface
    *
    * @return Speed in Hz
    */
   uint32_t getSpeed(void) {
      return interfaceFrequency;
   }
   /**
    * Set value that is combined with data for PUSHR register
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
    * Transmit and receive a value over SPI
    *
    * @param data - Data to send (8-16 bits) <br>
    *               May include other control bits
    *
    * @return Data received
    */
   uint32_t txRx(uint32_t data);

   static constexpr uint32_t mask = ~(SPI_CTAR_BR_MASK|SPI_CTAR_PBR_MASK|SPI_CTAR_DBR_MASK);

   /*! Set SPI.CTAR0 value
    *
    * @param ctar 32-bit CTAR value (excluding baud related settings)
    *     e.g. setCTAR0Value(SPI_CTAR_SLAVE_FMSZ(8-1)|SPI_CTAR_CPOL_MASK|SPI_CTAR_CPHA_MASK);
    */
   void setCTAR0Value(uint32_t ctar) {
      spi->CTAR[0] = spiBaudValue|(ctar&mask);
   }

   /*! Set SPI.CTAR1 value
    *
    * @param ctar 32-bit CTAR value (excluding baud related settings)
    *     e.g. setCTAR1Value(SPI_CTAR_SLAVE_FMSZ(8-1)|SPI_CTAR_CPOL_MASK|SPI_CTAR_CPHA_MASK);
    */
   void setCTAR1Value(uint32_t ctar) {
      spi->CTAR[1] = spiBaudValue|(ctar&mask);
   }
};

/**
 * @brief Template class representing a SPI interface
 *
 * @tparam  spiBasePtr     Base address of SPI hardware
 * @tparam  spiClockReg    Address of SIM register controlling SPI hardware clock
 * @tparam  spiClockMask   Clock mask for SIM clock register
 * @tparam  SpiSCK         Pcr used for SCK signal
 * @tparam  SpiSIN         Pcr used for SIN signal
 * @tparam  SpiSOUT        Pcr used for SOUT signal
 * @tparam  Rest...        Pcrs used for PCSx
 */
template<uint32_t spiBasePtr, uint32_t spiClockReg, uint32_t spiClockMask, typename SpiSCK, typename  SpiSIN, typename  SpiSOUT, typename ... Rest>
class Spi_T : public Spi {
public:
   virtual void enablePins() {
      // Configure SPI pins
      processPcrs<SpiSCK, SpiSIN, SpiSOUT, Rest...>();
   }

   virtual void disablePins() {
      // Configure SPI pins
      processPcrs<SpiSCK, SpiSIN, SpiSOUT, Rest...>(0);
   }

   /**
    * Constructor
    */
   Spi_T() : Spi(reinterpret_cast<volatile SPI_Type*>(spiBasePtr)) {
      // Enable SPI module clock
      *reinterpret_cast<volatile uint32_t*>(spiClockReg) |= spiClockMask;

      spi->MCR   = SPI_MCR_HALT_MASK|SPI_MCR_CLR_RXF_MASK|SPI_MCR_ROOE_MASK|SPI_MCR_CLR_TXF_MASK|
                   SPI_MCR_MSTR_MASK|SPI_MCR_DCONF(0)|SPI_MCR_SMPL_PT(0)|SPI_MCR_PCSIS_MASK;

      setSpeed();                        // Use default speed
      setCTAR0Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers
      setCTAR1Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers

      // Configure SPI pins
      enablePins();
   }
};

#if defined(SPI0) && (SPI0_SCK_PIN_SEL!=0) && (SPI0_SIN_PIN_SEL!=0) && (SPI0_SOUT_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI0 interface with optional PCSs
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0_T<USBDM::spi0_PCS1>();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
template<typename ... PCSs> using  Spi0_T = Spi_T<SPI0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI0_CLOCK_REG), SPI0_CLOCK_MASK,
      spi0_SCK, spi0_SIN, spi0_SOUT, PCSs...>;

/**
 * @brief Alias representing a SPI0 interface without PCS use
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
using Spi0 = Spi0_T<>;
#endif

#if defined(SPI1) && (SPI1_SCK_PIN_SEL!=0) && (SPI1_SIN_PIN_SEL!=0) && (SPI1_SOUT_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI1 interface with optional PCSs
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1_T<USBDM::spi1_PCS1>();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
template<typename ... PCSs> using  Spi1_T = Spi_T<SPI1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI1_CLOCK_REG), SPI1_CLOCK_MASK,
      spi1_SCK, spi1_SIN, spi1_SOUT, PCSs...>;

/**
 * @brief Alias representing a SPI1 interface without PCS use
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
using Spi1 = Spi1_T<>;
#endif
/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
