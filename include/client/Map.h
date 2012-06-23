#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Map{
public:
	Map(sf::RenderTarget* renderTarget, std::vector<sf::Sprite> tileList);
	void Draw();
	enum TileType {
		WALL,
		FLOOR,
		SPIKE
	};
	Map();
	

private:
	std::vector<sf::Sprite> tiles;
	sf::RenderTarget* rendTarget;
};


#endif