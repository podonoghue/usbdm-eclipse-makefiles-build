/*
 * JTAGSequence.cpp
 *
 *  Created on: 27/05/2010
 *      Author: podonoghue
 */
#include <string.h>
//#include <stdlib.h>

#include <stdio.h>
#include "JTAGSequence.h"
#include "UsbdmSystem.h"
#if defined(LOG) && defined(LOG_JTAG)
#include "USBDM_DSC_API.h"
#include "USBDM_DSC_API_Private.h"
#endif
//#include "USBDM_DSC_API.h"
//#include "USBDM_DSC_API_Private.h"

#define BITS_TO_NYBBLES(x)  (((x)+3)/4)


JTAG32::JTAG32() {
   this->length = 32;
   regData[0] = 0;
   regData[1] = 0;
   regData[2] = 0;
   regData[3] = 0;
}


JTAG32::JTAG32(uint32_t regValue, uint8_t length) {
   this->length = length;
   if (length < 32)
      regValue &= ~(0xFFFFFFFUL<<length);
   regData[0] = (regValue>>24);
   regData[1] = (regValue>>16);
   regData[2] = (regValue>>8);
   regData[3] = regValue;
}


JTAG32::JTAG32(const uint8_t *&regValue, uint8_t length) {
   this->length = length;
   if (length > 24) {
      regData[0] = *regValue++;
      regData[0] &= ~(0xFF<<(length-24));
   }
   else
      regData[0] = 0;
   if (length > 16) {
      regData[1] = *regValue++;
      regData[1] &= ~(0xFF<<(length-16));
   }
   else
      regData[1] = 0;
   if (length > 8) {
      regData[2] = *regValue++;
      regData[2] &= ~(0xFF<<(length-8));
   }
   else
      regData[2] = 0;
   regData[3] = *regValue++;
   if (length<8)
      regData[3] &= ~(0xFF<<length);
}


JTAG32::operator uint32_t() {
   if (length>24) {
      return (regData[0]<<24)+(regData[1]<<16)+(regData[2]<<8)+regData[3];
   }
   else if (length>16) {
      return (regData[1]<<16)+(regData[2]<<8)+regData[3];
   }
   else if (length>8) {
      return (regData[2]<<8)+regData[3];
   }
   else {
      return regData[3];
   }
}


uint8_t *JTAG32::getData(uint8_t length) {
   this->length = length;
   if (length>24) {
      return regData;
   }
   else if (length>16) {
      return regData+1;
   }
   else if (length>8) {
      return regData+2;
   }
   else {
      return regData+3;
   }
}


void JTAG32::copyToArray(uint8_t dest[]) {
   int sub = 0;
   if (length>24) {
      dest[sub++] = regData[0];
   }
   if (length>16) {
      dest[sub++] = regData[1];
   }
   if (length>8) {
      dest[sub++] = regData[2];
   }
   dest[sub++] = regData[3];
}

#ifdef _MSC_VER

#define snprintf c99_snprintf

inline int c99_vsnprintf(char* str, size_t size, const char* format, va_list ap)
{
    int count = -1;

    if (size != 0)
        count = _vsnprintf_s(str, size, _TRUNCATE, format, ap);
    if (count == -1)
        count = _vscprintf(format, ap);

    return count;
}

inline int c99_snprintf(char* str, size_t size, const char* format, ...)
{
    int count;
    va_list ap;

    va_start(ap, format);
    count = c99_vsnprintf(str, size, format, ap);
    va_end(ap);

    return count;
}

#endif // _MSC_VER

const char *JTAG32::toString() {
   uint32_t temp = (uint32_t)*this;
   if (length!= 32)
      temp &= ~(0xFFFFFFFFUL<<length);
   snprintf(buff, sizeof(buff), "0x%*.*X:%-2d",
            BITS_TO_NYBBLES(length), BITS_TO_NYBBLES(length), temp, length);
   return buff;
}

#ifdef LOG_JTAG

USBDM_ErrorCode debugExecuteJTAGSequence(uint8_t       sequenceLength,
                                         const uint8_t *sequenceStart,
                                         uint8_t       dataInLength,
                                         uint8_t       *dataInStart);
#endif


USBDM_ErrorCode executeJTAGSequence(uint8_t       sequenceLength,
                                    const uint8_t *sequenceStart,
                                    uint8_t       dataInLength,
                                    uint8_t       *dataInStart,
                                    bool          doLog) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
#ifndef LOG
   rc = USBDM_JTAG_ExecuteSequence(sequenceLength, sequenceStart, dataInLength, dataInStart);
#else
   if (doLog) {
      log.print("executeJTAGSequence()=>\n");
      log.print("==============================================================\n");
      listJTAGSequence(sequenceLength, sequenceStart);
   }
#ifdef LOG_JTAG
   rc = debugExecuteJTAGSequence(sequenceLength, sequenceStart, dataInLength, dataInStart);
#else
   rc = USBDM_JTAG_ExecuteSequence(sequenceLength, sequenceStart, dataInLength, dataInStart);
#endif
   if (doLog) {
      if (rc == BDM_RC_OK) {
         log.print("Returned data =>    ----------------------------------------\n");
         log.printDump(dataInStart, dataInLength);
      }
      log.print("==============================================================\n");
   }
#endif
   if (rc != BDM_RC_OK)
      log.print("executeJTAGSequence() Failed, reason = %s\n", USBDM_GetErrorString(rc));
   return rc;
}

#if defined(LOG) && defined(LOG_JTAG)

// 000 00000   move TEST-LOGIC-RESET
// 000 00001   move RUN-TEST-IDLE
// 000 00010   move DR-SCAN
// 000 00011   move IR-SCAN
// 000 001XX   set exit state for next sequence transfer
       // 00   remain JTAG_SHIFT-DR/IR (default)
       // 01   exit to JTAG_SHIFT-DR w/o crossing RUN-TEST-IDLE
       // 10   exit to JTAG_SHIFT-IR w/o crossing RUN-TEST-IDLE
       // 11   exit to RUN-TEST-IDLE w/o crossing RUN-TEST-IDLE
// 000 00100
// 000 11110   reserved
// 000 11111   end
// 001 NNNNN   shift out N bits of sequence
// 010 NNNNN   shift in N bits of sequence
// 011 NNNNN   shift in/out N bits of sequence
// 1xx xxxxx   reserved

static void printBits(uint8_t numBits, const uint8_t *data);

static uint8_t getValueByte(uint8_t value);

#define STOP_ON_END         (0<<0) // Stops on END anyway
#define STOP_ON_ELSE        (1<<1)
#define STOP_ON_ELSE_IF     (1<<2)
#define STOP_ON_END_IF      (1<<3)
#define STOP_ON_END_REPEAT  (1<<4)
#define STOP_ON_SUB         (1<<5)

