#ifndef PLAYER_H
#define PLAYER_H

#include <MoleBox/GameComponent.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <client/Map.h>
#include <client/WorkQueues.h>
#include <client/Players/PlayerInformation.hpp>
#include <shared/Packets.h>
#include <MoleBox/Actions/Action.hpp>

class Game;
class Component;

class Player : public MB::GameComponent
{
private:
    sf::Sprite playerSprite;
    MB::Actions::Action * up,*down; 
    Map* gameMap;
    sf::Vector2i directionVector;
    
public:
    Player(MB::Game* game, Map* map);
    virtual ~Player();
    
    virtual void Update(sf::Time elapsed, MB::EventList* events);
    virtual void Draw();
    
    void Attack();
    
    sf::Vector2f GetPosition();
    sf::IntRect GetTextureRect();
    int ownID;
    Bonus bonus;
	void SetPosition(float X, float Y);
    void SetPosition(sf::Vector2f vect);
	float GetDirection();
    sf::Vector2i GetDirectionVector();
    sf::IntRect GetHitBox();
    sf::RectangleShape weaponHitBox;
    void UpdateWeaponHitBox();
    sf::Vector2f HitBoxPosToBoundingPos(sf::Vector2f pos);



};

#endif // PLAYER_H
