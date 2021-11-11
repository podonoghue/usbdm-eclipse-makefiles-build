/*
 * @file    ht16k33_14_SegmentDisplay.h (180.ARM_Peripherals/Snippets/)
 * @brief   Interface for a 14-segment display
 *
 *  Created on: 29Sep.,2017
 *      Author: podonoghue
 */

#ifndef SOURCES_HT16K33_14_SEGMENTDISPLAY_H_
#define SOURCES_HT16K33_14_SEGMENTDISPLAY_H_

#include "hardware.h"
#include "i2c.h"
#include "formatted_io.h"

namespace USBDM {

class HT16k33_14_SegmentDisplay : public FormattedIO {

private:
   // I2C address
   static constexpr uint8_t ADDRESS = 0xE0;

   // I2C interface
   I2c *i2c;

   // Character position in display
   unsigned position = 0;

   // Structure to represent data for transmission to display
   struct Displaydata {
      uint8_t   fill;
      uint8_t   command;
      uint16_t  data[4];
   };

   // Data for transmission to display
   Displaydata displayData __attribute__((packed));

   /**
    * Set command to interface
    *
    * @param[in] command Command to send
    */
   void sendCommand(uint8_t command) {
      i2c->startTransaction();
      i2c->transmit(ADDRESS, sizeof(command), &command);
      i2c->endTransaction();
   }

   /**
    * Send display data from internal buffer to display
    */
   void sendDisplayData();

   /**
    * Initialise HT16K33
    */
   void setup();

   /**
    * Clear internal buffer\n
    * Display is unchanged
    */
   void clear() {
      memset(&displayData, 0, sizeof(displayData));
      position = 0;
   }

   /**
    * Writes a character (blocking)
    *
    * @param[in]  ch - character to send
    */
   virtual void _writeChar(char ch) override ;

   /**
    * Receives a character (blocking)
    *
    * @return Character received
    */
   virtual int _readChar() override { return -1; };

public:
   /**
    * Controls blink rate of display
    */
   enum BlinkRate {
      BlinkRate_off     = 0b000,  // Blinking off
      BlinkRate_2_Hz    = 0b010,  // 2 Hz
      BlinkRate_1_Hz    = 0b100,  // 1 Hz
      BlinkRate_500_mHz = 0b110,  // 0.5 Hz
   };

   enum IntPinFunction {
      IntPinFunction_Driver         = 0b00, // INT/ROW pin is ROW driver
      IntPinFunction_Interrupt_Low  = 0b01, // INT/ROW pin is active-low interrupt
      IntPinFunction_Interrupt_High = 0b11, // INT/ROW pin is active-high interrupt
   };

   /**
    * Display on/off
    */
   enum DisplayEnable {
      DisplayEnable_off = 0b0,//!< Display on
      DisplayEnable_on  = 0b1,//!< Display off
   };

   /**
    * Construct interface to 14-segment display using HT16K33 over I2C
    * e.g. Adafruit backpack
    *
    * @param[in] i2c
    */
   HT16k33_14_SegmentDisplay(I2c *i2c) : i2c(i2c) {
      clear();
      setup();
      setPadding(Padding_LeadingZeroes);
      setWidth(4);
   }

   /**
    * Set programmable Row driver/Interrupt pin function
    *
    * @param[in] intPinFunction Function for pin
    */
   void setPinFunction(IntPinFunction intPinFunction) {
      sendCommand(0b10100000|intPinFunction);
   }

   /**
    * Wake up display
    */
   void wakeup() {
      sendCommand(0b00100001);
   }

   /**
    * Set display to standby
    */
   void standby() {
      sendCommand(0b00100000);
   }

   /**
    * Set display brightness
    *
    * @param[in] brightness Value in range 0 - 15
    */
   void setBrightness(uint8_t brightness) {
      sendCommand(0xE0|(brightness&0xF));
   }

   /**
    * Set display features
    *
    * @param[in] on         Display on/off
    * @param[in] blinkRate  Blink rate
    */
   void setDisplay(DisplayEnable displayEnable, BlinkRate blinkRate) {
      sendCommand(0x80|blinkRate|displayEnable);
   }

   /**
    * Check if character is available
    *
    * @return true  Character available i.e. _readChar() will not block
    * @return false No character available
    */
   virtual bool _isCharAvailable() override { return false; };

   /**
    *  Flush output data
    */
   virtual HT16k33_14_SegmentDisplay &flushOutput() override { return *this; };

   /**
    *  Flush input data
    */
   virtual HT16k33_14_SegmentDisplay &flushInput() override { return *this; };
};

}  // namespace USBDM

#endif /* SOURCES_HT16K33_14_SEGMENTDISPLAY_H_ */
