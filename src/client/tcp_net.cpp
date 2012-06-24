#include "client/tcp_net.h"
//#include "out_helper.h"

using namespace std;

//public funcs

ClientTCP::ClientTCP(Game* mainGame){
	game = mainGame;
}

void ClientTCP::ConnectToServer(unsigned short port, string address)
{
	if (client.connect(address, port, timeout))	//try to connect to the specified server
	{
		//odprintf("Cannot connect to server. Socket connection error %s \n", address);
		cout << "Cannot connect to server. Socket connection error " << address << "\n";
		connected = false;
		return;
	}
	//odprintf("Connected to server %s \n", address);	//Successfully connected to the server
	cout << "Connected to server " << address << "\n";
	connected = true;


	
	game->GetPlayer()->SetPosition(3.0f,4.0f);
	client.send(packets.CreateSendThisPlayerPos(game->GetPlayer()->GetPosition(), game->GetPlayer()->GetDirection()));


	//if ((msg2Serv == NULL) || (msg2Serv == ""))	//Make sure that theres a message to send
	//{
	//	odprintf("No Message");
	//	return;
	//}
	//
	//if (client.send(msg2Serv.c_str(), msg2Serv.size()+1))
	//{
	//	odprintf("Message failed to send \"%s\"\n", msg2Serv);
	//	return;
	//}
	//odprintf("Message successfully sent :)");
	//string msg = "test 2000000000\n";
	//MessageTheServer(msg);

	////Retrieve any messages from the server
	//char	buf[1024] = "";
	//size_t	recieved = 0;
	//if (client.receive(buf, sizeof(buf), recieved) != Socket::Done)
	//{
	//	//odprintf("Message not recieved...");
	//	cout << "Message not recieved...\n";
	//	return;
	//}
	////odprintf("Message received from server: \"%s\"", buf);
	//cout << "Message recieved from server: " << buf << "\n";

	client.disconnect();
}

//void ClientTCP::MessageTheServer(string msg) 
//{
//	msg2Serv = msg;
//}

int ClientTCP::MessageTheServer(string msg)
{
	if (!connected)
	{
		//odprintf("Not connected to server.\n");
		cout << "Not connected to server.\n";
		return -1;
	}
	else
	{
		if (msg == "")	//Make sure that theres a message to send
		{
			//odprintf("Please enter a message.\n");
			cout << "Please enter a message.\n";
			return 0;
		}
		

		client.send(msg.c_str(), msg.size()+1);
		return 1;
	}
}

//private funcs
//helper func for displaying errors and other info, when paul fixes code :@
//void ClientTCP::OutputTest(LPCSTR arg)
//{
//	OutputDebugStringA(arg);
//}


//protected funcs
void ClientTCP::SetTimeout(int iMilliseconds)
{
	timeout = milliseconds(iMilliseconds);
}
