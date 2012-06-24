#include <client/MapLoader.h>
#include <client/Map/Tile.hpp>

using namespace std;

MapLoader::MapLoader()
{

}

std::vector<Tile *> MapLoader::ReadFile(std::string path)  {

	sf::Texture wallTexture ;
	sf::Texture floorTexture;
	sf::Texture spikeTexture;
	

 std::ifstream mapfile(path.c_str());
 string mapRow;
 std::vector<Tile *> tmpVect;

 int x = 0;
 int y = 0;
 Tile* tempTile;
 
 if(mapfile.is_open()) {
  while (!mapfile.eof()) {
	  std::getline(mapfile,mapRow);

   int i = mapRow.size();
   x = 0;
   for(int j = 0 ; j < i ; j++) {
     
    char tile = mapRow.at(j);
    sf::Sprite tempSprite;

    tempSprite.setPosition(x*32, y*32);
    switch (tile) 
    {
    case 'F':
	
     //FLOOR
<<<<<<< HEAD
     tempSprite.setTexture( MB::Content::Load<sf::Texture>("Floor.png") );
      tmpVect.push_back(new Floor( tempSprite ));
=======
		tmpSprite = sf::Sprite(MB::Content::Load<sf::Texture>("C:\\Content\\Floor.png" ));		
>>>>>>> 5bcdc7783b2b5efb78d2c07c1e6434c09da15a4d
     break;
    case 'W':
     //WALL
<<<<<<< HEAD
     tempSprite.setTexture( MB::Content::Load<sf::Texture>("Wall.png") );
     tempSprite.setPosition(x*32, y*32);
	tmpVect.push_back(new Wall( tempSprite ));

=======
		tmpSprite = sf::Sprite( MB::Content::Load<sf::Texture>("C:\\Content\\Wall.png" ));
>>>>>>> 5bcdc7783b2b5efb78d2c07c1e6434c09da15a4d
     break;
    case 'S':
     //SPIKE
<<<<<<< HEAD
     tempSprite.setTexture( MB::Content::Load<sf::Texture>("Spike.png") );
     tempSprite.setPosition(x*32, y*32);
	tmpVect.push_back(new Spikes( tempSprite ));

    default:

      break;
=======
		tmpSprite = sf::Sprite(MB::Content::Load<sf::Texture>("C:\\Content\\Spike.png" ));
	default:
		break;
	}
>>>>>>> 5bcdc7783b2b5efb78d2c07c1e6434c09da15a4d
    }
	x++;
   }
   y++;
  }
 }

 //return new vector;
 return tmpVect;
}