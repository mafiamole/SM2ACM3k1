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


#ifndef TCP_NET2_H
#define TCP_NET2_H
#include <SFML/Network/TcpSocket.hpp>
#include <client/WorkQueues.h>

class TCP_Net2
{
protected:
    sf::TcpSocket 	clientSocket;
    std::string		messageToServer;
    Packets 		packets;
    sf::Time 		timeout;
    sf::IpAddress	serverIP;
    bool 		connected;
    unsigned int 	connectionAttemptLimit;
    unsigned short	portNumber;
public:
  
			TCP_Net2(std::string IpAddress, short unsigned int port, unsigned int attempts, unsigned int timeout);
			
    virtual 		~TCP_Net2();
    
    void 		Run();
    
    
};

struct ConnectionInfo
{
  std::string 		address;
  unsigned short 	port;
  unsigned int 		attempts;
  unsigned int 		timeout;
};

void TCP_Net_Thead2(ConnectionInfo info);




#endif // TCP_NET2_H

