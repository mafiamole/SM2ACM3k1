#include <server/PacketRoutines.h>



    
void PacketRoutines::SendPositionToAllExcludingSender(int index, ClientInformation* client, list<ClientInformation>* allClientsList, sf::Packet packet)
{
    list<ClientInformation>& allClients = *allClientsList;

    sf::Vector2f playerPosition;
    float currDirectionFacing;
    packet >> playerPosition.x >> playerPosition.y >> currDirectionFacing;

    for (std::list<ClientInformation>::iterator it2 = allClients.begin(); it2 != allClients.end(); ++it2)
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
