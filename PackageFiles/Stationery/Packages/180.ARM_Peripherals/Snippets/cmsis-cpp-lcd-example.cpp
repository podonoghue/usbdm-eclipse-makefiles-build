/**
 ====================================================================================================
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
 *   - @htmlonly <a href=
 *   "http://www.elecfreaks.com/store/color-lcd-shield-shdcls-p-462.html"
 *   ><b>Elecfreaks LCD shield (obsolete)</b></a> @endhtmlonly
 *
 =====================================================================================================
 */
#include <stdlib.h>
#include "cmsis.h"
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

/// LCD derived dimensions
static constexpr int LCD_WIDTH  = (LCD_X_MAX-LCD_X_MIN);
static constexpr int LCD_HEIGHT = (LCD_Y_MAX-LCD_Y_MIN);
static constexpr int CENTRE_X   = ((LCD_X_MAX-LCD_X_MIN)/2);
static constexpr int CENTRE_Y   = ((LCD_Y_MAX-LCD_Y_MIN)/2);

// Colour for LCD background
static constexpr int BACKGROUND_COLOUR = (RED);

// Colour for LCD foreground
static constexpr int FOREGROUND_COLOUR = (WHITE);

class ShapeThread : public CMSIS::ThreadClass {

public:
   ShapeThread() {
   }

protected:
   static CMSIS::Mutex mutex;

   // Radius used for the moving circle
   static constexpr int SHAPE_SIZE = (20);

   /*
    * Draws a shape on the lcd screen
    *
    * @param x       x position
    * @param y       y position
    * @param colour  Colour of cursor
    */
   virtual void drawShape(int x, int y, int colour)  = 0;

   /*
    * Function executed as thread
    */
   virtual void task() override {
      // Cursor position on screen
      int x=0, y=0;
      // Old cursor position on screen
      int xOld=50, yOld=50;

      for(;;) {
         x = LCD_X_MIN + SHAPE_SIZE + rand() % (LCD_WIDTH-2*SHAPE_SIZE);
         y = LCD_Y_MIN + SHAPE_SIZE + rand() % (LCD_HEIGHT-2*SHAPE_SIZE);
         delay(100 /* ms */);
         mutex.lock();
         drawShape(xOld, yOld, BACKGROUND_COLOUR);
         drawShape(x, y, FOREGROUND_COLOUR);
         mutex.unlock();
         xOld = x;
         yOld = y;
      }
   }
};

CMSIS::Mutex ShapeThread:: mutex;

class CircleThread : public ShapeThread {

protected:
   /*
    * Draws a shape on the lcd screen
    *
    * @param x       x position
    * @param y       y position
    * @param colour  Colour of cursor
    */
   virtual void drawShape(int x, int y, int colour) override {
      lcd.drawCircle(x, y, SHAPE_SIZE/2, colour);
   }

};

class SquareThread : public ShapeThread {

protected:
   /*
    * Draws a shape on the lcd screen
    *
    * @param x       x position
    * @param y       y position
    * @param colour  Colour of cursor
    */
   virtual void drawShape(int x, int y, int colour) override {
      lcd.drawRect(x-SHAPE_SIZE/2, y-SHAPE_SIZE/2, x+SHAPE_SIZE/2, y+SHAPE_SIZE/2, false, colour);
   }

};

class TriangleThread : public ShapeThread {

protected:
   /*
    * Draws a shape on the lcd screen
    *
    * @param x       x position
    * @param y       y position
    * @param colour  Colour of cursor
    */
   virtual void drawShape(int x, int y, int colour) override {
      lcd.drawLine(x-SHAPE_SIZE/2, y-SHAPE_SIZE/2, x, y+SHAPE_SIZE/2, colour);
      lcd.drawLine(x+SHAPE_SIZE/2, y-SHAPE_SIZE/2, x, y+SHAPE_SIZE/2, colour);
      lcd.drawLine(x-SHAPE_SIZE/2, y-SHAPE_SIZE/2, x+SHAPE_SIZE/2, y-SHAPE_SIZE/2, colour);
   }

};

CircleThread   circleThread;
SquareThread   squareThread;
TriangleThread triangleThread;

int main() {

   // Draw pretty pattern
   lcd.clear(BACKGROUND_COLOUR);

   circleThread.run();
   squareThread.run();
   triangleThread.run();

   for(;;) {
      lcd.drawCircle(CENTRE_X, CENTRE_Y, 20, FOREGROUND_COLOUR);
      lcd.drawCircle(CENTRE_X, CENTRE_Y, 30, FOREGROUND_COLOUR);
      lcd.drawCircle(CENTRE_X, CENTRE_Y, 40, FOREGROUND_COLOUR);
      lcd.putStr("Some Circles", 30, 10, smallFont, FOREGROUND_COLOUR, BACKGROUND_COLOUR);
   }
}
