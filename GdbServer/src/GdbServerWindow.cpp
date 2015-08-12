/*
 * GdbServerWindow.cpp
 *
 *  Created on: 26 Mar 2015
 *      Author: podonoghue
 */

#include "GdbServerWindow.h"

#include "GdbServerDialogue.h"

#include "wx/busyinfo.h"
#include "GdbServerDialogue.h"
#include "GdbHandlerFactory.h"
#include "SocketTty.h"
#include "UsbdmSystem.h"

using namespace std;

GdbServerWindow::GdbServerWindow(BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, AppSettingsPtr appSettings) :
   GdbServerWindowSkeleton( (wxFrame *)0, wxID_ANY, _("USBDM GDB Server"), wxDefaultPosition, wxDefaultSize),
   bdmInterface(bdmInterface),
   deviceInterface(deviceInterface),
   appSettings(appSettings),
   loggingLevel(GdbHandler::M_ERROR),
   targetStatus(GdbHandler::T_UNKNOWN),
   serverState(idle),
   gdbInOut(NULL),
   statusTimer(NULL),
   deferredFail(false),
   deferredOpen(false) {
   LOGGING;

   serverSocket = NULL;
   clientSocket = NULL;

   gdbHandler.reset();

//   tty = new WxWidgetsTty(statusTextControl, entryTextControl);
   tty = new SocketTty(bdmInterface->getGdbTtyPort());

   this->Connect( SERVER_ID,      wxEVT_SOCKET, wxSocketEventHandler( GdbServerWindow::OnServerEvent ) );
   this->Connect( SOCKET_ID,      wxEVT_SOCKET, wxSocketEventHandler( GdbServerWindow::OnSocketEvent ) );
   this->Connect( STATUSTIMER_ID, wxEVT_TIMER,  wxTimerEventHandler(GdbServerWindow::OnTimer) );
}

/* Destructor
 */
GdbServerWindow::~GdbServerWindow() {
   // No delayed deletion here, as the frame is dying anyway
   delete serverSocket;
   serverSocket = NULL;
   delete clientSocket;
   clientSocket = NULL;
   delete statusTimer;
   statusTimer = NULL;
}

USBDM_ErrorCode GdbServerWindow::execute(bool skipOpeningDialogue) {
   if (!skipOpeningDialogue) {
      doSettingsDialogue(true);
   }
   updateMenu();
   Show();

   createServer();

   return BDM_RC_OK;
}

USBDM_ErrorCode GdbServerWindow::doSettingsDialogue(bool reloadSettings) {
   LOGGING;

   // Create the setting dialogue
   GdbServerDialogue gdbServerDialogue(this, bdmInterface, deviceInterface);
   USBDM_ErrorCode rc = gdbServerDialogue.execute(appSettings, reloadSettings);
   updateMenu();
   return rc;
}

void GdbServerWindow::updateMenu() {
   targetMenu->Check(wxID_CATCH_VLLS_ID,      bdmInterface->isCatchVLLSx());
   targetMenu->Check(wxID_DISABLE_INTERRUPTS, bdmInterface->getBdmOptions().maskInterrupts);
}

