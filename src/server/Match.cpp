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


#include <server/Match.h>
#include <shared/randomc.h>

Match::Match( TCP_Net_Manager* connectionManager, std::string mapFile ) : connectionManager(connectionManager)
{
    matchBegun = false;
    this->connectionManager->SetMatch(this);
}

Match::~Match()
{

}


void Match::LoadMap( std::string mapFile )
{
    this->mapFile = mapFile;
    this->mapTiles = mapLoader.ReadFile(mapFile);
}

void Match::CheckForTileCollision()
{

  int i;
    while(i < itemsOnMap.size()) {
        bool removedSomething = false;
        for(int j=0; j< allClients.size(); j++)
        {
            if(i < itemsOnMap.size())
            {
                sf::Vector2f topLeft = allClients.at(j).origin_position;
                if(mapLoader.TilesColliding(itemsOnMap.at(i), sf::Vector2f(allClients.at(j).origin_position.x - 16, allClients.at(j).origin_position.y - 16) ))
                {
                    // Player 'j' has landed on item 'i', give it to him, remove from the on board list and send update packets.
                    int packetID = SERVER_SEND_ITEM_COLLECT;
                    bool isWeapon = false;

                    switch(itemsOnMap.at(i).tileType)
                    {
                    case WEAPON:
                        allClients.at(j).currWeapon = itemsOnMap.at(i).ItemID;
                        isWeapon = true;
                        break;
                    case ITEM:
                        allClients.at(j).currPowerUp = itemsOnMap.at(i).ItemID;
                        break;
                    }
                    removedSomething = true;

                    sf::Packet packet;
                    packet << packetID << j << isWeapon << itemsOnMap.at(i).ItemID << i;

                    for(int k=0; k<allClients.size(); k++) {
                        connectionManager->SendPacket(k,packet);
                    }

                    itemsOnMap.erase(itemsOnMap.begin() + i);
                }
            }
        }
        if(!removedSomething || (itemsOnMap.size()==0))
        {
            i++;
        }
    }

}
void Match::CheckForContactTileDamage()
{

    CRandomMersenne rand((int)std::time(0));

    // Check if a player is colliding with a contact_damage tile (e.g. spikes), check if the time since last contact_damage is after the grace period, then update health / send packet
    for(int j=0; j<allClients.size(); j++) {
        if(mapLoader.TileCollidingWithTileOfType(allClients[j].topLeft_position,mapTiles,CONTACT_DAMAGE)) {
            if(allClients.at(j).timeOfLastContactDamage.getElapsedTime() > sf::milliseconds(1000)) { //Time before more hurting on spikies can occur (in milliseconds)
                //std::cout << "Player " << j << " took damage.\n";
                // Player needs to lose a random health block. This assumes that there IS some health to loose, otherwise infinite loop.

                bool foundHealthyBlock = false;
                HealthBits positionUsed;
                do {
                    positionUsed = (HealthBits)rand.IRandom(1,4);
                    if(this->ReadHealth(&allClients.at(j), positionUsed)) {
                        foundHealthyBlock = true;
                    }
                }
                while(!foundHealthyBlock);

                SetHealth(&allClients.at(j), positionUsed,0);

                // Check if player is dead, and deal with appropriately.
                if(IsPlayerDead(&allClients.at(j))) { // Alert other players that a player died, update kill count, re-init character etc
                    PlayerDiedUpdateAll(j, rand);

                } else { // Not dead, alert other players about losing health
                    int packetID = 4;
                    sf::Packet packet;
                    packet << packetID << j << allClients.at(j).health;

                    for(int i=0; i<allClients.size(); i++) {
                      //allClients.at(i).clientSocket->send(packet);
                      connectionManager->SendPacket(i,packet);
                    }

                }

                // Update collision time for this player
                allClients.at(j).timeOfLastContactDamage.restart();
            }
        }
    }
}

