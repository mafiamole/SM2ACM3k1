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
#include <queue>


void TCP_Net_Thread(ServerSettings settings)
{
    TCP_Net_Serv2 server(settings.port,settings.maxClients);

    server.Launch();

}


TCP_Net_Serv2::TCP_Net_Serv2(short unsigned int port, int MaxClients)
{
    this->port = port;
    this->maxClients = MaxClients;
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

        for (TcpSocketList::iterator itr = this->clientSockets.begin(); itr != this->clientSockets.end(); ++itr)
        {
            sf::TcpSocket* client = (*itr);

            if (selector.wait())
            {
                if (this->selector.isReady(*client))
                {
                    this->ReceiveData(index,client);
                }

            }
            index++;
        }
    }
}

void TCP_Net_Serv2::SendPlayerPositionToAll(int index,sf::TcpSocket* client, sf::Vector2f playerPosition,float currDirectionFacing)
{
    for (TcpSocketList::iterator it2 = this->clientSockets.begin(); it2 != this->clientSockets.end(); ++it2)
    {
        sf::TcpSocket* client2 = *it2;

        sf::IpAddress ip1 = client->getRemoteAddress();
        sf::IpAddress ip2 = client2->getRemoteAddress();
        unsigned short p1 = client->getRemotePort();
        unsigned short p2 = client2->getRemotePort();


        if(( ip1 != ip2 ) || ((ip1 == ip2) && (p1 != p2))) {
            int newPacketID = 3;
            sf::Packet newPacket;

            newPacket << newPacketID << playerPosition.x << playerPosition.y << currDirectionFacing << index;

            sf::Socket::Status status = client2->send(newPacket);
        }


    }
}

void TCP_Net_Serv2::ReceiveData(int index, sf::TcpSocket* client)
{

    sf::Packet packet;

    sf::Socket::Status status = client->receive(packet);

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
            SendPlayerPositionToAll(index,client,playerPosition,playerDirection);
            break;
        }

    }
    else if ( status == sf::Socket::Disconnected )
    {
        //std::cout << "Player at " <<  client->getRemoteAddress() << " Disconnected." << std::endl;
    }


}

void TCP_Net_Serv2::AddClient(sf::SocketSelector* selector)
{
    sf::TcpSocket* client = new sf::TcpSocket;
    if ( servListener.accept(*client) == sf::Socket::Done)
    {
        this->clientSockets.push_back(client);
        this->clientCount++;
        selector->add(*client);
        std::cout << "New client connected at " << client->getRemoteAddress() << std::endl;

    }
}



void TCP_Net_Serv2::WaitForClients(void)
{

    std::cout << "Listening for connections on port " << this->port << std::endl;
    servListener.listen( this->port );

    while (this->clientCount < this->maxClients)
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
                //add code that manages either talk between waiting players or all players wanting to start and select specialisation.
            }
        }

    }

    std::cout << "Everyone is ready. Sending go signal." << std::endl;

//     std::list<TcpSocket*>::iterator itr;
//     sf::Packet goPacket;
//     goPacket << "GO";
//     for (itr = this->clientSockets.begin(); itr != this->clientSockets.end(); itr++)
//     {
//       TcpSocket* client = (*itr);
//       client->send(goPacket);
//     }
}