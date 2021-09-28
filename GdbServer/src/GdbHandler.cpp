/*
 * GdbHandler.cpp
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#include "GdbHandler.h"

const char *GdbHandler::getStatusName(GdbTargetStatus status) {
   const char *names[] = {
         "NO CONNECTION",
         "UNKNOWN(LLSx/VLLSx?)",
         "RUN",
         "HALT",
         "RESET",
         "WAIT",
         "STOP",
         "VLPR",
         "VLPW",
         "VLPS",
         "LLSxEXIT",
         "VLLSxEXIT",
         "USER INPUT",
         };

   if (status>=(sizeof(names)/sizeof(names[0]))) {
      return "ILLEGAL";
   }
   return names[status];
}

const char *GdbHandler::getRunStateName(RunState runState) {
   enum RunState {Halted, Stepping, Running, Breaking, UserInput};

   const char *names[] = {
         "Halted",
         "Stepping",
         "Running",
         "UserInput",
         };

   if (runState>=(sizeof(names)/sizeof(names[0]))) {
      return "Illegal";
   }
   return names[runState];
}




