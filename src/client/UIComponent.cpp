#include <client/UIComponent.hpp>


static int Create(lua_State *L)
{
 
  
  //lua_pushinteger(L,1);
  return 1;
}
static int SetPosition(lua_State *L)
{
  
  lua_pushnumber(L,0.0f);
  lua_pushnumber(L,0.0f);
  return 2;
}
static int Activated(lua_State *L)
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

void UIComponent::Update(sf::Time elapsed,MB::Types::EventList* events,int argCount)
{
  
  sf::Event ev;
//   ev = sf::Event::TextEntered;
//   std::map< sf::Event::EventType, sf::Event >::iterator eventItr =  events->find(ev);
//  
  
  MB::Lua::LuaComponent::Update(elapsed,events,argCount);
}

void UIComponent::Draw()
{
  MB::Lua::LuaComponent::Draw();
}

void UIComponent::UpdateScriptPreCall(lua_State* L)
{
  
}