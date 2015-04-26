/*
 * GdbInOutWx.h
 *
 *  Created on: 02/07/2013
 *      Author: Peter
 */

#ifndef GDBINOUTWX_H_
#define GDBINOUTWX_H_

#include <wx/wx.h>
#include <wx/socket.h>

#include "GdbInOut.h"

class GdbInOutWx : public GdbInOut {

public:
   GdbInOutWx(wxSocketBase *clientSocket, wxTextCtrl *logScreen);
   virtual ~GdbInOutWx();
   virtual const GdbPacket *getGdbPacket();

private:

   unsigned char    gdbRxBuffer[1000]; //! Buffer for Rx data from GDB
   unsigned         rxBufferIndex;     //! Read index for gdbRxBuffer
   unsigned         rxBufferLength;    //! Occupied size of gdbRxBuffer
   wxSocketBase    *clientSocket;
   wxTextCtrl      *logScreen;

private:
   virtual void             writeBuffer(unsigned char *buffer, int size);
   virtual int              getData(unsigned char *buffer, int size);

public:
   virtual void finish(void);
};

#endif /* GDBINOUTWX_H_ */
