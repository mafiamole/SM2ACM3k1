#include "server/tcp_net_serv.h"

 //public funcs
//Launch the server and wait for incoming connection
ServerTCP::ServerTCP(void)
{

}

 

ServerTCP::~ServerTCP(void)
{

 

}

 

void ServerTCP::Launch(unsigned short p)
{

       shuttingDown = false;
       bool received = false;
       

      

       //ThreadClass threadClass;

       ServerTCP     serv;
	   serv.port = p;
	   // Start listening, on connection, spawn new thread passing in the returned socket



       Thread        t(&ServerTCP::WaitForClients, &serv);

       //t.launch();

 

      // WaitForClients();
	    

       //sf::Thread t(&WaitForClients);
       t.launch();
       //Recieve a message from the client
       //do
       //{

              ///*char      buf[1024] = "";
              //size_t      recieved = 0;
              //clientSocket.receive(buf,sizeof(buf), recieved);
              //cout << "The client said: " << buf << "\n";*/
       //

       //} while (!shuttingDown);

}

 

void ServerTCP::RestartServer(unsigned short p)
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
              if ((msg.size() < 2) || (msg == ""))     //Make sure that theres a message to send
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

 

void ServerTCP::DisconnectClient(TcpSocket *client)
{
       Packet pck;
       pck >> "Server full, now disconnecting";
       client->send(pck);
       client->disconnect();
}

 
// Run loop for an individual connection to a client.
//void ServerTCP::SocketRun;


void ServerTCP::WaitForClients()
{
       // Set number of clients to wait for

			  int                  clientCount = 0;
			  //TcpSocket            tmpSocket;
              SocketSelector       selector;
              list<TcpSocket*>     clients;


//Create a listener to wait for incoming connections
servListener.listen(port);

cout << "Server is listening to port " << port << ", waiting for connection...\n"; //Wait for a connection
       while(true)
       {
              
      
              selector.add(servListener);
              if (selector.wait()) //wait for data on any socket
              {
                     if (selector.isReady(servListener))      //test listener
                     {
                           //listener ready, pending connection
                           TcpSocket* client = new TcpSocket;

                           if (servListener.accept(*client) == Socket::Done)
                           {
                                  clientCount++;
								  clients.push_back(client); //add the new client to the clients list
								  //Add the new client to the selector so that we will
                                  //be notified when he sends something
								  selector.add(*client);
								  cout << "New client connected: " << client->getRemoteAddress() << "\n";

								  if(clientCount == 2){ 
									  cout << "Max client count now reached. Further connections will be disconnected.\n"; 
								  }

                                  if (clientCount > 2)
                                  {
                                         DisconnectClient(client);
                                  }
                                 
                           }
                     }

                     else
                     {
                           //The listener socket is not ready, test all other sockets (the clients) and process incoming messages
						   int index = 0;
                           for (list<TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it)
                           {
                                  TcpSocket& client = **it;
                                  if (selector.isReady(client))
                                  {
                                         Packet packet;       //the client sent some data
                                         if (client.receive(packet) == Socket::Done)
                                         {
                                                cout << "Data received... " << client.getRemotePort() << " :-: ";
												int packetID;
												packet >> packetID;

												switch(packetID){
												case 1:
													sf::Vector2f playerPosition; 
													float currDirectionFacing;
													packet >> playerPosition.x >> playerPosition.y >> currDirectionFacing;
													printf("%d - %f - %f - %f\n", packetID, playerPosition.x, playerPosition.y, currDirectionFacing);

													// Loop through all attached clients (excluding one recieved from) and send player location

													for (list<TcpSocket*>::iterator it2 = clients.begin(); it2 != clients.end(); ++it2)
													{
														TcpSocket& client2 = **it2;
														
														sf::IpAddress ip1 = client.getRemoteAddress();
														sf::IpAddress ip2 = client2.getRemoteAddress();
														unsigned short p1 = client.getRemotePort();
														unsigned short p2 = client2.getRemotePort();
														

														if(( ip1 != ip2 ) || ((ip1 == ip2) && (p1 != p2))){
															  int newPacketID = 3; 
															  Packet newPacket;

															  newPacket << newPacketID << playerPosition.x << playerPosition.y << currDirectionFacing << index;
															  client2.send(newPacket);

														}


													}


													for(int i = 0; i < clients.size();i++){
												
													}


													break;
												}

												
												//packets.CreateSendThisPlayerPos
                                         }
                                  }
								  index++;
                           }
                     }
              }
       }
              //servListener.accept(tmpSocket);

              //allSockets.push_back(&tmpSocket);

}

 

