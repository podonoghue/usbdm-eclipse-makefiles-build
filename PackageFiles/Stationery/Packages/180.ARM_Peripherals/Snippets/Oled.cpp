/*
 * Oled.cpp
 *
 *  Created on: 31 Oct 2019
 *      Author: podonoghue
 */
#include "malloc.h"
#include "Oled.h"
#include "memory.h"

using namespace USBDM;

// Control byte
//static constexpr uint8_t SINGLE_COMMAND    = 0b10000000; ///< Co=1, D/C=0: Byte(s) are command data followed by another control byte
static constexpr uint8_t MULTIPLE_COMMANDS = 0b00000000; ///< Co=0, D/C=0: Byte(s) are command data until I2C stop
static constexpr uint8_t MULTIPLE_GDRAM    = 0b01000000; ///< Co=0, D/C=1: Byte(s) are graphic data until I2C stop

/**
 * Clear internal frame buffer
 * The OLED is not affected until refreshImage() is called.
 */
Oled &Oled::clearDisplay(void) {
   memset((uint8_t *)&buffer, 0, sizeof(buffer));

   x = 0;
   y = 0;
   fontHeight = 0;

   return *this;
}

/**
 * Initialise OLED peripheral
 *
 * @return true on success
 *
 * @note   This function must be called before any drawing or updates!
 */
void Oled::initialise() {

   clearDisplay();

   // Initialise sequence
   static const uint8_t init1[] = {
         MULTIPLE_COMMANDS,                    // Co = 0, D/C = 0
         SSD1306_DISPLAYOFF,                   // 0xAE
         SSD1306_SETDISPLAYCLOCKDIV,           // 0xD5
         0x80,                                 // = Reset value
         SSD1306_SETMULTIPLEX,                 // 0xA8
         (HEIGHT - 1),
         SSD1306_SETDISPLAYOFFSET,             // 0xD3
         0x0,                                  // = Reset value, no offset
         SSD1306_SETSTARTLINE | 0x0,           // 0x40 - line #0
         SSD1306_CHARGEPUMP,                   // 0x8D
         ((VCC_CONTROL == OledVccControl_External) ? 0x10 : 0x14),
         SSD1306_MEMORYMODE,                   // 0x20
         0x00,                                 // Horizontal addressing mode
         SSD1306_SEGREMAP | 0x1,               // 0xA0 | 0x01 map col127->SEG0
         SSD1306_COMSCANDEC | 0x8,             // 0xC0 | 0x8  scan COM[N-1] -> COM0
         SSD1306_COLUMNADDR,                   // 0x21
         0,                                    // first column
         (WIDTH-1),                            // last column
         SSD1306_PAGEADDR,                     // 0x22
         0,                                    // first page
         (((HEIGHT+7)/8)-1),                   // last page
   };
   i2c.transmit(I2C_ADDRESS, sizeof(init1), init1);

   if constexpr ((WIDTH == 128) && (HEIGHT == 32)) {

      static const uint8_t init4a[] = {
            MULTIPLE_COMMANDS,                    // Co = 0, D/C = 0
            SSD1306_SETCOMPINS,                   // 0xDA
            0x02,                                 // = default
            SSD1306_SETCONTRAST,                  // 0x81
//            0x8F,
            0x10,
      };
      i2c.transmit(I2C_ADDRESS, sizeof(init4a), init4a);

   } else if constexpr ((WIDTH == 128) && (HEIGHT == 64)) {

      static const uint8_t init4b[] = {
            MULTIPLE_COMMANDS,                    // Co = 0, D/C = 0
            SSD1306_SETCOMPINS,                   // 0xDA
            0x12,
            SSD1306_SETCONTRAST,                  // 0x81
            ((VCC_CONTROL == OledVccControl_External) ? 0x9F : 0xCF),
      };
      i2c.transmit(I2C_ADDRESS, sizeof(init4b), init4b);

   } else if constexpr ((WIDTH == 96) && (HEIGHT == 16)) {

      static const uint8_t init4c[] = {
            MULTIPLE_COMMANDS,                    // Co = 0, D/C = 0
            SSD1306_SETCOMPINS,                   // 0xDA
            0x2,    // ada x12
            SSD1306_SETCONTRAST,                  // 0x81
            ((VCC_CONTROL == OledVccControl_External) ? 0x10 : 0xAF),
      };
      i2c.transmit(I2C_ADDRESS, sizeof(init4c), init4c);
   } else {
      // Other screen varieties -- TBD
   }

   static const uint8_t init5[] = {
         MULTIPLE_COMMANDS,                    // Co = 0, D/C = 0
         SSD1306_SETPRECHARGE,                 // 0xD9
         ((VCC_CONTROL == OledVccControl_External) ? 0x22 : 0xF1),
         SSD1306_SETVCOMDETECT,                // 0xDB
         0x40,
         SSD1306_DISPLAYALLON_RESUME,          // 0xA4
         SSD1306_NORMALDISPLAY,                // 0xA6
         SSD1306_DEACTIVATE_SCROLL,
         SSD1306_DISPLAYON,                    // Main screen turn on
   };
   i2c.transmit(I2C_ADDRESS, sizeof(init5), init5);
}

