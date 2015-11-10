/*
 * I2C.c
 *
 *  Created on: 22/11/2013
 *      Author: podonoghue
 */
#include <stdbool.h>
#include <stdio.h>
#include "derivative.h"
#include "utilities.h"
#include "system.h"
#include "I2C.h"

#ifndef PORT_PCR_ODE_MASK
// Some devices don't have ODE function on pin
// The open-drain mode is automatically selected when I2C function is selected for the pin
#define PORT_PCR_ODE_MASK 0
#endif

/*
 * Constructor for generic I2C interface
 *
 * @param myAddress - not used as slave interface is not handled.
 * @param mode      - i2c_polled or i2c_interrupt
 * @param i2c       - base address of peripheral
 */
I2C::I2C(uint8_t myAddress, Mode mode, volatile I2C_Type *i2c, const DigitalIO *scl, const DigitalIO *sda) :
   myAddress(myAddress), mode(mode), i2c(i2c), scl(scl), sda(sda),
   state(i2c_idle), dataBytesRemaining(0), dataPtr(0), addressedDevice(0), errorCode(0)
{
}

// I2C baud rate divisor table
static const uint16_t i2cDivisors[] = {
// Divider assuming MULT == 0
   20,   22,  24,   26,   28,   30,   34,   40,   28,   32,   36,   40,   44,   48,   56,   68,
   48,   56,  64,   72,   80,   88,  104,  128,   80,   96,  112,  128,  144,  160,  192,  240,
   160, 192, 224,  256,  288,  320,  384,  480,  320,  384,  448,  512,  576,  640,  768,  960,
   640, 768, 896, 1024, 1152, 1280, 1536, 1920, 1280, 1536, 1792, 2048, 2304, 2560, 3072, 3840,
};

/**
 * Set baud factor value for interface
 * This is calculated from processor bus frequency and given bps
 *
 * @param bps - Interface speed in bits-per-second
*/
void I2C::setbps(uint32_t bps) {
   uint8_t  best_mul   = 0;
   uint8_t  best_icr   = (uint8_t)-1u;
   uint16_t best_error = (uint16_t)-1u;

   for (uint8_t mul=0; mul<=2; mul++) {
      uint32_t divisor = (SystemBusClock>>mul)/bps;
      for(uint8_t icr=0; icr<(sizeof(i2cDivisors)/sizeof(i2cDivisors[0])); icr++) {
         if (divisor>i2cDivisors[icr]) {
            // Not suitable - try next
            continue;
         }
         uint16_t error=(uint16_t)(i2cDivisors[icr]-divisor);
         if ((error<best_error) || (error==0)) {
            best_error=error;
            best_icr=icr;
            best_mul=mul;
         }
      }
   }
   if (best_icr == (uint8_t)-1u) {
      i2c->F = I2C_F_MULT(1)|I2C_F_ICR(5);
   }
   else {
      i2c->F = I2C_F_MULT(best_mul)|I2C_F_ICR(best_icr);
   }
}

/**
 * Initialise I2C interface
 */
void I2C::init() {
   // Enable I2C peripheral
   i2c->C1 = I2C_C1_IICEN_MASK|mode;

   // Default options
   i2c->C2  = I2C_C2_AD(myAddress>>8);
   i2c->A1  = myAddress&~1;
   i2c->FLT = I2C_FLT_FLT(2);
}

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
void I2C::startTxRx(uint8_t address, uint8_t data[], int size) {

   // Set up transmit or receive data
   dataPtr            = data;
   dataBytesRemaining = size;

   // Configure for Tx of address
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK;
   // Generate START
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK|I2C_C1_MST_MASK;

   addressedDevice = address;

   // Tx address (starts interrupt process)
   i2c->D  = I2C_D_DATA(address);
}

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
void I2C::startTransmit(uint8_t address, const uint8_t data[], int size) {
   // Sending address byte of data transmission
   state = i2c_txAddr;
   startTxRx(address, (uint8_t *)data, size);
}

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
void I2C::startReceive(uint8_t address, uint8_t data[], int size) {
   // Sending address byte of data reception
   state = i2c_rxAddr;
   startTxRx(address, data, size);
}

/**
 * Wait for current sequence to complete
 */
void I2C::waitWhileBusy() {
   while (state != i2c_idle) {
      if ((i2c->C1&I2C_C1_IICIE_MASK) == 0) {
         poll();
      }
   }
}

/**
 * Transmit data to slave and wait for completion
 *
 * @param address - address of slave to access
 * @param data    - data out buffer, 0th byte is (usually) register address
 *                  0..size-1: data to transmit
 * @param size    - size of buffer to transfer
 */
