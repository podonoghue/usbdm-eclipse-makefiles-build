/**
 * @file     usb_implementation_cdc.cpp
 * @brief    USB CDC device implementation
 *
 * This module provides an implementation of a USB Composite interface
 * including the following end points:
 *  - EP0 Standard control
 *  - EP1 Interrupt CDC notification
 *  - EP2 CDC data OUT
 *  - EP3 CDC data IN
 *
 * @version  V4.12.1.170
 * @date     2 April 2017
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */
#include <string.h>

#include "usb.h"
#include "usb_implementation_cdc.h"
#include "hardware.h"

namespace USBDM {

/**
 * Interface numbers for USB descriptors
 */
enum InterfaceNumbers {
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
      /* bDeviceClass        */ (uint8_t) 0x02,                           // Device Class code [CDC Device Class]
      /* bDeviceSubClass     */ (uint8_t) 0x00,                           // Sub Class code    [none]
      /* bDeviceProtocol     */ (uint8_t) 0x00,                           // Protocol          [none]
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

/** In end-point for CDC notifications */
InEndpoint  <Usb0Info, Usb0::CDC_NOTIFICATION_ENDPOINT, CDC_NOTIFICATION_EP_MAXSIZE>  Usb0::epCdcNotification(EndPointType_Bulk);

/** Out end-point for CDC data out */
OutEndpoint <Usb0Info, Usb0::CDC_DATA_OUT_ENDPOINT,     CDC_DATA_OUT_EP_MAXSIZE>      Usb0::epCdcDataOut(EndPointType_Interrupt);

/** In end-point for CDC data in */
InEndpoint  <Usb0Info, Usb0::CDC_DATA_IN_ENDPOINT,      CDC_DATA_IN_EP_MAXSIZE>       Usb0::epCdcDataIn(EndPointType_Interrupt);

UartQueue<uint8_t, CDC_DATA_IN_EP_MAXSIZE>  Usb0::inQueue;
UartQueue<uint8_t, CDC_DATA_OUT_EP_MAXSIZE> Usb0::outQueue;

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
   // Notify any changes in CDC status
   epCdcSendNotification();

   return E_NO_ERROR;
}

/**
 * Check for change in CDC status
 * Notify as needed (IN status transaction [Tx, device -> host, DATA0/1])
 */
void Usb0::epCdcSendNotification() {
//   if (fConnectionState != USBconfigured) {
//      // Only send notifications if configured.
//      return;
//   }
   static const CDCNotification cdcNotification = {
         CDC_NOTIFICATION, SERIAL_STATE, 0, RT_INTERFACE, nativeToLe16(2)
   };
   static uint8_t lastStatus = -1;

   // Line state (dummy value sent once)
   static constexpr CdcLineState lineState { uint8_t(
      USB_CDC_STATE_DCD_MASK        |
      USB_CDC_STATE_DSR_MASK        |
//      USB_CDC_STATE_BREAK_IN_MASK   |
//      USB_CDC_STATE_RI_MASK         |
//      USB_CDC_STATE_FRAME_MASK      |
//      USB_CDC_STATE_PARITY_MASK     |
//      USB_CDC_STATE_OVERRUN_MASK    |
      USB_CDC_STATE_CHANGE_MASK
   )};
   uint8_t status = lineState.bits;

   if (status == lastStatus) {
      // No change
      return;
   }
   if (epCdcNotification.getState() != EPIdle) {
      // Busy with previous
      return;
   }
   static_assert(epCdcNotification.BUFFER_SIZE>=sizeof(CDCNotification), "Buffer size insufficient");

   lastStatus = status;

   // Copy the data to Tx buffer
   Endpoint::safeCopy(epCdcNotification.getTxBuffer(), &cdcNotification, sizeof(cdcNotification));
   epCdcNotification.getTxBuffer()[sizeof(cdcNotification)+0] = status;
   epCdcNotification.getTxBuffer()[sizeof(cdcNotification)+1] = 0;

   // Set up to Tx packet
   epCdcNotification.startTxTransfer(EPDataIn, sizeof(cdcNotification)+2);
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
      case CDC_NOTIFICATION_ENDPOINT: // Accept IN token
         // CDC Notification has been ACKed
//         console.WRITELN("CDC_NOTIFICATION_ENDPOINT");
         setActive();
         epCdcNotification.handleInToken();
         return;
      case CDC_DATA_OUT_ENDPOINT: // Accept OUT token
//         console.WRITELN("CDC_DATA_OUT_ENDPOINT");
         setActive();
         epCdcDataOut.handleOutToken();
         return;
      case CDC_DATA_IN_ENDPOINT:  // Accept IN token
//         console.WRITELN("CDC_DATA_IN_ENDPOINT");
         // Data has been ACKed
         setActive();
         epCdcDataIn.handleInToken();
         return;
      /*
       * TODO Add additional end-point handling here
       */
   }
}

//_______ CDC Call-backs ________________________________________________________________

/**
 * Call-back handling CDC-OUT transaction complete\n
 *
 * @param[in] state Current end-point state (always EPDataOut)
 *
 * @return The endpoint state to set after call-back (EPIdle/EPDataOut/EPComplete)
 */
EndpointState Usb0::cdcOutTransactionCallback(EndpointState state) {
   (void)state;
   auto numBytes = epCdcDataOut.getDataTransferredSize();
   const uint8_t *data = epCdcDataOut.getRxBuffer();
   for(int count=0; count<numBytes; count++) {
      outQueue.enQueueDiscardOnFull(data[count]);
   }
   return EPIdle;
}

