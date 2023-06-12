 # include "server.h"
  
 int main()
    {
   SocketServer soc;
 
  if(soc.CreateSocket() == FAILED_ )
     {
   
     perror("[ERROR]");
 
    exit(EXIT_FAILURE);

    }

  if(soc.Bind() == FAILED_ )
     {
       perror("[ERROR]");
       exit(EXIT_FAILURE);
    }

 if(soc.Listen() == FAILED_ )
   {
    perror("[ERROR]");
    exit(EXIT_FAILURE);
    }

  soc.Accept();
  
  	return 0;

     }	
