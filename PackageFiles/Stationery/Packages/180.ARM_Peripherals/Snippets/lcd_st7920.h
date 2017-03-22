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
 *
 * @tparam pinNum Pin number for PCSn signal
 */
class LCD_ST7920 {

public:
   /** Width of LCD in pixels */
   static constexpr int LCD_WIDTH  = 128;
   /** Height of LCD in pixels */
   static constexpr int LCD_HEIGHT = 64;
   /** Width of default font in pixels */
   static constexpr int FONT_WIDTH = 6;
   /** Height of default font in pixels */
   static constexpr int FONT_HEIGHT = 8;

protected:
   /** SPI CTAR value */
   uint32_t spiCtarValue = 0;

   /** SPI used for LCD */
   USBDM::Spi &spi;

   const int pinNum;

   /** Graphic mode X position */
   int x=0;

   /** Graphic mode Y position */
   int y=0;

   /** Graphic mode font height (for newline) */
   int fontHeight=0;

   /** Inverts writes to the LCD screen */
   uint8_t invertMask = 0;

protected:
   /** Frame buffer for graphics mode */
   uint8_t frameBuffer[(LCD_WIDTH*LCD_HEIGHT)/8];

   template<typename T> T max(T a, T b) {
      return (a>b)?a:b;
   }

   /**
    * Write command to LCD
    *
    * @param value Command value to write
    */
   void writeCommand(uint8_t value) {
      uint8_t data[] = {
            0xF8,
            (uint8_t)(value&0xF0),
            (uint8_t)(value<<4),
      };
      {
         IrqProtect protect;
         spi.setCTAR0Value(spiCtarValue);
         spi.setPushrValue(SPI_PUSHR_CTAS(0)|SPI_PUSHR_PCS(1<<pinNum));
         spi.txRxBytes(sizeof(data), data, nullptr);
      }
      USBDM::waitUS(100);
   }

   /**
    * Write data value to LCD
    *
    * @param value Data value to write
    */
   void writeData(uint8_t value) {
      uint8_t data[] = {
            0xFA,
            (uint8_t)(value&0xF0),
            (uint8_t)(value<<4),
      };
      {
         IrqProtect protect;
         spi.setCTAR0Value(spiCtarValue);
         spi.setPushrValue(SPI_PUSHR_CTAS(0)|SPI_PUSHR_PCS(1<<pinNum));
         spi.txRxBytes(sizeof(data), data, nullptr);
      }
      USBDM::waitUS(100);
   }


public:
   /**
    * Initialise the LCD
    */
   void initialise() {
      USBDM::waitMS(200);
      {
         IrqProtect protect;
         spi.setPcsPolarity(pinNum, false);
         spi.setSpeed(5000000);
         spi.setMode(USBDM::SPI_MODE3);
         spi.setDelays(0.5*USBDM::us, 0.5*USBDM::us, 0.5*USBDM::us);
         spi.setFrameSize(8);

         // Record CTAR value in case SPI shared
         spiCtarValue = spi.getCTAR0Value();
      }
      writeCommand(0b00111000); // Function set(DL=1, RE=0)
      writeCommand(0b00001100); // On/Off(D=1 C=0, B=0)
      writeCommand(0b00000110); // EntryMode(I/D=1,S=0)

      clear();
   }

   /**
    * Constructor
    *
    * @param spi     The SPI to use to communicate with LCD
    * @param pinNum  Number of PCS to use
    */
   LCD_ST7920(USBDM::Spi &spi, int pinNum) : spi(spi), pinNum(pinNum) {
//      initialise();
   }

   /**
    * Clear text screen
    */
   void clear() {
      setTextMode();
      writeCommand(0b00110000); // Basic instruction mode
      writeCommand(0b00000010); // Home
      writeCommand(0b00000001); // Clear
      USBDM::waitMS(2);
   }

   /**
    * Display text string using default LCD font
    *
    * @param row Row on display (0..3)
    * @param str String to display (up to 16 characters)
    */
   void displayString(uint8_t row, const char* str) {
      uint8_t addr;
      switch (row) {
      case 0: addr = 0x80; break;
      case 1: addr = 0x90; break;
      case 2: addr = 0x88; break;
      case 3: addr = 0x98; break;
      }
      // Set Basic instructions
      writeCommand(0b110000);
      // Set address
      writeCommand(addr);

      for(int i=0; i<16; i++) {
         if (*str == '\0') {
            break;
         }
         writeData(*str++);
      }
   }

   /**
    * Switches the LCD to text mode
    */
   void setTextMode() {
      // Set Extended instructions
      writeCommand(0b110100);
      // Set Graphic off
      writeCommand(0b110100);
      // Set Basic instructions
      writeCommand(0b110000);
   }

