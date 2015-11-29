/****************************************************************************************************//**
 * @file     I2C.h
 *
 * @brief    Abstracion layer for I2C interface
 *
 * @version  V0.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "derivative.h"
#include "gpio.h"

#ifndef PORT_PCR_ODE_MASK
// Some devices don't have ODE function on pin
// The open-drain mode is automatically selected when I2C function is selected for the pin
#define PORT_PCR_ODE_MASK 0
#endif

namespace USBDM {

/**
 * @addtogroup I2C_Group Inter-Integrated-Circuit I2C
 * @brief C++ Class allowing access to I2C interface
 * @{
 */

/**
 * Virtual Base class for I2C interface
 */
class I2C {

public:
   /** Operating mode */
   enum Mode {
      polled    = 0,                   //!< Operate in polled mode
      interrupt = I2C_C1_IICIE_MASK,   //!< Operate in interrupt mode
   };

   /** States for the I2C state machine */
   enum I2C_State { i2c_idle, i2c_txData, i2c_rxData, i2c_rxAddress };

protected:
   I2C_Type           *i2c;                 //!< I2C hardware instance
   I2C_State           state;               //!< State of current transaction
   const Mode          mode;                //!< Mode of operation (interrupt/polled)
   uint16_t            rxBytesRemaining;    //!< Number of receive bytes remaining in current transaction
   uint16_t            txBytesRemaining;    //!< Number of transmit bytes remaining in current transaction
   uint8_t            *rxDataPtr;           //!< Pointer to receive data for current transaction
   const uint8_t      *txDataPtr;           //!< Pointer to transmit data for current transaction
   uint8_t             addressedDevice;     //!< Address of device being communicated with
   uint8_t             errorCode;           //!< Error code from last transaction

   /** I2C baud rate divisor table */
   static const uint16_t I2C_DIVISORS[4*16];

   /**
    * Construct I2C interface
    *
    * @param i2c  Base address of I2C hardware
    * @param mode Mode of operation (interrupt or polled)
    *
    */
   I2C(I2C_Type *i2c, I2C::Mode mode) : i2c(i2c), state(i2c_idle), mode(mode), rxBytesRemaining(0), rxDataPtr(0), addressedDevice(0), errorCode(0) {
   }

   /**
    * Calculate value for baud rate register of I2C
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param bps - Interface speed in bits-per-second
    */
   static uint8_t getBPSValue(uint32_t bps);

   /**
    * Start Rx/Tx sequence by sending address byte
    *
    * @param address - address of slave to access
    */
   void sendAddress(uint8_t address);

   /**
    * Set baud factor value for interface
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param bps - Interface speed in bits-per-second
    */
   void setBPS(uint32_t bps) {
      i2c->F = getBPSValue(bps);
   }

public:
   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high.
    *
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   virtual void busHangReset() = 0;

   /**
    * Wait for current sequence to complete
    */
   void waitWhileBusy(void) {
      while (state != i2c_idle) {
         if ((i2c->C1&I2C_C1_IICIE_MASK) == 0) {
            poll();
         }
         else {
            __asm__("wfi");
         }
      }
   }

   /**
    * I2C state-machine based interrupt handler
    */
   virtual void poll(void);

   /**
    * Transmit message
    *
    * @param address  Address of slave to communicate with
    * @param data     Data to transmit, 0th byte is often register address
    * @param size     Size of transmission data
    */
   int transmit(uint8_t address, const uint8_t data[], uint16_t size);

   /**
    * Receive message
    *
    * @param address  Address of slave to communicate with
    * @param data     Data buffer for reception
    * @param size     Size of reception data
    */
   int receive(uint8_t address,  uint8_t data[], uint16_t size);

   /**
    * Transmit message followed by receive message.
    *
    * Uses repeated-start.
    *
    * @param address  Address of slave to communicate with
    * @param txData   Data for transmission
    * @param txSize   Size of transmission data
    * @param rxData   Date buffer for reception
    * @param rxSize   Size of reception data
    */
   int txRx(uint8_t address, const uint8_t txData[], uint16_t txSize, uint8_t rxData[], uint16_t rxSize );

   /**
    * Transmit message followed by receive message.
    * Uses repeated-start.\n
    * Uses shared transmit and receive buffer
    *
    * @param address  Address of slave to communicate with
    * @param data     Data for transmission and reception
    * @param txSize   Size of transmission data
    * @param rxSize   Size of reception data
    */
   int txRx(uint8_t address, uint8_t data[], uint16_t txSize, uint16_t rxSize );

};

