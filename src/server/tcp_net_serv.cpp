#include "tcp_net_serv.h"
#include "out_helper.h"

using namespace std;

//public funcs
//Launch the server and wait for incoming connection
void ServerTCP::Launch(unsigned short port)
{
	shuttingDown = false;
	//Create a listener to wait for incoming connections
	servListener.listen(port);
	cout << "Server is listening to port " << port << ", waiting for connections...\n";

	//Wait for a connection
	servListener.accept(clientSocket);
	cout << "New client connected: " << clientSocket.getRemoteAddress() << "\n";

	//Recieve a message from the client
	//do 
	//{
		char	buf[1024] = "";
		size_t	recieved = 0;
		clientSocket.receive(buf,sizeof(buf), recieved);
		cout << "The client said: " << buf << "\n";
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
		if ((msg == NULL) || (msg == ""))	//Make sure that theres a message to send
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