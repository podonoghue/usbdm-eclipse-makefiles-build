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

int main() {

   static const FontSettings textFont1(fontSmall, WHITE, BLACK);
   static const FontSettings textFont2(fontMedium, BLACK, WHITE);
   static const FontSettings textFont3(fontLarge, RED, BLUE);

   static const char text[] = {
         "Lorem ipsum dolor sit amet, conse"
         "ctetur adipiscing elit. Donec in n"
         "unc quis enim blandit bibendum. Al"
         "iquam sed mauris id massa ornare c"
         "onsectetur ac ut "
   };
   for(;;) {
      lcd.setTextSettings(textFont1);
      lcd.moveXY(0,LCD_Y_MAX-textFont1.font->height).write(text).write(text).write(text);
      waitMS(2000);

      lcd.setTextSettings(textFont2);
      lcd.moveXY(0,LCD_Y_MAX-textFont2.font->height).write(text).write(text);
      waitMS(2000);

      lcd.setTextSettings(textFont3);
      lcd.moveXY(0,LCD_Y_MAX-textFont3.font->height).write(text);
      waitMS(2000);
   }
}
