#ifndef PLAYER_H
#define PLAYER_H

#include <MoleBox/GameComponent.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <client/Map.h>
#include <client/WorkQueues.h>
#include <client/Players/PlayerInformation.hpp>
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
    sf::IntRect GetTextureRect();
    int ownID;
	void SetPosition(float X, float Y);
    void SetPosition(sf::Vector2f vect);
	float GetDirection();
    Player(MB::Game* game, Map* map);
	
    virtual void Update(sf::Time elapsed, MB::Types::EventList* events);
    virtual void Draw();
    virtual ~Player();
};

#endif // PLAYER_H