//! Search for delimiters
//!
//! @param sentinel - Mask indicating values to accept
//!
//! @return Ptr to found final search position (sentinel if found)
//!
//! @note Searches are qualified by loop depth.
//! @note Assumes correct nesting of loops and conditionals
//! @note Stop unconditionally on JTAG_SUBx or JTAG_END
//!
static const uint8_t *skipSequence(const uint8_t *sequence, uint8_t sentinel, int *indent) {
   uint8_t temp;
   uint8_t loopDepth = 0;
   const uint8_t *sequenceStart = sequence;

//   print("skipSequence() \n");
   for(;;) {
      uint8_t opcode   = *sequence;
      uint8_t numBits  = (opcode&JTAG_NUM_BITS_MASK);  // In case needed
      if (numBits == 0)
         numBits = 32;

      switch (opcode&JTAG_COMMAND_MASK) {
         case JTAG_MISC0: // Misc commands
         case JTAG_MISC1:
            switch (opcode) {
               // Unconditionally stop search on any of the following
               case JTAG_END:
               case JTAG_SAVE_SUB:
                  print("skipSequence(), Found end at %d\n",sequence-sequenceStart);
                  return sequence;

               case JTAG_SUBA:
               case JTAG_SUBB:
               case JTAG_SUBC:
               case JTAG_SUBD:
                  if (sentinel&STOP_ON_SUB)
                     return sequence;
                  break;

               case JTAG_END_SUB:
                  if (sentinel&STOP_ON_SUB)
                     return ++sequence;

               // 8-bit in line parameter
               case JTAG_SHIFT_IN_DP:
               case JTAG_SHIFT_OUT_DP:
               case JTAG_SHIFT_IN_OUT_DP:
//               case JTAG_SHIFT_IN_VARA:
//               case JTAG_SHIFT_IN_VARB:
               case JTAG_SHIFT_OUT_VARA:
               case JTAG_SHIFT_OUT_VARB:
               case JTAG_SET_ERROR:
               case JTAG_PUSH8:
               case JTAG_REPEAT8:
                  sequence++; // Skip inline value
                  break;

               // 16-bit in line parameter
               case JTAG_PUSH16:
                  sequence+=2; // Skip inline value
                  break;

               // 32-bit in line parameter
               case JTAG_PUSH32:
                  sequence+=4; // Skip inline value
                  break;

               // Increase nesting level - no params
               case JTAG_IF_ITER_EQ:
               case JTAG_IF_ITER_NEQ:
               case JTAG_IF_VARA_EQ:
               case JTAG_IF_VARB_EQ:
               case JTAG_IF_VARA_NEQ:
               case JTAG_IF_VARB_NEQ:
               case JTAG_REPEAT:
                  loopDepth++;
                  break;

               // Reduce nesting level - no params
               case JTAG_END_IF:
                  if (loopDepth>0)
                     loopDepth--;
                  else {
                     if (sentinel&STOP_ON_END_IF)
                        return sequence;
                     (*indent)--;
                  }
                  break;
               case JTAG_END_REPEAT:
                  if (loopDepth>0)
                     loopDepth--;
                  else {
                     if (sentinel&STOP_ON_END_REPEAT)
                        return sequence;
                     (*indent)--;
                  }
                  break;

               // No parameters
               case JTAG_ELSE:
                  if (sentinel&STOP_ON_ELSE)
                     return ++sequence;

               // No parameters
               case JTAG_TEST_LOGIC_RESET:
               case JTAG_MOVE_DR_SCAN:
               case JTAG_MOVE_IR_SCAN:
               case JTAG_SET_STAY_SHIFT:
               case JTAG_SET_EXIT_SHIFT_DR:
               case JTAG_SET_EXIT_SHIFT_IR:
               case JTAG_SET_EXIT_IDLE:
               case JTAG_SET_IN_FILL_0:
               case JTAG_SET_IN_FILL_1:
               case JTAG_CALL_SUBA:
               case JTAG_CALL_SUBB:
               case JTAG_CALL_SUBC:
               case JTAG_CALL_SUBD:
               case JTAG_NOP:
               case JTAG_RETURN:
               case JTAG_CONTINUE:
               case JTAG_BREAK:
               case JTAG_SAVE_OUT_DP_VARC:
               case JTAG_SAVE_OUT_DP_VARD:
               case JTAG_RESTORE_DP_VARC:
               case JTAG_RESTORE_DP_VARD:
               case JTAG_PUSH_DP_8:
               case JTAG_PUSH_DP_16:
               case JTAG_PUSH_DP_32:
               case JTAG_LOAD_VARA:
               case JTAG_LOAD_VARB:
               case JTAG_DEBUG_ON:
               case JTAG_DEBUG_OFF:
               case JTAG_SHIFT_OUT_DP_VARA:
               case JTAG_SKIP_DP:
                  break;

               default:
                  print("Unhandled opcode in skipSequence = %d, SP=%d\n", opcode, sequence-sequenceStart);
                  break;

               case JTAG_SHIFT_IN_OUT_VARA:
               case JTAG_SHIFT_IN_OUT_VARB:
                  temp = (uint8_t)BITS_TO_BYTES(*++sequence);
                  sequence += temp; // Skip over inline data
                  break;
               case JTAG_SET_PADDING:  // #HDR,#HIR,#TDR,#TIR
                  sequence += 5; // Skip numBits
                  break;
            }
            break;
         case JTAG_SHIFT_OUT_Q(0) :
         case JTAG_SHIFT_IN_OUT_Q(0) :
//            print("JTAG_SHIFT_OUT_Q(%d) SP=%d\n", numBits, sequence-sequenceStart);
            sequence += BITS_TO_BYTES(numBits); // Skip over inline data
//            print("JTAG_SHIFT_OUT_Q(%d) SP=%d\n", numBits, sequence-sequenceStart);
            break;
         case JTAG_REPEAT_Q(0):
            loopDepth++;
            break;
         case JTAG_SHIFT_IN_Q(0) :
         case JTAG_PUSH_Q(0):
            break;
         default:
            print("Unhandled opcode in skipSequence = %d, SP=%d\n", opcode, sequence-sequenceStart);
            break;
      }
      sequence++;
   };
//   return sequence;
}

//! Maximum size subroutine that can be cached
#define MAX_CACHE (64)

static const uint8_t *sequence;
static const uint8_t *dataOutPtr;
static const uint8_t *subPtrs[]  = {NULL, NULL, NULL, NULL};
static       uint8_t subroutineCache[MAX_CACHE];

typedef struct {
   const uint8_t* startOfLoop;
   uint16_t       iterator;
} RepeatInformation;

typedef struct {
   const uint8_t           *returnAddress;
   RepeatInformation  *repeatTOS;
} SubroutineInformation;

uint8_t                   complete          = false;
uint8_t                   inFill            = JTAG_WRITE_1;
JTAG_ExitActions_t   exitAction        = JTAG_EXIT_IDLE;
USBDM_ErrorCode      rc                = BDM_RC_OK;
uint32_t                  variables[4]      = {0,0,0,0};
uint16_t                  iterator          = 0;
const uint8_t             *startOfIteration = NULL;
uint32_t                  tempValue = 0;
uint8_t                   *dataInPtr;

RepeatInformation       repeatStack[6] = {{NULL,0}};
RepeatInformation       *repeatTOS = repeatStack;

SubroutineInformation   subroutineStack[4] = {{NULL, NULL}};
SubroutineInformation   *subroutineTOS = subroutineStack;
uint8_t opcode;
uint8_t numBits;
uint8_t regNo;
int adjustment;


