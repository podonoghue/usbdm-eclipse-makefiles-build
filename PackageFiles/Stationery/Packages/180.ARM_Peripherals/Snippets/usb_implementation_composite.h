/*
 * usb_implementation.h
 *
 *  Created on: 30Oct.,2016
 *      Author: podonoghue
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */

#ifndef SOURCES_USB_IMPLEMENTATION_H_
#define SOURCES_USB_IMPLEMENTATION_H_

#include "usb.h"

namespace USBDM {

//======================================================================
// Maximum packet sizes for each endpoint
//
static constexpr uint  CONTROL_EP_MAXSIZE      = 64; //!< Control in/out                64
/*
 *  TODO Define end-point sizes
 */
#ifdef USBDM_USB0_IS_DEFINED
/**
 * Class representing USB0
 */
class Usb0 : public UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE> {
public:

   /**
    * Endpoint numbers\n
    * Must be consecutive
    */
   enum EndpointNumbers {
      /** USB Control endpoint number - must be zero */
      CONTROL_ENDPOINT  = 0,

      /** BDM Control and Data out endpoint number */
      BDM_OUT_ENDPOINT,
      /** BDM Data in endpoint number */
      BDM_IN_ENDPOINT,

      /*
       * TODO Add additional Endpoint numbers here
       */
      /** Total number of end-points */
      NUMBER_OF_ENDPOINTS,
   };

   /**
    * Endpoint numbers\n
    * Must be consecutive
    */
   enum Configurations {
     CONFIGURATION_NUM = 1,
     /*
      * Assumes single configuration
      */
   };

   /**
    * String descriptor table
    */
   static const uint8_t *const stringDescriptors[];

protected:
   /*
    * TODO Add additional End-points here
    */

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
      /*
       * TODO Initialise additional End-points here
       */
   }

   /**
    * Handler for USB interrupt
    *
    * Determines source and dispatches to appropriate routine.
    */
   static void irqHandler(void);

   /**
    * Handler for Token Complete USB interrupt
    *
    * Handles ep0 [SETUP, IN & OUT] - passed to UsbBase_T::handleTokenCompleteEp0
    * Other end-points as needed
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

#endif /* SOURCES_USB_IMPLEMENTATION_H_ */
