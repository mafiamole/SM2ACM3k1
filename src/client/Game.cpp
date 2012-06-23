#include <client/Game.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/map.h>
#include <client/MapLoader.h>

//sf::Sound sound;
Map map = Map();
MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName) : MB::Game(windowName)
{
	//this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
	this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);
	//MB::Content::Load<sf::SoundBuffer>("mouthpop.wav");
	//this->AddComponent(new MB::Lua::LuaComponent(this,"testComponent2.lua"));

	
	//sound = MB::Content::NewSound("mouthpop.wav");


	// Load Map
	map = Map(this->window,	mapLoader.ReadFile("C:\\Content\\map.txt"));

}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)

{
	MB::Game::Update(elapsed,events);
	//sound.play();

}

void Game::Draw()
{
	map.Draw();
	
	MB::Game::Draw();
}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
  return 0;
}