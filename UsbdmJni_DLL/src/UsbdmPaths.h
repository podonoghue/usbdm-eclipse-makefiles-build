/*
 * Paths.h
 *
 *  Created on: 31/01/2013
 *      Author: podonoghue
 */

#ifndef USBDMPATHS_H
#define USBDMPATHS_H

#include <string>

/**
 *  Obtain the path of the resource directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmResourcePath(std::string &path);
/**
 * Obtain the path of the application directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmApplicationPath(std::string &path);
/**
 *  Obtain the path of the configuration directory
 *
 * @param path - Path found
 *
 * @return false if failed
 *
 * @note The configuration directory will be created if it doesn't already exist.
 */
bool getUsbdmDataPath(std::string &path);
/**
 * Obtain registry value
 *
 * @param [in]  regPath       Registry path e.g. "SOFTWARE\\pgo\\USBDM"
 * @param [in]  strValueName  Name of value e.g. "InstallationDirectory"
 *
 * @param [out] value         Value from registry
 *
 * @return false if failed
 */
bool getRegistryValue(std::string &regPath, std::string &strValueName, std::string &value);

#endif /* USBDMPATHS_H */
