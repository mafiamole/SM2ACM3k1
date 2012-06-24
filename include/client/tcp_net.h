#include <SFML/Network.hpp>
#include <client/Game.hpp>
#include <iostream>
#include <shared/Packets.h>
#include <client/Player.h>

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

private:
	//void		OutputTest(LPCSTR arg);	//for testing purposes
	Game*	game;
	Time		timeout;
	string		msg2Serv;
	TcpSocket	client;
	bool		connected;
	Packets packets;
};
