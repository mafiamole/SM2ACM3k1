#include <client/Map/Tile.hpp>
#include <iostream>
/**
 * 
 * 
 *  Spikes
 * 
 */

ClientTile::ClientTile(){}
ClientTile::ClientTile(sf::Sprite sprite) : sprite(sprite)
{

  
}

ClientTile::~ClientTile()
{


  
}
void ClientTile::Draw(sf::RenderTarget* target )
{
  target->draw(this->sprite);
}

void ClientTile::SetPosition(float x, float y)
{
  this->sprite.setPosition(x,y);
  this->position = this->sprite.getPosition();
}

void ClientTile::SetSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Vector2f ClientTile::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity, sf::Vector2f direction)
{
  
  return velocity;
 
}

/**
 * 
 * 
 *  Spikes
 * 
 */

Spikes::Spikes(sf::Sprite sprite) : ClientTile(sprite)
{
}

 sf::Vector2f Spikes::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{

  sf::IntRect hitbox = this->sprite.getTextureRect();
  
  hitbox.top = this->sprite.getPosition().y;
  hitbox.left = this->sprite.getPosition().x;
    sf::Vector2f newvel;
    newvel.x = velocity.x / 10;
    newvel.y = velocity.y / 10;
     
  bool intercepts = collisionBox.intersects( hitbox );
  
  if (intercepts){

    return velocity;//newvel;
  }
  else
  {
    return velocity;
  }
  
}

Spikes::~Spikes()
{
  
}
/**
 * 
 * 
 *  floor
 * 
 */

Floor::Floor(sf::Sprite sprite) : ClientTile(sprite)
{
 
}

sf::Vector2f Floor::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{

  return velocity;
}
Floor::~Floor()
{
  
}

/**
 * 
 * 
 *  Spikes
 * 
 */


Wall::Wall(sf::Sprite sprite)  : ClientTile(sprite)
{
  
}


Wall::~Wall()
{
}

sf::Vector2f Wall::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{
  
  //std::cout << "checking wall!" << std::endl;
  float xDistance = collisionBox.left - this->sprite.getPosition().x;
  float yDistance = collisionBox.top - this->sprite.getPosition().y;
  
  float xTileDistance = xDistance / this->sprite.getTextureRect().width;
  float yTileDistance = yDistance / this->sprite.getTextureRect().height;
  
  if ( xTileDistance > 2 || yTileDistance > 2)
    return velocity;
  
  sf::IntRect hitbox = this->sprite.getTextureRect();
  
  hitbox.top = this->sprite.getPosition().y;
  hitbox.left = this->sprite.getPosition().x;
  
  bool intercepts = collisionBox.intersects( hitbox );
  if (intercepts){
      //std::cout << "wall" << std::endl;
  return sf::Vector2f(0,0);  
    }
  else
    {
    return velocity;
    }
}