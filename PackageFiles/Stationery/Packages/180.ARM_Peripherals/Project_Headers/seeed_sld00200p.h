/*
 * @file seed_sld00200p.h
 *
 * Pin mapping for Seeed Studio ePaper interface
 *
 *  Created on: 8 Aug 2014
 *      Author: podonoghue
 */

#ifndef SEEED_SLD00200P_H_
#define SEEED_SLD00200P_H_

#include <gpio.h>
/*!
 * Mappings from Arduino pins to Seeed studio e-Paper shield
 */
using EPD_Pin_BUSY       = USBDM::gpio_D7;   //!< Busy flag from EPD
using EPD_Pin_RESETn     = USBDM::gpio_D6;   //!< Reset to EPD
using EPD_Pin_DISCHARGE  = USBDM::gpio_D8;   //!< Discharge to EPD
using EPD_Pin_BORDER     = USBDM::gpio_D3;   //!< Border to EPD
using EPD_Pin_PANEL_ON   = USBDM::gpio_D2;   //!< ON/OFF EPD Power
using EPD_Pin_PWM        = USBDM::ftm_D5;    //!< PWM to EPD

using EPD_Pin_EPD_CSn    = USBDM::gpio_D10;  //!< EPD SPI CS*
using SD_Pin_CSn         = USBDM::gpio_D4;   //!< SD SPI CS*
using GT20L16_Pin_CSn    = USBDM::gpio_D9;   //!< GT20L16 SPI CS*

using S8120CN_Pin_TEMP   = USBDM::adc_A0;    //!< Temperature sensor

// Larger display only
//using OE123_Pin          = USBDM::gpio_A1;
//using CKV_Pin            = USBDM::gpio_A2;
//using STV_Pin            = USBDM::gpio_A3;

//using TOGGLE = USBDM::gpio_A5;

/*
 * Shared SPI signals (Modified Panel)
 *
 * D11 = MOSI
 * D12 = MISO
 * D13 = SCK
 */
#endif /* SEEED_SLD00200P_H_ */
