/**
 * @file lcd_st7920.h
 *
 *  Created on: 18 Sep 2016
 *      Author: podonoghue
 */

#ifndef SOURCES_LCD_ST7920_H_
#define SOURCES_LCD_ST7920_H_

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "fonts.h"
#include "hardware.h"
#include "spi.h"
#include "delay.h"

/**
 * Class representing an LCD connected over SPI
 */
class LCD_ST7920 {

protected:
   constexpr static USBDM::Font &font = USBDM::smallFont;

public:
   /** Width of LCD in pixels */
   static constexpr int LCD_WIDTH  = 128;
   /** Height of LCD in pixels */
   static constexpr int LCD_HEIGHT = 64;
   /** Width of default font in pixels */
   static constexpr int FONT_WIDTH = 6;
   /** Height of default font in pixels */
   static constexpr int FONT_HEIGHT = 8;
   /** Command execution time for LCD */
   static constexpr int EXECUTE_TIME_US = 75;
   /** Command execution time for LCD */
   static constexpr int CLEAR_TIME_US = 1600;

protected:
   /** SPI Configuration */
   USBDM::SpiConfig spiConfig;

   /** SPI used for LCD */
   USBDM::Spi &spi;

   const USBDM::SpiPeripheralSelect pinNum;

   /** Graphic mode X position */
   int x=0;

   /** Graphic mode Y position */
   int y=0;

   /** Graphic mode font height (for newline) */
   int fontHeight=0;

   /** Inverts writes to the LCD screen */
   uint8_t invertMask = 0;

   /** Frame buffer for graphics mode */
   uint8_t frameBuffer[(LCD_WIDTH*LCD_HEIGHT)/8];

   template<typename T> T max(T a, T b) {
      return (a>b)?a:b;
   }

   /**
    * Write command to LCD
    *
    * @param[in] value Command value to write
    */
   void writeCommand(uint8_t value);

   /**
    * Write data value to LCD
    *
    * @param[in] value Data value to write
    */
   void writeData(uint8_t value);


public:
   /**
    * Initialise the LCD
    */
   void initialise();

   /**
    * Constructor
    *
    * @param[in] spi     The SPI to use to communicate with LCD
    * @param[in] pinNum  SPI_PCSx to use
    */
   LCD_ST7920(USBDM::Spi &spi, USBDM::SpiPeripheralSelect pinNum) : spi(spi), pinNum(pinNum) {
      initialise();
   }

   /**
    * Clear text screen
    */
   void clear();

   /**
    * Display text string using default LCD font
    *
    * @param[in] row Row on display (0..3)
    * @param[in] str String to display (up to 16 characters)
    */
   void displayString(uint8_t row, const char* str);

   /**
    * Switches the LCD to text mode
    */
   void setTextMode();

   /**
    * Switches the LCD to graphics mode
    */
   void setGraphicMode();

   /**
    * Clear frame buffer
    */
   void clearFrameBuffer();

   /**
    * Refreshes LCD from frame buffer
    */
   void refreshImage();

   /**
    * Write image to frame buffer
    *
    * @param[in] dataPtr Pointer to start of image
    * @param[in] x       X position of top-left corner
    * @param[in] y       Y position of top-left corner
    * @param[in] width   Width of image
    * @param[in] height  Height of image
    */
   void writeImage(const uint8_t *dataPtr, int x, int y, int width, int height);

   /**
    * Set inversion of images etc
    *
    * @param[in] enable True to invert writes, false to not invert
    */
   void setInversion(bool enable=true) {
      invertMask = enable?0xFF:0x00;
   }

   /**
    * Write full screen image to LCD
    *
    * @param[in] image The Image to write (must be 128x64 pixels i.e. 16x64 bytes)
    */
   void writeImage(const uint8_t *image) {
      writeImage(image, 0, 0, 128, 64);
   }

   /**
    * Write a custom character to the LCD in graphics mode at the current x,y location
    *
    * @param[in] image  Image describing the character
    * @param[in] width  Width of the image
    * @param[in] height Height of character
    */
   void putCustomChar(const uint8_t *image, int width, int height) {
      writeImage(image, x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);
   }

   /**
    * Write a character to the LCD in graphics mode at the current x,y location
    *
    * @param[in] ch The character to write
    */
   void __attribute__((noinline)) putChar(uint8_t ch);

