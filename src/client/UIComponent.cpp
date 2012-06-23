#include <client/UIComponent.hpp>



int UI_Button_Lua::Create(lua_State *L)
{
 
  
  //lua_pushinteger(L,1);
  return 1;
}

int UI_Button_Lua::SetPosition(lua_State *L)
{
  
  lua_pushnumber(L,0.0f);
  lua_pushnumber(L,0.0f);
  
  return 2;
}
int UI_Button_Lua::Activated(lua_State *L)
{
  
  //lua_pushboolean(L,false);
  return 1;
}
  
UIComponent::UIComponent(MB::Game* game, std::string file) : LuaComponent(game,file)
{

}


UIComponent::~UIComponent()
{
  
}

void UIComponent::Update(sf::Time elapsed,MB::Types::EventList* events)
{
  
  sf::Event ev;
//   ev = sf::Event::TextEntered;
//   std::map< sf::Event::EventType, sf::Event >::iterator eventItr =  events->find(ev);
//  
  
  this->script->AddLibrary("Button",UI_Button_reg);
  
  MB::Lua::LuaComponent::Update(elapsed,events);
}

void UIComponent::Draw()
{
  MB::Lua::LuaComponent::Draw();
}

void UIComponent::UpdateScriptPreCall(lua_State* L)
{
  
}