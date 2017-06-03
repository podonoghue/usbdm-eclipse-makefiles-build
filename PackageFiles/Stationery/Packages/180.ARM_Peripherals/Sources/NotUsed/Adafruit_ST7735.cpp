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

#include <limits.h>
#include "Adafruit_ST7735.h"
#include "spi.h"

namespace USBDM {

// for 1.44 and mini
#define ST7735_TFTWIDTH_128  128
// for mini
#define ST7735_TFTWIDTH_80   80
// for 1.44" display
#define ST7735_TFTHEIGHT_128 128
// for 1.8" and mini display
#define ST7735_TFTHEIGHT_160  160

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define ST7735_BLACK   0x0000
#define ST7735_BLUE    0x001F
#define ST7735_RED     0xF800
#define ST7735_GREEN   0x07E0
#define ST7735_CYAN    0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW  0xFFE0
#define ST7735_WHITE   0xFFFF

inline uint16_t swapcolor(uint16_t x) { 
   return (x << 11) | (x & 0x07E0) | (x >> 11);
}

// Rather than a bazillion writecommand() and writedata8() calls, screen
// initialization commands and arguments are organized in these tables
// stored in PROGMEM.  The table may look bulky, but that's mostly the
// formatting -- storage-wise this is hundreds of bytes more compact
// than the equivalent code.  Companion function follows.
#define DELAY 0x80
static const uint8_t Bcmd[] = { // Initialization commands for 7735B screens
      18,                       // 18 commands in list:
      ST7735_SWRESET,   DELAY,  //  1: Software reset, no args, w/delay
      50,                       //     50 ms delay
      ST7735_SLPOUT ,   DELAY,  //  2: Out of sleep mode, no args, w/delay
      255,                      //     255 = 500 ms delay
      ST7735_COLMOD , 1+DELAY,  //  3: Set color mode, 1 arg + delay:
      0x05,                     //     16-bit color
      10,                       //     10 ms delay
      ST7735_FRMCTR1, 3+DELAY,  //  4: Frame rate control, 3 args + delay:
      0x00,                     //     fastest refresh
      0x06,                     //     6 lines front porch
      0x03,                     //     3 lines back porch
      10,                       //     10 ms delay
      ST7735_MADCTL , 1      ,  //  5: Memory access ctrl (directions), 1 arg:
      0x08,                     //     Row addr/col addr, bottom to top refresh
      ST7735_DISSET5, 2      ,  //  6: Display settings #5, 2 args, no delay:
      0x15,                     //     1 clk cycle nonoverlap, 2 cycle gate
      //     rise, 3 cycle osc equalize
      0x02,                     //     Fix on VTL
      ST7735_INVCTR , 1      ,  //  7: Display inversion control, 1 arg:
      0x0,                      //     Line inversion
      ST7735_PWCTR1 , 2+DELAY,  //  8: Power control, 2 args + delay:
      0x02,                     //     GVDD = 4.7V
      0x70,                     //     1.0uA
      10,                       //     10 ms delay
      ST7735_PWCTR2 , 1      ,  //  9: Power control, 1 arg, no delay:
      0x05,                     //     VGH = 14.7V, VGL = -7.35V
      ST7735_PWCTR3 , 2      ,  // 10: Power control, 2 args, no delay:
      0x01,                     //     Opamp current small
      0x02,                     //     Boost frequency
      ST7735_VMCTR1 , 2+DELAY,  // 11: Power control, 2 args + delay:
      0x3C,                     //     VCOMH = 4V
      0x38,                     //     VCOML = -1.1V
      10,                       //     10 ms delay
      ST7735_PWCTR6 , 2      ,  // 12: Power control, 2 args, no delay:
      0x11, 0x15,
      ST7735_GMCTRP1,16      ,  // 13: Magical unicorn dust, 16 args, no delay:
      0x09, 0x16, 0x09, 0x20,   //     (seriously though, not sure what
      0x21, 0x1B, 0x13, 0x19,   //      these config values represent)
      0x17, 0x15, 0x1E, 0x2B,
      0x04, 0x05, 0x02, 0x0E,
      ST7735_GMCTRN1,16+DELAY,  // 14: Sparkles and rainbows, 16 args + delay:
      0x0B, 0x14, 0x08, 0x1E,   //     (ditto)
      0x22, 0x1D, 0x18, 0x1E,
      0x1B, 0x1A, 0x24, 0x2B,
      0x06, 0x06, 0x02, 0x0F,
      10,                       //     10 ms delay
      ST7735_CASET  , 4      ,  // 15: Column addr set, 4 args, no delay:
      0x00, 0x02,               //     XSTART = 2
      0x00, 0x81,               //     XEND = 129
      ST7735_RASET  , 4      ,  // 16: Row addr set, 4 args, no delay:
      0x00, 0x02,               //     XSTART = 1
      0x00, 0x81,               //     XEND = 160
      ST7735_NORON  ,   DELAY,  // 17: Normal display on, no args, w/delay
      10,                       //     10 ms delay
      ST7735_DISPON ,   DELAY,  // 18: Main screen turn on, no args, w/delay
      255 };                    //     255 = 500 ms delay

static const uint8_t Rcmd1[] = {// Init for 7735R, part 1 (red or green tab)
      15,                       // 15 commands in list:
      ST7735_SWRESET,   DELAY,  //  1: Software reset, 0 args, w/delay
      150,                      //     150 ms delay
      ST7735_SLPOUT ,   DELAY,  //  2: Out of sleep mode, 0 args, w/delay
      255,                      //     500 ms delay
      ST7735_FRMCTR1, 3      ,  //  3: Frame rate ctrl - normal mode, 3 args:
      0x01, 0x2C, 0x2D,         //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
      ST7735_FRMCTR2, 3      ,  //  4: Frame rate control - idle mode, 3 args:
      0x01, 0x2C, 0x2D,         //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
      ST7735_FRMCTR3, 6      ,  //  5: Frame rate ctrl - partial mode, 6 args:
      0x01, 0x2C, 0x2D,         //     Dot inversion mode
      0x01, 0x2C, 0x2D,         //     Line inversion mode
      ST7735_INVCTR , 1      ,  //  6: Display inversion ctrl, 1 arg, no delay:
      0x07,                     //     No inversion
      ST7735_PWCTR1 , 3      ,  //  7: Power control, 3 args, no delay:
      0xA2,
      0x02,                     //     -4.6V
      0x84,                     //     AUTO mode
      ST7735_PWCTR2 , 1      ,  //  8: Power control, 1 arg, no delay:
      0xC5,                     //     VGH25 = 2.4C VGSEL = -10 VGH = 3 * AVDD
      ST7735_PWCTR3 , 2      ,  //  9: Power control, 2 args, no delay:
      0x0A,                     //     Opamp current small
      0x00,                     //     Boost frequency
      ST7735_PWCTR4 , 2      ,  // 10: Power control, 2 args, no delay:
      0x8A,                     //     BCLK/2, Opamp current small & Medium low
      0x2A,  
      ST7735_PWCTR5 , 2      ,  // 11: Power control, 2 args, no delay:
      0x8A, 0xEE,
      ST7735_VMCTR1 , 1      ,  // 12: Power control, 1 arg, no delay:
      0x0E,
      ST7735_INVOFF , 0      ,  // 13: Don't invert display, no args, no delay
      ST7735_MADCTL , 1      ,  // 14: Memory access control (directions), 1 arg:
      0xC8,                     //     row addr/col addr, bottom to top refresh
      ST7735_COLMOD , 1      ,  // 15: set color mode, 1 arg, no delay:
      0x05 };                   //     16-bit color

static const uint8_t Rcmd2green[] = { // Init for 7735R, part 2 (green tab only)
      2,                        //  2 commands in list:
      ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x02,               //     XSTART = 0
      0x00, 0x7F+0x02,          //     XEND = 127
      ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x01,               //     XSTART = 0
      0x00, 0x9F+0x01 };        //     XEND = 159

static const uint8_t Rcmd2red[] = { // Init for 7735R, part 2 (red tab only)
      2,                        //  2 commands in list:
      ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x7F,               //     XEND = 127
      ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x9F };             //     XEND = 159

static const uint8_t Rcmd2green144[] = {              // Init for 7735R, part 2 (green 1.44 tab)
      2,                        //  2 commands in list:
      ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x7F,               //     XEND = 127
      ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x7F };             //     XEND = 127

static const uint8_t Rcmd2green160x80[] = {              // Init for 7735R, part 2 (mini 160x80)
      2,                        //  2 commands in list:
      ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x7F,               //     XEND = 79
      ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x00,               //     XSTART = 0
      0x00, 0x9F };             //     XEND = 159


static const uint8_t Rcmd3[] = { // Init for 7735R, part 3 (red or green tab)
      4,                        //  4 commands in list:
      ST7735_GMCTRP1, 16      , //  1: Magical unicorn dust, 16 args, no delay:
      0x02, 0x1c, 0x07, 0x12,
      0x37, 0x32, 0x29, 0x2d,
      0x29, 0x25, 0x2B, 0x39,
      0x00, 0x01, 0x03, 0x10,
      ST7735_GMCTRN1, 16      , //  2: Sparkles and rainbows, 16 args, no delay:
      0x03, 0x1d, 0x07, 0x06,
      0x2E, 0x2C, 0x29, 0x2D,
      0x2E, 0x2E, 0x37, 0x3F,
      0x00, 0x00, 0x02, 0x10,
      ST7735_NORON  ,    DELAY, //  3: Normal display on, no args, w/delay
      10,                       //     10 ms delay
      ST7735_DISPON ,    DELAY, //  4: Main screen turn on, no args w/delay
      100 };                    //     100 ms delay

/**
 * Companion code to the above tables.  Reads and issues
 * a series of LCD commands stored in PROGMEM byte array.
 */
void Adafruit_ST7735::commandList(const uint8_t *list) {

   uint8_t  numCommands, numArgs;
   uint16_t ms;

   numCommands = *(list++);          // Number of commands to follow
   while(numCommands--) {            // For each command...
      writecommand(*list++);         //   Read, issue command
      numArgs  = *(list++);          //   Number of args to follow
      ms       = numArgs & DELAY;    //   If hibit set, delay follows args
      numArgs &= ~DELAY;             //   Mask out delay bit
      while(numArgs--) {             //   For each argument...
         writedata8(*(list++));       //     Read, issue argument
      }

      if(ms) {
         ms = *(list++);             // Read post-command delay time (ms)
         if(ms == 255) ms = 500;     // If 255, delay for 500 ms
         waitMS(ms);
      }
   }
}

/**
 * Initialization for ST7735B screens
 */
void Adafruit_ST7735::initB(void) {
   commandList(Bcmd);

   setRotation(0);
}

/**
 * Initialization for ST7735R screens (green or red tabs)
 */
void Adafruit_ST7735::initR(DisplayType options) {
   commandList(Rcmd1);

   if(options == INITR_GREENTAB) {
      commandList(Rcmd2green);
      colstart = 2;
      rowstart = 1;
   } else if(options == INITR_144GREENTAB) {
      fHeight = ST7735_TFTHEIGHT_128;
      fWidth  = ST7735_TFTWIDTH_128;
      commandList(Rcmd2green144);
      colstart = 2;
      rowstart = 3;
   } else if(options == INITR_MINI160x80) {
      fHeight = ST7735_TFTHEIGHT_160;
      fWidth  = ST7735_TFTWIDTH_80;
      commandList(Rcmd2green160x80);
      colstart = 24;
      rowstart = 0;
   } else {
      // colstart, rowstart left at default '0' values
      commandList(Rcmd2red);
   }
   commandList(Rcmd3);

   // if black, change MADCTL color filter
   if ((options == INITR_BLACKTAB) || (options == INITR_MINI160x80)) {
      writecommand(ST7735_MADCTL);
      writedata8(0xC0);
   }

   tabcolor = options;

   setRotation(0);
}


void Adafruit_ST7735::setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {

   writecommand(ST7735_CASET); // Column addr set
   writedata8(0x00);
   writedata8(x0+xstart);     // XSTART
   writedata8(0x00);
   writedata8(x1+xstart);     // XEND

   writecommand(ST7735_RASET); // Row addr set
   writedata8(0x00);
   writedata8(y0+ystart);     // YSTART
   writedata8(0x00);
   writedata8(y1+ystart);     // YEND

   writecommand(ST7735_RAMWR); // write to RAM
}


void Adafruit_ST7735::pushColor(uint16_t color) {
   writedata16(color);
}

void Adafruit_ST7735::drawPixel(int x, int y, USBDM::Color color) {

   if((x < 0) ||(x >= fWidth) || (y < 0) || (y >= fHeight)) return;
   setAddrWindow(x,y,x+1,y+1);
   writedata16(color);
}


void Adafruit_ST7735::drawFastVLine(int x, int y, int h,
      uint16_t color) {

   // Rudimentary clipping
   if((x >= fWidth) || (y >= fHeight)) return;
   if((y+h-1) >= fHeight) h = fHeight-y;
   setAddrWindow(x, y, x, y+h-1);
   filldata16(color, h);
}


void Adafruit_ST7735::drawFastHLine(int x, int y, int w, uint16_t color) {

   // Rudimentary clipping
   if((x >= fWidth) || (y >= fHeight)) return;
   if((x+w-1) >= fWidth)  w = fWidth-x;
   setAddrWindow(x, y, x+w-1, y);
   filldata16(color, w);
}



void Adafruit_ST7735::fillScreen(uint16_t color) {
   fillRect(0, 0,  fWidth, fHeight, color);
}

// fill a rectangle
void Adafruit_ST7735::fillRect(int x, int y, int w, int h, uint16_t color) {

   // rudimentary clipping (drawChar w/big text requires this)
   if((x >= fWidth) || (y >= fHeight)) return;
   if((x + w - 1) >= fWidth)  w = fWidth  - x;
   if((y + h - 1) >= fHeight) h = fHeight - y;

   setAddrWindow(x, y, x+w-1, y+h-1);
   filldata16(color, h*w);
}

#define MADCTL_MY  0x80
#define MADCTL_MX  0x40
#define MADCTL_MV  0x20
#define MADCTL_ML  0x10
#define MADCTL_RGB 0x00
#define MADCTL_BGR 0x08
#define MADCTL_MH  0x04

void Adafruit_ST7735::setRotation(uint8_t m) {

   writecommand(ST7735_MADCTL);
   rotation = m % 4; // can't be higher than 3
   switch (rotation) {
      case 0:
         if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80)) {
            writedata8(MADCTL_MX | MADCTL_MY | MADCTL_RGB);
         } else {
            writedata8(MADCTL_MX | MADCTL_MY | MADCTL_BGR);
         }

