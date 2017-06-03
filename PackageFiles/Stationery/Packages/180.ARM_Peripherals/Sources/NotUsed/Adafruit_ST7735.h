/***************************************************
  This is a library for the Adafruit 1.8" SPI display.

This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
The 1.8" TFT shield
  ----> https://www.adafruit.com/product/802
The 1.44" TFT breakout
  ----> https://www.adafruit.com/product/2088
as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _ADAFRUIT_ST7735H_
#define _ADAFRUIT_ST7735H_

#include <stdint.h>
#include "spi.h"
#include "Lcd.h"

namespace USBDM {

/**
 * Calculates colour as 16-bit value in 5:6:5 format
 *
 * @param r Red
 * @param g Green
 * @param b Blue
 */
static constexpr uint16_t Color565(uint8_t r, uint8_t g, uint8_t b) {
   return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

static constexpr int BLACK        = Color565(0,0,0);
static constexpr int NAVY         = 0x008;
static constexpr int BLUE         = 0x00F;
static constexpr int TEAL         = 0x088;
static constexpr int EMERALD      = 0x0C5;
static constexpr int GREEN        = 0x0F0;
static constexpr int CYAN         = 0x0FF;
static constexpr int SLATE        = 0x244;
static constexpr int INDIGO       = 0x408;
static constexpr int TURQUOISE    = 0x4ED;
static constexpr int OLIVE        = 0x682;
static constexpr int MAROON       = 0x800;
static constexpr int PURPLE       = 0x808;
static constexpr int GRAY         = 0x888;
static constexpr int SKYBLUE      = 0x8CE;
static constexpr int BROWN        = 0xB22;
static constexpr int CRIMSON      = 0xD13;
static constexpr int ORCHID       = 0xD7D;
static constexpr int RED          = 0xF00;
static constexpr int MAGENTA      = 0xF0F;
static constexpr int PINK         = 0xF6A;
static constexpr int CORAL        = 0xF75;
static constexpr int SALMON       = 0xF87;
static constexpr int ORANGE       = 0xFA0;
static constexpr int GOLD         = 0xFD0;
static constexpr int YELLOW       = 0xFF0;
static constexpr int WHITE        = Color565(32,64,32);

class Adafruit_ST7735 : public Lcd {

protected:
   USBDM::Spi   *spi;
   uint8_t  colstart, rowstart, xstart, ystart; // some displays need this changed

public:
   // Flags initR() :(
   enum DisplayType {
      INITR_GREENTAB     = 0x0,
      INITR_REDTAB       = 0x1,
      INITR_BLACKTAB     = 0x2,
      INITR_18GREENTAB   = INITR_GREENTAB,
      INITR_18REDTAB     = INITR_REDTAB,
      INITR_18BLACKTAB   = INITR_BLACKTAB,
      INITR_144GREENTAB  = 0x1,
      INITR_MINI160x80   = 0x4,
   };

public:
   int rotation;

   Adafruit_ST7735(USBDM::Spi *spi) : Lcd(100,100), spi(spi), colstart(0), rowstart(0), xstart(0), ystart(0) {
   }

   virtual void drawPixel(int x, int y, Color color) override;

protected:
   /**
    * Initialise ST7735B displays
    */
   void initB(void);
   /**
    * Initialise ST7735R displays
    *
    * @param displayType Display type
    */
   void initR(DisplayType displayType = INITR_GREENTAB);

   void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
   void pushColor(Color color);
   void fillScreen(Color color);
   void drawFastVLine(int x, int y, int h, Color color);
   void drawFastHLine(int x, int y, int w, Color color);
   void fillRect(int x, int y, int w, int h, Color color);
   void setRotation(uint8_t r);
   void invertDisplay(bool i);



protected:
   DisplayType  tabcolor;

   virtual void init() {};
   virtual void writecommand(uint8_t c) = 0;
   virtual void writedata8(uint8_t d)   = 0;
   virtual void writedata16(uint16_t d) = 0;
   virtual void filldata16(uint16_t d, uint16_t size) = 0;

   /**
    * Executes a command list
    *
    * @param list The list to execute
    */
   void commandList(const uint8_t *list);

};

template<class ChipSelect_n=USBDM::gpio_D0, class DataSelect=USBDM::gpio_D1, class Reset_n=USBDM::gpio_D2>
class Adafruit_ST7735_T : public Adafruit_ST7735 {

private:
   uint32_t spiConfig;

public:
   Adafruit_ST7735_T(USBDM::Spi *spi) : Adafruit_ST7735(spi) {
      init();
   }

   void init() override {
      using namespace USBDM;

      DataSelect::setOutput(pcrValue(PullNone, DriveHigh));
      ChipSelect_n::setOutput(pcrValue(PullNone, DriveHigh));
      Reset_n::setOutput(pcrValue(PullNone, DriveHigh));

      // Configure SPI and save configuration value
      spi->startTransaction(0);
      spi->setMode(spiModeValue(SpiMode0, SpiMsbFirst));
      spi->setSpeed(8000000);
      spiConfig = spi->getCTAR0Value();
      spi->endTransaction();

      // Pulse RST low to reset; CS low so it'll listen to us
      ChipSelect_n::low();
      Reset_n::high();
      waitMS(500);
      Reset_n::low();
      waitMS(500);
      Reset_n::high();
      waitMS(500);
      ChipSelect_n::high();
      Adafruit_ST7735::init();
   }

private:
   void writecommand(uint8_t c) override {
      using namespace USBDM;

      spi->startTransaction(spiConfig);
      DataSelect::low();
      ChipSelect_n::low();
      spi->txRx(c);
      ChipSelect_n::high();
      spi->endTransaction();
   }

   void writedata8(uint8_t d) override {
      using namespace USBDM;

      spi->startTransaction(spiConfig);
      DataSelect::high();
      ChipSelect_n::low();
      spi->txRx(d);
      ChipSelect_n::high();
      spi->endTransaction();
   }

   void writedata16(uint16_t d) override {
      using namespace USBDM;

      spi->startTransaction(spiConfig);
      DataSelect::high();
      ChipSelect_n::low();
      spi->txRx(d>>8);
      spi->txRx(d);
      ChipSelect_n::high();
      spi->endTransaction();
   }

   void filldata16(uint16_t d, uint16_t size) override {
      using namespace USBDM;

      spi->startTransaction(spiConfig);
      uint8_t hi = d>>8;
      uint8_t lo = d;
      DataSelect::high();
      ChipSelect_n::low();
      while(size-->0) {
         spi->txRx(hi);
         spi->txRx(lo);
      }
      ChipSelect_n::high();
      spi->endTransaction();
   }

};

}; // end namespace USBDM

#endif
