#ifndef GAME_H
#define GAME_H

#include <MoleBox/Game.hpp>
#include <MoleBox/ContainerDefinitions.hpp>
#include <client/UI/UI_Elements.hpp>
#include <client/tcp_net.h>
#include <client/HUD.h>
#include "Player.h"
#include <client/Players/PlayerInformation.hpp>
#include <vector>

class Game :
	public MB::Game	
{
protected:

	HUD* Hud;

   UI_ELEMENTS elements;
   Player* player;
   
   bool hasFocus;
public:
	Game(std::string windowName);
	~Game(void);
	std::string pathPrefix;
	virtual void Draw(void);
	virtual void Update(sf::Time elapsed, MB::Types::EventList *events);
	virtual int Run(int argc,char **argv);
	Player* GetPlayer();
	bool HasFocus();
	std::vector<PlayerData> allPlayers;
};





#endif