/*
 * usb_implementation_bulk.cpp
 *
 *  Created on: 30Oct.,2016
 *      Author: podonoghue
 */
#include <string.h>

#include "usb.h"

namespace USBDM {

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
 * Other descriptors type
 */
struct Usb0::Descriptors {
   ConfigurationDescriptor                  configDescriptor;

   InterfaceDescriptor                      bulk_interface;
   EndpointDescriptor                       bulk_out_endpoint;
   EndpointDescriptor                       bulk_in_endpoint;
   /*
    * TODO Add additional Descriptors here
    */
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

/**
 * Handler for Start of Frame Token interrupt (~1ms interval)
 */
void Usb0::sofCallback() {
   // Activity LED
   // Off                     - no USB activity, not connected
   // On                      - no USB activity, connected
   // Off, flash briefly on   - USB activity, not connected
   // On,  flash briefly off  - USB activity, connected
   if (usb->FRMNUML==0) { // Every ~256 ms
      switch (usb->FRMNUMH&0x03) {
         case 0:
            if (deviceState.state == USBconfigured) {
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
void Usb0::handleTokenComplete(void) {

   // Let parent process first
   if (UsbBase_T::handleTokenComplete()) {
      // Done
      return;
   }

   // Status from Token
   uint8_t   usbStat  = usb->STAT;

   // Endpoint number
   uint8_t   endPoint = ((uint8_t)usbStat)>>4;

   switch (endPoint) {
      case BULK_OUT_ENDPOINT: // Accept OUT token
         setActive();
         epBulkOut.flipOddEven(usbStat);
         epBulkOut.handleOutToken();
         return;
      case BULK_IN_ENDPOINT: // Accept IN token
         epBulkIn.flipOddEven(usbStat);
         epBulkIn.handleInToken();
         return;
      /*
       * TODO Add additional End-point handling here
       */
   }
}

/**
 * Call-back handling BULK-OUT transaction complete
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

   setSOFCallback(sofCallback);
   /*
    * TODO Additional initialisation
    */
}

/**
 * Handler for USB0 interrupt
 *
 * Determines source and dispatches to appropriate routine.
 */
void Usb0::irqHandler() {
   // All active flags
   uint8_t interruptFlags = usb->ISTAT;

   //   if (interruptFlags&~USB_ISTAT_SOFTOK_MASK) {
   //      PRINTF("ISTAT=%2X\n", interruptFlags);
   //   }

   // Get active and enabled interrupt flags
   uint8_t enabledInterruptFlags = interruptFlags & usb->INTEN;

   if ((enabledInterruptFlags&USB_ISTAT_USBRST_MASK) != 0) {
      // Reset signaled on Bus
      handleUSBReset();
      usb->ISTAT = USB_ISTAT_USBRST_MASK; // Clear source
      return;
   }
   if ((enabledInterruptFlags&USB_ISTAT_TOKDNE_MASK) != 0) {
      // Token complete interrupt
      handleTokenComplete();
      // Clear source
      usb->ISTAT = USB_ISTAT_TOKDNE_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_RESUME_MASK) != 0) {
      // Resume signaled on Bus
      handleUSBResume();
      // Clear source
      usb->ISTAT = USB_ISTAT_RESUME_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_STALL_MASK) != 0) {
      // Stall sent
      handleStallComplete();
      // Clear source
      usb->ISTAT = USB_ISTAT_STALL_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_SOFTOK_MASK) != 0) {
      // SOF Token?
      handleSOFToken();
      usb->ISTAT = USB_ISTAT_SOFTOK_MASK; // Clear source
   }
   else if ((enabledInterruptFlags&USB_ISTAT_SLEEP_MASK) != 0) {
      // Bus Idle 3ms => sleep
      //      PUTS("Suspend");
      handleUSBSuspend();
      // Clear source
      usb->ISTAT = USB_ISTAT_SLEEP_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_ERROR_MASK) != 0) {
      // Any Error
      PRINTF("Error s=0x%02X\n", usb->ERRSTAT);
      usb->ERRSTAT = 0xFF;
      // Clear source
      usb->ISTAT = USB_ISTAT_ERROR_MASK;
   }
   else  {
      // Unexpected interrupt
      // Clear & ignore
      PRINTF("Unexpected interrupt, flags=0x%02X\n", interruptFlags);
      // Clear & ignore
      usb->ISTAT = interruptFlags;
   }
}

/**
 *  Blocking reception of data over bulk OUT end-point
 *
 *   @param maxSize  = max # of bytes to receive
 *   @param buffer   = ptr to buffer for bytes received
 *
 *   @return Number of bytes received
 *
 *   @note : Doesn't return until command has been received.
 */
int Usb0::receiveBulkData(uint8_t maxSize, uint8_t *buffer) {
   // Wait for USB connection
   while(deviceState.state != USBconfigured) {
      __WFI();
   }
   epBulkOut.startRxTransaction(EPDataOut, maxSize, buffer);
   while(epBulkOut.getHardwareState().state != EPIdle) {
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
   while (epBulkIn.getHardwareState().state != EPIdle) {
      __WFI();
   }
   epBulkIn.startTxTransaction(EPDataIn, size, buffer);
}

void idleLoop() {
   for(;;) {
      __asm__("nop");
   }
}

} // End namespace USBDM

