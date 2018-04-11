/*
 * console-mke-lp.c
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#include <derivative.h>
#include "system.h"
#include "clock_configure.h"
#include "console.h"

#if defined(MCU_MKE15Z7)
//=================================================================================

/** SCGFIRCLK - Fast IRC Clock(scg_firc_slow_clk), (maximum is 48MHz) **/
#define UART_CLOCK 48000000
#define LPUART     LPUART1

//=================================================================================
// UART Port pin setup
//
inline static void initDefaultUart()  {
   // Enable and select clock to UART
   PCC->PCC_LPUART1 =
         PCC_PCC_LPUART1_CGC(1)| // Enable
         PCC_PCC_LPUART1_PCS(3); // SCGFIRCLK

   // Enable clock to port pins used by UART
   PCC->PCC_PORTC = PCC_PCCn_CGC(1)|PCC_PCCn_PCS(1);

   // Set Tx & Rx Pin function
   PORTC->PCR[6] = PORT_PCR_MUX(2);
   PORTC->PCR[7] = PORT_PCR_MUX(2);
}
#elif defined(MCU_S32K144)
//=================================================================================

/** SCGFIRCLK - Fast IRC Clock(scg_firc_slow_clk), (maximum is 48MHz) **/
#define UART_CLOCK 48000000
#define LPUART     LPUART1

//=================================================================================
// UART Port pin setup
//
inline static void initDefaultUart()  {
   // Enable and select clock to UART
   PCC->PCC_LPUART1 =
         PCC_PCC_LPUART1_CGC(1)| // Enable
         PCC_PCC_LPUART1_PCS(3); // SCGFIRCLK

   // Enable clock to port pins used by UART
   PCC->PCC_PORTC = PCC_PCCn_CGC(1)|PCC_PCCn_PCS(1);

   // Set Tx & Rx Pin function
   PORTC->PCR[6] = PORT_PCR_MUX(2);
   PORTC->PCR[7] = PORT_PCR_MUX(2);
}
#else
#error "Please modify before use"
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

#define OVERSAMPLE (16)

// Disable LPUART before changing registers
LPUART->CTRL &= ~(LPUART_CTRL_RE_MASK|LPUART_CTRL_TE_MASK);

// Calculate LPUART clock setting
int baudValue = UART_CLOCK/(OVERSAMPLE*baudRate);

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
 * Transmits a single character over the UART (blocking)
 *
 * @param ch - character to send
 */
void console_txChar(int ch) {
   while ((LPUART->STAT & LPUART_STAT_TDRE_MASK) == 0) {
      // Wait for Tx buffer empty
      __asm__("nop");
   }
   LPUART->DATA = LPUART_DATA_RT(ch);
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
   int ch = LPUART_DATA_RT(LPUART->DATA);
//   console_txChar(ch);
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

