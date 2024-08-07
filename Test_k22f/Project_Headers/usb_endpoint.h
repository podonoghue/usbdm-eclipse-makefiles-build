/**
 * @file     usb_endpoint.h (180.ARM_Peripherals/Project_Headers/usb_endpoint.h)
 * @brief    Universal Serial Bus Endpoint
 *
 * @version  V4.12.1.210
 * @date     13 April 2016
 *      Author: podonoghue
 */

#ifndef HEADER_USB_ENDPOINT_H
#define HEADER_USB_ENDPOINT_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "usb_defs.h"
#include "derivative.h"
#include "error.h"
#include "cstring"
#include "console.h"

namespace USBDM {

/**
 * @addtogroup USB_Group USB, USB OTG Controller
 * @brief Abstraction for USB OTG Controller
 * @{
 */

/** BDTs organised by endpoint, odd/even, transmit/receive */
extern volatile EndpointBdtEntry endPointBdts[];

/** BDTs as simple array */
static BdtEntry *bdts() { return (BdtEntry *)endPointBdts; }

/** Endpoint state values */
enum EndpointState {
   EPIdle = 0,  //!< Idle
   EPDataIn,    //!< Doing a sequence of IN transactions
   EPDataOut,   //!< Doing a sequence of OUT transactions
   EPStatusIn,  //!< Doing an IN transaction as a status handshake
   EPStatusOut, //!< Doing an OUT transaction as a status handshake
   EPStall,     //!< Endpoint is stalled
   EPComplete,  //!< Used for command protocol - new command available
};

enum EndPointType {
   EndPointType_Control,
   EndPointType_Bulk,
   EndPointType_Interrupt,
};

/**
 * Class for generic endpoint
 */
class Endpoint {

protected:
   /// Endpoint type
   const EndPointType fEndPointType;

   /// Value used to initialise an Endpoint Control Register
   const uint8_t fEpControlValue;

   /// Associated BDTs (2*Tx, 2*Rx)
   volatile EndpointBdtEntry &fBdt;

public:
   /**
    * Get name of endpoint state
    *
    * @param[in]  state Endpoint state
    *
    * @return Pointer to static string
    */
   static const char *getStateName(EndpointState state) {
      static const char *names[] = {
         "EPIdle",
         "EPDataIn",
         "EPDataOut,",
         "EPStatusIn",
         "EPStatusOut",
         "EPStall",
         "EPComplete",
      };
      const char *rc = "Unknown";
      if (state<(sizeof(names)/sizeof(names[0]))) {
         rc = names[state];
      }
      return rc;
   }

   /**
    * Get name of endpoint state
    *
    * @return Pointer to static string
    */
   const char *getStateName() {
      return getStateName(fState);
   }

   /**
    * Simple copy routine for volatile buffer
    *
    * @param to      Where to copy to
    * @param from    Where to copy from
    * @param size    Number of bytes to copy
    */
   static void safeCopy(volatile void *to, volatile const void *from, unsigned size) {
      volatile uint8_t       *_to   = reinterpret_cast<volatile uint8_t *>(to);
      volatile const uint8_t *_from = reinterpret_cast<volatile const uint8_t *>(from);
      while(size-->0) {
         *_to++ = *_from++;
      }
   }

protected:
   /** Data 0/1 flag */
   volatile DataToggle fDataToggle = DataToggle_0;

   /** Odd/Even Transmit buffer flag */
   volatile BufferToggle fTxOdd = BufferToggle_Even;

   /** Odd/Even Receive buffer flag */
   volatile BufferToggle fRxOdd = BufferToggle_Even;

   /** End-point state */
   volatile EndpointState fState = EPIdle;

   /**
    *  Indicates that the IN transaction needs to be
    *  terminated with ZLP if size is a multiple of fEndpointSize
    */
   volatile bool fNeedZLP = false;

   /** Pointer to external data buffer for transmit/receive */
   volatile uint8_t* fDataPtr = nullptr;

   /** Count of remaining bytes in external data buffer to transmit/receive */
   volatile uint16_t fDataRemaining = 0;

   /** Count of data bytes transferred to/from data buffer */
   volatile uint16_t fDataTransferred = 0;