void Match::SpawnRandomItems()
{

    // spawn a few items to get going (testing)
    CRandomMersenne rand((int)std::time(0));

    for(int j=0; j<4; j++) {

        Item i;
        i.ItemID = REPEL_NPC;
        i.tileType = ITEM;

        float x, y;
        bool playerColliding;
        do {
            playerColliding = false;
            x = (float)rand.IRandom(10,1014);
            y = (float)rand.IRandom(10,758);
            i.position = sf::Vector2f(x,y);

            // Check not spawing on a player
            for(int j=0; j<allClients.size(); j++) {
                if(mapLoader.PlayersColliding(allClients.at(j).topLeft_position,i.position)) {
                    playerColliding = true;
                }
            }

            // Check not spawing on another item
            for(int k=0; playerColliding == false && k<itemsOnMap.size(); k++) {
                // if(j!=index){
                if(mapLoader.TilesColliding((Tile)itemsOnMap.at(k),i.position)) {
                    playerColliding = true;
                }
                //  }
            }

        } while(playerColliding || !mapLoader.TileOnFloor(&i, this->mapTiles));
        //should also check not colliding with players, or other items.
        // Randomly choose a position for item. Then check it's valid

        this->itemsOnMap.push_back(i);
        // Send packet saying new item has been put on floor
        int packetID = 8 ;
        bool isWeapon = false;

        sf::Packet packet;
        packet << packetID << isWeapon << i.ItemID << i.position.x << i.position.y;

        for(int k=0; k< allClients.size(); k++) {
//             allClients.at(k).clientSocket->send(packet);
          connectionManager->SendPacket(k,packet);
        }

    }
}

void Match::PlayerDiedUpdateAll(int index, CRandomMersenne rand)
{
    SetFullHealth(&allClients.at(index));

    SetPlayerRandomPosition(index, rand);
    // Drop/Destroy currently held weapon/items. Create packets (player powerup removed by position update packet)
    int packetID = 7;
    bool isWeapon = true;
    int itemIndex = -1;
    sf::Packet itemPacket;
    itemPacket << packetID << index << isWeapon << allClients.at(index).specBonus << itemIndex;

    allClients.at(index).currPowerUp = NO_POWERUP;
    allClients.at(index).currWeapon = allClients.at(index).specBonus;

    // Update Kill count + create packet
    packetID = 5;
    sf::Packet killCountPacket;
    allClients.at(index).killCount -= 1; // Minus one, on death.
    killCountPacket << packetID << index << allClients.at(index).killCount;

    // Create updated position packet
    packetID = 3;
    sf::Packet newPacket;
    newPacket << packetID << allClients.at(index).origin_position.x << allClients.at(index).origin_position.y << allClients.at(index).dirFacing << index;

    // Create updated health packet
    packetID = 4;
    sf::Packet packet;
    packet << packetID << index << allClients.at(index).health;


    // Send the packets to all
    for(int i=0; i<allClients.size(); i++) {
//         allClients.at(i).clientSocket->send(itemPacket);
//         allClients.at(i).clientSocket->send(killCountPacket);
//         allClients.at(i).clientSocket->send(newPacket);
//         allClients.at(i).clientSocket->send(packet);
      connectionManager->SendPacket(i,itemPacket);
      connectionManager->SendPacket(i,killCountPacket);
      connectionManager->SendPacket(i,newPacket);
      connectionManager->SendPacket(i,packet);
    }

}

bool Match::ReadHealth(ClientInformation* player, HealthBits healthPosition)
{
    int result;
    result = player->health & (1<<healthPosition-1);
    return result;
}

void Match::SetHealth(ClientInformation* player, HealthBits healthPosition, bool value)
{
    if(value)
    {
        player->health = player->health | (1<<healthPosition-1);
    }
    else
    {
        player->health = player->health & (~(1<<healthPosition-1));
    }
}

void Match::SetFullHealth(ClientInformation* player)
{
    // Could probably just set the value to 15 to init first 4 bits - At least this system is ignores platform endien-ness & int size.
    for(int i=1; i<5; i++)
    {
        SetHealth(player,(HealthBits)i,true);
    }
}

bool Match::IsPlayerDead(ClientInformation* player)
{
    for(int i=1; i<5; i++)
    {
        if(ReadHealth(player,(HealthBits)i))
        {
            return false;
        }
    }
    return true;
}

void Match::SetPlayerRandomPosition(int playerIndex, CRandomMersenne rand)
{
    Tile tmpTile;
    bool playerColliding;
    do {
        playerColliding = false;
        tmpTile.position.x = (float)rand.IRandom(10,1014); // some screen bounds
        tmpTile.position.y = (float)rand.IRandom(10,758);
        // Loop through other players, if colliding with one, set boolean, true.
        // This isn't a true collision check atm, incorrect hitbox size/shape/orientation
        for(int i=0; i<allClients.size(); i++) {
            if(i!=playerIndex) {
                if(mapLoader.PlayersColliding(allClients[i].topLeft_position,tmpTile.position)) {
                    playerColliding = true;
                }
            }
        }
    } while(playerColliding || !mapLoader.TileOnFloor(&tmpTile, mapTiles, true));

    allClients[playerIndex].origin_position = allClients[playerIndex].topLeft_position = tmpTile.position;
    allClients[playerIndex].origin_position.x += PLAYER_WIDTH/2;
    allClients[playerIndex].origin_position.y += PLAYER_HEIGHT/2;
}

