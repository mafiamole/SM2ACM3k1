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


#include <server/TCP_Net_Serv2.hpp>


void TCP_Net_Thread(ServerSettings settings)
{
    TCP_Net_Serv2 server(settings.port,settings.maxClients);

    server.Launch();

}

TCP_Net_Serv2::TCP_Net_Serv2(short unsigned int port, int MaxClients)
{
    this->port = port;
    this->maxClients = MaxClients;
    this->readyClients = 0;
    this->clientCount = 0;
    this->serverUp = true;
}

TCP_Net_Serv2::~TCP_Net_Serv2()
{

}


void TCP_Net_Serv2::Launch()
{

    std::cout << "Lanching SM2ACM3k1 Server" << std::endl;


    this->WaitForClients();

    while (this->serverUp)
    {

        int index = 0;

        for (std::vector<ClientInformation>::iterator itr = allClients.begin(); itr != this->allClients.end(); ++itr)
        {

            if (selector.wait())
            {
                if (this->selector.isReady(*itr->clientSocket))
                {
                    this->ReceiveData(index,&(*itr));
                }

            }
            index++;
        }
    }
}




void TCP_Net_Serv2::SendPositionToAllExcludingSender(int index, ClientInformation* client, sf::Vector2f playerPosition,float currDirectionFacing)
{
    for (std::vector<ClientInformation>::iterator it2 = this->allClients.begin(); it2 != this->allClients.end(); ++it2)
    {
        ClientInformation& client2 = *it2;

        sf::IpAddress ip1 = client->clientSocket->getRemoteAddress();
        sf::IpAddress ip2 = client2.clientSocket->getRemoteAddress();
        unsigned short p1 = client->clientSocket->getRemotePort();
        unsigned short p2 = client2.clientSocket->getRemotePort();


        if(( ip1 != ip2 ) || ((ip1 == ip2) && (p1 != p2))) {
            int newPacketID = 3;
            sf::Packet newPacket;

            newPacket << newPacketID << playerPosition.x << playerPosition.y << currDirectionFacing << index;

            sf::Socket::Status status = (client2.clientSocket)->send(newPacket);
        }else{
                // Update the player position/dir for this client
                client2.dirFacing = currDirectionFacing;
                client2.position = playerPosition;
        }


    }
}

void TCP_Net_Serv2::ReceiveData(int index, ClientInformation* client)
{

    sf::Packet packet;

    sf::Socket::Status status = client->clientSocket->receive(packet);

    if ( status == sf::Socket::Done)
    {
        int packetID;
        packet >> packetID;

        switch( packetID )
        {
        case 1:
            sf::Vector2f playerPosition;
            float playerDirection;
            packet >> playerPosition.x >> playerPosition.y >> playerDirection;
            SendPositionToAllExcludingSender(index,client,playerPosition,playerDirection);
            break;
        }

    }
    else if ( status == sf::Socket::Disconnected )
    {
        //std::cout << "Player at " <<  client->getRemoteAddress() << " Disconnected." << std::endl;
        sf::Packet p;
        int t[] = {1,2,3};
        p << t;
    }


}

void TCP_Net_Serv2::AddClient(sf::SocketSelector* selector)
{
    sf::TcpSocket* client = new sf::TcpSocket;
    if ( servListener.accept(*client) == sf::Socket::Done)
    {
        ClientInformation NCI;
        NCI.clientSocket = client;
        allClients.push_back(NCI); 
        this->clientCount++;
        selector->add(*client);
        std::cout << "New client connected at " << client->getRemoteAddress() << std::endl;

    }
}



void TCP_Net_Serv2::WaitForClients(void)
{
    // Need to wait for initialisation packet, might as well create temp vars now to save re-creating each time the packet is received.
    int packetID;	
    sf::Vector2f playerPosition;
    int bonusID;

    int index;

    std::cout << "Listening for connections on port " << this->port << std::endl;
    servListener.listen( this->port );

    while ((this->clientCount < this->maxClients) && (this->readyClients != this->maxClients))
    {

        this->selector.add(servListener);
        if ( this->selector.wait() )
        {

            if ( this->selector.isReady(servListener) )
            {

                this->AddClient(&selector);

            }
            else
            {
                // Process any data here while waiting for all clients to be ready.
                // Loop through all currently connected clients, if one is sending data check for an init packet, mark readyClients++ and set their info in the client list
                index = 0;
                for (std::vector<ClientInformation>::iterator itr = allClients.begin(); itr != this->allClients.end(); ++itr)
                {                  
                    if (this->selector.isReady(*itr->clientSocket))
                    {
                        sf::Packet packet;
                        sf::Socket::Status status = (*itr).clientSocket->receive(packet);

                        if ( status == sf::Socket::Done)
                        {
                            packet >> packetID;

                            if(packetID == 2){
                                this->readyClients++;
                                    packet >> playerPosition.x >> playerPosition.y >> bonusID;
                                    allClients.at(index).position = playerPosition;
                                    allClients.at(index).specBonus = bonusID;
                                    allClients.at(index).currWeapon = bonusID; // Starter weapons are in the order of the bonusID's, so can just assign it to weap.
                                    allClients.at(index).currPowerUp = PowerUp::NO_POWERUP;
                                    allClients.at(index).killCount = 0;
                                    allClients.at(index).dirFacing = 0.0f;
                                    allClients.at(index).health = 0;
                            }

                        }
                    }
                    index++;
                }
            }
        }

    }

    std::cout << "Everyone is ready. Sending go signal." << std::endl;

}




bool TCP_Net_Serv2::ReadHealth(ClientInformation* player, HealthBits healthPosition)
{
    int result;
    result = player->health & (1<<healthPosition-1);
    return result;
}

void TCP_Net_Serv2::SetHealth(ClientInformation* player, HealthBits healthPosition, bool value)
{
  if(value){
      player->health = player->health | (1<<healthPosition-1);
    }else{
        player->health = player->health & (~(1<<healthPosition-1));
    }
}