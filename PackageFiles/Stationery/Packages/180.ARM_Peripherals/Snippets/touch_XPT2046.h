/******************************************************************************
 * @file   touch_XPT2046.h (180.ARM_Peripherals/Snippets)
 * @brief  Driver for XPT2046 resistive touch interface
 * @author podonoghue
 *
 *  Created on: 5/10/2025
 *
 *  Requires declarations for the following in Configure.usbdmProject
 *
 *  TouchCs     XPT2046 CS as SPI Peripheral select e.g. PCS0 (D7)
 *  TouchIrq    XPT2046 IRQ as GPIO
 *
 *  Fixed SPI specific connections
 *  XPT2046 SIN     MOSI/SOUT - D11
 *  XPT2046 SOUT    MISO/SIN  - D12
 *  XPT2046 SCK     SCK       - D13
 *
 *  Power
 *  GND
 *  VCC
 ******************************************************************************/

#ifndef USBDM_TOUCH_XPT2046_H_
#define USBDM_TOUCH_XPT2046_H_
#include "hardware.h"
#include "spi.h"

namespace USBDM {

class TouchInterface {

protected:

   /* Touch SPI Signals (used for CS during transfers) */
   static constexpr SpiPeripheralSelect SpiPeripheralSelect_TouchCs = USBDM::SpiPeripheralSelect_TouchCs; // CS Active-low

   /* Touch GPIOs */
   using TouchIrq = USBDM::TouchIrq;    // Low=active

   // Communication settings
   static constexpr Spi0::SerialInit serialInitValue {
      2.5_MHz ,               // (speed[0])                 Speed of interface
      SpiMode_0 ,            // (spi_ctar_mode[0])         Mode - Mode 0: CPOL=0, CPHA=0
      SpiFrameSize_8_bits ,  // (spi_ctar_fmsz[0])         SPI Frame sizes - 8 bits/transfer
      SpiBitOrder_MsbFirst,  // (spi_ctar_lsbfe[0])        Transmission order - MSB sent first
   };

   /** SPI interface used to communicate with LCD */
   USBDM::Spi &spi;

   // SPI Configuration to send command bytes
   const Spi::SpiCalculatedConfiguration commandConfiguration;

public:
   TouchInterface(Spi &spi) :
      spi(spi),
      commandConfiguration(spi.calculateConfiguration(serialInitValue, SpiPeripheralSelect_TouchCs , SpiPeripheralSelectMode_Transaction)) {

      // Set CS polarities
      spi.setPcsPolarityActiveLow(SpiPeripheralSelect_TouchCs);
      // GPIOs
      static constexpr PcrInit pcrValue {
         PinPull_Up,
         PinAction_None,
         PinDriveStrength_Low,
         PinDriveMode_PushPull,
         PinFilter_None,
      };
      TouchIrq::setInput(pcrValue);
   }

   ~TouchInterface() = default;

   /**
    * Send a command to display
    *
    * @param Command  Command value
    */
   void sendCommand(uint8_t Command) {

      spi.startTransaction(commandConfiguration);
      spi.txRxFinal(Command);
      spi.endTransaction();
   }

   /*
    * PD1 PD0  PENIRQ
    *  0   0   Enabled  Power-Down Between Conversions. When each conversion is finished, the converter
    *                   enters a low-power mode. At the start of the next conversion, the device instantly
    *                   powers up to full power. There is no need for additional delays to ensure full operation,
    *                   and the very first conversion is valid. The Y− switch is on when in power-down.
    *  0   1   Disabled Reference is off and ADC is on.
    *  1   0   Enabled  Reference is on and ADC is off.
    *  1   1   Disabled Device is always powered. Reference is on and ADC is on.
    */

   enum Power {

      Start     = 0b1'000'0'0'00,

      Address_Y            = 0b0'001'0'0'00,
      Address_Z1           = 0b0'011'0'0'00,
      Address_Z2           = 0b0'100'0'0'00,
      Address_X            = 0b0'101'0'0'00,

      Mode_12Bits          = 0b0'000'0'0'00,  ///< 12-bit conversions
      Mode_8Bits           = 0b0'000'1'0'00,  ///< 8-bit conversions

      Conversion_Diff      = 0b0'000'0'0'00,
      Conversion_Single    = 0b0'000'0'1'00,

      Power_MinPower_Irq   = 0b0'000'0'0'00,
      Power_AdcOnly        = 0b0'000'0'0'01,
      Power_RefOnly_Irq    = 0b0'000'0'0'10,
      Power_FullPower      = 0b0'000'0'0'11,
   };

