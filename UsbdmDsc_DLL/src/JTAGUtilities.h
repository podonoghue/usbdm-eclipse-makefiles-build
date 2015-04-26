/*
 * JTAGUtilities.hpp
 *
 *  Created on: 29/03/2011
 *      Author: podonoghue
 */

#ifndef JTAGUTILITIES_HPP_
#define JTAGUTILITIES_HPP_
#include <list>
USBDM_ErrorCode jtagIdentifyCommand(unsigned &numDevice, std::list<uint32_t> &deviceList);
#endif /* JTAGUTILITIES_HPP_ */
