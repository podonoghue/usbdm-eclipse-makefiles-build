/*
 * uart.h
 *
 *  Created on: 6Nov.,2016
 *      Author: podonoghue
 */

#ifndef PROJECT_HEADERS_CDC_UART_H_
#define PROJECT_HEADERS_CDC_UART_H_

#include "usb_defs.h"

namespace USBDM {

class CdcUart {
private:
   static uint8_t             cdcStatus;
   static LineCodingStructure lineCoding;
   static uint8_t             breakCount;

   static void uartCallback(uint8_t status);

public:
   static constexpr uint8_t CDC_STATE_DCD_MASK        = 1<<0;
   static constexpr uint8_t CDC_STATE_DSR_MASK        = 1<<1;
   static constexpr uint8_t CDC_STATE_BREAK_IN_MASK   = 1<<2;
   static constexpr uint8_t CDC_STATE_RI_MASK         = 1<<3;
   static constexpr uint8_t CDC_STATE_FRAME_MASK      = 1<<4;
   static constexpr uint8_t CDC_STATE_PARITY_MASK     = 1<<5;
   static constexpr uint8_t CDC_STATE_OVERRUN_MASK    = 1<<6;
   static constexpr uint8_t CDC_STATE_CHANGE_MASK     = 1<<7;

   static constexpr uint8_t CDC_LINE_CONTROL_DTR_MASK = 1<<0;
   static constexpr uint8_t CDC_LINE_CONTROL_RTS_MASK = 1<<1;

   // UART control and status
   static void setLineCoding(const LineCodingStructure *lineCodingStructure);
   static const LineCodingStructure *getLineCoding(void);

   static void setControlLineState(uint8_t value);

   static void sendBreak(uint16_t length);

   static CdcLineState getSerialState();


   static void putInBuffer(char ch);

//   // SCI Tx
//   bool putTxBuffer(char *source, uint8_t size);
//   uint8_t txBufferIsFree(void);
//
//   // SCI Rx
//   uint8_t setRxBuffer(char *buffer);
//   uint8_t rxBufferItemCount(void);
//   void checkUsbCdcRxData(void);
};

}; // end namespace USBDM

#endif /* PROJECT_HEADERS_CDC_UART_H_ */
