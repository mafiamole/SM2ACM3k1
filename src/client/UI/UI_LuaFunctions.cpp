#include <client/UI/UI_LuaFunctions.hpp>

int UI_Button_Reg::Create(lua_State* L)
{
 
  lua_pushinteger(L,1);
  return 1;
}

int UI_Button_Reg::Activated(lua_State* L)
{
 
  lua_pushboolean(L,false);
  return 1;
}


int UI_Button_Reg::SetPosition(lua_State* L)
{
  
  
  lua_pushnumber(L,35);
  lua_pushnumber(L,35);
  return 2;
}