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
#include <shared/Enums.h>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <shared/MapLoader.h>
#include <shared/randomc.h>
#include <ctime>

using namespace std;

 struct ClientInformation 
  {
    int health;
    int killCount;
    int currWeapon;
    int currPowerUp;
    int specBonus;
    sf::Vector2f position;
    float dirFacing;
    sf::TcpSocket* clientSocket;

    
  };


class TCP_Net_Serv2
{
protected:
  sf::TcpListener          	servListener;
  sf::TcpSocket           	clientSocket; 
  sf::SocketSelector       	selector;
  unsigned short	       	port;   
  sf::Time                 	timeout;
  std::vector<ClientInformation> allClients;
  
  std::string              	msgClient;
  bool        	         	shuttingDown;
  int 				maxClients;
  int               readyClients;
  unsigned int			clientCount;
  bool				serverUp;
  Maps              currMap;
  std::vector<Tile>      currMapObj;
  std::vector<Item> itemsOnMap;
  MapLoader mapLoader;

  void WaitForClients(void);
  
  void AddClient(sf::SocketSelector* selector);
  void SendOutStart(void);
  void SendData(void);
  void DisconnectClient(sf::TcpSocket *client);
  void ReceiveData(int index, ClientInformation* client);
  void SendPositionToAllExcludingSender(int index, ClientInformation* client, sf::Vector2f playerPosition, float currDirectionFacing);
  void SetMap(Maps map);
  bool ReadHealth(ClientInformation* player, HealthBits healthPosition);
  void SetHealth(ClientInformation* player, HealthBits healthPosition, bool value);
  void SetFullHealth(ClientInformation* player);

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