/**
 * Call-back handling CDC-IN transaction complete\n
 *
 * @param[in] state Current end-point state (always EPDataIn)
 *
 * @return The endpoint state to set after call-back (EPIdle/EPDataIn/EPComplete)
 */
EndpointState Usb0::cdcInTransactionCallback(EndpointState state) {
   (void)state;
   return EPIdle;
}

/**
 * Initialise the USB0 interface
 *
 *  @note Assumes clock set up for USB operation (48MHz)
 */
void Usb0::initialise() {
   UsbBase_T::initialise();

   inQueue.clear();
   outQueue.clear();

   UsbLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   // Add extra handling of CDC requests directed to EP0
   setUnhandledSetupCallback(handleUserEp0SetupRequests);

   // Set SOF handler
   setSOFCallback(sofCallback);

   /*
    * TODO Additional initialisation
    */
}

//_______ CDC ________________________________________________________________

LineCodingStructure Usb0::lineCoding = {};

/**
 * CDC Set line coding handler
 */
void Usb0::handleSetLineCoding() {
   console.WRITELN("handleSetLineCoding()");

   // Call-back to do after transaction complete
   static auto callback = [](EndpointState) {
      // The controlEndpoint buffer will contain the LineCodingStructure data at call-back time
      // TODO Add handling here
      memcpy(&lineCoding, fControlEndpoint.getRxBuffer(), sizeof(LineCodingStructure));
      fControlEndpoint.setCallback(nullptr);
      return EPIdle;
   };
   fControlEndpoint.setCallback(callback);

   fControlEndpoint.startRxTransfer(EPDataOut, sizeof(LineCodingStructure), (uint8_t *)&lineCoding);
}

/**
 * CDC Get line coding handler
 */
void Usb0::handleGetLineCoding() {
   console.WRITELN("handleGetLineCoding()");
   // Send packet
   ep0StartTxStage(sizeof(LineCodingStructure), (const uint8_t*)&lineCoding);
}

/**
 * CDC Set line state handler
 */
void Usb0::handleSetControlLineState() {

   // TODO Add handling here
   // fEp0SetupBuffer.wValue.lo() will contain line state
   console.write("handleSetControlLineState() ").writeln(fEp0SetupBuffer.wValue.lo(), USBDM::Radix_16);

   // Tx empty Status packet
   ep0StartTxStage( 0, nullptr );
}

/**
 * CDC Send break handler
 */
void Usb0::handleSendBreak() {
   console.WRITELN("handleSendBreak()");
   // TODO Handle setting break
   // fEp0SetupBuffer.wValue will contain break details

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

//_______ Transmission ________________________________________________________________

/**
 * Start CDC IN transaction\n
 * A packet is only sent if data is available
 */
void Usb0::startCdcIn() {
//   if ((epCdcDataIn.getState() == EPIdle) && (cdcOutByteCount>0)) {
//      static_assert(epCdcDataIn.BUFFER_SIZE>sizeof(cdcOutBuff), "Buffer too small");
//      Endpoint::safeCopy(epCdcDataIn.getBuffer(), cdcOutBuff, cdcOutByteCount);
//      //TODO Check if need ZLP
//      epCdcDataIn.setNeedZLP();
//      epCdcDataIn.startTxStage(EPDataIn, cdcOutByteCount);
//      cdcOutByteCount = 0;
   }

/**
 * Send any pending data now.
 * If there is no data then an empty transfer (ZLP) occurs
 *
 * @return E_BUSY     Busy with last transfer
 * @return E_NO_ERROR New transfer configured
 */
ErrorCode Usb0::sendNow() {

   if (epCdcDataIn.getState() != EPIdle) {
      return E_BUSY;
   }
   uint8_t *buffer = epCdcDataIn.getTxBuffer();
   unsigned maxBuffer = epCdcDataIn.getMaximumTransferSize();
   unsigned count;
   for(count=0; count<maxBuffer; count++) {
      if (inQueue.isEmpty()) {
         break;
      }
      buffer[count] = inQueue.deQueue();
   }
   epCdcDataIn.startTxTransfer(EPDataIn, count, nullptr);
   return E_NO_ERROR;
}

/**
 * CDC Transmit (blocking)
 *
 * @param[in] data Pointer to data to transmit
 * @param[in] size Number of bytes to transmit
 */
ErrorCode Usb0::sendCdcData(const uint8_t *data, unsigned size) {

   for(unsigned index=0; index<size; index++) {
      bool ok;
      do {
         ok = inQueue.enQueueDiscardOnFull(data[index]);
         if (!ok && (epCdcDataIn.getState() == EPIdle)) {
            // Flush on queue full
            sendNow();
         }
      } while (!ok);
   }
   return E_NO_ERROR;
}

//_______ Reception ________________________________________________________________

/**
 * CDC Receive
 *
 * @param[in] data    Pointer to data to receive
 * @param[in] maxSize Maximum number of bytes to receive
 *
 * @return Number of bytes received
 */
int Usb0::receiveCdcData(uint8_t *data, unsigned maxSize) {
   unsigned count = 0;
   while (!outQueue.isEmpty()) {
      if (count>maxSize) {
         break;
      }
      data[count++] = outQueue.deQueue();
   }
   if (outQueue.isEmpty() && (epCdcDataOut.getState() == EPIdle)) {
      // Start new out transfer using internal buffer
      epCdcDataOut.startRxTransfer(EPDataOut, epCdcDataOut.getMaximumTransferSize(), nullptr);
      __asm__("nop");
   }
   return count;
}


} // End namespace USBDM

