/*
 * NRF24L01.cpp
 *
 *  Created on: 30/06/2014
 *      Author: podonoghue
 */
#include "nrf24l01.h"
#include "delay.h"

namespace USBDM {

static constexpr uint8_t R_REGISTER         = 0x00; // 000a aaaa - Read command and status registers. AAAAA = 5 bit Register Map Address
static constexpr uint8_t W_REGISTER         = 0x20; // 001a aaaa - Write command and status registers. AAAAA = 5 bit Register Map Address.
//                                                  // Executable in power down or standby modes only.
static constexpr uint8_t R_RX_PAYLOAD       = 0x61; // 0110 0001 - Read RX-pay-load: 1 - 32 bytes. A read operation always starts at byte 0.
//                                                  // Pay-load is deleted from FIFO after it is read. Used in RX mode.
static constexpr uint8_t W_TX_PAYLOAD       = 0xA0; // 1010 0000 - Write TX-pay-load: 1 - 32 bytes. A write operation always starts at byte 0. Used in TX payload.
static constexpr uint8_t FLUSH_TX           = 0xE1; // 1110 0001 - Flush TX FIFO; used in TX mode
static constexpr uint8_t FLUSH_RX           = 0xE2; // 1110 0010 - Flush RX FIFO; used in RX mode
//                                                  // Should not be executed during transmission of acknowledge.
static constexpr uint8_t REUSE_TX_PL        = 0xE3; // 1110 0011 - Used for a PTX device. Reuse last transmitted pay-load.
//                                                  // TX pay-load reuse is active until W_TX_PAYLOAD or FLUSH TX is executed.
//                                                  // TX pay-load reuse must not be activated or deactivated during package transmission.
static constexpr uint8_t R_RX_PL_WID        = 0x60; // 0110 0000 - Read RX pay-load width for the top R_RX_PAYLOAD in the RX FIFO.
//                                                  // Note: Flush RX FIFO if the read value is larger than 32 bytes.
static constexpr uint8_t W_ACK_PAYLOAD      = 0xA8; // 1010 1000 - Used in RX mode. Write Pay-load to be transmitted together with ACK packet on PIPE PPP.
//                                                  // (PPP valid in the range from 000 to 101). Maximum three ACK packet pay-loads can be pending.
//                                                  // Pay-loads with same PPP are handled using first in - first out principle.
//                                                  // Write pay-load: 1-32 bytes. A write operation always starts at byte 0.
static constexpr uint8_t W_TX_PAYLOAD_NOACK = 0xB0; // 1011 0000 - Used in TX mode. Disables AUTOACK on this specific packet.
static constexpr uint8_t NOP                = 0xFF; // 1111 1111 - No operation. May be used to read the STATUS register

const NRF24L01::NRFData NRF24L01::DEFAULT_CONFIGURATION = {
   /*                               */ CONFIG_EN_CRC,
   /* Enable Auto-ACK on Pipe n     */ EN_AA_P0|EN_AA_P1|EN_AA_P2|EN_AA_P3|EN_AA_P4|EN_AA_P5,
   /* Enable Rx address             */ EN_RXADDR_P0|EN_RXADDR_P1|EN_RXADDR_P2|EN_RXADDR_P3|EN_RXADDR_P4|EN_RXADDR_P5,
   /* Address Widths                */ SETUP_AW_5_BYTES,
   /* Auto Tx retry delay and count */ SETUP_RETR_ARD(0)|SETUP_RETR_ARC(3),
   /* RF Channel                    */ RF_CH_CH(2),
   /* RF Setup                      */ RF_SETUP_PWR_0dBm|RF_SETUP_RF_DR_2Mbps,
   /* Rx address Pipe 0             */ {0xE7,0xE7,0xE7,0xE7,0xE7},
   /* Rx address pipe 1             */ {0xC2,0xC2,0xC2,0xC2,0xC2},
   /* Rx Address Pipe 2 (lsb only)  */ 0xC3,
   /* Rx_Address Pipe 3 (lsb only)  */ 0xC4,
   /* Rx Address Pipe 4 (lsb only)  */ 0xC5,
   /* Rx Address Pipe 5 (lsb only)  */ 0xC6,
   /* Tx Address                    */ {0xE7,0xE7,0xE7,0xE7,0xE7},
   /* Rx Pay-load width Pipe 0      */ 0,
   /* Rx Pay-load width Pipe 1      */ 0,
   /* Rx Pay-load width Pipe 2      */ 0,
   /* Rx Pay-load width Pipe 3      */ 0,
   /* Rx Pay-load width Pipe 4      */ 0,
   /* Rx Pay-load width Pipe 5      */ 0,
   /* Dynamic pay-load length       */ 0, // DYNPD_P0 etc
   /* Features                      */ 0, // FEATURE_EN_ACK_PAY etc
};

/**
 * Initialise NRF24L01 based on configData data
 */
void NRF24L01::init() {
   static const uint8_t clearStatus[] = {NRF24L01::STATUS_RX_DR|NRF24L01::STATUS_TX_DS|NRF24L01::STATUS_MAX_RT};

   uint8_t buff[40];

   spi->setSpeed(10000000 /* Hz */);

   // Configure nRF24L01+ (Initially not powered-down)
   uint8_t configValue = configData->config & ~CONFIG_PWR_UP;
   writeRegister(CONFIG_REG,     sizeof(configValue),      &configValue);

   writeRegister(EN_AA_REG,      sizeof(configData->en_aa),       &configData->en_aa);
//   readRegister( EN_AA_REG,      sizeof(configData->en_aa),        buff);
   writeRegister(EN_RXADDR_REG,  sizeof(configData->en_rxaddr),   &configData->en_rxaddr);
//   readRegister( EN_RXADDR_REG,  sizeof(configData->en_rxaddr),    buff);
   writeRegister(SETUP_AW_REG,   sizeof(configData->setup_aw),    &configData->setup_aw);
//   readRegister( SETUP_AW_REG,   sizeof(configData->setup_aw),     buff);
   writeRegister(SETUP_RETR_REG, sizeof(configData->setup_retr),  &configData->setup_retr);
//   readRegister( SETUP_RETR_REG, sizeof(configData->setup_retr),   buff);
   writeRegister(RF_CH_REG,      sizeof(configData->rf_ch),       &configData->rf_ch);
//   readRegister( RF_CH_REG,      sizeof(configData->rf_ch),        buff);
   writeRegister(RF_SETUP_REG,   sizeof(configData->rf_setup),    &configData->rf_setup);
//   readRegister( RF_SETUP_REG,   sizeof(configData->rf_setup),     buff);
   writeRegister(STATUS_REG,     sizeof(clearStatus),              clearStatus);
   writeRegister(RX_ADDR_P0_REG, sizeof(configData->rx_addr_p0),   configData->rx_addr_p0);
   readRegister( RX_ADDR_P0_REG, sizeof(configData->rx_addr_p0),   buff);
   writeRegister(RX_ADDR_P1_REG, sizeof(configData->rx_addr_p1),   configData->rx_addr_p1);
   writeRegister(RX_ADDR_P2_REG, sizeof(configData->rx_addr_p2),  &configData->rx_addr_p2);
   writeRegister(RX_ADDR_P3_REG, sizeof(configData->rx_addr_p3),  &configData->rx_addr_p3);
   writeRegister(RX_ADDR_P4_REG, sizeof(configData->rx_addr_p4),  &configData->rx_addr_p4);
   writeRegister(RX_ADDR_P5_REG, sizeof(configData->rx_addr_p5),  &configData->rx_addr_p5);
   writeRegister(TX_ADDR_REG,    sizeof(configData->tx_addr),      configData->tx_addr);
//   readRegister(TX_ADDR_REG,     sizeof(configData->tx_addr),      buff);
   writeRegister(RX_PW_P0_REG,   sizeof(configData->rx_pw_p0),    &configData->rx_pw_p0);
   writeRegister(RX_PW_P1_REG,   sizeof(configData->rx_pw_p1),    &configData->rx_pw_p1);
   writeRegister(RX_PW_P2_REG,   sizeof(configData->rx_pw_p2),    &configData->rx_pw_p2);
   writeRegister(RX_PW_P3_REG,   sizeof(configData->rx_pw_p3),    &configData->rx_pw_p3);
   writeRegister(RX_PW_P4_REG,   sizeof(configData->rx_pw_p4),    &configData->rx_pw_p4);
   writeRegister(RX_PW_P5_REG,   sizeof(configData->rx_pw_p5),    &configData->rx_pw_p5);
   writeRegister(DYNPD_REG,      sizeof(configData->dynpd),       &configData->dynpd);
   writeRegister(FEATURE_REG,    sizeof(configData->feature),     &configData->feature);

   flushRx();
   flushTx();
}

/**
 * Read status register
 *
 * @return status register value
 */
uint8_t NRF24L01::getStatus(void) {
   uint8_t buff[] = {NOP};
   spi->txRxBytes(1,buff,buff);
   return buff[0];
}

/**
 * Write command
 *
 * @param command  - Command number e.g. R_REGISTER etc
 * @param dataSize - Size of data in bytes
 * @param data     - Data to write
 *
 * @return status register value
 */
uint8_t NRF24L01::writeCommand(uint8_t command, unsigned dataSize, const uint8_t data[]) {
   uint8_t buff[dataSize+1];
   buff[0] = command;
   memcpy(buff+1, data, dataSize);
   spi->txRxBytes(dataSize+1, buff, buff);
   return buff[0];
}

/**
 * Read command
 *
 * @param command  - Command number e.g. W_REGISTER etc
 * @param dataSize - Size of data in bytes
 * @param data     - Pointer to buffer for data read (may be NULL)
 *
 * @return status register value
 */
uint8_t NRF24L01::readCommand(uint8_t command, unsigned dataSize, uint8_t data[]) {
   uint8_t buff[dataSize+1];
   buff[0] = command;
   spi->txRxBytes(dataSize+1, buff, buff);
   if (data != 0) {
      memcpy(data, buff+1, dataSize);
   }
   return buff[0];
}

/**
 * Write data to register
 *
 * @param regNum   - Register number e.g. CONFIG_REG
 * @param dataSize - Size of data in bytes
 * @param data     - Data to write
 *
 * @return status register value
 */
uint8_t NRF24L01::writeRegister(uint8_t regNum, unsigned dataSize, const uint8_t data[]) {
   return writeCommand(W_REGISTER|regNum, dataSize, data);
}

/**
 * Read data from register
 *
 * @param regNum   - Register number e.g. CONFIG_REG
 * @param dataSize - Size of data in bytes
 * @param data     - Pointer to buffer for data read (may be NULL)
 *
 * @return status register value
 */
uint8_t NRF24L01::readRegister(uint8_t regNum, unsigned dataSize, uint8_t data[]) {
   return readCommand(R_REGISTER|regNum, dataSize, data);
}

/**
 * Flush Tx Buffer
 *
 * @return status register value
 */
uint8_t  NRF24L01::flushTx(void) {
   return writeCommand(FLUSH_TX, 0, 0);
}

/**
 * Flush Rx Buffer
 *
 * @return status register value
 */
uint8_t  NRF24L01::flushRx(void) {
   return writeCommand(FLUSH_RX, 0, 0);
}

/**
 * Transmit packet
 *
 * @param dataSize - Size of packet in bytes (should match what Rx pipe is expecting)
 * @param data     - Data to Tx
 *
 * @return status register value
 */
uint8_t NRF24L01::transmitData(unsigned dataSize, uint8_t data[]) {
   uint8_t status = writeCommand(W_TX_PAYLOAD, dataSize, data);
   setCE(true);
   waitUS(10);
   setCE(false);
   return status;
}

/**
 * Receive packet
 *
 * @param dataSize - Size of packet in bytes (should match what Rx pipe is expecting)
 * @param data     - Data received
 *
 *
 * @return status register value
 */
uint8_t NRF24L01::receiveData(unsigned dataSize, uint8_t data[]) {
   setCE(false);
   uint8_t status = readRegister(R_RX_PAYLOAD, dataSize, data);
   setCE(true);
   return status;
}

/**
 * Write value to CONFIG register
 *
 * @param value - Value to write
 *
 * @return status register value
 */
uint8_t NRF24L01::writeConfig(uint8_t value) {
   return writeRegister(CONFIG_REG, 1, &value);
}

/**
 * Read value from CONFIG register
 *
 * @return Value from register
 */
uint8_t NRF24L01::readConfig() {
   uint8_t value;
   readRegister(CONFIG_REG, 1, &value);
   return value;
}

/**
 * Change configuration and power up device
 *
 * @param configValue value for NRF24L01 config register (see CONFIG_EN_CRC etc)
 *
 * This sets the PWR_UP bit in the CONFIG register if necessary
 * The CE is set active if RX mode is indicated by CONFIG_PRIM_RX bit
 */
void NRF24L01::powerUp(uint8_t configValue) {
   configValue |= CONFIG_PWR_UP;
   writeRegister(CONFIG_REG, 1, &configValue);
   waitMS(15);
   setCE((configValue&CONFIG_PRIM_RX) != 0);
}

/**
 * Power up device with the current configuration
 *
 * This sets the PWR_UP bit in the CONFIG register if necessary
 * The CE is set active if RX mode is indicated by CONFIG_PRIM_RX bit
 */
void NRF24L01::powerUp() {
   uint8_t configValue = readConfig();
   if ((configValue & CONFIG_PWR_UP) == 0) {
      powerUp(configValue);
   }
   setCE((configValue&CONFIG_PRIM_RX) != 0);
}

/**
 * Power down device
 *
 * This clears the PWR_UP bit in the CONFIG register (if necessary)
 */
void NRF24L01::powerDown(void) {
   uint8_t configValue = readConfig();
   if ((configValue & CONFIG_PWR_UP) != 0) {
      configValue &= ~CONFIG_PWR_UP;
      writeRegister(CONFIG_REG, 1, &configValue);
   }
}

} // End namespace USBDM