   /**
    * Writes whitespace to the LCD in graphics mode at the current x,y location
    *
    * @param[in] width Width of white space in pixels
    */
   void putSpace(int width);

   /**
    * Write an Up arrow to the LCD in graphics mode at the current x,y location
    */
   void putUpArrow() {
      static const uint8_t upArrow[]   = {0x00,0x10,0x38,0x54,0x10,0x10,0x10,0x00,0x00};
      putCustomChar(upArrow, 6, 8);
   }

   /**
    * Write a Down arrow to the LCD in graphics mode at the current x,y location
    */
   void putDownArrow() {
      static const uint8_t downArrow[] = {0x00,0x10,0x10,0x10,0x54,0x38,0x10,0x00,0x00};
      putCustomChar(downArrow, 6, 8);
   }

   /**
    * Write a Left arrow to the LCD in graphics mode at the current x,y location
    */
   void putLeftArrow() {
      static const uint8_t leftArrow[]   = {0x00,0x10,0x20,0x7E,0x20,0x10,0x00,0x00,0x00};
      putCustomChar(leftArrow, 7, 8);
   }

   /**
    * Write an Right arrow to the LCD in graphics mode at the current x,y location
    */
   void putRightArrow() {
      static const uint8_t rightArrow[] = {0x00,0x08,0x04,0x7E,0x04,0x08,0x00,0x00,0x00};
      putCustomChar(rightArrow, 7, 8);
   }

   /**
    * Write an Enter symbol to the LCD in graphics mode at the current x,y location
    */
   void putEnter() {
      static const uint8_t enter[] = {0x00,0x02,0x12,0x22,0x7E,0x20,0x10,0x00,0x00};
      putCustomChar(enter, 7, 8);
   }

   /**
    * Write a string to the LCD in graphics mode at the current x,y location
    *
    * @param[in] str The string to write
    */
   void putString(const char *str);

   /**
    * Set the current X,Y location for graphics mode
    *
    * @param[in] x
    * @param[in] y
    */
   void gotoXY(int x, int y) {
      this->x = x;
      this->y = y;
      fontHeight = 0;
   }

   /**
    * Get the current X,Y location for graphics mode
    *
    * @param[out] x
    * @param[out] y
    */
   void getXY(int &x, int &y) {
      x = this->x;
      y = this->y;
   }

   /**
    * Write a small digit to the LCD in graphics mode at the current x,y location
    *
    * @param[in] value Digit to write (0-9)
    */
   void putSmallDigit(int value) {
      // Small digit font
      static const uint8_t smallNumberFont[10][6] = {
            {0x30,0x48,0x48,0x48,0x30,0x00},
            {0x10,0x30,0x10,0x10,0x38,0x00},
            {0x30,0x48,0x10,0x20,0x78,0x00},
            {0x30,0x48,0x10,0x48,0x30,0x00},
            {0x10,0x30,0x50,0x78,0x10,0x00},
            {0x70,0x40,0x70,0x10,0x60,0x00},
            {0x10,0x20,0x50,0x48,0x30,0x00},
            {0x70,0x10,0x20,0x20,0x20,0x00},
            {0x30,0x48,0x30,0x48,0x30,0x00},
            {0x30,0x48,0x30,0x08,0x30,0x00},
      };
      putCustomChar(smallNumberFont[value], 5, 6);
   }

   /**
    * Draw vertical line
    *
    * @param[in] x  Horizontal position in pixels
    * @param[in] y1 Vertical start position in pixels
    * @param[in] y2 Vertical end position in pixels
    */
   void drawVerticalLine(int x, int y1=0, int y2=LCD_HEIGHT-1);

   /**
    * Draw horizontal line
    *
    * @param[in] y Vertical position in pixels
    */
   void drawHorizontalLine(int y);

   /**
    * Draw pixel
    *
    * @param[in] x Horizontal position in pixel
    * @param[in] y Vertical position in pixel
    */
   void drawPixel(int x, int y);

   /**
    * Printf style formatted print\n
    * The string is printed to the screen at the current x,y location
    *
    * @param[in] format Format control string (as for printf())
    * @param[in] ...    Arguments to print
    *
    * @return numbers of chars printed?
    *
    * @note Limited to 21 characters ~ 1 line
    */
   int printf(const char *format, ...) __attribute__ ((format (printf, 2, 3)));
};

#endif /* SOURCES_LCD_ST7920_H_ */
