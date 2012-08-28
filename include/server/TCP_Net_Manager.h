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


#ifndef TCP_NET_MANAGER_H
#define TCP_NET_MANAGER_H
#include <SFML/Network.hpp>
#include <shared/Packets.h>
#include <shared/Enums.h>



struct ServerSettings
{
    unsigned short port;
    int            maxClients;

};
class Match;
/**
 * @brief Class For managing clients and the TCP connection
 **/
class TCP_Net_Manager
{
private:
    sf::Mutex                             transmissionMutex;
    sf::TcpListener                       servListener;
    sf::TcpSocket                         clientSocket;
    sf::SocketSelector                    selector;
    unsigned short                        port;
    sf::Time                              timeout;
    Match*                                currentMatch;
    
    std::vector<sf::TcpSocket*>           clientConnections;
    int                                   maxClients;
    int                                   clientCount;
    int                                   readyClients;
    bool                                  serverUp;


    
    void GrabPackets();
    void AddClient(sf::SocketSelector* selector);
    void ClientWaitInitCheck();
    void ReceiveData(int index, sf::TcpSocket* client);
    void SendPositionToAllExcludingSender(int index, sf::Packet packet);
    void clientUsedItem(int playerId);
public:

    TCP_Net_Manager(ServerSettings settings);
    ~TCP_Net_Manager();
    void SendPacket(int playerId,sf::Packet packetToSend);
    void WaitForClients(int number);
    void SendGoSignal();
    void SetMatch(Match *match);
};

#endif // TCP_NET_MANAGER_H
