#ifndef UICOMPONPONENT_H
#define UICOMPONPONENT_H
#include <MoleBox/Lua/ComponentFunctions.hpp>
#include <MoleBox/Lua/Component.hpp>



class UI_Button_Lua
{
public:
  static int Create(lua_State *L);
  static int SetPosition(lua_State *L);
  static int Activated(lua_State *L);
};
static const luaL_reg UI_Button_reg[] =
{
  
  { "Create", 		UI_Button_Lua::Create},
  { "SetPosition",  	UI_Button_Lua::SetPosition},
  { "Activated",	UI_Button_Lua::Activated},
  { NULL, NULL }
  
};

class UIComponent : public MB::Lua::LuaComponent
{
protected:
  virtual void UpdateScriptPreCall(lua_State* L);
public:
  
    UIComponent(MB::Game* game, std::string file);
    virtual ~UIComponent();
    
    void Update(sf::Time elapsed, MB::Types::EventList* events);
    void Draw();
  
};
#endif