#ifndef PLAYER_H
#define PLAYER_H

#include <MoleBox/GameComponent.hpp>
#include <SFML/Graphics.hpp>


class Game;
class Component;

class Player : public MB::GameComponent
{
private:
	sf::Sprite playerSprite;
    MB::Action * up,*down;  
public:
	sf::Vector2f GetPosition();
	void SetPosition(float X, float Y);
	float GetDirection();
    Player(MB::Game* game);
	//const sf::Vector2f& getPosition();
    //sf::IntRect getHitBox();
	
    virtual void Update(sf::Time elapsed, MB::Types::EventList* events);
    virtual void Draw();
    virtual ~Player();
};

#endif // PLAYER_H
