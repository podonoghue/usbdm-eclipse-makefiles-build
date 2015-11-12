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

/**
 * @addtogroup I2C_Group Inter IC
 * @brief C++ Class allowing access to I2C interface
 * @{
 */

/**
 * @brief Class representing an I2C interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  I2C *i2c = new I2C_1();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *  // Reception buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
 *     waitUS(40);
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
 *     waitUS(40);
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
 *     waitMS(5);
 *  }
 *
 *  @endcode
 */
class I2C {

public:
   /**
    * Operating mode
    */
   enum Mode {
      polled    = 0,                   //!< Operate in polled mode
      interrupt = I2C_C1_IICIE_MASK,   //!< Operate in interrupt mode
   };

   /**
    * States for the I2C state machine
    */
   enum i2cState { i2c_idle, i2c_txData, i2c_rxData, i2c_rxAddress };

   /**
    * Transmit message
    *
    * @param address  Address of slave to communicate with
    * @param data     Data to transmit, 0th byte is often register address
    * @param size     Size of transmission data
    */
   int transmit(uint8_t address, const uint8_t data[], int size);

   /**
    * Receive message
    *
    * @param address  Address of slave to communicate with
    * @param data     Data buffer for reception
    * @param size     Size of reception data
    */
   int receive(uint8_t address,  uint8_t data[], int size);

   /**
    * Transmit message followed by receive message.
    * Uses repeated-start.
    *
    * @param address  Address of slave to communicate with
    * @param txData   Data for transmission
    * @param txSize   Size of transmission data
    * @param rxData   Date buffer for reception
    * @param txSize   Size of reception data
    */
   int txRx(uint8_t address, const uint8_t txData[], int txSize, uint8_t rxData[], int rxSize );

   /**
    * Transmit message followed by receive message.
    * Uses repeated-start.
    * Uses shared transmit and receive buffer
    *
    * @param address  Address of slave to communicate with
    * @param data     Data for transmission and reception
    * @param txSize   Size of transmission data
    * @param txSize   Size of reception data
    */
   int txRx(uint8_t address, uint8_t data[], int txSize, int rxSize ) {
      return txRx(address, data, txSize, data, rxSize);
   }

protected:
   uint8_t             myAddress;           //!< Address of this device (operating as slave)
   Mode                mode;                //!< Operate in polled or interrupt mode
   volatile I2C_Type  *i2c;                 //!< Pointer to hardware device
   const DigitalIO    *scl;                 //!< I2C Clock port
   const DigitalIO    *sda;                 //!< I2C Data port
   i2cState            state;               //!< State of current transaction
   int                 rxBytesRemaining;    //!< Number of receive bytes remaining in current transaction
   int                 txBytesRemaining;    //!< Number of transmit bytes remaining in current transaction
   uint8_t            *rxDataPtr;           //!< Pointer to receive data for current transaction
   const uint8_t      *txDataPtr;           //!< Pointer to transmit data for current transaction
   uint8_t             addressedDevice;     //!< Address of device being communicated with
   int                 errorCode;           //!< Error code from last transaction

   /**
    * Construct I2C interface
    *
    * @param myAddress  Address of this device on bus (not currently used)
    * @param mode       Mode of operation
    * @param i2c        Hardware pointer
    * @param scl        I2C Clock port
    * @param sda        I2C Data port
    */
   I2C(uint8_t myAddress, Mode mode, volatile I2C_Type *i2c, const DigitalIO *sda, const DigitalIO *scl);

   /**
    * Initialise interface
    */
   void init(void);
   /**
    * Wait for current sequence to complete
    */
   void waitWhileBusy(void);

   /**
    * Start Rx/Tx sequence by sending address byte
    *
    * @param address - address of slave to access
    */
   void sendAddress(uint8_t address);

   /**
    * Set baud factor value for interface
    * This is calculated from processor bus frequency and given bps
    *
    * @param bps - Interface speed in bits-per-second
   */
   void setbps(uint32_t bps);
   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   void busHangReset();
   /**
    * I2C state-machine based interrupt handler
    */
   void poll(void);
   /**
    * I2C state-machine based interrupt handler
    */
   friend void I2C0_IRQHandler(void);
   /**
    * I2C state-machine based interrupt handler
    */
   friend void I2C1_IRQHandler(void);
   /**
    * I2C state-machine based interrupt handler
    */
   friend void I2C2_IRQHandler(void);
   /**
    * I2C state-machine based interrupt handler
    */
   friend void I2C3_IRQHandler(void);
};

#if defined(I2C0) && defined(I2C0_SCL_GPIO) && defined(I2C0_SDA_GPIO)
/**
 * I2C0 interface
 */
class I2C_0 : public I2C {

public:
   /**
    * Constructor for I2C #0 interface
    *
    * @param myAddress - not used as slave interface is not handled.
    * @param mode      - i2c_polled or i2c_interrupt
    * @param baud      - baud rate
    *
    */
   I2C_0(uint8_t myAddress = 0x00, Mode mode = polled, unsigned baud=400000)
       : I2C(myAddress, mode, I2C0, &I2C0_SCL_GPIO, &I2C0_SDA_GPIO) {
      busHangReset();
      init();
      // Set baud rate
      setbps(baud);
   }

private:
   void init(void);
   friend void I2C0_IRQHandler(void);
   static I2C* thisPtr;      // This pointer for class instance associated with I2C0
};
#endif // defined(I2C0) && defined(I2C0_SCL_GPIO) && defined(I2C0_SDA_GPIO)

#if defined(I2C1) && defined(I2C1_SCL_GPIO) && defined(I2C1_SDA_GPIO)
/**
 * I2C1 interface
 */
class I2C_1 : public I2C {


public:
   /**
    * Constructor for I2C #1 interface
    *
    * @param myAddress - not used as slave interface is not handled.
    * @param mode      - i2c_polled or i2c_interrupt
    * @param baud      - baud rate
    *
    */
   I2C_1(uint8_t myAddress = 0x00, Mode mode = polled, unsigned baud=400000)
      : I2C(myAddress, mode, I2C1, &I2C1_SCL_GPIO, &I2C1_SDA_GPIO) {
      busHangReset();
      init();
      setbps(baud);
   }

private:
   void init(void);
   static I2C* thisPtr;      // This pointer for class instance associated with I2S1
   friend void I2C1_IRQHandler(void);
};
#endif // defined(I2C1) && defined(I2C1_SCL_GPIO) && defined(I2C1_SDA_GPIO)

#if defined(I2C2) && defined(I2C2_SCL_GPIO) && defined(I2C2_SDA_GPIO)
/**
 * I2C2 interface
 */
class I2C_2 : public I2C {

public:
   /**
    * Initialise the I2C interface
    *
    * @param myAddress - not used as slave interface is not handled.
    * @param mode      - i2c_polled or i2c_interrupt
    * @param baud      - baud rate
    */
   I2C_2(uint8_t myAddress = 0x00, Mode mode = polled, unsigned baud=400000)
      : I2C(myAddress, mode, I2C2, &I2C2_SCL_GPIO, &I2C2_SDA_GPIO) {
      busHangReset();
      init();
      setbps(baud);
   }

private:
   void init(void);
   static I2C* thisPtr;      // This pointer for class instance associated with I2S2
   friend void I2C2_IRQHandler(void);
};
#endif // defined(I2C2) && defined(I2C2_SCL_GPIO) || defined(I2C2_SDA_GPIO)

/**
 * @}
 */

#endif /* I2C_H_ */
