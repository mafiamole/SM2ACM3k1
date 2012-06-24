#ifndef TCP_NET_H
#define TCP_NET_H

#include <SFML/Network.hpp>
#include <client/Game.hpp>
#include <iostream>
#include <shared/Packets.h>
#include <client/Player.h>
#include <queue>
#include <SFML/System/Thread.hpp>
#include <SFML/Config.hpp>
#include <client/WorkQueues.h>



using namespace std;
using namespace sf;


class ClientTCP
{
public:
	//Connect to server with a port and server ip address/name
	ClientTCP(Game* mainGame);
	void		ConnectToServer(unsigned short port, string address);
	int 		MessageTheServer(string msg);
	void		SetTimeout(int iMilliseconds);	//Connection timeout in milleseconds
	unsigned short portNumber;
	std::string serverIP;
	TcpSocket	client;
	Time		timeout;
	ClientTCP* clientTCP;
protected:
	
private:
	//void		OutputTest(LPCSTR arg);	//for testing purposes
	Game*	    game;	
	string		msg2Serv;	
	bool		connected;
	Packets     packets;
};

 
class ThreadClass
{
public:
	ThreadClass(ClientTCP* passedClientTCP);
	ClientTCP* clientTCP;
	void Run();    
};
#endif