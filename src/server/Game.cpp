#include <server/Game.hpp>
Game::Game(std::string windowName,int argc,char** argv) : MB::Game(windowName,argc,argv)
{
}


Game::~Game(void)
{
}

void Game::Update(sf::Time elapsed, MB::EventList *events)

{
	MB::Game::Update(elapsed,events);
}

void Game::Draw(void)
{

}

int Game::Run()
{
  MB::Game::Run();
  return 0;
}