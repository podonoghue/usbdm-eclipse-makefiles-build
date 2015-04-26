/*
 * FlashProgrammerFactory.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_FLASHPROGRAMMERFACTORY_H_
#define SRC_FLASHPROGRAMMERFACTORY_H_

#include "FlashProgrammer.h"

class FlashProgrammerFactory {
public:
   static FlashProgrammerPtr createFlashProgrammer(BdmInterfacePtr bdmInterface);

protected:
   FlashProgrammerFactory() {};
   ~FlashProgrammerFactory() {};
};

#endif /* SRC_FLASHPROGRAMMERFACTORY_H_ */
