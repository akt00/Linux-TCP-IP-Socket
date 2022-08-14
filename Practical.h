#ifndef _PRACTICAL
#define _PRACTICAL

#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


enum sizeConstants {
  MAXSTRINGLENGTH = 128,
  BUFSIZE = 512,
};

// Handle error with user msg
void DieWithUserMessage(const char *msg, const char *detail);

// Handle error with sys msg
void DieWithSystemMessage(const char *msg);

// Print socket address
void PrintSocketAddress(const struct sockaddr *address, FILE *stream);

int SetupTCPClientSocket(const char *host, const char *service);

// Create, bind, and listen a new TCP server socket
int SetupTCPServerSocket(const char *service);


static const int MAXPENDING = 5; // Maximum outstanding connection requests
// Handle new TCP client
void HandleTCPClient(int clntSocket);

// Accept a new TCP connection on a server socket
int AcceptTCPConnection(int servSock);

// Create and connect a new TCP client socket
int SetupTCPClientSocket(const char *server, const char *service);

void PrintSocketAddress(const struct sockaddr *address, FILE *stream);

// Test socket address equality
bool SockAddrsEqual(const struct sockaddr *addr1, const struct sockaddr *addr2);


#endif // _PRACTICAL
