#include <client/MapLoader.h>
#include <client/Map/Tile.hpp>

using namespace std;

MapLoader::MapLoader()
{

}

std::vector<Tile *> MapLoader::ReadFile(std::string path)  {

 
 std::ifstream mapfile(path.c_str());
 string mapRow;
 std::vector<Tile *> tmpVect;

 int x = 0;
 int y = 0;
 Tile* tempTile;
 
 if(mapfile.is_open()) {
  while (!mapfile.eof()) {
	  std::getline(mapfile,mapRow);
    std::cout << mapRow;
   int i = mapRow.size();
   x = 0;
   for(int j = 0 ; j < i ; j++) {
     
    char tile = mapRow.at(j);
    sf::Sprite tempSprite;

    tempSprite.setPosition(x*32, y*32);
    std::cout << (x * 32) << " " << ( y * 32 ) << std::endl;
    switch (tile) 
    {
    case 'F':
	
     //FLOOR
	tempSprite.setTexture( MB::Content::Load<sf::Texture>("Floor.png") );
	tmpVect.push_back(new Floor( tempSprite ));
     break;
    case 'W':
     //WALL
	tempSprite.setTexture( MB::Content::Load<sf::Texture>("Wall.png") );

	tmpVect.push_back(new Wall( tempSprite ));
     break;
    case 'S':
     //SPIKE
	tempSprite.setTexture( MB::Content::Load<sf::Texture>("Spike.png") );
	tmpVect.push_back(new Spikes( tempSprite ));

    default:

      break;

	}
	x++;
    }
	 y++;
   }
  
  }
 
 //return new vector;
 return tmpVect;
}