   /**
    * Switches the LCD to graphics mode
    */
   void setGraphicMode() {
      // Set Extended instructions
      writeCommand(0b110100);
      // Set Graphic on
      writeCommand(0b110110);
      // Set Basic instructions
      writeCommand(0b110000);
   }

   /**
    * Clear frame buffer
    *
    */
   void clearFrameBuffer() {
      memset(frameBuffer, invertMask, sizeof(frameBuffer));
      x          = 0;
      y          = 0;
      fontHeight = 0;
   }
   /**
    * Refreshes LCD from frame buffer
    */
   void refreshImage() {
      // Set Extended instructions
      writeCommand(0b110110);

      // Copy image from buffer to LCD
      const uint8_t *bufPtr = frameBuffer;
      for (int row=0; row<32; row++) {
         // Start of internal row
         writeCommand(0b10000000+row); // Vertical AC5..AC0 = N
         writeCommand(0b10000000);     // Horizontal AC3..AC0 = 0 => start of row
         for (int col=0; col<16; col++) {
            writeData(*bufPtr++);
         }
      }
      for (int row=0; row<32; row++) {
         // Start of internal row
         writeCommand(0b10000000+row); // Vertical AC5..AC0 = N
         writeCommand(0b10000000+8);   // Horizontal AC3..AC0 = 0 => start of row
         for (int col=0; col<16; col++) {
            writeData(*bufPtr++);
         }
      }
      // Set Basic instructions
      writeCommand(0b110000);
   }

   /**
    * Write image to frame buffer
    *
    * @param dataPtr Pointer to start of image
    * @param x       X position of top-left corner
    * @param y       Y position of top-left corner
    * @param width   Width of image
    * @param height  Height of image
    */
   void writeImage(const uint8_t *dataPtr, int x, int y, int width, int height) {
      if ((x<0)||(y<0)) {
         // Doesn't support negative clipping
         return;
      }
      if ((x>=LCD_WIDTH)||(y>=LCD_HEIGHT)) {
         // Entirely off screen
         return;
      }
      if ((x+width) > LCD_WIDTH) {
         // Clip on right
         width = LCD_WIDTH-x;
      }
      if ((y+height) > LCD_HEIGHT) {
         // Clip at bottom
         height = LCD_HEIGHT-y;
      }
      int offset          = x&0x07;
      int offsetPlusWidth = ((x+width-1)&0x07)+1;
      int startMask = (uint8_t)(0xFF>>offset);
      int endMask   = (uint8_t)(0xFF00>>offsetPlusWidth);
      //      printf("x=[%d..%d], y=%d, w=%d, sm=0x%02X, em=0x%02X\n", x, x+width-1, y, width, startMask, endMask); fflush(stdout);

      for (int yy=y; yy<y+height; yy++) {
         int     xx       = (yy*LCD_WIDTH)+x;
         int     ww       = width;
         int     mask     = startMask;
         const uint8_t *dataByte = dataPtr;
         int     data     = *dataByte++^invertMask;
         if ((ww+offset)>8) {
            //            printf("+m=0x%02X\n", mask);
            ww -= 8-(offset&0x07);
            frameBuffer[xx/8] = (frameBuffer[xx/8]&~mask)|((data>>offset)&mask);
            mask = 0xFF;
            data = (data<<8)|(*dataByte++^invertMask);
            xx += 8-(offset&0x07);
         }
         while (ww>8) {
            //            printf("=m=0x%02X\n", mask);
            ww -= 8;
            frameBuffer[xx/8] = (uint8_t)(data>>offset);
            data = (data<<8)|(*dataByte++^invertMask);
            xx += 8;
         }
         mask &= endMask;
         //         printf("-m=0x%02X\n", mask);
         frameBuffer[xx/8] = (frameBuffer[xx/8]&~mask)|((data>>offset)&mask);
         dataPtr += (width+7)/8;
      }
      //      refreshImage(); // Debug only
   }

   /**
    * Set inversion of images etc
    *
    * @param enable True to invert writes, false to not invert
    */
   void setInversion(bool enable=true) {
      if (enable) {
         invertMask = 0xFF;
      }
      else {
         invertMask = 0x00;
      }
   }

   /**
    * Write full screen image to LCD
    *
    * @param image The Image to write (must be 128x64 pixels i.e. 16x64 bytes)
    */
   void writeImage(const uint8_t *image) {
      writeImage(image, 0, 0, 128, 64);
   }

