/****************************************************************************************************//**
 * @file     uart.h
 *
 * @brief    Abstracion layer for UART interface
 *
 * @version  V0.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef INCLUDE_USBDM_UART_H_
#define INCLUDE_USBDM_UART_H_

#include <stdint.h>
#include "derivative.h"
#include "gpio.h"
#include "clock_configure.h"

namespace USBDM {

/**
 * @addtogroup UART_Group Universal Asynchronous Receiver/Transmitter
 * @brief C++ Class allowing access to UART interface
 * @{
 */

/**
 * Virtual Base class for UART interface
 */
class Uart {

protected:
   UART_Type *uart;            //!< UART hardware instance
   uint32_t   clockFrequency;  //!< Frequency of UART clock (SystemCoreClock or SystemBusClock)

   /**
    * Construct UART interface
    *
    * @param uart             Base address of UART hardware
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    *
    */
   Uart(UART_Type *uart, uint32_t clockFrequency) : uart(uart), clockFrequency(clockFrequency) {
   }

   /**
    * Initialise interface
    */
   void init() {
      setBaudRate(DEFAULT_BAUD_RATE);
   }

   /**
    * Set baud factor value for interface
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param baudrate - Interface speed in bits-per-second
    */
   void setBaudRate(uint32_t baudrate) {

      // Disable UART before changing registers
      uart->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

      // Calculate UART clock setting (5-bit fraction at right)
      int scaledBaudValue = (2*clockFrequency)/baudrate;

#ifdef UART_C4_BRFA_MASK
      // Set Baud rate register
      uart->BDH = (uart->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
      uart->BDL = UART_BDL_SBR(scaledBaudValue>>5);
      // Fractional divider to get closer to the baud rate
      uart->C4 = (uart->C4&~UART_C4_BRFA_MASK) | UART_C4_BRFA(scaledBaudValue);
#else
      scaledBaudValue += 1<<4; // Round value
      // Set Baud rate register
      uart->BDH = (uart->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
      uart->BDL = UART_BDL_SBR(scaledBaudValue>>5);
#endif

      uart->C1 = 0;

#ifdef USE_IRQ
      // Enable UART Tx & Rx - with Rx IRQ
      uart->C2 = UART_C2_TE_MASK|UART_C2_RE_MASK|UART_C2_RIE_MASK;
#else
      // Enable UART Tx & Rx
      uart->C2 = UART_C2_TE_MASK|UART_C2_RE_MASK;
#endif
   }

public:
   /**
    * Transmit message
    *
    * @param data     Data to transmit
    * @param size     Size of transmission data
    */
   void transmit(const uint8_t data[], uint16_t size) {
      while (size-->0) {
         tx(*data++);
      }
   }

   /**
    * Receive message
    *
    * @param data     Data buffer for reception
    * @param size     Size of data to receive
    */
   void receive(uint8_t data[], uint16_t size) {
      while (size-->0) {
         *data++ = rx();
      }
   }
   /*
    * Transmits a single character over the UART (blocking)
    *
    * @param ch - character to send
    */
   void tx(int ch) {
      while ((uart->S1 & UART_S1_TDRE_MASK) == 0) {
         // Wait for Tx buffer empty
         __asm__("nop");
      }
      uart->D = ch;
   }
   /*
    * Receives a single character over the UART (blocking)
    *
    * @return - character received
    */
   int rx(void) {
      uint8_t status;
      // Wait for Rx buffer full
      do {
         status = uart->S1;
         // Clear & ignore pending errors
         if ((status & (UART_S1_FE_MASK|UART_S1_OR_MASK|UART_S1_PF_MASK|UART_S1_NF_MASK)) != 0) {
            (void)uart->D;
         }
      }  while ((status & UART_S1_RDRF_MASK) == 0);
      int ch = uart->D;
      if (ch == '\r') {
         ch = '\n';
      }
      return ch;
   }

};

/**
 * @brief Template class representing an UART interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  UART_0 *uart0 = new USBDM::UART_T<Uart1Info>(DEFAULT_BAUD_RATE, SYSTEM_UART0_CLOCK);
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
template<class info> class Uart_T : public Uart {
public:
   static class Uart *thisPtr;

private:
   using TxPcr  = PcrTable_T<info, 0>;
   using RxPcr  = PcrTable_T<info, 1>;

public:
   /**
    * Construct UART interface
    *
    * @param baudrate         Interface speed in bits-per-second
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    */
   Uart_T(unsigned baudrate, unsigned clockFrequency) : Uart(reinterpret_cast<UART_Type*>(info::basePtr), clockFrequency) {
      // Enable clock to UART interface
      *reinterpret_cast<uint32_t *>(info::clockReg) |= info::clockMask;

      // Configure pins
      TxPcr::setPCR();
      RxPcr::setPCR();

      init();
      setBaudRate(baudrate);
   }
};

#ifdef UART0_CLOCK_MASK
/**
 * @brief Class representing UART0 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  Uart *uart = new USBDM::Uart1();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
class Uart0 : public Uart_T<Uart0Info> {
public:
   Uart0(unsigned baud=DEFAULT_BAUD_RATE, unsigned clockFrequency=SYSTEM_UART0_CLOCK) : Uart_T(baud, clockFrequency) {
   }
};
#endif

#ifdef UART1_CLOCK_MASK
/**
 * @brief Class representing UART1 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  Uart *uart = new USBDM::Uart1();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
class Uart1 : public Uart_T<Uart1Info> {
public:
   /**
    * Construct UART interface
    *
    * @param baudrate         Interface speed in bits-per-second
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    */
   Uart1(unsigned baudrate=DEFAULT_BAUD_RATE, unsigned clockFrequency=SYSTEM_UART1_CLOCK) : Uart_T(baudrate, clockFrequency) {
   }
};
#endif