int I2C::transmit(uint8_t address, const uint8_t data[], int size) {
   errorCode = 0;

   // Wait for bus idle
   while ((i2c->S & I2C_S_BUSY_MASK) != 0) {
      __asm("nop");
   }
   startTransmit(address, data, size);
   waitWhileBusy();
   return errorCode;
}

/**
 * Receive data from slave and wait for completion
 *
 * @param address - address of slave to access
 * @param data    - data in/out buffer, 0th byte is register address
 *                  Tx - 0th byte is register address
 *                  Rx - 0..size-1: data received (NOTE: overwrites address byte)
 * @param size    - size of buffer to transfer
 */
int I2C::receive(uint8_t address, uint8_t data[], int size) {
   errorCode = 0;
   // Wait for bus idle
   while ((i2c->S & I2C_S_BUSY_MASK) != 0) {
      __asm("nop");
   }
   startReceive(address, data, size);
   waitWhileBusy();
   return errorCode;
}

/*
 * I2C state-machine based interrupt handler
 */
void I2C::poll() {
   if ((i2c->S & I2C_S_ARBL_MASK) != 0) {
      i2c->S = I2C_S_ARBL_MASK|I2C_S_IICIF_MASK;
      errorCode = 1;
      state = i2c_idle;
      return;
   }
   if ((i2c->S & I2C_S_IICIF_MASK) == 0) {
      return;
   }
   // Clear interrupt flag
   i2c->S = I2C_S_IICIF_MASK;

   switch (state) {
      case i2c_idle:
      default:
         state = i2c_idle;
         break;

      case i2c_txAddr:
         // Just sent address byte at start of Tx transaction
         // Transmit register address byte
         state = i2c_txRegAddr;
         i2c->D = *dataPtr++;
         break;

      case i2c_txRegAddr:
         // Just sent register address byte at start of Tx data
      case i2c_txData:
         // Just sent data byte
         if (--dataBytesRemaining == 0) {
            // Complete
            state = i2c_idle;
            // Generate stop signal
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TXAK_MASK;
            return;
         }
         else {
            // Transmit next byte
            state = i2c_txData;
            i2c->D = *dataPtr++;
         }
         break;

      case i2c_rxAddr:
         // Just sent device address byte at start of Rx transaction
         // Transmit register address byte
         state = i2c_rxRegAddr;
         i2c->D = *dataPtr;
         break;

      case i2c_rxRegAddr:
         // Just sent register address byte at start of Rx transaction
         state = i2c_rxAddr2;
         // Send repeated start
#if defined(MCU_MKL25Z4)
         {
         // Temporarily clear MULT - see KL25 errata e6070
         uint8_t temp = i2c->F;
         i2c->F&=~I2C_F_MULT(3);
#endif
         i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TX_MASK|I2C_C1_RSTA_MASK;
#if defined(MCU_MKL25Z4)
         i2c->F = temp;
         }
#endif
         // Send device address again with READ bit set
#if defined(MCU_MKL27Z4) || defined(MCU_MKL27Z644) || defined(MCU_MKL43Z4)
         // This is a nasty hack
         // It seems these chips need a delay after asserting repeated start
         for (int i=0; i<20; i++) {
            __asm__ volatile("nop");
         }
#endif
         i2c->D = addressedDevice|1;
         break;

      case i2c_rxAddr2:
         // Just sent device address byte at start of Rx data phase
         state = i2c_rxData;
         // Change to reception
         if (dataBytesRemaining == 1) {
            // Receiving only single byte (don't acknowledge the byte)
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TXAK_MASK;
         }
         else {
            // Switch to Rx mode
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK;
         }
         // Dummy read of data to start Rx of 1st data byte
         (void)i2c->D;
         break;

      case i2c_rxData:
         // Just received a data byte
         if (--dataBytesRemaining == 0) {
            // Received last byte - complete
            state = i2c_idle;
            // Generate STOP
            i2c->C1 = mode|I2C_C1_IICEN_MASK;
         }
         else if (dataBytesRemaining == 1) {
            // Received 2nd last byte (don't acknowledge the last byte to follow)
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TXAK_MASK;
         }
         // Save receive data
         *dataPtr++ = i2c->D;
         break;
   }
}

/*
 * Generates I2C_SCL clock until I2C_SDA goes high
 *
 * This is useful if a slave is part-way through a transaction when the master goes away!
 */
