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


#ifndef PLAYERS_H
#define PLAYERS_H
#include <client/Players/PlayerInformation.hpp>
#include <MoleBox/GameComponent.hpp>

class Player;

class Players : public MB::GameComponent
{
protected:
    std::vector<PlayerData> allPlayers;
    Player *clientPlayer;
    int playerCount;
    
public:
  
    Players(Player *clientPlayer,MB::Game* game);
    virtual void Update(sf::Time elapsed, MB::EventList* events);
    virtual void Draw();
    virtual ~Players();
    
    PlayerData GetPlayerData(int playerId);
    void AddPlayer(int weapon, float xPos,float yPos);
    sf::Vector2f GetPlayerPosition(int playerId);
    sf::FloatRect PlayerHitBox(int playerId);
    
    void UpdatePlayerPosition(int playerId, float x, float y, float direction); 
    void UpdatePlayerHealth(int playerId,int health);
    void UpdateKillCount(int playerId, int killCount);
    void RemoveItem(int playerId,bool isWeapon,int code, int index);
    void UseEquiment(int playerId);
    
    void RemovePowerUp(int playerId);
    
    int Count();
    
    
};

#endif // PLAYERS_H