USBDM_ErrorCode executeTargetInstructionSequence(const uint8_t **dataOutPtr) {
USBDM_ErrorCode rc = BDM_RC_OK;
static const uint8_t enableONCECommand[] = {CORE_ENABLE_ONCE_COMMAND};
static const uint8_t writeOpcode[]       = {OPDBR_ADDRESS|ONCE_CMD_WRITE};
static const uint8_t writeOpcodeAndGo[]  = {OPDBR_ADDRESS|ONCE_CMD_WRITE|ONCE_CMD_GO};
uint8_t onceStatus;
uint8_t numberOfInstructions;
uint8_t retry;

//   print("executeTargetInstructionSequence()\n");
   rc = USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
   numberOfInstructions = *(*dataOutPtr)++;
   print("executeTargetInstructionSequence(#=%d)\n", numberOfInstructions);
   do {
      uint8_t numWords = *(*dataOutPtr)++;
      rc = USBDM_JTAG_Write(JTAG_CORE_COMMAND_LENGTH, JTAG_EXIT_SHIFT_DR, enableONCECommand);
      print("executeTargetInstructionSequence(#%d) : ", numberOfInstructions);
      do {
         uint16_t opcode = ((**dataOutPtr)<<8) + (*(*dataOutPtr+1));
         if (numWords>1) {
            print("0x%4.4X, ", opcode);
            rc = USBDM_JTAG_Write(ONCE_CMD_LENGTH, JTAG_EXIT_SHIFT_DR, writeOpcode);
            rc = USBDM_JTAG_Write(16, JTAG_EXIT_SHIFT_DR, (*dataOutPtr));
         }
         else {
            print("0x%4.4X\n", opcode);
            rc = USBDM_JTAG_Write(ONCE_CMD_LENGTH, JTAG_EXIT_SHIFT_DR, writeOpcodeAndGo);
            rc = USBDM_JTAG_Write(16, JTAG_EXIT_SHIFT_IR, (*dataOutPtr));
         }
         (*dataOutPtr) += 2;
      } while (--numWords>0);
   } while (--numberOfInstructions>0);
   rc = USBDM_JTAG_Write(JTAG_CORE_COMMAND_LENGTH, JTAG_EXIT_SHIFT_IR, enableONCECommand);
   rc = USBDM_JTAG_Write(JTAG_CORE_COMMAND_LENGTH, JTAG_EXIT_SHIFT_IR, enableONCECommand);
   retry = 100;
   do {
      rc = USBDM_JTAG_ReadWrite(JTAG_CORE_COMMAND_LENGTH, JTAG_EXIT_SHIFT_IR, enableONCECommand, &onceStatus);
   }  while ((onceStatus != TARGET_STATUS_DEBUG) && (retry-->0));
   // Move to IDLE
   rc = USBDM_JTAG_Write(JTAG_CORE_COMMAND_LENGTH, JTAG_EXIT_IDLE, enableONCECommand);

   if (onceStatus == TARGET_STATUS_DEBUG)
      return BDM_RC_OK;
   if (onceStatus == TARGET_STATUS_STOP)
      return BDM_RC_TARGET_BUSY;
   if (onceStatus == TARGET_STATUS_EXECUTE)
      return BDM_RC_TARGET_BUSY;
   if (onceStatus == TARGET_STATUS_EX_ACCESS)
      return BDM_RC_TARGET_BUSY;
   if (onceStatus == TARGET_STATUS_STOP)
      return BDM_RC_TARGET_BUSY;
   return BDM_RC_NO_CONNECTION;
}

//! Obtains an 8-bit data value from the instruction stream or
//! data stream as required.
//!
static uint8_t getValueByte(uint8_t value) {
   if ((value == 0) && (dataOutPtr != NULL)) {
      // If zero get value from dataOutPtr
      value = *dataOutPtr++;
   }
   return value;
}

//! @param sequenceLength - length of sequence (including dataOut)
//! @param sequenceStart  - start of sequence
//! @param dataInLength   - expected length of input data
//! @param dataInStart    - buffer for dataIn
//!

