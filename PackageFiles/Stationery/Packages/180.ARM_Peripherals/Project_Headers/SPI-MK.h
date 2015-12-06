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
   uint32_t  pushrMask;           //!< Value to combine with data

protected:
   /**
    * Constructor
    *
    * @param baseAddress - Base address of SPI
    */
   Spi(volatile SPI_Type *baseAddress) :
      spi(baseAddress), spiBaudValue(0), pushrMask(SPI_PUSHR_PCS_MASK) {
      setSpeed();   // Use default speed
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
};

/**
 * @brief Template class representing a SPI interface
 *
 * @tparam  spiBasePtr     Base address of SPI hardware
 * @tparam  spiClockReg    Address of SIM register controlling SPI hardware clock
 * @tparam  spiClockMask   Clock mask for SIM clock register
 * @tparam  SpiSCK         GpioX used for SCK signal
 * @tparam  SpiSIN         GpioX used for SIN signal
 * @tparam  SpiSOUT        GpioX used for SOUT signal
 * @tparam  Rest...        GpioX used for PCSx
 */
template<uint32_t spiBasePtr, uint32_t spiClockReg, uint32_t spiClockMask, typename SpiSCK, typename  SpiSIN, typename  SpiSOUT, typename ... Rest>
class Spi_T : public Spi {
public:
   /**
    * Constructor
    */
   Spi_T() : Spi(reinterpret_cast<volatile SPI_Type*>(spiBasePtr)) {
      // Configure SPI pins
      processPcrs<SpiSCK, SpiSIN, SpiSOUT, Rest...>();

      // Enable SPI module clock
      *reinterpret_cast<volatile uint32_t*>(spiClockReg) |= spiClockMask;

      spi->MCR   = SPI_MCR_HALT_MASK|SPI_MCR_CLR_RXF_MASK|SPI_MCR_ROOE_MASK|SPI_MCR_CLR_TXF_MASK|
                   SPI_MCR_MSTR_MASK|SPI_MCR_DCONF(0)|SPI_MCR_SMPL_PT(0)|SPI_MCR_PCSIS_MASK;

      setSpeed(0);   // Use default speed
      setCTAR0Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers
      setCTAR1Value(SPI_CTAR_FMSZ(8-1)); // Default 8-bit transfers
   }
};

#if defined(SPI0) && (SPI0_SCK_PIN_SEL!=0) && (SPI0_SIN_PIN_SEL!=0) && (SPI0_SOUT_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI0 interface
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
template<typename ... PCSs> using  Spi0_T = Spi_T<SPI0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI0_CLOCK_REG), SPI0_CLOCK_MASK,
      spi0_SCK, spi0_SIN, spi0_SOUT, PCSs...>;

/**
 * @brief Template class representing a SPI0 interface
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
using Spi0 = Spi0_T<spi0_PCS0, spi0_PCS1, spi0_PCS2, spi0_PCS3, spi0_PCS4, spi0_PCS5>;
#endif

#if defined(SPI1) && (SPI1_SCK_PIN_SEL!=0) && (SPI1_SIN_PIN_SEL!=0) && (SPI1_SOUT_PIN_SEL!=0)
/**
 * @brief Template class representing a SPI0 interface
 *
 * @tparam  PCSs...    GpioX used for PCSx
 */
template<typename ... PCSs> using  Spi1_T = Spi_T<SPI1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, SPI1_CLOCK_REG), SPI1_CLOCK_MASK,
      spi1_SCK, spi1_SIN, spi1_SOUT, PCSs...>;

using Spi1 = Spi1_T<spi1_PCS1, spi1_PCS1, spi1_PCS2, spi1_PCS3>;
#endif
/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
