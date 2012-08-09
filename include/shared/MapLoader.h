#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <shared/Enums.h>


class MapLoader {
public:
	MapLoader();
	std::vector<Tile> ReadFile(std::string path);
    
    bool TileOnFloor(Tile* tile, std::vector<Tile> mapTiles, bool isPlayer = false);
    bool TilesColliding(Tile* tile1, sf::Vector2f tile2Pos);
    bool PlayersColliding(sf::Vector2f player1Pos, sf::Vector2f player2Pos);
};


#endif
