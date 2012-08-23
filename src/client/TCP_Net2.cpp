/*
    Copyright (c) 2012 Paul Brown <email>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#include <client/TCP_Net2.hpp>

void TCP_Net_Thead2(ConnectionInfo info)
{
 
  TCP_Net2 tcpNet( info.address,info.port,info.attempts,info.timeout);
  
  tcpNet.Run();
}

TCP_Net2::TCP_Net2(std::string ipAddress,unsigned short port,unsigned int attempts, unsigned int timeout)
{
 this->connected 		= false;
 this->serverIP 		= sf::IpAddress(ipAddress);
 this->portNumber 		= port;
 this->connectionAttemptLimit 	= attempts;
 this->timeout 			= sf::milliseconds(timeout);
}

TCP_Net2::~TCP_Net2()
{

}

void TCP_Net2::Run()
{
  //first Connects
  
  clientSocket.setBlocking(true);

  sf::Packet tmpPacket;
  
  for ( unsigned int i = 1; i < this->connectionAttemptLimit; i++)
  {     
    // Attempt to connect
    std::cout << "Attempting new Connection" << std::endl;
    sf::Socket::Status connectStatus = this->clientSocket.connect(this->serverIP,this->portNumber,this->timeout);

    if(connectStatus == sf::Socket::Done){
        std::cout << "Connection established. Welcome to the Matrix." << std::endl;
        this->connected = true; 
        this->clientSocket.setBlocking(false); 
        break;
    }else{
        if(i==this->connectionAttemptLimit){ // Still more attempts to make
            std::cout << "Unable to establish connection." << std::endl;
        }
    }
  }


 
    while ( this->connected )
    {
      sf::sleep( sf::milliseconds(10) );
      
      sf::Socket::Status status = clientSocket.receive(tmpPacket);
      
      switch (status)
      {
	case sf::Socket::Disconnected:
	  std::cout << "You have been disconnected" << std::endl;
      this->connected = false;
	  break;
    case sf::Socket::Done:
	  WorkQueues::packetsToProcess().push(tmpPacket);
	  break;
	case sf::Socket::NotReady:
	  break;
	case sf::Socket::Error:
	  std::cerr << "Some error occured!" << std::endl;
	  break;
	default:
	  std::cerr << "IMPOSSIBRO!" << std::endl;
	break;
      } 

      
      // Send any pending data.
      if ( WorkQueues::packetsToSend().size() > 0 )
      {
	    for ( unsigned int i = 0; i < WorkQueues::packetsToSend().size(); i++)
	    {
	        sf::Socket::Status status2 = clientSocket.send( WorkQueues::packetsToSend().front() );
            if(status2 == sf::Socket::Done){
	            WorkQueues::packetsToSend().pop();
            }else{
                // Not ready to process packets, break.
                break;
            }
	    }
      }


    }
    
    std::cout << "Thank you for playing" << std::endl;
 }
  


