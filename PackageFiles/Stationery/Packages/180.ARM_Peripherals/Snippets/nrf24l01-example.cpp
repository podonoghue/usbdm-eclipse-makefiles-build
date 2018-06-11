/*
 ============================================================================
 * main-MK.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "nrf24l01.h"

/*
 * It will be necessary to change pin mappings to use this example
 * Make sure the following are correctly set under "Peripheral View".
 *
 * For whichever SPI is being used:
 * nRF24L01 SCK   - SPI SCK signal
 * nRF24L01 MISO  - SPI SIN signal
 * nRF24L01 MOSI  - SPI SOUT signal
 * nRF24L01 CS_n  - SPI PCSx signal
 *
 * Two individual GPIOs are used with the module (see below)
 * nRF24L01 CE    - GPIO signal
 * nRF24L01 IRQ   - GPIO signal
 */

using CeGpio_n = USBDM::$(demo.cpp.nrf24l01.ce:GpioC<4>); // CE pin
using IrqGpio  = USBDM::$(demo.cpp.nrf24l01.irq:GpioC<5>); // IRQ pin

int main() {
   USBDM::Spi *spi = new USBDM::$(demo.cpp.nrf24l01.spi:Spi0)($(demo.cpp.spi.dma:));

   USBDM::NRF24L01 *nrf24l01 = new USBDM::NRF24L01_T<CeGpio_n, IrqGpio>(spi);

   for (;;) {
      uint8_t txData[] = {1,2,3,4};
      uint8_t rxData[100];
      nrf24l01->transmitData(sizeof(txData), txData);
      uint8_t status = nrf24l01->getStatus();
      if ((status & USBDM::NRF24L01::FIFO_STATUS_RX_FULL) != 0) {
         nrf24l01->receiveData(sizeof(rxData), rxData);
      }
   }
}