   /*          SPP
    *    S AAA  /DD
    *      210 MD10
    * B1 1'011'0001 START+A3+M0+DIFF+PD1
    * C1 1'100'0001 START+A4+M0+DIFF+PD1
    * D1 1'101'0001 START+A5+M0+DIFF+PD1
    * 91 1'001'0001 START+A1+M0+DIFF+PD1
    * D0 1'101'0001 START+A5+M0+DIFF+PD1
    */
   static constexpr uint8_t Z1      = Start|Address_Z1|Conversion_Diff|Mode_12Bits|Power_FullPower;      // 0b1'011'0'0'01 = B1
   static constexpr uint8_t Z2      = Start|Address_Z2|Conversion_Diff|Mode_12Bits|Power_FullPower;      // 0b1'100'0'0'01 = C1
   static constexpr uint8_t X       = Start|Address_X |Conversion_Diff|Mode_12Bits|Power_FullPower;      // 0b1'101'0'0'01 = D1
   static constexpr uint8_t Y       = Start|Address_Y |Conversion_Diff|Mode_12Bits|Power_FullPower;      // 0b1'001'0'0'01 = 91
   static constexpr uint8_t Last    = Start|Power_MinPower_Irq;                                          // 0b1'000'0'0'00 = 80

   static constexpr unsigned Z_THRESHOLD = 300;

   /**
    * Scale raw X measurements to pixels
    *
    * @param rawX Original X value
    *
    * @return scaled X value
    */
   static constexpr unsigned scaleX(unsigned rawX) {

      constexpr unsigned xMax   = 3910;
      constexpr unsigned xWidth = 320;

      return (rawX*xWidth)/xMax;
   }

   /**
    * Scale raw Y measurements to pixels
    *
    * @param rawY Original Y value
    *
    * @return scaled Y value
    */
   static constexpr unsigned scaleY(unsigned rawY) {

      constexpr unsigned yMax   = 3934;
      constexpr unsigned yWidth = 480;

      return (rawY*yWidth)/yMax;
   }


   bool checkTouch(unsigned &x, unsigned &y) {

      static constexpr IntegerFormat decimalFormat(Padding_LeadingSpaces, Width_6, Radix_10);
      static constexpr IntegerFormat hex2Format(Padding_LeadingZeroes, Width_2, Radix_16);
      static constexpr IntegerFormat hex4Format(Padding_LeadingZeroes, Width_2, Radix_16);

      // Initiates a conversion every 16 bits - This starts 3 conversions but only gets the results for first 2
      // X is left 'hanging'
      static const uint8_t txData1[] = {Z1,0, Z2,0, X };
      uint8_t rxData1[sizeof(txData1)];

      spi.startTransaction(commandConfiguration);
      spi.txRx(txData1, rxData1, false);

      unsigned z1 = uint16_t((rxData1[1]<<8u)|rxData1[2])>>3;
      unsigned z2 = uint16_t((rxData1[3]<<8u)|rxData1[4])>>3;
      unsigned z = 4095 + z1 - z2;

      uint16_t xResults[4];
      uint16_t yResults[4];
      uint16_t xResult;
      uint16_t yResult;

      // Completes previous sequence
      static const uint8_t txData2[] = { /* X, */ 0, X,0, X,0, X,0, Y,0, Y,0, Y,0, Y,0, Last, };
      uint8_t rxData2[sizeof(txData2)];

      if (z>Z_THRESHOLD) {

         spi.txRx(txData2, rxData2);
         spi.endTransaction();

         xResults[0] = uint16_t((rxData2[0]<<8u)|rxData2[1])>>3;    // X0
         xResults[1] = uint16_t((rxData2[2]<<8u)|rxData2[3])>>3;    // Y0
         xResults[2] = uint16_t((rxData2[4]<<8u)|rxData2[5])>>3;    // X1
         xResults[3] = uint16_t((rxData2[6]<<8u)|rxData2[7])>>3;    // Y1
         yResults[0] = uint16_t((rxData2[8]<<8u)|rxData2[9])>>3;    // X2
         yResults[1] = uint16_t((rxData2[10]<<8u)|rxData2[11])>>3;  // Y2
         yResults[2] = uint16_t((rxData2[12]<<8u)|rxData2[13])>>3;  // X3
         yResults[3] = uint16_t((rxData2[14]<<8u)|rxData2[15])>>3;  // Y3

         xResult = scaleX((xResults[0]+xResults[1]+xResults[2]+xResults[3])>>2);
         yResult = scaleY((yResults[0]+yResults[1]+yResults[2]+yResults[3])>>2);
      }
      else {
         // Completes previous sequence (discards X value)
         spi.txRxFinal(Last);
         spi.endTransaction();
      }
      //   console.setFormat(decimalFormat);
      //   console.writeln("                                 z1 = ", z1, ", z2=", z2, ", z=", z);

      if (z>Z_THRESHOLD) {
         //      console.setFormat(hex2Format);
         //      console.writeArray(rxData2, Radix_16).writeln();
         //
         //      console.setFormat(hex4Format);
         //      console.writeArray(xResults, Radix_16).writeln(" x=", xResult);
         //      console.writeArray(yResults, Radix_16).writeln(" y=", yResult);
//         console.setFormat(decimalFormat);
//         console.writeln("X = ", xResult, ", Y = ", yResult);

         x = xResult;
         y = yResult;

         return true;
      }
      return false;
   }

};

} // namespace USBDM

#endif /* USBDM_TOUCH_XPT2046_H_ */
