/*
 * cdc_uart.cpp
 *
 *  Created on: 6Nov.,2016
 *      Author: podonoghue
 */
#include <string.h>
#include "usb_cdc_uart.h"
#include "derivative.h"
#include "usb.h"
#include "utilities.h"
#include "uart.h"

using UartInfo = USBDM::Uart1Info;

namespace USBDM {

static constexpr int CDC_TX_BUFFER_SIZE = CDC_DATA_OUT_EP_MAXSIZE;
static char outBuffer[CDC_TX_BUFFER_SIZE];
static uint8_t outHeadPtr     = 0;
static uint8_t outBufferCount = 0;

static constexpr int CDC_RX_BUFFER_SIZE = CDC_DATA_IN_EP_MAXSIZE;
static char *inBuffer        = NULL;
static uint8_t inBufferCount = 0;

uint8_t             CdcUart::breakCount = 0;
uint8_t             CdcUart::cdcStatus  = CdcUart::CDC_STATE_CHANGE_MASK;
LineCodingStructure CdcUart::lineCoding = {leToNative32(9600UL),0,1,8};

/**
 * Get state of serial interface
 *
 * @return Bit mask value
 */
CdcLineState CdcUart::getSerialState() {

   static uint8_t lastSciStatus = 0x00;

   // Assume DCD & DSR
   CdcLineState status;
   status.bits = CDC_STATE_DCD_MASK|CDC_STATE_DSR_MASK;

   if (cdcStatus&UART_S1_FE_MASK) {
      status.bits |= CDC_STATE_FRAME_MASK;
   }
   if (cdcStatus&UART_S1_OR_MASK) {
      status.bits |= CDC_STATE_OVERRUN_MASK;
   }
   if (cdcStatus&UART_S1_PF_MASK) {
      status.bits |= CDC_STATE_PARITY_MASK;
   }
   if (lastSciStatus != cdcStatus) {
      // Remember error status so we only report changes
      lastSciStatus  = cdcStatus&(UART_S1_FE_MASK|UART_S1_OR_MASK|UART_S1_PF_MASK);
      status.bits   |= CDC_STATE_CHANGE_MASK;
   }
   cdcStatus = 0;
   return status;
}

/**
 *  Set CDC communication characteristics
 *
 * @param lineCodingStructure - Structure describing desired settings
 *
 * The CDC is quite limited when compared to the serial interface implied
 * by LineCodingStructure.
 * It does not support many of the combinations available.
 */
void CdcUart::setLineCoding(const LineCodingStructure *lineCodingStructure) {
   uint8_t  UARTC1Value = 0x00;
   uint8_t  UARTC3Value = 0x00;

   // Initialise UART and set baud rate
   Uart_T<UartInfo> uart(leToNative32(lineCoding.dwDTERate));

   USBDM::UartIrq_T<UartInfo>::setCallback(uartCallback);

   cdcStatus  = CDC_STATE_CHANGE_MASK;
   breakCount = 0; // Clear any current BREAKs

   (void)memcpy(&lineCoding, lineCodingStructure, sizeof(LineCodingStructure));

   //! Note - for a 48MHz bus speed the useful baud range is ~300 to ~115200 for 0.5% error
   //  230400 & 460800 have a 8.5% error

   // Configure pins
   UartInfo::initPCRs();

   // Disable the transmitter and receiver while changing settings.
   UartInfo::uart->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

   // Note: lineCoding.bCharFormat is ignored (always 1 stop bit)
   //   switch (lineCoding.bCharFormat) {
   //      case 0:  // 1 bits
   //      case 1:  // 1.5 bits
   //      case 2:  // 2 bits
   //   }

   // Available combinations
   //============================================
   // Data bits  Parity   Stop |  M   PE  PT  T8
   //--------------------------------------------
   //     7      Odd       1   |  0   1   1   X
   //     7      Even      1   |  0   1   0   X
   //     8      None      1   |  0   0   X   X
   //     8      Odd       1   |  1   1   1   X
   //     8      Even      1   |  1   1   0   X
   //     8      Mark      1   |  1   0   X   0
   //     8      Space     1   |  1   0   X   1
   //--------------------------------------------
   //   All other values default to 8-None-1

   switch (lineCoding.bDataBits) {
      // 5,6,7,8,16
      case 7 :
         switch (lineCoding.bParityType) {
            case 1:  UARTC1Value = UART_C1_PE_MASK|UART_C1_PT_MASK; break; // Odd
            case 2:  UARTC1Value = UART_C1_PE_MASK;                 break; // Even
         }
         break;
      case 8 :
         UARTC1Value = UART_C1_M_MASK; // 9-data or 8-data+parity
         switch (lineCoding.bParityType) {
            case 0:  UARTC1Value  = 0;                               break; // None
            case 1:  UARTC1Value |= UART_C1_PE_MASK|UART_C1_PT_MASK; break; // Odd
            case 2:  UARTC1Value |= UART_C1_PE_MASK;                 break; // Even
            case 3:  UARTC3Value  = UART_C3_T8_MASK;                 break; // Mark
            case 4:                                                  break; // Space
         }
         break;
      default :
         break;
   }
   UartInfo::uart->C1 = UARTC1Value;
   UartInfo::uart->C2 =
         UART_C2_RIE_MASK| // Receive interrupts (Transmit interrupts enabled when data written)
         UART_C2_RE_MASK|  // Receiver enable
         UART_C2_TE_MASK;  // Transmitter enable
   UartInfo::uart->C3 = UARTC3Value|
         UART_C3_FEIE_MASK| // Framing error
         UART_C3_NEIE_MASK| // Noise error
         UART_C3_ORIE_MASK| // Overrun error
         UART_C3_PEIE_MASK; // Parity error

   // Discard any data in buffers
   inBufferCount  = 0;
   outBufferCount = 0;

   NVIC_EnableIRQ(UartInfo::irqNums[0]);
}

/**
 *  Get CDC communication characteristics\n
 *
 *  @return lineCodingStructure - Static structure describing current settings
 */
const LineCodingStructure *CdcUart::getLineCoding(void) {
   return &lineCoding;
}

/**
 *  Send CDC break\n
 *
 * @param length - length of break in milliseconds (see note)\n
 *  - 0x0000 => End BREAK
 *  - 0xFFFF => Start indefinite BREAK
 *  - else   => Send a break of 10 chars

 * @note - only partially implemented
 *       - breaks are sent after currently queued characters
 */
void CdcUart::sendBreak(uint16_t length) {
   if (length == 0xFFFF) {
      // Send indefinite BREAKs
      breakCount = 0xFF;
   }
   else if (length == 0x0) {
      // Stop sending BREAKs
      breakCount = 0x00;
   }
   else {
      // Queue a series of BREAKs
      breakCount = 10;
   }
}

/**
 *  Set CDC Line values
 *
 * @param value - Describes desired settings
 */
void CdcUart::setControlLineState(uint8_t value) {
   (void) value;
   // Not implemented as no control signals
}

/*
 * Simple double-buffering for Rx (in conjunction with USB buffer)
 */

/**
 * Add a character to the CDC-Rx buffer
 *
 * @param ch Character to add
 *
 * @note Overrun flag is set on buffer full
 */
void CdcUart::putInBuffer(char ch) {
   if (inBufferCount >= CDC_RX_BUFFER_SIZE) {
      // Overrun
      cdcStatus |= UART_S1_OR_MASK;
      return;
   }
   // Save char
   inBuffer[inBufferCount++] = ch;
}

/**
 * Set current Rx Buffer
 *
 * @param buffer Buffer address, new data is written to this buffer
 *
 * @return Number of characters in existing buffer
 *
 * @note Assumed called while interrupts blocked
 */
uint8_t setInBuffer(char *buffer) {
   inBuffer = buffer;
   uint8_t temp = inBufferCount;
   inBufferCount = 0;
   return temp;
}

/**
 *  RxBufferEmpty() - Check if Rx buffer is empty
 *
 * @return -  >0 => buffer is not empty
 *            0  => buffer is empty
 */
uint8_t getInBufferItemCount(void) {
   return inBufferCount;
}

/*
 * Simple double-buffering for CDC-OUT (in conjunction with USB end-point buffer)
 */

/**
 * Add data to Tx Buffer (from USB)
 *
 * @param source Source buffer to copy from
 * @param size   Number of bytes to copy
 *
 *  @return true => OK, false => Buffer is busy (overrun)
 */
bool putOutBuffer(char *source, uint8_t size) {
   if (outBufferCount > 0) {
      return 1; // Busy
   }
   (void)memcpy(outBuffer, source, size);
   outHeadPtr        = 0;
   outBufferCount = size;
   UartInfo::uart->C2 |= UART_C2_TIE_MASK; // Enable UART Tx interrupts
   return 0;
}

static int getOutBuffer(void) {
   uint8_t ch;
   if (outBufferCount == 0) {
      // Check data in USB buffer & restart USB Out if needed
      //      checkUsbCdcTxData();
   }
   // Need to re-check as above may have copied data
   if (outBufferCount == 0) {
      return -1;
   }
   ch = outBuffer[outHeadPtr++];
   if (outHeadPtr >= outBufferCount)
      outBufferCount = 0;
   return ch;
}

/**
 *  cdcTxSpace - check if CDC-Tx buffer is free
 *
 * @return 0 => buffer is occupied
 *         1 => buffer is free
 */
uint8_t outBufferIsFree() {
   return (outBufferCount == 0);
}

/**
 * Interrupt callback for UART
 */
void CdcUart::uartCallback(uint8_t status) {
   if (status&UART_S1_RDRF_MASK) {
      // Transfers a char from the UART_D to CDC-IN queue
      putInBuffer(UartInfo::uart->D);
   }
   else if (status&UART_S1_TDRE_MASK) {
      //  Transfer a char from the CDC-OUT queue to UART_D
      int ch = getOutBuffer();
      if (ch >= 0) {
         UartInfo::uart->D = (uint8_t)ch; // Send the char
      }
      else if (breakCount > 0) {
         // Send another BREAK 'char'
         UartInfo::uart->C2 |=  UART_C2_SBK_MASK;
         UartInfo::uart->C2 &= ~UART_C2_SBK_MASK;
         if (breakCount != 0xFF) {
            breakCount--;
         }
      }
      else {
         // No characters available
         // Disable further UART transmit interrupts
         UartInfo::uart->C2 &= ~UART_C2_TIE_MASK;
      }
   }
   else {
      // Record and clear error status
      cdcStatus |= status;
      (void)UartInfo::uart->D;
   }
}

}; // End namespace USBDM
