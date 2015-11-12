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

#if defined(MCU_MKL27Z4) || defined(MCU_MKL27Z644)
#define I2C_CLOCK_FREQ SystemCoreClock
#else
#define I2C_CLOCK_FREQ SystemBusClock
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
   state(i2c_idle), rxBytesRemaining(0), rxDataPtr(0), addressedDevice(0), errorCode(0)
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
      uint32_t divisor = (I2C_CLOCK_FREQ>>mul)/bps;
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
 * Start Rx/Tx sequence by sending address byte
 *
 * @param address - address of slave to access.  Should include R/W bit
 */
void I2C::sendAddress(uint8_t address) {

   // Wait for bus idle
   while ((i2c->S & I2C_S_BUSY_MASK) != 0) {
      __asm("nop");
   }

   addressedDevice = address;

   // Configure for Tx of address
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK;

   // Generate START
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK|I2C_C1_MST_MASK;

   // Tx address (starts interrupt process)
   i2c->D  = I2C_D_DATA(address);
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
 * Transmit message
 *
 * @param address  Address of slave to communicate with
 * @param data     Data to transmit, 0th byte is often register address
 * @param size     Size of transmission data
 */
int I2C::transmit(uint8_t address, const uint8_t data[], int size) {
   errorCode = 0;

   rxBytesRemaining = 0;

   // Send address byte at start and move to data transmission
   state = i2c_txData;

   // Set up transmit data
   txDataPtr        = data;
   txBytesRemaining = size;

   sendAddress(address);
   waitWhileBusy();

   return errorCode;
}

/**
 * Receive message
 *
 * @param address  Address of slave to communicate with
 * @param data     Data buffer for reception
 * @param size     Size of reception data
 */
int I2C::receive(uint8_t address, uint8_t data[], int size) {
   errorCode = 0;

   txBytesRemaining = 0;

   // Send address byte at start and move to data reception
   state = i2c_rxAddress;

   // Set up receive data
   rxDataPtr        = data;
   rxBytesRemaining = size;

   sendAddress(address|1);
   waitWhileBusy();

   return errorCode;
}

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
int I2C::txRx(uint8_t address, const uint8_t txData[], int txSize, uint8_t rxData[], int rxSize ) {
   errorCode = 0;

   // Send address byte at start and move to data transmission
   state = i2c_txData;

   // Set up transmit and receive data
   rxDataPtr        = rxData;
   rxBytesRemaining = rxSize;
   txDataPtr        = txData;
   txBytesRemaining = txSize;

   sendAddress(address);

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

   // i2c_txData* +-> i2c_idle
   //             +-> i2c_rxAddress -> i2c_rxData* +-> i2c_idle
   //                                              *-> i2c_txData

   switch (state) {
      case i2c_idle:
      default:
         state = i2c_idle;
         break;

      case i2c_txData:
         // Just send data bytes until none left
         if (txBytesRemaining-- == 0) {
            if (rxBytesRemaining > 0) {
               // Reception after transmission
               state = i2c_rxAddress;

#if defined(MCU_MKL25Z4)
               {
                  // Temporarily clear MULT - see KL25 errata e6070
                  uint8_t temp = i2c->F;
                  i2c->F&=~I2C_F_MULT(3);
#endif
                  // Generate REPEATED-START
                  i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TX_MASK|I2C_C1_RSTA_MASK;
#if defined(MCU_MKL25Z4)
                  // Restore MULT
                  i2c->F = temp;
               }
#endif
#if defined(MCU_MKL27Z4) || defined(MCU_MKL27Z644) || defined(MCU_MKL43Z4)
               // This is a nasty hack
               // It seems these chips need a delay after asserting repeated start
               for (int i=0; i<20; i++) {
                  __asm__ volatile("nop");
               }
#endif
               // Send device address again with READ bit set
               i2c->D = addressedDevice|1;
            }
            else {
               // Complete
               state = i2c_idle;

               // Generate stop signal
               i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TXAK_MASK;
               return;
            }
         }
         else {
            // Transmit next byte
            i2c->D = *txDataPtr++;
         }
         break;

      case i2c_rxAddress:
         // Just sent address for reception phase
         // Switch to data reception & trigger reception
         state = i2c_rxData;
         // Change to reception
         if (rxBytesRemaining == 1) {
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
         // Just receive data bytes until complete
         if (--rxBytesRemaining == 0) {
            if (txBytesRemaining > 0) {
               // Transmission after reception
               state = i2c_txData;

               // Generate REPEATED-START
               i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TX_MASK|I2C_C1_RSTA_MASK;

               // Tx address (starts interrupt process)
               i2c->D  = I2C_D_DATA(addressedDevice);
            }
            else {
               // Received last byte - complete
               state = i2c_idle;
               // Generate STOP
               i2c->C1 = mode|I2C_C1_IICEN_MASK;
            }
         }
         else if (rxBytesRemaining == 1) {
            // Received 2nd last byte (don't acknowledge the last byte to follow)
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TXAK_MASK;
         }
         else {
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK;
         }
         // Save receive data
         *rxDataPtr++ = i2c->D;
         break;
   }
}

/*
 * Generates I2C_SCL clock until I2C_SDA goes high
 *
 * This is useful if a slave is part-way through a transaction when the master goes away!
 */
void I2C::busHangReset() {

   sda->setDigitalInput(DigitalIO::GPIO_PORT_FN|PORT_PCR_ODE_MASK);
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
      if (sda->read()) {
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

#if defined(DEBUG_BUILD) && (DEBUG_I2C)
// Test code
int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new I2C_1();

   // Transmit data
   const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
   // Reception buffer
   uint8_t rxDataBuffer[5];

   for(;;) {
      waitUS(40);
      i2c->transmit(0x1D<<1,    txDataBuffer, sizeof(txDataBuffer));
      waitUS(40);
      i2c->receive((0x1D<<1)|1, rxDataBuffer, sizeof(rxDataBuffer));
      waitUS(40);
      i2c->txRx(0x1D<<1, txDataBuffer, sizeof(txDataBuffer), rxDataBuffer, sizeof(rxDataBuffer));
      waitMS(5);
   }
#endif
