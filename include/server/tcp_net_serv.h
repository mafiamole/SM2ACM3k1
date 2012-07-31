#ifndef TCP_NET_SERV_H
#define TCP_NET_SERV_H

 
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <shared/Packets.h>
#include <bitset>

//#include "server\threadClass2.h"

 

using namespace std;
using namespace sf;
 

class ServerTCP
{

public:
       ServerTCP(void);
       ~ServerTCP(void); 
       //Connect to server with a port and server ip address/name
       void   Launch(unsigned short p);
       int    MessageTheClients(string msg);
       void   Shutdown();
       void   RestartServer(unsigned short p);

private:
       void   WaitForClients();
       void   SendData();
       void   DisconnectClient(TcpSocket *client); 
	   TcpListener          servListener;
       Time                 timeout;
	   string               msgClient;
	   TcpSocket            clientSocket;
	   bool                 shuttingDown;
	   unsigned short       port;
       vector<TcpSocket*> allSockets; 

protected:
	       void SetTimeout(int iMilliseconds);      //Connection timeout in milleseconds

};
 

 struct ClientInformation 
  {
    bitset<4> health;
    int killCount;
    int currWeapon;
    int currPowerUp;
    int specBonus;
    sf::Vector2f position;
    float dirFacing;
    TcpSocket* clientSocket;
  };


#endif

 

 