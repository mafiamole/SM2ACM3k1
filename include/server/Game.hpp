#ifndef GAME_H
#define GAME_H
#include <MoleBox/Game.hpp>
#include <MoleBox/Types.hpp>
class Game :
	public MB::Game
{
public:
  Game(std::string windowName, int argc, char** argv);
  ~Game(void);
  virtual void Draw(void);
  virtual void Update(sf::Time elapsed, MB::EventList *events);
  virtual int Run();

};

#endif