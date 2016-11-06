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
static constexpr int VersionID = VERSION_SW;

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

#if (HW_CAPABILITY&CAP_CDC)
   /** Name of CDC interface */
   s_cdc_interface_index,
   /** CDC Control Interface */
   s_cdc_control_interface_index,
   /** CDC Data Interface */
   s_cdc_data_Interface_index,
#endif
   /** Marks last entry */
   s_last_string_descriptor_index
};

/*
 * String descriptors
 */
static const uint8_t s_language[]        = {4, DT_STRING, 0x09, 0x0C};   //!< Language IDs
static const uint8_t s_manufacturer[]    = "pgo";                        //!< Manufacturer
static const uint8_t s_product[]         = ProductDescription;           //!< Product Description
static const uint8_t s_serial[]          = SERIAL_NO;                    //!< Serial Number

static const uint8_t s_bdm_interface[]   = "USBDM BDM Interface";        //!< BDM Interface

#if (HW_CAPABILITY&CAP_CDC)
const const uint8_t s_cdc_interface[]    = "USBDM CDC Interface";        //!< Interface Association #2
const const uint8_t s_cdc_control[]      = "CDC Control Interface";      //!< CDC Control Interface
const const uint8_t s_cdc_data[]         = "CDC Data Interface";         //!< CDC Data Interface
#endif

/**
 * String descriptor table
 */
const uint8_t *const Usb0::stringDescriptors[] = {
      s_language,
      s_manufacturer,
      s_product,
      s_serial,
      s_bdm_interface,
#if (HW_CAPABILITY&CAP_CDC)
      Usb0::s_cdc_interface,
      Usb0::s_cdc_control,
      Usb0::s_cdc_data
#endif
};

#if (HW_CAPABILITY&CAP_CDC)
/**
 * Device Descriptor (Composite)
 */
const DeviceDescriptor Usb0::deviceDescriptor = {
      /* bLength             */ sizeof(DeviceDescriptor),
      /* bDescriptorType     */ DT_DEVICE,
      /* bcdUSB              */ nativeToLe16(0x0200),         // USB specification release No. [BCD = 2.00]
      /* bDeviceClass        */ 0xEF,                         // Device Class code [Miscellaneous Device Class]
      /* bDeviceSubClass     */ 0x02,                         // Sub Class code    [Common Class]
      /* bDeviceProtocol     */ 0x01,                         // Protocol          [Interface Association Descriptor]
      /* bMaxPacketSize0     */ CONTROL_EP_MAXSIZE,           // EndPt 0 max packet size
      /* idVendor            */ nativeToLe16(VendorID),       // Vendor ID
      /* idProduct           */ nativeToLe16(ProductID_CDC),  // Product ID for Composite device
      /* bcdDevice           */ nativeToLe16(VersionID),      // Device Release    [BCD = 4.10]
      /* iManufacturer       */ s_manufacturer_index,         // String index of Manufacturer name
      /* iProduct            */ s_product_index,              // String index of product description
      /* iSerialNumber       */ s_serial_index,               // String index of serial number
      /* bNumConfigurations  */ 1                             // Number of configurations
};
#else
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
#endif

/**
 * Other descriptors
 */
