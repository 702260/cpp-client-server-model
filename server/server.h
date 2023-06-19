#ifndef SOCKETSERVER_H

#define SOCKETSERVER_H

#include <iostream>

#include <unistd.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <netinet/in.h>

#include <iomanip>

#include <string.h>

#define FAILED_ -1

#define SUCCESS 0

#define MSG_SIZE 6

#define MAX_CONNECTIONS 20

#define DEFAULT_IP "127.0.0.1"

using namespace std;

class SocketServer
{
public:

  SocketServer(int port=5000):port(port) {}

  ~SocketServer() {};

  void getinfo(){cout<<this->port<<endl;}

  int CreateSocket();

  int Bind();

  int Listen();

  void Accept();

  void ReceiveAndClose();

private:

  int port;

  int socket_fd;

  int data_socket_fd;

  struct sockaddr_in serv_addr;

  char msg[1024];

  int msgsize = 1024; 

};

#endif 
