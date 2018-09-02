/**
 ============================================================================
 * \section ElecfreaksLcd Elecfreaks Colour LCD shield demonstration
 * This is a example of the use of the C++ library routines for the Elecfreaks LCD shield displays.\n
 *
 * It may be necessary to change pin mappings to use this example.\n
 * Open <b>Configure.usbdmProject</b> to change these.\n\n
 *
 * Refer to the individual files for license conditions as they vary.
 *
 * @example elecfreaks-lcd-example.cpp
 *
 * <hr>
 * <b>Quick Links</b>
 *
 *   - @htmlonly <a href="http://www.elecfreaks.com/store/color-lcd-shield-shdcls-p-462.html"><b>Elecfreaks LCD shield (obsolete)</b></a> @endhtmlonly
 *
 ============================================================================
 */
#include <stdlib.h>
#include "lcd.h"
#include "spi.h"
#include "delay.h"

// Access to USBDM name-space
using namespace USBDM;

/* **************************************************
 *  Globally shared objects representing hardware
 * ************************************************ */

// SPI interface
Spi0 spi;

// LCD interface using SPI
Lcd lcd(spi);

/* ************************************************** */

// LCD derived dimensions
static constexpr unsigned LCD_WIDTH  = (LCD_X_MAX-LCD_X_MIN);
static constexpr unsigned LCD_HEIGHT = (LCD_Y_MAX-LCD_Y_MIN);
static constexpr unsigned CENTRE_X   = ((LCD_X_MAX-LCD_X_MIN)/2);
static constexpr unsigned CENTRE_Y   = ((LCD_Y_MAX-LCD_Y_MIN)/2);

// Colour for LCD background
static constexpr Colour BACKGROUND_COLOUR = (RED);

// Colour for LCD foreground
static constexpr Colour FOREGROUND_COLOUR = (WHITE);

// Radius used for the moving circle
static constexpr unsigned CIRCLE_RADIUS = (20);

/*
 * Draws a cursor on the lcd screen
 *
 * @param x       x position
 * @param y       y position
 * @param colour  Colour of cursor
 *
 * @note Done this way so a more sophisticated cursor can be added
 */
void drawCursor(unsigned x, unsigned y, Colour colour) {
   lcd.drawCircle(x, y, CIRCLE_RADIUS, colour);
//   lcd.drawRect(x-CIRCLE_RADIUS/2, y-1, x+CIRCLE_RADIUS/2, y+1, false, colour);
//   lcd.drawRect(x-1, y-CIRCLE_RADIUS/2, x+1, y+CIRCLE_RADIUS/2, false, colour);
}

int main() {

   // Draw pretty pattern
   lcd.clear(BACKGROUND_COLOUR);
   lcd.drawCircle(CENTRE_X, CENTRE_Y, 20, WHITE);
   lcd.drawCircle(CENTRE_X, CENTRE_Y, 30, WHITE);
   lcd.drawCircle(CENTRE_X, CENTRE_Y, 40, WHITE);

   // Set LCD defaults
   lcd.setFont(fontSmall).setForeground(FOREGROUND_COLOUR).setBackground(BACKGROUND_COLOUR);

   // Simple text with position and default font and colours
   lcd.putStr("Some Circles", 30, 10);

   // Change LCD defaults
   lcd.setFont(fontLarge).setForeground(BLUE).setBackground(WHITE);

   // Formatted write to LCD using current defaults
   lcd.moveXY(10, LCD_Y_MAX-fontLarge.height-1)
      .write("max-X=").write(LCD_X_MAX).write(" ");

   // Cursor position on screen
   unsigned x=0, y=0;
   unsigned xOld=50, yOld=50;

   for(;;) {
      x = LCD_X_MIN + CIRCLE_RADIUS + rand() % (LCD_WIDTH-2*CIRCLE_RADIUS);
      y = LCD_Y_MIN + CIRCLE_RADIUS + rand() % (LCD_HEIGHT-2*CIRCLE_RADIUS);
      waitMS(50);
      drawCursor(xOld, yOld, BACKGROUND_COLOUR);
      drawCursor(x, y, FOREGROUND_COLOUR);
      xOld = x;
      yOld = y;
   }
}