struct Usb0::Descriptors {
   ConfigurationDescriptor                  configDescriptor;
   InterfaceDescriptor                      bdm_interface;
   EndpointDescriptor                       bdm_out_endpoint;
   EndpointDescriptor                       bdm_in_endpoint;
#if (HW_CAPABILITY&CAP_CDC)
   InterfaceAssociationDescriptor           interfaceAssociationDescriptorCDC;
   InterfaceDescriptor                      cdc_CCI_Interface;
   CDCHeaderFunctionalDescriptor            cdc_Functional_Header;
   CDCCallManagementFunctionalDescriptor    cdc_CallManagement;
   CDCAbstractControlManagementDescriptor   cdc_Functional_ACM;
   CDCUnionFunctionalDescriptor             cdc_Functional_Union;
   EndpointDescriptor                       cdc_notification_Endpoint;
   InterfaceDescriptor                      cdc_DCI_Interface;
   EndpointDescriptor                       cdc_dataOut_Endpoint;
   EndpointDescriptor                       cdc_dataIn_Endpoint;
#endif // (HW_CAPABILITY&CAP_CDC)
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
            /* bmAttributes            */ 0x80,     //  = Bus powered, no wakeup (yet?)
            /* bMaxPower               */ USBMilliamps(500)
      },
      { // bdm_interface
            /* bLength                 */ sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ DT_INTERFACE,
            /* bInterfaceNumber        */ Usb0::BDM_INTF_ID,
            /* bAlternateSetting       */ 0,
            /* bNumEndpoints           */ 2,
            /* bInterfaceClass         */ 0xFF,                         // (Vendor specific)
            /* bInterfaceSubClass      */ 0xFF,                         // (Vendor specific)
            /* bInterfaceProtocol      */ 0xFF,                         // (Vendor specific)
            /* iInterface desc         */ s_bdm_interface_index,
      },
      { // bdm_out_endpoint - OUT,Bulk
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_OUT|Usb0::BDM_OUT_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(BDM_OUT_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
      { // bdm_in_endpoint - IN, BULK
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_IN|Usb0::BDM_IN_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(BDM_IN_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
#if (HW_CAPABILITY&CAP_CDC)
      { // interfaceAssociationDescriptorCDC
            /* bLength                 */ sizeof(InterfaceAssociationDescriptor),
            /* bDescriptorType         */ DT_INTERFACEASSOCIATION,
            /* bFirstInterface         */ CDC_COMM_INTF_ID,
            /* bInterfaceCount         */ 2,
            /* bFunctionClass          */ 0x02,                                   //  CDC Control
            /* bFunctionSubClass       */ 0x02,                                   //  Abstract Control Model
            /* bFunctionProtocol       */ 0x01,                                   //  AT CommandL V.250
            /* iFunction = ""          */ s_cdc_interface_index,
      },
      /**
       * CDC Control/Communication Interface, 1 end-point
       */
      { // cdc_CCI_Interface
            /* bLength                 */ sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ DT_INTERFACE,
            /* bInterfaceNumber        */ CDC_COMM_INTF_ID,
            /* bAlternateSetting       */ 0,
            /* bNumEndpoints           */ 1,
            /* bInterfaceClass         */ 0x02,                         //  CDC Communication
            /* bInterfaceSubClass      */ 0x02,                         //  Abstract Control Model
            /* bInterfaceProtocol      */ 0x01,                         //  V.25ter, AT Command V.250
            /* iInterface description  */ s_cdc_control_interface_index
      },
      { // cdc_Functional_Header
            /* bFunctionalLength       */ sizeof(CDCHeaderFunctionalDescriptor),
            /* bDescriptorType         */ CS_INTERFACE,
            /* bDescriptorSubtype      */ DST_HEADER,
            /* bcdCDC                  */ nativeToLe16(0x0110),
      },
      { // cdc_CallManagement
            /* bFunctionalLength       */ sizeof(CDCCallManagementFunctionalDescriptor),
            /* bDescriptorType         */ CS_INTERFACE,
            /* bDescriptorSubtype      */ DST_CALL_MANAGEMENT,
            /* bmCapabilities          */ 1,
            /* bDataInterface          */ CDC_DATA_INTF_ID,
      },
      { // cdc_Functional_ACM
            /* bFunctionalLength       */ sizeof(CDCAbstractControlManagementDescriptor),
            /* bDescriptorType         */ CS_INTERFACE,
            /* bDescriptorSubtype      */ DST_ABSTRACT_CONTROL_MANAGEMENT,
            /* bmCapabilities          */ 0x06,
      },
      { // cdc_Functional_Union
            /* bFunctionalLength       */ sizeof(CDCUnionFunctionalDescriptor),
            /* bDescriptorType         */ CS_INTERFACE,
            /* bDescriptorSubtype      */ DST_UNION_MANAGEMENT,
            /* bmControlInterface      */ CDC_COMM_INTF_ID,
            /* bSubordinateInterface0  */ {CDC_DATA_INTF_ID},
      },
      { // cdc_notification_Endpoint - IN,interrupt
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_IN|CDC_CONTROL_ENDPOINT,
            /* bmAttributes            */ ATTR_INTERRUPT,
            /* wMaxPacketSize          */ nativeToLe16(CDC_CONTROL_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(255)
      },
      /**
       * CDC Data Interface, 2 end-points
       */
      { // cdc_DCI_Interface
            /* bLength                 */ sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ DT_INTERFACE,
            /* bInterfaceNumber        */ CDC_DATA_INTF_ID,
            /* bAlternateSetting       */ 0,
            /* bNumEndpoints           */ 2,
            /* bInterfaceClass         */ 0x0A,                         //  CDC DATA
            /* bInterfaceSubClass      */ 0x00,                         //  -
            /* bInterfaceProtocol      */ 0x00,                         //  -
            /* iInterface description  */ s_cdc_data_Interface_index
      },
      { // cdc_dataOut_Endpoint - OUT,bulk
            /* bLength                 */ sizeof(EndpointDescriptor),
            /* bDescriptorType         */ DT_ENDPOINT,
            /* bEndpointAddress        */ EP_OUT|CDC_DATA_OUT_ENDPOINT,
            /* bmAttributes            */ ATTR_BULK,
            /* wMaxPacketSize          */ nativeToLe16(CDC_DATA_OUT_EP_MAXSIZE),
            /* bInterval               */ USBMilliseconds(1)
      },
      { // cdc_dataIn_Endpoint - IN,bulk
            /*  bLength                */ sizeof(EndpointDescriptor),
            /*  bDescriptorType        */ DT_ENDPOINT,
            /*  bEndpointAddress       */ EP_IN|CDC_DATA_IN_ENDPOINT,
            /*  bmAttributes           */ ATTR_BULK,
            /*  wMaxPacketSize         */ nativeToLe16(2*CDC_DATA_IN_EP_MAXSIZE), // x2 so all packets are terminating (short))
            /*  bInterval              */ USBMilliseconds(1)
      },
#endif
};

/**
 * Handler for Token Complete USB interrupt
 *
 * Handles ep0 [SETUP, IN & OUT]
 * Handles ep1 [Out]
 * Handles ep2 [In]
 * Handles ep3 [In]
 * Handles ep4 [Out]
 * Handles ep5 [In]
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
   case BDM_OUT_ENDPOINT: // USBDM BDM - Accept OUT token
      setActive();
      ep1.flipOddEven(usbStat);
      ep1.handleOutToken();
      return;
   case BDM_IN_ENDPOINT: // USBDM BDM - Accept IN token
      setActive();
      ep2.flipOddEven(usbStat);
      ep2.handleInToken();
      return;
#if (HW_CAPABILITY&CAP_CDC)
   case CDC_CONTROL_ENDPOINT: // USBDM CDC Control - Accept IN token
      PRINTF("EP3\n");
      epHardwareState[CDC_CONTROL_ENDPOINT].data0_1 = !epHardwareState[CDC_CONTROL_ENDPOINT].data0_1; // Toggle data0/1
      ep3StartTxTransaction();
      return;
   case CDC_DATA_OUT_ENDPOINT: // USBDM CDC Data - Accept OUT token
      if (cdc_txBufferIsFree()) {
         ep4SaveRxData();
         ep4InitialiseBdtRx();
      }
      else {
         //! Throttle endpoint - send NAKs
         epHardwareState[CDC_DATA_OUT_ENDPOINT].state = EPThrottle;
      }
      return;
   case CDC_DATA_IN_ENDPOINT:  // USBD CDC Data - Accept IN token
      epHardwareState[CDC_DATA_IN_ENDPOINT].state = EPIdle;
      //          ep5StartInTransactionIfIdle();
      return;
#endif
   }
}
/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();
   // Other initialisation as required
   ep1.initialise();
   ep2.initialise();
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

   if ((enabledInterruptFlags&USB_ISTAT_TOKDNE_MASK) != 0) {
      // Token complete interrupt?
      handleTokenComplete();
      usb->ISTAT = USB_ISTAT_TOKDNE_MASK; // Clear source
   }
   else if ((enabledInterruptFlags&USB_ISTAT_RESUME_MASK) != 0) {
      // Resume signaled on Bus?
      handleUSBResume();
      usb->ISTAT = USB_ISTAT_RESUME_MASK; // Clear source
   }
   else if ((enabledInterruptFlags&USB_ISTAT_USBRST_MASK) != 0) {
      // Reset signaled on Bus
      handleUSBReset();
      usb->ISTAT = USB_ISTAT_USBRST_MASK; // Clear source
   }
   else if ((enabledInterruptFlags&USB_ISTAT_STALL_MASK) != 0) {
      // Stall sent?
      handleStallComplete();
      usb->ISTAT = USB_ISTAT_STALL_MASK; // Clear source
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
      usb->ISTAT = USB_ISTAT_SLEEP_MASK; // Clear source
   }
   else if ((enabledInterruptFlags&USB_ISTAT_ERROR_MASK) != 0) {
      // Any Error
      PRINTF("Error s=0x%02X\n", usb->ERRSTAT);
      usb->ERRSTAT = 0xFF;
      usb->ISTAT = USB_ISTAT_ERROR_MASK; // Clear source
   }
   else  {
      // Unexpected interrupt
      // Clear & ignore
      PRINTF("Unexpected interrupt, flags=0x%02X\n", interruptFlags);
      usb->ISTAT = interruptFlags; // Clear & ignore
   }
}

void idleLoop() {
   for(;;) {
      __asm__("nop");
   }
}

#if (HW_CAPABILITY&CAP_CDC)
//======================================================================
// Configure EP3 for an IN transaction [Tx, device -> host, DATA0/1]
//
static void ep3StartTxTransaction() {
   const CDCNotification cdcNotification= {CDC_NOTIFICATION, SERIAL_STATE, 0, RT_INTERFACE, nativeToLe16(2)};
   uint8_t status = cdc_getSerialState();

   if ((status & SERIAL_STATE_CHANGE) == 0) {
      epHardwareState[CDC_CONTROL_ENDPOINT].state = EPIdle; // Not busy
      return;
   }
   // Copy the Tx data to Tx buffer
   (void)memcpy(cdcControlDataBuffer, &cdcNotification, sizeof(cdcNotification));
   cdcControlDataBuffer[sizeof(cdcNotification)+0] = status&~SERIAL_STATE_CHANGE;
   cdcControlDataBuffer[sizeof(cdcNotification)+1] = 0;

   // Set up to Tx packet
   BdtEntry *bdt = epHardwareState[CDC_CONTROL_ENDPOINT].txOdd?&endPointBdts[CDC_CONTROL_ENDPOINT].txOdd:&endPointBdts[CDC_CONTROL_ENDPOINT].txEven;
   bdt->bc = sizeof(cdcNotification)+2;
   if (epHardwareState[CDC_CONTROL_ENDPOINT].data0_1) {
      bdt->u.bits = BDTEntry_OWN_MASK|BDTEntry_DATA1_MASK|BDTEntry_DTS_MASK;
   }
   else {
      bdt->u.bits = BDTEntry_OWN_MASK|BDTEntry_DATA0_MASK|BDTEntry_DTS_MASK;
   }
   epHardwareState[CDC_CONTROL_ENDPOINT].state = EPLastIn;    // Sending one and only packet
}

/**
 *  Configure the BDT for EP4 Out [Rx, device <- host, DATA0/1]
 *  CDC - OUT
 */
static void ep4InitialiseBdtRx() {
   BdtEntry *bdt = epHardwareState[CDC_DATA_OUT_ENDPOINT].rxOdd?&endPointBdts[CDC_DATA_OUT_ENDPOINT].rxOdd:&endPointBdts[CDC_DATA_OUT_ENDPOINT].rxEven;

   // Set up to Rx packet
   bdt->bc = CDC_DATA_OUT_EP_MAXSIZE;
   if (epHardwareState[CDC_DATA_OUT_ENDPOINT].data0_1) {
      bdt->u.bits  = BDTEntry_OWN_MASK|BDTEntry_DATA1_MASK|BDTEntry_DTS_MASK;
   }
   else {
      bdt->u.bits  = BDTEntry_OWN_MASK|BDTEntry_DATA0_MASK|BDTEntry_DTS_MASK;
   }
}

/**
 * Save the data from an EP4 OUT packet
 * CDC - OUT
 */
static void ep4SaveRxData() {
   // Get BDT
   BdtEntry *bdt = (!epHardwareState[CDC_DATA_OUT_ENDPOINT].rxOdd)?&endPointBdts[CDC_DATA_OUT_ENDPOINT].rxOdd:&endPointBdts[CDC_DATA_OUT_ENDPOINT].rxEven;
   uint8_t size = bdt->bc;
   (void)cdc_putTxBuffer((char*)cdcOutDataBuffer, size);

   // Toggle on successful reception
   epHardwareState[CDC_DATA_OUT_ENDPOINT].data0_1 = !epHardwareState[CDC_DATA_OUT_ENDPOINT].data0_1;
}

/**
 * Configure the BDT for EP5 In [Tx, device -> host]
 * CDC - IN
 */
static void ep5InitialiseBdtTx(void) {
   // Set up to Tx packet
   if (epHardwareState[CDC_DATA_IN_ENDPOINT].txOdd) {
      // Set to write to other buffer & get count in current buffer
      endPointBdts[CDC_DATA_IN_ENDPOINT].txOdd.bc     = cdc_setRxBuffer((char*)cdcInDataBuffer0);
      //       cdcInDataBuffer1[0]       = '|';
      endPointBdts[CDC_DATA_IN_ENDPOINT].txOdd.u.bits = BDTEntry_OWN_MASK|BDTEntry_DATA1_MASK;
   }
   else {
      // Set to write to other buffer & get count in current buffer
      endPointBdts[CDC_DATA_IN_ENDPOINT].txEven.bc    = cdc_setRxBuffer((char*)cdcInDataBuffer1);
      //       cdcInDataBuffer0[0]       = '^';
      endPointBdts[CDC_DATA_IN_ENDPOINT].txEven.u.bits = BDTEntry_OWN_MASK|BDTEntry_DATA0_MASK;
   }
   //   epHardwareState[CDC_DATA_IN_ENDPOINT].data0_1 = !epHardwareState[CDC_DATA_IN_ENDPOINT].data0_1; // Toggle data0/1
   epHardwareState[CDC_DATA_IN_ENDPOINT].txOdd     = !epHardwareState[CDC_DATA_IN_ENDPOINT].txOdd;
}
void checkUsbCdcTxData(void) {
   // Check if we need to unThrottle EP4
   if ((epHardwareState[CDC_DATA_OUT_ENDPOINT].state == EPThrottle) && cdc_txBufferIsFree()) {
      ep4SaveRxData();        // Save data from last transfer
      ep4InitialiseBdtRx();   // Set up next transfer
      epHardwareState[CDC_DATA_OUT_ENDPOINT].state = EPDataOut;
   }
}

static uint8_t serialDelayCount = 0;

// This value controls how long the serial interface will wait before
// sending a buffered character. (count of SOFs ~ ms)
constexpr uint SERIAL_THRESHOLD = 0; // ms

/**
 * Configure the BDT for EP5 In [Tx, device -> host]
 * CDC - IN
 */
static void ep5StartTxTransactionIfIdle() {
#if 0
   if ((epHardwareState[CDC_DATA_IN_ENDPOINT].state == EPIdle) && (cdc_rxBufferItemCount()>0)) {
      ep5InitialiseBdtTx();
      epHardwareState[CDC_DATA_IN_ENDPOINT].state = EPLastIn;
      serialDelayCount = 0;
   }
   else if ((epHardwareState[CDC_DATA_IN_ENDPOINT].state == EPLastIn) && (cdc_rxBufferItemCount()==16)) {
      ep5InitialiseBdtTx();
      epHardwareState[CDC_DATA_IN_ENDPOINT].state = EPDataIn;
      serialDelayCount = 0;
   }
#else
   if ((epHardwareState[CDC_DATA_IN_ENDPOINT].state == EPIdle) && (cdc_rxBufferItemCount()>0)) {
      ep5InitialiseBdtTx();
      epHardwareState[CDC_DATA_IN_ENDPOINT].state = EPDataIn;
      serialDelayCount = 0;
   }
#endif
}

void checkUsbCdcRxData(void) {
   ep5StartTxTransactionIfIdle();
}
#endif

/**
 *   Receive a command over EP1
 *
 *   @param maxSize  = max # of bytes to receive
 *   @param buffer   = ptr to buffer for bytes received
 *
 *   @note : Doesn't return until command has been received.
 *   @note : Format
 *       - [0]    = size of command (N)
 *       - [1]    = command
 *       - [2..N] = parameters
 *
 *   =======================================================
 *   Format - a command is made up of up to 2 pkts
 *   The size of the 1st packet indicates if subsequent pkts
 *   are used.
 *
 *    1st packet
 *   +--------------------------+
 *   |  Size of entire command  |  0 - size includes 2nd packet
 *   +--------------------------+
 *   |  Command byte            |  1
 *   +--------------------------+
 *   |                          |  2... up to BDM_OUT_EP_MAXSIZE-2
 *   | //// DATA ////////////// |
 *   |                          |
 *   +--------------------------+
 *    2nd packet (optional)
 *   +--------------------------+
 *   |  0                       |  0 - Ensures packet can't be mistaken as 1st packet
 *   +--------------------------+
 *   |                          |  1... up to BDM_OUT_EP_MAXSIZE-1
 *   | //// DATA ////////////// |
 *   |                          |
 *   +--------------------------+
 *
 */
//void receiveUSBCommand(uint8_t maxSize, uint8_t *buffer) {
//   uint8_t size;
//
//   // Wait for USB connection
//   while(deviceState.state != USBconfigured) {
//      __WFI();
//   }
//   Usb0::enableNvicInterrupts(true);
//
//   // Size of first (command) transaction
//   do {
//      size = BDM_OUT_EP_MAXSIZE;
//      if (size > maxSize) {
//         size = maxSize;
//      }
//      // Get 1st/only packet of command
//      reInit = false;
//      ep1.startRxTransaction( size, buffer );
//      while ((epHardwareState[BDM_OUT_ENDPOINT].state != EPComplete) && !reInit) {
//         __WFI();
//      }
//      if (reInit) {
//         continue;
//      }
//      // Size for entire command from 1st packet
//      size = buffer[0];
//      if (size > maxSize) {
//         size = maxSize;
//      }
//      if (size == 0) {
//         // Invalid packet - try again
//         // 0 indicates this is not an initial command packet
//         // but part of a longer command
//         reInit = true;
//         continue;
//      }
//      // Receive rest of data if present (only possibly 2 transactions total)
//      if (size > ep1.Endpoint::fDataCount) {
//         // Save last byte of 1st packet as overwritten by
//         // second packet (to save moving 2nd packet when size is discarded)
//         uint8_t saveByteOffset = ep1.Endpoint::fDataCount-1;
//         uint8_t saveByte       = buffer[saveByteOffset];
//         ep1.startRxTransaction( size-saveByteOffset, buffer+saveByteOffset );
//
//         while ((ep0.Endpoint::fState != EPComplete) && !reInit) {
//            __WFI();
//         }
//         // Check if second packet has correct marker
//         if (buffer[saveByteOffset] != 0) {
//            // packet corrupt
//            reInit = true;
//         }
//         // Restore saved byte
//         buffer[saveByteOffset] = saveByte;
//      }
//   } while (reInit);
//   //   PUTS(epHardwareState[BDM_OUT_ENDPOINT].data0_1?"receiveUSBCommand-1\n":"receiveUSBCommand-0\n");
//}

/**
 *  Set a command response over EP2
 *
 *  @param size   = # of bytes to send
 *  @param buffer = ptr to bytes to send
 *
 *  @note : Returns before the command has been sent.
 *
 *  @note : Format
 *      - [0]    = response
 *      - [1..N] = parameters
 */
//void sendUSBResponse( uint8_t size, const uint8_t *buffer) {
//   commandBusyFlag = false;
//   //   enableUSBIrq();
//   //   while (epHardwareState[BDM_IN_ENDPOINT].state != EPIdle) {
//   //   }
//   //   PUTS(epHardwareState[BDM_IN_ENDPOINT].data0_1?"sendUSBResponse-1\n":"sendUSBResponse-0\n");
//   ep2.startTxTransaction(size, buffer);
//}

} // End namespace USBDM