void Match::ClientAttack(sf::Packet packet)
{
    int playerID;
    sf::FloatRect rectangle;
    sf::FloatRect revisedRectangle;
    sf::Sprite revisedSprite;

    packet >> playerID >> rectangle.left >> rectangle.top >> rectangle.width >> rectangle.height >> revisedRectangle.left >> revisedRectangle.top >> revisedRectangle.width >> revisedRectangle.height;
    std::cout << "Player " << playerID << " has attacked!" << std::endl;

    // Create packet to send to all players saying someone attacked and send


    // Check if this hitbox is colliding with a player, if so check where the hitbox is relative to the other player to determine which health block to take.
    // -- if was colliding and health was taken (it wasn't 0 before), see if player is now dead and update as required.

    for(int i=0; i<allClients.size(); i++) {
        if(i!=playerID) {
            // Giving the player that was 'hit' a hitbox 46x46 around its centre, avoids the weird uneven shape and facing direction.
            //sf::FloatRect playerRect(allClients.at(i).origin_position.x - 23, allClients.at(i).origin_position.y - 23, 46, 46);
            sf::FloatRect playerRect(allClients.at(i).origin_position.x, allClients.at(i).origin_position.y, 46, 46);


            // If rectangle colliding with player,
            if(playerRect.intersects(rectangle)) {
                // set player sprite size and origin, rotate -current rotation.
                
                revisedSprite.setPosition(revisedRectangle.left,revisedRectangle.top);
                // NOT SURE IF THIS POSITION WILL BE CHANGED AFTER THE ORIGIN IS APPLIED, PROBABLY WILL, BUT NOT DESIRED

                sf::Transform transform = revisedSprite.getTransform();
                //sf::Vector2f pos = transform.transformPoint();

                // convert playerRect origin to a local co-ordinate of revisedsprite
                // revisedsprite.left - origin.x, revised sprite.top - origin.y
                sf::Vector2f revisedOrigin(revisedSprite.getGlobalBounds().left-allClients.at(i).origin_position.x,revisedSprite.getGlobalBounds().top - allClients.at(i).origin_position.y);

                // after origin is set, the revised rectangle centre is ....



                revisedSprite.setOrigin(revisedOrigin);
                revisedSprite.rotate(-allClients.at(i).dirFacing);


                // probably need to update position here (with offset to origin)

                // position before changing orientation/origin
                revisedRectangle.left = revisedSprite.getGlobalBounds().left;
                revisedRectangle.top = revisedSprite.getGlobalBounds().top;

                // set revised sprite pos, and its origin to centre of player being hit
                // rotate negative to the current player rotation

                // temp rotate rectangle.

                int side = mapLoader.GetTileRelativePosition(sf::IntRect(revisedRectangle),sf::IntRect(playerRect));
                // Translate hit side to side of player
                std::cout << "hitside " << side << "\n";
                //if( = )
            }
        }
    }


}

void Match::ReadyPlayer(int index, int bonusId)
{
    CRandomMersenne rand((int)std::time(0));
    SetPlayerRandomPosition( index, rand);

    allClients.at(index).specBonus = bonusId;
    allClients.at(index).currWeapon = bonusId; // Starter weapons are in the order of the bonusID's, so can just assign it to weap.
    allClients.at(index).currPowerUp = NO_POWERUP;
    allClients.at(index).killCount = 0;
    allClients.at(index).dirFacing = 0.0f;
    allClients.at(index).timeOfLastContactDamage.restart();
    SetFullHealth(&allClients.at(index));
}

void Match::ClientUseItem(int playerId)
{
  allClients[playerId].currPowerUp = NO_POWERUP;
}

void Match::UpdatePosition(int playerId,float dirFacing,sf::Vector2f position)
{
  ClientInformation& client2 = this->allClients[playerId];
  client2.dirFacing = dirFacing;
  client2.topLeft_position = client2.origin_position = position;
  client2.topLeft_position.x -= PLAYER_WIDTH;
  client2.topLeft_position.y -= PLAYER_HEIGHT;
}

sf::Vector2f Match::GetClientPos(int playerId)
{
  return allClients[playerId].origin_position;
}

int Match::GetClientWeapon(int playerId)
{
  return allClients[playerId].currWeapon;
}