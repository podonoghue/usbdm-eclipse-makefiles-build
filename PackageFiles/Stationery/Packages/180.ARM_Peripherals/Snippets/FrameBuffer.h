/*
 * FrameBuffer.h (180.ARM_Peripherals/Snippets)
 *
 *  Created on: 26 Sept 2025
 *      Author: peter
 */

#ifndef SOURCES_FRAMEBUFFER_H_
#define SOURCES_FRAMEBUFFER_H_

#include <memory.h>
#include "formatted_io.h"
#include "fonts.h"

namespace USBDM {

/**
 * How the new pixels are combined with existing
 */
enum WriteMode {
   WriteMode_Write,        /**< Write new value       */
   WriteMode_InverseWrite, /**< Write inverted value  */
   WriteMode_Or,           /**< Combine new pixel with existing by ORing */
   WriteMode_InverseAnd,   /**< Combine new pixel with existing by inversion and ANDing */
   WriteMode_Xor,          /**< Combine new pixel with existing by XORing */
};

/**
 * Mirroring of the screen
 */
enum MirrorMode {
   MirrorMode_None,    /**< None               */
   MirrorMode_X,       /**< Mirror on X axis   */
   MirrorMode_Y,       /**< Mirror on Y axis   */
   MirrorMode_Origin,  /**< Mirror on X=Y axis */
};

/**
 * Rotation of the screen
 */
enum RotateMode {
   RotateMode_0,    /**< Rotate 0 degrees    */
   RotateMode_90,   /**< Rotate 90 degrees   */
   RotateMode_180,  /**< Rotate 180 degrees  */
   RotateMode_270,  /**< Rotate 270 degrees  */
};

/**
 * Scaling of pixels to physical pixels
 */
enum ScaleMode {
   ScaleMode_1  = 1,  /**< Scale x 1 */
   ScaleMode_2  = 2,  /**< Scale x 2 */
   ScaleMode_4  = 4,  /**< Scale x 4 */
};

enum Colour : uint8_t {
   BLACK = 0b0000'0000,
         WHITE = 0b1111'1111,
};

enum PixelPacking {
   PixelPacking_8x1xRow,  /**< 1 byte = 8 pixels horizontal X 1 pixel vertical for each row */
   PixelPacking_1x8xRow,  /**< 1 byte = 1 pixel horizontal X 8 pixels vertical for each row */
};

/**
 * Frame buffer for display
 *
 * @tparam WIDTH        Physical width of display
 * @tparam HEIGHT       Physical height of display
 * @tparam pixelPacking How pixels are packed into frame buffer memory
 * @tparam rotate       How to rotate display
 * @tparam mirrorMode   How to mirror the display
 * @tparam scale        How to scale the display
 */
template <unsigned WIDTH, unsigned HEIGHT, PixelPacking pixelPacking, ScaleMode scale=ScaleMode_1, RotateMode rotate=RotateMode_0, MirrorMode mirrorMode=MirrorMode_None>
class FrameBuffer : public FormattedIO {

protected:

   static constexpr bool DEBUG = false;

   // Write mode - How the new pixels are combined with existing
   WriteMode writeMode = WriteMode_Write;

   // X position
   unsigned x = 0;

   // Y position
   unsigned y = 0;

   // Graphic mode font height (for newline)
   unsigned fontHeight = 0;

   // Current font
   const USBDM::Font *font;

   // Default colour for painting unless specified in call
   Colour colour = WHITE;

   template<typename T>
   constexpr T max(T a, T b) {
      return (a>b)?a:b;
   }

   static constexpr unsigned getHeight() {

      bool flipped = mirrorMode == MirrorMode_Origin;

      if constexpr ((rotate == RotateMode_90)||(rotate == RotateMode_270)) {
         flipped = !flipped;
      }
      return (flipped?WIDTH:HEIGHT)/scale;
   }

   static constexpr unsigned getWidth() {

      bool flipped = mirrorMode == MirrorMode_Origin;

      if constexpr ((rotate == RotateMode_90)||(rotate == RotateMode_270)) {
         flipped = !flipped;
      }
      return (flipped?HEIGHT:WIDTH)/scale;
   }
   /**
    * Check if character is available
    *
    * @return true  Character available i.e. _readChar() will not block
    * @return false No character available
    */
   __attribute__((deprecated))
   virtual bool _isCharAvailable() override {
      return false;
   }

