#include "client/Map.h"


Map::Map(sf::RenderTarget* renderTarget, std::vector<sf::Sprite> tileList){
	tiles = tileList;
	rendTarget = renderTarget;
}
Map::Map(){
}

void Map::Draw() {
  
	std::vector<sf::Sprite>::iterator it;
	int a = tiles.size();
	for(it = tiles.begin(); it != tiles.end();it++) {
	  
		rendTarget->draw(*it);
		
	}


}