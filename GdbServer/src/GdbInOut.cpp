/*! \file
    \brief Handles GDB output, and GDB input (on a separate thread)

    GdbInOut.cpp

    \verbatim
    USBDM
    Copyright (C) 2009  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    \endverbatim

    \verbatim
   Change History
   -==================================================================================
   | 23 Jun 2013 | Sockets version created and merged                            - pgo
   +==================================================================================
   | 23 Apr 2012 | Created                                                       - pgo
   +==================================================================================
   \endverbatim
*/

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif
#include <stdio.h>
#include <cstdarg>
#include <pthread.h>
//#include <unistd.h>

#include <stdlib.h>
#include "GdbInOut.h"
#include "UsbdmSystem.h"

//======================================================================
// GdbPacket

 /*!  GDB Packet that indicate a break has been received.
  */
const GdbPacket GdbPacket::breakToken  = {
      sizeof("break"),
      "break"
};

//======================================================================
// GdbInOut

/*!
 *
 */
GdbInOut::GdbInOut() :
   state(hunt),
   connectionActive(false),
   gdbTxChecksum(0),
   gdbTxCharCount(0),
   gdbTxPtr(gdbTxBuffer),
   rxBufferIndex(0),
   rxBufferLength(0),
   ackMode(true),
   errorLogger(0),
   sendLogger(0),
   receiveLogger(0) {
}

/*!
 *
 */
GdbInOut::~GdbInOut() {
   LOGGING_E;
   finish();
}

/*!  Finish up
 *
 *  Clean up
 *     - Sets connectionActive false
 */
void GdbInOut::finish(void) {
   LOGGING_E;
   if (connectionActive) {
      sendErrorMessage(E_Fatal, "Closing connection");
   }
   connectionActive = false;
}

/*!  Convert a HEX char to decimal
 *
 *   @param ch - char to convert ('0'-'9', 'a'-'f' or 'A' to 'F')
 *
 *   @return converted value - no error checks!
 */
int GdbInOut::charToHex(char ch) {
   if (('0' <= ch) && (ch <= '9'))
      return ch - '0';
   if (('a' <= ch) && (ch <= 'f'))
      return ch - 'a' + 10;
   if (('A' <= ch) && (ch <= 'F'))
      return ch - 'A' + 10;
   return 0;
}

/*! Convert a value to a HEX char
 *
 *  @param num - number to convert (0x0 - 0xF)
 *
 *  @return converted char ('0'-'9' or 'A' to 'F') - no error checks!
 */
char GdbInOut::hexChar(int num) {
const char chars[] = "0123456789abcdef";
   return chars[num&0x0F];
}

//=====================================================================
// Input functions
//=====================================================================

/*!  Get data from GDB
 *
 *   @param buff   - buffer for data
 *   @param size   - maximum number of bytes to read
 *
 *   @return  >0                  - Number of bytes read \n
 *            GDB_OK(0)           - No data \n
 *           -GDB_FATAL_ERROR     - Unexpected error
 */
int GdbInOut::getData(unsigned char *buffer, int size) {
   return -GDB_FATAL_ERROR;
}

/*!  Get a char from GDB input socket
 *
 *  @return -GDB_FATAL_ERROR     - Fatal error e.g. EOF \n
 *          -GDB_NON_FATAL_ERROR - No data available \n
 *          >= 0                 - Character received
 */
int GdbInOut::getChar() {
   LOGGING_Q;
   if (!connectionActive) {
      return -GDB_FATAL_ERROR;
   }
//   log.print("inBuffIndex = %d, inBuffLength = %d\n", inBuffIndex, inBuffLength);
   if (rxBufferIndex >= rxBufferLength) {
      // Buffer empty - try to read more data
//      log.print("Waiting for chars\n");
      int rc = getData(gdbRxBuffer, sizeof(gdbRxBuffer));
      if (rc < 0) {
//         log.print("Error %d\n", rc);
         return rc;
      }
      rxBufferLength = rc;
      rxBufferIndex  = 0;
//      log.print("Received %d chars\n", rxBufferLength);
   }
   if (rxBufferIndex >= rxBufferLength) {
      // No data at the moment
      return -GDB_NON_FATAL_ERROR;
   }
   int rc = gdbRxBuffer[rxBufferIndex++];
//   log.print("=%d(%c)\n", rc, rc);
   return rc;
}

