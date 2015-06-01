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
   +========================================================================================
   |  31 May 2015 | Removed clear halts as breaks USB3 under linux                   V4.11.1.50
   |  27 Dec 2012 | Changed bdm_usb_recv_epIn() to use geometric backoffs            V4.10.4
   |  30 Nov 2012 | Changed bdmJMxx_usb_transaction() retry method etc               V4.10.4
   |              | Added bdm_usb_reset_connection()
   |   6 May 2012 | Added BDM_RC_DEVICE_OPEN_FAILED error messages
   |  31 Mar 2011 | Added command toggle
   |  21 Dec 2010 | Fixed 1-off validation of device number in bdm_usb_open()
   |   8 Nov 2010 | Changed USB retry strategy to use BDM_RC_BUSY
   |  20 Oct 2010 | Added libusb_clear_halt() calls to reset data toggle
   |   1 Aug 2009 | Modified extensively for new format USB comms
   |   1 Aug 2009 | Fixed input range validation in bdm_usb_open()
   |   1 Jan 2009 | Extensive changes to fold USBDM & OSBDM together
   +========================================================================================
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
#include "USBDM_API.h"
#include "USBDM_API_Private.h"
#include "low_level_usb.h"
#include "Names.h"

#ifndef LIBUSB_SUCCESS
#define LIBUSB_SUCCESS (0)
#endif

//#define RETRY_TEST

#ifdef __unix__
DLL_LOCAL
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


static unsigned int timeoutValue = DEFAULT_USB_TIMEOUT_VALUE; // ms

// Count of devices found
static unsigned deviceCount = 0;

// Pointers to all BDM devices found. Terminated by NULL pointer entry
static struct libusb_device *bdmDevices[MAX_BDM_DEVICES+1] = {NULL};

// Handle of opened device
static libusb_device_handle *usbDeviceHandle = NULL;

// Indicates LIBUSB has been initialized
static bool initialised = FALSE;

libusb_context *context;

//**********************************************************
//!
//! Initialisation of low-level USB interface
//!
//!  @return\n
//!       BDM_RC_OK        - success \n
//!       BDM_RC_USB_ERROR - various errors
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_init( void ) {
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
   int rc = libusb_init(&context);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_init() Failed, rc=%d, %s\n", rc, libusb_error_name(rc));
      return BDM_RC_USB_ERROR;
   }
   initialised = TRUE;
   return BDM_RC_OK;
}

//**********************************************************
//!
//! De-initialise low-level USB interface
//!
//!  @return\n
//!       BDM_RC_OK        - success \n
//!       BDM_RC_USB_ERROR - various errors
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_exit( void ) {
   LOGGING;
   if (initialised) {
      bdm_usb_close();     // Close any open devices
      libusb_exit(context);
      log.print("libusb_exit() called\n");
   }
   initialised = false;
   return BDM_RC_OK;
}

