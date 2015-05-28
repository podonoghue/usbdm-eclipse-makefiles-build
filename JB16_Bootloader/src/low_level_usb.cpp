/*! \file
    \brief Low-level USB interface to BDM module .

    \verbatim
    USBDM - USB communication DLL
    Copyright (C) 2008  Peter O'Donoghue

    Based on:
    Turbo BDM Light - USB communication
    Copyright (C) 2005  Daniel Malik

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
   +=========================================================================
   |  31 Mar 2011 | Added command toggle
   |  21 Dec 2010 | Fixed 1-off validation of device number in bdm_usb_open()
   |   8 Nov 2010 | Changed USB retry strategy to use BDM_RC_BUSY
   |  20 Oct 2010 | Added libusb_clear_halt() calls to reset data toggle
   |   1 Aug 2009 | Modified extensively for new format USB comms
   |   1 Aug 2009 | Fixed input range validation in bdm_usb_open()
   |   1 Jan 2009 | Extensive changes to fold TBDML & OSBDM together
   +==========================================================================
    \endverbatim
*/

#include <stdio.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#include "libusb.h"
#else
#include <libusb-1.0/libusb.h>
#include <time.h>
#include <errno.h>
#endif
#include "UsbdmSystem.h"
#include "hwdesc.h"
#include "Common.h"
#include "low_level_usb.h"
#include "Names.h"

#ifndef LIBUSB_SUCCESS
#define LIBUSB_SUCCESS (0)
#endif

#ifdef __unix__
const char *libusb_error_name(int errNo) {
      switch (errNo) {

      /** Success (no error) */
      case LIBUSB_SUCCESS:
         return "LIBUSB_SUCCESS";
      /** Input/output error */
      case LIBUSB_ERROR_IO:
         return "LIBUSB_ERROR_IO";
      /** Invalid parameter */
      case LIBUSB_ERROR_INVALID_PARAM:
         return "LIBUSB_ERROR_INVALID_PARAM";
      /** Access denied (insufficient permissions) */
      case LIBUSB_ERROR_ACCESS:
         return "LIBUSB_ERROR_ACCESS";
      /** No such device (it may have been disconnected) */
      case LIBUSB_ERROR_NO_DEVICE:
         return "LIBUSB_ERROR_NO_DEVICE";
      /** Entity not found */
      case LIBUSB_ERROR_NOT_FOUND:
         return "LIBUSB_ERROR_NOT_FOUND";
      /** Resource busy */
      case LIBUSB_ERROR_BUSY:
         return "LIBUSB_ERROR_BUSY";
      /** Operation timed out */
      case LIBUSB_ERROR_TIMEOUT:
         return "LIBUSB_ERROR_TIMEOUT";
      /** Overflow */
      case LIBUSB_ERROR_OVERFLOW:
         return "LIBUSB_ERROR_OVERFLOW";
      /** Pipe error */
      case LIBUSB_ERROR_PIPE:
         return "LIBUSB_ERROR_PIPE";
      /** System call interrupted (perhaps due to signal) */
      case LIBUSB_ERROR_INTERRUPTED:
         return "LIBUSB_ERROR_INTERRUPTED";
      /** Insufficient memory */
      case LIBUSB_ERROR_NO_MEM:
         return "LIBUSB_ERROR_NO_MEM";
      /** Operation not supported or unimplemented on this platform */
      case LIBUSB_ERROR_NOT_SUPPORTED:
         return "LIBUSB_ERROR_NOT_SUPPORTED";
      /** Other error */
      case LIBUSB_ERROR_OTHER:
         return "LIBUSB_ERROR_OTHER";
      default:
         return "LIBUSB_ERROR_????";
      }
}
#endif

#ifdef LOG
// Uncomment for copious log of low-level USB transactions
//#define LOG_LOW_LEVEL
#endif

#define EP_CONTROL_OUT (LIBUSB_ENDPOINT_OUT|0) //!< EP # for Control Out endpoint
#define EP_CONTROL_IN  (LIBUSB_ENDPOINT_IN |0) //!< EP # for Control In endpoint

#define EP_OUT (LIBUSB_ENDPOINT_OUT|1) //!< EP # for Out endpoint
#define EP_IN  (LIBUSB_ENDPOINT_IN |2) //!< EP # for In endpoint

// Maximum number of BDMs recognized
#define MAX_BDM_DEVICES (10)

static unsigned int timeoutValue = 1000; // us

// Count of devices found
static unsigned deviceCount = 0;

