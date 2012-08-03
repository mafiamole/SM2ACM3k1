#ifndef SERV_MAP_LOADER_H
#define SERV_MAP_LOADER_H

#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <shared/Enums.h>


class ServMapLoader {
public:
	ServMapLoader();
	std::vector<ServTile> ReadFile(std::string path);
    
    bool TileOnFloor(ServTile* tile, std::vector<ServTile> mapTiles);
    bool TilesColliding(ServTile* tile1, sf::Vector2f tile2Pos);
    bool PlayersColliding(sf::Vector2f player1Pos, sf::Vector2f player2Pos);
};


#endif
