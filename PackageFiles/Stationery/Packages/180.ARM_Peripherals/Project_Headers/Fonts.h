#ifndef FONTS_H
#define FONTS_H

#include <stdint.h>

struct Fonts {
public:
   /**
    * Font sizes
    */
   typedef enum {FontSmall, FontMedium, FontLarge} FontSize;

   static const uint8_t FONT6x8[97][8];
   static const uint8_t FONT8x8[97][8];
   static const uint8_t FONT8x16[97][16];
};

#endif /* FONTS_H */
