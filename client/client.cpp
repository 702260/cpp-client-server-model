#include "client.h"

int SocketClient::CreateSocket()
{
  this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  if(this->socket_fd < 0)
    return FAILED_;

    return SUCCESS;
}

int SocketClient::Bind()
{
  char *IP = new char[sizeof(this->address.c_str())];

  strcpy(IP, this->address.c_str());

  this->ServerInfo.sin_family = AF_INET;

  this->ServerInfo.sin_addr.s_addr = inet_addr(IP);

  this->ServerInfo.sin_port = htons(this->port);

  delete IP;

    return SUCCESS;
}
 
int SocketClient::Connect()
{
  if(connect(socket_fd, (struct sockaddr *)&this->ServerInfo, sizeof(this->ServerInfo)) !=0)
    {
    cout<< "[ERROR]: Error connecting to server" << endl;
      return FAILED_;
    }	

  cout<<"[INFO]: Connection Successful"<<endl;

    return SUCCESS;
}

int SocketClient::SendReceiveAndClose()
{
    char msg1[1024];
      cin.getline(msg,1024); 
 
    if(send(this->socket_fd,this->msg,msgsize,0))
      cout<<"Message sent to server"<<endl;   
    else
      return FAILED_; 

    if(recv(this->socket_fd,msg1, 1024,0))
      cout<<msg1<<endl; 
    else
      return FAILED_;    

    close(socket_fd);
      return SUCCESS;
}

