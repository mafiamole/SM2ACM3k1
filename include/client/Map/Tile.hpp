#ifndef TILES_H
#define TILES_H
#include <client/SpriteSheet.h>
#include <shared/Enums.h>

class ClientTile : public Tile
{
  
protected:
  std::string 		identifier;
  sf::Sprite 	sprite;
public:
  
  ClientTile(sf::Sprite sprite);
  ClientTile();
  TileTypes tileType;

  void Draw(sf::RenderTarget* target );
  
  void SetPosition(float x, float y);
  void SetSprite(sf::Sprite sprite);
  virtual ~ClientTile();

  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction);
  
};


class Spikes : public ClientTile
{
public:  
  Spikes(sf::Sprite sprite);
    
  virtual ~Spikes();
  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction);
   
};

class Floor : public ClientTile
{
  
public:
  Floor(sf::Sprite sprite);

  virtual ~Floor();
  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction);
    
};


class Wall : public ClientTile
{
  
public:
  Wall(sf::Sprite sprite);
  
  virtual ~Wall();
  virtual sf::Vector2f DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction);
    
};

#endif