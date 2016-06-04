/*
 * console-mk.c
 *
 *  Created on: 14/04/2013
 *      Author: pgo
 */

#include <derivative.h>
#include "system.h"
#include "uart.h"
#include "console.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

/*
<o0> Choice of UART for console
   <0=> USBDM::Uart0
   <1=> USBDM::Uart1
   <2=> USBDM::Uart2
   <3=> USBDM::Uart3
   <3=> USBDM::Uart4
   <3=> USBDM::Uart5
   <1=> Default
   <info>Not all listed UARTs may be available
*/
#define CONSOLE $(demo.cpp.console:USBDM::Uart##0)

//*** <<< end of configuration section >>>    ***

// Maps console to UART used
using  Console = CONSOLE;

// Console instance
static Console *console = nullptr;

/*
 * Initialises the Console
 *
 * @param baudrate - the baud rate to use e.g. DEFAULT_BAUD_RATE
 */
extern "C"
void console_initialise(int baudRate) {
   if (console == nullptr) {
      console = new Console(baudRate);
   }
}

/*
 * Transmits a single character to Console
 *
 * @param ch - character to send
 */
extern "C"
void console_txChar(int ch) {
   console->tx(ch);
}

/*
 * Receives a single character fropm Console (blocking)
 *
 * @return - character received
 */
extern "C"
int console_rxChar(void) {
   int ch = console->rx();
   if (ch == '\r') {
      ch = '\n';
   }
   return ch;
}