   /**
    *  Callback used on completion of data and handshake phases of transaction.
    *  For a control endpoint this routine is called:\n
    *  - After an IN transaction with endpointState = EPStatusIn.\n
    *  - After an OUT transaction with endpointState = EPStatusOut.
    *
    *  For other types of endpoint this routine is called:\n
    *  - After an IN transaction with endpointState = EPDataIn.\n
    *  - After an OUT transaction with endpointState = EPDataOut.
    *
    * @param[in] endpointState State of endpoint before completion of transaction
    *
    * @return The endpoint state to set after call-back
    */
   EndpointState (*fCallback)(EndpointState endpointState) = unsetHandlerCallback;

   /**
    *  Dummy callback used to catch use of unset callback
    *
    * @param[in]  endpointState State of endpoint before completion
    *
    * @return The endpoint state to set after call-back (EPIdle)
    */
   static EndpointState unsetHandlerCallback(EndpointState endpointState) {
      (void)endpointState;
//      setAndCheckErrorCode(E_NO_HANDLER);
      return EPIdle;
   }

   /** Hardware instance pointer */
   HardwarePtr<USB_Type>fUsb;

   /** Buffer Transmit data */
   volatile uint8_t * const fTxDataBuffer;

   /** Buffer Receive data */
   volatile uint8_t * const fRxDataBuffer;

   /**
    * Constructor
    *
    * @param[in]  endpointNumber End-point number
    * @param[in]  endpointSize   Size of endpoint buffer
    * @param[in]  endPointType   Endpoint type (Control, Bulk, Interrupt)
    * @param[in]  dataBuffer     Endpoint buffer
    * @param[in]  usb            Reference to USB hardware
    */
   constexpr Endpoint(
         int               endpointNumber,
         unsigned          endpointSize,
         EndPointType      endPointType,
         uint8_t           bdtValue,
         uint8_t           txDataBuffer[],
         uint8_t           rxDataBuffer[],
         uint32_t          usb) :
            fEndPointType(endPointType),
            fEpControlValue(bdtValue),
            fBdt(endPointBdts[endpointNumber]),
            fUsb(usb),
            fTxDataBuffer(txDataBuffer),
            fRxDataBuffer(rxDataBuffer),
            fEndpointNumber(endpointNumber),
            fEndpointSize(endpointSize) {
   }

   virtual ~Endpoint() {}

public:

   /** End point number */
   const uint16_t fEndpointNumber;

   /**  Size of endpoint (size of maximum transfer)  */
   const uint16_t fEndpointSize;

   /**
    * Clear value reflecting selected hardware based ping-pong buffer.
    * This would normally only be called when resetting the USB hardware or using
    * USBx_CTL_ODDRST.
    */
   void clearPinPongToggle() {
      fTxOdd            = BufferToggle_Even;
      fRxOdd            = BufferToggle_Even;
   }

   /**
    * Initialise endpoint
    *  - Internal state
    *  - BDTs
    */
   void initialise() {
      fDataToggle       = DataToggle_0;
      fState            = EPIdle;
      fNeedZLP          = false;
      fDataPtr          = nullptr;
      fDataRemaining    = 0;
      fDataTransferred  = 0;
      fCallback         = unsetHandlerCallback;

      // Value used to initialise an Endpoint Control Register
      fUsb->ENDPOINT[fEndpointNumber].ENDPT = fEpControlValue;

      // Assumes single shared buffer
      fBdt.rxEven.initialise( 0, 0, nativeToLe32((uint32_t)fRxDataBuffer));
      fBdt.rxOdd.initialise(  0, 0, nativeToLe32((uint32_t)fRxDataBuffer));
      fBdt.txEven.initialise( 0, 0, nativeToLe32((uint32_t)fTxDataBuffer));
      fBdt.txOdd.initialise(  0, 0, nativeToLe32((uint32_t)fTxDataBuffer));
   }

   /**
    * Set endpoint state
    *
    * @param[in] state
    */
   void setState(EndpointState state) {
      fState = state;
   }

   /**
    * Return end-point state
    *
    * @return Endpoint state
    */
   EndpointState getState() {
      return fState;
   }

