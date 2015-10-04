/*
 * Seed_SLD00200P.h
 *
 * Pin mapping for Seeed Studio ePaper interface
 *
 *  Created on: 8 Aug 2014
 *      Author: podonoghue
 */

#ifndef SEEED_SLD00200P_H_
#define SEEED_SLD00200P_H_

/*!
 * Mappings from Arduino pins to Seeed studio e-Paper shield
 */
#define EPD_Pin_BUSY       digitalIO_D7   // Busy flag from EPD
#define EPD_Pin_RESET      digitalIO_D6   // Reset to EPD
#define EPD_Pin_DISCHARGE  digitalIO_D8   // Discharge to EPD
#define EPD_Pin_BORDER     digitalIO_D3   // Border to EPD
#define EPD_Pin_PANEL_ON   digitalIO_D2   // ON/OFF EPD Power
#define EPD_Pin_PWM        pwmIO_D5       // PWM to EPD

#define EPD_Pin_EPD_CS     digitalIO_D10  // EPD SPI CS*
#define SD_Pin_CS          digitalIO_D4   // SD SPI CS*
#define GT20L16_Pin_CS     digitalIO_D9   // GT20L16 SPI CS*

#define S8120CN_Pin_TEMP   analogueIO_A0  // Temperature sensor

// Larger display only
//#define OE123_Pin          digitalIO_A1
//#define CKV_Pin            digitalIO_A2
//#define STV_Pin            digitalIO_A3

#define TOGGLE digitalIO_A5

/*
 * Shared SPI signals (Modified Panel)
 *
 * D11 = MOSI
 * D12 = MISO
 * D13 = SCK
 */
#endif /* SEEED_SLD00200P_H_ */