/*!  Process byte received from debugger
 *
 * @return - !=NULL => Complete packet
 *           ==NULL => Packet not (yet) available
 */
const GdbPacket *GdbInOut::processRxByte(int byte) {
   LOGGING_Q;
   static GdbPacket packet1;
   static GdbPacket packet2;
   static GdbPacket *packet = &packet1;
   static unsigned char  checksum    = 0;
   static unsigned char  xmitcsum    = 0;
   static unsigned int   sequenceNum = 0;

   if (!connectionActive) {
      log.print("Connection not active\n");
      return NULL;
   }
   if (byte == -GDB_FATAL_ERROR) {
      log.print("-GDB_FATAL_ERROR\n");
      finish();
      return NULL;
   }
   if (byte < 0) {
//      log.print("-GDB_NONFATAL_ERROR\n");
      return NULL;
   }
   switch(state) {
      case hunt: // Looking for start of packet (or Break)
         if (byte == '$') { // Start token
            state         = data;
            checksum      = 0;
            packet->size  = 0;
         }
         else if (byte == 0x03) { // Break request
            return &GdbPacket::breakToken;
         }
         break;
      case data: // Data bytes within packet
         if (byte == '}') { // Escape token
            state     = escape;
            checksum  = checksum + byte;
         }
         else if (byte == '$') { // Unexpected start token
            state          = data;
            checksum       = 0;
            packet->size   = 0;
         }
         else if (byte == '#') { // End of data token
            state    = checksum1;
         }
         else { // Regular data
            if (packet->size < GdbPacket::MAX_MESSAGE) {
               packet->buffer[packet->size++] = byte;
            }
            checksum  = checksum + byte;
         }
         break;
      case escape: // Escaped byte within data
         state    = data;
         checksum = checksum + byte;
         byte       = byte ^ 0x20;
         if (packet->size < GdbPacket::MAX_MESSAGE) {
            packet->buffer[packet->size++] = byte;
         }
         break;
      case checksum1: // 1st Checksum byte
         state    = checksum2;
         xmitcsum = charToHex(byte) << 4;
         break;
      case checksum2: // 2nd Checksum byte
         xmitcsum += charToHex(byte);
         if (checksum != xmitcsum) {
            // Invalid packet - discard and start again
            log.print("\nBad checksum: my checksum = %2.2X, ", checksum);
            log.print("sent checksum = %2.2X\n", xmitcsum);
            log.print(" -- Bad buffer: \"%s\"\n", packet->buffer);
            state = hunt;
         }
         else {
            // Complete packet
            packet->checkSum = checksum;
            packet->buffer[packet->size] = '\0';
            packet->sequence = ++sequenceNum;
            state = hunt;
            GdbPacket *const tPacket = packet;
            if (packet == &packet1) {
               packet = &packet2;
            }
            else {
               packet = &packet1;
            }
            return tPacket;
         }
         break;
   }
   return NULL;
}

/*!  Get GDB Packet
 *
 *   @return - !=NULL => Complete packet
 *             ==NULL => Packet not (yet) available
 *
 *   @note must be Non-blocking
 */
const GdbPacket *GdbInOut::getGdbPacket(void) {
   return NULL;
}

//=====================================================================
// Output functions
//=====================================================================

/*!  Write buffer to GDB
 *
 *   @param buffer buffer to write
 *   @param size number of bytes to write
 *
 */
void GdbInOut::writeBuffer(unsigned char *buffer, int size) {
}