   /**
    * Stall endpoint
    */
   void stall() {
//      console.WRITELN("EpX.stall");
      fUsb->ENDPOINT[fEndpointNumber].ENDPT = fEpControlValue|USB_ENDPT_EPSTALL_MASK;
//      fBdt.txEven.setControl(BDTEntry_OWN_MASK|BDTEntry_STALL_MASK|BDTEntry_DTS_MASK);
//      fBdt.txOdd.setControl(BDTEntry_OWN_MASK|BDTEntry_STALL_MASK|BDTEntry_DTS_MASK);
      setState(EPStall);
   }

   /**
    * Set Data toggle
    *
    * @param[in] dataToggle
    */
   void setDataToggle(DataToggle dataToggle) {
      fDataToggle = dataToggle;
   }

   /**
    * Clear Stall on endpoint
    */
   void clearStall() {
//      console.WRITELN("EpX.clearStall");
      fUsb->ENDPOINT[fEndpointNumber].ENDPT = fEpControlValue;
//      fBdt.txEven.setControl(BDTEntry_DTS_MASK);
//      fBdt.txOdd.setControl(BDTEntry_DTS_MASK);
      setState(EPIdle);
      setDataToggle(DataToggle_0);
   }

   /**
    * Flip active odd/even buffer state
    *
    * @param[in]  usbStat Value from USB_STAT
    */
   void flipOddEven(const UsbStat usbStat) {
      usbdm_assert(fEndpointNumber == usbStat.endp, "Wrong end point!");

      if (usbStat.tx) {
         // Flip Transmit buffer
         fTxOdd = !usbStat.odd;
      }
      else {
         // Flip Receive buffer
         fRxOdd = !usbStat.odd;
      }
   }

   /**
    * Set callback to execute on completion of data and handshake phases of transaction.
    *
    *  This callback routine is called with parameter endpointState which is
    *  the state of endpoint before completion of transaction:\n
    *  - After an IN transaction with endpointState = EPDataIn, EPStatusIn.\n
    *  - After an OUT transaction with endpointState = EPDataOut, EPStatusOut.
    *  The endpoint state will be set to EPIdle <b>before</b> calling this routine.
    *
    * @param[in]  callback The call-back function to execute\n
    *                      May be nullptr to remove callback
    */
   void setCallback(EndpointState (*callback)(EndpointState)) {
      if (callback == nullptr) {
         callback = unsetHandlerCallback;
      }
      fCallback = callback;
   }

   /**
    *  Indicates that the next IN transaction needs to be terminated
    *  with a ZLP if transfer size is multiple of endpoint size
    *
    *  @param[in]  needZLP True to indicate need for ZLPs.
    *
    *  @note This flag is cleared during the transaction
    */
   void setNeedZLP(bool needZLP=true) {
      fNeedZLP = needZLP;
   }

   /**
    * Get Receive BDT entry to be used for next OUT transaction
    *
    * @return Receive BDT
    */
   volatile BdtEntry &getFreeBdtReceiveEntry() {
      return fRxOdd?fBdt.rxOdd:fBdt.rxEven;
   }

   /**
    * Get Receive BDT entry used for last OUT transaction
    *
    * @return Receive BDT
    */
   volatile BdtEntry &getCompleteBdtReceiveEntry() {
      return (!fRxOdd)?fBdt.rxOdd:fBdt.rxEven;
   }

   /**
    * Get Transmit BDT entry to be used for next IN transaction
    *
    * @return Transmit BDT
    */
   volatile BdtEntry &getFreeBdtTransmitEntry() {
      return fTxOdd?fBdt.txOdd:fBdt.txEven;
   }

   /**
    * Get Transmit BDT entry used for last IN transaction
    *
    * @return Transmit BDT
    */
   volatile BdtEntry &getCompleteBdtTransmitEntry() {
      return (!fTxOdd)?fBdt.txOdd:fBdt.txEven;
   }

   /**
    * Gets size of last completed transfer
    *
    * @return Size of transfer
    */
   uint16_t getDataTransferredSize() {
      return fDataTransferred;
   }

   /**
    * Gets maximum transfer size for endpoint
    *
    * @return Maximum size of transfer
    */
   uint16_t getMaximumTransferSize() {
      return fEndpointSize;
   }

