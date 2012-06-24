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



  struct Player_Interface_Reg 
  {
    static int GetPlayer	(lua_State* L);
    static int GetHP		(lua_State* L);
    static int GetWeapon	(lua_State* L);
    static int GetItem		(lua_State* L);
    static int GetPosition	(lua_State* L);
    static int GetDirection	(lua_State* L);

  };

  static const luaL_reg play_interface_reg[] =
  {
    { "GetPlayer", Player_Interface_Reg::GetPlayer},
    { "GetHP", Player_Interface_Reg::GetHP},
    { "GetWeapon", Player_Interface_Reg::GetWeapon},
    { "GetItem", Player_Interface_Reg::GetPlayer},
    { "GetPosition", Player_Interface_Reg::GetHP},
    { "GetDirection", Player_Interface_Reg::GetWeapon},
    { NULL, NULL }
  };


#endif