   /**
    * Receives a character (blocking)
    *
    * @return Character received
    */
   __attribute__((deprecated))
   virtual int _readChar() override {
      return -1;
   }

   /**
    * Flush input data
    *
    * @return Reference to self
    */
   __attribute__((deprecated))
   virtual FrameBuffer &flushInput() override {
      return *this;
   }

   /**
    * Combine a new pixel with existing frame buffer value
    *
    * @param address    Frame buffer address
    * @param mask       Mask indicating pixels in value
    * @param colour     New pixel colour
    */
   void combine(unsigned address, uint8_t mask, Colour colour) {

      if (address>getFrameSize()) {
#if DEBUG
         console.WRITELN("Illegal offset");
         __BKPT();
#else
         exit(-1);
#endif
      }
      if constexpr (DEBUG) {
         console.writeln("                          combine [", address, Radix_16, "] <- ", mask, Radix_16);
      }

      uint8_t oldValue = frameBuffer[address];

      uint8_t newValue = oldValue;

      switch(writeMode) {
         case WriteMode_InverseWrite:  colour = (Colour)~colour; [[fallthrough]];
         case WriteMode_Write:         newValue = (oldValue&~mask)|(colour&mask);  break;
         case WriteMode_Or:            newValue = oldValue|(colour&mask);          break;
         case WriteMode_Xor:           newValue = oldValue^(colour&mask);          break;
         case WriteMode_InverseAnd:    newValue = oldValue&(~colour|~mask);        break;
      }
      frameBuffer[address] = newValue;
   }

   /**
    * Map coordinate from canvas to frame buffer before scaling.
    * Only handles rotation and mirroring.
    *
    * @param [in/out] x          Mapped X coordinate from canvas -> frame buffer (before scaling)
    * @param [in/out] y          Mapped Y coordinate from canvas -> frame buffer (before scaling)
    *
    * @return true Coordinate is within frame buffer
    * @return false Coordinate is outside frame buffer
    */
   bool mapCoordinate(unsigned &x, unsigned &y) {

      // Dimensions of drawing canvas (from frame buffer with scaling i.e. in scaled pixels)

      if constexpr (DEBUG) {
         console.write("map(", x, ", ", y, ") -> ");
      }

      // Check if clipped [0.._width-1][0..height-1]
      bool onScreen = true;
      if (x>=width) {
         onScreen = false;
      }
      if (y>=height) {
         onScreen = false;
      }
      // For use with mirroring
      unsigned _width  = width;
      unsigned _height = height;

      switch (rotate) {
         unsigned t;

         case RotateMode_0:
            break;
         case RotateMode_90:
            t = x;
            x = y;
            y = width-t-1;
            _width  = height;
            _height = width;
            break;

         case RotateMode_180:
            x = width-x-1;
            y = height-y-1;
            break;
         case RotateMode_270:
            t = x;
            x = height-y-1;
            y = t;
            _width  = height;
            _height = width;
            break;
      }
      switch(mirrorMode) {
         unsigned t;

         case MirrorMode_None:
            break;
         case MirrorMode_X:
            x = _width-x-1;
            break;
         case MirrorMode_Y:
            y = _height-y-1;
            break;
         case MirrorMode_Origin:
            t = x;
            x = y;
            y = t;
            break;
      }
      if constexpr (DEBUG) {
         console.writeln("(", x, ", ", y, ")");
      }
      return onScreen;
   }

