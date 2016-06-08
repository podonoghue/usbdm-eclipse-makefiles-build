/**
 * \mainpage Elecfreaks Colour LCD shield demonstration
 *
 * \section introSection Introduction
 * This is a simple example of the use of the C++ library routines for the Elecfreaks LCD shield displays.\n
 *
 * It may be necessary to change pin mappings to use this example.\n
 * Open Configure.usbdmProject to change these.\n\n
 *
 * Refer to the individual files for license conditions as they vary.
 *
 * <hr>
 * \subsection QuickLinks Quick Links
 *
 *   - @htmlonly <a href="http://www.elecfreaks.com/estore/color-lcd-shield-shd-cls.html"><b>Elecfreaks LCD shield</b></a> @endhtmlonly
 */
#include <stdlib.h>
#include "lcd.h"
#include "spi.h"
#include "delay.h"

using namespace USBDM;

/// LCD derived dimensions
#define LCD_WIDTH  (LCD_X_MAX-LCD_X_MIN)
#define LCD_HEIGHT (LCD_Y_MAX-LCD_Y_MIN)
#define CENTRE_X   ((LCD_X_MAX-LCD_X_MIN)/2)
#define CENTRE_Y   ((LCD_Y_MAX-LCD_Y_MIN)/2)

// Colour for LCD background
#define BACKGROUND_COLOUR (RED)

// Colour for LCD foreground
#define FOREGROUND_COLOUR (WHITE)

// Radius used for the moving circle
#define CIRCLE_RADIUS (20)

/*
 * Draws a cursor on the lcd screen
 *
 * @param lcd     The LCD to draw on
 * @param x       x position
 * @param y       y position
 * @param colour  Colour of cursor
 *
 * @note Done this way so a more sophisticated cursor can be added
 */
void drawCursor(Lcd *lcd, int x, int y, int colour) {
   lcd->drawCircle(x, y, CIRCLE_RADIUS, colour);
//   lcd->drawRect(x-CIRCLE_RADIUS/2, y-CIRCLE_RADIUS/2, x+CIRCLE_RADIUS/2, y+CIRCLE_RADIUS/2, false, colour);
//   lcd->drawRect(x-CIRCLE_RADIUS/2, y-CIRCLE_RADIUS/2, x+CIRCLE_RADIUS/2, y+CIRCLE_RADIUS/2, true, colour);
}

int main() {
   // Instantiate SPI interface class
   Spi *spi = new $(demo.cpp.external.spi:Spi0)();
   // Instantiate LCD interface class
   Lcd *lcd = new Lcd(spi);

   lcd->clear(BACKGROUND_COLOUR);
   lcd->drawCircle(CENTRE_X, CENTRE_Y, 20, WHITE);
   lcd->drawCircle(CENTRE_X, CENTRE_Y, 30, WHITE);
   lcd->drawCircle(CENTRE_X, CENTRE_Y, 40, WHITE);
   lcd->putStr("Some Circles", 30, 10, Fonts::FontSmall, FOREGROUND_COLOUR, BACKGROUND_COLOUR);

   // Cursor position on screen
   int x=0, y=0;
   int xOld=50, yOld=50;

   for(;;) {
      x = LCD_X_MIN + CIRCLE_RADIUS + rand() % (LCD_WIDTH-2*CIRCLE_RADIUS);
      y = LCD_Y_MIN + CIRCLE_RADIUS + rand() % (LCD_HEIGHT-2*CIRCLE_RADIUS);
      waitMS(50);
      drawCursor(lcd, xOld, yOld, BACKGROUND_COLOUR);
      drawCursor(lcd, x, y, FOREGROUND_COLOUR);
      xOld = x;
      yOld = y;
   }
   for(;;) {
   }
}
