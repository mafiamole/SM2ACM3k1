#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <MoleBox/Content/Content.hpp>
#include <vector>
#include <string>
#include <client/Map/Tile.hpp>

class MapLoader {
public:
	MapLoader();
	   std::vector< Tile* > ReadFile(std::string path);

};


#endif
