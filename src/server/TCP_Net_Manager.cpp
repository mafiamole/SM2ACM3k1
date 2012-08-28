/*
    Copyright (c) 2012 Paul Brown <email>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#include <server/TCP_Net_Manager.h>
#include <server/Match.h>

TCP_Net_Manager::TCP_Net_Manager(ServerSettings settings)
{
    this->port = settings.port;
    this->maxClients = settings.maxClients;
    this->port = port;

    this->readyClients = 0;
    this->clientCount = 0;
    this->serverUp = true;
}

TCP_Net_Manager::~TCP_Net_Manager()
{

}

void TCP_Net_Manager::SendPacket(int playerId, sf::Packet packetToSend)
{
  sf::Lock transmissionLock(transmissionMutex);
  //this->clientConnections[playerId].send(packetToSend);
  this->clientConnections[playerId]->send(packetToSend);
}

void TCP_Net_Manager::GrabPackets()
{
  int index;
  for (std::vector<sf::TcpSocket*>::iterator itr = clientConnections.begin(); itr != this->clientConnections.end(); ++itr)
  {

      if (selector.wait(sf::milliseconds(5)))
      {
          if (this->selector.isReady(*(*itr)))
          {
              this->ReceiveData(index,(*itr));
          }

      }
      index++;
  }
}

void TCP_Net_Manager::WaitForClients(int maxClients)
{
    this->servListener.listen( this->port );

    while ( (this->clientCount < maxClients) || (this->readyClients != maxClients))
    {
        this->selector.add( this->servListener );
        if ( this->selector.wait() )
        {
            if ( this->selector.isReady(servListener) )
            {
                this->AddClient(&selector);
            }
            else
            {
                this->ClientWaitInitCheck();
            }
        }
    }
}

void TCP_Net_Manager::ClientWaitInitCheck()
{
    int packetID;
    int bonusID;

    int index;
    index = 0;
    for (std::vector<sf::TcpSocket*>::iterator itr = clientConnections.begin(); itr != this->clientConnections.end(); ++itr)
    {
        sf::TcpSocket* client = (*itr);
        if (this->selector.isReady(*client))
        {
            sf::Packet packet;
            sf::Socket::Status status = client->receive(packet);

            if ( status == sf::Socket::Done)
            {
                packet >> packetID;

                if(packetID == CLIENT_SEND_BONUS) {
                    packet >> bonusID;
                    
                    this->currentMatch->ReadyPlayer(index,bonusID); // Not very Thread safe :(
                    
                    this->readyClients++;
                }

            }
        }
        index++;
    }
}
void TCP_Net_Manager::AddClient(sf::SocketSelector* selector)
{
    sf::TcpSocket* client = new sf::TcpSocket;
    if ( servListener.accept(*client) == sf::Socket::Done)
    {
        clientConnections.push_back(client);
        this->clientCount++;
        selector->add(*client);
        std::cout << "New client connected at " << client->getRemoteAddress() << std::endl;
    }
}
void TCP_Net_Manager::SendGoSignal()
{
    int index;
    int packetID;

    packetID = SERVER_INITALISE;
    int *IDsForWeapons  = new int[this->maxClients];
    float *positionX    = new float[this->maxClients];
    float *positionY    = new float[this->maxClients];

    index = 0;
    for (std::vector<sf::TcpSocket*>::iterator itr = clientConnections.begin(); itr != this->clientConnections.end(); ++itr)
    {
        // Loop through all clients and fill arrays to send in the packets
        
        //not thread safe!
        IDsForWeapons[index] = currentMatch->GetClientWeapon(index);
        positionX[index] = currentMatch->GetClientPos(index).x;
        positionY[index] = currentMatch->GetClientPos(index).y;
        index++;
    }

    for(int i = 0; i < this->maxClients; i++) {
        // Loop through all clients, create its packet and send
        sf::Packet packet;
        packet << packetID << this->maxClients;

        // Need to loop through all data arrays and push each item individually into packet.
        for(int j=0; j<this->maxClients; j++) {
            packet << IDsForWeapons[j] << positionX[j] << positionY[j];
        }
        packet << i;
        clientConnections[i]->send(packet);
    }
}

void TCP_Net_Manager::ReceiveData(int index, sf::TcpSocket* client)
{
  sf::Packet packet;
  sf::Socket::Status status = client ->receive(packet);
  if ( status == sf::Socket::Done)
  {
    int packetId;
    packet >> packetId;
    switch ( packetId )
    {
      case CLIENT_SEND_POS:
        this->SendPositionToAllExcludingSender(index,packet);
      break;
      case CLIENT_SEND_ATTACK:
        break;
      case CLIENT_SEND_USE_ITEM:
        int playerId;
        packet >> playerId;
        this->clientUsedItem(playerId);
        
        break;
        
    }
  }
  else if ( status == sf::Socket::Disconnected )
  {
    std::cout << "Player at " <<  client->getRemoteAddress() << " Disconnected." << std::endl;
//     sf::Packet p;
//     int t[] = {1,2,3};
//     p << t;
    this->clientCount--;
  }
}

void TCP_Net_Manager::SendPositionToAllExcludingSender(int index, sf::Packet packet)
{
    sf::Vector2f origin_playerPosition;
    
    float currDirectionFacing;
    
    packet >> origin_playerPosition.x >> origin_playerPosition.y >> currDirectionFacing;
    
    int indexCounter;
    
    for (std::vector<sf::TcpSocket*>::iterator it2 = this->clientConnections.begin(); it2 != this->clientConnections.end(); ++it2)
    {
        sf::TcpSocket* client2 =(*it2);
        sf::TcpSocket* client = this->clientConnections[index];
        sf::IpAddress ip1 = client->getRemoteAddress();
        sf::IpAddress ip2 = client2->getRemoteAddress();
        unsigned short p1 = client->getRemotePort();
        unsigned short p2 = client2->getRemotePort();


//        if(( ip1 != ip2 ) || ((ip1 == ip2) && (p1 != p2))) {
        if ( index != indexCounter )
        {
            int newPacketID = 3;
            sf::Packet newPacket;

            newPacket << newPacketID << origin_playerPosition.x << origin_playerPosition.y << currDirectionFacing << index;

            sf::Socket::Status status = client2->send(newPacket);
        }
        else
        {
            // Update the player position/dir for this client
            
            
//             client2.dirFacing = currDirectionFacing;
//             client2.topLeft_position = client2.origin_position = origin_playerPosition;
//             client2.topLeft_position.x -= PLAYER_WIDTH;
//             client2.topLeft_position.y -= PLAYER_HEIGHT;
        }

    indexCounter++;
    }
}

void TCP_Net_Manager::clientUsedItem(int playerId)
{
  
  // need a thread safe way of doing this!
  //allClients[playerId].currPowerUp = NO_POWERUP;
  this->currentMatch->ClientUseItem(playerId);  // currently not thread safe!
  sf::Packet PUI_Packet; // Player Used Item Packet
  
  for ( int i = 0; i < clientConnections.size(); i++)
  {
    if ( i != playerId )
    {
      clientConnections[i]->send(PUI_Packet);
    }
  }
}

void TCP_Net_Manager:: SetMatch(Match *match)
{
  this->currentMatch = match;
}