#ifndef GAME_H
#define GAME_H
#include <MoleBox/Game.hpp>
#include <MoleBox/ContainerDefinitions.hpp>
#include <client/UI/UI_Elements.hpp>

#include <client/HUD.h>
#include "UIComponent.hpp"
#include "Player.h"

class Game :
	public MB::Game
{
protected:

	HUD* Hud;

  UI_ELEMENTS elements;
  UIComponent *UI;
  Player* player;
public:
	Game(std::string windowName);
	~Game(void);
	virtual void Draw(void);
	virtual void Update(sf::Time elapsed, MB::Types::EventList *events);
	virtual int Run(int argc,char **argv);


};

#endif