// Pointers to all BDM devices found. Terminated by NULL pointer entry
static struct libusb_device *bdmDevices[MAX_BDM_DEVICES+1] = {NULL};

// Handle of opened device
static libusb_device_handle *usbDeviceHandle = NULL;

// Indicates LIBUSB has been initialized
static bool initialised = FALSE;

//**********************************************************
//!
//! Sleep for given number of milliseconds (or longer!)
//!
//! @param milliSeconds - number of milliseconds to sleep
//!

void milliSleep(int milliSeconds) {

#ifdef __unix__
   LOGGING_Q;
   int rc;
   struct timespec sleepStruct = { 0, 1000000L*milliSeconds };
   log.print("%ld ns\n", sleepStruct.tv_nsec);
   do {
      rc = nanosleep(&sleepStruct, &sleepStruct);
      if ((rc < 0) && (errno == EINTR))
         log.print("milliSleep() - Sleep interrupted\n");
      else if (sleepStruct.tv_sec > 0)
         log.print("milliSleep() - time not completed!!\n");
   } while ((rc < 0) && (errno == EINTR));
#else
   Sleep(milliSeconds);
#endif
}

libusb_context *context;

//**********************************************************
//!
//! Initialisation of low-level USB interface
//!
//!  @return\n
//!       RC_OK        - success \n
//!       ICP_RC_USB_ERROR - various errors
//!
ICP_ErrorType bdm_usb_init( void ) {
   LOGGING;

   // Not initialised
   initialised = FALSE;

   // Clear array of devices found so far
   for (int i=0; i<=MAX_BDM_DEVICES; i++) {
      bdmDevices[i] = NULL;  // Clear the list of devices
   }
   deviceCount = 0;

#ifdef LOG
#ifdef WIN32
   const struct libusb_version* version;
   version = libusb_get_version();
   log.print("Using libusb v%d.%d.%d.%d\n", version->major, version->minor, version->micro, version->nano);
#endif
#endif
   // Initialise LIBUSB
   context = 0;
   if (libusb_init(&context) != LIBUSB_SUCCESS) {
      log.error("libusb_init() Failed\n");
      return ICP_RC_USB_ERROR;
   }
   initialised = TRUE;
   return RC_OK;
}

//**********************************************************
//!
//! De-initialise low-level USB interface
//!
//!  @return\n
//!       BDM_RC_OK        - success \n
//!       BDM_RC_USB_ERROR - various errors
//!

ICP_ErrorType bdm_usb_exit( void ) {
   LOGGING;
   if (initialised) {
      bdm_usb_close();     // Close any open devices
      libusb_exit(context);
      log.print("libusb_exit() called\n");
   }
   initialised = false;
   return RC_OK;
}

//**********************************************************
//!
//! Release all devices referenced by bdm_usb_findDevices
//!
//!  @return\n
//!       RC_OK        - success \n
//!

ICP_ErrorType bdm_usb_releaseDevices(void) {
   LOGGING;

   if (!initialised) {
      return ICP_RC_DEVICE_NOT_OPEN;
   }

   // Unreference all devices
   for(unsigned index=0; index<deviceCount; index++) {
      log.print("Unreferencing #%d\n", index);
      if (bdmDevices[index] != NULL) {
         libusb_unref_device(bdmDevices[index]);
      }
      bdmDevices[index] = NULL;
   }
   deviceCount = 0;
   return RC_OK;
}

//**********************************************************
//!
//! Find all USBDM devices attached to the computer
//!
//!  @param deviceCount Number of devices found.  This is set
//!                     to zero on any error.
//!
//!  @return\n
//!       RC_OK        - success - found at least 1 device \n
//!       ICP_RC_USB_ERROR - no device found or various errors
//!

