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
   static std::tr1::shared_ptr<FlashImage> createPlugin(std::string dllName) { return FlashImagePtr(); }

public:
   static FlashImagePtr createFlashImage(TargetType_t targetType) {
      LOGGING;
      if (newInstance == 0) {
#ifdef LOG
         loadClass("usbdm-flash-image-debug.4.dll", "createPluginInstance");
#else
         loadClass("usbdm-flash-image.4.dll", "createPluginInstance");
#endif
      }
      FlashImagePtr pp((FlashImage*)(*newInstance)(targetType), deleter);
      instanceCount++;
      return pp;
   }
};

#endif /* SOURCE_FLASHIMAGEFACTORY_H_ */
