#ifndef PLAYER_H
#define PLAYER_H

#include <MoleBox/GameComponent.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <client/Map.h>
#include <client/WorkQueues.h>

#include <shared/Packets.h>


class Game;
class Component;

class Player : public MB::GameComponent
{
private:
    sf::Sprite playerSprite;
    MB::Action * up,*down; 
     Map* gameMap;
    sf::IntRect rect;
public:
	sf::Vector2f GetPosition();
	void SetPosition(float X, float Y);
	float GetDirection();
    Player(MB::Game* game, Map* map);
	//const sf::Vector2f& getPosition();
    //sf::IntRect getHitBox();
	
    virtual void Update(sf::Time elapsed, MB::Types::EventList* events);
    virtual void Draw();
    virtual ~Player();
};

#endif // PLAYER_H
