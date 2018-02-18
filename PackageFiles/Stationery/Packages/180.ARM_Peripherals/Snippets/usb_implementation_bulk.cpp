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

namespace USBDM {

/**
 * Interface numbers for USB descriptors
 */
enum InterfaceNumbers {
   /** Interface number for BDM channel */
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

static const uint8_t s_bulk_interface[]  = "Bulk Interface";           //!< Bulk Interface

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
      /* bLength             */ sizeof(DeviceDescriptor),
      /* bDescriptorType     */ DT_DEVICE,
      /* bcdUSB              */ nativeToLe16(0x0200),           // USB specification release No. [BCD = 2.00]
      /* bDeviceClass        */ 0xFF,                           // Class code        [none]
      /* bDeviceSubClass     */ 0xFF,                           // Sub Class code    [none]
      /* bDeviceProtocol     */ 0xFF,                           // Protocol          [none]
      /* bMaxPacketSize0     */ CONTROL_EP_MAXSIZE,             // EndPt 0 max packet size
      /* idVendor            */ nativeToLe16(VENDOR_ID),        // Vendor ID
      /* idProduct           */ nativeToLe16(PRODUCT_ID),       // Product ID
      /* bcdDevice           */ nativeToLe16(VERSION_ID),       // Device Release    [BCD = 4.10]
      /* iManufacturer       */ s_manufacturer_index,           // String index of Manufacturer name
      /* iProduct            */ s_product_index,                // String index of product description
      /* iSerialNumber       */ s_serial_index,                 // String index of serial number
      /* bNumConfigurations  */ NUMBER_OF_CONFIGURATIONS        // Number of configurations
};

/**
 * All other descriptors
 */
const Usb0::Descriptors Usb0::otherDescriptors = {
      { // configDescriptor
            /* bLength                 */ sizeof(ConfigurationDescriptor),
            /* bDescriptorType         */ DT_CONFIGURATION,
            /* wTotalLength            */ nativeToLe16(sizeof(otherDescriptors)),
            /* bNumInterfaces          */ NUMBER_OF_INTERFACES,
            /* bConfigurationValue     */ CONFIGURATION_NUM,
            /* iConfiguration          */ s_config_index,
            /* bmAttributes            */ 0x80,     //  = Bus powered, no wake-up
            /* bMaxPower               */ USBMilliamps(500)
      },
      /**
       * Bulk interface, 2 end-points
       */
      { // bulk_interface
            /* bLength                 */ sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ DT_INTERFACE,
            /* bInterfaceNumber        */ BULK_INTF_ID,
            /* bAlternateSetting       */ 0,
            /* bNumEndpoints           */ 2,
            /* bInterfaceClass         */ 0xFF,                         // (Vendor specific)
            /* bInterfaceSubClass      */ 0xFF,                         // (Vendor specific)
            /* bInterfaceProtocol      */ 0xFF,                         // (Vendor specific)
            /* iInterface desc         */ s_bulk_interface_index,
      },
      { // bulk_out_endpoint - OUT, Bulk
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_OUT|BULK_OUT_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(BULK_OUT_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
      { // bulk_in_endpoint - IN, Bulk
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_IN|BULK_IN_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(BULK_IN_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
      /*
       * TODO Add additional Descriptors here
       */
};

/** Out end-point for BULK data out */
OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT, BULK_OUT_EP_MAXSIZE> Usb0::epBulkOut;

/** In end-point for BULK data in */
InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,  BULK_IN_EP_MAXSIZE>  Usb0::epBulkIn;
/*
 * TODO Add additional end-points here
 */

/**
 * Handler for Start of Frame Token interrupt (~1ms interval)
 */
void Usb0::sofCallback() {
   // Activity LED
   // Off                     - no USB activity, not connected
   // On                      - no USB activity, connected
   // Off, flash briefly on   - USB activity, not connected
   // On,  flash briefly off  - USB activity, connected
   if (fUsb->FRMNUML==0) { // Every ~256 ms
      switch (fUsb->FRMNUMH&0x03) {
         case 0:
            if (connectionState == USBconfigured) {
               // Activity LED on when USB connection established
//               UsbLed::on();
            }
            else {
               // Activity LED off when no USB connection
//               UsbLed::off();
            }
            break;
         case 1:
         case 2:
            break;
         case 3:
         default :
            if (activityFlag) {
               // Activity LED flashes
//               UsbLed::toggle();
               setActive(false);
            }
            break;
      }
   }
}

/**
 * Handler for Token Complete USB interrupts for
 * end-points other than EP0
 */
void Usb0::handleTokenComplete() {

   // Status from Token
   uint8_t   usbStat  = fUsb->STAT;

   // Endpoint number
   uint8_t   endPoint = ((uint8_t)usbStat)>>4;

   fEndPoints[endPoint]->flipOddEven(usbStat);
   switch (endPoint) {
      case BULK_OUT_ENDPOINT: // Accept OUT token
         setActive();
         epBulkOut.handleOutToken();
         return;
      case BULK_IN_ENDPOINT: // Accept IN token
         epBulkIn.handleInToken();
         return;
      /*
       * TODO Add additional end-point handling here
       */
   }
}

/**
 * Call-back handling BULK-OUT transaction complete
 *
 * @param state Current end-point state
 */
void Usb0::bulkOutTransactionCallback(EndpointState state) {
   static uint8_t buff[] = "";
//   PRINTF("%c\n", buff[0]);
   if (state == EPDataOut) {
      epBulkOut.startRxTransaction(EPDataOut, sizeof(buff), buff);
   }
}

/**
 * Call-back handling BULK-IN transaction complete
 *
 * @param state Current end-point state
 */
void Usb0::bulkInTransactionCallback(EndpointState state) {
   static const uint8_t buff[] = "Hello There\n\r";
   if (state == EPDataIn) {
      epBulkIn.startTxTransaction(EPDataIn, sizeof(buff), buff);
   }
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();

   // Add extra handling of CDC packets directed to EP0
//   setUnhandledSetupCallback(handleUserEp0SetupRequests);

   setSOFCallback(sofCallback);
   /*
    * TODO Additional initialisation
    */
}

/**
 *  Blocking reception of data over bulk OUT end-point
 *
 *   @param maxSize  = max # of bytes to receive
 *   @param buffer   = ptr to buffer for bytes received
 *
 *   @return Number of bytes received
 *
 *   @note Doesn't return until command has been received.
 */
int Usb0::receiveBulkData(uint8_t maxSize, uint8_t *buffer) {
   epBulkOut.startRxTransaction(EPDataOut, maxSize, buffer);
   while(epBulkOut.getState() != EPIdle) {
      __WFI();
   }
   setActive();
   return epBulkOut.getDataTransferredSize();
}

/**
 *  Blocking transmission of data over bulk IN end-point
 *
 *  @param size   Number of bytes to send
 *  @param buffer Pointer to bytes to send
 *
 *   @note : Waits for idle BEFORE transmission but\n
 *   returns before data has been transmitted
 *
 */
void Usb0::sendBulkData(uint8_t size, const uint8_t *buffer) {
//   commandBusyFlag = false;
   //   enableUSBIrq();
   while (epBulkIn.getState() != EPIdle) {
      __WFI();
   }
   epBulkIn.startTxTransaction(EPDataIn, size, buffer);
}


} // End namespace USBDM

