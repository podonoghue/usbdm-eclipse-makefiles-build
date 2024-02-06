/**
 * @file     usb_implementation_composite.h
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
#ifndef PROJECT_HEADERS_USB_IMPLEMENTATION_COMPOSITE_H_
#define PROJECT_HEADERS_USB_IMPLEMENTATION_COMPOSITE_H_

#include <stdint.h>

/*
 * Under Windows 8, or 10 there is no need to install a driver for
 * the bulk endpoints if the MS_COMPATIBLE_ID_FEATURE is enabled.
 * winusb.sys driver will be automatically loaded.
 *
 * Under Windows 10 the usbser.sys driver will be loaded automatically
 * for the CDC (serial) interface
 *
 * Under Linux drivers for bulk and CDC are automatically loaded
 */

//#define MS_COMPATIBLE_ID_FEATURE // Incompatible with CDC
#include "usb_cdc_interface.h"
//#include "configure.h"

namespace USBDM {

//======================================================================
// Customise for each USB device
//

/** Causes a semi-unique serial number to be generated for each USB device */
#define UNIQUE_ID

#ifdef UNIQUE_ID
#define SERIAL_NO           "USBDM-"
#else
#define SERIAL_NO           "USBDM-0001"
#endif
#define PRODUCT_DESCRIPTION "USB-Test"
#define MANUFACTURER        "pgo"

static constexpr uint16_t  VENDOR_ID   = 0x16D0;    // Vendor ID (actually MCS)
static constexpr uint16_t  PRODUCT_ID  = 0x4999;    // Product ID
static constexpr uint16_t  VERSION_ID  = 0x0100;    // Version ID

//======================================================================
// Maximum packet sizes for each endpoint
//
static constexpr unsigned  CONTROL_EP_MAXSIZE           = 64; //!< Control in/out
/*
 *  TODO Define additional endpoint sizes
 */
static constexpr unsigned  BULK_OUT_EP_MAXSIZE          = 64; //!< Bulk out
static constexpr unsigned  BULK_IN_EP_MAXSIZE           = 64; //!< Bulk in

static constexpr unsigned  CDC_NOTIFICATION_EP_MAXSIZE  = 16; //!< CDC notification
static constexpr unsigned  CDC_DATA_OUT_EP_MAXSIZE      = 16; //!< CDC data out
static constexpr unsigned  CDC_DATA_IN_EP_MAXSIZE       = 16; //!< CDC data in

/**
 * Class representing USB0
 */
class Usb0 : private UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE> {

   // Allow superclass to access handleTokenComplete(void);
   friend UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>;

   static LineCodingStructure lineCoding;
   static UartQueue<uint8_t, CDC_DATA_IN_EP_MAXSIZE>  inQueue;
   static UartQueue<uint8_t, CDC_DATA_OUT_EP_MAXSIZE> outQueue;

public:
   using UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>::getUserEventName;
   using UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>::isConfigured;
   using UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>::UserEvent;
   using UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>::irqHandler;
   using UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>::setUserCallback;

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
      /** Configuration Index */
      s_config_index,

      /** Name of Bulk interface */
      s_bulk_interface_index,

      /** Name of CDC interface */
      s_cdc_interface_index,
      /** CDC Control Interface */
      s_cdc_control_interface_index,
      /** CDC Data Interface */
      s_cdc_data_Interface_index,
      /*
       * TODO Add additional String indexes
       */

      /** Marks last entry */
      s_number_of_string_descriptors
   };

   /**
    * Endpoint numbers\n
    * Must be consecutive
    */
   enum EndpointNumbers {
      /** USB Control endpoint number - must be zero */
      CONTROL_ENDPOINT  = 0,

      /* endpoints are assumed consecutive */

      /** Bulk out endpoint number */
      BULK_OUT_ENDPOINT,
      /** Bulk in endpoint number */
      BULK_IN_ENDPOINT,

      /** CDC Control endpoint number */
      CDC_NOTIFICATION_ENDPOINT,
      /** CDC Data out endpoint number */
      CDC_DATA_OUT_ENDPOINT,
      /** CDC Data in endpoint number */
      CDC_DATA_IN_ENDPOINT,

      /*
       * TODO Add additional Endpoint numbers here
       */
      /** Total number of endpoints */
      NUMBER_OF_ENDPOINTS,
   };

   /**
    * Configuration numbers, consecutive from 1
    */
   enum Configurations {
      CONFIGURATION_NUM = 1,
      /*
       * Assumes single configuration
       */
      /** Total number of configurations */
      NUMBER_OF_CONFIGURATIONS = CONFIGURATION_NUM,
   };

   /**
    * String descriptor table
    */
   static const uint8_t *const stringDescriptors[];

protected:
   /* Additional endpoints */

   /** Out endpoint for Bulk */
   static OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT, BULK_OUT_EP_MAXSIZE> epBulkOut;

