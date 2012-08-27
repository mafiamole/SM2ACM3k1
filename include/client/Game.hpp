#ifndef GAME_H
#define GAME_H

#include <MoleBox/Game.hpp>
#include <MoleBox/Types.hpp>
#include <client/UI/UI_Elements.hpp>
#include <client/HUD.h>
#include "Player.h"
#include <client/Players/PlayerInformation.hpp>
#include <vector>
#include <client/TCP_Net2.hpp>
#include "Players.h"
#include <client/ClientMapLoader.h>
#include <shared/MapLoader.h>
class Game :
	public MB::Game	
{
private:
  Map mapObj;
  MapLoader mapLoader;  
protected:

  HUD* Hud;

   UI_ELEMENTS elements;
   Player* player;
   Players* players;
   bool hasFocus;
   void NetworkUpdate();
   ConnectionInfo info;
   std::vector<ClientItem> allItems; 
public:
	Game(std::string windowName, int argc, char** argv);
	~Game(void);
	
	virtual void Draw(void);
	virtual void Update(sf::Time elapsed, MB::EventList *events);
	virtual int Run();
	void RemoveItem(int index);

};





#endif