void ServerTCP::SendData()
{
       while(true)
       {
              Packet packet;
              allSockets.at(0)->receive(packet);

 
              int packetID;
              packet >> packetID;
			   

              switch(packetID)

              {

              case 1:

                     // Curr player position, update internally, check for a collision and broadcast to all other players

                     float positionX;

                     float positionY;

                     float currDirectionFacing;

                     packet >> positionX >> positionY >> currDirectionFacing;

 

                     break;

              }

       }

}







//#include "server/tcp_net_serv.h"
//#include <vector>
//#include <shared/out_helper.h>
//
//using namespace std;
//
//public funcs
//Launch the server and wait for incoming connection
//vector<sf::TcpSocket*> allSockets;
//
//
//void ServerTCP::Launch(unsigned short port)
//{
//	shuttingDown = false;
//	
//
//	 Set number of clients to wait for
//	while(allSockets.size() < 1){
//		Create a listener to wait for incoming connections
//		servListener.listen(port);
//		cout << "Server is listening to port " << port << ", waiting for connection...\n";
//		Wait for a connection
//		sf::TcpSocket tmpSocket;
//		servListener.accept(tmpSocket);
//		cout << "New client connected: " << clientSocket.getRemoteAddress() << "\n";
//		allSockets.push_back(&tmpSocket);
//		
//	}
//	
//	
//	bool received = false;
//
//	while(true){
//		sf::Packet packet;
//		allSockets.at(0)->receive(packet);
//
//		int packetID;
//		packet >> packetID;
//
//		switch(packetID){
//		case 1:
//			 Curr player position, update internally, check for a collision and broadcast to all other players
//			float positionX;
//			float positionY;
//			float currDirectionFacing;
//			packet >> positionX >> positionY >> currDirectionFacing;
//
//			break;
//		}
//
//	}
//
//
//
//	Recieve a message from the client
//	do 
//	{
//		*char	buf[1024] = "";
//		size_t	recieved = 0;
//		clientSocket.receive(buf,sizeof(buf), recieved);
//		cout << "The client said: " << buf << "\n";*/
//	
//	} while (!shuttingDown);
//}
//
//void ServerTCP::RestartServer(unsigned short port)
//{
//	shuttingDown = false;
//	Create a listener to wait for incoming connections
//	servListener.close();
//	servListener.listen(port);
//	cout << "Server is listening to port " << port << ", waiting for connections...\n";
//
//	Wait for a connection
//	servListener.accept(clientSocket);
//	cout << "New client connected: " << clientSocket.getRemoteAddress() << "\n";
//}
//
//int ServerTCP::MessageTheClients(string msg)
//{
//	if (clientSocket.getRemoteAddress().None == IpAddress::None)
//	{
//		cout << "No client connected.\n";
//		return -1;
//	}
//	else
//	{
//		if ((msg.size() < 2) || (msg == ""))	//Make sure that theres a message to send
//		{
//			cout << "Please enter a message.\n";
//			return 0;
//		}
//		else
//		{
//			clientSocket.send(msg.c_str(), msg.size()+1);
//			return 1;
//		}
//	}
//}
//
//void ServerTCP::Shutdown()
//{
//	shuttingDown = true;
//	clientSocket.disconnect();
//}
