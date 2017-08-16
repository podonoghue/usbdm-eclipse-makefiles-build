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
   typedef USBDM_ErrorCode (*GdbCallback)(const char *msg, GdbMessageLevel level, USBDM_ErrorCode rc);

   enum GdbTargetStatus {
      T_UNKNOWN =  0,         // Unknown - not yet polled or may be LLSx/VLLSx without timeout
      T_NOCONNECTION,         // Unable to connect to target - may be in LLSx or VLLSx.
      T_RUNNING,              // Currently executing
      T_HALT,                 // Currently in debug halt
      T_RESET,                // Currently in reset
      T_WAIT,                 // Currently in sleep (WAIT)
      T_STOP,                 // Currently in deep-sleep (STOP)
      T_VLPR,                 // Currently in low-power run (VLPR)
      T_VLPW,                 // Currently in low power sleep (VLPW)
      T_VLPS,                 // Currently in low power deep-sleep (VLPS)
      T_LLSxEXIT,             // Exited LLSx state
      T_VLLSxEXIT,            // Exited VLLSx state
      T_USER_INPUT,           // Stopped waiting for character in semi-hosting
   };

public:
   GdbHandler() {};
   virtual ~GdbHandler() {};

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
    * Get name for target status
    *
    * @param status
    *
    * @return
    */
   static const char           *getStatusName(GdbTargetStatus status);

protected:
   enum RunState {Halted, Stepping, Running, Breaking, UserInput};
   static const char           *getRunStateName(RunState runState);
};

typedef std::shared_ptr<GdbHandler> GdbHandlerPtr;

#endif /* GDBHANDLER_H_ */
