/*
 * lcd.h
 *
 *  Created on: 1 Jun 2017
 *      Author: podonoghue
 */
#ifndef SOURCES_LCD_H_
#define SOURCES_LCD_H_

#include "font.h"

namespace USBDM {

using Color = uint16_t;

class Lcd {

   //*******************************************************
   //       Circle Definitions
   //*******************************************************
   static constexpr int SECTOR_0_45      = 0x01;
   static constexpr int SECTOR_45_90     = 0x02;
   static constexpr int SECTOR_90_135    = 0x04;
   static constexpr int SECTOR_135_180   = 0x08;
   static constexpr int SECTOR_180_225   = 0x10;
   static constexpr int SECTOR_225_270   = 0x20;
   static constexpr int SECTOR_270_315   = 0x40;
   static constexpr int SECTOR_315_360   = 0x80;

   static constexpr int QUAD_NORTH_EAST  = (SECTOR_0_45|SECTOR_45_90);
   static constexpr int QUAD_NORTH_WEST  = (SECTOR_90_135|SECTOR_135_180);
   static constexpr int QUAD_SOUTH_WEST  = (SECTOR_180_225|SECTOR_225_270);
   static constexpr int QUAD_SOUTH_EAST  = (SECTOR_270_315|SECTOR_315_360);

   static constexpr int FULLCIRCLE       = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
   static constexpr int OPENSOUTH        = (QUAD_NORTH_EAST|QUAD_NORTH_WEST);
   static constexpr int OPENNORTH        = (QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
   static constexpr int OPENEAST         = (QUAD_NORTH_WEST|QUAD_SOUTH_WEST);
   static constexpr int OPENWEST         = (QUAD_NORTH_EAST|QUAD_SOUTH_EAST);
   static constexpr int OPENNORTHEAST    = (QUAD_NORTH_WEST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
   static constexpr int OPENNORTHWEST    = (QUAD_NORTH_EAST|QUAD_SOUTH_EAST|QUAD_SOUTH_WEST);
   static constexpr int OPENSOUTHEAST    = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_WEST);
   static constexpr int OPENSOUTHWEST    = (QUAD_NORTH_EAST|QUAD_NORTH_WEST|QUAD_SOUTH_EAST);

protected:
   int fWidth;
   int fHeight;

   Lcd(int width, int height) : fWidth(width), fHeight(height) {
   }

   virtual ~Lcd() {
   }

public:
   virtual void fillScreen(Color color);
   virtual void drawPixel(int x, int y, Color color) = 0;
   virtual void fillRect(int x0, int y0, int x1, int y1, Color fill, Color color);
   virtual void drawLine(int x0, int y0, int x1, int y1, Color color);
   virtual void drawCircle(int centreX, int centreY, int radius, Color color, int circleType);
   virtual void putChar(char c, int x, int y, Font &font, Color fColor, Color bColor);
   virtual void putStr(const char *pString, int x, int y, Font &font, Color fColor, Color bColor);
};

}; // end namespace USBDM

#endif /* SOURCES_LCD_H_ */