ICP_ErrorType bdm_usb_findDevices(unsigned *devCount, uint16_t vid, uint16_t pid) {
   LOGGING;
   log.print("Looking for device VID=%4.4X, PID=%4.4X\n",vid, pid);

   *devCount = 0; // Assume failure

   // Release any currently referenced devices
   bdm_usb_releaseDevices();

   // discover all USB devices
   libusb_device **list;

   ssize_t cnt = libusb_get_device_list(context, &list);
   if (cnt < 0) {
      log.error("libusb_get_device_list() failed! \n");
      return ICP_RC_USB_ERROR;
   }

   // Copy the ones we are interested in to our own list
   deviceCount = 0;
   for (int deviceIndex=0; deviceIndex<cnt; deviceIndex++) {
      // Check each device and copy any USBDMs to local list
//      log.print("bdm_usb_find_devices() ==> checking device #%d\n", deviceIndex);
      libusb_device *currentDevice = list[deviceIndex];
      libusb_device_descriptor deviceDescriptor;
      int rc = libusb_get_device_descriptor(currentDevice, &deviceDescriptor);
      if (rc != LIBUSB_SUCCESS) {
         continue; // Skip device
      }
      log.print("Checking device VID=%4.4X, PID=%4.4X\n",
            deviceDescriptor.idVendor, deviceDescriptor.idProduct);
      if ((deviceDescriptor.idVendor==vid)&&(deviceDescriptor.idProduct==pid)) {
         // Found a device

         uint8_t busNumber = libusb_get_bus_number(currentDevice);
         uint8_t address   = libusb_get_device_address(currentDevice);
         log.print("Found USBDM device, List[%d] = #%d, dev#=%d, addr=%d\n", deviceCount, deviceIndex, busNumber, address);
         bdmDevices[deviceCount++] = currentDevice; // Record found device
         libusb_ref_device(currentDevice);          // Reference so we don't lose it
         bdmDevices[deviceCount]=NULL;              // Terminate the list again
         if (deviceCount>MAX_BDM_DEVICES) {
            break;
         }
      }
   }
   // Free the original list (devices referenced above are still referenced)
   libusb_free_device_list(list, true);

   *devCount = deviceCount;

   if(deviceCount>0) {
      return RC_OK;
   }
   else {
      return ICP_RC_NO_JS16_DEVICE;
   }
}

//**********************************************************
//!
//! Open connection to device enumerated by bdm_usb_find_devices()
//!
//! @param device_no Device number to open
//!
//! @return \n
//!    == RC_OK (0)     => Success\n
//!    == ICP_RC_USB_ERROR  => USB failure
//!

ICP_ErrorType bdm_usb_open( unsigned int device_no ) {
   LOGGING;
   if (!initialised) {
      return ICP_RC_USB_ERROR;
   }
   if (device_no >= deviceCount) {
      log.error("Illegal device #\n");
      return ICP_RC_ILLEGAL_PARAMS;
   }
   if (usbDeviceHandle != NULL) {
      log.print("bdm_usb_open() - Closing previous device\n");
      bdm_usb_close();
   }
   int rc = libusb_open(bdmDevices[device_no], &usbDeviceHandle);

   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_open() failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
      usbDeviceHandle = NULL;
      return ICP_RC_USB_ERROR;
      }
   int configuration = 0;
   rc = libusb_get_configuration(usbDeviceHandle, &configuration);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_get_configuration() failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
   }
//   log.print("libusb_get_configuration() done\n");
   if (configuration != 1) {
      rc = libusb_set_configuration(usbDeviceHandle, 1);
      if (rc != LIBUSB_SUCCESS) {
         log.error("libusb_set_configuration(1) failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
         // Release the device
         libusb_close(usbDeviceHandle);
         usbDeviceHandle = NULL;
         return ICP_RC_USB_ERROR;
      }
//      log.print("libusb_set_configuration() done\n");
   }
   rc = libusb_claim_interface(usbDeviceHandle, 0);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_claim_interface(0) failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
      // Release the device
      libusb_set_configuration(usbDeviceHandle, 0);
      libusb_close(usbDeviceHandle);
      usbDeviceHandle = NULL;
      return ICP_RC_USB_ERROR;
   }
//   log.print("libusb_claim_interface() done\n");
   rc = libusb_clear_halt(usbDeviceHandle, EP_IN);
   if (rc != LIBUSB_SUCCESS) {
      // Ignore
      log.error("libusb_clear_halt(...,EP_IN(0x%02X)) failed, rc = %s\n", EP_IN, libusb_error_name((libusb_error)rc));
   }
   rc = libusb_clear_halt(usbDeviceHandle, EP_OUT);
   if (rc != LIBUSB_SUCCESS) {
      // Ignore
      log.error("libusb_clear_halt(...,EP_OUT(0x%02X)) failed, rc = %s\n", EP_OUT, libusb_error_name((libusb_error)rc));
   }
   return (RC_OK);
}

//**********************************************************
//!
//! Closes connection to the currently open device
//!
//! @return RC_OK => success (ignores errors)
//!