   /**
    * Start IN transaction stage [Transmit, device -> host, DATA0/1 sequence]
    *
    * @param[in]  state   State to adopt for this phase e.g. EPDataIn, EPStatusIn
    * @param[in]  bufSize Size of buffer to send (may be zero)
    * @param[in]  bufPtr  Pointer to external buffer (may be NULL to indicate fDatabuffer is being used directly)
    */
   void startTxStage(EndpointState state, uint16_t bufSize=0, volatile const uint8_t *bufPtr=nullptr) {
      // Pointer to data
      fDataPtr = (uint8_t*)bufPtr;

      // Count of bytes transferred
      fDataTransferred = 0;

      // Count of remaining bytes
      fDataRemaining = bufSize;

      // State for this transaction
      fState = state;

      // Configure the BDT for transfer
      startTxTransaction();
   }

   /**
    * Configure the BDT for next IN transaction [Transmit, device -> host]
    */
   void startTxTransaction() {

      // Get BDT to use
      volatile BdtEntry &bdt = getFreeBdtTransmitEntry();
      if (bdt.own != BdtOwner_MCU) {
         __asm__("bkpt");
      }
//      usbdm_assert(bdt.own == BdtOwner_MCU, "MCU doesn't own BDT!");

      uint16_t size = fDataRemaining;
      if (size > fEndpointSize) {
         size = fEndpointSize;
      }
      // No ZLP needed if sending undersize transaction
      if (size<fEndpointSize) {
         setNeedZLP(false);
      }
      // fDataBuffer may be nullptr to indicate using fDataBuffer directly
      if (fDataPtr != nullptr) {
         // Copy the Transmit data to EP buffer
         safeCopy(fTxDataBuffer, fDataPtr, size);

         // Advance pointer to next data
         fDataPtr += size;
      }
      // Count of transferred bytes
      fDataTransferred += size;

      // Count of remaining bytes
      fDataRemaining   -= size;

      // Set up to Transmit transaction
      bdt.setByteCount((uint8_t)size);
      if (fDataToggle == DataToggle_1) {
         bdt.setControl(BDTEntry_OWN_MASK|BDTEntry_DATA1_MASK|BDTEntry_DTS_MASK);
      }
      else {
         bdt.setControl(BDTEntry_OWN_MASK|BDTEntry_DATA0_MASK|BDTEntry_DTS_MASK);
      }
      // console.WRITE("BdtTx(s=").WRITE(size).WRITE(",").WRITE(fDataToggle?"D1,":"D0,").WRITE(fTxOdd?"Odd),":"Even),");;
   }

   /**
    * Start an OUT transaction stage [Receive, device <- host, DATA0/1 sequence]
    *
    *   @param[in]  state   - State to adopt for phase e.g. EPIdle, EPDataOut, EPStatusOut
    *   @param[in]  bufSize - Size of data to transfer (may be zero)
    *   @param[in]  bufPtr  - Buffer for data (may be nullptr)
    */
   void startRxStage(EndpointState state, uint16_t bufSize=0, uint8_t *bufPtr=nullptr) {
      // Count of bytes transferred
      fDataTransferred     = 0;
      // Total bytes to Receive
      fDataRemaining       = bufSize;
      // Where to (eventually) place data
      fDataPtr             = bufPtr;
      // State to adopt
      fState               = state;
      // Configure the BDT for transfer
      startRxTransaction();
   }

   /**
    * Configure the BDT for OUT transaction [Receive, device <- host, DATA0/1]
    *
    * @note Always uses EP_MAXSIZE for transaction size accepted irrespective of remaining transfer size.\n
    *       This is necessary to ensure the endpoint can accept a SETUP transaction.
    */
   void startRxTransaction() {

      // Get BDT to use
      volatile BdtEntry &bdt = getFreeBdtReceiveEntry();

      usbdm_assert(bdt.own == BdtOwner_MCU, "MCU doesn't own BDT!");

      // Set up to Receive transaction
      // Always used maximum size even if expecting less data
      bdt.setByteCount(fEndpointSize);
      if (fDataToggle) {
         bdt.setControl(BDTEntry_OWN_MASK|BDTEntry_DATA1_MASK|BDTEntry_DTS_MASK);
      }
      else {
         bdt.setControl(BDTEntry_OWN_MASK|BDTEntry_DATA0_MASK|BDTEntry_DTS_MASK);
      }
      // console.WRITE("BdtRx(s=").WRITE(EP_MAXSIZE).WRITE(fDataToggle?",D1:":",D0:").WRITE(fRxOdd?"Odd),":"Even),");
   }