   /** In endpoint for Bulk */
   static InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,  BULK_IN_EP_MAXSIZE>  epBulkIn;

   /** In endpoint for CDC notifications */
   static InEndpoint  <Usb0Info, Usb0::CDC_NOTIFICATION_ENDPOINT, CDC_NOTIFICATION_EP_MAXSIZE>  epCdcNotification;

   /** Out endpoint for CDC data out */
   static OutEndpoint <Usb0Info, Usb0::CDC_DATA_OUT_ENDPOINT,     CDC_DATA_OUT_EP_MAXSIZE>      epCdcDataOut;

   /** In endpoint for CDC data in */
   static InEndpoint  <Usb0Info, Usb0::CDC_DATA_IN_ENDPOINT,      CDC_DATA_IN_EP_MAXSIZE>       epCdcDataIn;

   /*
    * TODO Add additional End-points here
    */

   using cdcInterface = USBDM::CDC_Interface;

public:

   /**
    * Initialise the USB0 interface
    *
    *  @note Assumes clock set up for USB operation (48MHz)
    */
   static void initialise();

   //_______ Bulk Transmission ________________________________________________________________

   /**
    *  Non-blocking transmission of data over bulk IN endpoint
    *
    *  @param size         Number of bytes to send
    *  @param buffer       Pointer to bytes to send
    *
    *  @return E_WRONG_STATE  In wrong state e.g. Busy or Stalled
    *  @return E_NO_ERROR     Transmission successfully commenced
    */
   static ErrorCode startSendBulkData(uint16_t size, const uint8_t *buffer);

   /**
    *  Check if transmission completed
    *
    *  @return E_BUSY      Busy with last transmission - retry
    *  @return E_NO_ERROR  Transmission successfully completed
    */
   static ErrorCode pollSendBulkData();

   /**
    *  Blocking transmission of data over bulk IN endpoint
    *
    *  @param size            Number of bytes to send
    *  @param buffer          Pointer to bytes to send
    *  @param timeoutMS       Timeout in milliseconds (may be zero to suppress)
    *
    *  @return E_NO_ERROR     Transmission successfully completed
    *  @return E_TIMEOUT      Transmission not completed within timeout (transmission is aborted)
    *  @return E_WRONG_STATE  In wrong state e.g. Busy or Stalled (transmission is aborted)
    */
   static ErrorCode sendBulkData(uint16_t size, const uint8_t *buffer, int timeoutMS);


   //_______ Bulk Reception ________________________________________________________________

   /**
    *  Non-blocking reception of data over bulk OUT endpoint
    *
    *   @param size           Maximum number of bytes to receive
    *   @param buffer         Pointer to buffer for bytes received
    *
    *   @return E_NO_ERROR    Transmission started
    *   @return E_WRONG_STATE In unexpected state e.g. Busy or Stalled
    */
   static ErrorCode startReceiveBulkData(uint16_t size, uint8_t *buffer);

   /**
    *  Check for completion of reception of data over bulk OUT endpoint.
    *  Reception will have been previously configured by startReceiveBulkData().
    *
    *   @param  size          Number of bytes received
    *
    *   @return E_BUSY        Reception not complete. (size == 0)
    *   @return E_NO_ERROR    Reception complete. Buffer has data.
    *   @return E_WRONG_STATE In unexpected state e.g. Idle or Stalled
    */
   static ErrorCode pollReceiveBulkData(uint16_t &size);

   /**
    *  Blocking reception of data over bulk OUT endpoint
    *
    *  @param size           Maximum number of bytes to receive/Number of bytes received
    *  @param buffer         Pointer to buffer for bytes received
    *  @param timeoutMS      Timeout in milliseconds (may be zero to suppress)
    *
    *  @return E_NO_ERROR    Reception completed
    *  @return E_TIMEOUT     Reception not completed within timeout (reception is aborted)
    *  @return E_WRONG_STATE In unexpected state e.g. Busy or Stalled (reception is aborted)
    */
   static ErrorCode receiveBulkData(uint16_t &size, uint8_t *buffer, int timeoutMS);

   //_______ CDC Transmission ________________________________________________________________

   /**
    * CDC Transmit
    *
    * @param[in] data Pointer to data to transmit
    * @param[in] size Number of bytes to transmit
    */
   static void sendCdcData(const uint8_t *data, unsigned size);

   //_______ Reception ________________________________________________________________

   /**
    * CDC Receive
    *
    * @param[in] data    Pointer to data to receive
    * @param[in] maxSize Maximum number of bytes to receive
    *
    * @return Number of bytes received
    */
   static int receiveCdcData(uint8_t *data, unsigned maxSize);

   /**
    * Notify IN (device->host) endpoint that data is available
    *
    * @return Not used
    */
   static bool notify();

   /**
    * Device Descriptor
    */
   static const DeviceDescriptor deviceDescriptor;

   /**
    * Other descriptors type
    */
   struct Descriptors {
      ConfigurationDescriptor                  configDescriptor;