   /**
    * Write a custom character to the LCD in graphics mode at the current x,y location
    *
    * @param image  Image describing the character
    * @param width  Width of the image
    * @param height Height of character
    */
   void putCustomChar(const uint8_t *image, int width, int height) {
      writeImage(image, x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);
   }

   /**
    * Write a character to the LCD in graphics mode at the current x,y location
    *
    * @param ch The character to write
    */
   void putChar(uint8_t ch) {
      int width  = USBDM::Fonts::FONT6x8[0][0];
      int height = USBDM::Fonts::FONT6x8[0][1];
      if (ch == '\n') {
         putSpace(LCD_WIDTH-x);
         x  = 0;
         y += fontHeight;
         fontHeight = 0;
      }
      else {
         if ((x+width)>LCD_WIDTH) {
            // Don't display partial characters
            return;
         }
         writeImage((uint8_t*)(USBDM::Fonts::FONT6x8[ch-0x20+1]), x, y, width, height);
         x += width;
         fontHeight = max(fontHeight, height);
      }
   }

   /**
    * Writes whitespace to the LCD in graphics mode at the current x,y location
    *
    * @param width Width of white space in pixels
    */
   void putSpace(int width) {
      static const uint8_t space[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
      while (width>0) {
         int t = 8;
         if (t>width) {
            t = width;
         }
         width -= t;
         putCustomChar(space, t, 8);
      }
   }

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
    * @param str The string to write
    */
   void putString(const char *str) {
      while (*str != '\0') {
         putChar(*str++);
      }
   }

   /**
    * Set the current X,Y location for graphics mode
    *
    * @param x
    * @param y
    */
   void gotoXY(int x, int y) {
      this->x = x;
      this->y = y;
      fontHeight = 0;
   }

   /**
    * Get the current X,Y location for graphics mode
    *
    * @param x
    * @param y
    */
   void getXY(int &x, int &y) {
      x = this->x;
      y = this->y;
   }

   /**
    * Write a small digit to the LCD in graphics mode at the current x,y location
    *
    * @param value Digit to write (0-9)
    */
   void putSmallDigit(int value) {
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
    * @param x  Horizontal position in pixels
    * @param y1 Vertical start position in pixels
    * @param y2 Vertical end position in pixels
    */
   void drawVerticalLine(int x, int y1=0, int y2=LCD_HEIGHT-1) {
      if ((x<0)||(x>=LCD_WIDTH)) {
         // Off screen
         return;
      }
      uint8_t mask = 0x80>>(x&7);
      int    offset = x>>3;
      for (int yy=y1*(LCD_WIDTH/8); yy<=y2*(LCD_WIDTH/8); yy+=(LCD_WIDTH/8)) {
         if (invertMask) {
            frameBuffer[yy+offset] &= ~mask;
         }
         else {
            frameBuffer[yy+offset] |= mask;
         }
      }
   }

   /**
    * Draw horizontal line
    *
    * @param y Vertical position in pixels
    */
   void drawHorizontalLine(int y) {
      if ((y<0)||(y>=LCD_HEIGHT)) {
         // Off screen
         return;
      }
      uint8_t mask = invertMask?0x00:0xFF;
      for (int xx=0; xx<(LCD_WIDTH/8); xx++) {
         frameBuffer[(y*(LCD_WIDTH/8))+xx] = mask;
      }
   }

   /**
    * Draw pixel
    *
    * @param x Horizontal position in pixel
    * @param y Vertical position in pixel
    */
   void drawPixel(int x, int y) {
      if ((x<0)||(x>=LCD_WIDTH)) {
         // Off screen
         return;
      }
      if ((y<0)||(y>=LCD_HEIGHT)) {
         // Off screen
         return;
      }
      uint8_t mask    = 0x80>>(x&7);
      int     hOffset = x>>3;
      if (invertMask) {
         frameBuffer[(y*(LCD_WIDTH/8))+hOffset] &= ~mask;
      }
      else {
         frameBuffer[(y*(LCD_WIDTH/8))+hOffset] |= mask;
      }
   }

   /**
    * Printf style formatted print\n
    * The string is printed to the screen at the current x,y location
    *
    * @param format Format control string (as for printf())
    * @param ...    Arguments to print
    *
    * @return numbers of chars printed?
    *
    * @note Limited to 21 characters ~ 1 line
    */
   int printf(const char *format, ...) __attribute__ ((format (printf, 2, 3))) {
      static char buff[22];
      va_list args;
      va_start(args, format);
      int rc = vsnprintf(buff, sizeof(buff), format, args);
      putString(buff);
      return rc;
   }
};

#endif /* SOURCES_LCD_ST7920_H_ */
