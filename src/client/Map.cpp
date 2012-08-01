#include "client/Map.h"
#include <iostream>

Map::Map(sf::RenderTarget* renderTarget, std::vector<Tile *> tileList){
	tiles = tileList;
	rendTarget = renderTarget;
}
Map::Map(){
  
}

void Map::Draw() {
  
	std::vector<Tile*>::iterator it;
	int a = tiles.size();

	for(it = tiles.begin(); it != tiles.end();it++) {
	  
	  (*it)->Draw(this->rendTarget);
		
	}

}

bool Map::PlayerOnFloor(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction){
    sf::Vector2f value(0,0);
  
  std::vector<Tile*>::iterator it;
  int a = tiles.size();
  bool hasHitSomething = false;
  for(it = tiles.begin(); it != tiles.end();it++) {
      
    Tile* tile = (*it);
    
    value = tile->DetectCollision(collisionBox, velocety,direction);
    
    if (value != velocety)
    {
      hasHitSomething = true;      
    }
   
  }



  if(hasHitSomething){ return false; } else {return true;}

}

bool Map::collisionDetect(sf::IntRect collisionBox, sf::Vector2f velocety,sf::Vector2f direction) {

  sf::Vector2f value(0,0);
  
  std::vector<Tile*>::iterator it;
  int a = tiles.size();
  for(it = tiles.begin(); it != tiles.end();it++) {
      
    Tile* tile = (*it);
    
    value = tile->DetectCollision(collisionBox, velocety,direction);
    
    if (value != velocety)
    {
      return true;
      
    }
  }

  return false;
  
}