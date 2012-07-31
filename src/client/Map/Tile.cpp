#include <client/Map/Tile.hpp>
#include <iostream>
/**
 * 
 * 
 *  Spikes
 * 
 */

Tile::Tile(sf::Sprite sprite) : sprite(sprite)
{


  
}

Tile::~Tile()
{


  
}
void Tile::Draw(sf::RenderTarget* target )
{
  target->draw(this->sprite);
}

void Tile::SetPosition(float x, float y)
{
  this->sprite.setPosition(x,y);
}

sf::Vector2f Tile::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety, sf::Vector2f direction)
{
  
  return velocety;
 
}

/**
 * 
 * 
 *  Spikes
 * 
 */

Spikes::Spikes(sf::Sprite sprite) : Tile(sprite)
{
}

 sf::Vector2f Spikes::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction)
{

  sf::IntRect hitbox = this->sprite.getTextureRect();
  
  hitbox.top = this->sprite.getPosition().y;
  hitbox.left = this->sprite.getPosition().x;
    sf::Vector2f newvel;
    newvel.x = velocety.x / 10;
    newvel.y = velocety.y / 10;
     
  bool intercepts = collisionBox.intersects( hitbox );
  
  if (intercepts){
      //std::cout << "spikes" << std::endl;
    return newvel;
  }
  else
  {
    return velocety;
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

Floor::Floor(sf::Sprite sprite) : Tile(sprite)
{
 
}

sf::Vector2f Floor::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction)
{

  return velocety;
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


Wall::Wall(sf::Sprite sprite)  : Tile(sprite)
{
  
}


Wall::~Wall()
{
}

sf::Vector2f Wall::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction)
{
  
  //std::cout << "checking wall!" << std::endl;
  float xDistance = collisionBox.left - this->sprite.getPosition().x;
  float yDistance = collisionBox.top - this->sprite.getPosition().y;
  
  float xTileDistance = xDistance / this->sprite.getTextureRect().width;
  float yTileDistance = yDistance / this->sprite.getTextureRect().height;
  
  if ( xTileDistance > 2 || yTileDistance > 2)
    return velocety;
  
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
    return velocety;
    }
}