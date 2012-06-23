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
}