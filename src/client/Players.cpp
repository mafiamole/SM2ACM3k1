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


#include <client/Players.h>
#include <client/Player.h>
#include <client/Game.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Game.hpp>

Players::Players(Player* clientPlayer, MB::Game* game) : MB::GameComponent(game), clientPlayer(clientPlayer), playerCount(0)
{

}

void Players::Update(sf::Time elapsed, MB::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);
}

void Players::Draw()
{
    MB::GameComponent::Draw();
    
    for ( int playerCtr = 0; playerCtr < playerCount; playerCtr++)
    {
      if (playerCtr != clientPlayer->ownID)
	this->DrawAsset( this->allPlayers[playerCtr].playerSprite );
    }
}

Players::~Players()
{

}

void Players::AddPlayer(int weapon, float xPos,float yPos)
{
  PlayerData tmpPlayer;
  
  tmpPlayer.playerSprite = MB::Content::NewSprite("Player2.png");
  tmpPlayer.playerSprite.setOrigin(31,19);
  tmpPlayer.playerSprite.setPosition(xPos,yPos);
  tmpPlayer.position.x = xPos;
  tmpPlayer.position.y = yPos;
  tmpPlayer.weapon = weapon;
  tmpPlayer.direction = 0.0f;
  tmpPlayer.SetFullHealth(&tmpPlayer);
  tmpPlayer.item = NO_POWERUP;
  tmpPlayer.killCount = 0;
  
  this->allPlayers.push_back(tmpPlayer);
  
  playerCount++;
  
}

void Players::UpdatePlayerPosition(int playerId,float x,float y,float direction)
{
  allPlayers[playerId].position.x = x;
  allPlayers[playerId].position.y = y;
  allPlayers[playerId].direction = direction;
  allPlayers[playerId].playerSprite.setPosition(x,y);
  allPlayers[playerId].playerSprite.setRotation(direction);
  
  // If player is self (in case of has been killed and new position generated) - This packet should only be sent to self under that circumstance. So can re-init items as well
  if ( playerId == clientPlayer->ownID)
  {
    clientPlayer->SetPosition(allPlayers[playerId].position);
    RemovePowerUp(playerId);
  }
  
}
void Players::UpdatePlayerHealth(int playerId,int health)
{
  allPlayers[playerId].health = health;
}

void Players::UpdateKillCount(int playerId, int killCount)
{
  allPlayers[playerId].killCount = killCount;
}

void Players::RemoveItem(int playerId,bool isWeapon,int code, int index)
{
  if (isWeapon)
    allPlayers[playerId].weapon = code;
  else
    allPlayers[playerId].item = code;
  
  if ( ! ( index == -1 ) )
  {
    ((Game*)game)->RemoveItem(index);
  }

}

void Players::UseEquiment(int playerId)
{
  int itemId = allPlayers[playerId].item;
  allPlayers[playerId].item = NO_POWERUP;
  std::cout << "Player" << playerId << " has just used an item of type " << itemId << std::endl ;
}

sf::FloatRect Players::PlayerHitBox(int playerId)
{
  return this->allPlayers[playerId].playerSprite.getGlobalBounds();
}

sf::Vector2f Players::GetPlayerPosition(int playerId)
{
  return this->allPlayers[playerId].position;
}

void Players::RemovePowerUp(int playerId)
{
  allPlayers[playerId].item = NO_POWERUP;
}

PlayerData Players::GetPlayerData(int playerId)
{
  return allPlayers[playerId];
}

int Players::Count()
{
  return this->playerCount;
}