
#include <client/Players/PlayerInformation.hpp>
#include <client/HUD.h>
#include <MoleBox/Lua/ScriptHelper.hpp>
#include <lua.h>


bool PlayerData::FrontHealth(PlayerData player)
{
  return player.health && 1;
}
bool PlayerData::BackHealth(PlayerData player)
{
  return player.health && 2;
}


bool PlayerData::LeftHealth(PlayerData player)
{
  return player.health && 3;
  
}
bool PlayerData::RightHealth(PlayerData player)
{
  return player.health && 4;
  
}

int Player_Interface_Reg::GetHP(lua_State* L)
{
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushboolean(L,playerData.FrontHealth(playerData));
  lua_pushboolean(L,playerData.BackHealth(playerData));
  lua_pushboolean(L,playerData.LeftHealth(playerData));  
  lua_pushboolean(L,playerData.RightHealth(playerData));  

  return 4;

  
}

int Player_Interface_Reg::GetWeapon(lua_State* L)
{
  
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushinteger(L,playerData.weapon);

  return 1;
}

int Player_Interface_Reg::GetItem(lua_State* L)
{
  
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushinteger(L,playerData.item); 
  
  return 1;
}

int Player_Interface_Reg::GetPosition(lua_State* L)
{
  
  
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushnumber(L,playerData.position.x);
  lua_pushnumber(L,playerData.position.y);
  
  return 2;
}

int Player_Interface_Reg::GetDirection(lua_State* L)
{
  
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushnumber(L,playerData.direction);  
  
  return 1;
}
