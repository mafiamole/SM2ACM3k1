#ifndef HUD_H
#define HUD_H
#include <MoleBox/Lua/Component.hpp>
#include <client/Players/PlayerInformation.hpp>
#include "UI/UI_Elements.hpp"

class HUD : public MB::Lua::Component
{
protected:
  PlayerDataList 	playersData;
  UI_ELEMENTS 		elements;
  virtual void UpdateScriptPreCall(lua_State* L);
public:
  
  HUD(MB::Game *game,std::string file);
  
  ~HUD();
  
  void SetPlayersData(PlayerDataList list);
  
  PlayerData PlayerInformation( int player );
  
  
  
  void Update(sf::Time elapsed, MB::EventList* events);
  
  void Draw();
  
  
  
};

#endif