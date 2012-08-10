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

    bool createdItems = false;
     
    while (this->serverUp)
    {

        int index = 0;

        for (std::vector<ClientInformation>::iterator itr = allClients.begin(); itr != this->allClients.end(); ++itr)
        {

            if (selector.wait(sf::milliseconds(5)))
            {
                if (this->selector.isReady(*itr->clientSocket))
                {
                    this->ReceiveData(index,&(*itr));
                }

            }
            index++;
        }

        // Check for collisions between players with items on board
        int i = 0;

        while(i < itemsOnMap.size()){
            bool removedSomething = false;
            for(int j=0; j<this->allClients.size();j++){
                if(i < itemsOnMap.size()){
                    if(mapLoader.TilesColliding(&itemsOnMap.at(i), allClients.at(j).position)){
                        // Player 'j' has landed on item 'i', give it to him, remove from the on board list and send update packets.
                        int packetID = 7;
                        bool isWeapon = false;

                        switch(itemsOnMap.at(i).tileType){
                        case TileTypes::WEAPON:
                            allClients.at(j).currWeapon = itemsOnMap.at(i).ItemID;
                            isWeapon = true;
                            break;
                        case TileTypes::ITEM:
                            allClients.at(j).currPowerUp = itemsOnMap.at(i).ItemID;
                            break;
                        }
                        removedSomething = true;

                        sf::Packet packet;
                        packet << packetID << j << isWeapon << itemsOnMap.at(i).ItemID << i;

                        for(int k=0;k<this->allClients.size();k++){
                            this->allClients.at(k).clientSocket->send(packet);
                        }                     

                        itemsOnMap.erase(itemsOnMap.begin() + i);
                    }
                }
            }
            if(!removedSomething || (itemsOnMap.size()==0)){ i++; }
        }

        CRandomMersenne rand((int)time(0));

        // Check if a player is colliding with a contact_damage tile (e.g. spikes), check if the time since last contact_damage is after the grace period, then update health / send packet
        for(int j=0;j<allClients.size();j++){           
            if(mapLoader.TileCollidingWithTileOfType(allClients.at(j).position,currMapObj,TileTypes::CONTACT_DAMAGE)){
                if(allClients.at(j).timeOfLastContactDamage.getElapsedTime() > sf::milliseconds(1000)){ //Time before more hurting on spikies can occur (in milliseconds)
                   //std::cout << "Player " << j << " took damage.\n";
                   // Player needs to lose a random health block. This assumes that there IS some health to loose, otherwise infinite loop.
                   
                   bool foundHealthyBlock = false;
                   HealthBits positionUsed;
                   do{
                       positionUsed = (HealthBits)rand.IRandom(1,4);
                       if(this->ReadHealth(&allClients.at(j), positionUsed)){
                           foundHealthyBlock = true;
                       }
                   }
                   while(!foundHealthyBlock);

                   SetHealth(&allClients.at(j), positionUsed,0);

                   // Check if player is dead, and deal with appropriately.
                   if(IsPlayerDead(&allClients.at(j))){ // Alert other players that a player died, update kill count, re-init character etc
                        PlayerDiedUpdateAll(j, rand);            
                        
                   }else{ // Not dead, alert other players about losing health
                        int packetID = 4;
                        sf::Packet packet;
                        packet << packetID << j << allClients.at(j).health;

                        for(int i=0; i<allClients.size();i++){                    
                            allClients.at(i).clientSocket->send(packet);
                        }               

                   }
                   
                   // Update collision time for this player
                   allClients.at(j).timeOfLastContactDamage.restart();
                }
            }
        }



        // Randomly spawn items if it's time to. Needs to spawn in locations that are 'floor'.
        if(!createdItems){
            // spawn a few items to get going (testing)
            CRandomMersenne rand((int)time(0));

            for(int j=0;j<4;j++){

            Item i;
            i.ItemID = PowerUp::REPEL_NPC;
            i.tileType = TileTypes::ITEM;
            
            float x, y; 
            bool playerColliding;
            do{
               playerColliding = false;
               x = (float)rand.IRandom(0,1024);
               y = (float)rand.IRandom(0,768);
               i.position = sf::Vector2f(x,y);

               // Check not spawing on a player
               for(int j=0;j<allClients.size();j++){
                   if(mapLoader.PlayersColliding(allClients.at(j).position,i.position)){ playerColliding = true;}
               }

               // Check not spawing on another item
               for(int k=0;playerColliding == false && k<itemsOnMap.size();k++){
                // if(j!=index){
                   if(mapLoader.TilesColliding(&(Tile)itemsOnMap.at(k),i.position)){ playerColliding = true;}
               //  }                                            
               }

            }while(playerColliding || !mapLoader.TileOnFloor(&i, this->currMapObj)); 
            //should also check not colliding with players, or other items.
            // Randomly choose a position for item. Then check it's valid

            this->itemsOnMap.push_back(i);
            // Send packet saying new item has been put on floor
            int packetID = 8 ;
            bool isWeapon = false;

            sf::Packet packet;
            packet << packetID << isWeapon << i.ItemID << i.position.x << i.position.y;

            for(int k=0;k<this->allClients.size();k++){
               this->allClients.at(k).clientSocket->send(packet);
            } 

            }
            createdItems = true;
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

void TCP_Net_Serv2::PlayerDiedUpdateAll(int index, CRandomMersenne rand){
    //std::vector<ClientInformation>& allClients = *clients;
    SetFullHealth(&allClients.at(index));
                      
    SetPlayerRandomPosition(&allClients, index, &mapLoader, currMapObj, rand);
    // Drop/Destroy currently held weapon/items. Create packets (player powerup removed by position update packet)
    int packetID = 7;                        
    bool isWeapon = true;
    int itemIndex = -1;
    sf::Packet itemPacket;
    itemPacket << packetID << index << isWeapon << allClients.at(index).specBonus << itemIndex;

    allClients.at(index).currPowerUp = PowerUp::NO_POWERUP;                           
    allClients.at(index).currWeapon = allClients.at(index).specBonus;
            
    // Update Kill count + create packet
    packetID = 5;
    sf::Packet killCountPacket;
    allClients.at(index).killCount -= 1; // Minus one, on death.
    killCountPacket << packetID << index << allClients.at(index).killCount;
                           
    // Create updated position packet
    packetID = 3;
    sf::Packet newPacket;
    newPacket << packetID << allClients.at(index).position.x << allClients.at(index).position.y << allClients.at(index).dirFacing << index;

    // Create updated health packet
    packetID = 4;
    sf::Packet packet;
    packet << packetID << index << allClients.at(index).health;


    // Send the packets to all
    for(int i=0; i<allClients.size();i++){       
        allClients.at(i).clientSocket->send(itemPacket);
        allClients.at(i).clientSocket->send(killCountPacket);
        allClients.at(i).clientSocket->send(newPacket);
        allClients.at(i).clientSocket->send(packet);
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
        {
            sf::Vector2f playerPosition;
            float playerDirection;
            packet >> playerPosition.x >> playerPosition.y >> playerDirection;
            SendPositionToAllExcludingSender(index,client,playerPosition,playerDirection);
            break;
        }
        case 10: // Player has used item, update internal info, and process if needed, then send out same packet to all other clients.
            {
               int playerID;
               packet >> playerID;
               sf::Packet newPacket;
               newPacket << packetID << playerID;
               allClients.at(playerID).currPowerUp = PowerUp::NO_POWERUP;

               for(int i=0; i<allClients.size();i++){
                    if(i != playerID){
                        allClients.at(i).clientSocket->send(newPacket);
                    }
               }
               

            }
        }

    }
    else if ( status == sf::Socket::Disconnected )
    {
        std::cout << "Player at " <<  client->clientSocket->getRemoteAddress() << " Disconnected." << std::endl;
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
    int bonusID;

    int index;

    CRandomMersenne rand((int)time(0));

    std::cout << "Listening for connections on port " << this->port << std::endl;
    servListener.listen( this->port );
    
    // Set which map we will be using.
    std::cout << "Setting map <Colosseum> for round" << std::endl;
    SetMap(Maps::COLOSSEUM);

    while ((this->clientCount < this->maxClients) || (this->readyClients != this->maxClients))
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
                                    packet >> bonusID;

                                    SetPlayerRandomPosition(&allClients, index, &mapLoader, currMapObj, rand);
                                    
                                    allClients.at(index).specBonus = bonusID;
                                    allClients.at(index).currWeapon = bonusID; // Starter weapons are in the order of the bonusID's, so can just assign it to weap.
                                    allClients.at(index).currPowerUp = PowerUp::NO_POWERUP;
                                    allClients.at(index).killCount = 0;
                                    allClients.at(index).dirFacing = 0.0f;
                                    allClients.at(index).timeOfLastContactDamage.restart();
                                    SetFullHealth(&allClients.at(index));
                                    
                                    this->readyClients++;
                            }

                        }
                    }
                    index++;
                }
            }
        }

    }

    std::cout << "Everyone is ready. Init and Sending go signal." << std::endl;

   
    packetID = 0;
    int *IDsForWeapons = new int[this->maxClients];
    float *positionX = new float[this->maxClients];
    float *positionY = new float[this->maxClients];
    

    index = 0;
    for (std::vector<ClientInformation>::iterator itr = allClients.begin(); itr != this->allClients.end(); ++itr)
    {     
        // Loop through all clients and fill arrays to send in the packets
        IDsForWeapons[index] = (*itr).currWeapon;
        positionX[index] = (*itr).position.x;
        positionY[index] = (*itr).position.y;
        index++;
    }

    for(int i = 0; i < this->maxClients;i++){
        // Loop through all clients, create its packet and send
        sf::Packet packet;
        packet << packetID << this->maxClients;
        
        // Need to loop through all data arrays and push each item individually into packet.
        for(int j=0; j<this->maxClients;j++){
            packet << IDsForWeapons[j] << positionX[j] << positionY[j]; 
        }
        packet << i;
        allClients.at(i).clientSocket->send(packet);
    }
   
}


