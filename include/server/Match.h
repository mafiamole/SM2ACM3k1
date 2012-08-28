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


#ifndef MATCH_H
#define MATCH_H
#include "TCP_Net_Manager.h"
#include <shared/MapLoader.h>
#include <shared/randomc.h>
struct ClientInformation
{
    int health;
    int killCount;
    int currWeapon;
    int currPowerUp;
    int specBonus;
    sf::Clock timeOfLastContactDamage; // This is the time since last contact damage (e.g. spikes) and is the minimum time ( before adding grace period) before can be contact_damaged again
    sf::Vector2f origin_position;
    sf::Vector2f topLeft_position;
    float dirFacing;
};

class Match
{
private:
  TCP_Net_Manager* connectionManager;
  bool matchBegun;
  MapLoader mapLoader;
  std::string                           mapFile;
  std::vector<Tile>                     mapTiles;
  std::vector<Item>                     itemsOnMap;
  std::vector<ClientInformation>        allClients;

  void LoadMap( std::string mapFile );          // Map function
  void CheckForTileCollision();                 // Map function
  void CheckForContactTileDamage();             // Map function
  void SetPlayerRandomPosition(int playerIndex, CRandomMersenne rand); // client / Map function
  void SpawnRandomItems();                                              // Map function
  void PlayerDiedUpdateAll(int index, CRandomMersenne rand);            // client function
  bool ReadHealth(ClientInformation* player, HealthBits healthPosition); // client Function
  void SetHealth(ClientInformation* player, HealthBits healthPosition, bool value); // client function
  void SetFullHealth(ClientInformation* player);                                        // client function
  bool IsPlayerDead(ClientInformation* player);                                         // client function
  void ClientAttack(sf::Packet packet);                                                 // client function
public:
  /**
   * @brief Class that manages a single game
   *
   **/
  Match( TCP_Net_Manager* connectionManager, std::string mapFile );
  virtual ~Match();
  
  //void SetData(int id,ClientInformation information);
  void ClientUseItem(int playerId);
  void ReadyPlayer(int index,int bonusId);                                              // client function
  void UpdatePosition(int playerId,float dirFacing,sf::Vector2f position);              // client function
  sf::Vector2f GetClientPos(int playerId);                                              // client function
  int GetClientWeapon(int playerId);                                                    // client function
};

#endif // MATCH_H