   /**
    *  Save the data from an OUT transaction and advance pointers etc.
    *
    *  @return Number of bytes saved
    */
   uint8_t saveRxData() {

      // Get BDT to use
      volatile BdtEntry &bdt = getCompleteBdtReceiveEntry();

      uint8_t size = bdt.bc;

      if (size > 0) {
         // Check if more data than requested - discard excess
         if (size > fDataRemaining) {
            size = fDataRemaining;
         }
         // Check if external buffer in use
         if (fDataPtr != nullptr) {
            // Copy the data from the Receive buffer to external buffer
            ( void )memcpy((void*)fDataPtr, (void*)fRxDataBuffer, size);
            // Advance buffer ptr
            fDataPtr    += size;
         }
         // Count of transferred bytes
         fDataTransferred += size;
         // Count down bytes to go
         fDataRemaining   -= size;
      }
//      else {
//         console.WRITELN("RxSize = 0\n");
//      }
      return size;
   }

   /**
    * Handle OUT [Receive, device <- host, DATA0/1]
    */
   void handleOutToken() {
      //      console.WRITE("Out(),");

      uint8_t transferredSize = 0;

      // Toggle DATA0/1 for next transaction
      fDataToggle = !fDataToggle;

      switch (fState) {
         case EPDataOut:        // Receiving a sequence of OUT transactions
            // Save the data from the Receive buffer
            transferredSize = saveRxData();
            if ((transferredSize < fEndpointSize) || (fDataRemaining == 0)) {
               // Completed DATA stage if undersize transaction or received expected number of bytes

               if (fEndPointType == EndPointType_Control) {
                  // Just completed a series of OUT transfers on Control endpoint -
                  // Do empty status transaction transmission - no response expected
                  setDataToggle(DataToggle_1);
                  startTxStage(EPStatusIn);

                  // Make ready for next SETUP stage
                  setDataToggle(DataToggle_0);
                  startRxStage(EPStatusIn);
               }
               else {
                  // Bulk or interrupt
                  // Do callback after DATA OUT stage with no state change
                  fState = fCallback(EPDataOut);
               }
            }
            else {
               // Set up for next OUT DATA 0/1 transaction
               startRxTransaction();
            }
            break;

         case EPStatusOut:       // Done OUT transaction as a status handshake from host (IN CONTROL transfer)
            // Make ready for SETUP stage
            Endpoint::setDataToggle(DataToggle_0);
            startRxStage(EPIdle);

            // Execute callback function after STATUS IN transaction
            fCallback(EPStatusOut);
            break;

         // We don't expect an OUT token while in the following states
         case EPDataIn:    // Doing a sequence of IN transactions (until data count <= fEndpointSize)
         case EPStatusIn:  // Just done an IN transaction as a status handshake
         case EPIdle:      // Idle
         case EPStall:     // Not used
         default:
            console.WRITE("Unexpected OUT, ep=").WRITE(fEndpointNumber).WRITE(", s=").WRITELN(getStateName());
            fState = EPIdle;
            break;
      }
   }

   /**
    * Handle IN token [Transmit, device -> host]
    */
   void handleInToken() {
      //       console.WRITE("In(),");

      // Toggle DATA0/1 for next transaction
      fDataToggle = !fDataToggle;

      //   console.WRITELN(fHardwareState[BDM_OUT_ENDPOINT].data0_1?"ep2HandleInToken-T-1":"ep2HandleInToken-T-0");

      switch (fState) {
         case EPDataIn:    // Doing a sequence of IN transactions
            // Check if data remaining
            if ((fDataRemaining > 0) || fNeedZLP) {
               // Set up next IN DATA transaction
               startTxTransaction();
            }
            else {
               if (fEndPointType == EndPointType_Control) {
                  // Just completed a series of IN transfers on Control endpoint -
                  // Do empty status transaction reception
                  // (Already set up for next reception in EPDataOut)
                  fState = EPStatusOut;
               }
               else {
                  // Bulk or interrupt
                  // Do callback after DATA IN stage with no state change
                  fState = fCallback(EPDataIn);
               }
            }
            break;

         case EPStatusIn: // Just done an IN transaction as a status handshake for an OUT Data transfer
            // Execute callback function after STATUS IN transaction
            fState = EPIdle;
//            console.write((void*)fCallback); // Check call-back address
            fCallback(EPStatusIn);
            break;

         // We don't expect an IN token while in the following states
         case EPIdle:      // Idle (Transmit complete)
         case EPDataOut:   // Doing a sequence of OUT transactions (until data count <= fEndpointSize)
         case EPStatusOut: // Doing an OUT transaction as a status handshake
         default:
            console.WRITE("Unexpected IN, ep=").WRITE(fEndpointNumber).WRITE(", s=").WRITELN(getStateName());
            fState = EPIdle;
            break;
      }
   }

