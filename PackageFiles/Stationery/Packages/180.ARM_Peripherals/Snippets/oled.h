/*
 * @file oled.h
 *
 *  Created on: 31 Oct 2019
 *      Author: podonoghue
 *
 *  Based loosely on Adafruit library (initialisation sequences and constants)
 */

#ifndef SOURCES_OLED_H_
#define SOURCES_OLED_H_
#include <memory.h>

#include "i2c.h"
#include "fonts.h"
#include "formatted_io.h"

namespace USBDM {

enum class OledDisplayType {
   ssd1306,
   sh1106
};

enum OledVccControl : uint8_t {
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
   SSD1306_COMSCANDEC                            = 0xC0, ///< b3=COM0..COMn/COMn..COM0
   SSD1306_SETDISPLAYOFFSET                      = 0xD3, ///< See datasheet
   SSD1306_SETDISPLAYCLOCKDIV                    = 0xD5, ///< See datasheet
   SSD1306_SETPRECHARGE                          = 0xD9, ///< See datasheet
   SSD1306_SETCOMPINS                            = 0xDA, ///< b5=COM left/right map, b4=seq/alt COM pin config.
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

   SH1106_SET_PAGE_ADDRESS                       = 0xB0, ///< Set page address, b3-0 = page #
   SH1106_SETLOWCOLUMN                           = 0x00, ///< Set column address b3-0 => addr3-0
   SH1106_SETHIGHCOLUMN                          = 0x10, ///< Set column address b3-0 => addr7-4
};

class Oled : public USBDM::FormattedIO {
public:

   // Change as needed for actual display
   static constexpr OledDisplayType DISPLAY_TYPE = OledDisplayType::sh1106;
   static constexpr int             WIDTH        = 128;   // Visible display width
   static constexpr int             HEIGHT       =  64;   // Height
   static constexpr OledVccControl  VCC_CONTROL  = OledVccControl_Internal;

   enum Orientation {Orientation_Normal, Orientation_Rotated_180};
   static constexpr Orientation orientation = Orientation_Normal;

private:

   const USBDM::Font *font = &USBDM::fontSmall;

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
   virtual Oled &flushInput() override {
      return *this;
   }

public:
   /**
    *  Flush output data
    */
   virtual Oled &flushOutput() override {
      refreshImage();
      return *this;
   }

   // Address (LSB = R/W bit = 0)
   static constexpr unsigned   I2C_ADDRESS   = 0b01111000;
   static constexpr unsigned   I2C_SPEED     = 400_kHz;

   // Size of image array in memory
   static constexpr size_t IMAGE_DATA_SIZE = WIDTH * ((HEIGHT + 7) / 8);

   // Number of pages in OLED internal image buffer
   // Set to zero if auto-increment of image pointer across pages is supported
   static constexpr size_t IMAGE_PAGE_COUNT =
         (DISPLAY_TYPE==OledDisplayType::sh1106)?(HEIGHT/8):
         (DISPLAY_TYPE==OledDisplayType::ssd1306)?0:
         0;

#pragma pack(push,1)
   /// Buffer type for display data
   /// This is prefixed by a command byte for transmission to OLED
   typedef uint8_t  Buffer[IMAGE_DATA_SIZE];
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

   /**
    * Set font to use for subsequent operations
    *
    * @param font
    * @return
    */
   Oled &setFont(const USBDM::Font &font) {
      this->font = &font;
      return *this;
   }

   /**
    * Initialise OLED peripheral
    *
    * @note   This function must be called before any drawing or updates!
    * @note   Based loosely on Adafruit library initialisation sequence
    */   void initialise();

    /**
     * Clear internal frame buffer
     * The OLED is not affected until refreshImage() is called.
     */
    Oled &clearDisplay() {
       memset((uint8_t *)&buffer, 0, sizeof(buffer));

       x = 0;
       y = 0;
       fontHeight = 0;

       return *this;
    }

    /**
     * Turn display on or off
     */
    void enable(bool enable);

    /**
     * Control display contrast/brightness
     *
     *  Has no appreciable effect on display tested
     *
     * @param level
     */
    void setContrast(uint8_t level);

    /**
     * Refresh OLED from frame buffer
     */
    void refreshImage();

    /**
     * Write image to frame buffer
     *
     * @param [in] dataPtr    Pointer to start of image
     * @param [in] x          X position of top-left corner
     * @param [in] y          Y position of top-left corner
     * @param [in] width      Width of image
     * @param [in] height     Height of image
     * @param [in] writeMode  Write mode (inverse, xor etc)
     */
    Oled &writeImage(const uint8_t *dataPtr, int x, int y, int width, int height, WriteMode writeMode=WriteMode_Write);

    /**
     * Writes whitespace to the frame buffer at the current x,y location
     *
     * @param [in] width Width of white space in pixels
     */
    Oled &putSpace(int width);

    /**
     *
     * @param [in] index      Index into frame buffer in bytes
     * @param [in] mask       Mask for pixel being manipulated in byte
     * @param [in] pixel      Pixel value
     * @param [in] writeMode  Mode of modification
     */
    void putPixel(unsigned index, uint8_t mask, bool pixel, WriteMode writeMode);

    /**
     * Draw pixel to frame buffer
     *
     * @param [in] x          Horizontal position in pixel
     * @param [in] y          Vertical position in pixel
     * @param [in] pixel      Pixel value
     * @param [in] writeMode  Mode of modification
     */
    void drawPixel(int x, int y, bool pixel, WriteMode writeMode=WriteMode_Write);

    /**
     * Draw vertical line to frame buffer
     *
     * @param [in] x  Horizontal position in pixel
     * @param [in] y1 Top Y position
     * @param [in] y2 Top Y position
     * @param [in] writeMode  Mode of modification
     */
    void drawVerticalLine(int x, int y1, int y2, WriteMode writeMode=WriteMode_Write);

    /**
     * Draw horizontal line to frame buffer
     *
     * @param [in] x1          Left horizontal position in pixel
     * @param [in] x2          Right horizontal position in pixel
     * @param [in] y           Y position
     * @param [in] writeMode   Mode of modification
     */
    void drawHorizontalLine(int x1, int x2, int y, WriteMode writeMode=WriteMode_Write);

    /**
     *   Draw filled rectangle
     *
     * @param x1         Top-left X
     * @param y1         Top-left Y
     * @param x2         Bottom-right X
     * @param y2         Bottom-right Y
     * @param writeMode  Write mode (inverse, xor etc)
     */
    void drawRect(int x1, int y1, int x2, int y2, WriteMode writeMode=WriteMode_Write);

    /**
     * Move current location
     *
     * @param x
     * @param y
     *
     * @return Reference to self
     */
    Oled &moveXY(int x, int y) {
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
     * Get current X,Y location
     *
     * @param [out] x X location in pixels
     * @param [out] y Y location in pixels
     *
     * @return Reference to self
     */
    Oled &getXY(int &x, int &y) {
       x = this->x;
       y = this->y;
       return *this;
    }
};

} // namespace USBDM

#endif /* SOURCES_OLED_H_ */
