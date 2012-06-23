#include <Windows.h>
#include <server/Game.hpp>
#include "tcp_net_serv.h"

using namespace std;

int main(int argc, char **argv)
{
	//Game game("Lol cam.");
	//game.Run(argc,argv);

	ServerTCP	serv;
	unsigned	port = 55001;
	string msg = "";
	//do 
	//{
	//	cout << "Type in the port that this server will use.\n";
	//	cin >> port;

	//	if ((port <= 1024) || (port >= 65535))
	//		cout << "Port must be between 1024 and 65535\n";
	//
	//} while ((port <= 1024) || (port >= 65535));
	serv.Launch(port);

	char input = '\0';
	while (input != 'e')
	{
		cout << "Type ('c') to send messages to the clients, ('r') to restart the server and ('e') to exit\n";
		if (!(cin >> input))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid Input!\n";
			continue;
		}

		switch (input)
		{
		case 'c':
			cout << "Type in a message...\n";
			cin >> msg;
			serv.MessageTheClients(msg);
			break;

		case 'r':
			serv.RestartServer(port);
			break;

		case 'e':
			serv.Shutdown();
			return 0;
			break;

		default:
			cout << "Invalid command\n";
			break;
		}
	}
}
