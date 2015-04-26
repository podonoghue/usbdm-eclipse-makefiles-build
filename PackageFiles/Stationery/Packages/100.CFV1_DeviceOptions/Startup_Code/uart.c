/*
 * uart.c
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#include <derivative.h>
#include "system.h"
#include "clock_configure.h"
#include "uart.h"

#define TX_MUX_REG     MXC(UART0_TX_PIN_PORT,UART0_TX_MUX_NUM)
#define RX_MUX_REG     MXC(UART0_RX_PIN_PORT,UART0_RX_MUX_NUM)
#define TX_MUX_MASK(n) MXC_MASK(UART0_TX_PIN_NUM,n)
#define RX_MUX_MASK(n) MXC_MASK(UART0_RX_PIN_NUM,n)

#if defined(MCU_mcf51jf128) || defined(MCU_MCF51JF) || defined(MCU_mcf51ju128) || defined(MCU_MCF51JU)
//=================================================================================
// UART to use
//
#define UART  UART0

#define UART_CLOCK SYSTEM_UART0_CLOCK

//=================================================================================
// UART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {
   // Enable clock to UART
   SIM->SCGC1 |= SIM_SCGC1_UART0_MASK;

   // Set Tx (A7) & Rx (D6) Pin function
   MXC->PTDPF1 = (MXC->PTDPF1 & ~MXC_PTDPF1_D6_MASK) | MXC_PTDPF1_D6(2); // UART0_Rx
   MXC->PTAPF1 = (MXC->PTAPF1 & ~MXC_PTAPF1_A7_MASK) | MXC_PTAPF1_A7(2); // UART0_Tx

   // Set Tx & Rx pins in use
//   SIM_SOPT5 &= ~(SIM_SOPT5_UART0RXSRC_MASK|SIM_SOPT5_UART0TXSRC_MASK);


}
#elif defined(MCU_mcf51ju128)
//=================================================================================
// UART to use
//
#define UART  UART0_BASE_PTR

#define UART_CLOCK SYSTEM_UART0_CLOCK

//=================================================================================
// UART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {
   // Enable clock to UART
   SIM->SCGC1 |= SIM_SCGC1_UART0_MASK;

   // Set Tx (C6) & Rx (C7) Pin function
   MXC->PTDPF1 = (MXC_PTCPF1 & ~MXC_PTCPF1_C6_MASK) | MXC_PTCPF1_C6(2); // UART0_Rx
   MXC->PTAPF1 = (MXC_PTCPF1 & ~MXC_PTCPF1_C7_MASK) | MXC_PTCPF1_C7(2); // UART0_Tx

   // Set Tx & Rx pins in use
//   SIM_SOPT5 &= ~(SIM_SOPT5_UART0RXSRC_MASK|SIM_SOPT5_UART0TXSRC_MASK);


}
#else
#error "Please modify before use"
//=================================================================================
// UART to use
//
#define UART  UART0
#define UART_CLOCK SYSTEM_UART0_CLOCK

//=================================================================================
// UART Port pin setup
//
__attribute__((always_inline))
inline static void initDefaultUart()  {
   // Enable clock to UART
   SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

   // Enable clock to port pins used by UART
   SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

   // Select Tx & Rx pins to use
   SIM_SOPT5 &= ~(SIM_SOPT5_UART0RXSRC_MASK|SIM_SOPT5_UART0TXSRC_MASK);

   // Set Tx & Rx Pin function
   PORTD_PCR6 = PORT_PCR_MUX(3);
   PORTD_PCR7 = PORT_PCR_MUX(3);
}
#endif

#if !defined(UART_CLOCK)
#error "UART_CLOCK not defined"
#endif

/*
 * Initialises the UART
 *
 * @param baudrate - the baud rate to use e.g. 19200
 */
void uart_initialise(int baudrate) {
   initDefaultUart();

   // Disable UART before changing registers
   UART->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

   // Calculate UART clock setting (5-bit fraction at right)
   int scaledBaudValue = (2*UART_CLOCK)/(baudrate);

#ifdef UART_C4_BRFA_MASK
   // Set Baud rate register
   UART->BDH = (UART->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
   UART->BDL = UART_BDL_SBR(scaledBaudValue>>5);
   // Fractional divider to get closer to the baud rate
   UART->C4 = (UART->C4&~UART_C4_BRFA_MASK) | UART_C4_BRFA(scaledBaudValue);
#else
	scaledBaudValue += 1<<4; // Round value
   // Set Baud rate register
   UART->BDH = (UART->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
   UART->BDL = UART_BDL_SBR(scaledBaudValue>>5);
#endif

   UART->C1 = 0;

   // Enable UART Tx & Rx
   UART->C2 = UART_C2_TE_MASK|UART_C2_RE_MASK;
}

/*
 * Transmits a single character over the UART (blocking)
 *
 * @param ch - character to send
 */
void uart_txChar(int ch) {
   while ((UART->S1 & UART_S1_TDRE_MASK) == 0) {
      // Wait for Tx buffer empty
      __asm__("nop");
   }
   UART->D = ch;
}

/*
 * Receives a single character over the UART (blocking)
 *
 * @return - character received
 */
int uart_rxChar(void) {
   while ((UART->S1 & UART_S1_RDRF_MASK) == 0) {
      // Wait for Rx buffer full
      __asm__("nop");
   }
   return UART->D;
};
