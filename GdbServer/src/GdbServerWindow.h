/*
 * GdbServerWindow.h
 *
 *  Created on: 26 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBSERVERWINDOW_H_
#define SRC_GDBSERVERWINDOW_H_

#include <wx/socket.h>
#include <wx/timer.h>
typedef  wxIPV4address IPaddress;

#include "BdmInterface.h"
#include "DeviceData.h"
#include "USBDM_API.h"
#include "GdbInOutWx.h"
#include "GdbHandler.h"
#include "DeviceInterface.h"
#include "GdbServerWindowSkeleton.h"
#include "WxWidgetsTty.h"
#include "IGdbTty.h"

#define CONFIG_FILE_NAME "GDBServer_"

class GdbServerWindow: public GdbServerWindowSkeleton {

protected:
   class GdbMessageWrapper {
   private:
      static GdbServerWindow *me;
      static USBDM_ErrorCode callback(const char *msg, GdbHandler::GdbMessageLevel level, USBDM_ErrorCode rc);

   public:
      static GdbHandler::GdbCallback getCallBack(GdbServerWindow *me) {
         GdbMessageWrapper::me = me;
         return callback;
      }
   };

   // Virtual event handlers
   virtual void OnCloseWindow( wxCloseEvent& event );
   virtual void OnChangeSettings( wxCommandEvent& event );
   virtual void OnDropConnection( wxCommandEvent& event );
   virtual void OnQuit( wxCommandEvent& event );
   virtual void OnClearLog( wxCommandEvent& event );
   virtual void OnDisableLog( wxCommandEvent& event );
   virtual void OnModerateLog( wxCommandEvent& event );
   virtual void OnVerboseLog( wxCommandEvent& event );
   virtual void OnHaltTarget( wxCommandEvent& event );
   virtual void OnResetTarget( wxCommandEvent& event );
   virtual void OnToggleMaskISR( wxCommandEvent& event );
   virtual void OnSetTimeout( wxCommandEvent& event );
   virtual void OnToggleCatchVLLS( wxCommandEvent& event );
   virtual void OnEntryTextEnter( wxCommandEvent& event );

   // Timer Event handler
   void OnTimer(wxTimerEvent& event);

   // Socket events
   void OnServerEvent(wxSocketEvent& event);
   void OnSocketEvent(wxSocketEvent& event);

   // Convenience functions
   void UpdateStatusBar();
   void pollTarget();

   USBDM_ErrorCode        doSettingsDialogue();
   bool                   confirmDropConnection();
   void                   createServer();
   void                   closeServer();
   void                   dropConnection();
   void                   updateMenu();

   GdbHandler::GdbMessageLevel   getLoggingLevel();

   void                   setLoggingLevel(GdbHandler::GdbMessageLevel level);
   USBDM_ErrorCode        reportError(const char *msg, GdbHandler::GdbMessageLevel level, USBDM_ErrorCode rc);

   static wxString        getAddr(IPaddress addr);
   void                   setDeferredFail(bool value = true);
   void                   setDeferredOpen(bool value = true);

   wxString                      serverAddr;         // Current server address as string
   wxString                      clientAddr;         // Current client address as string
   wxSocketServer               *serverSocket;       // Server socket
   wxSocketBase                 *clientSocket;       // Client socket

   BdmInterfacePtr               bdmInterface;
   DeviceInterfacePtr            deviceInterface;
   AppSettings                   appSettings;

   GdbHandler::GdbMessageLevel   loggingLevel;
   GdbHandler::GdbTargetStatus   targetStatus;

   typedef enum {
      idle,
      listening,
      connected,
      abort} ServerState;
   ServerState                   serverState;

   GdbInOutWx                   *gdbInOut;

   wxTimer                      *statusTimer;

   bool                          deferredFail;
   bool                          deferredOpen;
   bool                          useGui;

   IGdbTty                      *tty;
   GdbHandlerPtr                 gdbHandler;

   static const int              pollIntervalVeryFast = 10;   // ms
   static const int              pollIntervalFast     = 100;  // ms
   static const int              pollIntervalSlow     = 1000; // ms

   enum {
      // id for sockets
      SERVER_ID = 100,
      SOCKET_ID,
      STATUSTIMER_ID,
   };

public:
   GdbServerWindow(
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         bool                 useGui);
   virtual ~GdbServerWindow();

   USBDM_ErrorCode   execute();
};

#endif /* SRC_GDBSERVERWINDOW_H_ */
