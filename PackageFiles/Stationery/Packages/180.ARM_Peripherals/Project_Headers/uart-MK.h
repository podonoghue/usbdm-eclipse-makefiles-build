/**
 * @file     uart.h (180.ARM_Peripherals/Project_Headers/uart-MK.h)
 * @brief    Universal Asynchronous Receiver/Transmitter interface
 */

#ifndef HEADER_UART_H_
#define HEADER_UART_H_

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "pin_mapping.h"
#include "formatted_io.h"
#include "uart_queue.h"

$(/UART/prototypes:// $/UART/prototypes not found)

namespace USBDM {

/**
 * @addtogroup UART_Group UART, Analogue Comparator
 * @brief Pins used for Analogue Comparator
 * @{
 */
$(/UART/peripheral_h_definition:// $/UART/peripheral_h_definition not found)
/**
 * @brief Template class representing an UART interface with buffered reception
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  UartBuffered_T<100, 100> bufferedUart{console};
 *
 *  for(int i=0; i++;) {
 *     bufferedUart.writeln("Tick... ", i);
 *  }
 *  @endcode
 *
 * @tparam Info   Class describing UART hardware
 */
template<typename T, int rxSize=100, int txSize=100>
class UartBuffered_T : public T {

private:
   UartBuffered_T(const UartBuffered_T&) = delete;
   UartBuffered_T(UartBuffered_T&&) = delete;

   static constexpr typename T::Init initValue = {
         UartBaudRate_115200,
         UartTxEmptyAction_Interrupt ,    // (uart_txempty_action)      Transmit empty DMA/Interrupt action - Interrupt
         UartRxFullAction_Interrupt ,     // (uart_rxfull_action)       Receive full DMA/interrupt action - Interrupt
#if $(/UART/uart_pfifo_txfe_present:false) // /UART/uart_pfifo_txfe_present
         UartTransmitFifoEnable_Enabled ,  // (uart_pfifo_txfe)          Transmit FIFO Enable - Enabled
         UartReceiveFifoEnable_Enabled ,   // (uart_pfifo_rxfe)          Receive FIFO Enable - Enabled
#endif
   };

public:

   UartBuffered_T(const T &uart) : T(uart) {
      T::setCallback(T::IrqNum_RxTx,  T::wrapCallback(this, &USBDM::UartBuffered_T<T, rxSize, txSize>::callback));
      T::configure(initValue);
   }

   UartBuffered_T(const T &uart, typename T::Init init) : UartBasicInfo(uart) {
      T::setCallback(T::IrqNum_RxTx,  T::wrapCallback(this, &USBDM::UartBuffered_T<T, rxSize, txSize>::callback));
      T::configure(init);
   }

   virtual ~UartBuffered_T() {
      T::setTransmitCompleteAction(UartTxCompleteAction_None);
      T::setReceiveFullAction(UartRxFullAction_None);
   }

protected:
   /**
    * Queue for Buffered reception (if used)
    */
   static inline UartQueue<char, rxSize> rxQueue;
   /**
    * Queue for Buffered transmission (if used)
    */
   static inline UartQueue<char, txSize> txQueue;

   /**
    * Writes a character (blocking on transmit queue full)
    *
    * @param[in]  ch - character to send
    */
   virtual void _writeChar(char ch) override {
      T::lock();
      // Add character to buffer
      while (!txQueue.enQueueDiscardOnFull(ch)) {
         __asm__("nop");
      }
      T::setTransmitCompleteAction(UartTxCompleteAction_Interrupt);
      T::unlock();
      if (ch=='\n') {
        _writeChar('\r');
      }
   }

   /**
    * Receives a single character (blocking on receive queue empty)
    *
    * @return Character received
    */
   virtual int _readChar() override {
      T::lock();
      while (rxQueue.isEmpty()) {
         __asm__("nop");
      }
      char t = rxQueue.deQueue();
      T::unlock();
      return t;
   }

   /**
    * Check if character is available
    *
    * @return true  Character available i.e. _readChar() will not block
    * @return false No character available
    */
   virtual bool _isCharAvailable() override {
      return (!rxQueue.isEmpty());
   }

public:
   /**
    * Receive/Transmit/Error IRQ handler call-back
    */
   void callback()  {
      UartStatusFlag status = T::getStatusFlags();

      // Empty UART Rx FIFO
      while(status&UartStatusFlag::ReceiveDataRegisterFullFlag) {
         // Receive data register full - save data
         rxQueue.enQueueDiscardOnFull(T::getReceiveData());
         status = T::getStatusFlags();
      }
      // Fill UART Tx FIFO
      while(status&UartStatusFlag::TransmitDataRegisterEmptyFlag) {
         // Transmitter ready
         if (txQueue.isEmpty()) {
            // No data available - disable further transmit interrupts
            T::setTransmitCompleteAction(UartTxCompleteAction_None);
            break;
         }
         else {
            // Transmit next byte
            T::setTransmitData(txQueue.deQueue());
         }
         status = T::getStatusFlags();
      }
   }

   /**
    *  Flush output data.
    *  This blocks until all pending data has been sent
    */
   virtual UartBuffered_T &flushOutput() override {
      while (!txQueue.isEmpty()) {
         // Wait until queue empty
      }
      while ((T::uart->S1 & UART_S1_TC_MASK) == 0) {
         // Wait until transmission of last character is complete
      }
      return *this;
   }

   /**
    *  Flush input data
    */
   virtual UartBuffered_T &flushInput() override {
      rxQueue.clear();
      UartBasicInfo::flushInput();
      return *this;
   }

};
$(/UART/declarations: // No declarations found)
/**
 * End UART_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_UART_H_ */
