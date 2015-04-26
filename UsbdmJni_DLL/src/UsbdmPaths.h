/*
 * Paths.h
 *
 *  Created on: 31/01/2013
 *      Author: podonoghue
 */

#ifndef USBDMPATHS_H
#define USBDMPATHS_H

#include <string>

bool getUsbdmResourcePath(std::string &path);
bool getUsbdmApplicationPath(std::string &path);
bool getUsbdmDataPath(std::string &path);

#endif /* USBDMPATHS_H */