/*!  Add character to GDB Tx buffer
 *
 *   @param ch - char to add
 */
void GdbInOut::putGdbChar(char ch) {
   LOGGING_Q;
   gdbTxChecksum   += ch;
   gdbTxCharCount  += 1;
   if (gdbTxCharCount > sizeof(gdbTxBuffer)) {
      log.print( "buffer overflow\n");
      exit(-1);
   }
   *gdbTxPtr++      = ch;
}

/*!  Add character to GDB Tx buffer
 *
 *   @param ch - char to add
 */
void GdbInOut::putGdbEscapedChar(char ch) {
   if ((ch=='#') || (ch=='$') || (ch=='}') || (ch=='*')) {
      putGdbChar('}');
      ch ^= 0x20;
   }
   putGdbChar(ch);
}

 /*!  Add a string to GDB Tx buffer
  *
  *   @param s    - '\0' terminated string to add
  *   @param size - maximum size to send (-1 ignored)
  */
void GdbInOut::putGdbString(const char *s, int size) {
   while ((*s != '\0') && (size != 0)) {
      putGdbChar(*s++);
      if (size > 0)
         size--;
   }
}

/*!  Add bytes to GDB Tx buffer as Hex character pairs
 *
 *   @param buff  Buffer to add
 *   @param size  Size of buffer
 */
void GdbInOut::putGdbHex(const unsigned char *buffer, unsigned size) {
  unsigned index;
  for (index=0; index<size; index++) {
     putGdbChar(hexChar(buffer[index]>>4));
     putGdbChar(hexChar(buffer[index]));
  }
}

 /*!  Add a string to GDB Tx buffer as a series of hex digit pairs
  *
  *   @param s    - '\0' terminated string to add
  *   @param size - maximum size to send (-1 ignored)
  */
void GdbInOut::putGdbHexString(const char *s, int size) {
   while ((*s != '\0') && (size != 0)) {
      putGdbChar(hexChar((*s)>>4));
      putGdbChar(hexChar(*s++));
      if (size > 0)
         size--;
   }
}

 /*!  Print to GDB Tx buffer in 'printf' manner
  *
  *   @param format - print control string
  *   @param ...    - argument list
  *
  *   @return number of characters written to buffer
  *           -ve on error
  */
int GdbInOut::putGdbPrintf(const char *format, ...) {
   char buff[200];
   va_list list;
   va_start(list, format);
   int numChars = vsnprintf(buff, sizeof(buff), format, list);
   for (int index=0; index<numChars; index++ ) {
      putGdbChar(buff[index]);
   }
   return numChars;
}

 /*!  Set up GDB Tx buffer
  *
  *   @param marker - packet marker to use
  */
void GdbInOut::putGdbPreamble(char marker) {
   gdbTxPtr = gdbTxBuffer;
   putGdbChar(marker);
   gdbTxChecksum  = 0;
   gdbTxCharCount = 0;
}

 /*!  Adds checksum to GDB Tx buffer
  */
void GdbInOut::putGdbChecksum(void) {
   int checksum = gdbTxChecksum & 0xFF;
   putGdbChar('#');
   putGdbChar(hexChar(checksum >> 4));
   putGdbChar(hexChar(checksum % 16));
   putGdbChar('\0');
}

 /*!  Transmit the GDB Tx buffer to GDB
  */
void GdbInOut::txGdbPkt(void) {
   LOGGING_Q;
   writeBuffer(gdbTxBuffer, gdbTxCharCount);
   log.print( "txGdbPkt()=>:%3d%*s\n", gdbTxCharCount, gdbTxCharCount, gdbTxBuffer);
}

 /*!  Immediately send string to GDB (pre-amble and postscript are added)
  *
  *  @param str  - string to send ('\0' terminated)
  *  @param size - size of packet (-1 ignored)
  */
