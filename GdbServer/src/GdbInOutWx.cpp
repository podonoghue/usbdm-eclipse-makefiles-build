/*! \file
    \brief Handles GDB output, and GDB input

    GdbInOutWx.cpp

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
   |  2 Jul 2013 | Created                                                       - pgo
   +==================================================================================
   \endverbatim
*/

#include "GdbInOutWx.h"
#include "UsbdmSystem.h"

/*
 *
 */
GdbInOutWx::GdbInOutWx(wxSocketBase *clientSocket, wxTextCtrl *logScreen) :
   GdbInOut(),
   rxBufferIndex(0),
   rxBufferLength(0),
   clientSocket(clientSocket),
   logScreen(logScreen) {
   connectionActive = true;
}

/*
 *
 */
GdbInOutWx::~GdbInOutWx() {
   LOGGING_E;
   finish();
}

//=====================================================================
// Input functions
//=====================================================================


/*!  Finish up
 *
 *  - Set end of file
 *  - Close client socket
 */
void GdbInOutWx::finish(void) {
   LOGGING_Q;
   clientSocket->SetFlags(wxSOCKET_WAITALL);
   log.print("GdbInOutWx::finish()\n");
   GdbInOut::finish();
}

/*!  Get GDB Packet
 *
 *   @return next GDB packet received or NULL if none available
 *
 *   @note Non-blocking
 */
const GdbPacket *GdbInOutWx::getGdbPacket(void) {
   LOGGING_Q;
   if (!connectionActive) {
      logScreen->AppendText(_("Connection lost\n"));
      return NULL;
   }
   const GdbPacket *packet;
   int byte;
   do {
      byte = getChar();
      packet = processRxByte(byte);
//      char t = byte;
//      if (!isascii(t)) {
//         t = '*';
//      }
//      logScreen->AppendText(t);
   } while ((byte >= 0) && (packet == NULL));
//   logScreen->AppendText('\n');
   if (packet != NULL) {
      log.print("Rx<=#:%d:%03d$%*.*s#%2.2x\n", packet->sequence, packet->size, packet->size, packet->size, packet->buffer, packet->checkSum);
//      wxString s;
//      s.Printf("Rx<=#:%d:%03d$%*.*s#%2.2x\n", packet->sequence, packet->size, packet->size, packet->size, packet->buffer, packet->checkSum);
//      logScreen->AppendText(s);
      if (ackMode) {
         sendAck();
      }
   }
//   else {
//      log.print("No packet\n");
//   }
   return packet;
}

/*!  Get data from GDB
 *
 *   @param buff   - buffer for data
 *   @param size   - maximum number of bytes to read
 *
 *   @return  >0                  - Number of bytes read \n
 *            GDB_OK(0)           - No data \n
 *           -GDB_FATAL_ERROR     - Unexpected error
 */
int GdbInOutWx::getData(unsigned char *buffer, int size) {

   memset(buffer, 0, size);

   clientSocket->Read(buffer, size);
   int bytesRead = clientSocket->LastCount();
   if (bytesRead == 0) {
//      logScreen->AppendText("clientSocket->Read() failed.\n");
      return -GDB_NON_FATAL_ERROR;
   }
   int t = bytesRead;
   if (t > 20) {
      t = 20;
   }
//   wxString s;
//   s.Printf("<==%03d:%*.*s:\n", bytesRead, t, t, (char *)buffer);
//   logScreen->AppendText(s);

   return bytesRead;
}

//=====================================================================
// Output functions
//=====================================================================

/*!  Write buffer to GDB
 *
 *   @param buffer buffer to write
 *   @param size number of bytes to write
 *
 *   @note Blocking but should usually succeed 1st try
 */
void GdbInOutWx::writeBuffer(unsigned char *buffer, int size) {
//   logScreen->AppendText("==>");
//   logScreen->AppendText(buffer);
//   logScreen->AppendText("\n");
   int bytesWritten = 0;
   do {
      clientSocket->Write(buffer+bytesWritten, size);
      bytesWritten += clientSocket->LastCount();
      size -= bytesWritten;
   } while ((size>0) && !clientSocket->Error());
   if (clientSocket->Error()) {
      errorLogger("clientSocket error");
   }
}
