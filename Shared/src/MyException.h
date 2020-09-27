/*
 * MyException.hpp
 *
 *  Created on: 24/02/2010
 *      Author: podonoghue
 */
#ifndef MYEXCEPTION_HPP_
#define MYEXCEPTION_HPP_

#include <string>
#include <stdexcept>

#include "USBDM_API.h"
#include "UsbdmSystem.h"

#ifdef __GNUC__
#pragma GCC visibility push(default)
#endif

class MyException : public std::runtime_error {

public:
   MyException(const std::string &msg) : runtime_error(msg) {
#ifdef LOG
      UsbdmSystem::Log::print("Exception: %s\n", this->what());
#endif
   }
   MyException(USBDM_ErrorCode rc) : runtime_error(USBDM_GetErrorString(rc)) {
#ifdef LOG
      UsbdmSystem::Log::print("Exception: %s\n", this->what());
#endif
   }
};

#ifdef __GNUC__
#pragma GCC visibility pop
#endif

#endif /* MYEXCEPTION_HPP_ */
