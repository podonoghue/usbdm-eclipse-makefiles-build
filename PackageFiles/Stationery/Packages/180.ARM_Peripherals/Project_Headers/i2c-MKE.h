/**
 * @file     i2c.h (180.ARM_Peripherals/Project_Headers/i2c-MKE.h)
 * @brief    I2C interface
 */

#ifndef INCLUDE_USBDM_I2C_H_
#define INCLUDE_USBDM_I2C_H_

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "pin_mapping.h"
#include "gpio.h"

#ifdef __CMSIS_RTOS
#include "cmsis.h"
#endif

#if $(/I2C/_BasicInfoGuard) // /I2C/_BasicInfoGuard

namespace USBDM {

/**
 * @addtogroup I2C_Group I2C, Inter-Integrated-Circuit Interface
 * @brief C++ Class allowing access to I2C interface
 * @{
 */
$(/I2C/peripheral_h_definition:// $/MCM/peripheral_h_definition not found)

/**
 * Virtual Base class for I2C interface
 */
class I2c : public I2cBasicInfo {

public:

#if $(/PCR/_present:false) // /PCR/_present
   CreatePinChecker("I2C");
#endif

   /** States for the I2C state machine */
   enum I2C_State { i2c_idle, i2c_txData, i2c_rxData, i2c_rxAddress };

   I2C_State           state;               //!< State of current transaction

private:
$(/I2C/private:// /I2C/private not found)

protected:

$(/I2C/protected:// /I2C/protected not found)
   static constexpr unsigned TIMEOUT_LIMIT = 100000;

   /// Mode of operation (Interrupt/Polled)
   static constexpr I2cInterrupt i2cInterrupt = irqHandlerInstalled?I2cInterrupt_Enabled:I2cInterrupt_Disabled;

   const HardwarePtr<I2C_Type> i2c;                 //!< I2C hardware instance
   uint16_t                    rxBytesRemaining;    //!< Number of receive bytes remaining in current transaction
   uint16_t                    txBytesRemaining;    //!< Number of transmit bytes remaining in current transaction
   uint8_t                    *rxDataPtr;           //!< Pointer to receive data for current transaction
   const uint8_t              *txDataPtr;           //!< Pointer to transmit data for current transaction
   uint8_t                     addressedDevice;     //!< Address of device being communicated with
   ErrorCode                   errorCode;           //!< Error code from last transaction

   /**
    * Construct I2C interface
    *
    * @param[in]  i2c     Base address of I2C hardware
    * @param[in]  i2cInterrupt Mode of operation (I2cMode_Interrupt or I2cMode_Polled)
    */
   I2c(uint32_t i2c) :
      state(i2c_idle), i2c(i2c), rxBytesRemaining(0),
      txBytesRemaining(0), rxDataPtr(0), txDataPtr(0), addressedDevice(0),
      errorCode(E_NO_ERROR) {
   }

   /**
    * Destructor
    */
   ~I2c() {}

   /**
    * Start Rx/Tx sequence by sending address byte
    *
    * @param[in]  address - address of slave to access
    */
   void sendAddress(uint8_t address);

   /**
    * Set speed for interface in bits-per-second
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param[in]  clockFrequency Frequency of I2C input clock
    * @param[in]  speed          Interface speed in bits-per-second
    */
   void setSpeed(uint32_t clockFrequency, uint32_t speed) {
      i2c->F = calculateBPSValue(clockFrequency, speed);
   }

public:
$(/I2C/public:// /I2C/public not found)

#ifdef __CMSIS_RTOS
   /**
    * Obtain I2C MUTEX
    *
    * @param[in]  milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus startTransaction(int milliseconds=osWaitForever) = 0;

   /**
    * Release I2C MUTEX
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus endTransaction() = 0;
#else
   /**
    * Obtain I2C MUTEX - dummy
    */
   virtual ErrorCode startTransaction(int =0) {return E_NO_ERROR;};
   /**
    * Release I2C MUTEX - dummy
    */
   virtual ErrorCode endTransaction() {return E_NO_ERROR;};
#endif

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
      I2C_State lastState = state;
      unsigned timeout = TIMEOUT_LIMIT;
      while ((state != i2c_idle) && (--timeout>0)) {
         if (state != lastState) {
            // Restart timeout
            timeout = TIMEOUT_LIMIT;
            lastState = state;
         }
         if ((i2c->C1&I2C_C1_IICIE_MASK) == 0) {
            poll();
         }
         else {
            __asm__("wfi");
         }
      }
      if (state != i2c_idle) {
         errorCode = E_TIMEOUT;
         busHangReset();
      }
   }

   /**
    * I2C state-machine poll function.
    * May be called by polling loop or interrupt handler.
    */
   virtual void poll(void);

   /**
    * Transmit message
    * Note: 0th byte of Tx is often register address.
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  size     Size of transmission data
    * @param[in]  data     Data to transmit
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode transmit(uint8_t address, uint16_t size, const uint8_t data[]);

   /**
    * Transmit message.
    * Note: 0th byte of Tx is often register address.
    *
    * @tparam txSize number of bytes to transmit
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  data     Data to transmit (size of transmission is inferred from array size).
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned txSize>
   ErrorCode transmit(uint8_t address, const uint8_t (&data)[txSize]) {
      return transmit(address, txSize, data);
   }

   /**
    * Transmit message.
    * Note: 0th byte of Tx is often register address.
    *
    * @tparam N number of bytes to transmit (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  data     Data to transmit (size of transmission is inferred from array size).
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned N>
   ErrorCode transmit(uint8_t address, const std::array<uint8_t, N> &data) {
      return transmit(address, N, data.data());
   }

   /**
    * Transmit message.
    * Note: 0th byte of Tx is often register address.
    *
    * @tparam N number of bytes to transmit (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  data     Data to transmit (size of transmission is inferred from array size).
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned N>
   ErrorCode transmit(uint8_t address, const std::array<const uint8_t, N> &data) {
      return transmit(address, N, data.data());
   }

   /**
    * Receive message
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  size     Size of reception data
    * @param[out] data     Data buffer for reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode receive(uint8_t address, uint16_t size,  uint8_t data[]);

   /**
    * Receive message
    *
    * @tparam rxSize number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[out] data     Data buffer for reception (size of reception is inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned rxSize>
   ErrorCode receive(uint8_t address, uint8_t (&data)[rxSize]) {
      return receive(address, rxSize, data);
   }

   /**
    * Receive message
    *
    * @tparam rxSize number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[out] data     Data buffer for reception (size of reception is inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned rxSize>
   ErrorCode receive(uint8_t address, std::array<uint8_t, rxSize> &data) {
      return receive(address, rxSize, data.data());
   }

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txSize   Size of transmission data
    * @param[in]  txData   Data for transmission
    * @param[in]  rxSize   Size of reception data
    * @param[out] rxData   Date buffer for reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode txRx(uint8_t address, uint16_t txSize, const uint8_t txData[], uint16_t rxSize, uint8_t rxData[] );

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @tparam TxSize Number of bytes to transmit (inferred)
    * @tparam RxSize Number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txData   Data for transmission (Tx size inferred from array size)
    * @param[out] rxData   Date buffer for reception (Rx size inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned TxSize, unsigned RxSize>
   ErrorCode txRx(uint8_t address, const uint8_t (&txData)[TxSize], uint8_t (&rxData)[RxSize] ) {
      return txRx(address, TxSize, txData, RxSize, rxData);
   }

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @tparam TxSize Number of bytes to transmit (inferred)
    * @tparam RxSize Number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txData   Data for transmission (Tx size inferred from array size)
    * @param[out] rxData   Date buffer for reception (Rx size inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned TxSize, unsigned RxSize>
   ErrorCode txRx(uint8_t address, const std::array<uint8_t, TxSize> &txData, std::array<uint8_t, RxSize> &rxData) {
      return txRx(address, TxSize, txData.data(), RxSize, rxData.data());
   }

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @tparam TxSize Number of bytes to transmit (inferred)
    * @tparam RxSize Number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txData   Data for transmission (Tx size inferred from array size)
    * @param[out] rxData   Date buffer for reception (Rx size inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned TxSize, unsigned RxSize>
   ErrorCode txRx(uint8_t address, const std::array<const uint8_t, TxSize> &txData, std::array<uint8_t, RxSize> &rxData) {
      return txRx(address, TxSize, txData.data(), RxSize, rxData.data());
   }

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @tparam RxSize Number of bytes to receive (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txSize   Size of transmission data
    * @param[in]  txData   Data for transmission
    * @param[out] rxData   Date buffer for reception (Rx size inferred from array size)
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned RxSize>
   ErrorCode txRx(uint8_t address, uint16_t txSize, const uint8_t txData[], uint8_t (&rxData)[RxSize] ) {
      return txRx(address, txSize, txData, RxSize, rxData);
   }

   /**
    * Transmit message followed by receive message.
    * Note: 0th byte of Tx is often register address.
    *
    * Uses repeated-start.
    *
    * @tparam TxSize Number of bytes to transmit (inferred)
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txData   Data for transmission (Tx size inferred from array size)
    * @param[in]  rxSize   Size of reception data
    * @param[out] rxData   Date buffer for reception
    *
    * @return E_NO_ERROR on success
    */
   template<unsigned TxSize>
   ErrorCode txRx(uint8_t address, const uint8_t (&txData)[TxSize], uint16_t rxSize, uint8_t rxData[] ) {
      return txRx(address, TxSize, txData, rxSize, rxData);
   }

   /**
    * Transmit message followed by receive message.
    * Uses repeated-start.\n
    * Uses shared transmit and receive buffer
    *
    * @param[in]    address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]    txSize   Size of transmission data
    * @param[in]    rxSize   Size of reception data
    * @param[inout] data     Data for transmission and reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode txRx(uint8_t address, uint16_t txSize, uint16_t rxSize, uint8_t data[] );

};

/**
 * @brief Template class representing an I2C interface
 *
 * <b>Example</b>
 *
 * @code
 *  // Instantiate interface
 *  I2c *i2c0 = new USBDM::I2cBase_T<I2cInfo>();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1, sizeof(txDataBuffer), txDataBuffer);
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, sizeof(rxDataBuffer), rxDataBuffer);
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, sizeof(txDataBuffer), txDataBuffer, sizeof(rxDataBuffer), rxDataBuffer);
 *  }
 *  @endcode
 *
 * @tparam Info            Class describing I2C hardware
 */
template<class Info> class I2cBase_T : public I2c, public Info {

public:
   // Handle on I2C hardware
   static constexpr volatile I2C_Type *I2C = Info::i2c;

   /** Used by ISR to obtain handle of object */
   static I2cBase_T<Info> *thisPtr;

#ifdef __CMSIS_RTOS
protected:
   /**
    * Mutex to protect access\n
    * Using a static accessor function avoids issues with static object initialisation order
    *
    * @return mutex
    */
   static CMSIS::Mutex &mutex() {
      static CMSIS::Mutex mutex;
      return mutex;
   }

public:
   /**
    * Obtain I2C mutex
    *
    * @param[in]  milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus startTransaction(int milliseconds=osWaitForever) override {
      return mutex().wait(milliseconds);
   }

   /**
    * Release I2C mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus endTransaction() override {
      return mutex().release();
   }
#endif

   /**
    * Class-based interrupt handler
    * Polls device
    */
    void _irqHandler() {
      poll();
      if (state == I2C_State::i2c_idle) {
        // Execute call-back
        Info::sCallback(errorCode);
      }
   }

public:
   $(/I2C/classInfo: // No class Info found)
   /**
    * Construct I2C interface
    *
    * @param init Configuration information
    */
   I2cBase_T(const I2cBasicInfo::Init &init) : I2c(Info::baseAddress) {

#if $(/PCR/_present:false) // /PCR/_present
      // Check pin assignments
      I2c::CheckPinExistsAndIsMapped<Info::sclPinIndex>::check();
      I2c::CheckPinExistsAndIsMapped<Info::sdaPinIndex>::check();
#endif

      busHangReset();
      
      thisPtr = this;

      Info::configure(init);
   }

   /**
    * Destructor
    */
   virtual ~I2cBase_T() {}

   /**
    * IRQ handler
    */
   static void irqHandler() {
      thisPtr->_irqHandler();
   }


$(/I2C/static:// /I2C/static not found)
$(/I2C/InitMethod: // /I2C/InitMethod not found)
   /**
    * Set speed for interface in bits-per-second
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param[in]  speed Interface speed in bits-per-second
    */
   void setSpeed(uint32_t speed) {
      I2c::setSpeed(Info::getInputClockFrequency(), speed);
   }

   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high followed by I2C STOP. \n
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   virtual void busHangReset() {

      // Disable I2C to clear some status flags
      i2c->C1 = i2c->C1 & ~I2C_C1_IICEN_MASK;

      static auto delay = [] {
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
      };
#if $(/PCR/_present:false) // /PCR/_present
      // I2C SCL (clock) Pin
      using sclGpio = Gpio_T<PcrValue(0), Info::sclPinIndex, ActiveHigh>;

      // I2C SDA (data) Pin
      using sdaGpio = Gpio_T<PcrValue(0), Info::sdaPinIndex, ActiveHigh>;
#else
      // I2C SCL (clock) Pin
      using sclGpio = Gpio_T<Info::sclPinIndex, ActiveHigh>;

      // I2C SDA (data) Pin
      using sdaGpio = Gpio_T<Info::sdaPinIndex, ActiveHigh>;
#endif

      // Re-map pins to GPIOs initially 3-state
      sclGpio::setInput();
      sdaGpio::setInput();
      Info::disableClock();

      // SCL & SDA data values are low but direction is manipulated to achieve open-drain operation
      sclGpio::low();
      sdaGpio::low();

      for (int i=0; i<9; i++) {
         // Set clock 3-state
         sclGpio::setIn();    // SCL=T, SDA=?
         delay();
         bool sda = sdaGpio::isHigh();
         // Set clock low
         sclGpio::setOut();   // SCL=0, SDA=?
         delay();
         // If data is high bus is OK
         if (sda) {
            break;
         }
      }
      // Generate stop on I2C bus
      sdaGpio::setOut(); // SCL=0, SDA=0
      delay();
      sclGpio::setIn();  // SCL=T, SDA=0
      delay();
      sdaGpio::setIn();  // SCL=T, SDA=T
      delay();

      // Restore pin mapping
      Info::enableClock();

      // Enable I2C
      i2c->C1 = i2c->C1 | ~I2C_C1_IICEN_MASK;
   }
};

/** Used by ISR to obtain handle of object */
template<class Info> I2cBase_T<Info> *I2cBase_T<Info>::thisPtr = 0;

$(/I2C/declarations: // No declarations found)
/**
 * End I2C_Group
 * @}
 */

} // End namespace USBDM

#endif // /I2C/_BasicInfoGuard

#endif /* INCLUDE_USBDM_I2C_H_ */
