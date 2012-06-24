#include "server/tcp_net_serv.h"
#include <vector>
//#include <shared/out_helper.h>

using namespace std;

//public funcs
//Launch the server and wait for incoming connection
vector<sf::TcpSocket*> allSockets;


void ServerTCP::Launch(unsigned short port)
{
	shuttingDown = false;
	

	// Set number of clients to wait for
	while(allSockets.size() < 1){
		//Create a listener to wait for incoming connections
		servListener.listen(port);
		cout << "Server is listening to port " << port << ", waiting for connection...\n";
		//Wait for a connection
		sf::TcpSocket tmpSocket;
		servListener.accept(tmpSocket);
		cout << "New client connected: " << clientSocket.getRemoteAddress() << "\n";
		allSockets.push_back(&tmpSocket);
		
	}
	
	
	bool received = false;

	while(true){
		sf::Packet packet;
		allSockets.at(0)->receive(packet);

		int packetID;
		packet >> packetID;

		switch(packetID){
		case 1:
			// Curr player position, update internally, check for a collision and broadcast to all other players
			float positionX;
			float positionY;
			float currDirectionFacing;
			packet >> positionX >> positionY >> currDirectionFacing;

			break;
		}

	}



	//Recieve a message from the client
	//do 
	//{
		///*char	buf[1024] = "";
		//size_t	recieved = 0;
		//clientSocket.receive(buf,sizeof(buf), recieved);
		//cout << "The client said: " << buf << "\n";*/
	//
	//} while (!shuttingDown);
}

void ServerTCP::RestartServer(unsigned short port)
{
	shuttingDown = false;
	//Create a listener to wait for incoming connections
	servListener.close();
	servListener.listen(port);
	cout << "Server is listening to port " << port << ", waiting for connections...\n";

	//Wait for a connection
	servListener.accept(clientSocket);
	cout << "New client connected: " << clientSocket.getRemoteAddress() << "\n";
}

int ServerTCP::MessageTheClients(string msg)
{
	if (clientSocket.getRemoteAddress().None == IpAddress::None)
	{
		cout << "No client connected.\n";
		return -1;
	}
	else
	{
		if ((msg.size() < 2) || (msg == ""))	//Make sure that theres a message to send
		{
			cout << "Please enter a message.\n";
			return 0;
		}
		else
		{
			clientSocket.send(msg.c_str(), msg.size()+1);
			return 1;
		}
	}
}

void ServerTCP::Shutdown()
{
	shuttingDown = true;
	clientSocket.disconnect();
}
