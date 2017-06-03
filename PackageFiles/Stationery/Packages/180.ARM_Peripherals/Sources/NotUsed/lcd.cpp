/*
 * lcd.cpp
 *
 *  Created on: 1 Jun 2017
 *      Author: podonoghue
 */

#include "lcd.h"

namespace USBDM {

/**
 * Draws a filled rectangle
 *
 * @param x       Top-left
 * @param y       Top-right
 * @param width   Width of rectangle
 * @param height  Height of rectangle
 * @param color   Color
 */
void Lcd::fillRect(int x0, int y0, int x1, int y1, Color fill, Color color) {
   for (int xx=x0; xx<x1; xx++) {
      for (int yy=y0; yy<y1; yy++) {
         drawPixel(xx,yy,color);
      }
   }
}

/**
 * Fills the screen with one color
 *
 * @param color   Color
 */
void Lcd::fillScreen(Color color) {
   fillRect(0, 0, fWidth-1, fHeight-1, color);
}

/** Draws a line in the specified color from (x0,y0) to (x1,y1)
 *
 * @param x0       Top-left-X
 * @param y0       Top-left-Y
 * @param x1       Bottom-right-X
 * @param y1       Bottom-right-Y
 * @param color    Color
 */
void Lcd::drawLine(int x0, int y0, int x1, int y1, Color color) {
   int dy = y1 - y0;
   int dx = x1 - x0;
   int stepx, stepy;
   if (dy < 0) {
      dy = -dy;
      stepy = -1;
   } else {
      stepy = 1;
   }
   if (dx < 0) {
      dx = -dx;
      stepx = -1;
   } else {
      stepx = 1;
   }
   dy <<= 1; // dy is now 2*dy
   dx <<= 1; // dx is now 2*dx
   drawPixel(x0, y0, color);
   if (dx > dy) {
      int fraction = dy - (dx >> 1); // same as 2*dy - dx
      while (x0 != x1) {
         if (fraction >= 0) {
            y0 += stepy;
            fraction -= dx; // same as fraction -= 2*dx
         }
         x0 += stepx;
         fraction += dy; // same as fraction -= 2*dy
         drawPixel(x0, y0, color);
      }
   } else {
      int fraction = dx - (dy >> 1);
      while (y0 != y1) {
         if (fraction >= 0) {
            x0 += stepx;
            fraction -= dy;
         }
         y0 += stepy;
         fraction += dx;
         drawPixel(x0, y0, color);
      }
   }
}

void Lcd::putChar(char c, int x, int y, Font &font, Color fColor, Color bColor) {
   const uint8_t *data = &font.data[(c-' ')*font.bytesPerChar];
   for (int yy=0; yy<font.height; yy++) {
      for (int xx=0; xx<font.width; xx++) {
         drawPixel(x+xx, y+yy, (data[yy]&(1<<xx))?fColor:bColor);
         if ((x+xx)>fWidth) {
            break;
         }
      }
      if ((y+yy)>fHeight) {
         break;
      }
   }
}

void Lcd::putStr(const char *str, int x, int y, Font &font, Color fColor, Color bColor) {

   while (*s != '\0') {
      // Draw the character
      putChar(*str++, x, y, font, fColor, bColor);

      // Advance the x position
      x += font.width;

      // Clip at right
      if (x > fWidth) break;
   }
}

void Lcd::drawCircle(int centreX, int centreY, int radius, Color color, int circleType) {
   int f = 1 - radius;
   int ddF_x = 0;
   int ddF_y = -2 * radius;
   int x = 0;
   int y = radius;

   if (circleType&(SECTOR_315_360|SECTOR_0_45)) {
      drawPixel(centreX + radius, centreY, color);  // 0,360
   }
   if (circleType&(SECTOR_45_90|SECTOR_90_135)) {
      drawPixel(centreX, centreY + radius, color);  // 90
   }
   if (circleType&(SECTOR_135_180|SECTOR_180_225)) {
      drawPixel(centreX - radius, centreY, color);  // 180
   }
   if (circleType&(SECTOR_225_270|SECTOR_270_315)) {
      drawPixel(centreX, centreY - radius, color);  // 270
   }
   while (x < y) {
      if (f >= 0) {
         y--;
         ddF_y += 2;
         f += ddF_y;
      }
      x++;
      ddF_x += 2;
      f += ddF_x + 1;
      if (circleType&SECTOR_0_45) {
         drawPixel(centreX + y, centreY + x, color);   // 0-45
      }
      if (circleType&SECTOR_45_90) {
         drawPixel(centreX + x, centreY + y, color);   // 45-90
      }
      if (circleType&SECTOR_90_135) {
         drawPixel(centreX - x, centreY + y, color);   // 90-135
      }
      if (circleType&SECTOR_135_180) {
         drawPixel(centreX - y, centreY + x, color);   // 135-180
      }
      if (circleType&SECTOR_180_225) {
         drawPixel(centreX - y, centreY - x, color);   // 180-225
      }
      if (circleType&SECTOR_225_270) {
         drawPixel(centreX - x, centreY - y, color);   // 225-270
      }
      if (circleType&SECTOR_270_315) {
         drawPixel(centreX + x, centreY - y, color);   // 270-315
      }
      if (circleType&SECTOR_315_360) {
         drawPixel(centreX + y, centreY - x, color);   // 315-360
      }
   }
}

}; // end namespace USBDM

