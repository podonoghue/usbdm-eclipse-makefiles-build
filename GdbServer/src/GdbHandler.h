/*
 * gdbHandler.h
 *
 *  Created on: 22/05/2011
 *      Author: podonoghue
 */

#ifndef GDBHANDLER_H_
#define GDBHANDLER_H_

#include <memory>
#include "BdmInterface.h"
#include "GdbInOut.h"
#include "DeviceData.h"

class GdbHandler {

public:
   enum GdbMessageLevel {
      M_BORINGINFO = 0,
      M_INFO,
      M_WARN,
      M_ERROR,
      M_FATAL,
      M_SEMI_HOSTING,
      M_DIALOGUE = 0x80,
   };

   class GdbHandlerOwner {

   public:
      /**
       * Constructor
       */
      GdbHandlerOwner(){}
      /**
       * Destructor
       */
      virtual ~GdbHandlerOwner(){}

      /**
       * Display/Notify message
       *
       * @param msg     Text of message
       * @param level   Severity of message (used to filter uninteresting messages)
       * @param rc      Error code associated with message (if any)
       *
       * @return Modified error code
       */
      virtual USBDM_ErrorCode displayMessage(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc) = 0;

      /**
       * Close connection in near future when inactive (i.e. polling etc not actually executing)
       */
      virtual void            setDeferredCloseClient() = 0;
   };

   GdbHandler() {};
   virtual ~GdbHandler() {};

   enum GdbTargetStatus {
      GdbTargetStatus_NOCONNECTION = 0,     // No connection
      GdbTargetStatus_UNKNOWN,              // Unable to poll target- may be due to LLSx/VLLSx (within timeout)
      GdbTargetStatus_RUNNING,              // Currently executing
      GdbTargetStatus_HALT,                 // Currently in debug halt
      GdbTargetStatus_RESET,                // Currently in reset
      GdbTargetStatus_WAIT,                 // Currently in sleep (WAIT)
      GdbTargetStatus_STOP,                 // Currently in deep-sleep (STOP)
      GdbTargetStatus_VLPR,                 // Currently in low-power run (VLPR)
      GdbTargetStatus_VLPW,                 // Currently in low power sleep (VLPW)
      GdbTargetStatus_VLPS,                 // Currently in low power deep-sleep (VLPS)
      GdbTargetStatus_LLSxEXIT,             // Exited LLSx mode and is executing
      GdbTargetStatus_VLLSxEXIT,            // Exited VLLSx state and held in reset (Debug state lost)
      GdbTargetStatus_USER_INPUT,           // Stopped waiting for character in semi-hosting
   };

   /**
    * Get name for target status
    *
    * @param status
    *
    * @return
    */
   static const char           *getStatusName(GdbTargetStatus status);

   /**
    * Initialize target
    *
    * @return Error code
    */
   virtual USBDM_ErrorCode      initialise() = 0;
   /**
    * Do GDB command
    *
    * @param pkt Packet indicate command
    *
    * @return
    */
   virtual USBDM_ErrorCode      doCommand(const GdbPacket *pkt) = 0;
   /**
    * Poll target status
    *
    * @return Target status
    */
   virtual GdbTargetStatus      pollTarget() = 0;
   /**
    * Notify that there has been a change in the bdmInterface settings etc.
    *
    * @return
    */
   virtual USBDM_ErrorCode      updateTarget() = 0;
   /**
    * Reset Target
    *
    * @param resetMethod  Reset method to use
    *
    * @return
    */
   virtual USBDM_ErrorCode      resetTarget(DeviceData::ResetMethod resetMethod=DeviceData::ResetMethod::resetTargetDefault) = 0;
   /**
    * Step target
    *
    * @param disableInterrupts  Whether interrupts should be enabled during stepping
    *
    * @return
    */
   virtual USBDM_ErrorCode      stepTarget(bool disableInterrupts) = 0;
   /**
    * Continue target execution
    *
    * @return
    */
   virtual USBDM_ErrorCode      continueTarget() = 0;
   /**
    * Halt target
    *
    * @return
    */
   virtual USBDM_ErrorCode      haltTarget() = 0;

   /**
    * Notify GDB of target status change
    *
    * @return
    */
   virtual USBDM_ErrorCode      notifyGdb() = 0;

protected:
   enum RunState {
      RunState_Halted,
      RunState_Stepping,
      RunState_Running,
      RunState_UserInput};

   static const char     *getRunStateName(RunState runState);
};

typedef std::shared_ptr<GdbHandler> GdbHandlerPtr;

#endif /* GDBHANDLER_H_ */
