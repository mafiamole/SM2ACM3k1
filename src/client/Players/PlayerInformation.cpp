
#include <client/Players/PlayerInformation.hpp>
#include <client/HUD.h>
#include <MoleBox/Lua/ScriptHelper.hpp>
#include <lua.h>

bool PlayerData::ReadHealth(PlayerData* player, HealthBits healthPosition)
{
    int result;
    result = player->health & (1<<healthPosition-1);
    if(result > 0){return true;}else{ return false;}
    //return result;
}

void PlayerData::SetHealth(PlayerData* player, HealthBits healthPosition, bool value)
{
  if(value){
      player->health = player->health | (1<<healthPosition-1);
    }else{
        player->health = player->health & (~(1<<healthPosition-1));
    }
}

void PlayerData::SetFullHealth(PlayerData* player)
{
    for(int i=1; i<5;i++){
        SetHealth(player, (HealthBits)i, true);
    }
}

int Player_Interface_Reg::GetHP(lua_State* L)
{
  int argc = lua_gettop(L);
  
  if ( argc != 1 )
    MB::Lua::PushError( L, "This function needs one argument only." );
  
  int Player = lua_tointeger(L,1);
  
  HUD* hud = getUserData<HUD>(L,"HUD_OBJ");
  
  PlayerData playerData = hud->PlayerInformation(Player);

  lua_pushboolean(L,playerData.ReadHealth(&playerData, HealthBits::FRONT));//1));//
  lua_pushboolean(L,playerData.ReadHealth(&playerData, HealthBits::BACK));//2));//
  lua_pushboolean(L,playerData.ReadHealth(&playerData, HealthBits::LEFT));//  3));//
  lua_pushboolean(L,playerData.ReadHealth(&playerData, HealthBits::RIGHT));//4));//  

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
