/*
 * GdbInOutPipe.h
 *
 *  Created on: 23/04/2012
 *      Author: PODonoghue
 */

#ifndef GDBINOUT_H_
#define GDBINOUT_H_

#include <stdint.h>

#define GDB_OK               (0)
#define GDB_FATAL_ERROR      (1)
#define GDB_NON_FATAL_ERROR  (2)

//==========================================================
//

#define MAX_GDB_MESSAGE_SIZE (2000) //! Maximum size of a GDB packet

/*! Represents a packet received from GDB
 */
class GdbPacket {

public:
   static const GdbPacket breakToken;                        //!< Packet representing a 'break' from GDB
   static const int       MAX_MESSAGE=MAX_GDB_MESSAGE_SIZE;  //!< Maximum size of message buffer
   int   size;                                               //!< Size of valid data in buffer
   char  buffer[MAX_MESSAGE];                                //!< Raw data from GDB
   int   checkSum;                                           //!< Checksum for data
   int   sequence;                                           //!< Sequence number for message
   bool  isBreak() const {                                   //!< Check if this is a 'break' packet
      return this == &breakToken;
   }
};

//==========================================================
//

/*! Class to handle GDB Input & Output
 *
 */
class GdbInOut {

public:
   enum ErrorType {E_Fatal, E_Memory};       //!< Type of error message to send to GDB
   typedef void Logger(const char *msg);

protected:
   enum StateType {hunt, data, escape, checksum1, checksum2};
   StateType               state;               //!< State of GDB packet Rx state machine
   bool                    connectionActive;    //!< Active connection to GDB

   unsigned char           gdbTxBuffer[2000];   //!< Buffer for assembling GDB Tx packet
   int                     gdbTxChecksum;       //!< Checksum for gdbTxBuffer
   unsigned                gdbTxCharCount;      //!< Byte count for gdbTxBuffer
   unsigned char *         gdbTxPtr;            //!< Pointer into gdbTxBuffer

   unsigned char    gdbRxBuffer[MAX_GDB_MESSAGE_SIZE+20]; //! Buffer for Rx data from GDB
   unsigned         rxBufferIndex;                        //! Read index for gdbRxBuffer
   unsigned         rxBufferLength;                       //! Occupied size of gdbRxBuffer

   bool             ackMode;

   Logger *errorLogger;
   Logger *sendLogger;
   Logger *receiveLogger;

protected:
   char hexChar(int num);
   int  charToHex(char ch);

   const GdbPacket *processRxByte(int byte);
   int  getChar();

   virtual void writeBuffer(unsigned char *buffer, int size);
   virtual int  getData(unsigned char *buffer, int size);

public:
   GdbInOut();
   virtual ~GdbInOut();
   virtual void finish(void);

   // Input functions (from GDB)
   virtual const GdbPacket *getGdbPacket();
   bool isEOF(void) { return !connectionActive; }

   void setAckMode(bool value) {
      ackMode = value;
   }

   void setLoggers(Logger *errorLogger, Logger *sendLogger, Logger *receiveLogger) {
      this->errorLogger   = errorLogger;
      this->sendLogger    = sendLogger;
      this->receiveLogger = receiveLogger;
   }

   // Output functions (to GDB)

   // Add values to output buffer (gdbBuffer)
   void putGdbPreamble(char marker='$');
   void putGdbChar(char ch);
   void putGdbEscapedChar(char ch);
   void putGdbHex(const unsigned char *buffer, unsigned size);
   void putGdbString(const char *s, int size=-1);
   void putGdbHexString(const char *s, int size=-1);
   int  putGdbPrintf(const char *format, ...);
   void putGdbChecksum(void);
   void putGdbPostscript(void);

   // Send data to GDB
   void sendGdbBuffer(void);
   void sendGdbHexDataString(const char *id, const uint8_t *data, unsigned size);
   void sendGdbHex(const unsigned char *buffer, unsigned size);
   void sendGdbString(const char *buffer, int size=-1);
   void sendGdbHexString(const char *id, const char *buffer, int size=-1);
   void sendGdbNotification(const char *buffer, int size=-1);
   void sendErrorMessage(ErrorType errorType, const char *msg);
   void sendErrorMessage(unsigned value);
   void sendAck(char ackValue='+');

   void txGdbPkt(void);
};
#endif /* GDBINOUT_H_ */
