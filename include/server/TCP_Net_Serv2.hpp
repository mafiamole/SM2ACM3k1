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


#ifndef TCP_NET_SERV2_HPP
#define TCP_NET_SERV2_HPP
#include <shared/Packets.h>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
typedef std::list<sf::TcpSocket*> TcpSocketList;

class TCP_Net_Serv2
{
protected:
  sf::TcpListener          	servListener;
  sf::TcpSocket           	clientSocket; 
  sf::SocketSelector       	selector;
  unsigned short	       	port;   
  sf::Time                 	timeout;
  TcpSocketList 		clientSockets;
  
  std::string              	msgClient;
  bool        	         	shuttingDown;
  int 				maxClients;
  unsigned int			clientCount;
  bool				serverUp;
  
  void WaitForClients(void);
  
  void CLIHandle(); // was not sure what to name this. It iterates over the last set of inputed commands.
  void AddClient(sf::SocketSelector* selector);
  void SendOutStart(void);
  void SendData(void);
  void DisconnectClient(sf::TcpSocket *client);
  void ReceiveData(int index,sf::TcpSocket* client);
  void SendPlayerPositionToAll(int index, sf::TcpSocket* client, sf::Vector2f playerPosition, float currDirectionFacing);
  
public:
  TCP_Net_Serv2(unsigned short port,int MaxClients);
  virtual ~TCP_Net_Serv2();
  
  void Launch(void);

};

struct ServerSettings
{
  unsigned short port;
  int 		 maxClients;

};
void TCP_Net_Thread(ServerSettings settings);
#endif // TCP_NET_SERV2_HPP