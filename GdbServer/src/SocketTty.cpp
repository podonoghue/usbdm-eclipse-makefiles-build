/*
 * SocketTty.cpp
 *
 *  Created on: 20 Jul 2015
 *      Author: podonoghue
 */
#include "UsbdmSystem.h"
#include "SocketTty.h"

const char *SocketTty::HOST_NAME = "localhost";

SocketTty::SocketTty(int port) : port(port), fClient(0), fConnected(false), inputOpen(false), outputOpen(false), errorOpen(false) {
   fAddress = new wxIPV4address();
   fAddress->Hostname(HOST_NAME);
   fAddress->Service(port);
}

bool SocketTty::openConnection() {
   LOGGING_Q;
   if (fClient == 0) {
      fClient = new wxSocketClient();
   }
   if (!fClient->IsConnected()) {
      fClient->Connect(*fAddress, false);
      // Wait only 5 seconds for connect
      fClient->WaitOnConnect(5);
      fClient->SetFlags(wxSOCKET_NOWAIT_READ);
      fConnected = fClient->IsConnected();
      log.print("Result = %s\n", fConnected?"OK":"FAILED");
   }
   return fConnected;
}

void SocketTty::closeConnection() {
   if ((fClient != 0) && !inputOpen && !outputOpen && !errorOpen) {
//      char message[] = "Console Closed\n";
//      fClient->Write(message, sizeof(message)-1);
      fClient->Close();
      fClient = 0;
   }
}

void SocketTty::closeInput()   {
   inputOpen = false;
   closeConnection();
};
void SocketTty::closeOutput()  {
   outputOpen = false;
   closeConnection();
};
void SocketTty::closeError()   {
   errorOpen = false;
   closeConnection();
};
void SocketTty::closeAll()   {
   inputOpen = false;
   outputOpen = false;
   errorOpen = false;
   closeConnection();
};
void SocketTty::putChar(int ch) {
   if (fClient == 0) {
      return;
   }
   char buff[1] = {(char)ch};
   fClient->Write(buff, sizeof(buff));
}

void SocketTty::puts(char *s) {
   LOGGING_Q;
   log.print("s = %s\n", s);
   if (fClient == 0) {
      log.print("no client\n");
      return;
   }
   int len = strlen(s);
   fClient->Write(s, len);
   log.print("s = %d\n", fClient->LastWriteCount());
}

int SocketTty::getChar() {
   return EOF;
   // TODO - add read functions
//   if (fClient == 0) {
//      return EOF;
//   }
//   unsigned char buff[1];
//   fClient->Read(buff, sizeof(buff));
//   return buff[0];
}

int SocketTty::gets(char s[], int len) {
   // TODO - add read functions
//   while (fClient != 0) {
//      fClient->Read(s, len);
//      int amountRead = fClient->LastReadCount();
//      if (amountRead>0) {
//         return amountRead;
//      }
//      fClient->WaitForRead(1,0);
//   }
   return 0;
}

