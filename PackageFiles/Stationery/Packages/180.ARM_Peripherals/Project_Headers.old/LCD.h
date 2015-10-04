/****************************************************************************************************//**
 * @file     LCD.h
 *
 * @brief    Abstraction layer for I2C interface
 *
 * @version  V0.0
 * @date     2015/06
 *
 *******************************************************************************************************/

#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "SPI.h"
#include "Fonts.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// LCD Options ==============================
//
//   <o> LCD PWM Backlight support
//   <i> Enables the use of PWM to adjust the LCD backlight
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
 * Indicates the code should be for a ELEC FREAKS version of the LCD
 */
#define ELEC_FREAKS

/**
 * @addtogroup LCD_Group Elecfreaks Liquid Crystal Display
 * @brief C++ Class allowing access LCD
 * @{
 */

//********************************************************************
//
//   LCD Dimension Definitions
//
//********************************************************************
#define ROW_LENGTH   132
#define COL_HEIGHT   132
#define ENDPAGE      132
#define ENDCOL       130

// Usable area
#define LCD_X_MIN         (1)
#define LCD_X_MAX         (130)
#define LCD_Y_MIN         (1)
#define LCD_Y_MAX         (130)

//*******************************************************
//   12-Bit Color Definitions
//*******************************************************
#define BLACK     0x000
#define NAVY      0x008
#define BLUE      0x00F
#define TEAL      0x088
#define EMERALD   0x0C5
#define GREEN     0x0F0
#define CYAN      0x0FF
#define SLATE     0x244
#define INDIGO    0x408
#define TURQUOISE 0x4ED
#define OLIVE     0x682
#define MAROON    0x800
#define PURPLE    0x808
#define GRAY      0x888
#define SKYBLUE   0x8CE
#define BROWN     0xB22
#define CRIMSON   0xD13
#define ORCHID    0xD7D
#define RED       0xF00
#define MAGENTA   0xF0F
//#define ORANGE    0xF40
#define PINK      0xF6A
#define CORAL     0xF75
#define SALMON    0xF87
#define ORANGE    0xFA0
#define GOLD      0xFD0
#define YELLOW    0xFF0
#define WHITE     0xFFF

//*******************************************************
//       Circle Definitions
//*******************************************************
#define SECTOR_0_45          0x01
#define SECTOR_45_90         0x02
#define SECTOR_90_135        0x04
#define SECTOR_135_180       0x08
#define SECTOR_180_225       0x10
#define SECTOR_225_270       0x20
#define SECTOR_270_315       0x40
#define SECTOR_315_360       0x80

#define QUAD_NORTH_EAST   (SECTOR_0_45|SECTOR_45_90)
#define QUAD_NORTH_WEST   (SECTOR_90_135|SECTOR_135_180)
#define QUAD_SOUTH_WEST   (SECTOR_180_225|SECTOR_225_270)  
#define QUAD_SOUTH_EAST   (SECTOR_270_315|SECTOR_315_360)

#define FULLCIRCLE    (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST)
#define OPENSOUTH     (QUAD_NORTH_EAST|QUAD_NORTH_WEST)
#define OPENNORTH     (QUAD_SOUTH_EAST|QUAD_SOUTH_WEST)
#define OPENEAST      (QUAD_NORTH_WEST|QUAD_SOUTH_WEST)
#define OPENWEST      (QUAD_NORTH_EAST|QUAD_SOUTH_EAST)
#define OPENNORTHEAST (QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST)
#define OPENNORTHWEST (QUAD_NORTH_EAST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST)
#define OPENSOUTHEAST (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_WEST)
#define OPENSOUTHWEST (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST)

#define DEFAULT_BACKGROUND BLACK
#define DEFAULT_FOREGROUND WHITE

/**
 * @brief Class representing a LCD
 *
 * <b>Example</b>
 * @code
 * // Instantiate interface
 *	LCD *lcd = new LCD(new SPI_0());
 *
 * lcd->clear(RED);
 * lcd->drawCircle(65, 65, 20, WHITE);
 * lcd->drawCircle(65, 65, 30, WHITE);
 * lcd->drawCircle(65, 65, 40, WHITE);
 * lcd->putStr("Some Circles", 30, 10, Fonts::FontSmall, WHITE, RED);
 *
 *  @endcode
 */

class LCD {
   SPI *spi;   //!< SPI interface used to communicate with LCD

public:
   /**
    *  Constructor
    *
    *  Initialises the LCD
    *
    *  @param spi The SPI interface to use to communicate with LCD
    */
   LCD(SPI *spi);

#ifdef ELEC_FREAKS
   // Only on Elecfreaks model
   /**
    * Set backlight level
    *
    * @param level back-light level as percentage
    * @note  Requires @ref LCD_BACKLIGHT_PWM_FEATURE to be fully implemented.\n
    * Otherwise it falls back to basic on/off
    */
   void backlightSetLevel(int level);
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
   void setContrast(uint8_t setting);
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
    * @note See LCD.h for some sample color settings
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
    * @note See LCD.h for some sample color settings
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
    * @note See LCD.h for some sample color settings
    *
    * @author James P Lynch July 7, 2007
    *
    */
   void drawRect(int x0, int y0, int x1, int y1, int fill, int color=DEFAULT_FOREGROUND);

   /** Draws a line circle in the specified colour at center (x0,y0) with radius
    *
    * @param x          row address (0 .. 131)
    * @param y          column address (0 .. 131)
    * @param radius     radius in pixels
    * @param color      12-bit colour value rrrrggggbbbb
    * @param sectors    controls which segments of the circle are drawn
    *
    * @author Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
    *
    * @note Taken verbatim Wikipedia article on Bresenham's line algorithm \n
    *        http://www.wikipedia.org
    */
   void drawCircle(int x, int y, int radius, int color, int sectors=FULLCIRCLE);
   /** Writes the entire LCD screen from a bmp file\n
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
    *   LCDPutChar('E', 20, 20, LCD::FontMedium, WHITE, BLACK);
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
    * @param fontSize = font pitch (LCD::FontSmall, LCD::FontMedium, LCD::FontLarge)
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

private:
   /**
    * Reset LCD
    */
   void reset();
   /**
    * Send a single command byte to the display
    */
   void txCommand(uint8_t command);
   /**
    * Send a single data byte to the display
    */
   void txData(uint8_t data);

   /** Sets the Row and Column addresses
    *
    * @param x = row address (0 .. 131)
    * @param y = column address (0 .. 131)
    *
    * @author James P Lynch July 7, 2007
    */
   void setXY(int x, int y);

};

/**
 * @}
 */

#endif /* LCD_H */
