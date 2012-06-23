#include <client/Game.hpp>
#include <client/UIComponent.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/Map.h>
#include <client/MapLoader.h>
#include <client/Game.hpp>
#include <client/UI/UI_Elements.hpp>


//sf::Sound sound;
Map map = Map();
MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName) : MB::Game(windowName)
{
  //this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
  this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);
  
  UI = (UIComponent*)this->AddComponent(new UIComponent(this,"testUI.lua"));
  
  this->elements.push_back( new UI_Button(this->window,"TestButton.png","name","text") );
  
  map = Map(this->window,mapLoader.ReadFile("map.txt"));

}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{

  UI->Update(elapsed,events);
  
    UI_ELEMENTS::iterator elementItr;

  for (elementItr = elements.begin(); elementItr != elements.end(); elementItr++)
  {
    
    if ((*elementItr)->Activated(events))
    {
      std::cout << "Element activated." << std::endl;
    }
    
  }  
  
  MB::Game::Update(elapsed,events);
  
}

void Game::Draw()
{
  map.Draw();
  UI_ELEMENTS::iterator elementItr;
  
  for (elementItr = elements.begin(); elementItr != elements.end(); elementItr++)
  {
    
    (*elementItr)->Draw();
    
  }
  
  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
  return 0;
}


