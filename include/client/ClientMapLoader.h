#ifndef CLIENT_MAPLOADER_H
#define CLIENT_MAPLOADER_H

#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <MoleBox/Content/Content.hpp>
#include <vector>
#include <string>
#include <shared/Enums.h>
#include <client/Map/Tile.hpp>

class ClientMapLoader {
public:
	ClientMapLoader();
  static std::vector<ClientTile*> PopulateClientTileSprites(std::vector< Tile > tiles);
};


#endif
