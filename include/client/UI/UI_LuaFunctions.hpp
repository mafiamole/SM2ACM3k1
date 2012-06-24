#include "lua.hpp"


  struct UI_Button_Reg 
  {
    static int Create(lua_State*);
    static int Activated(lua_State*);
    static int SetPosition(lua_State*);
  };

  static const luaL_reg ui_button_reg[] =
  {
    { "Create", UI_Button_Reg::Create},
    { "Activated", UI_Button_Reg::Activated},
    { "SetPosition", UI_Button_Reg::SetPosition},
    { NULL, NULL }
  };