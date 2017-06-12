/*
 * console-lpuart.c
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#include <derivative.h>
#include "system.h"
#include "clock_configure.h"
#include "console.h"

//#define USE_IRQ

#if defined(MCU_MKL82Z7)
//=================================================================================
// UART to use
//
#define LPUART       LPUART0

//=================================================================================
// UART Port pin setup
//
inline static void initDefaultUart()  {
   // Enable clock to UART
   SIM->SCGC5 |= SIM_SCGC5_LPUART0_MASK;

   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_LPUART0RXSRC_MASK|SIM_SOPT5_LPUART0TXSRC_MASK);

   // Enable clock to port pins used by UART
   SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;

   // Set Tx & Rx Pin function
   PORTB->PCR[16] = PORT_PCR_MUX(3);
   PORTB->PCR[17] = PORT_PCR_MUX(3);
}
#elif defined(MCU_MK82F25615)
//=================================================================================
// UART to use
//
#define LPUART  LPUART4

//=================================================================================
// UART Port pin setup
//
inline static void initDefaultUart()  {
   // Enable clock to UART
   SIM->SCGC2 |= SIM_SCGC2_LPUART4_MASK;

   // Enable clock to port pins used by UART
   SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

   // Set Tx & Rx Pin function
   PORTC->PCR[14] = PORT_PCR_MUX(3);
   PORTC->PCR[15] = PORT_PCR_MUX(3);
}
#endif

#define LPUART_FLAGS                \
   (LPUART_STAT_LBKDIF_MASK|        \
         LPUART_STAT_RXEDGIF_MASK|  \
         LPUART_STAT_IDLE_MASK|     \
         LPUART_STAT_OR_MASK|       \
         LPUART_STAT_NF_MASK|       \
         LPUART_STAT_FE_MASK|       \
         LPUART_STAT_PF_MASK)

/**
 * Set Console baud rate
 *
 * @param baudRate - the baud rate to use e.g. 19200
 */
void console_setBaudRate(int baudRate) {
#define OSR_VALUE (8)

	uint32_t clockIn = 0;

	switch(SIM_SOPT2_LPUARTSRC_V) {
	case 0:
		// Disabled
		__asm__("bkpt");
		break;
	case 1:
		clockIn = SIM_CLKDIV3_PLLFLL_FACTOR(SYSTEM_PERIPHERAL_CLOCK);
		break;
	case 2:
		clockIn = OSCCLK_CLOCK;
		break;
	case 3:
		clockIn = SYSTEM_MCGIR_CLOCK;
		break;
	}

   // Disable UART before changing registers
   LPUART->CTRL = 0;

   // Calculate UART clock setting (assume 8MHz clock!)
   int scaledBaudValue = clockIn/(OSR_VALUE*baudRate);

   // Set Baud rate register
   LPUART->BAUD = LPUART_BAUD_SBR(scaledBaudValue)|LPUART_BAUD_OSR(OSR_VALUE-1);

   // Clear flags
   LPUART->STAT = LPUART_FLAGS;

   // Disable FIFO
   LPUART->FIFO = 0;

   // Enable UART Tx & Rx
   LPUART->CTRL = LPUART_CTRL_RE_MASK|LPUART_CTRL_TE_MASK;
}

/*
 * Transmits a single character over the UART (blocking)
 *
 * @param ch - character to send
 */
void console_txChar(int ch) {
   while ((LPUART->STAT & LPUART_STAT_TDRE_MASK) == 0) {
      // Wait for Tx buffer empty
      __asm__("nop");
   }
   LPUART->DATA = ch;
}

/*
 * Receives a single character over the UART (blocking)
 *
 * @return - character received
 */
int console_rxChar(void) {
   uint32_t status;

   // Wait for Rx buffer full
   do {
      status = LPUART->STAT & LPUART_FLAGS;
      // Clear & ignore pending errors
      if (status != 0) {
         // Clear flags
         LPUART->STAT = status;
      }
   }  while ((status & LPUART_STAT_RDRF_MASK) == 0);
   int ch = LPUART->DATA;
   if (ch == '\r') {
      ch = '\n';
   }
   return ch;
}

/*
 * Initialises the Console with default settings
 */
void console_initialise() {
   initDefaultUart();
   console_setBaudRate(DEFAULT_BAUD_RATE);
}
