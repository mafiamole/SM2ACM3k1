#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <MoleBox/Content/Content.hpp>
#include <vector>
#include <string>

class MapLoader {
public:
	MapLoader();
	std::vector<sf::Sprite> ReadFile(std::string path);

};


#endif
