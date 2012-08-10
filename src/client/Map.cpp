#include "client/Map.h"
#include <iostream>

Map::Map(sf::RenderTarget* renderTarget, std::vector<ClientTile*> tileList){
	tiles = tileList;
	rendTarget = renderTarget;
}
Map::Map(){
  
}

void Map::Draw() {
  
	std::vector<ClientTile*>::iterator it;
	int a = tiles.size();

	for(it = tiles.begin(); it != tiles.end();it++) {
	  
	  (*it)->Draw(this->rendTarget);
		
	}

}


bool Map::collisionDetect(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction) {

  sf::Vector2f value(0,0);
  
  std::vector<ClientTile*>::iterator it;
  int a = tiles.size();
  for(it = tiles.begin(); it != tiles.end();it++) {
      
    ClientTile* tile = (*it);
    
    value = tile->DetectCollision(collisionBox, velocity,direction);
    
    if (value != velocity)
    {
      return true;
      
    }
  }

  return false;
  
}