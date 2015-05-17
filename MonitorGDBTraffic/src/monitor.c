#ifdef WIN32
#include <Winsock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#define closesocket close
#endif
#include <stdio.h>
#include <sys/time.h>

#define GDB_CLIENT_PORT       1234 // Client port (GDB connection)
#define GDB_SERVER_PORT       4000 // Server port number

int  gdbClientPort  = GDB_CLIENT_PORT; // Port for clients to connect to (GDB program)
int  gdbServerPort  = GDB_SERVER_PORT; // Existing GDB Server port number (GDB server)

#define LOCAL_HOST_NAME       "localhost"
#define D_QUEUE               1
#define D_SOCKETS             1
#define D_INFO                256
#define CONNECTION_DELAY      20 // seconds

#define GDB_OK               (0)
#define GDB_FATAL_ERROR      (1)
#define GDB_NON_FATAL_ERROR  (2)

#ifndef EWOULDBLOCK
#define EWOULDBLOCK     WSAEWOULDBLOCK
#endif

#ifdef _WIN32
#define NET_ERROR_NUM WSAGetLastError()
#else
#define NET_ERROR_NUM errno
#endif

/*
 *  Create Socket
 *
 *  @param returnSocket
 *
 *  @return GDB_OK on success
 *
 */
int createSocket(int *returnSocket, int portNumber, boolean nonBlocking) {

   fprintf(stderr, "Creating socket...\n"); fflush(stderr);

   // Set up for fail
   *returnSocket = INVALID_SOCKET;

   //  Create the new socket
   //
   int newSocket = socket(AF_INET, SOCK_STREAM, 0);
   if (newSocket < 0) {
      fprintf(stderr, " Create socket (socket()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_FATAL_ERROR;
   }

   // Allow socket descriptor to be reusable
   //
   int optionValue = 1;
   if (setsockopt(newSocket, SOL_SOCKET,  SO_REUSEADDR, (char *)&optionValue, sizeof(optionValue)) < 0) {
      fprintf(stderr, "Setting socket options (setsockopt()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      closesocket(newSocket);
      return GDB_FATAL_ERROR;
   }

   if (nonBlocking) {
      // Set socket to be non-blocking.  All of the sockets for the incoming connections
      // will also be non-blocking since they will inherit that state from this
      //
#ifdef WIN32
      unsigned long option2 = 1;
      int result = ioctlsocket(newSocket, FIONBIO, &option2);
#else
      char option2 = 1;
      int result = ioctl(newSocket, FIONBIO, (char *)&option2);
#endif
      if (result < 0 ) {
         fprintf(stderr, "ioctl() failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
         closesocket(newSocket);
         return GDB_FATAL_ERROR;
      }
   }
   //  Get information about the host
   struct sockaddr_in addr;
   memset(&addr, 0, sizeof(addr));

   struct hostent *host;
   host = gethostbyname(LOCAL_HOST_NAME);
   if (host == NULL) {
      fprintf(stderr, "Get host information (gethostbyname()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      closesocket(newSocket);
      return GDB_FATAL_ERROR;
   }

   if (portNumber > 0) {
      //  Bind the socket to an address and port
      memcpy(&addr.sin_addr, &host->h_addr_list[0], sizeof(host->h_addr_list[0])); // check
      addr.sin_family      = AF_INET;
      addr.sin_addr.s_addr = htonl(INADDR_ANY);
      addr.sin_port        = htons(portNumber);
      if (bind(newSocket, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
         fprintf(stderr, "Binding socket to address & port (bind()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
         fprintf(stderr, "port = %d", portNumber); fflush(stderr);
         closesocket(newSocket);
         return GDB_FATAL_ERROR;
      }
   }
   *returnSocket = newSocket;
   return GDB_OK;
}

// Non-blocking wait for client connection
//
int waitForConnection(int listenSocket, int *clientSocket) {

   *clientSocket = -1;

   /*  Listen for single connections  */
   if (listen(listenSocket, 1) != 0) {
      fprintf(stderr, "Listening for connection (listen()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_FATAL_ERROR;
   }
   fd_set input;
   FD_ZERO(&input);
   FD_SET(listenSocket, &input);
   struct timeval tv;
   tv.tv_sec  = CONNECTION_DELAY;
   tv.tv_usec = 0;

   fprintf(stderr, "Waiting for connection @%d ... ", gdbClientPort); fflush(stderr);
   int result = select(1, &input, NULL, NULL, &tv);

   fprintf(stderr, "Activity detected (or timeout) (select())\n"); fflush(stderr);

   if (result < 0) {
      // select() failed
      fprintf(stderr, "Waiting for connection (select()) failed with fatal error. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_FATAL_ERROR;
   }
   if (result == 0) {
      fprintf(stderr, "Waiting for connection (select()) failed no connection (timeout). Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_NON_FATAL_ERROR;
   }
   if (FD_ISSET(listenSocket , &input)) {
      SOCKET theConnection = accept(listenSocket, NULL, NULL );
      if (theConnection == INVALID_SOCKET) {
         fprintf(stderr, "Accepting connection (accept()) failed with fatal error. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
         return GDB_FATAL_ERROR;
      }
      *clientSocket = theConnection;
   }
   fprintf(stderr, "Client connection established\n"); fflush(stderr);
   return GDB_OK;
}

int connectToServer(int sendSocket) {

   //  Get information about the host
   struct sockaddr_in serv_addr;

   fprintf(stderr, "Connecting to gdbServer @%d... ", gdbServerPort); fflush(stderr);
   struct hostent *server;
   server = gethostbyname(LOCAL_HOST_NAME);
   if (server == NULL) {
      fprintf(stderr, "Failed. Get host information (gethostbyname()). Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_FATAL_ERROR;
   }

   memset(&serv_addr, 0, sizeof(serv_addr));
   memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
   serv_addr.sin_family      = AF_INET;
   serv_addr.sin_port        = htons(gdbServerPort);

   // Connect to server
   int result = connect(sendSocket, (SOCKADDR *)&serv_addr, sizeof(serv_addr));

   if (result != 0) {
      fprintf(stderr, "Failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return GDB_FATAL_ERROR;
   }
   fprintf(stderr, "Connected.\n"); fflush(stderr);

   return GDB_OK;
}

void sanitize(char *to, char *from, int size) {
   if ((*from == '\x03') && (size == 1)) {
      strcpy(to, "<<<<break>>>>");
      return;
   }
   int sub;
   for(sub=0; sub<size; sub++) {
      if ((from[sub]<0x20) || (from[sub] > 0x7F)) {
         to[sub] = '.';
      }
      else {
         to[sub] = from[sub];
      }
   }
   to[size] = '\0';
}

void writeMsg(boolean tx, char *msg, int size) {
   static const char SEND_PREFIX1[]    = " ==>";
   static const char SEND_PREFIX2[]    = "    ";
   static const char RECEIVE_PREFIX1[] = "<== ";
   static const char RECEIVE_PREFIX2[] = "    ";
   static const int  BUFF_SIZE        = 100;

   const char *prefix;
   if (tx) {
      prefix = SEND_PREFIX1;
   }
   else {
      prefix = RECEIVE_PREFIX1;
   }
   char buff[BUFF_SIZE];
   while (size>0) {
      int portion = BUFF_SIZE-10;
      if (portion > size) {
         portion = size;
      }
      if (tx) {
         sanitize(buff, msg, portion);
         strcat(buff, prefix);
         fprintf(stdout, "%s\n", buff); fflush(stdout);
         prefix = SEND_PREFIX2;
      }
      else {
         strcpy(buff, prefix);
         sanitize(buff+sizeof(RECEIVE_PREFIX1)-1, msg, portion);
         fprintf(stdout, "%*s%s\n", BUFF_SIZE, "", buff); fflush(stdout);
         prefix = RECEIVE_PREFIX2;
      }
      msg   += portion;
      size  -= portion;
   }
}

int getData(boolean tx, double timeStamp, int fd, char buff[], int size) {

   memset(buff, 0, size);

   int rc = recv(fd, buff, D_INFO, 0);
   int errNum = NET_ERROR_NUM;
   if ((rc <= 0) && (errNum != EWOULDBLOCK)) {
      fprintf(stderr, "recv() failed. Error = %d\n", errNum); fflush(stderr);
      return -GDB_FATAL_ERROR;
   }
   if (rc > 0) {
      writeMsg(tx, buff, rc);
      return rc;
   }
   return -GDB_NON_FATAL_ERROR;
}

int sendData(int fd, char buff[], int size) {
   int rc = send(fd, buff, size, 0);
   if (rc < 0) {
      fprintf(stderr, "  send() failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return -GDB_FATAL_ERROR;
   }
   return rc;
}

int waitForActivity(int clientSocket, int serverSocket) {
   fd_set input;
   FD_ZERO(&input);
   FD_SET(clientSocket, &input);
   FD_SET(serverSocket, &input);
   struct timeval tv;
   tv.tv_sec  = CONNECTION_DELAY;
   tv.tv_usec = 0;

   //   fprintf(stderr, "Waiting for activity... "); fflush(stderr);
   int result = select(2, &input, NULL, NULL, &tv);

   if (result == 0) {
      //      fprintf(stderr, "No activity\n"); fflush(stderr);
      return -GDB_NON_FATAL_ERROR;
   }
   if (result<0) {
      fprintf(stderr, "failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return -GDB_FATAL_ERROR;
   }
   if (FD_ISSET(clientSocket , &input)) {
      //      fprintf(stderr, "Client active\n"); fflush(stderr);
      return clientSocket;
   }
   if (FD_ISSET(serverSocket , &input)) {
      //      fprintf(stderr, "Server active\n"); fflush(stderr);
      return serverSocket;
   }
   //   fprintf(stderr, "Unknown activity\n"); fflush(stderr);
   return -GDB_FATAL_ERROR;
}

double timeval_subtract(struct timeval *x, struct timeval*y) {
   struct timeval result;

   /* Perform the carry for the later subtraction by updating y. */
   if (x->tv_usec < y->tv_usec) {
      int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
      y->tv_usec -= 1000000 * nsec;
      y->tv_sec += nsec;
   }
   if (x->tv_usec - y->tv_usec > 1000000) {
      int nsec = (x->tv_usec - y->tv_usec) / 1000000;
      y->tv_usec += 1000000 * nsec;
      y->tv_sec -= nsec;
   }

   /* Compute the time remaining to wait.
    * tv_usec is certainly positive.
    */
   result.tv_sec  = x->tv_sec  - y->tv_sec;
   result.tv_usec = x->tv_usec - y->tv_usec;

   /* Return 1 if result is negative. */
   return result.tv_sec + ((double)result.tv_usec/1000000);
}


#if 0
int connectToClient(int listenSocket) {

   SOCKET theSocket = -1;

   int result = waitForConnection(listenSocket, &theSocket);

   if (result != GDB_OK) {
      fprintf(stderr, "No client connection\n"); fflush(stderr);
      return result;
   }

   fprintf(stderr, "Accepted connection\n"); fflush(stderr);

   char buffer[D_INFO];
   int size;
   do {
      memset(buffer, 0, sizeof(buffer));
      size = getData(theSocket, buffer);
      if (size > 0) {
         fprintf(stderr, "%3d[%s]\n", size, buffer); fflush(stderr);
      }
      result = -size;
   } while (result != GDB_FATAL_ERROR);

   fprintf(stderr, "Closing client connection\n"); fflush(stderr);

   return GDB_NON_FATAL_ERROR;
}

#endif

int doSession(int listenSocket) {
   int serverSocket = INVALID_SOCKET;    // Connection to the server (gdbserver)
   int clientSocket = INVALID_SOCKET;    // Connection to the client (GDB)

   int rc = GDB_OK;

   // Wait for connection from GDB
   do {
      rc = waitForConnection(listenSocket, &clientSocket);
   } while (rc == GDB_NON_FATAL_ERROR);

   if (rc == GDB_FATAL_ERROR) {
      return GDB_FATAL_ERROR;
   }

   // Connect to gdbserver
   if (createSocket(&serverSocket, -1, FALSE) != GDB_OK) {
      return GDB_FATAL_ERROR;
   }
   if (connectToServer(serverSocket) != GDB_OK) {
      return GDB_FATAL_ERROR;
   }

   // Transfer data (GDB Session)
   do {
      struct timeval sendTime;
      gettimeofday(&sendTime, NULL);

      char buffer[4000];
      int size = 0;
      int activeSocket = waitForActivity(clientSocket, serverSocket);
      if (activeSocket == clientSocket) {
         gettimeofday(&sendTime, NULL);
         size = getData(TRUE, 0, clientSocket, buffer, sizeof(buffer));
         if (size > 0) {
            sendData(serverSocket, buffer, size);
         }
         else if (size == -GDB_FATAL_ERROR) {
            rc = GDB_FATAL_ERROR;
         }
      }
      else if (activeSocket == serverSocket) {
         struct timeval currentTime;
         gettimeofday(&currentTime, NULL);
         double elapsedTime = timeval_subtract(&currentTime, &sendTime);
         size = getData(FALSE, elapsedTime, serverSocket, buffer, sizeof(buffer));
         if (size > 0) {
            sendData(clientSocket, buffer, size);
         }
         else if (size == -GDB_FATAL_ERROR) {
            rc = GDB_FATAL_ERROR;
         }
      }
      else if (activeSocket == -GDB_FATAL_ERROR) {
         rc = GDB_FATAL_ERROR;
      }
   } while ((rc != GDB_FATAL_ERROR));

   if (clientSocket >= 0) {
      closesocket(clientSocket);
   }
   if (serverSocket >= 0) {
      closesocket(serverSocket);
   }
   return GDB_NON_FATAL_ERROR;
}

void usage(void) {
   fprintf(stderr,
         "\n"
         "Usage: MonitorGDBTraffic <gdbServerPort> <clientPort>\n"
         "       <gdbServerPort> - port victim GDB Server is using\n"
         "       <clientPort>    - port provided by this program for clients to connect to\n"
         "\n"
         "This program monitors traffic between a GDB server and client\n");
}

int main(int argc, char **argv) {
   if ((argc != 1) && (argc != 3)) {
      usage();
      exit(EXIT_FAILURE);
   }

   if (argc == 3) {
      gdbServerPort = atoi(argv[1]);
      gdbClientPort = atoi(argv[2]);
   }
   fprintf(stderr, "Will expect  SERVER on port %d \n", gdbServerPort);
   fprintf(stderr, "Will provide CLIENT on port %d \n", gdbClientPort); fflush(stderr);

#ifdef WIN32
   // Initiate use of the Winsock DLL by this process.
   WSADATA wsaData;
   if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
      fprintf(stderr, "Winsock initialization (WSAStartup()) failed. Error = %d\n", NET_ERROR_NUM); fflush(stderr);
      return (1);
   }
#endif

   int listenSocket = INVALID_SOCKET;    // Connection to wait for client connections on

   if (createSocket(&listenSocket, gdbClientPort, FALSE) == GDB_OK) {
      for (;;) {
         doSession(listenSocket);
      }
   }
   if (listenSocket >= 0) {
      closesocket(listenSocket);
   }

#ifdef WIN32
   WSACleanup();
#endif

   return (EXIT_FAILURE);
}
