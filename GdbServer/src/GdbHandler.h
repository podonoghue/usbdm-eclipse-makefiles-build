/*
 * gdbHandler.h
 *
 *  Created on: 22/05/2011
 *      Author: podonoghue
 */

#ifndef GDBHANDLER_H_
#define GDBHANDLER_H_

#include "BdmInterface.h"
#include "GdbInOut.h"

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
      T_UNKNOWN =  0,         // Unknown not polled or may be sleeping
      T_NOCONNECTION,
      T_RUNNING,              // Executing
      T_HALT,                 // Debug halt
      T_RESET,                // Target in reset
      T_WAIT,                 // Low power sleep (WAIT)
      T_STOP,                 // Low power deep-sleep (STOP)
      T_VLPR,                 // Low-power run (VLPR)
      T_VLPW,                 // Low power sleep (VLPW)
      T_VLPS,                 // Low power deep-sleep (VLPS)
      T_LLSxRESET,            // Stopped after LLSx Reset
      T_VLLSxRESET,           // Stopped after VLLSx Reset
      T_USER_INPUT,           // Stopped waiting for character in semi-hosting
   };

public:
   GdbHandler() {};
   virtual ~GdbHandler() {};

   virtual USBDM_ErrorCode      initialise() = 0;
   virtual USBDM_ErrorCode      doCommand(const GdbPacket *pkt) = 0;
   virtual GdbTargetStatus      pollTarget() = 0;
   virtual USBDM_ErrorCode      updateTarget() = 0;
   virtual USBDM_ErrorCode      resetTarget() = 0;
   virtual USBDM_ErrorCode      stepTarget(bool disableInterrupts) = 0;
   virtual USBDM_ErrorCode      continueTarget() = 0;
   virtual USBDM_ErrorCode      haltTarget() = 0;
   static const char           *getStatusName(GdbTargetStatus status);

protected:
   enum RunState {Halted, Stepping, Running, Breaking, UserInput};
   static const char           *getRunStateName(RunState runState);
};

typedef std::tr1::shared_ptr<GdbHandler> GdbHandlerPtr;

#endif /* GDBHANDLER_H_ */