   /**
    * Simple line drawing for y0=y1 using physical co-ords
    *
    * @param x0   Physical start X
    * @param y    Physical start Y == end Y
    * @param x1   Physical end X
    */
   void drawHorizontalLine(unsigned x0, unsigned y, unsigned x1) {

      if constexpr (DEBUG) {
         console.writeln("drawHLine(", x0, "<->", x1,", ",y, ")");
      }

      if (x0>x1) {
         unsigned t = x0;
         x0 = x1;
         x1 = t;
      }
      if ((y>=HEIGHT)||(x0>=WIDTH)) {
         // Off screen
         return;
      }
      if (x1>=WIDTH) {
         // Clip
         x1 = WIDTH-1;
      }
      if constexpr (pixelPacking == PixelPacking_1x8xRow) {

         switch (scale) {
            case ScaleMode_1: {

               // 8 vertical pixels/byte
               // Draw 1 pixel per loop
               uint8_t mask = 0b1<<(y&0b111);
               unsigned baseIndex = ((y>>3) * WIDTH);
               for (unsigned x=x0; x<=x1; x++) {
                  combine(baseIndex+x, mask, colour);
               }
            }
            break;
            case ScaleMode_2: {

               // 4 paired vertical pixels/byte
               // Draw 1 paired pixel per loop

               uint8_t mask = 0b11<<(2*(y&0b11));
               unsigned baseIndex = ((y>>2) * WIDTH);
               for (unsigned x=2*x0; x<=2*x1; x++) {
                  combine(baseIndex+x, mask, colour);
               }
            }
            break;
            case ScaleMode_4: {

               // 2 quad vertical pixels/byte
               // Draw 1 quad pixel per loop
               uint8_t mask = 0b1111<<(4*(y&0b1));
               unsigned baseIndex = ((y>>1) * WIDTH);
               for (unsigned x=4*x0; x<=4*x1; x++) {
                  combine(baseIndex+x, mask, colour);
               }
            }
            break;
         }
      }
      else {
         switch (scale) {
            case ScaleMode_1:
            /* x = 8 pixels/byte; y = 1 row/pixel */ {
               uint8_t mask     = 0b1111'1111>>(x0&0b111);
               uint8_t lastMask = 0b1111'1111'1000'0000>>(x1&0b111);
               x0 /= 8;
               x1 /= 8;
               unsigned address = x0 + y*((width+7)/8);
               for (unsigned x=x0; x<=x1; x++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  if (x==x1) {
                     // last byte
                     mask &= lastMask;
                  }
                  combine(address, mask, colour);
                  address++;
                  mask = 0b11111111;
               }
            }
            break;
            case ScaleMode_2:
            /* x = 4 pixels/byte; y= 2 rows/pixel */ {
               uint8_t mask     = 0b1111'1111>>(2*(x0&0b111));
               uint8_t lastMask = 0b1111'1111'1000'0000>>(2*(x1&0b111));
               x0 /= 4;
               x1 /= 4;
               y *= 2;
               unsigned address = x0 + y*((width+7)/8);
               for (unsigned x=x0; x<=x1; x++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  if (x==x1) {
                     // last byte
                     mask &= lastMask;
                  }
                  combine(address,               mask, colour);
                  combine(address+((width+7)/8), mask, colour);
                  address++;
                  mask = 0b11111111;
               }
            }
            break;
            case ScaleMode_4:
            /* x = 2 pixels/byte; y = 4 rows/pixel */ {
               uint8_t mask     = 0b1111'1111>>(4*(x0&0b111));
               uint8_t lastMask = 0b1111'1111'1000'0000>>(4*(x1&0b111));
               x0 /= 2;
               x1 /= 2;
               y *= 4;
               unsigned address = x0 + y*((width+7)/8);
               for (unsigned x=x0; x<=x1; x++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  if (x==x1) {
                     // last byte
                     mask &= lastMask;
                  }
                  combine(address,                 mask, colour);
                  combine(address+((width+7)/8),   mask, colour);
                  combine(address+2*((width+7)/8), mask, colour);
                  combine(address+3*((width+7)/8), mask, colour);
                  address++;
                  mask = 0b11111111;
               }
            }
            break;
         }
      }
   }

