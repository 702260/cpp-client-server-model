#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SERVER_MSG_SIZE 6
#define FAILED_ -1
#define SUCCESS 0

using namespace std;

class SocketClient
{
public:
  SocketClient(std::string ip="127.0.0.1", int port=5000):port(port),address(ip){}
  ~SocketClient() {};
  void getinfo(){cout<<this->address<<" "<<this->port<<endl;}
  int CreateSocket();
  int Bind();
  int Connect();
  int SendReceiveAndClose();

private:
  int port;
  int socket_fd;
  char ServerMsg[SERVER_MSG_SIZE];
  char msg [1024]; 
  int  msgsize = 1024;
  struct sockaddr_in ServerInfo;
  string address;
};

#endif
