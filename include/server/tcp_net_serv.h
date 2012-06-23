#include <SFML/Network.hpp>
#include <Windows.h>
#include <iostream>

using namespace std;
using namespace sf;

class ServerTCP
{
public:
	//Connect to server with a port and server ip address/name
	void	Launch(unsigned short port);
	int 	MessageTheClients(string msg);
	void	Shutdown();
	void	RestartServer(unsigned short port);

private:
	Time		timeout;
	string		msgClient;
	TcpSocket	clientSocket;
	bool		shuttingDown;
	TcpListener servListener;

protected:
	void SetTimeout(int iMilliseconds);	//Connection timeout in milleseconds
};