   /**
    * Simple line drawing for physical x0=x1
    *
    * @param x0   Physical start X == end X
    * @param y0   Physical start Y
    * @param y1   Physical end Y
    */
   void drawVerticalLine(unsigned x, unsigned y0, unsigned y1) {

      if constexpr (DEBUG) {
         console.writeln("drawVLine(", x, ", ", y0, "<->",y1, ")");
      }

      if (y0>y1) {
         int t = y0;
         y0 = y1;
         y1 = t;
      }
      if ((x>=WIDTH)||(y0>=HEIGHT)) {
         // Off screen
         return;
      }
      if (y1>=HEIGHT) {
         y1 = HEIGHT-1;
      }

      if constexpr (pixelPacking == PixelPacking_1x8xRow) {

         // Vertical on display
         switch (scale) {
            uint8_t  mask, endMask;
            unsigned address;

            case ScaleMode_1:
               mask    = 0b11111111U<<(y0&0b111);
               endMask = ~(0b11111111U<<((y1&0b111)+1));
               y0 = (y0>>3);
               y1 = (y1>>3);
               address = y0*WIDTH + x;
               for (unsigned row=y0; row<=y1; row++) {
                  if (row==y1) {
                     mask &= endMask;
                  }
                  combine(address, mask, colour);
                  mask = 0xFF;
                  address += WIDTH;
               }
               break;

            case ScaleMode_2:
               mask    = 0b11111111U<<(2*(y0&0b11));
               endMask = ~(0b11111111U<<(2*(y1&0b11)+2));
               y0 = (y0>>2);
               y1 = (y1>>2);
               address = y0*WIDTH + 2*x;
               for (unsigned row=y0; row<= y1; row++) {
                  if (row == y1) {
                     mask &= endMask;
                  }
                  combine(address,   mask, colour);
                  combine(address+1, mask, colour);
                  mask = 0xFF;
                  address += WIDTH;
               }
               break;

            case ScaleMode_4:
               mask    = 0b11111111U<<(4*(y0&0b1));
               endMask = ~(0b11111111U<<(4*(y1&0b1)+2));
               y0 = (y0>>1);
               y1 = (y1>>1);
               address = y0*WIDTH + 4*x;
               for (unsigned row=y0; row<= y1; row++) {
                  if (row == y1) {
                     mask &= endMask;
                  }
                  combine(address,   mask, colour);
                  combine(address+1, mask, colour);
                  combine(address+2, mask, colour);
                  combine(address+3, mask, colour);
                  mask = 0xFF;
                  address += WIDTH;
               }
               break;
         }
      }
      else {

         switch (scale) {
            case ScaleMode_1:
            /* x = 8 pixels/byte; y = 1 row/pixel */ {
               uint8_t mask     = (0b1000'0000>>(x&0b111));
               x /= 8;
               unsigned address = x + y0*((width+7)/8);
               for (unsigned y=y0; y<=y1; y++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  combine(address, mask, colour);
                  address += ((width+7)/8);
               }
            }
            break;
            case ScaleMode_2:
            /* x = 4 pixels/byte; y= 2 rows/pixel */ {
               uint8_t mask     = (0b1100'0000>>(2*(x&0b11)));
               x /= 4;
               y0 *= 2;
               y1 = 2*y1 + 1;
               unsigned address = x + y0*((width+7)/8);
               for (unsigned y=y0; y<=y1; y++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  combine(address, mask, colour);
                  address += ((width+7)/8);
               }
            }
            break;
            case ScaleMode_4:
            /* x = 2 pixels/byte; y = 4 rows/pixel */ {
               uint8_t mask     = (0b1111'0000>>(4*(x&0b1)));
               x /= 2;
               y0 *= 4;
               y1  = 4*y1 + 3;
               unsigned address = x + y0*((width+7)/8);
               for (unsigned y=y0; y<=y1; y++) {
                  if (address>=getFrameSize()) {
                     // Clipped
                     return;
                  }
                  combine(address, mask, colour);
                  address += ((width+7)/8);
               }
            }
            break;
         }
      }
   }

   /**
    * Write a custom character to the LCD in graphics mode at the current x,y location
    *
    * @param[in] image  Image describing the character
    * @param[in] width  Width of the image
    * @param[in] height Height of character
    *
    * @return Reference to self
    */
   FrameBuffer &putCustomChar(const uint8_t *image, unsigned width, unsigned height) {

      drawImage(image, x, y, width, height);
      x += width;
      fontHeight = max(fontHeight, height);

      return *this;
   }

public:
   /// Display height in scaled pixels
   static constexpr unsigned height = getHeight();

   /// Display width in scaled pixels
   static constexpr unsigned width = getWidth();

   // Frame buffer. Size is getFrameSize()
   uint8_t *frameBuffer;

   /**
    * Create frame buffer
    *
    * @param frameBuffer   Pre-allocated frame buffer
    * @param font          Initial font to use
    */
   FrameBuffer(const Font *font, uint8_t *fb) :
      FormattedIO(),
      font(font),
      frameBuffer(fb) {

      memset(frameBuffer, 0, getFrameSize());
   }

   virtual ~FrameBuffer() {
   }

   /**
    * Set colour for painting
    *
    * @param colour  Colour to use
    *
    * @return Reference to self
    */
   FrameBuffer &setColour(Colour colour) {

      this->colour = colour;
      return *this;
   }

   /**
    * Sets how new pixels are combined with existing
    *
    * @param writeMode Mode to set
    *
    * @return Reference to self
    */
   FrameBuffer &setWriteMode(WriteMode writeMode) {

      this->writeMode = writeMode;
      return *this;
   }

   /**
    * Get current font
    *
    * @return The current font
    */
   const Font *getFont() {

      return font;
   }

   /**
    * Set font to use for subsequent operations
    *
    * @param [in] font
    *
    * @return Reference to self
    */
   FrameBuffer &setFont(const USBDM::Font &font) {

      this->font = &font;
      return *this;
   }

   /**
    * Clear frame buffer
    *
    * @param pixel Value to set buffer to
    *
    * @return Reference to self
    */
   FrameBuffer &clear(Colour colour) {

      x = 0;
      y = 0;
      fontHeight = 0;

      uint8_t mask = colour;

      memset(frameBuffer, mask, getFrameSize());

      return *this;
   }

   /**
    * Move current location
    *
    * @param x
    * @param y
    *
    * @return Reference to self
    */
   FrameBuffer &moveXY(unsigned x, unsigned y) {

      this->x = x;
      this->y = y;

      return *this;
   }

   /**
    * Get current X location
    *
    * @return X location in pixels
    */
   int getX() {

      return x;
   }

   /**
    * Get current Y location
    *
    * @return Y location in pixels
    */
   int getY() {

      return y;
   }

   /**
    * Get the size of the frame buffer
    *
    * @return Size in bytes
    */
   static constexpr unsigned getFrameSize() {

      return HEIGHT*((WIDTH+7)/8);
   }

   /**
    * Get current X,Y location
    *
    * @param [out] x X location in pixels
    * @param [out] y Y location in pixels
    */
   void getXY(int &x, int &y) {

      x = this->x;
      y = this->y;
   }
   /**
    * Draw an image to frame buffer
    *
    * @param [in] image      Pointer to start of image
    * @param [in] x          X position of top-left corner
    * @param [in] y          Y position of top-left corner
    * @param [in] width      Width of image
    * @param [in] height     Height of image
    */
   void drawImage(const uint8_t *image, unsigned x, unsigned y, unsigned width, unsigned height) {

      for(unsigned h=0; h<height; h++) {
         for(unsigned w=0; w<width; w++) {

            // Get pixel value from image
            unsigned pixelIndex = (h*((width+7)/8))+(w/8);
            bool newPixel = (image[pixelIndex]&(1<<(7-(w&0b111))));

            // Paint pixel
            drawPixel(x+w, y+h, newPixel?colour:(Colour)~colour);
         }
      }
   }

   /**
    * Draw a full screen image to frame buffer
    *
    * @param [in] image      Pointer to start of image
    */
   void drawFullScreenImage(const uint8_t *image) {
      drawImage(image, 0, 0, width, height);
   }

   /**
    * Write a character to the frame buffer at the current x,y location
    *
    * @param[in]  ch - character to write
    */
   void _writeChar(char ch) {

      unsigned width  = font->width;
      unsigned height = font->height;

      if (ch == '\\n') {
         putSpace(width-x);
         x  = 0;
         y += fontHeight;
         fontHeight = 0;
      }
      else {
         if ((x+width)>this->width) {
            // Don't display partial characters
            return;
         }
         drawImage((*font)[ch], x, y, width, height);
         x += width;
         fontHeight = max(fontHeight, height);
      }
      return;
   }

   /**
    * Writes whitespace to the frame buffer at the current x,y location
    *
    * @param[in] WIDTH Width of white space in pixels
    *
    * @return Reference to self
    */
   FrameBuffer &putSpace(int width) {

      static const uint8_t space[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
      while (width>0) {
         int t = 8;
         if (t>width) {
            t = width;
         }
         putCustomChar(space, t, 8);
         width -= t;
      }
      return *this;
   }

   /**
    * Draw pixel to frame buffer
    *
    * @param [in] x          Horizontal position in pixel
    * @param [in] y          Vertical position in pixel
    * @param [in] pixel      Pixel value
    * @param [in] writeMode  Mode of modification
    */
   void drawPixel(unsigned x, unsigned y, Colour colour) {

      // Get effective X,Y with scaling and rotation
      if (!mapCoordinate(x, y)) {
         // Off-screen
         if constexpr (DEBUG) {
            console.writeln("off-screen [", x, ",", y, "]");
         }
         __asm__("nop");
         return;
      }
      if constexpr (DEBUG) {
         console.writeln("drawPixel(", x, ",", y, ")");
      }
      if constexpr (pixelPacking == PixelPacking_1x8xRow) {

         switch(scale) {
            case ScaleMode_1: {
               uint8_t  mask = 0b0000'0001<<(y&0b111);
               unsigned index = x+((y>>3)*WIDTH);
               combine(index, mask, colour);
            }
            break;
            case ScaleMode_2: {
               uint8_t mask = 0b0000'0011<<(2*(y&0b11));
               unsigned address = 2*x+((y>>2)*WIDTH);
               for (unsigned col=0; col<2; col++) {
                  combine(address+col, mask, colour);
               }
            }
            break;
            case ScaleMode_4: {
               uint8_t mask = 0b0000'1111<<(4*(y&0b1));
               unsigned address = 4*x+((y>>1)*WIDTH);
               for (unsigned col=0; col<4; col++) {
                  combine(address+col, mask, colour);
               }
            }
            break;
         }
      }
      else if (pixelPacking == PixelPacking_8x1xRow) {

         switch (scale) {
            case ScaleMode_1: /* x = 8 pixels/byte; y = 1 row; */ {
               uint8_t mask = 0b1000'0000>>(x&0b111);
               unsigned address = x/8 + y*((WIDTH+7)/8);
               combine(address, mask, colour);
               if constexpr (DEBUG) {
                  console.WRITELN("s(%d,%d), address = %d, mask=%2X\n", x, y, address, mask);
               }
            }
            break;
            case ScaleMode_2: /* x = 4 pixels/byte; y= 2 rows */ {
               uint8_t mask = 0b1100'0000>>(2*(x&0b11));
               for (unsigned row=0; row<2; row++) {
                  unsigned address = x/4 + (2*y+row)*((WIDTH+7)/8);
                  combine(address, mask, colour);
                  if constexpr (DEBUG) {
                     console.WRITELN("s(%d,%d), address = %d, mask=%2X\n", x, y, address, mask);
                  }
               }
            }
            break;
            case ScaleMode_4: /* x = 2 pixels/byte; y = 4 rows */ {
               uint8_t mask = 0b1111'0000>>(4*(x&0b1));
               for (unsigned row=0; row<4; row++) {
                  unsigned address = x/2 + (4*y+row)*((WIDTH+7)/8);
                  combine(address, mask, colour);
                  if constexpr (DEBUG) {
                     console.WRITELN("s(%d,%d), address = %d, mask=%2X\n", x, y, address, mask);
                  }
               }
            }
            break;
         }
      }
   }

   /**
    * Simple line drawing using Bresenham's algorithm
    * Ref : https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
    *
    * @param x0   Start X
    * @param y0   Start Y
    * @param x1   End X
    * @param y1   End Y
    */
   void drawLine(unsigned x0, unsigned y0, unsigned x1, unsigned y1) {

      if constexpr (DEBUG) {
         console.writeln("drawLine( (", x0, ", ", y0, "), (", x1, ", ", y1, ") )");
      }

      if ((y0==y1)||(x0==x1)) {

         // Map to physical co-ords
         mapCoordinate(x0, y0);
         mapCoordinate(x1, y1);

         if (x0==x1) {
            drawVerticalLine(x0, y0, y1);
         }
         else { // y0==y1
            drawHorizontalLine(x0, y0, x1);
         }
      }
      else {
         int dx = std::abs((int)x1 - (int)x0);
         int sx = (x0 < x1) ? 1 : -1;
         int dy = -abs((int)y1 - (int)y0);
         int sy = (y0 < y1) ? 1 : -1;
         int error = dx + dy;

         while (true) {
            drawPixel(x0, y0, colour);
            int e2 = 2 * error;
            if (e2 >= dy) {
               if (x0 == x1) {
                  break;
               }
               error = error + dy;
               x0 = x0 + sx;
            }
            if (e2 <= dx) {
               if (y0 == y1) {
                  break;
               }
               error = error + dx;
               y0 = y0 + sy;
            }
         }
      }
   }

   /**
    * Draw a filled rectangle
    *
    * @param x0  Top-left X
    * @param y0  Top-left Y
    * @param x1  Bottom-right X
    * @param y1  Bottom-right Y
    */
   void drawRect(unsigned x0, unsigned y0, unsigned x1, unsigned y1) {

      mapCoordinate(x0, y0);
      mapCoordinate(x1, y1);

      for (unsigned y=y0; y<=y1; y++) {
         drawHorizontalLine(x0, y, x1);
      }
   }

   /**
    * Draw an open rectangle
    *
    * @param x0  Top-left X
    * @param y0  Top-left Y
    * @param x1  Bottom-right X
    * @param y1  Bottom-right Y
    */
   void drawOpenRect(unsigned x0, unsigned y0, unsigned x1, unsigned y1) {

      drawHorizontalLine(x0, y0, x1);
      drawHorizontalLine(x0, y1, x1);
      drawVerticalLine(x0, y0+1, y1-1);
      drawVerticalLine(x1, y0+1, y1-1);
   }

   /**
    * Draw filled circle
    *
    * @param X       Circle centre X
    * @param Y       Circle centre Y
    * @param Radius  Circle radius
    */
   void drawCircle(unsigned X, unsigned Y, unsigned Radius) {

      int16_t f = 1 - Radius;
      int16_t ddF_x = 1;
      int16_t ddF_y = -2 * Radius;
      int16_t x = 0;
      int16_t y = Radius;

      // Solid Circle - Draw the fill line
      drawLine(X - Radius, Y, X + Radius, Y);

      while (x < y)
      {
         if (f >= 0)
         {
            y--;
            ddF_y += 2;
            f += ddF_y;
         }
         x++;
         ddF_x += 2;
         f += ddF_x;

         // Solid Circle - Draw the fill line
         drawLine(X - x, Y + y, X + x, Y + y);
         drawLine(X - x, Y - y, X + x, Y - y);
         drawLine(X - y, Y + x, X + y, Y + x);
         drawLine(X - y, Y - x, X + y, Y - x);
      }
   }

   /**
    * Draw open circle
    *
    * @param X       Circle centre X
    * @param Y       Circle centre Y
    * @param Radius  Circle radius
    */
   void drawOpenCircle(unsigned X, unsigned Y, unsigned Radius) {

      int16_t f = 1 - Radius;
      int16_t ddF_x = 1;
      int16_t ddF_y = -2 * Radius;
      int16_t x = 0;
      int16_t y = Radius;

      // Hollow Circle - Draw 8 points of symmetry
      drawPixel(X, Y + Radius, colour);
      drawPixel(X, Y - Radius, colour);
      drawPixel(X + Radius, Y, colour);
      drawPixel(X - Radius, Y, colour);

      while (x < y)
      {
         if (f >= 0)
         {
            y--;
            ddF_y += 2;
            f += ddF_y;
         }
         x++;
         ddF_x += 2;
         f += ddF_x;

         // Hollow Circle - Draw 8 points of symmetry
         drawPixel(X + x, Y + y, colour);
         drawPixel(X - x, Y + y, colour);
         drawPixel(X + x, Y - y, colour);
         drawPixel(X - x, Y - y, colour);
         drawPixel(X + y, Y + x, colour);
         drawPixel(X - y, Y + x, colour);
         drawPixel(X + y, Y - x, colour);
         drawPixel(X - y, Y - x, colour);
      }
   }
};

} // end namespace USBDM

#endif /* SOURCES_FRAMEBUFFER_H_ */
