/****************************************************************************************************//**
 * @file     i2c.h
 *
 * @brief    Abstracion layer for I2C interface
 *
 * @version  V0.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef INCLUDE_USBDM_I2C_H_
#define INCLUDE_USBDM_I2C_H_

#include <stdint.h>
#include "derivative.h"
#include "gpio.h"

namespace USBDM {

/**
 * @addtogroup I2C_Group Inter-Integrated-Circuit I2C
 * @brief C++ Class allowing access to I2C interface
 * @{
 */

/**
 * Virtual Base class for I2C interface
 */
class I2c {

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
   I2c(I2C_Type *i2c, I2c::Mode mode) : i2c(i2c), state(i2c_idle), mode(mode), rxBytesRemaining(0), rxDataPtr(0), addressedDevice(0), errorCode(0) {
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
 * @tparam  SclPcr         Pcr used for SCL signal
 * @tparam  SclGpio        Gpio used for SCL signal
 * @tparam  SdaPcr         Pcr used for SDA signal
 * @tparam  SdaGpio        Gpio used for SDA signal
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
template<uint32_t i2cBasePtr, uint32_t i2cClockReg, uint32_t i2cClockMask, IRQn_Type irqNum, class SclPcr, class SclGpio, class SdaPcr, class SdaGpio> class I2C_T : public I2c {
public:
   static class I2c *thisPtr;

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
   I2C_T(unsigned baud=400000, I2c::Mode mode=I2c::Mode::polled, uint8_t myAddress=0) : I2c(reinterpret_cast<I2C_Type*>(i2cBasePtr), mode) {
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
      SdaPcr::setPCR();
      SclPcr::setPCR();

      if (mode&I2C_C1_IICIE_MASK) {
         NVIC_EnableIRQ(irqNum);
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
      SdaGpio::setInput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      /*
       * Set SCL initially high before enabling to minimise disturbance to bus
       */
      SclGpio::setInput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      SclGpio::set();
      SclGpio::setOutput(GPIO_PORT_FN|PORT_PCR_ODE_MASK);
      for (int i=0; i<9; i++) {
         // Set clock high (3-state)
         SclGpio::set();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
         // If data is high bus is OK
         if (SdaGpio::read()) {
            break;
         }
         // Set clock low
         SclGpio::clear();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
      }
   }
};

#if defined(I2C0) && (I2C0_SCL_PIN_SEL!=0) && (I2C0_SDA_PIN_SEL!=0)
/**
 * @brief Convenience template class representing the I2C0 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2c *i2c = new USBDM::I2c0();
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
#ifdef MCU_MKM33Z5
using I2c0 = USBDM::I2C_T<I2C0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C0_CLOCK_REG), I2C0_CLOCK_MASK, I2C0_1_IRQn, i2c0_SCLPcr, i2c0_SCLGpio, i2c0_SDAPcr, i2c0_SDAGpio>;
#else
using I2c0 = USBDM::I2C_T<I2C0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C0_CLOCK_REG), I2C0_CLOCK_MASK, I2C0_IRQn, i2c0_SCLPcr, i2c0_SCLGpio, i2c0_SDAPcr, i2c0_SDAGpio>;
#endif
#endif

#if defined(I2C1) && (I2C1_SCL_PIN_SEL!=0) && (I2C1_SDA_PIN_SEL!=0)
/**
 * @brief Convenience template class representing the I2C1 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2c *i2c = new USBDM::I2c1();
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
#ifdef MCU_MKM33Z5
using I2c1 = USBDM::I2C_T<I2C1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C1_CLOCK_REG), I2C1_CLOCK_MASK, I2C0_1_IRQn, i2c1_SCLPcr, i2c1_SCLGpio, i2c1_SDAPcr, i2c1_SDAGpio>;
#else
using I2c1 = USBDM::I2C_T<I2C1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C1_CLOCK_REG), I2C1_CLOCK_MASK, I2C1_IRQn, i2c1_SCLPcr, i2c1_SCLGpio, i2c1_SDAPcr, i2c1_SDAGpio>;
#endif
#endif

#if defined(I2C2) && (I2C2_SCL_PIN_SEL!=0) && (I2C2_SDA_PIN_SEL!=0)
/**
 * @brief Convenience template class representing the I2C2 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  USBDM::I2c *i2c = new USBDM::I2c2();
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
using I2c2 = USBDM::I2C_T<I2C2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, I2C2_CLOCK_REG), I2C2_CLOCK_MASK, I2C2_IRQn, i2c2_SCLPcr, i2c2_SCLGpio, i2c2_SDAPcr, i2c2_SDAGpio>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_I2C_H_ */
