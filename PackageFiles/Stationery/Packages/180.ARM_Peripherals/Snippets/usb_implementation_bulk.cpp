/**
 * @file     usb_implementation_bulk.cpp
 * @brief    USB Bulk device implementation
 *
 * This module provides an implementation of a USB Bulk interface
 * including the following end points:
 *  - EP0 Standard control
 *  - EP1 Bulk OUT
 *  - EP2 Bulk IN
 *
 * @version  V4.12.1.170
 * @date     2 April 2017
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */
#include <string.h>

#include "usb.h"
#include "usb_implementation_bulk.h"
#include "hardware.h"

namespace USBDM {

/**
 * Interface numbers for USB descriptors
 */
enum InterfaceNumbers {
   /** Interface number for Bulk interface */
   BULK_INTF_ID,
   /*
    * TODO Add additional Interface numbers here
    */
   /** Total number of interfaces */
   NUMBER_OF_INTERFACES,
};

/*
 * String descriptors
 */
static const uint8_t s_language[]        = {4, DT_STRING, 0x09, 0x0C};  //!< Language IDs
static const uint8_t s_manufacturer[]    = MANUFACTURER;                //!< Manufacturer
static const uint8_t s_product[]         = PRODUCT_DESCRIPTION;         //!< Product Description
static const uint8_t s_serial[]          = SERIAL_NO;                   //!< Serial Number
static const uint8_t s_config[]          = "Default configuration";     //!< Configuration name

static const uint8_t s_bulk_interface[]  = "Bulk Interface";            //!< Bulk Interface


/*
 * Add additional String descriptors here
 */

/**
 * String descriptor table
 */
const uint8_t *const Usb0::stringDescriptors[] = {
      s_language,
      s_manufacturer,
      s_product,
      s_serial,
      s_config,

      s_bulk_interface,
      /*
       * Add additional String descriptors here
       */
};

/**
 * Device Descriptor
 */
const DeviceDescriptor Usb0::deviceDescriptor = {
      /* bLength             */ (uint8_t) sizeof(DeviceDescriptor),
      /* bDescriptorType     */ (uint8_t) DT_DEVICE,
      /* bcdUSB              */ (uint8_t) nativeToLe16(0x0200),           // USB specification release No. [BCD = 2.00]
      /* bDeviceClass        */ (uint8_t) 0xFF,                           // Class code        [none]
      /* bDeviceSubClass     */ (uint8_t) 0xFF,                           // Sub Class code    [none]
      /* bDeviceProtocol     */ (uint8_t) 0xFF,                           // Protocol          [none]
      /* bMaxPacketSize0     */ (uint8_t) CONTROL_EP_MAXSIZE,             // EndPt 0 max packet size
      /* idVendor            */ (uint16_t)nativeToLe16(VENDOR_ID),        // Vendor ID
      /* idProduct           */ (uint16_t)nativeToLe16(PRODUCT_ID),       // Product ID
      /* bcdDevice           */ (uint16_t)nativeToLe16(VERSION_ID),       // Device Release
      /* iManufacturer       */ (uint8_t) s_manufacturer_index,           // String index of Manufacturer name
      /* iProduct            */ (uint8_t) s_product_index,                // String index of product description
      /* iSerialNumber       */ (uint8_t) s_serial_index,                 // String index of serial number
      /* bNumConfigurations  */ (uint8_t) NUMBER_OF_CONFIGURATIONS        // Number of configurations
};

/**
 * All other descriptors
 */
const Usb0::Descriptors Usb0::otherDescriptors = {
      { // configDescriptor
            /* bLength                 */ (uint8_t) sizeof(ConfigurationDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_CONFIGURATION,
            /* wTotalLength            */ (uint16_t)nativeToLe16(sizeof(otherDescriptors)),
            /* bNumInterfaces          */ (uint8_t) NUMBER_OF_INTERFACES,
            /* bConfigurationValue     */ (uint8_t) CONFIGURATION_NUM,
            /* iConfiguration          */ (uint8_t) s_config_index,
            /* bmAttributes            */ (uint8_t) 0x80,     //  = Bus powered, no wake-up
            /* bMaxPower               */ (uint8_t) USBMilliamps(500)
      },
      /**
       * Bulk interface, 2 end-points
       */
      { // bulk_interface
            /* bLength                 */ (uint8_t) sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_INTERFACE,
            /* bInterfaceNumber        */ (uint8_t) BULK_INTF_ID,
            /* bAlternateSetting       */ (uint8_t) 0,
            /* bNumEndpoints           */ (uint8_t) 2,
            /* bInterfaceClass         */ (uint8_t) 0xFF,                         // (Vendor specific)
            /* bInterfaceSubClass      */ (uint8_t) 0xFF,                         // (Vendor specific)
            /* bInterfaceProtocol      */ (uint8_t) 0xFF,                         // (Vendor specific)
            /* iInterface desc         */ (uint8_t) s_bulk_interface_index,
      },
      { // bulk_out_endpoint - OUT, Bulk
            /* bLength                 */ (uint8_t) sizeof(EndpointDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_ENDPOINT,
            /* bEndpointAddress        */ (uint8_t) EP_OUT|BULK_OUT_ENDPOINT,
            /* bmAttributes            */ (uint8_t) ATTR_BULK,
            /* wMaxPacketSize          */ (uint16_t)nativeToLe16(BULK_OUT_EP_MAXSIZE),
            /* bInterval               */ (uint8_t) USBMilliseconds(1)
      },
      { // bulk_in_endpoint - IN, Bulk
            /* bLength                 */ (uint8_t) sizeof(EndpointDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_ENDPOINT,
            /* bEndpointAddress        */ (uint8_t) EP_IN|BULK_IN_ENDPOINT,
            /* bmAttributes            */ (uint8_t) ATTR_BULK,
            /* wMaxPacketSize          */ (uint16_t)nativeToLe16(BULK_IN_EP_MAXSIZE),
            /* bInterval               */ (uint8_t) USBMilliseconds(1)
      },
      /*
       * TODO Add additional Descriptors here
       */
};

/** Out end-point for BULK data out HOST -> DEVICE */
OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT, BULK_OUT_EP_MAXSIZE>  Usb0::epBulkOut(EndPointType_Bulk);

/** In end-point for BULK data in DEVICE -> HOST*/
InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,  BULK_IN_EP_MAXSIZE>   Usb0::epBulkIn(EndPointType_Bulk);

/*
 * TODO Add additional end-points here
 */

/**
 * Handler for Start of Frame Token interrupt (~1ms interval)
 *
 * @param frameNumber Frame number from SOF token
 *
 * @return  E_NO_ERROR on success
 */
ErrorCode Usb0::sofCallback(uint16_t frameNumber) {
   // Activity LED
   // Off                     - no USB activity, not connected
   // On                      - no USB activity, connected
   // Off, flash briefly on   - USB activity, not connected
   // On,  flash briefly off  - USB activity, connected
   if ((frameNumber&0xFF)==0) {
      // Every ~256 ms
      switch ((frameNumber>>8)&0x3) {
         case 0:
            // LED on if configured, off if not
            UsbLed::write(fConnectionState == USBconfigured);
            break;
         case 1:
         case 2:
            break;
         case 3:
         default :
            if (fActivityFlag) {
               // Flash LED to indicate activity
               UsbLed::toggle();
               fActivityFlag = false;
            }
            break;
      }
   }

   return E_NO_ERROR;
}

/**
 * Handler for Token Complete USB interrupts for
 * end-points other than EP0
 *
 * @param usbStat USB Status value from USB hardware
 */
void Usb0::handleTokenComplete(UsbStat usbStat) {

   // Endpoint number
   uint8_t endPoint = usbStat.endp;

   fEndPoints[endPoint]->flipOddEven(usbStat);
   switch (endPoint) {
      case BULK_OUT_ENDPOINT: // Accept OUT token
         setActive();
         epBulkOut.handleOutToken();
         return;
      case BULK_IN_ENDPOINT: // Accept IN token
         setActive();
         epBulkIn.handleInToken();
         return;
      /*
       * TODO Add additional end-point handling here
       */
   }
}

//_______ Bulk Call-backs ________________________________________________________________

/**
 * Call-back handling BULK-OUT transaction complete
 *
 * @param[in] state Current end-point state (always EPDataOut)
 *
 * @return The endpoint state to set after call-back (e.g. EPIdle/EPDataOut/EPComplete)
 */
EndpointState Usb0::bulkOutTransactionCallback(EndpointState state) {
   (void)state;
   return EPComplete;
}

/**
 * Call-back handling BULK-IN transaction complete
 *
 * @param[in] state Current end-point state (always EPDataIn)
 *
 * @return The endpoint state to set after call-back (e.g. EPIdle/EPDataIn/EPComplete)
 */
EndpointState Usb0::bulkInTransactionCallback(EndpointState state) {
   (void)state;
   return EPComplete;
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();

   UsbLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   // Add extra handling of packets directed to EP0
   //   setUnhandledSetupCallback(handleUserEp0SetupRequests);

   // Set SOF handler
   setSOFCallback(sofCallback);

   /*
    * TODO Additional initialisation
    */
}

//_______ Bulk Transmission ________________________________________________________________

/**
 *  Non-blocking transmission of data over bulk IN end-point
 *
 *  @param size         Number of bytes to send
 *  @param buffer       Pointer to bytes to send
 *
 *  @return E_WRONG_STATE  In wrong state e.g. Busy or Stalled
 *  @return E_NO_ERROR     Transmission successfully commenced
 */
ErrorCode Usb0::startSendBulkData(uint16_t size, const uint8_t *buffer) {

   EndpointState state = epBulkIn.getState();

   if (state != EPIdle) {
      return E_WRONG_STATE;
   }
   // Use ZLP as needed
   epBulkIn.setNeedZLP();
   epBulkIn.startTxTransfer(EPDataIn, size, buffer);
   return E_NO_ERROR;
}

/**
 *  Check if transmission completed
 *
 *  @return E_BUSY      Busy with last transmission - retry
 *  @return E_NO_ERROR  Transmission successfully completed
 */
ErrorCode Usb0::pollSendBulkData() {

   EndpointState state = epBulkIn.getState();
   switch(state) {
      case EPComplete:
         setActive();
         epBulkIn.setState(EPIdle);
         return E_NO_ERROR;
      case EPDataIn:
         return E_BUSY;
      default:
         return E_WRONG_STATE;
   }
}

/**
 *  Blocking transmission of data over bulk IN end-point
 *
 *  @param size            Number of bytes to send
 *  @param buffer          Pointer to bytes to send
 *  @param timeoutMS       Timeout in milliseconds (may be zero to suppress)
 *
 *  @return E_NO_ERROR     Transmission successfully completed
 *  @return E_TIMEOUT      Transmission not completed within timeout (transmission is aborted)
 *  @return E_WRONG_STATE  In wrong state e.g. Busy or Stalled (transmission is aborted)
 */
ErrorCode Usb0::sendBulkData(uint16_t size, const uint8_t *buffer, int timeoutMS) {

   ErrorCode rc = startSendBulkData(size, buffer);

   if (rc == E_NO_ERROR) {
      for(;;) {
         rc = pollSendBulkData();
         if (rc != E_BUSY) {
            break;
         }
         waitMS(1);
         if ((timeoutMS>0) && (--timeoutMS == 0)) {
            rc = E_TIMEOUT;
            break;
         }
      }
   }
   if (rc != E_NO_ERROR) {
      epBulkIn.initialise(false);
   }
   return rc;
}

//_______ Bulk Reception ________________________________________________________________

/**
 *  Non-blocking reception of data over bulk OUT end-point
 *
 *   @param size           Maximum number of bytes to receive
 *   @param buffer         Pointer to buffer for bytes received
 *
 *   @return E_NO_ERROR    Transmission started
 *   @return E_WRONG_STATE In unexpected state e.g. Busy or Stalled
 */
ErrorCode Usb0::startReceiveBulkData(uint16_t size, uint8_t *buffer) {
   EndpointState state = epBulkOut.getState();
   if (state != EPIdle) {
      return E_WRONG_STATE;
   }
   epBulkOut.startRxTransfer(EPDataOut, size, buffer);
   return E_NO_ERROR;
}

/**
 *  Check for completion of reception of data over bulk OUT end-point.
 *  Reception will have been previously configured by startReceiveBulkData().
 *
 *   @param  size          Number of bytes received
 *
 *   @return E_BUSY        Reception not complete. (size == 0)
 *   @return E_NO_ERROR    Reception complete. Buffer has data.
 *   @return E_WRONG_STATE In unexpected state e.g. Idle or Stalled
 */
ErrorCode Usb0::pollReceiveBulkData(uint16_t &size) {

   size = 0;
   EndpointState state = epBulkOut.getState();
   switch(state) {
      case EPComplete:
         setActive();
         size = epBulkOut.getDataTransferredSize();
         epBulkOut.setState(EPIdle);
         return E_NO_ERROR;
      case EPDataOut:
         return E_BUSY;
      default:
         return E_WRONG_STATE;
   }
}

/**
 *  Blocking reception of data over bulk OUT end-point
 *
 *  @param size           Maximum number of bytes to receive/Number of bytes received
 *  @param buffer         Pointer to buffer for bytes received
 *  @param timeoutMS      Timeout in milliseconds (may be zero to suppress)
 *
 *  @return E_NO_ERROR    Reception completed
 *  @return E_TIMEOUT     Reception not completed within timeout (reception is aborted)
 *  @return E_WRONG_STATE In unexpected state e.g. Busy or Stalled (reception is aborted)
 */
ErrorCode Usb0::receiveBulkData(uint16_t &size, uint8_t *buffer, int timeoutMS) {

   ErrorCode rc = startReceiveBulkData(size, buffer);
   if (rc == E_NO_ERROR) {
      for(;;) {
         rc = pollReceiveBulkData(size);
         if (rc != E_BUSY) {
            break;
         }
         waitMS(1);
         if ((timeoutMS>0) && (--timeoutMS==0)) {
            rc = E_TIMEOUT;
            break;
         }
      }
   }
   if (rc != E_NO_ERROR) {
      epBulkOut.initialise(false);
   }

   return rc;
}


} // End namespace USBDM

