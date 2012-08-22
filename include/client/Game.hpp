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
class Game :
	public MB::Game	
{
protected:

	HUD* Hud;

   UI_ELEMENTS elements;
   Player* player;
   
   bool hasFocus;
public:
	Game(std::string windowName, int argc, char** argv);
	~Game(void);
	std::string pathPrefix;
	virtual void Draw(void);
	virtual void Update(sf::Time elapsed, MB::EventList *events);
	virtual int Run();
	Player* GetPlayer();
	bool HasFocus();
	std::vector<PlayerData> allPlayers;
    std::vector<ClientItem> allItems;
	ConnectionInfo info;

    sf::Sprite revisedSpriteGlobal;
    sf::FloatRect revisedRectangleGlobal;

};





#endif