#ifdef UART2_CLOCK_MASK
/**
 * @brief Class representing UART2 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  Uart *uart = new USBDM::Uart2();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
class Uart2 : public Uart_T<Uart2Info> {
public:
   /**
    * Construct UART interface
    *
    * @param baudrate         Interface speed in bits-per-second
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    */
   Uart2(unsigned baudrate=DEFAULT_BAUD_RATE, unsigned clockFrequency=SYSTEM_UART2_CLOCK) : Uart_T(baudrate, clockFrequency) {
   }
};
#endif

#ifdef UART3_CLOCK_MASK
/**
 * @brief Class representing UART3 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  Uart *uart = new USBDM::Uart3();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
class Uart3 : public Uart_T<Uart3Info> {
public:
   /**
    * Construct UART interface
    *
    * @param baudrate         Interface speed in bits-per-second
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    */
   Uart3(unsigned baudrate=DEFAULT_BAUD_RATE, unsigned clockFrequency=SYSTEM_UART3_CLOCK) : Uart_T(baudrate, clockFrequency) {
   }
};
#endif

#ifdef UART4_CLOCK_MASK
/**
 * @brief Class representing UART4 interface
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  Uart *uart = new USBDM::Uart4();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     uart->transmit(txDataBuffer, sizeof(txDataBuffer));
 *
 *     // Receive block
 *     uart->receive((rxDataBuffer, sizeof(rxDataBuffer));
 *  }
 *  @endcode
 *
 * @tparam info   Class describing UART hardware
 */
class Uart4 : public Uart_T<Uart4Info> {
public:
   /**
    * Construct UART interface
    *
    * @param baudrate         Interface speed in bits-per-second
    * @param clockFrequency   Frequency of UART clock (SystemCoreClock or SystemBusClock)
    */
   Uart4(unsigned baudrate=DEFAULT_BAUD_RATE, unsigned clockFrequency=SYSTEM_UART4_CLOCK) : Uart_T(baudrate, clockFrequency) {
   }
};
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_UART_H_ */
