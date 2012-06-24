#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Map/Tile.hpp"

class Map{

public:
  
	Map(sf::RenderTarget* renderTarget, std::vector< Tile* > tileList);
	
	void Draw();
	
	enum TileType {
		WALL,
		FLOOR,
		SPIKE
	};
	Map();
	
	   bool collisionDetect(sf::IntRect collisionBox, sf::Vector2f velocety, sf::Vector2f direction);

private:
  
	std::vector<Tile*> tiles;

	sf::RenderTarget* rendTarget;
	
};


#endif