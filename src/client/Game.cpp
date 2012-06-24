#include <client/Game.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/Map.h>
#include <client/MapLoader.h>
#include <client/Game.hpp>
#include <client/UI/UI_Elements.hpp>
#include <client/randomc.h>


//sf::Sound sound;
Map map = Map();
MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName) : MB::Game(windowName)
{
  //this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
  this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);

  map = Map(this->window, mapLoader.ReadFile("map.txt"));


  this->actionList.Register("Exit",new MB::Keyboard(sf::Keyboard::Escape));
  this->actionList.Register("Player Move Up",new MB::Keyboard(sf::Keyboard::W));
  this->actionList.Register("Player Move Down",new MB::Keyboard(sf::Keyboard::S));
  this->actionList.Register("Player Move Left",new MB::Keyboard(sf::Keyboard::A));
  this->actionList.Register("Player Move Right",new MB::Keyboard(sf::Keyboard::D));
  	
  this->actionList.Register("Player Move Up Alt",new MB::Keyboard(sf::Keyboard::Comma));
  this->actionList.Register("Player Move Down Alt",new MB::Keyboard(sf::Keyboard::O));
  this->actionList.Register("Player Move Right Alt",new MB::Keyboard(sf::Keyboard::E));


  this->player = (Player*)this->AddComponent( new Player(this) );
  this->Hud    = (HUD*)this->AddComponent( new HUD(this,"HUD.lua") );
  
  CRandomMersenne rand(23232);
  printf("%i",rand.IRandom(0,100));

 


}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{
    // Handle Keyboard input	
	if (this->actionList.Exists("Exit") && this->actionList.Get("Exit")->IsActive()){
		this->window->close(); 
		exit(0);
	}
     


  MB::Game::Update(elapsed,events);
  
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