/**
 * Refresh OLED from frame buffer
 */
void Oled::refreshImage() {
   buffer.controlByte = MULTIPLE_GDRAM;
   i2c.transmit(I2C_ADDRESS, sizeof(buffer), (uint8_t *)&buffer);
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
Oled &Oled::writeImage(const uint8_t *dataPtr, int x, int y, int width, int height, WriteMode writeMode) {
   // Doesn't support negative clipping of images
   usbdm_assert((x>=0)||(y>=0), "Illegal image coordinate");

   if ((x>=WIDTH)||(y>=HEIGHT)) {
      // Entirely off screen
      return *this;
   }
   for(int h=0; h<height; h++) {
      if ((y+h) >= HEIGHT) {
         // Clip at bottom
         break;
      }
      for(int w=0;w<width; w++) {
         if ((x+w) >= WIDTH) {
            // Clip on right
            break;
         }
         unsigned pixelIndex = (h*((width+7)/8))+(w/8);
         bool pixel = (dataPtr[pixelIndex]&(1<<(7-(w&0b111))));
         uint8_t mask = 0b1<<((y+h)&0b111);
         unsigned index = (x+w)+(((y+h)/8)*WIDTH);
         putPixel(index, mask, pixel, writeMode);
//         console.write(pixel?'*':' ');
      }
//      console.writeln();
//      refreshImage();
   }
   return *this;
}

/**
 * Write a character to the frame buffer at the current x,y location
 *
 * @param[in] ch The character to write
 */
void Oled::_writeChar(char ch) {
   int width  = font->width;
   int height = font->height;
   if (ch == '\n') {
      putSpace(WIDTH-x);
      x  = 0;
      y += fontHeight;
      fontHeight = 0;
   }
   else {
      if ((x+width)>WIDTH) {
         // Don't display partial characters
         return;
      }
      writeImage((uint8_t*)(&font->data[(ch-USBDM::Font::BASE_CHAR)*font->bytesPerChar]), x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);
   }
   return;
}

/**
 * Writes whitespace to the frame buffer at the current x,y location
 *
 * @param[in] width Width of white space in pixels
 */
Oled &Oled::putSpace(int width) {
   static const uint8_t space[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
   while (width>0) {
      int t = 8;
      if (t>width) {
         t = width;
      }
      width -= t;
      putCustomChar(space, t, 8);
   }
   return *this;
}

void Oled::putPixel(unsigned index, uint8_t mask, bool pixel, WriteMode writeMode) {
   switch(writeMode) {
      case WriteMode_Write:
         if (pixel) {
            buffer.buffer[index] |= mask;
         }
         else {
            buffer.buffer[index] &= ~mask;
         }
         break;
      case WriteMode_InverseWrite:
         if (pixel) {
            buffer.buffer[index] &= ~mask;
         }
         else {
            buffer.buffer[index] |= mask;
         }
         break;
      case WriteMode_Or:
         if (pixel) {
            buffer.buffer[index] |= mask;
         }
         break;
      case WriteMode_InverseAnd:
         if (!pixel) {
            buffer.buffer[index] &= ~mask;
         }
         break;
      case WriteMode_Xor:
         if (!pixel) {
            buffer.buffer[index] ^= mask;
         }
         break;
      default:
         break;
   }

}
/**
 * Draw vertical line to frame buffer
 *
 * @param[in] x  Horizontal position in pixels
 * @param[in] y1 Vertical start position in pixels
 * @param[in] y2 Vertical end position in pixels
 */
void Oled::drawVerticalLine(int x, int y1, int y2, WriteMode writeMode) {
   if ((x<0)||(x>=WIDTH)) {
      // Off screen
      return;
   }
   if (y1>y2) {
      int t = y1;
      y1 = y2;
      y2 = t;
   }
   if (y1<0) {
      y1 = 0;
   }
   if (y2>=HEIGHT) {
      y2 = HEIGHT-1;
   }
   uint8_t  startMask   = 0b11111111U<<(unsigned(y1&7));
   uint8_t  endMask     = ~(0b11111111U<<(unsigned(y2&7)+1));

   uint8_t mask = startMask;
   unsigned startRow = y1>>3;
   unsigned endRow   = y2>>3;

   unsigned index = (y1>>3)*WIDTH + x;
   for (unsigned row=startRow; row<endRow; row++) {
      putPixel(index, mask, 1, writeMode);
      mask = 0xFF;
      index += WIDTH;
   }
   mask &= endMask;
   putPixel(index, mask, 1, writeMode);
}

/**
 * Draw horizontal line to frame buffer
 *
 * @param[in] x1 Horizontal start position in pixels
 * @param[in] x2 Horizontal end position in pixels
 * @param[in] y  Vertical position in pixels
 */
void Oled::drawHorizontalLine(int x1, int x2, int y, WriteMode writeMode) {
   if ((y<0)||(y>=HEIGHT)) {
      // Off screen
      return;
   }
   if (x1>x2) {
      int t = x1;
      x1 = x2;
      x2 = t;
   }
   if (x1<0) {
      x1 = 0;
   }
   if (x2>=WIDTH) {
      x2 = WIDTH-1;
   }
   uint8_t mask = 0b1<<(y&0b111);
   unsigned baseIndex = ((y>>3) * WIDTH);
   for (unsigned xx=(unsigned)x1; xx<=(unsigned)x2; xx++) {
      unsigned index = xx + baseIndex;
      putPixel(index, mask, 1, writeMode);
   }
}

/**
 * Draw pixel to frame buffer
 *
 * @param[in] x Horizontal position in pixel
 * @param[in] y Vertical position in pixel
 */
void Oled::drawPixel(int x, int y, bool pixel, WriteMode writeMode) {
   if ((x<0)||(x>=WIDTH)) {
      // Off screen
      return;
   }
   if ((y<0)||(y>=HEIGHT)) {
      // Off screen
      return;
   }
   uint8_t mask = 0b1<<(y&7);
   unsigned index = x+((y>>3)*WIDTH);
   putPixel(index, mask, pixel, writeMode);
}

/**
 *   Draw filled rectangle
 *
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param invert
 */
void Oled::drawRect(int x1, int y1, int x2, int y2, WriteMode writeMode) {
   if (y1>y2) {
      int t = y1;
      y1 = y2;
      y2 = t;
   }
   for (int y=y1; y<=y2; y++) {
      drawHorizontalLine(x1, x2, y, writeMode);
   }
}
