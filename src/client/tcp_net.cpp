#include "client/tcp_net.h"


//#include "out_helper.h"

using namespace std;

//public funcs

ThreadClass::ThreadClass(ClientTCP* passedClientTCP){
	this->clientTCP = passedClientTCP;
}
void ThreadClass::Run() {
         
	clientTCP->client.setBlocking(false);
	int status;
	sf::Packet tmpPacket;

	while(true){		
		sleep(sf::milliseconds(100));
		// Wait for connection and then put any recieved messages on a queue, while reading another queue of msgs to be sent
		if(clientTCP->client.connect(clientTCP->serverIP, clientTCP->portNumber, clientTCP->timeout) != clientTCP->client.Disconnected){
			if(clientTCP->client.receive(tmpPacket) == clientTCP->client.Done){
				// some data recieved, store on queue for update procedures to deal with
				WorkQueues::packetsToProcess().push(tmpPacket);
				//cout << "data received \n";
			}
			if(WorkQueues::packetsToSend().size() > 0){
				// Queue has messages to send, get and process
				//printf("%i \n", WorkQueues::packetsToSend().size());
				for(int i = 0; i < WorkQueues::packetsToSend().size(); i++){
					
					
					clientTCP->client.send(WorkQueues::packetsToSend().front());
					WorkQueues::packetsToSend().pop();				
				}				
			}
		}
	}
	//printf("testing ");		 
}




ClientTCP::ClientTCP(Game* mainGame){
	game = mainGame;
	/*packetsToSend.;
	packetsToProcess;*/
	this->clientTCP = this;

	// Setup Server
	this->portNumber = 4000;
	this->serverIP = "127.0.0.1";
   
	
  
}

//void ClientTCP::ThreadRun(int inte){//ClientTCP* clientTCP){
	//clientTCP->client.setBlocking(false);
	//int status;
	//sf::Packet tmpPacket;

	//while(true){

	//	// Wait for connection and then put any recieved messages on a queue, while reading another queue of msgs to be sent
	//	if(clientTCP->client.connect(clientTCP->serverIP, clientTCP->portNumber, clientTCP->timeout) != clientTCP->client.Disconnected){
	//		if(clientTCP->client.receive(tmpPacket)== clientTCP->client.Done){
	//			// some data recieved, store on queue for update procedures to deal with
	//			clientTCP->packetsToProcess.push(tmpPacket);
	//		}
	//		if(clientTCP->packetsToSend.size() > 0){
	//			// Queue has messages to send, get and process
	//			for(int i = 0; i < clientTCP->packetsToSend.size(); i++){
	//				;
	//				clientTCP->client.send(clientTCP->packetsToSend.front());
	//				clientTCP->packetsToSend.pop();				
	//			}				
	//		}
	//	}
	//}
	//	// loop 

	
//}




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


	/*
	game->GetPlayer()->SetPosition(3.0f,4.0f);
	sf::Packet packet = packets.CreateSendThisPlayerPos(game->GetPlayer()->GetPosition(), game->GetPlayer()->GetDirection());
	client.send( packet );
*/


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
