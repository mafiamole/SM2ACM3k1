#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Map/Tile.hpp"

class Map{

public:
  
	Map(sf::RenderTarget* renderTarget, std::vector<ClientTile*> tileList);
	
	void Draw();
	

	Map();
    sf::Vector2f collisionDetect(sf::IntRect collisionBox, sf::Vector2f velocity, sf::Vector2f direction);
    sf::Vector2f WallCheck(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction);
private:
  
	std::vector<ClientTile*> tiles;

	sf::RenderTarget* rendTarget;
	
};


#endif