//**********************************************************
//!
//! Release all devices referenced by bdm_usb_findDevices
//!
//!  @return\n
//!       BDM_RC_OK        - success \n
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_releaseDevices(void) {
   LOGGING;

   if (!initialised) {
      return BDM_RC_NOT_INITIALISED;
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
   return BDM_RC_OK;
}

//**********************************************************
//!
//! Find all USBDM devices attached to the computer
//!
//!  @param deviceCount Number of devices found.  This is set
//!                     to zero on any error.
//!
//!  @return\n
//!       BDM_RC_OK        - success - found at least 1 device \n
//!       BDM_RC_USB_ERROR - no device found or various errors
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_findDevices(unsigned *devCount) {
   LOGGING;
   *devCount = 0; // Assume failure

   // Release any currently referenced devices
   bdm_usb_releaseDevices();

   // discover all USB devices
   libusb_device **list;

   ssize_t cnt = libusb_get_device_list(context, &list);
   if (cnt < 0) {
      log.error("libusb_get_device_list() failed! \n");
      return BDM_RC_USB_ERROR;
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
//      log.print("bdm_usb_find_devices() ==> Checking device VID=%4.4X, PID=%4.4X\n",
//            deviceDescriptor.idVendor, deviceDescriptor.idProduct);
      if (((deviceDescriptor.idVendor==USBDM_VID)&&(deviceDescriptor.idProduct==USBDM_PID)) ||
          ((deviceDescriptor.idVendor==TBLCF_VID)&&(deviceDescriptor.idProduct==TBLCF_PID)) ||
          ((deviceDescriptor.idVendor==OSBDM_VID)&&(deviceDescriptor.idProduct==OSBDM_PID)) ||
          ((deviceDescriptor.idVendor==TBDML_VID)&&(deviceDescriptor.idProduct==TBDML_PID))) {
         // Found a device

         uint8_t busNumber = libusb_get_bus_number(currentDevice);
         uint8_t address   = libusb_get_device_address(currentDevice);
         log.print("==> Found USBDM device, List[%d] = #%d, dev#=%d, addr=%d\n", deviceCount, deviceIndex, busNumber, address);

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
      return BDM_RC_OK;
   }
   else {
      return BDM_RC_NO_USBDM_DEVICE;
   }
}

//**********************************************************
//!
//! Open connection to device enumerated by bdm_usb_find_devices()
//!
//! @param device_no Device number to open
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_open( unsigned int device_no ) {
   LOGGING;
   if (!initialised) {
      return BDM_RC_NOT_INITIALISED;
   }
   if (device_no >= deviceCount) {
      log.error("Illegal device #\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (usbDeviceHandle != NULL) {
      log.print("Closing previous device\n");
      bdm_usb_close();
   }
   int rc = libusb_open(bdmDevices[device_no], &usbDeviceHandle);

   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_open() failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
      usbDeviceHandle = NULL;
      if (rc == LIBUSB_ERROR_ACCESS) {
         // Probably device is busy (open in another app)
         return BDM_RC_USB_DEVICE_BUSY;
      }
      else if (rc == LIBUSB_ERROR_NO_DEVICE) {
         // Probably device has been removed
         return BDM_RC_USB_DEVICE_REMOVED;
      }
      else {
         // Some other USB error
         return BDM_RC_DEVICE_OPEN_FAILED;
      }
   }
//   log.print("libusb_open() done\n");
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
         return BDM_RC_DEVICE_OPEN_FAILED;
      }
//      log.print("libusb_set_configuration() done\n");
   }
   rc = libusb_claim_interface(usbDeviceHandle, 0);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_claim_interface(0) failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
      libusb_close(usbDeviceHandle);
      usbDeviceHandle = NULL;
      if ((rc == LIBUSB_ERROR_ACCESS)||(rc == LIBUSB_ERROR_NOT_SUPPORTED)) {
         // Probably device driver is not installed
         return BDM_RC_USB_DEVICE_NOT_INSTALLED;
      }
      else {
         // Some other USB error
         return BDM_RC_DEVICE_OPEN_FAILED;
      }
   }
//   log.print("libusb_claim_interface() done\n");
//   This breaks USB-3 under linux
//   rc = libusb_clear_halt(usbDeviceHandle, EP_IN);
//   if (rc != LIBUSB_SUCCESS) {
//      // Ignore
//      log.error("libusb_clear_halt(...,EP_IN(0x%02X)) failed, rc = %s\n", EP_IN, libusb_error_name((libusb_error)rc));
//   }
//   rc = libusb_clear_halt(usbDeviceHandle, EP_OUT);
//   if (rc != LIBUSB_SUCCESS) {
//      // Ignore
//      log.error("libusb_clear_halt(...,EP_OUT(0x%02X)) failed, rc = %s\n", EP_OUT, libusb_error_name((libusb_error)rc));
//   }
   return (BDM_RC_OK);
}

