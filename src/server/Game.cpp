#include <server/Game.hpp>
Game::Game(std::string windowName) : MB::Game(windowName)
{
}


Game::~Game(void)
{
}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)

{
	MB::Game::Update(elapsed,events);
}

void Game::Draw(void)
{

}

int Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
  return 0;
}