void TCP_Net_Serv2::SetPlayerRandomPosition(std::vector<ClientInformation>* allClients, int playerIndex, MapLoader* mapLoader, std::vector<Tile> mapTiles, CRandomMersenne rand){
    // Need to set a random location which is on the floor. (And ideally not where another player is.) 
    Tile tmpTile;
    bool playerColliding;
    do{
        playerColliding = false;
        tmpTile.position.x = (float)rand.IRandom(0,1024);
        tmpTile.position.y = (float)rand.IRandom(0,768);
        // Loop through other players, if colliding with one, set boolean, true.
        // This isn't a true collision check atm, incorrect hitbox size/shape/orientation
        for(int i=0;i<allClients->size();i++){
            if(i!=playerIndex){
                if(mapLoader->PlayersColliding(allClients->at(i).position,tmpTile.position)){ playerColliding = true;}
            }                                            
        }
    }while(playerColliding || !mapLoader->TileOnFloor(&tmpTile, mapTiles, true));

    allClients->at(playerIndex).position = tmpTile.position;
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

void TCP_Net_Serv2::SetFullHealth(ClientInformation* player)
{
    // Could probably just set the value to 15 to init first 4 bits - At least this system is ignores platform endien-ness & int size.
    for(int i=1;i<5;i++){
        SetHealth(player,(HealthBits)i,true);
    }
}

bool TCP_Net_Serv2::IsPlayerDead(ClientInformation* player)
{
    for(int i=1;i<5;i++){
        if(ReadHealth(player,(HealthBits)i)) { return false; }
    }
    return true;
}

void TCP_Net_Serv2::SetMap(Maps map)
{
    this->currMap = map;
    // also load the mapObj here
        switch(map){

        case 1: // Colosseum
            this->currMapObj = mapLoader.ReadFile("map.txt");
            break;

        }
}

//find map.txt for server, and work on integrating the mapid/enum/file loader ( i.e. for colosseum (enum 1) load map1.txt file.