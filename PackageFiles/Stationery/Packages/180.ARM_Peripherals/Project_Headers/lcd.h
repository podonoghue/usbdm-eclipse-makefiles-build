/****************************************************************************************************//**
 * @file     Lcd.h
 *
 * @brief    Abstraction layer for Lcd interface
 *
 * @version  V1.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef INCLUDES_LCD_H_
#define INCLUDES_LCD_H_

#include <stdint.h>
#include "Delay.h"
#include "spi.h"
#include "fonts.h"

namespace USBDM {

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// Lcd Options ==============================
//
//   <o> Lcd PWM Backlight support
//   <i> Enables the use of PWM to adjust the Lcd backlight
//   <i> This ties up one of the FTMs so is rather expensive to provide.
//     <0=> Backlight on/off only
//     <1=> Backlight adjustable
//     <0=> Default
/**
 * Controls if PWM feature is available for backlight
 */
#define LCD_BACKLIGHT_PWM_FEATURE 0

//------------- <<< end of configuration section >>> -----------------------

/**
 * Indicates the code should be for a ELEC FREAKS version of the Lcd
 */
#define ELEC_FREAKS

/**
 * @addtogroup LCD_Group Elecfreaks Liquid Crystal Display
 * @brief C++ Class allowing access Lcd
 * @{
 */

//********************************************************************
//
//   Lcd Dimension Definitions
//
//********************************************************************
constexpr int ROW_LENGTH   = 132;
constexpr int COL_HEIGHT   = 132;
constexpr int ENDPAGE      = 132;
constexpr int ENDCOL       = 130;

// Usable area
constexpr int LCD_X_MIN    = 1;
constexpr int LCD_X_MAX    = 130;
constexpr int LCD_Y_MIN    = 1;
constexpr int LCD_Y_MAX    = 130;

//*******************************************************
//   12-Bit Color Definitions
//*******************************************************
constexpr int BLACK        = 0x000;
constexpr int NAVY         = 0x008;
constexpr int BLUE         = 0x00F;
constexpr int TEAL         = 0x088;
constexpr int EMERALD      = 0x0C5;
constexpr int GREEN        = 0x0F0;
constexpr int CYAN         = 0x0FF;
constexpr int SLATE        = 0x244;
constexpr int INDIGO       = 0x408;
constexpr int TURQUOISE    = 0x4ED;
constexpr int OLIVE        = 0x682;
constexpr int MAROON       = 0x800;
constexpr int PURPLE       = 0x808;
constexpr int GRAY         = 0x888;
constexpr int SKYBLUE      = 0x8CE;
constexpr int BROWN        = 0xB22;
constexpr int CRIMSON      = 0xD13;
constexpr int ORCHID       = 0xD7D;
constexpr int RED          = 0xF00;
constexpr int MAGENTA      = 0xF0F;
//constexpr int ORANGE  =  0xF40
constexpr int PINK         = 0xF6A;
constexpr int CORAL        = 0xF75;
constexpr int SALMON       = 0xF87;
constexpr int ORANGE       = 0xFA0;
constexpr int GOLD         = 0xFD0;
constexpr int YELLOW       = 0xFF0;
constexpr int WHITE        = 0xFFF;

//*******************************************************
//       Circle Definitions
//*******************************************************
constexpr int SECTOR_0_45      = 0x01;
constexpr int SECTOR_45_90     = 0x02;
constexpr int SECTOR_90_135    = 0x04;
constexpr int SECTOR_135_180   = 0x08;
constexpr int SECTOR_180_225   = 0x10;
constexpr int SECTOR_225_270   = 0x20;
constexpr int SECTOR_270_315   = 0x40;
constexpr int SECTOR_315_360   = 0x80;