USBDM_ErrorCode debugExecuteJTAGSequence(uint8_t        sequenceLength,
                                         const uint8_t *sequenceStart,
                                         uint8_t        dataInLength,
                                         uint8_t       *dataInStart) {

   complete          = false;
   inFill            = JTAG_WRITE_1;
   exitAction        = JTAG_EXIT_IDLE;
   rc                = BDM_RC_OK;
   iterator          = 0;
   startOfIteration  = NULL;
   tempValue         = 0;
int                  indent            = 6;

   dataInPtr         = dataInStart;                         // Save start of dataIn

   sequence          = sequenceStart;                       // Point to command sequence
   dataOutPtr        = skipSequence(sequence, STOP_ON_END, &indent); // Point to data out sequence
   print("executeJTAGSequence()- DP=%d\n =>", dataOutPtr-sequenceStart);
   if (*dataOutPtr == JTAG_END)
      dataOutPtr++;
   print("executeJTAGSequence()- DP=%d\n =>", dataOutPtr-sequenceStart);

   print("\nexecuteJTAGSequence() =>\n");
   listJTAGSequence(sequenceLength, sequenceStart);

   print("executeJTAGSequence(seqLength = %d, sequence=%d, dataOutPtr=%d, dataInPtr=%d) \n",
         sequenceLength,
         (sequence==NULL)?0:(sequence-sequenceStart),
         (dataOutPtr==NULL)?0:(dataOutPtr-sequenceStart),
         (dataInPtr==NULL)?0:(dataInPtr-dataInStart));

   indent = 6;
   do {
      int lineNumber;
      if ((sequence>=sequenceStart) && (sequence<(sequenceStart+sequenceLength)))
         lineNumber = sequence-sequenceStart;
      else if ((sequence>=subroutineCache) && (sequence<(subroutineCache+sizeof(subroutineCache))))
         lineNumber = -(sequence-subroutineCache);
      else {
         print("%-*d: Illegal sequence ptr = %d\n", indent, lineNumber, sequence-sequenceStart);
         rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
      }
      if ((sequence>=sequenceStart) && (sequence<(sequenceStart+sequenceLength)))
         lineNumber = sequence-sequenceStart;
      else if ((sequence>=subroutineCache) && (sequence<(subroutineCache+sizeof(subroutineCache))))
         lineNumber = -(sequence-subroutineCache);
      if (dataOutPtr>sequenceStart+sequenceLength) {
         print("%-*d: Illegal dataOut ptr = %d\n", indent, lineNumber, sequence-sequenceStart);
         rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
      }

      opcode      = *sequence++;
      numBits     = (opcode&JTAG_NUM_BITS_MASK);   // In case needed
      regNo       = numBits & 0x03;                // In case needed
      if (numBits == 0)
         numBits = 32;

      switch (opcode&JTAG_COMMAND_MASK) {
         case JTAG_MISC0: // Misc commands
         case JTAG_MISC1: // Misc commands
            switch (opcode) {
               case JTAG_DEBUG_ON:
                  print("%-*d: JTAG_DEBUG_ON\n", indent, lineNumber);
                  enableLogging(true);
                  break;
               case JTAG_DEBUG_OFF:
                  print("%-*d: JTAG_DEBUG_OFF\n", indent, lineNumber);
                  enableLogging(false);
                  break;
               case JTAG_TEST_LOGIC_RESET:
                  print("%-*d: JTAG_TEST_LOGIC_RESET\n", indent, lineNumber);
                  rc = USBDM_JTAG_Reset();
                  break;
               case JTAG_MOVE_DR_SCAN:
                  print("%-*d: JTAG_MOVE_DR_SCAN\n", indent, lineNumber);
                  rc = USBDM_JTAG_SelectShift(JTAG_SHIFT_DR);
                  break;
               case JTAG_MOVE_IR_SCAN:
                  print("%-*d: JTAG_MOVE_IR_SCAN\n", indent, lineNumber);
                  rc = USBDM_JTAG_SelectShift(JTAG_SHIFT_IR);
                  break;
               case JTAG_SET_STAY_SHIFT:
                  print("%-*d: JTAG_SET_STAY_SHIFT\n", indent, lineNumber);
                  exitAction = JTAG_STAY_SHIFT;
                  break;
               case JTAG_SET_EXIT_SHIFT_DR:
                  print("%-*d: JTAG_SET_EXIT_SHIFT_DR\n", indent, lineNumber);
                  exitAction = JTAG_EXIT_SHIFT_DR;
                  break;
               case JTAG_SET_EXIT_SHIFT_IR:
                  print("%-*d: JTAG_SET_EXIT_SHIFT_IR\n", indent, lineNumber);
                  exitAction = JTAG_EXIT_SHIFT_IR;
                  break;
               case JTAG_SET_EXIT_IDLE:
                  print("%-*d: JTAG_SET_EXIT_IDLE\n", indent, lineNumber);
                  exitAction = JTAG_EXIT_IDLE;
                  break;
               case JTAG_SET_IN_FILL_0:
                  print("%-*d: JTAG_SET_IN_FILL_0\n", indent, lineNumber);
                  inFill = JTAG_WRITE_0;
                  break;
               case JTAG_SET_IN_FILL_1:
                  print("%-*d: JTAG_SET_IN_FILL_1\n", indent, lineNumber);
                  inFill = JTAG_WRITE_1;
                  break;
               case JTAG_SAVE_SUB:
                  // Save subroutine to cache
                  adjustment = subroutineCache-sequenceStart;
                  if ((unsigned)(sequence-sequenceStart) > sizeof(subroutineCache))
                     rc = BDM_RC_JTAG_TOO_LARGE;
                  else {
                     (void)memcpy(subroutineCache, sequenceStart, sequence-sequenceStart);
                     subPtrs[0] += adjustment;
                     subPtrs[1] += adjustment;
                     subPtrs[2] += adjustment;
                     subPtrs[3] += adjustment;
                     print("%-*d: JTAG_SAVE_SUB\n", indent, lineNumber);
                     complete = true;
                  }
                  break;

                  break;
               case JTAG_SUBA:
               case JTAG_SUBB:
               case JTAG_SUBC:
               case JTAG_SUBD:
                  print("%-*d: JTAG_SUB%c - start addr=%d\n", indent,
                        lineNumber, 'A'+(opcode&0x03), sequence-sequenceStart);
                  subPtrs[regNo] = sequence;
                  // Skip over subroutine
                  sequence = skipSequence(sequence, STOP_ON_SUB, &indent);
                  break;
               case JTAG_CALL_SUBA:
                  print("%-*d: JTAG_CALL_SUBA*\n", indent, lineNumber);
                  executeTargetInstructionSequence(&dataOutPtr);
                  break;
               case JTAG_CALL_SUBB:
               case JTAG_CALL_SUBC:
               case JTAG_CALL_SUBD:
                  // Save iterators from parent
                  repeatTOS->iterator    = iterator;
                  repeatTOS->startOfLoop = startOfIteration;
                  repeatTOS++;
                  subroutineTOS->repeatTOS     = repeatTOS;
                  subroutineTOS->returnAddress = sequence;
                  subroutineTOS++;
                  sequence       = subPtrs[regNo];
                  print("%-*d: JTAG_CALL_SUB%c, call addr=%d, dataOutPtr = %d(0x%X), iterator = %d\n", indent,
                        lineNumber, 'A'+(opcode&0x03), sequence-sequenceStart,
                        dataOutPtr-sequenceStart, dataOutPtr-sequenceStart, iterator);
                  print("%-*d: repeatTOS                = %p\n", indent, lineNumber, repeatTOS);
                  print("%-*d: (subroutineTOS-1)->repeatTOS = %p\n", indent, lineNumber, (subroutineTOS-1)->repeatTOS);
                  print("%-*d: repeatStack              = %p\n", indent, lineNumber, repeatStack);
                  print("%-*d: subroutineTOS            = %p\n", indent, lineNumber, subroutineTOS);
                  print("%-*d: subroutineStack          = %p\n", indent, lineNumber, subroutineStack);
                  indent+=3;
                  break;
               case JTAG_BREAK:
                  iterator = 1;
                  print("%-*d: JTAG_BREAK...\n", indent, lineNumber);
                  // Fall through
               case JTAG_CONTINUE:
                  print("%-*d: JTAG_CONTINUE...\n", indent, lineNumber);
                  sequence = skipSequence(sequence, STOP_ON_END_REPEAT|STOP_ON_SUB, &indent);
                  break;
               case JTAG_END_REPEAT:
                  // Check if unmatched
                  if (((subroutineTOS != subroutineStack) && (repeatTOS == (subroutineTOS-1)->repeatTOS )) ||
                      (repeatTOS == repeatStack)) {
                     rc = BDM_RC_JTAG_UNMATCHED_REPEAT;
                     print("%-*d: JTAG_END_REPEAT unexpected\n", indent, lineNumber);
                     print("%-*d: repeatTOS                = %p\n", indent, lineNumber, repeatTOS);
                     print("%-*d: subroutineTOS->repeatTOS = %p\n", indent, lineNumber, subroutineTOS->repeatTOS);
                     print("%-*d: repeatStack              = %p\n", indent, lineNumber, repeatStack);
                     print("%-*d: subroutineTOS            = %p\n", indent, lineNumber, subroutineTOS);
                     print("%-*d: subroutineStack          = %p\n", indent, lineNumber, subroutineStack);
                  }
                  else if (--iterator<=0) {
                     // End of loop - cleanup
                     repeatTOS--;
                     iterator         = repeatTOS->iterator;
                     startOfIteration = repeatTOS->startOfLoop;
                     indent-=3;
                     print("%-*d: JTAG_END_REPEAT leaving loop\n", indent, lineNumber);
                  }
                  else {
                     sequence = startOfIteration;
                     print("%-*d: JTAG_END_REPEAT #%d, addr=%d\n", indent, lineNumber, iterator, sequence-sequenceStart);
                  }
                  break;
               case JTAG_ELSE: // Skip to JTAG_END_IF
                  indent-=3;
                  print("%-*d: JTAG_ELSE\n", indent, lineNumber);
                  indent+=3;
                  sequence = skipSequence(sequence, STOP_ON_END_IF|STOP_ON_SUB, &indent);
                  break;
               case JTAG_END_IF:
                  indent-=3;
                  print("%-*d: JTAG_END_IF\n", indent, lineNumber);
                  break;
               case JTAG_NOP:
                  print("%-*d: JTAG_NOP\n", indent, lineNumber);
                  break;
               case JTAG_SKIP_DP:   // Skip over N bytes in data Out sequence
                  print("%-*d: JTAG_SKIP_DP(%d)", indent, lineNumber, tempValue);
                  dataOutPtr += tempValue;
                  print(" New DP=%d\n",dataOutPtr-sequenceStart);
                  break;
               case JTAG_END:
                  indent-=3;
                  print("%-*d: JTAG_END - end of sequence\n", indent, lineNumber);
                  complete = true;
                  break;
               case JTAG_RETURN:
                  print("%-*d: JTAG_RETURN...\n", indent, lineNumber);
                  // End of subroutine
                  // Fall through
               case JTAG_END_SUB:
                  indent-=3;
                  if (subroutineTOS == subroutineStack) {
                     print("%-*d: JTAG_END_SUB/RETURN - stack underflow, DP=%d(0x%X)\n", indent,
                           lineNumber, dataOutPtr-sequenceStart, dataOutPtr-sequenceStart);
                     rc = BDM_RC_JTAG_STACK_ERROR;
                  }
                  else {
                     subroutineTOS--;
                     sequence  = subroutineTOS->returnAddress;
                     repeatTOS = subroutineTOS->repeatTOS;
                     // restore parent iterator state
                     repeatTOS--;
                     iterator         = repeatTOS->iterator;
                     startOfIteration = repeatTOS->startOfLoop;

                     print("%-*d: JTAG_END_SUB/RETURN - returning, return addr=%d, DP=%d(0x%X)\n", indent,
                           lineNumber, sequence-sequenceStart,
                           dataOutPtr-sequenceStart, dataOutPtr-sequenceStart);
                     print("%-*d: repeatTOS                = %p\n", indent, lineNumber, repeatTOS);
                     print("%-*d: subroutineTOS->repeatTOS = %p\n", indent, lineNumber, subroutineTOS->repeatTOS);
                     print("%-*d: repeatStack              = %p\n", indent, lineNumber, repeatStack);
                     print("%-*d: subroutineTOS            = %p\n", indent, lineNumber, subroutineTOS);
                     print("%-*d: subroutineStack          = %p\n", indent, lineNumber, subroutineStack);
                  }
                  break;
               case JTAG_SHIFT_OUT_DP_VARA:
                  numBits = tempValue;
                  if (dataOutPtr == NULL) {
                     // Requires data out ptr.
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_OUT_DP_VARA(N) No output buffer\n", indent, lineNumber);
                  }
                  else if (numBits == 0) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_OUT_DP_VARA(0) - Illegal repeat count!\n", indent, lineNumber);
                  }
                  else {
                     print("%-*d: JTAG_SHIFT_OUT_DP_VARA (=%d) => ", indent, lineNumber, numBits);
                     printBits(numBits, dataOutPtr);
                     rc = USBDM_JTAG_Write(numBits, exitAction, dataOutPtr);
                     dataOutPtr += BITS_TO_BYTES(numBits);
                  }
                  break;
               case JTAG_SHIFT_OUT_DP : // Shift sequence out - sequence taken from dataOutPtr
                  numBits = getValueByte(*sequence++);
                  if (dataOutPtr == NULL) {
                     // Requires data out ptr.
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_OUT_DP(N) No output buffer\n", indent, lineNumber);
                  }
                  else if (numBits == 0) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_OUT_DP(0) - Illegal repeat count!\n", indent, lineNumber);
                  }
                  else {
                     print("%-*d: JTAG_SHIFT_OUT_DP (%d) => ", indent, lineNumber, numBits);
                     printBits(numBits, dataOutPtr);
                     rc = USBDM_JTAG_Write(numBits, exitAction, dataOutPtr);
                     dataOutPtr += BITS_TO_BYTES(numBits);
                  }
                  break;
               case JTAG_SHIFT_IN_DP : // Shift sequence in (8-bit count)/TL
                  numBits = getValueByte(*sequence++);
                  if (dataInPtr == NULL) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_TL(N) - No input buffer!\n", indent, lineNumber);
                  }
                  else if (numBits == 0) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_TL(0) - Illegal repeat count!\n", indent, lineNumber);
                  }
                  else {
                     rc = USBDM_JTAG_Read(numBits, exitAction|inFill, dataInPtr);
                     print("%-*d: JTAG_SHIFT_IN_TL (%d) <= ", indent, lineNumber, numBits);
                     printBits(numBits, dataInPtr);
                     dataInPtr += BITS_TO_BYTES(numBits);
                  }
                  break;
               case JTAG_SHIFT_IN_OUT_DP : // Shift sequence in & out at same time - sequence taken from dataOutPtr
                  numBits = getValueByte(*sequence++);
                  if (dataOutPtr == NULL) {
                     // Requires data out ptr.
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_OUT_TL(N) No output buffer\n", indent, lineNumber);
                  }
                  else if (dataInPtr == NULL) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_OUT_TL(N) - No input buffer!\n", indent, lineNumber);
                  }
                  else if (numBits == 0) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_OUT_TL(0) - Illegal repeat count!\n", indent, lineNumber);
                  }
                  else {
                     print("%-*d: JTAG_SHIFT_IN_OUT_TL (%d) => ", indent, lineNumber, numBits);
                     printBits(numBits, dataOutPtr);
                     rc = USBDM_JTAG_ReadWrite(numBits, exitAction, dataOutPtr, dataInPtr);
                     print("%-*d:                      (%d) <= ", indent, lineNumber, numBits);
                     printBits(numBits, dataInPtr);
                     dataOutPtr     += BITS_TO_BYTES(numBits);
                     dataInPtr      += BITS_TO_BYTES(numBits);
                  }
                  break;
               case JTAG_IF_VARA_EQ:  // IF statement testing variable A/B == value
               case JTAG_IF_VARB_EQ:
                  print("%-*d: JTAG_IF_VAR%c_EQ var=%d, value=%d\n", indent, lineNumber, 'A'+(opcode&3), (uint32_t)variables[opcode&3], (uint32_t)tempValue);
                  indent+=3;
                  if (variables[regNo] != tempValue) { // Fail => skip to ELSE/END_IF clause
                     sequence = skipSequence(sequence, STOP_ON_ELSE|STOP_ON_END_IF|STOP_ON_SUB, &indent);
                  }
                  if (*sequence == JTAG_ELSE)
                     sequence++;
                  break;
               case JTAG_IF_VARA_NEQ: // IF statement testing variable A/B != value
               case JTAG_IF_VARB_NEQ:
                  print("%-*d: JTAG_IF_VAR%c_NEQ var=%d, value=%d\n", indent, lineNumber, 'A'+(opcode&3), (uint32_t)variables[opcode&3], (uint32_t)tempValue);
                  indent+=3;
                  if (variables[regNo] == tempValue) { // Fail => skip to ELSE clause
                     sequence = skipSequence(sequence, STOP_ON_ELSE|STOP_ON_END_IF|STOP_ON_SUB, &indent);
                  }
                  if (*sequence == JTAG_ELSE)
                     sequence++;
                  break;
               case JTAG_IF_ITER_EQ:
                  print("%-*d: JTAG_IF_ITER_EQ iterator=%d, value=%d\n", indent, lineNumber, iterator, (uint32_t)tempValue);
                  indent+=3;
                  if (iterator != tempValue) { // Fail => skip to ELSE clause
                     sequence = skipSequence(sequence, STOP_ON_ELSE|STOP_ON_END_IF|STOP_ON_SUB, &indent);
                  }
                  if (*sequence == JTAG_ELSE)
                     sequence++;
                  break;
               case JTAG_IF_ITER_NEQ:
                  print("%-*d: JTAG_IF_ITER_NEQ iterator=%d, value=%d\n", indent, lineNumber, iterator, (uint32_t)tempValue);
                  indent+=3;
                  if (iterator == tempValue) { // Fail => skip to ELSE clause
                     sequence = skipSequence(sequence, STOP_ON_ELSE|STOP_ON_END_IF|STOP_ON_SUB, &indent);
                  }
                  if (*sequence == JTAG_ELSE)
                     sequence++;
                  break;
               case JTAG_REPEAT8:
                  tempValue = *sequence++;
                  // Fall through
               case JTAG_REPEAT:
                  if (tempValue == 0) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_REPEAT(%d) - Illegal repeat count!\n", indent, lineNumber, tempValue);
                  }
                  else {
                     repeatTOS->iterator    = iterator;
                     repeatTOS->startOfLoop = startOfIteration;
                     repeatTOS++;
                     iterator               = (uint16_t)tempValue; // Assumes value set previously (e.g. push)
                     startOfIteration       = sequence;
                     print("%-*d: JTAG_REPEAT(%d)\n", indent, lineNumber, iterator);
                     indent+=3;
                  }
                  break;