/**
 * @brief Template class representing an I2C interface
 *
 * @tparam  i2cBasePtr     Base address of I2C hardware
 * @tparam  i2cClockReg    Address of SIM register controlling I2C hardware clock
 * @tparam  i2cClockMask   Clock mask for SIM clock register
 * @tparam  Scl            GpioX used for SCL signal
 * @tparam  sclFn          PCR Mux value to connect SCL to pin
 * @tparam  Sda            GpioX used for SDA signal
 * @tparam  sdaFn          PCR Mux value to connect SDA to pin
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  I2C_0 *i2c0 = new USBDM::I2CT<I2C2_BasePtr,
 *            SIM_BasePtr+offsetof(SIM_Type, I2C2_CLOCK_REG), I2C2_CLOCK_MASK,
 *            USBDM::I2C2_SCL_GPIO, I2C2_SCL_FN,
 *            USBDM::I2C2_SDA_GPIO, I2C2_SDA_FN>();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *
 *  @endcode
 */
template<uint32_t i2cBasePtr, uint32_t i2cClockReg, uint32_t i2cClockMask, class Scl, int sclFn, class Sda, int sdaFn> class I2C_T : public I2C {
public:
   static class I2C *thisPtr;

private:
   friend void I2C0_IRQHandler(void);
   friend void I2C1_IRQHandler(void);
   friend void I2C2_IRQHandler(void);
   friend void I2C3_IRQHandler(void);

public:
   /**
    * Construct I2C interface
    *
    * @param baud
    * @param mode       Mode of operation
    * @param myAddress  Address of this device on bus (not currently used)
    *
    *
    * @tparam i2c        Hardware pointer
    * @tparam scl        I2C Clock port
    * @tparam sda        I2C Data port
    */
   I2C_T(unsigned baud=400000, I2C::Mode mode=I2C::Mode::polled, uint8_t myAddress=0) : I2C(reinterpret_cast<I2C_Type*>(i2cBasePtr), mode) {
      busHangReset();
      init(myAddress);
      setBPS(baud);
   }

   /**
    * Initialise interface
    */
   void init(const uint8_t myAddress) {

      // Enable clock to I2C interface
      *reinterpret_cast<uint32_t *>(i2cClockReg) |= i2cClockMask;

      thisPtr = this;

      // Configure I2C pins
      Sda::Pcr::setPCR(PORT_PCR_MUX(sclFn)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
      Scl::Pcr::setPCR(PORT_PCR_MUX(sdaFn)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

      if (mode&I2C_C1_IICIE_MASK) {
         NVIC_EnableIRQ(I2C0_IRQn);
      }

      // Enable I2C peripheral
      i2c->C1 = I2C_C1_IICEN_MASK|mode;

      // Default options
      i2c->C2  = I2C_C2_AD(myAddress>>8);
      i2c->A1  = myAddress&~1;
      i2c->FLT = I2C_FLT_FLT(2);
   }

   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   virtual void busHangReset() {
      Sda::setDigitalInput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      /*
       * Set SCL initially high before enabling to minimise disturbance to bus
       */
      Scl::setDigitalInput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      Scl::set();
      Scl::setDigitalOutput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      for (int i=0; i<9; i++) {
         // Set clock high (3-state)
         Scl::set();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
         // If data is high bus is OK
         if (Sda::read()) {
            break;
         }
         // Set clock low
         Scl::clear();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
      }
   }
};

#if defined(I2C0) && defined(I2C0_SCL_GPIO) && defined(I2C0_SDA_GPIO)
/**
 * @brief Convenience template class representing the I2C0 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2C *i2c = new USBDM::I2C_0();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
 *  @endcode
 */
using I2C_0 = USBDM::I2C_T<I2C0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C0_CLOCK_REG), I2C0_CLOCK_MASK, I2C0_SCL_GPIO, I2C0_SCL_FN, I2C0_SDA_GPIO, I2C0_SDA_FN>;
#endif

#if defined(I2C1) && defined(I2C1_SCL_GPIO) && defined(I2C1_SDA_GPIO)
/**
 * @brief Convenience template class representing the I2C1 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2C *i2c = new USBDM::I2C_1();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 */
using I2C_1 = USBDM::I2C_T<I2C1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C1_CLOCK_REG), I2C1_CLOCK_MASK, I2C1_SCL_GPIO, I2C1_SCL_FN, I2C1_SDA_GPIO, I2C1_SDA_FN>;
#endif

#if defined(I2C2) && defined(I2C2_SCL_GPIO) && defined(I2C2_SDA_GPIO)
/**
 * @brief Convenience template class representing the I2C2 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2C *i2c = new USBDM::I2C_2();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 */
using I2C_2 = USBDM::I2C_T<I2C2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C2_CLOCK_REG), I2C2_CLOCK_MASK, USBDM::I2C2_SCL_GPIO, I2C2_SCL_FN, USBDM::I2C2_SDA_GPIO, I2C2_SDA_FN>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* I2C_H_ */