   /**
    * Gets pointer to USB transmit data buffer
    *
    * @return Pointer to buffer
    */
   volatile uint8_t *getTxBuffer() {
      return fTxDataBuffer;
   }

   /**
    * Gets pointer to USB receive data buffer
    *
    * @return Pointer to buffer
    */
   volatile const uint8_t *getRxBuffer() {
      return fRxDataBuffer;
   }

};

/**
 * Class for generic endpoint with one buffer (Rx or Tx or shared Rx/Tx)
 *
 * @tparam Info         Class describing associated USB hardware
 * @tparam ENDPOINT_NUM Endpoint number
 * @tparam EP_MAXSIZE   Maximum size of DATA transaction
 */
template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
class Endpoint_T : public Endpoint {

private:
   /** Buffer for Transmit & Receive data */
   static uint8_t fAllocatedDataBuffer[EP_MAXSIZE] __attribute__ ((aligned (8)));

public:
   /** Size of endpoint (maximum transfer size) */
   static constexpr unsigned BUFFER_SIZE = EP_MAXSIZE;

   /**
    * Constructor
    */
   Endpoint_T(EndPointType endPointType, uint8_t bdtValue) :
      Endpoint(ENDPOINT_NUM, EP_MAXSIZE, endPointType, bdtValue, fAllocatedDataBuffer, fAllocatedDataBuffer, Usb0Info::baseAddress) {
   }
};

template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
uint8_t Endpoint_T<Info, ENDPOINT_NUM, EP_MAXSIZE>::fAllocatedDataBuffer[EP_MAXSIZE];

/**
 * Class for generic endpoint with 2 buffers (Tx + Rx)
 *
 * @tparam Info         Class describing associated USB hardware
 * @tparam ENDPOINT_NUM Endpoint number
 * @tparam EP_MAXSIZE   Maximum size of DATA transaction
 */
template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
class Endpoint2_T : public Endpoint {

private:
   /** Buffer for Transmit & Receive data */
   static uint8_t fAllocatedTxDataBuffer[EP_MAXSIZE] __attribute__ ((aligned (4)));

   /** Buffer for Transmit & Receive data */
   static uint8_t fAllocatedRxDataBuffer[EP_MAXSIZE] __attribute__ ((aligned (4)));

public:
   /** Size of endpoint (maximum transfer size) */
   static constexpr unsigned BUFFER_SIZE = EP_MAXSIZE;

   /**
    * Constructor
    */
   Endpoint2_T(EndPointType endPointType, uint8_t bdtValue) :
      Endpoint(ENDPOINT_NUM, EP_MAXSIZE, endPointType, bdtValue, fAllocatedTxDataBuffer, fAllocatedRxDataBuffer, Info::usb()) {
   }
};

template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
uint8_t Endpoint2_T<Info, ENDPOINT_NUM, EP_MAXSIZE>::fAllocatedTxDataBuffer[EP_MAXSIZE];

template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
uint8_t Endpoint2_T<Info, ENDPOINT_NUM, EP_MAXSIZE>::fAllocatedRxDataBuffer[EP_MAXSIZE];

/**
 * Class for CONTROL endpoint
 *
 * @tparam Info       Class describing associated USB hardware
 * @tparam EP0_SIZE   Maximum size of DATA transaction
 */
template<class Info, unsigned EP0_SIZE>
class ControlEndpoint : public Endpoint_T<Info, 0, EP0_SIZE> {

public:
   using Endpoint::fState;
   using Endpoint::startRxTransaction;
   using Endpoint::getFreeBdtReceiveEntry;
   using Endpoint::startTxStage;
   using Endpoint::startRxStage;

   /** End point number */
   static constexpr unsigned fEndpointNumber = 0;

