<<<<<<< HEAD
#include <client/Game.hpp>
#include <client/UIComponent.hpp>
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
  UI = (UIComponent*)this->AddComponent(new UIComponent(this,"testUI.lua"));
<<<<<<< .mine	//MB::Content::Load<sf::SoundBuffer>("mouthpop.wav");
=======  
>>>>>>> .theirs  this->elements.push_back(new UI_Radio("name","text"));
<<<<<<< .mine
	
	//sound = MB::Content::NewSound("mouthpop.wav");


=======  


>>>>>>> .theirs	// Load Map
	map = Map(this->window,	mapLoader.ReadFile("C:\\Content\\map.txt"));
<<<<<<< .mine
=======>>>>>>> .theirs}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{

  UI->Update(elapsed,events);
  
  MB::Game::Update(elapsed,events);
  
	//sound.play();

}

void Game::Draw()
{
	map.Draw();
	
	MB::Game::Draw();
  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
  return 0;
=======
#include <client/Game.hpp>
#include <client/UIComponent.hpp>


Game::Game(std::string windowName) : MB::Game(windowName)
{
  
  window = new sf::RenderWindow( sf::VideoMode(1024,800), windowName);
  
  UI = (UIComponent*)this->AddComponent(new UIComponent(this,"testUI.lua"));
  
  this->elements.push_back(new UI_Radio("name","text"));
  
  
}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{

  UI->Update(elapsed,events);
  
  MB::Game::Update(elapsed,events);
  
}

void Game::Draw()
{

  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
>>>>>>> stash
}