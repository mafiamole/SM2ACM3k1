#include <client/HUD.h>

HUD::HUD(MB::Game* game, std::string file) : MB::Lua::LuaComponent(game,file)
{
  
}

HUD::~HUD()
{

  
}
void HUD::UpdateScriptPreCall(lua_State* L)
{
  
}

void HUD::SetPlayersData(PlayerDataList list)
{
  this->playersData = list;
}

void HUD::Update(sf::Time elapsed, MB::Types::EventList* events)
{
 MB::Lua::LuaComponent::Update(elapsed,events); 
}


void HUD::Draw()
{
  
}