void I2C::busHangReset() {

   sda->setDigitalOutput(DigitalIO::GPIO_PORT_FN|PORT_PCR_ODE_MASK);
   /*
    * Set SCL initially high before enabling to minimise disturbance to bus
    */
   scl->setDigitalInput(DigitalIO::GPIO_PORT_FN|PORT_PCR_ODE_MASK);
   scl->set();
   scl->setDigitalOutput(DigitalIO::GPIO_PORT_FN|PORT_PCR_ODE_MASK);
   for (int i=0; i<9; i++) {
      // Set clock high (3-state)
      scl->set();
      for(int j=0; j<20; j++) {
         __asm__("nop");
      }
      // If data is high bus is OK
      if (scl->read()) {
         break;
      }
      // Set clock low
      scl->clear();
      for(int j=0; j<20; j++) {
         __asm__("nop");
      }
   }
}

#ifdef I2C0
#if !defined(I2C0_SCL_GPIO) || !defined(I2C0_SDA_GPIO)
#warning "Warning I2C0 present but disabled. Check pin mapping for I2C0_SCL & I2C0_SDA in pin_mapping.h"
#else
/*
 * =========================================================================================
 * I2C_0
 * =========================================================================================
 */
I2C* I2C_0::thisPtr = NULL; // This pointer for class instance associated with I2S0

/*
 * I2C state-machine based interrupt handler
 */
extern "C"
void I2C0_IRQHandler() {
   I2C_0::thisPtr->poll();
}

/**
 * Initialise interface
 */
void I2C_0::init() {

   // Enable clock to I2C interface
   I2C0_CLOCK_REG |= I2C0_CLOCK_MASK;

   I2C::init();

   thisPtr = this;

   // Configure I2C pins
   sda->pcr.setPCR(PORT_PCR_MUX(I2C0_SDA_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   scl->pcr.setPCR(PORT_PCR_MUX(I2C0_SCL_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

   if (mode&I2C_C1_IICIE_MASK) {
      NVIC_EnableIRQ(I2C0_IRQn);
   }
}
#endif // !defined(I2C0_SCL_GPIO) || !defined(I2C0_SDA_GPIO)
#endif // I2C0

#ifdef I2C1
#if !defined(I2C1_SCL_GPIO) || !defined(I2C1_SDA_GPIO)
#warning "Warning I2C1 present but disabled. Check pin mapping for I2C1_SCL & I2C1_SDA in pin_mapping.h"
#else
/*
 * =========================================================================================
 * I2C_1
 * =========================================================================================
 */
I2C* I2C_1::thisPtr = NULL; // This pointer for class instance associated with I2S1

/*
 * I2C state-machine based interrupt handler
 */
extern "C"
void I2C1_IRQHandler() {
   I2C_1::thisPtr->poll();
}

/**
 * Initialise interface
 */
void I2C_1::init() {

   // Enable clock to I2C interface
   I2C1_CLOCK_REG |= I2C1_CLOCK_MASK;

   I2C::init();

   thisPtr = this;

   // Configure I2C pins
   sda->pcr.setPCR(PORT_PCR_MUX(I2C1_SDA_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   scl->pcr.setPCR(PORT_PCR_MUX(I2C1_SCL_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

   if (mode&I2C_C1_IICIE_MASK) {
      NVIC_EnableIRQ(I2C1_IRQn);
   }
}
#endif // !defined(I2C1_SCL_GPIO) || !defined(I2C1_SDA_GPIO)
#endif // I2C1

#ifdef I2C2
#if !defined(I2C2_SCL_GPIO) || !defined(I2C2_SDA_GPIO)
#warning "Warning I2C2 present but disabled. Check pin mapping for I2C2_SCL & I2C2_SDA in pin_mapping.h"
#else
/*
 * =========================================================================================
 * I2C_2
 * =========================================================================================
 */
I2C* I2C_2::thisPtr = NULL; // This pointer for class instance associated with I2S1
/**
 * Initialise interface
 */
void I2C_2::init() {

   // Enable clock to I2C interface
   I2C2_CLOCK_REG |= I2C2_CLOCK_MASK;

   I2C::init();

   thisPtr = this;

   // Configure I2C pins
   sda->pcr.setPCR(PORT_PCR_MUX(I2C2_SDA_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   scl->pcr.setPCR(PORT_PCR_MUX(I2C2_SCL_FN)|PORT_PCR_ODE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);

   if (mode&I2C_C1_IICIE_MASK) {
      NVIC_EnableIRQ(I2C2_IRQn);
   }
}
#endif // !defined(I2C2_SCL_GPIO) || !defined(I2C2_SDA_GPIO)
#endif // I2C2
