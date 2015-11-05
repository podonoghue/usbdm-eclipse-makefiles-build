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
 *  I2C *i2c0 = new I2C_0();
 *
 *  // Transmit message
 *  uint8_t command[] = {1,2,3,4};
 *  i2c0->transmit(deviceAddress, command, sizeof(command));
 *
 *  // Receive message
 *  uint8_t buffer[20];
 *  i2c0->receive(deviceAddress, buffer, sizeof(buffer));
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
   enum i2cState { i2c_idle, i2c_txAddr, i2c_rxAddr, i2c_rxAddr2, i2c_txRegAddr, i2c_rxRegAddr, i2c_txData, i2c_rxData };

   /**
    * Transmit message
    *
    * @param address  Address to transmit to
    * @param data     Date to transmit
    * @param size     Size of data
    *
    */
   int transmit(uint8_t address, const uint8_t data[], int size);
   /**
    * Receive message
    *
    * @param address  Address to receive from
    * @param data     Date buffer for reception
    * @param size     Size of data buffer
    *
    */
   int receive(uint8_t address,  uint8_t data[], int size);

protected:
   uint8_t             myAddress;           //!< Address of this device (operating as slave)
   Mode                mode;                //!< Operate in polled or interrupt mode
   volatile I2C_Type  *i2c;                 //!< Pointer to hardware device
   const DigitalIO    *scl;                 //!< I2C Clock port
   const DigitalIO    *sda;                 //!< I2C Data port
   i2cState            state;               //!< State of current transaction
   int                 dataBytesRemaining;  //!< Number of bytes remaining in current transaction
   uint8_t            *dataPtr;             //!< Pointer to data for current transaction
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
    * Start TxRx sequence
    *
    * Sets up data pointer and size
    * Starts transmission of the address byte
    *
    * @param address - address of slave to access
    * @param data    - data in/out buffer
    * @param size    - size of buffer to transfer
    */
   void startTxRx(uint8_t address, uint8_t data[], int size);
   /**
    * Start Tx sequence
    *
    * Sets mode = i2c_txAddr
    * Sets up data pointer and size
    * Starts transmission of the address byte
    *
    * @param address - address of slave to access
    * @param data    - data in/out buffer
    * @param size    - size of buffer to transfer
    */
   void startTransmit(uint8_t address, const uint8_t data[], int size);
    /**
     * Start Rx sequence
     *
     * Sets mode = i2c_rxAddr
     * Sets up data pointer and size
     * Starts transmission of the address byte
     *
     * @param address - address of slave to access
     * @param data    - data in/out buffer
     * @param size    - size of buffer to transfer
     */
   void startReceive(uint8_t address, uint8_t data[], int size);
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

#ifdef I2C0
#if !defined(I2C0_SCL_GPIO) || !defined(I2C0_SDA_GPIO)
#warning "Warning I2C0 disabled. Check pin mapping for I2C0_SCL & I2C0_SDA in pin_mapping.h"
#else

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
#endif // !defined(I2C0_SCL_GPIO) ||!defined(I2C0_SDA_GPIO)
#endif // I2C0

#ifdef I2C1
#if !defined(I2C1_SCL_GPIO) ||!defined(I2C1_SDA_GPIO)
#warning "Warning I2C1 disabled. Check pin mapping for I2C1_SCL & I2C1_SDA in pin_mapping.h"
#else

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
#endif // !defined(I2C1_SCL_GPIO) ||!defined(I2C1_SDA_GPIO)
#endif // I2C1

#ifdef I2C2
#if !defined(I2C2_SCL_GPIO) ||!defined(I2C2_SDA_GPIO)
#warning "Warning I2C2 disabled. Check pin mapping for I2C1_SCL & I2C1_SDA in pin_mapping.h"
#else
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
#endif // !defined(I2C2_SCL_GPIO) ||!defined(I2C2_SDA_GPIO)
#endif // I2C2

/**
 * @}
 */

#endif /* I2C_H_ */
