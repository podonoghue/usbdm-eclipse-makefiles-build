/*
 * FlashImageFactory.h
 *
 *  Created on: 6 Apr 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_FLASHIMAGEFACTORY_H_
#define SOURCE_FLASHIMAGEFACTORY_H_

#include "PluginFactory.h"
#include "FlashImage.h"

class FlashImageFactory : public PluginFactory<FlashImage> {
private:
   FlashImageFactory() {}
   ~FlashImageFactory() {}

public:
   static FlashImagePtr createFlashImage(TargetType_t targetType) {
      LOGGING;
      FlashImagePtr pp = createPlugin(DLL_NAME("usbdm-flash-image"), "createPluginInstance");
      pp->setTargetType(targetType);
      return pp;
   }
};

#endif /* SOURCE_FLASHIMAGEFACTORY_H_ */
