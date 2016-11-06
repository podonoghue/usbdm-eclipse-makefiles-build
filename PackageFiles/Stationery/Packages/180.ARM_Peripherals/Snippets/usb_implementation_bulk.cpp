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

static const uint8_t s_bulk_interface[]   = "Bulk Interface";            //!< Bulk Interface


/**
 * String descriptor table
 */
const uint8_t *const Usb0::stringDescriptors[] = {
      s_language,
      s_manufacturer,
      s_product,
      s_serial,
      s_bulk_interface,
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
 * Other descriptors
 */
struct Usb0::Descriptors {
   ConfigurationDescriptor                  configDescriptor;
   InterfaceDescriptor                      bulk_interface;
   EndpointDescriptor                       bulk_out_endpoint;
   EndpointDescriptor                       bulk_in_endpoint;
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
            /* iConfiguration          */ 0,
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
      { // bulk_in_endpoint - IN, BULK
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_IN|BULK_IN_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(BULK_IN_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
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

   // Status from Token
   uint8_t   usbStat  = usb->STAT;

   // Endpoint number
   uint8_t   endPoint = ((uint8_t)usbStat)>>4;

   switch (endPoint) {
      case BULK_OUT_ENDPOINT: // Bulk OUT - Accept OUT token
         setActive();
         epBulkOut.flipOddEven(usbStat);
         epBulkOut.handleOutToken();
         return;
      case BULK_IN_ENDPOINT: // Bulk IN - Accept IN token
         epBulkIn.flipOddEven(usbStat);
         epBulkIn.handleInToken();
         return;
   }
}

void Usb0::bulkOutCallback(EndpointState state) {
   static uint8_t buff[] = "";
   PRINTF("%c\n", buff[0]);
   if (state == EPDataOut) {
      epBulkOut.startRxTransaction(sizeof(buff), buff, EPDataOut);
   }
}

void Usb0::bulkInCallback(EndpointState state) {
   static const uint8_t buff[] = "Hello There\n\r";
   if (state == EPDataIn) {
      epBulkIn.startTxTransaction(sizeof(buff), buff, EPDataIn);
   }
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();
}

/**
 * Handler for USB0 interrupt
 *
 * Determines source and dispatches to appropriate routine.
 */
void Usb0::irqHandler() {
   // All active flags
   uint8_t interruptFlags = usb->ISTAT;

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
      UsbBase_T::handleTokenComplete();
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

void idleLoop() {
   for(;;) {
      __asm__("nop");
   }
}

/**
 *  Blocking reception of data over bulk OUT end-point
 *
 *   @param maxSize  = max # of bytes to receive
 *   @param buffer   = ptr to buffer for bytes received
 *
 *   @note : Doesn't return until command has been received.
 */
void Usb0::receiveData(uint8_t maxSize, uint8_t *buffer) {
   // Wait for USB connection
   while(deviceState.state != USBconfigured) {
      __WFI();
   }
   Usb0::enableNvicInterrupts(true);
   epBulkOut.startRxTransaction(maxSize, buffer, EPDataOut);
   while(epBulkOut.getHardwareState().state != EPIdle) {
      __WFI();
   }
}

/**
 *  Blocking transmission of data over bulk IN end-point
 *
 *  @param size   Number of bytes to send
 *  @param buffer Pointer to bytes to send
 *
 *  @note : Returns before the data has been transmitted.\n
 *  So buffer may not be re-used unless smaller than epBulkIn.BUFFER_SIZE
 *
 *  @note : Format
 *      - [0]    = response
 *      - [1..N] = parameters
 */
void Usb0::sendData( uint8_t size, const uint8_t *buffer) {
//   commandBusyFlag = false;
   //   enableUSBIrq();
   while (epBulkIn.getHardwareState().state != EPIdle) {
      __WFI();
   }
   epBulkIn.startTxTransaction(size, buffer, EPDataIn);
}

} // End namespace USBDM

