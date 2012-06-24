#ifndef PLAYER_H
#define PLAYER_H

#include <MoleBox/GameComponent.hpp>


class Game;
class Component;

class Player : public MB::GameComponent
{
private:

  MB::Action * up,*down;
    sf::Sprite playerSprite;
public:
    Player(MB::Game* game);
    //const sf::Vector2f& getPosition();
    //sf::IntRect getHitBox();
    virtual void Update(sf::Time elapsed, MB::Types::EventList* events);
    virtual void Draw();
    virtual ~Player();
};

#endif // PLAYER_H
