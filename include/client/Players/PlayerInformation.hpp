#ifndef PLAYERINFORMATION_H
#define PLAYERINFORMATION_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <lua.hpp>

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

  int playerID;

  sf::Sprite playerSprite;
    
};

typedef std::vector <PlayerData> PlayerDataList;
/**
 *  
 *  Health is a single integer where,
 *  - least significant bit is the front health segment.
 *  - second significant bit is the back health segment.
 *  - third significant bit is the left health segment.
 *  - forth significant bit is the right health segment.
 * 
 */ 


template < class T > static T* getUserData(lua_State* L, std::string identifier)
{
  lua_pushstring(L,identifier.c_str());
  lua_gettable(L,LUA_REGISTRYINDEX);
  T* _this = (T*)lua_touserdata(L,-1);
  return _this;
}

template < class T > static void setUserData(lua_State*L, std::string identifier ,T* data)
{
  
    lua_pushstring( L, identifier.c_str() );
    lua_pushlightuserdata( L, (void*)data );
    lua_settable( L, LUA_REGISTRYINDEX );
    
}

  struct Player_Interface_Reg 
  {
    static int GetHP		(lua_State* L);
    static int GetWeapon	(lua_State* L);
    static int GetItem		(lua_State* L);
    static int GetPosition	(lua_State* L);
    static int GetDirection	(lua_State* L);

  };

  static const luaL_reg play_interface_reg[] =
  {
    { "GetHP", Player_Interface_Reg::GetHP},
    { "GetWeapon", Player_Interface_Reg::GetWeapon},
    { "GetItem", Player_Interface_Reg::GetItem},
    { "GetPosition", Player_Interface_Reg::GetHP},
    { "GetDirection", Player_Interface_Reg::GetWeapon},
    { NULL, NULL }
  };


#endif
