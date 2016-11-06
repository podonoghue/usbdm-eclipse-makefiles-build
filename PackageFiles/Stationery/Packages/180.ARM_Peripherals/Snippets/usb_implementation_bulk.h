/*
 * usb_implementation.h
 *
 *  Created on: 30Oct.,2016
 *      Author: podonoghue
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */

#ifndef PROJECT_HEADERS_USB_IMPLEMENTATION_H_
#define PROJECT_HEADERS_USB_IMPLEMENTATION_H_

#define MS_COMPATIBLE_ID_FEATURE

namespace USBDM {

//======================================================================
// Customise for each USB device
//
#define UNIQUE_ID

#ifndef SERIAL_NO
#ifdef UNIQUE_ID
#define SERIAL_NO "USBDM-MK-%lu"
#else
#define SERIAL_NO "USBDM-MK-0001"
#endif
#endif
#ifndef PRODUCT_DESCRIPTION
#define PRODUCT_DESCRIPTION "USBDM ARM-SWD for MK"
#endif
#ifndef MANUFACTURER
#define MANUFACTURER        "pgo"
#endif

#ifndef VENDOR_ID
#define VENDOR_ID  (0x16D0)
#endif
#ifndef PRODUCT_ID
#define PRODUCT_ID (0x9999)
#endif
#ifndef VERSION_ID
#define VERSION_ID (0x0100)
#endif

//======================================================================
// Maximum packet sizes for each endpoint
//
static constexpr uint  CONTROL_EP_MAXSIZE           = 64; //!< Control in/out    64

static constexpr uint  BULK_OUT_EP_MAXSIZE          = 64; //!< Bulk out          64
static constexpr uint  BULK_IN_EP_MAXSIZE           = 64; //!< Bulk in           64

#ifdef USBDM_USB0_IS_DEFINED
/**
 * Class representing USB0
 */
class Usb0 : public UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE> {
public:

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

      /** Name of Bulk interface */
      s_bulk_interface_index,


      /** Marks last entry */
      s_last_string_descriptor_index
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
   /* end-points */
   static const OutEndpoint <Usb0Info, Usb0::BULK_OUT_ENDPOINT, BULK_OUT_EP_MAXSIZE> epBulkOut;
   static const InEndpoint  <Usb0Info, Usb0::BULK_IN_ENDPOINT,  BULK_IN_EP_MAXSIZE>  epBulkIn;


public:

   /**
    * Initialise the USB interface
    */
   static void initialise();

   /**
    * Initialises all end-points
    */
   static void initialiseEndpoints(void) {
      UsbBase_T::initialiseEndpoints();

      epBulkOut.initialise();
      epBulkIn.initialise();

      epBulkOut.setCallback(bulkOutCallback);
      epBulkIn.setCallback(bulkInCallback);
   }

   /**
    * Handler for USB interrupt
    *
    * Determines source and dispatches to appropriate routine.
    */
   static void irqHandler(void);

   /**
    * Callback for SOF tokens
    */
   static void sofCallback();

   static void bulkOutCallback(EndpointState state);
   static void bulkInCallback(EndpointState state);

   static void sendData( uint8_t size, const uint8_t *buffer);
   static void receiveData(uint8_t maxSize, uint8_t *buffer);

   /**
    * Handler for Token Complete USB interrupts for
    * end-points other than EP0
    */
   static void handleTokenComplete(void);

   /**
    * Device Descriptor
    */
   static const DeviceDescriptor deviceDescriptor;

   /**
    * Other descriptors
    */
   struct Descriptors;

   /**
    * Other descriptors
    */
   static const Descriptors otherDescriptors;
};

using UsbImplementation = Usb0;
#endif // USBDM_USB0_IS_DEFINED

} // End namespace USBDM

#endif /* PROJECT_HEADERS_USB_IMPLEMENTATION_H_ */