GdbHandler::GdbMessageLevel GdbServerWindow::getLoggingLevel() {
   return loggingLevel;
}

 void GdbServerWindow::setLoggingLevel(GdbHandler::GdbMessageLevel level) {
   loggingLevel = level;
}

 void GdbServerWindow::setDeferredFail(bool value) {
    deferredFail = value;
 }

 void GdbServerWindow::setDeferredOpen(bool value) {
    deferredOpen = value;
 }

 /*!
  *  Translate a IPaddress into a meaningful string
  *
  *  @param addr The address to translate
  *
  *  @return A string representing the addr e.g. localhost:1099
  */
 wxString GdbServerWindow::getAddr(IPaddress addr) {
    wxString *serverAddr = new wxString();

    if (addr.IPAddress().compare(_("127.0.0.1")) == 0) {
       serverAddr->Printf(_("localhost:%u"), addr.Service());
    }
    else {
       serverAddr->Printf(_("%s:%u"), (const char *)addr.IPAddress().c_str(), addr.Service());
    }
    return *serverAddr;
 }

 /*!
  *  Create server listening on socket
  *  Subscribes to connection events with ID SERVER_ID
  */
 void GdbServerWindow::createServer() {
    LOGGING_E;

    // Create the address
    IPaddress listenAddr;
    listenAddr.Service(bdmInterface->getGdbServerPort());
    listenAddr.Hostname(_("localhost"));
    serverAddr = getAddr(listenAddr);

    closeServer();

    // Create the socket
    serverSocket = new wxSocketServer(listenAddr, wxSOCKET_NOWAIT);

    // We use IsOk() here to see if the server is really listening
    if (!serverSocket->IsOk()) {
       statusTextControl->AppendText(_("ERROR: Could not create server at the specified port !\n"));
       return;
    }
    string bdmSerialNumber = bdmInterface->getBdmSerialNumber();
    if (bdmSerialNumber.length() > 0) {
       if (bdmInterface->getBdmMatchRequired()) {
          statusTextControl->AppendText(_("Using required USBDM interface S/N = \'")+wxString(bdmSerialNumber.c_str(), wxConvUTF8)+_("\'\n"));
       }
       else {
          statusTextControl->AppendText(_("Using preferred USBDM interface S/N = \'")+wxString(bdmSerialNumber.c_str(), wxConvUTF8)+_("\'\n"));
       }
    }
    else {
       statusTextControl->AppendText(_("Using any suitable USBDM interface\n"));
    }
    IPaddress addrReal;
    if (!serverSocket->GetLocal(addrReal) ) {
       statusTextControl->AppendText(_("ERROR: couldn't get the address we bound to\n"));
    }
    else {
       serverAddr = getAddr(addrReal);
       wxString s;
       s.Printf(_("Server created @%s\n"), (const char *)serverAddr.c_str());
       statusTextControl->AppendText(s);
    }

    // Setup the event handler and subscribe to connection events
    serverSocket->SetEventHandler(*this, SERVER_ID);
    serverSocket->SetNotify(wxSOCKET_CONNECTION_FLAG);
    serverSocket->Notify(true);

    serverState = listening;

    UpdateStatusBar();
 }

 void GdbServerWindow::closeServer() {
    LOGGING_E;

    dropConnection();

    if (serverSocket != NULL) {
       statusTextControl->AppendText(_("Stopping Server\n"));
       serverSocket->Destroy();
       serverSocket = NULL;
    }
    serverState = idle;
    UpdateStatusBar();
 }

 bool GdbServerWindow::confirmDropConnection() {
    if (serverState != connected) {
       return true;
    }
    int getYesNo = wxMessageBox(
                 _("There is a current GDB connection.\n\nDrop this connection?"),
                 _("Active Connection Warning"),
                 wxOK|wxCANCEL,
                 this
                 );
    return (getYesNo == wxOK);
 }

 //===========================================================================
 // event handlers
 //===========================================================================

 /*!  Handler for Drop connection menu item
  *
  */
 void GdbServerWindow::OnDropConnection(wxCommandEvent& WXUNUSED(event)) {
    LOGGING_Q;
    if ((clientSocket != NULL) && confirmDropConnection()) {
       log.print("GdbServerWindow::OnDropConnection()\n");
       dropConnection();
    }
 }

 /*!   Handler for Quit button
  *
  */
 void GdbServerWindow::OnChangeSettings(wxCommandEvent& WXUNUSED(event)) {
    if (confirmDropConnection()) {
       closeServer();
       serverState = abort;
       doSettingsDialogue(false);
       createServer();
    }
 }

 /*!   Handler for Quit button
  *
  */
 void GdbServerWindow::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(false);
 }

 /*!   Handler for Close Window
  *
  */
 void GdbServerWindow::OnCloseWindow(wxCloseEvent& event) {
    LOGGING_Q;
    if (!event.CanVeto() || confirmDropConnection())  {
       log.print("GdbServerWindow::OnCloseWindow()\n");
       dropConnection();
       this->Destroy();
    }
    else {
       event.Veto();
    }
 }

 /*!  Handler for Clear Log Button
  *
  */
 void GdbServerWindow::OnClearLog(wxCommandEvent& WXUNUSED(event)) {
    statusTextControl->Clear();
 }

 /*!   Verbose log check-box menu item
  *
  */
 void GdbServerWindow::OnDisableLog(wxCommandEvent& event) {
    setLoggingLevel(GdbHandler::M_ERROR);
 }

 /*!   Verbose log check-box menu item
  *
  */
 void GdbServerWindow::OnModerateLog(wxCommandEvent& event) {
    setLoggingLevel(GdbHandler::M_INFO);
 }

 /*!   Verbose log check-box menu item
  *
  */
 void GdbServerWindow::OnVerboseLog(wxCommandEvent& event) {
    setLoggingLevel(GdbHandler::M_BORINGINFO);
 }

 /*!  Handler for Halt Target menu item
  *
  */
 void GdbServerWindow::OnHaltTarget(wxCommandEvent& event) {
    bdmInterface->halt();
    statusTextControl->AppendText(_("User halt of target - step GDB to synchronise\n"));
 }

 /*!  Handler for Reset Target menu item
  *
  */
 void GdbServerWindow::OnResetTarget(wxCommandEvent& event) {
    bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
    statusTextControl->AppendText(_("User reset of target - step GDB to synchronise\n"));
 }

 /*!  Handler for Mask interrupts menu item
  *
  */
 void GdbServerWindow::OnToggleMaskISR(wxCommandEvent& event) {
    bool disableInterrupts = event.IsChecked();
    bdmInterface->setMaskISR(disableInterrupts);
    if (gdbHandler != 0) {
       gdbHandler->updateTarget();
    }
 }

 /*!  Handler for Reset Target menu item
  *
  */
 void GdbServerWindow::OnToggleCatchVLLS(wxCommandEvent& event) {
    bool catchVLLS = event.IsChecked();
    bdmInterface->setCatchVLLSx(catchVLLS);
    if (gdbHandler != 0) {
       gdbHandler->updateTarget();
    }
 }

 void GdbServerWindow::OnEntryTextEnter( wxCommandEvent& event ) {

 }

 /*!  Handler for Timeout menu item
  *
  */
 void GdbServerWindow::OnSetTimeout(wxCommandEvent& WXUNUSED(event)) {
    unsigned long int value = bdmInterface->getConnectionTimeout();
    wxTextEntryDialog dlg(this, "Enter Timeout value in seconds\n0 means indefinite wait", "Timeout Value", wxString::Format("%lu", value));
    if (dlg.ShowModal() ==  wxID_OK) {
       wxString s = dlg.GetValue();
       if (!s.ToULong(&value, 10)) {
          return;
       }
    }
    bdmInterface->setConnectionTimeout((unsigned)value);
 }

 /*!
  *  Handler for Server events (before connection)
  *
  *  - Only expects connection events wxSOCKET_CONNECTION
  *  - Creates new socket and adds handler for socket events
  *
  *  @param event Event to handle
  */
 void GdbServerWindow::OnServerEvent(wxSocketEvent& event) {
    LOGGING;

    if (event.GetSocketEvent() != wxSOCKET_CONNECTION) {
       statusTextControl->AppendText(_("Unexpected event on Server\n"));
       // Ignore
       return;
    }

    if (clientSocket != NULL) {
       statusTextControl->AppendText(_("Client connection while busy - rejected\n"));
       wxSocketBase *clientSocket = serverSocket->Accept(false);
       clientSocket->Destroy();
       return;
    }

    // Accept new connection if there is one in the pending
    // connections queue, else exit. We use Accept(false) for
    // non-blocking accept (although if we got here, there
    // should ALWAYS be a pending connection).

    clientSocket = serverSocket->Accept(false);
    if (clientSocket == NULL) {
       statusTextControl->AppendText(_("Error: couldn't accept a new connection\n"));
       return;
    }

    IPaddress peerAddr;
    if ( !clientSocket->GetPeer(peerAddr) ) {
       statusTextControl->AppendText(_("New connection from unknown client accepted.\n"));
    }
    else {
       clientAddr = getAddr(peerAddr);
       statusTextControl->AppendText(_(
             "\n=====================================\n"
             "New client connection from ")+ clientAddr + _(" accepted\n"));
    }

    // Subscribe to socket events
    //  wxSOCKET_INPUT_FLAG - received data
    //  wxSOCKET_LOST_FLAG  - lost connection
    clientSocket->SetEventHandler(*this, SOCKET_ID);
    clientSocket->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    clientSocket->Notify(true);

    setDeferredFail(false);
    setDeferredOpen(true);

    if (statusTimer == 0) {
       statusTimer = new wxTimer(this, STATUSTIMER_ID);
    }
    log.print("Starting timer, interval = %d\n", pollIntervalSlow);
    statusTimer->Start(pollIntervalSlow, wxTIMER_ONE_SHOT);

    serverState = connected;
    UpdateStatusBar();
 }

 /*! Handler for Timer events
  *
  *   - Handles polling target when running
  */
 void GdbServerWindow::OnTimer(wxTimerEvent& event) {
    LOGGING;
    pollTarget();
 //   if ((clientSocket!= NULL) && clientSocket->IsData()) {
 //      log.print("OnTimer:: Data available?\n");
 //   }
 }

 /*!
  *  Drop client connection and clean up
  *
  */
 void GdbServerWindow::dropConnection() {
    LOGGING;
    if (gdbInOut != NULL) {
       gdbInOut->finish();
       delete gdbInOut;
       gdbInOut = NULL;
    }
    if (statusTimer != NULL) {
       statusTimer->Stop();
       delete statusTimer;
       statusTimer = NULL;
    }
    gdbHandler.reset();
    bdmInterface->closeBdm();
    if (clientSocket != NULL) {
       clientSocket->Destroy();
       clientSocket = NULL;
       statusTextControl->AppendText(_(
             "\n=====================\n"
             "Dropped connection\n"));
       if (!deferredOpen && bdmInterface->isExitOnClose()) {
          statusTextControl->AppendText(_("Closing\n\n"));
          Close(true);
       }
    }
    serverState  = listening;
    clientAddr = _("None");
    targetStatus = GdbHandler::T_UNKNOWN;
    UpdateStatusBar();
 }

 /*!  Report error message
  *
  *   @param msg   Message to display
  *   @param rc    Error code
  */
 USBDM_ErrorCode GdbServerWindow::reportError(const char *msg, GdbHandler::GdbMessageLevel level, USBDM_ErrorCode rc) {

    if ((rc != BDM_RC_OK) || (level >= getLoggingLevel())) {
       statusTextControl->AppendText(wxString(msg, wxConvUTF8));
       if (level == GdbHandler::M_FATAL) {
          setDeferredFail();
       }
    }
    if (level&GdbHandler::M_DIALOGUE) {
       Iconize(false); // restore the window if minimized
       SetFocus();     // focus on my window
       Raise();        // bring window to front
       Show(true);     // show the window
       wxMessageBox(
          wxString(msg, wxConvUTF8),                      /* message */
          wxString("Message", wxConvUTF8),                /* caption */
          wxOK|wxICON_ERROR,                              /* style   */
          this                                            /* parent  */
          );
    }
    if (rc != BDM_RC_OK) {
       statusTextControl->AppendText(wxString(bdmInterface->getErrorString(rc), wxConvUTF8));
       statusTextControl->AppendText(_("\n"));

       Iconize(false); // restore the window if minimized
       SetFocus();     // focus on my window
       Raise();        // bring window to front
       Show(true);     // show the window
       wxMessageBox(
          wxString(bdmInterface->getErrorString(rc), wxConvUTF8), /* message */
          wxString(msg, wxConvUTF8),                      /* caption */
          wxOK|wxICON_ERROR,                              /* style   */
          this                                            /* parent  */
          );
    }
    return rc;
 }

 GdbServerWindow *GdbServerWindow::GdbMessageWrapper::me = NULL; //!< handle on GdbServerWindow

 /*! Call back to display messages from GDB handler
  *
  *   @param msg   Message to display
  *   @param level Level
  *   @param rc    Error code
  *
  *   @return      Modified error code
  */
 USBDM_ErrorCode GdbServerWindow::GdbMessageWrapper::callback(const char *msg, GdbHandler::GdbMessageLevel level, USBDM_ErrorCode rc) {
    return me->reportError(msg, level, rc);
 }

 /*!
  *  Handler for Socket events (after connection)
  *
  *  - Only expects:
  *    - wxSOCKET_INPUT - New data
  *    - wxSOCKET_LOST  - Connection dropped
  *
  *  @param event Event to handle
  */
 void GdbServerWindow::OnSocketEvent(wxSocketEvent& event) {
    LOGGING_Q;

    if (event.GetSocket() != clientSocket) {
       statusTextControl->AppendText(_("Event from unknown socket\n"));
       return;
    }
    // Now we process the event
    switch(event.GetSocketEvent()) {
       case wxSOCKET_INPUT: {
          if (clientSocket != NULL) {
             clientSocket->SetNotify(wxSOCKET_LOST_FLAG);
          }
          if (deferredOpen) {

             // Open on first access after socket creation
             setDeferredOpen(false);

             USBDM_ErrorCode rc = bdmInterface->initBdm();
             if (rc != BDM_RC_OK) {
                reportError("BDM Open failed, reason: ", GdbHandler::M_FATAL, rc);
                statusTextControl->AppendText(_("BDM Open failed\n"));
                log.print("BDM Open failed\n");
                dropConnection();
                return;
             }

             gdbInOut = new GdbInOutWx(clientSocket, statusTextControl);
             GdbHandler::GdbCallback cb = GdbMessageWrapper::getCallBack(this);
             gdbHandler = GdbHandlerFactory::createGdbHandler(bdmInterface->getBdmOptions().targetType, gdbInOut, bdmInterface, deviceInterface, cb, tty);
             rc = gdbHandler->initialise();
             if (rc != BDM_RC_OK) {
                bdmInterface->reset();
                rc = gdbHandler->initialise();
             }
             if (rc != BDM_RC_OK) {
                reportError("GDB Handler initialisation failed, reason: ", GdbHandler::M_FATAL, rc);
                log.print("GDB Handler initialisation failed\n");
                dropConnection();
                return;
             }
             statusTextControl->AppendText(_("BDM Open OK\n"));
          }
          // Triggers read of socket
          const GdbPacket *packet;
          USBDM_ErrorCode rc = BDM_RC_OK;
          do {
             // Process packets from GDB until idle
             packet = gdbInOut->getGdbPacket();
             if (packet != NULL) {
                rc = gdbHandler->doCommand(packet);
                if (rc != BDM_RC_OK) {
                   statusTextControl->AppendText(wxString(bdmInterface->getErrorString(rc), wxConvUTF8));
                }
             }
          } while ((packet != NULL) && (rc == BDM_RC_OK) && !deferredFail);

          if (deferredFail) {
             // A fatal error was reported - drop connection
             log.print("DeferredFail\n");
             dropConnection();
          }
          else {
             // Poll target immediately (also adjusts polling rate)
             pollTarget();
          }
          if (clientSocket != NULL) {
             clientSocket->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
          }
          break;
       }
       case wxSOCKET_LOST: {
          serverState = listening;
          log.print("wxSOCKET_LOST\n");
          dropConnection();
          break;
       }
       default:
          statusTextControl->AppendText(_("Unexpected event on socket!\n"));
          break;
    }
    UpdateStatusBar();
 }

 /*!  Poll target to check run status
  *
  */
 void GdbServerWindow::pollTarget() {
    LOGGING_Q;
    static GdbHandler::GdbTargetStatus lastTargetStatus = GdbHandler::T_UNKNOWN;

    targetStatus = GdbHandler::T_NOCONNECTION;

    int pollInterval = pollIntervalFast;

    if (gdbHandler == 0) {
       log.print("Stopping timer\n");
       if (statusTimer != 0) {
          statusTimer->Stop();
       }
       return;
    }

    if (deferredOpen || deferredFail) {
       // Don't poll before opening target or shutting down
       return;
    }
    targetStatus = gdbHandler->pollTarget();
    log.print("Status = %s\n", GdbHandler::getStatusName(targetStatus));
    switch (targetStatus) {
       case GdbHandler::T_HALT:
       case GdbHandler::T_RESET:
          pollInterval = pollIntervalSlow;
          entryTextControl->Enable(0);
          break;
       case GdbHandler::T_USER_INPUT:
          entryTextControl->Enable();
          pollInterval = pollIntervalSlow;
          break;
       default:
          entryTextControl->Enable(0);
          break;
    }

    if (targetStatus != lastTargetStatus) {
       lastTargetStatus = targetStatus;
       UpdateStatusBar();
    }
    if (statusTimer != 0) {
       statusTimer->Start(pollInterval, wxTIMER_ONE_SHOT);
    }
 }

 /*!  Update status bar
  *
  */
 void GdbServerWindow::UpdateStatusBar() {

 #if wxUSE_STATUSBAR
    wxString serverStatusString = wxEmptyString;
    switch(serverState) {
       case idle :
          serverStatusString = _("Server not running");
          break;
       case connected :
          serverStatusString = _("Client @") + clientAddr;
          break;
       case listening :
          serverStatusString = _("Listening @") + serverAddr;
          break;
       case abort :
          serverStatusString = _("Server Abort");
          break;
    }
    SetStatusText(serverStatusString, 1);

    SetStatusText(GdbHandler::getStatusName(targetStatus), 2);
 #endif // wxUSE_STATUSBAR
 }
