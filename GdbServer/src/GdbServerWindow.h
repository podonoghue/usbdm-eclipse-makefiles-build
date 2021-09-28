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

class GdbServerWindow: public GdbServerWindowSkeleton, GdbHandler::GdbHandlerOwner {

protected:
   // Virtual event handlers
   virtual void OnCloseWindow( wxCloseEvent& event ) override;
   virtual void OnChangeSettings( wxCommandEvent& event ) override;
   virtual void OnDropConnection( wxCommandEvent& event ) override;
   virtual void OnQuit( wxCommandEvent& event ) override;
   virtual void OnClearLog( wxCommandEvent& event ) override;
   virtual void OnDisableLog( wxCommandEvent& event ) override;
   virtual void OnModerateLog( wxCommandEvent& event ) override;
   virtual void OnVerboseLog( wxCommandEvent& event ) override;
   virtual void OnHaltTarget( wxCommandEvent& event ) override;
   virtual void OnResetTarget( wxCommandEvent& event ) override;
   virtual void OnToggleMaskISR( wxCommandEvent& event ) override;
   virtual void OnSetTimeout( wxCommandEvent& event ) override;
   virtual void OnToggleCatchVLLS( wxCommandEvent& event ) override;
   virtual void OnEntryTextEnter( wxCommandEvent& event ) override;

   /**
    * Display/Notify message
    *
    * @param msg     Text of message
    * @param level   Severity of message (used to filter uninteresting messages)
    * @param rc      Error code associated with message (if any)
    *
    * @return Modified error code
    */
   virtual USBDM_ErrorCode displayMessage(const char *msg, GdbHandler::GdbMessageLevel level, USBDM_ErrorCode rc) override;
   /**
    * Close connection in near future when inactive (i.e. polling etc not actually executing)
    */
   virtual void            setDeferredCloseClient() override;

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