         if (tabcolor == INITR_144GREENTAB) {
            fHeight = ST7735_TFTHEIGHT_128;
            fWidth  = ST7735_TFTWIDTH_128;
         } else if (tabcolor == INITR_MINI160x80)  {
            fHeight = ST7735_TFTHEIGHT_160;
            fWidth = ST7735_TFTWIDTH_80;
         } else {
            fHeight = ST7735_TFTHEIGHT_160;
            fWidth  = ST7735_TFTWIDTH_128;
         }
         xstart = colstart;
         ystart = rowstart;
         break;
      case 1:
         if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80)) {
            writedata8(MADCTL_MY | MADCTL_MV | MADCTL_RGB);
         } else {
            writedata8(MADCTL_MY | MADCTL_MV | MADCTL_BGR);
         }

         if (tabcolor == INITR_144GREENTAB)  {
            fWidth = ST7735_TFTHEIGHT_128;
            fHeight = ST7735_TFTWIDTH_128;
         } else if (tabcolor == INITR_MINI160x80)  {
            fWidth = ST7735_TFTHEIGHT_160;
            fHeight = ST7735_TFTWIDTH_80;
         } else {
            fWidth = ST7735_TFTHEIGHT_160;
            fHeight = ST7735_TFTWIDTH_128;
         }
         ystart = colstart;
         xstart = rowstart;
         break;
      case 2:
         if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80)) {
            writedata8(MADCTL_RGB);
         } else {
            writedata8(MADCTL_BGR);
         }

         if (tabcolor == INITR_144GREENTAB) {
            fHeight = ST7735_TFTHEIGHT_128;
            fWidth  = ST7735_TFTWIDTH_128;
         } else if (tabcolor == INITR_MINI160x80)  {
            fHeight = ST7735_TFTHEIGHT_160;
            fWidth = ST7735_TFTWIDTH_80;
         } else {
            fHeight = ST7735_TFTHEIGHT_160;
            fWidth  = ST7735_TFTWIDTH_128;
         }
         xstart = colstart;
         ystart = rowstart;
         break;
      case 3:
         if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80)) {
            writedata8(MADCTL_MX | MADCTL_MV | MADCTL_RGB);
         } else {
            writedata8(MADCTL_MX | MADCTL_MV | MADCTL_BGR);
         }

         if (tabcolor == INITR_144GREENTAB)  {
            fWidth = ST7735_TFTHEIGHT_128;
            fHeight = ST7735_TFTWIDTH_128;
         } else if (tabcolor == INITR_MINI160x80)  {
            fWidth = ST7735_TFTHEIGHT_160;
            fHeight = ST7735_TFTWIDTH_80;
         } else {
            fWidth = ST7735_TFTHEIGHT_160;
            fHeight = ST7735_TFTWIDTH_128;
         }
         ystart = colstart;
         xstart = rowstart;
         break;
   }
}

void Adafruit_ST7735::invertDisplay(bool i) {
   writecommand(i ? ST7735_INVON : ST7735_INVOFF);
}

} // end namespace USBDM