void GdbInOut::sendGdbString(const char *str, int size) {
   putGdbPreamble();
   putGdbString(str, size);
   putGdbChecksum();
   txGdbPkt();
}

/*!  Immediately send a string to GDB as a series of hex digit pairs with leading id string
 *
 *   @param id   - '\0' terminated string to send unencoded (may be NULL)
 *   @param s    - '\0' terminated string to send encoded
 *   @param size - maximum size of encoded string to send (-1 ignored)
 */
void GdbInOut::sendGdbHexString(const char *id, const char *s, int size) {
  if (id == NULL) {
     id = "";
  }
  putGdbPreamble();
  putGdbString(id);
  putGdbHexString(s, size);
  putGdbChecksum();
  txGdbPkt();
}

/*!  Immediately send data to GDB as a series of hex digit pairs with leading id string
 *   Used for monitor read memory command only
 *
 *   @param id   - '\0' terminated string to send unencoded (may be NULL)
 *   @param s    - data to send encoded
 *   @param size - size of data to send (in bytes)
 */
void GdbInOut::sendGdbHexDataString(const char *id, const uint8_t *data, unsigned size) {
  if (id == NULL) {
     id = "";
  }
  putGdbPreamble();
  putGdbString(id);
  putGdbHex(data, size);
  putGdbChecksum();
  txGdbPkt();
}

 /*!  Immediately send bytes to GDB as Hex character pairs
  *
  *   @param buffer   - data to put
  *   @param size     - size of data (-1 ignored)
  */
void GdbInOut::sendGdbHex(const unsigned char *buffer, unsigned size) {
   putGdbPreamble();
   putGdbHex(buffer, size);
   putGdbChecksum();
   txGdbPkt();
}

 /*!  Immediately send notification packet to GDB  (pre-amble and postscript are added)
  *
  *   @param buffer - data to send ('\0' terminated)
  *   @param size   - size of data (-1 ignored)
  */
void GdbInOut::sendGdbNotification(const char *buffer, int size) {
   putGdbPreamble('%');
   putGdbString("Stop:");
   putGdbString(buffer, size);
   putGdbChecksum();
   txGdbPkt();
}

 /*! Append checksum & immediately send GDB Buffer
  */
void GdbInOut::sendGdbBuffer(void) {
   putGdbChecksum();
   txGdbPkt();
}

/*!  Immediately send Error message
 *
 *  @param errorType  One of E_Memory etc
 *  @param msg        Message to send
 */
void GdbInOut::sendErrorMessage(ErrorType errorType, const char *msg) {
   static const char *errStrings[] = {"fatal", "memType"};
   if (errorType>(sizeof(errStrings)/sizeof(errStrings[0]))) {
      errorType = E_Fatal;
   }
   if (errorLogger != 0) {
      char buff[200];
      snprintf(buff, sizeof(buff), "Error response sent: E.%s.%s", errStrings[errorType], msg);
      errorLogger(buff);
   }
   putGdbPreamble();
   putGdbPrintf("E.%s.", errStrings[errorType]);
   while (*msg != '\0') {
      putGdbEscapedChar(*msg++);
   }
   putGdbChecksum();
   txGdbPkt();
}

/*!  Immediately send Error message
 *
 *  @param value        Error code to send
 */
void GdbInOut::sendErrorMessage(unsigned value) {
   if (errorLogger != 0) {
      char buff[200];
      snprintf(buff, sizeof(buff), "Error response sent: E%2.2X", value);
      errorLogger(buff);
   }
   putGdbPreamble();
   putGdbPrintf("E%2.2X", value);
   putGdbChecksum();
   txGdbPkt();
}

 /*!  Send immediate ACK/NAK response
  *
  *   @param ackValue - Either '-' or '+' response to send
  */
void GdbInOut::sendAck(char ackValue) {
   LOGGING_Q;
   log.print("sendAck()=>ack=%c\n", ackValue);
   writeBuffer((unsigned char *)&ackValue, 1);
}