   // Value used to initialise an Endpoint Control Register - Tx and Rx
   static constexpr uint8_t fEpControlValue = USB_ENDPT_EPRXEN_MASK|USB_ENDPT_EPTXEN_MASK|USB_ENDPT_EPHSHK_MASK;

   /**
    * Constructor for CONTROL endpoint
    */
   constexpr ControlEndpoint() : Endpoint_T<Info, 0, EP0_SIZE>(EndPointType_Control, fEpControlValue) {
   }

   /**
    * Destructor
    */
   virtual ~ControlEndpoint() {
   }

   /**
    * Start empty status IN transaction phase [Transmit, device -> host, DATA1]
    * Used to acknowledge a DATA OUT transaction.
    *
    * State       = EPStatusIn
    * Data Toggle = DATA1
    */
   void startTxStatus() {
      Endpoint::setDataToggle(DataToggle_1);
      startTxStage(EPStatusIn);
   }

   /**
    * Start an SETUP transaction phase [Receive, device <- host, DATA0]
    *
    * State       = EPIdle
    * Data Toggle = DATA0
    */
   void startSetupTransaction() {
      Endpoint::setDataToggle(DataToggle_0);
      startRxStage(EPIdle);
   }

   /**
    * Conditionally set up for SETUP transaction [Rx, host -> device, DATAx]
    * If already configured for OUT transfer does nothing.
    *
    * This routine would be used after processing a SETUP transaction (before data phase).
    *
    * State       = unchanged
    * Data Toggle = unchanged
    */
   void checkSetupReady() {
      // Get BDT to use
      volatile BdtEntry &bdt = getFreeBdtReceiveEntry();

      if (bdt.own == BdtOwner_MCU) {
         // Make ready for SETUP transaction
         startRxTransaction();
      }
   }

   /**
    * Modifies endpoint state after SETUP has been received.
    * DATA1 is toggle for first transaction in data phase
    *
    * State       = EPIdle
    * Data Toggle = DATA1
    */
   void setupReceived() {
      fState      = EPIdle;
      Endpoint::setDataToggle(DataToggle_1);
   }
};

/**
 * Class for IN endpoint
 *
 * @tparam Info         Class describing associated USB hardware
 * @tparam ENDPOINT_NUM Endpoint number
 * @tparam EP_MAXSIZE   Maximum size of DATA transaction
 */
template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
class InEndpoint : public Endpoint_T<Info, ENDPOINT_NUM, EP_MAXSIZE> {

protected:
   using Endpoint = Endpoint_T<Info, ENDPOINT_NUM, EP_MAXSIZE>;

private:
   // Make private
   using Endpoint::startRxStage;
   using Endpoint::startRxTransaction;
   using Endpoint::saveRxData;

   // Value used to initialise an Endpoint Control Register - Tx
   static constexpr uint8_t fEpControlValue = USB_ENDPT_EPTXEN_MASK|USB_ENDPT_EPHSHK_MASK;

public:
   /**
    * Constructor for IN endpoint
    */
   constexpr InEndpoint(EndPointType endPointType) : Endpoint(endPointType, fEpControlValue)  {
   }
};

/**
 * Class for OUT endpoint
 *
 * @tparam Info         Class describing associated USB hardware
 * @tparam ENDPOINT_NUM Endpoint number
 * @tparam EP_MAXSIZE   Maximum size of DATA transaction
 */
template<class Info, unsigned ENDPOINT_NUM, unsigned EP_MAXSIZE>
class OutEndpoint : public Endpoint_T<Info, ENDPOINT_NUM, EP_MAXSIZE> {

protected:
   using Endpoint = Endpoint_T<Info, ENDPOINT_NUM, EP_MAXSIZE>;

private:
   // Make private
   using Endpoint::startTxStage;
   using Endpoint::startTxTransaction;

   // Value used to initialise an Endpoint Control Register - Rx
   static constexpr uint8_t fEpControlValue = USB_ENDPT_EPRXEN_MASK|USB_ENDPT_EPHSHK_MASK;

public:
   /**
    * Constructor for OUT endpoint
    */
   constexpr OutEndpoint(EndPointType endPointType) : Endpoint(endPointType, fEpControlValue) {
   }

};

/**
 * End USB_Group
 * @}
 */

}; // end namespace

#endif /* HEADER_USB_ENDPOINT_H */
