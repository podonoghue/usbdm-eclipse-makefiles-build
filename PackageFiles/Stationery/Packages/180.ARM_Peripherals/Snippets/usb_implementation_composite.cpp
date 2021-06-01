/**
 * @file     usb_implementation_composite.cpp
 * @brief    USB Composite device implementation
 *
 * This module provides an implementation of a USB Composite interface
 * including the following end points:
 *  - EP0 Standard control
 *  - EP1 Bulk OUT
 *  - EP2 Bulk IN
 *  - EP3 Interrupt CDC notification
 *  - EP4 CDC data OUT
 *  - EP5 CDC data IN
 *
 * @version  V4.12.1.170
 * @date     2 April 2017
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */
#include <string.h>

#include "usb.h"
#include "usb_implementation_composite.h"

namespace USBDM {

/**
 * Interface numbers for USB descriptors
 */
enum InterfaceNumbers {
   /** Interface number for BDM channel */
   BULK_INTF_ID,

   /** Interface number for CDC Control channel */
   CDC_COMM_INTF_ID,

   /** Interface number for CDC Data channel */
   CDC_DATA_INTF_ID,
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

static const uint8_t s_cdc_interface[]   = "CDC Interface";             //!< Interface Association #2
static const uint8_t s_cdc_control[]     = "CDC Control Interface";     //!< CDC Control Interface
static const uint8_t s_cdc_data[]        = "CDC Data Interface";        //!< CDC Data Interface
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