//               case JTAG_SHIFT_IN_VARA: // Set variable from TDO, default TDI
//               case JTAG_SHIFT_IN_VARB:
//                  numBits = getValueByte(*sequence++);
//                  if ((numBits == 0) || (numBits > 32)) {
//                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
//                     print("%-*d: JTAG_SHIFT_IN_VAR%c(%d) - Illegal repeat count!\n", indent, lineNumber, 'A'+(opcode&0x3), numBits);
//                  }
//                  else {
//                     JTAG32 temp(0,32);
//                     rc = USBDM_JTAG_Read(numBits, exitAction|inFill, temp.getData(numBits));
//                     print("%-*d: JTAG_SHIFT_IN_VAR%c (%d) varA <= %s", indent, lineNumber, 'A'+(opcode&0x3), numBits);
//                     printBits(numBits, temp.getData(BITS_TO_BYTES(numBits)));
//                     variables[opcode&0x3] = temp;
//                  }
//                  break;
               case JTAG_SHIFT_OUT_VARA: // Shift out VarA/B to TDI, TDO discarded
               case JTAG_SHIFT_OUT_VARB:
               case JTAG_SHIFT_OUT_VARC:
               case JTAG_SHIFT_OUT_VARD:
                  numBits = getValueByte(*sequence++);
                  if ((numBits == 0) || (numBits > 32)) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_OUT_VAR%c(%d) - Illegal repeat count!\n", indent, lineNumber, 'A'+(opcode&0x3), numBits);
                  }
                  else {
                     JTAG32 temp(variables[opcode&0x3],32);
                     print("%-*d: JTAG_SHIFT_OUT_VAR%c(%d) => ", indent, lineNumber, 'A'+(opcode&0x3), numBits);
                     printBits(numBits, sequence);
                     rc = USBDM_JTAG_Write(numBits, exitAction, temp.getData(numBits));
                  }
                  break;
               case JTAG_SHIFT_IN_OUT_VARA: // Set variable from TDO with TDI values from sequence
               case JTAG_SHIFT_IN_OUT_VARB:
               case JTAG_SHIFT_IN_OUT_VARC:
               case JTAG_SHIFT_IN_OUT_VARD:
                  numBits = getValueByte(*sequence++);
                  if ((numBits == 0) || (numBits > 32)) {
                     rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                     print("%-*d: JTAG_SHIFT_IN_OUT_VAR%c(%d) - Illegal repeat count!\n", indent, lineNumber, 'A'+(opcode&0x3), numBits);
                  }
                  else {
                     JTAG32 temp(0,32);
                     print("%-*d: JTAG_SHIFT_IN_OUT_VAR%c(%d) => ", indent, lineNumber, 'A'+(opcode&0x3), numBits);
                     printBits(numBits, sequence);
                     rc = USBDM_JTAG_ReadWrite(numBits, exitAction, sequence, temp.getData(numBits));
                     print("%-*d:                        (%d) <= ", indent, lineNumber, numBits);
                     printBits(numBits, temp.getData(BITS_TO_BYTES(numBits)));
                     variables[opcode&0x3] = temp;
                     sequence += BITS_TO_BYTES(numBits);
                  }
                  break;
               case JTAG_SET_ERROR:    // Set error variable & exit
                  rc = (USBDM_ErrorCode)getValueByte(*sequence++);
                  print("%-*d: JTAG_SET_ERROR error <= %s\n", indent, lineNumber, USBDM_GetErrorString(rc));
                  break;
               case JTAG_PUSH8:
                  tempValue = *sequence++;
                  if (tempValue<32) {
                     print("%-*d: JTAG_PUSH_8(%d, 0x%2.2X) - Warning - Use JTAG_PUSH_Q()\n", indent, lineNumber, (uint32_t)tempValue, (uint32_t)tempValue);
                  }
                  else
                     print("%-*d: JTAG_PUSH_8(%d, 0x%2.2X)\n", indent, lineNumber, (uint32_t)tempValue, (uint32_t)tempValue);
                  break;
               case JTAG_PUSH16:
                  tempValue = *sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  if (tempValue<=0xFFFFUL) {
                     print("%-*d: JTAG_PUSH_16(%d, 0x%4.4X) - Warning - Use JTAG_PUSH_Q/8()\n", indent, lineNumber, (uint32_t)tempValue, (uint32_t)tempValue);
                  }
                  else
                     print("%-*d: JTAG_PUSH_16(0x%4.4X)\n", indent, lineNumber, (uint32_t)tempValue);
                  break;
               case JTAG_PUSH32:
                  tempValue = *sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  if (tempValue<=0xFFFFUL) {
                     print("%-*d: JTAG_PUSH_32(%d, 0x%8.8X) - Warning - Use JTAG_PUSH_Q/8/16()\n", indent, lineNumber, (uint32_t)tempValue, (uint32_t)tempValue);
                  }
                  else
                     print("%-*d: JTAG_PUSH_32(0x%8.8X)\n", indent, lineNumber, (uint32_t)tempValue);
                  break;
               case JTAG_PUSH_DP_8:
                  tempValue = *dataOutPtr++;
                  print("%-*d: JTAG_PUSH_DP_8(DP=%d, %d, 0x%2.2X)\n", indent, lineNumber, dataOutPtr-sequenceStart, (uint32_t)tempValue, (uint32_t)tempValue);
                  break;
               case JTAG_PUSH_DP_16:
                  tempValue = *dataOutPtr++;
                  tempValue = (tempValue<<8)+*dataOutPtr++;
                  print("%-*d: JTAG_PUSH_DP_16(dptr=%d, 0x%4.4X)\n", indent, lineNumber, dataOutPtr-sequenceStart, (uint32_t)tempValue);
                  break;
               case JTAG_PUSH_DP_32:
                  tempValue = *dataOutPtr++;
                  tempValue = (tempValue<<8)+*dataOutPtr++;
                  tempValue = (tempValue<<8)+*dataOutPtr++;
                  tempValue = (tempValue<<8)+*dataOutPtr++;
                  print("%-*d: JTAG_PUSH_DP_32(dptr=%d, 0x%8.8X)\n", indent, lineNumber, dataOutPtr-sequenceStart, (uint32_t)tempValue);
                  break;
               case JTAG_SAVE_OUT_DP_VARC:
               case JTAG_SAVE_OUT_DP_VARD:
                  print("%-*d: JTAG_SAVE_DP_VAR%c DP=%d\n", indent, lineNumber, 'A'+(opcode&0x03), dataOutPtr-sequenceStart);
                  variables[regNo] = dataOutPtr-sequenceStart;
                  break;
               case JTAG_RESTORE_DP_VARC:
               case JTAG_RESTORE_DP_VARD:
                  dataOutPtr = variables[regNo]+sequenceStart;
                  print("%-*d: JTAG_RESTORE_DP_VAR%c DP=%d\n", indent, lineNumber, 'A'+(opcode&0x03), dataOutPtr-sequenceStart);
                  break;
               case JTAG_LOAD_VARA:
               case JTAG_LOAD_VARB:
                  variables[regNo] = tempValue;
                  print("%-*d: JTAG_LOAD_VAR%c(%d, 0x%X)\n", indent, lineNumber, 'A'+(opcode&0x03), tempValue, tempValue);
                  break;
               default:
                  print("%-*d: Unknown opcode = %d\n", indent, lineNumber, opcode);
                  rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
                  break;
            }
            break;
         case JTAG_REPEAT_Q(0):
            repeatTOS->iterator    = iterator;
            repeatTOS->startOfLoop = startOfIteration;
            repeatTOS++;
            iterator  = numBits;
            if (iterator==1) {
               // Value of 1 indicates use dataOut value
               iterator = *dataOutPtr;
               print("%-*d: JTAG_REPEAT_DP #%d, DP=%d\n", indent, lineNumber, iterator, dataOutPtr-sequenceStart);
               indent+=3;
               dataOutPtr++;
            }
            else {
               print("%-*d: JTAG_REPEAT_Q(%d)\n", indent, lineNumber, iterator);
               indent+=3;
            }
            if (iterator == 0) {
               rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
               print("%-*d: JTAG_REPEAT_DP #0 - Illegal repeat count!\n", indent, lineNumber);
            }
            else {
               startOfIteration       = sequence;
            }
            break;
         case JTAG_SHIFT_IN_Q(0) : // Shift sequence in (5-bit count)
            if (dataInPtr == NULL) {
               rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
               print("%-*d: JTAG_SHIFT_IN_Q(%d) - no input buffer!\n", indent, lineNumber, numBits);
            }
            else {
               rc = USBDM_JTAG_Read(numBits, exitAction|inFill, dataInPtr);
               print("%-*d: JTAG_SHIFT_IN_Q(%d) <= ", indent, lineNumber, numBits);
               printBits(numBits, dataInPtr);
               dataInPtr   += BITS_TO_BYTES(numBits);
            }
            break;
         case JTAG_SHIFT_OUT_Q(0) : // Shift sequence out (5-bit count) - sequence taken inline
            print("%-*d: JTAG_SHIFT_OUT_Q(%d) => ", indent, lineNumber, numBits);
            printBits(numBits, sequence);
            rc = USBDM_JTAG_Write(numBits, exitAction, sequence);
            sequence += BITS_TO_BYTES(numBits);
            break;
         case JTAG_SHIFT_IN_OUT_Q(0) : // Shift sequence in & out at same time - sequence taken inline
            if (dataInPtr == NULL) {
               rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
               print("%-*d: JTAG_SHIFT_IN_OUT_Q(%d) - no input buffer!\n", indent, lineNumber, numBits);
            }
            else {
               print("%-*d: JTAG_SHIFT_IN_OUT_Q(%d) => ", indent, lineNumber, numBits);
               printBits(numBits, sequence);
               rc = USBDM_JTAG_ReadWrite(numBits, exitAction, sequence, dataInPtr);
               print("%-*d:                    (%d) <= ", indent, lineNumber, numBits);
               printBits(numBits, dataInPtr);
               sequence   += BITS_TO_BYTES(numBits);
               dataInPtr     += BITS_TO_BYTES(numBits);
            }
            break;
         case JTAG_PUSH_Q(0): // Push a 5-bit value
            tempValue = opcode&JTAG_NUM_BITS_MASK;
            print("%-*d: JTAG_PUSH_Q(%d, 0x%X)\n", indent, lineNumber, (uint32_t)tempValue, (uint32_t)tempValue);
            break;
         default:
            print("%-*d: Unknown opcode = %d\n", indent, lineNumber, opcode);
            rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
            break;
      }

      // Bounds check ptrs
      if (dataInPtr > dataInStart+dataInLength) {    // Input buffer overflow
         print("%-*d: Illegal dataIn ptr = %d\n", indent, lineNumber, dataOutPtr-sequenceStart);
         rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
      }
      if (indent>30)
         indent -= 30;
      if (indent<0)
         indent += 30;
   } while (!complete && (rc == BDM_RC_OK));

   if ((dataInPtr-dataInStart) != dataInLength) {
      rc = BDM_RC_JTAG_ILLEGAL_SEQUENCE;
      print("executeJTAGSequence(inLength=%d), input length mismatch, actual=%d)\n", dataInLength, dataInPtr-dataInStart);
   }
   if (rc != BDM_RC_OK) {
      print("executeJTAGSequence() - error, reason = %s\n", USBDM_GetErrorString(rc));
   }
   return rc;
}

