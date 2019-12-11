/** \file
    \brief Factory for FlashImage

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   |    Apr 2015 | Created
   +====================================================================
    \endverbatim
*/
#ifndef SOURCE_FLASHIMAGEFACTORY_H_
#define SOURCE_FLASHIMAGEFACTORY_H_

#include "PluginFactory.h"
#include "FlashImage.h"

/**
 * Factory class for flash images
 */
class FlashImageFactory : public PluginFactory<FlashImage> {
private:
   FlashImageFactory() {}
   ~FlashImageFactory() {}

public:
   /**
    * Creates a flash image for the given target type
    *
    * @param targetType Type of target for which image is to be created
    */
   static FlashImagePtr createFlashImage(TargetType_t targetType) {
      LOGGING;
      FlashImagePtr pp = createPlugin(DLL_NAME("usbdm-flash-image"), "createPluginInstance");
      pp->setTargetType(targetType);
      return pp;
   }
};

#endif /* SOURCE_FLASHIMAGEFACTORY_H_ */