//**********************************************************
//!
//! Closes connection to the currently open device
//!
//! @return BDM_RC_OK => success (ignores errors)
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_close( void ) {
   int rc;
   LOGGING;

   if (usbDeviceHandle == NULL) {
      log.print("Device not open - no action\n");
      return BDM_RC_OK;
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
   return BDM_RC_OK;
}

//**************************************************************************
//!
//! Obtain a string descriptor from currently open BDM
//!
//! @param index              Index of string to obtain
//! @param deviceDescription  Ptr to buffer for descriptor
//! @param maxLength          Size of buffer
//!
//! @return \n
//!    == BDM_RC_OK (0)          => Success\n
//!    == BDM_RC_USB_ERROR       => USB failure
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_getStringDescriptor(int index, char *descriptorBuffer, unsigned maxLength) {
   const int DT_STRING = 3;
   LOGGING;

   memset(descriptorBuffer, '\0', maxLength);

   if (usbDeviceHandle == NULL) {
      log.error("Device handle NULL! \n");
      return BDM_RC_DEVICE_NOT_OPEN;
   }
   int rc = libusb_control_transfer(usbDeviceHandle ,
                                    LIBUSB_REQUEST_TYPE_STANDARD|EP_CONTROL_IN, // bmRequestType
                                    LIBUSB_REQUEST_GET_DESCRIPTOR,              // bRequest
                                    (DT_STRING << 8) + index,                   // wValue
                                    0,                                          // wIndex
                                    (unsigned char *)descriptorBuffer,          // data
                                    maxLength,                                  // size
                                    timeoutValue);                              // timeout

   if ((rc < 0) || (descriptorBuffer[1] != DT_STRING)) {
      memset(descriptorBuffer, '\0', maxLength);
      log.error("libusb_control_transfer() failed\n");
      return BDM_RC_USB_ERROR;
   }
//   else {
//      log.print("read %d bytes\n", rc);
//      printDump((unsigned char *)descriptorBuffer, rc);
//   }
   // Determine length
   unsigned length = descriptorBuffer[0];
   if (length>maxLength-2U) {
      length = maxLength-2U;
   }
   // Make sure UTF-16-LE string is terminated
   descriptorBuffer[length+2] = 0;
   descriptorBuffer[length+3] = 0;

   return BDM_RC_OK;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

//*****************************************************************************
//!
//! \brief Sends a message+data to the USBDM device over EP0
//!
//! No response is expected from device.
//!
//! Since the EP0 transfer is unidirectional in this case, data returned by the
//! device must be read in a separate transfer - this includes any status.
//!
//! @param data \n
//!    data[0]    = N, the number of bytes to send (excluding this byte)\n
//!    data[1]    = Command byte \n
//!    data[2..N] = parameter(s) for command \n
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_send_ep0( const unsigned char * data ) {
   unsigned char setupPkt[] = {0,0,0,0,0,0,0};
   unsigned char size       = data[0];   // Size is the first byte
   int rc;
   unsigned index;
   LOGGING;

   if (usbDeviceHandle == NULL) {
      log.error("Device handle NULL!\n");
      return BDM_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("============================\n");
   log.print("USB EP0 send (%s, size=%d):\n", getCommandName(data[1]), size);
   if (data[1] == CMD_USBDM_DEBUG)
      log.print("Debug cmd = %s\n", getDebugCommandName(data[2]));
   printDump(data, size+1);
#endif // LOG_LOW_LEVEL

   // Copy data in case <5 bytes to avoid possible illegal de-referencing
   for(index=0; index<(sizeof(setupPkt)/sizeof(setupPkt[0])); index++) {
      if (index > size)
         break;
      setupPkt[index] = data[index];
   }
   rc=libusb_control_transfer(usbDeviceHandle,
               LIBUSB_REQUEST_TYPE_VENDOR|EP_CONTROL_OUT,      // requestType=Vendor
               setupPkt[1],                                    // request
               setupPkt[2]+(setupPkt[3]<<8),                   // value
               setupPkt[4]+(setupPkt[5]<<8),                   // index
               (unsigned char *)((size>5)?data+6:setupPkt),    // data bytes
               (size>5)?(size-5):0,                            // size (# of data bytes)
               timeoutValue);                                  // how long to wait for reply
   if (rc < 0) {
      log.error("libusb_control_transfer() failed, send failed (USB error = %d)\n", rc);
      return(BDM_RC_USB_ERROR);
   }
   return(BDM_RC_OK);
}

//! \brief Sends a message of 5 bytes to the USBDM device over EP0.
//!
//!  An immediate response is expected
//!
//! @param data - Entry \n
//!    data[0]    = N, the number of bytes to receive from the device \n
//!    data[1]    = Command byte \n
//!    data[2..5] = parameter(s) for OSBDM command \n
//! @note data must be an array of at least 5 bytes even if there are no parameters!
//!
//! @param data - Exit \n
//!    data[0]      = cmd response from OSBDM\n
//!    data[1..N-1] = data response from the device (cleared on error)\n
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success, OK response from device\n
//!    == BDM_RC_USB_ERROR  => USB failure \n
//!    == else              => Error code from Device
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_recv_ep0(unsigned char *data, unsigned *actualRxSize) {
   unsigned char size = data[0];   // Transfer size is the first byte
   unsigned char cmd  = data[1];   // OSBDM/USBDM Command byte
   int rc;
   int retry = 5;
   LOGGING;

   *actualRxSize = 0;

   if (usbDeviceHandle == NULL) {
      log.error("ERROR : Device handle NULL!\n");
      data[0] = BDM_RC_DEVICE_NOT_OPEN;
      return BDM_RC_DEVICE_NOT_OPEN;
   }

#ifdef LOG_LOW_LEVEL
   log.print("============================\n");
   log.print("bdm_usb_recv_ep0(%s, size=%d) - \n", getCommandName(cmd), size);
   if (data[1] == CMD_USBDM_DEBUG)
      log.print("Debug cmd = %s\n", getDebugCommandName(data[2]));
   printDump(data, 6);
#endif // LOG_LOW_LEVEL

   do {
      rc = libusb_control_transfer(usbDeviceHandle,
               LIBUSB_REQUEST_TYPE_VENDOR|EP_CONTROL_IN,      // bmRequestType
               cmd,                                           // bRequest
               data[2]+(data[3]<<8),                          // wValue
               data[4]+(data[5]<<8),                          // wIndex
               (unsigned char*)data,                          // ptr to data buffer (for Rx)
               size,                                          // wLength = size of transfer
               timeoutValue                                   // timeout
               );
      if (rc < 0) {
         log.error("libusb_control_transfer(sz=%d) failed - Transfer error (USB error = %s) - retry %d \n", size, libusb_error_name((libusb_error)rc), retry);
         UsbdmSystem::milliSleep(100); // So we don't monopolize the USB
      }
   } while ((rc < 0) && (--retry>0));

   if (rc < 0) {
      log.error("Transfer failed (USB error = %s)\n", libusb_error_name((libusb_error)rc));
      data[0] = BDM_RC_USB_ERROR;
      *actualRxSize = 0;
   }
   else {
      *actualRxSize = (unsigned) rc;
   }
   if ((data[0] != BDM_RC_OK) && (data[0] != cmd)){ // Error at BDM?
      log.error("Cmd Failed (%s):\n", getErrorName(data[0]));
      log.printDump(data,*actualRxSize);
      memset(&data[1], 0x00, size-1);
      return (USBDM_ErrorCode)data[0];
   }
#ifdef LOG_LOW_LEVEL
   log.print("bdm_usb_recv_ep0(size = %d, recvd = %d):\n", size, rc);
   printDump(data,rc);
#endif // LOG_LOW_LEVEL

   return(BDM_RC_OK);
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
DLL_LOCAL
USBDM_ErrorCode bdm_usb_raw_send_ep0(unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     const unsigned char *data) {
   int rc;
   LOGGING;

if (usbDeviceHandle == NULL) {
      log.error("Device not open\n");
      return BDM_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("req=%2.2X, val=%2.2X, ind=%d, size=%d\n", request, wValue, wIndex, size);
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
      return(BDM_RC_USB_ERROR);
   }
   return(BDM_RC_OK);
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
//!     == BDM_RC_OK (0)     => Success, OK response from device\n
//!     == BDM_RC_USB_ERROR  => USB failure \n
//!     == else              => Error code from Device
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_raw_recv_ep0(unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     unsigned char *data) {
   int rc;
   LOGGING;
   if (usbDeviceHandle == NULL) {
      log.error("Device not open\n");
      data[0] = BDM_RC_DEVICE_NOT_OPEN;
      return BDM_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("============================\n");
   log.print("bdm_usb_raw_recv_ep0(req=%2.2X, val=%2.2X, ind=%d, size=%d)\n",
         request, wValue, wIndex, size);
#endif // LOG_LOW_LEVEL

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
      data[0] = BDM_RC_USB_ERROR;
   }
   return (USBDM_ErrorCode)data[0];
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

//! \brief Sends a command to the USBDM device over the Out Bulk Endpoint
//!
//! Since the EP transfer is unidirectional, data returned by the
//! device must be read in a separate transfer - this includes any status
//! from extended command execution.
//!
//! @param count = # of bytes to Tx (N)
//!
//! @param data                                 \n
//!    OUT                                      \n
//!    =======================================  \n
//!    data[0]      = reserved                  \n
//!    data[1]      = command byte              \n
//!    data[2..N-1] = parameters                \n
//!                                             \n
//!    IN                                       \n
//!    ======================================== \n
//!    data[0]      = error code (=rc)
//!
//! @return
//!   BDM_RC_OK        => USB transfer OK \n
//!   BDM_RC_USB_ERROR => USB transfer Failed
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_send_epOut(unsigned int count, const unsigned char *data) {
   int rc;
   int transferCount;
   LOGGING;

   if (usbDeviceHandle==NULL) {
      log.error("Device not open\n");
      return BDM_RC_DEVICE_NOT_OPEN;
   }

#ifdef LOG_LOW_LEVEL
   log.print("============================\n");
   if (data[0] == 0) { // Zero as first byte indicates split USBDM command
      log.print("bdm_usb_send_epOut() - USB EP0ut send (SPLIT, size=%d):\n", count);
   }
   else {
      log.print("bdm_usb_send_epOut() - USB EP0ut send (%s, size=%d):\n", getCommandName(data[1]), count);
      if (data[1] == CMD_USBDM_DEBUG)
         log.print("bdm_usb_send_epOut() - Debug cmd = %s\n", getDebugCommandName(data[2]));
   }
   printDump(data, count);
#endif // LOG_LOW_LEVEL

   rc = libusb_bulk_transfer(usbDeviceHandle,
                       EP_OUT,                  // Endpoint & direction
                       (unsigned char *)data,   // ptr to Tx data
                       count,                   // number of bytes to Tx
                       &transferCount,          // number of bytes actually Tx
                       timeoutValue             // timeout
                       );
   if (rc != LIBUSB_SUCCESS) {
      log.error("Transfer failed (USB error = %s, timeout=%d)\n", libusb_error_name((libusb_error)rc), timeoutValue);
      return BDM_RC_USB_ERROR;
   }
   return BDM_RC_OK;
}

//! Temporary buffer for IN transactions
//!
static unsigned char dummyBuffer[512];

//! \brief Receives a response from the USBDM device over the In Bulk Endpoint
//! Responses are retried to allow for target execution
//!
//! @param count = Maximum number of bytes to receive
//!
//! @param data
//!    IN                                       \n
//!    ======================================== \n
//!    data[0]      = error code (= rc)         \n
//!    data[1..N]   = data received             \n
//!
//! @param actualCount = Actual number of bytes received
//!
//! @return                                                       \n
//!    == BDM_RC_OK (0)     => Success, OK response from device   \n
//!    == BDM_RC_USB_ERROR  => USB failure                        \n
//!    == else              => Error code from Device
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_recv_epIn(unsigned count, unsigned char *data, unsigned *actualCount) {
   int rc;
   int transferCount;
   LOGGING;

   *actualCount = 0; // Assume failure

   if (usbDeviceHandle==NULL) {
      log.error("Device not open\n");
      return BDM_RC_DEVICE_NOT_OPEN;
   }
#ifdef LOG_LOW_LEVEL
   log.print("bdm_usb_recv_epIn(%d, ...)\n", count);
#endif // LOG_LOW_LEVEL

   int backoffLimit = 5000; // Maximum time to backoff before giving up (ms)
   int backoff      = 1;    // How long to wait before retry (ms)
   do {
      rc = libusb_bulk_transfer(usbDeviceHandle,
                                EP_IN,                         // Endpoint & direction
                                (unsigned char *)dummyBuffer,  // Ptr to Rx data
                                sizeof(dummyBuffer)-5,         // Number of bytes to Rx
                                &transferCount,                // Number of bytes actually Rx
                                timeoutValue                   // Timeout
                                );
      if ((rc == LIBUSB_SUCCESS)  && (dummyBuffer[0] == BDM_RC_BUSY)) {
         // The BDM has indicated it's busy for a while - try again in 10 ms
         log.error("BDM Busy (timeoutValue=%d ms, backoff=%d ms)\n", timeoutValue, backoff);
         UsbdmSystem::milliSleep(backoff); // So we don't monopolise the USB
         backoff *= 2; // Try 1,2,4,8,16 ... ms
      }
   } while ((rc == LIBUSB_SUCCESS) && (dummyBuffer[0] == BDM_RC_BUSY)  && (backoff<=backoffLimit));

   if (rc != LIBUSB_SUCCESS) {
      log.error("Transfer failed (Count = %d, USB error = %s, timeout=%d)\n", count, libusb_error_name((libusb_error)rc), timeoutValue);
      data[0] = BDM_RC_USB_ERROR;
      memset(&data[1], 0x00, count-1);
      return BDM_RC_USB_ERROR;
   }
   memcpy(data, dummyBuffer, transferCount);
   rc = data[0]&0x7F;

   if (rc != BDM_RC_OK) {
      log.error("Error Return %d (%s):\n", rc, getErrorName(rc));
      log.error("size = %d, recvd = %d\n", count, transferCount);
      log.printDump(data, transferCount);
      memset(&data[1], 0x00, count-1);
   }
#ifdef LOG_LOW_LEVEL
   printDump(data, transferCount);
#endif // LOG_LOW_LEVEL

   *actualCount = transferCount;
   return (USBDM_ErrorCode)(rc);
}

//! Attempt to reset the USB connection without upsetting target
//!
//! @return BDM_RC_OK => USB device re-opened OK
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_reset_connection(void) {
   USBDM_Version_t version;
   int rc;
   LOGGING;

   rc = libusb_set_configuration(usbDeviceHandle, 1);
   if (rc != LIBUSB_SUCCESS) {
      log.error("libusb_set_configuration(1) failed, rc = (%d):%s\n", rc, libusb_error_name(rc));
   }
//   rc = libusb_clear_halt(usbDeviceHandle, EP_IN);
//   if (rc != LIBUSB_SUCCESS) {
//      log.error("libusb_clear_halt(...,EP_IN(0x%02X)) failed, rc = %s\n", EP_IN, libusb_error_name((libusb_error)rc));
//   }
//   rc = libusb_clear_halt(usbDeviceHandle, EP_OUT);
//   if (rc != LIBUSB_SUCCESS) {
//      log.error("libusb_clear_halt(...,EP_OUT(0x%02X)) failed, rc = %s\n", EP_OUT, libusb_error_name((libusb_error)rc));
//   }
   if ((USBDM_GetVersion(&version)  != BDM_RC_OK) &&
       (USBDM_GetVersion(&version)  != BDM_RC_OK)) { // Get BDM version - reset USB command handler
      log.error("USBDM_GetVersion() failed\n");
      return BDM_RC_FAIL;
   }
   log.print("Success\n");
   return BDM_RC_OK;
}

//! \brief Executes an USB transaction.
//! This consists of a transmission of a command and reception of the response
//! JB16 Version - see \ref bdm_usb_transaction()
//!
static
USBDM_ErrorCode bdmJB16_usb_transaction( unsigned int   txSize,
                                         unsigned int   rxSize,
                                         unsigned char *data,
                                         unsigned int  *actualRxSize) {
   USBDM_ErrorCode rc;
   LOGGING;
   if (txSize <= 5) {
      // Transmission fits in SETUP pkt, Use single IN Data transfer to/from EP0
      *data = rxSize;
      rc = bdm_usb_recv_ep0( data, actualRxSize);
   }
   else {
      // Transmission requires separate IN transaction
      *data = txSize;
      rc = bdm_usb_send_ep0( (const unsigned char *)data );
      if (rc == BDM_RC_OK) {
         // Get response
         data[0] = rxSize;
         data[1] = CMD_USBDM_GET_COMMAND_RESPONSE; // dummy command
         rc = bdm_usb_recv_ep0(data, actualRxSize);
      }
   }
   if (rc != BDM_RC_OK) {
      data[0] = rc;
      memset(&data[1], 0x00, rxSize-1);
   }
   return rc;
}

//! \brief Executes an USB transaction.
//! This consists of a transmission of a command and reception of the response
//! JMxx Version - see \ref bdm_usb_transaction()
//!
static
USBDM_ErrorCode bdmJMxx_simple_usb_transaction( bool                 commandToggle,
                                                unsigned int         txSize,
                                                unsigned int         rxSize,
                                                const unsigned char *outData,
                                                unsigned char       *inData,
                                                unsigned int        *actualRxSize) {
//   const unsigned  MaxFirstTransaction = 30;
   const unsigned  MaxFirstTransaction = 62;
//   uint8_t        *sendBuffer = (uint8_t*) alloca(txSize);
   uint8_t         sendBuffer[txSize];
   USBDM_ErrorCode rc;
   LOGGING;

   memcpy(sendBuffer, outData, txSize);
   if (commandToggle) {
      sendBuffer[1] |= 0x80;
   }
   else {
      sendBuffer[1] &= ~0x80;
   }
//   log.print("Tx1\n");

   // An initial transaction of up to MaxFirstTransaction bytes is sent
   // This is guaranteed to fit in a single pkt (<= endpoint MAXPACKETSIZE)
   sendBuffer[0] = txSize;
   rc = bdm_usb_send_epOut(txSize>MaxFirstTransaction?MaxFirstTransaction:txSize, (const unsigned char *)sendBuffer);
   if (rc != BDM_RC_OK) {
      log.error("Tx1 failed\n");
      return rc;
   }
   // Remainder of data (if any) is sent as 2nd transaction
   // The size of this transaction is know to the receiver
   // Zero is sent as first byte (size) to allow differentiation from 1st transaction
   if (txSize>MaxFirstTransaction) {
//      log.print(" Splitting command\n");
      uint8_t saveByte = sendBuffer[MaxFirstTransaction-1];
      sendBuffer[MaxFirstTransaction-1] = 0; // Marker indicating later transaction
      rc = bdm_usb_send_epOut(txSize+1-MaxFirstTransaction,
            (const unsigned char *)(sendBuffer+MaxFirstTransaction-1));
      sendBuffer[MaxFirstTransaction-1] = saveByte;
   }
   if (rc != BDM_RC_OK) {
      log.error("Tx2 failed\n");
      return rc;
   }
   // Get response
   rc = bdm_usb_recv_epIn(rxSize, inData, actualRxSize);
   if (rc == BDM_RC_USB_ERROR) {
      // Single retry on Rx error
      log.error("USB Rx error\n");
      timeoutValue *= 4;
      rc = bdm_usb_recv_epIn(rxSize, inData, actualRxSize);
      if (rc == BDM_RC_USB_ERROR) {
         log.error("USB Rx error - retry failed\n");
         return rc;
      }
      log.error(" USB Rx error- retry success\n");
   }
   bool receivedCommandToggle = (inData[0]&0x80) != 0;
   if (commandToggle != receivedCommandToggle) {
      // Single retry on toggle error (clear any pending Rx)
      log.error("USB Toggle error, S=%d, R=%d\n", commandToggle?1:0, receivedCommandToggle?1:0);
      UsbdmSystem::milliSleep(100);
      rc = bdm_usb_recv_epIn(rxSize, inData, actualRxSize);
      receivedCommandToggle = (inData[0]&0x80) != 0;
      if ((rc == BDM_RC_USB_ERROR) || (commandToggle != receivedCommandToggle)) {
         log.error("Immediate retry failed, S=%d, R=%d\n", commandToggle?1:0, receivedCommandToggle?1:0);
         return BDM_RC_USB_ERROR;
      }
      log.error("Immediate retry succeeded, S=%d, R=%d\n", commandToggle?1:0, receivedCommandToggle?1:0);
   }
   // Mask toggle bit out of data
   inData[0] &= ~0x80;
   if (rc != BDM_RC_OK) {
      log.error("Non-USB error, rc = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}

//! \brief Executes an USB transaction.
//! This consists of a transmission of a command and reception of the response
//! JMxx Version - see \ref bdm_usb_transaction()
//!
//! @Note includes retries
//!
static
USBDM_ErrorCode bdmJMxx_usb_transaction( unsigned int   txSize,
                                         unsigned int   rxSize,
                                         unsigned char *data,
                                         unsigned int  *actualRxSize) {
   static bool     commandToggle       = 0;
   static int      sequence            = 0;
//   bool            resetFlag           = false;
//   bool            reportFlag          = false;
//   USBDM_ErrorCode rc                  = BDM_RC_OK;
   unsigned char   outData[txSize];
   LOGGING;

   // Save copy of data for retry
   memcpy(outData, data, txSize);

   if (data[1] == CMD_USBDM_GET_CAPABILITIES) {
      log.print("Setting toggle=0\n");
      commandToggle = 0;
      sequence      = 0;
   }
   sequence++;

   return bdmJMxx_simple_usb_transaction(commandToggle, txSize, rxSize, outData, data, actualRxSize);
}

//! \brief Executes an USB transaction.
//! This consists of a transmission of a command and reception of the response
//!
//! @param txSize = size of transmitted packet
//!
//! @param rxSize = maximum size of received packet
//!
//! @param data   = IN/OUT buffer for data                           \n
//!    Transmission                                                  \n
//!    ===================================                           \n
//!    data[0]    = reserved for USB layer                           \n
//!    data[1]    = command                                          \n
//!    data[2..N] = data                                             \n
//!                                                                  \n
//!    Reception                                                     \n
//!    ============================================================= \n
//!    data[0]    = response code (error code - see \ref USBDM_ErrorCode) \n
//!    data[1..N] = command response
//!
//! @param timeout      = timeout in ms
//! @param actualRxSize = number of bytes actually received (may be NULL if not required)
//!
//! @return                                                          \n
//!    == BDM_RC_OK (0)     => Success, OK response from device      \n
//!    == BDM_RC_USB_ERROR  => USB failure                           \n
//!    == else              => Error code from BDM
//!
DLL_LOCAL
USBDM_ErrorCode bdm_usb_transaction( unsigned int   txSize,
                                     unsigned int   rxSize,
                                     unsigned char *data,
                                     unsigned int   timeout,
                                     unsigned int  *actualRxSize) {
   USBDM_ErrorCode rc;
   unsigned tempRxSize;
   uint8_t command = data[1];
   LOGGING_Q;
   log.setLoggingLevel(0);

   if (usbDeviceHandle==NULL) {
      log.error("device not open\n");
	  return BDM_RC_DEVICE_NOT_OPEN;
   }
   timeoutValue = timeout;

   if (bdmState.useOnlyEp0) {
      rc = bdmJB16_usb_transaction(txSize, rxSize, data, &tempRxSize);
   }
   else {
      rc = bdmJMxx_usb_transaction(txSize, rxSize, data, &tempRxSize);
   }
   if (actualRxSize != NULL) {
      // Variable size data expected
      *actualRxSize = tempRxSize;
   }
   else if ((rc == BDM_RC_OK) && (tempRxSize != rxSize)) {
      // Expect exact data size
      log.error("Failed, cmd = %s, Expected %d; received %d\n",
            getCommandName(command), rxSize, tempRxSize);
      rc = BDM_RC_UNEXPECTED_RESPONSE;
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, cmd = %s, rc = %s\n",
            getCommandName(command), getErrorName(rc));
   }
   return rc;
}

