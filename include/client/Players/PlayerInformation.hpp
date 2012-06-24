#ifndef PLAYERINFORMATION_H
#define PLAYERINFORMATION_H
#include <SFML/Graphics.hpp>
#include <list>

struct PlayerData {
  
  int 		health;
  int 		weapon;
  int 		item;
  sf::Vector2f	position;
  float		direction;
  bool RightHealth(PlayerData player);

  bool LeftHealth(PlayerData player);

  bool BackHealth(PlayerData player);

  bool FrontHealth(PlayerData player);
    
};

typedef std::list <PlayerData> PlayerDataList;
/**
 *  
 *  Health is a single integer where,
 *  - least significant bit is the front health segment.
 *  - second significant bit is the back health segment.
 *  - third significant bit is the left health segment.
 *  - forth significant bit is the right health segment.
 * 
 */ 



#endif