      InterfaceDescriptor                      bulk_interface;
      EndpointDescriptor                       bulk_out_endpoint;
      EndpointDescriptor                       bulk_in_endpoint;

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
      /*
       * TODO Add additional Descriptors here
       */
   };

   /**
    * All other descriptors
    */
   static const Descriptors otherDescriptors;

protected:
   /**
    * Clear value reflecting selected hardware based ping-pong buffer.
    * This would normally only be called when resetting the USB hardware or using
    * USBx_CTL_ODDRST.
    */
   static void clearPinPongToggle() {
      epBulkOut.clearPinPongToggle();
      epBulkIn.clearPinPongToggle();
      epCdcNotification.clearPinPongToggle();
      epCdcDataOut.clearPinPongToggle();
      epCdcDataIn.clearPinPongToggle();
   }

   /**
    * Initialises all endpoints
    */
   static void initialiseEndpoints(bool clearToggles) {
      epBulkOut.initialise(clearToggles);
      addEndpoint(&epBulkOut);
      epBulkOut.setCallback(bulkOutTransactionCallback);

      epBulkIn.initialise(clearToggles);
      addEndpoint(&epBulkIn);
      epBulkIn.setCallback(bulkInTransactionCallback);

      epCdcNotification.initialise(clearToggles);
      addEndpoint(&epCdcNotification);

      epCdcDataOut.initialise(clearToggles);
      addEndpoint(&epCdcDataOut);
      epCdcDataOut.setCallback(cdcOutTransactionCallback);

      // Make sure epCdcDataOut is ready for polling (interrupt OUT)
      epCdcDataOut.startRxTransfer(EPDataOut, epCdcDataOut.getMaximumTransferSize());

      epCdcDataIn.initialise(clearToggles);
      addEndpoint(&epCdcDataIn);
      epCdcDataIn.setCallback(cdcInTransactionCallback);

      // Start CDC status transmission
      epCdcSendNotification();

      // Connect notify callback
      cdcInterface::setUsbInNotifyCallback(notify);
      /*
       * TODO Initialise additional End-points here
       */
   }

   /**
    * Handler for Start of Frame Token interrupt (~1ms interval)
    *
    * @param frameNumber Frame number from SOF token
    *
    * @return  E_NO_ERROR on success
    */
   static ErrorCode sofCallback(uint16_t frameNumber);

   /**
    * Call-back handling BULK-OUT transaction complete
    *
    * @param[in] state Current endpoint state (always EPDataOut)
    *
    * @return The endpoint state to set after call-back (EPDataOut)
    */
   static EndpointState bulkOutTransactionCallback(EndpointState state);

   /**
    * Call-back handling BULK-IN transaction complete
    *
    * @param[in] state Current endpoint state (always EPDataIn)
    *
    * @return The endpoint state to set after call-back (EPIdle/EPDataIn)
    */
   static EndpointState bulkInTransactionCallback(EndpointState state);

   /**
    * Call-back handling CDC-IN transaction complete\n
    * Checks for data and schedules transfer as necessary\n
    * Each transfer will have a ZLP as necessary.
    *
    * @param[in] state Current endpoint state (always EPDataIn)
    *
    * @return The endpoint state to set after call-back (EPIdle/EPDataIn)
    */
   static EndpointState cdcInTransactionCallback(EndpointState state);

   /**
    * Call-back handling CDC-OUT transaction complete\n
    * Data received is passed to the cdcInterface
    *
    * @param[in] state Current endpoint state (always EPDataOut)
    *
    * @return The endpoint state to set after call-back (EPDataOut)
    */
   static EndpointState cdcOutTransactionCallback(EndpointState state);

   /**
    * Handler for Token Complete USB interrupts for
    * endpoints other than EP0
    *
    * @param usbStat USB Status value from USB hardware
    */
   static void handleTokenComplete(UsbStat usbStat);

   /**
    * Start CDC IN transaction\n
    * A packet is only sent if data is available
    */
   static void startCdcIn();

   /**
    * Configure epCdcNotification for an IN transaction [Tx, device -> host, DATA0/1]
    */
   static void epCdcSendNotification();

   /**
    * Handle SETUP requests not handled by base handler
    *
    * @param[in] setup SETUP packet received from host
    *
    * @note Provides CDC extensions
    */
   static ErrorCode handleUserEp0SetupRequests(const SetupPacket &setup);

   /**
    * CDC Set line coding handler
    */
   static void handleSetLineCoding();

   /**
    * CDC Get line coding handler
    */
   static void handleGetLineCoding();

   /**
    * CDC Set line state handler
    */
   static void handleSetControlLineState();

   /**
    * CDC Send break handler
    */
   static void handleSendBreak();

};

using UsbImplementation = Usb0;

} // End namespace USBDM

#endif /* PROJECT_HEADERS_USB_IMPLEMENTATION_COMPOSITE_H_ */
