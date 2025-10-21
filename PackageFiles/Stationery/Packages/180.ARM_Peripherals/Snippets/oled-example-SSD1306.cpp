/******************************************************************************
 * @file    oled-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic OLED example
 *
 *  Requires declarations for the following in Configure.usbdmProject
 *
 *  Fixed I2C specific connections
 *  SCL         SCL  (PTB.0/A5)
 *  SDA         SDA  (PTB.1/A4)
 *
 *  Power
 *  GND
 *  VCC
 ******************************************************************************/
#include "hardware.h"
#include "oled_SSD1306.h"

using namespace USBDM;

// I2C interface connecting to OLED
I2c0 i2c{};

Oled_SSD1306<ScaleMode_1, RotateMode_0, MirrorMode_None> oled{i2c};

/**
 * Draws two open rectangles of 1 pixel line thickness enclosing a 1 pixel height
 * rectangle in centre of screen by drawing orthogonal lines.
 * The centre pixel is filled.
 */
void testOrthogonalLines() {

   for(;;) {
      const unsigned y  = oled.height/2;
      const unsigned x0 = oled.width/10;
      const unsigned x1 = 9*oled.width/10;
      const unsigned x  = oled.width/2;
      const unsigned y0 = oled.height/10;
      const unsigned y1 = 9*oled.height/10;

      oled.clear(BLACK);
      oled.setColour(WHITE);
      oled.drawLine(x0,   y-1, x1,   y-1);
      oled.drawLine(x0,   y,   x0+1, y);
      oled.drawLine(x1-1, y,   x1,   y);
      oled.drawLine(x0,   y+1, x1,   y+1);
      oled.drawLine(x-1, y0,   x-1, y1);
      oled.drawLine(x,   y0,   x,   y0+1);
      oled.drawLine(x,   y1-1, x,   y1);
      oled.drawLine(x+1, y0,   x+1, y1);

      oled.drawPixel(x, y, WHITE);
      oled.flushOutput();
      waitMS(1000);
   }
}

void testLines() {

   for(;;) {

      oled.setFont(font16x24);
      oled.clear(BLACK);
      oled.setColour(WHITE);
      oled.setWriteMode(WriteMode_Write);
      for (unsigned i=0; i<oled.height; i++) {
         oled.drawLine(0, 0, oled.width, i);
         oled.flushOutput();
      }
      oled.setWriteMode(WriteMode_Xor);
      oled.writeln("Hello");
      oled.writeln("Bye Bye");
      oled.flushOutput();
      waitMS(5000);

      oled.clear(BLACK);
      oled.setWriteMode(WriteMode_Write);
      for (unsigned i=0; i<oled.width; i++) {
         oled.drawLine(oled.width-1, oled.height-1, i, 0);
         oled.flushOutput();
      }
      oled.setWriteMode(WriteMode_Xor);
      oled.writeln("Hello");
      oled.writeln("Bye Bye");
      oled.flushOutput();
      waitMS(5000);
   }
}

int main() {

   testLines();
   testOrthogonalLines();

   oled.setWriteMode(WriteMode_Write);
   oled.setFont(font16x24);
   oled.setColour(WHITE);
   oled.clear(BLACK);
   oled.writeln("Hello There");
   oled.writeln("Bye Bye");
   oled.flushOutput();
   waitMS(1000);

   oled.clear(WHITE);
   oled.setColour(BLACK);
   oled.writeln("Hello There");
   oled.writeln("Bye Bye");
   oled.flushOutput();
   waitMS(1000);

   return 0;
}
