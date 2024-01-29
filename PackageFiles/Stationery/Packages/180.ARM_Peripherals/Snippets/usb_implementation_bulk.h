/**
 * @file     usb_implementation_bulk.h
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
#ifndef PROJECT_HEADERS_USB_IMPLEMENTATION_BULK_H_
#define PROJECT_HEADERS_USB_IMPLEMENTATION_BULK_H_

#include <stdint.h>

/*
 * Under Windows 8, or 10 there is no need to install a driver for
 * the bulk end-points if the MS_COMPATIBLE_ID_FEATURE is enabled.
 * winusb.sys driver will be automatically loaded.
 *
 * Under Windows 10 the usbser.sys driver will be loaded automatically
 * for the CDC (serial) interface
 *
 * Under Linux drivers for bulk and CDC are automatically loaded
 */

//#define MS_COMPATIBLE_ID_FEATURE

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
 *  TODO Define additional end-point sizes
 */
static constexpr unsigned  BULK_OUT_EP_MAXSIZE          = 64; //!< Bulk out
static constexpr unsigned  BULK_IN_EP_MAXSIZE           = 64; //!< Bulk in

/**
 * Class representing USB0
 */
class Usb0 : private UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE> {

   // Allow superclass to access handleTokenComplete(void);
   friend UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>;

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

      /* end-points are assumed consecutive */

      /** Bulk out endpoint number */
      BULK_OUT_ENDPOINT,
      /** Bulk in endpoint number */
      BULK_IN_ENDPOINT,

      /*
       * TODO Add additional Endpoint numbers here
       */
      /** Total number of end-points */
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
   /* Additional end-points */

   /** Out end-point for Bulk */
   static OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT, BULK_OUT_EP_MAXSIZE> epBulkOut;

   /** In end-point for Bulk */
   static InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,  BULK_IN_EP_MAXSIZE>  epBulkIn;

   /*
    * TODO Add additional End-points here
    */

public:

   /**
    * Initialise the USB0 interface
    *
    *  @note Assumes clock set up for USB operation (48MHz)
    */
   static void initialise();

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
   static ErrorCode startSendBulkData(uint16_t size, const uint8_t *buffer);

   /**
    *  Check if transmission completed
    *
    *  @return E_BUSY      Busy with last transmission - retry
    *  @return E_NO_ERROR  Transmission successfully completed
    */
   static ErrorCode pollSendBulkData();

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
   static ErrorCode sendBulkData(uint16_t size, const uint8_t *buffer, int timeoutMS);


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
   static ErrorCode startReceiveBulkData(uint16_t size, uint8_t *buffer);

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
   static ErrorCode pollReceiveBulkData(uint16_t &size);

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
   static ErrorCode receiveBulkData(uint16_t &size, uint8_t *buffer, int timeoutMS);

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
   }

   /**
    * Initialises all end-points
    */
   static void initialiseEndpoints(bool clearToggle) {
      epBulkOut.initialise(clearToggle);
      addEndpoint(&epBulkOut);
      epBulkOut.setCallback(bulkOutTransactionCallback);

      epBulkIn.initialise(clearToggle);
      addEndpoint(&epBulkIn);
      epBulkIn.setCallback(bulkInTransactionCallback);

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
    * @param[in] state Current end-point state (always EPDataOut)
    *
    * @return The endpoint state to set after call-back (EPIdle/EPDataOut)
    */
   static EndpointState bulkOutTransactionCallback(EndpointState state);

   /**
    * Call-back handling BULK-IN transaction complete
    *
    * @param[in] state Current end-point state (always EPDataIn)
    *
    * @return The endpoint state to set after call-back (EPIdle/EPDataIn)
    */
   static EndpointState bulkInTransactionCallback(EndpointState state);

   /**
    * Handler for Token Complete USB interrupts for
    * end-points other than EP0
    *
    * @param usbStat USB Status value from USB hardware
    */
   static void handleTokenComplete(UsbStat usbStat);

};

using UsbImplementation = Usb0;

} // End namespace USBDM

#endif /* PROJECT_HEADERS_USB_IMPLEMENTATION_BULK_H_ */