      s_cdc_interface,
      s_cdc_control,
      s_cdc_data
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
      /* bDeviceClass        */ (uint8_t) 0xEF,                           // Device Class code [Miscellaneous Device Class]
      /* bDeviceSubClass     */ (uint8_t) 0x02,                           // Sub Class code    [Common Class]
      /* bDeviceProtocol     */ (uint8_t) 0x01,                           // Protocol          [Interface Association Descriptor]
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
      { // interfaceAssociationDescriptorCDC
            /* bLength                 */ (uint8_t) sizeof(InterfaceAssociationDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_INTERFACEASSOCIATION,
            /* bFirstInterface         */ (uint8_t) CDC_COMM_INTF_ID,
            /* bInterfaceCount         */ (uint8_t) 2,
            /* bFunctionClass          */ (uint8_t) 0x02,                      //  CDC Control
            /* bFunctionSubClass       */ (uint8_t) 0x02,                      //  Abstract Control Model
            /* bFunctionProtocol       */ (uint8_t) 0x01,                      //  AT CommandL V.250
            /* iFunction = ""          */ (uint8_t) s_cdc_interface_index,
      },
      /**
       * CDC Control/Communication Interface, 1 end-point
       */
      { // cdc_CCI_Interface
            /* bLength                 */ (uint8_t) sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_INTERFACE,
            /* bInterfaceNumber        */ (uint8_t) CDC_COMM_INTF_ID,
            /* bAlternateSetting       */ (uint8_t) 0,
            /* bNumEndpoints           */ (uint8_t) 1,
            /* bInterfaceClass         */ (uint8_t) 0x02,      //  CDC Communication
            /* bInterfaceSubClass      */ (uint8_t) 0x02,      //  Abstract Control Model
            /* bInterfaceProtocol      */ (uint8_t) 0x01,      //  V.25ter, AT Command V.250
            /* iInterface description  */ (uint8_t) s_cdc_control_interface_index
      },
      { // cdc_Functional_Header
            /* bFunctionalLength       */ (uint8_t) sizeof(CDCHeaderFunctionalDescriptor),
            /* bDescriptorType         */ (uint8_t) CS_INTERFACE,
            /* bDescriptorSubtype      */ (uint8_t) DST_HEADER,
            /* bcdCDC                  */ (uint8_t) nativeToLe16(0x0110),
      },
      { // cdc_CallManagement
            /* bFunctionalLength       */ (uint8_t) sizeof(CDCCallManagementFunctionalDescriptor),
            /* bDescriptorType         */ (uint8_t) CS_INTERFACE,
            /* bDescriptorSubtype      */ (uint8_t) DST_CALL_MANAGEMENT,
            /* bmCapabilities          */ (uint8_t) 1,
            /* bDataInterface          */ (uint8_t) CDC_DATA_INTF_ID,
      },
      { // cdc_Functional_ACM
            /* bFunctionalLength       */ (uint8_t) sizeof(CDCAbstractControlManagementDescriptor),
            /* bDescriptorType         */ (uint8_t) CS_INTERFACE,
            /* bDescriptorSubtype      */ (uint8_t) DST_ABSTRACT_CONTROL_MANAGEMENT,
            /* bmCapabilities          */ (uint8_t) 0x06,
      },
      { // cdc_Functional_Union
            /* bFunctionalLength       */ (uint8_t) sizeof(CDCUnionFunctionalDescriptor),
            /* bDescriptorType         */ (uint8_t) CS_INTERFACE,
            /* bDescriptorSubtype      */ (uint8_t) DST_UNION_MANAGEMENT,
            /* bmControlInterface      */ (uint8_t) CDC_COMM_INTF_ID,
            /* bSubordinateInterface0  */ (uint8_t) {CDC_DATA_INTF_ID},
      },
      { // cdc_notification_Endpoint - IN,interrupt
            /* bLength                 */ (uint8_t) sizeof(EndpointDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_ENDPOINT,
            /* bEndpointAddress        */ (uint8_t) EP_IN|CDC_NOTIFICATION_ENDPOINT,
            /* bmAttributes            */ (uint8_t) ATTR_INTERRUPT,
            /* wMaxPacketSize          */ (uint16_t)nativeToLe16(CDC_NOTIFICATION_EP_MAXSIZE),
            /* bInterval               */ (uint8_t) USBMilliseconds(255)
      },
      /**
       * CDC Data Interface, 2 end-points
       */
      { // cdc_DCI_Interface
            /* bLength                 */ (uint8_t) sizeof(InterfaceDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_INTERFACE,
            /* bInterfaceNumber        */ (uint8_t) CDC_DATA_INTF_ID,
            /* bAlternateSetting       */ (uint8_t) 0,
            /* bNumEndpoints           */ (uint8_t) 2,
            /* bInterfaceClass         */ (uint8_t) 0x0A,                         //  CDC DATA
            /* bInterfaceSubClass      */ (uint8_t) 0x00,                         //  -
            /* bInterfaceProtocol      */ (uint8_t) 0x00,                         //  -
            /* iInterface description  */ (uint8_t) s_cdc_data_Interface_index
      },
      { // cdc_dataOut_Endpoint - OUT, Bulk
            /* bLength                 */ (uint8_t) sizeof(EndpointDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_ENDPOINT,
            /* bEndpointAddress        */ (uint8_t) EP_OUT|CDC_DATA_OUT_ENDPOINT,
            /* bmAttributes            */ (uint8_t) ATTR_BULK,
            /* wMaxPacketSize          */ (uint16_t)nativeToLe16(CDC_DATA_OUT_EP_MAXSIZE),
            /* bInterval               */ (uint8_t) USBMilliseconds(1)
      },
      { // cdc_dataIn_Endpoint - IN, Bulk
            /* bLength                 */ (uint8_t) sizeof(EndpointDescriptor),
            /* bDescriptorType         */ (uint8_t) DT_ENDPOINT,
            /* bEndpointAddress        */ (uint8_t) EP_IN|CDC_DATA_IN_ENDPOINT,
            /* bmAttributes            */ (uint8_t) ATTR_BULK,
            /* wMaxPacketSize          */ (uint16_t)nativeToLe16(CDC_DATA_IN_EP_MAXSIZE),
            /* bInterval               */ (uint8_t) USBMilliseconds(1)
      },
      /*
       * TODO Add additional Descriptors here
       */
};

/** Out end-point for BULK data out */
OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT,         BULK_OUT_EP_MAXSIZE>          Usb0::epBulkOut(EndPointType_Bulk);

/** In end-point for BULK data in */
InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,          BULK_IN_EP_MAXSIZE>           Usb0::epBulkIn(EndPointType_Bulk);

/** In end-point for CDC notifications */
InEndpoint  <Usb0Info, Usb0::CDC_NOTIFICATION_ENDPOINT, CDC_NOTIFICATION_EP_MAXSIZE>  Usb0::epCdcNotification(EndPointType_Bulk);

/** Out end-point for CDC data out */
OutEndpoint <Usb0Info, Usb0::CDC_DATA_OUT_ENDPOINT,     CDC_DATA_OUT_EP_MAXSIZE>      Usb0::epCdcDataOut(EndPointType_Interrupt);

/** In end-point for CDC data in */
InEndpoint  <Usb0Info, Usb0::CDC_DATA_IN_ENDPOINT,      CDC_DATA_IN_EP_MAXSIZE>       Usb0::epCdcDataIn(EndPointType_Interrupt);
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
//            UsbLed::write(fConnectionState == USBconfigured);
            break;
         case 1:
         case 2:
            break;
         case 3:
         default :
            if (fActivityFlag) {
               // Activity LED flashes
//               UsbLed::toggle();
               setActive(false);
            }
            break;
      }
   }
   // Check CDC status
   epCdcSendNotification();

   return E_NO_ERROR;
}

ErrorCode userCallbackFunction(const Usb0::UserEvent event) {
   switch(event) {
      case Usb0::UserEvent_Suspend:
      case Usb0::UserEvent_Reset:
//         UsbLed::off();
         break;

      case Usb0::UserEvent_Resume:
      case Usb0::UserEvent_Configure:
         break;
   }
   return E_NO_ERROR;
}

/**
 * Configure epCdcNotification for an IN status transaction [Tx, device -> host, DATA0/1]\n
 * A packet is only sent if there has been a change in status
 */
void Usb0::epCdcSendNotification() {
//   if (fConnectionState != USBconfigured) {
//      // Only send notifications if configured.
//      return;
//   }
   static const struct CDCNotificationData {
      CDCNotification notification;
      uint8_t         data[2];
   } cdcNotification = {
      { CDC_NOTIFICATION, SERIAL_STATE, 0, RT_INTERFACE, nativeToLe16(2) },
      {0,0}};

   static uint8_t lastStatus = -1;
   uint8_t status = cdcInterface::getSerialState().bits;

   if (status == lastStatus) {
      // No change
      return;
   }
   if (epCdcNotification.getState() != EPIdle) {
      // Busy with previous
      return;
   }
   static_assert(epCdcNotification.BUFFER_SIZE>=sizeof(cdcNotification), "Buffer size insufficient");

   lastStatus = status;

   // Copy the data to Tx buffer
   CDCNotificationData *buff = (CDCNotificationData*)epCdcNotification.getTxBuffer();
   Endpoint::safeCopy(buff, &cdcNotification, sizeof(cdcNotification));
   buff->data[0] = status;
   buff->data[1] = 0;

   // Set up to Tx packet
//   console.write("epCdcSendNotification() 0x").writeln(epCdcNotification.getBuffer()[sizeof(cdcNotification)+0], USBDM::Radix_16);
   epCdcNotification.startTxStage(EPDataIn, sizeof(cdcNotification));
}

static uint8_t cdcOutBuff[10] = "Welcome\n";
static int cdcOutByteCount    = 8;

/**
 * Start CDC IN transaction\n
 * A packet is only sent if data is available
 */
void Usb0::startCdcIn() {
   if ((epCdcDataIn.getState() == EPIdle) && (cdcOutByteCount>0)) {
      static_assert(epCdcDataIn.BUFFER_SIZE>sizeof(cdcOutBuff), "Buffer too small");
      Endpoint::safeCopy(epCdcDataIn.getBuffer(), cdcOutBuff, cdcOutByteCount);
      //TODO Check if need ZLP
      epCdcDataIn.setNeedZLP();
      epCdcDataIn.startTxStage(EPDataIn, cdcOutByteCount);
      cdcOutByteCount = 0;
   }
}

/**
 * Handler for Token Complete USB interrupts for
 * end-points other than EP0
 *
 * @param[in] usbStat USB Status value from USB hardware
 */
void Usb0::handleTokenComplete(UsbStat usbStat) {

   // Endpoint number
   uint8_t endPoint = usbStat.endp;

   fEndPoints[endPoint]->flipOddEven(usbStat);
   switch (endPoint) {
      case BULK_OUT_ENDPOINT: // Accept OUT token
         epBulkOut.handleOutToken();
         return;
      case BULK_IN_ENDPOINT: // Accept IN token
         epBulkIn.handleInToken();
         return;

      case CDC_NOTIFICATION_ENDPOINT: // Accept IN token
         // CDC Notification has been ACKed
//         console.WRITELN("CDC_NOTIFICATION_ENDPOINT");
         epCdcNotification.handleInToken();
         return;
      case CDC_DATA_OUT_ENDPOINT: // Accept OUT token
//         console.WRITELN("CDC_DATA_OUT_ENDPOINT");
         epCdcDataOut.handleOutToken();
         return;
      case CDC_DATA_IN_ENDPOINT:  // Accept IN token
//         console.WRITELN("CDC_DATA_IN_ENDPOINT");
         // Data has been ACKed
         epCdcDataIn.handleInToken();
         return;
      /*
       * TODO Add additional end-point handling here
       */
   }
}

/**
 * Call-back handling CDC-OUT transaction complete\n
 * Data received is passed to the cdcInterface
 *
 * @param[in] state Current end-point state (always EPDataOut)
 *
 * @return The endpoint state to set after call-back (EPDataOut)
 */
EndpointState Usb0::cdcOutTransactionCallback(EndpointState state) {
   //   console.WRITELN("cdc_out");
   usbdm_assert(state == EPDataOut, "Incorrect endpoint state");
   cdcInterface::putData(epCdcDataOut.getDataTransferredSize(), epCdcDataOut.getBuffer());
   // Set up for next transfer
   epCdcDataOut.startRxStage(EPDataOut, epCdcDataOut.BUFFER_SIZE);
   return EPDataOut;
}

/**
 * Call-back handling CDC-IN transaction complete\n
 * Checks for data and schedules transfer as necessary\n
 * Each transfer will have a ZLP as necessary.
 *
 * @param[in] state Current end-point state (always EPDataIn)
 *
 * @return The endpoint state to set after call-back (EPIdle/EPDataIn)
 */
EndpointState Usb0::cdcInTransactionCallback(EndpointState state) {
   usbdm_assert(state == EPDataIn, "Incorrect endpoint state");
   static uint8_t buffer[20];

   if (state == EPDataIn) {
      int size = cdcInterface::getData(sizeof(buffer), buffer);
      if (size != 0) {
         // Schedules transfer
         epCdcDataIn.setNeedZLP();
         epCdcDataIn.startTxTransaction(EPDataIn, size, buffer);
      }
   }
}

/**
 * Notify IN (device->host) endpoint that data is available
 *
 * @return Not used
 */
bool Usb0::notify() {
   if (epCdcDataIn.getState() == EPIdle) {
      // Restart IN transactions
      cdcInTransactionCallback(EPDataIn);
   }
   return true;
}

/**
 * Call-back handling BULK-OUT transaction complete
 *
 * @param[in] state Current end-point state
 *
 * @return The endpoint state to set after call-back (EPIdle)
 */
EndpointState Usb0::bulkOutTransactionCallback(EndpointState state) {
   (void)state;
   // No actions - End-point is polled
   return EPIdle;
}

/**
 * Call-back handling BULK-IN transaction complete
 *
 * @param[in] state Current end-point state
 *
 * @return The endpoint state to set after call-back (EPIdle)
 */
EndpointState Usb0::bulkInTransactionCallback(EndpointState state) {
   (void)state;
   // No actions - End-point is polled
   return EPIdle;
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();

   // Add extra handling of CDC requests directed to EP0
   setUnhandledSetupCallback(handleUserEp0SetupRequests);

   setSOFCallback(sofCallback);

   cdcInterface::initialise();
   cdcInterface::setUsbInNotifyCallback(notify);
   /*
    * TODO Additional initialisation
    */
}

/**
 *  Blocking reception of data over bulk OUT end-point
 *
 *   @param[in] maxSize  Maximum # of bytes to receive
 *   @param[in] buffer   Pointer to buffer for bytes received
 *
 *   @return Number of bytes received
 *
 *   @note Doesn't return until command has been received.
 */
int Usb0::receiveBulkData(uint8_t maxSize, uint8_t *buffer) {
   epBulkOut.startRxStage(EPDataOut, maxSize, buffer);
   while(epBulkOut.getState() != EPIdle) {
      __enable_irq();
      __WFI();
   }
   setActive();
   return epBulkOut.getDataTransferredSize();
}

/**
 *  Blocking transmission of data over bulk IN end-point
 *
 *  @param[in] size   Number of bytes to send
 *  @param[in] buffer Pointer to bytes to send
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
   epBulkIn.startTxStage(EPDataIn, size, buffer);
}

/**
 * CDC Set line coding handler
 */
void Usb0::handleSetLineCoding() {
//   console.WRITELN("handleSetLineCoding()");

   // Call-back to do after transaction complete
   static auto callback = []() {
      // The controlEndpoint buffer will contain the LineCodingStructure data at call-back time
      cdcInterface::setLineCoding((LineCodingStructure *)fControlEndpoint.getRxBuffer());
      fControlEndpoint.setCallback(nullptr);
      return EPIdle;
   };
   fControlEndpoint.setCallback(callback);

   // Don't use external buffer - this requires response to fit in internal EP buffer
   static_assert(sizeof(LineCodingStructure) < fControlEndpoint.BUFFER_SIZE, "Buffer insufficient size");
   fControlEndpoint.startRxStage(EPDataOut, sizeof(LineCodingStructure));
}

/**
 * CDC Get line coding handler
 */
void Usb0::handleGetLineCoding() {
//   console.WRITELN("handleGetLineCoding()");
   // Send packet
   ep0StartTxStage( sizeof(LineCodingStructure), (const uint8_t*)cdcInterface::getLineCoding());
}

/**
 * CDC Set line state handler
 */
void Usb0::handleSetControlLineState() {
//   console.write("handleSetControlLineState() ").writeln(fEp0SetupBuffer.wValue.lo(), USBDM::Radix_16);
   cdcInterface::setControlLineState(fEp0SetupBuffer.wValue.lo());
   // Tx empty Status packet
   ep0StartTxStage( 0, nullptr );
}

/**
 * CDC Send break handler
 */
void Usb0::handleSendBreak() {
//   console.WRITELN("handleSendBreak()");
   cdcInterface::sendBreak(fEp0SetupBuffer.wValue);
   // Tx empty Status packet
   ep0StartTxStage( 0, nullptr );
}

/**
 * Handle SETUP requests not handled by base handler
 *
 * @param[in] setup SETUP packet received from host
 *
 * @note Provides CDC extensions
 */
ErrorCode Usb0::handleUserEp0SetupRequests(const SetupPacket &setup) {
   //console.WRITE("handleUserEp0SetupRequests(").WRITE(setup.bRequest).WRITELN(")");
   switch(REQ_TYPE(setup.bmRequestType)) {
      case UsbRequestType_CLASS :
         // Class requests
         switch (setup.bRequest) {
            case SET_LINE_CODING :       handleSetLineCoding();       break;
            case GET_LINE_CODING :       handleGetLineCoding();       break;
            case SET_CONTROL_LINE_STATE: handleSetControlLineState(); break;
            case SEND_BREAK:             handleSendBreak();           break;
            default :                    fControlEndpoint.stall();    break;
         }
         break;
      default:
         fControlEndpoint.stall();
         break;
   }
   return E_NO_ERROR;
}

} // End namespace USBDM