#endif

#ifdef LOG

void printBits(uint8_t numBits, const uint8_t *data) {
uint8_t bitCount  = 0;
uint8_t byteCount = 0;
uint8_t bitMask   = 1<<((numBits-1)%8);

   while (bitCount++ < numBits) {
      UsbdmSystem::Log::print("%c", (data[byteCount]&bitMask)?'1':'0');
      bitMask >>= 1;
      if (bitMask == 0) {
         UsbdmSystem::Log::print("(%2.2X), ", data[byteCount]);
         bitMask = (1<<7);
         byteCount++;
      }
   }
   UsbdmSystem::Log::print("\n");
}


void listJTAGSequence(uint8_t       sequenceLength,
                      const uint8_t *sequenceStart) {
uint32_t tempValue = 0;
uint32_t tempValue2;
int indent = 6;
const uint8_t *sequence = sequenceStart;
uint8_t complete = false;
USBDM_ErrorCode rc;

// print("Input Data --------------------------------------\n");
// UsbdmSystem::Log::printdump(sequenceStart,sequenceLength);

   do {
      uint8_t lineNumber  = sequence-sequenceStart;
      uint8_t opcode      = *sequence++;
      uint8_t numBits     = (opcode&JTAG_NUM_BITS_MASK);  // In case needed

      if (numBits == 0)
         numBits = 32;

      switch (opcode&JTAG_COMMAND_MASK) {
         case JTAG_MISC0: // Misc commands 0x00-0x1F
         case JTAG_MISC1: // Misc commands 0x20-0x3F
         case JTAG_MISC2: // Misc commands 0x40-0x5F
            switch (opcode) {
               case JTAG_SAVE_SUB:
                  UsbdmSystem::Log::print("%-*d JTAG_SAVE_SUB\n", indent, lineNumber);
                  break;
               case JTAG_DEBUG_ON:
                  UsbdmSystem::Log::print("%-*d JTAG_DEBUG_ON\n", indent, lineNumber);
                  break;
               case JTAG_DEBUG_OFF:
                  UsbdmSystem::Log::print("%-*d JTAG_DEBUG_OFF\n", indent, lineNumber);
                  break;
               case JTAG_TEST_LOGIC_RESET:
                  UsbdmSystem::Log::print("%-*d JTAG_TEST_LOGIC_RESET\n", indent, lineNumber);
                  break;
               case JTAG_MOVE_DR_SCAN:
                  UsbdmSystem::Log::print("%-*d JTAG_MOVE_DR_SCAN\n", indent, lineNumber);
                  break;
               case JTAG_MOVE_IR_SCAN:
                  UsbdmSystem::Log::print("%-*d JTAG_MOVE_IR_SCAN\n", indent, lineNumber);
                  break;
               case JTAG_SET_STAY_SHIFT:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_STAY_SHIFT\n", indent, lineNumber);
                  break;
               case JTAG_SET_EXIT_SHIFT_DR:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_EXIT_SHIFT_DR\n", indent, lineNumber);
                  break;
               case JTAG_SET_EXIT_SHIFT_IR:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_EXIT_SHIFT_IR\n", indent, lineNumber);
                  break;
               case JTAG_SET_EXIT_IDLE:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_EXIT_IDLE\n", indent, lineNumber);
                  break;
               case JTAG_SET_IN_FILL_0:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_IN_FILL_0\n", indent, lineNumber);
                  break;
               case JTAG_SET_IN_FILL_1:
                  UsbdmSystem::Log::print("%-*d JTAG_SET_IN_FILL_1\n", indent, lineNumber);
                  break;
               case JTAG_SUBA:
               case JTAG_SUBB:
               case JTAG_SUBC:
               case JTAG_SUBD:
                  UsbdmSystem::Log::print("%-*d JTAG_SUB%c\n",
                        indent, lineNumber, 'A'+(opcode&0x03));
                  indent+=3;
                  break;
               case JTAG_CALL_SUBA:
               case JTAG_CALL_SUBB:
               case JTAG_CALL_SUBC:
               case JTAG_CALL_SUBD:
                  UsbdmSystem::Log::print("%-*d JTAG_CALL_SUB%c\n",
                        indent, lineNumber, 'A'+(opcode&0x03));
                  break;
               case JTAG_BREAK:
                  UsbdmSystem::Log::print("%-*d JTAG_BREAK...\n", indent, lineNumber);
                  break;
               case JTAG_CONTINUE:
                  UsbdmSystem::Log::print("%-*d JTAG_CONTINUE...\n", indent, lineNumber);
                  break;
               case JTAG_END_REPEAT:
                  indent-=3;
                  UsbdmSystem::Log::print("%-*d JTAG_END_REPEAT...\n", indent, lineNumber);
                  break;
               case JTAG_ELSE: // Skip to JTAG_END_IF
                  indent-=3;
                  UsbdmSystem::Log::print("%-*d JTAG_ELSE\n", indent, lineNumber);
                  indent+=3;
                  break;
               case JTAG_END_IF:
                  indent-=3;
                  UsbdmSystem::Log::print("%-*d JTAG_END_IF\n", indent, lineNumber);
                  break;
               case JTAG_NOP:
                  UsbdmSystem::Log::print("%-*d JTAG_NOP\n", indent, lineNumber);
                  break;
               case JTAG_SKIP_DP:
                  UsbdmSystem::Log::print("%-*d JTAG_SKIP_DP(\?\?)\n", indent, lineNumber);
                  break;
               case JTAG_END:
                  indent-=3;
                  complete = true;
                  UsbdmSystem::Log::print("%-*d JTAG_END - end of sequence\n", indent, lineNumber);
                  break;
               case JTAG_RETURN:
                  UsbdmSystem::Log::print("%-*d JTAG_RETURN\n", indent, lineNumber);
                  break;
               case JTAG_END_SUB:
                  indent-=3;
                  UsbdmSystem::Log::print("%-*d JTAG_END_SUB\n", indent, lineNumber);
                  break;
               case JTAG_SHIFT_IN_DP : // Shift sequence in (8-bit count)/TL
                  numBits = *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_DP (%d)\n", indent, lineNumber, numBits);
                  break;
               case JTAG_SHIFT_OUT_DP_VARA:
                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_OUT_DP_VARA\n", indent, lineNumber);
                  break;
               case JTAG_SHIFT_OUT_DP : // Shift sequence out - sequence taken from dataOutPtr
                  numBits = *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_OUT_DP (%d)\n", indent, lineNumber, numBits);
                  break;
               case JTAG_SHIFT_IN_OUT_DP : // Shift sequence in & out at same time - sequence taken from dataOutPtr
                  numBits = *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_OUT_DP (%d)\n", indent, lineNumber, numBits);
                  break;
               case JTAG_IF_VARA_EQ: // IF statement testing variable A/B == value
//               case JTAG_IF_VARB_EQ:
                  UsbdmSystem::Log::print("%-*d JTAG_IF_VAR%c_EQ(%d)\n", indent, lineNumber, 'A'+(opcode&3), tempValue);
                  indent+=3;
                  break;
               case JTAG_IF_VARA_NEQ: // IF statement testing variable A/B != value
               case JTAG_IF_VARB_NEQ:
                  UsbdmSystem::Log::print("%-*d JTAG_IF_VAR%c_NEQ(%d)\n", indent, lineNumber, 'A'+(opcode&3), tempValue);
                  indent+=3;
                  break;
               case JTAG_IF_ITER_EQ:
                  UsbdmSystem::Log::print("%-*d JTAG_IF_ITER_EQ(%d)\n", indent, lineNumber, tempValue);
                  indent+=3;
                  break;
               case JTAG_IF_ITER_NEQ:
                  UsbdmSystem::Log::print("%-*d JTAG_IF_ITER_NEQ(%d)\n", indent, lineNumber, tempValue);
                  indent+=3;
                  break;
               case JTAG_REPEAT8:
                  tempValue = *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_REPEAT8(%d)\n", indent, lineNumber, tempValue);
                  indent+=3;
                  break;
               case JTAG_REPEAT:
                  UsbdmSystem::Log::print("%-*d JTAG_REPEAT(%d)\n", indent, lineNumber, tempValue);
                  indent+=3;
                  break;
               case JTAG_SHIFT_OUT_VARA: // Shift out VarA/B
               case JTAG_SHIFT_OUT_VARB:
                  numBits = *sequence++;
                  UsbdmSystem::Log::print("%-*d: JTAG_SHIFT_OUT_VAR%c(%d)\n", indent, lineNumber, 'A'+(opcode&0x3), numBits);
                  break;
//               case JTAG_SHIFT_IN_VARA:    // Set variable A from TDO
//               case JTAG_SHIFT_IN_VARB:    // Set variable A from TDO
//                  numBits = *sequence++;
//                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_VAR%c(%d)\n", indent, lineNumber, 'A'+(opcode&3), numBits);
//                  break;
//               case JTAG_SHIFT_IN_OUT_VARA:
//               case JTAG_SHIFT_IN_OUT_VARB:
//                  numBits = *sequence++;
//                  UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_OUT_VAR%c(%d) => ", indent, lineNumber, 'A'+(opcode&3), numBits);
//                  printBits(numBits, sequence);
//                  sequence += BITS_TO_BYTES(numBits);
//                  break;
               case JTAG_SET_ERROR:    // Set error variable & exit
                  rc = (USBDM_ErrorCode)*sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SET_ERROR error <= %s\n", indent, lineNumber, USBDM_GetErrorString(rc));
                  break;
               case JTAG_PUSH8:
                  tempValue = *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_8(%d, 0x%2.2X)\n", indent, lineNumber, tempValue, tempValue);
                  break;
               case JTAG_PUSH16:
                  tempValue = *sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_16(0x%4.4X)\n", indent, lineNumber, tempValue);
                  break;
               case JTAG_PUSH32:
                  tempValue = *sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  tempValue = (tempValue<<8)+*sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_32(0x%8.8X)\n", indent, lineNumber, tempValue);
                  break;
               case JTAG_PUSH_DP_8:
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_DP_8\n", indent, lineNumber);
                  break;
               case JTAG_PUSH_DP_16:
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_DP_16\n", indent, lineNumber);
                  break;
               case JTAG_PUSH_DP_32:
                  UsbdmSystem::Log::print("%-*d JTAG_PUSH_32\n", indent, lineNumber);
                  break;
               case JTAG_SAVE_OUT_DP_VARC:
               case JTAG_SAVE_OUT_DP_VARD:
                  UsbdmSystem::Log::print("%-*d JTAG_SAVE_DP_VAR%c\n", indent, lineNumber, 'A'+(opcode&3));
                  break;
               case JTAG_RESTORE_DP_VARC:
               case JTAG_RESTORE_DP_VARD:
                  UsbdmSystem::Log::print("%-*d JTAG_RESTORE_DP_VAR%c\n", indent, lineNumber, 'A'+(opcode&3));
                  break;
               case JTAG_LOAD_VARA:
               case JTAG_LOAD_VARB:
                  UsbdmSystem::Log::print("%-*d JTAG_LOAD_VAR%c(%d, 0x%X)\n", indent, lineNumber, 'A'+(opcode&3), tempValue, tempValue);
                  break;
               case JTAG_ARM_READAP:
                  numBits    = *sequence++;;
                  tempValue  = *sequence++<<24;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_ARM_READAPx (N=%d, A=0x%08X)\n", indent, lineNumber, numBits, tempValue);
                  break;
               case JTAG_ARM_WRITEAP:
                  numBits    = *sequence++;;
                  tempValue  = *sequence++<<24;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_ARM_WRITEAPx (N=%d, A=0x%08X)\n", indent, lineNumber, numBits, tempValue);
                  break;
               case JTAG_ARM_WRITEAP_I:
                  tempValue   = *sequence++<<24;
                  tempValue  += *sequence++;
                  tempValue2  = *sequence++<<24;
                  tempValue2 += *sequence++<<16;
                  tempValue2 += *sequence++<<8;
                  tempValue2 += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_ARM_WRITEAP_Ix (A=0x%08X, V=0x%08X)\n", indent, lineNumber, tempValue, tempValue2);
                  break;
               case JTAG_SET_PADDING:  // #Set HDR, HIR, TDR, TIR
                  tempValue  = *sequence++<<8;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SET_HDR(%d)\n", indent, lineNumber, tempValue);
                  tempValue  = *sequence++<<8;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SET_HIR(%d)\n", indent, lineNumber, tempValue);
                  tempValue  = *sequence++<<8;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SET_TDR(%d)\n", indent, lineNumber, tempValue);
                  tempValue  = *sequence++<<8;
                  tempValue += *sequence++;
                  UsbdmSystem::Log::print("%-*d JTAG_SET_TIR(%d)\n", indent, lineNumber, tempValue);
                  break;
               default:
                  UsbdmSystem::Log::print("%-*d Unknown Opcode (%d)\n", indent, lineNumber, opcode);
                  break;
            }
            break;
         case JTAG_REPEAT_Q(0):
            if (numBits == 1) {
               // Value of 1 indicates use top-level value
               UsbdmSystem::Log::print("%-*d JTAG_REPEAT_DP #N\n", indent, lineNumber);
            }
            else {
               UsbdmSystem::Log::print("%-*d JTAG_REPEAT_Q(%d)\n", indent, lineNumber, numBits);
            }
            indent+=3;
            break;
         case JTAG_SHIFT_IN_Q(0) : // Shift sequence in (5-bit count)
            UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_Q(%d)\n", indent, lineNumber, numBits);
            break;
         case JTAG_SHIFT_OUT_Q(0) : // Shift sequence out (5-bit count) - sequence taken inline
            UsbdmSystem::Log::print("%-*d JTAG_SHIFT_OUT_Q(%d) => ", indent, lineNumber, numBits);
            printBits(numBits, sequence);
            sequence += BITS_TO_BYTES(numBits);
            break;
         case JTAG_SHIFT_IN_OUT_Q(0) : // Shift sequence in & out at same time - sequence taken inline
            UsbdmSystem::Log::print("%-*d JTAG_SHIFT_IN_OUT_Q(%d) =>", indent, lineNumber, numBits);
            printBits(numBits, sequence);
            sequence             += (numBits+7)/8;
            break;
         case JTAG_PUSH_Q(0): // Push a 5-bit value
            tempValue = opcode&JTAG_NUM_BITS_MASK;
            UsbdmSystem::Log::print("%-*d JTAG_PUSH_Q(%d, 0x%X)\n", indent, lineNumber, tempValue, tempValue);
            break;
         default:
            UsbdmSystem::Log::print("%-*d Unknown Opcode (%d)\n", indent, lineNumber, opcode);
            break;
      }
   } while ((sequence < sequenceStart+sequenceLength) && !complete);
   if (sequence < sequenceStart+sequenceLength) {
      UsbdmSystem::Log::print("Output data    =>  -------------------------------------------\n");
      UsbdmSystem::Log::printDump(sequence,
                         sequenceStart+sequenceLength-sequence,
                         sequence-sequenceStart);
   }
}

#endif

