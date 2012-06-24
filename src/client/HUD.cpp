#include <client/HUD.h>

HUD::HUD(MB::Game* game, std::string file) : MB::Lua::LuaComponent(game,file)
{
  
  //getComponentFromUserData<HUD>(this->script->GetState());
  setUserData<HUD>(this->script->GetState(),"HUD_OBJ",this);
  //this->script->AddLibrary("Test",);
}

HUD::~HUD()
{

  
}

void HUD::Update(sf::Time elapsed, MB::Types::EventList* events)
{
 MB::Lua::LuaComponent::Update(elapsed,events); 
}




void HUD::Draw()
{
  
}

void HUD::UpdateScriptPreCall(lua_State* L)
{
  
}

void HUD::SetPlayersData(PlayerDataList list)
{
  this->playersData = list;
}


 PlayerData HUD::PlayerInformation( int player )
 {
   if ( player < this->playersData.size() && player > 0)
   {
   return this->playersData.at(player);
   }
   else
   {
      PlayerData data;
   }
 }