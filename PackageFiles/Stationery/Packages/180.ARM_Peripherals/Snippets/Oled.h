/*
 * Oled.h
 *
 *  Created on: 31 Oct 2019
 *      Author: podonoghue
 *
 *  Based loosely on Adafruit library (initialisation sequences and constants)
 */

#ifndef SOURCES_OLED_H_
#define SOURCES_OLED_H_

#include "fonts.h"
#include "i2c.h"
#include "formatted_io.h"

namespace USBDM {

enum OledVccControl : int8_t {
   OledVccControl_Internal = 0,
   OledVccControl_External = 1,
};

enum WriteMode {
   WriteMode_Write,
   WriteMode_InverseWrite,
   WriteMode_Or,
   WriteMode_InverseAnd,
   WriteMode_Xor,
};

enum SSD1306_Colours {
   SSD1306_BLACK              = 0,    ///< Draw 'off' pixels
   SSD1306_WHITE              = 1,    ///< Draw 'on' pixels
   SSD1306_INVERSE            = 2,    ///< Invert pixels
};

enum SSD1306_Commands : uint8_t {
   SSD1306_MEMORYMODE                            = 0x20, ///< See datasheet
   SSD1306_COLUMNADDR                            = 0x21, ///< See datasheet
   SSD1306_PAGEADDR                              = 0x22, ///< See datasheet
   SSD1306_SETCONTRAST                           = 0x81, ///< See datasheet
   SSD1306_CHARGEPUMP                            = 0x8D, ///< See datasheet
   SSD1306_SEGREMAP                              = 0xA0, ///< See datasheet
   SSD1306_DISPLAYALLON_RESUME                   = 0xA4, ///< See datasheet
   SSD1306_DISPLAYALLON                          = 0xA5, ///< Not currently used
   SSD1306_NORMALDISPLAY                         = 0xA6, ///< See datasheet
   SSD1306_INVERTDISPLAY                         = 0xA7, ///< See datasheet
   SSD1306_SETMULTIPLEX                          = 0xA8, ///< See datasheet
   SSD1306_DISPLAYOFF                            = 0xAE, ///< See datasheet
   SSD1306_DISPLAYON                             = 0xAF, ///< See datasheet
   SSD1306_COMSCANINC                            = 0xC0, ///< Not currently used
   SSD1306_COMSCANDEC                            = 0xC0, ///< See datasheet
   SSD1306_SETDISPLAYOFFSET                      = 0xD3, ///< See datasheet
   SSD1306_SETDISPLAYCLOCKDIV                    = 0xD5, ///< See datasheet
   SSD1306_SETPRECHARGE                          = 0xD9, ///< See datasheet
   SSD1306_SETCOMPINS                            = 0xDA, ///< See datasheet
   SSD1306_SETVCOMDETECT                         = 0xDB, ///< See datasheet

   SSD1306_SETLOWCOLUMN                          = 0x00, ///< Not currently used
   SSD1306_SETHIGHCOLUMN                         = 0x10, ///< Not currently used
   SSD1306_SETSTARTLINE                          = 0x40, ///< See datasheet

   SSD1306_RIGHT_HORIZONTAL_SCROLL               = 0x26, ///< Init rt scroll
   SSD1306_LEFT_HORIZONTAL_SCROLL                = 0x27, ///< Init left scroll
   SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL  = 0x29, ///< Init diag scroll
   SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL   = 0x2A, ///< Init diag scroll
   SSD1306_DEACTIVATE_SCROLL                     = 0x2E, ///< Stop scroll
   SSD1306_ACTIVATE_SCROLL                       = 0x2F, ///< Start scroll
   SSD1306_SET_VERTICAL_SCROLL_AREA              = 0xA3, ///< Set scroll range
};

class Oled : public USBDM::FormattedIO {

private:

   USBDM::Font *font = &USBDM::fontSmall;

   /**
    * Check if character is available
    *
    * @return true  Character available i.e. _readChar() will not block
    * @return false No character available
    */
   virtual bool _isCharAvailable() override {
      return false;
   }

   /**
    * Receives a character (blocking)
    *
    * @return Character received
    */
   virtual int _readChar() override {
      return -1;
   }

   /**
    * Write a character to the LCD in graphics mode at the current x,y location
    *
    * @param[in]  ch - character to send
    */
   virtual void _writeChar(char ch) override;

   /**
    *  Flush input data
    */
   virtual void flushInput() override {
   }

public:
   /**
    *  Flush output data
    */
   virtual void flushOutput() override {
      refreshImage();
   }

   // Address (LSB = R/W bit = 0)
   static constexpr unsigned   I2C_ADDRESS   = 0b01111000;
   static constexpr unsigned   I2C_SPEED     = 400*kHz;

   static const int            WIDTH         = 128;
   static const int            HEIGHT        =  32;
   static const OledVccControl VCC_CONTROL   = OledVccControl_Internal;

#pragma pack(push,1)
   /// Buffer type for display data
   /// This is prefixed by a command byte for transmission to OLED
   struct Buffer {
      uint8_t  controlByte;
      uint8_t  buffer[WIDTH * ((HEIGHT + 7) / 8)];
   };
#pragma pack(pop)

   /** I2C peripheral to use */
   I2c &i2c;

   /** Buffer for display data */
   Buffer buffer;

   /** Graphic mode X position */
   int x = 0;

   /** Graphic mode Y position */
   int y = 0;

   /** Graphic mode font height (for newline) */
   int fontHeight = 0;

   template<typename T> T max(T a, T b) {
         return (a>b)?a:b;
      }

public:
   Oled(USBDM::I2c &i2c) : i2c(i2c) {
      initialise();
   }

   /**
    * Write a custom character to the LCD in graphics mode at the current x,y location
    *
    * @param[in] image  Image describing the character
    * @param[in] width  Width of the image
    * @param[in] height Height of character
    */
   Oled &putCustomChar(const uint8_t *image, int width, int height) {
      writeImage(image, x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);
      return *this;
   }

   Oled &setFont(USBDM::Font &font) {
      this->font = &font;
      return *this;
   }

   void initialise();
   Oled &clearDisplay();
//   void executeCommand1(uint8_t c);
   void refreshImage();

   Oled &writeImage(const uint8_t *dataPtr, int x, int y, int width, int height, WriteMode writeMode=WriteMode_Write);
   Oled &putSpace(int width);
   void putPixel(unsigned index, uint8_t mask, bool pixel, WriteMode writeMode);
   void drawPixel(int x, int y, bool pixel, WriteMode writeMode=WriteMode_Write);
   void drawVerticalLine(int x, int y1, int y2, WriteMode writeMode=WriteMode_Write);
   void drawHorizontalLine(int x1, int x2, int y, WriteMode writeMode=WriteMode_Write);
   void drawRect(int x1, int y1, int x2, int y2, WriteMode writeMode=WriteMode_Write);

   Oled &moveXY(int x, int y) {
      this->x = x;
      this->y = y;
      return *this;
   }
};

} // namespace USBDM

#endif /* SOURCES_OLED_H_ */
