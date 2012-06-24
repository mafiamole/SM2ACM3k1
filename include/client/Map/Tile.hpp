#ifndef TILES_H
#define TILES_H
#include <client/SpriteSheet.h>

class Tile
{
  
protected:
  std::string 		identifier;
  sf::Sprite 	sprite;
public:
  
  Tile(sf::Sprite sprite);
  
  void Draw(sf::RenderTarget* target );
  
  void SetPosition(float x, float y);
  
  virtual ~Tile();

  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction);
  
};


class Spikes : public Tile
{
public:  
  Spikes(sf::Sprite sprite);
  
  
  virtual ~Spikes();

  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction);
   
};

class Floor : public Tile
{
  
public:
  Floor(sf::Sprite sprite);

  virtual ~Floor();
  //   Tile(const sf::Texture& texture, unsigned int spriteWidth,unsigned int spriteHeight);
  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction);
    
};


class Wall : public Tile
{
  
public:
  Wall(sf::Sprite sprite);
  
  virtual ~Wall();
  //   Tile(const sf::Texture& texture, unsigned int spriteWidth,unsigned int spriteHeight);
  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction);
    
};

#endif