constexpr int QUAD_NORTH_EAST  = (SECTOR_0_45|SECTOR_45_90);
constexpr int QUAD_NORTH_WEST  = (SECTOR_90_135|SECTOR_135_180);
constexpr int QUAD_SOUTH_WEST  = (SECTOR_180_225|SECTOR_225_270);
constexpr int QUAD_SOUTH_EAST  = (SECTOR_270_315|SECTOR_315_360);

constexpr int FULLCIRCLE       = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
constexpr int OPENSOUTH        = (QUAD_NORTH_EAST|QUAD_NORTH_WEST);
constexpr int OPENNORTH        = (QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
constexpr int OPENEAST         = (QUAD_NORTH_WEST|QUAD_SOUTH_WEST);
constexpr int OPENWEST         = (QUAD_NORTH_EAST|QUAD_SOUTH_EAST);
constexpr int OPENNORTHEAST    = (QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
constexpr int OPENNORTHWEST    = (QUAD_NORTH_EAST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
constexpr int OPENSOUTHEAST    = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_WEST);
constexpr int OPENSOUTHWEST    = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST);

constexpr int DEFAULT_BACKGROUND = BLACK;
constexpr int DEFAULT_FOREGROUND = WHITE;

constexpr int DEFAULT_LCD_CONTRAST = 65;

/**
 * @brief Class representing an LCD
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 *	Lcd *lcd = new Lcd(new SPI_0());
 *
 * lcd->clear(RED);
 * lcd->drawCircle(65, 65, 20, WHITE);
 * lcd->drawCircle(65, 65, 30, WHITE);
 * lcd->drawCircle(65, 65, 40, WHITE);
 * lcd->putStr("Some Circles", 30, 10, Fonts::FontSmall, WHITE, RED);
 *
 *  @endcode
 */
class LcdBase {
protected:
   Spi *spi;   //!< SPI interface used to communicate with LCD

   /**
    * Reset LCD
    */
   virtual void reset() = 0;

   /**
    * Send a single command byte to the display
    */
   virtual void txCommand(uint8_t command) = 0;

   /**
    * Send a single data byte to the display
    */
   virtual void txData(uint8_t data) = 0;

   /** Sets the Row and Column addresses
    *
    * @param x = row address (0 .. 131)
    * @param y = column address (0 .. 131)
    *
    * @author James P Lynch July 7, 2007
    */
   void setXY(int x, int y);

   /**
    *  Initialises the LCD
    */
   void init();

public:
   /**
    *  Constructor
    *
    *  @param spi The SPI interface to use to communicate with LCD
    */
   LcdBase(Spi *spi) : spi(spi) {
   }

#ifdef ELEC_FREAKS
   /**
    * Set backlight level
    *
    * @param level back-light level as percentage
    * @note  Requires @ref LCD_BACKLIGHT_PWM_FEATURE to be fully implemented.\n
    * Otherwise it falls back to basic on/off
    *
    * Note : Only of elecfreaks version of shield
    */
   virtual void backlightSetLevel(int level) = 0;
   /**
    * Turn LCD backlight on
    */
   void backlightOn(void) { backlightSetLevel(100); }
   /**
    * Turn LCD backlight off
    */
   void backLightOff(void) { backlightSetLevel(0); }
#endif

   /** Set LCD contrast - range varies with device
    *
    *  @param setting contrast level (0..127) ?
    */
   virtual void setContrast(uint8_t setting);

   /** This function will clear the screen to the given color.
    *
    * @param color   12-bit color value rrrrggggbbbb
    *
    * @author James P Lynch July 7, 2007
    */
   void clear(int color=DEFAULT_BACKGROUND);

   /** Lights a single pixel in the specified color at the specified x and y addresses
    *
    * @param  x     row address (0 .. 131)
    * @param  y     column address (0 .. 131)
    * @param  color 12-bit color value rrrrggggbbbb
    *
    * @note See lcd.h for some sample color settings
    *
    * @author James P Lynch July 7, 2007
    */
   void drawPixel(int x, int y, int color=DEFAULT_FOREGROUND);

   /** Draws a line in the specified color from (x0,y0) to (x1,y1)
    *
    * @param  x0     row address (0 .. 131)
    * @param  y0     column address (0 .. 131)
    * @param  x1     row address (0 .. 131)
    * @param  y1     column address (0 .. 131)
    * @param  color  12-bit color value rrrrggggbbbb
    *
    * @author James P Lynch July 7, 2007
    *
    * @note See lcd.h for some sample color settings
    *
    * @note Good write-up on this algorithm in Wikipedia (search for Bresenham's line algorithm)\n
    * Authors: \n
    *   - Dr. Leonard McMillan, Associate Professor UNC \n
    *   - Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
    *
    * @note Taken verbatim from Professor McMillan's presentation: \n
    *       http://www.cs.unc.edu/~mcmillan/comp136/Lecture6/Lines.html
    */
   void drawLine(int x0, int y0, int x1, int y1, int color=DEFAULT_FOREGROUND);

   /** Draws a rectangle in the specified color from (x1,y1) to (x2,y2)\n
    *  Rectangle can be filled with a color if desired
    *
    * @param  x0     row address (0 .. 131)
    * @param  y0     column address (0 .. 131)
    * @param  x1     row address (0 .. 131)
    * @param  y1     column address (0 .. 131)
    * @param  fill   indicates if the rectangle will be filled
    * @param  color  12-bit color value rrrrggggbbbb
    *
    * @note See lcd.h for some sample color settings
    *
    * @author James P Lynch July 7, 2007
    *
    */
   void drawRect(int x0, int y0, int x1, int y1, int fill, int color=DEFAULT_FOREGROUND);

   /** Draws a line circle in the specified colour at center (x0,y0) with radius
    *
    * @param centreX = row address (0 .. 131)
    * @param centreY = column address (0 .. 131)
    * @param radius = radius in pixels
    * @param color = 12-bit colour value rrrrggggbbbb
    * @param circleType = controls which segments of the circle are drawn
    *
    * @author Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
    *
    * @note Taken verbatim Wikipedia article on Bresenham's line algorithm \n
    *        http://www.wikipedia.org
    */
   void drawCircle(int centreX, int centreY, int radius, int color, int circleType=FULLCIRCLE);
   /** Writes the entire LCD screen from a bmp file
    *
    * @param bmp - bitmap to display
    *
    * @author Olimex, James P Lynch July 7, 2007
    *
    * @note Use Olimex BmpToArray.exe utility to create bitmap
    */
   void drawBitmap(uint8_t bmp[131*131]);
   /** Draws an ASCII character at the specified (x,y) address and color
    *
    * @param c          character to be displayed
    * @param x          row address (0 .. 131)
    * @param y          column address (0 .. 131)
    * @param fontSize   font pitch (SMALL, MEDIUM, LARGE)
    * @param fColor     12-bit foreground color value
    * @param bColor     12-bit background color value
    *
    * @code{.c}
    *   Notes: Here's an example to display "E" at address (20,20)
    *
    *   LCDPutChar('E', 20, 20, Lcd::FontMedium, WHITE, BLACK);
    *
    *                (27,20)       (27,27)
    *                   |             |
    *                   |             |
    *                 ^ V             V
    *                 | _ # # # # # # #   0x7F
    *                 | _ _ # # _ _ _ #   0x31
    *                 | _ _ # # _ # _ _   0x34
    *                 x _ _ # # # # _ _   0x3C
    *                 | _ _ # # _ # _ _   0x34
    *                 | _ _ # # _ _ _ #   0x31
    *                 | _ # # # # # # #   0x7F
    *                 | _ _ _ _ _ _ _ _   0x00
    *
    *                   ------y------->
    *                   ^             ^
    *                   |             |
    *                   |             |
    *                (20,20)       (20,27)
    * @endcode
    *
    *  @author James P Lynch July 7, 2007
    */
   void putChar(char c, int x, int y, Fonts::FontSize fontSize=Fonts::FontSmall, int fColor=DEFAULT_FOREGROUND, int bColor=DEFAULT_BACKGROUND);

   /** Draws a null-terminated character string at the specified (x,y) address and color
    *
    * @param pString = pointer to character string to be displayed
    * @param x = row address (0 .. 131)
    * @param y = column address (0 .. 131)
    * @param fontSize = font pitch (Lcd::FontSmall, Lcd::FontMedium, Lcd::FontLarge)
    * @param fColor = 12-bit foreground colour value rrrrggggbbbb
    * @param bColor = 12-bit background colour value rrrrggggbbbb
    *
    * @code{.c}
    *       // Here's an example to display "Hello World!" at address (20,20)
    *
    *       lcd_putStr("Hello World!", 20, 20, WHITE, BLACK);
    * @endcode
    *
    * @author James P Lynch, August 30, 2007 \n
    *         Edited by Peter Davenport on August 23, 2010
    *
    * @note For more information on how this code does it's thing look at this \n
    *       "http://www.sparkfun.com/tutorial/Nokia%206100%20LCD%20Display%20Driver.pdf"
    */
   void putStr(const char *pString, int x, int y, Fonts::FontSize fontSize=Fonts::FontSmall, int fColor=DEFAULT_FOREGROUND, int bColor=DEFAULT_BACKGROUND);

};

/**
 * Template for LCD
 *
 * tparam SpiCS_n   Display CS     (D9 on Arduino)
 * tparam Reset_n   Display reset  (D8 on Arduino)
 * tparam BackLight Display back-light control (may be PWM) (D10 on Arduino)
 */
template<typename SpiCS_n, typename Reset_n, typename BackLight>
class Lcd_T : public LcdBase {
public:
   /**
    *  Constructor
    *
    *  Initialises the LCD
    *
    *  @param spi The SPI interface to use to communicate with LCD
    */
   Lcd_T(Spi *spi) : LcdBase(spi) {
      // Chip select pin
      SpiCS_n::setOutput();
      SpiCS_n::set();         // Set idle high

      // LCD Reset pin
      Reset_n::setOutput();
      init();
   }

   /**
    * Reset LCD
    */
   virtual void reset() {
      // Reset display
      Reset_n::clear();
      waitMS(2);
      Reset_n::set();
      waitMS(10);
   }
   /**
    * Send a single command byte to the display
    */
   virtual void txCommand(uint8_t command) {
      SpiCS_n::clear();
      spi->txRx(command);
      SpiCS_n::set();
   }

   /**
    * Send a single data byte to the display
    */
   virtual void txData(uint8_t data) {
      SpiCS_n::clear();
      spi->txRx(0x100|data);
      SpiCS_n::set();
   }

#ifdef ELEC_FREAKS
   /**
    * Set back-light level
    *
    * @param level 0-100 back-light level as percentage
    */
   virtual void backlightSetLevel(int level) {
#if LCD_BACKLIGHT_PWM_FEATURE
      BackLight::setMode(1000, PwmIO::ftm_leftAlign);
      if (level>100) {
         level = 100;
      }
      if (level<0) {
         level = 0;
      }
      BackLight::setDutyCycle(level);
#else
      BackLight::setOutput(USBDM::GPIO_DEFAULT_PCR|PORT_PCR_DSE_MASK);
      BackLight::write(level>0);
#endif
   }
#endif

};

/**
 *   Convenience type for typical Arduino shield LCD
 */
#if LCD_BACKLIGHT_PWM_FEATURE
// PWM control for back-light brightness
using Lcd = Lcd_T<USBDM::gpio_D9, USBDM::gpio_D8, USBDM::ftm_D10>;
#else
// On/Off control of back-light
using Lcd = Lcd_T<USBDM::gpio_D9, USBDM::gpio_D8, USBDM::gpio_D10>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDES_LCD_H_ */
