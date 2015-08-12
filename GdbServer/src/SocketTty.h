/*
 * SocketTty.h
 *
 *  Created on: 20 Jul 2015
 *      Author: podonoghue
 */

#ifndef SRC_SOCKET_TTY_H_
#define SRC_SOCKET_TTY_H_

#include <wx/socket.h>
#include "IGdbTty.h"

class SocketTty: public IGdbTty {
private:
   int                port;
   wxSocketClient    *fClient;
   wxIPV4address     *fAddress;
   bool               fConnected;
   bool               inputOpen;
   bool               outputOpen;
   bool               errorOpen;

   static const char *HOST_NAME;

public:
   SocketTty(int port);
   virtual ~SocketTty() {}
   bool     openConnection();
   void     closeConnection();
   virtual bool     openInput()    { return inputOpen  = openConnection(); };
   virtual bool     openOutput()   { return outputOpen = openConnection(); };
   virtual bool     openError()    { return errorOpen  = openConnection(); };
   virtual bool     isInputOpen()  { return inputOpen; };
   virtual bool     isOutputOpen() { return outputOpen; };
   virtual bool     isErrorOpen()  { return errorOpen; };
   virtual void     closeInput();
   virtual void     closeOutput();
   virtual void     closeError();
   virtual void     closeAll();
   virtual void     putChar(int ch);
   virtual int      getChar();
   virtual void     puts(char *s);
   virtual int      gets(char s[], int len);
};

#endif /* SRC_SOCKET_TTY_H_ */
