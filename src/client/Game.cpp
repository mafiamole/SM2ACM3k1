#include <client/Game.hpp>
#include <client/UIComponent.hpp>


Game::Game(std::string windowName) : MB::Game(windowName)
{
  window = new sf::RenderWindow( sf::VideoMode(1024,800), windowName);
  this->AddComponent(new UIComponent(this,"testUI.lua"));
  this->elements.push_back(new UI_Radio("name","text"));
  


}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{

  MB::Game::Update(elapsed,events); 

  /*  
  UI_ELEMENTS::iterator element_itr;
  
  for ( element_itr = events->begin(); element_itr != events->end();element_itr++ )
  {
    std::cout << (*element_itr)->Activated() << std::endl;
  }*/
  
}

void Game::Draw()
{

  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
}