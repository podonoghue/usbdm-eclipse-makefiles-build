/*
 * usb_implementation.cpp
 *
 *  Created on: 30Oct.,2016
 *      Author: podonoghue
 */
#include <string.h>

#include "configure.h"
#include "usb.h"

namespace USBDM {

static constexpr int VendorID  = 0x16D0;
static constexpr int ProductID = 0x0567;
static constexpr int VersionID = 0x0100;
enum InterfaceNumbers {
   /** Interface number for CDC Control channel */
   INTF_ID,
   /*
    * TODO Add additional Interface numbers here
    */
   /** Total number of interfaces */
   NUMBER_OF_INTERFACES,
};

/**
 * String indexes
 *
 * Must agree with stringDescriptors[] order
 */
enum StringIds {
   /** Language information for string descriptors */
   s_language_index=0,    // Must be zero
   /** Manufacturer */
   s_manufacturer_index,
   /** Product Description */
   s_product_index,
   /** Serial Number */
   s_serial_index,

   /** Name of BDM interface */
   s_bdm_interface_index,
   /*
    * TODO Add additional StringIds here
    */
   /** Marks last entry */
   s_last_string_descriptor_index
};

/*
 * String descriptors
 */
static const uint8_t s_language[]        = {4, DT_STRING, 0x09, 0x0C};   //!< Language IDs
static const uint8_t s_manufacturer[]    = "Manufacturer";               //!< Manufacturer
static const uint8_t s_product[]         = "Product description";        //!< Product Description
static const uint8_t s_serial[]          = "Serial Number";              //!< Serial Number

static const uint8_t s_bdm_interface[]   = "Interface";                  //!< Interface Name
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
      s_bdm_interface,
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
      /* bcdUSB              */ nativeToLe16(0x0200),    // USB specification release No. [BCD = 2.00]
      /* bDeviceClass        */ 0xFF,                    // Class code        [none]
      /* bDeviceSubClass     */ 0xFF,                    // Sub Class code    [none]
      /* bDeviceProtocol     */ 0xFF,                    // Protocol          [none]
      /* bMaxPacketSize0     */ CONTROL_EP_MAXSIZE,      // EndPt 0 max packet size
      /* idVendor            */ nativeToLe16(VendorID),  // Vendor ID
      /* idProduct           */ nativeToLe16(ProductID), // Product ID for simple device
      /* bcdDevice           */ nativeToLe16(VersionID), // Device Release    [BCD = 4.10]
      /* iManufacturer       */ s_manufacturer_index,    // String index of Manufacturer name
      /* iProduct            */ s_product_index,         // String index of product description
      /* iSerialNumber       */ s_serial_index,          // String index of serial number
      /* bNumConfigurations  */ 1                        // Number of configurations
};

/**
 * Other descriptors
 */
struct Usb0::Descriptors {
   ConfigurationDescriptor                  configDescriptor;

   InterfaceDescriptor        interface0;
   /*
    * TODO Add additional Descriptors here
    */
};

/**
 * All other descriptors
 */
const Usb0::Descriptors Usb0::otherDescriptors =
{
      { // configDescriptor
            /* bLength                 */ sizeof(ConfigurationDescriptor),
            /* bDescriptorType         */ DT_CONFIGURATION,
            /* wTotalLength            */ nativeToLe16(sizeof(otherDescriptors)),
            /* bNumInterfaces          */ NUMBER_OF_INTERFACES,
            /* bConfigurationValue     */ Usb0::CONFIGURATION_NUM,
            /* iConfiguration          */ 0,
            /* bmAttributes            */ 0x80,     //  = Bus powered, no wake-up
            /* bMaxPower               */ USBMilliamps(500)
      },
      /*
       * Modify to add end-points
       */
      { // interface0
            /* bLength                 */ sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ DT_INTERFACE,
            /* bInterfaceNumber        */ Usb0::INTF_ID,
            /* bAlternateSetting       */ 0,
            /* bNumEndpoints           */ 0, // TODO - modify
            /* bInterfaceClass         */ 0xFF,  // (Vendor specific)
            /* bInterfaceSubClass      */ 0xFF,  // (Vendor specific)
            /* bInterfaceProtocol      */ 0xFF,  // (Vendor specific)
            /* iInterface desc         */ s_bdm_interface_index,
      },
      /*
       * TODO Add additional Descriptors here
       */
};

/**
 * Handler for Token Complete USB interrupt
 *
 * ep0 [SETUP, IN & OUT] - passed to UsbBase_T::handleTokenCompleteEp0
 * Other end-points as needed
 */
void Usb0::handleTokenComplete(void) {

   // Status from Token
   uint8_t   usbStat  = usb->STAT;

   // Endpoint number
   uint8_t   endPoint = ((uint8_t)usbStat)>>4;

   if (endPoint == CONTROL_ENDPOINT) {
      // EP0
      UsbBase_T::handleTokenCompleteEp0();
      return;
   }
   switch (endPoint) {
      /*
       * TODO Add additional End-point handling here
       */
   }
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();
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
      // Token complete interrupt?
      handleTokenComplete();
      // Clear source
      usb->ISTAT = USB_ISTAT_TOKDNE_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_RESUME_MASK) != 0) {
      // Resume signaled on Bus?
      handleUSBResume();
      // Clear source
      usb->ISTAT = USB_ISTAT_RESUME_MASK;
   }
   else if ((enabledInterruptFlags&USB_ISTAT_STALL_MASK) != 0) {
      // Stall sent?
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
      // Bus Idle 3ms? => sleep
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

} // End namespace USBDM

