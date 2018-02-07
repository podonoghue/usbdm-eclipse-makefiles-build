/**
 * @file lcd_st7920.cpp
 *
 *  Created on: 18 Sep 2016
 *      Author: podonoghue
 */

#include "lcd_st7920.h"

/**
 * Write command to LCD
 *
 * @param[in] value Command value to write
 */
void LCD_ST7920::writeCommand(uint8_t value) {
   uint8_t data[] = {
         0xF8,
         (uint8_t)(value&0xF0),
         (uint8_t)(value<<4),
   };
   spi.startTransaction(spiConfig);
   spi.txRx(sizeof(data), data);
   spi.endTransaction();
   USBDM::waitUS(EXECUTE_TIME_US);
}

/**
 * Write data value to LCD
 *
 * @param[in] value Data value to write
 */
void LCD_ST7920::writeData(uint8_t value) {
   uint8_t data[] = {
         0xFA,
         (uint8_t)(value&0xF0),
         (uint8_t)(value<<4),
   };
   spi.startTransaction(spiConfig);
   spi.txRx(sizeof(data), data);
   spi.endTransaction();
   USBDM::waitUS(EXECUTE_TIME_US);
}


/**
 * Initialise the LCD
 */
void LCD_ST7920::initialise() {
   USBDM::waitMS(200);

   spi.startTransaction();

   // Set up SPI
   spi.setPeripheralSelect(pinNum, USBDM::ActiveLow);
   spi.setSpeed(12000000);
   spi.setMode(USBDM::SpiMode_3);
   spi.setFrameSize(8);

   // Record SPI configuration as shared
   spiConfig = spi.getConfiguration();
   spi.endTransaction();

   writeCommand(0b00111000); // Function set(DL=1, RE=0)
   writeCommand(0b00001100); // On/Off(D=1 C=0, B=0)
   writeCommand(0b00000110); // EntryMode(I/D=1,S=0)

   clear();
}

/**
 * Clear text screen
 */
void LCD_ST7920::clear() {
   setTextMode();
   writeCommand(0b00110000); // Basic instruction mode
   writeCommand(0b00000010); // Home
   writeCommand(0b00000001); // Clear
   USBDM::waitUS(CLEAR_TIME_US);
}

/**
 * Display text string using default LCD font
 *
 * @param[in] row Row on display (0..3)
 * @param[in] str String to display (up to 16 characters)
 */
void LCD_ST7920::displayString(uint8_t row, const char* str) {
   uint8_t addr = 0x80;
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
void LCD_ST7920::setTextMode() {
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
void LCD_ST7920::setGraphicMode() {
   // Set Extended instructions
   writeCommand(0b110100);
   // Set Graphic on
   writeCommand(0b110110);
   // Set Basic instructions
   writeCommand(0b110000);
}

/**
 * Clear frame buffer
 */
void LCD_ST7920::clearFrameBuffer() {
   memset(frameBuffer, invertMask, sizeof(frameBuffer));
   x          = 0;
   y          = 0;
   fontHeight = 0;
}

/**
 * Refreshes LCD from frame buffer
 */
void LCD_ST7920::refreshImage() {
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
 * @param[in] dataPtr Pointer to start of image
 * @param[in] x       X position of top-left corner
 * @param[in] y       Y position of top-left corner
 * @param[in] width   Width of image
 * @param[in] height  Height of image
 */
void LCD_ST7920::writeImage(const uint8_t *dataPtr, int x, int y, int width, int height) {
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
 * Write a character to the LCD in graphics mode at the current x,y location
 *
 * @param[in] ch The character to write
 */
void LCD_ST7920::putChar(uint8_t ch) {
   int width  = font.width;
   int height = font.height;
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
      writeImage((uint8_t*)(&font.data[(ch-USBDM::Font::BASE_CHAR)*font.bytesPerChar]), x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);
   }
}

/**
 * Writes whitespace to the LCD in graphics mode at the current x,y location
 *
 * @param[in] width Width of white space in pixels
 */
void LCD_ST7920::putSpace(int width) {
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
 * Write a string to the LCD in graphics mode at the current x,y location
 *
 * @param[in] str The string to write
 */
void LCD_ST7920::putString(const char *str) {
   while (*str != '\0') {
      putChar(*str++);
   }
}
/**
 * Draw vertical line
 *
 * @param[in] x  Horizontal position in pixels
 * @param[in] y1 Vertical start position in pixels
 * @param[in] y2 Vertical end position in pixels
 */
void LCD_ST7920::drawVerticalLine(int x, int y1, int y2) {
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
 * @param[in] y Vertical position in pixels
 */
void LCD_ST7920::drawHorizontalLine(int y) {
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
 * @param[in] x Horizontal position in pixel
 * @param[in] y Vertical position in pixel
 */
void LCD_ST7920::drawPixel(int x, int y) {
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
 * @param[in] format Format control string (as for printf())
 * @param[in] ...    Arguments to print
 *
 * @return numbers of chars printed?
 *
 * @note Limited to 21 characters ~ 1 line
 */
int LCD_ST7920::printf(const char *format, ...) {
   static char buff[22];
   va_list args;
   va_start(args, format);
   int rc = vsnprintf(buff, sizeof(buff), format, args);
   putString(buff);
   return rc;
}