ICP_ErrorType bdm_usb_close( void ) {
   int rc;
   LOGGING;

   if (usbDeviceHandle == NULL) {
      log.print("Device not open - no action\n");
      return RC_OK;
   }
   rc = libusb_release_interface(usbDeviceHandle, 0);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_release_interface() failed, rc = %s\n", libusb_error_name((libusb_error)rc));
   }
   int configValue;
   rc = libusb_get_configuration(usbDeviceHandle, &configValue);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_get_configuration() failed, rc = %s\n", libusb_error_name((libusb_error)rc));
   }
   // Unconfigure BDM
   // I know the libusb documentation says to use -1 but this ends up being passed
   // to the USB device WHICH IS NOT A GOOD THING!
   //#ifdef xWIN32
   //   rc = libusb_set_configuration(usbDeviceHandle, 0);
   //#else
   //   rc = libusb_set_configuration(usbDeviceHandle, -1);
   //#endif
   //   if (rc != LIBUSB_SUCCESS) {
   //      log.error("libusb_set_configuration(-1) failed, rc = %s\n", libusb_error_name((libusb_error)rc));
   //   }
   libusb_close(usbDeviceHandle);
   usbDeviceHandle = NULL;
   return RC_OK;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

/*! \brief Sends a message+data to the Device in ICP mode
 *
 *  No response is expected from device.
 *
 *  Since the EP0 transfer is unidirectional in this case, data returned by the
 *  device must be read in a separate transfer - this includes any status.
 *
 * @param request
 * @param wValue
 * @param wIndex
 * @param size
 * @param data
 *
 * @return
 *   == 0 => USB transfer OK \n
 *   != 0 => USB transfer Failed
 *
*/

ICP_ErrorType bdm_usb_raw_send_ep0(  unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     const unsigned char *data) {
   int rc;
   LOGGING_Q;

if (usbDeviceHandle == NULL) {
      log.error("Device not open\n");
      return ICP_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("[%2.2X, %2.2X, %4.4X, %4.4X, %4.4X]\n",
         LIBUSB_REQUEST_TYPE_VENDOR|EP_CONTROL_OUT, request, wValue, wIndex, size);
#endif
   rc = libusb_control_transfer(usbDeviceHandle,
            LIBUSB_REQUEST_TYPE_VENDOR|EP_CONTROL_OUT,      // bmRequestType
            request,                                        // bRequest
            wValue,                                         // value
            wIndex,                                         // index
            (unsigned char*)data,                           // data
            size,                                           // size (# of data bytes)
            timeoutValue);                                  // how long to wait for reply
   if (rc < 0) {
      log.error("Send failed (USB error = %s)\n", libusb_error_name((libusb_error)rc));
      return(ICP_RC_USB_ERROR);
   }
   return(RC_OK);
}

//! \brief Sends a message+data to the Device in ICP mode
//!
//!  An immediate response is expected from device.
//!
//!  Since the EP0 transfer is unidirectional in this case, data returned by the
//!  device must be read in a separate transfer - this includes any status.
//!
//!  @param request
//!  @param wValue
//!  @param wIndex
//!  @param size
//!  @param data
//!
//!  @return \n
//!     == RC_OK (0)     => Success, OK response from device\n
//!     == ICP_RC_USB_ERROR  => USB failure \n
//!     == else              => Error code from Device
//!

ICP_ErrorType bdm_usb_raw_recv_ep0(  unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     unsigned char *data) {
   int rc;
   LOGGING_Q;
   if (usbDeviceHandle == NULL) {
      log.error("Device not open\n");
      data[0] = ICP_RC_DEVICE_NOT_OPEN;
      return ICP_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("[%2.2X, %2.2X, %4.4X, %4.4X, %4.4X]\n",
         LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_ENDPOINT_IN, request, wValue, wIndex, size);
#endif
   rc = libusb_control_transfer(usbDeviceHandle,
            LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_ENDPOINT_IN,  // bmRequestType
            request,                                        // bRequest
            wValue,                                         // value
            wIndex,                                         // index
            (unsigned char*)data,                           // data
            size,                                           // size (# of data bytes)
            timeoutValue);                                  // how long to wait for reply

   if (rc < 0) {
      log.error("Transaction failed (USB error = %s)\n", libusb_error_name((libusb_error)rc));
      return ICP_RC_USB_ERROR;
   }
#ifdef LOG_LOW_LEVEL
   if (size >0) {
      log.print("[%2.2X", data[0]);
      for(unsigned i=1; i<size; i++) {
         log.printq("%2.2X", data[i]);
      }
      log.printq("]\n");
   }
#endif
   return RC_OK;
}

