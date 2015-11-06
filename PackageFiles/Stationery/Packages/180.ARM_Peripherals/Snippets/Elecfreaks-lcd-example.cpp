#include <stdlib.h>
#include "LCD.h"
#include "SPI.h"
#include "delay.h"

/**
 * Example demonstrating Elecfreaks LCD shield
 *
 * You may need to change the pin-mapping of the SPI interface
 * for a particular FRDM board
 *
 */

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


int main() {
   SPI *spi = new $(demo.cpp.lcd.spi)();
   spi->setSpeed(1000000);
   LCD *lcd = new LCD(spi);

   lcd->clear(BACKGROUND_COLOUR);
   lcd->putStr("Some Circles", 30, 10, Fonts::FontSmall, FOREGROUND_COLOUR, BACKGROUND_COLOUR);

   // Cursor position on screen
   int x=0, y=0;
   int xOld=0, yOld=0;

   for(;;) {
      x = LCD_X_MIN + CIRCLE_RADIUS + rand() % (LCD_WIDTH-2*CIRCLE_RADIUS);
      y = LCD_Y_MIN + CIRCLE_RADIUS + rand() % (LCD_HEIGHT-2*CIRCLE_RADIUS);
      waitMS(50);
      lcd->drawCircle(xOld, yOld, CIRCLE_RADIUS, BACKGROUND_COLOUR);
      lcd->drawCircle(x, y, CIRCLE_RADIUS, FOREGROUND_COLOUR);
      xOld = x;
      yOld = y;
   }
   for(;;) {
   }
}
