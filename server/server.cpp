# include "server.h"

int SocketServer :: CreateSocket()
{
  this->socket_fd = socket ( AF_INET,  SOCK_STREAM,  0);
  
     if(this->socket_fd < 0)
       return FAILED_;
    
       return SUCCESS;
  }
 
int SocketServer :: Bind()
{
  this->serv_addr.sin_family = AF_INET;
  this->serv_addr.sin_addr.s_addr = INADDR_ANY;
  this->serv_addr.sin_port = htons (this->port);
        
  return bind(this->socket_fd, (struct sockaddr *) &this->serv_addr , sizeof(this->serv_addr));
  }

int SocketServer :: Listen()
{
  if(listen(this->socket_fd, MAX_CONNECTIONS) < 0)
    return FAILED_;

    return SUCCESS;
  }

void  SocketServer ::  Accept()
{
  cout<<"[INFO]: Server is Running"<<endl;
  this->data_socket_fd = accept (this->socket_fd, (struct sockaddr *) NULL, NULL);

  if(this->data_socket_fd > 0)
      cout<<" Connection Accepted with ID:"<< this->data_socket_fd <<endl;
  else
      cout<<"[ERROR] : Connection Not Accepted\n" << endl;

  if(recv(this->data_socket_fd,msg,msgsize,0))
      cout<<msg<<endl;
  else
      cout<<"Error occured while receiving message"<<endl; 
   
  char msg1[1024]; 
      cin.getline(msg1,1024); 
  
  if(send(this->data_socket_fd,msg1,200, 0))      
      cout<<"Message sent to client successfully!"<<endl; 
  else
      cout<<"Error occured while sending message"<<endl;  
   
     close(this->data_socket_fd);
       exit(0);
    }
