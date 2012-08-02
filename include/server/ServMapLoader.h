#ifndef SERV_MAP_LOADER_H
#define SERV_MAP_LOADER_H

#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <shared/Enums.h>

struct Tile{
    sf::Vector2f position;
    TileTypes tileType;
};  

class ServMapLoader {
public:
	ServMapLoader();
	std::vector<Tile> ReadFile(std::string path);
    
    bool TileOnFloor(Tile* tile, std::vector<Tile> mapTiles);
    bool TilesColliding(Tile* tile1, sf::Vector2f tile2Pos);
};


#endif
