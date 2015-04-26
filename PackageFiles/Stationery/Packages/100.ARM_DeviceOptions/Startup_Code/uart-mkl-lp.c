/*
 * uart-mkl-lp.c
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#include <derivative.h>
#include "system.h"
#include "clock_configure.h"
#include "uart.h"

//#define USE_IRQ

#if defined(MCU_MKL03Z4)
//=================================================================================
// LPUART to use
//
#define LPUART  LPUART0
#define UART_CLOCK SYSTEM_LPUART0_CLOCK

//=================================================================================
// LPUART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {

   // Enable clock to LPUART
   // Enable clock to port pins used by LPUART
   SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK|SIM_SCGC5_LPUART0_MASK;

   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_LPUART0ODE_MASK|SIM_SOPT5_LPUART0RXSRC_MASK|SIM_SOPT5_LPUART0TXSRC_MASK);

   // Set Tx & Rx Pin function
   PORTB->PCR[1] = PORT_PCR_MUX(2);
   PORTB->PCR[2] = PORT_PCR_MUX(2);

#ifdef USE_IRQ
   // Enable IRQs in NVIC
   NVIC_EnableIRQ(LPUART0_IRQn);
#endif
}
#elif defined(MCU_MKL43Z4)
//=================================================================================
// LPUART to use
//
#define LPUART  LPUART0
#define UART_CLOCK SYSTEM_LPUART0_CLOCK

//=================================================================================
// LPUART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {

   // Enable clock to LPUART
   // Enable clock to port pins used by LPUART
   SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK|SIM_SCGC5_LPUART0_MASK;

   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_LPUART0ODE_MASK|SIM_SOPT5_LPUART0RXSRC_MASK|SIM_SOPT5_LPUART0TXSRC_MASK);

   // Set Tx & Rx Pin function
   PORTA->PCR[1] = PORT_PCR_MUX(2);
   PORTA->PCR[2] = PORT_PCR_MUX(2);

#ifdef USE_IRQ
   // Enable IRQs in NVIC
   NVIC_EnableIRQ(LPUART0_IRQn);
#endif
}
#else
#error "Please modify before use"
//=================================================================================
// LPUART to use
//
#define LPUART  LPUART0
#define UART_CLOCK SYSTEM_LPUART0_CLOCK

//=================================================================================
// LPUART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {

   // Enable clock to LPUART
   SIM->SCGC5 |= SIM_SCGC5_LPUART0_MASK;

   // Enable clock to port pins used by LPUART
   SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_LPUART0ODE_MASK|SIM_SOPT5_LPUART0RXSRC_MASK|SIM_SOPT5_LPUART0TXSRC_MASK);

   SIM->SOPT2 = (SIM->SOPT2 & ~SIM_SOPT2_LPUART0SRC_MASK) | SIM_SOPT2_LPUART0SRC(1);

   // Set Tx & Rx Pin function
   PORTA->PCR[1] = PORT_PCR_MUX(2);
   PORTA->PCR[2] = PORT_PCR_MUX(2);
}
#endif

#if !defined(UART_CLOCK)
#error "UART_CLOCK not defined"
#endif

/*
 * Initialises the LPUART
 *
 * @param baudrate - the baud rate to use e.g. 19200
 */
void uart_initialise(int baudrate) {
   initDefaultUart();

   #define OVERSAMPLE (16)

   // Disable LPUART before changing registers
   LPUART->CTRL &= ~(LPUART_CTRL_RE_MASK|LPUART_CTRL_TE_MASK);

   // Calculate LPUART clock setting
   int baudValue = UART_CLOCK/(OVERSAMPLE*baudrate);

   // Set Baud rate register
   LPUART->BAUD = LPUART_BAUD_SBR(baudValue)|LPUART_BAUD_OSR(OVERSAMPLE-1);

#ifdef USE_IRQ
   // Enable LPUART Tx & Rx - with Rx IRQ
   LPUART->CTRL = LPUART_CTRL_RE_MASK|LPUART_CTRL_TE_MASK|LPUART_CTRL_RIE_MASK|LPUART_CTRL_TIE_MASK;
#else
   // Enable LPUART Tx & Rx
   LPUART->CTRL = LPUART_CTRL_RE_MASK|LPUART_CTRL_TE_MASK;
#endif
}

/*
 * Transmits a single character over the LPUART (blocking)
 *
 * @param ch - character to send
 */
void uart_txChar(int ch) {
   while ((LPUART->STAT & LPUART_STAT_TDRE_MASK) == 0) {
      // Wait for Tx buffer empty
      __asm__("nop");
   }
   LPUART->DATA = LPUART_DATA_RT(ch);
}

#ifdef USE_IRQ
static uint8_t rxBuffer[100];
static uint8_t *rxPutPtr = rxBuffer;
static uint8_t *rxGetPtr = rxBuffer;

void LPUART0_IRQHandler() {
   // Clear & ignore any pending errors
   if ((LPUART->STAT & (LPUART_STAT_FE_MASK|LPUART_STAT_OR_MASK|LPUART_STAT_PF_MASK|LPUART_STAT_NF_MASK)) != 0) {
      // Clear error status
      LPUART->STAT = LPUART_STAT_FE_MASK|LPUART_STAT_OR_MASK|LPUART_STAT_PF_MASK|LPUART_STAT_NF_MASK;
   }
   int ch = LPUART_DATA_RT(LPUART->DATA);
   *rxPutPtr++ = ch;
   if (rxPutPtr == rxBuffer+sizeof(rxBuffer)) {
      rxPutPtr = rxBuffer;
   }
}

/*
 * Receives a single character over the LPUART (blocking)
 *
 * @return - character received
 */
int uart_rxChar(void) {

   // Wait for character
   while (rxGetPtr==rxPutPtr) {
   }
   // Get char from buffer
   __disable_irq();
   int ch = *rxGetPtr++;
   if (rxGetPtr==rxBuffer+sizeof(rxBuffer)) {
      rxGetPtr = rxBuffer;
   }
   __enable_irq();
   if (ch == '\r') {
      ch = '\n';
   }
   return ch;
}
#else
/*
 * Receives a single character over the LPUART (blocking)
 *
 * @return - character received
 */
int uart_rxChar(void) {
   uint8_t status;
   // Wait for Rx buffer full
   do {
      status = LPUART->STAT;
      // Clear & ignore pending errors
      if ((status & (LPUART_STAT_FE_MASK|LPUART_STAT_OR_MASK|LPUART_STAT_PF_MASK|LPUART_STAT_NF_MASK)) != 0) {
         LPUART->STAT = LPUART_STAT_FE_MASK|LPUART_STAT_OR_MASK|LPUART_STAT_PF_MASK|LPUART_STAT_NF_MASK;
      }
   }  while ((status & LPUART_STAT_RDRF_MASK) == 0);
   int ch = LPUART_DATA_RT(LPUART->DATA);
//   uart_txChar(ch);
   if (ch == '\r') {
      ch = '\n';
   }
   return ch;
}
#endif
