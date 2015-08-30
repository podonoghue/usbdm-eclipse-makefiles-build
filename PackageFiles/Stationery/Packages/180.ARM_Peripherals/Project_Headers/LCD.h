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
 *  // Instantiate interface
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
   SPI *spi;   //!< SPI interface to LCD

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

   /** Set LCD contrast - varies with device
    *
    *  @param setting - contrast level (0..127) ?
    */
   void setContrast(uint8_t setting);
   /** This function will clear the screen to the given color.
    *
    * @param color   12-bit color value rrrrggggbbbb
    *
    * @author James P Lynch July 7, 2007
    */
   void clear(int color=DEFAULT_BACKGROUND);

   /** Set LCD contrast - varies with device
    *
    * @param  x      row address (0 .. 131)
    * @param  y      column address (0 .. 131)
    * @param  color  12-bit color value rrrrggggbbbb
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
    * @note See LCD.h for some sample color settings
    *
    * @author James P Lynch July 7, 2007
    *
    * @note Good write-up on this algorithm in Wikipedia (search for Bresenham's line algorithm)
    * @note See LCD.h for some sample color settings
    *
    * @author Authors: Dr. Leonard McMillan, Associate Professor UNC \n
    *                  Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
    *
    * @note Taken verbatim from Professor McMillan's presentation: \n
    *       http://www.cs.unc.edu/~mcmillan/comp136/Lecture6/Lines.html
    */
   void drawLine(int x0, int y0, int x1, int y1, int color=DEFAULT_FOREGROUND);
   /** Draws a rectangle in the specified color from (x1,y1) to (x2,y2)
    *  Rectangle can be filled with a color if desired
    *
    * param  x0     row address (0 .. 131)
    * param  y0     column address (0 .. 131)
    * param  x1     row address (0 .. 131)
    * param  y1     column address (0 .. 131)
    * param  color  12-bit color value rrrrggggbbbb
    *
    * note See LCD.h for some sample color settings
    *
    * author James P Lynch July 7, 2007
    *
    * note
    *    The best way to fill a rectangle is to take advantage of the "wrap-around" feature
    *    built into the Philips PCF8833 controller. By defining a drawing box, the memory can
    *    be simply filled by successive memory writes until all pixels have been illuminated.
    *
    *    1. Given the coordinates of two opposing corners (x0, y0) (x1, y1)
    *       calculate the minimums and maximums of the coordinates
    *
    *       xmin = (x0 <= x1) ? x0 : x1;
    *       xmax = (x0 > x1) ? x0 : x1;
    *       ymin = (y0 <= y1) ? y0 : y1;
    *       ymax = (y0 > y1) ? y0 : y1;
    *
    *    2. Now set up the drawing box to be the desired rectangle
    *
    *       LCDCommand(PASET); // set the row boundaries
    *       LCDData(xmin);
    *       LCDData(xmax);
    *       LCDCommand(CASET); // set the column boundaries
    *       LCDData(ymin);
    *       LCDData(ymax);
    *
    *    3. Calculate the number of pixels to be written divided by 2
    *
    *       NumPixels = ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1)
    *
    *       You may notice that I added one pixel to the formula.
    *       This covers the case where the number of pixels is odd and we
    *       would lose one pixel due to rounding error. In the case of
    *       odd pixels, the number of pixels is exact.
    *       in the case of even pixels, we have one more pixel than
    *       needed, but it cannot be displayed because it is outside
    *       the drawing box.
    *
    *       We divide by 2 because two pixels are represented by three bytes.
    *       So we work through the rectangle two pixels at a time.
    *
    *    4. Now a simple memory write loop will fill the rectangle
    *
    *       for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) {
    *          LCDData((color >> 4) & 0xFF);
    *          LCDData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
    *          LCDData(color & 0xFF);
    *       }
    *
    *       In the case of an unfilled rectangle, drawing four lines with the Bresenham line
    *       drawing algorithm is reasonably efficient.
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
   /** Writes the entire LCD screen from a bmp file
    *  Uses Olimex BmpToArray.exe utility
    *
    * @param bmp - bitmap to display
    *
    * @author Olimex, James P Lynch July 7, 2007
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
    * @verbatim
    * Notes: Here's an example to display "E" at address (20,20)
    *
    *           LCDPutChar('E', 20, 20, LCD::FontMedium, WHITE, BLACK);
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
    *
    *
    *    The most efficient way to display a character is to make use of the "wrap-around" feature
    *    of the Philips PCF8833 LCD controller chip.
    *
    *    Assume that we position the character at (20, 20) that's a (row, col) specification.
    *    With the row and column address set commands, you can specify an 8x8 box for the SMALL and MEDIUM
    *    characters or a 16x8 box for the LARGE characters.
    *
    *            spi_txCommand(PASET);   // set the row drawing limits
    *            spi_txData(20);         //
    *            spi_txData(27);         // limit rows to (20, 27)
    *
    *            spi_txCommand(CASET);   // set the column drawing limits
    *            spi_txData(20);         //
    *            spi_txData(27);         // limit columns to (20,27)
    *
    *    When the algorithm completes col 27, the column address wraps back to 20
    *    At the same time, the row address increases by one (this is done by the controller)
    *
    *    We walk through each row, two pixels at a time. The purpose is to create three
    *    data bytes representing these two pixels in the following format (as specified by Philips
    *    for RGB 4 : 4 : 4 format (see page 62 of PCF8833 controller manual).
    *
    *            Data for pixel 0: RRRRGGGGBBBB
    *            Data for Pixel 1: RRRRGGGGBBBB
    *
    *            spi_txCommand(RAMWR);                 // start a memory write (96 data bytes to follow)
    *
    *            spi_txData(RRRRGGGG);                 // first pixel, red and green data
    *            spi_txData(BBBBRRRR);                 // first pixel, blue data; second pixel, red data
    *            spi_txData(GGGGBBBB);                 // second pixel, green and blue data
    *            :
    *            and so on until all pixels displayed!
    *            :
    *            spi_txCommand(NOP);                   // this will terminate the RAMWR command
    *
    *  @endverbatim
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
    * @note Here's an example to display "Hello World!" at address (20,20) \n
    *       lcd_putStr("Hello World!", 20, 20, WHITE, BLACK);
    *
    * @author James P Lynch, August 30, 2007 \n
    *         Edited by Peter Davenport on August 23, 2010
    *
    * @note For more information on how this code does it's thing look at this \n
    *       "http://www.sparkfun.com/tutorial/Nokia%206100%20LCD%20Display%20Driver.pdf"
    */
   void putStr(const char *pString, int x, int y, Fonts::FontSize fontSize=Fonts::FontSmall, int fColor=DEFAULT_FOREGROUND, int bColor=DEFAULT_BACKGROUND);
   /** Sets the Row and Column addresses
    *
    * @param x = row address (0 .. 131)
    * @param y = column address (0 .. 131)
    *
    * @author James P Lynch July 7, 2007
    */
   void setXY(int x, int y);

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
};

/**
 * @}
 */

#endif /* LCD_H */
